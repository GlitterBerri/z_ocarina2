/* $Id: z_event.h,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $ */	
/* $Log: z_event.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.1  1997/12/02 08:58:28  sasaki
 * Initial revision
 *
 * Revision 1.37  1997/12/01  07:37:32  sasaki
 * *** empty log message ***
 *
 * $Log追加
 * */

/************************************************************************
 *
 *	関数宣言
 *
 ************************************************************************/
extern void event_ct( Game_play *game_play );
extern void eventbit_set( Game_play *game_play, short no );
extern void eventbit_reset( Game_play *game_play, short no );
extern int  eventbit_check( Game_play *game_play, short no );
