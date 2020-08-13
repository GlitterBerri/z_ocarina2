/* $Id: z_kaleido_scope_h.h,v 2.2 1998-10-27 21:25:43+09 soejima Exp $
 * $Log: z_kaleido_scope_h.h,v $
 * Revision 2.2  1998-10-27 21:25:43+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.87  1998/09/26 13:47:24  hayakawa
 * *** empty log message ***
 *
 * Revision 1.86  1998-09-22 17:37:14+09  soejima
 * *** empty log message ***
 *
 * Revision 1.85  1998-09-19 18:28:30+09  soejima
 * *** empty log message ***
 *
 * Revision 1.84  1998-09-18 22:37:06+09  takahata
 * *** empty log message ***
 *
 * Revision 1.83  1998-09-17 14:10:05+09  soejima
 * *** empty log message ***
 *
 * Revision 1.82  1998-09-10 22:58:04+09  soejima
 * *** empty log message ***
 *
 * Revision 1.81  1998-09-08 22:34:35+09  soejima
 * *** empty log message ***
 *
 * Revision 1.80  1998-09-08 16:49:49+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/02/07  08:21:55  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_KALEIDO_SCOPE_H_H
#define INCLUDE_Z_KALEIDO_SCOPE_H_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "graph.h"		/* Graph */
#include "z_kaleido_scope.h"
#include "z_parameter.h"


#if defined(PAL_VERSION)
/*==============================================================*/
#define TS8	0
/*==============================================================*/
/*==============================================================*/
/*==============================================================*/
extern short partvtx_mapg_xsz[];
extern short partvtx_mapg_ysz[];

extern unsigned char	number_item[];

extern char 	select_popup_data[];
extern char 	equipment_popup_data[][4];


extern unchar kin_sta_suu[];


/*****************************
******************************
	ＤＵＮＧＥＯＮ
******************************
******************************/
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/nes/h_dt */
extern unsigned char  h_dt_1_nes_txt[];
extern unsigned char  h_dt_2_nes_txt[];
extern unsigned char  h_dt_3_nes_txt[];
extern unsigned char  h_dt_4_nes_txt[];
extern unsigned char  h_dt_5_nes_txt[];
extern unsigned char  h_dt_6_nes_txt[];
extern unsigned char  h_dt_7_nes_txt[];
extern unsigned char  h_dt_8_nes_txt[];
extern unsigned char  h_dt_9_nes_txt[];
extern unsigned char  h_dt_10_nes_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/dungeon_map/rgba16 : 【ＭＡＰ画面】 */
extern unsigned short h_link_txt[];
extern unsigned short h_boss_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/dungeon_map/ia : 【ＭＡＰ画面】 */
extern unsigned char h_0f_txt[];
extern unsigned char h_1f_txt[];
extern unsigned char h_2f_txt[];
extern unsigned char h_3f_txt[];
extern unsigned char h_4f_txt[];
extern unsigned char h_5f_txt[];
extern unsigned char h_6f_txt[];
extern unsigned char h_7f_txt[];
extern unsigned char h_8f_txt[];
extern unsigned char h_b1_txt[];
extern unsigned char h_b2_txt[];
extern unsigned char h_b3_txt[];
extern unsigned char h_b4_txt[];
extern unsigned char h_b5_txt[];
extern unsigned char h_b6_txt[];
extern unsigned char h_b7_txt[];
extern unsigned char h_b8_txt[];



/*****************************
******************************
	ＦＩＥＬＤ
******************************
******************************/
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/ci */
extern unsigned char h_fieldmap[];
extern unsigned short h_fieldmap_pal[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/ia */
extern unsigned char h_dungeon_mark_0_txt[];
extern unsigned char  h_area_10_13_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/area */
extern unsigned char  h_area_a_txt[];
extern unsigned char  h_area_b_txt[];
extern unsigned char  h_area_c_txt[];
extern unsigned char  h_area_d_txt[];
extern unsigned char  h_area_e_txt[];
extern unsigned char  h_area_f_txt[];
extern unsigned char  h_area_g_txt[];
extern unsigned char  h_area_h_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/ia4 */
extern unsigned char  h_wara_yajirusi_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/cloud */
extern unsigned char  h_cloud_01_txt[];
extern unsigned char  h_cloud_02_txt[];
extern unsigned char  h_cloud_03_txt[];
extern unsigned char  h_cloud_04_txt[];
extern unsigned char  h_cloud_05_txt[];
extern unsigned char  h_cloud_06_txt[];
extern unsigned char  h_cloud_07_txt[];
extern unsigned char  h_cloud_08_txt[];
extern unsigned char  h_cloud_09_txt[];
extern unsigned char  h_cloud_10_txt[];
extern unsigned char  h_cloud_11_txt[];
extern unsigned char  h_cloud_12_txt[];
extern unsigned char  h_cloud_13_txt[];
extern unsigned char  h_cloud_14_txt[];
extern unsigned char  h_cloud_15_txt[];
extern unsigned char  h_cloud_16_txt[];


/************************************************************************
 *									*
 *	カレイド・スコープ						*
 *				1997年02月06日(木曜日) 09時00分00秒 JST *
 ************************************************************************/
/* 処理ポインタ */
enum {
    Pause_None,
    Pause_Check,	// スタートチェック
    Pause_Wait,		// プリレンダ─化待ち
    Pause_Wait1,	// ＤＭＡ
    Pause_In,		// カレイド・スコープ出現
    Pause_Fade,		// フェードイン
    Pause_Play,		// ＰＬＡＹ
    Pause_Save,		// セーブ
    Pause_Gameover_C,	//
    Pause_Gameover_W,	//
    Pause_Gameover_00,	//
    Pause_Gameover_10,	//
    Pause_Gameover_20,	//
    Pause_Gameover_I,	//
    Pause_Gameover_P,	//
    Pause_Gameover_S,	//
    Pause_Gameover_N,	//
    Pause_Gameover_E,	//
    Pause_Out,		// カレイド・スコープ終了
    Pause_End,		// 終了
    Pause_Point
};

/* ＳＡＶＥ処理ポインタ */
enum {
    Save_In,		// Ｓａｖｅ面へ
    Save_Play,		// Ｋｅｙチェック
    Save_Cancel0,	// キャンセル
    Save_Out0,		// 元の面へ
    Save_Save,		// セーブ終了
    Save_Cancel1,	// キャンセル
    Save_Out1,		// 元の面へ
    Save_Point
};


/* 拡大メッセージ ポインタ */
enum {
    Display_Item,
    Display_Map,
    Display_Collect,
    Display_Equipment,
    Display_Map_Field,
    Display_Point
};

#define HD_LEFT			10
#define HD_RIGHT		11


#define DG_VTX			(2+1+3+8+2+1)
#define	DG_VTX_PT		(((5*3)+DG_VTX)*4)

#define	TRANSLATE_SS		1200.0f
#define TRANSLATE_S_0		(TRANSLATE_S - TRANSLATE_E)/FIFO_CNT
#define TRANSLATE_SS_0		(TRANSLATE_SS - TRANSLATE_E)/FIFO_CNT

#define	FIFO_CNT	 	5.0f

#define	CURSOL_TRANSLATE_E	144.0f
#define CURSOL_SCALE_X		10000
#define CURSOL_SCALE_Y		10000
#define	CURSOL_SCALE_Z		10000

#define	ANGLE_XZ		160.0f

#define ZOOM_UP			-22.0f
#define ZOOM_SUP		-57.0f
#define ZOOM_DOWN		-72.0f

#define PRIM_OFF		120
#define PRIM_ON			255

#define	MAP_Y_ANGLE		157	/* ＭＡＰ面 Ｙ角度 */
#define	COLLECT_Y_ANGLE		314	/* ＣＯＬＬＥＣＴ面 Ｙ角度 */
#define	EQUIPMENT_Y_ANGLE	-157	/* ＥＱＵＩＰＭＥＮＴ面 Ｙ角度 */


/* データサイズ */
#define	I_N_PT	(128*16)
#define	I_N_PT1	(80*16)

#define MENU_MYP	40	/* 名前パネルＹ位置（原本）*/


/*==============================================================*/
/* カーソルＣＯＬＯＲ */
#define Cursor_Red	0
#define Cursor_Yellow	4
#define Cursor_Blue	8
/*==============================================================*/
/*
 * z_kaleido_scope.c
 */
extern Gfx
*texture_QuadrangleIA4( Gfx *gp, void *timg,
			short width, short height,
			unsigned short pt );
extern Gfx
*texture_QuadrangleIA8( Gfx *gp, void *timg,
			short width, short height,
			unsigned short pt );

extern void
cursol_defalute( Kscope *kscope, unsigned short j, Vtx_t *vtx_pt );

extern void
key_arrangement( Game_play *game_play, unsigned short arrangement );
	
extern void
kaleido_scope_item_set( Graph *graph, void *data, unsigned short width, unsigned short height, unsigned short pt );

extern Gfx compas_model[];
extern void
cursor_draw( Game_play *game_play, unsigned short pos  );

extern void
map_dma( Game_play *game_play );



/*
 * z_kaleido_item.c
 */
extern void
item_select_disp( Game_play *game_play );

extern void
item_move( Game_play *game_play );

extern void
item_cursol_defalute( Kscope *kscope );



/*
 * z_kaleido_equipment.c
 */
extern void
equipment_disp( Game_play *game_play );



/*
 * z_kaleido_map.c
 */
extern void
dungeon_map_disp(Game_play *game_play, Graph *graph );
extern void
field_map_disp( Game_play *game_play, Graph *graph );



/*
 * z_kaleido_collect.c
 */
extern void
collect_disp( Game_play *game_play, Graph *graph );



/*
 * z_kaleido_save.c
 */
extern void
reset_disp( Game_play *game_play );



/*
 * z_kaleido_debug.c
 */
extern void
kaleido_scope_debug_draw( Game_play *game_play );



/*==============================================================*/
#define	KALEIDO_SCOPE_Pause_on_off( game_play )	( game_play->kscope.pause || game_play->kscope.debug  )

/*==============================================================*/
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/others/ia : カレイド・スコープ付属品 */
extern unsigned char g_sp_nes_others_0_txt[];
extern unsigned char g_sp_nes_others_1_txt[];
extern unsigned char g_sp_nes_others_2_txt[];
extern unsigned char g_sp_nes_others_3_txt[];
extern unsigned char g_sp_nes_others_4_txt[];
extern unsigned char g_sp_nes_others_5_txt[];
extern unsigned char g_sp_nes_others_6_txt[];
extern unsigned char g_sp_ger_others_0_txt[];
extern unsigned char g_sp_ger_others_1_txt[];
extern unsigned char g_sp_ger_others_2_txt[];
extern unsigned char g_sp_ger_others_3_txt[];
extern unsigned char g_sp_ger_others_4_txt[];
extern unsigned char g_sp_ger_others_5_txt[];
extern unsigned char g_sp_ger_others_6_txt[];
extern unsigned char g_sp_fra_others_0_txt[];
extern unsigned char g_sp_fra_others_1_txt[];
extern unsigned char g_sp_fra_others_2_txt[];
extern unsigned char g_sp_fra_others_3_txt[];
extern unsigned char g_sp_fra_others_4_txt[];
extern unsigned char g_sp_fra_others_5_txt[];
extern unsigned char g_sp_fra_others_6_txt[];

extern unsigned char h_here_nes_txt[];
extern unsigned char h_here_g_txt[];
extern unsigned char h_here_f_txt[];


/*extern Gfx map_frame_dl100[];*/
/*extern Gfx map_frame_dl101[];*/
extern Gfx map_frame_dl102[];
extern Gfx map_frame_dl103[];
/*extern Gfx item_frame_dl100[];*/
/*extern Gfx item_frame_dl101[];*/
extern Gfx item_frame_dl102[];
/*extern Gfx equipment_frame_dl100[];*/
/*extern Gfx equipment_frame_dl101[];*/
extern Gfx equipment_frame_dl102[];
extern Gfx equipment_frame_dl103[];
/*extern Gfx collectitems_frame_dl100[];*/
/*extern Gfx collectitems_frame_dl101[];*/
extern Gfx collectitems_frame_dl102[];
/*extern Gfx save_frame_dl000[];*/
/*extern Gfx save_frame_dl001[];*/
/*
extern Gfx save_frame_dl100[];
extern Gfx save_frame_dl101[];
extern Gfx save_frame_dl200[];
extern Gfx save_frame_dl201[];
extern Gfx save_frame_dl300[];
extern Gfx save_frame_dl400[];
*/
extern Gfx save_frame_dl200[];
extern Gfx save_frame_dl201[];


extern Gfx menu_data_dl0[];	// メッセージ枠
extern Gfx menu_data_dl0_1[];	// Ｚ
extern Gfx menu_data_dl0_2[];	// Ｒ
extern Gfx menu_data_dl2[];	// ＣＣＣ
extern Gfx menu_data_dl3[];	// Ａ
////////extern Gfx menu_data_dl4[];	// でセット
////////extern Gfx menu_data_dl6[];	// で決定
////////extern Gfx menu_data_dl7[];	// で切り替え
extern Gfx menu_data_dl8[];	// Ｂ
////////extern Gfx menu_data_dl20[];	// ←左の画面へ
////////extern Gfx menu_data_dl21[];	// 右の画面へ→
#else
/*==============================================================*/
#define TS8	0
/*==============================================================*/
/*==============================================================*/
/*==============================================================*/
extern short partvtx_mapg_xsz[];
extern short partvtx_mapg_ysz[];

extern unsigned char	number_item[];

extern char 	select_popup_data[];
extern char 	equipment_popup_data[][4];


extern unchar kin_sta_suu[];


/*****************************
******************************
	ＤＵＮＧＥＯＮ
******************************
******************************/
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/jpn/h_dt */
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/nes/h_dt */
extern unsigned char  h_dt_1_txt[];
extern unsigned char  h_dt_2_txt[];
extern unsigned char  h_dt_3_txt[];
extern unsigned char  h_dt_4_txt[];
extern unsigned char  h_dt_5_txt[];
extern unsigned char  h_dt_6_txt[];
extern unsigned char  h_dt_7_txt[];
extern unsigned char  h_dt_8_txt[];
extern unsigned char  h_dt_9_txt[];
extern unsigned char  h_dt_10_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/dungeon_map/rgba16 : 【ＭＡＰ画面】 */
extern unsigned short h_link_txt[];
extern unsigned short h_boss_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/dungeon_map/ia : 【ＭＡＰ画面】 */
extern unsigned char h_0f_txt[];
extern unsigned char h_1f_txt[];
extern unsigned char h_2f_txt[];
extern unsigned char h_3f_txt[];
extern unsigned char h_4f_txt[];
extern unsigned char h_5f_txt[];
extern unsigned char h_6f_txt[];
extern unsigned char h_7f_txt[];
extern unsigned char h_8f_txt[];
extern unsigned char h_b1_txt[];
extern unsigned char h_b2_txt[];
extern unsigned char h_b3_txt[];
extern unsigned char h_b4_txt[];
extern unsigned char h_b5_txt[];
extern unsigned char h_b6_txt[];
extern unsigned char h_b7_txt[];
extern unsigned char h_b8_txt[];



/*****************************
******************************
	ＦＩＥＬＤ
******************************
******************************/
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/ci */
extern unsigned char h_fieldmap[];
extern unsigned short h_fieldmap_pal[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/ia */
extern unsigned char h_dungeon_mark_0_txt[];
extern unsigned char  h_area_10_13_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/area */
extern unsigned char  h_area_a_txt[];
extern unsigned char  h_area_b_txt[];
extern unsigned char  h_area_c_txt[];
extern unsigned char  h_area_d_txt[];
extern unsigned char  h_area_e_txt[];
extern unsigned char  h_area_f_txt[];
extern unsigned char  h_area_g_txt[];
extern unsigned char  h_area_h_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/ia4 */
extern unsigned char  h_wara_yajirusi_txt[];
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/map/field_map/cloud */
extern unsigned char  h_cloud_01_txt[];
extern unsigned char  h_cloud_02_txt[];
extern unsigned char  h_cloud_03_txt[];
extern unsigned char  h_cloud_04_txt[];
extern unsigned char  h_cloud_05_txt[];
extern unsigned char  h_cloud_06_txt[];
extern unsigned char  h_cloud_07_txt[];
extern unsigned char  h_cloud_08_txt[];
extern unsigned char  h_cloud_09_txt[];
extern unsigned char  h_cloud_10_txt[];
extern unsigned char  h_cloud_11_txt[];
extern unsigned char  h_cloud_12_txt[];
extern unsigned char  h_cloud_13_txt[];
extern unsigned char  h_cloud_14_txt[];
extern unsigned char  h_cloud_15_txt[];
extern unsigned char  h_cloud_16_txt[];


/************************************************************************
 *									*
 *	カレイド・スコープ						*
 *				1997年02月06日(木曜日) 09時00分00秒 JST *
 ************************************************************************/
/* 処理ポインタ */
enum {
    Pause_None,
    Pause_Check,	// スタートチェック
    Pause_Wait,		// プリレンダ─化待ち
    Pause_Wait1,	// ＤＭＡ
    Pause_In,		// カレイド・スコープ出現
    Pause_Fade,		// フェードイン
    Pause_Play,		// ＰＬＡＹ
    Pause_Save,		// セーブ
    Pause_Gameover_C,	//
    Pause_Gameover_W,	//
    Pause_Gameover_00,	//
    Pause_Gameover_10,	//
    Pause_Gameover_20,	//
    Pause_Gameover_I,	//
    Pause_Gameover_P,	//
    Pause_Gameover_S,	//
    Pause_Gameover_N,	//
    Pause_Gameover_E,	//
    Pause_Out,		// カレイド・スコープ終了
    Pause_End,		// 終了
    Pause_Point
};

/* ＳＡＶＥ処理ポインタ */
enum {
    Save_In,		// Ｓａｖｅ面へ
    Save_Play,		// Ｋｅｙチェック
    Save_Cancel0,	// キャンセル
    Save_Out0,		// 元の面へ
    Save_Save,		// セーブ終了
    Save_Cancel1,	// キャンセル
    Save_Out1,		// 元の面へ
    Save_Point
};


/* 拡大メッセージ ポインタ */
enum {
    Display_Item,
    Display_Map,
    Display_Collect,
    Display_Equipment,
    Display_Map_Field,
    Display_Point
};

#define HD_LEFT			10
#define HD_RIGHT		11


#define DG_VTX			(2+1+3+8+2+1)
#define	DG_VTX_PT		(((5*3)+DG_VTX)*4)

#define	TRANSLATE_SS		1200.0f
#define TRANSLATE_S_0		(TRANSLATE_S - TRANSLATE_E)/FIFO_CNT
#define TRANSLATE_SS_0		(TRANSLATE_SS - TRANSLATE_E)/FIFO_CNT

#define	FIFO_CNT	 	5.0f

#define	CURSOL_TRANSLATE_E	144.0f
#define CURSOL_SCALE_X		10000
#define CURSOL_SCALE_Y		10000
#define	CURSOL_SCALE_Z		10000

#define	ANGLE_XZ		160.0f

#define ZOOM_UP			-22.0f
#define ZOOM_SUP		-57.0f
#define ZOOM_DOWN		-72.0f

#define PRIM_OFF		120
#define PRIM_ON			255

#define	MAP_Y_ANGLE		157	/* ＭＡＰ面 Ｙ角度 */
#define	COLLECT_Y_ANGLE		314	/* ＣＯＬＬＥＣＴ面 Ｙ角度 */
#define	EQUIPMENT_Y_ANGLE	-157	/* ＥＱＵＩＰＭＥＮＴ面 Ｙ角度 */


/* データサイズ */
#define	I_N_PT	(128*16)
#define	I_N_PT1	(80*16)

#define MENU_MYP	40	/* 名前パネルＹ位置（原本）*/


/*==============================================================*/
/* カーソルＣＯＬＯＲ */
#define Cursor_Red	0
#define Cursor_Yellow	4
#define Cursor_Blue	8
/*==============================================================*/
/*
 * z_kaleido_scope.c
 */
extern Gfx
*texture_QuadrangleIA4( Gfx *gp, void *timg,
			short width, short height,
			unsigned short pt );
extern Gfx
*texture_QuadrangleIA8( Gfx *gp, void *timg,
			short width, short height,
			unsigned short pt );

extern void
cursol_defalute( Kscope *kscope, unsigned short j, Vtx_t *vtx_pt );

extern void
key_arrangement( Game_play *game_play, unsigned short arrangement );
	
extern void
kaleido_scope_item_set( Graph *graph, void *data, unsigned short width, unsigned short height, unsigned short pt );

extern Gfx compas_model[];
extern void
cursor_draw( Game_play *game_play, unsigned short pos  );

extern void
map_dma( Game_play *game_play );



/*
 * z_kaleido_item.c
 */
extern void
item_select_disp( Game_play *game_play );

extern void
item_move( Game_play *game_play );

extern void
item_cursol_defalute( Kscope *kscope );



/*
 * z_kaleido_equipment.c
 */
extern void
equipment_disp( Game_play *game_play );



/*
 * z_kaleido_map.c
 */
extern void
dungeon_map_disp(Game_play *game_play, Graph *graph );
extern void
field_map_disp( Game_play *game_play, Graph *graph );



/*
 * z_kaleido_collect.c
 */
extern void
collect_disp( Game_play *game_play, Graph *graph );



/*
 * z_kaleido_save.c
 */
extern void
reset_disp( Game_play *game_play );



/*
 * z_kaleido_debug.c
 */
extern void
kaleido_scope_debug_draw( Game_play *game_play );



/*==============================================================*/
#define	KALEIDO_SCOPE_Pause_on_off( game_play )	( game_play->kscope.pause || game_play->kscope.debug  )

/*==============================================================*/
/* shape/TEXTURE/DMA_MAKE/ICON_ITEM/others/ia : カレイド・スコープ付属品 */
extern unsigned char g_sp_others_0_txt[];
extern unsigned char g_sp_others_1_txt[];
extern unsigned char g_sp_others_2_txt[];
extern unsigned char g_sp_others_3_txt[];
extern unsigned char g_sp_others_4_txt[];
extern unsigned char g_sp_others_5_txt[];
extern unsigned char g_sp_others_6_txt[];
extern unsigned char g_sp_nes_others_0_txt[];
extern unsigned char g_sp_nes_others_1_txt[];
extern unsigned char g_sp_nes_others_2_txt[];
extern unsigned char g_sp_nes_others_3_txt[];
extern unsigned char g_sp_nes_others_4_txt[];
extern unsigned char g_sp_nes_others_5_txt[];
extern unsigned char g_sp_nes_others_6_txt[];

extern unsigned char h_here_txt[];
extern unsigned char h_here_nes_txt[];


/*extern Gfx map_frame_dl100[];*/
/*extern Gfx map_frame_dl101[];*/
extern Gfx map_frame_dl102[];
extern Gfx map_frame_dl103[];
/*extern Gfx item_frame_dl100[];*/
/*extern Gfx item_frame_dl101[];*/
extern Gfx item_frame_dl102[];
/*extern Gfx equipment_frame_dl100[];*/
/*extern Gfx equipment_frame_dl101[];*/
extern Gfx equipment_frame_dl102[];
extern Gfx equipment_frame_dl103[];
/*extern Gfx collectitems_frame_dl100[];*/
/*extern Gfx collectitems_frame_dl101[];*/
extern Gfx collectitems_frame_dl102[];
/*extern Gfx save_frame_dl000[];*/
/*extern Gfx save_frame_dl001[];*/
/*
extern Gfx save_frame_dl100[];
extern Gfx save_frame_dl101[];
extern Gfx save_frame_dl200[];
extern Gfx save_frame_dl201[];
extern Gfx save_frame_dl300[];
extern Gfx save_frame_dl400[];
*/
extern Gfx save_frame_dl200[];
extern Gfx save_frame_dl201[];


extern Gfx menu_data_dl0[];	// メッセージ枠
extern Gfx menu_data_dl0_1[];	// Ｚ
extern Gfx menu_data_dl0_2[];	// Ｒ
extern Gfx menu_data_dl2[];	// ＣＣＣ
extern Gfx menu_data_dl3[];	// Ａ
////////extern Gfx menu_data_dl4[];	// でセット
////////extern Gfx menu_data_dl6[];	// で決定
////////extern Gfx menu_data_dl7[];	// で切り替え
extern Gfx menu_data_dl8[];	// Ｂ
////////extern Gfx menu_data_dl20[];	// ←左の画面へ
////////extern Gfx menu_data_dl21[];	// 右の画面へ→
#endif




#define	F00	0
#define	F8F	1
#define	F7F	2
#define	F6F	3
#define	F5F	4
#define	F4F	5
#define	F3F	6
#define	F2F	7
#define	F1F	8
#define	FB1	9
#define	FB2	10
#define	FB3	11
#define	FB4	12
#define	FB5	13
#define	FB6	14
#define	FB7	15
#define	FB8	16

#define BOSS_0	 51
#define BOSS_1	 37
#define BOSS_2	 23
#define BOSS_3    9
#define BOSS_4	 -5
#define BOSS_5	-19
#define BOSS_6	-33
#define BOSS_7	-47
#define BOSS_8	-99

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_kaleido_scope_h.h end ***/
