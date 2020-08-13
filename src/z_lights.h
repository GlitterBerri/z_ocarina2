/* $Id: z_lights.h,v 2.1 1998/10/22 12:17:25 zelda Exp $ */	
/* $Log: z_lights.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.28  1998/09/29 15:38:00  goron
 * *** empty log message ***
 *
 * Revision 1.27  1998-09-27 01:19:19+09  goron
 * *** empty log message ***
 *
 * Revision 1.26  1998-09-05 00:11:17+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1998-08-22 18:38:04+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.24  1998-03-25 20:53:53+09  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.23  1997/08/18  12:33:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1997/06/06  00:48:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.21  1997/06/05  00:34:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1997/05/27  13:02:42  iwawaki
 * *** empty log message ***
 *
 * Revision 1.19  1997/05/21  08:39:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/03/11  12:10:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1997/03/11  12:02:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1997/02/20  03:47:40  iwawaki
 * *** empty log message ***
 *
 * Revision 1.15  1997/01/28  13:01:19  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1997/01/28  07:55:41  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1996/10/24  07:20:39  sasaki
 * *** empty log message ***
 *
 * Revision 1.12  1996/10/23  12:12:15  sasaki
 * fog_far Add
 *
 * Revision 1.11  1996/10/18  08:26:45  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1996/10/17  06:47:30  sasaki
 * 環境ライト シーン対応
 *
 * Revision 1.9  1996/10/17  04:55:41  sasaki
 * *** empty log message ***
 *
 * Revision 1.8  1996/10/17  04:42:46  sasaki
 * fog_near 追加
 *
 * Revision 1.7  1996/10/17  02:54:22  sasaki
 * fog color 追加
 *
 * Revision 1.6  1996/09/21  07:38:05  hayakawa
 * enum シンボルの変更
 *
 * Revision 1.5  1996/09/19  13:09:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1996/09/19  07:08:34  iwawaki
 * デバック中
 *
 * Revision 1.3  1996/09/18  09:17:51  iwawaki
 * $Log追加
 * */


#ifndef INCLUDE_Z_LIGHTS_H
#define INCLUDE_Z_LIGHTS_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	ライト
 *
 ************************************************************************/
#include "z_play_h.h"


/************************************************************************
 *
 *	ライトクラス
 *
 ************************************************************************/
typedef struct {
    unsigned char	diffuse_num;	/* ディヒューズライト数 */
    Lights7		lights;		/* ライト情報 */
} LightsN;

/************************************************************************
 *
 *	ライトデータクラス
 *
 ************************************************************************/
enum {
    POINT_LIGHT,
    DIFFUSE_LIGHT,
    POINT2_LIGHT
};

typedef struct {
    short		x;		/* 点光源 Ｘ位置     */
    short		y;		/*        Ｙ         */
    short		z;		/*        Ｚ         */
    unsigned char	color[RGB_NUM];	/*        カラー     */
    unsigned char	status;		/*        情報フラグ */
    short		power;		/*        有効範囲   */
} Light_point;

typedef struct {
    signed char		dx;		/* 平行光源 Ｘ方向   */
    signed char		dy;		/*          Ｙ       */
    signed char		dz;		/*          Ｚ       */
    unsigned char	color[RGB_NUM];	/*          カラー   */
} Light_diffuse;

typedef union {
    Light_point		point;
    Light_diffuse	diffuse;
} Light_status;

typedef struct {
    char		type;	/* 光源タイプ */
    Light_status	status;	/*     情報   */ 
} Light_data;

typedef struct Light_list_s {
    Light_data		*light_data;	/* 光源データ		  */
    struct Light_list_s *pre;		/*           前ポインター */
    struct Light_list_s	*next;		/* 	     次           */
} Light_list;

typedef struct {
    char		num;		/* 光源データ数 */
    Light_data		*light_data;	/*             ポインタ */ 
} Light_data_info;

/*-----------------------------------------------------------------------
 *
 *	ライトデータクラス メンバ関数
 *
 *----------------------------------------------------------------------*/
extern void Light_point_ct(
    Light_data    *this,
    short	  x,
    short	  y,
    short	  z,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    short	  power
);
extern void Light_point2_ct(
    Light_data    *this,
    short	  x,
    short	  y,
    short	  z,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    short	  power
);
extern void Light_point_color_set(
    Light_data    *this,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    short	  power
);

/*-----------------------------------------------------------------------
 *
 *	ライトデータクラス コンストラクタ（ディヒューズライト）
 *
 *----------------------------------------------------------------------*/
extern void Light_diffuse_ct(
    Light_data    *this,
    signed char	  dx,
    signed char   dy,
    signed char   dz,
    unsigned char r,
    unsigned char g,
    unsigned char b
);

/************************************************************************
 *
 *	環境ライトクラス
 *
 ************************************************************************/
typedef struct {
    Light_list		*list;			/* ライトデータリストポインタ */
    unsigned char	ambient_col[RGB_NUM];	/* アンビエントライトカラー   */
    unsigned char	fog_col[RGB_NUM];	/* フォグカラー 	      */
    short		fog_near;		/*       近さ		      */
    short		fog_far;		/*       奥行き		      */
} Global_light;

/*-----------------------------------------------------------------------
 *
 *	ライトクラス メンバ関数
 *
 *----------------------------------------------------------------------*/
extern void LightsN_ct(
    LightsN       *this,
    unsigned char r,
    unsigned char g,
    unsigned char b
);
extern void LightsN_disp(
    LightsN *this,
    Graph   *graph
);
extern Light *LightsN_new_diffuse(
    LightsN *this
);
extern void LightsN_list_check(
    LightsN    *this,
    Light_list *light_list,
    xyz_t      *target
);

/*-----------------------------------------------------------------------
 *
 *	環境ライトクラス メンバ関数
 *
 *----------------------------------------------------------------------*/
extern void Global_light_ct(
    Game 	 *game,
    Global_light *this
);
extern void Global_light_ambient_set(
    Global_light  *this,
    unsigned char ambient_r, unsigned char ambient_g, unsigned char ambient_b
);
extern void Global_light_parallel_set(
    Global_light  *this,
    unsigned char parallel_num,
    unsigned char parallel_r, unsigned char parallel_g, unsigned char parallel_b,
    float 	  parallel_direction_x, float parallel_direction_y, float parallel_direction_z
);

/*-----------------------------------------------------------------------
 *
 *	環境ライト フォグ設定
 *
 *----------------------------------------------------------------------*/
extern void Global_light_fog_set(
    Global_light  *this,
    unsigned char fog_r, unsigned char fog_g, unsigned char fog_b,
    short 	  fog_near, short fog_far
);
extern LightsN *Global_light_read(
    Global_light *this,
    Graph 	 *graph
);

/*-----------------------------------------------------------------------
 *
 *	ライトデータクラス メンバ関数
 *
 *----------------------------------------------------------------------*/
extern void Global_light_list_ct(
    Game	 *game,
    Global_light *this
);
extern void Global_light_list_dt(
    Game         *game,
    Global_light *this
);
extern Light_list *Global_light_list_new(
    Game         *game,
    Global_light *this,
    Light_data   *light_data
);
extern void Global_light_list_delete(
    Game         *game,
    Global_light *this,
    Light_list   *light_list
);

/************************************************************************
 *
 *	ライトライブラリー関数
 *
 ************************************************************************/
extern LightsN *new_Lights(
    Graph 	  *graph,
    unsigned char ambient_r, unsigned char ambient_g, unsigned char ambient_b,
    unsigned char diffuse_num,
    unsigned char diffuse_r, unsigned char diffuse_g, unsigned char diffuse_b,
    signed char   direction_x, signed char direction_y, signed char direction_z
);

extern LightsN *new_LightsN(
    Graph 	  *graph,
    unsigned char ambient_r,
    unsigned char ambient_g,
    unsigned char ambient_b
);

/*-----------------------------------------------------------------------
 *
 *	ポイントライト表示チェック（コールバック関数）
 *
 *----------------------------------------------------------------------*/
extern void Light_list_point_draw_check(
    Game_play  *game_play
);
/*-----------------------------------------------------------------------
 *
 *	ポイントライト表示
 *
 *----------------------------------------------------------------------*/
extern void Light_list_point_draw(
    Game_play  *game_play
);


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_lights.h end ***/
