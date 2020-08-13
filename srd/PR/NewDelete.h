/*
 * $Id: NewDelete.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * Ｃ言語用Ｃ＋＋風アロケーションマクロ
 *
 * NEW/New:コンストラクタを呼び出さない new
 * DELETE/Delete:デストラクタを呼び出さない delete
 * NEWA/NewA:NEW/New の配列対応バージョン
 * DELETEA/DeleteA:DELETE/Delete の配列対応バージョン
 *
 * $Log: NewDelete.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.2  2000-02-01 22:16:33+09  hayakawa
 * malloc.hをincludeするようにした
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.2  1998-04-01 11:42:22+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.1  1997/04/14  05:02:37  hayakawa
 * Initial revision
 *
 */

#ifndef __NEWDELETE_H_
#define __NEWDELETE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <malloc.h>		/* malloc/free */
    
    /*
     * 使用例:
     *
     * int (*a)[10] = NewA(int, [10]);
     * int *b = New(int);
     * delete(b);
     * deleteA(a);
     */
    
#define NEWA(type, array) ((type(*)array)malloc(sizeof(type array)))
#define DELETEA(ptr) 	free(ptr)
#define NEW(type) 	NEWA(type,)
#define DELETE(ptr) 	DELETEA(ptr)
#define NewA(type, array) NEWA(type)
#define DeleteA(ptr) 	DELETEA(ptr)
#define New(type) 	NEW(type)
#define Delete(ptr) 	DELETE(ptr)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __NEWDELETE_H_ */
