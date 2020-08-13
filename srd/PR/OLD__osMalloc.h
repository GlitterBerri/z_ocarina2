/*
 * $Id: OLD__osMalloc.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * ヒープ管理クラス(malloc)
 *
 * $Log: OLD__osMalloc.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.6  2000-12-19 16:16:32+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.5  2000-07-18 09:43:10+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.4  2000-07-14 18:32:24+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.3  1999-07-15 16:54:16+09  hayakawa
 * メッセージキューを利用したマルチスレッド対応のため、構造体を一部変更
 *
 * Revision 2.2  1999-05-14 16:13:12+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.14  1998-10-18 01:17:43+09  hayakawa
 * ばっちりでしょう by 山本雄一
 *
 * Revision 1.13  1998-06-18 13:18:19+09  hayakawa
 * __osMallocCleanup
 * __osMallocIsInitalized
 * 追加
 *
 * Revision 1.12  1998-06-12 11:58:12+09  hayakawa
 * GetFreeArenaをデバッグ状態に関係なく使えるようにした
 *
 * Revision 1.11  1998-06-10 21:33:01+09  hayakawa
 * 逆malloc追加
 *
 * Revision 1.10  1998-06-09 16:24:30+09  hayakawa
 * OSArena構造体にfailcnt,__dummyを追加
 *
 * Revision 1.9  1998-04-27 11:28:22+09  hayakawa
 * arenaチェック用にメンバ新設
 * アライメントサイズ用メンバ修正
 * 構造体サイズは変わらず
 *
 * Revision 1.8  1997-08-28 20:07:21+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.7  1997/03/05  05:01:15  hayakawa
 * gccのワーニングに対応
 *
 * Revision 1.6  1996/12/18  02:52:15  hayakawa
 * FINALROM と DEBUGを入れ替えた
 *
 * Revision 1.5  1996/12/18  02:35:50  hayakawa
 * コンパイルエラー対処
 * OSArenaメンバ追加
 *
 * Revision 1.4  1996/12/18  01:31:30  hayakawa
 * realloc追加
 * realloc,freeのDEBUGバージョンの追加
 *
 * Revision 1.3  1996/11/01  09:21:43  hayakawa
 * デバッグ情報にmalloc時刻を追加
 *
 * Revision 1.2  1996/10/25  14:03:23  hayakawa
 * __osで始まる関数をmallocから__osMallocに移した
 *
 * Revision 1.1  1996/10/24  07:52:47  hayakawa
 * Initial revision
 *
 */

#ifndef __OSMALLOC_H_
#define __OSMALLOC_H_

#include <ultra64.h>
#include <stddef.h>

#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#define _SIZE_T
#if (_MIPS_SZLONG == 32)
typedef unsigned int size_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef unsigned long size_t;
#endif
#endif /* !_SIZE_T */

/*
 * メモリーブロック構造体定義
 * FINAL_ROMが定義されているときは   sizeof(__OSMemBlock) == 16bytes
 * FINAL_ROMが定義されていないときは sizeof(__OSMemBlock) == 48bytes
 * となります。
 * ※不用意に外部からアクセスするとシステムが破綻する恐れがあるので注意してください。
 */
typedef struct __OSMemBlock_s {
    /*private:*/
    s16         mark;		/* magic cookie */
    s16         free;		/* !0:このメモリブロックは空きブロックである */
    s32         size;		/* ヘッダを除くメモリブロックサイズ */
    struct      __OSMemBlock_s *next; /* 次のメモリブロックヘッダへのポインタ */
    struct      __OSMemBlock_s *prev; /* 前のメモリブロックヘッダへのポインタ */
#if !defined(FINAL_ROM)
    const char 	*file;		/* __FILE__ */
    s32 	line;		/* __LINE__ */
    OSId/*s32*/	osid;		/* osGetThreadId() */
    struct OSArena_t *arena;	/* 従属するarenaのポインタ */
    OSTime/*u64*/ time;		/* osGetTime() */
    u32 	__dummy[2];
#endif
} __OSMemBlock;

/*
 * Arena
 * 32byte
 */
typedef struct OSArena_t {
    /*private:*/
    __OSMemBlock *start;		/* list of allocated blocks     */
    u8 *base;			/* ヒープ領域先頭ポインタ */
    OSMesgQueue lockQ;		/* ロック用キュー */
    u8 failcnt;			/* mallocがNULLを返した回数 */
    u8 initialzed;		/* !0:初期化した */
    u8 flags;
    u8 __dummy;
} OSArena;

#if defined(_LANGUAGE_C_PLUS_PLUS)
extern "C" {
#endif
#if 0
}
#endif

extern void __osMallocInit(OSArena *arena, u8 *base, s32 len);
extern void __osMallocCleanup(OSArena *arena);
extern void __osMallocAddBlock(OSArena *arena, u8 *base, s32 len);
extern int  __osMallocIsInitalized(OSArena *arena);
#if DEBUG
extern void *__osMalloc_DEBUG(OSArena *arena, size_t size, const char *file, int line);
extern void *__osMallocR_DEBUG(OSArena *arena, size_t size, const char *file, int line);
extern void *__osRealloc_DEBUG(OSArena *arena, void *ptr, size_t size, const char *file, int line);
extern void __osFree_DEBUG(OSArena *arena, void *ptr, const char *file, int line);
#endif /* DEBUG */
extern void *__osMalloc(OSArena *arena, size_t size);
extern void *__osMallocR(OSArena *arena, size_t size);
extern void *__osRealloc(OSArena *arena, void *ptr, size_t size);
extern void __osFree(OSArena *, void *ptr);
extern void __osGetFreeArena(OSArena *arena, size_t *max_size, size_t *free_size, size_t *alloc_size);
extern int __osCheckArena(OSArena *arena);
#if DEBUG
extern void __osDisplayArena(OSArena *arena);
#endif /* DEBUG */
extern void __osDisplayArena_OnFault(OSArena *arena);

#if !defined(FINAL_ROM)
extern int __osMallocGetFailCount(OSArena *arena);
#endif
extern int __osMalloc_FreeBlockTest_Enable;
#if !defined(FINAL_ROM)
extern int __osMalloc_IsDebugFillMallocF(OSArena *arena);
extern int __osMalloc_IsDebugFillFreeF(OSArena *arena);
extern int __osMalloc_IsDebugFillTestF(OSArena *arena);
extern void __osMalloc_SetDebugFillMallocF(OSArena *arena);
extern void __osMalloc_SetDebugFillFreeF(OSArena *arena);
extern void __osMalloc_SetDebugFillTestF(OSArena *arena);
extern void __osMalloc_ClearDebugFillMallocF(OSArena *arena);
extern void __osMalloc_ClearDebugFillFreeF(OSArena *arena);
extern void __osMalloc_ClearDebugFillTestF(OSArena *arena);
#define __osMalloc_IsDebugFillMalloc(arena)	__osMalloc_IsDebugFillMallocF(arena)
#define __osMalloc_IsDebugFillFree(arena)	__osMalloc_IsDebugFillFreeF(arena)
#define __osMalloc_IsDebugFillTest(arena)	__osMalloc_IsDebugFillTestF(arena)
#define __osMalloc_SetDebugFillMalloc(arena)	__osMalloc_SetDebugFillMallocF(arena)
#define __osMalloc_SetDebugFillFree(arena)	__osMalloc_SetDebugFillFreeF(arena)
#define __osMalloc_SetDebugFillTest(arena)	__osMalloc_SetDebugFillTestF(arena)
#define __osMalloc_ClearDebugFillMalloc(arena)	__osMalloc_ClearDebugFillMallocF(arena)
#define __osMalloc_ClearDebugFillFree(arena)	__osMalloc_ClearDebugFillFreeF(arena)
#define __osMalloc_ClearDebugFillTest(arena)	__osMalloc_ClearDebugFillTestF(arena)
#endif /* defined(FINAL_ROM) */

#if 0
{
#endif
#if defined(_LANGUAGE_C_PLUS_PLUS)
} /* extern "C" */
#endif

#endif /* __OSMALLOC_H_ */
