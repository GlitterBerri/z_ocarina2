/* $Id: z_file_nameset.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 * $Log: z_file_nameset.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/07/06 13:20:57  soejima
 * *** empty log message ***
 *
 * Revision 1.3  1998-06-01 09:52:43+09  soejima
 * *** empty log message ***
 *
 * Revision 1.2  1998-01-30 21:27:38+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/07/31  09:57:00  soejima
 * Initial revision
 *
 * $Log追加
 * */


#ifndef INCLUDE_Z_FILE_NAMESET_H
#define INCLUDE_Z_FILE_NAMESET_H



/************************************************************************
 *									*
 *	名前登録処理							*
 *				1997年04月15日(火曜日) 14時00分00秒 JST *
 ************************************************************************/


/*==============================================================*/
extern void
file_choose_moji_set( Graph *graph, unchar *data, short j );

/*==============================================================*/
extern void
menu_nameset_display( Game *thisx );

extern void
menu_nameset_fdin( Game *thisx );

extern void
menu_nameset_play( Game *thisx );

/*==============================================================*/
extern void
menu_option_fdin( Game *thisx );

extern void
menu_option_play( Game *thisx );

extern void
menu_option_display( Game *thisx );

/*==============================================================*/


#endif

/*** z_file_nameset.h end ***/
