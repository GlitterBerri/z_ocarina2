/* $Id: z_sram_h.h,v 1.1.1.1 2003/03/10 22:42:53 tong Exp $ */	
/* $Log: z_sram_h.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:53  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.3  1999-01-07 13:28:27+09  soejima
 * £Ç£Á£Ô£Å£×£Á£Ù»ÅÍÍ
 *
 * Revision 2.2  1998-10-29 21:07:47+09  soejima
 * £Ð£Á£Ì
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.17  1998/09/19 14:07:01  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998/01/30  11:00:23  soejima
 * Initial revision
 * $LogÄÉ²Ã
 * */


#ifndef INCLUDE_Z_SRAM_H_H
#define INCLUDE_Z_SRAM_H_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_common_data.h"


/************************************************************************
 *
 *	£Ó£Ò£Á£Í¤Ë¤Ä¤¤¤Æ
 *
 ************************************************************************/
#define	DEBUG_MODE	1	/* DEBUG_MODE¡á£±¤Î»þ,¥Ç¥Ð¥Ã¥¯¥â¡¼¥ÉÂÐ±þ */

/*==============================================================*/
/* £Ó£Ò£Á£Í¥¤¥Ë¥·¥ã¥é¥¤¥º¥Á¥§¥Ã¥¯ */
extern void
sram_initialize( Game *game, Sram *sram );
/* £Ó£Ò£Á£Í £Ì£Ï£Á£Ä¡õ£Ã£È£Å£Ã£Ë */
extern void
sram_load_check( Sram *sram );
/* £Ó£Á£Ö£Å */
extern void
sram_save( Sram *sram );
/* £Ó£Ô£Á£Ò£Ô¨¡£Ì£Ï£Á£Ä */
extern void
sram_start_load( Game_file_choose *this, Sram *sram );
/* £Ó£Ô£Á£Ò£Ô¨¡£Ó£Á£Ö£Å */
extern void
sram_start_save( Game_file_choose *this, Sram *sram );

/* £Ó£Ò£Á£Í¥³¥ó¥¹¥È¥é¥¯¥È */
extern void
sram_title_ct( Game *game, Sram *sram );
extern void
sram_ct( Game *game, Sram *sram );

/* £Ó£Ò£Á£Í £Ó£Á£Ö£Å¨¡£Á£Ä£Ä£Ò£Å£Ó£Ó */
extern unshort
sram_save_address[];

extern void
sram_sound_save( Sram *sram );

/*==============================================================*/
/* ÅÐÏ¿¥³¡¼¥É */
#define REG0	'Z'
#define REG1	'E'
#define REG2	'L'
#define REG3	'D'
#define REG4	'A'
#define REG5	'Z'

/* ÅÐÏ¿¥Á¥§¥Ã¥¯ */
#define	REGCK_ALL( no ) 	(sram->read_buff[sram_save_address[no]+(SAVE_BASE)+0] == REG0 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+1] == REG1 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+2] == REG2 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+3] == REG3 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+4] == REG4 || \
				 sram->read_buff[sram_save_address[no]+(SAVE_BASE)+5] == REG5 )

/*==============================================================*/
#define SAVE_SIZE	5200
#define SRAM_Point00	0x20
#define SRAM_Point01	SRAM_Point00 + SAVE_SIZE
#define SRAM_Point02	SRAM_Point01 + SAVE_SIZE
#define SRAM_Point10	SRAM_Point02 + SAVE_SIZE
#define SRAM_Point11	SRAM_Point10 + SAVE_SIZE
#define SRAM_Point12	SRAM_Point11 + SAVE_SIZE

#define SAVE_MAX	(SAVE_BASE + sizeof(Memory)/sizeof(unchar))
#define SAVE_SAVECT	(SAVE_BASE + sizeof(S_Private.newf)/sizeof(unchar))
#define SAVE_NAME	(SAVE_SAVECT + sizeof(unshort)/sizeof(unchar))
#define SAVE_64DD	(SAVE_NAME + sizeof(S_Private.player_name)/sizeof(unchar))
#define SAVE_LIFE	(SAVE_64DD + sizeof(short)/sizeof(unchar))
#define SAVE_ITEM	((SAVE_BASE + (sizeof(S_Private)/sizeof(unchar)) + (sizeof(S_Used)/sizeof(unchar))  + (sizeof(S_Table)/sizeof(unchar))) - (sizeof(long)/sizeof(unchar) + sizeof(S_Table.key_compass_map)/sizeof(unchar) + sizeof(S_Table.key_register)/sizeof(unchar)+ sizeof(unshort)/sizeof(unchar)) )
#define SAVE_HEART	((SAVE_BASE + (sizeof(S_Private)/sizeof(unchar)) + (sizeof(S_Used)/sizeof(unchar))  + (sizeof(S_Table)/sizeof(unchar))) - (sizeof(S_Table.key_register)/sizeof(unchar)+ sizeof(unshort)/sizeof(unchar)) )
#if defined(PAL_VERSION)
#define SAVE_LIFE_NOW	(SAVE_LIFE + sizeof(short)/sizeof(unchar))
#endif
/*==============================================================*/



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_sram_h.h end ***/

