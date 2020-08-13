/* $Id: z_horse.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $ */
/*----------------------------------------------------------------------------
 *
 * 馬用処理
 *
 * z_horse.h
 *
 *$Log: z_horse.h,v $
 *Revision 2.1  1998-10-22 21:17:25+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.6  1998/09/22 11:38:29  matutani
 **** empty log message ***
 *
 *Revision 1.5  1998-09-10 17:40:25+09  matutani
 **** empty log message ***
 *
 *Revision 1.4  1998-04-22 21:53:14+09  matutani
 **** empty log message ***
 *
 *Revision 1.3  1998-04-21 22:54:56+09  matutani
 **** empty log message ***
 *
 *Revision 1.2  1998-03-30 22:17:43+09  matutani
 **** empty log message ***
 *
 *
 * Program:Kenji Matsutani
 *
 *--------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_HORSE_H
#define INCLUDE_Z_HORSE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


#include"z_play.h"
#include"z_actor.h"

/*---------------------------------------------------------------------------
 *
 * 馬セットチェック
 *
 *--------------------------------------------------------------------------*/
extern void Horse_Set_Check(
    Game_play *game_play,
    Actor *thisx);

/*===========================================================================
 *
 * 馬用共通ルーチン
 *
 *==========================================================================*/

/*===========================================================================
 *
 * 馬デフォルト位置送り
 *
 *==========================================================================*/
extern void Horse_goto_Default(Game_play *game_play);

/*============================================================================
 *
 * ハイリア湖 避難
 *
 *==========================================================================*/
extern void Horse_escape_Spot06Water(Game_play *game_play);

/*--------------------------------------------------------------------------
 *
 * ある位置へ向かおうとする。最大角度max_angle_sy(>0)で制限された角度変化で,
 * angle.syを変化させる
 *
 *------------------------------------------------------------------------*/
extern void horse_rot_trace_pos(
    Actor *this,
    xyz_t *ptarget_pos,
    short max_angle_sy);


/*----------------------------------------------------------------------------
 *
 * 他のアクターとの位置関係から、自分に最適な位置を求める。
 *
 * 引数:Game_play *game_play:
 *      Actor_info *ai:
 *      xyz_t *current_pos:現在位置
 *      short angle_y:向き
 *      float base_length 基準距離─＞他のアクターとこの距離を取ろうとする。
 *      ゼロでない。
 *      int counter:チェックカウンタ（チェックするアクター最大数）
 *      処理対策
 *      xyz_t *psp:弾き出された最適位置
 *
 *---------------------------------------------------------------------------*/
extern void horse_suitable_position(
    Game_play *game_play,
    Actor_info *ai,
    xyz_t *current_pos,
    short angle_y,
    float base_length,
    int limiter,
    xyz_t *psp);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_horse.h EOF ***/


