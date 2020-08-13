/*  $Id: z_bgcheck_movebg_type.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $ */
/*============================================================================
 *
 * z_bgcheck_movebg_type.h
 *
 * Program:Kenji Matsutani
 * 1997年 7月29日(火曜日) 09時41分28秒 JST
 *
 *$Log: z_bgcheck_movebg_type.h,v $
 *Revision 2.1  1998-10-22 20:45:49+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.5  1998/03/18 01:32:22  takahata
 **** empty log message ***
 *
 * Revision 1.4  1997/11/16  14:09:19  matutani
 * moveBG処理減らし
 *
 * Revision 1.3  1997/10/18  14:13:22  matutani
 * Bounding Sphere追加:処理は先送り
 *
 * Revision 1.2  1997/08/06  05:19:59  matutani
 * 乗っているかビット
 *
 * Revision 1.1  1997/07/29  09:57:49  matutani
 * Initial revision
 *
 *
 *==========================================================================*/

#ifndef Z_BGCHECK_MOVEBG_TYPE_H
#define Z_BGCHECK_MOVEBG_TYPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_actor.h" 
#include"sys_math3d.h"

/*---------------------------------------------------------------------------
 *
 * moveBG基底クラス
 *
 * メモ：
 * 
 *
 *-------------------------------------------------------------------------*/
typedef struct {
    Actor actor; 		/* 基底クラス */
    
    int bg_dyna_index;  /* ダイナミックポリゴンインデックス */

    float powerF;
    float powerY;
    short power_angle_y;
    
    long func_mask; /* 搭乗補正処理マスク─＞z_bgcheck_movebg_param.h */

    unsigned char status; /* 状態マスク */
			    
} MoveBG_Actor;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_bgcheck_movebg_type.h end ***/
