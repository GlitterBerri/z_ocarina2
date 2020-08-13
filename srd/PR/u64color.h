/*
 * $Id: u64color.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * カラー値定義
 *
 * $Log: u64color.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.1  1996-11-21 15:40:12+09  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __U64COLOR_H_
#define __U64COLOR_H_

#include "ultra64.h"		/* GPACK_RGBA5551 */

#define RGBA5551_GRAY    GPACK_RGBA5551(127,127,127,1)
#define RGBA5551_BLACK   GPACK_RGBA5551(0,0,0,1)
#define RGBA5551_BLUE    GPACK_RGBA5551(0,0,255,1)
#define RGBA5551_MAZENTA GPACK_RGBA5551(255,0,255,1)
#define RGBA5551_YELLOW  GPACK_RGBA5551(255,255,0,1)
#define RGBA5551_RED     GPACK_RGBA5551(255,0,0,1)
#define RGBA5551_GREEN   GPACK_RGBA5551(0,255,0,1)
#define RGBA5551_WHITE   GPACK_RGBA5551(255,255,255,1)
#define RGBA5551_PINK    GPACK_RGBA5551(255,128,128,1)
#define RGBA5551_CYAN    GPACK_RGBA5551(0,255,255,0)

#endif /* __U64COLOR_H_ */
    
