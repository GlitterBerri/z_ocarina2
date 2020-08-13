/*
 ******************************************************************************
 *              
 *      デモ用”ガノン戦ゼルダ”の外部参照ヘッダーファイル
 * 	$Id: z_en_zl3_dousa.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $
 ******************************************************************************
 */
#ifndef INCLUDE_Z_EN_ZL3_DOUSA_H
#define INCLUDE_Z_EN_ZL3_DOUSA_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_en_zl3.h"    
#include "z_save_area_h.h"    

    
/****************外部参照用マクロ変数****************/
/* ガノンとゼルダの連絡（value はu8型です）*/
#define SET_GANON_ORDER_FOR_ZL3(actor_p, value)	\
    		((((En_Zl3_Misc *)(actor_p))->order_ganon) = (value))
#define GET_GANON_ORDER_FOR_ZL3(actor_p)	(((En_Zl3_Misc *)(actor_p))->order_ganon)
    
/* ゼルダ右手の位置(xyz_t構造体) */
#define EN_ZL3_HAND_POS_FORGANON(actor_p)	(((En_Zl3_Misc *)(actor_p))->hand_pos)
#define EN_ZL3_HAND_POSX_FORGANON(actor_p)	((((En_Zl3_Misc *)(actor_p))->hand_pos).x)
#define EN_ZL3_HAND_POSY_FORGANON(actor_p)	((((En_Zl3_Misc *)(actor_p))->hand_pos).y)
#define EN_ZL3_HAND_POSZ_FORGANON(actor_p)	((((En_Zl3_Misc *)(actor_p))->hand_pos).z)

/* 良く考えるとずっと止ってます */    
///* ゼルダ右手の動き止った(とまっていないなら"False") */
//#define EN_ZL3_HAND_STOP_FORGANON(actor_p)	\
//    			((EN_ZL3_SKELETON((En_Nb_Misc *)(actor_p)).flag) == ANIME_FRAME_REPEAT)


/****************"Actor_info_make_child_actor"での引数の指定****************/
#define EN_ZL3_INFINAL_ARG_DATA 	0x2000
#define EN_ZL3_INFINAL_ANGLE_Z 		0x0000

#define EN_ZL3_INFINAL2_ARG_DATA 	0x0001
    
/****************命令定義****************/

/* ガノン戦１(EN_ZL3_INFINAL_ARG_DATA の En_Zl3) */    
enum {
    DOUSA_IS_LOOKHAND_IN_EN_ZL3_INFINAL,	/* "手を見る"リピートへ */
    DOUSA_IS_SURPRISE_IN_EN_ZL3_INFINAL,	/* "トライフォースが出た"へ */
    DOUSA_IS_DISAPPEAR_ALL_IN_EN_ZL3_INFINAL,	/* いきなりゼルダとクリスタル
						   が消える(Actor_delete呼ぶ) */

    DOUSA_IS_SWOOP_IN_EN_ZL3_INFINAL,		/* "ガノンを見る"第一フレームのまま */
    DOUSA_IS_LOOKGANON_IN_EN_ZL3_INFINAL,	/* "ガノンを見る"リピートへ */
    DOUSA_IS_LOOKUP_IN_EN_ZL3_INFINAL,		/* "ガノンを見る"から"見上げる"リピートへ */
    DOUSA_IS_STAND_IN_EN_ZL3_INFINAL,		/* "見上げる"から"立ち"リピートへ */
    DOUSA_IS_WALK_IN_EN_ZL3_INFINAL,		/* "立ち"から"歩き"リピートへ */

    DOUSA_IS_DISAPPEAR_CRYST_IN_EN_ZL3_INFINAL,	/* 徐々にクリスタルのみ
						   が消える(Actor_delete呼ぶ) */
    
    TOTAL_DOUSA_IN_EN_ZL3_INFINAL
};
    
/* ガノン戦２(EN_ZL3_INFINAL2_ARG_DATA の En_Zl3) */    
enum {
    DOUSA_IS_STAND_IN_EN_ZL3_INFINAL2,		/* "立ち"リピート(s_wait)へ */
    DOUSA_IS_PRESS_IN_EN_ZL3_INFINAL2,		/* "合掌"リピート(a_wait)へ */
    DOUSA_IS_LOOKUP_IN_EN_ZL3_INFINAL2,		/* "見上げる"リピート(u_wait)へ */
    DOUSA_IS_RELIEF_IN_EN_ZL3_INFINAL2,		/* "安心"リピート(ha_mからotituku_w)へ
						   (ゼルダが少し自分で動きます) */
    
    DOUSA_IS_HANDDOWN_IN_EN_ZL3_INFINAL2,	/* "不安"リピート(f_wait)へ */
    DOUSA_IS_SURPRISE_IN_EN_ZL3_INFINAL2,	/* "驚く"リピート(odo_wait)へ */
    DOUSA_IS_LOOKSWORD_IN_EN_ZL3_INFINAL2,	/* "剣見る"リピート(mousaigo)へ */
    
    DOUSA_IS_WATCH_IN_EN_ZL3_INFINAL2,		/* "見守る"リピート(uemuki_wait)へ */

    DOUSA_IS_AVERT_IN_EN_ZL3_INFINAL2,		/* "そむける"リピート
						   (kao_kakusuからuemuki_wait)へ */

    DOUSA_IS_MAGIC_IN_EN_ZL3_INFINAL2,		/* "魔法発射"リピート(bibibi)へ */
    DOUSA_IS_ENDMAGIC_IN_EN_ZL3_INFINAL2,	/* "魔法終了"リピート(f_wait)へ */
    DOUSA_IS_CALLSAGE_IN_EN_ZL3_INFINAL2,	/* "封印呼び掛け"リピート(k_wait)へ */
    DOUSA_IS_SEAL_IN_EN_ZL3_INFINAL2,		/* "封印ポーズ"リピート(syu_wait)へ */
    DOUSA_IS_DISHEART_IN_EN_ZL3_INFINAL2,	/* "力尽きる"リピート(gaku_wait)へ */
    
    DOUSA_IS_DISAPPEAR_IN_EN_ZL3_INFINAL2,	/* いきなりゼルダが消える(Actor_delete呼ぶ) */
    
    TOTAL_DOUSA_IN_EN_ZL3_INFINAL2
};

/****************セーブフラグ定義****************/
#if 0
#define GET_ESCAPE_EVENT_STATE_IN_ZL3()	\
	Get_Event_Chk_Inf(9, 0x0080)		/* ゼルダ脱出ゲームスタートした？ */
#define SET_ESCAPE_EVENT_STATE_IN_ZL3()	\
	Set_Event_Chk_Inf(9, 0x0080)		/* ゼルダ脱出ゲームスタートした */
#else
#define GET_ESCAPE_EVENT_STATE_IN_ZL3(game_play_p)	\
	(Actor_Environment_sw_Check((game_play_p), 55) &&\
	 ( (game_play_p->scene_data_ID == GANON_DEMO) ||\
	   (game_play_p->scene_data_ID == GANON_FINAL) ||\
	   (game_play_p->scene_data_ID == GANON_SONOGO) ||\
	   (game_play_p->scene_data_ID == GANONTIKA_SONOGO) )\
	    )
#define SET_ESCAPE_EVENT_STATE_IN_ZL3(game_play_p)	\
	(Actor_Environment_sw_On((game_play_p), 55))
#endif
	    
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
