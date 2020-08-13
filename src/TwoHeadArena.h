/*
 * $Id: TwoHeadArena.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * 双頭の闘技場
 *
 * このライブラリは、Ｃ＋＋から利用することで
 * 最大のパフォーマンスを発揮するように設計されている。
 *
 * 一定のサイズの領域を先頭と末尾から確保していく
 * 先頭からは連続的に確保する 常に realloc してるようなもの
 * 末尾からは断続的に確保する 高速 malloc  のようなもの
 * 個別の free は存在せず、常にすべてを同時に 解放する
 *
 * $Log: TwoHeadArena.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.10  1998/06/25 02:47:20  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1998-06-25 10:23:29+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.8  1998-06-24 23:01:02+09  hayakawa
 * アライメント全面修正
 * THA_alloc16追加
 * THA_allocAlign追加
 *
 * Revision 1.7  1998-06-24 17:38:11+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-04-30 22:36:52+09  hayakawa
 * ソース整理
 *
 * Revision 1.5  1998-04-02 18:05:20+09  hayakawa
 * Ｃ＋＋のときにインライン関数バージョンになるようにした
 *
 * Revision 1.4  1998/04/01  02:47:28  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.3  1996/10/09  05:30:17  hayakawa
 * 先頭ポインタの設定ができるように THA_setHeadPtr 関数を追加した
 *
 */

#ifndef __TWOHEADARENA_H_
#define __TWOHEADARENA_H_

#include "u64types.h"

typedef struct TwoHeadArena_s {
    size_t size;		/* バッファサイズ */
    char *buf_p;		/* バッファ先頭ポインタ */
    char *head_p;		/* 順アロケーションポインタ */
    char *tail_p;		/* 逆アロケーションポインタ */
} TwoHeadArena_t;
typedef TwoHeadArena_t TwoHeadArena;
typedef TwoHeadArena_t THA;


#if defined(_LANGUAGE_C_PLUS_PLUS) && !defined(__TWOHEADARENA_C_)

inline void *
THA_getHeadPtr(TwoHeadArena *this)
{ return this->head_p; }

inline void
THA_setHeadPtr(TwoHeadArena *this, void *p)
{ this->head_p = (char *)p; }

inline void *
THA_getTailPtr(TwoHeadArena *this)
{ return this->tail_p; }

inline void *
THA_nextPtrN(TwoHeadArena *this, size_t n)
{ char *head_p1 = this->head_p; this->head_p += n; return head_p1; }

inline void *
THA_nextPtr1(TwoHeadArena *this)
{ return THA_nextPtrN(this, 1); }

inline void *
THA_alloc(TwoHeadArena *this, size_t siz)
{
    int mask;

    if (siz == 8) {
	mask = ~(8-1);
    } else if (siz == 4 || siz == 12) {
	mask = ~(4-1);
    } else if (siz == 2 || siz == 6 || siz == 10 || siz == 12 || siz == 14) {
	mask = ~(2-1);
    } else if (siz >= 16) {
	mask = ~(16-1);
    } else {
	mask = 0;
    }
    this->tail_p = (char *)((((int)this->tail_p & mask) - siz) & mask); /* align mask */
    return this->tail_p;
}

inline void *
THA_alloc16(TwoHeadArena *this, size_t siz)
{
    const int mask = ~(15-1); /* align 16 */
    this->tail_p = (char *)((((int)this->tail_p & mask) - siz) & mask);
    return this->tail_p;
}

inline void *
THA_allocAlign(TwoHeadArena *this, size_t siz, int mask)
{
    this->tail_p = (char *)((((int)this->tail_p & mask) - siz) & mask);
    return this->tail_p;
}

inline int
THA_getFreeBytes(TwoHeadArena *this)
{ return (int)this->tail_p - (int)this->head_p; }

inline int
THA_isCrash(TwoHeadArena *this)
{ return THA_getFreeBytes(this) < 0; }

inline void
THA_init(TwoHeadArena *this)
{ this->head_p = this->buf_p; this->tail_p = this->buf_p + this->size; }

inline void
THA_ct(TwoHeadArena *this, char *p, size_t n)
{
    this->buf_p = p;
    this->size = n;
    THA_init(this);
}

inline void
THA_dt(TwoHeadArena *this)
{ bzero(this, sizeof(TwoHeadArena)); }

#else  /* !(defined(_LANGUAGE_C_PLUS_PLUS) && !defined(__TWOHEADARENA_C_)) */

/* コンストラクタ */
extern void THA_ct(TwoHeadArena *this, char *p, size_t n);
/* デストラクタ */
extern void THA_dt(TwoHeadArena *this);
/* 現在の順ポインタの取得 */
extern void *THA_getHeadPtr(TwoHeadArena *this);
/* 現在の順ポインタの設定 */
extern void THA_setHeadPtr(TwoHeadArena *this, void *p);
/* 現在の逆ポインタの取得 */
extern void *THA_getTailPtr(TwoHeadArena *this);
/* Ｎ個の順メモリのアロケーション */
extern void *THA_nextPtrN(TwoHeadArena *this, size_t n);
/* １個の順メモリのアロケーション */
extern void *THA_nextPtr1(TwoHeadArena *this);
/* 逆メモリのアロケーション */
extern void *THA_alloc(TwoHeadArena *this, size_t siz);
extern void *THA_alloc16(TwoHeadArena *this, size_t siz);
extern void *THA_allocAlign(TwoHeadArena *this, size_t siz, int mask);
/* 領域破壊を起こしているかをチェック */
extern int THA_isCrash(TwoHeadArena *this);
/* 領域初期化（free） */
extern void THA_init(TwoHeadArena *this);
/* 残りのアロケーションメモリのバイト数を返す */
extern int THA_getFreeBytes(TwoHeadArena *this);

#endif  /* !(defined(_LANGUAGE_C_PLUS_PLUS) && !defined(__TWOHEADARENA_C_)) */

#endif /* __TWOHEADARENA_H_ */
