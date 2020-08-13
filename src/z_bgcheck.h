/*
 * $Id: z_bgcheck.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $
 *
 * $Log: z_bgcheck.h,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.100  1998/10/06 06:16:45  matutani
 * *** empty log message ***
 *
 * Revision 1.99  1998-10-02 14:10:38+09  matutani
 * Spot07滝上対応
 *
 * Revision 1.98  1998-10-01 14:03:19+09  matutani
 * ラインの弓矢当らないチェック
 *
 * Revision 1.97  1998-09-30 14:07:09+09  matutani
 * *** empty log message ***
 *
 * Revision 1.96  1998-09-22 13:23:42+09  matutani
 * *** empty log message ***
 *
 * Revision 1.95  1998-09-14 19:01:21+09  matutani
 * *** empty log message ***
 *
 * Revision 1.94  1998-09-07 11:43:04+09  matutani
 * Obj系当らないコードをチェック
 *
 * Revision 1.93  1998-09-04 00:01:49+09  matutani
 * *** empty log message ***
 *
 * Revision 1.92  1998-09-02 17:35:47+09  matutani
 * DynaPolygonInfo_setExpand()セット
 *
 * Revision 1.91  1998-08-25 20:51:29+09  matutani
 * *** empty log message ***
 *
 * Revision 1.90  1998-08-19 16:31:30+09  matutani
 * T_BGCheck_ObjWallCheck*()系列を削除
 * T_BGCheck_ObjWAllCheck2*()系列を使いましょう
 *                       ~~
 *
 * Revision 1.89  1998-08-17 15:33:44+09  matutani
 * *** empty log message ***
 *
 * Revision 1.88  1998-07-14 14:39:50+09  matutani
 * 天井チェック新バージョン
 *
 * Revision 1.87  1998-06-23 22:04:02+09  matutani
 * *** empty log message ***
 *
 * Revision 1.86  1998-06-19 18:46:29+09  matutani
 * *** empty log message ***
 *
 * Revision 1.85  1998-06-16 17:46:35+09  matutani
 * *** empty log message ***
 *
 * Revision 1.84  1998-06-15 22:27:08+09  matutani
 * *** empty log message ***
 *
 * Revision 1.83  1998-06-12 19:31:36+09  matutani
 * ある２枚の無限平面の交線とある直線との一番近い点
 *
 * Revision 1.82  1998-06-09 13:43:27+09  matutani
 * 隙間パラメータラインチェック／床チェック追加
 *
 * Revision 1.81  1998-06-06 17:01:13+09  matutani
 * ある２枚の無限平面の交線とある点から垂線を下ろした時に交差する点を
 * 求める
 *
 * Revision 1.80  1998-05-26 15:22:10+09  matutani
 * T_BGCheck_ObjGroundCheck_grpWG_aiac()追加
 *
 * Revision 1.79  1998-05-25 21:59:47+09  matutani
 * T_BGCheck_ObjGroundCheck_grpW_aiac()追加
 *
 * Revision 1.78  1998-05-14 20:29:26+09  matutani
 * 整理
 *
 * Revision 1.77  1998-05-11 13:40:21+09  matutani
 * T_BGCheck_CameraGroundCheck_grpWG_ai()復帰
 *
 * Revision 1.76  1998-05-07 16:01:53+09  matutani
 * *** empty log message ***
 *
 * Revision 1.75  1998-05-05 14:50:26+09  matutani
 *  T_Polygon -> float a, b, c変換
 *
 * Revision 1.74  1998-04-27 14:02:30+09  matutani
 * *** empty log message ***
 *
 * Revision 1.73  1998-04-23 22:36:01+09  matutani
 * 床チェック特殊処理（壁／床チェック）
 *
 * Revision 1.72  1998-04-21 18:31:04+09  matutani
 * *** empty log message ***
 *
 * Revision 1.71  1998-04-15 15:19:39+09  matutani
 * *** empty log message ***
 *
 * Revision 1.70  1998-04-09 23:26:12+10  matutani
 * *** empty log message ***
 *
 * Revision 1.69  1998/03/27  12:03:51  matutani
 * moveBG当り無し処理
 *
 * Revision 1.68  1998/03/18  01:33:04  takahata
 * *** empty log message ***
 *
 * Revision 1.67  1998/03/11  02:22:10  matutani
 * *** empty log message ***
 *
 * Revision 1.66  1998/03/06  11:30:45  matutani
 * 変更点１
 * お店、ＶＲ─ＢＯＸ＋ＰＲ、ＶＲ─ＢＯＸの時、BGチェックのバッファーを
 * １５ＫＢしか取らなくしました。
 *
 * 変更点２
 * マップにポリゴンが少ないときにチェックで使うメッシュの個数を２x２x２に
 * する、処理追加。（場所によって処理が増えているところがあるかも知れませ
 * ん。注意してください）
 *
 * Revision 1.65  1998/02/25  03:09:45  matutani
 * *** empty log message ***
 *
 * Revision 1.64  1998/02/24  05:09:10  matutani
 * 関数追加
 *
 * Revision 1.63  1998/02/18  13:19:16  matutani
 * マクロ速度テスト
 *
 * Revision 1.62  1998/02/12  11:21:04  matutani
 * *** empty log message ***
 *
 * Revision 1.61  1998/02/10  05:07:58  matutani
 * *** empty log message ***
 *
 * Revision 1.60  1998/02/04  13:12:35  matutani
 * シンプルＢＧチェック
 *
 * Revision 1.59  1998/01/29  12:01:48  matutani
 * 矢系当らないフラグ
 *
 * Revision 1.58  1998/01/12  12:02:15  matutani
 * フックショット刺さるコード
 *
 * Revision 1.57  1997/12/25  09:39:59  matutani
 * *** empty log message ***
 *
 * Revision 1.56  1997/12/24  09:58:31  matutani
 * 横穴
 *
 * Revision 1.55  1997/12/12  02:13:41  matutani
 * *** empty log message ***
 *
 * Revision 1.54  1997/12/11  02:50:28  matutani
 * T_BGCheck_getWallCode_aiをexternにした。
 *
 * Revision 1.53  1997/12/03  08:40:23  matutani
 * *** empty log message ***
 *
 * Revision 1.52  1997/12/03  08:31:28  matutani
 * 水情報変更のための関数追加
 *
 * Revision 1.51  1997/11/14  01:02:29  matutani
 * *** empty log message ***
 *
 * Revision 1.50  1997/11/10  06:42:53  matutani
 * bsp関連削除／修正
 *
 * Revision 1.49  1997/11/05  11:48:24  matutani
 * 変更中止
 *
 * Revision 1.48  1997/11/04  06:27:16  matutani
 * 床上げビット追加
 *
 * Revision 1.47  1997/10/11  12:26:15  matutani
 * extern void DynaPolyInfo_resetBGDataInfo()の引数変更
 *
 * Revision 1.46  1997/10/11  06:43:15  matutani
 * T_BGCheck_WaterGetCameraType()関数名訂正
 *
 * Revision 1.45  1997/10/11  05:59:27  matutani
 * T_BGCheck_WaterGetCameraSet():カメラデータがNULLの場合は-1を返す。
 *
 * Revision 1.44  1997/10/10  12:06:38  matutani
 * *** empty log message ***
 *
 * Revision 1.43  1997/10/10  11:59:35  matutani
 * *** empty log message ***
 *
 * Revision 1.42  1997/10/07  13:53:08  matutani
 * 環境取得
 *
 * Revision 1.41  1997/10/07  11:54:25  matutani
 * 水面高さチェック
 *
 * Revision 1.40  1997/09/11  03:09:19  matutani
 * *** empty log message ***
 *
 * Revision 1.39  1997/09/11  02:49:00  matutani
 * *** empty log message ***
 *
 * Revision 1.38  1997/09/01  03:06:44  matutani
 * *** empty log message ***
 *
 * Revision 1.37  1997/08/27  11:21:41  matutani
 * *** empty log message ***
 *
 * Revision 1.36  1997/08/09  06:56:36  matutani
 * ごみ削除
 *
 * Revision 1.35  1997/08/04  08:32:06  matutani
 * T_BGCheck_getKankyo_ai()追加
 *
 * Revision 1.34  1997/07/29  09:54:46  matutani
 * ダイナミックポリゴンテスト
 *
 * Revision 1.33  1997/07/25  06:22:37  matutani
 * T_BGCheck_CameraLineCheck_polyThrough_chgrp_ai追加
 *
 * Revision 1.32  1997/07/23  10:57:32  matutani
 * aiacグループ追加
 *
 * Revision 1.31  1997/07/22  23:44:50  matutani
 * 自分自身のダイナミックポリゴンの当たりをはずした。
 *
 * Revision 1.30  1997/07/19  10:43:18  matutani
 * ダイナミック当り
 *
 * Revision 1.29  1997/07/07  06:02:52  matutani
 * *** empty log message ***
 *
 * Revision 1.28  1997/07/03  04:37:43  matutani
 * *** empty log message ***
 *
 * Revision 1.27  1997/06/30  13:26:32  matutani
 * 梯子UP追加
 *
 * Revision 1.26  1997/06/27  12:52:20  matutani
 * 壁梯子チェック
 *
 * Revision 1.25  1997/06/27  12:15:39  matutani
 * 壁ビットコード取得関数追加と整理
 *
 * Revision 1.24  1997/06/27  05:20:46  matutani
 * index版
 *
 * Revision 1.23  1997/06/26  10:56:40  matutani
 * パンチミスCangeをChangeに
 *
 * Revision 1.22  1997/06/26  00:37:31  matutani
 * 新規ポリゴンデータ
 *
 * Revision 1.21  1997/06/20  10:56:03  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1997/06/18  13:10:31  matutani
 * 高速化／データ準備
 *
 * Revision 1.19  1997/05/26  04:29:03  matutani
 * 前処理／その他高速化
 *
 * Revision 1.18  1996/11/20  01:17:26  hayakawa
 * SHORT_MAX ー＞ SHRT_MAXに変更
 *
 * Revision 1.17  1996/11/14  07:26:55  matutani
 * 面の頂点データを渡す関数追加
 *
 * Revision 1.16  1996/11/11  08:33:37  matutani
 * BGチェック調整
 *
 * Revision 1.15  1996/10/28  10:25:34  matutani
 * z_bgcheck_type.hを追加
 *
 * Revision 1.14  1996/10/28  09:08:34  matutani
 * *** empty log message ***
 *
 * Revision 1.13  1996/10/23  01:07:35  matutani
 * 壁チェックバグ取り
 *
 * Revision 1.12  1996/10/22  05:14:36  matutani
 * ラインチェック引数変更
 *
 * Revision 1.11  1996/10/15  05:35:58  matutani
 * 最大最小変更
 *
 * Revision 1.10  1996/10/15  04:52:44  iwawaki
 * 最大値を８１９２から１６５３６へ
 *
 * Revision 1.9  1996/10/03  13:29:07  matutani
 * 壁チェック補正変更
 *
 * Revision 1.8  1996/09/27  05:02:04  matutani
 * SHORT_MAX/SHORT_MINをはずした
 *
 * Revision 1.7  1996/09/24  06:54:52  matutani
 * *** empty log message ***
 *
 * Revision 1.6  1996/09/24  03:57:18  matutani
 * 壁チェック時の壁を抜けているかどうかのチェック時のパラメータの値を0.0f
 * からBGCHECK_WALL_CHECK_PARAM(=10.0f)に変更
 *
 * Revision 1.5  1996/09/21  12:07:26  matutani
 * 引数の文字列変更／天井チェック追加
 *
 * Revision 1.4  1996/09/20  08:03:15  matutani
 * MESH_OVERRAPを１００にした。
 *
 * Revision 1.3  1996/09/18  09:07:42  iwawaki
 * $Log追加
 */

/*----------------------------------------------------------------------------
 *
 * ＢＧチェック
 *
 * 1996/08/22
 * Program:Kenji Matsutani
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_BGCHECK_H
#define INCLUDE_BGCHECK_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"game.h"
#include"z_bgcheck_type.h"


#define BG_INFINITY 30000
#define BG_FP_INFINITY 1.0e38f
#define	BGCHECK_OVER_Y	32000.0f

#define POS_MAX 16384.0f
#define POS_MIN -16384.0f

/*=========================================================================
 *
 * ポリゴン処理
 *
 *=========================================================================*/
/*--------------------------------------------------------------------------
 *
 * T_Polygon->Math3D_triangle
 *
 *-----------------------------------------------------------------------*/
extern void T_Polygon2Math3D_trinale(
    T_Polygon *ppoly,
    T_Vertex *vtx_tbl,
    Math3D_triangle *ptri);

/*----------------------------------------------------------------------------
 *
 * BGチェック用Polygon構造体 
 *
 *---------------------------------------------------------------------------*/

/* a,b,cの値の変換計算 */
#define T_POLYGON_ABC_CONV(x) ((float)(x)* (1.0f/(float)SHRT_MAX))

/*----------------------------------------------------------------------------
 *
 * T_Polygon -> float a, b, c
 *
 *---------------------------------------------------------------------------*/
extern void T_Polygon_getABC(
    T_Polygon *ppoly,
    float *a, float *b, float *c);

/*-----------------------------------------------------------------------
 *
 *	地形ポリゴン行列作成
 *
 *----------------------------------------------------------------------*/
extern void T_Polygon_Ground_Matrix(
    T_Polygon	*polygon_info,
    float	x,
    float	y,
    float	z,
    MtxF	m
);

/*
 * 平面方程式の値
 * f(x, y, z) = ax + by + cz + d
 */
extern float T_Polygon_PlaneFunc(T_Polygon *this, xyz_t *pp);

/*
 * 面の頂点データを渡す。
 * アクターインデックスが必要
 */
extern void T_Polygon_GetVertex_bg_ai(
    T_Polygon *this, /* 頂点を調べるポリゴン */
    int bg_actor_index, /* アクターインデックス */
    T_BGCheck *pbgcheck, /* BG情報 */
    xyz_t *vertex_array); /* vertex データを入れて返す領域 xyz_t
			   * のサイズ３の配列 の先頭ポインター
			   */
/*---------------------------------------------------------------------------
 *
 * 初期化
 *
 *---------------------------------------------------------------------------*/
extern void T_BGCheck_ct(
    T_BGCheck *this, /* BGチェック用の情報構造体 */
    Game *game, /* ゲーム構造体 */
    T_BGDataInfo *pbgdata); /* BGのデータ情報構造体 */

/*---------------------------------------------------------------------------
 *
 * デストラクター
 *
 * T_BGCheck内 後処理
 *
 *--------------------------------------------------------------------------*/
extern void T_BGCheck_dt(
    T_BGCheck *this, /* BGチェック用の情報構造体 */
    Game *game); /* ゲーム構造体 */

/*============================================================================
 *
 * 床チェック
 *
 *===========================================================================*/

/*----------------------------------------------------------------------------
 *
 * カメラ用
 *
 *--------------------------------------------------------------------------*/
extern float T_BGCheck_CameraGroundCheck(
    T_BGCheck *this, /* BGチェック構造体 */
    T_Polygon **ret_poly, /* 床ポリゴン:領域は外部で確保 */
    xyz_t *pos); /* 判定位置 */

/*--------------------------------------------------------------------------
 *
 * 床方向チェック:チェックグループ床／壁
 * カメラ当たり版
 *
 * 引数:
 * T_BGCheck *this : BGチェック構造体
 * T_Polygon **ret_poly : 床ポリゴンポインター]
 * int *pbg_actor_index : moveBG用のインデックス
 * xyz_t *pos : チェック位置
 *
 *--------------------------------------------------------------------------*/
extern float T_BGCheck_CameraGroundCheck_grpWG_ai(
    T_BGCheck *this,
    T_Polygon **ret_poly,
    int *pbg_actor_index,
    xyz_t *pos);

/*----------------------------------------------------------------------------
 *
 * 床方向チェック:チェックグループ壁
 * オブジェ当たり版
 *
 * 引数
 * T_BGCheck *this : BGチェック構造体
 * T_Polygon **ret_poly : 交差ポリゴンポインター
 * int *pbg_actor_index : moveBG用のインデックス
 * Actor *pself_actor : 自分自身のアクターポインター（自分自身に当てない）
 * xyz_t *pos : チェック位置
 *
 *--------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_grpW_aiac(
    T_BGCheck *this,
    T_Polygon **ret_poly,
    int *pbg_actor_index,
    Actor *pself_actor,
    xyz_t *pos);

/*--------------------------------------------------------------------------
 *
 * 床方向チェック:チェックグループ床／壁
 * Obj当たり版
 *
 * 引数:
 * T_BGCheck *this : BGチェック構造体
 * T_Polygon **ret_poly : 床ポリゴンポインター]
 * int *pbg_actor_index : moveBG用のインデックス
 * xyz_t *pos : チェック位置
 *
 *--------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_grpWG_ai(
    T_BGCheck *this,
    T_Polygon **ret_poly,
    int *pbg_actor_index,
    xyz_t *pos);

/*----------------------------------------------------------------------------
 *
 * OBJ用
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck(
    T_BGCheck *this, /* BGチェック構造体 */
    T_Polygon **ret_poly,  /* 領域は外部で確保 */
    xyz_t *pos); /* 判定位置 */

/*----------------------------------------------------------------------------
 *
 * OBJ用
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck2(
    Game_play *game_play,
    T_BGCheck *this, /* BGチェック構造体ポインター領域へのポインター */
    T_Polygon **ret_poly,
    xyz_t *pos); /* 判定位置 */
    
/*----------------------------------------------------------------------------
 *
 * OBJ用:アクターインデックス取得用
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_ai(
    T_BGCheck *this, /* BGチェック構造体ポインター領域へのポインター */
    T_Polygon **ret_poly,
    int *pbg_actor_index, /* アクターテーブル内のインデックス */
    xyz_t *pos); /* 判定位置 */

/*----------------------------------------------------------------------------
 *
 * OBJ用:アクターインデックス取得
 * 自分のアクターポインター指定
 *
 *--------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_aiac(
    T_BGCheck *this, /* BGチェック構造体ポインター領域へのポインター */
    T_Polygon **ret_poly,
    int *pbg_actor_index, /* ア クターテーブル内のインデックス */
    Actor *pself_actor, /* 自分自身のアクター */
    xyz_t *ppos); /* 判定位置 */


/*----------------------------------------------------------------------------
 *
 * OBJ用:アクターインデックス取得
 * 自分のアクターポインター指定
 * game_playのポインターつき
 *
 *--------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_aiac2(
    Game_play *game_play, 
    T_BGCheck *this, /* BGチェック構造体ポインター領域へのポインター */
    T_Polygon **ret_poly,
    int *pbg_actor_index, /* ア クターテーブル内のインデックス */
    Actor *pself_actor, /* 自分自身のアクター */
    xyz_t *ppos); /* 判定位置 */
    
/*----------------------------------------------------------------------------
 *
 * OBJ用:アクターインデックス取得
 * 隙間パラメータ指定
 *
 * 返り値:床高さ
 * 引数:
 * T_BGCheck *this: BGチェック構造体ポインター領域へのポインター
 * T_Polygon **ret_poly:床交差ポリゴン
 * int *pbg_actor_index:アクターインデックス
 * Actor *pself_actor:アクターポインター
 * xyz_t *ppos: 判定位置
 * float sukima_r:隙間パラメータ
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_aiac_skp(
    T_BGCheck *this,
    T_Polygon **ret_poly,
    int *pbg_actor_index,
    Actor *pself_actor,
    xyz_t *ppos,
    float sukima_r);

/*-----------------------------------------------------------------------------
 *
 * OBJ用:アクターインデックス取得
 * 自分のアクターポインター指定
 *
 * 対象グループ:壁／床
 *
 * 返り値:床高さ
 *
 * T_BGCheck *this:ｂｇチェック情報
 * T_Polygon **ret_poly:交差ポリゴン
 * int *pbg_actor_index:アクターインデックス
 * Actor *pself_actor:チェック対象アクター
 * xyz_t *pos:チェック位置
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_ObjGroundCheck_grpWG_aiac(
    T_BGCheck *this,
    T_Polygon **ret_poly,
    int *pbg_actor_index,
    Actor *pself_actor, 
    xyz_t *pos);

/*---------------------------------------------------------------------------
 *
 * 床チェック:OBJ/カメラ当たらないチェック無関係
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_GroundCheck(
    T_BGCheck* this,
    T_Polygon *ret_poly, /* 領域は外部で確保 */
    xyz_t *pos);

/*---------------------------------------------------------------------------
 *
 * 床チェック:OBJ/カメラ当たらないチェック無関係
 *           :アクターインデックス取得版
 *
 *---------------------------------------------------------------------------*/
extern float T_BGCheck_GroundCheck_ai(
    T_BGCheck *this,
    T_Polygon *ret_poly, /* 領域は外部で確保 */
    int *pbg_actor_index, /* BGアクターインデックス */
    xyz_t *pos);


/*============================================================================
 *
 * 壁チェック２
 *
 *==========================================================================*/
/*---------------------------------------------------------------------------
 *
 *  Obj用壁チェック
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_ObjWallCheck2(
    T_BGCheck *this,
    xyz_t *cl_pos,
    xyz_t *pos,
    xyz_t *old_pos,
    float radius,
    T_Polygon **ppoly,
    float check_h);

/*---------------------------------------------------------------------------
 *
 *  Obj用壁チェック:
 *  メモ：アクターインデックス取得版
 *  actor_index:DYNA_ACTOR_NUMの時はBGのポリゴンである。
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_ObjWallCheck2_ai(
    T_BGCheck *this,
    xyz_t *cl_pos,
    xyz_t *pos,
    xyz_t *old_pos,
    float radius,
    T_Polygon **ppoly,
    int *pbg_actor_index,
    float check_h);

/*---------------------------------------------------------------------------
 *
 *  Obj用壁チェック:
 *  メモ：アクターインデックス取得版
 *  自分自身に当らないバージョン
 *  actor_index:DYNA_ACTOR_NUMの時はBGのポリゴンである。
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_ObjWallCheck2_aiac(
    T_BGCheck *this,
    xyz_t *cl_pos,
    xyz_t *pos,
    xyz_t *old_pos,
    float radius,
    T_Polygon **ppoly,
    int *pbg_actor_index,
    Actor *pself_actor,
    float check_h);

/*---------------------------------------------------------------------------
 *
 *  Obj用壁チェック:
 *  メモ：アクターインデックス取得版
 *  自分自身に当らないバージョン
 *  actor_index:DYNA_ACTOR_NUMの時はBGのポリゴンである。
 *  ラインチェックなし版
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_ObjWallCheck2_aiac_nl(
    T_BGCheck *this,
    xyz_t *cl_pos,
    xyz_t *pos,
    xyz_t *old_pos,
    float radius,
    T_Polygon **ppoly,
    int *pbg_actor_index,
    Actor *pself_actor,
    float check_h);

/*============================================================================
 *
 * ある位置の天井チェック
 *
 *===========================================================================*/

/*---------------------------------------------------------------------------
 *
 * 天井チェック:OBJ,カメラ当たらないチェック無関係
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_RoofCheck(
    T_BGCheck *this,
    float *ry, 
    xyz_t *pos,
    float radius_y);

/*---------------------------------------------------------------------------
 *
 * 天井チェック:
 * OBJ用:ポリゴン,アクターインデックス取得版
 * 自分のアクターポインター指定版
 *
 * 引数:
 * T_BGCheck *this:
 * float *ry:返す高さ
 * xyz_t *pos:チェック位置
 * float radius:チェック距離
 * T_Polygon **ret_poly:ポリゴン情報絵のポインターのポインター
 * int *pbg_actor_index:actor indexを返す変数へのポインター
 * Actor *pself_actor:自分自身のアクターポインター
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_ObjRoofCheck_aiac(
    T_BGCheck *this,
    float *ry,
    xyz_t *pos,
    float radius, 
    T_Polygon **ret_poly,
    int *pbg_actor_index,
    Actor *pself_actor);

/*===========================================================================
 *
 * ラインチェック
 *
 *=========================================================================*/

/*
 * ラインチェック
 * 引数変化版
 */
extern int T_BGCheck_LineCheck_poly(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly, 
    int front_flag); /* 表面のみ (!= 0の時）*/

/*
 * ラインチェック
 * チェックするグループ指定
 */
extern int T_BGCheck_LineCheck_poly_chgrp(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag); /* 表面のみ (!= 0の時）*/

/*
 * ラインチェック
 * チェックするグループ指定
 * アクターインデックス対応版
 */
extern int T_BGCheck_LineCheck_poly_chgrp_ai(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index); /* アクターインデックスを返す */

/*---------------------------------------------------------------------------
 *
 * Camera用チェック:カメラ当たらないフラグが影響する
 *                 :アクターインデックス対応版
 * メモ：*pbg_actor_index == DYNA_ACTOR_NUMの時BGと当っている。
 *
 *--------------------------------------------------------------------------*/
/*
 * ラインチェック
 * チェックするグループ指定
 */
extern int T_BGCheck_CameraLineCheck_poly_chgrp_ai(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index); /* アクターインデックスを返す */

/*---------------------------------------------------------------------------
 *
 * Camera用チェック:カメラ当たらないフラグが影響する
 *                 :アクターインデックス対応版
 * メモ：*pbg_actor_index == DYNA_ACTOR_NUMの時BGと当っている。
 * カメラ当らないチェックのポリゴンのみチェックする。
 *                                 ^^^^
 *--------------------------------------------------------------------------*/
/*
 * ラインチェック
 * チェックするグループ指定
 */
extern int T_BGCheck_CameraLineCheck_polyThrough_chgrp_ai(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index); /* アクターインデックスを返す */

/*---------------------------------------------------------------------------
 *
 * Obj用チェック:Obj当たらないフラグが影響する
 *              :アクターインデックス対応版
 * メモ：*pbg_actor_index == DYNA_ACTOR_NUMの時,BGと当っている。
 *
 *--------------------------------------------------------------------------*/
/*
 * ラインチェック
 * チェックするグループ指定
 */
extern int T_BGCheck_ObjLineCheck_poly_chgrp_ai(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index); /* アクターテーブルへのインデックスを返す */

/*---------------------------------------------------------------------------
 *
 * Obj用チェック:Obj当たらないフラグが影響する
 *              :アクターインデックス対応版
 * メモ：*pbg_actor_index == DYNA_ACTOR_NUMの時,BGと当っている。
 *
 *--------------------------------------------------------------------------*/
/*
 * ラインチェック
 * チェックするグループ指定
 */
extern int T_BGCheck_ObjLineCheck_poly_chgrp_aiac(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index, /* アクターテーブルへのインデックスを返す */
    Actor *pself_actor); /* 自分自身のアクターポインター */

/*---------------------------------------------------------------------------
 *
 * Obj用チェック:Obj当たらないフラグが影響する
 *              :アクターインデックス対応版
 *              :隙間パラメータ
 * メモ：*pbg_actor_index == DYNA_ACTOR_NUMの時,BGと当っている。
 * 返り値:交差の有無
 * 引数:
 * T_BGCheck* this:BGチェック構造体
 * xyz_t* psp: スタート
 * xyz_t* pep: エンド
 * xyz_t* p_near_cross:スタートに近い点
 * T_Polygon **ppret_poly:スタートに近い交差ポリゴンのポインターへのポインター
 * int wall_flag:壁フラッグ
 * int ground_flag:床フラッグ
 * int roof_flag:天井フラッグ
 * int front_flag: 表面のみ (!= 0の時）
 * int *pbg_actor_index: アクターテーブルへのインデックスを返す
 * Actor *pself_actor: 自分自身のアクターポインター
 * float sukima_r: 隙間パラメータ
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_ObjLineCheck_poly_chgrp_aiac_skp(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index, /* アクターテーブルへのインデックスを返す */
    Actor *pself_actor, /* 自分自身のアクターポインター */
    float sukima_r);

/*---------------------------------------------------------------------------
 *
 * Arrow用チェック:Arrow当たらないフラグが影響する
 *                :アクターインデックス対応版
 * メモ：*pbg_actor_index == DYNA_ACTOR_NUMの時,BGと当っている。
 *
 *--------------------------------------------------------------------------*/
/*
 * ラインチェック
 * チェックするグループ指定
 */
extern int T_BGCheck_ArrowLineCheck_poly_chgrp_ai(
    T_BGCheck* this,
    xyz_t* psp, /* スタート */
    xyz_t* pep, /* エンド */
    xyz_t* p_near_cross, /* スタートに近い点 */
    /* スタートに近い交差ポリゴンのポインターへのポインター */
    T_Polygon **ppret_poly,
    int wall_flag, /* 壁フラッグ */
    int ground_flag, /* 床フラッグ */
    int roof_flag, /* 天井フラッグ */
    int front_flag, /* 表面のみ (!= 0の時）*/
    int *pbg_actor_index); /* アクターテーブルへのインデックスを返す */

/*---------------------------------------------------------------------------
 *
 * シンプルＢＧチェック
 *
 * 簡易引数版
 *
 * 引数：
 * T_BGCheck *this: ＢＧチェック構造体
 * xyz_t *pos : チェック球中心
 * float r: チェック球半径r
 *
 * メモ：
 * チェック球に接触/包含されるBGのポリゴンがあればTRUE／無ければFALSEを返す。
 * 現在,rが５０を越えていると、うまくポリゴンがとれない場合が、あるが、対応
 * する予定。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_SimpleCheck(
    T_BGCheck *this,
    xyz_t *pos,
    float r);

/*----------------------------------------------------------------------------
 *
 * シンプルＢＧチェック
 * 壁チェックのみ版
 *
 *  引数：
 * T_BGCheck *this: ＢＧチェック構造体
 * xyz_t *pos : チェック球中心
 * float r: チェック球半径r
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_SimpleCheck_Wall(
    T_BGCheck *this,
    xyz_t *pos,
    float r);

/*----------------------------------------------------------------------------
 *
 * short_SLIST_NODE 確保
 *
 *--------------------------------------------------------------------------*/
extern short_SLIST_NODE *T_BGCheckAlloc_getShortSlistNode(
    BGCheckAlloc *this);

/*----------------------------------------------------------------------------
 *
 * short_SLIST_NODE インデックス確保
 *
 *--------------------------------------------------------------------------*/
extern unsigned short T_BGCheckAlloc_getShortSlistNode_index(
    BGCheckAlloc *this);

/*============================================================================
 *
 * ダイナミックポリゴン
 *
 *==========================================================================*/

/*---------------------------------------------------------------------------
 *
 * short_SLIST_NODE クリーンアップ
 *
 *-------------------------------------------------------------------------*/
extern void T_BGCheckAlloc_cleanUp(BGCheckAlloc *this);


/*----------------------------------------------------------------------------
 *
 * short_SLIST_NODE ダイナミックポリゴン:インデックス確保
 *
 *--------------------------------------------------------------------------*/
extern unsigned short T_BGCheckAlloc_getShortSlistNode_indexDynamic(
    BGCheckAlloc *this);
/*============================================================================
 *
 * ダイナミックポリゴン各処理部分
 *
 *==========================================================================*/
/*---------------------------------------------------------------------------
 *
 * moveBGか？
 *
 *-------------------------------------------------------------------------*/
extern int DynaPolyInfo_checkMoveBG(int bg_actor_index);

/*---------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:アクター登録    
 *   
 * pbgdataは,ROMデータの場合,SEGMENT_TO_KSEG0しておいてください、中身も含む。
 * 手作りのポリゴンデータの場合もあるため。
 *
 *-------------------------------------------------------------------------*/
extern int DynaPolyInfo_setActor(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info, 
    Actor *actor, /* MoveBGアクターへのポインタ */
    T_BGDataInfo *pbgdata); /* 形状データ */

/*---------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:アクターインデックスからポインターに変換
 *
 *--------------------------------------------------------------------------*/
extern Actor *DynaPolyInfo_actor_index2pointer(
    T_BGCheck *pbgcheck,
    int bg_actor_index);

/*---------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:通過ビットセット
 * このビットをセットするとデータは残っていますが,当りからは外されます。
 *
 *--------------------------------------------------------------------------*/
extern void DynaPolygonInfo_setThrough(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info,
    int bg_actor_index);

/*---------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:通過ビットクリア
 * このビットをセットするとデータは残っていますが,当りからは外されます。
 *
 *--------------------------------------------------------------------------*/
extern void DynaPolygonInfo_clearThrough(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:天井 off
 * ポリゴン一枚一枚の登録をやめます。
 *
 *---------------------------------------------------------------------------*/
extern void DynaPolygonInfo_setRoofOff(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:天井 off
 * ポリゴン一枚一枚の登録を再開します。
 *
 *---------------------------------------------------------------------------*/
extern void DynaPolygonInfo_clearRoofOff(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:登録削除予約
 *
 *--------------------------------------------------------------------------*/
extern void DynaPolyInfo_delReserve(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info,
    int del_index); /* 削除するアクターインデックス */

/*----------------------------------------------------------------------------
 *
 * ダイナミック ポリゴン展開セット
 * SRTをいじらなくてもmoveBGを展開します。
 * pdyna_poly_info => &game_play->BGCheck.dyna_poly_info
 *
 *---------------------------------------------------------------------------*/
extern void DynaPolygonInfo_setExpand(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info);

/*--------------------------------------------------------------------------
 *
 * ステータス情報クリア
 *
 *------------------------------------------------------------------------*/
extern void DynaPolyInfo_statusClear(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info,
    Actor *actor);

/*-----------------------------------------------------------------------------
 *
 * データセットアップ
 *
 *---------------------------------------------------------------------------*/
extern void DynaPolyInfo_setup(
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info);
    
/*--------------------------------------------------------------------------
 *
 * ダイナミックポリゴン動作終了処理
 *
 *------------------------------------------------------------------------*/
extern void DynaPolyInfo_cleanUp(  
    Game *game,
    Dyna_Poly_Info *pdyna_poly_info);
/*============================================================================
 *
 * ダイナミックポリゴンユーティリティー
 *
 *==========================================================================*/
/*----------------------------------------------------------------------------
 *
 * T_BGDataInfo内容をSEGMENT_TO_KSEG0する。
 * メモ：たぶんデータの方も書き変っている。
 *
 *---------------------------------------------------------------------------*/
extern void DynaPolyUty_bgdi_SG2KSG(
    T_BGDataInfo *pbgdata_from, /* データ元 */
    /* キャストされた内容:引数はポインター（領域無し） */
    T_BGDataInfo **ppbgdata_to);

/*----------------------------------------------------------------------------
 *
 * BGデータポインタ再設定
 *
 * セレクト画面後などデータが再設定されるときに,T_BGDataInfoの内容が書き変る
 * ため,再び書き直す。
 * 総てのT_BGDataInfo内容をSEGMENT_TO_KSEG0する。
 * メモ：たぶんデータの方も書き変っている。
 *
 *---------------------------------------------------------------------------*/
extern void DynaPolyInfo_resetBGDataInfo(
    T_BGCheck *pbgcheck,
    Game_play *game_play);

/*============================================================================
 *
 * ポリゴン情報関連
 *
 *==========================================================================*/


/*----------------------------------------------------------------------------
 *
 * カメラセットを取得
 * アクターインデックス版
 * メモ：ポリゴン情報テーブルがNULLの時は０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getCameraSet_ai(
    T_BGCheck *this,
    T_Polygon *ppoly, /* カメラ セットを得るポリゴンへのポインター */
    int bg_actor_index); /* そのポリゴンを持っているアクターインデックス */
/*----------------------------------------------------------------------------
 *
 * Indexからカメラタイプを取得
 * アクターインデックス版
 * メモ：カメラデータがNULLの場合,0を返す。
 *
 *-------------------------------------------------------------------------*/
extern unsigned short T_BGCheck_getCameraType_index_ai(
    T_BGCheck *this,
    int index,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * カメラのタイプを取得
 * アクターインデックス版
 * メモ：カメラデータ／ポリゴン情報がどちらががNULLの場合,0を返す。
 *
 *---------------------------------------------------------------------------*/
extern unsigned short T_BGCheck_getCameraType_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*--------------------------------------------------------------------------
 *
 * indexからカメラのs_xyzデータの個数を得る
 * アクターインデックス版
 * メモ；カメラデータテーブルがNULLの場合,０を返す。
 *
 *-------------------------------------------------------------------------*/
extern unsigned short T_BGCheck_getCameraDataNum_index_ai(
    T_BGCheck *this,
    int index,
    int bg_actor_index);


/*---------------------------------------------------------------------------
 *
 * カメラのs_xyzのデータの個数を得る
 * アクターインデックス版
 * メモ：カメラデータ／ポリゴン情報がどちらががNULLの場合,0を返す。
 *
 *--------------------------------------------------------------------------*/
extern unsigned short T_BGCheck_getCameraDataNum_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);


/*----------------------------------------------------------------------------
 *
 * indexからカメラのs_xyzのデータへのポインターを返す。
 * アクターインデックス版
 * もし、カメラデータテーブルがNULLの場合,NULLを返す。
 *
 *---------------------------------------------------------------------------*/
extern s_xyz *T_BGCheck_getCameraPos_index_ai(
    T_BGCheck *this,
    int index,
    int bg_actor_index);

/*---------------------------------------------------------------------------
 *
 * カメラのs_xyzのデータへのポインターを返す。
 * アクターインデックス版
 * メモ：カメラデータ/ポリゴンテーブル情報がNULLの場合,NULLを返す。
 *
 *--------------------------------------------------------------------------*/
extern s_xyz *T_BGCheck_getCameraPos_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * シーン切り替えコード
 * アクターインデックス版
 * メモ：もし、poly_info_tblがNULLのばあい、０を返す。
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_getSceneChangeCode_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);



/*----------------------------------------------------------------------------
 *
 * 属性
 * アクターインデックス版
 * もし、ポリゴン情報テーブルがNULLのばあい、０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getAttributeCode_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);


/*----------------------------------------------------------------------------
 *
 * 床上げビット
 *
 * メモ：ポリゴン情報がNULLなら,０を返る
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_getGroundUpBit_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);
 
/*----------------------------------------------------------------------------
 *
 * 馬侵入禁止
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_getHorseKeepOutBit_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*-----------------------------------------------------------------------------
 *
 * 地面指定ラベル
 * ポリゴンの属性からサウンド地面指定ラベルを得る。
 *
 *---------------------------------------------------------------------------*/
extern u16 T_BGCheck_getSoundGroundLabel(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);



/*-----------------------------------------------------------------------------
 *
 * 天井コードを得る
 * アクターインデックス版
 * メモ：ポリゴン情報テーブルがNULLのばあい,０を返す。
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_getRoofCode_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*===========================================================================
 *
 * 壁コード
 *
 *===========================================================================*/



/* 以下ポリゴン情報がNULLの場合,まともに情報を返さない */
/*--------------------------------------------------------------------------
 *
 * 壁コードを得る
 * アクターインデックス版
 * もし、ポリゴン情報がNULLの場合,０を返す。
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_getWallCode_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*--------------------------------------------------------------------------
 *
 * 壁コードビットを得る
 * アクターインデックス版
 *
 *-------------------------------------------------------------------------*/
extern unsigned int T_BGCheck_getWallCodeBit_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*--------------------------------------------------------------------------
 *
 * 登れない壁か？
 * アクターインデックス版
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_WallNotClib_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);


/*-----------------------------------------------------------------------------
 *
 * 梯子か？
 * アクターインデックス版
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_WallLadder_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);


/*--------------------------------------------------------------------------
 *
 * 梯子UPか？
 * アクターインデックス版
 *
 *-------------------------------------------------------------------------*/
extern int T_BGCheck_WallLadderUp_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*==========================================================================
 *
 * 床コード
 *
 *=========================================================================*/

/*---------------------------------------------------------------------------
 *
 * 床コードを得る
 * アクターインデックス版
 * メモ：ポリゴン情報がNULLの場合、０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getGroundCode_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);


/*----------------------------------------------------------------------------
 *
 * オートジャンプタイプ
 * アクターインデックス版
 * メモ：polygon_info_tblがNULLの場合、０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_GroundAutoJumpType_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * サウンド
 * アクターインデックス版
 * メモ：ポリゴン情報がNULLなら、０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getTypeSoundCode_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * 摩擦
 * アクターインデックス版
 * メモ：ポリゴン情報がNULLの場合,０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getFriction_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * 環境
 * アクターインデックス版
 * メモ：ポリゴン情報がNULLの場合,０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getKankyo_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);
/*----------------------------------------------------------------------------
 *
 * ２面で出来る交線と直線との位置関係
 *
 *---------------------------------------------------------------------------*/
#ifdef DEBUG_BG_2PLANELINE_LINENEARPOS
extern void T_BGCheckUty_2PlaneLine_LineNearPos(Game *game);
#endif

/*----------------------------------------------------------------------------
 *
 * BGチェックユーティリティー
 *
 *---------------------------------------------------------------------------*/
extern void T_BGCheckUty_line_check(Game *game);
   
/*--------------------------------------------------------------------------
 *
 * Obj系当らないコードをチェック
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_CheckObjNoHit(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*--------------------------------------------------------------------------
 *
 * Arrow系当らないコード
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_CheckArrowNoHit(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index); /* 使わない */

/*----------------------------------------------------------------------------
 *
 * エコーレベル
 * アクターインデックス版
 * メモ：ポリゴン情報がNULLの場合,０を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getEcho_ai(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*----------------------------------------------------------------------------
 *
 * フックショット刺さるコード
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_checkHookShotStick(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);


/*--------------------------------------------------------------------------
 *
 * ベルトコンベアかどうか？
 * メモ:水流/ベルト パワーインデックス が０の時無効
 *      返り値 TRUE ベルトコンベア
 *             FALSE 水 （or 何もなし)
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_checkBelt(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*---------------------------------------------------------------------------
 *
 * 水流/ベルト パワーインデックス
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getSlidePowerIndex(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*---------------------------------------------------------------------------
 *
 * 角度インデックス
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_getSlideAngle(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);
/*---------------------------------------------------------------------------
 *
 * ダメージビット
 *
 * T_BGCheck *this:BGチェック情報
 * T_Polygon *ppoly:ポリゴン情報
 * int bg_actor_index:アクターインデックス
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_CheckDamagePoly(
    T_BGCheck *this,
    T_Polygon *ppoly,
    int bg_actor_index);

/*============================================================================
 *
 * 水処理（WaterInfo版)
 *
 *===========================================================================*/

/*----------------------------------------------------------------------------
 *
 * 水面高さチェック
 *
 * 返り値:そのxz位置における水面の有無
 * 
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_WaterSurfaceCheck(
    T_BGCheck *this, float x, float z,
    float *pheight, /* 高さ */
    Water_Info **pwater); /* ポインターのポインター */

/*----------------------------------------------------------------------------
 *
 * 水面高さチェック2
 *
 * 部屋番号チェックバージョン
 *
 * 返り値:そのxz位置における水面情報の有無(TRUEの時その場所のしたに水あり）
 * 
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_WaterSurfaceCheck2(
    Game_play *game_play, /* ゲームポインター:追加 */
    T_BGCheck *this, float x, float z,
    float *pheight, /* 高さ:床より低いときは無視？ */
    Water_Info **pwater); /* ポインターのポインター */

/*----------------------------------------------------------------------------
 *
 * 水面高さチェック３:水ポリゴン取得処理(Spot07対策）
 *
 * Spot07水ポリゴンのための特殊処理版
 *
 * Spot07の時のみ滝の上の水のポリゴンのためにyをチェックします。それ以外の
 * 時はT_BGCheck_WaterSurfaceCheck2()と同じにします。
 * yのチェック位置は*pheightに初期値として入れてください。
 * （水ポリゴンがあると変化します。）
 *
 * 引数:
 * float *pheight:チェックする高さを初期値としていれてください。（前との違い)
 * （しかし、Spot07でしか使いません）
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_WaterSurfaceCheck3(
    Game_play * game_play,
    T_BGCheck *this,
    float x,
    float z,
    float *pheight,
    Water_Info **pwater);

/*-----------------------------------------------------------------------------
 *
 * カメラセットを取得
 * Water_Info版
 * メモ：カメラデータがNULLの場合は-1を返す。
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_WaterGetCameraSet(
    T_BGCheck *this,
    Water_Info *pwater);

/*-----------------------------------------------------------------------------
 *
 * カメラタイプを取得
 * WaterInfo版
 *
 *---------------------------------------------------------------------------*/
extern unsigned short T_BGCheck_WaterGetCameraType(
    T_BGCheck *this,
    Water_Info *pwater);

/*-----------------------------------------------------------------------------
 *
 * 環境コードを得る
 * Water_Info版
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_WaterGetKankyo(
    T_BGCheck *this,
    Water_Info *pwater);

/*-----------------------------------------------------------------------------
 *
 * 水面ポリゴンチェック
 * 処理内容:ある位置の近く（y＝＋─y_range)の水ポリゴンインデッ
 * クスを取得する。
 * もし、範囲内に水面が存在しない場合,-1を返す。
 *
 * 返り値:水ポリゴンインデックス
 * 引数:Game_play *game_play:ゲームプレイ
 *      T_BGCheck *this:bgチェック構造体
 *      xyz_t *pos:チェック位置
 *      float y_range:チェックｙ範囲
 *      Water_Info **pwater:見つかった水ポリゴンへのポインター（もし、
 *      見つからなかった場合NULLが入る）が入る、ポインターへのポインター
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_WaterGetIndex(
    Game_play *game_play,
    T_BGCheck *this,
    xyz_t *pos,
    float y_range,
    Water_Info **pwater);

/*===========================================================================
 *
 * 環境ポリゴン（WaterInfo版)
 *
 *==========================================================================*/
/*---------------------------------------------------------------------------
 *
 * 水情報で環境ポリゴンかどうか？
 * メモ：ゼロ以外で水情報環境ポリゴン
 * 引数:水情報ポリゴンへのポインター
 *
 *--------------------------------------------------------------------------*/
#define BG_WI_checkKankyo(pwi) ((pwi)->info & (1<<19))

/*----------------------------------------------------------------------------
 *
 * 水情報環境ポリゴン高さチェック2:環境ポリゴン取得処理
 *
 * 部屋番号チェックバージョン
 *
 * 返り値:そのxz位置におけるWater_Info環境ポリゴンの有無
 * (TRUEの時その場所のしたにポリゴンあり）
 *
 *---------------------------------------------------------------------------*/
extern int T_BGCheck_WaterKankyoSurfaceCheck2(
    Game_play *game_play,
    T_BGCheck *this, float x, float z,
    float *pheight, /* 高さ:床より低いときは無視？ */
    Water_Info **pwater); /* ポインターのポインター */
    
/*============================================================================
 *
 * moveBGデバッグ表示
 *
 *==========================================================================*/
extern void T_BGCheck_DebugMoveBGDisp(
    Game *game,
    T_BGCheck *pbgcheck); /* BGチェック情報 */
/*=============================================================================
 *
 * 背景チェック表示
 *
 *===========================================================================*/
extern void T_BGCheck_DebugBGDisp(
    Game *game,
    T_BGCheck *pbgcheck); /* BGチェック情報 */

/*============================================================================
 *
 * Utility
 *
 *==========================================================================*/

/*--------------------------------------------------------------------------
 *
 * ある２枚の無限平面の交線とある点から垂線を下ろした時に交差する点を
 * 求める。
 *
 * 返り値:交点がある（２つの面の交線ある）
 * 引数:
 * T_Polygon *pp1, *pp2 : ２つの面へのポインター
 * xyz_t *pcheck_pos : チェック位置
 * xyz_t *pcross_pos : 求める交点
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_2PlaneLinePosNearPos(
    T_Polygon *pp1,
    T_Polygon *pp2,
    xyz_t *pcheck_pos,
    xyz_t *pcross_pos);


/*--------------------------------------------------------------------------
 *
 * ある２枚の無限平面の交線とある直線との一番近い点
 *
 * 返り値:交点がある（２つの面の交線ある）
 * 引数:
 * T_Polygon *pp1, *pp2 : ２つの面へのポインター
 * xyz_t *pl1p1, xyz_t *pl1p2: ある直線上の２点
 * xyz_t *pcross_pos : 求める交点
 *
 *--------------------------------------------------------------------------*/
extern int T_BGCheck_2PlaneLine_LineNearPos(
    T_Polygon *pp1, T_Polygon *pp2,
    xyz_t *pl2p1, xyz_t *pl2p2,
    xyz_t *pnear_pos);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** bgcheck.h ***/
