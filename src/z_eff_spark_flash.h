/* $Id: z_eff_spark_flash.h,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $ */
/* $Log: z_eff_spark_flash.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.6  1998/08/26 12:49:10  matutani
 * 個人的に調整（本ちゃん待ち)
 *
 * Revision 1.5  1998-03-18 19:55:17+09  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.4  1996/10/31  02:06:24  matutani
 * *** empty log message ***
 *
 * Revision 1.3  1996/10/29  07:39:08  matutani
 * *** empty log message ***
 *
 * Revision 1.2  1996/10/28  02:15:51  matutani
 * spark flash add
 *
 * Revision 1.1  1996/10/24  04:14:53  matutani
 * Initial revision
 * */
/*-----------------------------------------------------------------------------
 *
 * z_eff_spark_flash.h
 *
 * 剣と盾用火花
 * Program:Kenji Matsutani
 * 1996年10月24日(木曜日) 10時27分52秒 JST
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EFF_SPARK_FLASH_H
#define INCLUDE_Z_EFF_SPARK_FLASH_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif    

#include"z_effect.h"
#include"z_basic.h"

/*
 * Spark Flash構造体
 */
typedef struct effect_spark_flash {
    xyz_t in_position; /* 内側の位置 */
    xyz_t in_vec; /* 変化量 */
    xyz_t out_position; /* 外側の位置 */
    xyz_t out_vec; /* 変化量 */

} Effect_Spark_Flash;

/* 閃光本数 */
#define EFFECT_SPARK_FLASH_MAX_NUM 16

/*
 * spark flash info
 */
typedef struct effect_spark_flash_info {
    s_xyz center; /* 閃光中心位置 */

    int flash_num; /* 閃光の数 */
    Effect_Spark_Flash flash_table[EFFECT_SPARK_FLASH_MAX_NUM]; /* テーブル */
    
    unsigned char start_in_color[4]; /* r,g,b,a */
    unsigned char start_out_color[4]; /* r,g,b,a */

    unsigned char end_in_color[4]; /* r,g,b,a */
    unsigned char end_out_color[4]; /* r,g,b,a */

    float speed; /* 内側の頂点の速度 */
    float mag; /* 外側の内側に対する速度倍率 */
    
    int now_frame; /* 現在のフレーム数 */
    int end_frame; /* 最終フレーム数 */

    /* light */
    Light_data light; /* lightのデータ─ */
    Light_list *light_list; /* light listのデータ */
    int light_flag; /* ライト処理をするかどうかのフラグ */
    
    /* ambient off */
#if 1
    short reg0, reg1, reg2; /* 一時保存パラメーター */
    int ambient_off_frame; /* 明転するまでのフレーム数 */
#endif

} EffectSparkFlashInfo;


/*-----------------------------------------------------------------------------
 *
 * EffectSparkFlashInfo 初期化
 *
 *---------------------------------------------------------------------------*/
extern void EffectSparkFlashInfo_ct(void *this, void *init_data);


/*-----------------------------------------------------------------------------
 *
 * EffectSparkFlashInfoデストラクター
 *
 *--------------------------------------------------------------------------*/
extern void EffectSparkFlashInfo_dt(void *this);


/*----------------------------------------------------------------------------
 *
 * EffectSparkFlashInfo動作処理
 *
 *--------------------------------------------------------------------------*/
extern Effect_Proc_Func EffectSparkFlashInfo_proc(void *this);


/*----------------------------------------------------------------------------
 *
 * EffectInfo表示処理
 *
 *---------------------------------------------------------------------------*/
extern void EffectSparkFlashInfo_disp(void *this, Graph *graph);

#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** z_eff_spark_flash.h end ***/

