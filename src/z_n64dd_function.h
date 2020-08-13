/*
 * $Id: z_n64dd_function.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 * ディスク版関数プロトタイプ 
 *
 * $Log: z_n64dd_function.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.3  1998/09/22 12:59:09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1998-09-21 23:15:53+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1998-09-19 22:58:37+09  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_N64DD_FUNCTION_H_
#define _Z_N64DD_FUNCTION_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#if 0
#include "z_play.h"		/* Game_play */
#include "z_debug.h"		/* Debug_mode */
#include "stdarg.h"		/* va_list */
#endif

#include "z_disk_function.h"	/* disk_function_t */

typedef disk_function_t n64dd_function_t;
    
extern n64dd_function_t *n64dd_function;

#define n64dd_function_ok(name) (n64dd_function != NULL && n64dd_function->name != NULL)
#define n64dd_function_call(name) (n64dd_function->name)

extern n64dd_function_t *n64dd_function_Init(n64dd_function_t *function);
extern void n64dd_function_Cleanup(void);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif	/* _Z_N64DD_FUNCTION_H_ */
