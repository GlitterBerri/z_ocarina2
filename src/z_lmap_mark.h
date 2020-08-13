/********************************************************************************
 *
 * $Id: z_lmap_mark.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 * $Log: z_lmap_mark.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.1  1998/09/21 00:19:46  hayakawa
 * Initial revision
 *
 *
 ********************************************************************************/

#ifndef INCLUDE_Z_LMAP_MARK_H
#define INCLUDE_Z_LMAP_MARK_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_map_mark.h"

typedef struct {
    short		idx;
    float		x, y;
} MapMarkSPos;

typedef struct {
    short		markID;
    int			frame;
    const Vtx		*vtx;
    int			nvtx;
    int			suu;
    MapMarkSPos		pos[ MAX_MARKPOINT ];
} LargeMapMark;

extern void LargeMapMarkInit( Game_play *game_play );
extern void LargeMapMarkCleanup( Game_play *game_play );
extern void LargeMapMarkDisplay( Game_play *game_play );

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif	/* INCLUDE_Z_LMAP_MARK_H */
