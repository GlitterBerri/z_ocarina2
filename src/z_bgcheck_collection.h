/*  $Id: z_bgcheck_collection.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $ */
/*=============================================================================
 *
 * z_bgcheck_collection.h
 * 補正処理集
 *
 * Program:Kenji Matsutani
 * date:1997年 7月25日(金曜日) 16時50分35秒 JST
 *
 *$Log: z_bgcheck_collection.h,v $
 *Revision 2.1  1998-10-22 20:45:49+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.4  1998/08/27 07:20:44  matutani
 *SW用ビット処理追加
 *
 *Revision 1.3  1998-03-18 10:32:45+09  takahata
 **** empty log message ***
 *
 * Revision 1.2  1997/09/27  06:21:49  matutani
 * *** empty log message ***
 *
 * Revision 1.1  1997/07/29  09:54:21  matutani
 * Initial revision
 *
 *
 *===========================================================================*/

#ifndef INCLUDE_Z_BGCHECK_COLLECTION_H
#define INCLUDE_Z_BGCHECK_COLLECTION_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_bgcheck_type.h"

/*---------------------------------------------------------------------------
 *
 * BGCheckCollection_proc()用列挙型
 * 補正を行ったかどうか
 *
 *------------------------------------------------------------------------*/
typedef enum {
    BG_COLLECT_NO_MOVE,
    BG_COLLECT_MOVE,
    BG_COLLECT_LAST_INDEX
} BG_COLLECT_STATUS;

/*----------------------------------------------------------------------------
 * 位置補正処理
 * 典型的なある,BGアクター乗って,BGアクター上の位置を変えないように補正する。
 * BGアクターの位置移動/回転/スケールに対応
 *
 * 
 * T_BGCheck *pbgcheck: BGチェック構造体
 * int bg_actor_index: BGと多数のBGアクター識別のためのアクターインデックス
 * Actor *pmove_actor: 補正したいアクター 
 *
 *---------------------------------------------------------------------------*/
extern void BGCheckCollection_typicalActorPos(
    T_BGCheck *pbgcheck,
    int bg_actor_index,
    Actor *pmove_actor);


/*---------------------------------------------------------------------------
 * シェイプy回転 補正処理
 * リフトの処理に注意
 *
 * 位置補正はここでしない。ただリフト側の変化量を加えるのみ。
 * 
 * T_BGCheck *pbgcheck: BGチェック構造体
 * int bg_actor_index: BGと多数のBGアクター識別のためのアクターインデックス
 * Actor *pmove_actor: 補正したいアクター 
 *
 *---------------------------------------------------------------------------*/
extern void BGCheckCollection_typicalActorRotY(
    T_BGCheck *pbgcheck,
    int bg_actor_index,
    Actor *pmove_actor);

/*============================================================================
 *
 * 乗っているかのビットセット
 *
 * T_BGCheck *pbgcheck: BGチェック構造体
 * int bg_actor_index: BGと多数のBGアクター識別のためのアクターインデックス
 *
 *==========================================================================*/
extern void BGCheckCollection_setRideStatus(
    T_BGCheck *pbgcheck,
    Actor *actor,
    int bg_actor_index);

/*============================================================================
 *
 * 補正処理
 *
 * 乗ってるリフトのタイプに応じて必要な補正関数を呼び出す。
 *
 * T_BGCheck *pbgcheck: BGチェック構造体
 * int bg_actor_index: BGと多数のBGアクター識別のためのアクターインデックス
 * Actor *pmove_actor: 補正したいアクター 
 *
 *---------------------------------------------------------------------------*/
extern BG_COLLECT_STATUS BGCheckCollection_proc(
    T_BGCheck *pbgcheck,
    int bg_actor_index,
    Actor *pmove_actor);


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_bgcheck_collection.h end ***/
