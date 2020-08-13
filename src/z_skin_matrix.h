/*  $Id: z_skin_matrix.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $ */
/*---------------------------------------------------------------------------
 *
 * z_skin_matrix.h
 * スキン処理用マトリックス計算ヘッダー
 *
 * Program:Kenji Matsutani
 *
 * $Log: z_skin_matrix.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.13  1998/08/04 10:44:08  matutani
 * プロトタイプにSkin_Matrix_SetRotateZxy_s()を追加
 *
 * Revision 1.12  1998-05-09 20:43:20+09  matutani
 * Quaternionからマトリックスへ変換
 *
 * Revision 1.11  1998-05-09 16:16:40+09  matutani
 * Skin_Matrix_PRINTF()削除
 *
 * Revision 1.10  1998-03-25 20:23:34+09  hayakawa
 * #if #endifの対応があってないので修正しときました
 *
 * Revision 1.9  1998/03/19  13:03:40  komatu
 * *** empty log message ***
 *
 * Revision 1.8  1998/03/03  10:56:46  matutani
 * 自由軸回転
 *
 * Revision 1.7  1997/09/03  10:31:28  matutani
 * ZXYの回転マトリックスを掛ける順番
 *
 * Revision 1.6  1997/08/11  07:22:28  matutani
 * *** empty log message ***
 *
 * Revision 1.5  1997/08/05  08:54:41  matutani
 * *** empty log message ***
 *
 * Revision 1.4  1997/07/29  09:52:59  matutani
 * *** empty log message ***
 *
 * Revision 1.3  1997/07/18  08:39:16  matutani
 * Skin_Matrix_PrjMulVector追加
 *
 * Revision 1.2  1997/03/27  02:17:27  matutani
 * extern関数追加
 *
 * Revision 1.1  1997/03/25  07:45:31  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_SISK_MATRIX_H
#define INCLUDE_Z_SISK_MATRIX_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_skin_type.h"

/*-------------------------------------------------------------------------
 *
 * マクロ
 * 使用に注意
 *
 *------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 *
 * Vector x Matrix マクロ版 （使用に注意）
 *
 *--------------------------------------------------------------------------*/
#define Skin_Matrix_Macro_MulVector(pmat, vec, ret_vec) \
{\
     float *e;\
e = (float *)(pmat)->e;\
(ret_vec)->x = (vec)->x * *(e + 0*4 + 0) + (vec)->y * *(e + 1*4 + 0) +\
(vec)->z * *(e + 2*4 + 0) + *(e + 3*4 + 0);\
(ret_vec)->y = (vec)->x * *(e + 0*4 + 1) + (vec)->y * *(e + 1*4 + 1) +\
(vec)->z * *(e + 2*4 + 1) + *(e + 3*4 + 1);\
(ret_vec)->z = (vec)->x * *(e + 0*4 + 2) + (vec)->y * *(e + 1*4 + 2) +\
(vec)->z * *(e + 2*4 + 2) + *(e + 3*4 + 2);\
}


/*----------------------------------------------------------------------------
 *
 * Skin_Vector から Skin_SVector
 *
 *---------------------------------------------------------------------------*/
#define Skin_Matrix_Macro_vec2svec(pvec, psvec) \
{(psvec)->sx  = (short)((pvec)->x); \
(psvec)->sy = (short)((pvec)->y); \
(psvec)->sz = (short)((pvec)->z); \
}

/*----------------------------------------------------------------------------
 *
 * Skin_SVector から Skin_Vector
 *
 *---------------------------------------------------------------------------*/
#define Skin_Matrix_Macro_svec2vec(psvec, pvec) \
{((pvec)->x) = (float)((psvec)->sx); \
((pvec)->y) = (float)((psvec)->sy); \
((pvec)->z) = (float)((psvec)->sz); \
}
#if 0
PRINTF("%f %f %f -> %d %d %d \n", (pvec)->x, (pvec)->y, (pvec)->z,\
       (psvec)->sx, (psvec)->sy, (psvec)->sz);
#endif

/*-------------------------------------------------------------------------
 *
 * 関数
 *
 *------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
 *
 * プロジェクションマトリックス x 頂点(もちろん元の頂点はw=1)
 * x,yの1/wは計算しない
 *
 *-----------------------------------------------------------------------*/
extern void Skin_Matrix_PrjMulVector(
    Skin_Matrix *pprj_mat, Skin_Vector *vec, Skin_Vector *ret_vec, float *pw);

/*------------------------------------------------------------------------
 *
 * Vector x Matrix
 * w = 1として計算
 *
 *----------------------------------------------------------------------*/
extern void Skin_Matrix_MulVector(
    Skin_Matrix *pmat, Skin_Vector *vec, Skin_Vector *ret_vec);


/*----------------------------------------------------------------------------
 *
 * Matrix x Matrix
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_MulMatrix(
    Skin_Matrix *pmat1, Skin_Matrix *pmat2, Skin_Matrix *pret_mat);


/*---------------------------------------------------------------------------
 *
 * 単位行列へのポインター
 *
 *-------------------------------------------------------------------------*/
extern void Skin_Matrix_getUnitMatrixPointer(Skin_Matrix **ppmat);

/*----------------------------------------------------------------------------
 *
 * Set Unit Matrix
 * 単位ベクトル
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_SetUnitMatrix(
    Skin_Matrix *pmat);


/*-----------------------------------------------------------------------------
 *
 * matrix data copy
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_Copy(
    Skin_Matrix *pfrom, Skin_Matrix *pto);

#if 0
/*----------------------------------------------------------------------------
 *
 * matrix printf
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_PRINTF(Skin_Matrix *pmat, char *label);
#endif

/*----------------------------------------------------------------------------
 *
 * SRT行列
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_SetSrtMatrix(
    Skin_Matrix *pmat,
    float sx, float sy, float sz,
    short rx, short ry, short rz,
    float tx, float ty, float tz);

/*----------------------------------------------------------------------------
 *
 * SRzxyT行列
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_SetSRzxyTMatrix(
    Skin_Matrix *pmat,
    float sx, float sy, float sz,
    short rx, short ry, short rz,
    float tx, float ty, float tz);

/*----------------------------------------------------------------------------
 *
 * RT行列
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_SetRtMatrix(
    Skin_Matrix *pmat,
    short rx, short ry, short rz,
    float tx, float ty, float tz);

/*----------------------------------------------------------------------------
 *
 * Skin_Vector から Skin_SVector
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_vec2svec(
    Skin_Vector *pskin_vec,
    Skin_SVector *pskin_svec);

/*----------------------------------------------------------------------------
 *
 * Skin_SVector から Skin_Vector
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_svec2vec(
    Skin_SVector *pskin_svec,
    Skin_Vector *pskin_vec);

/*-----------------------------------------------------------------------
 *
 *	Skin_Matrix --> Mtx
 *
 *----------------------------------------------------------------------*/
extern void Skin_Matrix_to_Mtx(
    Skin_Matrix *sk_mat,
    Mtx		*m
);

/*---------------------------------------------------------------------------
 *
 * Skin_Matrix ---> Mtx (graph_malloc付き)
 *
 *--------------------------------------------------------------------------*/
extern Mtx *Skin_Matrix_to_Mtx_new(
    Graph *graph,
    Skin_Matrix *sk_mat);

/*----------------------------------------------------------------------------
 *
 * トランスレート行列
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_SetTranslate(
    Skin_Matrix *pmat,
    float x,
    float y,
    float z);

/*---------------------------------------------------------------------------
 *
 * スケール行列
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_SetScale(
    Skin_Matrix *pmat,
    float x,
    float y,
    float z);

/*-----------------------------------------------------------------------------
 *
 * xyzローテート行列
 * short角度
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_SetRotateXyz_s(
    Skin_Matrix *pmat,
    short x,
    short y,
    short z);


/*-----------------------------------------------------------------------------
 *
 * zxyローテート行列
 * short角度
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_SetRotateZxy_s(
    Skin_Matrix *pmat,
    short x,
    short y,
    short z);

/*---------------------------------------------------------------------------
 *
 * Inverse Matrix
 *
 *--------------------------------------------------------------------------*/
extern Skin_Error Skin_Matrix_InverseMatrix(
    Skin_Matrix *pmat1, Skin_Matrix *pinv);

/*-----------------------------------------------------------------------------
 *
 * 自由軸回転をセットする。
 * ベクトル(a,b,c)を中心にある角度th（単位はshort)回転する）
 *
 *---------------------------------------------------------------------------*/
extern void Skin_Matrix_SetFreeVecRotMatrix(
    Skin_Matrix *pmat,
    short th,
    float a,
    float b,
    float c);

/*----------------------------------------------------------------------------
 *
 * Quaternion空間から回転マトリックスへ変換
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Matrix_SetQuaternion(
    Skin_Matrix *pmat,
    Quaternion *q);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_skin_matrix.h ***/
