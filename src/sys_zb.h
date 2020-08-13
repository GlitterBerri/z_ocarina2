/* $Id: sys_zb.h,v 2.1 1998/10/22 11:41:56 zelda Exp $ */

/*
 * Ｚバッファ領域
 * １ドットのビット数:１６（固定）
 * 横ドット数:３２０ドット（カラーフレームバッファと同じ）
 * 縦ドット数:２４０ドット（カラーフレームバッファと同じ）
 *
 * 備考:今はサイズ固定になっているが,幅と高さを可変にできるようにしたい
 */

#ifndef __SYS_ZB_H_
#define __SYS_ZB_H_

#include "u64basic.h"
#include "sys_cfb.h"

#define SYS_ZB_TYPE	u16	/* 配列の要素の型 */
#define SYS_ZB_PIXBIT	16	/* １ドットのビット数:１６ */
#define	SYS_ZB_WD	SYS_CFB_WD	/* 横ドット数 */
#define	SYS_ZB_HT	SYS_CFB_HT	/* 縦ドット数 */
#define	SYS_ZB_BOUND	64	/* バウンダリ:６４バイト？ */

extern SYS_ZB_TYPE sys_zb[SYS_ZB_HT][SYS_ZB_WD]; 

#endif /* __SYS_ZB_H_ */
