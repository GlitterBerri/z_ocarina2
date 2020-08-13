/*
 * $Id: z_map_exp.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 *
 *
 * $Log: z_map_exp.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.7  1998/09/26 13:48:07  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-09-21 14:31:55+09  soejima
 * *** empty log message ***
 *
 * Revision 1.5  1998-09-19 22:29:58+09  hayakawa
 * map_exp_dtÄÉ²Ã
 *
 * Revision 1.4  1998-09-19 15:08:09+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1998-09-11 16:06:19+09  soejima
 * *** empty log message ***
 *
 * Revision 1.2  1998-07-29 22:52:38+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998-07-24 22:01:32+09  soejima
 * Initial revision
 *
 * Revision 1.134  1998-07-23 22:52:26+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/05/21  01:12:28  soejima
 * Initial revision
 * $LogÄÉ²Ã
 *
 */


#ifndef INCLUDE_Z_MAP_EXP_H
#define INCLUDE_Z_MAP_EXP_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_save_area_h.h"




/************************************************************************
 *									*
 *	¥¼¥ë¥À64 £Í£Á£Ð							*
 *				1998Ç¯07·î24Æü(¶âÍËÆü) 14»þ00Ê¬00ÉÃ JST *
 *									*
 ************************************************************************/
/*
 * £Í£Á£Ð
 */
#define MAP_ALPHA	255	/* £Í£Á£Ð £Á£ì£ð£è£á */
////////#define MAP_COLOR	0x52bf
////////#define LINK_MAP	0xf801
#define MAP_COLOR	0x02bf
#define LINK_MAP	0x0663
#define MAP_COLOR_H	((MAP_COLOR & 0xff00)>>8)	/* £Í£Á£Ð £Ï£Î¥«¥é¡¼¡Ê£È¡Ë*/
#define MAP_COLOR_L	(MAP_COLOR & 0x00ff)		/*                  ¡Ê£Ì¡Ë*/
#define LINK_MAP_H	((LINK_MAP & 0xff00)>>8)	/* £Í£Á£Ð £Ï£Î¥«¥é¡¼¡Ê£È¡Ë*/
#define LINK_MAP_L	(LINK_MAP & 0x00ff)		/*                  ¡Ê£Ì¡Ë*/

/* £Í£Á£Ð £Ï£Î¥»¥Ã¥È */
#define SIZE0		((64*57)/2)		/* ÃÏ¾å£Í£Á£Ð¥µ¥¤¥º */
#define SIZE1		((96*85)/2)		/* ¥À¥ó¥¸¥ç¥ó£Í£Á£Ð¥µ¥¤¥º */
#define SIZE2		((48*85)/2)		/* ¥«¥ì¥¤¥É¡¦¥¹¥³¡¼¥× £Í£Á£Ð¥µ¥¤¥º */



extern short map_no_data[][8];
extern short boss_floor_data[];

/* £Í£Á£Ð ³Æ³¬£Ï£Î¥Á¥§¥Ã¥¯ */
extern void
map_floor_check( Game_play *game_play, short floor );
/* £Í£Á£Ð ¥Æ¥¯¥¹¥Á¥ã£Ä£Í£Á */
extern void
map_textuer_dma( Game_play *game_play, short room_no  );
/* £Í£Á£Ð £Ï£Î¥»¥Ã¥È */
extern void
map_enter_set( Game_play *game_play, short room_no );
/* £Í£Á£Ð £Ã£Ï£Î£Ó£Ô£Ò£Õ£Ã£Ô */
extern void
map_exp_ct( Game_play *game_play );
/* £Í£Á£Ð ¤Ç¤¹¤È¤é¤¯¤È */
extern void
map_exp_dt( Game_play *game_play );
/* £Í£Á£Ð £Ä£Ò£Á£× */
extern void
map_exp_draw( Game_play *game_play );
/* map_no */
extern int
map_exp_get_map_no( int sceneid, int no );
/* £Í£Á£Ð £Í£Ï£Ö£Å */
extern void
map_exp_move( Game_play *game_play );

/* Æþ¼¼¥×¥ì¥¤¥ä¡¼°ÌÃÖÊÝÂ¸ */
extern void
player_position_hold( Game_play *game_play );


#include "z_map_exp_data.h"
extern map_exp_data_tbl_t *map_exp_data_tbl_p;



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_map_exp.h end ***/
