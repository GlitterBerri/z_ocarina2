/*
 * $Id: zurumode.h,v 2.1 1998-10-22 21:31:42+09 zelda Exp $
 *
 * ずるモード
 * ZURUMODE == 0 : ずるなし（製品版）
 * ZURUMODE == 1 : ずるあり（開発版）
 * ZURUMODE == 2 : ２コンが挿さっていればずるあり（デバッグ版）
 *
 * isZuruMode() ずるができるときは真
 *
 * extern void zurumode_init(void); * 初期化 *
 * extern void zurumode_cleanup(void); * 後始末 *
 *
 * $Log: zurumode.h,v $
 * Revision 2.1  1998-10-22 21:31:42+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/08/26 05:13:14  zelda
 * *** empty log message ***
 *
 * Revision 1.3  1998-08-26 09:24:01+09  zelda
 * *** empty log message ***
 *
 * Revision 1.2  1998-08-25 23:09:54+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1998-08-25 21:21:56+09  hayakawa
 * Initial revision
 *
 */

#ifndef __ZURUMODE_H_
#define __ZURUMODE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#ifndef ZURUMODE
#define ZURUMODE 0
#endif

#if (ZURUMODE == 0) || (ZURUMODE == 1)
#define isZuruMode() 		ZURUMODE
#define zurumode_init() 	(void)0
#define zurumode_cleanup() 	(void)0
#else
extern int zurumode_flag;
#define isZuruMode() 		(zurumode_flag != 0)
extern void zurumode_init(void);
extern void zurumode_cleanup(void);
#endif /* ZURUMODE */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __ZURUMODEX_H_ */
