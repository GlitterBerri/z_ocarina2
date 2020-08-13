/* $Id: z_en_item00.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/* $Log: z_en_item00.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.26  1998/09/16 14:55:07  tarukado
 * *** empty log message ***
 *
 * Revision 1.25  1998-08-06 13:36:05+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.24  1998-06-10 22:12:38+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.23  1998-06-04 23:07:09+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.22  1998-05-05 22:06:28+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.21  1998/04/13 13:45:31  tarukado
 * *** empty log message ***
 *
 * Revision 1.20  1998/03/18 09:02:21  umemiya
 * C++対応の変更
 *
 * Revision 1.19  1998/03/10  00:18:42  umemiya
 * *** empty log message ***
 *
 * Revision 1.18  1998/03/09  14:04:47  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1998/02/25  04:22:21  tarukado
 * *** empty log message ***
 *
 * Revision 1.16  1998/02/02  13:09:47  tarukado
 * *** empty log message ***
 *
 * Revision 1.15  1998/01/05  07:20:01  tarukado
 * *** empty log message ***
 *
 * Revision 1.14  1997/11/05  13:47:51  tarukado
 * *** empty log message ***
 *
 * Revision 1.13  1997/09/06  14:28:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1997/06/17  07:21:47  tarukado
 * *** empty log message ***
 *
 * Revision 1.11  1997/06/09  12:48:45  tarukado
 * *** empty log message ***
 *
 * Revision 1.10  1997/05/31  07:19:26  tarukado
 * 岩脇が樽角から強制奪取
 *
 * Revision 1.9  1997/05/28  08:24:02  tarukado
 * *** empty log message ***
 *
 * Revision 1.8  1997/05/22  09:09:41  tarukado
 * *** empty log message ***
 *
 * Revision 1.7  1997/05/15  05:55:53  tarukado
 * キラキラ効果用レジスター追加
 *
 * Revision 1.6  1997/04/25  08:28:57  tarukado
 * *** empty log message ***
 *
 * Revision 1.5  1997/04/25  02:28:07  tarukado
 * *** empty log message ***
 *
 * Revision 1.4  1997/04/24  08:44:47  tarukado
 * *** empty log message ***
 *
 * Revision 1.3  1997/04/24  02:18:03  tarukado
 * *** empty log message ***
 *
 * Revision 1.2  1997/04/22  00:02:20  tarukado
 * *** empty log message ***
 *
 * Revision 1.1  1997/04/21  07:36:51  tarukado
 * Initial revision
 * 追加
 * */

/*-----------------------------------------------------------------------------
 *
 * z_en_item00.h
 * 常駐アイテム
 * Program:Tarukado
 * 1997/04/21
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EN_ITEM00_H
#define INCLUDE_Z_EN_ITEM00_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_basic.h"
#include"z_collision_type.h"
#include"z_collision_param.h"

typedef struct en_item00_s {
    Actor actor; /* 基底クラス */
    void		(*process)(		/* 処理関数ポインタ */
	struct en_item00_s *,
	Game_play *
    );
    short		arg_data2;
    short		i_flg;
    short		init_timer;
    short		flash_timer;
    short		flash_flam;
    short		mode_timer;
    float		trg_scale;
    /* 体 当り */
    ClObjPipe		pipe_pos;
} En_Item00_Actor;

/* 状態 */
#define	EN_ITEM00_ACTION_NORMAL		(0)

#define	EN_ITEM00_GRAVITY		-2.0f
#define	EN_ITEM00_SCALE			 (2.0f/100.0f)
#define	EN_ITEM00_RUPEE_SCALE		 (1.5f/100.0f)
#define	EN_ITEM00_SHADOW_SIZE		 6.0f
#define	EN_ITEM00_OFFSET_G_Y		 980.0f

#define ITEM_KIRA_C   3//DREG(44)
#define ITEM_KIRA_P_R 255//DREG(45)
#define ITEM_KIRA_P_G 255//DREG(46)
#define ITEM_KIRA_P_B 127//DREG(47)
#define ITEM_KIRA_E_R 255//DREG(48)
#define ITEM_KIRA_E_G 255//DREG(49)
#define ITEM_KIRA_E_B 255//DREG(50)

/*---------------------------------------------------------------------------
 *
 * en_item00 プロフィール
 *
 *--------------------------------------------------------------------------*/
extern Actor_profile En_Item00_Profile;
/*
 * アイテム発生汎用ルーチン
 */
extern void Item_Set_Std(
    Game *game, Actor *a, xyz_t *this, short item_set_type);


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif


/*** z_en_item00.h ***/


