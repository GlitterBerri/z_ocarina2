/*
 * $Id: gamealloc.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * ゲームアロケーションクラス
 * malloc/freeができ、かつゲームクラス終了時に自動的に領域を解放する
 *
 * $Log: gamealloc.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.8  1998/06/24 13:57:06  hayakawa
 * *** empty log message ***
 *
 * Revision 1.7  1998-04-30 22:30:09+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-04-01 11:47:13+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.5  1998/03/23  05:54:48  hayakawa
 * extern "C" が２つあった
 *
 * Revision 1.4  1998/03/17  10:27:29  hayakawa
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.3  1997/10/01  14:16:27  hayakawa
 * gamealloc_malloc_DEBUG追加
 *
 * Revision 1.2  1997/02/06  07:24:46  hayakawa
 * Ｃ＋＋でコンパイルできるように変更
 *
 * Revision 1.1  1996/10/16  00:22:42  hayakawa
 * Initial revision
 *
 */

#ifndef __GAMEALLOC_H_
#define __GAMEALLOC_H_

#include "u64basic.h"

/*
 * 型定義
 */

typedef struct gamealloclist_s {
    struct gamealloclist_s   *next;          /* note: this must be first */
    struct gamealloclist_s   *prev;          /* note: this must be first */
    size_t alloc_size;		/* ヘッダを含まない確保サイズ */
    u32    dummy;
} gamealloclist_t;
typedef gamealloclist_t GameAllocList;

typedef struct gamealloc_s {
    GameAllocList list_head;
    GameAllocList *list_tail;
} gamealloc_t;
typedef gamealloc_t GameAlloc;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    /*
     * 関数プロトタイプ
     */

/*
 * 内容表示
 */
extern void gamealloc_display(GameAlloc *this);
/*
 * 領域確保
 */
extern void *gamealloc_malloc(GameAlloc *this, size_t siz);
/*
 * 領域解放
 */
extern void gamealloc_free(GameAlloc *this, void *ptr1);
/*
 * 終了
 * ゲームクラス終了時にコールする
 */
extern void gamealloc_cleanup(GameAlloc *this);
/*
 * 初期化
 * ゲームクラス初期化時にコールする
 */
extern void gamealloc_init(GameAlloc *this);

#define Gamealloc_malloc(siz) gamealloc_malloc(gamealloc, siz)
#define Gamealloc_free(ptr1) gamealloc_free(gamealloc, ptr1)

#if DEBUG
extern void *gamealloc_malloc_DEBUG(GameAlloc *this, size_t siz, const char *file, int line);
#define gamealloc_malloc(this, size) gamealloc_malloc_DEBUG(this, size, __FILE__, __LINE__)
#endif /* DEBUG */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __GAMEALLOC_H_ */
