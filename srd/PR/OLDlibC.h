/*
 * $Id: OLDlibC.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * C++関連のヘッダ
 *
 * $Log: OLDlibC.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.5  1996-10-24 15:25:22+09  hayakawa
 * マロック関係の分離
 *
 * Revision 1.4  1996/10/24  00:45:16  hayakawa
 * malloc のデバッグインターフェース修正
 *
 * Revision 1.3  1996/10/24  00:29:28  hayakawa
 * malloc に付加情報を追加
 *
 * Revision 1.2  1996/10/16  05:39:41  hayakawa
 * 外部リンケージの変更
 * いらない関数の排除
 *
 */

#ifndef __LIBC_H_
#define __LIBC_H_

#include "ultra64.h"
#include "u64types.h"

#ifdef _LANGUAGE_C_PLUS_PLUS

extern void* operator new(size_t size);
extern void operator delete(void *ptr);

extern "C" {
    
#endif
    
    void __pure_virtual_called( void );
    void __vec_ct(void *vec, int n, int size, void *f);
    void __vec_dt(void *vec, int n, int size, void *f);
    void *__vec_new(void *vec, int n, int size, void *f);
    void __vec_delete(void * vec, int n, int size, void * f, int del, int);
    void __CallLibGlobalCtors( void );
    void osInitializeCPP( u8 *base, s32 len ) ;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
