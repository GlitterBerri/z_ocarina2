/*
 * $Id: sys_ddcache.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * ＤＤ簡易キャッシュシステム
 * シーンデータとルームデータのセグメントがすべて連続していると仮定している
 * ので注意すること
 *
 * $Log: sys_ddcache.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.3  1998/09/04 02:42:37  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1998-09-04 11:00:37+09  hayakawa
 * IF変更
 *
 * Revision 1.1  1998-06-19 21:06:51+09  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __SYS_DDCACHE_H_
#define __SYS_DDCACHE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "u64types.h"
    
    typedef struct DDCache_s {
	void *cache;		/* !NULL:キャッシュ先頭ポインタ(16B align) */
	u32 start;		/* 開始ROMアドレス */
	u32 end;		/* 終了ROMアドレス */
	u32 size;		/* キャッシュサイズ */
    } DDCache_t;
    typedef DDCache_t DDCache;
    
    extern void DDCache_SetCacheBuffer(DDCache *this, void *buffer, u32 size);
    extern void *DDCache_GetCacheBuffer(DDCache *this, void **buffer_p, u32 *size_p);
    extern int DDCache_ReadyCache(DDCache *this, u32 start, u32 end);
    extern void DDCache_Load(DDCache *this, void *dst, u32 src, u32 size);

    extern DDCache *DDCache_init(DDCache *this, void *buffer, u32 size);
    extern void DDCache_cleanup(DDCache *this);
    
    
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __SYS_DDCACHE_H_ */
