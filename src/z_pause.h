/* $Id: z_pause.h,v 2.1 1998/10/22 11:51:48 zelda Exp $ */	
/* $Log: z_pause.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.12  1998/03/25 11:49:25  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.11  1997/05/22  07:10:27  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1996/12/16  06:48:55  soejima
 * *** empty log message ***
 *
 * Revision 1.9  1996/12/13  01:42:16  soejima
 * ポーズチェック修正
 *
 * Revision 1.8  1996/12/11  09:32:38  soejima
 * カレイド・スコープ処理
 *
 * Revision 1.7  1996/10/18  08:32:20  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1996/10/17  04:04:11  iwawaki
 * ポーズチェック追加
 *
 * Revision 1.5  1996/10/17  03:04:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1996/09/18  10:57:22  iwawaki
 * 秘密
 *
 * Revision 1.3  1996/09/18  09:20:39  iwawaki
 * $Log追加
 * */


#ifndef INCLUDE_Z_PAUSE_H
#define INCLUDE_Z_PAUSE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


/************************************************************************
 *
 *	ポーズクラス
 *
 ************************************************************************/

#define	PAUSE_WAIT	8

typedef struct {
    int		flag;	/* ポーズフラグ	    */	
    int		timer;	/* コマ送りタイマー */
} Pause;

/*-----------------------------------------------------------------------
 *
 *	ポーズクラス コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Pause_ct(
    Pause *this
);
/*-----------------------------------------------------------------------
 *
 *	ポーズ処理
 *
 *----------------------------------------------------------------------*/
extern int Pause_proc(
    Pause *this,
    pad_t *pad		/* コントロールパッド情報ポインター */
);

/*-----------------------------------------------------------------------
 *
 *	ポーズ処理
 *
 *----------------------------------------------------------------------*/
#define	Pause_on_off_check(this)	((this)->flag)


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_pause.h end ***/

