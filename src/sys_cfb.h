/*
 * $Id: sys_cfb.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * カラーフレームバッファ領域
 * バッファ数:３
 * １ドットのビット数:１６
 * 横ドット数:３２０
 * 縦ドット数:２４０
 *
 * 備考:今はサイズ固定になっているが,幅と高さを可変にできるようにしたい
 * $Log: sys_cfb.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1998/09/04 05:38:06  hayakawa
 * sys_cfb_initの引数追加
 *
 * Revision 1.6  1998-06-08 22:00:14+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.5  1998-04-30 20:53:06+09  hayakawa
 * 動的アドレスＣＦＢ
 *
 * Revision 1.4  1997-03-19 22:47:37+09  hayakawa
 * スクリーンサイズ情報を別ファイルにした
 *
 * Revision 1.3  1997/03/17  12:21:20  hayakawa
 * フレームバッファ数を２にした（正式）
 *
 */

#ifndef __SYS_CFB_H_
#define __SYS_CFB_H_

#include "u64basic.h"

#define SYS_CFB_TYPE	u16	/* 配列の要素の型 */
#define SYS_CFB_PIXBIT	16	/* １ドットのビット数:１６ */
#define SYS_CFB_MAX 	2	/* バッファ数:２ */
#define	SYS_CFB_WD	320	/* 横ドット数:３２０ */
#define	SYS_CFB_HT	240	/* 縦ドット数:２４０ */
#define	SYS_CFB_BOUND	64	/* バウンダリ:６４バイト */

extern void sys_cfb_init(int rammode); /* 0:4M 1:8M */
extern void sys_cfb_cleanup(void);
extern void *sys_cfb_getptr(int page);
extern void *sys_cfb_get_bottom(void);

#endif /* __SYS_CFB_H_ */
