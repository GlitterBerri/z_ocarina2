/*
 * $Id: z_en_part.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $
 * $Log: z_en_part.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.19  1998/09/26 07:02:39  tarukado
 * *** empty log message ***
 *
 * Revision 1.18  1998-09-19 18:10:12+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.17  1998-08-20 23:21:15+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.16  1998-08-03 23:24:16+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.15  1998-06-09 22:43:53+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.14  1998-05-28 11:48:32+09  matutani
 * MREG削除
 *
 * Revision 1.13  1998-04-13 22:46:53+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.12  1998/03/31 12:47:04  hayakawa
 * En_Part_Actor_Profile → En_Part_Profile
 *
 * Revision 1.11  1998/03/18  02:17:16  tarukado
 * *** empty log message ***
 *
 * Revision 1.10  1998/03/10  00:18:52  umemiya
 * *** empty log message ***
 *
 * Revision 1.9  1998/03/09  14:04:47  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1998/02/25  04:21:27  tarukado
 * *** empty log message ***
 *
 * Revision 1.7  1997/06/03  08:35:00  tarukado
 * angle_add 追加
 *
 * Revision 1.6  1997/04/30  08:05:57  tarukado
 * 落下軌道 及び スピードの変更
 *
 * Revision 1.5  1997/04/25  08:29:11  tarukado
 * *** empty log message ***
 *
 * Revision 1.4  1997/02/24  09:58:49  matutani
 * デストラクター引数修正
 *
 * Revision 1.3  1996/10/28  11:21:40  tarukado
 * *** empty log message ***
 *
 * Revision 1.2  1996/10/24  10:03:25  tarukado
 * *** empty log message ***
 *
 * Revision 1.2  1996/10/22  00:14:26  tarukado
 * 追加
 * */

/*-----------------------------------------------------------------------------
 *
 * z_en_part.h
 * テスト
 * Program: Tarukado
 * 1996/10/19
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EN_PART_H
#define INCLUDE_Z_EN_PART_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


#include"z_basic.h"
#include"z_eff_blure.h"
#include"z_collision_type.h"

typedef struct en_part_s {
    Actor actor; /* 基底クラス */
   
    u8			mode; /* 動作モード */
    short		mode_timer;
    unsigned int	shape_part;
    float		angle;
    float		angle_add;
    
} En_Part_Actor;

/* 敵１モード */
enum {
    EN_PART_DROP_INIT,
    EN_PART_DROP_PROC,
    EN_PART_SHOT_INIT,
    EN_PART_SHOT_PROC,
    EN_PART_RET_PROC,
    EN_PART_MODE_LAST_INDEX
};

#define	EN_PART_GRAVITY		-0.6f

/*---------------------------------------------------------------------------
 *
 * en_part プロフィール
 *
 *--------------------------------------------------------------------------*/
extern Actor_profile En_Part_Profile;
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif


#endif


/*** z_en_part.h ***/


