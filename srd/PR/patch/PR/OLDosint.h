/*
 * $Log: OLDosint.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.3  1998/04/01  02:36:54  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1997/03/05  10:50:30  hayakawa
 * c++対応
 * _Printf追加
 *
 * Revision 1.1  1997/02/05  11:25:54  hayakawa
 * Initial revision
 *
 */

#ifndef _OSINT_H_
#define _OSINT_H_

/**************************************************************************
 *                                                                        *
 *               Copyright (C) 1994, Silicon Graphics, Inc.               *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 **************************************************************************/

#include <stdarg.h>
#include <os.h>
#include <os_internal.h>
#include <ultraerror.h>
#include <ultralog.h>
#include <sptask.h>

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/***************************************
 *
 * Type definitions
 *
 */

typedef struct {
	OSMesgQueue	*messageQueue;
	OSMesg		message;
} __OSEventState;

typedef struct {
	OSThread *	next;
	OSPri		priority;
} __OSThreadTail;


/***************************************
 *
 * Macro definitions
 *
 */


/***************************************
 *
 * Extern function prototypes
 *
 */

/* export from assert.c */

extern void		__assert(const char *, const char *, int);

/* exports from cache.s */

extern void		__osConfigureCache(void);

/* exports from error.c */

extern OSErrorHandler	__osErrorHandler;

/* exports from exceptasm.s */

extern int		__osExceptionPreamble[];
extern void		__osPanic(void);
extern void		(*__osHwIntTable[])(void);

/* exports from exception.c */

extern void		__osInitializeException(void);

/* exports from probetlb.s */

extern u32		__osProbeTLB(void *);

/* exports from saveparameters.s */

extern void		__osSaveParameters(void);

/* exports from seteventmesg.c */

extern	__OSEventState	__osEventStateTab[];

/* exports from thread.c */

extern __OSThreadTail	__osThreadTail;
extern OSThread *	__osRunningThread;
extern OSThread	*	__osRunQueue;
extern OSThread	*	__osActiveQueue;
extern OSThread	*	__osFaultedThread;

extern void		__osEnqueueThread(OSThread **, OSThread *);
extern void		__osDequeueThread(OSThread **, OSThread *);
extern OSThread *	__osPopThread(OSThread **);

/* exports from threadasm.s */

extern void		__osCleanupThread(void);
extern void		__osDispatchThread(void);
extern void		__osEnqueueAndYield(OSThread **);

/* exports from timer.c */

extern OSTime		__osCurrentTime;
extern u32		__osBaseCounter;
extern u32		__osViIntrCount;
extern u32		__osTimerCounter;

extern OSTimer 		*__osTimerList;

extern void		__osTimerInterrupt(void);
extern void 		__osTimerServicesInit(void);
extern void 		__osSetTimerIntr(OSTime );
extern OSTime 		__osInsertTimer(OSTimer * );

/* exports from profile.c */

extern OSProf		*__osProfileList;
extern OSProf		*__osProfileListEnd;
extern u32		__osProfileOverflowBin;
extern OSTimer		__osProfTimer;
extern OSMesgQueue	__osProfTimerQ;

/* exports from io/ai.c */
extern int		__osAiDeviceBusy(void);

/* exports from io/devmgr.c */
extern void		__osDevMgrMain(void *);

/* exports from io/dp.c */
extern int		__osDpDeviceBusy(void);

/* exports from io/sp.c */
extern int		__osSpDeviceBusy(void);

/* exports from io/pi.c */
extern int		__osPiDeviceBusy(void);

/* exports from io/si.c */
extern int		__osSiDeviceBusy(void);

/* exports from io/vi.c */
extern void		__osViInit(void);

/* exports from log/log.c */
extern void 		__osLogWrite(OSLog *, s16, s16, va_list);

/*
 * hayakawa added
 */

int _Printf(void *(*)(void *, const char *, int), char *,  const char *, va_list);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif  /* _OSINT_H_ */

