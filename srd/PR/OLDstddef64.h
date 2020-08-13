/*
 * $Id: OLDstddef64.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * $Log: OLDstddef64.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.3  2000-02-23 21:30:11+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  1999-05-14 16:12:01+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.5  1998-04-01 11:39:14+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.4  1996/11/21  06:38:42  hayakawa
 * c++ のときの NULLを0にした
 *
 */

#ifndef __STDDEF64_H_
#define __STDDEF64_H_

#ifndef NULL
/*
 * ANSI-C では, NULL は 0 または (void *)0 のどちらを定義してもよいので、
 * ポインタを強調し、潜在的なエラーを減少させるため (void *)0 を定義する
 * しかし、C++ においては型が厳密なので、0とする。
 */
#ifdef _LANGUAGE_C_PLUS_PLUS
#define NULL            0
#else
#define NULL		((void *)0)
#endif
#endif

#include <stddef.h>		/* ptrdiff_t, size_t, offsetof */

#endif /* __STDDEF64_H_ */
