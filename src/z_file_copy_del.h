/* $Id: z_file_copy_del.h,v 1.1.1.1 2003/03/10 22:42:56 tong Exp $ */	
/* $Log: z_file_copy_del.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:56  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.7  1998/04/21 13:52:41  soejima
 * *** empty log message ***
 *
 * Revision 1.6  1998-04-15 21:48:10+09  soejima
 * *** empty log message ***
 *
 * Revision 1.3  1998/01/27  13:18:24  soejima
 * Revision 1.1  1997/07/31  09:57:06  soejima
 * Initial revision
 * $LogÄÉ²Ã
 * */


#ifndef INCLUDE_Z_FILE_COPY_DEL_H
#define INCLUDE_Z_FILE_COPY_DEL_H



/************************************************************************
 *									*
 *	£Ã£Ï£Ð£Ù ¡õ £Ä£å£ì£å£ô£Å½èÍý					*
 *				1997Ç¯04·î15Æü(²ÐÍËÆü) 14»þ00Ê¬00ÉÃ JST *
 ************************************************************************/



/*==============================================================*/
extern void
menu_copy_init( Game *thisx );
extern void
menu_copy_which( Game *thisx );
extern void
menu_copy_move1( Game *thisx );
extern void
menu_copy_fdin1( Game *thisx );
extern void
menu_copy_where( Game *thisx );
extern void
menu_copy_fdout1( Game *thisx );
extern void
menu_copy_cancel1( Game *thisx );
extern void
menu_copy_move2( Game *thisx );
extern void
menu_copy_fdin2( Game *thisx );
extern void
menu_copy_ok( Game *thisx );
extern void
menu_copy_fdout2( Game *thisx );
extern void
menu_copy_move3( Game *thisx );
extern void
menu_copy_fdin3( Game *thisx );
extern void
menu_copy_end( Game *thisx );
extern void
menu_copy_end1( Game *thisx );
extern void
menu_copy_end2( Game *thisx );
extern void
menu_copy_return( Game *thisx );


extern void
menu_delt_init( Game *thisx );
extern void
menu_delt_where( Game *thisx );
extern void
menu_delt_move( Game *thisx );
extern void
menu_delt_fdin( Game *thisx );
extern void
menu_delt_ok( Game *thisx );
extern void
menu_delt_fdout( Game *thisx );
extern void
menu_delt_cancel( Game *thisx );
extern void
menu_delt_end( Game *thisx );
extern void
menu_delt_end1( Game *thisx );
extern void
menu_delt_end2( Game *thisx );
extern void
menu_delt_return( Game *thisx );

/*==============================================================*/


#endif

/*** z_file_copy_del.h end ***/
