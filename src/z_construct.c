/* $Id: z_construct.c,v 2.6 1998/11/06 02:55:48 soejima Exp $
 *
 * parameter_dt( Game_play *game_play )
 * parameter_ct( Game_play *game_play )
 * message_ct( Game_play *game_play )
 * save_area_ct( Game_play *game_play )
 * コンストラクタ
 *
 * $Log: z_construct.c,v $
 * Revision 2.6  1998/11/06  02:55:48  soejima
 * コメント
 *
 * Revision 2.5  1998-11-02 17:58:16+09  soejima
 * ＰＡＬ
 *
 * Revision 2.4  1998-10-30 14:06:11+09  soejima
 * ＰＡＬ変更
 *
 * Revision 2.3  1998-10-29 18:18:14+09  soejima
 * ＰＡＬ変更
 *
 * Revision 2.2  1998-10-27 21:24:21+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.128  1998/10/14 08:20:27  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998/03/05  02:23:23  soejima
 * Initial revision
 * $Log追加
 * */




/************************************************************************
 *									*
 *	ゼルダ64 コンストラクタ集					*
 *				1998年03月05日(火曜日) 11時00分00秒 JST *
 *									*
 ************************************************************************/
#include "z_basic.h"
#include "z_play.h"
#include "assert64.h"		/* assert */
#include "padmgr.h"

#include "z_scene_table.h"
#include "z_save_area_h.h"
#include "z_parameter_h.h"
#include "z_message_h.h"
#include "z_map_exp.h"

#include "z_parameter.h"	/* map_textuer_dma alpha_clear */
#include "z_kanfont.h"		/* kscope_kanfont_get */
#include "z_lifemeter.h"	/* initial_LifeMeterColorAnimation */



EXTERN_DEFSEG_DATA(parameter_static);
EXTERN_DEFSEG_DATA(do_action_static);
EXTERN_DEFSEG_DATA(icon_item_static);


extern padmgr_t padmgr;



/************************************************************************
 *									*
 *	パラメーター表示処理 クラス コンストラクト			*
 *									*
 ************************************************************************/
extern void
parameter_dt( Game_play *game_play )
{
    /* ＭＡＰ */
    map_exp_dt( game_play );
}

extern void
parameter_ct( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    u32		size0;
    unshort	jjj;
    short 	event_pt;


    ZCommonSet( sunmoon_flag, 0 );

    Z_ALPHA_TYPE =
	Z_PREV_ALPHA_TYPE = 0;
    /* ビュー イニシャル */
    view_init( &parameter->view, game_play->g.graph );

    parameter->do_action_flg =
	parameter->do_action =
	parameter->do_action_old = 0;
    parameter->do_action_rotate = 0.0f;
/*    parameter->h_gage    =
      parameter->b_button  =
      parameter->a_button  =
      parameter->c_bottle  =
      parameter->c_warasibe =
      parameter->c_hook    =
      parameter->c_sunmoon =
      parameter->c_ocarina =
      parameter->c_warp    =
      parameter->m_wind    =
      parameter->m_magic   =
      parameter->another   =*/
    parameter->sp_action_flag =
	parameter->marathon_fg =
	parameter->sp_action = 0;
    

    parameter->magic_mp = 0;
    parameter->magic_frame = 16;

    parameter->active_heart_timer = XREG(95);


    parameter->fill_alpha =		/* ＦｉｌｌＲｅｃｔａｎｇｌｅ Ａｌｐｈａ値 */
	parameter->a_alpha =    	/* Ａボタン Ａｌｐｈａ値 */
	parameter->b_alpha =		/* Ｂボタン Ａｌｐｈａ値 */
	parameter->c_alpha =		/* Ｃボタン Ａｌｐｈａ値 */
	parameter->c_alpha1 =		/* Ｃボタン Ａｌｐｈａ値 */
	parameter->c_alpha2 =		/* Ｃボタン Ａｌｐｈａ値 */
	parameter->heart_alpha =	/* ハート Ａｌｐｈａ値 */
	parameter->start_alpha =	/* ＳＴＡＲＴ Ａｌｐｈａ値 */
	parameter->meter_alpha = 0;	/* メーター Ａｌｐｈａ値 */
# if 0
    if ( game_play->room_info.now.type == ROOM_TYPE_DANGEON ) {
	parameter->map_alpha = 0;		/* ＭＡＰ Ａｌｐｈａ値 */
    } else {
	parameter->map_alpha = 0;		/* ＭＡＰ Ａｌｐｈａ値 */
    }
# endif
    parameter->map_alpha = 0;		/* ＭＡＰ Ａｌｐｈａ値 */

    parameter->hold_rod = 0;

    /* 常駐ＰＡＲＡＭＥＴＥＲセグメント */
    size0 = (u32)_parameter_staticSegmentRomEnd - (u32)_parameter_staticSegmentRomStart;
    PRINTF("常駐ＰＡＲＡＭＥＴＥＲセグメント=%x\n",size0);
    parameter->parameterSegment = (char *)game_alloc( &game_play->g, (size_t)size0 );
    PRINTF("parameter->parameterSegment=%x\n",parameter->parameterSegment);
    assert(parameter->parameterSegment != NULL);
    dmacopy_fg(parameter->parameterSegment, (u32)_parameter_staticSegmentRomStart, size0 );


    /* ＤＯアクション テクスチャ初期 */
    parameter->do_actionSegment = (char *)game_alloc(&game_play->g, (size_t)G_B_PT*3);
    PRINTF("ＤＯアクション テクスチャ初期=%x\n",G_B_PT*3);
    PRINTF("parameter->do_actionSegment=%x\n",parameter->do_actionSegment);
    assert(parameter->do_actionSegment != NULL);
#if defined(PAL_VERSION)
    if ( !J_N )          jjj = DO_Attack * G_B_PT;
    else if ( J_N == 1 ) jjj = (DO_Attack + DO_F_Navi) * G_B_PT;
    else                 jjj = (DO_Attack + DO_F_Navi + DO_F_Navi) * G_B_PT;
    dmacopy_fg(parameter->do_actionSegment, (u32)_do_action_staticSegmentRomStart+jjj, G_B_PT*2 );
    if ( !J_N )          jjj = G_B_PT*DO_Modoru;
    else if ( J_N == 1 ) jjj = G_B_PT*(DO_Modoru + DO_F_Navi);
    else                 jjj = G_B_PT*(DO_Modoru + DO_F_Navi + DO_F_Navi);
    dmacopy_fg(parameter->do_actionSegment+(G_B_PT*2), (u32)_do_action_staticSegmentRomStart+jjj, G_B_PT );
#else
    if ( !J_N ) jjj = DO_Attack * G_B_PT;
    else        jjj = (DO_Attack + DO_F_Navi) * G_B_PT;
    dmacopy_fg(parameter->do_actionSegment, (u32)_do_action_staticSegmentRomStart+jjj, G_B_PT*2 );
    if ( !J_N ) jjj = G_B_PT*DO_Modoru;
    else        jjj = G_B_PT*(DO_Modoru + DO_F_Navi);
    dmacopy_fg(parameter->do_actionSegment+(G_B_PT*2), (u32)_do_action_staticSegmentRomStart+jjj, G_B_PT );
#endif


    /* アイコンアイテム テクスチャ初期 */
    parameter->icon_itemSegment = (char *)game_alloc(&game_play->g, (size_t)I_IT_PT*4);
    PRINTF("アイコンアイテム テクスチャ初期=%x\n",I_IT_PT*4);
    PRINTF("parameter->icon_itemSegment=%x\n",parameter->icon_itemSegment);
    assert(parameter->icon_itemSegment != NULL);
    PRINTF("Register_Item[%x, %x, %x, %x]\n",Register_Item(0),Register_Item(1),Register_Item(2),Register_Item(3));
    if ( Register_Item(0) < 0xf0 ) {
	dmacopy_fg( parameter->icon_itemSegment+I_IT_PT*0,
		    (u32)_icon_item_staticSegmentRomStart+((Register_Item(0))*I_IT_PT),
		    I_IT_PT );
    } else {
	if ( Register_Item(0) != 0xff ) {
	    dmacopy_fg( parameter->icon_itemSegment+I_IT_PT*0,
			(u32)_icon_item_staticSegmentRomStart+((Register_Item(0))*I_IT_PT),
			I_IT_PT );
	}
    }
    if ( Register_Item(1) < 0xf0 ) {
	dmacopy_fg( parameter->icon_itemSegment+I_IT_PT*1,
		    (u32)_icon_item_staticSegmentRomStart+((Register_Item(1))*I_IT_PT),
		    I_IT_PT );
    }
    if ( Register_Item(2) < 0xf0 ) {
	dmacopy_fg( parameter->icon_itemSegment+I_IT_PT*2,
		    (u32)_icon_item_staticSegmentRomStart+((Register_Item(2))*I_IT_PT),
		    I_IT_PT );
    }
    if ( Register_Item(3) < 0xf0 ) {
	dmacopy_fg( parameter->icon_itemSegment+I_IT_PT*3,
		    (u32)_icon_item_staticSegmentRomStart+((Register_Item(3))*I_IT_PT),
		    I_IT_PT );
    }




    PRINTF("ＥＶＥＮＴ＝%d\n",ZCommonGet( event_fg ));
    if ( ZCommonGet( event_fg ) == Event_MD4 ||
	 ZCommonGet( event_fg ) == Event_MD20 ||
	 ZCommonGet( total_event_fg ) == TEvent_MD4 ||
	 ZCommonGet( total_event_fg ) == TEvent_MD14) {
	PRINTF("restart_flag=%d\n",ZCommonGet( game_info.restart_flag ) );
	if ( ZCommonGet( game_info.restart_flag ) == -1 || ZCommonGet( game_info.restart_flag ) == (RESTART_MODE_DOWN + 1) ) {
	    if (ZCommonGet( event_fg ) == Event_MD4 ) {
		EVENT_FG = Event_MD1;
		ZCommonSet( event_xp[0], 140 );	/* タイマー表示Ｘ位置 */
		ZCommonSet( event_yp[0],  80 );	/* タイマー表示Ｙ位置 */
	    }
	}
	if ( ZCommonGet( event_fg ) == Event_MD4 || ZCommonGet( event_fg ) == Event_MD20 ) event_pt = 0;
	else                                                                               event_pt = 1;
	ZCommonSet( event_xp[event_pt], 26 );	/* タイマー表示Ｘ位置 */
	if ( S_Private.max_life > LIFE_CT*10 )  ZCommonSet( event_yp[event_pt], 54);
	else                                    ZCommonSet( event_yp[event_pt], 46);
    }
    if ( ZCommonGet( event_fg ) >= Event_MD30 && ZCommonGet( event_fg ) <= Event_MD34 ) {
	/* タイマー停止 */
	ZCommonSet( event_fg, Event_MD0 );
	PRINTF("タイマー停止！！！！！！！！！！！！！！！！！！！！！  = %d\n",ZCommonGet( event_fg ));
    }


    PRINTF("ＰＡＲＡＭＥＴＥＲ領域＝%x\n",size0+(G_B_PT*2)+(I_IT_PT*4)+4096);

    initial_LifeMeterColorAnimation( game_play );


    /* ＭＡＰ */
    map_exp_ct( game_play );


    /* 流鏑馬関係 */
    parameter->yabusame_score =
	parameter->yabu_score = 0;

# if 0
    TREG(10) = 1;	/* ボタン配置 */
# endif

/*    if ( !TREG(10) ) {*/
# if 0
	/* Ｂボタンアクション  Ａボタン剣 */
	ZREG(70) = 196;		//ＡボタンＸ位置
	ZREG(43) = 90;		//Ａボタン背景Ｐｒｉｍ（Ｒ）
	ZREG(44) = 90;      	//                    （Ｇ）
	ZREG(45) = 255;     	//                    （Ｂ）
	ZREG(82) = 196;		//ＡアイテムＸ
	VREG(64) = 198;		// アイテム数Ｘ（Ａ）
	
	XREG(17) = 158;		//Ｂボタン背景 Ｌｅｆｔ位置
	XREG(20) = 158;		//Ｂボタンアイテム Ｌｅｆｔ位置
	XREG(22) = 0;		//Ｂボタン背景Ｐｒｉｍ（Ｒ）
	XREG(23) = 150;		//                    （Ｇ）
	XREG(24) = 0;		//                    （Ｂ）
# else
/*	} else {*/
	/* Ｂボタン剣  Ａボタンアクション */
	ZREG(70) = 160;		//ＢボタンＸ位置
	ZREG(43) = 0;		//Ｂボタン背景Ｐｒｉｍ（Ｒ）
	ZREG(44) = 150;      	//                    （Ｇ）
	ZREG(45) = 0;     	//                    （Ｂ）
	ZREG(82) = 160;		//ＢアイテムＸ
	VREG(64) = 162;		// アイテム数Ｘ（Ａ）
	
	XREG(17) = 186;		//Ａボタン背景 Ｌｅｆｔ位置
	XREG(20) = 186;		//Ａボタンアイテム Ｌｅｆｔ位置
	XREG(22) = 90;		//Ａボタン背景Ｐｒｉｍ（Ｒ）
	XREG(23) = 90;		//                    （Ｇ）
	XREG(24) = 255;		//                    （Ｂ）
# endif
/*	}*/

}




/************************************************************************
 *									*
 *	メッセージ クラス コンストラクト				*
 *									*
 ************************************************************************/
extern void
message_ct( Game_play *game_play )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

#if 01
    message_tbl_p_init();		/* メッセージポインタ初期化 */
#endif
    
    OCARINA_MODE( game_play ) = Oca_Null;
    message->msg_mode = M_NULL;
    message->msg_data = NULL;
    message->msgno =
	message->select =
	message->sel_pnt =
	message->ocarina_no =
	message->nonono_fg = 0;


    message->color_a = 255;
    
    view_init(&message->view, game_play->g.graph);

    message->fukidashiSegment = (char *)game_alloc( &game_play->g, ((size_t)((128*64)/2) + 96*48) );
    PRINTF("message->fukidashiSegment=%x\n",message->fukidashiSegment);
    PRINTF("吹き出しgame_alloc=%x\n",((128*64)/2) + (96*48));
    assert(message->fukidashiSegment != NULL);

    /* 文字フォント セット */
    kscope_kanfont_get( kanfont );

    YREG(31) = 0;	/* お店会話フラグＯＦＦ */
}



/************************************************************************
 *									*
 *	ＹＲＥＧデータ コンストラクト					*
 *									*
 ************************************************************************/
static void
YREG_data_ct( void )
{
    YREG(8) = 10;		// ＫＥＹ連続入力フレーム
    YREG(14) = 0;		// 時の間オカリナデバック用コード
    YREG(15) = 0;  		// シーンＴＹＰＥ

    YREG(16) = 0;  		// 吹き出しサイズＸ
    YREG(17) = 0;  		//         サイズＹ
    YREG(22) = 50;		// 吹き出しサイズＸ
    YREG(23) = 0;       	//         サイズＹ  

    YREG(24) = -60;		// カレイド『右の画面へ→』Ｘ位置
    YREG(25) = 13;		//         『Ａでメロディ表示』Ｘ位置
    YREG(26) = 15;		//         『Ａでセット』Ｘ位置
    YREG(27) = 41;		//         『Ｃでセット』Ｘ位置
    YREG(28) = 15;		//         『Ｂで決定』Ｘ位置



//    YREG(31) = 0;		// お店会話フラグ

    YREG(32) = 265;	//
    YREG(33) = 55;	//
    YREG(34) = 0;    	//
    YREG(35) = 20;	//
    YREG(36) = 0;	//
    YREG(37) = 0;	//
    YREG(38) = 0;	//

    /********************  z_parameter.c  ********************/
    YREG(40) = 2;		/* 魔法メーター点滅カウンター ０ */
    YREG(41) = 1;		/*                            １ */
    YREG(42) = 2;		/*                            ２ */
    YREG(43) = 1;		/*                            ３ */

    /********************  z_vr_box.c  ********************/
    YREG(44) = 0;		// ＶＲーＢＯＸ アングルＸ
    YREG(45) = 236;		//		        Ｙ
    YREG(46) = 36;		//			Ｚ
    
    /********************  z_.c  ********************/
    YREG(47) = 0;	//

    YREG(48) = -45;		// 『Ｃでセット』Ｘ位置
    YREG(49) = -48;		//
    YREG(50) = 16;		// 『Ａ』Ｘサイズ
    YREG(51) = 22;		//
    YREG(52) = -55;		// 『Ａでメロディ表示』Ｘ位置
    YREG(53) = -53;		//
    YREG(54) = 43;		// 『Ｃ』Ｘサイズ 
    YREG(55) = 47;		//
    YREG(56) = -33;		// 『Ａで決定』表示Ｘ 
    YREG(57) = -42;		//
    YREG(58) = -33;		// 『Ａでセット』Ｘ位置
    YREG(59) = -37;		//

    YREG(60) = 14;
    YREG(61) = -2;
    YREG(62) = -2;
    YREG(63) = -18;
    YREG(64) = -18;
    
    YREG(67) = 0;
    YREG(68) = 0;
    YREG(69) = 0;
    YREG(70) = 0;

    YREG(71) = -6;		// メッセージ（２４）アイテムＸ補正
    YREG(72) = 10;		//                           Ｙ補正
    YREG(73) = -8;	        // メッセージ（３２）アイテムＸ補正
    YREG(74) = 8;	        //                           Ｙ補正
    YREG(75) = 24;		// メッセージ（２４）アイテムサイズ
    YREG(76) = 32;		// メッセージ（３２）アイテムサイズ
    YREG(77) = 0;	//
    YREG(78) = 0;	//
    YREG(79) = 0x30;		// デバック用メッセージＮｏ．

    /********************  z_gameover.c  ********************/
    /*  */
    YREG(80) = 450;
    YREG(81) = 0;
    YREG(82) = -15;
    YREG(83) = 500;
    YREG(84) = 600;
    YREG(85) = 0;
    YREG(86) = -21;
    YREG(87) = 510;

    /********************  z_.c  ********************/
    YREG(88) = 247;	//
    YREG(89) = 20;	//

    /********************  z_parameter.c  ********************/
    /* ハート点滅カウンタ */
    YREG(92) = 8;
    YREG(93) = 6;
    YREG(94) = 3;
    YREG(95) = 1;
 
    /****************************************/
    /****************************************/
    /****************************************/
    /****************************************/
    /****************************************/
    ZREG(0) = 0;		// 魔法メーター ＰＲＩＭーＲ
    ZREG(1) = 200;		//                        Ｇ
    ZREG(2) = 0;		//                        Ｂ
//    ZREG(3) = 0;		// ファイル選択コースＮＯ.
 
//    ZREG(4) = 0;
//    ZREG(5) = 0;
//    ZREG(6) = 0;
     /* z_gameover.c */
//    ZREG(7) = 90;		/* ゲームオーバー フレームＲ */
//    ZREG(8) = 20;		/*                        Ｇ */
    ZREG(9) = 140;		/*                        Ｂ */
    ZREG(10) = 200;		/*                        Ａ */
    /* z_kaleido_scope.c */
    ZREG(11) = 0;		/* カーソルＹ軸回転速度 */
    ZREG(12) = 200; 		/* スケール */
    ZREG(13) = 0;		/* カレイド・スコープ 回転デバックフラグ */
    /* z_parameter.c */
    ZREG(14) = 110;		/* 鞭メーター表示Ｘ */
    ZREG(15) = 56;		/*               Ｙ */

    /* z_message.c */
    ZREG(16) = 1;		/* z_message.c: */
    /* z_gameover.c */
    ZREG(17) = -50;    		/* ライト Ｘ */
    ZREG(18) = -200; 		/*        Ｙ */
    ZREG(19) = 0;		/*        Ｚ */
    ZREG(20) = 0;		/* 目位置 Ｘ */
    ZREG(21) = 50;		/*        Ｙ */
    ZREG(22) = -50;		/*        Ｚ */
    /* z_kaleido_*.c */
    ZREG(23) = 20;		/* ハート点滅カウンター */
    ZREG(24) = 20;		/*                     ０ */
    ZREG(25) = 4;		/*                     １ */
    ZREG(26) = 20;		/*                     ２ */
    ZREG(27) = 10;		/*                     ３ */
    ZREG(28) = 20;		/*  カーソル点滅カウンター ０ */
    ZREG(29) = 4;		/*                         １ */
    ZREG(30) = 20;		/*                         ２ */
    ZREG(31) = 10;		/*                         ３ */
  
    /* z_parameter.c */
    ZREG(32) = 0;
    ZREG(33) = 0;
    ZREG(34) = 0;
    ZREG(36) = 0;
    ZREG(37) = 0;
    ZREG(38) = 0;

    ZREG(39) = 255;		//Ｃボタン背景Ｐｒｉｍ（Ｒ）
    ZREG(40) = 160;     	//                    （Ｇ）
    ZREG(41) = 0;		//		      （Ｂ）
////////    ZREG(43) = 90;		//Ａボタン背景Ｐｒｉｍ（Ｒ）
////////    ZREG(44) = 90;      	//                    （Ｇ）
////////    ZREG(45) = 255;     	//                    （Ｂ）
    ZREG(46) = 1;		// カレイド・スコープSTART-SCROLLスピード
    ZREG(47) = 1;		//                   START-SCROLLスピード

#if defined(PAL_VERSION)
    ZREG(48) = 100;
    ZREG(49) = 89;
    ZREG(50) = 92;

    ZREG(51) = 20;
    ZREG(52) = 20;
    ZREG(53) = 20;

    ZREG(54) = 120;
    ZREG(55) = 119;
    ZREG(56) = 119;

#else
    ZREG(49) = 86;
    ZREG(50) = 100;
    ZREG(51) = 0;
    ZREG(52) = 0;

    ZREG(53) = 21;
    ZREG(54) = 20;

    ZREG(55) = 122;
    ZREG(56) = 120;
#endif

# if 0
    ZREG(48) = 20;		// ＥＱＵＩＰ面 子供リンクＸ
    ZREG(49) = -1300;	        //                        Ｙ
    ZREG(50) = -1500;	        //                        Ｚ
    ZREG(51) = 46;	        //                        スケール
    ZREG(52) = 250;	        //              大人リンクＸ
    ZREG(53) = -2280;	        //                        Ｙ
    ZREG(54) = 600;	        //                        Ｚ
    ZREG(55) = 56;	        //                        スケール
    ZREG(56) = 200;	        //              巨人のナイフＸ
    ZREG(57) = -1800;	        //                          Ｙ 
    ZREG(58) = -400;	        //                          Ｚ
    ZREG(59) = 47;	        //                        スケール
    ZREG(60) = 32300;	        //              Ａｎｇｌｅ
# endif
    
    ZREG(61) = 1;		//
    ZREG(62) = 254;		// ナヴィボタンＸ
    ZREG(63) = 16;		//             Ｙ
    ZREG(64) = 20;	//
    ZREG(65) = 21;		// 『もどる』Ｘ
    ZREG(66) = 122;		//           Ｙ
    
////////////////    ZREG(68) = 132;		// スタートボタンＸ
 ////////////////   ZREG(69) = 17;		//               Ｙ

////////    ZREG(70) = 196;		//ＡボタンＸ
    ZREG(71) = 227;		//Ｃ左
    ZREG(72) = 249;		//Ｃ下
    ZREG(73) = 271;		//Ｃ右
    ZREG(74) = 17; 		//ＡボタンＹ
    ZREG(75) = 18;		//Ｃ左
    ZREG(76) = 34;		//Ｃ下
    ZREG(77) = 18;		//Ｃ右
    ZREG(78) = 575;		//Ａボタンスケール
    ZREG(79) = 620;		//Ｃ左
    ZREG(80) = 620;		//Ｃ下
    ZREG(81) = 620;		//Ｃ右

////////    ZREG(82) = 196;		//ＡアイテムＸ
    ZREG(83) = 227;		//Ｃ左
    ZREG(84) = 249;		//Ｃ下
    ZREG(85) = 271;		//Ｃ右
    ZREG(86) = 17; 		//ＡアイテムＹ
    ZREG(87) = 18;		//Ｃ左
    ZREG(88) = 34;		//Ｃ下
    ZREG(89) = 18;		//Ｃ右
    ZREG(90) = 550;		//Ａアイテムスケール
    ZREG(91) = 680;		//Ｃ左
    ZREG(92) = 680;		//Ｃ下
    ZREG(93) = 680;		//Ｃ右

    ZREG(94) = 1;
    
    ZREG(95) = 0;		//ＶＲーＢＯＸコリジョン表示ＯＮ／ＯＦＦ

    /*
     * ＸＲＥＧ
     */
    XREG(0) = 26;		//Ａボタンアイテムサイズ
    XREG(1) = 22;		//Ｃボタンアイテムサイズ
    XREG(2) = -11;		//Ａボタン位置アイテム数位置
    XREG(3) = -4;		//Ｃボタン位置アイテム数位置
    XREG(4) = 3;		//ボタン背景種類（０、１、２）
    XREG(5) = 0;		//使用禁止アイテムalpha値
    XREG(6) = 2;		/* カレイド・スコープＷａｉｔフレーム */
    XREG(7) = 30; 		/*                   ３Ｄステック入力Ａｎｇｌｅ */
    XREG(8) = 10; 		//            ３
    XREG(9) = 0;		/*   */
    XREG(10) = -9550;		//ドキドキＸ位置
    XREG(11) = 9950;		//        Ｙ位置
    XREG(12) = 68;		//        サイズ
    XREG(13) = 36;		//１アニメーションフレーム
    XREG(14) = 4;		//ドキドキフレーム
    XREG(15) = 1;		//ＰＲＩＭ,ＥＮＶカラー切替

    XREG(16) = 9;		//Ｂボタン背景 Ｔｏｐ位置
////////    XREG(17) = 158;		//             Ｌｅｆｔ位置
    XREG(18) = -380;		// Ｂボタン背景サイズ
    XREG(19) = 9;		//Ｂボタンアイテム Ｔｏｐ位置
////////    XREG(20) = 158;		//                 Ｌｅｆｔ位置

    XREG(21) = 48;		//ＢボタンアイテムＸサイズ
////////    XREG(22) = 0;		//Ｂボタン背景Ｐｒｉｍ（Ｒ）
////////    XREG(23) = 150;		//                    （Ｇ）
////////    XREG(24) = 0;		//                    （Ｂ）
    XREG(25) = 0;
    XREG(26) = 0;
    XREG(27) = 0;
    XREG(28) = 16;		//ＢボタンアイテムＹサイズ
    XREG(29) = 50;		//ドキドキ速度 １６０
    XREG(30) = 15;		//             １２０ｕｐ
    XREG(31) = 8;		//		 ８０ｕｐ
    XREG(32) = 4;		//               ４０ｕｐ
    XREG(33) = 2;		//             基本
    XREG(34) = 100;		//カメラぐらぐら スピード
    XREG(35) = 7;		//               縦揺れ
    XREG(36) = 20;		//               横揺れ
    XREG(37) = 10;		//		 パース
    XREG(38) = 2;		//               フレーム
    XREG(39) = 140;		// 黄色切替位置
    XREG(40) = 20;		// 赤色切替位置
    XREG(41) = 300;		// １アニメーションフレーム（ドキドキ速度 １６０）
    XREG(42) = 100;		//                         （             １２０ｕｐ）
    XREG(43) = 70;		//                         （             ８０ｕｐ
    XREG(44) = 50;		//                         （             ４０ｕｐ
    XREG(45) = 36;		//                         （             基本
    XREG(46) = 16;		//
    XREG(47) = 8;		//

    XREG(48) = 34;		//魔法メーター器（Ｙ位置）
    XREG(49) = 18;		//              （Ｘ位置）
    XREG(50) = 42;		//		（Ｙ位置）
    XREG(51) = 26;		//              （Ｘ位置）
    XREG(52) = 0;		//            ＭＡＸ値
    XREG(53) = 1;		//            値

    XREG(54) = 65;		// メッセージ表示位置Ｘ
    XREG(55) = 60; 		//                   Ｙ
    XREG(56) = 16;		// １行サイズ
////////    XREG(57) = 13;		// 文字サイズ
////////    XREG(58) = 650;		// 文字スケール
    XREG(57) = 80;		// 文字サイズ
    XREG(58) = 80;		// 文字スケール
    XREG(59) = 12;		// 文字Ｘ幅
    XREG(60) = 1;		// 文字ズレサイズ
    XREG(61) = 3;		// １枚絵表示位置Ｙ
    XREG(62) = 0;

    XREG(63) = 100;		// パラメーター半透明ａｌｐｈａ値

    XREG(64) = 158;		// 改行・終了マーク（Ｘ位置）
    XREG(65) = 102; //96;  	//                 （Ｙ位置）
    XREG(66) = 48;		// 選択カーソル（Ｘ位置）
    XREG(67) = 54;		// ３択時（Ｙ位置０）
    XREG(68) = 70;		//       （Ｙ位置１）２択時（Ｙ位置０）
    XREG(69) = 86;		//       （Ｙ位置２）      （Ｙ位置１）
    XREG(70) = -300; //-40;	// 上段下段切替位置
    XREG(71) = 0;		// メッセージＹ位置

    XREG(72) = 54;
    XREG(73) = 48;
    XREG(74) = 128;
    XREG(75) = 64;
    XREG(76) = 256*8;
    XREG(77) = 64*8;
    XREG(78) = 96;	
    XREG(79) = 98;

////////    XREG(80) = 25;	//ドキドキＵＰ値（走る）
    XREG(80) = 0;		//ドキドキＵＰ値（走る）
    XREG(81) = 50;		//              （剣振る）
    XREG(82) = 25;		//              （剣溜め中）
    XREG(83) = 100;		//              （敵と接触）
    XREG(84) = 100;		//              （びっくりイベント）

    XREG(85) = 0;		// ＶＲ＿ＢＯＸ  Matrix_translate（Ｘ）
    XREG(86) = 0;		//                               （Ｙ）
    XREG(87) = 0;		//                               （Ｚ）
 
    XREG(88) = -50;		//ドキドキＤＯＷＮ値（歩く）
    XREG(89) = -100;		//                  （停止）
    XREG(90) = -500;		//                  （落ち着きイベント）

    XREG(91) = 0;	//
    
    XREG(92) = 100;		// 吹き出し表示位置チェックＹ（ＶＲーＢＯＸ）
    XREG(93) = 100;		// 吹き出し表示位置チェックＹ（マーケット【昼夜】）
    XREG(94) = 160; /*100 (10/05/19変更) */	// 吹き出し表示位置チェックＹ
 
    XREG(95) = 200;		// アクティブハートタイマー

    /*
     * ＷＲＥＧ
     */
    WREG(2) = -6080;		// Matrix_translate
    WREG(3) = 9355;		// Matrix_translate
    WREG(4) = 8;		// 出現時カウンタ
    WREG(5) = 3;		// ＤＯアクション回転速度
    WREG(6) = 8;		// ＤＯアクション回転速度（フレーム）*/
    WREG(7) = 0;		// Ｂボタンbutton_ud_rotate

    WREG(8) = 100;
    WREG(9) = 109;
    WREG(10) = 151;
    WREG(11) = 148;
    WREG(12) = 23;
    WREG(13) = 22;

    WREG(14) = -380;
    WREG(15) = -350;

    WREG(16) = -175;		// カレイド・スコープＺ・Ｘ値
    WREG(17) = 155;		//                   Ｒ・Ｘ値
    WREG(18) = 10;		//                       Ｙ値
    
    WREG(19) = 10;		// ＳＡＶＥ面回転速度
    WREG(20) = -50;		// カレイド面『Ｃでセット』表示Ｘ
    WREG(21) = -54;		//           『Ａで切り替え』表示Ｘ
    WREG(22) = -32;		//           『Ｂで決定』表示Ｘ
    WREG(23) = -38;		//           『Ａでセット』表示Ｘ
    WREG(24) = -36;		//           『ＺＲ で回転』表示Ｘ
 
    WREG(25) = 40;		// カレイド・スコープＺスクロール値
    WREG(26) = -40;		//                   Ｒスクロール値
    WREG(27) = 0;
    WREG(28) = 0;

    WREG(29) = 238; //204;	// 地上ＭＡＰ表示Ｘ
    WREG(30) = 164; //140;	//               Ｙ
    WREG(31) = 0;		//           on/offフラグ
 
    WREG(32) = 122;		// 流鏑馬
    WREG(33) = 60;		// 流鏑馬

    WREG(35) = 0;		/* TOTAL_EVENT タイマー表示Ｘ位置 */
    WREG(36) = 0;		/*                     表示Ｙ位置 */
    
    
#if defined(PAL_VERSION)    
    WREG(37) = 100;
    WREG(38) = 99;
    WREG(39) = 109;

    WREG(40) = 151;
    WREG(41) = 149;
    WREG(42) = 148;

    WREG(43) = 23;
    WREG(44) = 22;
    WREG(45) = 22;

    WREG(46) = -380;
    WREG(47) = -360;
    WREG(48) = -350;

    WREG(49) = -48;		// 『Ｃでセット』Ｘ位置
    WREG(50) =  16;		//
    WREG(51) = -62;		//
    WREG(52) =  22;		// 『Ａ』Ｘサイズ
    WREG(53) = -84;		//
    WREG(54) =  20;		//
    WREG(55) = -53;		// 『Ａでメロディ表示』Ｘ位置
    WREG(56) =  40;		//
    WREG(57) = -64;		//
    WREG(58) =  47;		// 『Ｃ』Ｘサイズ 
    WREG(59) = -84;		//
    WREG(60) =  44;		//
    WREG(61) = -42;		// 『Ａで決定』表示Ｘ 
    WREG(62) =  32;		//
    WREG(63) = -45;		//
    WREG(64) = -37;		// 『Ａでセット』Ｘ位置
    WREG(65) =  30;		//
    WREG(66) = -50;		//

#endif  
    
    
    WREG(68) = 204;		// ダンジョンＭＡＰ表示位置Ｘ
    WREG(69) = 140;		//                         Ｙ

    WREG(87) = 80;		//
    WREG(88) = 70;		//
    WREG(89) = 40;		//
    WREG(90) = 320;		//
    WREG(91) = 40;		//

    WREG(92) = 3;
    WREG(93) = 6;
    WREG(94) = 3;
    WREG(95) = 6;

    /*
     * ＶＲＥＧ
     */
    if ( z_common_data.game_info.mode == GAME_INFO_GAME ) {
    VREG(0) = 52;		// 吹き出しＸ位置
    VREG(1) = 36;		//         Ｙ位置
    VREG(2) = 214;		//         サイズＸ
    VREG(3) = 76;		//               Ｙ
    VREG(4) = 304;		//         シフトＳ
    VREG(5) = 430;		//               Ｔ
    VREG(6) = 1;		//         シフト
    VREG(7) = 78;		// ト音記号Ｘ
    VREG(8) = 166;		//         Ｙ
    VREG(9) = 40;	//
////////    VREG(10) = 0;	// ＭＡＰデータ部屋ＮＯ。
////////    Scene_ID = 0;	// ＭＡＰデータポインター
////////    VREG(12) = 0;	// ＭＡＰデータ（基本）
////////    VREG(13) = 0;	// ＭＡＰデータ（出力中）
    VREG(14) = 32;		// ＭＡＰコンパス（Ｘ補正値）
    VREG(15) = 32;		// ＭＡＰコンパス（Ｙ補正値）
    VREG(16) = 110;		// ＭＡＰコンパス（translateＸ）
    VREG(17) = -740;		// ＭＡＰコンパス（translateＹ）

    VREG(18) =   0; //170;		// 地上ＭＡＰ ＰＲＩＭ─Ｒ
    VREG(19) = 255; //190;		//                      Ｇ
    VREG(20) = 255; //255;		//                      Ｂ
    }

    VREG(21) = 0;		// 音符表示ＡＹ位置
    VREG(22) = 0;		//         Ｃ下
    VREG(23) = 0;		//         Ｃ右
    VREG(24) = 0;		//         Ｃ左
    VREG(25) = 0;		//         Ｃ上
    
    VREG(26) = 0;		// アイテムＭＡＰｏｎ／ｏｆｆ
    VREG(27) = 0;		// アイテムコンパスｏｎ／ｏｆｆ

    VREG(28) = 98;		// 音符Ｘ
    VREG(29) = 18;		//     Ｙ

    VREG(30) = 0;		// リンク階情報

    VREG(31) = 0;
    VREG(32) = 0;

    VREG(33) = 70;		// メッセージＰＲＩＭ─Ｒ
    VREG(34) = 255;		//                     Ｇ
    VREG(35) = 80;		//                     Ｂ
    VREG(36) = 70;		//                     Ｒ
    VREG(37) = 255;		//                     Ｇ
    VREG(38) = 80;              //                     Ｂ
    VREG(40) = 9;		/* タイマー表示Ｘサイズ */
    VREG(42) = 250;		/* タイマー表示Ｙサイズ */
    VREG(43) = 440;		/* スケール */
    VREG(44) = 10;		/* サイズ */
    VREG(45) = 190;		// 音符表示ＡＹ位置
    VREG(46) = 184;		//         Ｃ下
    VREG(47) = 176;		//         Ｃ右
    VREG(48) = 172;		//         Ｃ左
    VREG(49) = 170;		//         Ｃ上
    VREG(50) = 30;		// 音符ＡＬＰＨＡ速度
    VREG(51) = 0;		// 音符落下速度

    VREG(52) = -16;

    VREG(53) = 230;		// 拡大ＭＡＰＸシフト
    VREG(54) = 230;		//           Ｙ
    VREG(55) = 120;		//           Ｘ位置
    VREG(56) = -720;		//           Ｙ位置

    VREG(57) = 255;		// ＭＡＰ面 雲Ｒ
    VREG(58) = 255;		//            Ｇ
    VREG(59) = 255;		//            Ｂ

    VREG(60) = 20;		// ＳＡＶＥ面 カウンタ値
    VREG(61) = 100;		//            カーソルＡｌｐｈａ
    VREG(62) = 0;		//            ポインタ
    VREG(63) = 10;		//            カウンタ
    
////////    VREG(64) = 198;		// アイテム数Ｘ（Ａ）
    VREG(65) = 228;		//             （Ｃ左）
    VREG(66) = 250;		//             （  下）
    VREG(67) = 272;		//             （  右）
    VREG(68) = 35;		// アイテム数Ｙ（Ａ）
    VREG(69) = 35;		//             （Ｃ左）
    VREG(70) = 51;		//             （  下）
    VREG(71) = 35;		//             （  右）
    VREG(72) = 0;
    VREG(73) = 0;
    VREG(74) = 0;
    VREG(75) = 0;
    
    VREG(76) = 30;		//Ａアイテムサイズ
    VREG(77) = 24;		//Ｃ左
    VREG(78) = 24;		//Ｃ下
    VREG(79) = 24;		//Ｃ右
    VREG(80) = 29;		//Ａボタンサイズ
    VREG(81) = 27;		//Ｃ左
    VREG(82) = 27;		//Ｃ下
    VREG(83) = 27;		//Ｃ右

    VREG(84) = 0;

    VREG(85) = 50;		// ＧＡＭＥ・ＯＶＥＲ カウンタ

    VREG(86) = 0;

    VREG(87) = 64;		// ＧＡＭＥ・ＯＶＥＲ 表示Ｘ
    VREG(88) = 66;		//                        Ｙ
    VREG(89) = 0;		//                        Ｌｏｏｐカウンタ
    VREG(90) = 126;		//
    VREG(91) = 124;		//
    VREG(92) = -63;		//

////////    VREG(93) = 0;
////////    VREG(94) = 0;		// 地形Ｏｎ／Ｏｆｆ
////////    VREG(95) = 0;		// ＶＲーＢｏｘ Ｏｎ／Ｏｆｆ
}

/************************************************************************
 *									*
 *	セーブ・エリア コンストラクト					*
 *									*
 ************************************************************************/
extern void
save_area_ct( Game_play *game_play )
{
    game_play;
    
    /* ＹＲＥＧデータ コンストラクト */
    YREG_data_ct( );
}


