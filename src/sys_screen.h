/*
 * $Id: sys_screen.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * スクリーンのサイズの定義
 *
 * $Log: sys_screen.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1997/09/30 13:44:32  hayakawa
 * ワーニング対策
 *
 * Revision 1.1  1997/03/19  13:42:37  hayakawa
 * Initial revision
 *
 */

#ifndef __SYS_SCREEN_H_
#define __SYS_SCREEN_H_

#ifndef SCREEN_WD
#define	SCREEN_WD	320
#endif
#ifndef SCREEN_HT
#define	SCREEN_HT	240
#endif

extern int ScreenWidth;
extern int ScreenHeight;

#endif /* __SYS_SCREEN_H_ */
