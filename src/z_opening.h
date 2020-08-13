/* $Id: z_opening.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $ */	
/* $Log: z_opening.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.6  1998/05/20 08:40:25  soejima
 * *** empty log message ***
 *
 * Revision 1.5  1998-05-20 17:09:30+09  soejima
 * *** empty log message ***
 *
 * Revision 1.4  1998-03-25 20:50:09+09  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.3  1997/05/29  08:22:08  soejima
 * *** empty log message ***
 *
 * Revision 1.2  1997/05/29  08:18:29  soejima
 * TITLEとOPENINGとFILE_CHOOSEに分割
 *
 * Revision 1.1  1997/05/28  10:05:54  soejima
 * Initial revision
 *
 * $Log追加
 * */


#ifndef INCLUDE_Z_OPENING_H
#define INCLUDE_Z_OPENING_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif



/************************************************************************
 *
 *	ゼルダタイトル
 *
 ************************************************************************/
				/* 派生クラスの定義 */
typedef struct {
    Game	g;		/* 基底クラス */

    char	*staticSegment;	/* スタティックセグメントポインタ */

    View	view;		/* ビュワークラス */
} Game_opening;
    


/*==============================================================*/
extern void
opening_cleanup( Game *thisx );

extern void
opening_init( Game *thisx );
/*==============================================================*/



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_opening.h end ***/

