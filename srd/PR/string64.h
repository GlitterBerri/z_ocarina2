/*
 * $Id: string64.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * $Log: string64.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.1  1996/11/18  06:06:50  hayakawa
 * Initial revision
 *
 * Revision 1.5  1996/10/20  09:17:35  hayakawa
 * _LANGUAGE_C_PLUS_PLUS を __cplusplus に変更
 *
 */

#ifndef __STRING64_H_
#define __STRING64_H_

#include "string.h"		/* /usr/include/string.h */

#ifdef __cplusplus
extern "C" {
#endif

void *memchr(const void *region, int character, size_t n);
void *memcpy(void *s1, const void *s2, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *s1, const void *s2, size_t n);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __STRING64_H_ */
