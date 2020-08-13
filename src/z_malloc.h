/*
 * $Id: z_malloc.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 * ゼルダ用ヒープ関数群
 * ゲーム中にヒープを初期化しながら使用する
 * 
 * ・使用する前に必ず zelda_InitArena で初期化してください
 * ・zelda_malloc した領域 zelda_free で解放してください。
 * ・ヒープ領域を解放(再初期化)したときは,それ以前に zelda_malloc した領域を
 *   使用してはいけません。
 *
 * $Log: z_malloc.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.10  1998/07/03 05:06:02  hayakawa
 * いろいろ整理
 *
 * Revision 1.9  1998-06-25 20:11:00+09  hayakawa
 * DEBUGバージョンが非DEBUGバージョンになるようにマクロを追加
 *
 * Revision 1.8  1998-06-18 13:39:49+09  hayakawa
 * zelda_CheckArena
 * をデバッグ以外でも使えるようにした
 * zelda_MallocIsInitalized
 * zelda_CleanupArena
 * 追加
 *
 * Revision 1.7  1998-06-12 11:58:37+09  hayakawa
 * GetFreeArenaをデバッグ状態に関係なく使えるようにした
 *
 * Revision 1.6  1998-06-10 21:42:38+09  hayakawa
 * 逆malloc追加
 *
 * Revision 1.5  1998-06-08 22:00:28+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-04-01 11:46:28+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.3  1998/03/25  11:53:27  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.2  1998/02/11  06:41:28  hayakawa
 * アルファ版完成
 *
 * Revision 1.1  1998/02/11  05:52:52  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_MALLOC_H_
#define __Z_MALLOC_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*
 * size_t 型
 */
#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#define _SIZE_T
#if (_MIPS_SZLONG == 32)
typedef unsigned int 	size_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef unsigned long 	size_t;
#endif
#endif

/*
 * ヒープ初期化関数
 * zelda_mallocなどの関数を使う前に必ず初期化を必要とします
 *
 * base ヒープ領域先頭ポインタ
 * len  ヒープ領域バイトサイズ
 * base, len ともに16の倍数にしてください
 */
extern void zelda_InitArena(void *base, size_t len);
extern void zelda_CleanupArena(void);

/*
 * zelda_MallocIsInitalized ヒープが初期化されているか？
 * zelda_GetFreeArena ヒープの空きサイズの調査
 * zelda_CheckArena   ヒープの整合性調査
 */
extern int  zelda_MallocIsInitalized(void);
extern void zelda_GetFreeArena(size_t *max_size, size_t *free_size, size_t *alloc_size);
extern int  zelda_CheckArena(void);

/*
 * zelda_malloc
 * zelda_malloc_r (逆malloc)
 * zelda_realloc
 * zelda_free
 * zelda_calloc
 *
 * それぞれ、標準関数の malloc, malloc_r, realloc, free, calloc に相当します。
 */
#if !DEBUG
extern void *zelda_malloc(size_t size);
extern void *zelda_malloc_r(size_t size);
extern void *zelda_realloc(void *ptr, size_t size);
extern void zelda_free(void *ptr);
extern void *zelda_calloc(size_t nelem, size_t elsize);
#else
extern void *zelda_malloc_DEBUG(size_t size, const char *file, int line);
extern void *zelda_malloc_r_DEBUG(size_t size, const char *file, int line);
extern void *zelda_realloc_DEBUG(void *ptr, size_t size, const char *file, int line);
extern void zelda_free_DEBUG(void *ptr, const char *file, int line);
#endif

#ifndef __Z_MALLOC_C_
#if !DEBUG
#define zelda_malloc_DEBUG(size, file, line) \
	zelda_malloc(size)
#define zelda_malloc_r_DEBUG(size, file, line) \
	zelda_malloc_r(size)
#define zelda_realloc_DEBUG(ptr, size, file, line) \
	zelda_realloc(ptr, size)
#define zelda_free_DEBUG(ptr, file, line) \
	zelda_free(ptr)
#else
#define zelda_malloc(size) \
	zelda_malloc_DEBUG(size, __FILE__, __LINE__)
#define zelda_malloc_r(size) \
	zelda_malloc_r_DEBUG(size, __FILE__, __LINE__)
#define zelda_realloc(ptr, size) \
	zelda_realloc_DEBUG(ptr, size, __FILE__, __LINE__)
#define zelda_free(ptr) \
	zelda_free_DEBUG(ptr, __FILE__, __LINE__)
#endif
#endif /* __Z_MALLOC_C_ */

#if DEBUG
/*
 * zelda_DisplayArena ヒープ内容の表示
 */
extern void zelda_DisplayArena(void);

extern int zelda_malloc_verbose;	/* 0:なし 1:エラー 2:警告 3:情報 */

#endif /* DEBUG */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_MALLOC_H_ */
