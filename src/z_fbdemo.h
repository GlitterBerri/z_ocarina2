/*
 * $Id: z_fbdemo.h,v 2.1 1998/10/22 12:17:25 zelda Exp $
 *
 * ゼルダ６４ の Ｄフレームバッファデモ
 *
 * $Log: z_fbdemo.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1998/09/07 02:46:36  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-04-01 11:46:58+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.5  1997/10/03  14:18:42  hayakawa
 * fbdemo_triforceとの分離
 *
 * Revision 1.4  1997/10/03  05:09:15  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1997/10/01  14:16:01  hayakawa
 * 関数プロトタイプ変更
 *
 * Revision 1.2  1997/09/30  13:45:09  hayakawa
 * トライフォースフィルタ処理
 *
 * Revision 1.1  1997/09/24  00:59:45  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_FBDEMO_H_
#define _Z_FBDEMO_H_

#include "u64basic.h"

typedef struct {
    int row;			/* ポリゴンの横数=10 */
    int col;			/* ポリゴンの縦数=7 */
    int bank;			/* 0:BankA 1:BankB */
    xy_t *xy_tbl;		/* 計算用頂点テーブル */
    Vtx *vtxtbl_A;		/* 描画用頂点テーブル BankA */
    Vtx *vtxtbl_B;		/* 描画用頂点テーブル BankB */
    Mtx project_mtx;
    Mtx model_mtx_A;		/* モデリング行列 BankA */
    Mtx model_mtx_B;		/* モデリング行列 BankB */
    Gfx *gfxtbl;		/* ディスプレイリスト領域 */
    u64 *txtbuf;		/* テクスチャポインタ */
} fbdemo_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
extern fbdemo_t *fbdemo_init(fbdemo_t *this, int row, int col);
extern void fbdemo_cleanup(fbdemo_t *this);
extern void fbdemo_draw(fbdemo_t *this, Gfx **gpp);
extern void fbdemo_move(fbdemo_t *this);
extern int fbdemo_is_finish(fbdemo_t *this);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
