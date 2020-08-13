/*
 * $Id: macro.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * スタンドアローンなマクロ
 *
 * $Log: macro.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.3  2000-07-14 18:05:46+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  1999-07-26 17:36:28+09  hayakawa
 * マクロ名変更 Max/Min→MAX/MIN
 * SGNマクロの引数評価回数をかならず２回になるようにした
 * Numberマクロの型を修正(signed→unsigned)
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.16  1997-08-28 19:34:46+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.15  1997/05/16  02:38:30  hayakawa
 * UPBOUND、DOWNBOUNDにキャスト追加
 * SIZE2LOG2を内部変更
 *
 * Revision 1.14  1997/01/29  12:11:35  hayakawa
 * WRAP,CLAMPを追加
 *
 * Revision 1.13  1996/11/26  10:17:13  hayakawa
 * 度 ←→ ラジアン変換をmath64.hに移動させた
 *
 * Revision 1.12  1996/11/21  06:31:45  hayakawa
 * TRUE,True,true,FALSE,False,falseを定義
 * 一部マクロをmath64.hに移動
 *
 * Revision 1.11  1996/11/07  02:38:44  hayakawa
 * 配列、ポインタ高速化マクロの追加
 *
 * Revision 1.10  1996/11/07  02:37:30  hayakawa
 * 型定義関連をu64types.hに移動した
 *
 * Revision 1.9  1996/10/20  09:22:57  hayakawa
 * _LANGUAGE_C_PLUS_PLUS を __cplusplus に変更
 *
 * Revision 1.8  1996/10/01  05:28:08  hayakawa
 * UPBOUND／DOWNBOUNDの追加
 *
 */

#ifndef __MACRO_H_
#define __MACRO_H_

/*
 * Misc constants
 */

#ifndef TRUE
#define TRUE			(0 == 0)
#endif
#ifndef FALSE
#define FALSE			(!TRUE)
#endif
#ifndef true
#define true TRUE
#endif
#ifndef True
#define True TRUE
#endif
#ifndef false
#define false FALSE
#endif
#ifndef False
#define False FALSE
#endif

/*
 * 高速化のためのマクロ
 */

/*
 * typeのサイズを２の対数にする
 * サイズが２のべき乗でなければならない
 * サイズは1,2,4,8,16,32,64,128,256のいずれかでなければならない
 * それ以外の場合は -1 を返す
 * 帰り値は int である
 */
#define _SIZE2LOG2(type, n, m) ((sizeof(type) == (1 << (n))) ? (n) : (m))
#define SIZE2LOG2(type) \
        _SIZE2LOG2(type, 0, \
        _SIZE2LOG2(type, 1, \
	_SIZE2LOG2(type, 2, \
	_SIZE2LOG2(type, 3, \
	_SIZE2LOG2(type, 4, \
	_SIZE2LOG2(type, 5, \
	_SIZE2LOG2(type, 6, \
	_SIZE2LOG2(type, 7, \
	_SIZE2LOG2(type, 8, \
	_SIZE2LOG2(type, 9, \
	_SIZE2LOG2(type, 10, \
        _SIZE2LOG2(type, 11, \
	_SIZE2LOG2(type, 12, \
	_SIZE2LOG2(type, 13, \
	_SIZE2LOG2(type, 14, \
	_SIZE2LOG2(type, 15, \
		   -1))))))))))))))))
//
/*
 * char*でないポインタとintの足し算を高速化する
 * t:ポインタがさす型(例:int *p なら int)
 * p:ポインタ値
 * i:加算する値
 */
#define XPOINTER(t, p, i) \
	((1 << -(sizeof(t) != sizeof(*(p)))), \
	 ((t *)((char *)(p) + ((i) << SIZE2LOG2(*(p))))))
//
/*
 * char*でないポインタとintの足し算を高速化する
 * t:ポインタ型(例:typedef int *(int_p) なら int_p)
 * p:ポインタ値
 * i:加算する値
 */
#define XPOINTER_P(t, p, i) \
	((1 << (sizeof(t) != sizeof(p))), \
	 ((t)((char *)(p) + ((i) << SIZE2LOG2(*(p))))))
//
/*
 * charでない１次元配列を高速化する
 * t:配列の型(例:int)
 * a:配列
 * i:添字
 */
#define XARRAY1(t, a, i) \
	((1 << (sizeof(t) != sizeof((a)[0]))), \
	 (*(t *)((char *)(a) + \
		 ((i) << SIZE2LOG2((a)[0])))))
//
/*
 * charでない２次元配列を高速化する
 * t:配列の型(例:int)
 * a:配列
 * i:添字1
 * j:添字2
 */
#define XARRAY2(t, a, i, j) \
	((1 << (sizeof(t) != sizeof((a)[0][0]))), \
	 (*(t *)((char *)(a) + \
		 ((i) << SIZE2LOG2((a)[0])) + \
		 ((j) << SIZE2LOG2((a)[0][0])))))
//
/*
 * charでない３次元配列を高速化する
 * t:配列の型(例:int)
 * a:配列
 * i:添字1
 * j:添字2
 * k:添字3
 */
#define XARRAY3(t, a, i, j, k) \
	((1 << (sizeof(t) != sizeof((a)[0][0][0]))), \
	 (*(t *)((char *)(a) + \
		 ((i) << SIZE2LOG2((a)[0])) + \
		 ((j) << SIZE2LOG2((a)[0][0])) + \
		 ((k) << SIZE2LOG2((a)[0][0][0])))))
//}

/*
 * 汎用のマクロなどの定義
 */
/*#define Max(a, b)	(((a) > (b)) ? (a) : (b))*/
/*#define Min(a, b)	(((a) < (b)) ? (a) : (b))*/
#ifndef MAX
#define MAX(a, b)	(((a) > (b)) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b)	(((a) < (b)) ? (a) : (b))
#endif
/*#define SGN(X)		(((X) > 0) ? 1 : (((X) == 0) ? 0 : -1))*/
#ifndef SGN
#define SGN(X)		(((X) > 0) - ((X) < 0)))
#endif

#define SSizeof(a)	((int)sizeof(a))
#define number(a)	(sizeof(a) / sizeof(a[0])) /* 配列の要素数を返す */
#define Number(a)	(sizeof(a) / sizeof(a[0])) /* 配列の要素数を返す */
#define SNumber(a)	(SSizeof(a) / SSizeof(a[0])) /* 配列の要素数を返す */

#define UPBOUND(n, b)	DOWNBOUND((unsigned long)(n) + (unsigned long)(b) - 1ul, b) /* バウンダリ切り上げ調整 */
#define DOWNBOUND(n, b)	((unsigned long)(n) & ~((unsigned long)(b) - 1ul)) /* バウンダリ切り捨て調整 */

#define WRAP(no, min, max) (((no) - (min) + ((max) - (min))) % ((max) - (min)))
#define CLAMP(no, min, max) (((no) < (min)) ? (min) : (((no) > (max)) ? (max) : (no)))

#if 0
/*
 * ビット操作
 * まだ仕様が固まっていない
 */
#define BIT_TEST(a, b)	(~((a)|~(b)) == 0) /* 3 nor, nor, sltiu */
#define BIT_SET(a, b)	((a) |= (b))
#define BIT_CLEAR(a, b)	((a) &= ~(b))
#endif

#endif
