/*
 * $Id: u64uty.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * ６４ＯＳ用ミニユーティリティ関数集
 *
 * $Log: u64uty.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.3  2001-02-05 21:53:52+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  2001-02-01 20:12:10+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.3  1998-04-01 11:40:29+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1997/04/09  10:07:53  hayakawa
 * osContInitXの追加
 *
 * Revision 1.1  1997/03/05  05:33:24  hayakawa
 * Initial revision
 *
 */

#ifndef __U64UTY_H_
#define __U64UTY_H_

#include <ultra64.h>

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
#if 0
}
#endif
    
extern void KillRspRdp(void);		/* RSP/RDPを強制停止させる */
extern s32 osContInitX(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *status); /* 必ずステータスを取得する */

/*
 * 以下の関数は osGetTime() の補助として使用します。
 * ただし、返り値が u32 なので osGetTime() と同じ値を保持しているわけではありません
 * 各関数間の値も必ずしも1000倍の関係を保つという保証はどこにもありません。
 * 少なくとも電源投入後 4.3 秒以上経過している場合は
 * utGetTime_us() ≒ utGetTime_ns() / 1000
 * の関係すら成り立たないことを覚えておいてください。
 *
 * 結局 91.62453秒以下の時間を計るなら osGetCOunt() を使うのが一番てこと
 * でも比較する秒数をマクロで変換しないとダメよ！こんな風に。
 *
 * static u32 start;
 * u32 now = osGetCOunt();
 * if (now - start > OS_USEC_TO_CYCLES(90*1000*1000)) {
 *     osSyncPrintf("90秒経過\n");
 * }
 *
 */
extern u32 utGetTime_s(void);   /* 0-4294967296 s(136years + alpha */
extern u32 utGetTime_ms(void);  /* 0-4294967.296s(49days + 17:2:47) */
extern u32 utGetTime_us(void);  /* 0-4294.967296s(1:11:34) */
extern u32 utGetTime_ns(void);  /* 0-4.294967296s */

#if 0
{
#endif
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __U64UTY_H_ */
