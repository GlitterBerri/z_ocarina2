/*
 * $Id: z_title.c,v 2.1 1998/10/22 11:51:48 zelda Exp $
 *
 * Ｎキューブ＆Ｎ６４ロゴ表示
 *
 * $Log: z_title.c,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.126  1998/10/07 11:57:04  hayakawa
 * *** empty log message ***
 *
 * Revision 1.125  1998-10-07 15:57:39+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.124  1998-10-03 21:07:38+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.123  1998-10-02 21:15:17+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.122  1998-10-01 22:55:49+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.121  1998-09-30 09:29:09+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.120  1998-09-26 23:23:05+09  okajima
 * *** empty log message ***
 *
 * Revision 1.119  1998-09-26 23:06:33+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.118  1998-09-26 15:53:19+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.117  1998-09-26 15:44:48+09  soejima
 * はずした！！！！！！！
 *
 * Revision 1.116  1998-09-25 23:08:37+09  hayakawa
 * DISK変更
 *
 * Revision 1.115  1998-09-25 00:24:26+09  okajima
 * *** empty log message ***
 *
 * Revision 1.114  1998-09-24 23:10:13+09  hayakawa
 * CICテスト
 *
 * Revision 1.113  1998-09-22 22:04:59+09  hayakawa
 * CIC
 *
 * Revision 1.112  1998-09-22 15:54:25+09  hayakawa
 * CIC6105 TEST
 *
 * Revision 1.111  1998-09-18 13:32:27+09  okajima
 * *** empty log message ***
 *
 * Revision 1.110  1998-09-17 17:54:10+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.109  1998-09-15 21:50:44+09  hayakawa
 * ６４ＤＤ更新
 *
 * Revision 1.108  1998-09-14 23:00:12+09  hayakawa
 * CICテスト
 *
 * Revision 1.107  1998-09-10 20:53:47+09  okajima
 * *** empty log message ***
 *
 * Revision 1.106  1998-09-09 00:09:44+09  okajima
 * *** empty log message ***
 *
 * Revision 1.105  1998-09-07 20:30:02+09  zelda
 * CIC Check結果を表示するようにした
 *
 * Revision 1.104  1998-09-05 21:46:16+09  okajima
 * *** empty log message ***
 *
 * Revision 1.103  1998-09-04 23:51:35+09  okajima
 * *** empty log message ***
 *
 * Revision 1.102  1998-09-04 17:43:47+09  okajima
 * *** empty log message ***
 *
 * Revision 1.101  1998-09-04 00:06:10+09  okajima
 * *** empty log message ***
 *
 * Revision 1.100  1998-09-03 15:46:13+09  okajima
 * *** empty log message ***
 *
 * Revision 1.99  1998-09-03 13:32:49+09  okajima
 * *** empty log message ***
 *
 * Revision 1.97  1998-09-03 11:33:26+09  soejima
 * *** empty log message ***
 *
 * Revision 1.96  1998-09-02 22:05:43+09  hayakawa
 * バージョン表示をこっちに移動した
 * ずるモードの時ロゴを飛ばせるようにした
 *
 * Revision 1.95  1998-08-19 22:48:28+09  hayakawa
 * CIC6105のオーディオ制御
 *
 * Revision 1.94  1998-08-08 17:51:46+09  okajima
 * *** empty log message ***
 *
 * Revision 1.93  1998-08-07 09:46:32+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.92  1998-08-06 15:28:49+09  okajima
 * *** empty log message ***
 *
 * Revision 1.91  1998-08-04 22:00:19+09  okajima
 * *** empty log message ***
 *
 * Revision 1.90  1998-08-04 21:59:21+09  okajima
 * *** empty log message ***
 *
 * Revision 1.89  1998-08-04 21:37:56+09  okajima
 * *** empty log message ***
 *
 * Revision 1.88  1998-08-04 21:08:37+09  okajima
 * *** empty log message ***
 *
 * Revision 1.87  1998-08-03 15:56:08+09  okajima
 * *** empty log message ***
 *
 * Revision 1.86  1998-08-03 13:33:48+09  okajima
 * *** empty log message ***
 *
 * Revision 1.85  1998-08-03 12:02:09+09  okajima
 * *** empty log message ***
 *
 * Revision 1.84  1998-08-01 23:57:39+09  okajima
 * *** empty log message ***
 *
 * Revision 1.83  1998-07-31 21:45:01+09  okajima
 * *** empty log message ***
 *
 * Revision 1.82  1998-07-30 23:04:31+09  okajima
 * *** empty log message ***
 *
 * Revision 1.81  1998-07-29 23:00:14+09  okajima
 * *** empty log message ***
 *
 * Revision 1.80  1998-07-29 12:55:01+09  okajima
 * *** empty log message ***
 *
 * Revision 1.79  1998-07-28 22:55:26+09  okajima
 * *** empty log message ***
 *
 * Revision 1.78  1998-07-25 21:21:58+09  okajima
 * *** empty log message ***
 *
 * Revision 1.77  1998-07-24 21:11:19+09  okajima
 * *** empty log message ***
 *
 * Revision 1.76  1998-07-24 19:54:18+09  okajima
 * *** empty log message ***
 *
 * Revision 1.75  1998-07-24 16:58:19+09  soejima
 * 岡嶋君お願いします！！！！！！！！！！！！！
 *
 * Revision 1.74  1998-06-30 20:24:20+09  soejima
 * *** empty log message ***
 *
 * $Log追加
 *
 */



/************************************************************************
 *
 *	ゼルダタイトル
 *
 ************************************************************************/
#include "z_basic.h"
#include "sys_segment.h"
#include "z_play.h"
#include "assert64.h"		/* assert */
#include "padmgr.h"
#include "z_common_data.h"	/* z_common_data_t */

#include "z_file_choose.h"
#include "z_sram.h"
#include "z_sram_h.h"
#include "z_title.h"
#include "z_opening.h"
#include "z_save_area_h.h"
#include "CIC6105.h"

#ifdef USE_N64DD
#include "z_n64dd.h"	/* n64dd_init */
#endif
#include "zurumode.h"		/* isZuruMode */
#include "sys_freeze.h"		/* Freeze */

#define	DISPLAY_FILLTER_XLU	(1<<1)	

extern padmgr_t padmgr;


/* 外部シンボル宣言 */
EXTERN_DEFSEG_DATA(nintendo_rogo_static);

extern unsigned char g_nintendo64_l_txt[];
extern unsigned char g_nintendo64_m_txt[];
extern Gfx n_cube_model[];

#if 0
/* TEST */
extern unsigned char  mable_txt[];
extern unsigned char g_boss_name00_txt[];
extern unsigned char g_boss_e_name00_txt[];
#endif

#if ZURUMODE
#include "gfxprint.h"		/* gfxprint_t */
#include "alloca.h"		/* alloca */
#include "version.h"		/* __Creator__ ... */
static void
draw_version(Gfx **gpp)
{
    Gfx *gp = *gpp;
    gfxprint_t *gfxprint;
    
    gp = gfx_rect_moji(gp);
    gfxprint = (gfxprint_t *)alloca(sizeof(gfxprint_t));
    Gfxprint_init();
    Gfxprint_open(gp);
    
    Gfxprint_color(255, 155, 255, 255);
    
#ifndef ROM_F
    Gfxprint_locate8x8(9, 21);
    gfxprint_printf(gfxprint, "NOT MARIO CLUB VERSION");
#endif
    
    Gfxprint_color(255, 255, 255, 255);
    
    Gfxprint_locate8x8(7, 23);
    gfxprint_printf(gfxprint, "[Creator:%s]", __Creator__);
    
    Gfxprint_locate8x8(7, 24);
    gfxprint_printf(gfxprint, "[Date:%s]", __DateTime__);
    
#ifdef U_hayakawa_U
    Gfxprint_locate8x8(2, 2);
    gfxprint_printf(gfxprint, "osRomType=%d,", osRomType);
    Gfxprint_locate8x8(2, 3);
    gfxprint_printf(gfxprint, "osRomBase=%08x,", osRomBase);
    Gfxprint_locate8x8(2, 4);
    gfxprint_printf(gfxprint, "osTvType=%d,", osTvType);
    Gfxprint_locate8x8(2, 5);
    gfxprint_printf(gfxprint, "osCicId=%d, ", osCicId);
    Gfxprint_locate8x8(2, 6);
    gfxprint_printf(gfxprint, "osVersion=%d, ", osVersion);
    Gfxprint_locate8x8(2, 7);
    gfxprint_printf(gfxprint, "osMemSize=%08x, ", osMemSize);
    Gfxprint_locate8x8(4, 8);
    gfxprint_printf(gfxprint, "osResetType=%d,", osResetType);
#endif
    
#ifdef USE_N64DD
    Gfxprint_locate8x8(12, 27);
    if (n64dd_isConnected()) {
	Gfxprint_color(255, 255, 50, 255);
	gfxprint_printf(gfxprint, "N64DISK CONNECTED");
    } else {
	Gfxprint_color(255, 55, 150, 255);
	gfxprint_printf(gfxprint, "N64DISK NOT CONNECTED");
    }
#endif /* USE_N64DD */

#ifdef USE_CIC6105
    cic6105_title_draw(gfxprint);
#endif /* USE_CIC6105 */

    gp = Gfxprint_close();
    Gfxprint_cleanup();
    *gpp = gp;
}
#endif /* ZURUMODE */

/*===============================================================
  =	任天堂ロゴ表示						=
 ===============================================================*/
static void
nintendo_rogo_move( Game *thisx )
{
    Game_title	*this = (Game_title *)thisx;

#ifdef U_hayakawa_U
#if ZURUMODE
    /*
     * 飛ばさせて頂きます
     * 電源／リセット osResetType
     */
    if (isZuruMode()) {
	pad_t *pad = &thisx->pads[0];
	if ( Pad_push_also(START_BUTTON) ) {
	    this->done = 1;
	}
    }
#endif /* ZURUMODE */
#endif /* U_hayakawa_U */

    if ( this->alpha == 0 && this->wait_timer != 0 ) {
	--this->timer;
	--this->wait_timer;
	if ( !this->timer ) {
	    this->timer = 400;
	}
    } else {
	this->alpha += this->alpha_data;
	if ( this->alpha <= 0 ) {
	    this->alpha = 0;
	    this->alpha_data = 3;
	} else if ( this->alpha >= 255 ) {
	    this->alpha = 255;
	    this->done = 1;
	}
    }

    this->work = (this->counter * 1 ) & 0x7f;
    this->counter++;
}

/*===============================================================
  =	ビュー設定						=
 ===============================================================*/
static void
view_setting( Game *thisx, float ex, float ey, float ez )
{
    Game_title	*this = (Game_title *)thisx;

    xyz_t	eye, center, up;


    /*
     * ビュー設定
     */
    eye.x = ex;
    eye.y = ey;
    eye.z = ez;
    up.x = up.z = 0.0f;
    up.y = 1.0f;

    center.x = center.y = center.z = 0.0f;
/*
    center.x = 7.200000f;
    center.y = 450.799988f;
    center.z = -3.300000f;
    */
    setPerspectiveView(&this->view, 30.0f, 10.0f, 12800.0f );

    setLookAtView(&this->view, &eye, &center, &up);

    view_setup_view(&this->view);
    /* showView(&this->view, VIEW_DO_PERSALL); */
}

/*-----------------------------------------------------------------------
 *
 *	ＮＩＮＴＥＮＤＯロゴ 表示処理
 *
 *----------------------------------------------------------------------*/
static void nintendo_rogo_draw( Game *thisx )
{

    Game_title	*this = (Game_title *)thisx;
    
    unshort	i, ypos;
    xyz_t	light_direction;	/* 環境マッピングのため */
    xyz_t h_pos,h_eye;
    static short yang = 0;
    int scale_x,scale_y;
    static Lights1 light_data = gdSPDefLights1( 100,100,100, 255,255,255, 69,69,69 );
    
    OPEN_DISP(this->g.graph);


    light_direction.x = 69.0f;
    light_direction.y = 69.0f;
    light_direction.z = 69.0f;
    h_eye.x = -4949.147949f;
    h_eye.y = 4002.541748f;
    h_eye.z = 1119.083740f;
    h_pos.x = 0.0f;
    h_pos.y = 0.0f;
    h_pos.z = 0.0f;
    HiliteReflect_init(&h_pos,
		       &h_eye,
		       &light_direction,
		       this->g.graph);

    gSPSetLights1( NEXT_DISP,light_data );

    /* ビュー設定 */
    view_setting( thisx, 0.0f, 150.0f, 300.0f );

    _texture_z_light_fog_prim(this->g.graph);

    Matrix_translate( -53.0f, -5.0f, 0.0f, SET_MTX );
    
    Matrix_scale( 1.0f, 1.0f, 1.0f, MULT_MTX );
    Matrix_rotateXYZ( 0, yang, 0, MULT_MTX );

    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(this->g.graph),
	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    /* Ｎ キューブ表示 */
    gSPDisplayList(NEXT_DISP, n_cube_model);

    /* ＮＩＮＴＥＮＤＯ６４ロゴ表示 */
#if 1
    scale_x = (int)(1024.0f/ (199.0f/100.0f));
    scale_y = (int)(1024.0f/ (102.0f/100.0f));

    rectangle_a_prim(this->g.graph);
#define G_CC_INT552	TEXEL1, PRIMITIVE, ENV_ALPHA, TEXEL0, 0, 0, 0, TEXEL0
#define G_CC_INT553	PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0
    gDPPipeSync( NEXT_DISP );
    gDPSetCycleType( NEXT_DISP, G_CYC_2CYCLE );
    gDPSetRenderMode( NEXT_DISP, G_RM_PASS, G_RM_CLD_SURF2 );
//    gDPSetRenderMode( NEXT_DISP, G_RM_PASS, G_RM_XLU_SURF2 );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT552, G_CC_INT553 );
#else
    rectangle(this->g.graph);
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineLERP( NEXT_DISP,
		       TEXEL1, PRIMITIVE, ENV_ALPHA, TEXEL0,
		       0, 0, 0, TEXEL0,
		       PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT,
		       COMBINED, 0, PRIMITIVE, 0);
#endif
    
    gDPSetPrimColor( NEXT_DISP, 0, 0, 170, 255, 255, 255 );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 255, 128 );


    gDPLoadMultiBlock( NEXT_DISP,
		       g_nintendo64_m_txt, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
		       G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
		       5, 5, scale_x, scale_y );

    for ( i = 0, ypos = 110-16; i < 16; i++, ypos+=2 ) {
	gDPLoadMultiBlock( NEXT_DISP,
			   g_nintendo64_l_txt+(192*2*i), 0, G_TX_RENDERTILE, G_IM_FMT_I, G_IM_SIZ_8b, 192, 2, 0,
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );

	gDPSetTileSize( NEXT_DISP, G_TX_RENDERTILE+1,
			this->work,
			((this->counter * 1) & 0x7f) - ((i * 1) << 2), 
			0, 0 );
	
	gSPTextureRectangle( NEXT_DISP,
			     97 << 2, ypos << 2,
			     (97 + 192) << 2, (ypos + 2) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 <<10, 1 << 10 );
    }

    Display_Fillter(this->g.graph, 0, 0, 0, this->alpha, DISPLAY_FILLTER_XLU );
    
    yang += 300;

    CLOSE_DISP(this->g.graph);
}

 /************************************************************************
 *	タイトル メイン処理						*
 ************************************************************************/
static void
title_main( Game *thisx )
{
    Game_title	*this = (Game_title *)thisx;
    
    OPEN_DISP( this->g.graph );

    /*
     * セグメントアドレス設定
     */
    gSPSegment( NEXT_DISP, 0, 0x0 );	/* Physical address segment */
    gSPSegment( NEXT_DISP, STATIC_SEGMENT, this->staticSegment );

    /*
     * ディスプレイリスト初期設定
     */
    DisplayList_initialize( this->g.graph , 0, 0, 0 );

#ifdef CHINA
    /*
     * ＭＯＶＥ処理
     */
    nintendo_rogo_move( thisx );	/* 任天堂ロゴ表示 */
    
    /*
     * ＤＲＡＷ処理
     */
    nintendo_rogo_draw( thisx );

    /* nintendo_rogo_draw_test( thisx ); */	/* 実験 */

#endif

#if ZURUMODE
    if (isZuruMode()) {
	Gfx *gp;
	
	/* バージョン表示 */
	gp = NOW_DISP;
	draw_version(&gp);
	SET_NOW_DISP(gp);
    }
#endif /* ZURUMODE */

#ifdef CHINA
    this->done = 1;
#endif
    
    if ( this->done ) {
	/* Ｎｅｘｔ設定 */
	ZCommonSet(old_bgm, 255);
	ZCommonSet(old_env, 255);
	z_common_data.game_info.mode = GAME_INFO_OPENING_DEMO;
	this->g._doing = 0;
	game_set_next_game_name(&this->g, opening);
    }
    
    CLOSE_DISP( this->g.graph );
}


/************************************************************************
 *	タイトル画面後始末						*
 * 	・メンバ変数の後始末						*
 ************************************************************************/
extern void
title_cleanup( Game *thisx )
{
    Game_title	*this = (Game_title *)thisx;
    
#ifdef USE_N64DD
    if (this->n64dd_inital_background) {
	PRINTF(ESC_CYAN "n64dd初期化完了待ち\n" ESC_NORMAL);
	if (n64dd_init_wait() == 0) {
	    PRINTF(ESC_CYAN "n64dd初期化完了！\n" ESC_NORMAL);
	} else {
	    PRINTF(ESC_CYAN "n64dd初期化失敗！\n" ESC_NORMAL);
	    Freeze();
	}
	PRINTF(ESC_CYAN "ゼルダディスクは入ってる？\n" ESC_NORMAL);
	n64dd_MediumCheck();
    }
#endif /* USE_N64DD */
	
    /* ＳＲＡＭイニシャライズチェック */
    sram_initialize( thisx, &this->sram );

#define view_cleanup(view) ((void)(view))
    view_cleanup(&this->view);
#if defined(USE_CIC6105)
    cic6105_title_cleanup();
#endif
}



/************************************************************************
 *	タイトル初期化							*
 * 	・exec, cleanupメンバの設定					*
 * 	・他のメンバ変数の初期化					*
 * 	・ＲＯＭデータのＤＭＡ転送（必要なら）				*
 * 	（注意）描画やキー入力はできません				*
 ************************************************************************/
extern void
title_init( Game *thisx )
{
    Game_title	*this = (Game_title *)thisx;

    u32		size;

#ifdef USE_N64DD
    if (n64dd_isStay() && n64dd_isConnected() && !n64dd_isInitialized()) {
	PRINTF(ESC_CYAN "n64dd初期化開始\n" ESC_NORMAL);
	if (n64dd_init_background() != 0) {
	    PRINTF(ESC_CYAN "n64dd初期化失敗！\n" ESC_NORMAL);
	    Freeze();
	}
	this->n64dd_inital_background = 1;
    } else {
    	this->n64dd_inital_background = 0;
    }
#endif /* USE_N64DD */
	
    /*
     * スタティックデータの転送
     */
    size = (u32)_nintendo_rogo_staticSegmentRomEnd - (u32)_nintendo_rogo_staticSegmentRomStart;
    this->staticSegment = (char *)game_alloc(&this->g, (size_t)size);

    PRINTF("z_title.c\n");
    assert(this->staticSegment != NULL);
    dmacopy_fg(this->staticSegment, (u32)_nintendo_rogo_staticSegmentRomStart, size);

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
    this->g.exec	= title_main;
    this->g.cleanup	= title_cleanup;

    /*
     * 終了フラグ初期化
     */
    this->done = 0;
    
    /*
     * コントローラー装着チェック
     */
    if ( !(padmgr_GetPadPattern(&padmgr) & 0x1) ) {
	z_common_data.file_no = 0xFEDC;		/* 未装着 */
    } else z_common_data.file_no = 0xff;	/* 装着 */
    
    /*
     * ＳＲＡＭクラス コンストラクト 
     */
    sram_title_ct( thisx, &this->sram );

    /*
     * 変数初期化
     */
    this->counter = 0;
    this->timer	= 20;
    this->alpha = 255;
    this->alpha_data = -3;
    /* this->wait_timer = 100; */
    this->wait_timer = 60;
}






#if 0
/*-----------------------------------------------------------------------
 *
 *	ＮＩＮＴＥＮＤＯロゴ 表示処理 (実験)
 *
 *----------------------------------------------------------------------*/
static void nintendo_rogo_draw_test( Game *thisx )
{

    Game_title	*this = (Game_title *)thisx;
    
    unshort	i, ypos;
    
    static unsigned char *txture[] = {
	g_boss_name00_txt,
	g_boss_e_name00_txt,
    };

    OPEN_DISP(this->g.graph);


    /* ビュー設定 */
    view_setting( thisx, 0.0f, 0.0f, 200.0f );

    rectangle_a_prim(this->g.graph);
//#define G_CC_INT550	TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, 1, PRIM_LOD_FRAC, TEXEL0
#define G_CC_INT550	TEXEL1, PRIMITIVE, ENV_ALPHA, TEXEL0, TEXEL1, 1, ENVIRONMENT, TEXEL0
#define G_CC_INT551	PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0
    gDPPipeSync( NEXT_DISP );
    gDPSetCycleType( NEXT_DISP, G_CYC_2CYCLE );
    gDPSetAlphaCompare( NEXT_DISP, G_AC_THRESHOLD );
    gDPSetRenderMode( NEXT_DISP, G_RM_PASS, G_RM_CLD_SURF2 );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT550, G_CC_INT551 );

//    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 170, 255 );
    gDPSetPrimColor( NEXT_DISP, 0, 128, 255, 255, 170, 255 );
    gDPSetEnvColor( NEXT_DISP, 170, 100, 0, DORO(1) );
    
    gDPLoadMultiBlock( NEXT_DISP,
		       mable_txt, 256+128, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
		       G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
		       5, 5, 1, 1 );
    for ( i = 0, ypos = DORO(11)-16; i < 2; i++, ypos+=20 ) {
	gDPLoadMultiBlock( NEXT_DISP,
			   txture[DORO(27)]+(128*20*i), 0, G_TX_RENDERTILE, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 20, 0,
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );

	gDPSetTileSize( NEXT_DISP, G_TX_RENDERTILE+1,
			this->work,
			((this->counter * DORO(26)) & 0x7f) - ((i * 10) << 2),
			0, 0 );

	gSPTextureRectangle( NEXT_DISP,
			     DORO(10) << 2, ypos << 2,
			     (DORO(10) + 128) << 2, (ypos + 20) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 <<10, 1 << 10 );
    }

    CLOSE_DISP(this->g.graph);
}
#endif
