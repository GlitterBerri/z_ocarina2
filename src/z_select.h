/*
 * $Id: z_select.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 *
 * ゼルダセレクト画面（機能テスト）
 *
 * $Log: z_select.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.10  1998/06/22 09:40:19  okajima
 * *** empty log message ***
 *
 * Revision 1.9  1998-04-02 13:40:46+09  okajima
 * *** empty log message ***
 *
 * Revision 1.8  1998/03/30  09:05:59  okajima
 * *** empty log message ***
 *
 * Revision 1.7  1998/03/19  13:02:50  komatu
 * *** empty log message ***
 *
 * Revision 1.6  1997/10/04  08:42:33  hayakawa
 * option_no
 *
 * Revision 1.5  1997/05/29  01:31:46  hayakawa
 * select_cleanupプロトタイプ追加
 *
 * Revision 1.4  1997/05/21  09:45:52  hayakawa
 * スタティックセグメントのデータをＲＯＭ読み込みにした
 *
 * Revision 1.3  1996/12/17  04:17:11  hayakawa
 * スクロール用の変数追加
 *
 * Revision 1.2  1996/10/24  07:55:24  hayakawa
 * ヘッダファイル追加
 *
 * Revision 1.1  1996/10/22  08:46:55  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_SELECT_H_
#define __Z_SELECT_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_basic.h"		/* rgba_t */

typedef struct {
    char *name;			/* 名前 */
    void (*func)(Game *, void *); /* 関数 */
    void *parm;			/* パラメータ */
} namefunc_t;

				/* 派生クラスの定義 */
typedef struct {
    Game	g;		/* 基底クラス */
    View	view;		/* ビュワークラス */
    int		namefunc_num;	/* namefuncの数 */
    namefunc_t *namefunc;
    int 	select_no;	/* 現在のセレクト位置 */
    int 	select2_no;	/* 現在のセレクト位置 */
    int 	select_pos[10];	/* 現在のセレクト位置 */
    int		option_no;	/* オプション番号 */
    int		now_pos;
    xy_t	base_pos;
    rgba_t	color;
    int yy, yyy;		/* スクロール用 */
    int work[5];		/* work */
//    char *ptr;			/* free */
    char *staticSegment;	/* スタティックセグメントポインタ */
} Game_select;
    
extern void select_init(Game *thisx);
extern void select_cleanup(Game *thisx);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_SELECT_H_ */
