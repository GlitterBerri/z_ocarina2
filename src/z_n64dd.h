/*
 * $Id: z_n64dd.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 * ６４ＤＤインターフェース関数
 *
 * $Log: z_n64dd.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.18  1998/10/08 10:57:40  hayakawa
 * *** empty log message ***
 *
 * Revision 1.17  1998-10-08 11:17:49+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.16  1998-10-07 15:20:59+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.15  1998-10-07 15:11:27+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.14  1998-10-05 15:55:34+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.13  1998-10-03 21:11:27+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.12  1998-09-22 14:26:32+09  hayakawa
 * n64dd_isInMediumに名前変更
 *
 * Revision 1.11  1998-09-21 09:40:08+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.10  1998-09-15 21:49:48+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1998-09-14 22:58:50+09  hayakawa
 * 新型
 *
 * Revision 1.8  1998-09-04 14:45:28+09  hayakawa
 * n64dd_initの返り値変更
 *
 * Revision 1.7  1998-07-24 21:23:02+09  zelda
 * n64dd_isDiskMode
 *
 * Revision 1.6  1998-07-06 10:48:57+09  hayakawa
 * n64dd_enable, n64dd_isLinked追加
 *
 * Revision 1.5  1998-07-02 22:00:07+09  hayakawa
 * n64dd_draw n64dd_draw追加
 *
 * Revision 1.4  1998-06-25 22:14:07+09  hayakawa
 * n64dd_isConnected追加
 *
 * Revision 1.3  1998-06-23 21:20:56+09  hayakawa
 * n64dd_isBusy追加
 *
 * Revision 1.2  1998-06-19 21:13:26+09  hayakawa
 * dmacopy_disk＋α
 *
 * Revision 1.1  1998-06-04 16:34:40+09  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_N64DD_H_
#define __Z_N64DD_H_

#include "ultratypes.h"
#include "mbi.h"		/* Gfx */

#include "z_n64dd_keep.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    extern int n64dd_init(void);
    extern void n64dd_cleanup(void);
    extern int n64dd_init_background(void);
    extern int n64dd_init_wait(void);
    extern void n64dd_read(u32 lba, void *ram, size_t size);
#if defined(USE_DD_WRITE)
    extern void n64dd_write(u32 lba, void *ram, size_t size);
#endif
    extern void dmacopy_disk(void *dst, u32 src, u32 size);

    extern int n64dd_isInMedium(void); /* !0:ディスクが入っている */
    extern int n64dd_isInJustMedium(void); /* !0:ゼルダのディスクが入っている */
    extern void n64dd_MediumCheck(void);	/* 手動メディアチェック */

    extern void n64dd_move(void);
    extern void n64dd_draw(Gfx **gpp);
    
    extern u32 n64dd_LeoDriveExist(void);

    
    extern void n64dd_SoundStop(void); /* サウンドを止めます */
    extern void n64dd_SoundStopNoWait(void); /* サウンドを止めようとします */
    extern int n64dd_isSoundStoped_Check(void); /* サウンドが止まったかどうか(n64dd_SoundStopNoWaitと対で) */
    extern int n64dd_isSoundStoped(void);	/* サウンドが止まっているかどうか */
    extern void n64dd_SoundContinue(void); /* n64dd_SoundStop[Wait]で止めたサウンドを復活 */

    
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_N64DD_H_ */
