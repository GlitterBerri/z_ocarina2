/*
 * $Id: ThreadPriority.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * スレッド優先順位を定義する
 * この値は、注意深く決めなければならない
 *
 * $Log: ThreadPriority.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.11  1998/10/19 07:19:44  hayakawa
 * PRIORITY_DDMSGの優先度をPRIORITY_N64DDと同じにした
 *
 * Revision 1.10  1998-10-06 23:13:41+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1998-10-06 17:31:10+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.8  1998-09-14 23:01:46+09  hayakawa
 * PRIORITY_N64DDの優先度を下げた
 *
 * Revision 1.7  1998-07-03 16:23:31+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-04-28 21:06:39+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.5  1998-04-21 22:39:15+09  hayakawa
 * 64DD用変更
 *
 * Revision 1.4  1997-11-08 17:20:15+09  hayakawa
 * PRIORITY_IRQMGR
 *
 * Revision 1.3  1996/10/12  08:12:28  hayakawa
 * ヘッダの変更
 *
 */

#ifndef __THREADPRIORITY_H_
#define __THREADPRIORITY_H_

#undef USE_DDMEDIUM		/* 問題解決しなかったので結局使わない */

typedef enum threadpriority_e {
#if defined(USE_DDMEDIUM)
    PRIORITY_DDMEDIUM = 13,
#endif /* defined(USE_DDMEDIUM) */
    PRIORITY_MAIN = 10,		/* 処理あり */
    PRIORITY_GRAPH,		/* 処理あり */
    PRIORITY_AUDIO,		/* 処理あり */
    PRIORITY_N64DD,		
    PRIORITY_DDMSG = PRIORITY_N64DD, /* GRAPH,AUDIO,N64DD画止まってる状態でのみ処理あり */
    PRIORITY_PADMGR,
    PRIORITY_SCHEDULER,
    PRIORITY_DMAMGR,		
    PRIORITY_IRQMGR,		
    PRIORITY_FAULTMGR,		/* もっとも高い必要がある */
    PRIORITY_MSGMGR,		/* もっとも高い必要がある */
    PRIORITY_MAX
} threadpriority_t;

#endif
