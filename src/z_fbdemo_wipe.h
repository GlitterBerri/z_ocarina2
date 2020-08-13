/*
 * $Id: z_fbdemo_wipe.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 *
 *
 *
 * $Log: z_fbdemo_wipe.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1998/04/24 06:54:59  hayakawa
 * setaltcolorの追加
 *
 * Revision 1.1  1998-04-22 19:45:30+09  hayakawa
 * Initial revision
 *
 */


#ifndef INCLUDE_Z_FBDEMO_WIPE_H
#define INCLUDE_Z_FBDEMO_WIPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_fbdemo.h"		/* fbdemo */
#include "z_fbdemo_triforce.h"	/* fbdemo_triforce */
#include "z_fbdemo_wipe1.h"	/* fbdemo_wipe1 */
#include "z_fbdemo_wipe3.h"	/* fbdemo_wipe3 */
#include "z_fbdemo_fade.h"	/* fbdemo_fade */

typedef union {
    fbdemo_triforce_t 	fbdemo_triforce; /* トライフォースワイプ */
    fbdemo_wipe1_t 	fbdemo_wipe1; /* ギザギザワイプ */
    fbdemo_wipe3_t 	fbdemo_wipe3; /* 新型ワイプ */
    fbdemo_fade_t 	fbdemo_fade; /* フェードイン・アウト */
} fbdemo_wipe_sub_t;

typedef struct fbdemo_wipe_s {
    fbdemo_wipe_sub_t wipe;
    int type;
				/* 処理関数へのポインタ */
    fbdemo_wipe_sub_t *(*init)(fbdemo_wipe_sub_t *this);
    void (*cleanup)(fbdemo_wipe_sub_t *this);
    void (*move)(fbdemo_wipe_sub_t *this, int frame);
    void (*draw)(fbdemo_wipe_sub_t *this, Gfx **gpp);
    void (*startup)(fbdemo_wipe_sub_t *this);
    void (*settype)(fbdemo_wipe_sub_t *this, int t);
    void (*setcolor)(fbdemo_wipe_sub_t *this, u32 c);
    void (*setaltcolor)(fbdemo_wipe_sub_t *this, u32 c);
    int  (*is_finish)(fbdemo_wipe_sub_t *this);
} fbdemo_wipe_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* INCLUDE_Z_FBDEMO_WIPE_H */
