/* $Id: z_play_h.h,v 2.1 1998/10/22 11:51:48 zelda Exp $ */	
/* $Log: z_play_h.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.5  1998/03/25 11:48:47  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.4  1997/05/24  07:17:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1997/01/13  13:07:41  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1996/10/21  04:38:30  iwawaki
 * new
 * */

#ifndef INCLUDE_Z_PLAY_H_H
#define INCLUDE_Z_PLAY_H_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "u64basic.h"

/************************************************************************
 *
 *	ゼルダゲームプレイ
 *
 ************************************************************************/

typedef struct GAME_PLAY Game_play;

typedef struct {
    u32		start;
    u32		end;
} Rom_Address;


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_play_h.h end ***/
