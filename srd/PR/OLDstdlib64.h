/*
 * $Id: OLDstdlib64.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * $Log: OLDstdlib64.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.2  2000-08-02 14:19:09+09  hayakawa
 * ２重宣言になっているところを修正
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.8  1998-04-01 11:37:20+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.7  1997/03/26  06:36:17  hayakawa
 * EXIT_FAILURE,EXIT_SUCCESS,RAND_MAX,div_t,ldiv_t,lldiv_t
 * wchar_t,__ctype,atof,atoi,atol,strtod,strtol,strtoul,atoll,strtoll,strtoull
 * rand,srand,abort,bsearch,qsort,abs
 * div,labs,ldiv,lldiv,mbtowc,mblen,wctomb,mbstowcs,wcstombs,mblenを追加
 *
 * Revision 1.6  1996/12/18  02:04:58  hayakawa
 * malloc,free,reallocの宣言を#include "malloc.h"に置き換え
 *
 * Revision 1.5  1996/12/02  02:25:30  hayakawa
 * 副作用を考えて、Absー＞ABSに変更
 *
 * Revision 1.4  1996/10/20  09:16:59  hayakawa
 * _LANGUAGE_C_PLUS_PLUS を __cplusplus に変更
 *
 */

#ifndef __STDLIB64_H_
#define __STDLIB64_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/* Arguments to exit(2). */
#define EXIT_FAILURE	1
#define EXIT_SUCCESS	0

/* Maximum value returned by rand(3C). */
#define RAND_MAX	32767

#if (defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS))
typedef	struct {
	 int	quot;
	 int	rem;
	} div_t;

typedef struct {
	 long	quot;
	 long	rem;
	} ldiv_t;

#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
typedef struct {
	 long long	quot;
	 long long	rem;
	} lldiv_t;
#endif

#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#define _SIZE_T
#if (_MIPS_SZLONG == 32)
typedef unsigned int	size_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef unsigned long	size_t;
#endif
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
#if (_MIPS_SZLONG == 32)
typedef int	ssize_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef long	ssize_t;
#endif
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
#if (_MIPS_SZLONG == 32)
typedef long wchar_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef __int32_t wchar_t;
#endif
#endif

extern unsigned char 	__ctype[];	

#define MB_CUR_MAX	(int)__ctype[520]	

extern double atof(const char *);
extern int atoi(const char *);
extern long int atol(const char *);
extern double strtod(const char *, char **);
extern long int strtol(const char *, char **, int);
extern unsigned long int strtoul(const char *, char **, int);
#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
extern long long int atoll(const char *);
extern long long int strtoll(const char *, char **, int);
extern unsigned long long int strtoull(const char *, char **, int);
#endif

#include "rand.h"		/* rand,qrand,rand_r */
#include "qrand.h"		/* qrand,sqrand,fqrand */

#include "malloc.h"		/* malloc,calloc,free,realloc */

extern void abort(void);

extern void *bsearch(const void *, const void *, size_t, size_t,
	int (*)(const void *, const void *));
extern void qsort(void *, size_t, size_t,
	int (*)(const void *, const void *));

#ifdef __GNUC__
#define ABS(x) ({int __arg = (x); __arg < 0 ? -__arg : __arg;})
#else
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

#if defined(_LANGUAGE_C_PLUS_PLUS)
#ifndef _ABS_
#define _ABS_
inline int abs(int x) { return ABS(x); }
#endif
#elif defined(__GNUC__)
#define abs(x) ABS(x)
#else
extern int abs(int);
#endif

extern div_t div(int, int);
extern long int labs(long);
extern ldiv_t ldiv(long, long);
#if defined(_SGI_SOURCE) && defined(_LONGLONG) && !defined(_POSIX_SOURCE) && !defined(_XOPEN_SOURCE)
extern long long llabs(long long);
extern lldiv_t lldiv(long long, long long);
#endif

extern int mbtowc(wchar_t *, const char *, size_t);
extern int mblen(const char *, size_t);
extern int wctomb(char *, wchar_t);

extern size_t mbstowcs(wchar_t *, const char *, size_t);
extern size_t wcstombs(char *, const wchar_t *, size_t);

#define mblen(s, n)	mbtowc((wchar_t *)0, s, n)
#endif /* _LANGUAGE_C || _LANGUAGE_C_PLUS_PLUS */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __STDLIB64_H_ */
