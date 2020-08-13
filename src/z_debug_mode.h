/*
 * $Id: z_debug_mode.h,v 2.1 1998/10/22 11:45:49 zelda Exp $
 *
 * $Log: z_debug_mode.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.8  1998/08/28 13:08:11  zelda
 * *** empty log message ***
 *
 * Revision 1.7  1998-07-31 21:49:06+09  hayakawa
 * Debug_Print2_start, Debug_Print2_stop, Debug_Print_outputを殺しました
 *
 * Revision 1.6  1998-07-25 21:42:00+09  ogawa
 * これでいいのだ
 *
 * Revision 1.5  1998-07-25 21:21:47+09  ogawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-07-25 20:09:03+09  ogawa
 * DEBUG_PRINT_START_LOCATE_Yの変更
 *
 * Revision 1.3  1998-04-01 11:46:59+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1998/03/18  08:04:25  hayakawa
 * Ｃ＋＋対応
 *
 * Revision 1.1  1998/03/09  12:38:09  hayakawa
 * Initial revision
 *
 */

#ifndef INCLUDE_Z_DEBUG_MODE_H
#define INCLUDE_Z_DEBUG_MODE_H

#include "z_debug.h"		/* Debug_mode */
#include "graph.h"		/* Graph */
#include "pad.h"		/* pad_t */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	デバッグモードクラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	デバッグモードクラス宣言
 *
 *----------------------------------------------------------------------*/
extern void new_Debug_mode(void);

#ifndef DEBUG_MODE_NOINPUT
/*-----------------------------------------------------------------------
 *
 *	デバッグモード入力
 *
 *----------------------------------------------------------------------*/
extern void Debug_mode_input(pad_t *pad);
#endif /* DEBUG_MODE_NOINPUT */

/*-----------------------------------------------------------------------
 *
 *	デバッグ文字列設定
 *
 *----------------------------------------------------------------------*/
extern void Debug_mode_output(Graph *graph);

/*-----------------------------------------------------------------------
 *
 *	デバッグ文字列
 *
 *----------------------------------------------------------------------*/

/*-----------------------------------------------------------------------
 *
 *	デバッグ文字列設定
 *
 *----------------------------------------------------------------------*/
extern void Debug_Print_write(int line, int color, char *str);
extern void Debug_Print2_write(char row, char column, char color, char *str);

/*-----------------------------------------------------------------------
 *
 *	デバッグ文字列出力
 *
 *----------------------------------------------------------------------*/

#define DEBUG_PRINT_COLOR_BLUE     (1)
#define DEBUG_PRINT_COLOR_RED      (2)
#define DEBUG_PRINT_COLOR_MAGENTA  (3)
#define DEBUG_PRINT_COLOR_GREEN    (4)
#define DEBUG_PRINT_COLOR_CYAN     (5)
#define DEBUG_PRINT_COLOR_YELLOW   (6)
#define DEBUG_PRINT_COLOR_WHITE    (7)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* INCLUDE_Z_DEBUG_MODE_H */
