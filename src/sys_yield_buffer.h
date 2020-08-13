/*
 * $Id: sys_yield_buffer.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 * ＲＣＰのＹＩＥＬＤ用バッファ領域
 * $Log: sys_yield_buffer.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1996/11/01 04:56:23  hayakawa
 * ＲＣＳヘッダ変更
 *
 */

#ifndef __GRAPH_YIELD_BUFFER_H_
#define __GRAPH_YIELD_BUFFER_H_

#include "u64basic.h"

#define SYS_YIELD_TYPE 	u64	/* バッファの配列の要素の型 */
#define SYS_YIELD_SIZE 	OS_YIELD_DATA_SIZE /* バッファのバイトサイズ */
#define	SYS_YIELD_BOUND	16	/* バウンダリ:16バイト */

extern SYS_YIELD_TYPE sys_yield_buffer[SYS_YIELD_SIZE / sizeof(SYS_YIELD_TYPE)];

#endif /* __GRAPH_YIELD_BUFFER_H_ */
