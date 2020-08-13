/*
 * $Id: cfbinfo.h,v 2.2 1998/10/27 11:06:41 hayakawa Exp $
 *
 * 表示画面の定義
 *
 * $Log: cfbinfo.h,v $
 * Revision 2.2  1998/10/27  11:06:41  hayakawa
 * スケール対応テスト
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.3  1998/05/01 03:01:29  hayakawa
 * include追加
 *
 * Revision 1.2  1997-03-17 09:55:45+09  hayakawa
 * cfbinfo_get_ScreenWidthマクロを追加
 *
 * Revision 1.1  1997/03/14  00:21:33  hayakawa
 * Initial revision
 *
 */

#ifndef __CFBINFO_H_
#define __CFBINFO_H_

#include <ultra64.h>
#include "sys_screen.h"		/* ScreenWidth, ScreenHeight */

typedef struct cfbinfo_s {
    void		*framebuffer;	/* 描画フレームバッファ */
    void		*swapbuffer;	/* !NULL:表示フレームバッファ */
    OSViMode		*vimode; 	/* !NULL:ビデオモード */
    u32			vispecial;
    u8			flag;		/* 表示待ち 表示中 描画中 アイドル 確保 */
    s8			life_max;	/* 表示保証フレーム数 */
    s8			life;		/* 表示保証残りフレーム数 */
    float		vixscale, viyscale; /* スケール */
} cfbinfo_t;

#define cfbinfo_get_ScreenWidth(this) (((this)->vimode ? (int)(this)->vimode->comRegs.width : (int)ScreenWidth))
#define cfbinfo_get_ScreenHeight(this) ((void)(this), (int)ScreenHeight)
#define cfbinfo_get_ScreenPixSizBit(this) (16)


#endif /* __CFBINFO_H_ */
