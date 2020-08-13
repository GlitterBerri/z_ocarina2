/* $Id: z_title.h,v 1.2 2003/03/14 02:53:56 tong Exp $ */	
/* $Log: z_title.h,v $
 * Revision 1.2  2003/03/14 02:53:56  tong
 * more source from Nintendo including cheat obj code.
 *
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.34  1998/10/03 12:07:32  hayakawa
 * *** empty log message ***
 *
 * Revision 1.33  1998-09-19 23:07:08+09  soejima
 * *** empty log message ***
 *
 * $Log追加
 * */


#ifndef INCLUDE_Z_TITLE_H
#define INCLUDE_Z_TITLE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_sram.h"


/************************************************************************
 *
 *	ゼルダタイトル
 *
 ************************************************************************/
#define Buf_Ct   	(128/8)

				/* 派生クラスの定義 */
typedef struct {
    Game	g;		/* 基底クラス */

    char	*staticSegment;	/* スタティックセグメントポインタ */

    View	view;		/* ビュワークラス */

    Sram	sram;		/* ＳＲＡＭ クラス */


    short	timer;		/* タイマー */
    short	alpha;		/* アルファ値 */
    short	alpha_data;	/* アルファ増減値 */
    short	wait_timer;	/* タイマー */

    short	counter;	/*  */
    short	work;		/*  */
    unsigned char n64dd_inital_background; /* ６４ＤＤを初期化中 */
    unsigned char done;		/* 終了フラグ */
} Game_title;
    




/*==============================================================*/
extern void Display_Fillter(
    Graph    *graph,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a,
    unsigned char mode
);

extern void
title_cleanup( Game *thisx );

extern void
title_init( Game *thisx );
/*==============================================================*/


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_title.h end ***/

