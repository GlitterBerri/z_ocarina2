/* $Id: z_bgcheck_param.h,v 1.1.1.1 2003/03/10 22:42:56 tong Exp $ */
/*===========================================================================
 *
 * z_bgcheck_param.h
 *
 * Program:Kenji Matsutnai
 * Date:1997年 7月25日(金曜日) 11時44分55秒 JST
 *
 *$Log: z_bgcheck_param.h,v $
 *Revision 1.1.1.1  2003/03/10 22:42:56  tong
 *new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.13  1998/10/01 05:03:41  matutani
 *ラインの弓矢当らないチェック
 *
 *Revision 1.12  1998-09-30 14:07:44+09  matutani
 **** empty log message ***
 *
 *Revision 1.11  1998-07-09 19:26:47+09  matutani
 *床チェックでb>0のみチェックするパターン追加
 *
 *Revision 1.10  1998-06-24 22:19:52+09  matutani
 **** empty log message ***
 *
 *Revision 1.9  1998-06-19 18:46:52+09  matutani
 **** empty log message ***
 *
 *Revision 1.8  1998-04-23 22:35:32+09  matutani
 *床チェック処理マスク
 *
 *Revision 1.7  1998-03-27 21:04:16+09  matutani
 *moveBG当り無し処理
 *
 * Revision 1.6  1998/03/18  01:32:17  takahata
 * *** empty log message ***
 *
 * Revision 1.5  1998/03/06  11:29:38  matutani
 * 変更点１
 * お店、ＶＲ─ＢＯＸ＋ＰＲ、ＶＲ─ＢＯＸの時、BGチェックのバッファーを
 * １５ＫＢしか取らなくしました。
 *
 * 変更点２
 * マップにポリゴンが少ないときにチェックで使うメッシュの個数を２x２x２に
 * する、処理追加。（場所によって処理が増えているところがあるかも知れませ
 * ん。注意してください）
 *
 * Revision 1.4  1997/12/26  02:38:51  umemiya
 * ダイナミック頂点バッファー個数(DYNA_VERT_NUM)増加
 *
 * Revision 1.3  1997/11/06  07:02:53  matutani
 * *** empty log message ***
 *
 * Revision 1.2  1997/11/06  07:02:19  matutani
 * *** empty log message ***
 *
 * Revision 1.1  1997/07/25  06:23:11  matutani
 * Initial revision
 *
 *
 *===========================================================================*/
#ifndef INCLUDE_Z_BGCHECK_PARAM_H
#define INCLUDE_Z_BGCHECK_PARAM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*
 * ダイナミックポリゴン
 */
#if 0
#define DP_NULL 65535
#endif


/*============================================================================
 *
 * 定数値
 *
 *===========================================================================*/
/* 床、天井、壁の区別用パラメーター */
#define BG_GROUND_B_PARAM (0.5f)
#define BG_ROOF_B_PARAM (-0.8f)
#undef BG_WALL_B_PARAM

/* 壁パラメーター */
#define BGCHECK_WALL_CHECK_PARAM (4.0f)
/*----------------------------------------------------------------------------
 *
 * BGチェック用Polygon構造情報
 *
 *---------------------------------------------------------------------------*/

/* カメラでBGチェック */
#define BG_CAMERA_MASK (1<<0)
/* OBJでBGチェック */
#define BG_OBJ_MASK (1<<1)
/* ARROWでBGチェック */
#define BG_ARROW_MASK (1<<2)    

/*
 * v[0]とcheckのマスクを与えて,０以外なら当たらない
 */
#define V0_CHECK(v0, check) (((0x7 & (check)) << 13) & (v0))

/*
 *
 * チェックマスクを除去
 */
#define V_INDEX(x) (0x1fff & (x))
/*
 * 上位３ビットのみ登録
 */
#define V_UP3BIT(x) (0xe000 & (x))
/*
 * ダメージポリゴンチェック用処理マクロ
 */
#define BG_DAMAGE_POLY_CHECK(x) (((x)&(0x1<<27)) != 0 ? TRUE : FALSE)

/*--------------------------------------------------------------------------
 *
 * ダイナミックポリゴン管理構造体
 *
 *-------------------------------------------------------------------------*/
/*
 * チェックマスク内容
 */
#define DYNA_PA_TBL_NO_MASK 0
/* 領域使用中 */
#define DYNA_PA_TBL_USE (1<<0)
/* 削除予約 */
#define DYNA_PA_TBL_DEL_RESERVE (1<<1)
/* 当り無し */
#define DYNA_PA_TBL_THROUGH (1<<2)
/* 天井 off */
#define DYNA_PA_TBL_ROOF_OFF (1<<3)
/* 壁 off */
#define DYNA_PA_TBL_WALL_OFF (1<<4)
/* 床 off */
#define DYNA_PA_TBL_GROUND_OFF (1<<5)

/*---------------------------------------------------------------------------
 *
 * BGチェック用BGCheckInfo
 *
 *--------------------------------------------------------------------------*/

/* オーバラップサイズ */
#define MESH_OVERRAP 50

/*============================================================================
 *
 * 床チェック処理マスク
 *
 *===========================================================================*/
/* デフォルト */
#define BG_GRCH_DEFAULT (BG_GRCH_GROUND_CHECK|BG_GRCH_WALL_CHECK_NFG|BG_GRCH_CHECK_B_PLUSE)
    
/* 天井チェック */
#define BG_GRCH_ROOF_CHECK (1<<0) 
/* 壁チェック */
#define BG_GRCH_WALL_CHECK (1<<1)
/* 床チェック */
#define BG_GRCH_GROUND_CHECK (1<<2)
/*
 * 床チェックでポリゴンが見つかっていなければ壁チェックをする
 * NFG = Not Found Ground
 */
#define BG_GRCH_WALL_CHECK_NFG (1<<3)
/* b > 0の面のみをチェックする */
#define BG_GRCH_CHECK_B_PLUSE (1<<4)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_bgcheck_param.h EOF ***/

