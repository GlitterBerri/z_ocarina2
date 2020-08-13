/*
 * $Id: sys_math.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * シスマス シスマス シスマス シスマス シスーマス
 *
 * $Log: sys_math.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.12  1998/08/10 12:03:47  hayakawa
 * cosf_table sinf_table 追加
 *
 * Revision 1.11  1998-03-17 20:13:16+09  hayakawa
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.10  1998/02/05  06:07:28  hayakawa
 * atans_table atanf_table 追加
 *
 * Revision 1.9  1997/11/14  00:55:43  hayakawa
 * math.hを組み込むとエラーになったので緊急回避
 *
 * Revision 1.8  1997/11/14  00:27:27  hayakawa
 * fabsfを削除
 * fatan3を削除
 * math.hを同時にインクルードするようにしてみた
 * マクロ版のIfactを削除
 *
 * Revision 1.7  1997/11/05  13:59:55  hayakawa
 * fmodf削除
 *
 * Revision 1.6  1997/07/11  08:17:38  hayakawa
 * *** empty log message ***
 *
 * Revision 1.5  1997/03/25  14:05:08  hayakawa
 * 乱数関係を削除
 *
 * Revision 1.4  1996/11/27  04:39:08  hayakawa
 * math64.hとだぶっているマクロをコメント合うとした
 *
 * Revision 1.3  1996/10/18  08:04:26  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1996/09/18  08:56:29  iwawaki
 * Log追加
 */


#ifndef INCLUDE_SYS_MATH_H
#define INCLUDE_SYS_MATH_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	sys_math.c の extern など
 *
 ************************************************************************/

    /*
     * 非常にありがちな絶対値マクロ
     * 例によって副作用を持つので注意
     */
#define ABS(x) (((x) >= 0) ? (x) : -(x))

    /*
     * fox互換用の乱数発生器
     * しかし、乱数系列に互換性は全くない
     */
#include "qrand.h"
#define init_rnd() 	sqrand((unsigned long)osGetTime())
#define rnd() 		fqrand()

#include "math64.h"

/*======================================================================*
 *	         							*
 *	階乗                                                            *
 *									*
 *======================================================================*/
extern float ffact(
    float x
);

/*======================================================================*
 *	         							*
 *	階乗                                                            *
 *									*
 *======================================================================*/
extern float ifact(
    int x
);

/*======================================================================*
 *	         							*
 *	巾乗(巾乗値はint)                                               *
 *									*
 *======================================================================*/
extern float powi(
    float z,
    int x
);

/*
 * テーブルを使用した高速なアークタンジェント
 * ソース:sys_math_atan.c
 */
extern short atans_table(float x, float y);
extern float atanf_table(float x, float y);

/*
 * テーブル利用の sinf
 * テーブル利用の cosf
 * 精度は悪いが高速です（当社比78% up）
 */
extern float sinf_table(float rad);
extern float cosf_table(float rad);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** sys_math.h end ***/
