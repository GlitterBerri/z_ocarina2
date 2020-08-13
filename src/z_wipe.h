/*
 * $Id: z_wipe.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 * $Log: z_wipe.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/09/17 07:17:58  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1998-09-17 15:34:59+09  hayakawa
 * SREGからGame_playへ華麗なる成長
 *
 * Revision 1.2  1998-04-22 22:15:59+09  hayakawa
 * WIPE_GETでSREG(4)を見るようにしてみた
 *
 * Revision 1.1  1998-04-22 19:52:00+09  hayakawa
 * Initial revision
 *
 */

#ifndef INCLUDE_Z_WIPE_H
#define INCLUDE_Z_WIPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#define game_play_WIPE_SET(game_play, no) (void)(((game_play)->wipe_type) = (no)) 
#define game_play_WIPE_GET(game_play) 	((game_play)->wipe_type)
 
#define WIPE_SET(no) 	game_play_WIPE_SET(game_play, no)
#define WIPE_GET() 	game_play_WIPE_GET(game_play)
 
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* INCLUDE_Z_WIPE_H */
