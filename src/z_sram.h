/* $Id: z_sram.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $ */	
/* $Log: z_sram.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.5  1998/09/19 09:29:40  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998/01/13  11:55:34  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_SRAM_H
#define INCLUDE_Z_SRAM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif



/************************************************************************
 *
 *	ＳＲＡＭについて
 *
 ************************************************************************/
				/* 派生クラスの定義 */
typedef struct {
    unsigned char	*read_buff;
} Sram;


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_sram.h end ***/

