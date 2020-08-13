/*
 * $Id: z_fbdemo_triforce.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 *
 * ゼルダ６４ の フレームバッファデモ（トライフォース）
 *
 * $Log: z_fbdemo_triforce.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1998/04/01 02:46:56  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.6  1997/11/12  13:24:54  hayakawa
 * fbdemo_wipe_startup追加
 *
 * Revision 1.5  1997/11/11  07:43:01  hayakawa
 * fbdemo_wipe.moveの引数変更
 *
 * Revision 1.4  1997/11/07  10:37:55  hayakawa
 * fbdemo_triforce_setscaletype
 *
 * Revision 1.3  1997/11/07  05:59:34  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1997/10/16  11:15:11  hayakawa
 * 回転
 *
 * Revision 1.1  1997/10/03  14:19:08  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_FBDEMO_TRIFORCE_H_
#define _Z_FBDEMO_TRIFORCE_H_

#include "u64basic.h"

typedef struct {
    Mtx model_smtx;		/* スケーリング行列 */
    Mtx model_rmtx;		/* ローテート行列 */
    Mtx model_tmtx;		/* トランスレート行列 */
} fbdemo_triforce_dynamic_t;

typedef struct {
    rgba8888_u_t color;		/* 表示色 */
    float rate;			/* 1.0:最大 0.0:最小 */
    float rate_speed;		/* 速度 */
    int scale_type;		/* 0:通常縮小 1:反転縮小 2:通常拡大 3:反転拡大 */
    int tri_type;		/* 1:通常 2:反転 */
    Mtx project_mtx;		/* プロジェクション行列 */
    int bank;			/* dynamicバンク */
    fbdemo_triforce_dynamic_t dynamic[2];
} fbdemo_triforce_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
    fbdemo_triforce_t *fbdemo_triforce_init(fbdemo_triforce_t *this);
    void fbdemo_triforce_cleanup(fbdemo_triforce_t *this);
    void fbdemo_triforce_startup(fbdemo_triforce_t *this);
    void fbdemo_triforce_draw(fbdemo_triforce_t *this, Gfx **gpp);
    void fbdemo_triforce_move(fbdemo_triforce_t *this, int frame);
    void fbdemo_triforce_setcolor_rgba8888(fbdemo_triforce_t *this, u32 c);
    void fbdemo_triforce_settype(fbdemo_triforce_t *this, int t);
    void fbdemo_triforce_setscaletype(fbdemo_triforce_t *this, int t);
    int  fbdemo_triforce_is_finish(fbdemo_triforce_t *this);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C"  */
#endif

#endif /* _Z_FBDEMO_TRIFORCE_H_ */
