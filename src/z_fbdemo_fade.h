/*
 * $Id: z_fbdemo_fade.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 *
 * フェードアウト
 *
 * $Log: z_fbdemo_fade.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.8  1998/06/26 13:13:24  hayakawa
 * 構造対抗心準備
 *
 * Revision 1.7  1998-04-01 11:46:57+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.6  1997/11/14  08:05:26  hayakawa
 * SREG(82)を使わないようにした
 *
 * Revision 1.5  1997/11/13  07:06:09  hayakawa
 * type追加
 *
 * Revision 1.4  1997/11/12  13:25:09  hayakawa
 * fbdemo_wipe_startup追加
 *
 * Revision 1.3  1997/11/11  07:43:45  hayakawa
 * fbdemo_wipe.moveの引数変更
 *
 * Revision 1.2  1997/11/11  05:06:37  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1997/11/11  01:26:10  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_FBDEMO_FADE_H_
#define _Z_FBDEMO_FADE_H_

#include "u64basic.h"

typedef struct {
#if 0
    int type;			/* 処理タイプ */
    int finished;		/* 完了フラグ */
    rgba8888_u_t color;		/* 表示色 */
    int frame;			/* フレーム数 */
    int frame_max;		/* 終了フレーム数 */
    int FadeIn;			/* !0:FadeIn */
    short SREG82;
#else
    unsigned char type;		/* 処理タイプ */
    unsigned char finished;	/* 完了フラグ */
    unsigned char FadeIn;	/* !0:FadeIn */
    unsigned char __aligner;	/*  */
    rgba8888_u_t color;		/* 表示色 */
    unsigned short frame;	/* フレーム数 */
    unsigned short frame_max;	/* 終了フレーム数 */
#endif
} fbdemo_fade_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
    extern fbdemo_fade_t *fbdemo_fade_init(fbdemo_fade_t *this);
    extern void fbdemo_fade_cleanup(fbdemo_fade_t *this);
    extern void fbdemo_fade_startup(fbdemo_fade_t *this);
    extern void fbdemo_fade_draw(fbdemo_fade_t *this, Gfx **gpp);
    extern void fbdemo_fade_move(fbdemo_fade_t *this, int frame);
    extern void fbdemo_fade_setcolor_rgba8888(fbdemo_fade_t *this, u32 c);
    extern void fbdemo_fade_settype(fbdemo_fade_t *this, int t);
    extern void fbdemo_fade_setscaletype(fbdemo_fade_t *this, int t);
    extern int  fbdemo_fade_is_finish(fbdemo_fade_t *this);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C"  */
#endif

#endif /* _Z_FBDEMO_FADE_H_ */
