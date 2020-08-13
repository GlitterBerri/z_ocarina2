/*
 * $Id: z_message.c,v 2.4 2001/04/04 07:21:47 zelda Exp $
 *
 * メッセージ
 *
 * $Log: z_message.c,v $
 * Revision 2.4  2001/04/04  07:21:47  zelda
 * ドルフィンエミュレータ用仮ぐみ版 CICと64DD対応部分をはずしたバージョン
 *
 * Revision 2.3  1998-11-12 16:26:23+09  soejima
 * *** empty log message ***
 *
 * Revision 2.2  1998-11-09 14:01:46+09  soejima
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.537  1998/10/17 07:05:06  soejima
 * *** empty log message ***
 *
 * Revision 1.536  1998-10-16 18:14:11+09  soejima
 * *** empty log message ***
 *
 * Revision 1.535  1998-10-15 17:50:28+09  soejima
 * *** empty log message ***
 *
 * Revision 1.534  1998-10-15 15:51:04+09  hayakawa
 * ＤＤ対応
 *
 * Revision 1.533  1998-10-15 15:43:53+09  soejima
 * *** empty log message ***
 *
 * Revision 1.532  1998-10-14 19:49:02+09  soejima
 * *** empty log message ***
 *
 * Revision 1.531  1998-10-14 17:20:14+09  soejima
 * *** empty log message ***
 *
 * Revision 1.530  1998-10-13 23:08:00+09  soejima
 * *** empty log message ***
 *
 * Revision 1.529  1998-10-12 23:08:25+09  soejima
 * *** empty log message ***
 *
 * Revision 1.528  1998-10-10 22:56:01+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/10/02  06:17:16  soejima
 * Initial revision
 * $Log追加
 *
 */


/************************************************************************
 *									*
 *	ゼルダ６４ メッセージ						*
 *				1996年 9月 9日(月曜日) 18時00分00秒 JST *
 *									*
 ************************************************************************/
#include "z_basic.h"
#include "audio.h"
#include "z_play.h"
#include "z_player.h"
#include "z_actor.h"
#include"z_actor_files.h"
#include "gfxprint.h"		/* gfxprint */
#include "assert64.h"		/* assert */
#include "z_common_data.h"
#include "z_scene_table.h"

#include "z_message_h.h"
#include "z_message_tbl.h"
#include "z_parameter_h.h"
#include "z_parameterd.h"
#include "z_define1.h"
#include "z_save_area_h.h"
#include "z_kaleido_moji.h"
#include "gfxalloc.h"		/* gfxopen/gfxclose */
#include"z_en_in.h"

#if defined(USE_N64DD)
#include "z_n64dd_function.h"
#endif /* defined(USE_N64DD) */

EXTERN_DEFSEG_DATA(parameter_static);
EXTERN_DEFSEG_DATA(message_static);
EXTERN_DEFSEG_DATA(message_data_static);
EXTERN_DEFSEG_DATA(message_texture_static);
EXTERN_DEFSEG_DATA(nes_message_data_static);
EXTERN_DEFSEG_DATA(staff_message_data_static);
EXTERN_DEFSEG_DATA(icon_item_static);
EXTERN_DEFSEG_DATA(icon_item_24_static);

/* オカリナ */
extern NA_OCARINA_MELODY_DATA na_oca_note[6];

#define CAMERA_FG	0


static short	key_off_flag = 0;
static char	start_flag = 0;
static int	size, scale;
static short 	onpu_pt = 0, onpu_ct = 0;
static char	last_flag = 0;
static unshort	next_msg_no = 0;
static short	staff_mode = 0;
static short	Chk_Ocarina_No = 0xff;
static short	SunMoon_Ocarina = 0;
static short	se_flag = 0;
static unshort	ocarina_bit = 0;




/************************************************************************
 *	メッセージ データ テーブル					*
 *	------ msg.tbl ------						*
 *	ＮＥＳ版メッセージ データ テーブル				*
 *	------ nes_b ------						*
 *	ＳＴＡＦＦ版メッセージ データ テーブル				*
 *	------ staff_b ------						*
 ************************************************************************/
#include "../data/msg.tbl"
#include "../data/nes_b"
#include "../data/staff_b"


static MSG_T *message_tbl_p = message_tbl;
static MSG_NT *message_tbl_nes_p = message_tbl_nes;
static MSG_NT *message_tbl_staff_p = message_tbl_staff;



/*===============================================================
  =								=
  ===============================================================*/
static short mes_board_prim_dt[][3] = {
    { 255, 255, 255, },
    {  50,  20,   0, },
    { 255,  60,   0, },
    { 255, 255, 255, },
    { 255, 255, 255, },
    { 255, 255, 255, },
    { 255, 255, 255, },
    { 255, 255, 255, },
};
static short mes_board_shadow_dt[][3] = {
    {   0,   0,   0, },
    { 220, 150,   0, },
    {   0,   0,   0, },
    {   0,   0,   0, },
};
static short mes_board_shift_dt[] = {
    1, 2,
};





/*===============================================================
  =								=
  ===============================================================*/
static unchar onpu_buff[] = {	/* 音符バッファ */
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static short onpu_alpha[] = {	/* 音符Ａｌｐｈａ */
    0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static short	onpu_par, onpu_pab, onpu_pag;	/* 音符Ａ Ｐｒｉｍカラー */
static short	onpu_ear, onpu_eab, onpu_eag;	/*        Ｅｎｖカラー */
static short	onpu_pcr, onpu_pcb, onpu_pcg;	/* 音符Ｃ Ｐｒｉｍカラー */
static short	onpu_ecr, onpu_ecb, onpu_ecg;	/*        Ｅｎｖカラー */

extern short ocarina_number[] = {
    NA_OCA_CHK_WIND,
    NA_OCA_CHK_FLAME,
    NA_OCA_CHK_WATER,
    NA_OCA_CHK_SOUL,
    NA_OCA_CHK_DARKNESS,
    NA_OCA_CHK_LIGHT,
    NA_OCA_CHK_ZELDA,
    NA_OCA_CHK_EPONA,
    NA_OCA_CHK_SPIRIT,
    NA_OCA_CHK_SUNMOON,
    NA_OCA_CHK_TIME,
    NA_OCA_CHK_STORM,
};

#define OCARINA_WCT10	10
#define OCARINA_WCT20	20
/*===============================================================
  =	音符バッファ初期化					=
  ===============================================================*/
static void
onpu_buff_reset( void )
{
    VREG(45) = 189;	/* 音符表示ＡＹ */
    VREG(46) = 184;	/*         Ｃ下 */
    VREG(47) = 179;	/*         Ｃ右 */
    VREG(48) = 174;	/*         Ｃ左 */
    VREG(49) = 169;	/*         Ｃ上 */
    onpu_buff[0] = 0xff;
    onpu_alpha[0] =
	onpu_alpha[1] =
	onpu_alpha[2] =
	onpu_alpha[3] =
	onpu_alpha[4] =
	onpu_alpha[5] =
	onpu_alpha[6] =
	onpu_alpha[7] =
	onpu_alpha[8] = 0;
    /* 音符Ａカラー */
    onpu_par = 80;
    onpu_pag = 150;
    onpu_pab = 255;
    onpu_ear = 10;
    onpu_eag = 10;
    onpu_eab = 10;
    /* 音符Ｃカラー */
    onpu_pcr = 255;
    onpu_pcg = 255;
    onpu_pcb = 50;
    onpu_ecr = 10;
    onpu_ecg = 10;
    onpu_ecb = 10;
}


/*===============================================================
  =	輪唱ＮＥＸＴ						=
  ===============================================================*/
extern void
ocarina_round_next( Game_play *game_play )
{
    Message		*message = (Message *)&game_play->message;


////////    if ( message->info->status == NA_OCA_SEQ_STOP ) {
	message->msg_mode++;
	if ( message->msg_mode == M_OCARINA65 ) {
	    Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	    message->info = Na_GetOcarinaInfoWork();
	    message->info->locate = onpu_pt = 0;
	    Na_StartOcarinaSinglePlayCheck2( NA_OCA_CHK_GAME );
	    message->end = message->rd_end;
	} else if ( message->msg_mode == M_OCARINA63 ) {
	    Na_SetOcarinaInst( NA_OCA_INST_PICCOLO );
	    message->info = Na_GetOcarinaSeqInfoWork();
	    message->info->locate = onpu_pt = 0;
	    Na_StartOcarinaSeq( NA_OCA_CHK_GAME, 1 );
	    message->wct = 2;
	}
	/* 音符バッファ初期化 */
	onpu_buff_reset();
////////    }
}










/*===============================================================
  =	ＫＥＹ入力チェック					=
  ===============================================================*/
extern char
pad_on_check( Game_play *game_play )
{
    pad_t		*pad = &game_play->g.pads[0];


    if ( Pad_on_trigger(A_BUTTON) || Pad_on_trigger(B_BUTTON) || Pad_on_trigger(U_CBUTTONS) )
	Na_StartSystemSe( NA_SE_SY_MESSAGE_PASS );

    return( Pad_on_trigger(A_BUTTON) || Pad_on_trigger(B_BUTTON) || Pad_on_trigger(U_CBUTTONS) );
}
/*===============================================================
  =	ＫＥＹ入力チェック					=
  ===============================================================*/
extern char
pad_on_check_0( Game_play *game_play )
{
    pad_t		*pad = &game_play->g.pads[0];

    return( Pad_on_trigger(A_BUTTON) || Pad_on_trigger(B_BUTTON) || Pad_on_trigger(U_CBUTTONS) );
}


/*===============================================================
  =	メッセージＣＬＯＳＥ					=
  ===============================================================*/
extern void
message_close( Game_play *game_play )
{
    Message		*message = (Message *)&game_play->message;

    if ( message->msg_data != NULL ) {
	message->wct = 2;
	message->msg_mode = M_CLOSE;
	message->select = 0;
	Na_StartSystemSe( NA_SE_SY_MESSAGE_WIN_CLOSE );
    }
}


/*===============================================================
  =	選択カーソル処理					=
  ===============================================================*/
static void
arrow_select( Game_play *game_play, char number )
{
    Message		*message = (Message *)&game_play->message;
    
    pad_t		*pad = &game_play->g.pads[0];

# if 0
    static short	wct = 4;


    if ( wct == 0 ) {
	if ( ABS(Pad_stick_y()) >= KEY_ANGLE_3D ) {
	    Na_StartSystemSe( NA_SE_SY_CURSOR );
	    wct = 4;
	    if ( Pad_stick_y() > 0 ) {
		message->sel_pnt--;
		if ( message->sel_pnt > 0x80 ) message->sel_pnt = number;
	    } else {
		message->sel_pnt++;
		if ( message->sel_pnt > number ) message->sel_pnt = 0;
	    }
	}
    } else wct--;
# else
    static short	wct = 0;

    if ( Pad_stick_y() >= KEY_ANGLE_3D && !wct ) {
	wct = 1;
	message->sel_pnt--;
	if ( message->sel_pnt > 0x80 ) message->sel_pnt = 0;
	else Na_StartSystemSe( NA_SE_SY_CURSOR );
    } else if ( Pad_stick_y() <= -KEY_ANGLE_3D && !wct ) {
	wct = 1;
	message->sel_pnt++;
	if ( message->sel_pnt > number ) message->sel_pnt = number;
	else Na_StartSystemSe( NA_SE_SY_CURSOR );
    } else if ( !(ABS(Pad_stick_y()) >= KEY_ANGLE_3D) ) wct = 0;
# endif
    
    message->mxp = XREG(66);
    if ( number == 1 ) message->myp = XREG(68+message->sel_pnt);
    else	       message->myp = XREG(67+message->sel_pnt);
}



/*=======================================================================
  =	メッセージ セット						=
  =======================================================================*/
static void
message_moji_display( Game_play *game_play, unchar *data, Gfx **glistp )
{
    Message		*message = (Message *)&game_play->message;

    Gfx 		*gp = *glistp;

    int 	xpos = (int)message->mxp;
    int 	ypos = (int)message->myp;


    gDPPipeSync( gp++ );
    size = (int)(16.0f * ((float)XREG(57)/100.0f));
    scale = (int)(1024.0f/ ((float)XREG(57)/100.0f));
    gDPLoadTextureBlock_4b( gp++,
			    data, G_IM_FMT_I, 16, 16, 0,
			    G_TX_CLAMP, G_TX_CLAMP,
			    G_TX_NOMASK, G_TX_NOMASK,
			    G_TX_NOLOD, G_TX_NOLOD );
    if ( message->msg_disp_type0 != 0x5 ) {
	/* 影文字 */
	gDPSetPrimColor( gp++, 0, 0, 0, 0, 0, message->color_a);
	gSPTextureRectangle( gp++,
			     (xpos+XREG(60)) << 2, (ypos+XREG(60)) << 2,
////////////////			     xpos+XREG(60) + XREG(57) << 2, ypos+XREG(60) + XREG(57) << 2,
////////////////			     G_TX_RENDERTILE, 0, 0, XREG(58) <<1, XREG(58) << 1 );
			 (xpos + XREG(60) + size) << 2, (ypos + XREG(60) + size) << 2,
			 G_TX_RENDERTILE, 0, 0,  scale, scale );
    }
    /* 正文字 */
    gDPPipeSync( gp++ );
    gDPSetPrimColor( gp++, 0, 0, message->color_r, message->color_g, message->color_b, message->color_a);
    gSPTextureRectangle( gp++,
			 xpos << 2, ypos << 2,
////////////////			 (xpos + XREG(57)) << 2, (ypos + XREG(57)) << 2,
////////////////			 G_TX_RENDERTILE, 0, 0, XREG(58) <<1, XREG(58) << 1 );
			 (xpos + size) << 2, (ypos + size) << 2,
			 G_TX_RENDERTILE, 0, 0,  scale, scale );
    
    *glistp = gp;
}



/*=======================================================================
  =	メッセージ Ｗｉｎｄｏｗ Ｏｐｅｎ／Ｃｌｏｓｅ			=
  =======================================================================*/
static void
window_open( Message *message )
{
    static float	value_x[] = {
/*          0      1      2      3      4      5      6      7 */
	1.20f, 1.50f, 1.80f, 2.00f, 2.10f, 2.20f, 2.10f, 2.00f,
    };
    static float	value_y[] = {
	0.60f, 0.75f, 0.90f, 1.00f, 1.05f, 1.10f, 1.05f, 1.00f,
    };

    float	wxs, wys;		/* ウィンドウ サイズ */
    float	wxz, wyz;		/*	      スケール */

    wxs = (float)XREG(74)*(2.0f*value_x[message->wct]);
    wys = (float)XREG(75)*value_y[message->wct];
    wxz = (float)XREG(76)/(2.0f*value_x[message->wct]);
    wyz = (float)XREG(77)/value_y[message->wct];
/*    VREG(0) = XREG(72) + ((XREG(72) - (short)(XREG(72)*value_y[message->wct] + 0.5f)) * 2);*/
    VREG(1) = XREG(73) + ((XREG(73) - (short)(XREG(73)*value_y[message->wct] + 0.5f)) / 2);
    message->fc_alpha += message->fc_a/8;
    message->wct++;
    if ( message->wct == 8 )  {
	VREG(0) = XREG(72);
	VREG(1) = XREG(73);
	message->msg_mode =  M_WAIT;
	message->fc_alpha = message->fc_a;
    }
    YREG(22) = (short)(wxs + 0.5f) / 2;
    YREG(23) = (short)(wys + 0.5f);
    YREG(16) = (short)(wxz + 0.5f);
    YREG(17) = (short)(wyz + 0.5f);

    VREG(0) = XREG(74) - (YREG(22) / 2) + XREG(72);
}



/*=======================================================================
  =	メッセージデータのアドレス取得					=
  =======================================================================*/
static void
get_msg_add_get( Game_play *game_play, unshort data )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    MSG_T *pnt;
    unchar	*msg_data1, *msg_data2, *msg_data3;

    pnt = message_tbl_p;
    msg_data2 = (unchar *)pnt->msg_add;
    while( pnt->msg_num != 0xFFFF ) {
	if( pnt->msg_num == data ) {
	    /* メッセージが,見つかった！！！ */
	    msg_data1 = (unchar *)pnt->msg_add;
	    kanfont->kbuffer[0] = pnt->msg_tp;		/* ＴＹＰＥ */
	    pnt++;
	    msg_data3 = (unchar *)pnt->msg_add;
	    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
	    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
	    PRINTF(" メッセージが,見つかった！！！ = %x  (data=%x) (data0=%x) (data1=%x) (data2=%x) (data3=%x)\n",data,kanfont->msg_data,kanfont->msg_data0,msg_data1,msg_data2,msg_data3);
	    return;
	}
	pnt++;
    }

    /* メッセージ見つからなかった */
    PRINTF(" メッセージが,見つからなかった！！！ = %x\n",data);
    pnt = message_tbl_p;
    msg_data1 = (unchar *)pnt->msg_add;
    kanfont->kbuffer[0] = pnt->msg_tp;		/* ＴＹＰＥ */
    pnt++;
    msg_data3 = (unchar *)pnt->msg_add;
    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
}
/*=======================================================================
  =	メッセージデータのアドレス取得					=
  =======================================================================*/
static void
get_msg_add_get_NES( Game_play *game_play, unshort data )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    MSG_NT *pnt;
    unchar	*msg_data1, *msg_data2, *msg_data3;


    pnt = message_tbl_nes_p;
    msg_data2 = (unchar *)pnt->msg_add;
    while( pnt->msg_num != 0xFFFF ) {
	if( pnt->msg_num == data ) {
	    /* メッセージが,見つかった！！！ */
	    msg_data1 = (unchar *)pnt->msg_add;
	    kanfont->kbuffer[0] = pnt->msg_tp;		/* ＴＹＰＥ */
	    pnt++;
	    msg_data3 = (unchar *)pnt->msg_add;
	    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
	    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
	    PRINTF(" メッセージが,見つかった！！！ = %x  (data=%x) (data0=%x) (data1=%x) (data2=%x) (data3=%x)\n",data,kanfont->msg_data,kanfont->msg_data0,msg_data1,msg_data2,msg_data3);
	    return;
	}
	pnt++;
    }
    
    /* メッセージ見つからなかった */
    PRINTF(" メッセージが,見つからなかった！！！ = %x\n",data);
    pnt = message_tbl_nes_p;
    msg_data1 = (unchar *)pnt->msg_add;
    kanfont->kbuffer[0] = pnt->msg_tp;		/* ＴＹＰＥ */
    pnt++;
    msg_data3 = (unchar *)pnt->msg_add;
    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
}
/*=======================================================================
  =	メッセージデータのアドレス取得					=
  =======================================================================*/
static void
get_msg_add_get_STAFF( Game_play *game_play, unshort data )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    MSG_NT *pnt;
    unchar	*msg_data1, *msg_data2, *msg_data3;


    pnt = message_tbl_staff_p;
    msg_data2 = (unchar *)pnt->msg_add;
    while( pnt->msg_num != 0xFFFF ) {
	if( pnt->msg_num == data ) {
	    /* メッセージが,見つかった！！！ */
	    msg_data1 = (unchar *)pnt->msg_add;
	    kanfont->kbuffer[0] = pnt->msg_tp;		/* ＴＹＰＥ */
	    pnt++;
	    msg_data3 = (unchar *)pnt->msg_add;
	    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
	    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
	    PRINTF(" メッセージが,見つかった！！！ = %x  (data=%x) (data0=%x) (data1=%x) (data2=%x) (data3=%x)\n",data,kanfont->msg_data,kanfont->msg_data0,msg_data1,msg_data2,msg_data3);
	    return;
	}
	pnt++;
    }
}


/*=======================================================================
  =	文字サイズ ＆ 文字カラー 変更					=
  =======================================================================*/
static void
moji_size_color( Message *message, unshort rd_dt )
{
    /* 文字カラー */
    switch( rd_dt ) {
    case 0x01: /* 赤 */
	if ( message->msg_disp_type0 == 0x1 ) {
	    /* 立て札 */
	    message->color_r = 255; /*255;*/
	    message->color_g = 120; /*80;*/
	    message->color_b = 0;   /*50;*/
# if 0
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    /* ホワイト・ナレーション */
	    message->color_r = 255;
	    message->color_g = 60;
	    message->color_b = 60;
# endif
	} else {
	    /* 通常,ナレーション,字幕 */
	    message->color_r = 255;
	    message->color_g = 60;
	    message->color_b = 60;
	}
	break;
    case 0x02: /* 緑 */
	if ( message->msg_disp_type0 == 0x1 ) {
/*	    message->color_r = 70;
	    message->color_g = 255;
	    message->color_b = 80;	*/
	    message->color_r = VREG(33);
	    message->color_g = VREG(34);
	    message->color_b = VREG(35);
# if 0
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r = VREG(36);
	    message->color_g = VREG(37);
	    message->color_b = VREG(38);
# endif
	} else {
/*	    message->color_r = 70;
	    message->color_g = 255;
	    message->color_b = 80;	*/
	    message->color_r = VREG(36);
	    message->color_g = VREG(37);
	    message->color_b = VREG(38);
	}
	break;
    case 0x03: /* 青 */
/*	message->color_r = VREG(39);
	message->color_g = VREG(40);
	message->color_b = VREG(41);	*/
	if ( message->msg_disp_type0 == 0x1 ) {
	    message->color_r = 80;  /*30;*/
	    message->color_g = 110; /*130;*/
	    message->color_b = 255;
# if 0
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r = 80;
	    message->color_g = 90;
	    message->color_b = 255;
# endif
	} else {
	    message->color_r = 80;
	    message->color_g = 90;
	    message->color_b = 255;
	}
	break;
    case 0x04: /* 水色 */
/*	message->color_r = WREG(25);
	message->color_g = WREG(26);
	message->color_b = WREG(27);	*/
	if ( message->msg_disp_type0 == 0x1 ) {
	    message->color_r = 90;  /*30;*/
	    message->color_g = 180;
	    message->color_b = 255;
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r = 80;
	    message->color_g = 150;
	    message->color_b = 180;
	} else {
	    message->color_r = 100;
	    message->color_g = 180;
	    message->color_b = 255;
	}
	break;
    case 0x05: /* 紫 */
/*	message->color_r = VREG(32);
	message->color_g = VREG(33);
	message->color_b = VREG(34);	*/
	if ( message->msg_disp_type0 == 0x1 ) {
	    message->color_r = 210;
	    message->color_g = 100;
	    message->color_b = 255;
# if 0
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r = 190;
	    message->color_g = 70;
	    message->color_b = 255;
# endif
	} else {
	    message->color_r = 255;
	    message->color_g = 150;
	    message->color_b = 180;
	}
	break;
    case 0x06: /* 黄 */
/*	message->color_r = WREG(25);
	message->color_g = WREG(26);
	message->color_b = WREG(27);	*/
	if ( message->msg_disp_type0 == 0x1 ) {
	    message->color_r = 255;
	    message->color_g = 255;
	    message->color_b = 30;
# if 0
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r = 225;
	    message->color_g = 255;
	    message->color_b = 50;
# endif
	} else {
	    message->color_r = 225;
	    message->color_g = 255;
	    message->color_b = 50;
	}
	break;
    case 0x07: /* 黒 */
# if 0
	if ( message->msg_disp_type0 == 0x1 ) {
	    message->color_r =
		message->color_g =
		message->color_b = 0;
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r =
		message->color_g =
		message->color_b = 0;
	} else {
	    message->color_r =
		message->color_g =
		message->color_b = 0;
	}
# endif
	message->color_r =
	    message->color_g =
	    message->color_b = 0;
	break;

    case 0x00: /* 白 */
    default:   /* その他 */
# if 0
	if ( message->msg_disp_type0 == 0x1 ) {
	    message->color_r =
		message->color_g =
		message->color_b = 255;
	} else if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r =
		message->color_g =
		message->color_b = 0;
	} else {
	    message->color_r =
		message->color_g =
		message->color_b = 255;
	}
# endif
	if ( message->msg_disp_type0 == 0x5 ) {
	    message->color_r =
		message->color_g =
		message->color_b = 0;
	} else {
	    message->color_r =
		message->color_g =
		message->color_b = 255;
	}
	break;
    }    
}



/*=======================================================================
  =	改行・終了マーク表示						=
  =======================================================================*/
static void
last_mark_display( Game_play *game_play, Gfx **glistp, short xps, short yps )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    Gfx 		*gp = *glistp;

    static short	mark_color[][3] = {
    	{   0,  80, 200, },
    	{  50, 130, 255, },
    };
    static short	mark_env[][3] = {
    	{   0,   0,   0, },
    	{   0, 130, 255, },
    };
    static short	mr = 0, mg =  80, mb = 200, mc = 12, mp = 0;
    static short	er = 0, eg =   0, eb =   0;
    short		rc, gc, bc;
    short		re, ge, be;
    unchar 		*data = &kanfont->kbuffer2[0];


    if ( !staff_mode ) {
	rc = (ABS(mr - mark_color[mp][0] )) / mc;
	gc = (ABS(mg - mark_color[mp][1] )) / mc;
	bc = (ABS(mb - mark_color[mp][2] )) / mc;
	if ( mr >= mark_color[mp][0] ) mr -= rc;
	else			   mr += rc;
	if ( mg >= mark_color[mp][1] ) mg -= gc;
	else			   mg += gc;
	if ( mb >= mark_color[mp][2] ) mb -= bc;
	else			   mb += bc;
	re = (ABS(er - mark_env[mp][0] )) / mc;
	ge = (ABS(eg - mark_env[mp][1] )) / mc;
	be = (ABS(eb - mark_env[mp][2] )) / mc;
	if ( er >= mark_env[mp][0] ) er -= re;
	else			 er += re;
	if ( eg >= mark_env[mp][1] ) eg -= ge;
	else			 eg += ge;
	if ( eb >= mark_env[mp][2] ) eb -= be;
	else			 eb += be;
	if ( !(--mc) ) {
	    mr = mark_color[mp][0];
	    mg = mark_color[mp][1];
	    mb = mark_color[mp][2];
	    er = mark_env[mp][0];
	    eg = mark_env[mp][1];
	    eb = mark_env[mp][2];
	    mc = 12;
	    mp ^=1;
	}
	
	
	gDPPipeSync( gp++ );
	gDPSetCombineMode( gp++, G_CC_INT9, G_CC_INT9 );
	gDPSetPrimColor( gp++, 0, 0, mr, mg, mb, 255 );
	gDPSetEnvColor( gp++, er, eg, eb, 255 );
	gDPLoadTextureBlock_4b( gp++,
				data, G_IM_FMT_I, 16, 16, 0,
				G_TX_CLAMP, G_TX_CLAMP,
				G_TX_NOMASK, G_TX_NOMASK,
				G_TX_NOLOD, G_TX_NOLOD );
	size = (int)(16.0f*((float)XREG(57)/100.0f));
	scale = (int)(1024.0f/((float)XREG(57)/100.0f));
	gSPTextureRectangle( gp++,
			     xps << 2, yps << 2,
////////////////			 xps + XREG(57) << 2, yps + XREG(57) << 2,
////////////////			 G_TX_RENDERTILE, 0, 0, XREG(58) <<1, XREG(58) << 1 );
			     (xps + size) << 2, (yps + size) << 2,
			     G_TX_RENDERTILE, 0, 0,  scale, scale );
	message->wct++;
	
	*glistp = gp;
    }
}


/*=======================================================================
  =	アイテムＷＲＩＴＥ						=
  =======================================================================*/
static unshort
dpitem_write( Game_play *game_play, unshort item, Gfx **glistp, unshort i )
{
    Message		*message = (Message *)&game_play->message;

    Gfx 		*gp = *glistp;


    if ( message->msg_mode == M_DISPLAY) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
    gDPPipeSync( gp++ );
    gDPSetCombineMode( gp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
    gDPSetPrimColor( gp++, 0, 0, 255, 255, 255, message->color_a );
////////	    if ( message->msg_b.msg_buff[i+1] >= H_holystone_1 && message->msg_b.msg_buff[i+1] < H_seal_medal_1/*H_purse_1*/ ) {
    if ( item >= H_seal_medal_1 ) {
	gDPLoadTextureBlock( gp++,
			     message->fukidashiSegment + BALSZ,
			     G_IM_FMT_RGBA, G_IM_SIZ_32b,
			     24, 24, 0,
			     G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK,   G_TX_NOMASK,
			     G_TX_NOLOD,    G_TX_NOLOD );
# if 0
	gSPTextureRectangle( gp++,
			     (int)(message->mxp + YREG(71)) << 2, (int)(message->myp + YREG(72)) << 2,
////////			     (int)((message->mxp + YREG(71)) + 24) << 2, (int)((message->myp + YREG(72)) + 24) << 2,
			     (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((message->myp + YREG(72)) + YREG(75)) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
# endif
    } else {
	gDPLoadTextureBlock( gp++,
			     message->fukidashiSegment + BALSZ,
			     G_IM_FMT_RGBA, G_IM_SIZ_32b,
			     32, 32, 0,
			     G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK,   G_TX_NOMASK,
			     G_TX_NOLOD,    G_TX_NOLOD );
# if 0
	gSPTextureRectangle( gp++,
////////			     (int)(message->mxp + YREG(73)) << 2, (int)(message->myp + YREG(74)) << 2,
////////			     (int)((message->mxp + YREG(73)) + 32) << 2, (int)((message->myp + YREG(74)) + 32) << 2,
			     (int)(message->mxp + YREG(71)) << 2, (int)(message->myp + YREG(72)) << 2,
			     (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((message->myp + YREG(72)) + YREG(75)) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
# endif
    }
    gSPTextureRectangle( gp++,
			 (int)(message->mxp + YREG(71)) << 2, (int)(YREG(72)) << 2,
			 (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((YREG(72)) + YREG(75)) << 2,
			 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
    
    gDPPipeSync( gp++ );
    gDPSetCombineMode( gp++, G_CC_INT4, G_CC_INT4 );
    message->mxp += ITEMSIZE;
    i++;

    *glistp = gp;
    return( i );
}

/*=======================================================================
  =	オカリナ初期設定						=
  =======================================================================*/
static void
ocarina_init_set( Game_play *game_play )
{
    Message		*message = (Message *)&game_play->message;

    if ( message->msg_mode == M_DISPLAY ) {
	OCARINA_MODE( game_play ) = Oca_Play;
	if ( message->ocarina_no == Ocarina_Record ) {
	    message->msg_mode = M_OCARINA40;
	    PRINTF("録音開始 録音開始 録音開始 録音開始  -> ");
	} else if ( message->ocarina_no == Ocarina_PlayBack ) {
	    PRINTF("録音再生 録音再生 録音再生 録音再生  -> ");
	    Na_StartOcarinaMode();
	    Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	    message->info = Na_GetOcarinaSeqInfoWork();
	    message->info->locate = onpu_pt = onpu_ct = 0;
	    /* 音符バッファ初期化 */
	    onpu_buff_reset();
	    message->wct = 3;
	    message->msg_mode = M_OCARINA42;
	    Na_StartOcarinaSeq( NA_OCA_CHK_RECMELODY, 1 );
	} else if ( message->ocarina_no == Ocarina_Scarecrow ) {
	    message->msg_mode = M_OCARINA50;
	    PRINTF("８音録音開始 ８音録音開始 ８音録音開始  -> ");
	} else if ( message->ocarina_no == Ocarina_ScarecrowP ) {
	    PRINTF("８音再生 ８音再生 ８音再生  -> ");
	    Na_StartOcarinaMode();
	    Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	    message->info = Na_GetOcarinaSeqInfoWork();
	    message->info->locate = onpu_pt = onpu_ct = 0;
	    /* 音符バッファ初期化 */
	    onpu_buff_reset();
	    message->wct = 3;
	    message->msg_mode = M_OCARINA54;
	    Na_StartOcarinaSeq( NA_OCA_CHK_RECMELODY2, 1 );
	} else if ( message->ocarina_no == Ocarina_Round ) {
	    message->msg_mode = M_OCARINA60;
	    PRINTF("輪唱開始 輪唱開始 輪唱開始 輪唱開始  -> ");
	} else if ( message->ocarina_no == Ocarina_Chorus ) {
	    message->msg_mode = M_OCARINA80;
	    PRINTF("カエルの合唱 カエルの合唱  -> ");
	} else {
/*			Na_StartOcarinaMode();
			Na_StartOcarinaPlayCheck2( NA_OCA_CHK_GRP_WARP );
			message->info = Na_GetOcarinaInfoWork();
			message->info->locate = 0;*/
	    PRINTF("オカリナ（%d） ",message->ocarina_no);
	    if ( message->ocarina_no == Ocarina_0 ||
		 message->ocarina_no == Ocarina_Free ||
		 message->ocarina_no >= Ocarina_PC_Salia ) {
		message->msg_mode = M_OCARINA0;
		PRINTF("000000000000  -> ");
	    } else if ( message->ocarina_no >= Ocarina_Wind && message->ocarina_no <= Ocarina_Storm ) {
		message->msg_mode = M_OCARINA10_S;
		PRINTF("111111111111  -> ");
	    } else {
		message->msg_mode = M_OCARINA20_S;
		PRINTF("222222222222  -> ");
	    }
	}
	PRINTF("msg_mode=%d\n",message->msg_mode);
    }
}
/*=======================================================================
  =	メッセージ ＷＲＩＴＥ						=
  =======================================================================*/
static void
message_write( Game_play *game_play, Gfx **glistp )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    unshort		i, j, rd_dt, kanadr;

    Gfx 		*gp = *glistp;




    message->mxp = XREG(54);
    message->myp = XREG(55);
# if 0
    if ( message->msg_disp_type0 == 0x1 ) {
	message->color_r = message->color_g = message->color_b = 255;
    } else if ( message->msg_disp_type0 == 0x5 ) {
	message->color_r = message->color_g = message->color_b = 0;
    } else {
	message->color_r = message->color_g = message->color_b = 255;
    }
# endif	    
    if ( message->msg_disp_type0 == 0x5 ) {
	message->color_r =
	    message->color_g =
	    message->color_b = 0;
    } else {
	message->color_r =
	    message->color_g =
	    message->color_b = 255;
    }

    message->ldp = 0;
    kanadr = 0;

    for ( i = 0; i < message->end; i++ ) {
	rd_dt = message->msg_b.msg_buff[i];
	switch( rd_dt ) {
	case KAIGYO:
	    /* 改行 処理 */
	    message->myp += XREG(56);
	    message->mxp = XREG(54);
	    if ( message->item_dp == 1 ) message->mxp += ITEMSIZE;
	    if ( message->item_dp == 2 ) message->mxp += ITEMSIZE;
	    break;
	    
	case CHANGE:
	    /* 切替 */
	    /* 文字サイズ ＆ 文字カラー */
	    moji_size_color( message, message->msg_b.msg_buff[++i] );
	    break;
	    
	case SPACE:
	    /* スペース */
	    message->mxp += MSPC; 	/* スペース */
	    break;


	    
	case Z_KEYWAIT:
	    if ( message->msg_mode == M_DISPLAY) {
		if ( !last_flag ) {
		    Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		    message->msg_mode = M_NEXT;
		    kanfont_get2( kanfont, 0 );
		} else {
		    message->msg_mode = M_READ;
		    message->nonono_fg = 0;
		    message->rdp++;
		}
	    }
	    *glistp = gp;
	    return;
	    
	case Z_BLANK:
	    message->mxp += message->msg_b.msg_buff[++i]; 	/* スペース */
	    break;
	    
	case Z_NEXTMSG:
	    message->select = __Next_Message;
	    if ( message->msg_mode == M_DISPLAY) {
		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		kanfont_get2( kanfont, 0 );
	    }
	    *glistp = gp;
	    return;

	case Z_START:
	    if ( i+1 == message->end ) {
		if ( message->msg_mode == M_DISPLAY ||
		     (message->msg_mode >= M_OCARINA0 && message->msg_mode <= M_OCARINA_FREE) ) {
		    for ( j = i; ; j++ ) {
			rd_dt = message->msg_b.msg_buff[j];
			if ( rd_dt == Z_STOP || rd_dt == Z_DISPSTOP || rd_dt == Z_ENEMY || rd_dt == Z_TIMER || rd_dt == Z_PAUSE  || rd_dt == Z_KEYWAIT || rd_dt == D_SYURYOU ) break;
		    }
		    i = j - 1;
		    message->end = i + 1;
		}
	    }
	case Z_STOP:
	    break;
	    
	case Z_PAUSE:
	    if ( i+1 == message->end ) {
		if ( message->msg_mode == M_DISPLAY) {
		    message->msg_mode = M_PAUSE;
		    kanfont_get2( kanfont, 0 );
		}
		*glistp = gp;
		return;
	    }
	    break;
	    
	case Z_TIMER:
	    if ( message->msg_mode == M_DISPLAY) {
////////		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->wct = message->msg_b.msg_buff[++i]; 	/* タイマー */
		message->msg_mode = M_TIMER;
	    }
	    *glistp = gp;
	    return;

	case Z_BGM:
# if 0
	    /* サウンド（ＢＧＭ） */
	    if ( message->msg_mode == M_DISPLAY) {
		Na_StartSystemSe( message->msg_b.msg_buff[i+1] );
	    }
	    i++;
# endif
	    break;

	case Z_SE:
	    /* サウンド（ＳＥ） */
	    if ( message->msg_mode == M_DISPLAY && !se_flag ) {
		se_flag = 1;
//		PRINTF("サウンド（ＳＥ）\n");
		Na_StartSystemSe( message->msg_b.msg_buff[i+1] );
	    }
	    i++;
	    break;

	case Z_DPITEM:
	    /* アイテム */
# if 1
	    i = dpitem_write( game_play, message->msg_b.msg_buff[i+1], &gp, i );
# else
	    if ( message->msg_mode == M_DISPLAY) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	    gDPSetPrimColor( gp++, 0, 0, 255, 255, 255, message->color_a );
////////	    if ( message->msg_b.msg_buff[i+1] >= H_holystone_1 && message->msg_b.msg_buff[i+1] < H_seal_medal_1/*H_purse_1*/ ) {
	    if ( message->msg_b.msg_buff[i+1] >= H_seal_medal_1 ) {
		gDPLoadTextureBlock( gp++,
				     message->fukidashiSegment + BALSZ,
				     G_IM_FMT_RGBA, G_IM_SIZ_32b,
				     24, 24, 0,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_NOMASK,   G_TX_NOMASK,
				     G_TX_NOLOD,    G_TX_NOLOD );
		gSPTextureRectangle( gp++,
				     (int)(message->mxp + YREG(71)) << 2, (int)(message->myp + YREG(72)) << 2,
				     (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((message->myp + YREG(72)) + YREG(75)) << 2,
				     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    } else {
		gDPLoadTextureBlock( gp++,
				     message->fukidashiSegment + BALSZ,
				     G_IM_FMT_RGBA, G_IM_SIZ_32b,
				     32, 32, 0,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_NOMASK,   G_TX_NOMASK,
				     G_TX_NOLOD,    G_TX_NOLOD );
		gSPTextureRectangle( gp++,
////////				     (int)(message->mxp + YREG(73)) << 2, (int)(message->myp + YREG(74)) << 2,
////////				     (int)((message->mxp + YREG(73)) + YREG(76)) << 2, (int)((message->myp + YREG(74)) + YREG(76)) << 2,
				     (int)(message->mxp + YREG(71)) << 2, (int)(message->myp + YREG(72)) << 2,
				     (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((message->myp + YREG(72)) + YREG(75)) << 2,
				     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    }
	    gDPPipeSync( gp++ );
	    message->mxp += ITEMSIZE;
	    gDPSetCombineMode( gp++, G_CC_INT4, G_CC_INT4 );
	    i++;
# endif
	    break;

	case Z_TEXTURE:
	    /* テクスチャ */
	    if ( message->msg_mode == M_DISPLAY) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	    /* 影 */
	    gDPSetPrimColor( gp++, 0, 0, mes_board_shadow_dt[message->mes_board_shadow][0], mes_board_shadow_dt[message->mes_board_shadow][1], mes_board_shadow_dt[message->mes_board_shadow][2], message->color_a );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT,
				    message->fukidashiSegment + BALSZ,
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp+1 << 2, (int)XREG(61)+mes_board_shift_dt[message->mes_board_shift] << 2,
				 (int)message->mxp+96+1 << 2, (int)XREG(61)+48+mes_board_shift_dt[message->mes_board_shift] << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT + ((96*48)/2),
				    message->fukidashiSegment + BALSZ + ((96*48)/2),
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp+96+1 << 2, (int)XREG(61)+mes_board_shift_dt[message->mes_board_shift] << 2,
				 (int)message->mxp+96+1+96+1 << 2, (int)XREG(61)+48+mes_board_shift_dt[message->mes_board_shift] << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    /* 本体 */
	    gDPPipeSync( gp++ );
	    gDPSetPrimColor( gp++, 0, 0, mes_board_prim_dt[message->mes_board_prim][0], mes_board_prim_dt[message->mes_board_prim][1], mes_board_prim_dt[message->mes_board_prim][2], message->color_a );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT,
				    message->fukidashiSegment + BALSZ,
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp << 2, (int)XREG(61) << 2,
				 (int)message->mxp+96 << 2, (int)XREG(61)+48 << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT + ((96*48)/2),
				    message->fukidashiSegment + BALSZ + ((96*48)/2),
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp+96 << 2, (int)XREG(61) << 2,
				 (int)message->mxp+96+96 << 2, (int)XREG(61)+48 << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_INT4, G_CC_INT4 );
	    message->mxp += ITEMSIZE;
	    break;
	    
	case Z_SPEED:
	    message->tspd = message->msg_b.msg_buff[++i]; 	/* スペース */
	    break;
	    
	case Z_NONONO:
	    message->nonono_fg = 1; 		/* 早送り禁止 */
	    break;

	case Z_SENTAKU_2:
	    /* ２択 */
	    message->select = __2_SELECT;
	    if ( message->msg_mode == M_DISPLAY) {
		message->sel_msgno = message->msgno;
		message->wct = 4;
		message->sel_pnt = 0;
		kanfont_get2( kanfont, 2 );
	    }
	    break;
	    
	case Z_SENTAKU_3:
	    /* ３択 */
	    message->select = __3_SELECT;
	    if ( message->msg_mode == M_DISPLAY) {
		message->sel_msgno = message->msgno;
		message->wct = 4;
		message->sel_pnt = 0;
		kanfont_get2( kanfont, 2 );
	    }
	    break;
	    
	case D_SYURYOU:
	    /* ＥＮＤ */
	    if ( message->msg_mode == M_DISPLAY) {
		message->msg_mode = M_END;
		if ( !message->select ) {
		    Na_StartSystemSe( NA_SE_SY_MESSAGE_END );
		    kanfont_get2( kanfont, 1 );
		    if ( !game_play->demo_play.mode ) { 
			DO_ACTION_POINT_SET( game_play, DO_Modoru );
		    }
		}
	    }
	    *glistp = gp;
	    return;
	    
	case Z_OCARINA:
	    if ( i+1 == message->end ) {
		ocarina_init_set( game_play );
		*glistp = gp;
		return;
	    }
	    break;
	    
	case Z_TIMER_END:
	    /* ＥＮＤ */
	    if ( message->msg_mode == M_DISPLAY) {
////////		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		message->select = __TIMER;
		message->wct = message->msg_b.msg_buff[++i]; 	/* タイマー */
		kanfont_get2( kanfont, 1 );
		if ( !game_play->demo_play.mode ) { 
		    DO_ACTION_POINT_SET( game_play, DO_Modoru );
		}
	    }
	    *glistp = gp;
	    return;
	    
	case Z_DISPSTOP:
	    if ( message->msg_mode == M_DISPLAY) {
		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		message->select = __DISPSTOP;
	    }
	    *glistp = gp;
	    return;
	    
	case Z_ENEMY:
	    if ( message->msg_mode == M_DISPLAY) {
		message->msg_mode = M_END;
		message->select = __ENEMY;
		kanfont_get2( kanfont, 0 );
		Na_StartSystemSe( NA_SE_SY_MESSAGE_END );
	    }
	    *glistp = gp;
	    return;
	    
	default:
	    /* 文字 出力 */
	    /* 左字詰め */
	    switch ( rd_dt ) {
	    case 0x8169 : // （
	    case 0x8175 : // 「
		message->mxp -= 6;
		break;
		
	    case 0x8145 : // ・
		message->mxp -= 3;
		break;
		
	    case 0x8148 : // ？
	    case 0x8149 : // ！
	    case 0x814F : // ＾
	    case 0x8250 : // １
		message->mxp -= 2;
		break;
		
	    default:
		break;
	    }
	    if ( message->msg_mode == M_DISPLAY && i == message->end - 1 && message->mspd == message->tspd ) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
	    message_moji_display( game_play, &kanfont->kbuffer[kanadr], &gp );
	    kanadr += BUF_CT;
	    
	    /* 右字詰め */
	    switch ( rd_dt ) {
	    case 0x8144 : // ．
		message->mxp += (MXSZ-8);
		break;
		
	    case 0x816A : // ）
	    case 0x8176 : // 」
		message->mxp += (MXSZ-6);
		break;
		
	    case 0x8141 : // ，
	    case 0x8142 : // 。
	    case 0x8168 : // ”
		message->mxp += (MXSZ-4);
		break;
		
////////	    case 0x8149 : // ！
	    case 0x814F : // ＾
	    case 0x8194 : // ＃
	    case 0x8196 : // ＊
////////	    case 0x8250 : // １
		message->mxp += (MXSZ-2);
		break;
		
	    case 0x8145 : // ・
		message->mxp += (MXSZ-1);
		break;
		
	    default:
////////		message->mxp += XREG(59);
		message->mxp += (int)(16.0f*((float)XREG(57)/100.0f));
		break;
	    }
	    break;
	}
    }
    if ( !message->mspd ) {
	message->end = i + 1;
	message->mspd = message->tspd;
    } else {
	--message->mspd;
    }

    *glistp = gp;
}
/*=======================================================================
  =	メッセージ ＷＲＩＴＥ						=
  =======================================================================*/
static void
message_write_NES( Game_play *game_play, Gfx **glistp )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    unshort		i, j, kkk, kanadr;

    unchar		rd_dt;
    
    Gfx 		*gp = *glistp;

    static float shift_data[] = {
/*        △     ！     ”     ＃     ＄     ％     ＆     ’     （     ）     ＊     ＋     ，     −     ．     ／  */
	 8.0f,  8.0f,  6.0f,  9.0f,  9.0f, 14.0f, 12.0f,  3.0f,  7.0f,  7.0f,  7.0f,  9.0f,  4.0f,  6.0f,  4.0f,  9.0f,
/*	  ０     １     ２     ３     ４     ５     ６     ７     ８     ９     ：     ；     ＜     ＝     ＞     ？  */
	10.0f,  5.0f,  9.0f,  9.0f, 10.0f,  9.0f,  9.0f,  9.0f,  9.0f,  9.0f,  6.0f,  6.0f,  9.0f, 11.0f,  9.0f, 11.0f,
/*	  ＠     Ａ     Ｂ     Ｃ     Ｄ     Ｅ     Ｆ     Ｇ     Ｈ     Ｉ     Ｊ     Ｋ     Ｌ     Ｍ     Ｎ     Ｏ  */
	13.0f, 12.0f,  9.0f, 11.0f, 11.0f,  8.0f,  8.0f, 12.0f, 10.0f,  4.0f,  8.0f, 10.0f,  8.0f, 13.0f, 11.0f, 13.0f,
/*	  Ｐ     Ｑ     Ｒ     Ｓ     Ｔ     Ｕ     Ｖ     Ｗ     Ｘ     Ｙ     Ｚ     ［     ￥     ］     ＾     ＿  */
	 9.0f, 13.0f, 10.0f, 10.0f,  9.0f, 10.0f, 11.0f, 15.0f, 11.0f, 10.0f, 10.0f,  7.0f, 10.0f,  7.0f, 10.0f,  9.0f,
/*	  ｀     ａ     ｂ     ｃ     ｄ     ｅ     ｆ     ｇ     ｈ     ｉ     ｊ     ｋ     ｌ     ｍ     ｎ     ｏ  */
	 5.0f,  8.0f,  9.0f,  8.0f,  9.0f,  9.0f,  6.0f,  9.0f,  8.0f,  4.0f,  6.0f,  8.0f,  4.0f, 12.0f,  9.0f,  9.0f,
/*	  ｐ     ｑ     ｒ     ｓ     ｔ     ｕ     ｖ     ｗ     ｘ     ｙ     ｚ     ｛     ｜     ｝     〜         */
	 9.0f,  9.0f,  7.0f,  8.0f,  7.0f,  8.0f,  9.0f, 12.0f,  8.0f,  9.0f,  8.0f,  7.0f,  5.0f,  7.0f, 10.0f, 10.0f,
/*                                                                                                                     */
	12.0f, 12.0f, 12.0f, 12.0f, 11.0f,  8.0f,  8.0f,  8.0f,  6.0f,  6.0f, 13.0f, 13.0f, 10.0f, 10.0f, 10.0f,  9.0f,
/*                                                                                                                     */
	 8.0f,  8.0f,  8.0f,  8.0f,  8.0f,  9.0f,  9.0f,  9.0f,  9.0f,  6.0f,  9.0f,  9.0f,  9.0f,  9.0f,  9.0f, 14.0f,
/*                                                                                                                     */
	14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f, 14.0f,
    };



    message->mxp = XREG(54);
    if( !staff_mode ) {
	message->myp = XREG(55);
    } else {
	message->myp = YREG(1);
    }
# if 0
    if ( message->msg_disp_type0 == 0x1 ) {
	message->color_r = message->color_g = message->color_b = 255;
    } else if ( message->msg_disp_type0 == 0x5 ) {
	message->color_r = message->color_g = message->color_b = 0;
    } else {
	message->color_r = message->color_g = message->color_b = 255;
    }
# endif	    
    if ( message->msg_disp_type0 == 0x5 ) {
	message->color_r =
	    message->color_g =
	    message->color_b = 0;
    } else {
	message->color_r =
	    message->color_g =
	    message->color_b = 255;
    }

    message->ldp = 0;
    kanadr = 0;

    for ( i = 0; i < message->end; i++ ) {
	rd_dt = message->msg_b.nes_msg_b[i];
	switch( rd_dt ) {
	case NKAIGYO:
	    /* 改行 処理 */
	    message->mxp = XREG(54);
	    if ( message->item_dp == 1 || message->item_dp == 3 ) message->mxp += ITEMSIZE;
	    if ( message->item_dp == 2 && message->myp != XREG(55) ) message->mxp += ITEMSIZE;
	    message->myp += XREG(56);
	    break;
	    
	case NCHANGE:
	    /* 切替 */
	    /* 文字サイズ ＆ 文字カラー */
	    moji_size_color( message, (message->msg_b.nes_msg_b[++i] & 0x0f) );
	    break;
	    
	case NSPACE:
	    /* スペース */
	    message->mxp += MSPC; 	/* スペース */
	    break;


	    
	case NZ_KEYWAIT:
	    if ( message->msg_mode == M_DISPLAY) {
		if ( !last_flag ) {
		    Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		    message->msg_mode = M_NEXT;
		    kanfont_get2( kanfont, 0 );
		} else {
		    message->msg_mode = M_READ;
		    message->nonono_fg = 0;
		    message->rdp++;
		}
	    }
	    *glistp = gp;
	    return;
	    
	case NZ_BLANK:
	    message->mxp += message->msg_b.nes_msg_b[++i]; 	/* スペース */
	    break;
	    
	case NZ_NEXTMSG:
	    message->select = __Next_Message;
	    if ( message->msg_mode == M_DISPLAY) {
		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		kanfont_get2( kanfont, 0 );
	    }
	    *glistp = gp;
	    return;

	case NZ_START:
	    if ( i+1 == message->end ) {
		if ( message->msg_mode == M_DISPLAY ||
		     (message->msg_mode >= M_OCARINA0 && message->msg_mode <= M_OCARINA_FREE) ) {
		    for ( j = i; ; j++ ) {
			rd_dt = message->msg_b.nes_msg_b[j];
			if ( rd_dt == NZ_BLANK ) {
			    j++;
			} else if ( rd_dt == NZ_STOP || rd_dt == NZ_DISPSTOP || rd_dt == NZ_ENEMY || rd_dt == NZ_TIMER || rd_dt == NZ_PAUSE  || rd_dt == NZ_KEYWAIT || rd_dt == ND_SYURYOU ) break;
		    }
		    i = j - 1;
		    message->end = i + 1;
		}
	    }
	case NZ_STOP:
	    break;
	    
	case NZ_PAUSE:
	    if ( i+1 == message->end ) {
		if ( message->msg_mode == M_DISPLAY) {
		    message->msg_mode = M_PAUSE;
		    kanfont_get2( kanfont, 0 );
		}
		*glistp = gp;
		return;
	    }
	    break;
	    
	case NZ_TIMER:
	    if ( message->msg_mode == M_DISPLAY) {
////////		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->wct = message->msg_b.nes_msg_b[++i]; 	/* タイマー */
		message->msg_mode = M_TIMER;
	    }
	    *glistp = gp;
	    return;

	case NZ_BGM:
# if 0
	    /* サウンド（ＢＧＭ） */
	    if ( message->msg_mode == M_DISPLAY) {
		Na_StartSystemSe( message->msg_b.nes_msg_b[i+1] );
	    }
	    i++;
	    break;
# endif
	    /* ＥＮＤ */
	    if ( message->msg_mode == M_DISPLAY) {
////////		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		message->select = __TIMER;
		PRINTF("タイマー (%x) (%x)",message->msg_b.nes_msg_b[i+1],message->msg_b.nes_msg_b[i+2]);
		message->wct = message->msg_b.nes_msg_b[++i] << 8; 	/* タイマー */
		message->wct |= message->msg_b.nes_msg_b[++i]; 	/* タイマー */
		PRINTF("合計wct=%x(%d)\n",message->wct,message->wct);
	    }
	    *glistp = gp;
	    return;

	case NZ_SE:
	    /* サウンド（ＳＥ） */
	    if ( message->msg_mode == M_DISPLAY && !se_flag ) {
		se_flag = 1;
		PRINTF("サウンド（ＳＥ）\n");
		kkk = message->msg_b.nes_msg_b[i+1];
		kkk <<= 8;
		Na_StartSystemSe( kkk | message->msg_b.nes_msg_b[i+2] );
	    }
	    i+=2;
	    break;

	case NZ_DPITEM:
	    /* アイテム */
# if 1
	    i = dpitem_write( game_play, (unshort)message->msg_b.nes_msg_b[i+1], &gp, i );
# else
	    if ( message->msg_mode == M_DISPLAY) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	    gDPSetPrimColor( gp++, 0, 0, 255, 255, 255, message->color_a );
////////	    if ( message->msg_b.nes_msg_b[i+1] >= H_holystone_1 && message->msg_b.nes_msg_b[i+1] < H_seal_medal_1/*H_purse_1*/ ) {
	    if ( message->msg_b.nes_msg_b[i+1] >= H_seal_medal_1 ) {
		gDPLoadTextureBlock( gp++,
				     message->fukidashiSegment + BALSZ,
				     G_IM_FMT_RGBA, G_IM_SIZ_32b,
				     24, 24, 0,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_NOMASK,   G_TX_NOMASK,
				     G_TX_NOLOD,    G_TX_NOLOD );
		gSPTextureRectangle( gp++,
				     (int)(message->mxp + YREG(71)) << 2, (int)(message->myp + YREG(72)) << 2,
				     (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((message->myp + YREG(72)) + YREG(75)) << 2,
				     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    } else {
		gDPLoadTextureBlock( gp++,
				     message->fukidashiSegment + BALSZ,
				     G_IM_FMT_RGBA, G_IM_SIZ_32b,
				     32, 32, 0,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_NOMASK,   G_TX_NOMASK,
				     G_TX_NOLOD,    G_TX_NOLOD );
		gSPTextureRectangle( gp++,
////////				     (int)(message->mxp + YREG(73)) << 2, (int)(message->myp + YREG(74)) << 2,
////////				     (int)((message->mxp + YREG(73)) + YREG(76)) << 2, (int)((message->myp + YREG(74)) + YREG(76)) << 2,
				     (int)(message->mxp + YREG(71)) << 2, (int)(message->myp + YREG(72)) << 2,
				     (int)((message->mxp + YREG(71)) + YREG(75)) << 2, (int)((message->myp + YREG(72)) + YREG(75)) << 2,
				     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    }
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_INT4, G_CC_INT4 );
	    message->mxp += ITEMSIZE;
	    i++;
# endif
	    break;

	case NZ_TEXTURE:
	    /* テクスチャ */
	    if ( message->msg_mode == M_DISPLAY) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	    /* 影 */
	    gDPSetPrimColor( gp++, 0, 0, mes_board_shadow_dt[message->mes_board_shadow][0], mes_board_shadow_dt[message->mes_board_shadow][1], mes_board_shadow_dt[message->mes_board_shadow][2], message->color_a );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT,
				    message->fukidashiSegment + BALSZ,
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp+1 << 2, (int)XREG(61)+mes_board_shift_dt[message->mes_board_shift] << 2,
				 (int)message->mxp+96+1 << 2, (int)XREG(61)+48+mes_board_shift_dt[message->mes_board_shift] << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT + ((96*48)/2),
				    message->fukidashiSegment + BALSZ + ((96*48)/2),
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp+96+1 << 2, (int)XREG(61)+mes_board_shift_dt[message->mes_board_shift] << 2,
				 (int)message->mxp+96+1+96+1 << 2, (int)XREG(61)+48+mes_board_shift_dt[message->mes_board_shift] << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    /* 本体 */
	    gDPPipeSync( gp++ );
	    gDPSetPrimColor( gp++, 0, 0, mes_board_prim_dt[message->mes_board_prim][0], mes_board_prim_dt[message->mes_board_prim][1], mes_board_prim_dt[message->mes_board_prim][2], message->color_a );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT,
				    message->fukidashiSegment + BALSZ,
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp << 2, (int)XREG(61) << 2,
				 (int)message->mxp+96 << 2, (int)XREG(61)+48 << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    gDPLoadTextureBlock_4b( gp++,
////////				    message->fukidashiSegment + BALSZ + I_IT_PT + ((96*48)/2),
				    message->fukidashiSegment + BALSZ + ((96*48)/2),
				    G_IM_FMT_I, 96, 48, 0,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK,   G_TX_NOMASK,
				    G_TX_NOLOD,    G_TX_NOLOD );
	    gSPTextureRectangle( gp++,
				 (int)message->mxp+96 << 2, (int)XREG(61) << 2,
				 (int)message->mxp+96+96 << 2, (int)XREG(61)+48 << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    
	    gDPPipeSync( gp++ );
	    gDPSetCombineMode( gp++, G_CC_INT4, G_CC_INT4 );
	    message->mxp += ITEMSIZE;
	    break;
	    
	case NZ_SPEED:
	    message->tspd = message->msg_b.nes_msg_b[++i]; 	/* スペース */
	    break;
	    
	case NZ_NONONO:
	    message->nonono_fg = 1; 		/* 早送り禁止 */
	    break;

	case NZ_SENTAKU_2:
	    /* ２択 */
	    message->select = __2_SELECT;
	    if ( message->msg_mode == M_DISPLAY) {
		message->sel_msgno = message->msgno;
		message->wct = 4;
		message->sel_pnt = 0;
		kanfont_get2( kanfont, 2 );
	    }
	    break;
	    
	case NZ_SENTAKU_3:
	    /* ３択 */
	    message->select = __3_SELECT;
	    if ( message->msg_mode == M_DISPLAY) {
		message->sel_msgno = message->msgno;
		message->wct = 4;
		message->sel_pnt = 0;
		kanfont_get2( kanfont, 2 );
	    }
	    break;
	    
	case ND_SYURYOU:
	    /* ＥＮＤ */
	    if ( message->msg_mode == M_DISPLAY) {
		message->msg_mode = M_END;
		if ( !message->select ) {
		    Na_StartSystemSe( NA_SE_SY_MESSAGE_END );
		    kanfont_get2( kanfont, 1 );
		    if ( !game_play->demo_play.mode ) { 
			DO_ACTION_POINT_SET( game_play, DO_Modoru );
		    }
		}
	    }
	    *glistp = gp;
	    return;
	    
	case NZ_OCARINA:
	    if ( i+1 == message->end ) {
		ocarina_init_set( game_play );
# if 0
		if ( message->msg_mode == M_DISPLAY ) {
		    OCARINA_MODE( game_play ) = Oca_Play;
		    if ( message->ocarina_no == Ocarina_Record ) {
			message->msg_mode = M_OCARINA40;
			PRINTF("録音開始 録音開始 録音開始 録音開始  -> ");
		    } else if ( message->ocarina_no == Ocarina_PlayBack ) {
			PRINTF("録音再生 録音再生 録音再生 録音再生  -> ");
			Na_StartOcarinaMode();
			Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
			message->info = Na_GetOcarinaSeqInfoWork();
			message->info->locate = onpu_pt = onpu_ct = 0;
			/* 音符バッファ初期化 */
			onpu_buff_reset();
			message->wct = 3;
			message->msg_mode = M_OCARINA42;
			Na_StartOcarinaSeq( NA_OCA_CHK_RECMELODY, 1 );
		    } else if ( message->ocarina_no == Ocarina_Round ) {
			message->msg_mode = M_OCARINA60;
			PRINTF("輪唱開始 輪唱開始 輪唱開始 輪唱開始  -> ");
		    } else if ( message->ocarina_no == Ocarina_Chorus ) {
			message->msg_mode = M_OCARINA80;
			PRINTF("カエルの合唱 カエルの合唱  -> ");
		    } else {
/*			Na_StartOcarinaMode();
			Na_StartOcarinaPlayCheck2( NA_OCA_CHK_GRP_WARP );
			message->info = Na_GetOcarinaInfoWork();
			message->info->locate = 0;*/
			PRINTF("オカリナ（%d） ",message->ocarina_no);
			if ( message->ocarina_no == Ocarina_0 ||
			     message->ocarina_no == Ocarina_Free ||
			     message->ocarina_no >= Ocarina_PC_Salia ) {
			    message->msg_mode = M_OCARINA0;
			    PRINTF("000000000000  -> ");
			} else if ( message->ocarina_no >= Ocarina_Wind && message->ocarina_no <= Ocarina_Storm ) {
			    message->msg_mode = M_OCARINA10_S;
			    PRINTF("111111111111  -> ");
			} else {
			    message->msg_mode = M_OCARINA20_S;
			    PRINTF("222222222222  -> ");
			}
		    }
		    PRINTF("msg_mode=%d\n",message->msg_mode);
		}
# endif
		*glistp = gp;
		return;
	    }
	    break;
	    
	case NZ_TIMER_END:
	    /* ＥＮＤ */
	    if ( message->msg_mode == M_DISPLAY) {
////////		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		message->select = __TIMER;
		message->wct = message->msg_b.nes_msg_b[++i]; 	/* タイマー */
		kanfont_get2( kanfont, 1 );
		if ( !game_play->demo_play.mode ) { 
		    DO_ACTION_POINT_SET( game_play, DO_Modoru );
		}
	    }
	    *glistp = gp;
	    return;
	    
	case NZ_DISPSTOP:
	    if ( message->msg_mode == M_DISPLAY) {
		Na_StartSystemSe( NA_SE_SY_MESSAGE_PAUSE );
		message->msg_mode = M_END;
		message->select = __DISPSTOP;
	    }
	    *glistp = gp;
	    return;
	    
	case NZ_ENEMY:
	    if ( message->msg_mode == M_DISPLAY) {
		message->msg_mode = M_END;
		message->select = __ENEMY;
		kanfont_get2( kanfont, 0 );
		Na_StartSystemSe( NA_SE_SY_MESSAGE_END );
	    }
	    *glistp = gp;
	    return;
	    
	default:
	    /* 文字 出力 */
	    if ( message->msg_mode == M_DISPLAY && i == message->end - 1 && message->mspd == message->tspd ) Na_StartSystemSe( NA_SE_SY_MESSAGE_NEUTRAL );
	    message_moji_display( game_play, &kanfont->kbuffer[kanadr], &gp );
	    kanadr += BUF_CT;
	    message->mxp += (int)(shift_data[rd_dt-0x20] * ((float)XREG(57)/100.0f));
	    break;
	}
    }
    if ( !message->mspd ) {
	message->end = i + 1;
	message->mspd = message->tspd;
    } else {
	--message->mspd;
    }

    *glistp = gp;
}




/*=======================================================================
  =	アイテムテクスチャＲＥＡＤ					=
  =======================================================================*/
static void
dpitem_read( Game_play *game_play, unshort item, short yp )
{
    Message		*message = (Message *)&game_play->message;

    Parameter		*parameter = (Parameter *)&game_play->parameter;

    static short moji_32x[] = {
	54, 74,
    };
    static short moji_24x[] = {
	50, 72,
    };

    if ( item == H_map ) {
	parameter->map_palete[30] = 255;
	parameter->map_palete[31] = 255;
    }
    if ( item < H_seal_medal_1 ) {
	/* ３２ｘ３２アイテム */
	YREG(71) = XREG(54) - moji_32x[J_N];
	YREG(72) = 6 + yp;
	YREG(75) = 32;
	dmacopy_fg( message->fukidashiSegment + BALSZ,
		    (u32)_icon_item_staticSegmentRomStart + (I_IT_PT * item ),
		    I_IT_PT );
	PRINTF("アイテム32-0\n");
    } else {
	/* ２４ｘ２４アイテム */
	YREG(71) = XREG(54) - moji_24x[J_N];
	YREG(72) = 10 + yp;
	YREG(75) = 24;
	dmacopy_fg( message->fukidashiSegment + BALSZ,
		    (u32)_icon_item_24_staticSegmentRomStart + (I_IT_P1 * (item - H_seal_medal_1) ),
		    I_IT_P1 );
	PRINTF("アイテム24＝%d (%d) {%d}\n", item, item - H_holystone_1, H_scale_2);
    }
    message->rdp+=1;
    message->item_dp = 1;
}
/*===============================================================
 =	メッセージデータ読み込み				=
 ===============================================================*/
static void
message_read( Game_play *game_play )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;


    short		i, j, k, m, p, jj, rpc[4];
    unshort   		rd_dt, score;
    unchar   		nes_rd_dt;
    int			kanadr;
    unchar 		*uc;
    float 		r;


    i = kanadr = jj = 0;
    message->nonono_fg =
	message->tspd =
	message->mspd = 0;
    key_off_flag = 0;
    /* バッファ読み込み */
    if ( !J_N && !staff_mode ) {
	/* 日本語バージョン */
	do {
	    rd_dt = message->msg_b.msg_buff[i] = kanfont->mbuff.message_buf[message->rdp];
	    if ( rd_dt  == Z_KEYWAIT || rd_dt == Z_NEXTMSG || rd_dt == Z_TIMER || rd_dt == Z_ENEMY || rd_dt == D_SYURYOU ) {
		message->msg_mode = M_DISPLAY;
		message->end = 1;
		XREG(55) = VREG(1) + 6;				// ３行メッセージ
		if ( message->msg_disp_type0 != 0x4 ) {
		    if ( !jj ) XREG(55) =  VREG(1) + 6 + 16;		// １行メッセージ
		    else if ( jj == 1 ) XREG(55) = VREG(1) + 6 + 8;	// ２行メッセージ
		}
		if ( rd_dt == Z_NEXTMSG ) {
		    next_msg_no =
			message->msg_b.msg_buff[++i] = kanfont->mbuff.message_buf[message->rdp+1];
		}
		if ( rd_dt == Z_TIMER ) {
		    message->msg_b.msg_buff[++i] = kanfont->mbuff.message_buf[message->rdp+1];
		    message->rdp+=2;
		}
	    
		message->rd_end = i;
		if ( last_flag ) message->end = message->rd_end;
		break;
	    } else if ( rd_dt == Z_NAME ) {
		for ( j = 8; j > 0; j-- ) {
		    if ( Player_Name[j-1] != SSS ) break;
		}
		PRINTF("\n名前 ＝ ");
		for ( k = 0; k < j; k++ ) {
		    rd_dt = Player_Name[k];
		    PRINTF("(%x), ",rd_dt);
		    message->msg_b.msg_buff[i+k] = Z_NAME;
		    uc = (unchar *)(&kanfont->kbuffer4[Buf_Ct*rd_dt]);
		    for ( p = 0; p < 128; p+=4 ) {
			kanfont->kbuffer[kanadr+p+0] = uc[p+0];
			kanfont->kbuffer[kanadr+p+1] = uc[p+1];
			kanfont->kbuffer[kanadr+p+2] = uc[p+2];
			kanfont->kbuffer[kanadr+p+3] = uc[p+3];
		    }
		    kanadr += BUF_CT;
		}
		i += (j - 1);
	    } else if ( rd_dt == Z_EVENT_0 || rd_dt == Z_EVENT_1 ) {
		PRINTF("\nＥＶＥＮＴタイマー ＝ \n");
		rpc[0] = rpc[1] = rpc[2] = 0;
/*		if ( ZCommonGet( event_fg ) ) {*/
		if ( rd_dt == Z_EVENT_1 ) {
		    rpc[3] = ZCommonGet( event_tm );
		} else {
		    rpc[3] = ZCommonGet( total_event_tm );
		}
		while ( rpc[3] >= 60 ) {
		    rpc[1]++;
		    if ( rpc[1] >= 10 ) {
			rpc[0]++;
			rpc[1] -= 10;
		    }
		    rpc[3] -= 60;
		}
		while ( rpc[3] >= 10 ) {
		    rpc[2]++;
		    rpc[3] -= 10;
		}
		for ( k = 0; k < 4; k++ ) {
		    PRINTF("rpc[%d] = %x\n",k,rpc[k] + 0x824F);
		    kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
		    kanadr += BUF_CT;
		    message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
		    i++;
		    if ( k == 1 ) {
			kanfont_get( kanfont, 0x95AA, kanadr );	/* "分" */
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = 0x95AA;
			i++;
		    } else if ( k == 3 ) {
			kanfont_get( kanfont, 0x9562, kanadr );	/* "秒" */
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = 0x9562;
		    }
		}
	    } else if ( rd_dt == Z_YABUSAME ) {
		PRINTF("\n流鏑馬スコア ＝ ");
		rpc[0] = rpc[1] = rpc[2] = 0;
		rpc[3] = Yabusame_Total;
		while ( rpc[3] >= 1000 ) {
		    rpc[0]++;
		    rpc[3] -= 1000;
		}
		while ( rpc[3] >= 100 ) {
		    rpc[1]++;
		    rpc[3] -=100;
		}
		while ( rpc[3] >= 10 ) {
		    rpc[2]++;
		    rpc[3] -=10;
		}
		for ( k = m = 0; k < 4; k++ ) {
		    if ( k == 3 || rpc[k] ) m = 1;
		    if ( m ) {
			kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
			i++;
		    }
		}
		i--;
	    } else if ( rd_dt == Z_KINSTA ) {
		PRINTF("\n金スタ合計数 ＝ %d",N_COIN_TOTAL);
		rpc[0] = rpc[1] = 0;
		rpc[2] = N_COIN_TOTAL;
		while ( rpc[2] >= 100 ) {
		    rpc[0]++;
		    rpc[2] -=100;
		}
		while ( rpc[2] >= 10 ) {
		    rpc[1]++;
		    rpc[2] -=10;
		}
		for ( k = m = 0; k < 3; k++ ) {
		    if ( k == 2 || rpc[k] ) m = 1;
		    if ( m ) {
			kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
			i++;
		    }
		}
		i--;
	    } else if ( rd_dt == Z_FISHSZ ) {
		PRINTF("\n釣り堀魚サイズ ＝ ");
		rpc[0] = 0;
		rpc[1] = Yabusame_Total;
		while ( rpc[1] >= 10 ) {
		    rpc[0]++;
		    rpc[1] -=10;
		}
		for ( k = m = 0; k < 2; k++ ) {
		    if ( k == 1 || rpc[k] ) {
			kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
			i++;
		    }
		}
		i--;
	    } else if ( rd_dt == Z_RANKING ) {
		/* ランキング */
		score = (unshort)HI_SCORE( kanfont->mbuff.message_buf[++message->rdp] & 0xff );
		if ( (kanfont->mbuff.message_buf[message->rdp] & 0xff) == HS_FISH ) {
		    if ( ZCommon_LinkAgeIsChild() ) {
			score &= 0x7f;
		    } else {
			PRINTF("HI_SCORE(kanfont->mbuff.message_buf[message->rdp]) = %x\n",HI_SCORE( kanfont->mbuff.message_buf[message->rdp]) );
			PRINTF("HI_SCORE( kanfont->mbuff.message_buf[message->rdp]) & 0xff000000  = %x\n",HI_SCORE( kanfont->mbuff.message_buf[message->rdp] ) & 0xff000000 );
			score = (unshort)((HI_SCORE(kanfont->mbuff.message_buf[message->rdp]) & 0xff000000) >> 24);
			score &= 0x7f;
		    }
		}
		switch ( kanfont->mbuff.message_buf[message->rdp] & 0xff ) {
		case HS_YABU:	/* 流鏑馬 ＨｉーＳｃｏｒｅ */
		case HS_POW:	/* ポ─   ＨｉーＳｃｏｒｅ */
		case HS_FISH:	/* つり   ＨｉーＳｃｏｒｅ */
		    rpc[0] = rpc[1] = rpc[2] = 0;
		    rpc[3] = score;
		    while ( rpc[3] >= 1000 ) {
			rpc[0]++;
			rpc[3] -= 1000;
		    }
		    while ( rpc[3] >= 100 ) {
			rpc[1]++;
			rpc[3] -=100;
		    }
		    while ( rpc[3] >= 10 ) {
			rpc[2]++;
			rpc[3] -=10;
		    }
		    for ( k = m = 0; k < 4; k++ ) {
			if ( k == 3 || rpc[k] ) m = 1;
			if ( m ) {
			    kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
			    kanadr += BUF_CT;
			    message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
			    i++;
			}
		    }
		    i--;
		    break;
		case HS_EPONA:	/*  （エポナレース）ＨｉーＳｃｏｒｅ */
		case HS_MARASON:/*  （マラソンマン）ＨｉーＳｃｏｒｅ */
		case HS_DANPI:	/*  墓下リレー（ダンペイ）ＨｉーＳｃｏｒｅ */
		    rpc[0] = rpc[1] = rpc[2] = 0;
		    rpc[3] = score;
		    while ( rpc[3] >= 60 ) {
			rpc[1]++;
			if ( rpc[1] >= 10 ) {
			    rpc[0]++;
			    rpc[1] -= 10;
			}
			rpc[3] -= 60;
		    }
		    while ( rpc[3] >= 10 ) {
			rpc[2]++;
			rpc[3] -= 10;
		    }
		    for ( k = 0; k < 4; k++ ) {
			PRINTF("rpc[%d] = %x\n",k,rpc[k] + 0x824F);
			kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
			i++;
			if ( k == 1 ) {
			    kanfont_get( kanfont, 0x95AA, kanadr );	/* "分" */
			    kanadr += BUF_CT;
			    message->msg_b.msg_buff[i] = 0x95AA;
			    i++;
			} else if ( k == 3 ) {
			    kanfont_get( kanfont, 0x9562, kanadr );	/* "秒" */
			    kanadr += BUF_CT;
			    message->msg_b.msg_buff[i] = 0x9562;
			}
		    }
		    break;
		default:
		    break;
		}
	    } else if ( rd_dt == Z_ZELDATM ) {
		PRINTF("\nゼルダ時間 ＝ ");
		rpc[0] = 0;
		rpc[1] = (short)((float)ZCommonGet(zelda_time) * 0.021972656f / 60.0f );
		while ( rpc[1] >= 10 ) {
		    rpc[0]++;
		    rpc[1] -=10;
		}
		rpc[2] = 0;
		rpc[3] = (short)((float)ZCommonGet(zelda_time) * 0.021972656f) % 60;
		while ( rpc[3] >= 10 ) {
		    rpc[2]++;
		    rpc[3] -=10;
		}
		for ( k = 0; k < 4; k++ ) {
		    PRINTF("rpc[%d] = %x\n",k,rpc[k] + 0x824F);
		    kanfont_get( kanfont, rpc[k] + 0x824F, kanadr );
		    kanadr += BUF_CT;
		    message->msg_b.msg_buff[i] = rpc[k] + 0x824F;
		    i++;
		    if ( k == 1 ) {
			kanfont_get( kanfont, 0x8E9E, kanadr );	/* "時" */
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = 0x8E9E;
			i++;
		    } else if ( k == 3 ) {
			kanfont_get( kanfont, 0x95AA, kanadr );	/* "分" */
			kanadr += BUF_CT;
			message->msg_b.msg_buff[i] = 0x95AA;
		    }
		}
	    } else if ( rd_dt == Z_DPITEM ) {
		message->msg_b.msg_buff[++i] = kanfont->mbuff.message_buf[message->rdp+1];
		PRINTF("ITEM_NO=(%d) (%d)\n",message->msg_b.msg_buff[i],kanfont->mbuff.message_buf[message->rdp+1]);
		dpitem_read( game_play, kanfont->mbuff.message_buf[message->rdp+1], VREG(1) + 10 );
	    } else if ( rd_dt == Z_TEXTURE ) {
		message->mes_board = kanfont->mbuff.message_buf[message->rdp+1] << 1;
		PRINTF("mes_board=%d\n",message->mes_board);
		message->mes_board_prim = (kanfont->mbuff.message_buf[message->rdp+2] & 0xF000) >> 12;
		message->mes_board_shadow = (kanfont->mbuff.message_buf[message->rdp+2] & 0x0F00) >> 8;
		message->mes_board_shift = (kanfont->mbuff.message_buf[message->rdp+2] & 0x00F0) >> 4;
		message->mes_board_anime = kanfont->mbuff.message_buf[message->rdp+2] & 0x000F;
		
		dmacopy_fg( message->fukidashiSegment + BALSZ,
			    (u32)_message_texture_staticSegmentRomStart + (((96*48)/2) * message->mes_board),
			    ((96*48)/2) );
		dmacopy_fg( message->fukidashiSegment + BALSZ + ((96*48)/2),
			    (u32)_message_texture_staticSegmentRomStart + (((96*48)/2) * (message->mes_board+1)),
			    ((96*48)/2) );
		message->rdp+=2;
		XREG(61) = VREG(1) + ((64-48)/2);
		jj = 2;
	    } else if ( rd_dt == CHANGE ) {
		message->msg_b.msg_buff[++i] = (kanfont->mbuff.message_buf[++message->rdp] & 0x0f);
	    } else if ( rd_dt == KAIGYO ) {
		jj++;
	    } else if ( rd_dt == Z_START || rd_dt == Z_STOP || rd_dt == Z_PAUSE || rd_dt == Z_OCARINA || rd_dt == Z_DISPSTOP || rd_dt == Z_NONONO ) {
	    } else if ( rd_dt == Z_TIMER_END ) {
		key_off_flag = 1;
		PRINTF("Z_TIMER_END (key_off_flag=%d)\n",key_off_flag);
		message->msg_b.msg_buff[++i] = (kanfont->mbuff.message_buf[++message->rdp] & 0xff);
	    } else if ( rd_dt == Z_BLANK || rd_dt == Z_SPEED ) {
		message->msg_b.msg_buff[++i] = (kanfont->mbuff.message_buf[++message->rdp] & 0xff);
/*	    } else if ( rd_dt == Z_BGM || rd_dt == Z_SE ) {*/
	    } else if ( rd_dt == Z_SE ) {
		message->msg_b.msg_buff[++i] = (kanfont->mbuff.message_buf[++message->rdp]);
	    } else if ( rd_dt == Z_SENTAKU_2 ) {
		message->item_dp = 2;
	    } else if ( rd_dt == Z_SENTAKU_3 ) {
		message->item_dp = 3;
		XREG(54) += ITEMSIZE;
	    } else if ( rd_dt != SPACE ) {
		kanfont_get( kanfont, rd_dt, kanadr );
		kanadr += BUF_CT;
	    }
	    i++;
	    message->rdp++;
	} while ( 1 );
    } else {
	/* 英語バージョン */
	do {
	    nes_rd_dt = message->msg_b.nes_msg_b[i] = kanfont->mbuff.nes_mes_buf[message->rdp];
////////	    PRINTF("msg_b.nes_msg_b[%d]=%x\n",i, message->msg_b.nes_msg_b[i] );
	    if ( nes_rd_dt  == NZ_KEYWAIT || nes_rd_dt == NZ_NEXTMSG || nes_rd_dt == NZ_TIMER || nes_rd_dt == NZ_ENEMY || nes_rd_dt == ND_SYURYOU ) {
		message->msg_mode = M_DISPLAY;
		message->end = 1;
		XREG(55) = VREG(1) + 8;					// ４行メッセージ
		PRINTF("ＪＪ＝%d\n",jj);
		if ( message->msg_disp_type0 != 0x4 ) {
		    if ( !jj ) XREG(55) =  VREG(1) + 10 + 16;		// １行メッセージ
		    else if ( jj == 1 ) XREG(55) = VREG(1) + 20;	// ２行メッセージ
		    else if ( jj == 2 ) XREG(55) = VREG(1) + 16;	// ３行メッセージ
		}
		if ( nes_rd_dt == NZ_NEXTMSG ) {
		    PRINTF("NZ_NEXTMSG=%x, %x, %x\n",kanfont->mbuff.nes_mes_buf[message->rdp],kanfont->mbuff.nes_mes_buf[message->rdp+1],kanfont->mbuff.nes_mes_buf[message->rdp+2]);
		    score =
			message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[message->rdp+1];
		    score <<= 8;
		    message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[message->rdp+2];
		    next_msg_no = score | message->msg_b.nes_msg_b[i];
		    
		}
		if ( nes_rd_dt == NZ_TIMER ) {
		    message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[message->rdp+1];
		    message->rdp+=2;
		}
	    
		message->rd_end = i;
		if ( last_flag ) message->end = message->rd_end;
		break;
	    } else if ( nes_rd_dt == NZ_NAME ) {
		for ( j = 8; j > 0; j-- ) {
		    if ( Player_Name[j-1] != SSS ) break;
		}
		PRINTF("\n名前 ＝ ");
		for ( k = 0; k < j; k++ ) {
		    nes_rd_dt = Player_Name[k];
		    if ( nes_rd_dt == SSS ) nes_rd_dt = ' ';
		    else if ( nes_rd_dt == SPO ) nes_rd_dt = '.';
		    else if ( nes_rd_dt == SPD ) nes_rd_dt = '-';
		    else if ( nes_rd_dt <= SS9 ) {
			nes_rd_dt -= SS0;
			nes_rd_dt += '0';
		    } else if ( nes_rd_dt <= AAZ ) {
			nes_rd_dt -= AAA;
			nes_rd_dt += 'A';
		    } else if ( nes_rd_dt <= AXZ ) {
			nes_rd_dt -= AXA;
			nes_rd_dt += 'a';
		    }
		    if ( nes_rd_dt != ' ' ) {
			kanfont_get_NES( kanfont, (nes_rd_dt - 0x20), kanadr );
			kanadr += BUF_CT;
		    }
		    PRINTF("%x ",nes_rd_dt);
		    message->msg_b.nes_msg_b[i] = nes_rd_dt;
		    i++;
		}
		i--;
	    } else if ( nes_rd_dt == NZ_EVENT_0 || nes_rd_dt == NZ_EVENT_1 ) {
		PRINTF("\nＥＶＥＮＴタイマー ＝ ");
		rpc[0] = rpc[1] = rpc[2] = 0;
/*		if ( ZCommonGet( event_fg ) ) {*/
		if ( nes_rd_dt == NZ_EVENT_1 ) {
		    rpc[3] = ZCommonGet( event_tm );
		} else {
		    rpc[3] = ZCommonGet( total_event_tm );
		}
		while ( rpc[3] >= 60 ) {
		    rpc[1]++;
		    if ( rpc[1] >= 10 ) {
			rpc[0]++;
			rpc[1] -= 10;
		    }
		    rpc[3] -= 60;
		}
		while ( rpc[3] >= 10 ) {
		    rpc[2]++;
		    rpc[3] -=10;
		}
		for ( k = 0; k < 4; k++ ) {
		    kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
		    kanadr += BUF_CT;
		    message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
		    i++;
		    if ( k == 1 ) {
			kanfont_get_NES( kanfont, 0x02, kanadr );	/* "分" */
			kanadr += BUF_CT;
			message->msg_b.nes_msg_b[i] = 0x22;
			i++;
		    } else if ( k == 3 ) {
			kanfont_get_NES( kanfont, 0x02, kanadr );	/* "秒" */
			kanadr += BUF_CT;
			message->msg_b.nes_msg_b[i] = 0x22;
		    }
		}
	    } else if ( nes_rd_dt == NZ_YABUSAME ) {
		PRINTF("\n流鏑馬スコア ＝ %d\n",Yabusame_Total);
		rpc[0] = rpc[1] = rpc[2] = 0;
		rpc[3] = Yabusame_Total;
		while ( rpc[3] >= 1000 ) {
		    rpc[0]++;
		    rpc[3] -= 1000;
		}
		while ( rpc[3] >= 100 ) {
		    rpc[1]++;
		    rpc[3] -=100;
		}
		while ( rpc[3] >= 10 ) {
		    rpc[2]++;
		    rpc[3] -=10;
		}
		for ( k = m = 0; k < 4; k++ ) {
		    if ( k == 3 || rpc[k] ) m = 1;
		    if ( m ) {
			kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
			message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
			kanadr += BUF_CT;
			i++;
		    }
		}
		i--;
	    } else if ( nes_rd_dt == NZ_KINSTA ) {
		PRINTF("\n金スタ合計数 ＝ %d",N_COIN_TOTAL);
		rpc[0] = rpc[1] = 0;
		rpc[2] = N_COIN_TOTAL;
		while ( rpc[2] >= 100 ) {
		    rpc[0]++;
		    rpc[2] -=100;
		}
		while ( rpc[2] >= 10 ) {
		    rpc[1]++;
		    rpc[2] -=10;
		}
		for ( k = m = 0; k < 3; k++ ) {
		    if ( k == 2 || rpc[k] ) m = 1;
		    if ( m ) {
			kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
			kanadr += BUF_CT;
			message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
			PRINTF("%x(%x) ",rpc[k] + 0x10, rpc[k]);
			i++;
		    }
		}
		i--;
	    } else if ( nes_rd_dt == NZ_FISHSZ ) {
		PRINTF("\n釣り堀魚サイズ ＝ ");
		rpc[0] = 0;
		rpc[1] = Yabusame_Total;
		while ( rpc[1] >= 10 ) {
		    rpc[0]++;
		    rpc[1] -=10;
		}
		for ( k = 0; k < 2; k++ ) {
		    if ( k == 1 || rpc[k] ) {
			kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
			kanadr += BUF_CT;
			message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
			PRINTF("%x(%x) ",rpc[k] + 0x10, rpc[k]);
			i++;
		    }
		}
		i--;
	    } else if ( nes_rd_dt == NZ_RANKING ) {
		/* ランキング */
		score = (unshort)HI_SCORE( kanfont->mbuff.nes_mes_buf[++message->rdp] );
		PRINTF("ランキング＝%d\n",kanfont->mbuff.nes_mes_buf[message->rdp] & 0xff);
		if ( (kanfont->mbuff.nes_mes_buf[message->rdp] & 0xff) == HS_FISH ) {
		    if ( ZCommon_LinkAgeIsChild() ) {
			score &= 0x7f;
		    } else {
			PRINTF("HI_SCORE( kanfont->mbuff.nes_mes_buf[message->rdp] & 0xff000000 ) = %x\n",HI_SCORE( kanfont->mbuff.message_buf[message->rdp] & 0xff000000 ) );
			score = (unshort)((HI_SCORE(kanfont->mbuff.nes_mes_buf[message->rdp]) & 0xff000000) >> 24);
			score &= 0x7f;
		    }
		    r = (float)score;
		    score = (unshort)(r * r * 0.0036f + 0.5f);
		    PRINTF("score=%d\n",score);
		}
		switch ( kanfont->mbuff.nes_mes_buf[message->rdp] & 0xff ) {
		case HS_YABU:	/* 流鏑馬 ＨｉーＳｃｏｒｅ */
		case HS_POW:	/* ポ─   ＨｉーＳｃｏｒｅ */
		case HS_FISH:	/* つり   ＨｉーＳｃｏｒｅ */
		    rpc[0] = rpc[1] = rpc[2] = 0;
		    rpc[3] = score;
		    while ( rpc[3] >= 1000 ) {
			rpc[0]++;
			rpc[3] -= 1000;
		    }
		    while ( rpc[3] >= 100 ) {
			rpc[1]++;
			rpc[3] -=100;
		    }
		    while ( rpc[3] >= 10 ) {
			rpc[2]++;
			rpc[3] -=10;
		    }
		    for ( k = m = 0; k < 4; k++ ) {
			if ( k == 3 || rpc[k] ) m = 1;
			if ( m ) {
			    kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
			    message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
			    kanadr += BUF_CT;
			    i++;
			}
		    }
		    i--;
		    break;
		case HS_EPONA:	/*  （エポナレース）ＨｉーＳｃｏｒｅ */
		case HS_MARASON:/*  （マラソンマン）ＨｉーＳｃｏｒｅ */
		case HS_DANPI:	/*  墓下リレー（ダンペイ）ＨｉーＳｃｏｒｅ */
		    rpc[0] = rpc[1] = rpc[2] = 0;
		    rpc[3] = score;
		    while ( rpc[3] >= 60 ) {
			rpc[1]++;
			if ( rpc[1] >= 10 ) {
			    rpc[0]++;
			    rpc[1] -= 10;
			}
			rpc[3] -= 60;
		    }
		    while ( rpc[3] >= 10 ) {
			rpc[2]++;
			rpc[3] -= 10;
		    }
		    for ( k = 0; k < 4; k++ ) {
			kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
			kanadr += BUF_CT;
			message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
			i++;
			if ( k == 1 ) {
			    kanfont_get_NES( kanfont, 0x02, kanadr );	/* "分" */
			    kanadr += BUF_CT;
			    message->msg_b.nes_msg_b[i] = 0x22;
			    i++;
			} else if ( k == 3 ) {
			    kanfont_get_NES( kanfont, 0x02, kanadr );	/* "秒" */
			    kanadr += BUF_CT;
			    message->msg_b.nes_msg_b[i] = 0x22;
			}
		    }
		    break;
		default:
		    break;
		}
	    } else if ( nes_rd_dt == NZ_ZELDATM ) {
		PRINTF("\nゼルダ時間 ＝ ");
		rpc[0] = 0;
		rpc[1] = (short)((float)ZCommonGet(zelda_time) * 0.021972656f / 60.0f );
		while ( rpc[1] >= 10 ) {
		    rpc[0]++;
		    rpc[1] -=10;
		}
		rpc[2] = 0;
		rpc[3] = (short)((float)ZCommonGet(zelda_time) * 0.021972656f) % 60;
		while ( rpc[3] >= 10 ) {
		    rpc[2]++;
		    rpc[3] -=10;
		}
		for ( k = 0; k < 4; k++ ) {
		    kanfont_get_NES( kanfont, rpc[k] + 0x10, kanadr );
		    kanadr += BUF_CT;
		    message->msg_b.nes_msg_b[i] = rpc[k] + 0x30;
		    i++;
		    if ( k == 1 ) {
			kanfont_get_NES( kanfont, 0x1A, kanadr );	/* "時" */
			kanadr += BUF_CT;
			message->msg_b.nes_msg_b[i] = 0x3A;
			i++;
		    }
		}
		i--;
	    } else if ( nes_rd_dt == NZ_DPITEM ) {
		message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[message->rdp+1];
		PRINTF("ITEM_NO=(%d) (%d)\n",message->msg_b.nes_msg_b[i],kanfont->mbuff.nes_mes_buf[message->rdp+1]);
		dpitem_read( game_play, (unshort)kanfont->mbuff.nes_mes_buf[message->rdp+1], VREG(1) + 10 );
# if 0
		if ( kanfont->mbuff.nes_mes_buf[message->rdp+1] == H_map ) {
		    parameter->map_palete[30] = 255;
		    parameter->map_palete[31] = 255;
		}
////////		if ( kanfont->mbuff.nes_mes_buf[message->rdp+1] < H_holystone_1 ) {
		if ( kanfont->mbuff.nes_mes_buf[message->rdp+1] < H_seal_medal_1 ) {
		    dmacopy_fg( message->fukidashiSegment + BALSZ,
				(u32)_icon_item_staticSegmentRomStart + (I_IT_PT * kanfont->mbuff.nes_mes_buf[message->rdp+1] ),
				I_IT_PT );
		    PRINTF("アイテム32-0\n");
////////		} else if ( kanfont->mbuff.nes_mes_buf[message->rdp+1] < H_seal_medal_1/*H_purse_1*/ ) {
		} else {
		    dmacopy_fg( message->fukidashiSegment + BALSZ,
////////				(u32)_icon_item_24_staticSegmentRomStart + (I_IT_P1 * (kanfont->mbuff.nes_mes_buf[message->rdp+1] - H_holystone_1) ),
				(u32)_icon_item_24_staticSegmentRomStart + (I_IT_P1 * (kanfont->mbuff.nes_mes_buf[message->rdp+1] - H_seal_medal_1) ),
				I_IT_P1 );
		    PRINTF("アイテム24＝%d (%d) {%d}\n",kanfont->mbuff.nes_mes_buf[message->rdp+1], kanfont->mbuff.nes_mes_buf[message->rdp+1] - H_holystone_1, H_scale_2);
# if 0
		} else {
		    dmacopy_fg( message->fukidashiSegment + BALSZ,
				(u32)_icon_item_staticSegmentRomStart + (I_IT_PT * H_scale_2) + (I_IT_PT * (kanfont->mbuff.nes_mes_buf[message->rdp+1] - H_seal_medal_1/*H_purse_1*/)),
				I_IT_PT );
		    PRINTF("アイテム32-1＝%d (%d)n",kanfont->mbuff.nes_mes_buf[message->rdp+1], kanfont->mbuff.nes_mes_buf[message->rdp+1] - H_seal_medal_1/*H_purse_1*/);
# endif
		}
		message->rdp+=1;
		message->item_dp = 1;
# endif
	    } else if ( nes_rd_dt == NZ_TEXTURE ) {
		message->mes_board = kanfont->mbuff.nes_mes_buf[message->rdp+1] << 1;
////////		message->mes_board_prim = (kanfont->mbuff.nes_mes_buf[message->rdp+2] & 0xF000) >> 12;
////////		message->mes_board_shadow = (kanfont->mbuff.nes_mes_buf[message->rdp+2] & 0x0F00) >> 8;
		message->mes_board_prim = (kanfont->mbuff.nes_mes_buf[message->rdp+2] & 0x00F0) >> 4;
		message->mes_board_shadow = kanfont->mbuff.nes_mes_buf[message->rdp+2] & 0x000F;
		message->mes_board_shift = (kanfont->mbuff.nes_mes_buf[message->rdp+3] & 0x00F0) >> 4;
		message->mes_board_anime = kanfont->mbuff.nes_mes_buf[message->rdp+3] & 0x000F;
		
		////////	    dmacopy_fg( message->fukidashiSegment + BALSZ + I_IT_PT,
		dmacopy_fg( message->fukidashiSegment + BALSZ,
			    (u32)_message_texture_staticSegmentRomStart + (((96*48)/2) * message->mes_board),
			    ((96*48)/2) );
		////////	    dmacopy_fg( message->fukidashiSegment + BALSZ + I_IT_PT + ((96*48)/2),
		dmacopy_fg( message->fukidashiSegment + BALSZ + ((96*48)/2),
			    (u32)_message_texture_staticSegmentRomStart + (((96*48)/2) * (message->mes_board+1)),
			    ((96*48)/2) );
		message->rdp+=3;
		XREG(61) = VREG(1) + ((64-48)/2);
		jj = 2;
	    } else if ( nes_rd_dt == NCHANGE ) {
		message->msg_b.nes_msg_b[++i] = (kanfont->mbuff.nes_mes_buf[++message->rdp]);
	    } else if ( nes_rd_dt == NKAIGYO ) {
		jj++;
	    } else if ( nes_rd_dt == NZ_START || nes_rd_dt == NZ_STOP || nes_rd_dt == NZ_PAUSE || nes_rd_dt == NZ_OCARINA || nes_rd_dt == NZ_DISPSTOP || nes_rd_dt == NZ_NONONO ) {
	    } else if ( nes_rd_dt == NZ_TIMER_END ) {
		key_off_flag = 1;
		PRINTF("NZ_TIMER_END (key_off_flag=%d)\n",key_off_flag);
		message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[++message->rdp];
	    } else if ( nes_rd_dt == NZ_BGM ) {
		key_off_flag = 1;
		PRINTF("NZ_BGM (key_off_flag=%d)\n",key_off_flag);
		message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[++message->rdp];
		message->msg_b.nes_msg_b[++i] = kanfont->mbuff.nes_mes_buf[++message->rdp];
	    } else if ( nes_rd_dt == NZ_BLANK || nes_rd_dt == NZ_SPEED ) {
		message->msg_b.nes_msg_b[++i] = (kanfont->mbuff.nes_mes_buf[++message->rdp] & 0xff);
/*	    } else if ( nes_rd_dt == NZ_BGM || nes_rd_dt == NZ_SE ) {*/
	    } else if ( nes_rd_dt == NZ_SE ) {
		message->msg_b.nes_msg_b[++i] = (kanfont->mbuff.nes_mes_buf[++message->rdp]);
		message->msg_b.nes_msg_b[++i] = (kanfont->mbuff.nes_mes_buf[++message->rdp]);
	    } else if ( nes_rd_dt == NZ_SENTAKU_2 ) {
		message->item_dp = 2;
	    } else if ( nes_rd_dt == NZ_SENTAKU_3 ) {
		message->item_dp = 3;
////////		XREG(54) += ITEMSIZE;
	    } else if ( nes_rd_dt != NSPACE ) {
		kanfont_get_NES( kanfont, (nes_rd_dt - 0x20), kanadr );
		kanadr += BUF_CT;
	    }
	    i++;
	    message->rdp++;
	} while ( 1 );
    }
}


/*=======================================================================
  =	吹き出しＤＭＡ							=
  =======================================================================*/
static void
fukidashi_dma( Game_play *game_play, unshort message_no )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    static short fukidashi_kids[] = {
	0, 1, 3, 2,
    };

    short	j;

    if ( message->msg_mode == M_NULL ) LAST_TIME_TYPE = Z_PREV_ALPHA_TYPE;
    if ( YREG(15) == 0x10 ) alpha_change( 5 );
    se_flag =
	start_flag =
	last_flag =
	staff_mode = 0;

    if ( message_no >= 0x500 && message_no <= 0x5ff ) {
	staff_mode = 1;
	/* ＳＴＡＦＦ版 */
	XREG(57) = 85;
	XREG(56) = 6;		// １行サイズ
	XREG(54) = 20;		// メッセージ表示位置Ｘ
	YREG(1) = 48;
    } else if ( !J_N ) {
	/* 日本版 */
	XREG(57) = 88;
	XREG(56) = 18;		// １行サイズ
	XREG(54) = 50;		// メッセージ表示位置Ｘ
    } else {
	/* ＮＥＳ版 ／ ＳＴＡＦＦ用 */
	XREG(57) = 75;
	XREG(56) = 12;		// １行サイズ
	XREG(54) = 65;		// メッセージ表示位置Ｘ
    }
    if ( message_no == 0x00c2 || message_no == 0x00fa ) {		/* ハートの欠片 */
	message_no += GetCollect_Heart;
    } else if ( message->msgno == 0x000c && Equip_Sword_CK( H_sword_2 ) ) {
	/* 巨人のナイフすでに持っている。*/
	message_no = 0x000b;
    } else if ( message->msgno == 0x00b4 && Get_Event_Chk_Inf( 9, 0x0040 ) ) {
	/* 金スタおやじとしゃべった */
	message_no = 0x00b5;
    }

    /* メーター消しチェック */
    if ( message_no == 0x4077 ||
	 message_no == 0x407a ||
	 message_no == 0x2061 ||
	 message_no == 0x5035 ||
	 message_no == 0x40ac )
	alpha_change( 1 );
# if 0
    if ( message_no == 0x60 ) {		/* 小さなカギ */
	message_no += (game_play->scene_data_ID - MORI1);
    }
# endif
    message->msgno = message_no;
    if ( message_no == 0x2030 ) {
	COLOR_YELLOW();
	PRINTF("？？？？？？？？？？？？？？？？  z_message.c  ？？？？？？？？？？？？？？？？？？\n");
	COLOR_NORMAL();
	EVENT_INF(0) =
	    EVENT_INF(1) =
	    EVENT_INF(2) =
	    EVENT_INF(3) = 0;
    }
    /* メッセージ情報 取得 */
    if ( staff_mode ) {
	get_msg_add_get_STAFF( game_play, message_no );
	message->msg_data = kanfont->msg_data0;
	/* メッセージデータバッファセット */
#if defined(USE_N64DD)
        if (n64dd_function_ok(message_staff) && n64dd_function_call(message_staff)( kanfont)) {
		/* DDのデータを転送した */
    	} else
#endif /* defined(USE_N64DD) */
        {
	    dmacopy_fg( &kanfont->mbuff.nes_mes_buf[0], (u32)_staff_message_data_staticSegmentRomStart+(u32)kanfont->msg_data, (u32)kanfont->msg_data0 );
	}
    } else if ( !J_N ) {
	get_msg_add_get( game_play, message_no );
	message->msg_data = kanfont->msg_data0;
	/* メッセージデータバッファセット */
#if defined(USE_N64DD)
	if (n64dd_function_ok(message_jpn) && n64dd_function_call(message_jpn)( kanfont)) {
		/* DDのデータを転送した */
    	} else
#endif /* defined(USE_N64DD) */
        {
	    dmacopy_fg( &kanfont->mbuff.message_buf[0], (u32)_message_data_staticSegmentRomStart+(u32)kanfont->msg_data, (u32)kanfont->msg_data0 );
	}
    } else {
	get_msg_add_get_NES( game_play, message_no );
	message->msg_data = kanfont->msg_data0;
	/* メッセージデータバッファセット */
#if defined(USE_N64DD)
	if (n64dd_function_ok(message_nes) && n64dd_function_call(message_nes)( kanfont)) {
		/* DDのデータを転送した */
    	} else
#endif /* defined(USE_N64DD) */
        {
	    dmacopy_fg( &kanfont->mbuff.nes_mes_buf[0], (u32)_nes_message_data_staticSegmentRomStart+(u32)kanfont->msg_data, (u32)kanfont->msg_data0 );
	}
    }
    /* ＴＹＰＥ */
    message->msg_disp_type = kanfont->kbuffer[0];
    message->msg_disp_type0 = message->msg_disp_type >> 4;
    message->msg_disp_type1 = message->msg_disp_type & 0xf;

    
    /* 吹き出しgamealloc_malloc */
    j = message->msg_disp_type0;
    PRINTF("吹き出し種類＝%d\n",j);
////////    if ( !j || j == 1 || j == 3 ) {
    if ( j <= 3 ) {
	dmacopy_fg( message->fukidashiSegment,
		    (u32)_message_staticSegmentRomStart + (BALSZ * fukidashi_kids[j]),
		    BALSZ );
	if ( !j ) {
	    /* 通常カラー */
	    message->fc_r = 0;
	    message->fc_g = 0;
	    message->fc_b = 0;
	} else  if ( j == 1 ) {
	    /* 立て札カラー */
	    message->fc_r = 70; /*150;*/
	    message->fc_g = 50; /*80;*/
	    message->fc_b = 30; /*0;*/
	} else if ( j == 2 ) {
	    /* ナレーション */
	    message->fc_r = 0;
	    message->fc_g = 10;
	    message->fc_b = 50;
	} else {
	    /* オカリナカラー */
	    message->fc_r = 255;
	    message->fc_g = 0;
	    message->fc_b = 0;
	}
	if ( j == 1 )        message->fc_a = 230;
	else if ( j == 3 )   message->fc_a = 180;
	else                 message->fc_a = 170;
	message->fc_alpha = 0;
    }
    message->item_dp     =
	message->nonono_fg =
	message->select	 = 0;
	
    message->rdp	= 
	message->ldp	= 
	message->end	= 0;

}


/************************************************************************
 *									*
 *	メッセージ 設定							*
 *									*
 ************************************************************************/
extern void
message_set( Game_play *game_play, unshort message_no, Actor *talk_actor )
{
    Message		*message = (Message *)&game_play->message;
    
    COLOR_BLUE();
    PRINTF("めっせーじ＝%x(%d)\n",message_no,talk_actor);
    COLOR_NORMAL();
    /* 吹き出しＤＭＡ */
    message->ocarina_no = 0xffff;
    fukidashi_dma( game_play, message_no );
////////    if ( talk_actor != NULL ) {
////////	Na_StartSystemSe( NA_SE_SY_MESSAGE_WIN_OPEN );
////////    }
    message->talk_actor = talk_actor;	/* 会話相手のポインタ保存 */

    /* 基本データ セット */
    message->msg_mode = M_MOVE;
    message->wct      = 0;
    message->mspd = 0;
    OCARINA_MODE( game_play ) = Oca_Null;
}
/************************************************************************
 *									*
 *	メッセージ 設定							*
 *									*
 ************************************************************************/
extern void
message_set2( Game_play *game_play, unshort message_no )
{
    Message		*message = (Message *)&game_play->message;

    Parameter		*parameter = (Parameter *)&game_play->parameter;

//    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

//    short		i;
//    int			kanadr;

    COLOR_GREEN();
    PRINTF("めっせーじ＝%x  message->msg_data\n",message_no,message->msg_data);
    COLOR_NORMAL();

    message->msg_data = NULL;

    /* 吹き出しＤＭＡ */
    fukidashi_dma( game_play, message_no );

    message->msg_mode = M_NULL;

    message->fc_alpha =  message->fc_a;

////////    message->msg_mode = M_READ;
    message->msg_mode = M_REST;
    message->wct = 3;
    message->select = 
	message->rdp = 
	message->ldp = 
	message->end =
	message->mspd = 0;

    message->color_a = 255;

////////    if ( YREG(15) != 0x10 ) {	/* お店 */
    if ( !YREG(31) && !parameter->sp_action_flag ) {	/* お店 */
	DO_ACTION_POINT_SET( game_play, DO_Tsugihe );
    }
    
    message->fc_alpha =  message->fc_a;

}


/************************************************************************
 *									*
 *	オカリナ設定							*
 *									*
 ************************************************************************/
static void
ocarina_set_sub( Game_play *game_play, unshort ocarina_no )
{
    Message		*message = (Message *)&game_play->message;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    static unshort ocarina_check_bit[] = {
	0x0001,
	0x0002,
	0x0004,
	0x0008,
	0x0010,
	0x0020,
	0x0100,
	0x0080,
	0x0040,
	0x0200,
	0x0400,
	0x0800,
	0x1000,
    };
    short		i, k, kkk;
    int			kanadr;
    

    
    COLOR_GREEN();
    for ( k = ocarina_bit = 0; k < C_MELODY; k++ ) {
	if ( Collect_Register(C_SEAL+k) ) {
	    PRINTF("ocarina_check_bit[%d]=%x\n",k,ocarina_check_bit[k]);
	    ocarina_bit |= ocarina_check_bit[k];
	}
    }
    if ( OCA_REC_FLAG8 ) ocarina_bit |= 1<<NA_OCA_CHK_RECMELODY2;
    PRINTF("ocarina_bit = %x\n",ocarina_bit);
    COLOR_NORMAL();
    
    SunMoon_Ocarina = GetCollect_MELODY( H_melody_10 );	
    message->info = Na_GetOcarinaRecInfoWork();
    message->info->locate = onpu_pt = 0;
    onpu_ct = 0;
    /* 音符バッファ初期化 */
    onpu_buff_reset();
    Chk_Ocarina_No =
    message->chk_ocarina_no = 
	message->frame_cfg = 0xff;

    PRINTF( "\033[31m☆☆☆☆☆ オカリナ番号＝%d(%d) ☆☆☆☆☆\n\033[m", ocarina_no,Ocarina_Wind );
    kkk = 0;
    if ( ocarina_no >= 0x0893 ) {
	fukidashi_dma( game_play, ocarina_no );
    } else if ( ocarina_no == Ocarina_Round ) {
	message->ocarina_no = ocarina_no;
	fukidashi_dma( game_play, OCARINA_BASE-1 );
    } else if ( ocarina_no == Ocarina_Free || ocarina_no >= Ocarina_PC_Salia ) {
	PRINTF("ocarina_set 000000000000000000  = %d\n",ocarina_no);
	message->ocarina_no = ocarina_no;
	if ( ocarina_no >= Ocarina_PC_Salia && ocarina_no <= Ocarina_PC_Storm )
	    Na_StartSystemSe(NA_SE_SY_HINT_CHIME);
	if ( ocarina_no == Ocarina_ScarecrowP )
	    fukidashi_dma( game_play, OCARINA_BASE+1 );
	else
	    fukidashi_dma( game_play, OCARINA_BASE );
/*    } else if ( ocarina_no >= Ocarina_Salia ) {
	PRINTF("ocarina_set 111111111111111111\n");
	message->ocarina_no = ocarina_no;
	fukidashi_dma( game_play, OCARINA_BASE );*/
    } else {
	message->ocarina_no = ocarina_no;
	kkk = 1;
	if ( ocarina_no >= Ocarina_C_Wind ) {
	    PRINTF("222222222\n");
	    fukidashi_dma( game_play, OCARINA_BASE - 1 );
	} else {
	    PRINTF("333333333\n");
	    fukidashi_dma( game_play, OCARINA_BASE+ocarina_no );
	}
    }
    message->talk_actor = NULL;	

    /* オカリナモード セット */
    PRINTF("オカリナモード = %d  (%x)\n",message->ocarina_no, OCARINA_BASE+ocarina_no );
    message->mspd = 0;
    OCARINA_MODE( game_play ) = Oca_Null;
    VREG(0) = 34;
    VREG(1) = 142;
    YREG(16) = 512;
    YREG(17) = 512;
    YREG(22) = 256;
    YREG(23) = 64;
    /* メッセージデータ読み込み */
//    message_read( game_play );

    message->wct = 0;
    if ( YREG(12) ) message->msg_mode = M_READ;
    else {
	message->wct = 2;
	message->msg_mode = M_REST;
    }
    message->fc_alpha =  message->fc_a;
///////    DO_ACTION_POINT_SET( game_play, DO_Yameru );
    if ( !kkk ) {
	DO_ACTION_SPECIAL( game_play, DO_Yameru );

////////    kkk = LAST_TIME_TYPE;
	kkk = Z_PREV_ALPHA_TYPE;
	alpha_change( 10 );
	Z_PREV_ALPHA_TYPE = kkk;
////////    LAST_TIME_TYPE = kkk;
    }
    PRINTF("演奏開始\n");
    if ( ocarina_no == Ocarina_Free || ocarina_no == Ocarina_Flog ) {
	message->msg_mode = M_OCARINA0;
	message->msg_disp_type0 = 99;
    } else if ( ocarina_no == Ocarina_Chorus ) {
	message->msg_mode = M_OCARINA80;
	message->msg_disp_type0 = 2;
    } else if ( ocarina_no == Ocarina_Round ) {
////////	kkk = LAST_TIME_TYPE;
	alpha_change( 1 );
////////	LAST_TIME_TYPE = kkk;
	message_read( game_play );
	message->msg_mode = M_OCARINA60;
    } else if ( ocarina_no == Ocarina_PlayBack ) {
	PRINTF("?????録音再生 録音再生 録音再生 録音再生  -> ");
	Na_StartOcarinaMode();
	Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	message->info = Na_GetOcarinaSeqInfoWork();
	message->info->locate = onpu_pt = onpu_ct = 0;
	/* 音符バッファ初期化 */
	onpu_buff_reset();
	message->wct = 3;
	message->msg_mode = M_OCARINA42;
	Na_StartOcarinaSeq( NA_OCA_CHK_RECMELODY, 1 );
	Z_PREV_ALPHA_TYPE = 0;
	alpha_change( 1 );
    } 
    for ( i = kanadr = 0; i < 16*3; i++ ) {
	kanfont_get( kanfont, 0x8140, kanadr );
	kanadr += BUF_CT;
    }
}
/************************************************************************
 *									*
 *	オカリナ設定							*
 *									*
 ************************************************************************/
extern void
ocarina_set( Game_play *game_play, unshort ocarina_no )
{
    Message		*message = (Message *)&game_play->message;

    message->sunmoon_flg = 0;	/* 太陽の歌許可 */

    ocarina_set_sub( game_play, ocarina_no );
}
/************************************************************************
 *									*
 *	オカリナ設定							*
 *									*
 ************************************************************************/
extern void
ocarina_set_111( Game_play *game_play, unshort ocarina_no )
{
    Message		*message = (Message *)&game_play->message;

    message->sunmoon_flg = 1;	/* 太陽の歌禁止 */

    ocarina_set_sub( game_play, ocarina_no );
}





/************************************************************************
 *	メッセージ 終了チェック						*
 *									*
 *	Ｒｅｔｒｕｎ値	０：Ｎｏｔｈｉｎｇメッセージ			*
 *			１：次のメッセージ有り				*
 *			２：メッセージ終了				*
 *			３：メッセージ出力中				*
 *			４：選択					*
 *			５：敵側制御					*
 *			６：メッセージ出力終了				*
 *			７：オカリナ自動演奏終了			*
 *			８：オカリナ演奏正解				*
 *			９：オカリナ演奏誤り				*
 *		      １０：改行待ち					*
 ************************************************************************/
extern char
message_check( Message *message )
{
    char	a;

    if ( message->msg_data == NULL ) a = Mes_Null /* メッセージＮｏｔｈｉｎｇ */;
    else {
	if ( message->msg_mode == M_END ) {
	    if ( message->select == __Next_Message ) a = Mes_Next /* 次のメッセージ有り */;
	    else if ( message->select == __2_SELECT || message->select == __3_SELECT ) a = Mes_Select; /* 選択 */
	    else if ( message->select == __ENEMY || message->select == __DISPSTOP ) a = Mes_Enemy; /* 敵側制御 */
	    else if ( message->select == __TIMER ) a = Mes_Draw; /* メッセージ出力中 */
	    else a = Mes_DpEnd; /* メッセージ出力終了 */
	} else if ( message->msg_mode == M_NEXT ) {
	    a = Mes_Keywait;	/* 改行待ち */
	} else if ( message->msg_mode == M_OCARINA12 ) {
	    a = Mes_Oca00;	/* オカリナ自動演奏終了 */
////////	} else if ( message->msg_mode == M_OCARINA21 ) {
	} else if ( message->ocarina_mode == Oca_Hit ) {
	    a = Mes_Oca10;	/* オカリナ演奏正解 */
	} else if ( message->msg_mode == M_OCARINA24 ) {
	    a = Mes_Oca20;	/* オカリナ演奏誤り */
	} else {
	    if ( message->msg_mode == M_CLOSE && message->wct == 1 ) a = Mes_End; /* メッセージ終了 */
	    else a = Mes_Draw; /* メッセージ出力中 */
	}
    }
////////    PRINTF("ＲＥＴＵＲＮ値＝%d\n",a);
    return(a);
}
	
	
	


/*===============================================================
  =	   吹き出し表示処理					=
 ===============================================================*/
static void
fukidashi_display( Game_play *game_play, Gfx **glistp )
{
    Message		*message = (Message *)&game_play->message;

    Gfx 		*gp = *glistp;


    gDPPipeSync( gp++ );
    gDPSetPrimColor( gp++, 0, 0, message->fc_r, message->fc_g, message->fc_b, message->fc_alpha );
    if ( !message->msg_disp_type0 || message->msg_disp_type0 == 0x2 ) {
	gDPLoadTextureBlock_4b( gp++,
				message->fukidashiSegment, G_IM_FMT_I, 128, 64, 0,
				G_TX_MIRROR, G_TX_NOMIRROR,
				7, 0,
				G_TX_NOLOD, G_TX_NOLOD );
    } else {
	if ( message->msg_disp_type0 == 0x3 ) {
	    gDPSetEnvColor( gp++, 0, 0, 0, 255 );
	} else {
	    gDPSetEnvColor( gp++, 50, 20, 0, 255 );
	}
	gDPLoadTextureBlock_4b( gp++,
				message->fukidashiSegment, G_IM_FMT_IA, 128, 64, 0,
				G_TX_MIRROR, G_TX_MIRROR,
				7, 0,
				G_TX_NOLOD, G_TX_NOLOD );
    }
    gSPTextureRectangle( gp++,
			 VREG(0) << 2, VREG(1) << 2,
			 (VREG(0)+YREG(22)) << 2, (VREG(1)+YREG(23)) << 2,
			 G_TX_RENDERTILE,
			 0, 0, YREG(16) << 1, YREG(17) << 1 );

    if ( message->msg_disp_type0 == 0x3 ) {
	gDPPipeSync( gp++ );
	gDPSetCombineMode( gp++, G_CC_INT2, G_CC_INT2 );
	gDPSetPrimColor( gp++, 0, 0, 255, 100, 0, 255 );
	gDPLoadTextureBlock_4b( gp++,
				h_to_txt, G_IM_FMT_I, 16, 32, 0,
				G_TX_MIRROR, G_TX_MIRROR,
				G_TX_NOMASK, G_TX_NOMASK,
				G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( gp++,
			     VREG(7) << 2, VREG(8) << 2,
			     (VREG(7)+16) << 2, (VREG(8)+32) << 2,
			     G_TX_RENDERTILE,
			     0, 0, 1 << 10, 1 << 10 );
	
    }

    *glistp = gp;
}


/*===============================================================
  =	メッセージ 正射影ビュー設定				=
 ===============================================================*/
static void
message_view( Message *message )
{
    view_set_ScissorBox( &message->view, 0, 0, SCREEN_WD, SCREEN_HT );

    showOverLayView( &message->view );
}

    
/************************************************************************
 *									*
 *	メッセージＤＲＡＷ						*
 *									*
 ************************************************************************/
static void
message_draw_sub( Game_play *game_play, Gfx **glistp )
{
    Message		*message = (Message *)&game_play->message;

    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Kanfont		*kanfont = (Kanfont *)&message->kanfont;

    Actor		*player = (Actor *)get_player_actor(game_play);

    pad_t		*pad = &game_play->g.pads[0];

    Gfx 		*gp = *glistp;


    static short	profile_data[] = {
	Oceff_Wipe3, Oceff_Wipe2, Oceff_Wipe, Oceff_Spot, Oceff_Wipe, Oceff_Storm, Oceff_Wipe4,
    };
    static short	arg_data_data[] = {
	0, 0, 0, 0, 1, 0, 0,
    };
    static unchar 	*onpu[] = {
	h_s_a_txt, h_s_und_txt, h_s_r_txt, h_s_l_txt, h_s_up_txt,
    };
    static short	a_prim_color[][3] = {
    	{  80, 150, 255, },
    	{ 100, 200, 255, },
    };
    static short	a_env_color[][3] = {
    	{  10,  10,  10, },
    	{  50,  50, 255, },
    };
    static short	c_prim_color[][3] = {
    	{ 255, 255,  50, },
    	{ 255, 255, 180, },
    };
    static short	c_env_color[][3] = {
    	{  10,  10,  10, },
    	{ 110, 110,  50, },
    };
    static short 	mc = 12, mp = 1;
    short		rc, gc, bc;
    static unshort	ocarina_bgm[] = {
	NA_BGM_OCA_WIND, NA_BGM_OCA_FLAME, NA_BGM_OCA_WATER, NA_BGM_OCA_SOUL, NA_BGM_OCA_DARKNESS, NA_BGM_OCA_LIGHT,
	NA_BGM_OCA_SARIA, NA_BGM_OCA_EPONA, NA_BGM_OCA_ZELDA, NA_BGM_OCA_SUNMOON, NA_BGM_OCA_TIME, NA_BGM_OCA_STORM,
    };

    unshort   	i, j, xp, kanadr;



    gSPSegment ( gp++, DYNAMIC_SEGMENT,  game_play->parameter.parameterSegment );
    gSPSegment ( gp++, MESSAGE0_SEGMENT, message->fukidashiSegment);


    if ( message->msg_data != NULL ) {
	/*
	 * 吹き出し出力
	 */
	if ( message->ocarina_no != Ocarina_Chorus &&
	     message->msg_mode != M_OCARINAC &&
	     message->msg_mode >= M_OPEN && message->msg_mode < M_CLOSE &&
	     message->msg_disp_type0 <= 0x3 ) {
	    message_view( message );
	    gp_overlay_rectangle_a_prim( &gp );
	    fukidashi_display( game_play, &gp );
	}


	/*
	 *  メッセージ出力
	 */
	gp_overlay_rectangle_a_prim( &gp );
	gDPSetAlphaCompare( gp++, G_AC_NONE );
	gDPSetCombineMode( gp++, G_CC_INT4, G_CC_INT4 );

	switch ( message->msg_mode ) {
	case M_MOVE:
	    /* カメラ移動 */
	case M_OPEN:
	    /* メッセージ ウィンドウ ＯＰＥＮ */
	case M_WAIT:
	    /* Ｗａｉｔ */
	case M_READ:
	    /* バッファ読み込み */
	    break;
	    
	case M_REST:
	    /* 一時停止 */
	    if ( message->wct == 1 ) {
		for ( i = kanadr = 0; i < 16*3; i++ ) {
		    kanfont_get( kanfont, 0x8140, kanadr );
		    kanadr += BUF_CT;
		}
		if ( !J_N && !staff_mode ) {
		    message_write( game_play, &gp );
		} else {
		    message_write_NES( game_play, &gp );
		}
	    }
	    break;

	case M_DISPLAY:
	case M_TIMER:
	    /* メッセージ表示 */
////////	    if ( !(message->ocarina_no == Ocarina_Free || message->ocarina_no == Ocarina_Flog) ) {
		if ( !J_N && !staff_mode ) {
		    message_write( game_play, &gp );
		} else {
		    message_write_NES( game_play, &gp );
		}
////////	    }
	    break;

	case M_PAUSE:
	case M_NEXT:
	    /* 改ページ */
	    if ( !J_N && !staff_mode ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }

	    last_mark_display( game_play, &gp, XREG(64), XREG(65) );
	    break;
	    
	case M_OCARINA0:
	case M_OCARINA10_S:
	case M_OCARINA20_S:
	    /* 初期化 */
	    Na_StartOcarinaMode();
	    message->info = Na_GetOcarinaInfoWork();
	    message->info->locate = onpu_pt = 0;
	    OCARINA_MODE( game_play ) = Oca_Play;
	    /* 音符バッファ初期化 */
	    onpu_buff_reset();
	    mp = 1;
	    mc = 3;
	    if ( message->msg_mode == M_OCARINA0 ) {
		if ( message->ocarina_no == Ocarina_0 ||
		     message->ocarina_no == Ocarina_Free ||
		     message->ocarina_no == Ocarina_Scarecrow ||
		     message->ocarina_no == Ocarina_Flog ||
		     message->ocarina_no >= Ocarina_PC_Salia ) {
		    if ( message->ocarina_no == Ocarina_Free || message->ocarina_no == Ocarina_Flog ) {
			/* フリー演奏 */
/*???????			Na_StartOcarinaFreePlayCheck( NA_OCA_CHK_GRP_ALL );*/
			Na_StartOcarinaFreePlayCheck( ocarina_bit );
		    } else {
			/* 台上演奏 */
			PRINTF("台上演奏\n");
/*???????			Na_StartOcarinaPlayCheck2( NA_OCA_CHK_GRP_ALL );*/
			Na_StartOcarinaPlayCheck2( ocarina_bit );
		    }
# if 0
		    Na_StartOcarinaPlayCheck2( NA_OCA_CHK_GRP_WARP );
		} else if ( message->ocarina_no == Ocarina_1 ) {
		    Na_StartOcarinaPlayCheck2( NA_OCA_CHK_GRP_GROUND );
# endif
		} else {
		    PRINTF("Na_StartOcarinaSinglePlayCheck2( message->ocarina_no );\n");
		    Na_StartOcarinaSinglePlayCheck2( message->ocarina_no );
		}
		message->msg_mode = M_OCARINA1;
	    } else if ( message->msg_mode == M_OCARINA10_S ) {
		message->wct = 20;
		message->msg_mode = M_OCARINA10;
	    } else {
		Na_StartOcarinaSinglePlayCheck2( message->ocarina_no - Ocarina_C_Wind );
		PRINTF("演奏チェック=%d\n",message->ocarina_no - Ocarina_C_Wind);
////////		Na_StartMixBgm( message->ocarina_no - Ocarina_C_Wind + NA_BGM_OCA_WIND );
		message->msg_mode = M_OCARINA20;
	    }
	    if ( !(message->ocarina_no == Ocarina_Free || message->ocarina_no == Ocarina_Flog) ) {
		if ( !J_N && !staff_mode ) {
		    message_write( game_play, &gp );
		} else {
		    message_write_NES( game_play, &gp );
		}
	    }
	    break;
	    
	case M_OCARINA1:
	    /* 入力 */
	    message->info = Na_GetOcarinaInfoWork();
	    if ( message->info->locate ) {
		if ( message->info->locate == 1 && onpu_pt == 8 ) onpu_pt = 0;
		if ( onpu_pt == message->info->locate-1 ) {
		    message->frame_cfg = 
			onpu_buff[message->info->locate-1] = message->info->button;
		    onpu_buff[message->info->locate] = 0xff;
		    onpu_pt++;
		}
	    }
	    message->ocarina = message->info->status;
////?????////	    PRINTF("status=%d\n",message->info->status);
	    if ( message->info->status <= NA_OCA_CHK_RECMELODY2 ) {
////////		if ( Collect_Register(C_SEAL+message->info->status) ) {
////////		if ( GetCollect_MELODY( H_melody_1 + message->info->status ) ) {
		if ( message->info->status == NA_OCA_CHK_RECMELODY2 || GetCollect_MELODY( H_melody_1 + ocarina_number[message->info->status] ) ) {
		    Chk_Ocarina_No =
			message->chk_ocarina_no =
			message->ocarina = message->info->status;
		    message->msg_mode = M_OCARINA2;
		    message->wct = OCARINA_WCT20;
		    if ( message->ocarina_no == Ocarina_Flog ) {
			if ( message->info->status <= NA_OCA_CHK_LIGHT || message->info->status == NA_OCA_CHK_RECMELODY2 ) {
			    /* 吹いてもダメな曲吹いた！！！ */
			    Na_StopOcarinaMode();
			    Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
			    message->msg_mode = M_OCARINA0;
			} else {
			    /* 正解模範演奏 */
			    PRINTF("Ocarina_Flog 正解模範演奏=%x\n",message->ocarina);
			    message_set2( game_play, 0x086F );
			    message->msg_mode = M_OCARINA6;
			    message->msg_disp_type0 = 0x3;
			    message->wct = OCARINA_WCT10;
			    Na_StartSystemSe( NA_SE_SY_TRE_BOX_APPEAR );
			    alpha_change( 1 );
			}
		    } else if ( message->ocarina_no == Ocarina_PC_Kakasi ) {
			if ( message->info->status <= NA_OCA_CHK_STORM ) {
			    /* 吹いてもダメな曲吹いた！！！ */
////????////			    PRINTF("status=%d\n",message->info->status);
			    Na_StopOcarinaMode();
			    Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
			    message->wct = 10;
			    message->msg_mode = M_OCARINA3;
			} else {
			    /* 正解模範演奏 */
			    PRINTF("Ocarina_Flog 正解模範演奏=%x\n",message->ocarina);
			    message_set2( game_play, 0x086F );
			    message->msg_mode = M_OCARINA6;
			    message->msg_disp_type0 = 0x3;
			    message->wct = OCARINA_WCT10;
			    Na_StartSystemSe( NA_SE_SY_TRE_BOX_APPEAR );
			    alpha_change( 1 );
			}
		    } else if ( message->ocarina_no == Ocarina_Free ) {
			/* 正解模範演奏 */
			PRINTF("Ocarina_Free 正解模範演奏=%x\n",message->ocarina);
			message_set2( game_play, 0x086F );
			message->msg_mode = M_OCARINA6;
			message->msg_disp_type0 = 0x3;
			message->wct = OCARINA_WCT10;
			Na_StartSystemSe( NA_SE_SY_TRE_BOX_APPEAR );
		    } else {
			Na_StartSystemSe( NA_SE_SY_TRE_BOX_APPEAR );
		    }
		    alpha_change( 1 );
		} else {
		    /* まだ,覚えていない曲吹いた！！！ */
		    Na_StopOcarinaMode();
		    Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		    message->msg_mode = M_OCARINA0;
		}
	    } else if ( message->info->status == NA_OCA_CHK_STOP ) {
		Na_StopOcarinaMode();
		Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		message->wct = 10;
		message->msg_mode = M_OCARINA3;
	    } else if ( Pad_on_trigger(B_BUTTON) ) {
# if 0
		if ( onpu_pt ) {
		    Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		    message->wct = 10;
		    message->msg_mode = M_OCARINA4;
		} else {
		    OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		    /* メッセージＣＬＯＳＥ */
		    message_close( game_play );
		}
# endif
		Na_StopOcarinaMode();

		OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		/* メッセージＣＬＯＳＥ */
		message_close( game_play );
	    }
	    if ( !(message->ocarina_no == Ocarina_Free ||  message->ocarina_no == Ocarina_Flog) ) {
		if ( !J_N && !staff_mode ) {
		    message_write( game_play, &gp );
		} else {
		    message_write_NES( game_play, &gp );
		}
	    }
	    break;

	case M_OCARINA2:
	case M_OCARINA21:
	case M_OCARINA53:
	    /* 正解 */
	    /* ＡボタンＰｒｉｍ/ＥｎｖＣＯＬＯＲ */
	    rc = (ABS(onpu_par - a_prim_color[mp][0] )) / mc;
	    gc = (ABS(onpu_pag - a_prim_color[mp][1] )) / mc;
	    bc = (ABS(onpu_pab - a_prim_color[mp][2] )) / mc;
	    if ( onpu_par >= a_prim_color[mp][0] ) onpu_par -= rc;
	    else			           onpu_par += rc;
	    if ( onpu_pag >= a_prim_color[mp][1] ) onpu_pag -= gc;
	    else			           onpu_pag += gc;
	    if ( onpu_pab >= a_prim_color[mp][2] ) onpu_pab -= bc;
	    else			           onpu_pab += bc;
	    rc = (ABS(onpu_ear - a_env_color[mp][0] )) / mc;
	    gc = (ABS(onpu_eag - a_env_color[mp][1] )) / mc;
	    bc = (ABS(onpu_eab - a_env_color[mp][2] )) / mc;
	    if ( onpu_ecr >= a_env_color[mp][0] ) onpu_ear -= rc;
	    else			          onpu_ear += rc;
	    if ( onpu_ecg >= a_env_color[mp][1] ) onpu_eag -= gc;
	    else			          onpu_eag += gc;
	    if ( onpu_ecb >= a_env_color[mp][2] ) onpu_eab -= bc;
	    else			          onpu_eab += bc;
	    /* ＣボタンＰｒｉｍ/ＥｎｖＣＯＬＯＲ */
	    rc = (ABS(onpu_pcr - c_prim_color[mp][0] )) / mc;
	    gc = (ABS(onpu_pcg - c_prim_color[mp][1] )) / mc;
	    bc = (ABS(onpu_pcb - c_prim_color[mp][2] )) / mc;
	    if ( onpu_pcr >= c_prim_color[mp][0] ) onpu_pcr -= rc;
	    else			           onpu_pcr += rc;
	    if ( onpu_pcg >= c_prim_color[mp][1] ) onpu_pcg -= gc;
	    else			           onpu_pcg += gc;
	    if ( onpu_pcb >= c_prim_color[mp][2] ) onpu_pcb -= bc;
	    else			           onpu_pcb += bc;
	    rc = (ABS(onpu_ecr - c_env_color[mp][0] )) / mc;
	    gc = (ABS(onpu_ecg - c_env_color[mp][1] )) / mc;
	    bc = (ABS(onpu_ecb - c_env_color[mp][2] )) / mc;
	    if ( onpu_ecr >= c_env_color[mp][0] ) onpu_ecr -= rc;
	    else			          onpu_ecr += rc;
	    if ( onpu_ecg >= c_env_color[mp][1] ) onpu_ecg -= gc;
	    else			          onpu_ecg += gc;
	    if ( onpu_ecb >= c_env_color[mp][2] ) onpu_ecb -= bc;
	    else			          onpu_ecb += bc;
	    if ( !(--mc) ) {
		/* 音符Ａカラー */
		onpu_par = a_prim_color[mp][0];
		onpu_pag = a_prim_color[mp][1];
		onpu_pab = a_prim_color[mp][2];
		onpu_ear = a_env_color[mp][0];
		onpu_eag = a_env_color[mp][1];
		onpu_eab = a_env_color[mp][2];
		/* 音符Ｃカラー */
		onpu_pcr = c_prim_color[mp][0];
		onpu_pcg = c_prim_color[mp][1];
		onpu_pcb = c_prim_color[mp][2];
		onpu_ecr = c_env_color[mp][0];
		onpu_ecg = c_env_color[mp][1];
		onpu_ecb = c_env_color[mp][2];
		mc = 3;
		mp ^=1;
	    }
	    if ( !(--message->wct) ) {
		Na_StopOcarinaMode();
		if ( message->msg_mode == M_OCARINA2 ) {
		    /* 正解模範演奏 */
		    PRINTF("正解模範演奏=%x\n",message->ocarina);
////////		    message_set2( game_play, 0x0893+message->ocarina );
		    message_set2( game_play, 0x086F );
		    message->msg_mode = M_OCARINA6;
		    message->msg_disp_type0 = 0x3;
		    message->wct = 1;
		} else if ( message->msg_mode == M_OCARINA21 ) {
		    if ( message->ocarina > NA_OCA_CHK_LIGHT ) {
			message_set2( game_play, 0x086F );
			message->msg_mode = M_OCARINA6;
			message->msg_disp_type0 = 0x3;
			message->wct = 1;
		    } else {
			message_close( game_play );
			OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		    }
		} else {
		    message_close( game_play );
		    OCARINA_MODE( game_play ) = Oca_Hit;
		}
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA3:
	case M_OCARINA22:
	    /* 不正解 */
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	case M_OCARINA4:
	    /* キャンセル */
	    if ( !(--message->wct) ) {
		VREG(51) = 1;
		if ( message->msg_mode == M_OCARINA22 ){
		    PRINTF("ここここここ\n");
		    message_set2( game_play, 0x088B );
		    message_read( game_play );
		    message->msg_mode = M_OCARINA23;
		} else {
		    message->msg_mode = M_OCARINA5;
		}
		PRINTF("キャンセル\n");
	    }
	    break;

	case M_OCARINA5:
	case M_OCARINA23:
	    /* 音符落下 */
	    for ( i = 0; i < 5; i++ ) {
		VREG(45+i) += VREG(51);
	    }
	    VREG(51) += VREG(51);
	    if ( VREG(51) >= 550 ) {
		onpu_buff[0] = 0xff;
		onpu_alpha[0] =
		    onpu_alpha[1] =
		    onpu_alpha[2] =
		    onpu_alpha[3] =
		    onpu_alpha[4] =
		    onpu_alpha[5] =
		    onpu_alpha[6] =
		    onpu_alpha[7] =
		    onpu_alpha[8] = 0;
		if ( message->msg_mode == M_OCARINA23 ){
		    message->msg_mode = M_OCARINA24;
		} else {
		    message->msg_mode = M_OCARINA0;
		}
	    }
	    break;

	case M_OCARINA6:
	    if ( !(--message->wct) ) {
		Na_StopOcarinaMode();
		COLOR_GREEN();
		PRINTF("Na_StopOcarinaMode();\n");
		PRINTF("Na_StopOcarinaMode();\n");
		PRINTF("Na_StopOcarinaMode();\n");
		COLOR_NORMAL();
		/* メッセージデータ読み込み */
		message_read( game_play );
		message->msg_mode = M_OCARINA7;
		message->info = Na_GetOcarinaInfoWork();
		message->info->locate = onpu_pt = 0;
		/* 音符バッファ初期化 */
		onpu_buff_reset();

		if ( message->ocarina >= NA_OCA_CHK_SPIRIT && message->ocarina <= NA_OCA_CHK_RECMELODY2 ) {
		    /* エフェクト発生 */
		    Actor_info_make_actor(&game_play->actor_info,
					  (Game *)game_play,
////////					  Magic_Fire,
					  profile_data[message->ocarina - NA_OCA_CHK_SPIRIT],
					  player->world.position.x,
					  player->world.position.y,
					  player->world.position.z,
					  0,
					  0,
					  0,
////////					  0);
					  arg_data_data[message->ocarina - NA_OCA_CHK_SPIRIT]);
		}
	    }
	    break;

	case M_OCARINA7:
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	    Na_StartOcarinaMode();
	    Na_StartOcarinaSeq( message->ocarina + NA_OCA_CHK_WIND, 1 );
	    if ( message->ocarina != NA_OCA_CHK_RECMELODY2 ) {
		Na_StartFanfare( ocarina_bgm[message->ocarina] );
		Na_SetOcarinaMute();
	    }
	    OCARINA_MODE( game_play ) = Oca_Play;
	    if ( message->ocarina_no == Ocarina_Free ) message->ocarina_no = Ocarina_FreeFree;
	    if ( message->ocarina_no == Ocarina_Flog ) message->ocarina_no = Ocarina_FrogFrog;
	    onpu_pt = 0;
	    message->msg_mode = M_OCARINA8;
	    break;

	case M_OCARINA10:
	    /* 模範演奏Ｗａｉｔ */
	    if ( !(--message->wct) ) {
		PRINTF("ocarina_no=%d  選曲=%d\n",message->ocarina_no, Ocarina_C_Epona);
		if ( message->ocarina_no <= Ocarina_Light ) Na_SetOcarinaInst( NA_OCA_INST_HARP );
		else if ( message->ocarina_no == Ocarina_Epona ) Na_SetOcarinaInst( NA_OCA_INST_MALON );
		else if ( message->ocarina_no == Ocarina_Zelda ) Na_SetOcarinaInst( NA_OCA_INST_IMPA );
		else if ( message->ocarina_no == Ocarina_Storm ) Na_SetOcarinaInst( NA_OCA_INST_WINDMILL );
		else Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
		PRINTF("模範演奏=%x\n",message->ocarina_no - Ocarina_Wind + NA_OCA_CHK_WIND);
		Na_StartOcarinaSeq( message->ocarina_no - Ocarina_Wind + NA_OCA_CHK_WIND, 2 );
		onpu_pt = 0;
		message->msg_mode = M_OCARINA11;
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;
	    
	case M_OCARINA9:
	    message_set2( game_play, 0x0893+message->ocarina );
	    message_read( game_play );
	    message->msg_mode = M_OCARINAA;
	    message->wct = OCARINA_WCT20;
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;
	    
	case M_OCARINAA:
	    if ( !(--message->wct) ) {
		message->msg_mode = M_OCARINAB;
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;
	    
	case M_OCARINAB:
	    /* 音符バッファ初期化 */
	    Na_StopOcarinaMode();
	    onpu_buff_reset();
	    message->msg_mode = M_OCARINAC;
	    message->wct = 2;
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINAC:
	    if ( !(--message->wct) ) {
		if ( message->ocarina <= NA_OCA_CHK_LIGHT && !(message->ocarina_no >= Ocarina_C_Wind && message->ocarina_no <= Ocarina_C_Light) ) {
		    if ( message->warp_flg || parameter->c_warp == 3 ) {
			message_set( game_play, 0x88c, 0 );
			OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		    } else {
			if (  InRaceSeq != SCENE_2 ) {
			    message_set( game_play, 0x88d+message->ocarina, 0 );
			    OCARINA_MODE( game_play ) = Oca_Play;
			} else {
			    message_close( game_play );
			}
		    }
		} else {
		    message_close( game_play );
		    if ( message->ocarina == NA_OCA_CHK_EPONA ) DREG(53) = 1;
/*		    if ( GetCollect_MELODY( H_melody_10 ) ) {*/
/*		    if ( SunMoon_Ocarina ) {
			if ( message->ocarina == NA_OCA_CHK_SUNMOON ) {
			    game_play->actor_stop_flag = 1;
			}
		    }*/
		    COLOR_YELLOW();
		    PRINTF( "☆☆☆ocarina=%d   message->ocarina_no=%d  ",message->ocarina, message->ocarina_no );
////////		    if ( message->ocarina_no == Ocarina_FreeFree ) OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		    if ( message->ocarina_no == Ocarina_FreeFree ) {
			OCARINA_MODE( game_play ) = Oca_Play;	/* フリー演奏 */
			if ( message->ocarina == NA_OCA_CHK_RECMELODY2 )
			    OCARINA_MODE( game_play ) = Oca_Kakasi;
		    } else {
			if ( message->ocarina_no >= Ocarina_PC_Wind ) {
			    /* オカリナ・タグ */
			    COLOR_YELLOW();
			    PRINTF( "Ocarina_PC_Wind=%d(%d) ☆☆☆   ",Ocarina_PC_Wind,(message->ocarina_no-Ocarina_PC_Wind) );
			    if ( message->ocarina == (message->ocarina_no-Ocarina_PC_Wind) )
				OCARINA_MODE( game_play ) = Oca_Hit;
			    else
				OCARINA_MODE( game_play ) = ((message->ocarina - 6) + Oca_Salia);
			} else {
			    /* 魔方陣 */
			    COLOR_GREEN();
			    PRINTF( "Ocarina_C_Wind=%d(%d) ☆☆☆   ",Ocarina_C_Wind,(message->ocarina_no-Ocarina_C_Wind) );
			    if ( message->ocarina == (message->ocarina_no-Ocarina_C_Wind) )
				OCARINA_MODE( game_play ) = Oca_Hit;
			    else 
////////				OCARINA_MODE( game_play ) = ((message->ocarina - 6) + Oca_Salia);
				OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
			}
		    }
		    COLOR_NORMAL();
		    PRINTF("→  OCARINA_MODE=%d\n",OCARINA_MODE( game_play ));
		}
	    }
	    break;
	    
	case M_OCARINA8:
	case M_OCARINA11:
	    /* 模範演奏 */
	    message->info = Na_GetOcarinaSeqInfoWork();
	    if ( message->info->status == NA_OCA_SEQ_STOP ) {
		if ( message->msg_mode == M_OCARINA8 ) message->msg_mode = M_OCARINA9;
		else                                   message->msg_mode = M_OCARINA12;
		PRINTF("onpu_buff[%d]=%x\n",message->info->locate, onpu_buff[message->info->locate] );
	    } else {
		if ( onpu_pt && message->info->locate == 1 ) onpu_pt = 0;
		if ( message->info->locate ) {
		    if ( onpu_pt == message->info->locate-1 ) {
			message->frame_cfg = 
			    onpu_buff[message->info->locate-1] = message->info->button;
			onpu_buff[message->info->locate] = 0xff;
			onpu_pt++;
		    }
		}
	    }
	case M_OCARINA12:
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;
	    
	case M_OCARINA20:
	    /* 入力 */
	    message->info = Na_GetOcarinaInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    onpu_buff[message->info->locate-1] = message->info->button;
		    onpu_buff[message->info->locate] = 0xff;
		    onpu_pt++;
		}
	    }
//	    PRINTF("status=%x\n",message->info->status);
//	    PRINTF("ocarina_no=%x    status=%x\n",message->ocarina_no-Ocarina_C_Wind, message->info->status );
	    if ( message->info->status <= NA_OCA_CHK_RECMELODY2 ) {
		PRINTF("M_OCARINA20 : ocarina_no=%x    status=%x\n",message->ocarina_no, message->info->status );
////////		if ( Collect_Register(C_SEAL+message->info->status) ) {
		message->ocarina = message->info->status;
		message->msg_mode = M_OCARINA21;
/*		    item_get_setting( game_play, message->info->status + H_melody_1 );*/
		item_get_setting( game_play, ocarina_number[message->info->status] + H_melody_1 );
		COLOR_YELLOW();
		PRINTF("z_message.c 取得メロディ＝%d\n",message->info->status + H_melody_1);
		COLOR_NORMAL();
		message->wct = OCARINA_WCT20;
////////		}
		Na_StartSystemSe( NA_SE_SY_TRE_BOX_APPEAR );
	    } else if ( message->info->status == NA_OCA_CHK_STOP ) {
/*		Na_StopOcarinaMode();*/
		Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		message->wct = 10;
		message->msg_mode = M_OCARINA22;
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA24:
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    if( pad_on_check(game_play) ) {
		ocarina_set( game_play, message->ocarina_no );
	    }
	    break;

	    /*
	     * 案山子録音
	     */
	case M_OCARINA40:
	    PRINTF("案山子録音 初期化\n");
	    /* 初期化 */
	    Na_StartOcarinaRecMode();
	    Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	    message->info = Na_GetOcarinaRecInfoWork();
	    message->info->locate = onpu_pt = 0;
	    onpu_ct = 0;
	    /* 音符バッファ初期化 */
	    onpu_buff_reset();
	    message->msg_mode = M_OCARINA41;
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA41:
	    /* 入力 */
	    message->info = Na_GetOcarinaRecInfoWork();
	    PRINTF("\nonpu_pt=%d, locate=%d",onpu_pt,message->info->locate);
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    if ( onpu_ct >= 8 ) {
			for ( i = 0, j = (onpu_ct-8); i < 8; i++,j++ ) {
			    onpu_buff[j] = onpu_buff[j+1];
			}
			onpu_ct--;
		    }
		    PRINTF("    入力ボタン【%d】=%d",onpu_ct,message->info->button);
		    message->frame_cfg = 
			onpu_buff[onpu_ct] = message->info->button;
		    onpu_ct++;
		    onpu_buff[onpu_ct] = 0xff;
		    onpu_pt++;
		    if ( message->info->locate == 8 ) {
			onpu_pt = 0;
		    }
		}
	    }
	    if ( message->info->status == NA_OCA_REC_STOP || Pad_on_trigger(B_BUTTON) ) {
		if ( onpu_ct ) {
		    PRINTF("録音終了！！！！！！！！！  message->info->status=%d \n",message->info->status);
		    OCA_REC_FLAG = 1;		/* 録音フラグＯＮ */
		}
		Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		PRINTF("aaaaaaaaaaaaaa\n");
		Na_StopOcarinaRecMode();
		message->wct = 10;
		OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		/* メッセージＣＬＯＳＥ */
		message_close( game_play );
		PRINTF("録音終了！！！！！！！！！録音終了\n");
		/* 録音フラグＯＮ */
		COLOR_YELLOW();
		PRINTF("\n====================================================================\n");
		/* 録音フラグＯＮ */
		Memcpy( &S_Information.oca_rec_buff, na_oca_rec_buf_ptr, NA_OCA_REC_MEMORY_SIZE );
		for ( i = 0; i < NA_OCA_REC_MEMORY_SIZE; i++ ) {
		    PRINTF("%d, ",S_Information.oca_rec_buff[i]);
		}
		COLOR_NORMAL();
		PRINTF("\n====================================================================\n");
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA42:
	case M_OCARINA54:
	    message->info = Na_GetOcarinaSeqInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    if ( onpu_ct >= 8 ) {
			for ( i = 0, j = (onpu_ct-8); i < 8; i++,j++ ) {
			    onpu_buff[j] = onpu_buff[j+1];
			}
			onpu_ct--;
		    }
		    onpu_buff[onpu_ct] = message->info->button;
		    onpu_ct++;
		    onpu_buff[onpu_ct] = 0xff;
		    onpu_pt++;
		    if ( message->info->locate == 8 ) {
			onpu_ct = 
			    onpu_pt = 0;
		    }
		}
	    }
	    PRINTF("status=%d (%d)\n",message->info->status,NA_OCA_SEQ_STOP);
	    if ( !message->wct ) {
		if ( message->info->status == NA_OCA_SEQ_STOP ) {
		    PRINTF("bbbbbbbbbbb\n");
		    Na_StopOcarinaMode();
		    OCARINA_MODE( game_play ) = Oca_PlayE;
		    message_close( game_play );
		}
	    } else message->wct--;
	    break;

	    /*
	     * 案山子８音録音
	     */
	case M_OCARINA50:
	    /* 初期化 */
	    Na_StartOcarinaRecEightMode();
	    Na_SetOcarinaInst( NA_OCA_INST_OCARINA );
	    message->msg_mode = M_OCARINA51;
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA51:
	    /* 入力 */
	    message->info = Na_GetOcarinaRecInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    message->frame_cfg = 
			onpu_buff[onpu_pt] = message->info->button;
		    onpu_pt++;
		    onpu_buff[onpu_pt] = 0xff;
		}
	    }
	    if ( message->info->status == NA_OCA_REC_STOP ) {
		PRINTF("８音録音ＯＫ！\n");
		message->wct = OCARINA_WCT20;
		OCA_REC_FLAG8 = 1;		/* ８音録音フラグＯＮ */
		message->msg_mode = M_OCARINA53;
		Na_StartSystemSe( NA_SE_SY_TRE_BOX_APPEAR );
		/* 録音フラグＯＮ */
		COLOR_YELLOW();
		PRINTF("\n====================================================================\n");
		/* 録音フラグＯＮ */
		Memcpy( &S_Information.oca_rec_buff8, na_oca_rec_buf2_ptr, NA_OCA_REC_MEMORY_SIZE2 );
		for ( i = 0; i < NA_OCA_REC_MEMORY_SIZE2; i++ ) {
		    PRINTF("%d, ",S_Information.oca_rec_buff8[i]);
		}
		COLOR_NORMAL();
		PRINTF("\n====================================================================\n");
	    } else if ( message->info->status == NA_OCA_REC_BAD || Pad_on_trigger(B_BUTTON) ) {
		PRINTF("すでに存在する曲吹いた！！！ \n");
		Na_StopOcarinaRecMode();
		Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		message_close( game_play );
		message->msg_mode = M_OCARINA52;
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA52:
	    PRINTF("cccccccccccc\n");
	    Na_StopOcarinaMode();
	    message_set( game_play, 0x40AD, 0 );
	    OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
	    break;
	    
	case M_OCARINA60:
	    /* 初期化 */
	    Na_StartOcarinaMode();
	    Na_SetOcarinaInst( NA_OCA_INST_PICCOLO );
	    Na_InitOcarinaGameWork( OCARINA_ROUND );
	    message->info = Na_GetOcarinaSeqInfoWork();
	    message->info->locate = onpu_pt = 0;
	    /* 音符バッファ初期化 */
	    onpu_buff_reset();
	    Na_StartOcarinaSeq( NA_OCA_CHK_GAME, 1 );
	    message->msg_mode = M_OCARINA61;
	    message->wct = 2;
	    break;

	case M_OCARINA61:
	case M_OCARINA63:
	    Na_StartSystemSe(NA_SE_SY_METRONOME_LV);
	    message->info = Na_GetOcarinaSeqInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    onpu_buff[message->info->locate-1] = message->info->button;
		    onpu_buff[message->info->locate] = 0xff;
		    onpu_pt++;
		}
	    }
	    if ( !message->wct ) {
		if ( message->info->status == NA_OCA_SEQ_STOP ) {
		    if ( message->msg_mode == M_OCARINA61 ) {
			Na_StartSystemSe(NA_SE_SY_METRONOME);
		    } else {
			Na_StartSystemSe(NA_SE_SY_METRONOME_2);
		    }
		    message->msg_mode++;
		}
	    } else message->wct--;
	    break;

	case M_OCARINA62:
	case M_OCARINA64:
	    message->info = Na_GetOcarinaSeqInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    onpu_buff[message->info->locate-1] = message->info->button;
		    onpu_buff[message->info->locate] = 0xff;
		    onpu_pt++;
		}
	    }
	    break;

	case M_OCARINA65:
	    /* 入力 */
	    Na_StartSystemSe(NA_SE_SY_METRONOME_LV);
	    message->info = Na_GetOcarinaInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    onpu_buff[message->info->locate-1] = message->info->button;
		    onpu_buff[message->info->locate] = 0xff;
		    onpu_pt++;
		}
	    }
	    if ( message->info->status == NA_OCA_CHK_STOP ) {
		PRINTF("輪唱失敗！！！！！！！！！\n");
		Na_StopOcarinaMode();
		Na_StartSystemSe( NA_SE_SY_OCARINA_ERROR );
		message->wct = 10;
		OCARINA_MODE( game_play ) = Oca_Hit;
	    } else if ( message->info->status == NA_OCA_CHK_GAME ){
		PRINTF("輪唱成功！！！！！！！！！\n");
		Na_StartSystemSe( NA_SE_SY_GET_ITEM );
		message->msg_mode = M_OCARINA66;
		message->wct = 30;
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA66:
	    message->info = Na_GetOcarinaInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    onpu_buff[message->info->locate-1] = message->info->button;
		    onpu_buff[message->info->locate] = 0xff;
		    onpu_pt++;
		}
	    }
	    if ( !(--message->wct) ) {
		if ( Na_MakeOcarinaGameData() != NA_OCA_GAME_MAX ) {
		    Na_StartSystemSe(NA_SE_SY_METRONOME);
		    message->info = Na_GetOcarinaInfoWork();
		    message->info->locate = onpu_pt = 0;
		    onpu_buff_reset();
		    message->msg_mode = M_OCARINA67;
/////////		    message->wct = 2;
		} else {
		    OCARINA_MODE( game_play ) = Oca_PlayE;	/* フリー演奏 */
		}
	    }
	    if ( !J_N ) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }
	    break;

	case M_OCARINA67:
	    if ( Na_CheckPlayingSeFlag(NA_SE_SY_METRONOME) == NA_FLAG_NO_ENTRY ) {
		message->info = Na_GetOcarinaSeqInfoWork();
		message->info->locate = onpu_pt = 0;
		/* 音符バッファ初期化 */
		onpu_buff_reset();
		Na_StartOcarinaSeq( NA_OCA_CHK_GAME, 1 );
	    }
	    break;
	    
	case M_OCARINA80:
	    /* 初期化 */
	    Na_StartOcarinaMode();
	    message->info = Na_GetOcarinaInfoWork();
	    message->info->locate = onpu_pt = 0;
	    OCARINA_MODE( game_play ) = Oca_Play;
	    /* 音符バッファ初期化 */
	    onpu_buff_reset();
	    /* フリー演奏 */
/*???????	    Na_StartOcarinaFreePlayCheck( NA_OCA_CHK_GRP_ALL );*/
	    Na_StartOcarinaFreePlayCheck( ocarina_bit );
	    message->msg_mode = M_OCARINA81;
	    break;
	    
	case M_OCARINA81:
	    /* 入力 */
	    message->info = Na_GetOcarinaInfoWork();
	    if ( message->info->locate ) {
		if ( onpu_pt == message->info->locate-1 ) {
		    message->frame_cfg = message->info->button;
		    message->info->locate = onpu_pt = 0;
		    onpu_buff_reset();
		    message->msg_mode = M_OCARINA82;
		}
	    }
	case M_OCARINA82:
	    break;

	    
	case M_END:
	    /* メッセージ終了 */
	    if ( !J_N && !staff_mode) {
		message_write( game_play, &gp );
	    } else {
		message_write_NES( game_play, &gp );
	    }

	    switch ( message->select ) {
	    case __2_SELECT:
		/* ２択 */
		arrow_select( game_play, 1 );
/*		message_moji_display( game_play, &kanfont->kbuffer2[0], &gp ); */
		last_mark_display( game_play, &gp, message->mxp, message->myp );
		break;

	    case __3_SELECT:
		/* ３択 */
		arrow_select( game_play, 2 );
/*		message_moji_display( game_play, &kanfont->kbuffer2[0], &gp ); */
		last_mark_display( game_play, &gp, message->mxp, message->myp );
		break;

	    case __DISPSTOP:
		if ( message->msgno >= 0x006D && message->msgno <= 0x0072 ) {
		    /* ワープ行き先表示メッセージ */
		    if ( (++message->wct) > 30 ) {
			message->wct = 2;
			message->msg_mode = M_CLOSE;
		    }
		}
		break;

	    case __ENEMY:
		/* 敵側制御コード */
	    default:
		/* 終了 */
		last_mark_display( game_play, &gp, XREG(64), XREG(65) );
	    case __TIMER:
		/* タイマー終了 */
		break;
	    }
	    break;
	    
	case M_CLOSE:
	case M_KOMATSU:
	    break;

	default:
	    message->msg_mode = M_DISPLAY;
	    break;
	}


	if ( (message->msg_mode >= M_OCARINA1 && message->msg_mode < M_NEXT) && !(message->ocarina_no == Ocarina_Free || message->ocarina_no == Ocarina_Flog) ) {
	    gp_overlay_rectangle_a_prim( &gp );
	    gDPSetCombineMode( gp++, G_CC_INT9, G_CC_INT9 );
	    if ( message->msg_mode == M_OCARINA20 ) {
		gc = message->ocarina_no - Ocarina_C_Wind + NA_OCA_CHK_WIND;
		rc = na_oca_note[gc].max;
		xp = VREG(28);
		for ( i = 0; i < rc; i++ ) {
		    gDPPipeSync( gp++ );
		    gDPSetPrimColor( gp++, 0, 0, 150, 150, 150, 150 );
		    gDPSetEnvColor( gp++, 10, 10, 10, 0 );
		    gDPLoadTextureBlock( gp++,
					 onpu[na_oca_note[gc].key[i]], G_IM_FMT_IA, G_IM_SIZ_8b,
					 16, 16, 0,
					 G_TX_WRAP | G_TX_NOMIRROR,
					 G_TX_WRAP | G_TX_NOMIRROR,
					 G_TX_NOMASK,   G_TX_NOMASK,
					 G_TX_NOLOD,    G_TX_NOLOD );
		    gSPTextureRectangle( gp++,
					 xp << 2, VREG(45+na_oca_note[gc].key[i]) << 2,
					 xp+16 << 2, VREG(45+na_oca_note[gc].key[i])+16 << 2,
					 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
		    xp += VREG(29);
		}
	    }
	    if ( !(message->msg_mode == M_OCARINA40 || message->msg_mode == M_OCARINA60 /*|| message->msg_mode == M_OCARINA63 || message->msg_mode == M_OCARINA64*/) ) {
		xp = VREG(28);
		for ( i = 0; i < 8; i++ ) {
		    if ( onpu_buff[i] != 0xff ) {
			if ( onpu_alpha[i] != 255 ) {
			    if ( (onpu_alpha[i] += VREG(50)) >= 255 ) onpu_alpha[i] = 255;
			}
			gDPPipeSync( gp++ );
			if ( !onpu_buff[i] ) {
			    gDPSetPrimColor( gp++, 0, 0, onpu_par, onpu_pag, onpu_pab, onpu_alpha[i] );
			    gDPSetEnvColor( gp++, onpu_ear, onpu_eag, onpu_eab, 0 );
			} else {
			    gDPSetPrimColor( gp++, 0, 0, onpu_pcr, onpu_pcg, onpu_pcb, onpu_alpha[i] );
			    gDPSetEnvColor( gp++, onpu_ecr, onpu_ecg, onpu_ecb, 0 );
			}
			gDPLoadTextureBlock( gp++,
					     onpu[onpu_buff[i]], G_IM_FMT_IA, G_IM_SIZ_8b,
					     16, 16, 0,
					     G_TX_WRAP | G_TX_NOMIRROR,
					     G_TX_WRAP | G_TX_NOMIRROR,
					     G_TX_NOMASK,   G_TX_NOMASK,
					     G_TX_NOLOD,    G_TX_NOLOD );
			gSPTextureRectangle( gp++,
					     xp << 2, VREG(45+onpu_buff[i]) << 2,
					     xp+16 << 2, VREG(45+onpu_buff[i])+16 << 2,
					     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
			xp += VREG(29);
		    } else break;
		}
	    }
	}
    }

#if 0
    if ( message->frame_disp ) {
	/* 安全フレーム表示 */
	gDPPipeSync(gp++);
	/* レンダリング・モードの設定 */
	gDPSetRenderMode(gp++, G_RM_XLU_SURF, G_RM_XLU_SURF);
	gDPSetCombineMode(gp++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
	gDPSetPrimColor( gp++, 0, 0, 255, 255, 0, 150 );
	/*                             左Ｘ,         上Ｙ,         右Ｘ,         下Ｙ */
	gDPFillRectangle(gp++,            0,            0,  SCREEN_WD-1,           16);
	gDPFillRectangle(gp++,            0, SCREEN_HT-16,  SCREEN_WD-1,  SCREEN_HT-1);
	gDPFillRectangle(gp++,            0,            0,           22,  SCREEN_HT-1);
	gDPFillRectangle(gp++, SCREEN_WD-22,            0,  SCREEN_WD-1,  SCREEN_HT-1);
	gDPPipeSync(gp++);
    };
# endif
    
    *glistp = gp;
}




#if !defined(ROM_F)
void box_chk(
    short	*cnt,
    Graph *graph
    )
{
    static short flag = 0;
    static short ocnt = 0;
    short	x, y;

    OPEN_DISP(graph);

    if ( flag != *cnt ) {
	flag = *cnt;
	ocnt = 30;
    }
    if ( ocnt ) {
	ocnt--;
	gDPPipeSync(NEXT_DISP);
	gDPSetCycleType(NEXT_DISP, G_CYC_FILL);
	gDPSetRenderMode(NEXT_DISP, G_RM_NOOP, G_RM_NOOP2);
	gDPSetFillColor(NEXT_DISP, GPACK_RGBA5551(0, 0, 0, 1) << 16 | 
			GPACK_RGBA5551(0, 0, 0, 1));
	gDPFillRectangle(NEXT_DISP, 0, 110, 319, 150);
	gDPPipeSync(NEXT_DISP);
	
	y = ((1) / 25) * 10 + 120;
	x = ((1) % 25) * 10 + 30;
	
	gDPPipeSync(NEXT_DISP);
	gDPSetCycleType(NEXT_DISP, G_CYC_FILL);
	gDPSetRenderMode(NEXT_DISP, G_RM_NOOP, G_RM_NOOP2);
	gDPSetFillColor(NEXT_DISP, GPACK_RGBA5551(255, 255, 255, 1) << 16 | 
			GPACK_RGBA5551(255, 255, 255, 1));
	gDPFillRectangle(NEXT_DISP, x, y, x + 20, y + 20);
	gDPPipeSync(NEXT_DISP);
    }

    CLOSE_DISP(graph);
}
/*===============================================================
  =								=
  ===============================================================*/
static void
message_no_draw( Game_play *game_play, Gfx **glistpp )
{
    Message		*message = (Message *)&game_play->message;

    gfxprint_t gfxprintx, *gfxprint = &gfxprintx;


    Gfxprint_init();
    Gfxprint_open(*glistpp);

    Gfxprint_locate8x8( 6, 26 );
    Gfxprint_color(255,60,0,255);
    Gfxprint_printf1("%s","MESSAGE");
    Gfxprint_locate8x8( 14, 26 );
    Gfxprint_printf1("%s","=");
    Gfxprint_locate8x8( 16, 26 );
    Gfxprint_printf1("%x",message->msgno);

    *glistpp = Gfxprint_close();
    Gfxprint_cleanup();
}
# endif
/************************************************************************
 *									*
 *	メッセージＤＲＡＷ						*
 *									*
 ************************************************************************/
extern void
message_draw( Game_play *game_play )
{
    Gfx *glistp, *glistp_save;
    short	kkk;

    OPEN_DISP( game_play->g.graph );

#if !defined(ROM_F)
    kkk = (short)OCA_REC_FLAG;
    box_chk( &kkk, game_play->g.graph );
    
    if ( BREG(0) ) {
	/* テスト用 メッセージＮＯ．表示 */
	if ( game_play->message.msgno ) {
	    glistp = gfxopen( glistp_save = NOW_DISP );
	    gSPDisplayList( NEXT_OVERLAY_DISP, glistp );
	    message_no_draw( game_play, &glistp );
	    gSPEndDisplayList( glistp++ );
	    gfxclose( glistp_save, glistp );
	    SET_NOW_DISP( glistp );
	}
    }
# endif

    glistp = gfxopen( glistp_save = NOW_DISP );
    gSPDisplayList( NEXT_OVERLAY_DISP, glistp );

    message_draw_sub( game_play, &glistp );
    gSPEndDisplayList( glistp++ );

    gfxclose( glistp_save, glistp );
    SET_NOW_DISP( glistp );

    CLOSE_DISP( game_play->g.graph );
}
    
    
    
    
/************************************************************************
 *									*
 *	メッセージＭＯＶＥ						*
 *									*
 ************************************************************************/
extern void
message_move( Game_play *game_play )
{
    Message		*message = (Message *)&game_play->message;

    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Player_actor 	*p_player = (Player_actor *)get_player_actor(game_play);

    pad_t		*pad = &game_play->g.pads[0];

    static short	start_xposd[] = {
	 34,  34,  34,  34,  34,  34,
    };
    static short	start_yposd0[] = {	/* 下表示 */
/*        0    1    2    3    4    5 */
	142, 142, 142, 142, 174, 142,
    };
    static short	start_yposd1[] = {	/* 上表示 */
/*        0    1    2    3    4    5 */
	 38,  38,  38,  38, 174,  38,
    };
    static short	start_yposd2[] = {	/* 中表示 */
/*        0    1    2    3    4    5 */
	 90,  90,  90,  90, 174,  90,
    };
    static short	last_mark_yposd[] = {
/*        0    1    2    3    4    5 */
	 59,  59,  59,  59,  34,  59,
    };
	
    static unshort	key_data[] = {
	D_JPAD, D_JPAD, L_JPAD,
    };
    static unshort msg_number[] = {
	0x1038, 8, 0x200A, 0x88B, 7, 9, 10, 0x107E, 0x2008, 0x2007, 0x0015, 0x0016, 0x0017, 0x0003, 0x0000, 
	9995, 200, 300, 301, 0xffda,
	20, 22, 20, 22,
    };

    short		i, dxpos, dypos, dypos1, dypos2; ////////, kkk;
/*    unshort		rd_dt;*/
    /* デバック用メッセージＮｏ．*/
    static unshort	msgno = 0;
    /* メッセージ早送りフラグ */
    static char		speed_fg = 0;

    MSG_T *pnt;
    MSG_NT *pnt_n;
    

#if !defined(ROM_F)
    if ( BREG(0) ) {
	if ( Pad_on_trigger( D_JPAD ) && Pad_push_also( L_TRIG ) ) {
	    PRINTF("msgno=%d\n",msgno);
////////	message_set( game_play, msg_number[msgno], 0 );
	    message_set( game_play, YREG(79), 0 );
	    msgno = (unshort)( ( msgno + 1 ) % 10 );
	}
	if ( YREG(78) ) {
	    while( YREG(79) != 0x8000 ) {
		if ( !J_N && !staff_mode ) {
		    pnt = message_tbl_p;
		    while( pnt->msg_num != 0xFFFD ) {
			if( pnt->msg_num == YREG(79) ) {
			    /* メッセージが,見つかった！！！ */
			    PRINTF(" メッセージが,見つかった！！！ = %x\n",YREG(79));
			    message_set( game_play, YREG(79), 0 );
			    YREG(79)++;
			    YREG(78) = 0;
			    return;
			}
			pnt++;
		    } 
		    YREG(79)++;
		} else {
		    pnt_n = message_tbl_nes_p;
		    while( pnt_n->msg_num != 0xFFFD ) {
			if( pnt_n->msg_num == YREG(79) ) {
			    /* メッセージが,見つかった！！！ */
			    PRINTF(" メッセージが,見つかった！！！ = %x\n",YREG(79));
			    message_set( game_play, YREG(79), 0 );
			    YREG(79)++;
			    YREG(78) = 0;
			    return;
			}
			pnt_n++;
		    } 
		    YREG(79)++;
		}
	    }
	}
    }
#endif

    if ( message->msg_data != NULL ) {
	switch ( message->msg_mode ) {
	case M_MOVE:
	    start_flag++;
	    i = 0;
	    if ( YREG(15) == 0x40 ) {	/* ＶＲーＢＯＸ */
		/* ＶＲーＢＯＸズーム */
////////		if ( isCameraStoped(game_play->cameras[game_play->active_camera]) ) i++;
		if ( start_flag >= 4 ) i++;
	    } else if ( YREG(15) || SceneID(HAIRARUNIWA) ) {
# if CAMERA_FG
		YREG(32) = player->world.position.x;
		YREG(33) = player->world.position.z;
# endif
# if 0
		/* 各家の中 */
		if ( YREG(15) == 0x10 ) {	/* お店 */
		    if ( SceneID(SHIELD_SHOP) ) {
			player->world.position.x = -30;
			player->world.position.z = 70;
		    } else if ( SceneID(KOKIRI_SHOP) || SceneID(KAKARIKO_SHOP) || SceneID(TARON_SHOP) || SceneID(NIGHT_SHOP) ) {
			player->world.position.x = 0;
			player->world.position.z = 60;
		    } else if ( SceneID(GORON_SHOP_N) || SceneID(ZOORA_SHOP) ) {
			player->world.position.x = 0;
			player->world.position.z = -70;
		    } else if ( SceneID(DRAG_SHOP) ) {
			player->world.position.x = 30;
			player->world.position.z = 70;
		    } else if ( SceneID(ALLEY_SHOP) ) {
			player->world.position.x = 40;
			player->world.position.z = 30;
		    }
# if 0
		    player->world.position.x = -30;
		    player->world.position.z = 36;
		    if ( SceneID(TARON_SHOP) || SceneID(KAKARIKO_SHOP) ) {
			player->world.position.x = 0;
			player->world.position.z = 16;
		    } else if ( SceneID(ZOORA_SHOP) || SceneID(GORON_SHOP_N) ) {
			player->world.position.x = 0;
			player->world.position.z = -104;
		    } 
# endif
		}
# endif
		i++;
/*	    } else if ( isCameraStoped(game_play->cameras[game_play->active_camera]) ) {
		i++;
	    } else if ( message->talk_actor == NULL ) {
		i++;
	    }*/
	    } else if ( start_flag >= 4 || message->talk_actor == NULL ) i++;
	    if ( i ) {
		/* カメラ移動終了 */
		if ( message->talk_actor != NULL ) {
		    /* プレイヤー位置ＧＥＴ */
		    Actor_display_position_set( game_play, get_player_actor(game_play), &dxpos, &dypos1 );
		    /* 話し相手位置ＧＥＴ */
		    Actor_display_position_set( game_play, message->talk_actor, &dxpos, &dypos2 );
		    if ( dypos1 >= dypos2 ) dypos = (dypos1 - dypos2)/2 + dypos2;
		    else                    dypos = (dypos2 - dypos1)/2 + dypos1;
		    PRINTF("dxpos=%d   dypos=%d  dypos1  dypos2=%d\n",dxpos, dypos, dypos1, dypos2);
		} else {
		    VREG(0) = XREG(72);
		    VREG(1) = XREG(73);
		}
		/* メッセージＴＹＰＥチェック */
		i = message->msg_disp_type0;
		if ( !message->msg_disp_type1 ) {
		    /* メッセージ表示ＡＵＴＯ */
		    if ( YREG(15) || SceneID(HAIRARUNIWA) ) {
			if ( dypos < XREG(92) ) XREG(73) = start_yposd0[i];
			else                    XREG(73) = start_yposd1[i];
		    } else if ( SceneID(MARKET_DAY) || SceneID(MARKET_NIGHT) || SceneID(MARKET_RUINS) ) {
			if ( dypos < XREG(93) ) XREG(73) = start_yposd0[i];
			else                    XREG(73) = start_yposd1[i];
		    } else {
			if ( dypos < XREG(94) ) XREG(73) = start_yposd0[i];
			else                    XREG(73) = start_yposd1[i];
		    }
		} else {
		    /* メッセージ表示固定 */
		    if ( message->msg_disp_type1 == 1 )		XREG(73) = start_yposd1[i];
		    else if ( message->msg_disp_type1 == 2 )    XREG(73) = start_yposd2[i];
		    else					XREG(73) = start_yposd0[i];
		}
		XREG(72) = start_xposd[i];
		XREG(65) = last_mark_yposd[i] + XREG(73);
		if ( !J_N && !staff_mode ) {
		    XREG(67) = XREG(73) + 7;
		    XREG(68) = XREG(73) + 7 + 18;
		    XREG(69) = XREG(73) + 7 + 18 + 18;
		} else {
		    XREG(67) = XREG(73) + 20;
		    XREG(68) = XREG(73) + 20 + 12;
		    XREG(69) = XREG(73) + 20 + 12 + 12;
		}
		PRINTF("message->msg_disp_type=%x\n",message->msg_disp_type & 0xf0);
/*		if ( message->msg_disp_type0 == 0x2 || message->msg_disp_type0 == 0x4 || message->msg_disp_type0 == 0x5 ) {*/
		if ( message->msg_disp_type0 == 0x4 || message->msg_disp_type0 == 0x5 ) {
		    /* 吹き出し無し */
		    message->msg_mode = M_WAIT;
		    VREG(0) = XREG(72);
		    VREG(1) = XREG(73);
		    YREG(22) = 256;
		    YREG(23) = 64;
		    YREG(16) = 512;
		    YREG(17) = 512;
		} else {
		    window_open( message );
////////		    Na_StartSystemSe( NA_SE_SY_MESSAGE_WIN_OPEN );
		    Na_StartMessageWindowSe();
		    message->wct = 0;
		    message->msg_mode = M_OPEN;
		}
	    }
	    break;

	case M_OPEN:
	    /* メッセージ ウィンドウ ＯＰＥＮ */
	    window_open( message );
	    break;

	case M_WAIT:
	    /* Ｗａｉｔ */
	    message->msg_mode = M_READ;
////////		if ( YREG(15) != 0x10 ) {
	    if ( !YREG(31) ) {
		DO_ACTION_POINT_SET( game_play, DO_Tsugihe );
	    }
	    break;

	case M_READ:
	    /* メッセージデータ読み込み */
	    message_read( game_play );

	    if ( key_off_flag ) {
////////		kkk = LAST_TIME_TYPE;
		alpha_change( 1 );
////////		LAST_TIME_TYPE = kkk;
////////		PRINTF("kkk=%d  LAST_TIME_TYPE=%d\n",kkk,LAST_TIME_TYPE);
/*	    } else {
		if ( YREG(15) == 0x10 ) {
		    alpha_change( 5 );
		} else {
		    alpha_change( 4 );
		}*/
	    }

	    if ( speed_fg ) {
		message->end = message->rd_end;
		speed_fg = 0;
	    }
	    break;

	case M_REST:
	    /* 一時停止 */
	    if ( !(--message->wct) ) {
		/* メッセージデータ読み込み */
		message_read( game_play );
	    }
	    break;

	case M_DISPLAY:
	    /* 文字読み込み */
	    if ( message->msg_disp_type0 != 0x4 ) {
		if ( !YREG(31) ) {
/*		    if ( Pad_on_trigger(START_BUTTON) ) {
			message_close( game_play );
		    } else if ( pad_on_check( game_play )  ) {
			message->end = message->rd_end;
		    }*/
		    if ( (Pad_on_trigger(B_BUTTON) && !message->nonono_fg) ) {
			last_flag = 1;
			message->end = message->rd_end;
		    }
		}
	    }
	    break;
	    
	case M_PAUSE:
	    /* 改ページ */
////////	    if ( YREG(15) != 0x10 ) {
	    if ( !YREG(31) ) {
		if ( pad_on_check( game_play ) ) {
		    message->msg_mode = M_DISPLAY;
		    message->end++;
# if 0
		} else if ( Pad_on_trigger(START_BUTTON) ) {
		    /* メッセージＣＬＯＳＥ */
		    message_close( game_play );
# endif
		}
	    }
	    break;

	case M_TIMER:
	    /* タイマー改行 */
	    if ( !(--message->wct) ) {
		message->msg_mode = M_READ;
	    }
	    break;
	    
	case M_NEXT:
	    /* 改ページ */
	    if ( pad_on_check( game_play ) ) {
		message->msg_mode = M_READ;
		message->nonono_fg = 0;
		message->rdp++;
/*		speed_fg = 1;  */ /* 早送りフラグ */
# if 0
	    } else if ( Pad_on_trigger(START_BUTTON) ) {
		if ( YREG(15) != 0x10 ) {
		    /* メッセージＣＬＯＳＥ */
		    message_close( game_play );
		}
# endif
	    }
	    break;
	    
	case M_END:
# if CAMERA_FG
	    player->world.position.x = YREG(32);
	    player->world.position.z = YREG(33);
# endif
	    /* メッセージ終了 */
	    if ( message->select == __TIMER ) {
		if ( !(--message->wct) ) {
		    /* メッセージＣＬＯＳＥ */
		    message_close( game_play );
		}
	    } else if ( !(message->select == __DISPSTOP || message->select == __ENEMY/* || YREG(15) == 0x10*/ || YREG(31) ) ) {
		if ( message->select == __2_SELECT && OCARINA_MODE( game_play ) == Oca_Play ) {
		    if ( pad_on_check( game_play ) ) {
			PRINTF("OCARINA_MODE=%d -> ",OCARINA_MODE( game_play ));
			if ( !message->sel_pnt ) OCARINA_MODE( game_play ) = Oca_Warp; 
			else                     OCARINA_MODE( game_play ) = Oca_Stop; /* オカリナ終了 */
			
			PRINTF("InRaceSeq=%d(%d) OCARINA_MODE=%d  -->  ",InRaceSeq,SCENE_2,OCARINA_MODE( game_play ));
			message_close( game_play );
			PRINTF("OCARINA_MODE=%d\n",OCARINA_MODE( game_play ));
		    }
		} else {
		    if ( pad_on_check_0( game_play ) ) {
			PRINTF("select=%d\n",message->select );
			if ( message->select == __Next_Message ) {
			    Na_StartSystemSe( NA_SE_SY_MESSAGE_PASS );
			    if ( !J_N && !staff_mode ) {
				message_set2( game_play, message->msg_b.msg_buff[message->end] );
			    } else {
/*				rd_dt = message->msg_b.nes_msg_b[message->end-1] << 8;
				rd_dt |= message->msg_b.nes_msg_b[message->end];*/
/*				rd_dt = message->msg_b.nes_msg_b[message->end] << 8;
				rd_dt |= message->msg_b.nes_msg_b[message->end+1];
				PRINTF("ＮＥＸＴ(%x, %x) = %x [%04x]\n",message->msg_b.nes_msg_b[message->end],message->msg_b.nes_msg_b[message->end+1], rd_dt, next_msg_no);*/
				message_set2( game_play, next_msg_no );
			    }
			} else {
			    Na_StartSystemSe( NA_SE_SY_DECIDE );
			    /* メッセージＣＬＯＳＥ */
			    message_close( game_play );
			}
		    }
# if 0
		} else if ( Pad_on_trigger(START_BUTTON) ) {
		    /* メッセージＣＬＯＳＥ */
		    message_close( game_play );
# endif
		}
	    }
	    break;
	    
	case M_CLOSE:
	    if ( !--message->wct ) {
		if ( message->msgno >= 0x00c2 && message->msgno <= 0x00c6 ||
		     message->msgno >= 0x00fa && message->msgno <= 0x00fd ) {
		    LIFE_DRINK( game_play );
		}
		if ( message->msgno == 0x301F ||
		     message->msgno == 0x000a ||
		     message->msgno == 0x000c ||
		     message->msgno == 0x00cf ||
		     message->msgno == 0x021c ||
		     message->msgno == 0x0009 ||
		     message->msgno == 0x4078 ||
		     message->msgno == 0x2015 ||
		     message->msgno == 0x3040 ) {
		    LAST_TIME_TYPE = 50;
		}
		if ( !game_play->demo_play.mode ) {
		    COLOR_GREEN();
		    PRINTF("day_time=%x  active_camera=%d  ",ZCommonGet( day_time ), game_play->active_camera);
		    if ( !(message->msgno == 0x2061 ||
			   message->msgno == 0x2025 ||
			   message->msgno == 0x208c ||
			   ((message->msgno >= 0x088d && message->msgno <= 0x0892) && !message->sel_pnt) ||
			   message->msgno == 0x3055) ) {
			if ( ZCommonGet( day_time ) < 0xfff0 ) {
			    PRINTF("=== day_time=%x ",ZCommonGet( day_time ));
			    if ( !game_play->active_camera ) {
				if ( !LAST_TIME_TYPE || LAST_TIME_TYPE == 1 ||  LAST_TIME_TYPE == 2 ) LAST_TIME_TYPE = 50;
				Z_PREV_ALPHA_TYPE = 0;
				alpha_change( LAST_TIME_TYPE );
			    }
			}
		    }
		}
		COLOR_NORMAL();
		message->msg_data = NULL;
		message->msg_mode = M_NULL;
		parameter->sp_action_flag =
		    parameter->sp_action = 0;
		message->msgno =
		    message->wct = 0;
		if ( message->select == __DISPSTOP ) {
		    message->select = 0;
		    OCARINA_MODE( game_play ) = Oca_Warp;
		} else message->select = 0;

		if ( Collect_Heart == HeartMax ) {
		    S_Table.collect_register ^= HeartMax;
		    S_Private.max_life += LIFE_CT;
		    S_Private.now_life += LIFE_CT;
		}
		if ( message->ocarina_no != Ocarina_FrogFrog ) {
		    if ( Chk_Ocarina_No == NA_OCA_CHK_SPIRIT ) {
			/*『サリアの歌』処理 */
			p_player->elf_message = -(0x00e0);
			Actor_set_status(p_player->elf_actor,
					 ACTOR_STATUS_TALK_PLEASE);
		    }
		    
		    if ( message->ocarina_no == Ocarina_FreeFree &&
			 (OCARINA_MODE( game_play ) == Oca_Play || OCARINA_MODE( game_play ) == Oca_Kakasi) ) {
			OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
			if ( message->chk_ocarina_no == NA_OCA_CHK_SUNMOON ) OCARINA_MODE( game_play ) = Oca_Play;
		    }
		}
		Chk_Ocarina_No = 0xff;
		PRINTF("OCARINA_MODE=%d   chk_ocarina_no=%d\n",OCARINA_MODE( game_play ),message->chk_ocarina_no);
	    }
	case M_KOMATSU:
	    break;

# if 0
	case M_OCARINA0:
	case M_OCARINA1:
	case M_OCARINA2:
	case M_OCARINA3:
	case M_OCARINA4:
	case M_OCARINA5:
	case M_OCARINA6:
	case M_OCARINA7:
	case M_OCARINA8:
	case M_OCARINA9:
	case M_OCARINAA:
	case M_OCARINAB:
	case M_OCARINA10_S:
	case M_OCARINA10:
	case M_OCARINA11:
	case M_OCARINA12:
	case M_OCARINA20_S:
	case M_OCARINA20:
	case M_OCARINA21:
	case M_OCARINA22:
	case M_OCARINA23:
	case M_OCARINA24:
	case M_OCARINA40:
	case M_OCARINA41:
	case M_OCARINA42:
	case M_OCARINA60:
	case M_OCARINA61:
	case M_OCARINA62:
	case M_OCARINA63:
	case M_OCARINA64:
	case M_OCARINA65:
	case M_OCARINA66:
	case M_OCARINA67:
	case M_OCARINA80:
	case M_OCARINA81:
	case M_OCARINA82:
# endif
	default:
	    message->frame_cfg = 0xff;
	    break;

	}
    }


#if 0
    /*===========  安全フレーム表示チェック  ===========*/
    if ( message->frame_disp ) {
	if ( Pad_push_also(L_CBUTTONS) ) {
	    if ( Pad_on_trigger(key_data[message->frame_cfg]) ) {
		message->frame_cfg++;
		if ( message->frame_cfg == 3 ) {
		    message->frame_disp = message->frame_cfg = 0;
		}
	    }
	}
    } else {
	if ( Pad_push_also(L_CBUTTONS) ) {
	    if ( Pad_on_trigger(key_data[message->frame_cfg]) ) {
		message->frame_cfg++;
		if ( message->frame_cfg == 3 ) {
		    message->frame_disp = 1;
		    message->frame_cfg  = 0;
		}
	    }
	}
    }
    /*===========  安全フレーム表示チェック  ===========*/
#endif
}
	
/*
 * メッセージポインタ初期化
 */
extern void
message_tbl_p_init(void)
{
    message_tbl_p = message_tbl;
    message_tbl_nes_p = message_tbl_nes;
    message_tbl_staff_p = message_tbl_staff;
#if 01
#if defined(USE_N64DD)
    if (n64dd_function_ok(message_init)) {
	n64dd_function_call(message_init)(
	    &message_tbl_p,
	    &message_tbl_nes_p,
	    &message_tbl_staff_p);
    }
#endif /* defined(USE_N64DD) */
#endif
}
