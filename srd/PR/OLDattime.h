/*
 * $Id: OLDattime.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * 一定時間後に関数を発動する
 *
 * $Log: OLDattime.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.3  1998-04-01 11:42:21+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1997/02/07  10:42:37  hayakawa
 * 時限式発動関数
 *
 * Revision 1.1  1996/12/18  01:05:55  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __ATTIME_H_
#define __ATTIME_H_

#include "u64types.h"		/* rgba_t */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

typedef struct attime_s {
    void (*func)(void *);
    void *arg;
    OSThread *Thread;
    OSTimer   timer;		/* オプション */
} attime_t;
typedef attime_t Attime;

void attime_cleanup(Attime *this);
void attime_init(Attime *this);
void attime_SetTimer(Attime *this, OSTime countdown, OSTime interval);
void attime_entry_func(Attime *this, void (*func)(void *), void *arg);
void attime_CreateThread(Attime *this, OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri);
void attimeproc_init(void);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __ATTIME_H_ */
