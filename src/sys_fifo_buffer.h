/*
 * $Id: sys_fifo_buffer.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * ＲＣＰのＦＩＦＯバージョンマイクロコード用バッファ領域
 * SYS_FIFO_SIZEが大きいと速くなる
 *
 * $Log: sys_fifo_buffer.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/05/06 13:47:34  hayakawa
 * FIFOサイズ縮小
 *
 * Revision 1.3  1996-11-05 18:02:58+09  hayakawa
 * ＦＩＦＯバッファを１６０Ｋに変更
 *
 * Revision 1.2  1996/11/01  09:23:42  hayakawa
 * バッファのバイトサイズを128Kに増やした
 *
 */

#ifndef __SYS_FIFO_BUFFER_H_
#define __SYS_FIFO_BUFFER_H_

#include "u64basic.h"

#define SYS_FIFO_TYPE 	u64	/* バッファの配列の要素の型 */
#define SYS_FIFO_SIZE_MIN 0x400 /* バッファの最低サイズ (man osSpTaskStart) */
#ifndef SYS_FIFO_SIZE
//#define SYS_FIFO_SIZE 	0x28000 /* バッファのバイトサイズ(160K) */
//#define SYS_FIFO_SIZE 	0x20000 /* バッファのバイトサイズ(128K) */
#define SYS_FIFO_SIZE 	0x18000 /* バッファのバイトサイズ(96K) */
#endif
#define	SYS_FIFO_BOUND	16	/* バウンダリ:16バイト */

#if    SYS_FIFO_SIZE < SYS_FIFO_SIZE_MIN
#error SYS_FIFO_SIZE < SYS_FIFO_SIZE_MIN
#endif

extern SYS_FIFO_TYPE sys_fifo_buffer[SYS_FIFO_SIZE / sizeof(SYS_FIFO_TYPE)];

#if 0
extern void sys_fifo_init(void *buf, size_t siz);
extern void sys_fifo_cleanup(void);
extern void *sys_fifo_getptr(void);
#endif

#endif /* __SYS_FIFO_BUFFER_H_ */
