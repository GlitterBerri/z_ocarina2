/* $Id: z_opening.c,v 2.2 1998/11/06 04:57:46 soejima Exp $
 *
 * ゼルダタイトル
 *
 * $Log: z_opening.c,v $
 * Revision 2.2  1998/11/06  04:57:46  soejima
 * コメント
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.19  1998/08/12 10:19:24  soejima
 * *** empty log message ***
 *
 * Revision 1.18  1998-08-03 22:27:41+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.17  1998/07/18 10:50:22  soejima
 * *** empty log message ***
 *
 * Revision 1.16  1998-07-18 16:46:32+09  soejima
 * *** empty log message ***
 *
 * Revision 1.15  1998-07-18 15:16:23+09  soejima
 * *** empty log message ***
 *
 * Revision 1.14  1998-07-18 15:14:10+09  soejima
 * *** empty log message ***
 *
 * $Log追加
 * */

/************************************************************************
 *
 *	ゼルダタイトル
 *
 ************************************************************************/
#include "z_basic.h"
#include "sys_segment.h"
////////#include "z_sram.h"
////////#include "z_sram_h.h"

#include "z_title.h"
#include "z_select.h"
#include "z_opening.h"
#include "z_play.h"
#include "z_common_data.h"	/* z_common_data_t */
#include "z_save_area_h.h"
#include "z_file_choose.h"




extern void save_initialize999( void );


/*===============================================================
  =	オープニング						=
 ===============================================================*/
static void
opening_move( Game *thisx )
{
    Game_opening	*this = (Game_opening *)thisx;


# if 0
    /* Ｎｅｘｔ設定 */
    game_set_next_game_name(thisx, file_choose);
    thisx->_doing = 0;
# endif
# ifdef SCENE_TOOL
    VREG(9) = 255;
    z_common_data.game_info.mode = GAME_INFO_GAME;
    game_set_next_game_name(&this->g, select);
    this->g._doing = 0;
    /* ゲーム開始ＳＲＡＭ ＬＯＡＤ＆ＣＨＥＣＫ */
    Z_BTN_ITEM(0) = 
	Z_BTN_ITEM(1) = 
	Z_BTN_ITEM(2) = 
	Z_BTN_ITEM(3) =
	Z_BTN_ITEM(4) = 0;
    Z_CK_FG =
	Z_ALPHA_TYPE =
	Z_PREV_ALPHA_TYPE =
	Z_ALPHA_COUNT =
	Z_MAGIC_NOW_MAX = 0;
# else
    z_common_data.game_info.mode = GAME_INFO_OPENING_DEMO;
    this->g._doing = 0;
    ZCommon_LinkAgeBeAdult();
    save_initialize999( );
/*    ZCommonSet( day_time, 0xFFF0+VREG(94) );	*/
    ZCommonSet(day_time, 0xfff3);	/* タイトルデモ		*/
    ZCommonSet(game_info.counter, 7);	/* デモＮｏセット	*/
    game_set_next_game_name(&this->g, play);
# endif
}

/*-----------------------------------------------------------------------
 *
 *	オープニング
 *
 *----------------------------------------------------------------------*/
static void
opening_draw( Game *thisx )
{
    thisx;
}



/************************************************************************
 *	オープニング メイン処理						*
 ************************************************************************/
static void
opening_main( Game *thisx )
{
    Game_opening	*this = (Game_opening *)thisx;
    

    /*
     * セグメントアドレス設定
     */
//??    gSPSegment( NEXT_DISP, 0, 0x0 );	/* Physical address segment */
//??    gSPSegment( NEXT_DISP, STATIC_SEGMENT, this->staticSegment );

    /*
     * ディスプレイリスト初期設定
     */
    DisplayList_initialize( this->g.graph, 0, 0, 0 );


    /*
     * ＭＯＶＥ処理
     */
    opening_move( thisx );

    /*
     * ＤＲＡＷ処理
     */
    opening_draw( thisx );
}



/************************************************************************
 *	オープニング画面後始末						*
 * 	・メンバ変数の後始末						*
 ************************************************************************/
extern void
opening_cleanup( Game *thisx )
{
    Game_opening	*this = (Game_opening *)thisx;

#define view_cleanup(view) ((void)(view))
    view_cleanup(&this->view);
}



/************************************************************************
 *	オープニング初期化						*
 * 	・exec, cleanupメンバの設定					*
 * 	・他のメンバ変数の初期化					*
 * 	・ＲＯＭデータのＤＭＡ転送（必要なら）				*
 * 	（注意）描画やキー入力はできません				*
 ************************************************************************/
extern void
opening_init( Game *thisx )
{
    Game_opening	*this = (Game_opening *)thisx;

    
    /*
     * 初期化
     */
    SetGameFrame(1);	/* ゲームフレーム＝１ */

    /*
     * 行列計算クラス宣言
     */
    new_Matrix( thisx );
    
    /*
     * ビュワー初期設定
     */ 
    view_init( &this->view, this->g.graph );

    /*
     * Game必須変数初期化
     */
    this->g.exec	= opening_main;
    this->g.cleanup	= opening_cleanup;

    /*
     * ＳＲＡＭクラス コンストラクト 
     */
///////    sram_title_ct( thisx, &this->sram );
}
