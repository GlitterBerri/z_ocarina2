/* $Id: z_eff_spark.h,v 2.1 1998/10/22 12:13:45 zelda Exp $ */
/* $Log: z_eff_spark.h,v $
 * Revision 2.1  1998/10/22  12:13:45  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/07/04 11:30:46  matutani
 * 粒の回転を追加
 *
 * Revision 1.3  1998-03-18 19:55:26+09  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.2  1997/11/10  08:23:08  matutani
 * *** empty log message ***
 *
 * Revision 1.1  1996/10/23  13:45:32  matutani
 * Initial revision
 * */
/*-----------------------------------------------------------------------------
 *
 * z_eff_spark.h
 *
 * Program:Kenji Matsutani
 * 1996年10月19日(土曜日) 21時05分49秒 JST
 * 火花:自己消去型
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EFF_SPARK_H
#define INCLUDE_Z_EFF_SPARK_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif    

#define PAIF (3.14159f)

#include"z_effect.h"
#include"z_basic.h"

#define EFFECT_SPARK_PARTICLE_MAX_NUM (32)

/*
 * 各Spark情報
 */
typedef struct effect_spark {
    xyz_t vec; /* 速度 */
    xyz_t pos; /* 位置 */

    s_xyz diff_rot; /* 回転速度 */
    s_xyz rot; /* 回転 */
} EffectSpark;

/*
 * Spark情報構造体データ部分
 */
typedef struct effect_spark_info_data {
    s_xyz center; /* 火花中心位置 */

    float speed;
    float gravity;
    
    /*
     * 上下の極の位置には常に生成
     * u_divは赤道上に何点とるか？
     * v_divは極以外の点として何点とるか?（０の場合u_divは無効）
     * を示す。
     */
    int u_div; 
    int v_div;

    unsigned char start_color0[4]; /* r,g,b,a */
    unsigned char start_color1[4]; /* r,g,b,a */
    unsigned char start_color2[4]; /* r,g,b,a */
    unsigned char start_color3[4]; /* r,g,b,a */
    
    unsigned char end_color0[4]; /* r,g,b,a */
    unsigned char end_color1[4]; /* r,g,b,a */
    unsigned char end_color2[4]; /* r,g,b,a */
    unsigned char end_color3[4]; /* r,g,b,a */
   
    int now_frame; /* 現在フレーム数 */
    int end_frame; /* 終了フレーム数 */
} EffectSparkInfoData;

/*
 * Spark情報構造体
 */
typedef struct effect_spark_info {
    s_xyz center; /* 火花中心位置 */

    /*
     * Sparkのテーブル
     * size 2 + u_div * v_div
     */
    int table_size; 
    EffectSpark spark_table[EFFECT_SPARK_PARTICLE_MAX_NUM];

    float speed;
    float gravity;
    
    /*
     * 上下の極の位置には常に生成
     * u_divは赤道上に何点とるか？
     * v_divは極以外の点として何点とるか?（０の場合u_divは無効）
     * を示す。
     */
    int u_div; 
    int v_div;

    unsigned char start_color0[4]; /* r,g,b,a */
    unsigned char start_color1[4]; /* r,g,b,a */
    unsigned char start_color2[4]; /* r,g,b,a */
    unsigned char start_color3[4]; /* r,g,b,a */
    
    unsigned char end_color0[4]; /* r,g,b,a */
    unsigned char end_color1[4]; /* r,g,b,a */
    unsigned char end_color2[4]; /* r,g,b,a */
    unsigned char end_color3[4]; /* r,g,b,a */
   
    int now_frame; /* 現在フレーム数 */
    int end_frame; /* 終了フレーム数 */
} EffectSparkInfo;



/*-----------------------------------------------------------------------------
 *
 * EffectInfo初期化
 *
 *---------------------------------------------------------------------------*/
extern void EffectSparkInfo_ct(void *this, void *init);

/*-----------------------------------------------------------------------------
 *
 * EffectInfoデストラクター
 *
 *---------------------------------------------------------------------------*/
extern void EffectSparkInfo_dt(void *this);



/*---------------------------------------------------------------------------
 *
 * EffectInfo動作処理
 *
 *--------------------------------------------------------------------------*/
extern Effect_Proc_Func EffectSparkInfo_proc(void *this);


/*----------------------------------------------------------------------------
 *
 * EffectInfo表示処理
 *
 *---------------------------------------------------------------------------*/
extern void EffectSparkInfo_disp(void *this, Graph *graph);



#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** z_eff_spark.h ***/

 
