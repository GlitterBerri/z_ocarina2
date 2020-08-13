/* $Id: z_fcurve_data_skelanime_type.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $ */
/*=============================================================================
 *
 * z_fcurve_data_skelanime_type.h
 *
 * Program:Kenji Matsutani
 * Date:1998年 1月30日(金曜日) 21時04分23秒 JST
 *
 *$Log: z_fcurve_data_skelanime_type.h,v $
 *Revision 2.1  1998-10-22 21:17:25+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.3  1998/02/25 10:47:40  matutani
 **** empty log message ***
 *
 * Revision 1.2  1998/02/23  13:38:44  matutani
 * *** empty log message ***
 *
 * Revision 1.1  1998/02/09  05:11:33  matutani
 * Initial revision
 * 
 *
 *===========================================================================*/

#ifndef INCLUDE_Z_FCURVE_DATA_SKELANIME_TYPE_H 
#define INCLUDE_Z_FCURVE_DATA_SKELANIME_TYPE_H

#include"z_fcurve_data_type.h"
#include"z_types.h"

typedef struct fc_skeleton_info {
    unsigned char joint_num ;/* 全関節数 */
    void **list; /* モデルリスト */
    
    /* アニメフレーム関係 */
    FcurveData *fc_data;
    float start_frame; /* スタート */
    float end_frame; /* エンド */
    float frame_speed; /* １ゲームフレーム当たりの変化量 */
    float anime_frame; /* 現在のフレーム */

    /* ジョイントデータはなし、その場計算 */
    s_xyz *now_joint;
    /* 現状 補間は考えない,代替案としては補間用データもその場計算。 */

    
} FcSkeletonInfo;


#endif

/*** z_fcurve_data_skelanime_type.h EOF ***/
