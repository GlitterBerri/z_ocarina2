/*
 * $Id: main.h,v 2.2 1998/11/06 08:59:38 hayakawa Exp $
 *
 * $Log: main.h,v $
 * Revision 2.2  1998/11/06  08:59:38  hayakawa
 * スタックを増やした
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.6  1998/04/01 02:47:08  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.5  1998/03/25  14:15:37  hayakawa
 * 必要なヘッダをインクルードするようにした
 *
 * Revision 1.4  1997/11/18  12:45:59  hayakawa
 * MAIN_STACKSIZEを増やした
 *
 * Revision 1.3  1997/11/16  13:35:49  hayakawa
 * MAIN_STACKSIZE調整
 *
 * Revision 1.2  1997/11/15  13:02:31  hayakawa
 * コントローラパックメニューを条件コンパイルにした
 *
 * Revision 1.1  1997/03/18  00:15:46  hayakawa
 * Initial revision
 *
 */

#ifndef __MAIN_H_
#define __MAIN_H_

#include "ultratypes.h"		/* u8 */

#ifdef USE_NOSPAKMENU
#define MAIN_STACKSIZE (0x400+2048+1024) /* nosPakMenu用に少し増やした */
#else
#define MAIN_STACKSIZE (0x400+1024+0x100) /* 実績 0x2f4 */
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    extern void	mainproc(void *);
    extern u8 	vimode_no;
#if DEBUG
    extern int 	debugflag;
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __MAIN_H_ */
