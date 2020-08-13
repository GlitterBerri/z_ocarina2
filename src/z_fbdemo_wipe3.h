/*
 * $Id: z_fbdemo_wipe3.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 *
 * ワイプデモ
 *
 * $Log: z_fbdemo_wipe3.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1998/04/24 06:31:55  hayakawa
 * メンバ追加＆整理
 *
 * Revision 1.1  1998-04-22 23:13:31+09  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_FBDEMO_WIPE3_H_
#define _Z_FBDEMO_WIPE3_H_

#include "u64basic.h"

typedef struct {
    Mtx model_smtx;		/* スケーリング行列 */
    Mtx model_rmtx;		/* ローテート行列 */
    Mtx model_tmtx;		/* トランスレート行列 */
} fbdemo_wipe3_dynamic_t;

typedef struct {
    rgba8888_u_t color;		/* 表示色 */
    rgba8888_u_t alt_color;	/* 変更色 */
    int txt_s;			/* テクスチャスクロールＳ */
    int txt_t;			/* テクスチャスクロールＴ */
    int speed;			/* 速度 /3frame */
    u8  wipeType;		/* ワイプタイプ   0:Wipeout 1:Wipein */
    u8  colorType;		/* 色タイプ       0:白 1:黒 2:カスタム */
    u8  speedType;		/* 速度タイプ     0:標準速 1:低速 2:倍速 3:カスタム? */
    u8  textureNo;		/* テクスチャ番号 0-3 */
    u8  finished;		/* !0:ワイプ完了 */
    u8  bank;			/* dynamicバンク */
    u16 normal;
    Mtx project_mtx;		/* プロジェクション行列 */
    Mtx lookat_mtx;		/* プロジェクション行列 */
    void *texture;		/* テクスチャポインタ */
    fbdemo_wipe3_dynamic_t dynamic[2];
} fbdemo_wipe3_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
    extern fbdemo_wipe3_t *fbdemo_wipe3_init(fbdemo_wipe3_t *this);
    extern void fbdemo_wipe3_cleanup(fbdemo_wipe3_t *this);
    extern void fbdemo_wipe3_startup(fbdemo_wipe3_t *this);
    extern void fbdemo_wipe3_draw(fbdemo_wipe3_t *this, Gfx **gpp);
    extern void fbdemo_wipe3_move(fbdemo_wipe3_t *this, int frame);
    extern void fbdemo_wipe3_setcolor_rgba8888(fbdemo_wipe3_t *this, u32 c);
    extern void fbdemo_wipe3_setaltcolor_rgba8888(fbdemo_wipe3_t *this, u32 c);
    extern void fbdemo_wipe3_settype(fbdemo_wipe3_t *this, int t);
    extern void fbdemo_wipe3_setscaletype(fbdemo_wipe3_t *this, int t);
    extern int  fbdemo_wipe3_is_finish(fbdemo_wipe3_t *this);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C"  */
#endif

#endif /* _Z_FBDEMO_WIPE3_H_ */
