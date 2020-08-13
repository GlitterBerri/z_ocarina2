/*
 * $Id: assert64.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 * $Log: assert64.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.3  2001-02-07 11:58:23+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  2001-02-07 11:56:57+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.6  1998-04-01 11:40:23+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.5  1997/11/19  10:24:22  hayakawa
 * assert_modeで内部でabortするかどうか決めるようにした
 *
 * Revision 1.4  1997/03/14  04:29:17  hayakawa
 * libc64に移動
 * NDEBUG定義時に引数を評価しないように変更(ANSI-C)
 *
 * Revision 1.3  1997/02/07  10:55:55  hayakawa
 * BATCH
 *
 * Revision 1.2  1996/11/21  05:06:59  hayakawa
 * NDEBUGのときに、ワーニングを出さないようにする
 *
 */

#ifndef __ASSERT64_H__
#define __ASSERT64_H__

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#ifdef NDEBUG
    
#define assert(ignore)		/* （副作用に注意） */

#else /* NDEBUG */

extern int __assert_mode;	/* 0:call abort() 1:none */
extern void __assert64(const char *, const char *, int); /* __assert_mode==0なら内部でabortする */
#if defined(__STDC__)
#define assert(EX)  ((EX) ? ((void)0) : __assert64( # EX , __FILE__, __LINE__))
#else
#define assert(EX)  ((EX) ? ((void)0) : __assert64("EX", __FILE__, __LINE__))
#endif

#endif /* NDEBUG */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __ASSERT64_H__ */
