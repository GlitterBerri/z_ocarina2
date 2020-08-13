/*
 * $Id: OLDmath64_intrinsics.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * 高速整数化ルーチン
 *
 * $Log: OLDmath64_intrinsics.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.3  1998-04-01 11:39:47+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1997/03/26  06:32:18  hayakawa
 * 復帰値intのバージョンを追加
 *
 * Revision 1.1  1997/03/05  05:22:44  hayakawa
 * Initial revision
 *
 */

#ifndef __MATH64_INTRINSICS_H_
#define __MATH64_INTRINSICS_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

float __ffloor(float  x);
double __floor(double x);
int  __iffloor(float  x);
int   __ifloor(double x);
float  __fceil(float  x);
double  __ceil(double x);
int   __ifceil(float  x);
int    __iceil(double x);
float __ftrunc(float  x);
double __trunc(double x);
int  __iftrunc(float  x);
int   __itrunc(double x);
float __fround(float  x);
double __round(double x);
int  __ifround(float  x);
int   __iround(double x);
float  __frint(float  x);
double  __rint(double x);
int   __ifrint(float  x);
int    __irint(double x);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
