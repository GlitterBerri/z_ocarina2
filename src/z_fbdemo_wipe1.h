/*
 * $Id: z_fbdemo_wipe1.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 *
 * ワイプデモ
 *
 * $Log: z_fbdemo_wipe1.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.8  1998/06/26 13:16:50  hayakawa
 * 構造体更新準備
 *
 * Revision 1.7  1998-04-23 19:33:35+09  hayakawa
 * alt_color追加
 *
 * Revision 1.6  1998-04-01 11:46:55+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.5  1997/11/12  13:27:34  hayakawa
 * fbdemo_wipe_startup追加
 *
 * ソース整理等
 *
 * Revision 1.4  1997/11/11  13:34:51  hayakawa
 * fbdemo_wipe1_setcolor_rgba8888
 *
 * Revision 1.3  1997/11/11  07:43:12  hayakawa
 * fbdemo_wipe.moveの引数変更
 *
 * Revision 1.2  1997/11/10  13:50:56  hayakawa
 * 射影行列に対応
 *
 * Revision 1.1  1997/11/08  08:17:49  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_FBDEMO_WIPE1_H_
#define _Z_FBDEMO_WIPE1_H_

#include "u64basic.h"

typedef struct {
    Mtx model_smtx;		/* スケーリング行列 */
    Mtx model_rmtx;		/* ローテート行列 */
    Mtx model_tmtx;		/* トランスレート行列 */
} fbdemo_wipe1_dynamic_t;

typedef struct {
#if 0
    rgba8888_u_t color;		/* 表示色 */
    rgba8888_u_t alt_color;	/* 変更色 */
    int Wipein;			/* !0:Wipein 0:Wipeout */
    int txt_s;			/* テクスチャスクロールＳ */
    int txt_t;			/* テクスチャスクロールＴ */
    u16 normal;
    Mtx project_mtx;		/* プロジェクション行列 */
    Mtx lookat_mtx;		/* プロジェクション行列 */
    int bank;			/* dynamicバンク */
    fbdemo_wipe1_dynamic_t dynamic[2];
    int finished;
#else
    rgba8888_u_t color;		/* 表示色 */
    rgba8888_u_t alt_color;	/* 変更色 */
    u8 Wipein;			/* !0:Wipein 0:Wipeout */
    u8 bank;			/* dynamicバンク */
    u8 finished;
    u8 __aligner;
    u16 txt_s;			/* テクスチャスクロールＳ */
    u16 txt_t;			/* テクスチャスクロールＴ */
    u16 normal;
    u16 __aligner16;
    Mtx project_mtx;		/* プロジェクション行列 */
    Mtx lookat_mtx;		/* プロジェクション行列 */
    fbdemo_wipe1_dynamic_t dynamic[2];
#endif
} fbdemo_wipe1_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
    extern fbdemo_wipe1_t *fbdemo_wipe1_init(fbdemo_wipe1_t *this);
    extern void fbdemo_wipe1_cleanup(fbdemo_wipe1_t *this);
    extern void fbdemo_wipe1_startup(fbdemo_wipe1_t *this);
    extern void fbdemo_wipe1_draw(fbdemo_wipe1_t *this, Gfx **gpp);
    extern void fbdemo_wipe1_move(fbdemo_wipe1_t *this, int frame);
    extern void fbdemo_wipe1_setcolor_rgba8888(fbdemo_wipe1_t *this, u32 c);
    extern void fbdemo_wipe1_setaltcolor_rgba8888(fbdemo_wipe1_t *this, u32 c);
    extern void fbdemo_wipe1_settype(fbdemo_wipe1_t *this, int t);
    extern void fbdemo_wipe1_setscaletype(fbdemo_wipe1_t *this, int t);
    extern int  fbdemo_wipe1_is_finish(fbdemo_wipe1_t *this);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C"  */
#endif

#endif /* _Z_FBDEMO_WIPE1_H_ */
