/* $Id: sys_matrix.h,v 2.1 1998/10/22 11:41:56 zelda Exp $ */	
/*
 * $Log: sys_matrix.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.20  1998/08/13 07:07:17  zelda
 * *** empty log message ***
 *
 * Revision 1.19  1998-08-12 20:26:45+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.18  1998-08-12 20:13:55+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.17  1998-08-12 20:04:23+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.16  1998-08-12 19:00:45+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.15  1998-08-12 18:16:48+09  hayakawa
 * デバッグモードいろいろ
 *
 * Revision 1.14  1998-06-24 10:43:34+09  umemiya
 * Matrix_to_rotate関係変更
 *
 * Revision 1.13  1998-03-17 21:25:32+09  hayakawa
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.12  1997/09/04  13:27:05  umemiya
 * Matrix_rotateVector, Matrix_to_rotate2追加
 *
 * Revision 1.11  1997/09/04  04:28:04  umemiya
 * Matrix_to_rotate追加
 *
 * Revision 1.10  1997/04/19  08:20:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.9  1997/03/18  13:27:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1996/12/24  06:09:28  iwawaki
 * Matrix_rotateXYZ追加
 *
 * Revision 1.7  1996/10/21  00:22:15  iwawaki
 * Matrix_reverse make
 *
 * Revision 1.6  1996/10/18  08:05:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1996/10/11  03:04:36  matutani
 * LoadIdentity Matrix Add
 *
 * Revision 1.4  1996/09/28  06:44:46  iwawaki
 * Matrix_softcv3_****追加
 *
 * Revision 1.3  1996/09/18  08:58:58  iwawaki
 * $Log追加
 * */


#ifndef INCLUDE_SYS_MATRIX_H
#define INCLUDE_SYS_MATRIX_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_types.h"		/* MtxF */
#include "game.h"		/* Game */
    
/************************************************************************
 *
 *	sys_matrix.c の extern など
 *
 ************************************************************************/

#define		MTXF_STACK_MAX	20	/* 行列バッファ最大数 */
#define		SET_MTX		0	/* 行列関数用 フラグ */
#define		MULT_MTX	1	/* 行列関数用 フラグ */


/*-----------------------------------------------------------------------
 *
 *	単位行列
 *
 *----------------------------------------------------------------------*/
extern MtxF	MtxF_clear;

/*-----------------------------------------------------------------------
 *
 *	単位行列セット
 *
 *----------------------------------------------------------------------*/
extern Mtx	Mtx_clear;

#define	GspLoadIdentity(gfxp) \
gSPMatrix(gfxp, &Mtx_clear, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);


/*-----------------------------------------------------------------------
 *
 *	行列計算クラス宣言
 *
 *----------------------------------------------------------------------*/
extern void new_Matrix(Game *game);

/*-----------------------------------------------------------------------
 *
 *	行列 の プッシュ
 *
 *----------------------------------------------------------------------*/
extern void Matrix_push(void);

/*-----------------------------------------------------------------------
 *
 *	行列 の プル
 *
 *----------------------------------------------------------------------*/
extern void Matrix_pull(void);

/*-----------------------------------------------------------------------
 *
 *	行列 の ゲット
 *
 *----------------------------------------------------------------------*/
extern void Matrix_get(
    MtxF *m		/* ゲット行列格納バッファ */
);

/*-----------------------------------------------------------------------
 *
 *	行列 の プット
 *
 *----------------------------------------------------------------------*/
extern void Matrix_put(
    MtxF *m		/* プット行列 */
);

/*-----------------------------------------------------------------------
 *
 *	行列 の かけ算							*
 *
 *----------------------------------------------------------------------*/
extern void Matrix_mult(
    MtxF 	*m,	/* 乗算行列 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	トランスレート行列						*
 *
 *----------------------------------------------------------------------*/
extern void Matrix_translate(
    float	x,	/* Ｘ 角度 */
    float	y,	/* Ｙ 角度 */
    float	z,	/* Ｚ 角度 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	スケール行列
 *
 *----------------------------------------------------------------------*/
extern void Matrix_scale(
    float	x,	/* Ｘ 倍率 */
    float	y,	/* Ｙ 倍率 */
    float	z,	/* Ｚ 倍率 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	Ｘローテート行列
 *
 *----------------------------------------------------------------------*/
extern void Matrix_rotateX(
    float	angle,	/* 角度 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	Ｙローテート行列
 *
 *----------------------------------------------------------------------*/
extern void Matrix_rotateY(
    float	angle,	/* 角度 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	Ｚローテート行列
 *
 *----------------------------------------------------------------------*/
extern void Matrix_rotateZ(
    float	angle,	/* 角度 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	ＸＹＺローテート行
 *
 *----------------------------------------------------------------------*/
extern void Matrix_rotateXYZ(
    short	x,	/* Ｘ軸角度 */
    short	y,	/* Ｙ軸角度 */
    short	z,	/* Ｚ軸角度 */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

/*-----------------------------------------------------------------------
 *
 *	アニメーション用行列計算
 *
 *----------------------------------------------------------------------*/
extern void Matrix_softcv3_mult(
    xyz_t	*t,	/* 移動値 */
    s_xyz	*r	/* 回転角 */
);

/*-----------------------------------------------------------------------
 *
 *	アニメーション用初期行列計算
 *
 *----------------------------------------------------------------------*/
extern void Matrix_softcv3_load(
    float	x,	/* Ｘ移動値 */
    float	y,	/* Ｙ移動値 */
    float	z,	/* Ｚ移動値 */
    s_xyz	*r	/* 回転角 */
);

#if DEBUG
extern MtxF *
__Matrix_TestMtxF(MtxF *mf, const char *file, int line);
#define Matrix_TestMtxF(mf) __Matrix_TestMtxF(mf, __FILE__, __LINE__)
#else
#define Matrix_TestMtxF(mf) (mf)
#endif

/*-----------------------------------------------------------------------
 *
 *	MtxF --> Mtx
 *
 *----------------------------------------------------------------------*/
extern Mtx *_MtxF_to_Mtx(
    MtxF	*mf,
    Mtx		*m
);
#define MtxF_to_Mtx(mf, m) _MtxF_to_Mtx(Matrix_TestMtxF(mf), m)

/*-----------------------------------------------------------------------
 *
 *	now MtxF --> Mtx
 *
 *----------------------------------------------------------------------*/
#if DEBUG
extern Mtx *__Matrix_to_Mtx(
    Mtx		*m,
    const char *file,
    int line
);
#define Matrix_to_Mtx(m) __Matrix_to_Mtx(m, __FILE__, __LINE__)
#else
extern Mtx *_Matrix_to_Mtx(
    Mtx		*m
);
#define Matrix_to_Mtx(m) _Matrix_to_Mtx(m)
#endif

/*-----------------------------------------------------------------------
 *
 *	now MtxF --> Mtx（行列バッファ確保）
 *
 *----------------------------------------------------------------------*/
#if DEBUG
extern Mtx *__Matrix_to_Mtx_new(
    Graph 	*graph,
    const char *file,
    int line
);
#define Matrix_to_Mtx_new(graph) __Matrix_to_Mtx_new(graph, __FILE__, __LINE__)
#else
extern Mtx *_Matrix_to_Mtx_new(
    Graph 	*graph
);
#define Matrix_to_Mtx_new(graph) _Matrix_to_Mtx_new(graph)
#endif


/*-----------------------------------------------------------------------
 *
 *	MtxF --> Mtx（行列バッファ確保）
 *
 *----------------------------------------------------------------------*/
extern Mtx *_MtxF_to_Mtx_new(
    MtxF	*mf,
    Graph 	*graph
);
#define MtxF_to_Mtx_new(mf, graph) MtxF_to_Mtx(mf, graph_new(graph, Mtx))

/*-----------------------------------------------------------------------
 *
 *	座標 の 計算
 *
 *----------------------------------------------------------------------*/
extern void Matrix_Position(
    xyz_t	*a,
    xyz_t	*b
);

/*-----------------------------------------------------------------------
 *
 *	行列 の コピー							*
 *
 *----------------------------------------------------------------------*/
extern void Matrix_copy_MtxF(
    MtxF	*m0,
    MtxF	*m1
);

/*-----------------------------------------------------------------------
 *
 *	Mtx --> MtxF
 *
 *----------------------------------------------------------------------*/
extern void Matrix_MtxtoMtxF(
    Mtx		*m0,
    MtxF	*m1
);

/*======================================================================*
 *									*
 *	座標 の 計算							*
 *									*
 *======================================================================*/
extern void Matrix_MtxF_Position2(
    xyz_t	*a,
    xyz_t	*b,
    MtxF	*mtx
);

/*======================================================================*
 *									*
 *	逆行列								*
 *									*
 *======================================================================*/
extern void Matrix_reverse(
    MtxF	*mtx
);

/*======================================================================*
 *									*
 *	回転行列の入れ替え						*
 *									*
 *======================================================================*/
extern void Matrix_rotate_scale_exchange(
    MtxF	*mtx
);

/*-----------------------------------------------------------------------
 *
 *	マトリクスからローテートへ(ZXY)
 *
 *----------------------------------------------------------------------*/
extern void Matrix_to_rotate_new(MtxF *mtx, s_xyz *r, int flg);

#define Matrix_to_rotate(mtx, r) Matrix_to_rotate_new(mtx, r, 0)
#define Matrix_to_rotate_scale(mtx, r) Matrix_to_rotate_new(mtx, r, 1)

/*-----------------------------------------------------------------------
 *
 *	マトリクスからローテートへ(XYZ)
 *
 *----------------------------------------------------------------------*/
extern void Matrix_to_rotate2_new(MtxF *mtx, s_xyz *r, int flg);

#define Matrix_to_rotate2(mtx, r) Matrix_to_rotate2_new(mtx, r, 0)
#define Matrix_to_rotate2_scale(mtx, r) Matrix_to_rotate2_new(mtx, r, 1)

/*-----------------------------------------------------------------------
 *
 *      回転軸指定ローテート行列
 *
 *----------------------------------------------------------------------*/
extern void Matrix_rotateVector(
    float       angle,	/* 角度 */
    xyz_t	*axis,	/* 回転軸単位ベクトル */
    char	flg	/* SET_MTX:行列 の ロード  MULT_MTX:行列 の 乗算 */
);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** sys_matrix.h end ***/
