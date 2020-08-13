/* $Id: z_eff_shield_particle.h,v 2.1 1998/10/22 12:13:45 zelda Exp $ */
/*
 *$Log: z_eff_shield_particle.h,v $
 * Revision 2.1  1998/10/22  12:13:45  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.1  1998/08/28 01:44:39  matutani
 *Initial revision
 *
 */
/*===========================================================================
 *
 * 盾用火花 V2
 *
 * Program:Kenji Matsutani
 * 1998年 8月26日(水曜日) 14時03分38秒 JST 
 *
 *=========================================================================*/

#ifndef INCLUDE_Z_EFF_SHIELD_PARTICLE_H
#define INCLUDE_Z_EFF_SHIELD_PARTICLE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_effect.h"
#include"z_basic.h"

/*
 * メモ
 * まず、scalingして,trs_x,rot_z,rot_yして表示する。
 * scale_xとtrs_xに関連性を持たせる。
 * head_xをtail_xとの差がmax_lengthになるまで動かす。
 * head_x,tail_xからtrs,scaleを決定する。
 */
    
/*
 * Particle構造体
 */
typedef struct eff_sh_particle {
    /* 形状位置関連 */
    float start_speed_x;
    float head_speed_x;
    float head_x;
    float tail_speed_x;
    float tail_x;
    
    /* rot関連 */
    short rot_y;
    short rot_z;
} EffShParticle;

#define EFF_SH_PARTICLE_MAX_NUM 16

/*
 * データセット構造体
 */
typedef struct eff_sh_particle_info_data {

    /* パーティクル個数 */
    unsigned char particle_num;
    
    /* 中心位置 */
    s_xyz center;
    
    /* カラー */
    /* スタート */
    rgba_t sp;
    rgba_t se;
    /* 中間 */
    rgba_t mp;
    rgba_t me;
    /* 最後 */
    rgba_t ep;
    rgba_t ee;

    /*
     * 一定のブレーキ
     * head_brake > tail_brake
     */
    float brake;
    float max_speed; /* 最大速度 */
    float max_length; /* 最大長さ(tail位置,さらにスケールに関係) */
    
    unsigned char max_frame;  /* 最大フレーム:下の方のコメント参照 */
    
    Light_point lp; /* point lightのデータ─:固定 */
    int light_flag; /* ライト処理をするかどうかのフラグ */
    
} EffShParticleInfoData;

/*
 * メイン構造体
 */
typedef struct eff_sh_particle_info {
    EffShParticle particle[EFF_SH_PARTICLE_MAX_NUM];

    /* パーティクル個数 */
    unsigned char particle_num;

    /* 中心位置 */
    s_xyz center;
    
    /* カラー */
    /* スタート */
    rgba_t sp;
    rgba_t se;
    /* 中間 */
    rgba_t mp;
    rgba_t me;
    /* 最後 */
    rgba_t ep;
    rgba_t ee;

    /*
     * 一定のブレーキ
     */
    float brake;
    float start_speed_x; /* 初速度 */
    float max_speed; /* 最大速度 */
    float max_length; /* 最大長さ(tail位置,さらにスケールに関係) */
    
    /*
     * 一応speedが０になるようにmax_frameの設定をしてください。
     * このフレームからカラー計算
     */
    unsigned char max_frame; 
    unsigned char frame;

    /* light */
    Light_data light; /* lightのデータ─ */
    Light_list *light_list; /* light listのデータ */
    int light_flag; /* ライト処理をするかどうかのフラグ */
    
} EffShParticleInfo;

/*============================================================================
 *
 * コンストラクター
 *
 *==========================================================================*/
extern void EffectShieldParticle_ct(
    void *thisx,
    void *initx);

/*===========================================================================
 *
 * デストラクター
 *
 *=========================================================================*/
extern void EffectShieldParticle_dt(
    void *thisx);


/*============================================================================
 *
 * 動作処理
 *
 *===========================================================================*/
extern Effect_Proc_Func EffectShieldParticle_proc(void *thisx);


/*============================================================================
 *
 * 表示処理
 *
 *==========================================================================*/
extern void EffectShieldParticle_disp(void *thisx, Graph *graph);


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_eff_shield_particle.h EOF ***/


