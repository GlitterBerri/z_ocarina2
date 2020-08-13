/* $Id: z_effect_soft_sprite_type.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/*----------------------------------------------------------------------------
 * 
 * z_effect_soft_sprite_type.h
 *
 * Program:Kenji Matsutani
 *
 *$Log: z_effect_soft_sprite_type.h,v $
 *Revision 2.1  1998-10-22 21:13:45+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.18  1998/08/11 08:30:13  matutani
 *掃除
 *
 *Revision 1.17  1998-08-05 19:51:25+09  matutani
 *オーバーレイ化
 *
 *Revision 1.16  1998-06-17 13:39:45+09  umemiya
 *work_mtxを外しました
 *
 *Revision 1.15  1998-03-18 19:46:06+09  sumiyosi
 *修正依頼おわりました。
 *
 * Revision 1.14  1998/03/10  01:57:12  tarukado
 * マトリクス保存領域 追加
 *
 * Revision 1.13  1998/02/21  10:54:24  sumiyosi
 * 効果のワークバッファを１３に変更。
 *
 * Revision 1.12  1997/09/10  11:27:38  matutani
 * priority
 *
 * Revision 1.11  1997/09/10  06:22:56  matutani
 * ラベル修正
 *
 * Revision 1.10  1997/09/10  01:36:05  matutani
 * EffectSoftSprite_clear():追加 初期値設定
 *
 * Revision 1.9  1997/07/31  12:52:50  matutani
 * max_counterをはずした
 *
 * Revision 1.8  1997/07/30  13:38:05  umemiya
 * *** empty log message ***
 *
 * Revision 1.7  1997/07/23  11:09:39  tarukado
 * ワーク領域増やしたよ
 *
 * Revision 1.6  1997/07/02  11:52:14  tarukado
 * *** empty log message ***
 *
 * Revision 1.5  1997/04/14  01:16:27  matutani
 * 構造体メンバー変更／追加
 *
 * Revision 1.4  1997/04/01  13:26:27  matutani
 * EFFECT_SS_WORK_BUFFER_SIZE ラベル？名変更
 *
 * Revision 1.3  1997/03/31  06:17:53  matutani
 * キラキラカラー属性追加による作業領域増加
 *
 * Revision 1.2  1997/03/27  09:57:39  matutani
 * コメント付加
 *
 * Revision 1.1  1997/03/27  02:13:15  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/


#ifndef INCLUDE_Z_EFFECT_SOFT_SPRITE_TYPE_H
#define INCLUDE_Z_EFFECT_SOFT_SPRITE_TYPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif    

#include"z_basic.h"
#include"z_effect_soft_sprite_label.h"

/* オーバーレイテスト */ 
    
/*==========================================================================
 *
 * オーバーレイ対応
 *
 *========================================================================*/


/*=========================================================================
 *
 * ラベル
 *
 *========================================================================*/

/* 作業領域 : 減らすときは影響が大きいので注意 */
#define EFFECT_SS2_WORK_BUFFER_SIZE 13

/*--------------------------------------------------------------------------
 *
 * ステータスビット
 *
 *-------------------------------------------------------------------------*/
/*
 * デフォルト内容
 * 新規エフェクト上書き可能
 */
#define EFF_SS_STATUS_NONE 0
/*
 * 新規エフェクト上書き禁止
 * counterが0未満にならないと永久に消えない。
 * 同じ優先順位の場合のみ有効:優先順位最大はpriority 0でこのビットを
 * 立てておく。
 */
#define EFF_SS_STATUS_OVER_WRITE_LOCK (1<<0)

/*
 * エフェクト削除時にNa_StopAllObjSe()をelem->pos, pos2で行う
 * ただし、自分でcounter < 0にするときなどは自分で停止処理してください。
 *
 */
#define EFF_SS_STATUS_NA_OBJ_POS (1<<1)
#define EFF_SS_STATUS_NA_OBJ_POS2 (1<<2)

/*--------------------------------------------------------------------------
 *
 * 要素
 *
 *-------------------------------------------------------------------------*/
typedef struct effect_ss2_element {

    /*--------------------------------------------------------
     *
     * z_eff_ss_*.c 関連パラメータ:メインシステム参照
     *
     *------------------------------------------------------*/
    
    /* 位置状態 */
    xyz_t pos; /* 位置 */
    xyz_t vec; /* 速度 */
    xyz_t acc; /* 加減速 */
    
    /* 動作関数: NULLの時処理しない */
    void (* func_proc)(Game *game,
		       int effect_index, /* 自分のインデックス */
		       struct effect_ss2_element *elem); /* 自分の作業領域 */

    /* 表示関数: モードなどを設定して表示する。NULLの時処理しない。 */
    void (* disp_func)(
	Game *game, 
	int effect_index, /* 自分のインデックス */
	struct effect_ss2_element *elem); /* 自分の作業領域 */

    /*-----------------------------------------------------------
     *	
     * 各エフェクト内ワークパラメータ:作業用
     *
     *---------------------------------------------------------*/

    /* 位置状態 */
    xyz_t pos2;     
    
    /* イメージ */
    Gfx *gfx;

    /* アクターポインター:呼び出しアクターなど */
    Actor *actor;

    /* 作業領域 */
    short work[EFFECT_SS2_WORK_BUFFER_SIZE];
    
    /* ステータス:ゼロがデフォルトになるように。 */
    unsigned short status;
    
    /* カウンター (０未満になると終了) */
    short counter;
    
    /*
     * 優先順位
     * priority 数値が低い方を優先して残す。
     */
    unsigned char priority;
    
    /* タイプ */
    unsigned char type;

} Effect_SS2_Element;

/*=========================================================================
 *
 * エフェクトプロフィール
 *
 *========================================================================*/
typedef struct effect_ss_profile {
    /* ラベル */
    TYPE_EFFECT_SS2_LABEL type; 
    
    /* コンストラクター */
    int (* ct_proc)(Game *game, int effect_index,
		    struct effect_ss2_element *elem,
		    void *data);
} EffectSSProfile;

#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** z_effect_soft_sprite_type.h end ***/



