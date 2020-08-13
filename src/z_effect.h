/* $Id: z_effect.h,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $ */
/* $Log: z_effect.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.16  1998/09/10 09:11:21  matutani
 * *** empty log message ***
 *
 * Revision 1.15  1998-09-10 15:33:28+09  matutani
 * *** empty log message ***
 *
 * Revision 1.14  1998-09-10 15:26:50+09  matutani
 * *** empty log message ***
 *
 * Revision 1.13  1998-09-01 23:23:17+09  matutani
 * エフェクト削除
 *
 * Revision 1.12  1998-08-28 10:47:13+09  matutani
 * エフェクト追加
 *
 * Revision 1.11  1998-07-15 21:13:17+09  matutani
 * ブラ─初期化別バージョン
 *
 * Revision 1.10  1998-03-18 19:46:51+09  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.9  1998/03/03  10:48:00  matutani
 * *** empty log message ***
 *
 * Revision 1.8  1997/05/30  07:23:55  matutani
 * *** empty log message ***
 *
 * Revision 1.7  1997/03/14  00:33:42  hayakawa
 * ヘッダ追加
 *
 * Revision 1.6  1997/02/27  02:21:05  matutani
 * エフェクトのメモリ確保解放をgame mallocに変更
 *
 * Revision 1.5  1996/11/06  06:06:48  matutani
 * *** empty log message ***
 *
 * Revision 1.4  1996/10/31  02:05:26  matutani
 * *** empty log message ***
 *
 * Revision 1.3  1996/10/29  07:39:23  matutani
 * *** empty log message ***
 *
 * Revision 1.2  1996/10/28  02:15:51  matutani
 * spark flash add
 *
 * Revision 1.1  1996/10/23  13:45:13  matutani
 * Initial revision
 * */
/*----------------------------------------------------------------------------
 *
 * Effect制御
 * z_effect.h
 * Program:Kenji Matsutani
 * 1996年10月19日(土曜日) 20時38分25秒 JST
 *
 *--------------------------------------------------------------------------*/

#ifndef INCLUDE_EFFECT_H
#define INCLUDE_EFFECT_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif    

/*
 * 処理関数返り値
 */
typedef enum effect_proc_func_return {
    EFFECT_RPOC_FUNC_NORMAL_RETURN, /* 特に意味無し */
    EFFECT_PROC_FUNC_DESTRUCT, /* デストラクト処理を行う */
    EFFECT_PROC_FUNC_LAST_INDEX
} Effect_Proc_Func;

#include"z_basic.h"
#include"graph.h"		/* Graph */
#include"z_eff_spark.h"
#include"z_eff_blure.h"
#include"z_eff_shield_particle.h"

#define SH_TEST

#define EFFECT_TYPE_SPARK_NUM 3
#define EFFECT_TYPE_BLURE_NUM 25
#define EFFECT_TYPE_SH_PARTICLE_NUM 3

#define MAX_EFFECT_INDEX \
(EFFECT_TYPE_SPARK_NUM + EFFECT_TYPE_BLURE_NUM + EFFECT_TYPE_SH_PARTICLE_NUM)

/*
 * エフェクトメモリーポインター型
 */
typedef void * Effect_Memory_Pointer;

/*
 * エフェクトタイプ
 */
typedef enum effect_type {
    EFFECT_TYPE_SPARK,
    EFFECT_TYPE_BLURE,
    EFFECT_TYPE_BLURE2,
    EFFECT_TYPE_SH_PARTICLE,
    EFFECT_TYPE_LAST_INDEX
} EFFECT_TYPE;
   
/*
 * 各エフェクト情報 テーブル要素型
 */
typedef struct effect_type_info {
    
    unsigned int effect_memory_size; /* エフェクトメモリーサイズ */
    
    /* コンストラクト関数ポインター */
    void (*construct_func)(Effect_Memory_Pointer this, /* 処理データ */
			   Effect_Memory_Pointer init); /* 初期化データ */
    /* デストラクト関数ポインター */
    void (*destruct_func)(Effect_Memory_Pointer p); 
    Effect_Proc_Func (*proc_func)(Effect_Memory_Pointer p); /* 処理関数 */
    void (*disp_func)(Effect_Memory_Pointer p,
		      Graph *graph); /* 表示関数 */
    
} Effect_Type_Info;

/*
 * エフェクト動作テーブル要素型
 */
typedef struct effect_current {
    EFFECT_TYPE type; /* エフェクトタイプ */
    void *effect_memory; /* エフェクトメモリーポインター */
 
    unsigned char priority; /* 優先順位 */
    unsigned char flag; /* フラグ */
    
} Effect_Current;

/*
 * エフェクト動作フラグ内容
 */
/* マスククリアー */
#define EFFECT_FLAG_TYPE_NO_MASK (0)
/* 自己消失型 */
#define EFFECT_FLAG_TYPE_SELF_DESTRUCT_MASK (1<<0)

/*
 * その他 define
 */



/*----------------------------------------------------------------------------
 *
 * 関数
 *
 *---------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------
 *
 * Game ポインターを得る。
 *
 *---------------------------------------------------------------------------*/
extern Game *Effect_GetGamePointer(void);

/*--------------------------------------------------------------------------
 *
 * ある動作番号のエフェクトのメモリーポインターを返す
 *
 *------------------------------------------------------------------------*/
extern void *Effect_GetEffectMemoryPointer(int effect_index);

/*----------------------------------------------------------------------------
 *
 * エフェクト制御初期化
 *
 *--------------------------------------------------------------------------*/
extern void EffectInit(Game *pgame);


/*----------------------------------------------------------------------------
 *
 * エフェクト付加
 *
 *--------------------------------------------------------------------------*/
extern void EffectAdd(
    Game *game, /* ゲーム */
    int *index, /* 動作テーブルのインデックスを返す */
    EFFECT_TYPE type, /* エフェクトタイプ */
    unsigned char priority, /* 優先順位 */
    unsigned char flag, /* フラグ */
    void *init_data); /* 初期化データ */


/*----------------------------------------------------------------------------
 *
 * Effect Disp
 *
 * エフェクト表示
 *
 *--------------------------------------------------------------------------*/
extern void EffectDisp(Graph *graph);


/*----------------------------------------------------------------------------
 *
 * Effect Proc
 *
 * 各エフェクト処理
 *
 *--------------------------------------------------------------------------*/
extern void EffectProc(Game *game);

/*----------------------------------------------------------------------------
 *
 * あるインデックスのエフェクトを解放
 *
 *---------------------------------------------------------------------------*/
extern void EffectFreeIndex(Game *game, int i);

/*----------------------------------------------------------------------------
 *
 * エフェクト総て解放
 *
 *--------------------------------------------------------------------------*/
extern void EffectFreeAllIndex(Game *game);




#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** z_effect.h end ***/



