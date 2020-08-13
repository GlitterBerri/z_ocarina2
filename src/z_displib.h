/*
 * $Id: z_displib.h,v 2.1 1998/10/22 11:45:49 zelda Exp $
 *	
 * 削除予定
 *
 * $Log: z_displib.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.9  1998/08/26 05:52:13  zelda
 * 使っていない関数をバッサリ削除した
 *
 * Revision 1.8  1998-03-25 22:12:58+09  hayakawa
 * 不要なものを消し、必要なものを追加した。
 *
 * Revision 1.7  1998/03/18  03:10:24  ogawa
 * *** empty log message ***
 *
 * Revision 1.6  1997/03/21  09:19:14  hayakawa
 * sPrintf vsPrintfなど、不要なものを削除した
 *
 * Revision 1.5  1996/10/18  08:16:53  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1996/09/28  10:56:10  iwawaki
 * si_***をコメントに
 *
 * Revision 1.3  1996/09/18  09:15:56  iwawaki
 * $Log追加
 */
   
#ifndef INCLUDE_Z_DISPLIB_H
#define INCLUDE_Z_DISPLIB_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*======================================================================*
 *                                                                      *
 *	memcpy関数                                                      *
 *                                                                      *
 *======================================================================*/
extern void *Memcpy(
    void *,
    const void *,
    int
);

/*======================================================================*
 *                                                                      *
 *	memset関数                                                      *
 *                                                                      *
 *======================================================================*/
extern void *Memset(
    void *,
    int,
    int
);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_displib.h end ***/
