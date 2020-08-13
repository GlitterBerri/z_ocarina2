/* $Id: z_arms_hook.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $ */
/* $Log: z_arms_hook.h,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.9  1998/08/14 14:08:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1998-08-13 00:46:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1998-03-20 15:42:42+09  sakakibara
 * *** empty log message ***
 *
 * Revision 1.6  1998/02/25  03:02:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1998/02/24  13:55:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1998/01/21  12:42:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1997/12/25  14:19:03  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1997/12/22  12:22:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.1  1997/12/11  09:51:41  iwawaki
 * Initial revision
 * */

/*-----------------------------------------------------------------------------
 *
 * z_arms_hook.h
 * フックショット
 * Program:T.Iwawaki
 * 1997/12/11
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_ARMS_HOOK_H
#define INCLUDE_Z_ARMS_HOOK_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_basic.h"

/*-----------------------------------------------------------------------
 *
 *	フックショットクラス
 *
 *----------------------------------------------------------------------*/
typedef struct Arms_Hook_actor_s {
    Actor		actor; 			/* 基底クラス */

    ClObjSwrd		at_info; 		/* コリジョン情報 AT Collision */
    SWORD_POS_S		sword_pos;		/* 剣の位置データ保持 */

    xyz_t		BGcheck_pos;		/* ＢＧチェック座標 */
    xyz_t		old_BGcheck_pos;	/* 前フレームＢＧチェック座標 */

    Actor		*carry_actor;		/* 引っ張りＡｃｔｏｒポインタ */
    xyz_t		carry_offset;		/*         ”        オフセット値 */ 
    
    short		timer;			/* タイマー */
    
    void		(*process)(		/* 処理関数ポインタ */
	struct Arms_Hook_actor_s *,
	Game_play *
    );
} Arms_Hook_actor;

/*---------------------------------------------------------------------------
 *
 *	プロフィール
 *
 *--------------------------------------------------------------------------*/
extern Actor_profile Arms_Hook_Profile;


/*-----------------------------------------------------------------------
 *
 *	 マクロ
 *
 *----------------------------------------------------------------------*/

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif


/*** z_arms_hook.h ***/


