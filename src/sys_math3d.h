/* $Id: sys_math3d.h,v 2.1 1998/10/22 11:41:56 zelda Exp $ */
/*============================================================================
 *
 * $Log: sys_math3d.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.65  1998/10/07 03:04:07  matutani
 * *** empty log message ***
 *
 * Revision 1.64  1998-10-07 00:38:39+09  matutani
 * *** empty log message ***
 *
 * Revision 1.63  1998-10-06 15:16:56+09  matutani
 * *** empty log message ***
 *
 * Revision 1.62  1998-10-05 22:23:26+09  matutani
 *  壁を床チェックにいれた影響を考慮して訂正
 *
 * Revision 1.61  1998-10-01 18:24:49+09  matutani
 * short版０に近いチェック(1.0を32767)
 *
 * Revision 1.60  1998-09-29 22:00:04+09  matutani
 * *** empty log message ***
 *
 * Revision 1.59  1998-09-28 20:58:12+09  matutani
 * *** empty log message ***
 *
 * Revision 1.58  1998-09-28 13:10:26+09  matutani
 * *** empty log message ***
 *
 * Revision 1.57  1998-09-26 22:58:12+09  matutani
 * *** empty log message ***
 *
 * Revision 1.56  1998-09-22 22:00:20+09  matutani
 * *** empty log message ***
 *
 * Revision 1.55  1998-09-08 23:25:06+09  matutani
 * M3D_getCos2()追加
 *
 * Revision 1.54  1998-09-05 23:00:19+09  matutani
 * *** empty log message ***
 *
 * Revision 1.53  1998-08-20 23:18:06+09  matutani
 * *** empty log message ***
 *
 * Revision 1.52  1998-07-01 21:22:49+09  matutani
 * 内分点計算
 *
 * Revision 1.51  1998-06-30 22:13:21+09  matutani
 * 調整
 *
 * Revision 1.50  1998-06-25 21:45:02+09  matutani
 * Bounding Box用構造体
 *
 * Revision 1.49  1998-06-24 22:19:31+09  matutani
 * *** empty log message ***
 *
 * Revision 1.48  1998-06-12 19:31:16+09  matutani
 * ２枚の無限平面で出来る交線(line1)とある直線(line2)とで出来る近接する２点
 *
 * Revision 1.47  1998-06-11 16:16:13+09  matutani
 * Macro_IS_EQ2追加
 *
 * Revision 1.46  1998-06-09 13:44:20+09  matutani
 * 各チェック用隙間パラメータ追加
 *
 * Revision 1.45  1998-06-06 17:02:02+09  matutani
 * ある２枚の無限平面の交線とある点から垂線を下ろした時に交差する点を
 * 求める。
 *
 * Revision 1.44  1998-06-01 19:04:07+09  matutani
 * 整理
 *
 * Revision 1.43  1998-06-01 17:54:54+09  matutani
 * バージョンキャンセル
 *
 * Revision 1.42  1998-05-30 22:34:31+09  matutani
 * ベクトルサイズ計算
 *
 * Revision 1.41  1998-05-30 20:04:08+09  matutani
 * Math3D_pointVsLineSegmentLength2D()をstaticからexternに変更
 *
 * Revision 1.40  1998-05-27 18:11:41+09  matutani
 * *** empty log message ***  
 *
 * Revision 1.39  1998-05-26 18:18:11+09  matutani
 * 交点計算なしMath3DTrianglePFCross版
 *
 * Revision 1.38  1998-05-14 22:33:05+09  matutani
 * *** empty log message ***
 *
 * Revision 1.37  1998-05-07 16:01:42+09  matutani
 * *** empty log message ***
 *
 * Revision 1.36  1998-04-24 17:51:40+09  matutani
 * *** empty log message ***
 *
 * Revision 1.35  1998-04-23 22:37:03+09  matutani
 * *** empty log message ***
 *
 * Revision 1.34  1998-04-14 11:03:22+09  matutani
 * *** empty log message ***
 *
 * Revision 1.33  1998-04-14 12:03:01+10  matutani
 * ある面に入射するベクトルの反射ベクトルを計算
 *
 * Revision 1.32  1998-04-04 23:06:02+09  matutani
 * *** empty log message ***
 *
 * Revision 1.31  1998/03/17  12:24:38  hayakawa
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.30  1998/03/09  13:36:59  matutani
 * 無限平面と無限直線の交差
 *
 * Revision 1.29  1998/02/25  03:10:45  matutani
 * *** empty log message ***
 *
 * Revision 1.28  1998/02/11  09:07:40  matutani
 * メモリ減らし
 *
 * Revision 1.27  1997/11/16  14:09:33  matutani
 * moveBG処理減らし
 *
 * Revision 1.26  1997/11/15  05:41:10  matutani
 * スペルミス
 *
 * Revision 1.25  1997/11/10  06:42:16  matutani
 * ちょっと修正
 *
 * Revision 1.24  1997/11/06  06:54:17  matutani
 * *** empty log message ***
 *
 * Revision 1.23  1997/11/01  11:50:22  matutani
 * 関数追加
 *
 * Revision 1.22  1997/10/29  14:01:20  matutani
 * *** empty log message ***
 *
 * Revision 1.21  1997/10/23  05:56:23  matutani
 * 無限平面と線分との交点
 * Math3DCheckPlaneCrossLine_xyz_t_cp()を追加（抽出）
 *
 * Revision 1.20  1997/10/22  05:11:44  matutani
 * *** empty log message ***
 *
 * Revision 1.19  1997/10/16  09:23:06  matutani
 * *** empty log message ***
 *
 * Revision 1.18  1997/10/14  06:00:55  matutani
 * 打ち込み終了
 *
 * Revision 1.17  1997/10/10  13:01:12  matutani
 * NewCollisionCheck 制作中
 *
 * Revision 1.16  1997/10/08  02:07:16  matutani
 * 円筒
 *
 * Revision 1.15  1997/10/01  05:25:36  matutani
 * *** empty log message ***
 *
 * Revision 1.14  1997/09/19  14:01:28  matutani
 *  Math3DTrianglePFCross*追加
 *
 * Revision 1.13  1997/08/28  00:42:27  matutani
 * 面と点の距離関係符合付き
 *
 * Revision 1.12  1997/08/05  08:54:55  matutani
 * *** empty log message ***
 *
 * Revision 1.11  1997/06/19  02:22:38  matutani
 * パラメータ変更
 *
 * Revision 1.10  1997/05/26  13:08:02  matutani
 * 整理
 *
 * Revision 1.9  1997/05/26  04:27:35  matutani
 * チェック高速化／確認
 *
 * Revision 1.8  1997/05/21  05:38:52  matutani
 * 高速化テスト
 *
 * Revision 1.7  1997/04/09  09:50:11  matutani
 * ｙ軸に平行な直線と三角形の交差判定
 *
 * Revision 1.6  1996/11/11  08:34:12  matutani
 * BGチェック調整
 *
 * Revision 1.5  1996/10/23  13:43:49  matutani
 * *** empty log message ***
 *
 * Revision 1.4  1996/09/24  08:16:05  matutani
 * *** empty log message ***
 *
 * Revision 1.3  1996/09/24  06:55:13  matutani
 * *** empty log message ***
 *
 *===========================================================================*/
/*-----------------------------------------------------------------------------
 *
 * sys_math3d.h
 *
 * ３Ｄ処理用関数
 *
 * 1996/08/22
 * Kenji Matsutani
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_SYS_MATH3D_H
#define INCLUDE_SYS_MATH3D_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


/*---------------------------------------------------------------------------
 *
 * C Version
 *
 *--------------------------------------------------------------------------*/


/* xyz_t用include ファイル */
#include<ultratypes.h>
#include<mbi.h>
#include<u64types.h>	/* ウルトラ ６４ ＳＲＤ マクロ */
#include"z_types.h" /* for s_xyz */

/*=========================================================================
 *
 * 構造体型宣言
 *
 *========================================================================*/
/*-------------------------------------------------------------------------
 *
 * 直線構造体
 *
 *------------------------------------------------------------------------*/
typedef struct math3d_line {
    xyz_t pos; /* 直線が通過する点（ライン上の点） */
    xyz_t vec; /* 直線の方向ベクトル */
} Math3D_line;

/*------------------------------------------------------------------------
 *
 * 線分構造体
 *
 *----------------------------------------------------------------------*/
typedef struct math3d_line_segment {
    /* 端点 */
    xyz_t p1; /* 始点終点が存在するならこちらが始点 */
    xyz_t p2;
} Math3D_lineSegment;

/*-------------------------------------------------------------------------
 *
 * 球構造体
 *
 *-----------------------------------------------------------------------*/
typedef struct math3d_sphere {
    s_xyz c; /* 中心 */
    short r; /* 半径 */
} Math3D_sphere;


/*-------------------------------------------------------------------------
 *
 * 球構造体
 *
 *-----------------------------------------------------------------------*/
typedef struct math3d_spheref {
    xyz_t c; /* 中心 */
    float r; /* 半径 */
} Math3D_sphereF;

/*-------------------------------------------------------------------------
 *
 * 浮動小数点 平面パラメータ
 * ax+by+cz+d = 0
 *
 *------------------------------------------------------------------------*/
typedef struct t_polygonf {
    float fa;
    float fb;
    float fc;
    float fd;
} T_PolygonF;

/*---------------------------------------------------------------------------
 *
 * 三角形構造体(コンストラクター（初期設定関数あり））
 *
 *--------------------------------------------------------------------------*/
typedef struct math3d_triangle {
    xyz_t p[3];
    T_PolygonF plane; /* 平面パラメータ */
} Math3D_triangle;

/*--------------------------------------------------------------------------
 *
 * 円筒
 *
 *-------------------------------------------------------------------------*/
typedef struct math3d_pipe {
    short r; /* 半径 */
    short h; /* 高さ:常に正 */
    short offset; /* オフセット */
    s_xyz c; /* 位置 */
} Math3D_pipe;

/*--------------------------------------------------------------------------
 *
 * 円筒浮動小数点版
 *
 *-------------------------------------------------------------------------*/
typedef struct math3d_pipef {
    float r; /* 半径 */
    float h; /* 高さ:常に正 */
    float offset; /* オフセット */
    xyz_t c; /* 位置 */
} Math3D_pipeF;

/*--------------------------------------------------------------------------
 *
 * 各軸方向min-max包含ボックス
 *
 *-------------------------------------------------------------------------*/
typedef struct math3d_bounding_box {
    xyz_t min, max;
} Math3D_BB;

/*==========================================================================
 *
 * Utility
 *
 *=========================================================================*/
/*=========================================================================
 *
 * Math3D_BB(Bounding Box）:ユーティリティ
 *
 *=========================================================================*/
extern int Math3D_BBSetPos(
    Math3D_BB *bb,
    xyz_t *pos);

/*==========================================================================
 *
 * ２枚の無限平面で出来る交線(line1)とある直線(line2)とで出来る近接する２点
 *
 * 引数:
 * float fa1, float fb1, float fc1, float fd1: 面１
 * float fa2, float fb2, float fc2, float fd2: 面２
 * xyz_t *pl2p1, xyz_t *pl2p2:line2
 * xyz_t *pnear_pos: line1上の近接点
 *
 *=========================================================================*/
extern int Math3D_2PlaneLine_LineNearPos(
    float fa1, float fb1, float fc1, float fd1, 
    float fa2, float fb2, float fc2, float fd2,
    xyz_t *pl2p1, xyz_t *pl2p2,
    xyz_t *pnear_pos);

/*==========================================================================
 *
 * ２本の直線上のもっとも近い２点を求める。
 *
 * メモ:
 * ２直線が平行な場合求まらない。
 *
 *==========================================================================*/
extern int Math3D_2LineNear2Pos(
    xyz_t *pl1p1, xyz_t *pl1p2,
    xyz_t *pl2p1, xyz_t *pl2p2,
    xyz_t *pl1_near, xyz_t *pl2_near);

/*===========================================================================
 *
 * 点からある直線（端点無し）へ下ろした垂線との交点を求める
 *
 * 引数:
 * Math3D_line *pline:直線構造体（ベクトルが０ではassertエラー)
 * xyz_t *pos:チェック位置
 * cross *cross:垂線との交点
 *
 * 似ている関数が増えてきたので整理が必要！！
 *
 *==========================================================================*/
extern void Math3D_lineVsPosSuisenCross(
    Math3D_line *pline,
    xyz_t *pos,
    xyz_t *cross);

/*--------------------------------------------------------------------------
 *
 * ある２枚の無限平面の交線を求める。
 *
 *  返り値:２つの面の交線がある。
 *
 *-------------------------------------------------------------------------*/
extern int Math3D2PlaneCrossLine(
    float fa1, float fb1, float fc1, float fd1, /* 面１ */
    float fa2, float fb2, float fc2, float fd2, /* 面２ */
    Math3D_line *pp2cl);

/*--------------------------------------------------------------------------
 *
 * 内分点計算(2)
 * ある位置s(x,y,z)から終点e(x,y,z)の線上をある比で別ける点p(x,y,z)
 *
 *-------------------------------------------------------------------------*/
extern void Math3DInDivPos2(
    xyz_t *ps, xyz_t *pe, float ratio, xyz_t *p);
   
/*--------------------------------------------------------------------------
 *
 * ある２枚の無限平面の交線とある点から垂線を下ろした時に交差する点を
 * 求める。
 *
 * 返り値:交点がある（２つの面の交線ある）
 *
 *--------------------------------------------------------------------------*/
extern int  Math3D2PlaneLinePosNearPos(
    float fa1, float fb1, float fc1, float fd1, /* 面１ */
    float fa2, float fb2, float fc2, float fd2, /* 面２ */
    xyz_t *pcheck_pos, /* チェック位置 */
    xyz_t *pcross_pos); /* 求める交点 */
    
/*---------------------------------------------------------------------------
 *
 * ２つのベクトルのなす角のcos
 * 引数:２つのベクトル xyz_t *vec1, xyz_t *vec2;
 *
 * 返り値
 * cosの値
 *
 *--------------------------------------------------------------------------*/
extern float M3D_getCos(
    xyz_t *vec1,
    xyz_t *vec2);

/*---------------------------------------------------------------------------
 *
 * ２つのベクトルのなす角のcos
 * 引数:２つのベクトル xyz_t *vec1, xyz_t *vec2;
 * float *value:cosの値を入れて返します。
 *
 * 返り値
 * TRUE:ベクトルのサイズが０のため,cosの値が計算できません。
 *
 *--------------------------------------------------------------------------*/
extern int M3D_getCos2(
    xyz_t *vec1,
    xyz_t *vec2,
    float *value);

/*----------------------------------------------------------------------------
 *
 * ある面に入射するベクトルの反射ベクトル。（正反射？）
 * 注意:正規化（ベクトルの大きさを１にすること）をされたベクトルを使用してく
 * ださい。エラーでなければT_Polygonの法線ベクトルも正規化されているはず。
 *
 * 引数:入力
 * 入射ベクトル xyz_t *in; 
 * 法線ベクトル xyz_t *no;
 * 出力
 * 反射ベクトル xyz_t *re;
 *
 * 返り値：無し
 *
 *--------------------------------------------------------------------------*/
extern void M3D_getRefVec(
    xyz_t *in,
    xyz_t *no,
    xyz_t *re);

/*-------------------------------------------------------------------------
 *
 * 処理マクロ
 *
 *-------------------------------------------------------------------------*/
#define TOLER 0.5f
#define VP_MIN_VALUE 300.0f
#define F_ABS_MIN 0.008f 
#define IS_ZERO(x) (fabsf((x)) < F_ABS_MIN)
#define S_ABS_MIN (short)((float)SHRT_MAX * F_ABS_MIN + 1.0f)

/*--------------------------------------------------------------------------
 *
 * 隙間マクロ
 *
 *-------------------------------------------------------------------------*/
#define SUKIMA_R (1.0f)
#define SUKIMA_RR (SUKIMA_R * SUKIMA_R)

/*==========================================================================
 *
 * 区間チェック
 *
 *=========================================================================*/

/*
 * ある２次元領域に存在しているかのチェック
 */
extern int Math3D_Check2DInArea(
    float min_x, float max_x,
    float min_y, float max_y,
    float x, float y);

/*=========================================================================
 *
 * 位置関係チェック
 *
 *=========================================================================*/

#if 0
/*----------------------------------------------------------------------------
 *
 * boxの６面とある点の位置関係を返す。
 *
 *---------------------------------------------------------------------------*/
extern long Math3DCheckBoxPos_CheckPosition_sv(
    short *point, /* チェック位置 */
    short *box_min, /* box min pos */ 
    short *box_max); /* box max pos */
#endif
/*
 * Box-Pos Position外部コード
 */
#define BPCP_INSIDE   0
#define BPCP_OUTCODE0 (1<<0)
#define BPCP_OUTCODE1 (1<<1)
#define BPCP_OUTCODE2 (1<<2)
#define BPCP_OUTCODE3 (1<<3)
#define BPCP_OUTCODE4 (1<<4)
#define BPCP_OUTCODE5 (1<<5)

/*---------------------------------------------------------------------------
 *
 * boxの６面とある点の位置関係を返す。
 * xyz_t版
 *
 *-------------------------------------------------------------------------*/
extern long Math3DCheckBoxPos_CheckPosition_xyz_t(
    xyz_t *point,
    xyz_t *box_min,
    xyz_t *box_max);
#if 0
/*---------------------------------------------------------------------------
 *
 * boxの１２本のエッジに接する面の上にあるか下にあるかの判定を行う。
 * 傾斜が４５度の面群。
 * 引数はshortのすべてサイズ３の配列版 -> xyz_t版を呼んでいる。
 * 返り値:long 位置に応じたビットコードがかえる。 返り値==0なら、
 * 内部に存在。
 *
 *---------------------------------------------------------------------------*/
extern long Math3DCheckBoxEdgePlane_Bevel2DCheck_sv(
    short *point, /* チェック位置 */
    short *box_min, /* box min pos */ 
    short *box_max); /* box max pos */
#endif
/*---------------------------------------------------------------------------
 *
 * boxの１２本のエッジに接する面の上にあるか下にあるかの判定を行う。
 * 傾斜が４５度の面群。
 * xyz_t版
 * 返り値:long 位置に応じたビットコードがかえる。 返り値==0なら、
 * 内部に存在。
 *
 *---------------------------------------------------------------------------*/
extern long Math3DCheckBoxEdgePlane_Bevel2DCheck_xyz_t(
    xyz_t *point, /* チェック位置 */
    xyz_t *box_min, /* box min pos */ 
    xyz_t *box_max); /* box max pos */
/*
 * BEVEL2D 外部コード
 */

#define BEVEL2D_OUTCODE0 (1<<0)
#define BEVEL2D_OUTCODE1 (1<<1)
#define BEVEL2D_OUTCODE2 (1<<2)
#define BEVEL2D_OUTCODE3 (1<<3)
#define BEVEL2D_OUTCODE4 (1<<4)
#define BEVEL2D_OUTCODE5 (1<<5)
#define BEVEL2D_OUTCODE6 (1<<6)
#define BEVEL2D_OUTCODE7 (1<<7)
#define BEVEL2D_OUTCODE8 (1<<8)
#define BEVEL2D_OUTCODE9 (1<<9)
#define BEVEL2D_OUTCODE10 (1<<10)
#define BEVEL2D_OUTCODE11 (1<<11)

/*---------------------------------------------------------------------------
 *
 * boxの８つの頂点に接する面との位置関係
 * 傾斜が４５度の面群。
 * 引数:shortのすべてサイズ３の配列 -> xyz_t版を呼び出す
 * 返り値:long 位置に応じたビットコードがかえる。 返り値==0なら、
 * 内部に存在。
 *
 *---------------------------------------------------------------------------*/
extern long Math3DCheckBoxEdgePlane_Bevel3DCheck_sv(
    short *point, /* チェック位置 */
    short *box_min, /* box min pos */ 
    short *box_max); /* box max pos */

/*---------------------------------------------------------------------------
 *
 * boxの８つの頂点に接する面との位置関係
 * 傾斜が４５度の面群。
 * 引数:xyz_t版
 * 返り値:long 位置に応じたビットコードがかえる。 返り値==0なら、
 * 内部に存在。
 *
 *---------------------------------------------------------------------------*/
extern long Math3DCheckBoxEdgePlane_Bevel3DCheck_xyz_t(
    xyz_t *point,
    xyz_t *min,
    xyz_t *max);
/*
 * Bevel 3D 外部コード
 */
#define BEVEL3D_OUTCODE0 (1<<0)
#define BEVEL3D_OUTCODE1 (1<<1)
#define BEVEL3D_OUTCODE2 (1<<2)
#define BEVEL3D_OUTCODE3 (1<<3)
#define BEVEL3D_OUTCODE4 (1<<4)
#define BEVEL3D_OUTCODE5 (1<<5)
#define BEVEL3D_OUTCODE6 (1<<6)
#define BEVEL3D_OUTCODE7 (1<<7)


/*===========================================================================
 *
 * ２次元距離計算
 *
 *==========================================================================*/
/*--------------------------------------------------------------------------
 *
 * ２次元ベクトルの２乗のサイズ計算（ルート計算なし）
 *
 *--------------------------------------------------------------------------*/
extern float Math3DVecLengthSquare2D(
    float x, float y);

/*---------------------------------------------------------------------------
 *
 * ２次元ベクトルのサイズ計算（ルート計算あり）
 *
 *--------------------------------------------------------------------------*/
extern float Math3DVecLength2D(
    float x, float y);


/*---------------------------------------------------------------------------
 *
 * ２次元距離計算（2乗サイズルート計算なし）
 *
 *-------------------------------------------------------------------------*/
extern float Math3DLengthSquare2D(
    float x1, float y1,
    float x2, float y2);


/*---------------------------------------------------------------------------
 *
 * ２次元距離計算（2乗サイズルート計算なし:マクロ版）
 *
 *-------------------------------------------------------------------------*/
#define MATH3D_LENGTH_SQUARE2D(x1, y1, x2, y2) \
((((x1) - (x2)) * ((x1) - (x2))) + \
 (((y1) - (y2)) * ((y1) - (y2))))

/*===========================================================================
 *
 * ３次元距離計算
 *
 *==========================================================================*/

/*---------------------------------------------------------------------------
 *
 * ベクトルの２乗のサイズ計算（ルート計算なし）
 *
 *---------------------------------------------------------------------------*/
extern float Math3DVecLengthSquare(xyz_t *vec);

/*---------------------------------------------------------------------------
 *
 * ベクトルの大きさ計算（ルート計算あり）
 * 大きさの値が重要なとき以外上を使用してください。
 *
 *--------------------------------------------------------------------------*/
extern float Math3DVecLength(xyz_t *vec);

/*---------------------------------------------------------------------------
 *
 * 距離の2乗の計算(ルート計算なし）
 *
 *-------------------------------------------------------------------------*/
extern float Math3DLengthSquare(xyz_t *pp1, xyz_t *pp2);


/*---------------------------------------------------------------------------
 *
 * 距離の2乗の計算(ルート計算あり）
 *
 *-------------------------------------------------------------------------*/
extern float Math3DLength(xyz_t *pp1, xyz_t *pp2);

/*---------------------------------------------------------------------------
 *
 * 距離の2乗の計算(ルート計算あり）
 *
 *-------------------------------------------------------------------------*/
extern float Math3DLength(xyz_t *pp1, xyz_t *pp2);

/*==========================================================================
 *
 * 外積計算
 *
 *=========================================================================*/

/*-------------------------------------------------------------------------
 *
 * 外積計算(２ベクトルから計算する)
 *
 *------------------------------------------------------------------------*/
extern void Math3DVectorProduct2Vec(
    xyz_t *vec1, xyz_t *vec2, xyz_t *vp_vec);

/*--------------------------------------------------------------------------
 *
 * 外積計算(３点から計算する）
 * pos0からpos1へのベクトルとpos0からpos2へのベクトルの外積
 *
 *-------------------------------------------------------------------------*/
extern void Math3DVectorProductXYZ(xyz_t *pos0, xyz_t *pos1, xyz_t *pos2,
				   xyz_t *mult_vec);

/*==========================================================================
 *
 * 平面処理関連
 *
 *=========================================================================*/

/*--------------------------------------------------------------------------
 *
 * 平面方程式の値
 *
 *-------------------------------------------------------------------------*/
extern float Math3DPlaneFunc(float a, float b, float c, float d, xyz_t* pos);

/*--------------------------------------------------------------------------
 *
 * xz平面に垂直な面で,その面の向きをangle_yで与えて、その面の位置を得たとき
 * その面の方程式のa,(b = 0),c,dを計算する。
 *
 *-------------------------------------------------------------------------*/
extern void Math3DPlanePosAngleY(
    xyz_t *pos, short angle_y,
    float *a, float *c, float *d);

/*--------------------------------------------------------------------------
 *
 * 平面方程式係数計算
 *
 *-------------------------------------------------------------------------*/
extern void Math3DPlane(
    xyz_t *pos0, xyz_t *pos1, xyz_t *pos2,
    float *a, float *b, float *c, float *d);

/*--------------------------------------------------------------------------
 *
 *  平面方程式の値
 * f(x, y, z) = ax + by + cz + d
 * float:a,b,c,d要素指定版
 *
 * T_PolygonF:floatのa,b,c,d要素ポリゴン ローカル型
 *
 *--------------------------------------------------------------------------*/
extern float T_PolygonF_planeFunc(T_PolygonF *this, xyz_t *pp);

/*--------------------------------------------------------------------------
 *
 * 無限平面との距離
 *
 *------------------------------------------------------------------------*/
extern float Math3DLengthPlaneAndPos(
    float a, float b, float c, float d,
    xyz_t *pos);

/*---------------------------------------------------------------------------
 *
 * 無限平面との距離（符合付き:面より上の時は正/面よりしたの時は負
 *
 *-------------------------------------------------------------------------*/
extern float Math3DSignedLengthPlaneAndPos(
    float a, float b, float c, float d,
    xyz_t *pos);

/*============================================================================
 *
 * 三角形との交差判定
 *
 *==========================================================================*/

/*============================================================================
 * 
 * y軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 * ベクトル積との比較パラメーター設定可能バージョン
 * これは外から呼ばないでください。
 * 総合バージョン
 *
 *===========================================================================*/
extern int Math3DTriangleCrossYCheck_general(
    xyz_t *tri_pos1, xyz_t *tri_pos2, xyz_t *tri_pos3, /*三角形の三頂点 */
    float z, float x, /* 直線座標 */
    float check_param, /* チェックパラメータ */
    float sukima_r, /* 隙間パラメーター */
    float b); /* 法線のbパラメータ */

/*---------------------------------------------------------------------------
 * 
 * y軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTriangleCrossYCheck(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /*三角形の三頂点 */
    float z, float x); /* 直線座標 */

/*---------------------------------------------------------------------------
 *
 * y軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 * b == 0.0fの時 false
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTriangleCrossYLine_sukimaR(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /*三角形の三頂点 */
    float a, float b, float c, float d, /* 平面のパラメータ 注意:shortでない */
    float z, float x, /* 直線座標 */
    float* p_cross_y, /* 交点のy座標 */
    float sukima_r); /* 隙間パラメータ */
    
/*---------------------------------------------------------------------------
 *
 * y軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 * b == 0.0fの時 false
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTriangleCrossYLine_sukimaR_VP0(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /*三角形の三頂点 */
    float a, float b, float c, float d, /* 平面のパラメータ 注意:shortでない */
    float z, float x, /* 直線座標 */
    float* p_cross_y, /* 交点のy座標 */
    float sukima_r); /* 隙間パラメータ */

/*---------------------------------------------------------------------------
 *
 * y軸に平行な無限直線と三角形の交差判定
 * 範囲指定つき
 * 返り値:0がfalse
 * 引数:
 * xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3:三角形の三頂点 
 * float a, float b, float c, float d: 平面のパラメータ 注意:shortでない 
 * float z, float x: 直線座標
 * float* p_cross_y: 交点のy座標
 * float scope_y1, float scope_y2:チェックｙ座標範囲
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTriangleCrossYLine_scope(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3,
    float a, float b, float c, float d,
    float z, float x, 
    float* p_cross_y,
    float scope_y1, float scope_y2);

/*---------------------------------------------------------------------------
 *
 * y軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 * 浮動小数点 平面パラメータ
 * 交点計算しません
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTrianglePFCrossYLine_noCross_sukimaR(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /*三角形の三頂点 */
    T_PolygonF *ppolyf, /* 浮動小数点 平面パラメータ */
    float z, float x, /* 直線座標 */
    float sukima_r); /* 隙間パラメータ */

/* 簡易マクロバージョン */
#define MATH3D_TRIANGLE_PF_CROSSYLINE_NOCROSS_SUKIMAR(tri_pos1, tri_pos2, tri_pos3, ppolyf, y, z, sukima_r) \
(Math3DTriangleCrossYCheck_general((tri_pos1), (tri_pos2), (tri_pos3), (y), (z), (0.0f), (sukima_r)))
    
/*============================================================================
 *
 * x軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 * 総合版
 * これは外から呼ばないでください。
 *
 *==========================================================================*/
extern int Math3DTriangleCrossXCheck_general(
    xyz_t *tri_pos1, xyz_t *tri_pos2, xyz_t *tri_pos3, /*三角形の三頂点 */
    float y, float z, /* 直線座標 */
    float check_param, /* チェックパラメータ */
    float sukima_r, /* 隙間パラメータ */
    float a); /* 法線のaパラメータ */

/*-----------------------------------------------------------------------------
 *
 * x軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 *
 */
extern int Math3DTriangleCrossXLine(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /* 三角形の三頂点 */
    float a, float b, float c, float d, /* 平面パラメータ 注意:shortでない */
    float y, float z, /* 直線座標 */
    float* p_cross_x); /* 交点のx座標 */
 
/*-----------------------------------------------------------------------------
 *
 * x軸に平行な無限直線と三角形の交差判定と交点(範囲指定つき）
 * 返り値:0がfalse
 * xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3: 三角形の三頂点
 * float a, float b, float c, float d: 平面パラメータ 注意:shortでない
 * float y, float z: 直線座標
 * float *p_cross_x:交点のx座標 
 * float scope_x1, float scope_x2:チェック範囲
 *
 *---------------------------------------------------------------------------*/
extern int Math3DTriangleCrossXLine_scope(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, 
    float a, float b, float c, float d,
    float y, float z, 
    float *p_cross_x,
    float scope_x1, float scope_x2);
/*-----------------------------------------------------------------------------
 *
 * x軸に平行な無限直線と三角形の交差判定と交点
 * 返り値:0がfalse
 * 浮動小数点 平面パラメータ version
 * 交点計算しません
 * 隙間パラメータセット
 *
 *---------------------------------------------------------------------------*/
extern int Math3DTrianglePFCrossXLine_noCross_sukimaR(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /* 三角形の三頂点 */
    T_PolygonF *ppolyf, /* 浮動小数点 平面パラメータ version */
    float y, float z, /* 直線座標 */
    float sukima_r);

/* 簡易マクロバージョン */
#define MATH3D_TRIANGLE_PF_CROSSXLINE_NOCROSS_SUKIMAR(tri_pos1, tri_pos2, tri_pos3, ppolyf, y, z, sukima_r) \
(Math3DTriangleCrossXCheck_general((tri_pos1), (tri_pos2), (tri_pos3), (y), (z), 0.0f, (sukima_r)))

/*===========================================================================
 *
 *  z軸に平行な無限直線と交差判定
 * 総合版
 *
 *==========================================================================*/
extern int Math3DTriangleCrossZCheck_general(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /*三角形の三頂点 */
    float x, float y, /* 直線座標 */
    float check_param, /* チェックパラメータ */
    float sukima_r, /* 隙間パラメータ */
    float c); /* 法線のcパラメータ */

/*----------------------------------------------------------------------------
 *
 * z軸に平行な無限直線と三角形の交差判定
 * 返り値:0がfalse
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTriangleCrossZLine(
    xyz_t* tri_pos1, xyz_t* tri_pos2, xyz_t* tri_pos3, /* 三角形の頂点 */
    float a, float b, float c, float d, /* 平面パラメータ 注意:shortでない */
    float x, float y, /* 直線座標 */
    float *p_cross_z); /* 交点のz座標 */

/*----------------------------------------------------------------------------
 *
 * z軸に平行な無限直線と三角形の交差判定と交点
 * 返り値:0がfalse
 * 引数:
 * xyz_t *tri_pos1, xyz_t *tri_pos2, xyz_t *tri_pos3:三角形の頂点
 * float a, float b, float c, float d: 平面パラメータ 注意:shortでない
 * float x, float y,:直線座標
 * float *p_cross_z: 交点のz座標
 * float min_z1, float max_scope_z2:チェック範囲
 *--------------------------------------------------------------------------*/
extern int Math3DTriangleCrossZLine_scope(
    xyz_t *tri_pos1, xyz_t *tri_pos2, xyz_t *tri_pos3, 
    float a, float b, float c, float d, 
    float x, float y, 
    float *p_cross_z,
    float scope_z1, float scope_z2);

/*----------------------------------------------------------------------------
 *
 * z軸に平行な無限直線と三角形の交差判定と交点
 * 交点計算しません
 * 返り値:0がfalse
 * 浮動小数点 平面パラメータ Version
 * 隙間パラメータセット
 *
 *--------------------------------------------------------------------------*/
extern int Math3DTrianglePFCrossZLine_noCross_sukimaR(
    xyz_t *tri_pos1, xyz_t *tri_pos2, xyz_t *tri_pos3, /* 三角形の頂点 */
    T_PolygonF *ppolyf, /* 浮動小数点 平面パラメータ */
    float x, float y, /* 直線座標 */
    float sukima_r);

/* 簡易マクロバージョン */
#define MATH3D_TRIANGLE_PF_CROSSZLINE_NOCROSS_SUKIMAR(tri_pos1, tri_pos2, tri_pos3, ppolyf, y, z, sukima_r) \
(Math3DTriangleCrossZCheck_general((tri_pos1), (tri_pos2), (tri_pos3), (y), (z), 0.0f, (sukima_r)))

/*---------------------------------------------------------------------------
 *
 * 無限平面と線分との交点
 * 返り値:
 * 交差したかどうか？(TRUE/FALSE) 現在端点が面上の時もTRUE
 * 引数：
 * float a, float b, float c, float d:平面のパラメーター
 * xyz_t *pstart, xyz_t *pend :線分のスタートエンド
 * xyz_t *pcross_pos: 交点を入れて返す（交差時のみ）
 * 交差しないとき*pend,それぞれ面上にあるとき*pstart,*pend
 * int front_flag: 表面のみチェック
 *
 *---------------------------------------------------------------------------*/
extern int Math3DCheckPlaneCrossLine_xyz_t_cp(
    float a, float b, float c, float d,
    xyz_t *pstart, xyz_t *pend,
    xyz_t *pcross_pos,
    int front_flag);

/*---------------------------------------------------------------------------
 *
 * Math3DCheckTriangleCrossLine_xyz_tの交点を返すバージョン
 *
 *--------------------------------------------------------------------------*/
extern int Math3DCheckTriangleCrossLine_xyz_t_cp(
    xyz_t *tri_pos1, xyz_t *tri_pos2, xyz_t *tri_pos3, /* 三角形頂点 */
    float a, float b, float c, float d, /* 平面パラメーター:shortではない */
    xyz_t *pstart, xyz_t *pend, /* 直線のスタートエンド */
    xyz_t *cross_pos,/* 交点を入れて返す。（構造体へのポインター) */
    int front_flag); /* 表面のみチェック */
 

/*--------------------------------------------------------------------------
 *
 * あるmin-max領域と線分が交差しているか？
 * xyz_t位置指定,交点を返すバージョン(返す交点は交点が見つかった
 * 時点で返すため,位置関係は不定）
 *
 *-------------------------------------------------------------------------*/
extern int Math3DCheckBoxCrossLine_xyz_t(
    xyz_t *min, xyz_t *max, /* 箱領域 */
    xyz_t *lps, xyz_t *lpe); /* ラインの始点終点*/


/*===========================================================================
 *
 * コリジョン用に製作した関数群(Collsiion)
 *
 *=========================================================================*/
/*===========================================================================
 *
 * Math3D_triangle コンストラクター
 *
 *=========================================================================*/
extern void Math3D_triangle_ct(
    Math3D_triangle *ptri,
    xyz_t *p1, xyz_t *p2, xyz_t *p); /* 一応時計回り */
        
/*----------------------------------------------------------------------------
 *
 * 球と線分交差チェック
 * 返り値:交差している == TRUE
 * Math3D_sphere *psphere:球構造体
 * Math3D_lineSegment *pls:線分構造体
 * 参照:InsideWindows ３月号
 *
 * 球の中心から線分への垂線の足（交点）Ｈを求めて,それが球の内部に存在するか
 * を計算する。
 *
 *---------------------------------------------------------------------------*/
extern int Math3D_sphereCrossLineSegment(
    Math3D_sphere *psphere,
    Math3D_lineSegment *pls);

/*==========================================================================
 *
 * 球と球
 * 返り値:TRUE の時 包含/接触
 * メモ：中心間距離と半径から判定
 *
 *========================================================================*/
extern int Math3D_sphereCrossSphere(
    Math3D_sphere *sp1,
    Math3D_sphere *sp2);

/*=========================================================================
 *
 * 球と球(めり込み距離取得版)
 *
 * 返り値:TRUE の時 包含/接触
 * メモ：中心間距離と半径から判定
 *
 *========================================================================*/
extern int Math3D_sphereCrossSphere_cl(
    Math3D_sphere *sp1,
    Math3D_sphere *sp2,
    float *pcross_length);

/*=========================================================================
 *
 * 球と球(めり込み距離/中心間距離取得版)
 *
 * 返り値:TRUE の時 包含/接触
 * メモ：中心間距離と半径から判定
 * 引数:
 * float *pcross_length : めり込み距離を入れて返す。
 * flaot *pcc_length : 中心間距離を入れて返す。
 *
 *========================================================================*/
extern int Math3D_sphereCrossSphere_cl_cc(
    Math3D_sphere *sp1,
    Math3D_sphere *sp2,
    float *pcross_length,
    float *pcc_lenght);

/*========================================================================
 *
 * 球vs円柱
 * 返り値:TRUE の時包含/接触
 * メモ：正確ではないが確実に接触しているときにTRUEにできるだけなりように。
 * 傾いていない円柱です。
 *========================================================================*/
extern int Math3D_sphereVsPipe_cl(
    Math3D_sphere *sp1,
    Math3D_pipe *ppipe,
    float *pcross_length);

/*========================================================================
 *
 * 球vs円柱
 * 返り値:TRUE の時包含/接触
 * メモ：正確ではないが確実に接触しているときにTRUEにできるだけなりように。
 * 傾いていない円柱です。
 * 引数:
 * Math3D_sphere *sp1:球情報
 * Math3D_pipe *ppipe:パイプ情報
 * float *pcross_length: 交差距離
 * float *pcc_length: 中心間距離
 * 
 *========================================================================*/
extern int Math3D_sphereVsPipe_cl_cc(
    Math3D_sphere *sp1,
    Math3D_pipe *ppipe,
    float *pcross_length,
    float *pcc_length);

/*===========================================================================
 *
 * 線分と点との距離(２次元版）
 *
 * メモ：線分に長さがないときは返り値FALSEで長さが0.0fがかえる。
 * 返り値:点から線分に足を下ろした時に交点が線分内に出来なければFALSEを返す。
 *
 *==========================================================================*/
extern int Math3D_pointVsLineSegmentLengthSquare2D(
    float px, float py,
    float lx1, float ly1,
    float lx2, float ly2,
    float *plen);

/*--------------------------------------------------------------------------
 *
 * 球vs三角形（剣用）
 * 交点を返すバージョン:交点が剣用。
 * 詳細チェック
 * 返り値:TRUE 接触
 * 結局 Math3D_triangleに平面方程式のabcdパラメータつけました。(by matutani)
 *
 *-------------------------------------------------------------------------*/
extern int Math3D_sphereCrossTriangle3_cp(
    Math3D_sphere *sphere,
    Math3D_triangle *tri,
    xyz_t *pcross);

/*==========================================================================
 *
 * 円柱vs円柱(重なり量取得版）
 * 返り値:TRUE 包含/接触
 *
 *=======================================================================*/
extern int Math3D_pipeVsPipe_cl(
    Math3D_pipe *ppipe1,
    Math3D_pipe *ppipe2,
    float *pcross_length);

/*==========================================================================
 *
 * 円柱vs円柱(重なり量,中心間距離取得版）
 * 返り値:TRUE 包含/接触
 * メモ:
 * 引数
 * Math3D_pipe *ppipe1, *ppipe2 : チェックする形状データ
 * float *pcross_length : 交差時の重なり量
 * float *pcenter_xzlength : ２つの円柱の中心間距離
 *
 *=======================================================================*/
extern int Math3D_pipeVsPipe_cl_cc(
    Math3D_pipe *ppipe1,
    Math3D_pipe *ppipe2,
    float *pcross_length,
    float *pcenter_xzlength);

/*--------------------------------------------------------------------------
 *
 * 円筒vs線分
 * まじめにチェック
 * 返り値:交点個数─＞３:ラインを含む
 *
 *-------------------------------------------------------------------------*/
extern int Math3D_pipeCrossLine( 
    Math3D_pipe *pipe, 
    xyz_t *plpos1, xyz_t *plpos2, /* ライン情報 */
    xyz_t *pcross1, xyz_t *pcross2); /* 交点（pcross1優先) */
    
/*--------------------------------------------------------------------------
 *
 * 円筒vs三角形（円筒にXやZ回転がある場合はチェックできない）
 * 詳細チェック
 * 返り値:TRUE 接触
 * 全くデバッグしてません
 * 都合上引数変えました。(by matutani)
 *
 *-------------------------------------------------------------------------*/
extern int Math3D_pipeCrossTriangle(
    Math3D_pipe *pipe,
    Math3D_triangle *tri);

/*--------------------------------------------------------------------------
 *
 * 円筒vs三角形（円筒にXやZ回転がある場合はチェックできない）
 * 詳細チェック
 * 返り値:TRUE 接触
 * 全くデバッグしてません
 * 都合上引数変えました。(by matutani)
 * 交点計算つき
 *
 *-------------------------------------------------------------------------*/
extern int Math3D_pipeCrossTriangle_cp(
    Math3D_pipe *pipe,
    Math3D_triangle *tri,
    xyz_t *pcross);

/*=========================================================================
 *
 * 三角形vs三角形
 * 返り値:TRUE 交差時のみチェック（包含時は省く）
 *
 *=========================================================================*/
extern int Math3D_triangleCrossTriangle_cp(
    Math3D_triangle *ptri1,
    Math3D_triangle *ptri2,
    xyz_t *pcross);

/*---------------------------------------------------------------------------
 *
 * 球とy軸に平行な直線との交差
 * 返り値:交差の有無 True/False
 *
 *-------------------------------------------------------------------------*/
extern int Math3D_sphereCrossXZLine(
    Math3D_sphere *psph,
    float x, float z);


/*---------------------------------------------------------------------------
 *
 * 球とz軸に平行な直線との交点
 * 返り値:交差の有無 True/False
 *
 *--------------------------------------------------------------------------*/
extern int Math3D_sphereCrossXYLine(
    Math3D_sphere *psph,
    float x, float y);

/*---------------------------------------------------------------------------
 *
 * 球とx軸に平行な直線との交点
 * 返り値:交差の有無 True/False
 *
 *--------------------------------------------------------------------------*/
extern int Math3D_sphereCrossYZLine(
    Math3D_sphere *psph,
    float y, float z);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif   

/*** math3d.h end ***/

