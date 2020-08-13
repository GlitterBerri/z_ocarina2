/*
 * $Id: aprintf.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * アプリケーションＰＲＩＮＴ
 * ６４用表示関数使用の printf, vprintf
 *
 * 使い方の例は gfxprint.c を参照
 *
 * $Log: aprintf.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.2  1999-05-14 16:13:03+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.4  1998-04-01 11:40:27+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.3  1997/03/05  05:04:02  hayakawa
 * 型変更
 *
 * Revision 1.2  1996/12/18  02:36:18  hayakawa
 * 型がおかしいのを修正
 *
 * Revision 1.1  1996/12/18  02:08:40  hayakawa
 * Initial revision
 *
 */

#ifndef __APRINTF_H_
#define __APRINTF_H_

#include <stdarg.h>		/* va_list, va_start, va_end */

typedef struct aprintf_prout_s {
    void *(*prout_func)(void *, const char *, int); /* プリントアウト関数へのポインタ */
    /* この後ろは描画関数用のデータ */
} aprintf_prout_t;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

int vaprintf(aprintf_prout_t *a, const char *fmt, va_list ap);
int aprintf(aprintf_prout_t *a, const char *fmt, ...);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __APRINTF_H_ */
