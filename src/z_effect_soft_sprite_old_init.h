/* $Id: z_effect_soft_sprite_old_init.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/*=============================================================================
 *
 * ソフトスプライトエフェクト 旧初期化ルーチン集(常駐ファイル)
 * z_effect_soft_sprite_old_init.h
 *
 * Program:Kenji Matsutani
 * $Log: z_effect_soft_sprite_old_init.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.14  1998/09/23 15:03:18  sakakibara
 * Effect_Kakera_ct2 作成
 *
 * Revision 1.13  1998-09-18 16:08:58+09  umemiya
 * フォグオフ煙追加
 *
 * Revision 1.12  1998-09-12 21:09:15+09  matutani
 * *** empty log message ***
 *
 * Revision 1.11  1998-09-12 17:25:18+09  matutani
 * *** empty log message ***
 *
 * Revision 1.10  1998-09-03 10:13:57+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.9  1998-09-01 14:33:50+09  matutani
 * *** empty log message ***
 *
 * Revision 1.8  1998-09-01 11:59:18+09  matutani
 * ダスト ライト版追加
 *
 * Revision 1.7  1998-08-18 19:51:01+09  umemiya
 * 水しぶきの色を設定できるよう変更
 *
 * Revision 1.6  1998-08-13 16:26:37+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.5  1998-08-13 10:57:18+09  nisiwaki
 * fire_tail_effect_set3 変更
 *
 * Revision 1.4  1998-08-12 19:54:54+09  nisiwaki
 * fire_tail_effect_set3 追加
 *
 * Revision 1.3  1998-08-11 18:31:05+09  matutani
 * Effect_SS_Magma2_ct()入れ忘れ
 *
 * Revision 1.2  1998-08-07 18:36:30+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.1  1998-08-05 19:51:34+09  matutani
 * Initial revision
 *
 *
 *===========================================================================*/

#ifndef INCLUDE_Z_EFFECT_SOFT_SPRITE_OLD_INIT_H
#define INCLUDE_Z_EFFECT_SOFT_SPRITE_OLD_INIT_H

#include"z_basic.h"
#include"z_effect_soft_sprite_type.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" { /* extern "C" */
#endif

/*=============================================================================
 *
 * 煙エフェクト初期化関数集
 *
 *=========================================================================*/

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_ct_direct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);

/*----------------------------------------------------------------------------
 *
 * データセット1
 * ライト指定版
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dust_ct_li_direct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);

/*----------------------------------------------------------------------------
 *
 * 色指定バージョン
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dust_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env);


/*----------------------------------------------------------------------------
 *
 * 色指定バージョン
 * ライト版
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dust_li_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env);

/*--------------------------------------------------------------------------
 *
 * スケールバージョン
 *
 *-------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short scale_diff);

/*--------------------------------------------------------------------------
 *
 * スケールバージョン
 * ライト版
 *
 *-------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_li_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short scale_diff);

/*--------------------------------------------------------------------------
 *
 * スケールバージョン
 *
 *-------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_co_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short scale_diff,
    short counter);

/*-----------------------------------------------------------------------------
 *
 * スケールバージョン
 * カウンタ指定,ライトつき
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_co_li_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short scale_diff,
    short counter);

/*-----------------------------------------------------------------------------
 *
 * カラー/初期スケール指定バージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_cl_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff);

/*-----------------------------------------------------------------------------
 *
 * 初期スケール指定バージョン ライト指定版
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_cl_li_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff);

/*-----------------------------------------------------------------------------
 *
 * カラー/初期スケール/カウンター指定バージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_cl_co_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff,
    short counter);

/*-----------------------------------------------------------------------------
 *
 * カラー/初期スケール/カウンター指定/ライトバージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_cl_co_li_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff,
    short counter);

/*-----------------------------------------------------------------------------
 *
 * カラー/初期スケール/カウンター指定/フォグなしバージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dust_sc_cl_co_nofog_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff,
    short counter);

/*==========================================================================
 *
 * ある位置を中心として,２０個の砂煙が広がる
 *
 *=========================================================================*/
extern void Effect_SS_Dust_spread20(
    Game *game,
    float r,
    xyz_t *center);

/*==========================================================================
 *
 * ある位置を中心として,２０個の砂煙が広がる
 * ライト版
 *
 *=========================================================================*/
extern void Effect_SS_Dust_li_spread20(
    Game *game,
    float r,
    xyz_t *center);

/*=============================================================================
 *
 * キラキラエフェクト
 *
 *===========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_KiraKira_ct_direct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);


/*----------------------------------------------------------------------------
 *
 * エフェクトセット/カラーセット
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_KiraKira_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env);

/*-----------------------------------------------------------------------
 *
 *	スケール/ カウンタ指定バージョン
 *
 *----------------------------------------------------------------------*/
extern void Effect_SS_KiraKira_sc_ct_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    int counter
);

/*----------------------------------------------------------------------------
 *
 * スケール/ カウンタ指定バージョン (主に魂の魔法に使われている)
 * 動きが違う
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_KiraKira_soul_sc_ct_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    int counter
);

/*===========================================================================
 *
 * 旧:z_eff_ss_bom.c用コンストラクタ
 *
 *==========================================================================*/

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Bomb_ct_direct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);


/*===========================================================================
 *
 * 旧:z_eff_ss_bomb2.c用コンストラクタ
 *
 *==========================================================================*/
/*---------------------------------------------------------------------------
 *
 * データセット
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Bomb2_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);

/*---------------------------------------------------------------------------
 *
 * データセット:スケール対応版
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Bomb2_2_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale,
    short scale_diff);

/*===========================================================================
 *
 * 旧:z_eff_ss_blast.cコンストラクタ
 *
 *==========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Blast_ct_direct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);


/*----------------------------------------------------------------------------
 *
 * 色指定バージョン
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Blast_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short del_time);


/*--------------------------------------------------------------------------
 *
 * スケールバージョン
 *
 *-------------------------------------------------------------------------*/
extern void Effect_SS_Blast_sc_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short scale_diff,
    short del_time);

/*-----------------------------------------------------------------------------
 *
 * カラー/初期スケール指定バージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Blast_sc_cl_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff,
    short scale_diff_diff,
    short del_time);

/*============================================================================
 *
 * 旧：z_effect_soft_sprite_old_int.cコンストラクタ
 *
 *===========================================================================*/
/*-----------------------------------------------------------------------------
 *
 * 初期スケール指定バージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Spk_sc_cl_ct(
    Game *game,
    Actor *actor,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff);


/*-----------------------------------------------------------------------------
 *
 * 初期スケール指定バージョン2
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Spk_sc_cl_ct2(
    Game *game,
    Actor *actor,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff);

/*-----------------------------------------------------------------------------
 *
 * 初期スケール指定バージョン2
 * ライト指定版
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Spk_sc_cl_li_ct2(
    Game *game,
    Actor *actor,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short scale_diff);

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Spk_ct_direct(
    Game *game,
    Actor *actor,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc);

/*--------------------------------------------------------------------------
 *
 * スケールバージョン
 *
 *-------------------------------------------------------------------------*/
extern void Effect_SS_Spk_sc_ct(
    Game *game,
    Actor *actor,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short scale_diff);

/*----------------------------------------------------------------------------
 *
 * 色指定バージョン
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Spk_ct(
    Game *game,
    Actor *actor,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env);

/*============================================================================
 *
 * 旧:z_eff_ss_d_fire.cコンストラクター
 *
 *===========================================================================*/

/*-------------------------------------------------------------------------
 *
 * データセット1
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dfire_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short prim_a,
    short del_p);

/*-------------------------------------------------------------------------
 *
 * データセット２
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Dfire_ct_s(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short sc,
    short sc_deff,
    short prim_a,
    short del_p,
    int	  frame);

/*===========================================================================
 *
 * 旧:z_eff_ss_bubble.cコンストラクター
 *
 *=========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Bubble_ct(
    Game  *game,
    xyz_t *ppos,
    float offset_y,
    float rand_y,
    float rand_w,
    float scale
);
#if 0
/*============================================================================
 *
 * 旧：z_eff_ss_magic.cコンストラクター
 *
 *==========================================================================*/
/*-------------------------------------------------------------------------
 *
 * データセット1
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_Magic_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short no,
    float size,
    short scrl_type);
/*----------------------------------------------------------------------------
 *
 * 竜巻魔法セット
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_twister_ct_direct(
    Game *game,
    xyz_t *ppos);

/*----------------------------------------------------------------------------
 *
 * 火炎魔法セット
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_mfire_ct_direct(
    Game *game,
    xyz_t *ppos,
    float size,
    short scrl_type);
#endif
/*=============================================================================
 *
 * z_eff_ss_g_ddg_smoke.cより抽出ファイル
 *
 *==========================================================================*/
#if 0
/*-------------------------------------------------------------------------
 *
 *	初期設定処理
 *    
 *------------------------------------------------------------------------*/
extern	void	Effect_SS_G_Ddg_Smoke_ct(Game *game, xyz_t *ppos, short scale);
#endif

extern void effect_disp_mode_sub(Game *game, Effect_SS2_Element *buf,
				 unsigned char *image_txt);

/*============================================================================
 *
 * 旧:z_eff_ss_g_ripple.cコンストラクター
 *
 *===========================================================================*/
extern void Effect_SS_G_Ripple_ct2(
    Game *game, xyz_t *ppos, short start_scale, short end_scale,
    short timer);

#define Effect_SS_G_Ripple_ct(game, ppos, scale, timer)		Effect_SS_G_Ripple_ct2(game, ppos, scale, 500, timer)

/*-------------------------------------------------------------------------
 *
 *	初期設定処理
 *    
 *------------------------------------------------------------------------*/
extern	void	Effect_SS_G_Splash_sc_cl_ct(Game *game, xyz_t *ppos, rgba_t *prim, rgba_t *env, short no, short scale);

#define Effect_SS_G_Splash_sc_ct(game, ppos, no, scale) Effect_SS_G_Splash_sc_cl_ct(game, ppos, NULL, NULL, no, scale);
#define Effect_SS_G_Splash_ct(game, ppos, no) Effect_SS_G_Splash_sc_ct(game, ppos, no, 0)

/*-------------------------------------------------------------------------
 *
 *  旧：z_eff_ss_g_magma.cコンストラクター
 *    
 *------------------------------------------------------------------------*/
extern	void	Effect_SS_G_Magma_ct(Game *game, xyz_t *ppos);


/*============================================================================
 *
 * 旧:z_eff_ss_g_fire.cコンストラクター
 *
 *==========================================================================*/
extern void Effect_SS_G_Fire_ct(
    Game *game, xyz_t *ppos);


/*============================================================================
 *
 * 旧:z_eff_ss_lightning.cコンストラクター
 *
 *===========================================================================*/
extern void Effect_SS_Lightning_sc_cl_co_ct(
    Game *game,
    xyz_t *ppos,
    rgba_t *prim,
    rgba_t *env,
    short scale100_y,
    short angle_z,
    short counter,
    short length);

/*============================================================================
 *
 * 旧:z_eff_ss_dt_bubble.cコンストラクター
 *
 *=========================================================================*/
/*----------------------------------------------------------------------------
 *
 * 規定カラー/スケール/カウンター指定バージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dt_Bubble_sc_co_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale100,
    short counter,
    short color_num,
    short type);

/*----------------------------------------------------------------------------
 *
 * カラー/スケール/カウンター指定バージョン
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dt_Bubble_sc_cl_co_ct(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    rgba_t *prim,
    rgba_t *env,
    short scale100,
    short counter,
    short type);

/* スケール/カウンター指定バージョン */
#define Effect_SS_Dt_Bubble_r_sc_co_ct(game, ppos, pvec, pacc, scale100, counter) Effect_SS_Dt_Bubble_sc_co_ct(game, ppos, pvec, pacc, scale100, counter, 0, 1)
#define Effect_SS_Dt_Bubble_g_sc_co_ct(game, ppos, pvec, pacc, scale100, counter) Effect_SS_Dt_Bubble_sc_co_ct(game, ppos, pvec, pacc, scale100, counter, 1, 1)
#define Effect_SS_Dt_Bubble_b_sc_co_ct(game, ppos, pvec, pacc, scale100, counter) Effect_SS_Dt_Bubble_sc_co_ct(game, ppos, pvec, pacc, scale100, counter, 2, 1)

/* スケール指定バージョン（カウンターは25） */
#define Effect_SS_Dt_Bubble_r_sc_ct(game, ppos, pvec, pacc, scale100) Effect_SS_Dt_Bubble_sc_co_ct(game, ppos, pvec, pacc, scale100, 25, 0, 1)
#define Effect_SS_Dt_Bubble_g_sc_ct(game, ppos, pvec, pacc, scale100) Effect_SS_Dt_Bubble_sc_co_ct(game, ppos, pvec, pacc, scale100, 25, 1, 1)
#define Effect_SS_Dt_Bubble_b_sc_ct(game, ppos, pvec, pacc, scale100) Effect_SS_Dt_Bubble_sc_co_ct(game, ppos, pvec, pacc, scale100, 25, 2, 1)

#if 0
/*=============================================================================
 *
 * 旧:z_eff_ss_dust2.cコンストラクター
 *
 *===========================================================================*/

/*-----------------------------------------------------------------------
 *
 *	コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Effect_SS_Dust2_ct(
    Game	*game,
    xyz_t	*pos,
    xyz_t	*vec,
    xyz_t	*acc,
    rgba_t	*prim,
    rgba_t	*env,
    short	scale,
    short	count);

/*-----------------------------------------------------------------------
 *
 *	テスト版ほこり発生
 *
 *----------------------------------------------------------------------*/
extern void effect_dust2_set(
    Game	*game,
    xyz_t	*pos,
    short	kosuu
);
#endif
#if 0
/*=============================================================================
 *
 * 旧：z_eff_ss_ddj_dust.cコンストラクター
 *
 *===========================================================================*/
/************************************************************************
 *
 *	初期設定処理
 *			
 ************************************************************************/
extern void Effect_SS_Ddj_Dust_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*wvec,
    xyz_t	*wacc,
    short	scale,
    short	set_type
);

/************************************************************************
 *
 *	ベビードドンゴ用砂煙セット
 *			
 ************************************************************************/
extern void ddj_dust_set(
    Game_play	*game_play,
    xyz_t	*wpos,
    float	scale,
    float	base_speed,
    float	rsize,
    int		count,
    int		set_type);
#endif

/*===========================================================================
 *
 * 旧:z_eff_hahen.cコンストラクター
 *
 *=========================================================================*/

/************************************************************************
 *
 *	初期設定処理
 *			
 ************************************************************************/
extern void Effect_Hahen_ct3(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*wvec,
    xyz_t	*wacc,
    short	type,
    short	scale,
    short	bank_num,
    short	min_frm,
    Gfx		*shape_model
);


/************************************************************************
 *
 *	破片拡散簡易設定
 *			
 ************************************************************************/
extern void Effect_Hahen_Kakusan_ct3(
    Game	*game,
    xyz_t	*ppos,
    float	vec_scale,
    short	type,
    short	shape_scale,
    short	shape_random_scale,
    short	hahen_cnt,
    short	bank_num,
    short	min_frm,
    Gfx		*shape_model);

/************************************************************************
 *
 *	初期設定処理
 *	シェイプ：bomb_fragment_model
 *	最低表示フレーム：10
 *			
 ************************************************************************/
#define Effect_Hahen_ct(game, wpos, wvec, wacc, type, scale)	Effect_Hahen_ct3(game, wpos, wvec, wacc, type, scale, -1, 10, NULL)

/************************************************************************
 *
 *	破片拡散簡易設定
 *			
 ************************************************************************/
#define Effect_Hahen_Kakusan_ct(game, ppos, vec_scale, type, shape_scale, shape_random_scale, hahen_cnt)	Effect_Hahen_Kakusan_ct3(game, ppos, vec_scale, type, shape_scale, shape_random_scale, hahen_cnt, -1, 10, NULL)

/************************************************************************
 *
 *	初期設定処理２
 *	シェイプ：引数
 *	最低表示フレーム：10
 *			
 ************************************************************************/
#define Effect_Hahen_ct2(game, wpos, wvec, wacc, type, scale, bank_num, shape_model)	Effect_Hahen_ct3(game, wpos, wvec, wacc, type, scale, bank_num, 10, shape_model)

/************************************************************************
 *
 *	破片拡散簡易設定２
 *			
 ************************************************************************/
#define Effect_Hahen_Kakusan_ct2(game, ppos, vec_scale, type, shape_scale, shape_random_scale, hahen_cnt, bank_num, shape_model)	Effect_Hahen_Kakusan_ct3(game, ppos, vec_scale, type, shape_scale, shape_random_scale, hahen_cnt, bank_num, 10, shape_model)

/************************************************************************
 *
 *	初期設定処理
 *	シェイプ：bomb_fragment_model
 *	最低表示フレーム：引数
 *			
 ************************************************************************/
#define Effect_Hahen_frm_ct(game, wpos, wvec, wacc, type, scale, min_frm)	Effect_Hahen_ct3(game, wpos, wvec, wacc, type, scale, -1, min_frm, NULL)

/************************************************************************
 *
 *	破片拡散簡易設定
 *			
 ************************************************************************/
#define Effect_Hahen_Kakusan_frm_ct(game, ppos, vec_scale, type, shape_scale, shape_random_scale, hahen_cnt, min_frm)	Effect_Hahen_Kakusan_ct3(game, ppos, vec_scale, type, shape_scale, shape_random_scale, hahen_cnt, -1, min_frm, NULL)

/*============================================================================
 *
 * 旧:z_eff_ss_stick.c コンストラクター
 *
 *===========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Stick_ct(
    Game  *game,
    xyz_t *ppos,
    short move_angle_y
);

/*=============================================================================
 *
 * 旧:z_eff_ss_sibuki.cコンストラクター
 *
 *===========================================================================*/
extern void Effect_SS_Sibuki_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*wvec,
    xyz_t	*wacc,
    short	time,
    short	way,
    short	scale
);

/* ダメージヒット時 */
extern void DamageEffectSibukiSet(
    Game	*game,
    xyz_t	*wpos
);

/*=============================================================================
 *
 * 旧z_eff_ss_sibuki.cコンストラクター
 *
 *===========================================================================*/
extern void Effect_SS_Sibuki2_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*wvec,
    xyz_t	*wacc,
    short	scale
);

/*=============================================================================
 *
 * 旧:z_eff_ss_g_magma2.cコンストラクター
 *
 *===========================================================================*/
extern void Effect_SS_Magma2_ct(
    Game	*game,
    xyz_t	*wpos,
    rgba_t      *prim,
    rgba_t      *env,
    short       ch_spd,
    short       flg,
    short       scale100);

/*=============================================================================
 *
 * 旧:z_eff_ss_stone1.cコンストラクター
 *
 *==========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Stone1_ct(
    Game  *game,
    xyz_t *ppos,
    int	  flag);

/*============================================================================
 *
 * 旧:z_eff_ss_hitmark.cのコンストラクタ
 *
 *==========================================================================*/

/*----------------------------------------------------------------------------
 *
 * コンストラクター
 * hit_mark_type = ヒットマークのタイプ０、１、２を入れる。仕様書では、１、
 * ２、３なので注意
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_HitMark_ct(
    Game *game,
    int hit_mark_type,
    xyz_t *ppos);

/*--------------------------------------------------------------------------
 *
 * コンストラクター
 * スケール変更版
 *
 *--------------------------------------------------------------------------*/
extern void Effect_SS_HitMark_scl_ct(
    Game *game,
    int hit_mark_type,
    short scale100,
    xyz_t *ppos);

/*============================================================================
 *
 * 旧:z_eff_ss_fhg_flash.cコンストラクター
 *
 *=========================================================================*/
extern void Effect_fhg_flash_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*vec,
    xyz_t	*acc,
    short       scale100,
    u8          flg
);
extern void Effect_fhg_flash_mini_ct(
    Game	*game,
    Actor       *ac,
    xyz_t	*wpos,
    short       scale100,
    u8          flg
);

/*============================================================================
 *
 * 旧:z_eff_k_fire.cコンストラクター
 *
 *==========================================================================*/
/************************************************************************
 *
 *	初期設定処理
 *			
 ************************************************************************/
extern void Effect_k_fire_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*vec,
    xyz_t	*acc,
    short       scale100,
    u8          flag);

/*=============================================================================
 *
 * 旧:z_eff_ss_solder_srch_ball.cのコンストラクター
 *
 *===========================================================================*/
/*-------------------------------------------------------------------------
 *
 *	初期設定処理
 *    
 *------------------------------------------------------------------------*/
extern void Effect_Ss_Solder_Srch_Ball_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*wvec,
    xyz_t	*wacc,
    short	scale,
    short       *find_flag
);

#define Effect_SS_Solder_Srch_Ball_ct(game, ppos, scale, timer)		Effect_SS_Solder_Srch_Ball_ct2(game, ppos, scale, 500, timer)


/*=============================================================================
 *
 * 旧:z_eff_kakera.cのコンストラクター
 *
 *===========================================================================*/

/************************************************************************
 *	初期設定処理
 ************************************************************************/
extern void Effect_Kakera_ct2(
    Game	*game,		/*  */
    xyz_t	*wPos,		/* 初期位置 */
    xyz_t	*wSpd,		/* 初期速度 */
    xyz_t	*center,	/* 流体の中心位置 */
    short	gravity,	/* 重力加速度 (256倍) */
    short	info,		/* 情報ビット */
    short	airK1,		/* 空気抵抗(速度に比例) (1024倍) */
    short	airK2,		/* 空気抵抗(速度の２乗に比例) (1024倍) */
    short	accType,	/* ベクトル場のタイプ(重力を除く) */
    short	scale,		/* 大きさ (256倍) */
    short	boundNum,	/* バウンド回数 */
    short	entropy,	/* 乱雑度 (0-1024)(0:理想的  1024:無造作) */
    int		counter,	/* カウンター */
    short	prim_type,	/* プリムカラータイプ */
    short	bank_num,	/*  */
    Gfx		*shape_model	/*  */
);

#define Effect_Kakera_ct(game, wPos, wSpd, center, gravity, info, airK1, airK2, accType, scale, boundNum, entropy, counter, bank_num, shape_model)	\
Effect_Kakera_ct2((game), (wPos), (wSpd), (center), (gravity), (info), (airK1), (airK2), (accType), (scale), (boundNum), (entropy), (counter), KAKERA_PRIM_DEFAULT, (bank_num), (shape_model))

/*============================================================================
 *
 * 旧:z_eff_ice_piece.cコンストラクター
 *
 *==========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Ice_Piece_ct(
    Game  *game,
    xyz_t *pos,	/* 発生位置 */
    float scale,	/* スケール */
    xyz_t *vec,	/* 初期速度 */
    xyz_t *acc,	/* 加速度 */
    int	counter	/* 消滅までの時間 */
);

extern void ice_piece_effect_set(
    Game_play	*game_play,
    xyz_t	*ppos,
    float	scale
);

/*============================================================================
 *
 * 旧:z_effect_soft_sprite_old_init.cコンストラクター
 *
 *===========================================================================*/

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_En_Ice_ct0(
    Game  *,
    Actor *,
    xyz_t *,	/* 発生位置 */
    short	prim_r,
    short	prim_g,
    short	prim_b,
    short	prim_a,
    short	env_r,
    short	env_g,
    short	env_b,
    float 	/* スケール */
);
#define Effect_En_Ice_ct( g, a, xyz, f) Effect_En_Ice_ct0( g, a, xyz, 150, 150, 150, 250, 235, 245, 255, f)

extern void Effect_En_Ice_ct1(
    Game  *,
    Actor *,
    s_xyz *,	/* 発生位置 */
    short	prim_r,
    short	prim_g,
    short	prim_b,
    short	prim_a,
    short	env_r,
    short	env_g,
    short	env_b,
    float 	/* スケール */
);
#define Effect_En_Ice_ct_s( g, a, xyz, f) Effect_En_Ice_ct1( g, a, xyz, 150, 150, 150, 250, 235, 245, 255, f)

#if 0

#define Effect_En_Ice_ct( g, a, xyz, f) Effect_En_Ice_ct0( g, a, xyz, 200, 230, 230, 255, 0, 20, 50, f);

#endif

extern void Effect_SS_Ice_Piece2_ct(
    Game	*game,
    xyz_t	*ppos,
    float	scale,
    xyz_t 	*vec,
    xyz_t	*acc,
    rgba_t	*prim,
    rgba_t	*env,
    int 	counter
);

/*=============================================================================
 *
 * 旧:z_eff_fire_tail.cコンストラクター
 *
 *==========================================================================*/

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Fire_Tail_ct(
    Game  	*game,
    Actor	*actor,
    xyz_t 	*ppos,		/* 現在位置 */
    float 	scale,		/* 元になる大きさ */
    xyz_t	*pvec,		/* 現在の親の速度 */
    short	param,		/* 基準値 */
    rgba_t	*prim,		
    rgba_t	*env,
    short	type,		/* タイプ 0 torch4 タイプ 1 torch5 */
    short	part,
    int 	counter		/* 消滅までのカウンター */
    );


extern void fire_tail_effect_set2(Game_play*,float,short,float);
extern void fire_tail_effect_set3(Game_play*,Actor *,xyz_t*,float,short,float);

/*===========================================================================
 *
 * 旧:z_eff_en_fire.cコンストラクト
 *
 *=========================================================================*/
/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_En_Fire_ct(
    Game  	*game,
    Actor	*actor,
    xyz_t 	*ppos,		/* 現在位置 */
    short 	scale,		/* 元になる大きさ */
    short	param,		/* 親アクター消滅時 0:徐々に消える 1:即消滅 */
    short	type,		/* タイプ 0 torch4 タイプ 1 torch5 */
    short	part		/* 接続タイプ -1:オフセット 0-n: パーツ */
);
extern void Effect_En_Fire_ct_s(
    Game  	*game,
    Actor	*actor,
    s_xyz 	*ppos,		/* 現在位置 */
    short 	scale,		/* 元になる大きさ */
    short	param,		/* 親アクター消滅時 0:徐々に消える 1:即消滅 */
    short	type,		/* タイプ 0 torch4 タイプ 1 torch5 */
    short	part		/* 接続タイプ -1:オフセット 0-n: パーツ */
);

/*===========================================================================
 *
 * 旧:z_eff_ss_extra.cコンストラクター
 *
 *==========================================================================*/
/*-------------------------------------------------------------------------
 *
 *	初期設定処理
 *    
 *------------------------------------------------------------------------*/
extern void Effect_SS_Extra_ct(
    Game	*game,
    xyz_t	*wpos,
    xyz_t	*wvec,
    xyz_t	*wacc,
    short	scale,
    short	point);

/*=============================================================================
 *
 * 旧:z_eff_fcircle.cコンストラクター
 *
 *===========================================================================*/
/*-----------------------------------------------------------------------------
 *
 *  データセット
 *
 *---------------------------------------------------------------------------*/
extern void Effect_Fcircle_ct(
    Game *game,
    Actor *thisx,
    xyz_t *ppos,
    short scale1000_xz,
    short scale1000_y);

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
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


/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
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

/*----------------------------------------------------------------------------
 *
 * データセット２
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Dd_ct1(
    Game *game,
    xyz_t *ppos,
    short sc,
    short sc_deff,
    float size,
    int	  count,
    int	  frame);

/*----------------------------------------------------------------------------
 *
 * データセット1
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Ds_ct0(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short sc,
    short sc_deff,
    short prim_a,
    int	  frame);

/*----------------------------------------------------------------------------
 *
 * データセット２
 *
 *---------------------------------------------------------------------------*/
extern void Effect_SS_Ds_ct1(
    Game *game,
    xyz_t *ppos,
    short sc,
    short sc_deff,
    short prim_a,
    int	  frame);

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

/*=============================================================================
 *
 * 氷用煙エフェクト
 *
 *===========================================================================*/
extern void Effect_SS_Ice_Smoke_make(
    Game *game,
    xyz_t *ppos,
    xyz_t *pvec,
    xyz_t *pacc,
    short scale1000);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_effect_soft_sprite_old_init.h EOF ***/
