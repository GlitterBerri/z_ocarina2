/* $Id: z_en_bom.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/* $Log: z_en_bom.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.16  1998/09/25 13:40:44  tarukado
 * *** empty log message ***
 *
 * Revision 1.15  1998-04-13 22:45:26+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.14  1998/04/08 02:01:01  tarukado
 * *** empty log message ***
 *
 * Revision 1.13  1998/04/02  00:27:52  tarukado
 * *** empty log message ***
 *
 * Revision 1.12  1998/03/18  04:41:08  nisiwaki
 * C++対策
 *
 * Revision 1.11  1998/02/25  04:24:20  tarukado
 * *** empty log message ***
 *
 * Revision 1.10  1997/11/03  13:37:36  tarukado
 * *** empty log message ***
 *
 * Revision 1.9  1997/10/30  14:12:10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1997/10/04  05:53:10  tarukado
 * *** empty log message ***
 *
 * Revision 1.7  1997/09/06  14:28:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1997/07/15  06:33:03  tarukado
 * *** empty log message ***
 *
 * Revision 1.5  1997/06/09  06:17:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1997/04/12  12:18:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1997/04/05  09:11:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1997/03/18  13:27:01  iwawaki
 * *** empty log message ***
 * */

/*-----------------------------------------------------------------------------
 *
 * z_en_bom.h
 * 爆弾
 * Program:T.Iwawaki
 * 1997/3/18
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EN_BOM_H
#define INCLUDE_Z_EN_BOM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
#include"z_basic.h"
#include"z_eff_blure.h"
#include"z_collision_type.h"

/*-----------------------------------------------------------------------
 *
 *	爆弾クラス
 *
 *----------------------------------------------------------------------*/
typedef struct En_Bom_actor_s {
    Actor		actor; 		/* 基底クラス */
    
    ClObjPipe 		acoc_info;	/* コリジョン情報 Obj Collision */
    ClObjJntSph		bomb_sph;
    ClObjJntSphElem	bomb_elem;
    
    short		mode_timer;
    short		flash_spd;
    float		env_r;
    char		oc_flg;
    
    void		(*process)(	/* 処理関数ポインタ */
	struct En_Bom_actor_s *,
	Game_play *
    );
} En_Bom_actor;

/*---------------------------------------------------------------------------
 *
 *	プロフィール
 *
 *--------------------------------------------------------------------------*/
extern Actor_profile En_Bom_Profile;


/*-----------------------------------------------------------------------
 *
 *	 マクロ
 *
 *----------------------------------------------------------------------*/

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif


/*** z_en_bom.h ***/


