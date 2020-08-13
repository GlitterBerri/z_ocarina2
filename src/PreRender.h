/*
 * $Id: PreRender.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 * プリレンダリング処理
 * レンダリングされた画面をバッファに取り込み
 * それをテクスチャレクタングル命令で表示することにより、
 * 緻密な背景を高速に表示する。
 *
 * Ｚバッファやカバレッジにも対応している
 * ただし、dzは上位２ビットのみ
 *
 * $Log: PreRender.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.12  1998/06/26 12:49:59  hayakawa
 * *** empty log message ***
 *
 * Revision 1.11  1998-04-01 11:47:05+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.10  1997/10/17  14:07:50  hayakawa
 * 死んでいる処理をはずした
 *
 * Revision 1.9  1997/07/17  05:28:33  hayakawa
 * 不要メンバ削除
 *
 * Revision 1.8  1997/04/16  11:41:33  hayakawa
 * is_alloc_myselfメンバの追加（不要？）
 *
 * Revision 1.7  1997/04/14  11:59:33  hayakawa
 * listalloc追加
 *
 * Revision 1.6  1997/03/27  13:01:18  hayakawa
 * PreRender_ConvertFrameBuffer2追加
 * テスト用にfbufx_save追加
 *
 * Revision 1.5  1997/02/26  05:21:28  hayakawa
 * 内部形式変更
 *
 * Revision 1.4  1997/01/24  06:15:42  hayakawa
 * プロトタイプ追加
 *
 * Revision 1.3  1997/01/20  05:19:30  hayakawa
 * プロトタイプ追加
 *
 * Revision 1.2  1997/01/17  05:37:09  hayakawa
 * 小さい変更
 *
 * Revision 1.1  1997/01/14  00:51:00  hayakawa
 * Initial revision
 *
 */

#ifndef __PRERENDER_H_
#define __PRERENDER_H_

#include "ultra64.h"		/* rgba_t */
#include "listalloc.h"		/* listalloc_t */

/*
 * 型定義
 */
typedef struct {
#if 0
    unsigned short wd, ht;	/* フレームバッファの横／縦サイズ */
    unsigned short wd_save, ht_save; /* フレームバッファを保持する領域の横／縦サイズ */
    void *fbuf;			/* フレームバッファへのポインタ */
    void *fbuf_save;		/* フレームバッファを保持する領域 RGBA5551 */
    void *cvg_save;		/* カバレッジを保持する領域 A4/A8 */
    void *zbuf;			/* Ｚバッファへのポインタ */
    void *zbuf_save;		/* Ｚバッファを保持する領域 Z14DZ2 */
    unsigned short uls, ult, lrs, lrt;	/* 有効範囲 */
    unsigned short ulx, uly, lrx, lry;	/* 描画範囲 */
    listalloc_t listalloc;
    char is_alloc_myself;	/* !0:自分自身でアロケートした */
    char __aligner[3];		/* アライメント用 */
#else
    int wd, ht;			/* フレームバッファの横／縦サイズ */
    int wd_save, ht_save;	/* フレームバッファを保持する領域の横／縦サイズ */
    void *fbuf;			/* フレームバッファへのポインタ */
    void *fbuf_save;		/* フレームバッファを保持する領域 RGBA5551 */
    void *cvg_save;		/* カバレッジを保持する領域 A4/A8 */
    void *zbuf;			/* Ｚバッファへのポインタ */
    void *zbuf_save;		/* Ｚバッファを保持する領域 Z14DZ2 */
    int uls, ult, lrs, lrt;	/* 有効範囲 */
    int ulx, uly, lrx, lry;	/* 描画範囲 */
    listalloc_t listalloc;
    int is_alloc_myself;	/* !0:自分自身でアロケートした */
#endif
} PreRender_t;

#define PreRender_set_xoff(this) ((this)->xoff)



#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
    /*
     * 関数プロトタイプ
     */
 
/*
 * 初期化
 * ヒープ領域から337.5Kバイト使用する
 */
extern void
PreRender_init(PreRender_t *this);

/*
 * フレームバッファとＺバッファのポインタを設定する
 */
extern void
PreRender_setbuf(PreRender_t *this, void *fbuf, void *zbuf);
/*
 * バッファ設定
 */
extern void
PreRender_setup_savebuf(PreRender_t *this, int wd, int ht, void *fbuf, void *zbuf, void *cvgbuf);
/*
 * レンダリング用の
 * フレームバッファとＺバッファのポインタを設定する
 */
extern void
PreRender_setup_renderbuf(PreRender_t *this, int wd, int ht, void *fbuf, void *zbuf);

/*
 * 後始末
 */
extern void
PreRender_cleanup(PreRender_t *this);

/*
 * Ｚバッファ内容セーブ
 * Ｚバッファ→プリレンダー用Ｚバッファ
 */
extern void
PreRender_saveZBuffer(PreRender_t *this, Gfx **glistpp);

/*
 * フレームバッファ内容セーブ
 * フレームバッファ→プリレンダー用カラーバッファ
 */
extern void
PreRender_saveFrameBuffer(PreRender_t *this, Gfx **glistpp);

/*
 * カバレッジ内容セーブ
 * フレームバッファのカバレッジ→プリレンダー用カバレッジバッファ
 */
extern void
PreRender_saveCVG(PreRender_t *this, Gfx **glistpp);

/*
 * Ｚバッファ内容ロード
 * プリレンダー用Ｚバッファ→Ｚバッファ
 */
extern void
PreRender_loadZBuffer(PreRender_t *this, Gfx **glistpp);

/*
 * フレームバッファ内容ロード
 * プリレンダー用カラー＋プリレンダー用カバレッジバッファ→フレームバッファ
 */
extern void
PreRender_loadFrameBuffer(PreRender_t *this, Gfx **glistpp);

/*
 * アンチエリアスコンバート
 * プリレンダー用カラー＋プリレンダー用カバレッジバッファ→プリレンダー用カラー
 */
extern void
PreRender_ConvertFrameBuffer2(PreRender_t *this);

/*
 * フレームバッファ内容ロード
 * カラーのみ
 * プリレンダー用カラー→フレームバッファ
 */
extern void
PreRender_loadFrameBufferCopy(PreRender_t *this, Gfx **glistpp);

/*
 * フレームバッファ内容ロード
 * カラーのみ
 * カラーバッファがフレームバッファより大きい場合
 * プリレンダー用カラー→フレームバッファ
 */
extern void
PreRender_loadFrameBufferCopyX(PreRender_t *this, Gfx **glistpp);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __PRERENDER_H_ */
