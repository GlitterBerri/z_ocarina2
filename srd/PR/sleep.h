/*
 * $Id: sleep.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * いわゆる sleep と愉快な仲間たち
 *
 * $Log: sleep.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.2  1999-05-14 16:12:13+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.3  1998-06-09 16:19:49+09  hayakawa
 * csleep 以外の sleep をマクロでなく、関数にした。
 * かつ引数の型を u32 に変更した。
 *
 * Revision 1.2  1998-04-30 10:26:51+09  hayakawa
 *
 * Revision 1.1  1996-11-18 15:06:31+09  hayakawa
 * Initial revision
 *
 */

#ifndef __SLEEP_H_
#define __SLEEP_H_

#include <ultra64.h>		/* OS_*SEC_TO_CYCLES */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    extern void csleep(OSTime sleep_time);
    extern void nsleep(u32 ns);
    extern void usleep(u32 us);
    extern void msleep(u32 ms);
    extern void sleep(u32 s);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __SLEEP_H_ */
