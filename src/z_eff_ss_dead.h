/* $Id: z_eff_ss_dead.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/*----------------------------------------------------------------------------
 *
 * 敵やられ汎用ソフトスプライトエフェクト
 *
 * Program: Tarukado
 *
 *$Log: z_eff_ss_dead.h,v $
 *Revision 2.1  1998-10-22 21:13:45+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.12  1998/08/05 11:25:21  matutani
 *オーバーレイ化
 *
 *
 * Initial revision
 *
 *
 *
 *--------------------------------------------------------------------------*/
#ifndef INCLUDE_Z_EFF_SS_DEAD_H
#define INCLUDE_Z_EFF_SS_DEAD_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" { 
#endif    

#include"z_basic.h" 
#include"z_effect_soft_sprite_type.h"
#include"z_eff_ss_dead_db.h"
#include"z_eff_ss_dead_dd.h"
#include"z_eff_ss_dead_ds.h"
#include"z_eff_ss_dead_sound.h"
    
#if 0
    /* z_eff_ss_dead_dk.hへ引っ越し */
/*----------------------------------------------------------------------------
 *
 * 汎用 コンパスシェイプ飛び散り データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dk_ct0(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short sc,
    short sc_deff,
    int	  frame);
/*----------------------------------------------------------------------------
 *
 * 汎用 コンパスシェイプ飛び散り データセット２
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dk_ct1(
    Game *game,
    xyz_t *ppos,
    short sc,
    short sc_deff,
    float size,
    int	  count,
    int	  frame);
#endif

#if 0
/*-------------------------------------------------------------------------
 *
 * 汎用 炎 ソフトスプライトエフェクト データセット1
 *
 *--------------------------------------------------------------------------*/
extern void _Effect_SS_Db_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short sc,
    short sc_deff,
    short prim_r,
    short prim_g,
    short prim_b,
    short prim_a,
    short env_r,
    short env_g,
    short env_b,
    short del_p,
    int	  frame, short sound);

#define Effect_SS_Db_ct0( game, ppos, pvec, pacc, sc, sc_deff, prim_r, prim_g, prim_b, prim_a, env_r, env_g, env_b, del_p, frame) _Effect_SS_Db_ct( game, ppos, pvec, pacc, sc, sc_deff, prim_r, prim_g, prim_b, prim_a, env_r, env_g, env_b, del_p, frame, 1);

#define Effect_SS_Db_ct1( game, ppos, pvec, pacc, sc, sc_deff, prim_r, prim_g, prim_b, prim_a, env_r, env_g, env_b, del_p, frame) _Effect_SS_Db_ct( game, ppos, pvec, pacc, sc, sc_deff, prim_r, prim_g, prim_b, prim_a, env_r, env_g, env_b, del_p, frame, 0);

/* 白 基本設定 */
#define Effect_SS_Db_ct( game, ppos, pvec, pacc, sc, sc_deff, prim_a, del_p, frame) Effect_SS_Db_ct0( game, ppos, pvec, pacc, sc, sc_deff, 255, 255, 255, prim_a, 150, 150, 150, del_p, frame);

/* 白 らくらく設定 */
#define Effect_DB_Set( game, pos, vec, acc) Effect_SS_Db_ct( game, pos, vec,acc, 100, 0, 255, 1, 9);

/* 白 スケール変更可能 設定 */
#define Effect_DB_Set_s( game, pos, vec, acc, sc, sc_d) Effect_SS_Db_ct( game, pos, vec,acc, sc, sc_d, 255, 1, 9);

/* 赤 スケール変更可能 設定 */
#define Effect_DB_Set_r_s( game, ppos, pvec, pacc, sc, sc_deff) Effect_SS_Db_ct0( game, ppos, pvec, pacc, sc, sc_deff, 255, 255, 255, 255, 255, 0, 0, 1, 9);

/* 緑 スケール変更可能 設定 */
#define Effect_DB_Set_g_s( game, ppos, pvec, pacc, sc, sc_deff) Effect_SS_Db_ct0( game, ppos, pvec, pacc, sc, sc_deff, 255, 255, 255, 255, 0, 255, 0, 1, 9);

/* 青 スケール変更可能 設定 */
#define Effect_DB_Set_b_s( game, ppos, pvec, pacc, sc, sc_deff) Effect_SS_Db_ct0( game, ppos, pvec, pacc, sc, sc_deff, 255, 255, 255, 255, 0, 0, 255, 1, 9);

/* 赤  基本 設定 */
#define Effect_DB_Set_r( game, ppos, pvec, pacc) Effect_DB_Set_r_s( game, ppos, pvec, pacc, 100, 0);

/* 緑  基本 設定 */
#define Effect_DB_Set_g( game, ppos, pvec, pacc) Effect_DB_Set_g_s( game, ppos, pvec, pacc, 100, 0);

/* 青  基本 設定 */
#define Effect_DB_Set_b( game, ppos, pvec, pacc) Effect_DB_Set_b_s( game, ppos, pvec, pacc, 100, 0);
/*-------------------------------------------------------------------------
 *
 * 汎用 佐々木さん虫 ソフトスプライトエフェクト データセット1
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dd_ct0(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short sc,
    short sc_deff,
    short prim_r,
    short prim_g,
    short prim_b,
    short prim_a,
    short env_r,
    short env_g,
    short env_b,
    short del_p,
    int	  frame);
/*-------------------------------------------------------------------------
 *
 * 汎用 佐々木さん虫 ソフトスプライトエフェクト データセット2
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dd_ct1(
    Game *game,
    xyz_t *ppos,
    short sc,
    short sc_deff,
    float size,
    int	  count,
    int	  frame);
#endif
/************************************************************************
 *									*
 *	汎用フォグ効果 処理			 			*
 *									*
 ************************************************************************/
#define Eff_Set_Fog(game, now_time, max_time) Eff_Set_Fog2(game, NULL, now_time, max_time)
extern void Eff_Set_Fog2(Game *game, rgba_t *fog_color,
			 short now_time, short max_time);
extern void Eff_Set_Fog3(Game *game, rgba_t *fog_color,
			 short now_time, short max_time);
extern void Eff_Off_Fog(Game *game);
/************************************************************************
 *									*
 *	汎用フォグ効果処理（半透明用）		 			*
 *									*
 ************************************************************************/
extern void Eff_Set_Fog2_xlu(Game *game, rgba_t *fog_color,
			     short now_time, short max_time);
extern void Eff_Set_Fog3_xlu(Game *game, rgba_t *fog_color,
			     short now_time, short max_time);
extern void Eff_Off_Fog_xlu(Game *game);
#if 0
/*----------------------------------------------------------------------------
 *
 * 汎用 消える影 エフェクトデータセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Ds_ct0( Game *game, xyz_t *ppos, xyz_t *pvec,
			      xyz_t *pacc, short sc, short sc_deff,
			      short prim_a, int	  frame);
/*----------------------------------------------------------------------------
 *
 * 汎用 消える影 エフェクトデータセット２
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Ds_ct1( Game *game, xyz_t *ppos, short sc, short sc_deff,
			      short prim_a, int	  frame);

/*---------------------------------------------------------------------------
 *
 * 汎用 音発生 エフェクト 
 *
 *--------------------------------------------------------------------------*/
enum { /* 効果優先順位 */
    S_NOM, /* 通常 */
    S_MAX  /* 最大 */
};
enum { /* 音タイプ */
    S_TRG = 1, /* トリガ */
    S_LEV /* レベル */
};
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_sound_ct0(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    u16   s_flg,
    short pri,
    short s_type,
    int	  frame);
/*----------------------------------------------------------------------------
 * データセット２
 *---------------------------------------------------------------------------*/
extern void Effect_sound_ct(
    Game *game,
    xyz_t *ppos,
    u16   s_flg,
    short pri,
    short s_type,
    int	  frame);
#endif


#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** z_eff_ss_dead.h  end ***/
