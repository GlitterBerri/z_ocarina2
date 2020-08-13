/* $Id: z_kaleido_scope.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 * $Log: z_kaleido_scope.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.64  1998/09/19 14:11:41  hayakawa
 * kaleido_scope_dt追加
 *
 * Revision 1.63  1998-09-19 18:28:18+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/02/06  04:45:57  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_KALEIDO_SCOPE_H
#define INCLUDE_Z_KALEIDO_SCOPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_basic.h"
#include "audio.h"
#include "sys_segment.h"

#include "z_kanfont.h"



/************************************************************************
 *									*
 *	カレイド・スコープ						*
 *				1997年02月06日(木曜日) 09時00分00秒 JST *
 ************************************************************************/
typedef struct {
	short	r, g, b, a;
} rgba_z;

typedef struct {
	short	ob[2];			/* x, y */
} Vtx_z;



typedef struct zelda_z_kscope_struct {
    View	view;

    char	*icon_itemSegment;	/* アイテム セグメント */
    char	*icon_item24Segment;	/* アイテム セグメント */
    char	*icon_item_map_Segment;	/* アイテム セグメント */
    char	*icon_item_jpn_nes_Segment;	/* アイテム セグメント */
    char	*item_nameSegment;	/* アイテムＮａｍｅ セグメント */
    char	*playerSegment;		/* プレイヤー セグメント */
    char	*map_nameSegment;	/* 現在地名 セグメント */

    Vtx_t	*item_frame_Vtx;	/* ＩＴＥＭフレーム */
    Vtx_t	*equipment_frame_Vtx;	/* ＥＱＵＩＰフレーム */
    Vtx_t	*map_frame_Vtx;		/* ＭＡＰフレーム */
    Vtx_t	*collect_frame_Vtx;	/* ＣＯＬＬＥＣＴフレーム */
    
    Vtx_t	*menuVtx;		/* メニュー パネル */
    Vtx_t	*itemVtx;		/* Ｉｔｅｍアイテム */
    Vtx_t	*equipVtx;		/* Ｅｑｕｉｐアイテム */
    Vtx_t	*mapVtx;		/* ＭＡＰアイテム */
    Vtx_t	*collectVtx;		/* ＣＯＬＬＥＣＴアイテム */
    Vtx_t	*cursolVtx;		/* カーソル */
    Vtx_t	*saveVtx;		/* セーブ メッセージ */

    char	map_palete[16*2];	/* ＭＡＰパレット */


    char	*cvg;


    NA_OCARINA_PLAY_INFO	*info;	/* オカリナ */


    dma_t	k_dma;			/* メモリ転送関係 */
    OSMesgQueue	mq;			/*		  */
    OSMesg	m;			/*	  	  */
    
    
    unshort	pause;			/* on/offフラグ */
    unshort	debug;			/* on/offフラグ */

    xyz_t	eye;			/* LookAt 視点位置 */

    unshort	kscp_status;		/* 状態 */
    unshort	kscp_mode;		/* モード */
    unshort	kscp_pos;		/* 表示面 */
    unshort	kscp_scroll;		/* カウンタ─ */
    unshort	save_status;		/* ＳＡＶＥ状態 */

    float	translate;		/* 距離 */
    float	angle_i;		/* ＩＴＥＭ面用角度 */
    float	angle_e;		/* ＥＱＵＩＰＭＥＮＴ面用角度 */
    float	angle_m;		/* ＭＡＰ面用角度 */
    float	angle_c;		/* ＣＯＬＬＥＣＴ面用角度 */
    float	angle_s;		/* ＳＡＶＥ面用角度 */
    unshort	alpha;			/* アルファ値 */
    short	yp;			/* 補正ＹＰＯＳ */

    int		xbuff, ybuff;		/* ＸＹ入力キー */
    short	wkey_x, wkey_y;		/* 入力キー バッファ */
    short	cursor_point[5];	/* 各面カーソル位置 */
    short	cur_xpt[5], cur_ypt[5];	/* ＥＱＵＩＰ面ポインタ */
    short	dungeon_map_pt;		/* ＭＡＰ面ポインタ */

    short	key_angle;		/* 入力キー方向 */
    short	key_frame;		/* 入力キーＷａｉｔフレーム */


    unshort	zoom_name;		/* 拡大アイテム名前ポインター */
    unshort	select_name[4];		/* 選択名前ポインター */
    unshort	select_pt[4];		/* 選択アイテムポインター */

    unshort	sl_item_no;		/* 選択アイテムＮｏ．*/
    unshort	sl_number;		/* 選択アイテム番号 */
    unshort	sl_button;		/* 選択ボタン */
    short	sl_xpos;		/* 選択アイテム移動Ｘ */
    short	sl_ypos;		/*                 Ｙ */
    short	sl_alpha;		/*             Ａｌｐｈａ */

    short	menu_myp;		/* メニュー・移動Ｙ */
    unshort	name_flush;		/* アイテム点滅カウンター */
    unshort	name_hold;		/* アイテムＨＯＬＤフラグ */
    short	cursor_colp;		/* カーソル カラーポインタ */

    short	save_cursor;

    short	ocarina_no;

    unchar	field_map_evt[20];	/* フィールドＭＡＰ用 イベント */

    unchar	warashibe_flag;		/* わらしべフラグ */

    /* プレイヤー */
    Skeleton_Info 	skeleton;		/* スケルトンシェイプクラス */
} Kscope; 



/*==============================================================*/
extern void
kaleido_scope_ct( Game_play *game_play );	/* 構築子（コンストラクタ）*/

extern void
kaleido_scope_dt( Game_play *game_play );	/* 消滅子（デストラクタ）*/

extern void
kaleido_scope_draw( Game_play *game_play );

extern void
kaleido_scope_move( Game_play *game_play );


/*==============================================================*/


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_kaleido_scope.h end ***/
