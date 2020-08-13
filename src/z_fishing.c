/* $Id: z_fishing.c,v 2.3 1999/01/06 05:23:34 morita Exp $ */
/*
 * $Log: z_fishing.c,v $
 * Revision 2.3  1999/01/06  05:23:34  morita
 * if defined(USE_CIC6105_CHECK) などで制御
 *
 * Revision 2.2  1998-10-27 11:41:49+09  morita
 * PAL用魚大きさメッセージ出力判断追加
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.152  1998/10/19 13:20:27  morita
 * *** empty log message ***
 *
 * Revision 1.151  1998-10-16 16:40:11+09  morita
 * *** empty log message ***
 *
 * Revision 1.150  1998-10-15 21:21:12+09  zelda
 * CIC6105_BootRamTest1_is_OKに変更
 *
 * Revision 1.149  1998-10-15 21:17:08+09  zelda
 * CIC6105_BootRamTest1_is_OKに変更
 *
 * Revision 1.148  1998-10-15 19:04:11+09  morita
 * *** empty log message ***
 *
 * Revision 1.147  1998-10-15 17:17:11+09  morita
 * *** empty log message ***
 *
 * Revision 1.146  1998-10-15 13:04:04+09  morita
 * *** empty log message ***
 *
 * Revision 1.145  1998-10-15 12:39:01+09  morita
 * *** empty log message ***
 *
 * Revision 1.144  1998-10-14 22:31:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.143  1998-10-10 23:01:28+09  morita
 * *** empty log message ***
 *
 * Revision 1.142  1998-10-09 20:06:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.141  1998-10-08 23:06:35+09  morita
 * *** empty log message ***
 *
 * Revision 1.140  1998-10-07 21:54:02+09  morita
 * *** empty log message ***
 *
 * Revision 1.139  1998-10-06 19:22:20+09  morita
 * *** empty log message ***
 *
 * Revision 1.138  1998-10-05 22:16:46+09  morita
 * *** empty log message ***
 *
 * Revision 1.137  1998-10-02 21:01:39+09  morita
 * *** empty log message ***
 *
 * Revision 1.136  1998-10-02 19:55:59+09  morita
 * *** empty log message ***
 *
 * Revision 1.135  1998-10-02 00:13:50+09  sasaki
 * REG(15)をTIME_SPEEDに替えさせて頂きました。
 *
 * Revision 1.134  1998-10-01 19:33:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.133  1998-10-01 17:21:41+09  morita
 * *** empty log message ***
 *
 * Revision 1.132  1998-09-30 23:49:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.131  1998-09-29 20:06:36+09  morita
 * カリング距離調整
 *
 * Revision 1.130  1998-09-29 19:21:39+09  morita
 * *** empty log message ***
 *
 * Revision 1.129  1998-09-28 23:42:28+09  morita
 * *** empty log message ***
 *
 * Revision 1.128  1998-09-28 22:14:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.127  1998-09-28 21:05:36+09  morita
 * *** empty log message ***
 *
 * Revision 1.126  1998-09-28 19:37:15+09  morita
 * *** empty log message ***
 *
 * Revision 1.125  1998-09-28 19:05:09+09  morita
 * *** empty log message ***
 *
 * Revision 1.124  1998-09-27 16:26:23+09  goron
 * { が足りなかったゴロン
 *
 * Revision 1.123  1998-09-26 23:44:11+09  morita
 * *** empty log message ***
 *
 * Revision 1.122  1998-09-26 23:17:24+09  morita
 * *** empty log message ***
 *
 * Revision 1.121  1998-09-26 22:35:42+09  morita
 * *** empty log message ***
 *
 * Revision 1.120  1998-09-25 18:26:33+09  morita
 * 新コリジョン
 *
 * Revision 1.119  1998-09-25 00:32:22+09  morita
 * *** empty log message ***
 *
 * Revision 1.118  1998-09-24 22:20:00+09  morita
 * *** empty log message ***
 *
 * Revision 1.117  1998-09-24 19:23:58+09  morita
 * *** empty log message ***
 *
 * Revision 1.116  1998-09-24 17:42:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.115  1998-09-23 16:18:20+09  morita
 * *** empty log message ***
 *
 * Revision 1.114  1998-09-22 22:57:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.113  1998-09-21 23:51:36+09  morita
 * *** empty log message ***
 *
 * Revision 1.112  1998-09-21 20:31:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.111  1998-09-21 17:34:31+09  morita
 * *** empty log message ***
 *
 * Revision 1.110  1998-09-20 00:50:17+09  morita
 * *** empty log message ***
 *
 * Revision 1.109  1998-09-20 00:19:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.108  1998-09-20 00:05:02+09  morita
 * *** empty log message ***
 *
 * Revision 1.107  1998-09-19 18:00:18+09  morita
 * *** empty log message ***
 *
 * Revision 1.106  1998-09-19 17:45:44+09  morita
 * *** empty log message ***
 *
 * Revision 1.105  1998-09-19 16:22:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.104  1998-09-18 22:12:07+09  morita
 * *** empty log message ***
 *
 * Revision 1.103  1998-09-18 17:12:07+09  morita
 * *** empty log message ***
 *
 * Revision 1.102  1998-09-18 00:14:07+09  morita
 * *** empty log message ***
 *
 * Revision 1.101  1998-09-17 13:24:34+09  morita
 * *** empty log message ***
 *
 * Revision 1.100  1998-09-17 01:06:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.99  1998-09-17 00:56:58+09  morita
 * *** empty log message ***
 *
 * Revision 1.98  1998-09-17 00:55:13+09  morita
 * *** empty log message ***
 *
 * Revision 1.97  1998-09-17 00:28:54+09  morita
 * *** empty log message ***
 *
 * Revision 1.96  1998-09-16 23:01:28+09  morita
 * *** empty log message ***
 *
 * Revision 1.95  1998-09-16 01:00:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.94  1998-09-16 00:46:41+09  morita
 * *** empty log message ***
 *
 * Revision 1.93  1998-09-16 00:10:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.92  1998-09-15 00:11:15+09  morita
 * *** empty log message ***
 *
 * Revision 1.91  1998-09-15 00:04:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.90  1998-09-12 21:14:26+09  morita
 * *** empty log message ***
 *
 * Revision 1.89  1998-09-12 17:24:22+09  morita
 * *** empty log message ***
 *
 * Revision 1.88  1998-09-12 14:10:54+09  morita
 * *** empty log message ***
 *
 * Revision 1.87  1998-09-11 21:38:34+09  morita
 * *** empty log message ***
 *
 * Revision 1.86  1998-09-11 20:25:23+09  morita
 * *** empty log message ***
 *
 * Revision 1.85  1998-09-11 18:44:55+09  morita
 * *** empty log message ***
 *
 * Revision 1.84  1998-09-11 18:42:25+09  morita
 * *** empty log message ***
 *
 * Revision 1.83  1998-09-11 12:09:57+09  morita
 * *** empty log message ***
 *
 * Revision 1.82  1998-09-11 10:43:49+09  morita
 * *** empty log message ***
 *
 * Revision 1.81  1998-09-11 00:31:04+09  morita
 * *** empty log message ***
 *
 * Revision 1.80  1998-09-10 00:38:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.79  1998-09-10 00:13:38+09  morita
 * *** empty log message ***
 *
 * Revision 1.78  1998-09-09 16:46:19+09  morita
 * 竿持ち帰り禁止処理
 *
 * Revision 1.77  1998-09-09 11:08:10+09  morita
 * *** empty log message ***
 *
 * Revision 1.76  1998-09-08 00:05:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.75  1998-09-05 23:08:12+09  morita
 * *** empty log message ***
 *
 * Revision 1.74  1998-09-05 17:04:26+09  morita
 * *** empty log message ***
 *
 * Revision 1.73  1998-09-05 16:57:00+09  morita
 * *** empty log message ***
 *
 * Revision 1.72  1998-09-04 20:26:36+09  morita
 * *** empty log message ***
 *
 * Revision 1.71  1998-09-03 23:59:03+09  morita
 * *** empty log message ***
 *
 * Revision 1.70  1998-09-02 23:58:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.69  1998-09-02 22:03:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.68  1998-09-01 18:11:45+09  morita
 * *** empty log message ***
 *
 * Revision 1.67  1998-08-31 22:18:58+09  morita
 * *** empty log message ***
 *
 * Revision 1.66  1998-08-29 23:29:38+09  morita
 * *** empty log message ***
 *
 * Revision 1.65  1998-08-29 22:26:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.64  1998-08-29 17:48:49+09  morita
 * *** empty log message ***
 *
 * Revision 1.63  1998-08-27 21:40:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.62  1998-08-27 21:17:18+09  morita
 * *** empty log message ***
 *
 * Revision 1.61  1998-08-27 20:43:15+09  morita
 * *** empty log message ***
 *
 * Revision 1.60  1998-08-27 19:26:15+09  morita
 * *** empty log message ***
 *
 * Revision 1.59  1998-08-27 18:16:29+09  morita
 * *** empty log message ***
 *
 * Revision 1.58  1998-08-27 00:20:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.57  1998-08-27 00:10:44+09  morita
 * *** empty log message ***
 *
 * Revision 1.56  1998-08-26 23:00:17+09  kuzuhara
 * おー！
 *
 * Revision 1.55  1998-08-26 21:05:23+09  morita
 * *** empty log message ***
 *
 * Revision 1.54  1998-08-26 17:53:49+09  morita
 * *** empty log message ***
 *
 * Revision 1.53  1998-08-25 23:37:26+09  morita
 * *** empty log message ***
 *
 * Revision 1.52  1998-08-25 22:56:29+09  morita
 * *** empty log message ***
 *
 * Revision 1.51  1998-08-25 20:48:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.50  1998-08-24 20:31:46+09  morita
 * *** empty log message ***
 *
 * Revision 1.49  1998-08-22 23:15:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.48  1998-08-22 18:24:38+09  morita
 * *** empty log message ***
 *
 * Revision 1.47  1998-08-21 22:04:03+09  morita
 * *** empty log message ***
 *
 * Revision 1.46  1998-08-20 23:45:01+09  morita
 * *** empty log message ***
 *
 * Revision 1.45  1998-08-20 23:37:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.44  1998-08-20 22:09:48+09  morita
 * *** empty log message ***
 *
 * Revision 1.43  1998-08-19 23:05:36+09  morita
 * *** empty log message ***
 *
 * Revision 1.42  1998-08-18 23:06:59+09  morita
 * *** empty log message ***
 *
 * Revision 1.41  1998-08-18 21:16:07+09  morita
 * 水しぶき変更
 *
 * Revision 1.40  1998-08-14 19:01:59+09  morita
 * *** empty log message ***
 *
 * Revision 1.39  1998-08-13 22:40:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.38  1998-08-13 15:47:04+09  morita
 * *** empty log message ***
 *
 * Revision 1.37  1998-08-12 22:18:50+09  morita
 * 本番の魚シェイプ導入
 *
 * Revision 1.36  1998-08-11 18:15:24+09  morita
 * *** empty log message ***
 *
 * Revision 1.35  1998-08-10 20:29:42+09  morita
 * *** empty log message ***
 *
 * Revision 1.34  1998-08-08 23:15:26+09  morita
 * *** empty log message ***
 *
 * Revision 1.33  1998-08-08 23:09:58+09  morita
 * *** empty log message ***
 *
 * Revision 1.32  1998-08-08 21:46:02+09  morita
 * *** empty log message ***
 *
 * Revision 1.31  1998-08-08 21:22:41+09  morita
 * *** empty log message ***
 *
 * Revision 1.30  1998-08-07 18:38:28+09  morita
 * *** empty log message ***
 *
 * Revision 1.29  1998-08-06 18:56:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.28  1998-08-06 18:55:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.27  1998-08-05 23:23:47+09  morita
 * *** empty log message ***
 *
 * Revision 1.26  1998-08-05 23:18:04+09  morita
 * *** empty log message ***
 *
 * Revision 1.25  1998-08-05 14:52:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.24  1998-08-05 14:49:56+09  morita
 * *** empty log message ***
 *
 * Revision 1.23  1998-08-04 18:06:55+09  morita
 * *** empty log message ***
 *
 * Revision 1.22  1998-08-03 23:18:25+09  morita
 * *** empty log message ***
 *
 * Revision 1.21  1998-08-01 23:10:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.20  1998-07-31 17:53:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.19  1998-07-30 22:13:34+09  morita
 * *** empty log message ***
 *
 * Revision 1.18  1998-07-25 22:50:13+09  morita
 * *** empty log message ***
 *
 * Revision 1.17  1998-07-25 22:24:21+09  morita
 * ええ感じ
 *
 * Revision 1.16  1998-07-24 18:54:48+09  morita
 * *** empty log message ***
 *
 * Revision 1.15  1998-07-23 23:22:35+09  morita
 * とうとう初めて正式な部品が来た！！
 *
 * Revision 1.14  1998-06-25 21:20:09+09  morita
 * *** empty log message ***
 *
 * Revision 1.13  1998-06-15 14:37:24+09  morita
 * *** empty log message ***
 *
 * Revision 1.12  1998-06-04 18:09:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.11  1998-05-28 17:26:27+09  matutani
 * EffectSoftSprite_normalDitherSet_xlu()消しました。
 * 多分、動作していません。
 *
 * Revision 1.10  1998-05-25 21:26:48+09  ogawa
 * camera test
 *
 * Revision 1.9  1998-04-30 21:55:36+09  morita
 * すまぬ、、、無念、、、、、
 *
 * Revision 1.8  1998/04/28 14:34:15  morita
 * *** empty log message ***
 *
 * Revision 1.7  1998/04/24 08:15:17  morita
 * *** empty log message ***
 *
 * Revision 1.6  1998/04/23 14:22:34  morita
 * 少しずつ手入れ、、、、
 *
 * Revision 1.5  1998/04/22 14:18:00  morita
 * *** empty log message ***
 *
 * Revision 1.4  1998/04/21 14:29:25  morita
 * すきを見て作成
 *
 * Revision 1.3  1998/04/20 14:35:00  morita
 * *** empty log message ***
 *
 * Revision 1.2  1998/04/20 07:18:02  morita
 * *** empty log message ***
 *
 **/

/*-----------------------------------------------------------------------------
 * z_fishing.c
 * Program:K.Morita
 * 1998/4/??
 *
 *---------------------------------------------------------------------------*/
#include "z_hilite.h"
#include"z_basic.h"
#include"z_play.h"
#include"z_fishing.h"
#include"z_collision_check.h"
#include"z_collision_param.h"
#include"z_player.h"
#include "z_player_macro.h"
#include"z_actor_files.h"
#include"z_effect_soft_sprite.h"
#include"z_bgcheck.h"
#include"z_skin_matrix.h"
#include "camera_param_data.h"
#include "z_common_data.h"
#include "z_message_h.h"
#include "z_save_area_h.h"
#include "z_parameter.h"
#include "z_shrink_window.h"

#include "z_vibctl.h"			/* 振動パックささってるか？の有無 */
#include "z_common_data.h"		/* S_Private.lupy_count */
#include "z_parameter_h.h"		/* lupy_increase */
#include "z_player_item.h"		/* GET_ITEM_GOLD_SCALE */
#include "z_kankyo.h"			/* TIME_SPEED */


#include "CIC6105.h"
   


#if 0
#include "z_malloc.h" /* zelda_malloc */
#endif
/* extern Gfx     test_rua_body_model[]; */
#define FS_DEBUG  DEBUG  
/*#define FS_DEBUG 0 */


/*  work[?] */
#define FS_TIME     0
#define FISH_STAT   1

#define FISH_XA     2
#define FISH_YA     3
#define FISH_ZA     4

#define FISH_XA_S   5
#define FISH_YA_S   6
#define FISH_ZA_S   7
#define ANIME_YA    8
#define ANIME_YA2   9 /* 急激なターンで体曲げる */
#define MOUSE_OPEN  10
#define HIRE_ANG    11
#define HIRE_ANG2   12
#define TAIL_ANG    13
#define ANGLE_SX_SP 14

/*  fwork[?] */
#define FISH_Y_SPD        (0) /* fwork *//* 空中ジャンプ用 */
#define FISH_ATACK_SPEED  (1) /* fwork */
#define ANIME_FRAME       (2)
#define ANIME_SPD         (3)
#define ANIME_SCALE       (4)
#define ANIME_SPD_S       (5)
#define ANIME_SCALE_S     (6)


/*
     セーブデータチェックビット（型 は 32bit long)

     (00 00 00 ff)
     下位７ビットは魚の最大記録（子供用）
     その左の１ビットは最大記録を何でつったか（子供用）

     (00 00 ff 00)
     その左の８ビットは１回で子供で遊んだなど（下図）
     
     (00 ff 00 00)
     その左の８ビットはプレイ回数 (マックス２５５回）

     (ff 00 00 00)
     上位７ビットは魚の最大記録（大人用）
     その左の１ビットは最大記録を何でつったか（大人用）
 */




#define SAVE_CHILD_PLAY   0x00000100   /* １回でも子供で遊んだ */
#define SAVE_ADULT_PLAY   0x00000200   /* １回でも大人で遊んだ */
#define SAVE_HEART_GET    0x00000400   /* １回でもウロコもらった */
#define SAVE_UROKO_GET    0x00000800   /* １回でもハートかけらもらった */
#define SAVE_CAP_OFF      0x00001000   /* オヤジボウシなし */

#define SAVE_PLAY_COUNT   0x00010000   /* １回遊んだら足される */

#define SAVE_USE_WORM_C     0x00000080   /*  子供でワームで釣ったらオン */
#define SAVE_USE_WORM_A     0x80000000   /*  大人でワームで釣ったらオン */

#define FISH_RANGE_FOR_MESSAGE  Yabusame_Total

#define CHANGE_TIME(time)    (unsigned short)(time*(65536.0f/24.00f))

/* プレイヤーアクターポインターを得るマクロ */
#define Macro_Game_play_get_player_actor_p(x) \
((x)->actor_info.actor_list[ACTOR_PART_PLAYER].actor)


static void lure_move(Fishing_actor *this, Game_play *game_play);

static void bm_move(Actor *thisx, Game *game);
static void bm_draw(Actor *thisx, Game *game);
/************************************************************************
 *
 *	初期設定処理
 *
 ************************************************************************/
static void Fishing_actor_ct(Actor *thisx, Game *game);

/************************************************************************
 *
 *	デストラクター
 *
 ************************************************************************/
static void Fishing_actor_dt(Actor *thisx, Game *game);

/************************************************************************
 *
 *	 動作処理
 *
 ************************************************************************/
static void Fishing_actor_move(Actor *thisx, Game *game);

/************************************************************************
 *
 *	表示処理
 *
 ************************************************************************/
static void Fishing_actor_draw(Actor *thisx, Game *game);

static void Fishing_Eff_move(Fishing_Eff *eff, Game_play *game_play);
static void Fishing_Eff_disp(Fishing_Eff *eff, Game_play *game_play);

static void Fishing_Obj_move(Game_play *game_play);
static void Fishing_Obj_disp(Game_play *game_play);

static void Minnow_move(Game_play *game_play);
static void Minnow_disp(Game_play *game_play);
/*---------------------------------------------------------------------------
 *
 *	プロフィール
 *
 *--------------------------------------------------------------------------*/

extern Actor_profile Fishing_Profile = {
    ACTOR_NAME_FISHING,	/* 名前 */
    ACTOR_PART_PEOPLE,		/* 役柄 */
    (/* ACTOR_STATUS_FIGHT |  */ACTOR_STATUS_NO_CULL_MOVE /*| ACTOR_STATUS_NO_CULL_DRAW*/),		/* 情報 */
    Object_Bank_Fish,
    sizeof(Fishing_actor),	/* クラスサイズ */
    Fishing_actor_ct,	/* コンストラクト関数ポインタ */
    Fishing_actor_dt,	/* デストラクト関数ポインタ */
    Fishing_actor_move,	/* 処理関数ポインタ */
    Fishing_actor_draw	/* 表示関数ポインタ */
};


#define LINE_MAX_JOINT  200
/*#define LINE_MAX_JOINT  SEX(0)*/

static Fishing_actor    *master;

static u8   CIC_ERROR;
static u8   AGE; /* 内部処理用リンク年齢 */
static u8   mad_water; /* 水が透明か濁ってるか */
static u8   wether;    /* 天気 */
static float  rain_S = 0.0f;        /* 雨が降る */
static u8     rain = 0;      /* 雨が降る */
static float  add_light = 0.0f;

static xyz_t     rain_se_pos = {0.0f, 0.0f, 0.0f};
static float     rain_se_p = 0.0f;

static u8  worm_set_P = 0;
//static u8  bakkin = 0; /* 罰金中で操作無効 */

/* save 用 */
#if 0
static u16   Player_Name_S[8];       /* 内部保存用名前 */
#endif
static float fish_record;            /* ファイル内用魚最大 */
static float my_record = 0.0f;       /* 自分のキープ最大 */
static u8    my_fish_kind;           /* 自分のキープの種類 */
static u8    play_count;             /* 累計何回遊んだか？ */
static u8    use_lure;               /* 何のルアーで釣ったっか？   */

static u8    rod_disp = 1;            /* 道具の表示オンオフ */
static u16   FishRangeForMessage = 0; /* メッセージへ渡す大きさ */
static short fish_fight_time;         /* 魚とやり合う 累計時間 */
static u8    seken_mes_ct;            /* おやじ世間話のカウンター */
static u16   fish_catch_count;        /* 何匹釣ったか */
static short fs_message_no;           /* 任意メッセージセット用番号 */
static u8    fs_message_time = 0;     /* 任意メッセージセット用タイミング */
static int   fishing_time = 0;            /* 汎用処理カウンター */
static s8    camera_zoom_switch;      /* デモカメラ視点切り替えスイッチ */
static short head_check = 0;          /* 親父の頭当りチェックしていいか？ */
static u8    bm_head_no = 0;          /* 親父の頭の状態 0:ハゲ 1:ボウシ 2:カツラ */
static xyz_t bm_head_pos;             /* 親父の頭の位置 */
static u8    lure_with_head = 0;      /* ルアーにボウシかカツラが引っ掛かった場合の番号 */
static u8    lure_with_head_off = 0;  /*    ボウシがルアーからハズレた */
static s_xyz cap_ang;
static u8    lure_reel_ready;         /* 巻き取り準備？ */
static short vib_time;                /* 振動パックセット禁止時間 */
static short lure_bgm_time;           /* BGMセットタイミング */
static Fishing_actor *hit_fish_actor; /* ヒットした魚のポインター */
static short fishing_game_mode;       /* 釣りシステムモード */
static short lure_count;            /* 汎用カウンター */
static short lure_time;             /* 汎用タイマー */
static short lure_cast_time;        /* 投げた瞬間タイマー */
static short lure_cast_wait;        /* 投げた瞬間タイマー 2*/
static short lure_mode = 0;         /* 動作状態 */
static u8    lure_type;             /* ルアーの種類 */
static xyz_t lure_pos;              /* ルアーの位置 */
static xyz_t lure_head_pos;         /* ルアーの先の位置 */
static xyz_t lure_ang;              /* ルアーの角度 */
static xyz_t lure_spd;              /* ルアーの飛ぶ早さ */
static xyz_t lure_acc;              /* ルアーの加速度 */
static float lure_vib_ya;           /* ルアーバイブ幅 */
static float lure_offset_z;         /* ルアーのアクション時とぶら下がり時の表示中心位置補正値 */
#if 0
static float lure_scale;            /* ルアーの大きさカットによって可変 */
#endif
static float lure_dog_swing_X;      /* ルアーのアクション時のX可変角度  */
static float lure_ang_x_ad;         /* ルアーのアクション時のX可変角速度 */
static s8    lure_in_water;         /* ルアーが着水した瞬間タイム */
static short lure_hook_power;       /* 針掛りの度合い */
static u8    lure_search_p;         /* どうでもいいけど魚がルアーサーチする方向 */

static float hit_power;             /* 魚が引っ張る強さ */
#if 0
static float lure_ys2;            /* ? */
#endif
static u8    lure_action;           /* ルアーがアクションしてる証 */

static short lure_hook_time;      /* フッキング猶予 */
static u8    lure_hook_up;        /* フッキング完了 */

static xyz_t lure_act_vec;    /* ルアーアクションする力  */
static float lure_act_ang_Y;  /* ルアーアクションする Y 角度  */
static float lure_act_speed;  /* ルアーアクションする Y 力割合  */
static short lure_ang_Y_s;    /* ルアーの角度 Y (short)計算用 */
static float lure_dog_walk_way;     /* ルアーの首振り力（方向） */
static float line_cap;  /* リールに巻いてる量（遠くへ飛ばす程減る） */
static float line_G;  /* 糸の重力 */
static float line_scale;

static short lure_dog_wait_time; /* 首振り連続入力防止 */

static float lure_hosei_s; /* キャスト後のルアー位置を滑らかに補正する */

static xyz_t fish_mouse_p = {500.0f, 500.0f, 0.0f};


 /* 糸の制御用 */
#if 0
static     xyz_t   line_base_pos_OLD;
#endif
static     xyz_t   line_base_pos;       
static     xyz_t   line_pos[200];
static     xyz_t   line_angle[200];
static     xyz_t   line_spd[200];
static     u8      line_tensyon = 0;  /* ラインを無理やり張らす */

/* 針の制御用 */
static     xyz_t   hook_pos[2];
static     float   hook_angle_Y[2];

/* 竿の制御用 */
static     float   rod_curvY = 0.0f; /* 通常の慣性での竿の曲がり */
static     float   rod_curvX = 0.0f;
static     float   rod_curvY_spd = 0.0f;
static     float   rod_curvX_spd = 0.0f;

static     float   rod_curvX2 = 0.0f;     /* キャスト時の反動竿の曲がり */
static     float   rod_curvX3 = 0.0f;     /* ヒット時の反動の曲がり */
static     float   rod_base_curvX = 0.0f; /* 持つ根本の角度 */
static     u8      rod_hooking_impact;    /* 合わせの瞬間 */


static short old_stick_x = 0; /* 前フレームのステック */
static short old_stick_y = 0;


/* わーむ表示用 */
static xyz_t worm_shape_pos[20];
/* static xyz_t worm_shape_angle[20]; */
/* static xyz_t worm_shape_scale[20]; */
static short worm_eat;

/* static     xyz_t   static_se_pos = {0.0f, 0.0f, 0.0f}; */
static     float   float_dammy;

/* static     s8 audio_flag = 0; */
/* デモ用 */
static    u8      demo_mode = 0;
static    xyz_t   demo_eye,demo_way;
static    short   demo_camera_no;
static    float   demo_xa;
static    float   demo_morf;
static    float   demo_eye_xp;
static    u8      door_check_time = 0; /* ドア判定猶予？ */
/*static    short   demo_eye_old_y = 0;*/

static    u8      lure_hirotta = 0;
static    xyz_t   lure_hirotta_pos;
static    float   lure_hirotta_pos_y2;

#define CAST_BUTTON  B_BUTTON
#define REEL_BUTTON  A_BUTTON

/* lure_mode */
#define LURE_MODE_READY   (0)
#define LURE_MODE_CAST    (1)
#define LURE_MODE_ACTION_READY (2)
#define LURE_MODE_ACTION  (3)
#define LURE_MODE_FISHON  (4)
#define LURE_MODE_CATCH   (5)

/* lure_type */
#define LURE_TYPE_PENCIL_BAIT   (0)
#define LURE_TYPE_SHAD          (1)
#define LURE_TYPE_WORM          (2)


/* fish->move_mode */
#define FISH_SUISOU         100
#define FISH_STRUCT_WAIT_1   10
#define FISH_STRUCT_WAIT_2   11
#define FISH_NORMAL_SWIM_1    0
#define FISH_NORMAL_SWIM_2    1
#define FISH_SNAKEHEAD_WAIT  -1
#define FISH_SNAKEHEAD_AIR   -2
#define FISH_SNAKEHEAD_AIR_2 -25
#define FISH_FIND_LURE        2
#define FISH_ATACK_LURE_1     3
#define FISH_ATACK_LURE_2     4
#define FISH_SNAKEHEAD_ATACK_LURE  -3
#define FISH_HIT_LURE         5
#define FISH_CATCH            6
#define FISH_FEEDING_MINNOW   7


#define NEXT_CAST_WAIT    (5) /* 連続キャスト防止待ち */

#define OBJ_SET (0)

/*----------------------------------------------------------------------------
 *
 * コリジョン用データ
 *
 *--------------------------------------------------------------------------*/
/* Jnt Sphere Data 要素データ */
static ClObjJntSphElemData FsIshiOcInfoJntSphElemData[FISHING_COLL_KAZU] =
{
{  /* 0 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 1 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 2 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 3 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 4 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 5 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 6 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 7 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 8 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
	/* 杭 */
{  /* 9 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 10 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
{  /* 11 */
    CLE_MTRL_NONE,
    CLE_ATC_BIT_ANY_TYPE, CLE_AT_SPL_NONE, (LIFE_CT/1),
    CLE_ATC_BIT_ANY_TYPE,  CLE_AC_SPL_NONE, 0,
    CLE_AT_BIT_NONE, CLE_AC_BIT_NONE,
    CLE_OC_BIT_CHECK,
    /* attr 0*/
    0,  
    0, 0, 0, 30,
    100
},
};
 
/* Jnt Sphere Data */
static ClObjJntSphData5 FsIshiOcInfoJntSphData = {
    CL_HM_NONE,
    CL_AT_BIT_NONE  | CL_AT_BIT_GRP_ENEMY,
    CL_AC_BIT_NONE  | CL_AC_BIT_GRP_PLAYER,
    CL_OC_BIT_CHECK | CL_OC_BIT_GRP_PLAYER,
    CL_OC_BIT2_SELF_ENEMY,
    CL_DATA_LBL_JNT_SPH,
/* 球の数 */
    9+3,
/* ClObjJntSphElemData */
    FsIshiOcInfoJntSphElemData
};
/* 専用当り座標セット */
static void CollisionCheck_pos_set(int i, ClObjJntSph *pclobj_jntsph, xyz_t *pos, float scale)
{
    pclobj_jntsph->elem_tbl[i].attr.global_sph.c.sx = (short)pos->x;
    pclobj_jntsph->elem_tbl[i].attr.global_sph.c.sy = (short)pos->y;
    pclobj_jntsph->elem_tbl[i].attr.global_sph.c.sz = (short)pos->z;
    
    pclobj_jntsph->elem_tbl[i].attr.global_sph.r =
	(short)(pclobj_jntsph->elem_tbl[i].attr.local_sph.r *
		pclobj_jntsph->elem_tbl[i].attr.scl_r *
		scale * (1.6f/*  + (float)KAZ(50)*0.001f */)
	    );
}


#if 0
/* ********************************************
	    BGM FLAG
   ******************************************** */
static u16 bgm_test_no[] = {   
       NA_BGM_NO_ENTRY		    ,       // 0 0xffff
       NA_BGM_SE_SEQUENCE	    ,       // 1 0x0000
       NA_BGM_NA_SEQUENCE	    ,       // 2 0x0001
       NA_BGM_FIELD		    ,       // 3 0x0002
       NA_BGM_DUNGEON		    ,       // 4 0x0018
       NA_BGM_KAKARIKO_ADULT	    ,       // 5 0x0019
       NA_BGM_BGM00		    ,       // 6 0x0002
       NA_BGM_BGM01		    ,       // 7 0x0019
       NA_BGM_BGM02		    ,       // 8 0x001a
       NA_BGM_BGM03		    ,       // 9 0x001a
       NA_BGM_ENEMY		    ,       // 10  0x081a

       NA_BGM_BOSS00		    ,       // 11 0x001b
       NA_BGM_FAIRY_DUNGEON	    ,       // 12  0x001c
       NA_BGM_MARKET		    ,       // 13 0x001d
       NA_BGM_TITLE		    ,       // 14 0x001e
       NA_BGM_LINK_HOUSE	    ,       // 15 0x001f
       NA_BGM_GAME_OVER	    ,       //  16 0x0020
       NA_BGM_BOSS_CLEAR	    ,       //  17 0x0021
       NA_BGM_ITEM_GET		    ,       //  18 0x0922
       NA_BGM_OPENING_GANON	    ,       //  19 0x0023
       NA_BGM_HEART_GET	    ,       //  20 0x0924
       NA_BGM_OCA_LIGHT	    ,       //  21 0x0025
       NA_BGM_BUYO_DANGEON 	    ,       //  22 0x0026
       NA_BGM_KAKARIKO_KID 	    ,       //  23 0x0027
       NA_BGM_GODESS 		    ,       //  24 0x0028
       NA_BGM_HIME 		    ,       //  25 0x0029
       NA_BGM_FIRE_DUNGEON	    ,       //  26 0x002a
       NA_BGM_OPEN_TRE_BOX	    ,       //  27 0x092b
       NA_BGM_FORST_DUNGEON	    ,       //  28 0x002c
       NA_BGM_HIRAL_GARDEN	    ,       //  29 0x002d

       NA_BGM_NARRATION_0	           //  30 0x002e
};

static void bgm_test(void)
{
    if(BREG(32)) {
	BREG(32) = 0;
	Na_StartBgm(bgm_test_no[BREG(33)]);  /* BGM  */
    }
}
#endif
/*==================================================*/
/*    乱数 イニシャル  (1 <= a,b,c <= 30000)        */
/*==================================================*/
static int rnd20, rnd21, rnd22;

static void init_stage_rnd(int a, int b, int c)
{
    rnd20 = a;
    rnd21 = b;
    rnd22 = c;
}    

/*==================================================*/
/*    乱数 発生     (0.0 < rnd() < 1.0)             */
/*==================================================*/
static float stage_rnd(void)
{
    float r;

    rnd20 = (int)((171 * rnd20) % 30269);
    rnd21 = (int)((172 * rnd21) % 30307);
    rnd22 = (int)((170 * rnd22) % 30323);

    r = (float)rnd20 / 30269.0f + (float)rnd21 / 30307.0f + (float)rnd22 / 30323.0f;

    while (r >= 1.0f) r = r - 1.0f;
/*     r = fabsf(fmodf(r, 1.0f)); */
    
    return fabsf(r);
}
/*======================================================================*
      adds2  
 *======================================================================*/
static short adds2(short *a, short b, short p, short max)
{
    short s,s2;

    s2 = (short)(b - *a);
    
    s = (short)(s2 / p);
    
    if(s > max)
	s = max;
    if(s < -max)
	s = (short)(-max);
    
    *a += s;

    return s;
}

/*-----------------------------------------------------------------------
 *
 *	いろいろ設定
 *
 *----------------------------------------------------------------------*/

/* 簡易障害物 */
#if 01
static Fishing_Obj  fishing_obj[FISHING_OBJ_SIZE];
#else
static Fishing_Obj  *fishing_obj;
#endif
/* 簡易子魚 */
static Minnow       minnow[MINNOW_SIZE];
static float        minnow_home_angle_Y1;
static float        minnow_home_angle_Y2;
static float        minnow_home_angle_Y3;
static float        minnow_panic = 0;
/*-----------------------------------------------------------------------
 *	専用効果設定
 *----------------------------------------------------------------------*/
/* 専用高速化効果 ただし同じバンクでの話 */
static Fishing_Eff  fishing_eff[FISHING_EFF_SIZE+30];

static xyz_t zero = {0.0f, 0.0f, 0.0f};
static xyz_t zero3 = {0.0f, 0.0f, 2000.0f};

/* #define static_se_pos zero */
static void fs_hamon_ct(
    xyz_t          *cp,
    Fishing_Eff    *eff,
    xyz_t	*wpos,
    float       start_scale,
    float       end_scale,
    short       prim_a,
    short       max
)
{
    short i;
    
    if(cp != NULL &&
       (cp->z > 500.0f ||
	cp->z < 0.0f)) { /* エリア外？ */
	return;
    }

    for(i=0; i < max ;i++,eff++)  {
	if(eff->mode == 0)  {
	    eff->mode = FS_HAMON;

	    eff->pos = *wpos;
	    eff->vec = zero;
	    eff->acc = zero;

	    eff->fwork[FISHING_EFF_SCALE]   = start_scale * 0.0025f;
	    eff->fwork[FISHING_EFF_SCALE_S] = end_scale * 0.0025f;
	    if(start_scale > 300.0f) {
		eff->prim_a = 0;  /*100 */ /*+ BREG(0)*/
		eff->work[FISHING_EFF_A_AD] = prim_a;
		eff->work[FISHING_EFF_STAT] = 0;
		eff->fwork[FISHING_EFF_SCALE_SP] =
		    (eff->fwork[FISHING_EFF_SCALE_S] - eff->fwork[FISHING_EFF_SCALE]) *
		    (0.1f /*+ (float)BREG(2)/100.0f */- 0.05f);
	    } else {
		eff->prim_a = prim_a;  /*100 */ /*+ BREG(0)*/
		eff->work[FISHING_EFF_STAT] = 1;
		
		eff->fwork[FISHING_EFF_SCALE_SP] =
		    (eff->fwork[FISHING_EFF_SCALE_S] - eff->fwork[FISHING_EFF_SCALE]) *
		    (0.1f /*+ (float)BREG(2)/100.0f */- 0.0f);
	    }
	    break;
	}
    }
}

static void fs_mizu_ct(
    xyz_t          *cp,
    Fishing_Eff    *eff,
    xyz_t	*wpos,
    xyz_t	*wvec,
    float       scale
)
{
    short i;
    xyz_t  acc = {0.0f, -1.0f, 0.0f};

    if(cp != NULL &&
       (cp->z > 500.0f ||
	cp->z < 0.0f)) { /* エリア外？ */
	return;
    }

    for(i=0;i<FISHING_EFF_SIZE;i++,eff++)  {
	if(eff->mode == 0 ||
	   eff->mode == FS_RAIN ||
	   eff->mode == FS_RAIN_HAMON ||
	   eff->mode == FS_RAIN_HAMON_2
	    )  {
	    eff->mode = FS_MIZU;

	    eff->pos = *wpos;
	    eff->vec = *wvec;
	    eff->acc = acc;

	    eff->prim_a = 100 + (short)rnd_f(100.0f);

	    eff->fwork[FISHING_EFF_SCALE]   = scale;
	    break;
	}
    }
}

static void fs_smoke_ct(
    xyz_t          *cp,
    Fishing_Eff    *eff,
    xyz_t	*wpos,
    float       scale
)
{
    short i;
    xyz_t  acc = {0.0f,  0.05f, 0.0f};

/*     acc.y += (float)NS1(76)*0.01f; */
    if(cp != NULL &&
       (cp->z > 500.0f ||
	cp->z < 0.0f)) { /* エリア外？ */
	return;
    }

    for(i=0;i<FISHING_EFF_SIZE-10;i++,eff++)  {
	if(eff->mode == 0)  {
	    eff->mode = FS_SMOKE;
	    
	    eff->pos = *wpos;
	    eff->vec = zero;
	    eff->acc = acc;

	    eff->prim_a = 255/*  + BREG(18) */;
	    eff->count = (short)rnd_f(100.0f);
	    
	    eff->fwork[FISHING_EFF_SCALE]   = scale;
	    eff->fwork[FISHING_EFF_SCALE_S] = scale * (2.0f /* + (float)BREG(19)*0.1f */);
	    break;
	}
    }
}

static void fs_bubble_ct(
    xyz_t          *cp,
    Fishing_Eff    *eff,
    xyz_t	*wpos,
    float       size,
    u8          stat
)
{
    short i;
    xyz_t  vec = {0.0f,  1.0f, 0.0f};

/*     vec.y += (float)NS1(76)*0.01f; */
    if(cp != NULL &&
       (cp->z > 500.0f ||
	cp->z < 0.0f)) { /* エリア外？ */
	return;
    }

    for(i=0;i<FISHING_EFF_SIZE-10;i++,eff++)  {
	if(eff->mode == 0)  {
	    eff->mode = FS_BUBBLE;
	    
	    eff->pos = *wpos;
	    eff->vec = vec;
	    eff->acc = zero;

	    eff->count = (short)rnd_f(100.0f);
	    
/* 	    eff->fwork[FISHING_EFF_SCALE] = (float)(NS1(77)+5)*0.01f; */
/*	    eff->fwork[FISHING_EFF_SCALE] = 0.03f + rnd_f(0.02f);*/
	    eff->fwork[FISHING_EFF_SCALE] = size;
	    
	    eff->work[0] = stat;
	    break;
	}
    }
}

static void fs_rain_ct(
    Fishing_Eff    *eff,
    xyz_t	*wpos,
    xyz_t	*wang
)
{
    short i;
    xyz_t mae;

    mae.x = 0.0f;
    mae.y = 0.0f;
    mae.z = 200.0f/*  + SEX(3) */ /* + KAZ(39) */ + 100.0f;

    eff += 30;
    
    for(i=0+30;i<FISHING_EFF_SIZE+30;i++,eff++)  {
	if(eff->mode == 0)  {
	    eff->mode = FS_RAIN;

	    eff->pos = *wpos;
	    eff->acc = zero;

	    eff->fwork[FISHING_EFF_XANG] = wang->x;
	    eff->fwork[FISHING_EFF_YANG] = wang->y;
	    eff->fwork[FISHING_EFF_ZANG] = wang->z;

	    Matrix_rotateY(	wang->y, SET_MTX);
	    Matrix_rotateX(	wang->x, MULT_MTX);
	    Matrix_Position(&mae, &eff->vec); /*  */
	    break;
	}
    }
}

/* 簡易障害物セット */
static Fishing_Obj_Data fishing_obj_data[] = {
{3,529,-53,-498},
{3,461,-66,-480},
{3,398,-73,-474},
{3,-226,-52,-691},
{3,-300,-41,-710},
{3,-333,-50,-643},
{3,-387,-46,-632},
{3,-484,-43,-596},
{3,-409,-57,-560},
{4,444,-87,-322},
{4,447,-91,-274},
{4,395,-109,-189},
    
{1,617,-29,646},
{1,698,-26,584},
{1,711,-29,501},
{1,757,-28,457},
{1,812,-29,341},
{1,856,-30,235},
{1,847,-31,83},
{1,900,-26,119},
{2,861,-22,137},
{2,836,-22,150},
{2,829,-22,200},
{2,788,-22,232},
{2,803,-22,319},
{2,756,-22,348},
{2,731,-22,377},
{2,700,-22,392},
{2,706,-22,351},
{2,677,-22,286},
{2,691,-22,250},
{2,744,-22,290},
{2,766,-22,201},
{2,781,-22,128},
{2,817,-22, 46},
{2,857,-22,-50},
{2,724,-22,110},
{2,723,-22,145},
{2,728,-22,202},
{2,721,-22,237},
{2,698,-22,312},
{2,660,-22,349},
{2,662,-22,388},
{2,667,-22,432},
{2,732,-22,429},
{2,606,-22,366},
{2,604,-22,286},
{2,620,-22,217},
{2,663,-22,159},
{2,682,-22,73},
{2,777,-22,83},
{2,766,-22,158},
{1,1073,0,-876},
{1,970,0,-853},
{1,896,0,-886},
{1,646,-27,-651},
{1,597,-29,-657},
{1,547,-32,-651},
{1,690,-29,-546},
{1,720,-29,-490},
{1,-756,-30,-409},
{1,-688,-34,-458},
{1,-613,-34,-581},
{2,-593,-22,-479},
{2,-602,-22,-421},
{2,-664,-22,-371},
{2,-708,-22,-316},
{2,-718,-22,-237},
{1,-807,-36,-183},
{1,-856,-29,-259},
{2,-814,-22,-317},
{2,-759,-22,-384},
{2,-718,-22,-441},
{2,-474,-22,-567},
{2,-519,-22,-517},
{2,-539,-22,-487},
{2,-575,-22,-442},
{2,-594,-22,-525},
{2,-669,-22,-514},
{2,-653,-22,-456},
{1,-663,-28,-606},
{1,-708,-26,-567},
{1,-739,-27,-506},
{1,-752,-28,-464},
{1,-709,-29,-513},
{2,-544,-22,-436}, /**/
{2,-559,-22,-397},
{2,-616,-22,-353},
{2,-712,-22,-368},
{2,-678,-22,-403},
{2,-664,-22,-273},
{2,-630,-22,-276},
{2,-579,-22,-311},
{2,-588,-22,-351},
{2,-555,-22,-534},
{2,-547,-22,-567},
{2,-592,-22,-571},
{2,-541,-22,-610},
{2,-476,-22,-629},
{2,-439,-22,-598},
{2,-412,-22,-550},
{2,-411,-22,-606},
{2,-370,-22,-634},
{2,-352,-22,-662},
{2,-413,-22,-641},
{2,-488,-22,-666},
{2,-578,-22,-656},
{2,-560,-22,-640},
{2,-531,-22,-654},
{2,-451,-22,-669},
{2,-439,-22,-699},
{2,-482,-22,-719},
{2,-524,-22,-720},
{2,-569,-22,-714},
{1,-520,-27,-727},
{1,-572,-28,-686},
{1,-588,-32,-631},
{1,-622,-34,-571},
{1,-628,-36,-510},
{1,-655,-36,-466},
{1,-655,-41,-393},
{1,-661,-47,-328},
{1,-723,-40,-287},
{1,-756,-33,-349},
{1,-755,-43,-210},
{2,-770,-22,-281},
{2,-750,-22,-313},
{2,-736,-22,-341},
{2,-620,-22,-418},
{2,-601,-22,-371},
{2,-635,-22,-383},
{2,-627,-22,-311},
{2,-665,-22,-327},
{2,-524,-22,-537},
{2,-514,-22,-579},
{2,-512,-22,-623},
{2,-576,-22,-582},
{2,-600,-22,-608},
{2,-657,-22,-531},
{2,-641,-22,-547},


    
{35, 0, 0, 0},
};

static void fishing_obj_init(Fishing_actor *this, Game_play *game_play)
{
    short i;
    xyz_t col_pos;
    Fishing_Obj    *obj       = &fishing_obj[0];

    this;
    game_play;
    
    init_stage_rnd(1, 29100, 9786);

    /* 葦セット */
    for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	if(fishing_obj_data[i].mode != 35) {
	    obj->mode = fishing_obj_data[i].mode;
	    obj->pos.x = (float)fishing_obj_data[i].x;
	    obj->pos.y = (float)fishing_obj_data[i].y;
	    obj->pos.z = (float)fishing_obj_data[i].z;
	    obj->ang.x = 
		obj->ang.z = 0.0f;
	    
	    obj->count = (short)rnd_f(100.0f);
	    obj->cull_z = 800.0f;
	    
	    if(obj->mode == FS_ASHI) {
		obj->scale = 0.75f + stage_rnd() * 0.25f;
		obj->ang.z = rnd_f(F_PI*2.0f);
		
		if(AGE == 1) { /* 5歳 */
		    obj->scale *= 0.6f;   /* まだ葦も低い */
		}
		obj->cull_z = 1200.0f;
	    } else if(obj->mode == FS_KUI) {
		obj->scale = 0.08f /* + (float)KAZ(58)*0.01f */;
		obj->cull_z = 1200.0f;

		col_pos = obj->pos;
		col_pos.y += /* KAZ(51) +  */50.0f;
		
		CollisionCheck_pos_set(
		    i,
		    &master->ishi_jntsph_info,
		    &col_pos,
		    obj->scale * (3.5f/*  + (float)KAZ(50)*0.01f */)
		    );
	    } else if(obj->mode == FS_LILY) {
		obj->scale = 0.5f + stage_rnd() * 0.3f;
		obj->ang.y = rnd_f(F_PI*2.0f);

		if(AGE == 1) { /* 5歳 */
		    if(i & 0x03) {
			obj->scale *= 0.6f;  /* まだハスが若い */  
		    } else {
			obj->mode = 0;    /* 数も少ない */
		    }
		}
	    } else { /* ISHI */
		obj->scale = 0.3f + stage_rnd() * 0.1f;
		obj->ang.y = rnd_f(F_PI*2.0f);
		obj->cull_z = 1000.0f;
#if 0		
		if(AGE != 1) { /* 17歳 */
		    if(!(i & 0x03)) {
			obj->mode = 0;    /* 数少ない */
		    }
		}
#endif		
		CollisionCheck_pos_set(
		    i,
		    &master->ishi_jntsph_info,
		    &obj->pos,
		    obj->scale);
	    }
	} else {
	    break;
	}
    }
}


/************************************************************************
 *
 *	コンストラクト
 *			
 ************************************************************************/
#define FISH_MAX 15   /* つれる魚の数 */

/* 魚セット位置 */
static Fishing_Fish_Data  fish_set[] = {
    {FISH_KIND_BASS, {  666,    -45,     354},   38,  0.1f},  /* 0  */ 
    {FISH_KIND_BASS, {  681,    -45,     240},   36,  0.1f}, /*  1 */ 
    {FISH_KIND_BASS, {  670,    -45,      90},   41,  0.05f}, /*  2 */ 
    
    {FISH_KIND_BASS, {  615,    -45,    -450},   35,  0.2f}, /*  3 */ 
    {FISH_KIND_BASS, {  500,    -45,    -420},   39,  0.1f}, /*  4 */ 
    {FISH_KIND_BASS, {  420,    -45,    -550},   44,  0.05f}, /*  5 */ 
    
    {FISH_KIND_BASS, { -264,    -45,    -640},   40,  0.1f}, /*  6 */ 
    {FISH_KIND_BASS, { -470,    -45,    -540},   34,  0.2f}, /*  7 */ 
    {FISH_KIND_BASS, { -557,    -45,    -430},   54,  0.01f}, /*  8 */ 
    
    {FISH_KIND_BASS, { -260,    -60,    -330},   47,  0.05f}, /*  9 */ 
    
    {FISH_KIND_BASS, { -500,    -60,     330},   42,  0.06f}, /*  10 */
    
    {FISH_KIND_BASS, {  428,    -40,    -283},   33,  0.2f}, /*  11 */
    
    /* ビッグワン */
    {FISH_KIND_BASS, {  409,    -70,     -230},   57,  0.0f}, /* 12  */
    {FISH_KIND_BASS, {   450,    -67,    -300},   63,  0.0f}, /* 13  */ 
    {FISH_KIND_BASS, {  -136,    -65,    -196},   71,  0.0f}, /* 14  */

    /* 雷魚 */
    {FISH_KIND_SNAKEHEAD, {  -561,    -35,    -547},   90/2,  0.0f}, /* 15  */ 
    {FISH_KIND_SNAKEHEAD, {   667,    -35,     317},   86/2,  0.0f}, /* 16  */ 
};

static void Fishing_actor_ct(Actor *thisx, Game *game)
{
    short i;
    Game_play *game_play = (Game_play *)game;
    Fishing_actor	*this = (Fishing_actor *)thisx;

    static ValueSet_W	value_init[] = {
	Act_vst_s_c(anchor_range, ANCHOR_RANGE_F),
	Act_vst_f_e(anchor_offset_y, 0.0f)
    };

    ValueSet_process((char *)this, value_init);

    Shape_Info_init(&this->actor.shape,
		    0.0f,
		    NULL,
		    0.0f);
#if FS_DEBUG
    if(KAZ(5)) {
	AGE = 1;
    } else {
	AGE = ZCommonGet(link_age);
    }
#if 0    
    KAZ(35) = 35; /* いつでも投げれる */
#endif    
#else    
    AGE = ZCommonGet(link_age);
#endif    

    if(this->actor.arg_data < 100) { /* マスター？ */
	u8 fish_kazu;

#if defined(USE_CIC6105_CHECK)	
	CIC_ERROR = (u8)(!CIC6105_BootRamTest1_is_OK(&cic6105_BootRamTestData1));
#else
	CIC_ERROR = 0;
#endif	
	master = this;
	
	/* 石の当り用 */
	ClObjJntSph_ct(game, &master->ishi_jntsph_info);
	ClObjJntSph_set5_nzm(game, &master->ishi_jntsph_info,
			     thisx,
			     &FsIshiOcInfoJntSphData,
			     master->jntsph_elem );
	
	this->actor.arg_data = 1;
	
        Skeleton_Info2_SV_ct(game,
			     &this->skeleton,
			     &fs_matsu_mdl_info,
			     &fs_matsu_soft_anim_tbl_info);
	
	Skeleton_Info2_init_standard_repeat_morf(
	    &this->skeleton,
	    &fs_matsu_soft_anim_tbl_info,
	    0.0f
	    );
	
	this->actor.move_proc = bm_move;
	this->actor.draw_proc = bm_draw;
	
	thisx->world.position.x = /* KAZ(70) +  */160.0f;
	thisx->world.position.y = /* KAZ(71)  */- 2.0f;
	thisx->world.position.z =/*  KAZ(72) +  */1208.0f;
	
	thisx->shape.angle.sy = 0x2000 * (/* KAZ(73) */ - 3);
	
	Actor_set_scale(thisx, 0.01f + (float)(/* KAZ(74)+ */1)*0.001f);
	
	
	this->actor.eye.position = this->actor.world.position;
	this->actor.eye.position.y += 75.0f /*+ KAZ(75)*/;

#if 0
	Actor_info_part_chg(game_play, &game_play->actor_info,
			    (Actor *)this, ACTOR_PART_PEOPLE); /*  */
#endif	
	Actor_set_status((Actor *)this, ACTOR_STATUS_TALK);

	if(AGE != 1) { /* 17歳 */
	    if(HI_SCORE(HS_FISH) & SAVE_CAP_OFF) {
		bm_head_no = 0; /* ハゲ */
	    } else {
		bm_head_no = 1; /* ハゲ ＋ 帽子 */
	    }
	} else {  /* ５歳 */
	    bm_head_no = 2; /* 若かりし普通頭 */
	}
	
	head_check = 20;  /* 親父ぼうし判定なし時間 */
	
	game_play->special_effect = &fishing_eff[0];
/*	KAZ(66) = game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 1;*/
#if 01
	TIME_SPEED = 1; /* 時間経過単位 */
#else
	REG(15) = 1;
#endif
	fishing_game_mode = 0;  /* 初期化 */
	lure_bgm_time = 10;
	Na_StopBgm(1);  /*  SE BGM */

#if 0
	if(AGE == 1  || KAZ(78) ) { /* 5歳 */
	    if(!(HI_SCORE(HS_FISH) & SAVE_CHILD_PLAY)) { /* 子供で初めて？ */
		HI_SCORE(HS_FISH) &= 0xffffff00;
	    }
	}
#endif	
	if(AGE == 1) { /* 5歳 */
	    if(HI_SCORE(HS_FISH) & 0x0000007f) { /* 最大記録セット */
		fish_record = (float)(HI_SCORE(HS_FISH) & 0x7f);
	    } else {
		fish_record = 40.0f;
	    }
	} else { /* 大人 */
	    if(HI_SCORE(HS_FISH) & 0x7f000000) { /* 最大記録セット */
		fish_record = (float)((HI_SCORE(HS_FISH) & 0x7f000000) >> 24);
	    } else {
		fish_record = 45.0f;
	    }
	}
#if 0	
	if(HI_SCORE(HS_FISH) & 0x7f) { /* 最大記録セット */
	    fish_record = (float)(HI_SCORE(HS_FISH) & 0x7f);
	} else {
	    if(AGE == 1) { /* 5歳 */
		fish_record = 40.0f;
	    } else {
		fish_record = 45.0f;
	    }
	}
#endif
	
	/* ゲーム中用プレイ回数 */
	play_count = (u8)((HI_SCORE(HS_FISH) & 0x00ff0000) >> 16);

#if 0
	/* プレイヤー名前保存 */
	for(i=0;i<8;i++) {
	    Player_Name_S[i] = Player_Name[i];
	}
#endif	
	/* 水の透明度設定 */
	if((play_count & 0x07) == 0x07 /* || KAZ(2) */) { /* ８回に１回水濁る */
	    game_play->room_info.work[0] =  /* KAZ(83) + */  20 + 70;
	    mad_water = 1;
	} else {
	    game_play->room_info.work[0] =  /* KAZ(84) +  */ 20 + 20;
	    mad_water = 0;
	}
	
	if((play_count & 0x07) == 0x06
#if FS_DEBUG	   
	   || KAZ(3)
#endif	   
	    ) { /* 濁る前の日は雨 */
	    wether = 100; /* 環境セット猶予時間 */
#if FS_DEBUG
	    if(KAZ(3)) {
		KAZ(3) = 0;
		HI_SCORE(HS_FISH) &= 0xff00ffff;
		HI_SCORE(HS_FISH) |= 0x00060000;
	    }
#endif	   
	} else {
	    wether = 0;
	}
	
	for(i=0;i<FISHING_EFF_SIZE+30;i++) {
	    fishing_eff[i].mode = 0;
	}

/* 	static Fishing_Obj  fishing_obj[FISHING_OBJ_SIZE]; */
/*
	fishing_obj = (Fishing_Obj *)zelda_malloc(
	    sizeof(Fishing_Obj) * FISHING_OBJ_SIZE);
	    */
	for(i=0;i<FISHING_OBJ_SIZE;i++) {
	    fishing_obj[i].mode = 0;
	}

	minnow_home_angle_Y1 = 0.7f /* + (float)NS1(32)*0.1f */;
	minnow_home_angle_Y2 = 2.3f /* + (float)NS1(33)*0.1f */;
	minnow_home_angle_Y3 = 4.6f /* + (float)NS1(33)*0.1f */;
	
	for(i=0;i<MINNOW_SIZE;i++) {
	    minnow[i].mode = 1;
	    if(i <= 20) {
		minnow[i].t_pos.x = minnow[i].pos.x = sinf(minnow_home_angle_Y1) * (720.0f /* + NS1(34) */);
		minnow[i].t_pos.z = minnow[i].pos.z = cosf(minnow_home_angle_Y1) * (720.0f/*  + NS1(34) */);
	    } else if(i <= 40) {
		minnow[i].t_pos.x = minnow[i].pos.x = sinf(minnow_home_angle_Y2) * (720.0f/*  + NS1(34) */);
		minnow[i].t_pos.z = minnow[i].pos.z = cosf(minnow_home_angle_Y2) * (720.0f/*  + NS1(34) */);
	    } else  {
		minnow[i].t_pos.x = minnow[i].pos.x = sinf(minnow_home_angle_Y3) * (720.0f/*  + NS1(34) */);
		minnow[i].t_pos.z = minnow[i].pos.z = cosf(minnow_home_angle_Y3) * (720.0f/*  + NS1(34) */);
	    }
	    minnow[i].t_pos.y = minnow[i].pos.y = -35.0f;
	    minnow[i].count = (short)rnd_f(100.0f);
	    minnow[i].ang.sx = 0;
	    minnow[i].ang.sy = 0;
	    minnow[i].ang.sz = 0;
	    
	    if(AGE != 1) { /* 17歳 */
		if((i >= 15 && i <= 19) ||
		   (i >= 35 && i <= 39) ||
		   (i >= 55 && i <= 59)
		    ) {
		    minnow[i].mode = 0; /* 数へってる */
		}
	    }
	}
	
	fishing_obj_init(this, game_play);
	
	/* 専用カンバン */
	Actor_info_make_child_actor(&game_play->actor_info,
				    (Actor *)this,
				    (Game *)game_play,
				    En_Kanban,
				    53.0f,
				    -17.0f,
				    982.0f,
				    0,
				    0/* KAZ(9)*0x1000 */,
				    0,
				    0x300);

	/* 水槽の中用 */
	Actor_info_make_actor(&game_play->actor_info,
			      (Game *)game_play,
			      Fishing,
			      0.0f,
			      0.0f,
			      0.0f,
			      0,
			      0,
			      0,
			      200);

	if(
#if FS_DEBUG	    
	    KAZ(1) == 1 ||
#endif	    
	    (play_count & 0x03) == 3 ) { /* 4回に１回雷魚セット */
	    if(AGE != 1) { /* 17歳 */
		fish_kazu = FISH_MAX + 1;
	    } else {
		fish_kazu = FISH_MAX + 2; /* 昔は多い */
	    }
	} else {
	    fish_kazu = FISH_MAX;
	}
	
	for(i=0;i<fish_kazu;i++) {
	    Actor_info_make_actor(&game_play->actor_info,
				  (Game *)game_play,
				  Fishing,
				  (float)fish_set[i].pos.sx,
				  (float)fish_set[i].pos.sy,
				  (float)fish_set[i].pos.sz,
				  0,
				  (short)(rnd_f(65536.0f)),
				  0,
				  100 + i );
	}

#if 0
	Na_StopBgm(1);  /*  SE BGM */
#endif	
	return;
    }
    
    /* 魚 */
/*    this->kind = KAZ(1);*/
#if 0    
    thisx->cull_z = 750.0f /* + KAZ(62) */;
    thisx->cull_r = 50.0f /* + KAZ(63) */;		                /* カリング半径セット */
#endif	
    if(thisx->arg_data  < FISH_MAX + 100 || thisx->arg_data  == 200) { /*BASS?*/
	Skeleton_Info2_SV_ct(game, &this->skeleton,
			     &basu_mdl_info,
			     &basu_soft_anim_tbl_info);
	
	Skeleton_Info2_init_standard_repeat_morf(
	    &this->skeleton,
	    &basu_soft_anim_tbl_info,
	    0.0f
	    );
    } else {
	Skeleton_Info2_SV_ct(game, &this->skeleton,
			     &nz_namazu_mdl_info,
			     &nz_namazu_soft_anim_tbl_info);
	
	Skeleton_Info2_init_standard_repeat_morf(
	    &this->skeleton,
	    &nz_namazu_soft_anim_tbl_info,
	    0.0f
	    );
    }

    
    Skeleton_Info2_anime_play(&this->skeleton);

    if(thisx->arg_data == 200) { /* 水槽用 */
	this->move_mode = FISH_SUISOU;
#if 01	
	Actor_info_part_chg(game_play, &game_play->actor_info,
			    (Actor *)this, ACTOR_PART_OBJ); /*  */
#endif	
	
	Actor_set_status((Actor *)this, ACTOR_STATUS_TALK);
	thisx->anchor_range = ANCHOR_RANGE_A;
#if 0	
	this->size = fish_record; /* 現在の記録が入るはず */
#endif	
	/*
	 * ライトデータリスト追加
	 */
	this->light_list =
	    Global_light_list_new(game, &game_play->global_light, &this->light_data);
    } else {
	this->move_mode   = FISH_STRUCT_WAIT_1;
	this->move_mode_S = FISH_STRUCT_WAIT_1;  /* もどすモード */

	this->kind = fish_set[thisx->arg_data-100].kind; /* 種類 */
	this->brain = fish_set[thisx->arg_data-100].brain; /* ヒット確率 */
	
	this->size = (float)fish_set[thisx->arg_data-100].size; /* 大きさ（長さ）cm  */
	this->size += rnd_f(4.99999f); /*  てきとうに大きさ変えよう */
	if(this->size >= 65.0f) {
	    if(rnd() < 0.05f) {
		this->size += rnd_f(7.99999f); /* 最大８１cm （あがるかな？）*/
	    }
	}
#if FS_DEBUG	
 	if(KAZ(6)) { 
 	    this->size = 80.0f + (float)KAZ(6);   
 	} 
#endif
/*	this->size += KAZ(2);*/
	
	if(AGE == 1) { /* 5歳 */
	    this->size *= 0.73f; /* 子供は少し魚も小さい */
	}
    }
#if 0    
    if(this->kind == FISH_KIND_BASS) {
	Actor_set_scale(thisx, this->size  * (float)(15) * 0.00001f);
    } else {
	Actor_set_scale(thisx, this->size  * (float)(/* KAZ(11) + */ 50 + 15) * 0.000001f);
	thisx->scale.x = thisx->scale.z * (1.1f /* + (float)KAZ(12)*0.1f */);
	thisx->scale.y = thisx->scale.z * (1.1f /* + (float)KAZ(12)*0.1f */);
    }
#endif
/*     Actor_set_status((Actor *)this, ACTOR_STATUS_FIGHT); */
    /*
    ** カメラ テスト
    */
/*    changeCameraSet(ACTIVE_CAMERA(game_play), CAM_SET_FISHING);*/
/*    lockCamera(ACTIVE_CAMERA(game_play), CAM_LOCK_TARGETACTOR, thisx); */
}
/************************************************************************
 *
 *	デストラクト
 *
 ************************************************************************/
static void Fishing_actor_dt(Actor *thisx, Game *game)
{
    Game_play *game_play = (Game_play *)game;
    Fishing_actor	*this = (Fishing_actor *)thisx;
    
    Skeleton_Info_dt(&this->skeleton, game);
     /*
    ** カメラ テスト
    */
/*   changeCameraSet(ACTIVE_CAMERA(game_play), CAM_SET_NORMAL0);*/
    /*
     * ライトデータリスト削除
     */

    if(thisx->arg_data == 200) { /* 水槽魚 ? */
	Global_light_list_delete(game, &game_play->global_light, this->light_list);
    } else {
	if(thisx->arg_data == 1) { /* 親？ */
	    ClObjJntSph_dt_nzf(game, &this->ishi_jntsph_info);
	}
    }
}

/*-----------------------------------------------------------------------
 *	専用効果
 *----------------------------------------------------------------------*/
static void Fishing_Eff_move(Fishing_Eff *eff, Game_play *game_play)
{
    float check_y;
    short i;
    
    for(i=0;i<FISHING_EFF_SIZE+30;i++,eff++) {
	if(eff->mode)  {
	    eff->count ++;
	    eff->pos.x += eff->vec.x;
	    eff->pos.y += eff->vec.y;
	    eff->pos.z += eff->vec.z;
	    
/*	    eff->vec.x += eff->acc.x;*/
	    eff->vec.y += eff->acc.y;
/*	    eff->vec.z += eff->acc.z;*/

	    if(eff->mode == FS_HAMON)  {
		add_calc2(&eff->fwork[FISHING_EFF_SCALE],
			 eff->fwork[FISHING_EFF_SCALE_S],
			 0.2f,
			 eff->fwork[FISHING_EFF_SCALE_SP]
			 );

		if(eff->work[FISHING_EFF_STAT] == 0) {
		    eff->prim_a += 20  - 5 + 5;
		    if(eff->prim_a >= eff->work[FISHING_EFF_A_AD]) {
			eff->prim_a = eff->work[FISHING_EFF_A_AD];
			eff->work[FISHING_EFF_STAT] ++;
		    }
		} else {
		    eff->prim_a -= 6 /*+ BREG(1)*/ - 3 + 2 + 3;
		
		    if(eff->prim_a <= 0) {
			eff->mode = 0;
		    }
		}
	    } else if(eff->mode == FS_SMOKE)  {
		add_calc2(&eff->fwork[FISHING_EFF_SCALE],
			  eff->fwork[FISHING_EFF_SCALE_S],
			  0.1f,
			  0.1f /* + (float)BREG(16)*0.01f */
		    );

		eff->prim_a -= /* BREG(17) + */ 2 + 8;

		if(eff->pos.y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 5.0f) {
		    eff->vec.y = 
			eff->acc.y = 0.0f;
		    
		    eff->prim_a -= 5;
		}
		
		if(eff->prim_a <= 0) {
		    eff->mode = 0;
		}
	    } else if(eff->mode == FS_BUBBLE)  {
		if(eff->work[0] == 0) {
		    check_y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
		} else {
		    check_y = 69.0f /* + KAZ(60) */;
		}
		if(eff->pos.y >= check_y) {
		    eff->mode = 0;
		    
		    if(rnd() < 0.3f) {
			xyz_t pos = eff->pos;
			
			pos.y = check_y;
			
			fs_hamon_ct(
			    NULL,
			    (Fishing_Eff *)game_play->special_effect,
			    &pos,
			    20 /* + KAZ(21) */,
			    60 /* + KAZ(22) */,
			    150,
			    FISHING_EFF_SIZE-10
			    );
		    }
		}
	    } else if(eff->mode == FS_MIZU) {
/*		
		float col;
		
		if(eff->count & 0x06) {
		    col = 80.0f;
		} else {
		    col = 200.0f;
		}

		add_calc2(&eff->fwork[FISHING_EFF_COL],
			 col,
			 1.0f,
			 80.0f
			 );

		eff->prim_a = (short)eff->fwork[FISHING_EFF_COL];
		*/
		
		if(eff->vec.y < -20.0f) { /* MAX落下早さ */
		    eff->vec.y = -20.0f;
		    eff->acc.y =  0.0f;
		}
		
		if(eff->pos.y <= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) { /* 水面？ */
		    eff->mode = 0;
		    
		    if(rnd() < 0.5f) {
			xyz_t pos = eff->pos;
			
			pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
			
			fs_hamon_ct(
			    NULL,
			    (Fishing_Eff *)game_play->special_effect,
			    &pos,
			    40 /* + KAZ(21) */,
			    110 /* + KAZ(22) */,
			    150,
			    FISHING_EFF_SIZE-10
			    );
		    }
		}
	    } else if(eff->mode == FS_RAIN)  {
		if(eff->pos.y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy /* + SEX(14) */) {
		    float rg;
		    if((rg = eff->pos.x*eff->pos.x + eff->pos.z*eff->pos.z) > 920.0f*920.0f) { /* 地面？ */
			eff->pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
			    + (sqrtf(rg) - 920.0f) * 0.11f;
			eff->count = 2 /* + SEX(5) */ + KAZ(17);

			eff->mode = FS_RAIN_HAMON_2;
			eff->fwork[FISHING_EFF_SCALE] = (float)(KAZ(18)+ 30)*0.001f;
		    } else {
			eff->pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 3.0f/*  + KAZ(6) */;
			eff->count = 0;
			
			if(rnd() < 0.75f) {
			    eff->mode = FS_RAIN_HAMON;
			    eff->vec = zero;
			    eff->fwork[FISHING_EFF_SCALE] = (float)(KAZ(18)+ 30)*0.001f;
			} else {
			    eff->mode = 0;
			}
		    }
		    eff->vec = zero;
#if 0		    
		    eff->prim_a = 180 /* + SEX(16) */;
#endif		    
		}
	    } else if(eff->mode >= FS_RAIN_HAMON)  {
		eff->fwork[FISHING_EFF_SCALE] += (float)(KAZ(18)+ 30)*0.001f;
		
		if(eff->count > 5/* +SEX(9) */) {
		    eff->mode = 0;
		}
	    } else if(eff->mode == FS_OYAJI_CAP)  { /* 一個しかでない設定！！！ */
/* 		Player_actor *pla = (Player_actor *)get_player_actor(game_play); */
		float /* x,z, */rg,gnd;
/* 		xyz_t mae; */
/* 		static float cap_spd = 0.0f; */
/* 		static short cap_xangS = 0; */
		
		eff->fwork[FISHING_EFF_SCALE] = (float)(10 /* + KAZ(65) */ )*0.001f;
#if 0		
		x = eff->pos.x -  pla->actor.world.position.x;
		z = eff->pos.z -  pla->actor.world.position.z;
		
		if((x*x + z*z) <= 40.0f*40.0f) {
		    cap_xangS = atans_table(z,x);
		    add_calc2(&cap_spd,
			      0.5f + (float)KAZ(66)*0.01f,
			      1.0f,
			      0.01f + (float)KAZ(67)*0.01f);
		} else {
		    add_calc0(&cap_spd,
			      0.05f,
			      0.01f + (float)KAZ(68)*0.01f);
		}
		adds(&cap_ang.sx,
		     cap_xangS,
		     20,
		     0x200 + KAZ(65) * 0x100);
		
		mae.x = 
		    mae.y = 
		    mae.z = 0.0f;
		if((eff->pos.x*eff->pos.x + eff->pos.z*eff->pos.z) < 900.0f*900.0f) { /* 水面？ */
		    mae.z = cap_spd;
		}
		Matrix_rotateY(	atanf_table(z,x), SET_MTX);
		Matrix_Position(&mae, &eff->vec); /*  */
#endif
		
#if 0		
		cap_ang.sx += KAZ(75);
		cap_ang.sy += KAZ(78);
		cap_ang.sz += KAZ(79);
#endif
		adds(&cap_ang.sy,
		     0,
		     20,
		     100);
		adds(&cap_ang.sx,
		     0,
		     20,
		     100);
		adds(&cap_ang.sz,
		     -0x4000,
		     20,
		     100);


		rg = eff->pos.x*eff->pos.x + eff->pos.z*eff->pos.z;
		gnd = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
		    + (sqrtf(rg) - 920.0f) * (0.147f /* + (float)KAZ(77)*0.0001f */);
		
		if(eff->pos.y > gnd - 10.0f) {
		    eff->pos.y -= /* (float)KAZ(76)*0.01f + */ 0.1f;
		}
#if 0		
		add_calc2(&eff->pos.y,
			  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy +2.0f/* + KAZ(76) */,
			  0.05f,
			  1.0f);
#endif		
#if 0		
/*
		cap_ang.sx = KAZ(75)*0x1000;
		cap_ang.sy = KAZ(78)*0x1000;
		cap_ang.sz = KAZ(79)*0x1000;*/
		eff->pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + KAZ(76);
#endif		
		if((eff->count & 0x0f) == 0) {
		    xyz_t pos;
		    pos = eff->pos;
		    pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
		    
		    fs_hamon_ct(
			NULL,
			(Fishing_Eff *)game_play->special_effect,
			&pos,
			30,
			300,
			150,
			FISHING_EFF_SIZE-10
			);
		}

		if(eff->work[0] >= 0)
		    eff->work[0] ++;
		
		if(eff->work[0] == 30) {
		    message_set(game_play, 0x40b3, NULL);  /* わ─！ */
//		    bakkin = 1;
		}
		if(eff->work[0]  >= 100) {
		    if(message_check( &( game_play->message ) ) == 5 ) {	/* 原選択待ち？ */
			if(pad_on_check(game_play)  ||
			   message_check( &( game_play->message ) ) == 0   ) {
			    message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
			    lupy_increase( -50 ); /*  罰金 */
			    eff->work[0] = -1;
//			    bakkin = 0;
			}
		    }
		}
	    }
	}
    }
}
/*-----------------------------------------------------------------------
 *	ボス別専用効果表示  （ループに無理があるが高速化は捨てがたい）
 *----------------------------------------------------------------------*/

/*ボスより優先低いやつ*/

static void Fishing_Eff_disp(Fishing_Eff *eff, Game_play *game_play)
{
    u8    first_flag = 0;
    float ya;
    short i;
    Game 	*game      = (Game *)game_play;
    Fishing_Eff    *eff_BAK   = eff;
	
    OPEN_DISP(game->graph);
    Matrix_push();
    
    gDPPipeSync(NEXT_POLY_XLU_DISP);

    for(i=0;i<FISHING_EFF_SIZE;i++,eff++) {
	if(eff->mode == FS_HAMON)  {
	    if(first_flag == 0) {
 		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_ripple_DISP_MODE); 
		gDPSetEnvColor(NEXT_POLY_XLU_DISP, 
			       155,
			       155,
			       155,
/*			       255,*/
			       0  
		);
		first_flag ++;
	    }
	    /*
	     * レンダリングモードセット
	     */
	    gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
			    255,
			    255,
			    255,
			    eff->prim_a  /* 注意！ */
	    );
	    
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_scale(eff->fwork[FISHING_EFF_SCALE],
			 1.0f,
			 eff->fwork[FISHING_EFF_SCALE],
			 MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

/* 	    gSPDisplayList(NEXT_POLY_XLU_DISP, g_blast_model); */
 	    gSPDisplayList(NEXT_POLY_XLU_DISP, fs_ripple_model); 
	}
    }
    
    first_flag = 0;
    eff = eff_BAK;

    for(i=0;i<FISHING_EFF_SIZE;i++,eff++) {
	if(eff->mode == FS_MIZU) { 
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_mizu_DISP_MODE);
		
		gDPSetEnvColor(NEXT_POLY_XLU_DISP, 
			       200,
			       200,
			       200,
			         0
		);
/*			    
			    (short)eff->fwork[FISHING_EFF_COL],
			    (short)eff->fwork[FISHING_EFF_COL],
			    (short)eff->fwork[FISHING_EFF_COL],
			    eff->prim_a*/
		first_flag ++;
	    }
	    gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
			    180,
			    180,
			    180,
			    eff->prim_a
		);
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
	    Matrix_scale(eff->fwork[FISHING_EFF_SCALE],
			 eff->fwork[FISHING_EFF_SCALE],
			 1.0f,
			 MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	    gSPDisplayList(NEXT_POLY_XLU_DISP, fs_mizu_modelT);
	}
    }
    
    first_flag = 0;
    eff = eff_BAK;
    
    for(i=0;i<FISHING_EFF_SIZE;i++,eff++) {
	if(eff->mode == FS_SMOKE) {
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_DISP, fs_smoke_DISP_MODE);
		
		gDPSetEnvColor(NEXT_DISP, 
			       /* BREG(20)+ */ 60 - 20,
			       /* BREG(21)+  */40 + 50,
			       /* BREG(22)+  */30 + 50,
			       128
		    );
		first_flag ++;
	    }
	    gDPSetPrimColor(NEXT_DISP, 0, 0,
			    /* BREG(20)+ */ 60 - 20,
			    /* BREG(21)+ */ 40 + 50,
			    /* BREG(22)+ */ 30 + 50,
			    eff->prim_a
	    );
	    
	    gSPSegment(NEXT_DISP, ANIME_MODEL_1_SEGMENT,
		       two_tex_scroll(game->graph,
				      0,
				      ((eff->count+i*3) * 1),
				      ((eff->count+i*3) * 5),
				      32,
				      64,
				      1,
				      00,
				      00,
				      32,
				      32)
		);
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
	    Matrix_scale(eff->fwork[FISHING_EFF_SCALE],
			 eff->fwork[FISHING_EFF_SCALE],
			 1.0f,
			 MULT_MTX);
	    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	    gSPDisplayList(NEXT_DISP, fs_smoke_modelT);
	}
    }
    
    first_flag = 0;
    eff = eff_BAK;
    
    for(i=0;i<FISHING_EFF_SIZE;i++,eff++) {
	if(eff->mode == FS_BUBBLE) {
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_bubble_DISP_MODE);
		
		gDPSetEnvColor(NEXT_POLY_XLU_DISP, 150, 150, 150, 0);
		gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
				255,
				255,
				255,
				255 /* + KAZ(61) */ 
		    );
		first_flag ++;
	    }
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
	    Matrix_scale(eff->fwork[FISHING_EFF_SCALE],
			 eff->fwork[FISHING_EFF_SCALE],
			 1.0f,
			 MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	    gSPDisplayList(NEXT_POLY_XLU_DISP, fs_bubble_model);
	}
    }
    
    first_flag = 0;
    eff = eff_BAK;
    
/*     KAZ(40) = 0; */
    
    eff += 30;
    
    for(i=30;i<FISHING_EFF_SIZE+30;i++,eff++) {
	if(eff->mode == FS_RAIN) {
/* 	    KAZ(40)++; */
	    if(first_flag == 0) {
#if 0		
		gSPDisplayList(NEXT_DISP, fs_line_MODE);
		gDPSetPrimColor(NEXT_DISP, 0, 0,
				255 /* + KAZ(22) */,
				255 /* + KAZ(23) */,
				255 /* + KAZ(24) */,
				255
				);
#endif		
		/* 表示 指定	*/
		SET_NOW_POLY_XLU_DISP(rcp_mode_set(NOW_POLY_XLU_DISP, 20));
		gDPSetCombineMode(NEXT_POLY_XLU_DISP, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
		gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
				150/*  + SEX(4) */,
				255/*  + SEX(5) */,
				255/*  + SEX(6) */,
				30/*   + SEX(7) */);
		first_flag ++;
	    }
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_rotateY( eff->fwork[FISHING_EFF_YANG], MULT_MTX);
	    Matrix_rotateX( eff->fwork[FISHING_EFF_XANG]/*  + F_PI*(0.0f + (float)SEX(3)*0.5f) */, MULT_MTX);
	    Matrix_rotateZ( eff->fwork[FISHING_EFF_ZANG], MULT_MTX);
	    Matrix_scale( /* (float)SEX(0)*0.001f + */  0.002f,
			  1.0f,
			  /* (float)SEX(2)*0.001f +  */ 0.10f,
			 MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
 	    gSPDisplayList(NEXT_POLY_XLU_DISP, fs_rain_model); 
	}
    }
    
    _texture_z_light_fog_prim_xlu(game->graph);
    
    first_flag = 0;
    eff = eff_BAK;
    
    eff += 30;
    
    for(i=30;i<FISHING_EFF_SIZE+30;i++,eff++) {
	if(eff->mode == FS_RAIN_HAMON)  {
/* 	    KAZ(40)++; */
	    if(first_flag == 0) {
 		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_ripple_DISP_MODE); 
		gDPSetEnvColor(NEXT_POLY_XLU_DISP, 
			       155,
			       155,
			       155,
			       0  
		);
		gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
				255,
				255,
				255,
				130
		    );
		first_flag ++;
	    }
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_scale(eff->fwork[FISHING_EFF_SCALE],
			 1.0f,
			 eff->fwork[FISHING_EFF_SCALE],
			 MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
/* 	    gSPDisplayList(NEXT_POLY_XLU_DISP, g_blast_model); */
 	    gSPDisplayList(NEXT_POLY_XLU_DISP, fs_ripple_model); 
	}
    }

    first_flag = 0;
    eff = eff_BAK;
    
    eff += 30;
    
    for(i=30;i<FISHING_EFF_SIZE+30;i++,eff++) {
	if(eff->mode == FS_RAIN_HAMON_2)  {
/* 	    KAZ(40)++; */
	    if(first_flag == 0) {
 		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_rain_sibuki_DISP_MODE); 
		gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
				255,
				255,
				255,
				80+KAZ(19)
		    );
		first_flag ++;
	    }

	    if(rnd() < 0.5f)
		ya = 0.0f;
	    else
		ya = F_PI;
	    
	    Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	    Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
	    Matrix_rotateY( ya, MULT_MTX);
	    Matrix_scale(eff->fwork[FISHING_EFF_SCALE] /* * (1.0f + (float)KAZ(16)*0.01f) */,
			 eff->fwork[FISHING_EFF_SCALE] /* * (1.0f + (float)KAZ(16)*0.01f) */,
			 1.0f,
			 MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
 	    gSPDisplayList(NEXT_POLY_XLU_DISP, fs_rain_sibuki_model); 
	}
    }
    
    
    eff = eff_BAK;
    
    if(eff->mode == FS_OYAJI_CAP) {
	Matrix_translate(eff->pos.x, eff->pos.y, eff->pos.z, SET_MTX);
	Matrix_rotateY((float)cap_ang.sy*F_PI/32768.0f, MULT_MTX);
	Matrix_rotateX((float)cap_ang.sx*F_PI/32768.0f, MULT_MTX);
	Matrix_rotateZ((float)cap_ang.sz*F_PI/32768.0f, MULT_MTX);
	Matrix_scale(eff->fwork[FISHING_EFF_SCALE],
		     eff->fwork[FISHING_EFF_SCALE],
		     eff->fwork[FISHING_EFF_SCALE],
		     MULT_MTX);
	Matrix_translate(  -1250.0f/*  + GREG(25) */, 0.0f/* GREG(26) */, 0.0f/* GREG(27) */,     MULT_MTX);
	Matrix_rotateX( F_PI*0.5f, MULT_MTX);
	gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	gSPDisplayList(NEXT_DISP, fs_cap_model);
    }
    
    Matrix_pull();
    CLOSE_DISP(game->graph);
}

static void backwater_disp(Game_play *game_play)
{
    Game 	*game      = (Game *)game_play;
	
    OPEN_DISP(game->graph);

    gSPSegment(NEXT_POLY_XLU_DISP, ANIME_MODEL_2_SEGMENT,
	       two_tex_scroll(game->graph,
			      0,
			      (game_play->game_frame_counter  * 1),
			      (game_play->game_frame_counter  * 8),
			      32,
			      64,
			      1,
			      -(game_play->game_frame_counter  * 2),
			      0,
			      16,
			      16)
	);
    
    gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
		    195,
		    225,
		    235,
		    /*GREG(80) + */50
	);
	    
    Matrix_translate(/*  GREG(81)+ */ 670.0f,/*  GREG(82)  */- 24.0f, /* GREG(83)  */- 600.0f,  SET_MTX);
    Matrix_scale(/* (float)GREG(84)*0.001f */ + 0.02f, 1.0f,/* (float)GREG(84)*0.001f */ + 0.02f,
		 MULT_MTX);
    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(NEXT_POLY_XLU_DISP, SEGMENT_TO_KSEG0(fs_backwater_modelT));


#if 0
    Matrix_translate(0.0f, 50.0f + KAZ(65), 0.0f, SET_MTX);
    Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
    Matrix_scale(
	(float)KAZ(64)*0.01f,
	(float)KAZ(64)*0.01f,
	1.0f,
	MULT_MTX);
    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(NEXT_POLY_XLU_DISP, SEGMENT_TO_KSEG0(test_rua_body_model));
#endif    
    CLOSE_DISP(game->graph);
}


/* 親父の台判定 */
static int oyaji_floor_check(xyz_t *pos)
{
    if((pos->x >= 110.0f &&
	pos->x <= 150.0f &&
	pos->z <= 1400.0f &&
	pos->z >= 1160.0f) ||
       (pos->x >= 110.0f &&
	pos->x <= 210.0f &&
	pos->z <= 1200.0f &&
	pos->z >= 1160.0f)) {

	if(pos->y <= 42.0f) {
	    return 1;
	}
    }

    return 0;
}


#if 0
static float sanbashi_check(xyz_t *pos, float offset)
{
    float yck = 30.0f;
    
    /* 平面部分 */
    if(fabsf(pos->z) < 60.0f + offset &&
       pos->x >= (440.0f - offset) &&  pos->x <= 840.0f) {
	if(pos->y <= 30.0f && pos->y > 10.0f) {
	    return yck;
	}
    }

    /* 坂部分 tan = 0.3 */
    if(fabsf(pos->z) < 60.0f + offset &&
       pos->x >= 840.0f &&  pos->x <= 990.0f) {
	yck = 30.0f - (pos->x - 840.0f) * 0.3f;

	if(pos->y <= yck && pos->y > yck - 20.0f) {
	    return yck;
	}
    }    
    return 1000.0f;
}
#endif

/*******************************************************************

    フィッシング！！

***********************************************************************/

/*
 *    糸の制御
 */

/* 1 ねもとから制御 */
static void line_control(Game_play *game_play,
		       xyz_t *base_pos,
		       xyz_t *pos,
		       xyz_t *ang,
		       xyz_t *spd)
{
    short i,j;
    float x,y,z,xa,ya,r,y2,gnd,grv/*,y3*/;
    float rg;
    xyz_t mae = {0.0f, 0.0f, 0.0f},ato;
    short line_cap_s;
    xyz_t start_pos;
    xyz_t end_pos;
    float xr,yr,zr;
/*     float kansei_power; */

/*     if(NS1(80)) { */
/* 	NS1(80) = 0; */
/* 	line_tensyon = 10; */
/*     } */
    
    if(line_tensyon) { /* ライン張る？ */
	start_pos = *(base_pos);
	end_pos = *(pos+LINE_MAX_JOINT-1);
	
	xr = end_pos.x  - start_pos.x;
	yr = end_pos.y  - start_pos.y;
	zr = end_pos.z  - start_pos.z;

/*	    r = sqrtf(xr*xr + yr*yr + zr*zr) * (0.95f + (float)SEX(67)*0.01f);*/
	r = sqrtf(xr*xr + yr*yr + zr*zr) * (0.97f /* + (float)SEX(67)*0.01f */);
	
	if(r > 1000.0f) 
		r = 1000.0f;
	line_cap = (float)LINE_MAX_JOINT - (r * (float)LINE_MAX_JOINT*0.001f); /* 飛んだ距離からラインの残量を求める */
    }
    
    line_cap_s =  (short)line_cap;
    
    *spd;
    
    mae.z = 5.0f * 200.0f/(float)LINE_MAX_JOINT;

    for(i=0;i<LINE_MAX_JOINT;i++) {
	if(i <= line_cap_s) {  /* 付根の位置 */
	    *(pos+i) = *(base_pos);
	} else {              /* 慣性力クリアー */
	    if(line_tensyon) {
		float p = (float)(i - line_cap_s)/(float)(LINE_MAX_JOINT - (line_cap_s-1));

		add_calc2(&(pos+i)->x,
			  start_pos.x + xr * p,
			  1.0f,
			  20.0f/*  + NS1(81) */);
		add_calc2(&(pos+i)->y,
			  start_pos.y + yr * p,
			  1.0f,
			  20.0f/*  + NS1(81) */);
		add_calc2(&(pos+i)->z,
			  start_pos.z + zr * p,
			  1.0f,
			  20.0f/*  + NS1(81) */);
/*		
		(pos+i)->x = start_pos.x + xr * p;
		(pos+i)->y = start_pos.y + yr * p;
		(pos+i)->z = start_pos.z + zr * p;*/
	    }
#if 0	    
	    add_calc2(&(spd+i)->x,
		     0.0f,
		     1.0f,
		     1.0f /* + (float)SEX(86)*0.01f */
		     );
	    add_calc2(&(spd+i)->y,
		     0.0f,
		     1.0f,
		     1.0f /* + (float)SEX(86)*0.01f */
		     );
	    add_calc2(&(spd+i)->z,
		     0.0f,
		     1.0f,
		     1.0f /* + (float)SEX(86)*0.01f */
		     );
#endif	    
	}
    }
    
    for(i=line_cap_s+1,j=0;i<LINE_MAX_JOINT;i++,j++) {
	x =  (pos+i)->x /* + (spd+i)->x  */- (pos+i-1)->x;
	
	grv = line_G /** gp */* 2.0f;

	y2 = (pos+i)->y /* + (spd+i)->y */;

#if 0
	/* 桟橋付近は,,,,*/
	if(sanbashi_check((pos+i), 20.0f) != 1000.0f && i < LINE_MAX_JOINT - 20) {
	    grv = 0.0f;
	}
#endif
	
/*	
	if(fabsf((pos+i)->z) < 80.0f + BREG(80) &&
	   (pos+i)->x >= 440.0f &&  (pos+i)->x <= 840.0f &&
	   y2 < 30.0f
	    ) {
	    grv = 0.0f;
	}
	*/
	/* 水辺の簡易皿地形判定 */
	if( (rg = (pos+i)->x*(pos+i)->x + (pos+i)->z*(pos+i)->z) > 920.0f*920.0f) {
	    gnd = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
		+ (sqrtf(rg) - 920.0f) * 0.11f;
	} else {
	    gnd = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
	}
	
	if(lure_type == LURE_TYPE_WORM) {
	    float gnd2;
	    if(y2 < gnd) {
		gnd2 = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
		    + (sqrtf(rg) - 920.0f) * (0.147f /* + (float)KAZ(77)*0.0001f */);
		
		if(y2 > gnd2) {
		    float grv2;
		    
		    grv2 = (y2 - gnd2)*(0.05f /* + (float)KAZ(75)*0.01f */);
		    
		    if(grv2 > (float)(30 /* + KAZ(76) */)*0.01f)
			grv2 = (float)(30 /* + KAZ(76) */)*0.01f;

		    if(i >= LINE_MAX_JOINT - 100) {
			grv2 *= (float)(i - (LINE_MAX_JOINT - 100)) * 0.02f;
			y2 -= grv2;  /* 重力 */
		    }
		}
	    } else {
		y2 -= grv;
	    }
	} else {
	    if(i > LINE_MAX_JOINT - 10 /*&& SEX(30) == 0*/) {
		if(y2 > gnd) {
		    float grv2;
		    
		    grv2 = (y2 - gnd)*0.2f;
		    
		    if(grv2 > grv)
			grv2 = grv;
		    
		    y2 -= grv2;  /* 重力 */
		}
	    } else {  /* 先端以外はわざとくちゃくちゃする */
		if(y2 > gnd) {
		    y2 -= grv;
		}
	    }
	}
	
	
	if(oyaji_floor_check((pos+i))) {
	    y2 = 42.0f;
	}
#if 0
	/* 桟橋チェック */
	if((y3 = sanbashi_check((pos+i), 0.0f)) != 1000.0f) {
	    y2 = y3;
	}
#endif	
/*	
	if(fabsf((pos+i)->z) < 60.0f &&
	   (pos+i)->x >= 440.0f &&  (pos+i)->x <= 840.0f &&
	   y2 < 30.0f
	    ) {
	    y2 = 30.0f;
	}
	*/
/*	
	if(y2 < gnd) {
	    y2 = gnd;
	}
	*/
	
	y = y2  - (pos+i-1)->y;
	
	z =  (pos+i)->z /* + (spd+i)->z */ - (pos+i-1)->z;
	
	ya = atanf_table(z,x);
	r  = sqrtf(x*x + z*z);
	xa = -atanf_table(r, y);
	
	(ang+i-1)->y = ya;
	(ang+i-1)->x = xa;
	
	Matrix_rotateY(	ya, SET_MTX);
	Matrix_rotateX(	xa, MULT_MTX);
	Matrix_Position(&mae, &ato); /*  */
#if 0	
	x = (pos+i)->x;
	y = (pos+i)->y;
	z = (pos+i)->z;
#endif	
	(pos+i)->x = (pos+i-1)->x + ato.x;
	(pos+i)->y = (pos+i-1)->y + ato.y;
	(pos+i)->z = (pos+i-1)->z + ato.z;
#if 0
	kansei_power = /* (float)SEX(88)*0.01f + */  (float)(LINE_MAX_JOINT-1 - j) * (0.005f /* + (float)SEX(89)*0.0001f */) *
	    (float)(/* SEX(87)  */- 70.0f + 70.0f)*0.01f;
	
	(spd+i)->x = ((pos+i)->x - x) * kansei_power;
	(spd+i)->y = ((pos+i)->y - y) * kansei_power;
	(spd+i)->z = ((pos+i)->z - z) * kansei_power;
/*
	(spd+i)->x *= ((float)SEX(88)*0.01f +  (float)(LINE_MAX_JOINT-1 - j) * (0.005f + (float)SEX(89)*0.0001f ));
	(spd+i)->y *= ((float)SEX(88)*0.01f +  (float)(LINE_MAX_JOINT-1 - j) * (0.005f + (float)SEX(89)*0.0001f ));
	(spd+i)->z *= ((float)SEX(88)*0.01f +  (float)(LINE_MAX_JOINT-1 - j) * (0.005f + (float)SEX(89)*0.0001f ));
	*/
	if((spd+i)->x > /* SEX(90)+ */30.0f)
	    (spd+i)->x = /* SEX(90)+ */30.0f;
	if((spd+i)->x < /* -SEX(90) */-30.0f)
	    (spd+i)->x = /* -SEX(90) */-30.0f;
	if((spd+i)->y > /* SEX(90)+ */30.0f)
	    (spd+i)->y = /* SEX(90)+ */30.0f;
	if((spd+i)->y < /* -SEX(90) */-30.0f)
	    (spd+i)->y = /* -SEX(90) */-30.0f;
	if((spd+i)->z > /* SEX(90)+ */30.0f)
	    (spd+i)->z = /* SEX(90)+ */30.0f;
	if((spd+i)->z < /* -SEX(90) */-30.0f)
	    (spd+i)->z = /* -SEX(90) */-30.0f;
#endif	
    }

}

/* 2 先端から制御 */
static void line_control2(xyz_t *pos)
{
    short i;
    float x,y,z,xa,ya,r;
    xyz_t mae = {0.0f, 0.0f, 0.0f},ato;
    short line_cap_s = (short)line_cap;

    mae.z = 5.0f * 200.0f/(float)LINE_MAX_JOINT;
/*
    (pos+199)->x += SEX(10);
    (pos+199)->z += SEX(11);
    */
    for(i=LINE_MAX_JOINT-1-1;i > line_cap_s;i--) {
	x =  (pos+i)->x   - (pos+i+1)->x;
	y =  (pos+i)->y   - (pos+i+1)->y;
#if 0	
	y2 = (pos+i)->y   - (0.0f);  /* 2.0は重力 */
	
	if(mizu_floor_check((pos+i), 0.0f)) {
	    gr = 2.0f /*+ SEX(4)*/;
	} else {
	    gr = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
	}
	
	if(y2 < gr) {
	    y2 = gr;
	}
	
	y = y2  - (pos+i+1)->y;
#endif	
	z =  (pos+i)->z - (pos+i+1)->z;
	
	ya = atanf_table(z,x);
	r  = sqrtf(x*x + z*z);
	xa = -atanf_table(r,y);
	
	Matrix_rotateY(	ya, SET_MTX);
	Matrix_rotateX(	xa, MULT_MTX);
	Matrix_Position(&mae, &ato); /*  */
	
	(pos+i)->x = (pos+i+1)->x + ato.x;
	(pos+i)->y = (pos+i+1)->y + ato.y;
	(pos+i)->z = (pos+i+1)->z + ato.z;
    }
}

/* 針の制御 */
static void hook_draw(Game_play  *game_play, 
		      xyz_t *base_pos,
		      xyz_t *pos, u8 no)
{
    float x,y,z,xa,ya,r,grv;
    xyz_t mae = {0.0f, 0.0f, 1.0f},ato;
    Player_actor *pla = (Player_actor *)get_player_actor(game_play);
    OPEN_DISP(game_play->g.graph);
    
    Matrix_push();

    /* 重力 */

    if(lure_mode == LURE_MODE_ACTION &&
       (base_pos->y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy ||
	(lure_with_head && no) )
	) {
	grv = 0.0f; /* ようは地上でルアーひきずってるとき */
    } else if(base_pos->y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) { /* 水中？ */
	grv = -1.0f;
    } else {
	grv = -3.0f;
    }

/*     mae.z += (float)GREG(39)*0.1f;   */

    x =  pos->x - base_pos->x;
    y =  pos->y - base_pos->y + grv;
    z =  pos->z - base_pos->z;

    ya = atanf_table(z,x);
    r  = sqrtf(x*x + z*z);
    xa = -atanf_table(r, y);
	
    Matrix_rotateY(	ya, SET_MTX);
    Matrix_rotateX(	xa, MULT_MTX);
    Matrix_Position(&mae, &ato); /*  */
    
    pos->x = base_pos->x + ato.x;
    pos->y = base_pos->y + ato.y;
    pos->z = base_pos->z + ato.z;

    Matrix_translate(base_pos->x,
		     base_pos->y,
		     base_pos->z,
		     SET_MTX);

    if(pla->actor.speedF == 0.0f &&
       lure_act_speed == 0.0f) { /* 移動なし？ */
	add_calc2(&hook_angle_Y[no],  /* ぷるぷるせんように */
		  ya,
		  0.1f,
		  0.3f /* + (float)BREG(22)*0.01f */);
    } else {
	hook_angle_Y[no] = ya;
#if 0	
	add_calc2(&hook_angle_Y[no],
		  ya,
		  0.5f,
		  0.75f /* + (float)BREG(22)*0.01f */);
#endif	
    }

    Matrix_rotateY(	hook_angle_Y[no], MULT_MTX);
    Matrix_rotateX(	xa, MULT_MTX);
	
    Matrix_scale(
	/*  (float)GREG(35)*0.0001f +  */ 0.006f - 0.002f,
	/*  (float)GREG(36)*0.0001f +  */ 0.006f - 0.002f,
	/*  (float)GREG(37)*0.0001f +  */ 0.006f - 0.001f,
	MULT_MTX);
	
    Matrix_rotateY(F_PI, MULT_MTX);
    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    
    gSPDisplayList(NEXT_DISP, lure_hook_model);
    
    Matrix_rotateZ(0.5f*F_PI, MULT_MTX);
    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    
    gSPDisplayList(NEXT_DISP, lure_hook_model);

    if(no == 1) { /* シッポの針？ */
#if 0	
	if(/* GREG(31) &&  */bm_head_no == 1) {
/* 	    GREG(31) = 0; */
	    bm_head_no = 0;
	    lure_with_head = 1;
	    message_set(game_play, 0x4087, NULL);  /* コラ！ */
	}
#endif	
	if(lure_with_head) {
	    Matrix_scale(
		/* (float)(GREG(30))*0.001f + */ 2.0f,
		/* (float)(GREG(30))*0.001f + */ 2.0f,
		/* (float)(GREG(30))*0.001f +  */2.0f,
		MULT_MTX);
/* 	    if(lure_with_head == 1) { */
	    Matrix_translate(  1250.0f-1000.0f /*+GREG(25)*/, 0.0f/*+ GREG(26)*/,-1400.0f/*+GREG(27)*/ ,     MULT_MTX);
/* 	    } else { */
#if 0		
		Matrix_translate(  -1300.0f/*  + GREG(25) */, 100.0f/*  + GREG(26) */, -1300.0f/* +GREG(27) */,     MULT_MTX);
#endif		
/* 	    } */
	    Matrix_push();
	    if(lure_with_head_off) {
		Fishing_Eff    *eff = (Fishing_Eff *)game_play->special_effect;
		MtxF m;
		
		Matrix_Position(&zero, &eff->pos);
		Matrix_get(&m);
		Matrix_to_rotate(&m, &cap_ang);

		lure_with_head_off = 0;
 		lure_with_head = 0;
		
		eff->mode = FS_OYAJI_CAP;
		eff->work[0] = 0;

		eff->vec = zero;
		eff->acc = zero;
/*		
		eff->fwork[FISHING_EFF_XANG] = (float)cap_ang.sx*F_PI/32768.0f;
		eff->fwork[FISHING_EFF_YANG] = (float)cap_ang.sy*F_PI/32768.0f;
		eff->fwork[FISHING_EFF_ZANG] = (float)cap_ang.sz*F_PI/32768.0f;*/
	    }
	    Matrix_pull();
	    Matrix_translate(  -1250.0f/*  + GREG(25) */, 0.0f/* GREG(26) */, 0.0f/* GREG(27) */,     MULT_MTX);
	    Matrix_rotateX( F_PI*0.5f, MULT_MTX);
	    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
/* 	    if(lure_with_head == 1) { */
	    gSPDisplayList(NEXT_DISP, fs_cap_model);
/* 	    } else if (lure_with_head == 2) { */
/* 		gSPDisplayList(NEXT_DISP, fs_zura_model); */
/* 	    } */

	}
    }
    
    
    Matrix_pull();
    
    CLOSE_DISP(game_play->g.graph);
}


/* わーむの表示 */
static void worm_control(Game_play *game_play)
{
    short i;
    float x,y,z,xa,ya,r;
    float grv;
    xyz_t mae = {0.0f, 0.0f, 0.0f},ato,mae2,vv,vv2;
    xyz_t *pos/* ,*ang */;
    Player_actor *pla = (Player_actor *)get_player_actor(game_play);

    pos = &worm_shape_pos[0];
/*     ang = &worm_shape_angle[0]; */
    
    mae.z = 10.0f /* + (float)GREG(81)*0.1f */ - 9.0f  - 0.15f /* + (float)GREG(17)*0.01f */;

    *pos = lure_pos; /* 先頭位置 */

    /* 重力チェック */
    if(lure_hirotta) { /* ひろったデモ ? */
	grv = /*(float)GREG(92)*0.1f  */- 1.0f;
    } else {
	if(lure_pos.y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
	    grv = /* (float)GREG(82)*0.1f + */ 0.5f;
	} else {
	    grv = /* (float)GREG(82)*0.1f  */- 5.0f;
	}
    }

    if(lure_mode == LURE_MODE_CATCH) {
	Matrix_rotateY( (float)pla->actor.shape.angle.sy*(F_PI/32768.0f) /* + (float)KAZ(27)*0.01f, */, SET_MTX);
	mae2.x = -2.0f /* + KAZ(28) */+ 7.0f;
	mae2.y = 0.0f;
	mae2.z = 3.0f /* + KAZ(29) */;
	Matrix_Position(&mae2, &vv); /*  */
    }
    for(i=1;i<20;i++) {
	if(i < 10/* +KAZ(24) */ && lure_mode == LURE_MODE_CATCH) {
	    vv2.x = vv.x * (float)(10/* +KAZ(24) */-i)*0.1f;
	    vv2.z = vv.z * (float)(10/* +KAZ(24) */-i)*0.1f;
	} else {
	    vv2.x = 
		vv2.z = 0.0f;
	}
	x =  (pos+i)->x - (pos+i-1)->x + vv2.x;
	y =  (pos+i)->y - (pos+i-1)->y + grv;
	z =  (pos+i)->z - (pos+i-1)->z + vv2.z;
	
	ya = atanf_table(z,x);
	r  = sqrtf(x*x + z*z);
	xa = -atanf_table(r, y);
	
/* 	(ang+i-1)->y = ya; */
/* 	(ang+i-1)->x = xa; */
	
	Matrix_rotateY(	ya, SET_MTX);
	Matrix_rotateX(	xa, MULT_MTX);
	Matrix_Position(&mae, &ato); /*  */
	
	(pos+i)->x = (pos+i-1)->x + ato.x;
	(pos+i)->y = (pos+i-1)->y + ato.y;
	(pos+i)->z = (pos+i-1)->z + ato.z;
    }
}
#if 0
static Gfx *worm_shape[] = {
    mo_base_test,
    mo_body_1,
    mo_body_2,
    mo_body_3,
    mo_body_4,
    mo_body_5,
    mo_body_6,
    mo_body_7,
    mo_body_8,
    mo_body_9,
    mo_body_10,
};
#endif

static float worm_scale[] = {
    1.0f, /* 0  */
    1.5f, /* 1  */
    1.8f, /* 2  */
    2.0f, /* 3  */
    1.8f, /* 4  */
    1.6f, /* 5  */
    1.4f, /* 6  */
    1.2f, /* 7  */
    1.0f, /* 8  */
    1.0f, /* 9  */
    0.9f, /*10  */
    0.85f,/* 1  */
    0.8f, /* 2  */
    0.7f, /* 3  */
    0.8f, /* 4  */
    1.0f, /* 5  */
    1.2f, /* 6  */
    1.1f, /* 7  */
    1.0f, /* 8  */
    0.8f, /* 9  */
};


static void worm_disp(Game_play *game_play)
{
    Game *game = (Game *)game_play;
    short i;
    OPEN_DISP(game->graph);

    worm_control(game_play);

/*     if(KAZ(13)) { */
/* 	worm_eat = KAZ(13)-1; */
/*     } */
    
    if(lure_pos.y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
	_texture_z_light_fog_prim(game->graph);
	
	gSPDisplayList(NEXT_DISP, worm_DISP_MODE);
	
	
	for(i=20-1;i>=0;i--) {
	    if((i + worm_eat) <= 20-1) {
		Matrix_translate(
		    worm_shape_pos[i].x,
		    worm_shape_pos[i].y,
		    worm_shape_pos[i].z,
		    SET_MTX);
		
		Matrix_scale(
		    worm_scale[i + worm_eat] * (0.05f  - 0.01f/*   + (float)GREG(16)*0.001f */ ),
		    worm_scale[i + worm_eat] * (0.05f  - 0.01f/*   + (float)GREG(16)*0.001f */ ),
		    worm_scale[i + worm_eat] * (0.05f  - 0.01f/*   + (float)GREG(16)*0.001f */ ),
		    MULT_MTX);
	    
		Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
/* 	    Matrix_rotateZ(	(float)lure_count * (float)KAZ(5)*0.0001f,  MULT_MTX); */
		gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_DISP, worm_model);
	    }
	}
    } else {
	_texture_z_light_fog_prim_xlu(game->graph);
	
	gSPDisplayList(NEXT_POLY_XLU_DISP, worm_DISP_MODE);
	
	
	for(i=20-1;i>=0;i--) {
	    if((i + worm_eat) <= 20-1) {
		Matrix_translate(
		    worm_shape_pos[i].x,
		    worm_shape_pos[i].y,
		    worm_shape_pos[i].z,
		    SET_MTX);
		
		Matrix_scale(
		    worm_scale[i + worm_eat] * (0.05f  - 0.01f /*  + (float)GREG(16)*0.001f */ ),
		    worm_scale[i + worm_eat] * (0.05f  - 0.01f /*  + (float)GREG(16)*0.001f */ ),
		    worm_scale[i + worm_eat] * (0.05f  - 0.01f /*  + (float)GREG(16)*0.001f */ ),
		    MULT_MTX);
		
		Matrix_rotate_scale_exchange(&game_play->softsprite_matrix);
/* 	    Matrix_rotateZ(	(float)lure_count * (float)KAZ(5)*0.0001f,  MULT_MTX); */
		gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_POLY_XLU_DISP, worm_model);
	    }
	}
    }
	
    CLOSE_DISP(game->graph);
}



static void fishing_draw(Game_play *game_play,
		       xyz_t *pos,
		       xyz_t *ang)
{
/*   xyz_t mae,ato; */
    xyz_t mae,ato;
    xyz_t hook_base_P[2];
    short i;
    short line_cap_s = (short)line_cap;
    Game *game = (Game *)game_play;
    Player_actor *pla = (Player_actor *)get_player_actor(game_play);
    OPEN_DISP(game->graph);
    
    _texture_z_light_fog_prim(game->graph);
    
    Matrix_push();

    if(lure_hirotta) { /* 拾ったデモ用？ */
	xyz_t save_p;

	save_p = lure_pos;

	lure_pos = lure_hirotta_pos;
	
	worm_disp(game_play);

	lure_pos = save_p;
    }
    /* ルアーの表示 */
    if(lure_mode == LURE_MODE_FISHON ||
       lure_mode == LURE_MODE_CATCH) { /* 食わえられた？ むりやり表示 ずれんように*/
	lure_pos = hit_fish_actor->pl_catch_pos;
	if(lure_mode == LURE_MODE_CATCH &&
	   lure_type == LURE_TYPE_WORM) { /* わーむのキャッチデモは少しずらそう */
	    
	    Matrix_rotateY( (float)pla->actor.shape.angle.sy*(F_PI/32768.0f), SET_MTX);
	    mae.x = 2.0f /* + KAZ(25) */;
	    mae.y = 0.0f;
	    mae.z = 0.0f /* + KAZ(26) */;
	    Matrix_Position(&mae, &ato); /*  */
	    lure_pos.x += ato.x;
	    lure_pos.z += ato.z;
	}
    } else if(lure_mode == LURE_MODE_READY) {
	lure_pos = line_pos[LINE_MAX_JOINT-1]; /* ぶらぶら */
	
	lure_ang.x = line_angle[LINE_MAX_JOINT-2].x + F_PI;

	if(pla->actor.speedF == 0.0f && lure_time == 0) {
	    add_calc2(&lure_ang.y,
		      line_angle[LINE_MAX_JOINT-2].y,
		      0.1f,
		      0.2f/*  + (float)BREG(22)*0.01f */);
	} else {
	    lure_ang.y = line_angle[LINE_MAX_JOINT-2].y;
	}
#if 0	
	if(lure_with_head) { /* 帽子ひっかかった ? */
	    add_calc2(&lure_ang.y,
		      line_angle[LINE_MAX_JOINT-2].y,
		      0.1f,
		      0.2f /* + (float)BREG(22)*0.01f */);
	} else {
	    lure_ang.y = line_angle[LINE_MAX_JOINT-2].y;
	}
#endif	
    }


    if(lure_type != LURE_TYPE_WORM) { /* ワームは半透明だから後で描く */
/*	worm_disp(game_play);*/
/*     } else { */
    
	Matrix_translate(lure_pos.x,
			 lure_pos.y,
			 lure_pos.z,
			 SET_MTX);
	
	Matrix_rotateY(	lure_ang.y + lure_vib_ya, MULT_MTX);
	Matrix_rotateX(	lure_ang.x /* + (float)KAZ(27)*0.1f*F_PI */, MULT_MTX);
	
	Matrix_scale(
	    /*  (float)SEX(28)*0.0001f + */  0.005f - 0.001f,
	    /*  (float)SEX(28)*0.0001f +  */ 0.005f - 0.001f,
	    /*  (float)SEX(29)*0.0001f +  */ 0.005f - 0.001f,
	    MULT_MTX);
	
	Matrix_translate(   0.0f,  0.0f,    lure_offset_z /* + (float)KAZ(26) */,     MULT_MTX);
	
	Matrix_rotateZ( F_PI*0.5f, MULT_MTX);
	Matrix_rotateY( F_PI*0.5f, MULT_MTX);
	
	_texture_z_light_fog_prim(game->graph);
	gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
/*    gSPDisplayList(NEXT_DISP, fishing_hook_model);*/
	gSPDisplayList(NEXT_DISP, lure_body_model);
	mae.x = -850.0f;
	mae.y = 0.0f;
	mae.z = 0.0f;
	Matrix_Position(&mae, &lure_head_pos); /*  */
	
	mae.x = 500.0f;
	mae.z = -250.0f /* + KAZ(45) */ - 50.0f;
	Matrix_Position(&mae, &hook_base_P[0]); /*  */
	
	/* 針 1 表示 */
	hook_draw(game_play,
		  &hook_base_P[0],
		  &hook_pos[0], 0);
	
	mae.x = 2100.0f;
	mae.z = 0.0f/*  + KAZ(46) */ - 50.0f ;
	Matrix_Position(&mae, &hook_base_P[1]); /*  */
	
	/* 針 2 表示 */
	hook_draw(game_play,
		  &hook_base_P[1],
		  &hook_pos[1], 1);
	
    } 
    
    /* 糸の表示 */
#if 0    
    gSPDisplayList(NEXT_DISP, fs_line_MODE);
    gDPSetPrimColor(NEXT_DISP, 0, 0,
		    255 /* + KAZ(22) */,
		    255 /* + KAZ(23) */,
		    255 /* + KAZ(24) */,
		    255
	);
#else    
    /* 表示 指定	*/
    SET_NOW_POLY_XLU_DISP(rcp_mode_set(NOW_POLY_XLU_DISP, 20));
    gDPSetCombineMode(NEXT_POLY_XLU_DISP, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0,
		    255 /*  + SEX(4) */ ,
		    255 /*  + SEX(5) */ ,
		    255 /*  + SEX(6) */ ,
		    55  /*  + SEX(7)  */);
#endif
    
    if(lure_mode == LURE_MODE_FISHON &&
       (lure_hook_up || lure_type != LURE_TYPE_WORM)) {  /* 引っ張ってる時は１本線 */
	float xa,ya,rg,x,y,z;
	
	x = lure_pos.x - line_base_pos.x;
	y = lure_pos.y - line_base_pos.y;
	z = lure_pos.z - line_base_pos.z;
	
	ya = fatan2(x,z);  /* 精度優先 */
	rg = sqrtf(x*x + z*z);
	xa = -fatan2(y,rg);

	rg = sqrtf(x*x + y*y + z*z)*0.001f;
	
	Matrix_translate(line_base_pos.x,
			 line_base_pos.y,
			 line_base_pos.z,
			 SET_MTX);
	Matrix_rotateY(	ya, MULT_MTX);
	Matrix_rotateX(	xa, MULT_MTX);
	
	Matrix_scale(
	    line_scale /* + (float)SEX(2)*0.0001f */, /* 太さ */
	    1.0f,
	    rg,
	    MULT_MTX);
	
	gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	gSPDisplayList(NEXT_POLY_XLU_DISP, fs_line_model);
    } else {
	for(i=line_cap_s;i<=LINE_MAX_JOINT-2;i++) {
	    if(i == LINE_MAX_JOINT-2-1/*  + KAZ(47) */ &&
	       lure_type == LURE_TYPE_PENCIL_BAIT &&
		lure_mode == LURE_MODE_ACTION) { /* アクション中は無理やりてっぺんに糸結ぶ */
		float xa,ya,rg,x,y,z;
		x = lure_head_pos.x - (pos+i)->x;
		y = lure_head_pos.y - (pos+i)->y;
		z = lure_head_pos.z - (pos+i)->z;
		
		ya = fatan2(x,z);  /* 精度優先 */
		rg = sqrtf(x*x + z*z);
		xa = -fatan2(y,rg);
		
		rg = sqrtf(x*x + y*y + z*z)*0.001f;
		
		Matrix_translate((pos+i)->x,
				 (pos+i)->y,
				 (pos+i)->z,
				 SET_MTX);
		Matrix_rotateY(	ya, MULT_MTX);
		Matrix_rotateX(	xa, MULT_MTX);
		
		Matrix_scale(
		    line_scale /* + (float)SEX(2)*0.0001f */, /* 太さ */
		    1.0f,
		    rg,
		    MULT_MTX);
		
		gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_line_model);
		break;
	    } else {
		Matrix_translate((pos+i)->x,
				 (pos+i)->y,
				 (pos+i)->z,
				 SET_MTX);
		Matrix_rotateY(	(ang+i)->y, MULT_MTX);
		Matrix_rotateX(	(ang+i)->x, MULT_MTX);
	    
		Matrix_scale(
		    line_scale /* + (float)SEX(2)*0.0001f */, /* 太さ */
		    1.0f,
		    0.01f * (0.5f /* + (float)SEX(2)*0.01f */)/*  * 200.0f/(float)LINE_MAX_JOINT*/,
		    MULT_MTX);
	    
		gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_POLY_XLU_DISP, fs_line_model);
	    }
	}
    }

    Matrix_pull();
    _texture_z_light_fog_prim_xlu(game->graph);
    CLOSE_DISP(game->graph);
}

/* 竿の表示 */

static float rod_scale[] = { /* 竿の太さ */
    1.0f - 0.075f*0.0f, /* グリップ */
    1.0f - 0.075f*0.0f,
    
    1.0f - 0.075f*0.0f,
    1.0f - 0.075f*0.5f,
    1.0f - 0.075f*1.0f,
    1.0f - 0.075f*1.5f,
    1.0f - 0.075f*2.0f,
    1.0f - 0.075f*2.5f,
    1.0f - 0.075f*3.0f,
    1.0f - 0.075f*3.5f,
    1.0f - 0.075f*4.0f,
    1.0f - 0.075f*4.5f,
    1.0f - 0.075f*5.0f,
    1.0f - 0.075f*5.5f,
    1.0f - 0.075f*6.0f,
    1.0f - 0.075f*6.5f,
    1.0f - 0.075f*7.0f,
    1.0f - 0.075f*7.5f,
    1.0f - 0.075f*8.0f,
    1.0f - 0.075f*8.5f,
    1.0f - 0.075f*9.0f,
    1.0f - 0.075f*9.5f,
/*    
    1.0f,
    0.95f,
    0.90f,
    0.85f,
    0.80f,
    0.75f,
    0.70f,
    0.65f,
    0.60f,
    0.55f,*/
};

static float rod_teper[] = { /* 竿のテーパー ファーストスロー */
    0.0f,
    0.0f,
    
    0.0f,
    0.0f,
    0.0f,
    0.06f,
    0.12f,
    0.18f,
    0.24f,
    0.30f,
    0.36f,
    0.42f,
    0.48f,
    0.54f,
    0.6f,
    0.6f,
    0.5142f,
    0.4285f,
    0.3428f,
    0.2571f,
    0.1714f,
    0.0857f,
/*    
    0.0f,
    0.04f,
    0.08f,
    0.12f,
    0.16f,
    0.20f,
    0.28f,
    0.35f,
    0.4f,
    0.45f,
    0.5f,
    0.55f,
    0.6f,
    0.55f,
    0.5f,
    0.45f,
    0.4f,
    0.3f,
    0.15f,
    0.1f,*/
};

static void rod_draw(Game_play *game_play)
{
    short i;
/*    s_xyz  rod_base_ang;
    xyz_t  rod_base_pos;*/
    float  rod_spd_y,rod_spd_x;
    float  rod_curvX3_S;
    static xyz_t  mae = {0.0f, 0.0f, 0.0f};
    Game *game = (Game *)game_play;
    Player_actor *pla = (Player_actor *)get_player_actor(game_play);
    pad_t		*pad = &game_play->g.pads[P_PAD];
    OPEN_DISP(game->graph);
#if 0
    if(NS1(48)) {
	NS1(48) = 0;
	rod_hooking_impact = 10 + NS1(49);
	line_tensyon = 10; /* ライン張ろう！ */
	Na_StartObjectSe_F((f32 *)&static_se_pos, NA_SE_IT_LASH);	/* <SE> */
    }
#endif    
    if(rod_hooking_impact) {
	rod_hooking_impact --;

	add_calc2(&rod_base_curvX,
		  35.0f,
		  1.0f,
		  100.0f/*  + NS1(56) */);
	
	add_calc2(&rod_curvX3,
		 -0.8f/*  + (float)NS1(53)*0.01f */,
		  1.0f,
		  0.4f /* + (float)NS1(54)*0.01f */);
	
	adds(&pla->actor.shape.angle.sx,
	    /*  NS1(50)  */- 4000,
	     2,
	     15000/*  + NS1(51) */
	     );
    } else {
	short ss = 0;
	
	if(lure_mode == LURE_MODE_FISHON && lure_hook_up) { /* 魚かかってる？ */
	    ss = (short)(sin_s(lure_count * 0x100 * (100 /* + KAZ(85) */)) * (/* KAZ(86)+ */1500));
	} else {
	    add_calc0(&rod_base_curvX,
		      0.1f,
		      10.0f);
	    
	    add_calc0(&rod_curvX3,
		      1.0f,
		      0.05f/*  + (float)NS1(55)*0.01f */);
	}

	adds(&pla->actor.shape.angle.sx,
	     ss,
	     5 /* + KAZ(87) */,
	     1000 /* + KAZ(88) */
	     );
    }

    if(lure_mode == LURE_MODE_ACTION ||
       lure_mode == LURE_MODE_FISHON) { /* アクション or ヒット中？ */
	if(Pad_stick_x() == 0 &&
	   old_stick_x != 0) {  /* スティック離したときは慣性クリアー */
	    rod_curvY_spd = 0.0f;
	}
	if(Pad_stick_y() == 0 &&
	   old_stick_y != 0) {
	    rod_curvX_spd = 0.0f;
	}

#if 0	
	if(Pad_stick_x() < 0 &&
	   old_stick_x >  0) { /* 急激に振ったら音出す */
	    Na_StartObjectSe((f32 *)&static_se_pos, NA_SE_IT_SLING_SHOT);	/* <SE> */
	}
	if(Pad_stick_x() > 0 &&
	   old_stick_x < 0) {
	    Na_StartObjectSe((f32 *)&static_se_pos, NA_SE_IT_SLING_SHOT);	/* <SE> */
	}
#endif
	
/*	
	old_stick_x = Pad_stick_x();
	old_stick_y = Pad_stick_y();
	*/
	/* スティック位置からプレイヤーアニメへ補間 */
	rod_spd_y = pla->fishing_powerY;
	add_calc(&pla->fishing_powerY,
		 (float)Pad_stick_y() * (0.02f/*  + NS1(23)*0.01f */),
		 0.3f /*+  (float)NS1(24)*0.01f */,
		 5.0f /* + (float)NS1(25)*0.01f */,
		 0.0f);
	rod_spd_y = (pla->fishing_powerY - rod_spd_y);
	
	rod_spd_x = pla->fishing_powerX;
	add_calc(&pla->fishing_powerX,
		 (float)Pad_stick_x() * (0.02f /* + NS1(23)*0.01f */),
		 0.3f /* + (float)NS1(24)*0.01f */,
		 5.0f/*  + (float)NS1(25)*0.01f */,
		 0.0f);
	rod_spd_x = (pla->fishing_powerX - rod_spd_x);

	if(pla->fishing_powerX > 1.0f)
	    pla->fishing_powerX = 1.0f;
	if(pla->fishing_powerY > 1.0f)
	    pla->fishing_powerY = 1.0f;
	if(pla->fishing_powerX < -1.0f)
	    pla->fishing_powerX = -1.0f;
	if(pla->fishing_powerY < -1.0f)
	    pla->fishing_powerY = -1.0f;
	
	/* 慣性による竿の曲がり */
	add_calc2(&rod_curvY,
		  (rod_spd_x) * (float)(/* NS1(26)+ */70) * -0.01f,
		  1.0f /* + (float)NS1(27)*0.01f */,
		  rod_curvY_spd);
	
	add_calc2(&rod_curvY_spd,
		  1.0f /* + (float)NS1(28)*0.01f */,
		  1.0f,
		  0.1f /*+ (float)NS1(38)*0.01f*/);
	
	add_calc2(&rod_curvX,
		  (rod_spd_y) * (float)(/* NS1(26)+ */70) * 0.01f,
		  1.0f /* + (float)NS1(27)*0.01f */,
		  rod_curvX_spd);
	
	add_calc2(&rod_curvX_spd,
		  1.0f /* + (float)NS1(28)*0.01f */,
		  1.0f,
		  0.1f/* + (float)NS1(38)*0.01f*/);
	
	add_calc0(&rod_curvX2,
		  1.0f,
		  0.05f);
    } else {
	add_calc0(&pla->fishing_powerY,
		  1.0f,
		  0.1f);
	add_calc0(&pla->fishing_powerX,
		  1.0f,
		  0.1f);

	add_calc2(&rod_curvX,
		  -0.03f + sin_s(lure_count * 3000) * 0.025f,
		  1.0f,
		  0.05f);
	
	add_calc0(&rod_curvY,
		  1.0f,
		  0.05f);
	
	if(lure_cast_wait > 18/* +NS1(3)  */&&
	   lure_cast_wait < 25/* +NS1(4) */) {
	    add_calc2(&rod_curvX2,
		      0.8f/*  + (float)NS1(5)*0.01f */,
		      1.0f,
		      0.2f/*  + (float)NS1(6)*0.01f */);
	} else {
	    add_calc2(&rod_curvX2,
		      0.0f,
		      1.0f,
		      0.4f /* + (float)NS1(7)*0.01f */);
	}
    }
    _texture_z_light_fog_prim(game->graph);
    gSPDisplayList(NEXT_DISP, rod_MODE);
    
    gDPSetPrimColor(NEXT_DISP, 0, 0, 
		    255 /* + NS1(70) */,   /* FO-60カラー */
		    255 /* + NS1(71) */-100,
		    255 /* + NS1(72) */-255,
		    255
	);

    /* 持つ位置 */
    Matrix_mult(&pla->sword_matrix,  SET_MTX);
    if(AGE != 1) { /* 17歳 */
	Matrix_translate(/* SEX(51) */0.0f, 400.0f /* + SEX(52) */, 0.0f/* SEX(53) */,  MULT_MTX);
    } else {  /* 5歳 */
	Matrix_translate(/* SEX(51) */0.0f, 400.0f /* + SEX(52) */-170.0f, 0.0f/* SEX(53) */,  MULT_MTX);
    }

    /* 持つ角度 */
    if(lure_mode == LURE_MODE_CATCH) {
	Matrix_rotateY((float)( 50-9 + 15)*0.01f*F_PI, MULT_MTX);
    } else {
	Matrix_rotateY((float)( 50-9)*0.01f*F_PI, MULT_MTX);
    }
    Matrix_rotateX((float)(/*  SEX(55) */ -20)*0.01f*F_PI, MULT_MTX);
    
    Matrix_rotateZ(0.4712389f + pla->fishing_powerX * (0.5f/* +(float)NS1(59)*0.1f */), MULT_MTX);
    Matrix_rotateX((float)(/* NS1(18) + */ rod_base_curvX + 20)*0.01f*F_PI, MULT_MTX);   /* 基本の竿の上下角度 */
    Matrix_scale((float)(/* NS1(16)+ */700)*0.001f,
		 (float)(/* NS1(16)+ */700)*0.001f,
		 (float)(/* NS1(17)+ */700)*0.001f,
		 MULT_MTX);

    rod_curvX3_S = rod_curvX +  rod_curvX2 + 
	rod_curvX3 *
	(/* (float)NS1(60)*0.01f + */ 0.5f + (pla->fishing_powerY - 1.0f)*(-0.25f/* +(float)NS1(61)*0.01f */));
    
    Matrix_translate(0.0f,
		     0.0f,
		     /* KAZ(12)  */- 1300.0f,
		     MULT_MTX);
    
    for(i=0;i<20+2;i++) {
	Matrix_rotateY( rod_curvY * rod_teper[i] * (0.5f/* +(float)NS1(69)*0.1f */), /* 竿の曲がり */
			MULT_MTX);
	Matrix_rotateX( (/* rod_curvX + rod_curvX2 + */ rod_curvX3_S) * rod_teper[i] *  (0.5f/* +(float)NS1(69)*0.1f */),
			MULT_MTX);
	
	Matrix_push();
	
	Matrix_scale(rod_scale[i],
		     rod_scale[i],
		     0.02f + 1.0f*0.5f,
		     MULT_MTX);
	gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	if(i < 5 /* + KAZ(91) */ /* + SEX(45) */) { /* 黒い */
	    gDPLoadMultiBlock(NEXT_DISP, hook_grip_0_txt, 0, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 8, 0,
			      G_TX_WRAP, G_TX_WRAP, 4, 3, 0, 0);
	} else if(i < 8 /* + SEX(46) */ ||
		  (i & 0x01) == 0) { /* 単色 */
	    gDPLoadMultiBlock(NEXT_DISP, hook_grip_1_txt, 0, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 8, 0,
			      G_TX_WRAP, G_TX_WRAP, 4, 3, 0, 0);
	} else {  /* スレッド */
	    gDPLoadMultiBlock(NEXT_DISP, hook_grip_2_txt, 0, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 8, 0,
			      G_TX_WRAP, G_TX_WRAP, 4, 3, 0, 0);
	}
	gSPDisplayList(NEXT_DISP, rod_model);
	
	Matrix_pull();
	
	Matrix_translate(0.0f,
			 0.0f,
			 1000.0f*0.5f,
			 MULT_MTX);
	if(i == 19+2) { /* 先位置 */
/* 	    line_base_pos_OLD = line_base_pos; */
	    Matrix_Position(&mae, &line_base_pos); /*  */
	}
    }
/*
PRINTF("   fishing_powerY %f\n", pla->fishing_powerY);
PRINTF("   fishing_powerX %f\n", pla->fishing_powerX);
*/
    CLOSE_DISP(game->graph);
}

static xyz_t lure_se_pos = {0.0f, 0.0f, 0.0f};

static void lure_move(Fishing_actor *this, Game_play *game_play)
{
    float gr;
    float old_y;
    short         i,yaad;
    float         x,y,z,r,rg,cky;
    Player_actor *pl = (Player_actor *)get_player_actor(game_play);
    xyz_t         zz = {0.0f, 0.0f, 0.0f},pos,vec,mae;
    pad_t		*pad = &game_play->g.pads[P_PAD];

    lure_count ++;

    if(lure_time) {
	lure_time --;
    }
    if(lure_cast_time) {
	lure_cast_time --;
    }
    if(lure_cast_wait) {
	lure_cast_wait --;
    }
    if(lure_hook_time) {
	lure_hook_time --;
    }
    if(lure_dog_wait_time)
	lure_dog_wait_time --;

    if(line_tensyon)
	line_tensyon --;

    if(vib_time)
	vib_time --;

    if(lure_in_water) {
	lure_in_water --;
    }
    
    
/*    line_base_pos = pl->parts_pos[12+KAZ(58)];*/
/*    line_base_pos.y += 50.0f;*/
    
    if(fishing_game_mode == 1) {  /* 初期化？ */
	fishing_game_mode = 2;
	
/* 	fishing_time = 0; */
	fish_catch_count = 0;
	seken_mes_ct = 0;

	lure_type = LURE_TYPE_PENCIL_BAIT;

	/* ワ─ムが落ちてる場所セット */
	if((AGE == 1 && /* 子供でハートもらった後？ */
	    (HI_SCORE(HS_FISH) & SAVE_HEART_GET)) ||
	   (AGE != 1 && /* 大人でウロコもらった後？ */ 
	    (HI_SCORE(HS_FISH) & SAVE_UROKO_GET))
	    ) { 
	    worm_set_P = 1 + (u8)rnd_f(3.999f); /* 1 ~ 3 */
	}
	
/*	LINE_MAX_JOINT = 200;*/

	line_G = 20.0f/*  + KAZ(81)  */+ 500.0f;
	line_cap = (float)LINE_MAX_JOINT - 5.0f /* - KAZ(80) */;
	lure_mode = 
	    lure_type =
	    lure_count =
	    lure_time = 
	    lure_cast_time = 
	    lure_cast_wait =
	    lure_action =
	    lure_in_water = 
	    lure_dog_wait_time = 0;

	lure_vib_ya =
	    lure_hosei_s = 
	    lure_offset_z = 0.0f;
	
	lure_act_vec = zz;
	
	for(i=0;i<LINE_MAX_JOINT;i++) {
	    line_pos[i] = zz;
	    line_angle[i] = zz;
	    line_spd[i] = zz;
	}
#if 0	
	lure_bgm_time = 10;
	Na_StopBgm(1);  /*  SE BGM */
#endif	
/*	NS1(0) = 1;*/
    }

    /*
     * SE用カメラポジションセット
     */
    Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
			     (Skin_Vector *)&lure_pos,
			     (Skin_Vector *)&lure_se_pos,
			     &float_dammy);


    if(lure_mode == LURE_MODE_READY) { /* ぶらさがってる時の中心補正 */
	add_calc2(&lure_offset_z,
		  -800.0f /* + KAZ(24) */,
		  1.0f,
		  20.0f
	    );
    } else {
	add_calc2(&lure_offset_z,
		  300.0f /* + KAZ(25) */,
		  1.0f,
		  20.0f
	    );
    }
    
    
/* PRINTF("   lure_mode %d\n", lure_mode); */

    switch(lure_mode) {
/*-------------------------------------------------------------------*/	
    case LURE_MODE_READY:
	worm_eat = 0;
	
#if FS_DEBUG
	if(KAZ(14)) {
	    KAZ(14) = 0;
	    lure_type = 2 - lure_type;
	    if(lure_type) {
		seken_mes_ct = 0;
	    }
	}
#endif	
	add_calc2(&line_cap,
		  (float)LINE_MAX_JOINT - 5.0f /* - KAZ(80) */,
		  1.0f,
		  1.0f);
#if 0	/* ずれないように表示でやる */
	lure_pos = line_pos[LINE_MAX_JOINT-1]; /* ぶらぶら */

	lure_ang.x = line_angle[LINE_MAX_JOINT-2].x + F_PI;
	
	if(lure_with_head) { /* 帽子ひっかかった ? */
	    add_calc2(&lure_ang.y,
		      line_angle[LINE_MAX_JOINT-2].y,
		      0.1f,
		      0.2f /* + (float)BREG(22)*0.01f */);
	} else {
	    lure_ang.y = line_angle[LINE_MAX_JOINT-2].y;
	}
#endif
	if(bitcheck(pl->action, P_ACTION_SWIM)) { /* 水はまったらキャスト出来ない */
	    lure_cast_wait = 0;
	    pl->fishing_mode = 0;
	}
	if(lure_cast_wait == 0) {
	    if(lure_time == 0 &&
	       pl->fishing_mode == FISHING_MODE_THROW) { /* キャスト？ */
/*	   Pad_on_trigger(CAST_BUTTON)) {*/
		lure_cast_wait = 37/* +NS1(2) */; /* アニメのタイミングに合わせる時間 */
		message_close(game_play);   /* メッセージウィンドウ閉じ原、る？  */
	    }
	} else {
	    lure_ang.x = line_angle[LINE_MAX_JOINT-2].x + F_PI;
	    lure_ang.y = line_angle[LINE_MAX_JOINT-2].y;
	    
	    if(lure_cast_wait == 18 /* + NS1(8) */) {
		lure_mode = LURE_MODE_CAST;
		lure_pos = line_base_pos;
/* 		lure_pos.y += NS1(9); */
		
		Matrix_rotateY( (float)pl->actor.shape.angle.sy/32768.0f*F_PI, SET_MTX);
		mae.x = 0.0f;
		mae.y = 0.0f;
		mae.z = 25.0f /* + SEX(11) */;
		Matrix_Position(&mae, &lure_spd); /*  */
		
		lure_spd.y = 15.0f /*+ SEX(12)*/;
		lure_acc.x =
		    lure_acc.z = 0.0f;
		lure_acc.y = -1.0f /*+ (float)SEX(13)/10.0f*/;
		
		line_G = 0.0f;
		lure_cast_time = 5/* + KAZ(3)*/;
/*		lure_ys2 = 0.0f;*/
		
		hit_power = 0.5f;
		
		lure_search_p = (u8)rnd_f(1.9f);

		fish_mouse_p.y = 500.0f;
		
		Na_StartObjectSe_F((f32 *)&lure_se_pos, NA_SE_IT_SWORD_SWING_HARD);	/* <SE> */
	    }
	}
	break;
/*-------------------------------------------------------------------*/	
    case LURE_MODE_CAST: /* キャスト中 */
	old_y = lure_pos.y;
	
	lure_pos.x += lure_spd.x;
	lure_pos.y += lure_spd.y;
	lure_pos.z += lure_spd.z;
	
	lure_spd.x += lure_acc.x;
	lure_spd.y += lure_acc.y;
	lure_spd.z += lure_acc.z;
	
	if(Pad_push_also(REEL_BUTTON) || lure_with_head) { 	/* 失速？ */	
	    lure_spd.x *= 0.9f; 
	    lure_spd.z *= 0.9f;
	    if(lure_with_head == 0) { /* ブレーキ音 */
		Na_StartSystemSe_F(NA_SE_IT_FISHING_REEL_HIGH);	/* <SE> */
	    }
	}
	
	x = lure_pos.x - line_base_pos.x;
	y = lure_pos.y - line_base_pos.y;
	z = lure_pos.z - line_base_pos.z;
	
	if(lure_cast_time) {
	    lure_ang.x = line_angle[LINE_MAX_JOINT-2].x + F_PI; /* ぶらさがってる */
	    lure_ang.y = line_angle[LINE_MAX_JOINT-2].y;
	} else {
	    lure_ang.x = 0.0f;
	    lure_ang.y = atanf_table(z,x) + F_PI;
	}
	
	r = sqrtf(x*x + y*y + z*z) * (1.0f /* + (float)SEX(17)*0.1f */);
	
	if(r > 1000.0f) 
	    r = 1000.0f;
	
	line_cap = (float)LINE_MAX_JOINT - (r * (float)LINE_MAX_JOINT*0.001f); /* 飛んだ距離からラインの残量を求める */
	
	if( (rg = lure_pos.x*lure_pos.x + lure_pos.z*lure_pos.z) > 920.0f*920.0f) { /* 水範囲外？ */
	    if(
#if FS_DEBUG
		KAZ(56) ||
#endif
		lure_pos.y > 160.0f ||
		lure_pos.x < 80.0f ||
		lure_pos.x > 180.0f  ||
		lure_pos.z > 1350.0f ||
		lure_pos.z < 1100.0f ||
		lure_pos.y < 45.0f) { /* おやじの台近辺以外？ */
		xyz_t save_pos;
#if 0		
		float hankei,x,z;
		short ys;
		u8    check_f = 0;

		x =  -  pl->actor.world.position.x;
		z =  -  pl->actor.world.position.z;
	
		ys = atans_table(z,x);
		
		if(ABS((short)(ys - pl->actor.shape.angle.sy)) < 0x3000 /* + KAZ(80)*0x800 */) {
		    check_f = 1; /* いい方向！ */
		}
		if(lure_cast_time && check_f == 0) { /* 投げた瞬間？ */
		    hankei = 100.0f
#if FS_DEBUG
			+ KAZ(57)
#endif			
			;
		} else {
		    hankei = 30.0f;
		}
#endif		
		save_pos = this->actor.world.position;
		this->actor.old_position = this->actor.world.position = lure_pos;
		
		Actor_BGcheck2(game_play,
			       (Actor *)this,
			       15.0f,			/* 壁チェック高さ */
			       30.0f,/* 壁チェック半径 */
#if 0			       
			       hankei /* 30.0f *//* +SEX(94) */,			/* 壁チェック半径 */
#endif			       
			       30.0f,			/* 天井チェック高さ */
			       BGCHECK_ROOF | BGCHECK_WALL | BGCHECK_RIPPLE_NOSET);	/* チェック情報 */
	    
		this->actor.world.position = save_pos;
		
		if(bitcheck(this->actor.environment_info, ENVIRONMENT_INFO_ROOF)) { 	/* 天井衝突？ */
		    lure_spd.y = -0.5f;
		}
		if(bitcheck(this->actor.environment_info, ENVIRONMENT_INFO_WALL)) { 	/* 壁衝突？ */
 		    if(lure_spd.y > 0.0f) 
 			lure_spd.y = 0.0f; 
		    lure_spd.x = /* 0.0f;  */
			lure_spd.z = 0.0f; 
		}
	    } else {
		if(oyaji_floor_check(&lure_pos)) {
		    lure_mode = LURE_MODE_ACTION;
		    lure_hosei_s = 00.0f;
		}
	    }
#if 0	    
	    if(T_BGCheck_SimpleCheck(&game_play->BGCheck, &lure_pos, 30.0f) ) { /* シンプルＢＧチェック */
		lure_spd.x = 
		    lure_spd.z = 0.0f;
		if(lure_spd.y > 0.0f)
		    lure_spd.y = 0.0f;
	    }
#endif		
	    gr = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
		+ (sqrtf(rg) - 920.0f) * 0.11f;

	    if(lure_pos.y <= gr) { /* 地面に落ちた？ */
#if 0		
		add_calc2(&line_G,
			  2.0f /* + (float)SEX(23)*0.1f */,
			  1.0f,
			  0.1f /* + (float)SEX(24)*0.01f */
		    );
#endif		
		lure_pos.y = gr;
		lure_spd.x = 
		lure_spd.y = 
		lure_spd.z = 0.0f;
		lure_mode = LURE_MODE_ACTION;
		lure_hosei_s = 00.0f;
/* 		lure_reel_ready = 15+KAZ(9); */
#if 0		
		lure_spd.x *= (0.05f /* + (float)SEX(20)*0.01f */); 
		lure_spd.z *= (0.05f /* + (float)SEX(20)*0.01f */);
		lure_spd.y *= -(0.1f/* +(float)SEX(51)*0.01f */);

		if(fabsf(lure_spd.y) <= 0.2f/* +(float)SEX(52)*0.1f */) { /* キャスト終り？ */
		    lure_mode = LURE_MODE_ACTION;
		    lure_hosei_s = 00.0f;
		}
#endif		
	    } else {
/* 		PRINTF("??????????????????????????\n"); */
		add_calc2(&line_G,
			  0.0f /* + (float)SEX(4)*0.1f */,
			  1.0f,
			  0.05f
		    );
		Na_StartObjectSe_F((f32 *)&lure_se_pos, NA_SE_EN_FANTOM_FLOAT);	/* <SE> */
	    }
	} else {   /* 水中？ */
	    gr = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
	    
	    if(lure_pos.y <= gr) {
		lure_mode = LURE_MODE_ACTION_READY;
		lure_hosei_s = 0.0f;
/*		lure_pos.y = gr;*/
		lure_spd.x = 
/*		    lure_spd.y = */
		    lure_spd.z = 0.0f;
		
		if(lure_type == LURE_TYPE_WORM) {
		    lure_reel_ready = 0;
		} else {
		    lure_reel_ready = 10/* +KAZ(9) */;
		}
#if 0		
		add_calc2(&line_G,
			  2.0f /* + (float)SEX(23)*0.1f */,
			  1.0f,
			  0.1f /* + (float)SEX(24)*0.01f */
		    );
		
		add_calc2(&lure_pos.y,
			  gr,
			  1.0f,
			  1.0f /*+ (float)SEX(21)/10.0f*/
		    );
		add_calc2(&lure_spd.y,
			  0.0f,
			  1.0f,
			  1.0f /* + (float)SEX(22)*0.1f */
		    );
		
		lure_spd.x *= (0.3f /* + (float)SEX(20)*0.01f */); 
		lure_spd.z *= (0.3f /* + (float)SEX(20)*0.01f */); 
		
/*		if(Pad_on_trigger(CAST_BUTTON)) {*/
		if(lure_type == LURE_TYPE_WORM ||
		  /*  KAZ(53) || */
		   (lure_pos.y == gr &&
		    lure_spd.y == 0.0f)) { /* キャスト終り？ */
		    lure_mode = LURE_MODE_ACTION;
		    lure_hosei_s = 0.0f;
/*		    lure_with_head = 0;*/
		}
/*		
		lure_pos.y = gr;
		lure_spd.x = 0.0f;
		lure_spd.y = 0.0f;
		lure_spd.z = 0.0f;
		lure_acc.y = 0.0f;
		lure_mode = 2;
		*/
#endif	    
		if(lure_pos.y <= gr && old_y > gr) { /* しぶき？ */
		    if( gr == (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
			lure_in_water = 10; /* サカナをビビらす情報 */
			
			Na_StartObjectSe_F((f32 *)&lure_se_pos,
					 NA_SE_EV_BOMB_DROP_WATER);	/* <SE> */
			
			lure_acc.y = 0.0f;
			lure_spd.y *= (0.2f /* + (float)SEX(25)*0.01f */);
			
			for(i=0;i<50/* +GREG(1) */;i++) {
			    float ad,ra;
			    
			    ad = 0.5f + rnd_f(1.5f);
			    
			    ra = rnd_f(6.28f);
			    
			    vec.x = sinf( ra ) * ad;
			    vec.z = cosf( ra ) * ad;
			    vec.y = 3.0f + rnd_f(3.0f);
			    
			    pos = lure_pos;
			    pos.x += vec.x * 3.0f;
			    pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
			    pos.z += vec.z * 3.0f;
			    
			    fs_mizu_ct(
				NULL,
				(Fishing_Eff *)game_play->special_effect,
				&pos,
				&vec,
				(25.0f/* +GREG(2) */)*0.001f + rnd_f(0.02f)
				);
			}
			
			pos = lure_pos;
			pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
			
			fs_hamon_ct(
			    NULL,
			    (Fishing_Eff *)game_play->special_effect,
			    &pos,
			    100 ,
			    800 ,
			    150,
			    FISHING_EFF_SIZE-10
			    );
		    }
		}
	    } else {
		add_calc0(&line_G,
			  1.0f,
			  0.05f
		    );
		Na_StartObjectSe_F((f32 *)&lure_se_pos, NA_SE_EN_FANTOM_FLOAT);	/* <SE> */
	    }
	}
	
	line_pos[LINE_MAX_JOINT-1].x = lure_pos.x;
	line_pos[LINE_MAX_JOINT-1].y = lure_pos.y;
	line_pos[LINE_MAX_JOINT-1].z = lure_pos.z;

	lure_dog_walk_way = 1.0f;
	
	lure_dog_swing_X = 0.5f;
	break;
/*-------------------------------------------------------------------*/	
    case LURE_MODE_ACTION_READY:/* 巻き取り準備 ？ */
	if(lure_pos.y <= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) { /* 水中 */
	    lure_pos.y += lure_spd.y;
	    add_calc0(&lure_spd.y,
		      1.0f,
		      1.0f /* + (float)SEX(23)*0.1f */);
#if 01
	    if(lure_type != LURE_TYPE_WORM) {
		add_calc2(&lure_pos.y,
			  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy,
			  0.5f,
			  1.0f /* + (float)SEX(21)/10.0f */
		    );
	    }
#endif	    
	}
	add_calc2(&line_G,
		  2.0f /* + (float)SEX(23)*0.1f */,
		  1.0f,
		  0.1f /* + (float)SEX(24)*0.01f */
	    );
	if(lure_reel_ready == 0) {
	    lure_mode = LURE_MODE_ACTION;
	} else {
	    lure_reel_ready --;
	}
	break;
	
    case LURE_MODE_ACTION:/* 巻き取り ？ */
	worm_eat = 0;
	
	if(lure_with_head &&
	   (lure_pos.x*lure_pos.x + lure_pos.z*lure_pos.z) < 500.0f*500.0f) { /* ボウシつきでわりと池の真ん中に落ちた？ */
	    lure_with_head_off = 1; /* ボウシはずそう */
	}
	pl->fishing_mode = FISHING_MODE_FIGHT;
	
	if(lure_act_speed < 3.0f) {
	    rg = sin_s(lure_count * (0x2000-4000)) * lure_dog_swing_X;
	
	    add_calc2(&lure_ang.x,
		      -F_PI/6.0f + rg,  /* 浮き角度 */
		      0.3f /* + (float)GREG(65)*0.01f */,
		      lure_ang_x_ad
/*		      0.5f + (float)GREG(66)*0.01f*/
		);
	    add_calc2(&lure_ang_x_ad,
		      0.5f/*  + (float)GREG(66)*0.01f */,
		      1.0f,
		      0.02f);

	    add_calc0(&lure_dog_swing_X,
		      1.0f,
		      0.02f /* + (float)GREG(67)*0.001f */);
	} else {
	    lure_ang_x_ad = 0.0f;
	}
	
	yaad = 0x4000;

	gr = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
	
	if( (rg = lure_pos.x*lure_pos.x + lure_pos.z*lure_pos.z) < 920.0f*920.0f) { /* 水範囲？ */
	    if(lure_pos.y <= gr + 4.0f) { /* 水面下？ */
		pad_t		*pad = &game_play->g.pads[P_PAD];
		float           stick_power = 0.0f;

		if(lure_dog_wait_time == 0) {
		    if(fabsf((float)Pad_stick_x()) > 30.0f /* + (float)NS1(36) */) {
			stick_power = fabsf((float)(Pad_stick_x() - old_stick_x)*(1.0f/60.0f));
		    } else if(fabsf((float)Pad_stick_y()) > 30.0f /* + (float)NS1(36) */) {
			stick_power = fabsf((float)(Pad_stick_y() - old_stick_y)*(1.0f/60.0f));
		    }
		}

		if(stick_power > 1.0f)
		    stick_power = 1.0f;
		
		/* サービスでボタンでもアクション */
		if(Pad_on_trigger(CAST_BUTTON)) {
		    stick_power = 0.5f;
		}

		if(lure_with_head) {
		    if(stick_power > 0.3f)
			stick_power = 0.3f;
		}
		
		/* 首振り ! */
		if(stick_power > (0.2f /* + (float)NS1(32)*0.01f */) &&
		   lure_act_speed < (4.0f /* + (float)NS1(37)*0.1f */)
		    ) {
		    lure_dog_wait_time = 5 /* + NS1(38) */;
		    if(stick_power > 0.8f) { /* 大スライド？ */
			lure_action = 2; /* さかなに動いたことを教える */
		    } else {
			lure_action = 1; /* さかなに動いたことを教える */
		    }
		    mae.x = pl->actor.world.position.x - lure_pos.x;
		    mae.z = pl->actor.world.position.z - lure_pos.z;
		    mae.y = atanf_table(mae.z,mae.x);

		    lure_act_ang_Y = mae.y +  stick_power * (1.0f /* + (float)NS1(33)*0.01f */) * lure_dog_walk_way;
		    lure_dog_walk_way *= -1.0f;
		    lure_act_speed = fabsf(stick_power) * (6.0f /* + (float)NS1(34)*0.01f */);
		    lure_ang.x = 0.0f;
		    lure_dog_swing_X = 0.5f;
		    line_cap += fabsf(stick_power) * (6.0f + 1.5f
#if FS_DEBUG						      
						      + (float)KAZ(25)*0.1f
#endif						      
			);
#if 1		    
		    Na_StartRodSe((f32 *)&lure_se_pos, NA_SE_EV_LURE_MOVE, stick_power * 1.999f);	/* <SE> */
#else		    
		    Na_StartObjectSe_F((f32 *)&lure_se_pos, NA_SE_PL_WALK_SAND);	/* <SE> */
#endif		    
		    if(lure_type == LURE_TYPE_WORM) {
			lure_act_vec.y = (5.0f  /* + (float)KAZ(67)*0.01f */) * stick_power;
			line_pos[LINE_MAX_JOINT-1].y += lure_act_vec.y;
			lure_pos.y += lure_act_vec.y;
		    }
		} else if (Pad_push_also(REEL_BUTTON)) { 	/* 棒引き？ */
		    lure_act_ang_Y = line_angle[LINE_MAX_JOINT-2].y + F_PI; /* ルアー真っ直ぐ */
		    lure_ang.x = 0.0f;
		    lure_dog_swing_X = 0.5f;
		    
		    yaad = 0x500;
		    if(lure_type == LURE_TYPE_WORM) {
			lure_act_vec.y = 0.2f  /* + (float)KAZ(68)*0.01f */ ;
			line_pos[LINE_MAX_JOINT-1].y += lure_act_vec.y;
			lure_pos.y += lure_act_vec.y;
		    }
		}
	    } else { /* 空中？ */
		if(line_cap > (float)LINE_MAX_JOINT-50.0f/* +SEX(72) */) { /* ある程度巻いた？ */
		    lure_ang.x = line_angle[LINE_MAX_JOINT-2].x + F_PI; /* ぶらさがってる */
		    lure_act_ang_Y = line_angle[LINE_MAX_JOINT-2].y + F_PI;
		    
		    line_cap += 2.0f; /* 自動で巻く */
			
/* 		    lure_time = NEXT_CAST_WAIT; */
		}
	    }
	} else { /* 地上チェック */
	    gr = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
		+ (sqrtf(rg) - 920.0f) * 0.11f;
	    
	    if(lure_pos.y <= gr) {
		lure_pos.y = gr;
		
		lure_act_ang_Y = line_angle[LINE_MAX_JOINT-2].y + F_PI; /* ルアー真っ直ぐ */
		lure_ang.x = 0.0f;
		
		yaad = 0x500;
		
		if(Pad_on_trigger(CAST_BUTTON)) {  /* 地上で首振りしても無駄 ! */
		    line_cap += 6.0f /* + KAZ(36) */;  /* ラインのたるみを取る */
		    Na_StartObjectSe_F((f32 *)&lure_se_pos, NA_SE_PL_WALK_SAND);	/* <SE> */
		}
	    } else { /* 空中？ */
		if(line_cap > (float)LINE_MAX_JOINT-50.0f/* +SEX(72) */) { /* ある程度巻いた？ */
		    lure_ang.x = line_angle[LINE_MAX_JOINT-2].x + F_PI; /* ぶらさがってる */
		    lure_act_ang_Y = line_angle[LINE_MAX_JOINT-2].y + F_PI;
		    
		    line_cap += 2.0f; /* 自動で巻く */
			
/* 		    lure_time = NEXT_CAST_WAIT; */
		}
	    }
	}
	add_calc0(&lure_act_speed,
		  1.0f,
		  0.3f /* + (float)KAZ(35)*0.1f */
	    );
	
	adds(&lure_ang_Y_s,
	     (short)(lure_act_ang_Y*32768.0f/F_PI),
	     3,
	     yaad
	     );
	
	lure_ang.y = (float)lure_ang_Y_s/32768.0f * F_PI;
	
	mae.x =  0.0f;
	mae.y =  0.0f;
	mae.z = lure_act_speed;
	Matrix_rotateY(	lure_ang.y, SET_MTX);
	
	if(lure_type == LURE_TYPE_WORM) {
	    xyz_t ato;
	    Matrix_Position(&mae, &ato); /* lure_act_vec.y を書かない為 */
	    lure_act_vec.x = ato.x;
	    lure_act_vec.z = ato.z;
	    cky = 10.0f; /* すぐに落す為 */
	} else {
	    Matrix_Position(&mae, &lure_act_vec); /*  */
	    cky = 0.0f;
	}
	lure_vib_ya = 0.0f;
	
	if(lure_type == LURE_TYPE_SHAD && Pad_push_also(REEL_BUTTON)) {
/*	    
	    if(Pad_on_trigger(REEL_BUTTON)) {
		line_tensyon = 2;
	    }*/
	    lure_act_vec.y = -2.0f /* + (float)KAZ(13)*0.1f */;
	    
	    if(lure_count & (0x01/* +KAZ(12) */)) {
		lure_vib_ya = (float)(/* KAZ(11)+ */50)*0.01f;
	    } else {
		lure_vib_ya = -(float)(/* KAZ(11)+ */50)*0.01f;
	    }
/*	    
	    lure_vib_ya = sin_s(lure_count * (0x3000 + KAZ(12)*0x100)) * (float)KAZ(11)*0.1f;
	    */
	} else if(line_pos[LINE_MAX_JOINT-1].y <
		  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + cky) {
	    if(lure_type == LURE_TYPE_WORM) { /* しずむから地面判定 */
		xyz_t save_pos;
		
		save_pos = this->actor.world.position;
		this->actor.old_position = this->actor.world.position = lure_pos;
		
		Actor_BGcheck2(game_play,
			       (Actor *)this,
			       15.0f,			/* 壁チェック高さ */
			       30.0f/* +SEX(94) */,			/* 壁チェック半径 */
			       30.0f,			/* 天井チェック高さ */
			       BGCHECK_GROUND | BGCHECK_RIPPLE_NOSET);	/* チェック情報 */
		
		this->actor.world.position = save_pos;
	
		lure_act_vec.y += -0.5f /* + (float)KAZ(65)*0.01f */;
		if(lure_act_vec.y < -1.0f /* + (float)KAZ(66)*0.1f */)
		    lure_act_vec.y = -1.0f /* + (float)KAZ(66)*0.1f */;
		if(lure_pos.y <  this->actor.ground_y + 5.0f /* + KAZ(64) */) {
		    lure_pos.y = this->actor.ground_y + 5.0f /* + KAZ(64) */;
		    line_pos[LINE_MAX_JOINT-1].y = lure_pos.y;
#if 0
		    if(lure_act_vec.y < -0.8f) {
			xyz_t pos;
			
			pos.x = lure_pos.x;
			pos.y = lure_pos.y;
			pos.z = lure_pos.z;
			
			fs_smoke_ct(
			    NULL,
			    (Fishing_Eff *)game_play->special_effect,
			    &pos,
			    1.0f - 0.75f /* + (float)BREG(28)*0.001f */
			    );
		    }
#endif		    
		    lure_act_vec.y = 0.0f;
		} else {
		    lure_action = 1; /* フォーリング中をさかなに教える */
		}
	    } else {/* 浮力 */
		lure_act_vec.y = fabsf(line_pos[LINE_MAX_JOINT-1].y - (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) * 0.2f;
		if(lure_act_vec.y > 1.5f)
		    lure_act_vec.y = 1.5f;
	    }
	}
	
	line_pos[LINE_MAX_JOINT-1].x += lure_act_vec.x;
	line_pos[LINE_MAX_JOINT-1].y += lure_act_vec.y/* + lure_ys2*/;
	line_pos[LINE_MAX_JOINT-1].z += lure_act_vec.z;

	if(line_pos[LINE_MAX_JOINT-1].y > gr + 6.0f) {
	    line_pos[LINE_MAX_JOINT-1].y -= 5.0f;
	}
	
	lure_spd.x = 
	    lure_spd.y = 
	    lure_spd.z = 
	    lure_acc.y = 0.0f;

	if(Pad_push_also(REEL_BUTTON)) { /* 巻き取り？ */		 
/* 	    lure_pos = line_pos[LINE_MAX_JOINT-1]; */
	    
	    if(Pad_push_also(R_TRIG)) {
		line_cap += 1.5f;  /* 高速 */
		Na_StartSystemSe_F(NA_SE_IT_FISHING_REEL_HIGH);	/* <SE> */
		add_calc2(&lure_hosei_s,
			  1000.0f,
			  1.0f,
			  2.0f /* + (float)SEX(26)*0.01f */
		    );
	    }  else {
		line_cap += hit_power;
		Na_StartSystemSe_F(NA_SE_IT_FISHING_REEL_SLOW);	/* <SE> */
		add_calc2(&lure_hosei_s,
			  1000.0f,
			  1.0f,
			  0.2f /* + (float)SEX(26)*0.01f */
		    );
	    }
#if 0	    
	    Na_StartObjectSe((f32 *)&lure_se_pos, NA_SE_IT_BOW_DRAW);	/* <SE> */
#endif	    
	    if(line_pos[LINE_MAX_JOINT-1].y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 4.0f) {
		add_calc2(&line_G,
			  3.0f /* + (float)SEX(21)*0.01f */,
			  1.0f,
			  0.2f /* + (float)SEX(24)*0.01f */
		    );
	    } else {
		add_calc2(&line_G,
			  1.0f /* + (float)SEX(21)*0.01f */,
			  1.0f,
			  0.2f /* + (float)SEX(24)*0.01f */
		    );
	    }
	} else {   
	    add_calc2(&line_G,
		      2.0f /* + (float)SEX(23)*0.01f */,
		      1.0f,
		      0.2f /* + (float)SEX(24)*0.01f */
		);
	}

	/* キャスト直後の急激な補正を防ぐ為 */
	add_calc2(&lure_pos.x,
		  line_pos[LINE_MAX_JOINT-1].x,
		  1.0f,
		  lure_hosei_s
	    );
	add_calc2(&lure_pos.y,
		  line_pos[LINE_MAX_JOINT-1].y,
		  1.0f,
		  lure_hosei_s
	    );
	add_calc2(&lure_pos.z,
		  line_pos[LINE_MAX_JOINT-1].z,
		  1.0f,
		  lure_hosei_s
	    );
	if(lure_act_speed > 1.0f) {
	    add_calc2(&lure_hosei_s,
		      1000.0f,
		      1.0f,
		      1.0f /* + (float)SEX(26)*0.01f */
		);
	}
	add_calc2(&lure_hosei_s,
		  1000.0f,
		  1.0f,
		  0.1f /* + (float)SEX(26)*0.01f */
	    );
	
	if(line_cap >= (float)LINE_MAX_JOINT - 5.0f /* - KAZ(80) */) {  /* 全部巻いた？ */
	    line_cap = (float)LINE_MAX_JOINT - 5.0f /* - KAZ(80) */;
	    
//	    pl->fishing_mode = -NEXT_CAST_WAIT; /* 次のキャストまでのウエイト */
//	    pl->fishing_mode =  KAZ(37); /* 次のキャストまでのウエイト */
	    
	    lure_mode = LURE_MODE_READY;
	    line_G = 20.0f /* + KAZ(81)  */+ 500.0f;
	    
	    demo_mode = 3;
	}
	
	if(lure_pos.y <= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 4.0f &&
	   lure_pos.y >= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 4.0f) { /* 波紋セット */
	    short ct = 0x3f;
	    
	    if(Pad_push_also(REEL_BUTTON) || lure_act_speed > 1.0f) { /* ルアー移動？ */
		ct = 0x01;
	    }
	    if((lure_count & ct) == 0) {
		pos = lure_pos;
		pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
		
		fs_hamon_ct(
		    NULL,
		    (Fishing_Eff *)game_play->special_effect,
		    &pos,
		    30,
		    300,
		    150,
		    FISHING_EFF_SIZE-10
		    );
	    }
	}
	break;
	
    case LURE_MODE_FISHON:/* ヒット ？ */
	if(this->hikiyose_power) {
	    this->hikiyose_power --;
	    line_cap += hit_power;
	}
	if(Pad_push_also(REEL_BUTTON)) { /* 巻き取り？ */		 
/* 	    line_cap += hit_power; */
	    if( (lure_pos.x*lure_pos.x + lure_pos.z*lure_pos.z) > 920.0f*920.0f) { /* 水範囲外？ */
		line_cap += 1.0f
#if FS_DEBUG		    
		    + (float)KAZ(65)*0.1f
#endif		    
		    ;
	    } else {
		line_cap += hit_power;
	    }
#if 1	    
	    Na_StartSystemSe_F(NA_SE_IT_FISHING_REEL_SLOW);	/* <SE> */
#else	    
	    Na_StartObjectSe_F((f32 *)&lure_se_pos, NA_SE_IT_BOW_DRAW);	/* <SE> */
#endif	    
	}
	    
	if(!(lure_count & 0x01f)) {
	    if((lure_hook_up || lure_type != LURE_TYPE_WORM)) {
		line_tensyon = 5;
	    }
	}
	add_calc2(&line_G,
		  0.0f,
		  1.0f,
		  0.2f /* + (float)SEX(24)*0.01f */
	    );
	break;
	
    case LURE_MODE_CATCH: /* 取り込みデモ中 */
	/* アップなので細くしたほうが見栄えがいい */
	line_scale = 0.01f * 0.15f + (float)(/* SEX(1) */-10)*0.0001f; 
	
	line_pos[LINE_MAX_JOINT-1].x = lure_pos.x;
	line_pos[LINE_MAX_JOINT-1].y = lure_pos.y;
	line_pos[LINE_MAX_JOINT-1].z = lure_pos.z;

	line_G = 2.0f /* + (float)SEX(79)*0.01f */;
	break;
    }
    
}

static int  fish_sibuki_set(Fishing_actor *this, Game_play *game_play, u8 flag)
{
    short i,s;
    float size;
    xyz_t pos,vec;

    if(this->actor.world.position.y <   /* 下すぎ ? */
       (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 10.0f && flag == 0) {
	return 0;
    }

    if(this->size >= 60.0f) {
	s = 60;
	size = 1.5f;
    } if(this->size >= 50.0f) {
	s = 50;
	size = 1.3f;
    } if(this->size >= 40.0f) {
	s = 40;
	size = 1.2f;
    } else {
	s = 30;
	size = 1.0f;
    }
    
    for(i=0;i<s;i++) {
	float ad,ra;
	
	ad = (0.5f + rnd_f(1.5f)) * size;
	
	ra = rnd_f(6.28f);
	
	vec.x = sinf( ra ) * ad;
	vec.z = cosf( ra ) * ad;
	vec.y = (3.0f + rnd_f(3.0f)) * size;
	
	pos = this->actor.world.position;
	pos.x += vec.x * 3.0f;
	pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
	pos.z += vec.z * 3.0f;
	
	fs_mizu_ct(
	    &this->actor.camera_position,
	    (Fishing_Eff *)game_play->special_effect,
	    &pos,
	    &vec,
	    (0.025f + rnd_f(0.02f)) * size
	    );
    }
    
    pos = this->actor.world.position;
    pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
    
    fs_hamon_ct(
	&this->actor.camera_position,
	(Fishing_Eff *)game_play->special_effect,
	&pos,
	100 ,
	800 ,
	150,
	FISHING_EFF_SIZE-10
	);

    this->power_move = 30;
    
    return 1;
}

static void fish_sibuki_set_S(Fishing_actor *this, Game_play *game_play)
{
    short i,s;
    float size;
    xyz_t pos,vec;

    if(this->size >= 60.0f) {
	s = 40;
	size = 0.75f;
    } if(this->size >= 45.0f) {
	s = 30;
	size = 0.5f;
    } else {
	s = 20;
	size = 0.3f;
    }
    
    for(i=0;i<s;i++) {
	float ad,ra;
	
	ad = (0.5f + rnd_f(1.5f)) * size;
	
	ra = rnd_f(6.28f);
	
	vec.x = sinf( ra ) * ad;
	vec.z = cosf( ra ) * ad;
	vec.y = (2.0f + rnd_f(2.0f));
	
	pos = this->actor.world.position;
	pos.x += vec.x * 3.0f;
	pos.y += vec.y * 3.0f;
	pos.z += vec.z * 3.0f;
	
	fs_mizu_ct(
	    &this->actor.camera_position,
	    (Fishing_Eff *)game_play->special_effect,
	    &pos,
	    &vec,
	    (0.025f + rnd_f(0.02f)) * size
	    );
    }
}


/*
 *   ルアー発見チェック
 */
static void lure_find_check(Fishing_actor *this, pad_t *pad)
{
    xyz_t mae,ato;
    float rg;
    
    /* ルアー探し */
    mae.x = lure_pos.x - this->actor.world.position.x;
    mae.y = lure_pos.y - this->actor.world.position.y;
    mae.z = lure_pos.z - this->actor.world.position.z;

    rg = (mae.x*mae.x + mae.y*mae.y + mae.z*mae.z);
    
    if(lure_mode == LURE_MODE_ACTION && /* るあー動作？ */
       this->not_eat_time == 0 &&  /* 食べる気ある？ */
       lure_with_head == 0) { /* ？ */
	Matrix_rotateY( (float)(-this->actor.shape.angle.sy)/32768.0f*F_PI , SET_MTX);
	Matrix_Position(&mae, &ato); /*  */
	
	if(ato.z > 0.0f || this->size < 40.0f) {  /* 視界？ 子バスは反応がいい*/
	    if(this->move_mode == FISH_FEEDING_MINNOW && rg < 200.0f*200.0f) { /* フィーデイングタイム？ */
		this->move_mode = FISH_ATACK_LURE_2; /* 即ヒット！ */
		this->target_pos = lure_pos;
		this->angle_sp = 0x7000;
		this->fwork[FISH_ATACK_SPEED] = 5.0f;
	    } else {
		if((Pad_push_also(REEL_BUTTON) || lure_act_speed > 1.0f ) &&
		   rg < 120.0f*120.0f)  { /* アクションに反応？ */
		    this->move_mode = FISH_FIND_LURE;  /* サーチ */
		    this->work[FISH_STAT] = 0;
		    this->timer[0] = 0;
		    this->timer[2] = 100 + (short)rnd_f(100.0f);
		    this->brain = fish_set[this->actor.arg_data-100].brain; /* ヒット確率再セット */
		    this->angle_sp = 0.0f;
		}
		if(this->timer[1] == 0 &&
		   rg < 70.0f*70.0f /* + KAZ(18) */)  { /* 自然発見？ */
		    this->move_mode = FISH_FIND_LURE;  /* サーチ */
		    this->work[FISH_STAT] = 0;
		    this->timer[0] = 0;
		    this->timer[2] = 100 + (short)rnd_f(100.0f);
		    this->brain = fish_set[this->actor.arg_data-100].brain; /* ヒット確率再セット */
		    this->angle_sp = 0.0f;
		}
	    }
	}
    } else if(lure_mode == LURE_MODE_FISHON &&
	      lure_hook_up) { /* ヒットしたルアー？ ようするにヒットした魚が接近 */
	if( rg < 100.0f*100.0f &&
	    this->move_mode >= 10) {
	    
	    this->move_mode_S = 0;
	    this->move_mode = FISH_NORMAL_SWIM_2;    /* 深みへ逃げる */
	    
	    this->wait_time = 1000;
	    this->not_eat_time = 100; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	}
    }
    if(lure_type != LURE_TYPE_WORM &&
       lure_in_water && this->size > 60.0f) { /* デカイ奴のまん前にルアーが落ちたら逃げる */
	if( rg < 30.0f*30.0f &&
	    this->move_mode >= 10) {
	    
	    this->move_mode_S = 0;
	    this->move_mode = FISH_NORMAL_SWIM_2;    /* 深みへ逃げる */
	    
	    this->wait_time = 1000;
	    this->not_eat_time = 100; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	}
    }
}
/*=======================================================================
 *	水しぶき音セット
 *======================================================================*/
#define SE_WATER_IN  0
#define SE_WATER_OUT 1
static void fish_water_se_set(Fishing_actor *this, u8 flag)
{
    short se_flag;
    u8    size;
    
    if(this->kind == FISH_KIND_BASS) {
	size = (u8)this->size;
    } else {
	size = (u8)(this->size * 2.0f);
    }

    if(flag == SE_WATER_IN) { /* 入った？ */
	if(size >= 50) {
	    se_flag  = NA_SE_EV_DIVE_INTO_WATER_H;
	} else if(size >= 40) {
	    se_flag  = NA_SE_EV_DIVE_INTO_WATER_M;
	} else {
/* 	    se_flag  = NA_SE_EV_DIVE_INTO_WATER_L; */
	    se_flag  = NA_SE_EV_DIVE_INTO_WATER_M;
	}
    } else { /* 出た */
	if(size >= 50) {
	    se_flag  = NA_SE_EV_OUT_OF_WATER_H;
	} else if(size >= 40) {
	    se_flag  = NA_SE_EV_OUT_OF_WATER_M;
	} else {
/* 	    se_flag  = NA_SE_EV_OUT_OF_WATER_L; */
	    se_flag  = NA_SE_EV_OUT_OF_WATER_M;
	}
    }
    
    Actor_SE_set(&this->actor,  se_flag);
}
	
/*=======================================================================
 *	水槽の最大魚会話処理
 *======================================================================*/
static void fish_message_check(Fishing_actor *this, Game_play *game_play)
{
    if(AGE == 1) {
	if(HI_SCORE(HS_FISH) & 0x0000007f) {  /* 記録ある？ */
	    if(HI_SCORE(HS_FISH) & SAVE_USE_WORM_C) {
		this->actor.talk_message = 0x40b1; /* 自分の記録（わーむ使用） */
	    } else {
		this->actor.talk_message = 0x4089; /* 自分の記録 */
	    }
	} else {   
	    this->actor.talk_message = 0x40ae; /* 店長の記録 */
	}
    } else { /* 大人 */
	if(HI_SCORE(HS_FISH) & 0x7f000000) {  /* 記録ある？ */
	    if(HI_SCORE(HS_FISH) & SAVE_USE_WORM_A) {
		this->actor.talk_message = 0x40b1; /* 自分の記録（わーむ使用） */
	    } else {
		this->actor.talk_message = 0x4089; /* 自分の記録 */
	    }
	} else {   
	    this->actor.talk_message = 0x40ae; /* 店長の記録 */
	}
    }
#if 0    
    if(HI_SCORE(HS_FISH) & 0x7f) {  /* 記録ある？ */
	if(HI_SCORE(HS_FISH) & SAVE_USE_WORM) {
	    this->actor.talk_message = 0x40b1; /* 自分の記録（わーむ使用） */
	} else {
	    this->actor.talk_message = 0x4089; /* 自分の記録 */
	}
    } else {   
        this->actor.talk_message = 0x40ae; /* 店長の記録 */
    }
#endif
    
    if(this->message_mode == 0) {
	if(this->message_wait == 0) {
	    Actor_set_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	    
	    if(Actor_talk_check(&this->actor, game_play)){
		FishRangeForMessage = (u16)fish_record;
		this->message_mode = 1;
	    }else{
		Actor_talk_request(&this->actor, game_play);
	    }
	} else {
	    this->message_wait --;
	    Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	}
    } else {
	if ( Actor_talk_end_check((Actor *)this, game_play) ){ /* 会話終り？ */
	    this->message_mode = 0;
	    this->message_wait = 20; /* 連続防止 */
	}
    }
}




static void Fishing_actor_move(Actor *thisx, Game *game)
{
/*     int                 bgckf; */
    short               i,angle_ad = 10;
    float x,y,z,rg,hitp,hitp2,pl_dis;
    xyz_t mae,ato;
    short xa,ya,/*za,*/zap,zad,tya;
    short /*xa2,ya2,*/xap,xad,yap,yad;
    Game_play		*game_play = (Game_play *)game;
    Fishing_actor *this = (Fishing_actor *)thisx;
    Player_actor *pla  = (Player_actor *)get_player_actor(game_play);
    pad_t		*pad = &game_play->g.pads[P_PAD];
    float        bg_ground_offset;

#if 01    
    thisx->cull_z = 700.0f /* + KAZ(62) */;
    thisx->cull_r = 50.0f /* + KAZ(63) */;		                /* カリング半径セット */
#endif
    
#if /* FS_DEBUG */ 0
    if(this->move_mode < 100) {
	if( (thisx->world.position.x*thisx->world.position.x + thisx->world.position.z*thisx->world.position.z) >
	    920.0f*920.0f) { /* 水範囲外？ */
	    
	    PRINTF("FISH MOVE MODE	%d\n",this->move_mode);

	    if(KAZ(53)) {
		thisx->world.position.y += 50.0f;
		KAZ(53) = 0;
	    }
	}
	if(KAZ(48)) {
	    if(rnd() < 0.5f) {
		this->move_mode   = KAZ(49);
		this->move_mode_S = KAZ(50);
		thisx->world.position = pla->actor.world.position;
		thisx->world.position.y += KAZ(51);
		thisx->speedF = (float)KAZ(52);
		
		this->target_pos = pla->actor.world.position;
		KAZ(48) = 0;
	    }
	}
    }
#endif

    /* プレイヤーの足音反応用 */
    if(this->kind == FISH_KIND_BASS) {
	pl_dis = 0.25f + pla->actor.speedF * 0.15f;
    } else { /* 雷魚は敏感 */
	pl_dis = 0.25f + pla->actor.speedF * 0.3f;
    }
    
    /* どこに注目？ */
    if(lure_time ||
       demo_camera_no || /* デモカメラ中は注目無し！！ */
       (pla->actor.world.position.z > 1150.0f && this->move_mode != FISH_SUISOU)) {
       /* リンク軒下？ */
/*|| this->move_mode == FISH_SUISOU) {*/ /* 水槽の奴は注目なし */
	Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
    } else {
	Actor_set_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	
	if(lure_mode) { /* ルアー動作？  */
	    if(lure_cast_time == 0) { /* 投げた瞬間はまだ早い */
		this->actor.eye.position = lure_pos;  /* ルアーを見る */
	    } else {
		if(lure_cast_time == 1) { /* カメラ切り替え？ */
#if 0		    
		    this->actor.eye.position = lure_pos;  /* ルアーを見る */
#endif		    
		    demo_mode = 1;
		    demo_eye_xp = 0.0f;
		    camera_zoom_switch = 2;
		}
#if 0		
		else {
		    this->actor.eye.position = this->actor.world.position; /* 魚を見る */
		}
#endif		
	    }
	}
#if 0	
	else {
	    this->actor.eye.position = this->actor.world.position; /* 魚を見る */
	}
#endif
	this->actor.eye.position = this->actor.world.position; /* 魚を見る */
    }
    
    this->work[FS_TIME] ++;
    
    for(i=0;i<4;i++)
	timer_check_dec(&this->timer[i]);
    
    timer_check_dec(&this->wait_time);
    timer_check_dec(&this->not_eat_time);
    timer_check_dec(&this->wall_hit);

    if(this->power_move)
	this->power_move --;

/*    
    this->fwork[ANIME_SPD] = (float)GREG(21)*0.001f;
    this->fwork[ANIME_SCALE] = (float)GREG(22);
    */
    add_calc2(&this->fwork[ANIME_SPD_S],
	      this->fwork[ANIME_SPD],
	      1.0f,
	      0.2f);

    if(this->move_mode == FISH_CATCH) {
	add_calc2(&this->fwork[ANIME_SCALE_S],
		  this->fwork[ANIME_SCALE],
		  0.2f,
		  200.0f/* +KAZ(74) */);
    } else {
	float anime_scale_P = 1.0f;
	float anime_scale_P2 = 1.0f;

	if(this->actor.world.position.y >  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) { /* 空中？ */
	    anime_scale_P = 1.5f
#if FS_DEBUG		
		+ (float)KAZ(64)*0.1f
#endif		
		;
	    anime_scale_P2 = 3.0f;
	}
	
	add_calc2(&this->fwork[ANIME_SCALE_S],
		  this->fwork[ANIME_SCALE] * anime_scale_P,
		  1.0f,
		  500.0f * anime_scale_P2
	    );
    }

    adds(&this->work[MOUSE_OPEN],
	 0,
	 5,
	 500);
	      
    
    if(this->kind == FISH_KIND_BASS) {
	Actor_set_scale(thisx, this->size  * (float)(15) * 0.00001f); /* スケールをここでやらんとヤバイ */
	
	this->fwork[ANIME_FRAME] += this->fwork[ANIME_SPD_S];
	
	this->work[ANIME_YA] = (short)(cosf(this->fwork[ANIME_FRAME]) * this->fwork[ANIME_SCALE_S]) +
	    this->work[ANIME_YA2];/* 急激なターンで体曲げる */
	
	this->work[TAIL_ANG] = (short)(cosf(this->fwork[ANIME_FRAME]
					    + (float)(300-1500/* +KAZ(72) */)*0.001f) * this->fwork[ANIME_SCALE_S]
				       * (1.6f /* + (float)KAZ(73)*0.1f */)) +
	    this->work[ANIME_YA2];/* 急激なターンで体曲げる */
    } else {
	Actor_set_scale(thisx, this->size  * (float)(/* KAZ(11) + */ 50 + 15) * 0.000001f);/* スケールをここでやらんとヤバイ */
	thisx->scale.x = thisx->scale.z * (1.1f /* + (float)KAZ(12)*0.1f */);
	thisx->scale.y = thisx->scale.z * (1.1f /* + (float)KAZ(12)*0.1f */);
	
/* 	this->fwork[ANIME_FRAME] += (float)(NS1(82)+300)*0.001f; */
/*	
	if(NS1(95)) {
	    this->fwork[ANIME_SPD_S] =  (float)(NS1(82)+300)*0.001f;
	    this->fwork[ANIME_SCALE_S] = NS1(80)*0x100;
	}
	*/
	this->fwork[ANIME_FRAME] += this->fwork[ANIME_SPD_S] * 0.8f;
	
	for(i=0;i<3;i++) {
	    this->body_ya[i] = (short)(cosf(this->fwork[ANIME_FRAME] +
					    (float)i*(0.1f + (float)(2000/* +NS1(81) */)*0.001f)) * this->fwork[ANIME_SCALE_S] * 2.0f)
		+ this->work[ANIME_YA2];
	}
	this->work[ANIME_YA] = (short)(cosf(this->fwork[ANIME_FRAME] +
					    (0.1f + (float)(300/* +NS1(83) */)*0.001f)) *this->fwork[ANIME_SCALE_S] * 2.0f * 0.6f);
    }
    
    x = this->target_pos.x - this->actor.world.position.x;
    y = this->target_pos.y - this->actor.world.position.y;
    z = this->target_pos.z - this->actor.world.position.z;
    
    ya = atans_table(z, x);
    rg = sqrtf(x*x + z*z);
    xa = atans_table(rg, y);
    
    rg = sqrtf(x*x + z*z + y*y);

    if(this->wall_hit  &&
       this->move_mode != FISH_FIND_LURE &&
       this->move_mode != FISH_ATACK_LURE_1 &&
       this->move_mode != FISH_ATACK_LURE_2 /* ルアーサーチ以外？ */
	) { /* 壁補正？ */
	if(this->work[FS_TIME] & 0x40) {
	    ya = (short)(ya + 0x4000); 
	} else {
	    ya = (short)(ya - 0x4000); 
	}
	if((this->work[FS_TIME] + 0x20) & 0x40) {
	    xa = (short)(xa + 0x2000); 
	} else {
	    xa = (short)(xa - 0x2000); 
	}
    }

    switch(this->move_mode) {
/* 水槽の中の奴 */	
    case FISH_SUISOU:
/*     case 100: */
	fish_message_check(this, game_play); /* 会話処理 */
	
	thisx->cull_z = 500.0f /* + KAZ(62) */;
	thisx->cull_r = 300.0f /* + KAZ(63) */;		                /* カリング半径セット */
	
	/* 水槽に当るライト */
	Light_point_ct(&this->light_data,
		       (short)this->actor.world.position.x,
		       (short)this->actor.world.position.y + 20.0f,
		       (short)this->actor.world.position.z - 50.0f,
		       255, 255, 255, 255);
	
	this->size = fish_record; /* 現在の記録が入るはず */
/* 	Actor_set_scale(thisx, this->size  * (float)(15) * 0.00001f); */
	
/* PRINTF("SUISOU FISH %dcm\n",(u8)this->size);	 */
	
	ato.y = sin_s(game_play->game_frame_counter*(300 /* +GREG(39) */)) * (/* GREG(40) */ + 1);
	ato.z = sin_s(game_play->game_frame_counter*(230 /* +GREG(41) */)) * (/* GREG(42)  */+ 2);
	
	this->actor.world.position.x =/*  GREG(16) +  */130.0f;
	this->actor.world.position.y =/*  GREG(17) + */ 55.0f + ato.y;
	this->actor.world.position.z = /* GREG(18) + */ 1280.0f + 20.0f + ato.z;
	this->actor.shape.angle.sy = (short)(0x1000 * (/* GREG(19) + */ 8));

	if(this->actor.camera_position.z < 200.0f /* + KAZ(53) */ &&
	   this->actor.camera_position.z > 0.0f) {
	    xyz_t pos;
	    
	    pos.x = /* KAZ(55) +  */130.0f + rnd_fx(/* KAZ(56)+ */5.0f);
	    pos.y = 40.0f /* + KAZ(57) */;
	    pos.z = /* KAZ(58) +  */1260.0f + 20.0f +rnd_fx(/* KAZ(56)+ */5.0f);
	    
	    fs_bubble_ct(
		NULL,
		(Fishing_Eff *)game_play->special_effect,
		&pos,
		0.03f + rnd_f(0.02f),
		1
		);
	}
	adds(&this->work[HIRE_ANG],
	     (short)(sin_s(this->work[FS_TIME] * 0x800) * 2500.0f + 2500.0f),
	     2,
	     2000);
	adds(&this->work[HIRE_ANG2],
	     (short)(sin_s(this->work[FS_TIME] * 0xa00) * 1500.0f),
	     2,
	     2000);

	this->fwork[ANIME_SPD] = 0.3f /* + (float)KAZ(70)*0.1f */;
	this->fwork[ANIME_SCALE] = 500.0f / 1.5f /* + KAZ(71) */;
	return;
	
/* ストラクチャーで待機 */	
/*     case 10:    */
    case FISH_STRUCT_WAIT_1:
	this->target_pos = this->actor.home.position;

	add_calc2(&this->actor.speedF,
		  2.0f /* + (float)SEX(51) */,
		  1.0f,
		  0.5f /* + (float)SEX(52)*0.01f */
	    );
	
	add_calc2(&this->angle_sp,
		  (float)0x1000,
		  1.0f,
		  (float)0x100 /* + SEX(59)*0x10 */
	    );
	
	if(rg < 40.0f) {
	    this->move_mode = FISH_STRUCT_WAIT_2;
	    
	    this->fwork[ANIME_SPD] = 0.4f;
	    this->fwork[ANIME_SCALE] = 500.0f;
	}
	
	lure_find_check(this, pad);  /* ルアー発見？ */
	
	if(this->actor.player_distance < (250.0f /* + KAZ(46) */) * pl_dis) { /* 釣り人接近 ？*/
	    this->move_mode_S = 
		this->move_mode = FISH_NORMAL_SWIM_1;    /* 深みへ逃げる */
	    this->wait_time = 1000;
	    this->not_eat_time = 200; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	}
	break;
	
    case FISH_STRUCT_WAIT_2:
/*     case 11: */
	this->target_pos = this->actor.home.position;
	
	add_calc2(&this->actor.speedF,
		  0.0f /* + (float)SEX(51) */,
		  1.0f,
		  0.05f /* + (float)SEX(52)*0.01f */
	    );
	
	add_calc2(&this->angle_sp,
		 0.0f,
		 1.0f,
		 (float)0x100 /* + SEX(59)*0x10 */
		 );
	
	if(rg >= 40.0f) {
	    this->move_mode = FISH_STRUCT_WAIT_1;

	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 2000.0f;
	}

	lure_find_check(this, pad);  /* ルアー発見？ */
	
	if(this->actor.player_distance < (250.0f /* + KAZ(46) */) * pl_dis) { /* 釣り人接近 ？*/
	    this->move_mode_S = 
		this->move_mode = FISH_NORMAL_SWIM_1;    /* 深みへ逃げる */
	    this->wait_time = 1000;
	    this->not_eat_time = 200; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	}

	if(message_check(&(game_play->message)) == 0) { /* 会話中は無し */
	    if( ZCommonGet(zelda_time) >= CHANGE_TIME(18.00f) &&
		ZCommonGet(zelda_time) <= CHANGE_TIME(18.01f)
		) { /* 夕暮れ */
		this->move_mode = FISH_FEEDING_MINNOW; /* フィーデイングタイム */
		this->timer[3] = 200/*  + GREG(30) */ + (short)rnd_f(150.0f);
	    }
	    if( ZCommonGet(zelda_time) >= CHANGE_TIME(5.50f) &&
		ZCommonGet(zelda_time) <= CHANGE_TIME(5.51f)
		) { /* 早朝 */
		this->move_mode = FISH_FEEDING_MINNOW; /* フィーデイングタイム */
		this->timer[3] = 200 /* + GREG(30)  */+ (short)rnd_f(150.0f);
	    }
	}

	
#if FS_DEBUG 
	if(KAZ(15)) {
	    KAZ(15) = 0;
	    
	    this->move_mode = FISH_FEEDING_MINNOW; /* フィーデイングタイム */
	    this->timer[3] = 2000/*  + GREG(30) */ + (short)rnd_f(150.0f);
	}
#endif	
	break;

/* 真ん中で遊泳 */
    case FISH_NORMAL_SWIM_1:
/*     case 0: */
	add_calc2(&this->actor.speedF,
		  1.0f/*  + (float)SEX(58)*0.1f */,
		  1.0f,
		  0.05f /* + (float)SEX(48)*0.01f */
	    );

	add_calc2(&this->angle_sp,
		 0.0f,
		 1.0f,
		 0x100 /* + SEX(59)*0x10 */
		 );

	if(this->timer[0] == 0) {
	    if(this->wait_time == 0) {  /* ストラクチャーへ戻ろう */
		this->move_mode   = 
		    this->move_mode_S = FISH_STRUCT_WAIT_1;  /* もどすモード */
	    } else {
		this->move_mode = FISH_NORMAL_SWIM_2;
		this->timer[0] = 10 /* + SEX(49)  */+ (short)rnd_f(30.0f);
		
		this->target_pos.x = rnd_fx(300.0f/* +SEX(50) */);
		this->target_pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
		    -50.0f - rnd_f(50.0f /* + SEX(57) */);
		this->target_pos.z = rnd_fx(300.0f/* +SEX(50) */);

		this->fwork[ANIME_SPD] = 1.0f;
		this->fwork[ANIME_SCALE] = 2000.0f;
#if 0		
		this->angle_sp = /* SEX(55)*0x100 + */ 0x700 + rnd_f(0x700 /* + SEX(54)*0x100 */);
#endif		
	    }
	}
	
	if(lure_type == LURE_TYPE_WORM) { /* ワームは食う */
	    lure_find_check(this, pad);  /* ルアー発見？ */
	} else {
	    Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	}
	break;
	
/* 真ん中で遊泳 ２ */
    case FISH_NORMAL_SWIM_2: /* 通常遊泳 */
/*     case 1: */
	if(this->kind == FISH_KIND_SNAKEHEAD) {
	    this->move_mode = FISH_SNAKEHEAD_WAIT;
	    this->wait_time = 20000;
	    this->not_eat_time = 20000; /* しばらく食わない */
	    
	    this->target_pos.x = 0.0f;
	    this->target_pos.y = -140.0f;
	    this->target_pos.z = 0.0f;
	    break;
	}
	add_calc2(&this->angle_sp,
		  (float)(0x1000),
		  1.0f,
		  0x100 /* + SEX(59)*0x10 */
	    );
	
	if(this->actor.player_distance < (250.0f /* + KAZ(46) */) * pl_dis ||
	   this->timer[1]) { /* 釣り人あるいはヒットした魚接近 ？*/
	    add_calc2(&this->angle_sp,
		      (float)(0x2000),
		      1.0f,
		      0x300 /* + SEX(59)*0x10 */
		);
	    add_calc2(&this->actor.speedF,
		      4.2f /* + (float)SEX(51) */,
		      1.0f,
		      0.75f /* + (float)SEX(52)*0.01f */
		);

	    this->fwork[ANIME_SPD] = 1.2f;
	    this->fwork[ANIME_SCALE] = 4000.0f;
	    
	    this->timer[0] = 20;
	} else {
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 2000.0f;
	    
	    add_calc2(&this->actor.speedF,
/*		      3.0f + (float)SEX(51),*/
		      1.5f /* + (float)SEX(51) */,
		      1.0f,
		      0.1f /* + (float)SEX(52)*0.01f */
		);
	}

	if(this->timer[0] == 0 ||
	   rg < 50.0f /* + SEX(56) */) {
	    this->move_mode = FISH_NORMAL_SWIM_1;
	    this->timer[0] = 3 /* + SEX(53) */ + (short)rnd_f(30.0f);
	   
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 500.0f;
	}
	
	if(lure_type == LURE_TYPE_WORM) {
	    lure_find_check(this, pad);  /* ルアー発見？ */
	} else {
	    Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	}
	break;
	
    case FISH_SNAKEHEAD_WAIT: /* SNAKEHEAD用待機 */
   /*  case -1: */ 
	adds(&this->work[FISH_XA_S],
	     0,
	     20,
	     0x20
	     );
	
	if(this->actor.player_distance < (250.0f /* + KAZ(46) */) * pl_dis ||
	   this->timer[1]) { /* 釣り人あるいはヒットした魚接近 ？*/
	    add_calc2(&this->actor.speedF,
		      3.0f /* + (float)SEX(51) */,
		      1.0f,
		      0.75f /* + (float)SEX(52)*0.01f */
		);

	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 4000.0f;
	    
	    this->timer[0] = 20;
	    
	    add_calc2(&this->angle_sp,
		      (float)(0x1000),
		      1.0f,
		      0x100 /* + SEX(59)*0x10 */
	    );

	    if(!(game_play->game_frame_counter & 0x1f)) {
		this->target_pos.x = rnd_fx(600.0f);
		this->target_pos.z = rnd_fx(600.0f);
		this->target_pos.y = -120.0f;
	    }
	} else {
	    if(rg > 50.0f) {
		this->fwork[ANIME_SPD] = 0.8f;
		this->fwork[ANIME_SCALE] = 1500.0f;
		
		add_calc2(&this->actor.speedF,
			  1.0f /* + (float)SEX(51) */,
			  1.0f,
			  0.1f /* + (float)SEX(52)*0.01f */
		    );
		add_calc2(&this->angle_sp,
			  (float)(0x800),
			  1.0f,
			  0x80 /* + SEX(59)*0x10 */
		    );
	    } else {
		this->fwork[ANIME_SPD] = 0.4f;
		this->fwork[ANIME_SCALE] = 500.0f;
		
		add_calc0(&this->actor.speedF,
			  1.0f,
			  0.02f /* + (float)SEX(48)*0.01f */
		    );
		
		add_calc2(&this->angle_sp,
			  0.0f,
			  1.0f,
			  0x100 /* + SEX(59)*0x10 */
		    );
	    }
	}

	if(this->wait_time == 0) {  /* ストラクチャーへ戻ろう */
	    this->move_mode   = FISH_STRUCT_WAIT_1;
	    this->move_mode_S = FISH_STRUCT_WAIT_1;  /* もどすモード */
	} else {
	    if (
#if FS_DEBUG		
		KAZ(2) ||
#endif		
		(!(this->wait_time & 0x7ff) && this->wait_time < 15000)) {
#if FS_DEBUG		
 		KAZ(2) = 0;
#endif		
		this->move_mode = FISH_SNAKEHEAD_AIR;
		this->actor.world.angle.sx = 
		    this->actor.shape.angle.sx = 0x00;
		this->target_pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 10.0f;
		this->target_pos.x = rnd_f(50.0f);
		this->target_pos.z = rnd_f(50.0f);
	    }
	}
	Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	break;
	
    case FISH_SNAKEHEAD_AIR: /* SNAKEHEAD用空気吸い */
	if(this->actor.player_distance < (250.0f /* + KAZ(46) */) * pl_dis ||
	   this->timer[1]) { /* 釣り人あるいはヒットした魚接近 ？*/
	    this->move_mode = FISH_SNAKEHEAD_WAIT;
	    this->target_pos.y = -120.0f;
	    break;
	}
	this->fwork[ANIME_SPD] = 0.6f;
	this->fwork[ANIME_SCALE] = 1000.0f;

	adds(&this->work[FISH_XA_S],
	     -0x1000 /* + KAZ(43)*0x100 */,
	     20 /* + KAZ(44) */,
	     0x100 /* + KAZ(45) */
	     );
	
	if(this->actor.world.position.y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 20.0f /* + KAZ(40) */) {
	    add_calc2(&this->actor.speedF,
		      0.5f /* + (float)SEX(51) */,
		      1.0f,
		      0.1f /* + (float)SEX(52)*0.01f */
		);
	} else {
	    add_calc0(&this->actor.speedF,
		      1.0f,
		      0.01f/*   + (float)KAZ(41)*0.001f */ 
		);
	    if(this->actor.speedF == 0.0f ||
	       this->actor.world.position.y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 5.0f /* + KAZ(42) */) {
		xyz_t pos;
		
		this->target_pos.x = rnd_f(300.0f);
		this->target_pos.z = rnd_f(300.0f);
		this->target_pos.y = this->actor.ground_y + 10.0f;
		this->move_mode = FISH_SNAKEHEAD_AIR_2;
		this->angle_sp = 0.0f;

		pos = this->pl_catch_pos;
		pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;

		fs_hamon_ct(
		    &this->actor.camera_position,
		    (Fishing_Eff *)game_play->special_effect,
		    &pos,
		    10,
		    300,
		    150,
		    FISHING_EFF_SIZE-10
		    );
		
		fs_hamon_ct(
		    &this->actor.camera_position,
		    (Fishing_Eff *)game_play->special_effect,
		    &pos,
		    30,
		    400,
		    150,
		    FISHING_EFF_SIZE-10
		    );
		Actor_SE_set((Actor *)this, NA_SE_PL_CATCH_BOOMERANG); /* SE */
		break;
	    }
	}
	
	add_calc2(&this->angle_sp,
		  (float)(0x800),
		  1.0f,
		  (float)(0x80 /* + KAZ(49)*0x10 */)
	    );
	
	Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
	break;
	
    case FISH_SNAKEHEAD_AIR_2: /* SNAKEHEAD用空気吸い 2 */
	if(this->actor.player_distance < (250.0f /* + KAZ(46) */) * pl_dis ||
	   this->timer[1]) { /* 釣り人あるいはヒットした魚接近 ？*/
	    this->move_mode = FISH_SNAKEHEAD_WAIT;
	    this->target_pos.y = -120.0f;
	} else {
	    adds(&this->work[FISH_XA_S],
		 0x1000/*  + KAZ(46)*0x100 */,
		 20 /* + KAZ(47) */,
		 256 - 150
		);
	    
	    if(rg > 40.0f) {
		this->fwork[ANIME_SPD] = 0.7f;
		this->fwork[ANIME_SCALE] = 1200.0f;
		
		add_calc2(&this->actor.speedF,
			  0.5f /* + (float)SEX(51) */,
			  1.0f,
			  0.01f /* + (float)SEX(52)*0.01f */
		    );
		add_calc2(&this->angle_sp,
			  (float)(0x800),
			  1.0f,
			  0x80 /* + SEX(59)*0x10 */
		    );
	    } else {
		this->move_mode = FISH_SNAKEHEAD_WAIT;
	    }
	}
	break;
	
    case FISH_FIND_LURE:/* ルアーサーチ */
/*     case 2:  */
	if((this->actor.arg_data + lure_search_p )& 0x01) { /* 多分ランダム */
	    mae.x =  10.0f;
	} else {
	    mae.x = -10.0f;
	}
	mae.y =  0.0f;
	mae.z =  0.0f;
	Matrix_rotateY(	lure_ang.y, SET_MTX);
	Matrix_Position(&mae, &ato); /*  */
	
/* 	this->target_pos = lure_pos; */
	
	this->target_pos.x = lure_pos.x + ato.x;
	this->target_pos.z = lure_pos.z + ato.z;
	
	if(lure_type == LURE_TYPE_WORM) {
	    this->target_pos.y = lure_pos.y + 0.0f;
	} else {
	    if(this->kind == FISH_KIND_BASS) {
		this->target_pos.y = lure_pos.y - 15.0f /* + SEX(62) */;
	    } else {
		this->target_pos.y = lure_pos.y - 5.0f /* + SEX(62) */;
	    }
	}
	if(this->target_pos.y <= this->actor.ground_y) {
	    this->target_pos.y = this->actor.ground_y /* + SEX(63) */ + 3.0f;
	}
	
	if(lure_type != LURE_TYPE_WORM &&
	   this->actor.world.position.y > this->target_pos.y) { /* 頭が下を向かないように */
	    add_calc2(&this->actor.world.position.y,
		     this->target_pos.y,
		     0.1f,
		     (this->actor.world.position.y - this->target_pos.y) * 0.1f
		     );
	}
	
/*	this->angle_sp = 0x2000;*/
	add_calc2(&this->angle_sp,
		  (float)0x2000,
		  1.0f,
		  (float)0x100 * 1.5f
#if FS_DEBUG		  
		  + KAZ(16)*0x80
#endif		  
	    );
	
	if(Pad_on_trigger(REEL_BUTTON)) { /* 微妙なアクション？ */
	    this->brain += 0.005f; /* だんだん興味を持つ */
	}
	if(lure_action) {
/*	if(lure_actionPad_on_trigger(CAST_BUTTON)) {*/
	    if(lure_action == 1) {
		this->brain += 0.01f; /* だんだん興味を持つ */
	    } else {
		this->brain += 0.05f; /* 大スライド幅 */
	    }
	    lure_action = 0;
	}
	if(Pad_on_trigger(CAST_BUTTON)) {
	    this->brain += 0.008f; /* だんだん興味を持つ */
	}
	
	if(rg < 60.0f - 40.0f /* + SEX(61) */ + this->size * 0.5f) {
	    if(this->work[FISH_STAT] == 0) {

		this->fwork[ANIME_SPD] = 1.0f;
		this->fwork[ANIME_SCALE] = 500.0f;
		
		this->timer[0] = (short)rnd_f(10.0f) + 2;
	    }
	    add_calc2(&this->actor.speedF,
		      -0.2f /* + (float)SEX(64)*0.01f */,
		      1.0f,
		      0.1f /* + (float)SEX(65)*0.01f */
		);
	    this->work[FISH_STAT] = 1;
	} else {
	    if(this->work[FISH_STAT]) {
		this->angle_sp = 0.0f;

		this->fwork[ANIME_SPD] = 1.0f;
		this->fwork[ANIME_SCALE] = 3000.0f;
	    }
	    
	    add_calc2(&this->actor.speedF,
		     3.0f /* + (float)SEX(66) */,
		     1.0f,
		     0.15f /* + (float)SEX(67)*0.01f */
		     );
	    this->work[FISH_STAT] = 0;
	}

	if(this->size >= 60.0f) { /* 60up? */
	    hitp = 0.3f;  /* なかなかヒットしない（はず） */
	} else if(this->size >= 45.0f) { /* 45up? */
	    hitp = 0.6f;  /* なかなかヒットしない（はず） */
	} else {
	    hitp = 1.0f; 
	}

	/* 環境によるヒット可能性アップ */
	if( ZCommonGet(zelda_time) >= CHANGE_TIME(17.00f) &&
	    ZCommonGet(zelda_time) <= CHANGE_TIME(19.00f)
	    ) { /* 夕暮れ */
	    hitp *= 1.75f;
	} else if( ZCommonGet(zelda_time) >= CHANGE_TIME(5.00f) &&
		   ZCommonGet(zelda_time) <= CHANGE_TIME(7.00f)
	    ) { /* 早朝 */
	    hitp *= 1.5f;
	} else if(mad_water) { /* 濁り？ */
	    hitp *= 1.5f;
	} else if((u8)rain_S) {  /* 雨？ */
	    hitp *= 3.0f;
	}

	hitp2 = 0.03f * hitp;

	if(lure_type == LURE_TYPE_WORM) { /* わーむは停止しても食いやすい */
	    hitp2 *= 5.0f;
	}

	if(this->timer[0] == 1 || /* 動から静に変わった？ */
	   rnd() < hitp2) { /* ガマンできん！ */
	    if(rnd() < this->brain * hitp    /* 確率？ */
#if FS_DEBUG	    
	       ||   KAZ(69) == this->kind + 1
#endif	       
		) {
		if(this->kind == FISH_KIND_BASS) {
		    this->move_mode = FISH_ATACK_LURE_1;
		    this->fwork[ANIME_SPD] = 1.2f;
		    this->fwork[ANIME_SCALE] = 5000.0f;
		    this->timer[0] = (short)rnd_f(10.0f);
		} else {
		    this->move_mode = FISH_SNAKEHEAD_ATACK_LURE;
		    this->fwork[ANIME_SPD] = 1.0f;
		    this->fwork[ANIME_SCALE] = 3000.0f;
		    this->timer[0] = 40;
		}
		if(lure_type == LURE_TYPE_WORM) { 
		    this->fwork[FISH_ATACK_SPEED] = rnd_f(1.5f) + 3.0f;
		} else {
		    this->fwork[FISH_ATACK_SPEED] = rnd_f(1.5f) + 4.5f;
		}
	    }
	}

	if(lure_mode != LURE_MODE_ACTION ||
	   this->timer[2] == 0 || /* 見破り */
	   sqrtf(this->actor.world.position.x*this->actor.world.position.x +
		 this->actor.world.position.z*this->actor.world.position.z) > 800.0f /* + KAZ(47) */) { /* 岸に行きすぎ ？*/
#if 0	    
	   fabsf(this->actor.world.position.x)  > 800.0f+KAZ(47) || /* 岸に行きすぎ ？*/
	   fabsf(this->actor.world.position.z)  > 800.0f+KAZ(47)
	    ) {
#endif		     
	    this->move_mode = this->move_mode_S;
	    this->timer[1] = 50 + (short)rnd_f(30.0f); /* すぐにサーチしないように */
	    this->timer[0] = 5 + (short)rnd_f(10.0f);
	    this->angle_sp = 0.0f;

	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 2000.0f;
	}
	
	if(this->actor.player_distance < (100.0f /* + KAZ(46) */) * pl_dis) { /* 釣り人接近 ？*/
	    this->move_mode_S = 
		this->move_mode = FISH_NORMAL_SWIM_1;    /* 深みへ逃げる */
	    this->wait_time = 1000;
	    this->not_eat_time = 200; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	}
	break;
	
    case FISH_ATACK_LURE_1:/* 周り込み */
/*     case 3:  */
	this->power_move = 6;
	
	angle_ad = 2;

	if(((short)pla->actor.world.position.x  + lure_search_p  ) & 0x01) { /* 多分ランダム */
	    mae.x =  30.0f;
	} else {
	    mae.x = -30.0f;
	}
	mae.y =  0.0f;
	mae.z = 30.0f;
	Matrix_rotateY(	lure_ang.y, SET_MTX);
	Matrix_Position(&mae, &ato); /*  */
	
	this->target_pos.x = lure_pos.x + ato.x;
	this->target_pos.z = lure_pos.z + ato.z;
	
	this->target_pos.y = lure_pos.y - 10.0f;
	
	this->angle_sp = (float)0x1000;
	
	add_calc2(&this->actor.speedF,
		 this->fwork[FISH_ATACK_SPEED] * 0.8f,
/*		 5.0f + (float)SEX(66),*/
		 1.0f,
		 1.0f /* + (float)SEX(67)*0.01f */
		 );

	if(lure_mode != LURE_MODE_ACTION ||
	   lure_pos.y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 5.0f || /* 上に行きすぎ */
	   sqrtf(lure_pos.x*lure_pos.x +
		 lure_pos.z*lure_pos.z) > 800.0f /* 岸に行きすぎ ？*/
	    ) {
#if 0	    
	   fabsf(lure_pos.x)  > 800.0f/* +KAZ(47) */ || /* 岸に行きすぎ ？*/
	   fabsf(lure_pos.z)  > 800.0f/* +KAZ(47) */
	    ) { /* 他の奴に先に食われた？ */
#endif		
	    this->move_mode = this->move_mode_S;
	    this->timer[0] = 0;
	   
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 2000.0f;
 	    break;     
	}
	
	if(this->timer[0] == 0 || rg < 30.0f /* + KAZ(16) */) {
	    this->move_mode = FISH_ATACK_LURE_2;
	    this->target_pos = lure_pos;
	    this->angle_sp = 0x4000;
	    
	    this->fwork[ANIME_SPD] = 1.2f;
	    this->fwork[ANIME_SCALE] = 5000.0f;
	    
	    this->timer[0] = 20;
	    
/*	    this->timer[0] = 10;*/
	}
	break;
	
    case FISH_ATACK_LURE_2: /* 食う！！ */
/*     case 4:  */
	add_calc2(&this->angle_sp,
		  (float)0x4000,
		  1.0f,
		  (float)0x1000 /* + SEX(59)*0x10 */
	    );
	adds(&this->work[MOUSE_OPEN],
	     20000,
	     4,
	     5000);
	
	this->power_move = 50;
	
	angle_ad = 2;
	
	this->target_pos = lure_pos;
	add_calc2(&this->actor.speedF,
/*		 7.0f + (float)SEX(66),*/
		 this->fwork[FISH_ATACK_SPEED],
		 1.0f,
		 1.0f /* + (float)SEX(67)*0.01f */
		 );
	
	if(lure_mode != LURE_MODE_ACTION ||
	   this->timer[0] == 0 ||
	   lure_pos.y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 5.0f || /* 上に行きすぎ */
	   sqrtf(lure_pos.x*lure_pos.x +
		 lure_pos.z*lure_pos.z) > 800.0f /* 岸に行きすぎ ？*/
#if 0	   
	   fabsf(lure_pos.x)  > 800.0f/* +KAZ(47) */ || /* 岸に行きすぎ ？*/
	   fabsf(lure_pos.z)  > 800.0f/* +KAZ(47) */
#endif	   
	    ) { /* 他の奴に先に食われた？ */
	    this->move_mode = this->move_mode_S;
	    this->timer[0] = 0;
	   
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 2000.0f;
/* 	    break; */    /* ダブルヒットの可能性をあえて入れよう */
	    break; /* やっぱりやめ  */
	}
	
	
/*	if(this->timer[0] == 0 || rg < 30.0f + KAZ(16)) {  */
        if(rg < 10.0f /* + KAZ(26) */) { /* くわえた？ */
	    short tame_time;
	    
	    if(fish_sibuki_set(this, game_play, 0)) {
		fish_water_se_set(this, SE_WATER_IN);
	    }
	    this->move_mode = FISH_HIT_LURE;
/*	    this->timer[0] = 5 + (short)rnd_f(10.0f);*/
	    
	    this->fwork[ANIME_SPD] = 1.2f;
	    this->fwork[ANIME_SCALE] = 5000.0f;
	    
	    this->timer[1] = 150;
	    this->timer[0] = 0;
	    this->timer[2] = 0;
	    this->timer[3] = 120; /* すぐにジャンプしない */

	    lure_mode = LURE_MODE_FISHON; /* ヒット！ */
	    hit_fish_actor = this;

	    fish_mouse_p.y = 500.0f - rnd_f(400.0f); /* 口に掛る場所を微妙に変える */
	
	    if(lure_type == LURE_TYPE_WORM) {
		if(this->size > 70.0f) {
		    tame_time = 10 + (short)rnd_f(20.0f);
		} else if(this->size > 60.0f) {
		    tame_time = 20 + (short)rnd_f(30.0f);
		} else if(this->size > 50.0f) {
		    tame_time = 30 + (short)rnd_f(30.0f);
		} else {
		    tame_time = 40 + (short)rnd_f(40.0f);
		}
		lure_hook_time = tame_time;
		vib_time = tame_time;
		RUMBLE_ENTRY_FORCE2(60/* +KAZ(52) */, tame_time*3, 10, 0.0f);	/* 振動セット */
	    } else {
		if(this->size > 70.0f) {
		    tame_time = 10 + (short)rnd_f(5.0f);
		} else if(this->size > 60.0f) {
		    tame_time = 15 + (short)rnd_f(5.0f);
		} else if(this->size > 50.0f) {
		    tame_time = 17 + (short)rnd_f(5.0f);
		} else {
		    tame_time = 25 + (short)rnd_f(5.0f);
		}
		lure_hook_time = tame_time;
		vib_time = tame_time;
		RUMBLE_ENTRY_FORCE2(180, tame_time*3, 10, 0.0f);	/* 振動セット */
	    }
	    lure_hook_up = 0;
	    lure_hook_power = 100; /* 針掛りの度合い */
	    fish_fight_time = 0; /* 格闘時間 */
#if 0	    
	    Na_StopBgm(30);  /*  SE BGM */
#endif	    
	}
	break;
	
    case FISH_SNAKEHEAD_ATACK_LURE:/* SNAKEHEAD用食う！ */
/*     case -3:  */
	this->power_move = 50;
	
	this->target_pos = lure_pos;
	
	add_calc2(&this->actor.speedF,
		  2.0f,
		  1.0f,
		  1.0f /* + (float)SEX(67)*0.01f */
	    );
	
	if(lure_mode != LURE_MODE_ACTION ||
	   this->timer[0] == 0 ||
	   lure_pos.y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 5.0f || /* 上に行きすぎ */
	   sqrtf(lure_pos.x*lure_pos.x +
		 lure_pos.z*lure_pos.z) > 800.0f /* 岸に行きすぎ ？*/
#if 0	   
	   fabsf(lure_pos.x)  > 800.0f/* +KAZ(47) */ || /* 岸に行きすぎ ？*/
	   fabsf(lure_pos.z)  > 800.0f/* +KAZ(47) */
#endif	   
	    ) { /* 他の奴に先に食われた？ */
	    this->move_mode = this->move_mode_S;
	    this->timer[0] = 0;
	   
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 2000.0f;
/* 	    break; */    /* ダブルヒットの可能性をあえて入れよう */
	    break; /* やっぱりやめ  */
	}
	
        if(rg < 10.0f/*  + KAZ(26) */) { /* 食った？ */
	    if(lure_pos.y >  /* 水面？ */
	       (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy -10.0f) {
		Actor_SE_set((Actor *)this, NA_SE_PL_JUMP_OUT_WATER); /* SE */
		Na_StartSystemSe_F(NA_SE_PL_CATCH_BOOMERANG);	/* <SE> */
	    }
	    fish_sibuki_set(this, game_play, 0);
	    
	    this->move_mode = FISH_HIT_LURE;
	    
	    this->fwork[ANIME_SPD] = 1.2f;
	    this->fwork[ANIME_SCALE] = 5000.0f;
	    
	    this->timer[1] = 150;
	    this->timer[0] = 0;
	    this->timer[2] = 0;
	    this->timer[3] = 120; /* すぐにジャンプしない */

	    lure_mode = LURE_MODE_FISHON; /* ヒット！ */
	    hit_fish_actor = this;
	
	    if(lure_type == LURE_TYPE_WORM) {
		lure_hook_time = 30;
		vib_time = 100;
		RUMBLE_ENTRY_FORCE2(60/* +KAZ(52) */, 90, 10, 0.0f);	/* 振動セット */
	    } else {
		lure_hook_time = 30;
		vib_time = 40;
		RUMBLE_ENTRY_FORCE2(180, 90, 10, 0.0f);	/* 振動セット */
	    }
	    lure_hook_up = 0;
	    lure_hook_power = 100; /* 針掛りの度合い */
	    fish_fight_time = 0; /* 格闘時間 */
#if 0	    
	    Na_StopBgm(30);  /*  SE BGM */
#endif	    
	}
	break;
	
    case FISH_HIT_LURE: /* ヒット!! */
	thisx->cull_z = 1200.0f/*  + KAZ(62) */;
	thisx->cull_r = 200.0f/*  + KAZ(62) */;
/*     case 5: */
	fish_fight_time ++;
	
PRINTF("HIT FISH %dcm\n",(u8)this->size);	
	
	adds(&this->work[MOUSE_OPEN],
	     11000,
	     4,
	     3000);
	
	hit_fish_actor = this;
	
	adds(&pla->actor.shape.angle.sy,
	     (short)(this->actor.player_angle_y+0x8000),
	     5,
	     0x500);

	if(lure_hook_up == 0) { /* わーむ飲み込み時間？ */
	    if(worm_eat < 20 && !(lure_count & (0x03/*  + KAZ(3) */))) {
		worm_eat ++;
	    }
	}
	
	if(lure_hook_time &&
	   lure_hook_up == 0) {  /* チャンス？ */
	    if((Pad_stick_y() < -50 &&
		old_stick_y > -40) ||
	       Pad_on_trigger(REEL_BUTTON)
		) { /*フッキング？*/
		float vib_p;
/*	    if(Pad_push_also(REEL_BUTTON)) { */
		if(Pad_stick_y() < -50)  { /* 瞬間向き変化 */
		    float yowa;
		    yowa = 40.0f - (this->size - 30.0f)*1.333333f;
		    
		    if(yowa > 0.0f) {
			this->yowari = (u8)yowa;
			this->yowari_ya = (short)(this->actor.player_angle_y - this->actor.shape.angle.sy);
			this->yowari_p = 1;
		    }
		}

		this->fwork[ANIME_SPD_S] = 1.7f /* + (float)KAZ(38)*0.1f */;
		this->fwork[ANIME_SCALE_S] = 7000.0f /* + KAZ(39)*1000.0f */; /* 一瞬ビビル！ */
		
		lure_hook_up = 1;               /* ヒット！！！ */
		
		Na_StartBgm(NA_BGM_ENEMY);     /* BGM  */
		lure_bgm_time = 0;

		if(this->kind == FISH_KIND_SNAKEHEAD) {
		    vib_p = 120.0f + this->size * 3.0f;
		} else {
		    vib_p = 120.0f + this->size * 2.0f;
		}
		if(vib_p > 255.0f)
		    vib_p = 255.0f;
		
		RUMBLE_ENTRY_FORCE2((u8)vib_p, 40*3, 5, 0.0f);	/* 振動セット */
		
		vib_time = 40;
		
		rod_hooking_impact = 10/*  + NS1(49) */;
#if 0		
		line_tensyon = 5; /* ライン張ろう！ */
#endif
		Na_StartSystemSe_F(NA_SE_IT_FISHING_HIT);	/* <SE> */
/* COLOR_BLUE(); */
/* PRINTF("  ひっと！！！！！\n"); */
/* PRINTF("  ひっと！！！！！\n"); */
/* PRINTF("  ひっと！！！！！\n"); */
/* COLOR_NORMAL(); */
	    }
	}
/*	
	BREG(0) = this->timer[0];
	BREG(1) = this->timer[1];
	BREG(2) = this->timer[2];
	BREG(3) = this->timer[3];
	BREG(4) = (short)this->target_pos.y;
	*/
	if(this->actor.world.position.y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
	    u16 rum_time;
	    /* 水中？ */
	    if(this->timer[1] > 30) { /* 引っ張る？ */
		rum_time = 0x07;
	    } else {
		rum_time = 0x0f;
	    }

	    if(!(this->work[FS_TIME] & rum_time)) {
		if(rnd() < 0.75f && vib_time == 0) {
		    float power;
		    
		    if(this->size >= 70.0f) { /* 大きさで振動かえる */
			power = 255.0f;
		    } else if(this->size >= 60.0f) {
			power = 230.0f;
		    } else if(this->size >= 50.0f) {
			power = 200.0f;
		    } else if(this->size >= 40.0f) {
			power = 170.0f;
		    } else {
			power = 140.0f;
		    }

		    if(rum_time == 0x0f) { /* 弱い引き？ */
			power *= 0.75f;
		    }
		    
		    RUMBLE_ENTRY_FORCE2((u8)power, (short)rnd_f(5.0f)+10, 5/* +KAZ(78) */, 0.0f);	/* 振動セット */
		}
	    }

	    if(this->timer[1] > 30) { /* 引っ張る？ */
/*		
		this->fwork[ANIME_SPD] = 1.4f;
		this->fwork[ANIME_SCALE] = 5000.0f;
		*/	
		if(this->timer[0] == 0) {
		    u16  check_count;
/*		    float tya = atanf_table(-this->actor.world.position.z , -this->actor.world.position.x);*/
		    
		    mae.x = 0.0f;
		    mae.y = 0.0f;
		    mae.z = 200.0f * (1.0f /* + SEX(38) */);


		    for(check_count = 0;check_count<100;check_count++) {
			Matrix_rotateY(
			    /*rnd_fx(F_PI*0.75f) + tya, SET_MTX);*/
			    rnd_fx(F_PI*0.75f) + (float)(this->actor.player_angle_y+0x8000)/32768.0f*F_PI , SET_MTX);
			Matrix_Position(&mae, &ato); /*  */
		    
			this->target_pos.x = this->actor.world.position.x + ato.x;
			this->target_pos.z = this->actor.world.position.z + ato.z;

			if((this->target_pos.x*this->target_pos.x+this->target_pos.z*this->target_pos.z) <
			   750.0f*750.0f) { /* なるべく岸際には行かないように */
			    break;
			}
		    }
		    if(rnd() < 0.1f && this->timer[3] == 0) { /* ジャンプ？ */
			u8 power;
			if(this->size >= 60.0f) {
			    power = 255;
			} else if(this->size >= 50.0f) {
			    power = 200;
			} else {
			    power = 180;
			}
			
			RUMBLE_ENTRY_FORCE2(power, 30*3, 2, 0.0f);	/* 振動セット */
			
			this->timer[0] = 20/* +SEX(80) */;
			this->timer[1] = 100;
			this->timer[2] = 20/* +SEX(81) */;
			this->timer[3] = 100/* +SEX(84) */; /* 連続防止 */
			this->target_pos.y = 300.0f/* +SEX(82) */;
#if 0			
			RUMBLE_ENTRY_FORCE2(255, 30, 2, 0.0f);	/* 振動セット */
#endif			
			vib_time = 40;
			lure_hook_power = 20 + (short)rnd_f(30.0f); /* ジャンプ後はばれやすい */
		    } else {
			this->timer[0] = 3 /* + SEX(49)  */+ (short)rnd_f(10.0f);
			this->timer[2] = 0;
			this->target_pos.y = -70.0f - rnd_f(70.0f + 80.0f /* + SEX(57) */)/*  + BREG(54) */;
/*			this->skeleton.anime_frame_speed = 2.0f;*/
		    }
		}
		if(this->timer[2]) { /* ジャンプへ？ */
		    hit_power = 0.0f;
		    
		    this->fwork[ANIME_SPD] = 1.6f;
		    this->fwork[ANIME_SCALE] = 6000.0f;
		    
		    add_calc2(&this->actor.speedF,
			      7.5f /* + (float)SEX(83) */,
			      1.0f,
			      1.0f /* + (float)SEX(84)*0.01f */
			);
		    
		    adds(&this->work[MOUSE_OPEN],
			 20000,
			 2,
			 4000);
		} else {
		    if(lure_hook_up == 0 && /* フッキングまだ？ */
		       lure_type == LURE_TYPE_WORM) { /* わーむくわえたまま？ 違和感なし ！*/
			this->fwork[ANIME_SPD] = 1.0f;
			this->fwork[ANIME_SCALE] = 2000.0f;
	    
			add_calc2(&this->actor.speedF,
				  3.0f /* + (float)SEX(51) */,
				  1.0f,
				  0.2f /* + (float)SEX(52)*0.01f */
			    );
		    } else {
			this->fwork[ANIME_SPD] = 1.4f;
			this->fwork[ANIME_SCALE] = 5000.0f;
			
			add_calc2(&this->actor.speedF,
				  5.0f /* + (float)SEX(66) */,
				  1.0f,
				  0.5f /* + (float)SEX(67)*0.01f */
			    );
		    }
		    if(this->kind == FISH_KIND_BASS) {
			hit_power = 1.0f - this->size * 0.00899f;
		    } else {
			hit_power = 1.0f - this->size * 0.00899f * 1.4f;
		    }
		}
	    } else { /* 休憩 */
		if(!(this->timer[1] & 0x0f) &&
		   Pad_push_also(REEL_BUTTON)) { /* 向きを釣り人へ */

		    if(!(this->size >= 60.0f &&
			 fish_fight_time < 2000)) { /* 60overはしばらくしないと向きかえない */
			this->yowari = 15 + (short)rnd_f(30);
			this->yowari_ya = (short)(this->actor.player_angle_y - this->actor.shape.angle.sy);
#if 0			    
			this->yowari_ya = (short)(/* this->actor.player_angle_y + */
						  0x8000 + (short)rnd_fx((float)0x4000));
#endif			
		    }
		}
		this->fwork[ANIME_SPD] = 1.0f;
		this->fwork[ANIME_SCALE] = 4500.0f;
		
		if(this->kind == FISH_KIND_BASS) {
		    hit_power = 1.3f - this->size * 0.00899f;
		} else {
		    hit_power = 1.3f - this->size * 0.00899f * 1.4f;
		}
		
		add_calc2(&this->actor.speedF,
			  2.0f /* + (float)SEX(66) */,
			  1.0f,
			  0.5f /* + (float)SEX(67)*0.01f */
		    );
/*		this->skeleton.anime_frame_speed = 1.0f;*/
		
		if(this->timer[1] == 0) {
		    this->yowari =0;
		    
		    if(fish_fight_time < 2000) {
			this->timer[1] = (short)rnd_f(50.0f) + 50;
		    } else if(fish_fight_time < 3000) { /* 弱った？ */
			this->timer[1] = (short)rnd_f(20.0f) + 30;
		    } else {
			this->timer[1] = (short)rnd_f(10.0f) + 25;
		    }
		}
	    }
	}

	if(CIC_ERROR) { /* CIC 不可 ? */ 
 	    hit_power = 0.0f; /* 重い！！ */
	}
#if 0	
	if(Pad_stick_y() < -50 &&
	   old_stick_y > -30) { /* 竿強引に引かれた？ */
	    float check_s = 45.0f;
	    if(AGE == 1) { /* 5歳 */
		check_s = 35.0f;
	    }
	    if(this->size < check_s) { /* 子バスは弱いから,, */
		this->hikiyose_power = 10; /* 引き寄せられる */
		
		this->yowari = 5 + (short)rnd_f(20);
		this->yowari_ya = (short)(/* this->actor.player_angle_y + */
					  0x8000 + (short)rnd_fx((float)0x4000));
	    }
	}
#endif	
	/* 竿を曲げる */
	if(lure_hook_up || lure_type != LURE_TYPE_WORM) {
	    if(this->actor.speedF < 3.0f) {
		if(lure_count & 0x8) {
		    ato.x = -0.8f /* + (float)NS1(57)*0.01f */;
		} else {
		    ato.x = -0.75f /* + (float)NS1(57)*0.01f */;
		}
	    } else {
		if(lure_count & 0x4) {
		    ato.x = -0.9f /* + (float)NS1(58)*0.01f */;
		} else {
		    ato.x = -0.85f/*  + (float)NS1(58)*0.01f */;
		}
	    }

	    add_calc2(&rod_base_curvX,
		      35.0f,
		      0.1f,
		      3.5f /* + (float)NS1(56)*0.01f */);
	    
	    add_calc2(&rod_curvX3,
		      ato.x,
		      0.3f,
		      0.1f /* + (float)NS1(54)*0.001f */);
	}
    /* 口の位置計算のみ */
#if 0	
	Matrix_translate(this->actor.world.position.x,
			 this->actor.world.position.y,
			 this->actor.world.position.z,    SET_MTX);
	
	Matrix_rotateY( (float)(this->actor.shape.angle.sy + this->work[FISH_YA])/32768.0f*F_PI ,  MULT_MTX);
	Matrix_rotateX( (float)(this->actor.shape.angle.sx + this->work[FISH_XA])/32768.0f*F_PI ,  MULT_MTX);
	Matrix_rotateZ( (float)(this->actor.shape.angle.sz + this->work[FISH_ZA])/32768.0f*F_PI ,  MULT_MTX);
	Matrix_scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MULT_MTX);
	
	Si2_draw_SV(game, (Rigid_ModelPointer *)this->skeleton.list,
		    this->skeleton.now_joint,
		    this->skeleton.model_num,
		    fish_draw_sub,
		    fish_draw_sub2,
		    this);
#endif	
	line_pos[LINE_MAX_JOINT-1] = this->pl_catch_pos; /* 口の位置 */

	mae.x = line_pos[LINE_MAX_JOINT-1].x - line_pos[LINE_MAX_JOINT-2].x;
	mae.y = line_pos[LINE_MAX_JOINT-1].y - line_pos[LINE_MAX_JOINT-2].y;
	mae.z = line_pos[LINE_MAX_JOINT-1].z - line_pos[LINE_MAX_JOINT-2].z;

/* 	PRINTF("HARI   %f\n",sqrtf(mae.x*mae.x + mae.y*mae.y + mae.z*mae.z)); */
/* 	PRINTF("SPEEDF %f\n",this->actor.speedF); */
/* 	PRINTF("YS2 %f\n",this->fwork[FISH_Y_SPD]); *//* 空中ジャンプ用 */
	
	/* ライン延び切り？ */
	if((mae.x*mae.x + mae.y*mae.y + mae.z*mae.z) > 20.0f*20.0f /* + KAZ(16) */)  {
/* 	    PRINTF("TENTION !!!!!!!!!!!!!!!!!!!!!!!!\n"); */
	    /* 寄せられる */
	    add_calc2(&this->actor.world.position.x,
		      line_pos[LINE_MAX_JOINT-2].x,
		      0.2f,
		      this->actor.speedF * 1.5f * 2.0f /* + KAZ(17) */
		);
	    add_calc2(&this->actor.world.position.y,
		      line_pos[LINE_MAX_JOINT-2].y,
		      0.2f,
		      this->actor.speedF * 1.5f * 2.0f * (float)(/* KAZ(18) + */ 5.0f)*0.1f
		);
	    add_calc2(&this->actor.world.position.z,
		      line_pos[LINE_MAX_JOINT-2].z,
		      0.2f,
		      this->actor.speedF * 1.5f * 2.0f/*  + KAZ(17) */
		);
	}
	
	if(Pad_push_also(REEL_BUTTON) ||
	   Pad_stick_y() < -30 
	    ) { /* 竿を立てるあるいはリールを巻くつどに針掛りの度合い増す */
	    if(lure_hook_power < 100)
		lure_hook_power ++;
	} else { /* 何もしたなかったら針掛りが浅くなる */
	    if(lure_hook_power)
		lure_hook_power --;
	}
	
	if(lure_mode < LURE_MODE_ACTION ||
	   (CIC_ERROR && fish_fight_time > 50) || /* CIC 不可のときはすぐバレル */
	   fish_fight_time >= 6000 || /* ５分続くとバレル */
	   (lure_hook_time == 0 && lure_hook_up == 0) || /* 合わせ失敗 */
	   lure_hook_power == 0 ||   /* 何もしないでほっといた */
	  /*  GREG(69)  || */
	   (!(lure_count  & 0x7f) &&
	    rnd() < 0.05f  &&
	    lure_type != LURE_TYPE_WORM
#if FS_DEBUG	    
	  &&   KAZ(69) == 0
#endif	    
	       )) { /* バレル */

	    fs_message_time = 20;
	    
	    if((lure_hook_time == 0 && lure_hook_up == 0)) { /* 合わせ失敗 */
		fs_message_no = 0x4081; /* 掛らなかった */

		/* うまい人にはいちいち言わないでいい */
		if((AGE == 1 && /* 子供でハートもらった後？ */
		    (HI_SCORE(HS_FISH) & SAVE_HEART_GET)) ||
		   (AGE != 1 && /* 大人でウロコもらった後？ */ 
		    (HI_SCORE(HS_FISH) & SAVE_UROKO_GET))
		    ) { 
		    fs_message_time = 0;
		}
	    } else {    /* しばらくしてからばれた */
		fs_message_no = 0x4082;
		RUMBLE_ENTRY_FORCE2(1, 3, 1, 0.0f);	/* 振動クリア */
		Na_StopBgm(10);  /*  SE BGM */
	    }
	    
	    this->move_mode = 
		this->move_mode_S = FISH_NORMAL_SWIM_1;
	    
	    this->wait_time = 10000;  /* しばらく底でうろうろ */
	    
	    this->not_eat_time = 500; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	    
	    this->timer[0] = 0;
	    
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 3000.0f;
	    
	    if(lure_mode == LURE_MODE_FISHON) /* ヒット中？ */
		lure_mode = LURE_MODE_ACTION; /* ヒット解除 */

//	    Na_StopBgm(30);  /*  SE BGM */
	    lure_bgm_time = 50;
	    
	    hit_power = 0.5f;
	    this->yowari =0;
	    break;
	}

#if 0
	if(this->actor.player_distance <  120.0f
#if FS_DEBUG	   
	   + KAZ(58)
#endif	   
	    ) { /* さかな接近？ */
	    if(Pad_push_also(REEL_BUTTON)) { /* 巻き取り？ */		 
		short sad;
		this->yowari = 3; /* 無理やり弱った体制 */
		if(game_play->game_frame_counter & 0x80) {
		    sad = 0x100;
		} else {
		    sad = -0x100;
		}
		this->yowari_ya = (short)(/* this->actor.player_angle_y + */
					  0x8000 + sad);
	    }
	}
#endif	
	if(this->actor.player_distance <  50.0f
#if FS_DEBUG	   
	   + KAZ(59)
#endif	   
	    ) { /* さかなゲット？ */
/*	if(line_cap >= (float)LINE_MAX_JOINT - 5.0f ) {*/
	    this->move_mode = FISH_CATCH;
	    this->timer[0] = 100 /* + KAZ(93) */;
	    pla->fishing_mode = FISHING_MODE_CATCH;
	    RUMBLE_ENTRY_FORCE2(1, 3, 1, 0.0f);	/* 振動クリア */

	    fish_catch_count ++;

	    Demo_play_start(game_play, &game_play->demo_play);
	    
	    demo_mode = 100;
	    demo_xa = 45.0f;

	    lure_mode = LURE_MODE_CATCH;
/* 	    line_tensyon = 5; */
	    
	    this->fwork[ANIME_SPD] = 1.0f;
	    this->fwork[ANIME_SCALE] = 500.0f;
	    this->fwork[ANIME_SCALE_S] = 5000.0f/*  + KAZ(75) */;
	    
	    if(this->actor.world.position.y <=
	       (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
		
		fish_water_se_set(this, SE_WATER_OUT);
		fish_sibuki_set(this, game_play, 1);
	    }
	    goto catch_demo;
	}
	break;

    catch_demo:
    case FISH_CATCH:/* 取り込まれ */
/*     case 6:  */
/* PRINTF(" This fish range is %d cm !!!!!\n",(short)this->size); */
	adds(&this->work[MOUSE_OPEN],
	     11000,
	     2,
	     4000);
	
	add_calc2(&demo_xa,
		  15.0f,
		  0.05f,
		  0.75f);
	
	mae.x = 0.0f /* + KAZ(36) */ + demo_xa;

	if(AGE != 1) { /* 17歳 */
	    mae.y = 30.0f /* + KAZ(37) */;
	    mae.z = 80.0f /* + KAZ(38) */ - 25.0f;
	} else {
	    mae.y = 30.0f /* + KAZ(37) */ - 20.0f;
	    mae.z = 80.0f /* + KAZ(38) */ - 30.0f;
	}
	Matrix_rotateY(	(float)pla->actor.shape.angle.sy/32768.0f*F_PI, SET_MTX);
	Matrix_Position(&mae, &demo_eye); /*  */

	demo_eye.x += pla->actor.world.position.x;
	demo_eye.y += pla->actor.world.position.y;
	demo_eye.z += pla->actor.world.position.z;

	demo_way = pla->actor.world.position;
	if(AGE != 1) { /* 17歳 */
	    demo_way.y += /* KAZ(40)+ */30.0f + 10.0f;
	} else {
	    demo_way.y +=/*  KAZ(40)+ */30.0f - 5.0f;
	}
	
	if(this->timer[0] == 90 /* + KAZ(93) */) {
#if 01	    
	    Na_StartBgm(NA_BGM_HEART_GET);  /* BGM  */
#else	    
	    Na_StartFanfare(NA_BGM_HEART_GET);
#endif	    
	    fs_message_time = 40;

	    if(this->kind == FISH_KIND_BASS) {
		FishRangeForMessage = (u16)this->size;
		
		if(FishRangeForMessage >= 75) {
		    fs_message_no = 0x409f; /* デカイ！？？cm */
		} else if(FishRangeForMessage >= 50) {
		    fs_message_no = 0x4091; /* まあまあ？？cm */
		} else {
		    fs_message_no = 0x4083; /* 多分？？cm */
		}
	    } else {
		FishRangeForMessage = (u16)(this->size * 2.0f);
		fs_message_no = 0x4099; /* へんな魚釣った！？ */
	    }
	    
	    this->demo_mess_sel = 0;
	}

	this->work[FISH_XA] = -0x4000;
	this->actor.shape.angle.sy = pla->actor.shape.angle.sy /* + 0x1000 * NS1(29) */ + 0x5000;
	this->actor.shape.angle.sx = 
	    this->actor.shape.angle.sz = 
	    this->work[FISH_YA] = 
	    this->work[FISH_ZA] =
	    this->work[ANIME_YA2] = 0x00;
#if 0	
	adds(&this->actor.shape.angle.sy,
	     pla->actor.shape.angle.sy /* + 0x1000 * NS1(29) */ + 0x5000,
/*			     0,*/
	     2,
	     5000/*  + NS1(30) */
	     );
	adds(&this->actor.shape.angle.sx,
	     0,
	     2,
	     5000 /* + NS1(30) */
	     );
	adds(&this->actor.shape.angle.sz,
	     0,
	     2,
	     5000/*  + NS1(30) */
	     );
	
	adds(&this->work[FISH_XA],
	     -0x4000 /* + (0 + NS1(31)) */, 
	     2,
	     5000 /* + NS1(30) */
	     );

	adds(&this->work[FISH_YA],
	     0x4000 * (0 /* + NS1(32) */), 
	     2,
	     5000/*  + NS1(30) */
	     );
	
	adds(&this->work[FISH_ZA],
	     0x4000 * (0 /* + NS1(33) */), 
	     2,
	     5000/*  + NS1(30) */
	     );
	     
	adds(&this->work[ANIME_YA2],
	     0,
	     5,
	     2000);
#endif	

	mae.x = 0.0f /* + KAZ(20) */ + 4.0f;
	mae.y = -5.0f /* + KAZ(21) */ - 10.0f + 5.0f;
	mae.z = 5.0f /* + KAZ(22) */;
	
	Matrix_Position(&mae, &ato); /*  */
	
	add_calc2(&this->actor.world.position.x,
		  pla->parts_pos[LINK_PARTS_R_HAND].x + ato.x,
		  1.0f,
		  6.0f/* +KAZ(91) */);
	add_calc2(&this->actor.world.position.y,
		  pla->parts_pos[LINK_PARTS_R_HAND].y + ato.y,
		  1.0f,
		  6.0f/* +KAZ(92) */);
	add_calc2(&this->actor.world.position.z,
		  pla->parts_pos[LINK_PARTS_R_HAND].z + ato.z,
		  1.0f,
		  6.0f/* +KAZ(92) */);
	
	line_cap = (float)LINE_MAX_JOINT - 70.0f - (/* KAZ(89) */-58.0f);
	    
	if(this->timer[0] <= 50) { /* アニメエンド？ */
	    switch(this->demo_mess_sel) {
	    case 0:
		if ( message_check( &( game_play->message ) ) == 4 ||
		     message_check( &( game_play->message ) ) == 0) {	/* 原選択待ち？ */
		    if ( pad_on_check(game_play) ) {
			message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
			
			if(game_play->message.sel_pnt == 0) { /* キープ？ */
			    if(my_record == 0.0f) { /* 最初の一匹？ */
				my_record = this->size; /* 自分の記録 */
				my_fish_kind = this->kind;
				use_lure = lure_type;
				Actor_delete((Actor *)this); /* 消そう */
			    } else {
				if(this->kind == FISH_KIND_BASS &&
				   my_fish_kind == FISH_KIND_BASS &&
				   (short)my_record > (short)this->size) { /* バスの場合前の方が大きい？ */
				    this->demo_mess_sel = 1;
				    this->timer[0] = 60;
				    message_set(game_play, 0x4098, NULL);  /* まてよ？ */
				} else {
				    float sv;
				    u8    svk;
				    sv = my_record;
				    svk = my_fish_kind;
				    my_record = this->size;  /* 自分の記録 */
				    my_fish_kind = this->kind;
				    use_lure = lure_type;
				    this->size = sv;  /* まえの記録と交換 */
				    this->kind = svk; /* まえの記録と交換 */
				}
			    }
			}
			if(this->demo_mess_sel == 0) {
			    lure_mode = LURE_MODE_READY;  /* ルアー離す */
			}
		    }
		}
		break;
	    case 1:
		if ( message_check( &( game_play->message ) ) == 4 ||
		     message_check( &( game_play->message ) ) == 0) {	/* 原選択待ち？ */
		    if ( pad_on_check(game_play) ) {
			message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
			
			if(game_play->message.sel_pnt == 0) { /* やっぱりやめる */
			} else { /* それでもキープ */
			    float sv;
			    u8    svk;
			    sv = my_record;
			    svk = my_fish_kind;
			    my_record = this->size;  /* 自分の記録 */
			    use_lure = lure_type;
			    this->size = sv; /* まえの記録と交換 */
			    this->kind = svk; /* まえの記録と交換 */
			}
			lure_mode = LURE_MODE_READY;  /* ルアー離す */
		    }
		}
		break;
	    }
	}
	
	if(lure_mode == LURE_MODE_READY) { /* ルアー離した？ */
	    if(this->actor.move_proc != NULL) { /* 消えてない？ */
		this->move_mode = 
		    this->move_mode_S = FISH_NORMAL_SWIM_1; /* 今は逃がす */
		this->wait_time = 10000;
		this->not_eat_time = 500; /* しばらく食わない */
		this->timer[1] = 50; /* あわてる */
		
		this->timer[0] = 0;
		
		this->fwork[ANIME_SPD] = 1.0f;
		this->fwork[ANIME_SCALE] = 2000.0f;

		Skeleton_Info_dt(&this->skeleton, game);
		
		if(this->kind == FISH_KIND_BASS) {
		    Skeleton_Info2_SV_ct(game, &this->skeleton,
					 &basu_mdl_info,
					 &basu_soft_anim_tbl_info);
		    
		    Skeleton_Info2_init_standard_repeat_morf(
			&this->skeleton,
			&basu_soft_anim_tbl_info,
			0.0f
			);
		} else {
		    Skeleton_Info2_SV_ct(game, &this->skeleton,
					 &nz_namazu_mdl_info,
					 &nz_namazu_soft_anim_tbl_info);
		    
		    Skeleton_Info2_init_standard_repeat_morf(
			&this->skeleton,
			&nz_namazu_soft_anim_tbl_info,
			0.0f
			);
		}
 	    }
	    line_G = 20.0f /* + KAZ(81) */ + 500.0f;
	    line_cap = (float)LINE_MAX_JOINT - 5.0f/*  - KAZ(80) */;
	    
	    Na_StopBgm(10);  /*  SE BGM */
	    lure_bgm_time = 20;
	    
	    demo_mode = 3;
	}
	break;

    case FISH_FEEDING_MINNOW:/* 子魚追う */	
/*     case 7: */
	this->power_move = 50;
	
	angle_ad = 5 /* + SEX(64) */;
	this->angle_sp = 0x3000 /* + SEX(65)*0x1000 */;

	if(this->actor.arg_data <= 103) {
	    this->target_pos = minnow[this->actor.arg_data - 100].pos;
	    minnow_panic = 1;
	} else if(this->actor.arg_data <= 107) { /* 104~107 */
	    this->target_pos = minnow[this->actor.arg_data - 104 + 20].pos;
	    minnow_panic = 2;
	} else {   /* 108~end */
	    this->target_pos = minnow[this->actor.arg_data - 108 + 40].pos;
	    minnow_panic = 3;
	}
	
	add_calc2(&this->actor.speedF,
		  5.0f /* + (float)SEX(66) */,
		  1.0f,
		  1.0f /* + (float)SEX(67)*0.01f */
	    );
	
        if(rg < 20.0f /* + KAZ(26) */) {
	    adds(&this->work[MOUSE_OPEN],
		 20000,
		 2,
		 4000);
	    
	    if(this->timer[2] == 0) {
		if(fish_sibuki_set(this, game_play, 0)) {
		    fish_water_se_set(this, (u8)rnd_f(1.99f));
		    
		    this->timer[2] = 20 + (short)rnd_f(20.0f);
		}
	    }
	}
	
	if(this->timer[3] == 0) {
	    this->move_mode   = FISH_STRUCT_WAIT_1;
	    this->move_mode_S = FISH_STRUCT_WAIT_1;  /* もどすモード */
	    break;
	}
	
	lure_find_check(this, pad);  /* ルアー発見？ */
	
	if(this->actor.player_distance < (100.0f/*  + KAZ(46) */) * pl_dis) { /* 釣り人接近 ？*/
	    this->move_mode_S = 
		this->move_mode = FISH_NORMAL_SWIM_1;    /* 深みへ逃げる */
	    this->wait_time = 500;
	    this->not_eat_time = 200; /* しばらく食わない */
	    this->timer[1] = 50; /* あわてる */
	}
	break;
    }


/* 共通処理 */
    adds(&this->work[HIRE_ANG], /* むなヒレヒラヒラ */
	 (short)(sin_s(this->work[FS_TIME] * 0x1000) * 5000.0f + 5000.0f),
	 2,
	 2000);
	
    if(this->move_mode != 6) { /* 取り込まれ以外 */
/*	adds(&this->work[HIRE_ANG],
	     0x00,
	     5,
	     1000);
	     */
	if(this->actor.world.position.y >  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) { /* 空中？ */
	    this->fwork[ANIME_SPD] = 1.5f;
	    this->fwork[ANIME_SCALE] = 5000.0f;
	    
	    adds(&this->work[ANIME_YA2],
		 0,
		 5,
		 2000);
#if 0	
	    if(lure_count & 0x40) {
		za =  0x4000; /* 空中は平打ち */
	    } else {
		za = -0x4000; /* 空中は平打ち */
	    }
#endif
/*	
	xa2 = this->work[FISH_XA_S];
	ya2 = this->work[FISH_YA_S];
	za = this->work[FISH_ZA_S];*/
	    xap = 
		yap = 
		zap = 3 /* + SEX(75) */;
	    xad =  
		yad =  
		zad = 0x2000 /* + SEX(76)*0x100 */; 
	    
	    this->fwork[FISH_Y_SPD] -= 1.0f;/* 空中ジャンプ用 */
/*	Actor_position_move((Actor *)this); */
	    this->timer[2] = 0; /* ジャンプパワー解除 */
	} else {
	    add_calc0(&this->fwork[FISH_Y_SPD],/* 空中ジャンプ用 */
		      1.0f,
		      2.0f);
	    
/* 	    this->fwork[FISH_Y_SPD] = 0; */
/*	    
	    this->work[FISH_XA_S] = 
		this->work[FISH_YA_S] = 
		this->work[FISH_ZA_S] = 0x00;
		*/
	    
	    if(this->move_mode != FISH_SNAKEHEAD_WAIT &&
	       this->move_mode != FISH_SNAKEHEAD_AIR &&
	       this->move_mode != FISH_SNAKEHEAD_AIR_2) {
		this->work[FISH_XA_S] = 0x00;
	    }
	    this->work[FISH_YA_S] = 
		this->work[FISH_ZA_S] = 0x00;
	    
	    xap = 
		yap = 
		zap = 4;
	    
	    xad = 
		yad = 
		zad = 0x2000;
	    
	    tya = adds2(&this->actor.world.angle.sy,
			ya,
			angle_ad,
			(short)this->angle_sp);
 
	    tya = (short)((float)tya * (3.0f /* + (float)KAZ(62)*0.1f */));
/* 	    tya = (tya << (1 + KAZ(62))); */
	    
	    adds(&this->actor.world.angle.sx,
		 xa,
		 angle_ad,
		 (short)(this->angle_sp * 0.5f));

	    /* 急激なターンで体曲げる */

	    if(tya > 8000 /* + KAZ(19) */) {
		tya = 8000 /* + KAZ(19) */;
	    } else if(tya < -8000 /* - KAZ(19) */) {
		tya = -8000 /* - KAZ(19) */;
	    }
	    
	    if(this->actor.speedF >= 3.2f) { /* 攻撃時は急激 */
		adds(&this->work[ANIME_YA2],
		     tya,
		     2 /* + GREG(80) */,
		     20000/* +GREG(78) */);
	    } else {
		adds(&this->work[ANIME_YA2],
		     tya,
		     3 /* + GREG(80) */,
		     3000/* +GREG(78) */);
	    }

#if 0	    
	    if(ABS(tya) < 0x2000 + KAZ(62)*0x100 ||
	       this->angle_sp < 300.0f ||
	       this->actor.speedF <= 0.5f) {
		adds(&this->work[ANIME_YA2],
		     0,
		     5,
		     2000+GREG(77));
	    } else {
		if(tya > 0) {
		    tya -= 0x2000 + KAZ(62)*0x100;
		} else {
		    tya += 0x2000 + KAZ(62)*0x100;
		}
/*		tya /= (2+GREG(79));*/
		    
		if(tya > 8000 + KAZ(19)) {
		    tya = 8000 + KAZ(19);
		} else if(tya < -8000 - KAZ(19)) {
		    tya = -8000 - KAZ(19);
		}

		if(this->actor.speedF >= 3.2f) { /* 攻撃時は急激 */
		    adds(&this->work[ANIME_YA2],
			 tya,
			 2 + GREG(80),
			 20000+GREG(78));
		} else {
		    adds(&this->work[ANIME_YA2],
			 tya,
			 3 + GREG(80),
			 3000+GREG(78));
		}
	    }
#endif
	    Actor_position_speed_set_XY((Actor *)this);
	}
	Actor_position_move((Actor *)this);
	this->actor.world.position.y += (this->fwork[FISH_Y_SPD] * 1.5f); /* 空中ジャンプ用 */
	
	if(this->yowari) { /* hit時サカナが弱ったときの向き制御 */
	    this->work[FISH_YA_S] = this->yowari_ya;
	    this->yowari --;
	    if(this->yowari_p) {
		yap = 5;
		yad = 0x4000;
	    } else {
		yap = 10;
		yad = 0x800;
	    }
	    this->work[FISH_XA_S] = (short)((/* KAZ(34) */-5)*0x100 - this->actor.shape.angle.sx);
	    xap = 5;
	    xad = 0x4000;
	} else {
	    this->yowari_p = 0;
	}

#if 0
	if(KAZ(35)) {
	    this->actor.shape.angle.sx = KAZ(37)*0x100;
	    this->work[FISH_YA_S] = (short)(this->actor.player_angle_y - this->actor.shape.angle.sy);
	    this->work[FISH_XA_S] = (short)(KAZ(34)*0x100 - this->actor.shape.angle.sx);
	    if(KAZ(36)) {
		this->work[FISH_XA_S] *= -1;
	    }
	}
#endif
	adds(&this->work[FISH_XA],
	     this->work[FISH_XA_S],
	     xap,
	     xad
	     );

	adds(&this->work[FISH_YA],
	     this->work[FISH_YA_S],
	     yap,
	     yad
	     );
	
	adds(&this->work[FISH_ZA],
	     this->work[FISH_ZA_S],
	     zap,
	     zad
	     );
#if 0
	if(this->move_mode != FISH_SNAKEHEAD_WAIT &&
	   this->move_mode != FISH_SNAKEHEAD_AIR &&
	   this->move_mode != FISH_SNAKEHEAD_AIR_2) {
	    this->work[FISH_XA_S] = 0x00;
	}
	this->work[FISH_YA_S] = 
	    this->work[FISH_ZA_S] = 0x00;
#endif	
	if(this->actor.speedF <= 0.5f) { /* とまってたら平行に */
	    adds(&this->actor.shape.angle.sx,
		 0,
		 10/*  + GREG(57) */,
		 this->work[ANGLE_SX_SP]);
	    
	    adds(&this->work[ANGLE_SX_SP],
		 0x500 /* + GREG(58)*0x10 */,
		 1,
		 0x20);
	} else {
	    adds(&this->actor.shape.angle.sx,
		 -this->actor.world.angle.sx,
		 10,
		 0x1000);
	    this->work[ANGLE_SX_SP] = 0;
	}
	this->actor.shape.angle.sy = this->actor.world.angle.sy;
	
	if(this->move_mode != FISH_SNAKEHEAD_WAIT &&
	   this->move_mode != FISH_SNAKEHEAD_AIR &&
	   this->move_mode != FISH_SNAKEHEAD_AIR_2) { /* あまりよくない */
	    if(this->actor.world.position.y >  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy &&
	       this->actor.old_position.y <= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
		/* 水面から出た瞬間 */
		fish_sibuki_set(this, game_play, 1);
		
		fish_water_se_set(this, SE_WATER_OUT);
		
		this->fwork[FISH_Y_SPD] = this->actor.position_speed.y;/* 空中ジャンプ用 */
		this->actor.position_speed.y = 0.0f;
		this->work[FISH_ZA_S] = (short)(rnd_fx((float)0x8000));
/* 	    PRINTF("UP !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); */
	    } else if(this->actor.world.position.y <  (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy &&
		      this->actor.old_position.y >= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
		/* 水中に入った瞬間 */
		
		if(this->fwork[FISH_Y_SPD] < -5.0f) {/* 空中ジャンプ用 */
		    this->fwork[FISH_Y_SPD] = -5.0f;
		}
		this->actor.world.angle.sx = -4000;
		
		fish_sibuki_set(this, game_play, 1);
		this->bubble_time = 20;
		
		fish_water_se_set(this, SE_WATER_IN);
		
/* 	    PRINTF("DOWN !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); */
	    }
	}
	
	if(this->actor.world.position.y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy  &&
	   this->actor.world.position.y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 10.0f) { /* 波紋セット */
	    if((this->work[FS_TIME] & 0x01) == 0 &&
	       this->actor.speedF > 0.0f) {
		xyz_t pos;
		
		pos = this->actor.world.position;
		pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
		
		fs_hamon_ct(
		    &this->actor.camera_position,
		    (Fishing_Eff *)game_play->special_effect,
		    &pos,
		    80,
		    500,
		    150,
		    FISHING_EFF_SIZE-10
		    );
	    }
	}

	if(
	    this->actor.speedF > 0.0f || this->move_mode == FISH_HIT_LURE ) {
	    float ysp_save = this->actor.position_speed.y;
	    bg_ground_offset = this->size * 0.1f; /* 3.0f ~ 7.5f */
	
	    this->actor.world.position.y -= bg_ground_offset;
	    this->actor.old_position.y -= bg_ground_offset;

	    this->actor.position_speed.y = -1.0f;/*  無理やりGROUNDチェック */

	    Actor_BGcheck2(game_play,
			   (Actor *)this,
			   30.0f,			/* 壁チェック高さ */
			   30.0f/* +SEX(94) */,			/* 壁チェック半径 */
			   100.0f,			/* 天井チェック高さ */
			   BGCHECK_GROUND | BGCHECK_WALL | BGCHECK_RIPPLE_NOSET);	/* チェック情報 */

	    
	    this->actor.world.position.y += bg_ground_offset;
	    this->actor.old_position.y += bg_ground_offset;
	    this->actor.position_speed.y = ysp_save;
	
	    if(bitcheck(this->actor.environment_info, ENVIRONMENT_INFO_WALL) ) { 	/* 壁衝突？ */
		this->wall_hit = 20;
	    }
	    
#if /* FS_DEBUG */0
	    if(this->move_mode < 100) {
		if( (thisx->world.position.x*thisx->world.position.x + thisx->world.position.z*thisx->world.position.z) >
		    920.0f*920.0f) { /* 水範囲外？ */
		    PRINTF("environment 	%d\n",this->actor.environment_info);
		}
	    }
#endif	    
	    if(bitcheck(this->actor.environment_info, ENVIRONMENT_INFO_GROUND) ) { 	/* 床衝突？ */
		if(this->actor.world.position.y  >
		   (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
#if/*  FS_DEBUG */0
		   + KAZ(54)
#endif		   
		    ) {
		    this->fwork[FISH_Y_SPD] = 3.0f + rnd_f(3.0f);
		    this->actor.position_speed.x = this->actor.world.position.x * -0.003f;
		    this->actor.position_speed.z = this->actor.world.position.z * -0.003f;
#if 0		
		    Actor_SE_set((Actor *)this, NA_SE_PL_WALK_CONCRETE); /* SE */
#endif		
		    Actor_SE_set((Actor *)this, NA_SE_EV_FISH_LEAP); /* SE */
		    
		    fish_sibuki_set_S(this, game_play);
		    
		    if(rnd() < 0.5f) { /* ぺたんぺたん */
			this->work[FISH_ZA_S] = 0x4000;
		    } else {
			this->work[FISH_ZA_S] = -0x4000;
		    }
		    if(rnd() < 0.5f) { /* ぺたんぺたん */
			this->work[FISH_XA_S] = 0x000;
		    } else {
			this->work[FISH_XA_S] = 0x8000 + (short)(rnd_fx(32.0f));
		    }
		    
		    this->work[FISH_YA_S] = (short)(rnd_fx((float)0x4000));
/*	    this->skeleton.anime_frame_speed = 4.0f + SEX(87);*/
		    this->fwork[ANIME_SPD] = 1.0f;
		    this->fwork[ANIME_SCALE] = 5000.0f;
		    this->fwork[ANIME_SCALE_S] = 5000.0f;
		} else {
		    this->fwork[FISH_Y_SPD] = 0.0f;
		    
		    if(this->move_mode == FISH_HIT_LURE) {
			if(!(this->work[FS_TIME] & 0x01)) {
			    xyz_t epos;
			    
			    epos.x = this->actor.world.position.x + rnd_fx(10.0f/* +BREG(29) */);
			    epos.z = this->actor.world.position.z + rnd_fx(10.0f/* +BREG(29) */);
			    epos.y = this->actor.ground_y + 5.0f;
			    
			    fs_smoke_ct(
				&this->actor.camera_position,
				(Fishing_Eff *)game_play->special_effect,
				&epos,
				0.15f + this->size * 0.005f
#if 0			    
				1.0f -0.6f/*  + (float)BREG(28)*0.001f */
#endif			    
				);
			}
		    }
		}
	    }
	}
    }


    if(this->bubble_time) {
	short i;
	xyz_t pos;
	float size;
	size = 10.0f + this->size * 0.075f;
	
	this->bubble_time --;

	for(i=0;i<2;i++) {
	    pos.x = this->actor.world.position.x  + rnd_fx(size);
	    pos.y = this->actor.world.position.y  + rnd_fx(size);
	    pos.z = this->actor.world.position.z  + rnd_fx(size);
	    
	    fs_bubble_ct(
		&this->actor.camera_position,
		(Fishing_Eff *)game_play->special_effect,
		&pos,
		rnd_f(0.035f) + 0.04f,
		0
		);
#if 0	    
	    Effect_SS_Bubble_ct((Game *)game_play,
				&pos,
				0.0f,
				0.0f /* + BREG(45) */,
				0.0f /* + BREG(46) */,
				rnd_f(0.035f) + 0.04f /* + (float)BREG(47)*0.001f */
		);
#endif	    
	}
    }
}



#if 01
/*-----------------------------------------------------------------------
 *	表示特殊制御用関数
 *----------------------------------------------------------------------*/
static int fish_draw_sub(Game *game, int jyoint_no, Gfx **d, xyz_t *t, s_xyz *r, void *p)
{
/*     Game_play		*game_play = (Game_play *)game; */
    Fishing_actor	*this = (Fishing_actor *)p;
    t;
    p;
    game;
    *d;
#if 0    
    if( jyoint_no == KAZ(32) ) {
	if(!(game_play->game_frame_counter & 0x03)) {
	    *d = NULL;
	}
	r->sx += KAZ(33)*100;
	r->sy += KAZ(34)*100;
	r->sz += KAZ(35)*100;
    }
#endif    
#if 0
    if(jyoint_no == 10) {
	r->sz += 11000 - this->work[MOUSE_OPEN];
    } else if(jyoint_no == 2 ||
	      jyoint_no == 3 ||
	      jyoint_no == 4) {
	r->sy += this->work[ANIME_YA];
    } else if(jyoint_no == 11) { /* 右ひれ */
	r->sy -= this->work[HIRE_ANG];
    } else if(jyoint_no == 12) { /* 左ヒレ */
	r->sy += this->work[HIRE_ANG];
    } else if(jyoint_no == 7) {  /* 背ひれ */
	r->sy += this->work[HIRE_ANG2];
    }
#else
    if(jyoint_no == 10/*  + NS1(0) */ + 3) {
	r->sz += 11000 - this->work[MOUSE_OPEN];
    } else if(jyoint_no == 2 /* + NS1(1) */ ||
	      jyoint_no == 3 /* + NS1(2) */ /*||*/
	      /* jyoint_no == 4 + NS1(3)   */) {
	r->sy += this->work[ANIME_YA];
    } else if(jyoint_no == 4 /* + NS1(3) */) { /* おひれ */
	r->sy += this->work[TAIL_ANG];
    } else if(jyoint_no == 14 /* + NS1(4) */) { /* 右ひれ */
	r->sy -= this->work[HIRE_ANG];
    } else if(jyoint_no == 15 /* + NS1(5) */) { /* 左ヒレ */
	r->sy += this->work[HIRE_ANG];
    } else if(jyoint_no == 8 /* + NS1(6) */) {  /* 背ひれ */
	r->sy += this->work[HIRE_ANG2];
    } else if(jyoint_no == 9 /* + NS1(7) */) {  /* シリひれ */
	r->sy -= this->work[HIRE_ANG2];
    }
#endif

    return 0;
}
#endif

static void fish_draw_sub2(Game *game, int jyoint_no, Gfx **d, s_xyz *r, void *p)
{
    Fishing_actor	*this = (Fishing_actor *)p;
    game;
    d;
    r;

    if(jyoint_no == 10 + 3) {
/* 	static xyz_t fish_mouse_p = {500.0f, 500.0f, 0.0f}; */
/*	
	mouse_p.x += KAZ(36)*100;
	mouse_p.y += KAZ(37)*100;
	mouse_p.z += KAZ(38)*100;
	*/
	Matrix_Position(&fish_mouse_p, &this->pl_catch_pos); /* 口位置セット */
    }
}
/*-----------------------------------------------------------------------
 *	表示特殊制御用関数
 *----------------------------------------------------------------------*/
static int snake_draw_sub(Game *game, int jyoint_no, Gfx **d, xyz_t *t, s_xyz *r, void *p)
{
/*     Game_play		*game_play = (Game_play *)game; */
    Fishing_actor	*this = (Fishing_actor *)p;
    t;
    p;
    game;
    *d;
#if 0    
    if( jyoint_no == KAZ(32) ) {
	if(!(game_play->game_frame_counter & 0x03)) {
	    *d = NULL;
	}
	r->sx += KAZ(33)*100;
	r->sy += KAZ(34)*100;
	r->sz += KAZ(35)*100;
    }
#endif    
#if 0    
    if(jyoint_no == 1) {
	r->sy += this->work[ANIME_YA];
    }
#endif    
    if(jyoint_no == 3) {
	r->sy += this->body_ya[0];
    } else if(jyoint_no == 4) {
	r->sy += this->body_ya[1]/*  * (1.0f + (float)KAZ(57)*0.1f) */;
    } else if(jyoint_no == 5) {
	r->sy += this->body_ya[2]/*  * (1.0f + (float)KAZ(58)*0.1f) */;
    }
    return 0;
}

static void snake_draw_sub2(Game *game, int jyoint_no, Gfx **d, s_xyz *r, void *p)
{
    Fishing_actor	*this = (Fishing_actor *)p;
    game;
    d;
    r;

    if(jyoint_no == 11) {
	static xyz_t mouse_p = {500.0f, 500.0f, 0.0f};
/*	
	mouse_p.x += KAZ(16)*100;
	mouse_p.y += KAZ(17)*100;
	mouse_p.z += KAZ(18)*100;
	*/
	Matrix_Position(&mouse_p, &this->pl_catch_pos); /* 口位置セット */
    }
}

static void Fishing_actor_draw(Actor *thisx, Game *game)
{
    Fishing_actor	*this = (Fishing_actor *)thisx;
/*    Game_play		*game_play = (Game_play *)game;*/
    
    _texture_z_light_fog_prim(game->graph);

    Matrix_translate(thisx->world.position.x,
		     thisx->world.position.y,
		     thisx->world.position.z,    SET_MTX);
    
    Matrix_rotateY(
	(float)(thisx->shape.angle.sy + this->work[FISH_YA])/32768.0f*F_PI, MULT_MTX);
    Matrix_rotateX( (float)(thisx->shape.angle.sx + this->work[FISH_XA])/32768.0f*F_PI ,  MULT_MTX);
    Matrix_rotateZ( (float)(thisx->shape.angle.sz + this->work[FISH_ZA])/32768.0f*F_PI ,  MULT_MTX);
    
    Matrix_scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, MULT_MTX);

    if(this->kind == FISH_KIND_BASS) {
	Matrix_rotateY( (float)this->work[ANIME_YA]*(F_PI/32768.0f) - F_PI*0.5f, MULT_MTX);
	Matrix_translate(0.0f, 0.0f,
			 (float)this->work[ANIME_YA]*(float)(/* GREG(23)+ */10)*0.01f,
			 MULT_MTX);

	Si2_draw_SV(game, (Rigid_ModelPointer *)this->skeleton.list,
		    this->skeleton.now_joint,
		    this->skeleton.model_num,
		    fish_draw_sub,
		    fish_draw_sub2,
		    this);
    } else {
	Matrix_translate(0.0f, 0.0f, 3000.0f /* + NS1(85) */,	 MULT_MTX);
	Matrix_rotateY( (float)this->work[ANIME_YA]*(F_PI/32768.0f), MULT_MTX);
	Matrix_translate(0.0f, 0.0f, -3000.0f /* - NS1(85) */, MULT_MTX);
	
 	Matrix_rotateY( -F_PI*0.5f, MULT_MTX);
	Si2_draw_SV(game, (Rigid_ModelPointer *)this->skeleton.list,
		    this->skeleton.now_joint,
		    this->skeleton.model_num,
		    snake_draw_sub,
		    snake_draw_sub2,
		    this);
    }
}





/*-----------------------------------------------------------------------
 *	専用簡易障害物表示  （ループに無理があるが高速化は捨てがたい）
 *----------------------------------------------------------------------*/
static void ashi_obj_check(Fishing_Obj    *obj, xyz_t *pos)
{
    float x,z,rg;
    
    x = obj->pos.x - pos->x;
    z = obj->pos.z - pos->z;
    
    if((rg = sqrtf(x*x + z*z)) <= 20.0f /* + GREG(48) */) {
	obj->ang.y = atanf_table(z,x);
	add_calc2(&obj->ang.x,
		  (20.0f/*  + GREG(48) */ - rg) * (0.03f /* + (float)GREG(49)*0.001f */),
		  0.2f,
		  0.2f);
    }
}

static void lily_obj_check(Fishing_Obj    *obj, xyz_t *pos, u8 flag)
{
    float x,z,rg;
    
    x = obj->pos.x - pos->x;
    z = obj->pos.z - pos->z;
    
    if((rg = sqrtf(x*x + z*z)) <= 40.0f /* + GREG(48) */) {
	adds(&obj->work,
	     atans_table(z,x),
	     10 /* + GREG(55) */,
	     0x300 /* + GREG(56)*0x100 */);
	
    }
    
    if(flag &&
       rg <= 60.0f /* + KAZ(52) */) {
	float ya;
	
	ya = 1.0f /* + (float)KAZ(51)*0.1f */;
	
	if(flag > 20) { /* 激しい？ */
	    ya = 1.5f /* + (float)KAZ(51)*0.1f */;
	}
	
	add_calc2(&obj->fwork, /* 波振幅 */
		  ya,
		  0.1f,
		  0.2f /* + (float)KAZ(50)*0.01f */);
    }
}

static void Fishing_Obj_move(Game_play *game_play)
{
    short          i;
    Fishing_Obj    *obj       = &fishing_obj[0];
    Player_actor   *pla = (Player_actor *)get_player_actor(game_play);
    Actor          *check_actor;
    Fishing_actor  *fish;
    
#if OBJ_SET
    pad_t		*pad = &game_play->g.pads[P_PAD];
    
    obj       = &fishing_obj[0];
    
    if(Pad_on_trigger(R_CBUTTONS)) {
	for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	    if(obj->mode == 0) {
/*		obj->mode = FS_KUI;*/
		obj->mode = FS_ASHI;
		obj->pos = pla->actor.world.position;
		obj->pos.y = pla->actor.ground_y;
		obj->ang.x = 
		    obj->ang.z = 0.0f;
		obj->ang.y = rnd_f(F_PI*2.0f);
		obj->scale = 1.0f;
#if 0		
		obj->scale = 0.1f /* + (float)GREG(10)*0.001f */;
#endif		
		break;
	    }
	}
    }
    
    obj       = &fishing_obj[0];
    
    if(Pad_on_trigger(D_CBUTTONS)) {
	for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	    if(obj->mode == 0) {
		obj->mode = FS_LILY;
		obj->pos = pla->actor.world.position;
		obj->pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy + 2.0f;
		obj->ang.y = rnd_f(F_PI*2.0f);
		obj->scale = 0.5f /* + (float)GREG(4)*0.01f */;
		break;
	    }
	}
    }
    
    obj       = &fishing_obj[0];
    
    if(Pad_on_trigger(L_CBUTTONS)) {
	for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	    if(obj->mode == 0) {
		obj->mode = FS_ISHI;
		obj->pos = pla->actor.world.position;
		obj->pos.y = pla->actor.ground_y;
		obj->ang.y = rnd_f(F_PI*2.0f);
		obj->scale = 0.3f /* + (float)GREG(5)*0.01f */;
		break;
	    }
	}
    }
    
    obj       = &fishing_obj[FISHING_OBJ_SIZE-1];
    
    if(Pad_on_trigger(B_BUTTON)) {
	for(i=FISHING_OBJ_SIZE-1;i>=0;i--,obj--) {
	    if(obj->mode == FS_LILY) {
		obj->mode = 0;
		break;
	    }
	}
    }
    
    obj       = &fishing_obj[0];
    
    PRINTF("static Fishing_Obj_Data fishing_obj_data[] = {\n");
    
#endif
    
    for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	if(obj->mode) {
	    obj->count ++;
#if OBJ_SET
	    if(Pad_push_also(R_TRIG)) {
		if(obj->mode == FS_LILY) {
		    PRINTF("{%d,%d,%d,%d},\n",(short)obj->mode,(short)obj->pos.x,(short)obj->pos.y,(short)obj->pos.z);
		}
	    }
#endif
	    obj->cull_flag = 0;
	    
   	    Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
				     (Skin_Vector *)&obj->pos,
				     (Skin_Vector *)&obj->camera_pos,
				     &float_dammy);
	    if(obj->camera_pos.z < obj->cull_z /*800.0f*/ &&
	       fabsf(obj->camera_pos.x) < 100.0f + obj->camera_pos.z) {
		obj->cull_flag = 1;
	    }
	    if(obj->camera_pos.z < 500.0f &&
	       fabsf(obj->camera_pos.x) < 100.0f + obj->camera_pos.z) {
		if(obj->mode == FS_ASHI) {
		    ashi_obj_check(obj, &pla->actor.world.position);
		    
		    check_actor = game_play->actor_info.actor_list[ACTOR_PART_PEOPLE].actor;
		    
		    while(check_actor != NULL) {
			if(check_actor->name != ACTOR_NAME_FISHING ||
			   check_actor->arg_data < 100) { /* 魚？ */
			    check_actor = check_actor->next; /* いいえ    では 次！ */
			    continue;
			}
			
			ashi_obj_check(obj, &check_actor->world.position);
			
			check_actor = check_actor->next; /* では 次！ */
		    }
		    
		    add_calc0(&obj->ang.x,
			      0.05f,
			      0.05f);
		} else if(obj->mode == FS_LILY) {
		    lily_obj_check(obj, &pla->actor.world.position, 0);
		    
		    check_actor = game_play->actor_info.actor_list[ACTOR_PART_PEOPLE].actor;
		    
		    while(check_actor != NULL) {
			if(check_actor->name != ACTOR_NAME_FISHING ||
			   check_actor->arg_data < 100) { /* 魚？ */
			    check_actor = check_actor->next; /* いいえ    では 次！ */
			    continue;
			}
			
			fish = (Fishing_actor *)check_actor;
			
			lily_obj_check(obj, &check_actor->world.position,  (u8)fish->power_move);
			
			check_actor = check_actor->next; /* では 次！ */
		    }
		    
		    adds(&obj->work,
			 0,
			 20 /* + GREG(57) */,
			 0x50/*  + GREG(58)*0x10 */);
		    
		    /* 微妙な波の影響 */
		    obj->pos.y =
			(float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy
			+ 2.0f + sin_s(obj->count * (0x1000 /* + KAZ(48) */)) * obj->fwork;
		    
		    add_calc0(&obj->fwork,
			      0.1f,
			      0.02f /* + (float)KAZ(49)*0.01f */);
		}
#if 0
		else if(obj->mode >= FS_ISHI) {
		    if(obj->mode == FS_ISHI) {
			CollisionCheck_pos_set(
			    i,
			    &master->ishi_jntsph_info,
			    &obj->pos,
			    obj->scale);
		    } else {
			xyz_t col_pos = obj->pos;
			
			col_pos.y += KAZ(51);
			
			CollisionCheck_pos_set(
			    i,
			    &master->ishi_jntsph_info,
			    &col_pos,
			    obj->scale * (1.0f + (float)KAZ(50)*0.01f)
			    );
		    }
		}
#endif		
	    }
	}
    }
#if OBJ_SET
    PRINTF("};\n");
#endif
    if(demo_camera_no == 0) { /* デモ中以外？ */
	CollisionCheck_setOC( /* OBJ石の当り */
	    (Game *)game_play, &game_play->collision_check,
	    &master->ishi_jntsph_info.cl_obj);
    }
}

static void Fishing_Obj_disp(Game_play *game_play)
{
    u8    first_flag = 0;
    short i;
    Game 	   *game      = (Game *)game_play;
    Fishing_Obj    *obj       = &fishing_obj[0];
    Fishing_Obj    *obj_BAK   = obj;
	
    OPEN_DISP(game->graph);
    Matrix_push();

/*     _texture_z_light_fog_prim(game->graph); */
/*     _texture_z_light_fog_prim_xlu(game->graph); */
		
    for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	if(obj->mode == FS_ASHI)  {
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_POLY_XLU_DISP, turi_kusa_DISP_MODE);
		first_flag ++;
	    }
	    
	    if(obj->cull_flag) {
		Matrix_translate(obj->pos.x, obj->pos.y, obj->pos.z, SET_MTX);
		Matrix_scale(obj->scale,
			     obj->scale,
			     obj->scale,
			     MULT_MTX);
		Matrix_rotateY(obj->ang.y, MULT_MTX);
		Matrix_rotateX(obj->ang.x, MULT_MTX);
		Matrix_rotateY(obj->ang.z, MULT_MTX);
		gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_POLY_XLU_DISP, turi_kusa_model);
	    }
	}
    }
    
    first_flag = 0;
    obj = obj_BAK;
    
    for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	if(obj->mode == FS_KUI)  {
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_DISP, turi_kui_DISP_MODE);
		first_flag ++;
	    }
	    
	    if(obj->cull_flag) {
		Matrix_translate(obj->pos.x, obj->pos.y, obj->pos.z, SET_MTX);
		Matrix_scale(obj->scale,
			     obj->scale,
			     obj->scale,
			     MULT_MTX);
		gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_DISP, turi_kui_model);
	    }
	}
    }
    
    first_flag = 0;
    obj = obj_BAK;
    
    for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	if(obj->mode == FS_LILY)  {
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_POLY_XLU_DISP, turi_hasu_DISP_MODE);
		first_flag ++;
	    }
	    
	    if(obj->cull_flag) {
		Matrix_translate(obj->pos.x, obj->pos.y, obj->pos.z, SET_MTX);
		Matrix_scale(obj->scale,
			     1.0f,
			     obj->scale,
			     MULT_MTX);
		
		Matrix_rotateY((float)obj->work*(F_PI/32768.0f), MULT_MTX);
		Matrix_translate(0.0f, 0.0f, 20.0f /* + GREG(50) */, MULT_MTX);
		Matrix_rotateY(obj->ang.y, MULT_MTX);
		gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_POLY_XLU_DISP, turi_hasu_model);
	    }
	}
    }

    
    first_flag = 0;
    obj = obj_BAK;
    
    for(i=0;i<FISHING_OBJ_SIZE;i++,obj++) {
	if(obj->mode == FS_ISHI)  {
	    if(first_flag == 0) {
		gSPDisplayList(NEXT_DISP, turi_isi_DISP_MODE);
		first_flag ++;
	    }
	    
	    if(obj->cull_flag) {
		Matrix_translate(obj->pos.x, obj->pos.y, obj->pos.z, SET_MTX);
		Matrix_scale(obj->scale,
			     obj->scale,
			     obj->scale,
			     MULT_MTX);
		Matrix_rotateY(obj->ang.y, MULT_MTX);
		gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPDisplayList(NEXT_DISP, turi_isi_model);
	    }
	}
    }

    Matrix_pull();
    CLOSE_DISP(game->graph);
}


/* 子魚処理 */
static void Minnow_move(Game_play *game_play)
{
    short          flag = 0;
    short          i,j,bi;
    float          x,y,z,rg;
    float	   speedXY;
    float          turn_a;
    float          speedF,speedP;
    short          xa,ya,tya;
    xyz_t          base_pos[3],pos,*pos_p;
    Player_actor   *pla = (Player_actor *)get_player_actor(game_play);
    Minnow         *obj       = &minnow[0];


    
/* いろんな奴の反応 */
    if(lure_in_water ||  /* ルアー着水瞬間 */
       lure_mode == LURE_MODE_FISHON) { /* ヒット中のルアーにも反応 */
	pos_p = &lure_pos;
    } else {
	pos_p = &pla->actor.world.position;
    }
    
/* 集団１*/    
    base_pos[0].x = sinf(minnow_home_angle_Y1) * (720.0f /* + NS1(34) */);
    base_pos[0].y = -35.0f;
    base_pos[0].z = cosf(minnow_home_angle_Y1) * (720.0f /* + NS1(34) */);
    
    x = pos_p->x - base_pos[0].x;
    z = pos_p->z - base_pos[0].z;
    
    if((x*x + z*z) < 50.0f*50.0f) {
	minnow_home_angle_Y1 += 0.3f /*  + (float)NS1(35)*0.01f */;
	flag |= 0x01;
    } else if(minnow_panic/* == 1*/) {
	minnow_home_angle_Y1 += 0.05f  /* + (float)NS1(75)*0.001f  */;
	base_pos[0].y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 5.0f;
    } else {
	add_calc2(&minnow_home_angle_Y1,
		  0.7f /* + (float)NS1(32)*0.1f */,
		  1.0f,
		  0.001f);
    }
    
/* 集団 2 */    
    base_pos[1].x = sinf(minnow_home_angle_Y2) * (720.0f /* + NS1(34) */);
    base_pos[1].y = -35.0f;
    base_pos[1].z = cosf(minnow_home_angle_Y2) * (720.0f /* + NS1(34) */);
    
    x = pos_p->x - base_pos[1].x;
    z = pos_p->z - base_pos[1].z;

    if((x*x + z*z) < 50.0f*50.0f) {
	minnow_home_angle_Y2 -= 0.3f /*  + (float)NS1(35)*0.01f */;
	flag |= 0x02;
    } else if(minnow_panic/* == 2*/) {
	minnow_home_angle_Y2 -= 0.05f /*  + (float)NS1(75)*0.001f */ ;
	base_pos[1].y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 5.0f;
    } else {
	add_calc2(&minnow_home_angle_Y2,
		  2.3f/*  + (float)NS1(33)*0.1f */,
		  1.0f,
		  0.001f);
    }
    
/* 集団 3 */    
    base_pos[2].x = sinf(minnow_home_angle_Y3) * (720.0f /* + NS1(34) */);
    base_pos[2].y = -35.0f;
    base_pos[2].z = cosf(minnow_home_angle_Y3) * (720.0f /* + NS1(34) */);
    
    x = pos_p->x - base_pos[2].x;
    z = pos_p->z - base_pos[2].z;

    if((x*x + z*z) < 50.0f*50.0f) {
	minnow_home_angle_Y3 -= 0.3f  /* + (float)NS1(35)*0.01f */;
	flag |= 0x04;
    } else if(minnow_panic/* == 3*/) {
	minnow_home_angle_Y3 -= 0.05f  /* + (float)NS1(75)*0.001f */ ;
	base_pos[2].y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 5.0f;
    } else {
	add_calc2(&minnow_home_angle_Y3,
		  4.6f /* + (float)NS1(33)*0.1f */,
		  1.0f,
		  0.001f);
    }

    if(AGE == 1) { /* 5歳 */
	speedP = 0.8f;
    } else {
	speedP = 1.0f;
    }
	    
    for(i=0;i<MINNOW_SIZE;i++,obj++) {
	if(obj->mode) {
	    obj->count ++;
	    
	    Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
				     (Skin_Vector *)&obj->pos,
				     (Skin_Vector *)&obj->camera_pos,
				     &float_dammy);
	    if(obj->camera_pos.z < 400.0f /*  + KAZ(63)  */ &&
	       fabsf(obj->camera_pos.x) < 100.0f + obj->camera_pos.z) {
		obj->cull_flag = 1;
	    } else {
		obj->cull_flag = 0;
	    }
		
	    if(i <= 20) {
		bi = 0;
		j = 0x01;
	    } else if(i <= 40) {
		bi = 1;
		j = 0x02;
	    } else {
		bi = 2;
		j = 0x04;
	    }
	    
	    x = obj->t_pos.x - obj->pos.x;
	    y = obj->t_pos.y - obj->pos.y;
	    z = obj->t_pos.z - obj->pos.z;
	    
	    ya = atans_table(z, x);
	    rg = sqrtf(x*x + z*z);
	    xa = atans_table(rg, y);
	    
	    if(rg < 10.0f /* + NS1(72)  */||
	       ( !(obj->count & 0x1f /* + NS1(71) */) && rnd() > 0.5f)) { /* 方向変化？*/
		obj->t_pos.y = base_pos[bi].y + rnd_fx(10.0f /* + NS1(70) */);
		if(minnow_panic) {
		    obj->t_pos.x = base_pos[bi].x + rnd_fx(200.0f/*  + NS1(69) */);
		    obj->t_pos.z = base_pos[bi].z + rnd_fx(200.0f /* + NS1(69) */);
		} else {
		    obj->t_pos.x = base_pos[bi].x + rnd_fx(100.0f/*  + NS1(69) */);
		    obj->t_pos.z = base_pos[bi].z + rnd_fx(100.0f /* + NS1(69) */);
		}
		pos = obj->pos;
		pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
		
		fs_hamon_ct(
		    &obj->camera_pos,
		    (Fishing_Eff *)game_play->special_effect,
		    &pos,
		    20.0f /* + SEX(13) */,
		    100.0f /* + SEX(14) */ + rnd_f(50.0f),
		    150 /* + SEX(15) */,
		    FISHING_EFF_SIZE-10
		    );
		
		if(obj->speedF < /* (float)NS1(64)*0.1f +  */1.5f)
		    obj->speedF = /* (float)NS1(64)*0.1f +  */1.5f;
		
		obj->anime_spd = 1.5f;
		obj->anime_scale = 1.0f;
	    }
	    tya = adds2(&obj->ang.sy,
			ya,
			5,
			0x4000/* +NS1(65)*0x100 */);
	    
	    tya = (short)((float)tya * (3.0f /* + (float)KAZ(62)*0.1f */));
	    
	    /* 急激なターンで体曲げる */
	    
	    if(tya > 8000 /* + KAZ(19) */) {
		tya = 8000 /* + KAZ(19) */;
	    } else if(tya < -8000 /* - KAZ(19) */) {
		tya = -8000 /* - KAZ(19) */;
	    }
	    
	    adds(&obj->turn_a,
		 tya,
		 3 /* + GREG(80) */,
		 5000/* +GREG(78) */);
	    
	    turn_a  = (float)obj->turn_a * (-0.0001f /* + (float)KAZ(18)*0.00001f */);
	    
	    adds(&obj->ang.sx,
		 xa,
		 5,
		 0x4000/* +NS1(65)*0x100 */);
	    
	    if(flag & j) {
		obj->speedF = 6.0f /* + (float)NS1(37)*0.1f */;
		obj->anime_spd = 2.0f;
		obj->anime_scale = 1.0f;
	    }
	    if(minnow_panic/* == (j+1)*/) {
		obj->speedF = 4.0f /* + (float)NS1(37)*0.1f */;
		obj->anime_spd = 2.0f;
		obj->anime_scale = 1.0f;
	    }
	    
	    add_calc2(&obj->speedF,
		      /*  (float)NS1(64)*0.1f + */ 0.75f,
		      1.0f,
		      0.05f/*  + (float)NS1(36)*0.01f */);
	    
	    speedF = obj->speedF * speedP;
	    
	    speedXY = speedF * cos_s(obj->ang.sx);
	    obj->pos.x += speedXY * sin_s(obj->ang.sy);
	    obj->pos.y += speedF * sin_s(obj->ang.sx);
	    obj->pos.z += speedXY * cos_s(obj->ang.sy);

	    if(obj->cull_flag) { /* みえてへんときは計算なし */
		add_calc2(&obj->anime_spd,
			  1.0f /* + (float)GREG(58)*0.01f */,
			  1.0f,
			  0.1f);
		
		add_calc2(&obj->anime_scale,
			  0.4f /* + (float)GREG(59)*0.01f */,
			  1.0f,
			  0.04f);
		
		obj->anime_frame += obj->anime_spd;
		obj->anime_range = cosf(obj->anime_frame) * obj->anime_scale + turn_a;
	    }
	}
    }

    minnow_panic = 0;
}
static void Minnow_disp(Game_play *game_play)
{
    u8    first_flag = 0;
    float minnow_scale;
    short i;
    Game 	   *game      = (Game *)game_play;
    Minnow         *obj       = &minnow[0];

    if(AGE == 1 /* || KAZ(4) */) { /* 5歳 */
	minnow_scale = 0.00475f * 0.7f;
    } else {
	minnow_scale = 0.00475f;
    }
	
    OPEN_DISP(game->graph);
/*    _texture_z_light_fog_prim(game->graph);*/
		
    for(i=0;i<MINNOW_SIZE;i++,obj++) {
	if(obj->mode)  {
	    if(first_flag == 0) {
/*		gSPDisplayList(NEXT_DISP, fs_minnow_DISP_MODE);*/
		gSPDisplayList(NEXT_DISP, minnow_DISP_MODE);
		gDPSetPrimColor(NEXT_DISP, 0, 0, 
				155  /* + NS1(73) */ ,   /* */
				155  /* + NS1(74)  */,
				155  /* + NS1(75) */ ,
				255
		    );
		first_flag ++;
	    }
	    
/*PRINTF("CP.z = %f\n",obj->camera_pos.z);*/

	    if(obj->cull_flag) {
		Matrix_translate(obj->pos.x, obj->pos.y, obj->pos.z, SET_MTX);
		
		Matrix_rotateY((float)obj->ang.sy*F_PI/32768.0f, MULT_MTX);
		Matrix_rotateX(-(float)obj->ang.sx*F_PI/32768.0f, MULT_MTX);
		
		Matrix_scale(/* (float)KAZ(65)*0.0001f +  */minnow_scale * obj->anime_range,
			     /* (float)KAZ(65)*0.0001f +  */minnow_scale,
			     /* (float)KAZ(65)*0.0001f +  */minnow_scale,
			     MULT_MTX);
/*		
		Matrix_scale( obj->anime_range,
			      1.0f,
			      1.0f,
			     MULT_MTX);*/
/*		
		Matrix_rotateY( (float)GREG(56)*0.1f*F_PI, MULT_MTX);
		Matrix_rotateX( (float)GREG(57)*0.1f*F_PI, MULT_MTX);
		Matrix_rotateZ( (float)GREG(58)*0.1f*F_PI, MULT_MTX);
		*/
/*		
		Matrix_rotateY( 0.5f*F_PI, MULT_MTX);
		Matrix_rotateX( 0.5f*F_PI, MULT_MTX);
		*/
		
/* 		Matrix_translate(KAZ(67), 0.0f, 0.0f, MULT_MTX); */
		gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
/*		gSPDisplayList(NEXT_DISP, fs_minnow_model);*/
		gSPDisplayList(NEXT_DISP, minnow_model);
	    }
	}
    }
    CLOSE_DISP(game->graph);
}




/* 親父会話処理 */
#include "z_fishing_oyaji.c"


static  short bm_eye_pt[] = {  /* 目のまばたきデータ */
    0,  /* 0 */ 
    1,  /* 1 */ 
    2,  /* 2 */ 
    2,  /* 3 */ 
    1,  /* 4 */ 
};

static void bm_move(Actor *thisx, Game *game)
{
    Game_play		*game_play = (Game_play *)game;
    Fishing_actor *this = (Fishing_actor *)thisx;
    static xyz_t wall_pos = {670.0f, 0.0f, -600.0f};
    static xyz_t static_wall_pos;
    xyz_t  mae,ato,ato2;
    short  ya,al;
    float  yaf;
    float  pp,range;
    Camera *cam;
    Player_actor *pla = (Player_actor *)get_player_actor(game_play);
    pad_t		*pad = &game_play->g.pads[P_PAD];

#if 0
    thisx->world.position.x = sin_s(game_play->game_frame_counter * 0x800) * KAZ(64);
    thisx->world.position.z = cos_s(game_play->game_frame_counter * 0x800) * KAZ(64);
    thisx->world.position.x += KAZ(65);
    thisx->world.position.y = KAZ(66);
    thisx->world.position.z += KAZ(67);
#endif
    
#if FS_DEBUG    
    if(0) {
	float x,z;
	short ys;
	
	x =  -  pla->actor.world.position.x;
	z =  -  pla->actor.world.position.z;
	
	ys = atans_table(z,x);
	
	if(ABS((short)(ys - pla->actor.shape.angle.sy)) < 0x3000 + KAZ(80)*0x800) {
	    COLOR_GREEN();
	} else {
	    COLOR_YELLOW();
	}
	PRINTF("plays %x\n",pla->actor.shape.angle.sy);
	PRINTF("ys %x\n",ys);
	COLOR_NORMAL();
    }
#endif

#if /* FS_DEBUG */0
    
    PRINTF("FISHING_MODE        %d\n",pla->fishing_mode);
    PRINTF("FishRangeForMessage %d\n",FishRangeForMessage);
    PRINTF("PLAY COUNT          %d\n",play_count);
    PRINTF("HI_SCORE            %x\n",HI_SCORE(HS_FISH));
    
    if(KAZ(7)) {
	Player_Name[0] = KAZ(7);
    }
#if 0    
    COLOR_GREEN();
    PRINTF("PLAYER NAME : %d",Player_Name[0]);
    PRINTF(",%d",Player_Name[1]);
    PRINTF(",%d",Player_Name[2]);
    PRINTF(",%d",Player_Name[3]);
    PRINTF(",%d",Player_Name[4]);
    PRINTF(",%d",Player_Name[5]);
    PRINTF(",%d",Player_Name[6]);
    PRINTF(",%d\n",Player_Name[7]);
    COLOR_NORMAL();
#endif    
#endif    

    /* リンクの影の濃さ調整 */
    al = (short)pla->actor.shape.shadow_alpha;

    if((pla->actor.world.position.x * pla->actor.world.position.x +
	pla->actor.world.position.z * pla->actor.world.position.z) < 920.0f*920.0f) { /* 水範囲？ */
	adds(&al,
	     0,
	     1,
	     40);
    } else {
	adds(&al,
	     200,
	     1,
	     40);
    }

    pla->actor.shape.shadow_alpha = (unsigned char)al;

#if 0
    if(KAZ(90)) {
	short i;
	xyz_t minnow_v[]={
	    {     0,    302,   -707},
	    {  1344,   -306,      0},
	    {     0,    302,    707},
	    { -1344,   -306,      0},
	};
	
	xyz_t ato;
	
	Matrix_rotateY( 0.5f*F_PI, SET_MTX);
	Matrix_rotateX( 0.5f*F_PI, MULT_MTX);
	
	for(i=0;i<4;i++) {
	    Matrix_Position(&minnow_v[i], &ato); /*  */
	    
	    PRINTF("{ %d,     %d,      %d},\n",(short)ato.x,(short)ato.y,(short)ato.z);
	}
	
	PRINTF("\n");
    }
#endif    
    Skeleton_Info2_anime_play(&this->skeleton);

    if(head_check || /* ロックしない？ */
       message_check(&(game_play->message))) { /* メッセージある ？ */
	Actor_clear_status((Actor *)this, ACTOR_STATUS_ANCHOR);
    } else {
	Actor_set_status((Actor *)this, (ACTOR_STATUS_ANCHOR | ACTOR_STATUS_NO_CULL_DRAW));
    }
    
    /* 顔サーチ */
    if(this->actor.player_distance < 120.0f /* + KAZ(77) */ ||
       message_check( &( game_play->message )) ) {
	ya = (short)(this->actor.shape.angle.sy - this->actor.player_angle_y);
    } else {
	ya = 0;
    }
    
    if(ya > 10000)
	ya = 10000;
    else if(ya < -10000)
	ya = -10000;
    
    adds(&this->work[BM_KUBI_YA],
	 ya,
	 3,
	 5000);

    /* 目パチ制御 */
    if(!(game_play->game_frame_counter & 0x1f))  {
	if(rnd() < 0.3f) {
	    this->work[BM_EYE_TIME] = 0x04;
	}
    }
    
    this->work[BM_EYE_NO] = bm_eye_pt[this->work[BM_EYE_TIME]];

    timer_check_dec(&this->work[BM_EYE_TIME]);
    
    timer_check_dec(&head_check);

    if(lure_with_head == 0 &&
       lure_type != LURE_TYPE_WORM &&
       lure_mode >= LURE_MODE_CAST &&
       bm_head_no == 1 && /* ハゲ＆帽子？ */
       head_check == 0
	) { /* 帽子ひっかけられ判定 */
	float x,y,z;
	
	x = bm_head_pos.x - lure_pos.x;
	y = bm_head_pos.y /* + KAZ(75)  */- lure_pos.y;
	z = bm_head_pos.z - lure_pos.z;
	
	if(sqrtf(x*x + y*y + z*z) < 25.0f/*  + KAZ(76) */
#if FS_DEBUG	   
 || KAZ(77) > 0
#endif	   
	    ) {
#if FS_DEBUG	    
 	    KAZ(77) = 0;
#endif	    
	    bm_head_no = 0;
	    lure_with_head = 1;
	    message_set(game_play, 0x4087, NULL);  /* コラ！ */
	}
    }

    if(bm_head_no == 0) {
	HI_SCORE(HS_FISH) |= SAVE_CAP_OFF; /* ボウシあるかSAVE */
    } else if(bm_head_no == 1) {
	HI_SCORE(HS_FISH) &= ~SAVE_CAP_OFF; /* ボウシあるかSAVE OFF */
    }

#if FS_DEBUG
    if(KAZ(77) < 0) { 
	KAZ(77) = 0; 
 	lure_with_head_off = 1; 
    }
#endif

    if(fs_message_time) {
	fs_message_time --;
	if(!fs_message_time) {
	    message_set(game_play, fs_message_no, NULL);  /* MES */
	}
    }
    
    bm_message_check(this, game_play);

    /* 親がすべきこと */
    
    line_scale = 0.01f * 0.15f /* + (float)SEX(1)*0.0001f */;

    /* ルアーの制御 */
    fishing_time ++; /* 累計時間 */
    
    if(fishing_game_mode && rod_disp) {
 	lure_move(this, game_play);
    }

    /* 効果の制御 */
    Fishing_Eff_move((Fishing_Eff *)game_play->special_effect, game_play);

    /* 草などの制御 */
    Fishing_Obj_move(game_play);

    /* 子魚の制御 */
    Minnow_move(game_play);
/*    
    bgm_test();
    */
#if 0    
    if(NS1(0)) {
	NS1(0) = 0;
	
	to_fishing_set(game_play); /* 構えセット */
	fishing_game_mode = 1;     /* 竿セット */
    }
#endif
    
#if 0
    /* プレイヤーが中心に行かないように */
    if(sqrtf(pla->actor.world.position.x*pla->actor.world.position.x +
	     pla->actor.world.position.z*pla->actor.world.position.z) < 777.0f /* + KAZ(42) */) {
	pla->actor.world.position.x = pla->actor.old_position.x;
	pla->actor.world.position.z = pla->actor.old_position.z;
	pla->actor.speedF = 0.0f;
    }
#endif

    /* 竿を持ったまま出ないように */
    if(fishing_game_mode &&
       demo_mode == 0 &&
       pla->actor.world.position.z > 1360.0f &&
       fabsf(pla->actor.world.position.x) < 25.0f) {
	
	pla->actor.world.position.z = 1360.0f;
	pla->actor.speedF = 0.0f;
	
	if(door_check_time == 0) {
	    demo_mode = 10;
	}
    }

    /* 拾うしずむルアーチェック */
    if( worm_set_P ) {
	static s_xyz worm_set_pos[] = {
	    {-364,	-30,  -269},
	    {1129,	  3,  -855},
	    {-480,	  0, -1055},
	    { 553,	-48,  -508},
/* 	    { 524,	-54,  -497}, */
	};
/* PRINTF("worm_set_P %d\n",worm_set_P); */
	if(fabsf(pla->actor.world.position.x - (float)worm_set_pos[worm_set_P-1].sx) < 25.0f) {
	    if(fabsf(pla->actor.world.position.y - (float)worm_set_pos[worm_set_P-1].sy) < 10.0f) {
		if(fabsf(pla->actor.world.position.z - (float)worm_set_pos[worm_set_P-1].sz) < 25.0f) {
		    worm_set_P = 0;
		    demo_mode = 20;
		    RUMBLE_ENTRY_FORCE2(150, 10, 10, 0.0f);	/* 振動セット */
		    Na_StartSystemSe_F(NA_SE_SY_HINT_CHIME);	/* <SE> */
		    Na_StopBgm(20);  /*  SE BGM */
		}
	    }
	}
    }
#if FS_DEBUG
    if(KAZ(0)) {
	KAZ(0) = 0;
	lure_type = 0;
	demo_mode = 20;
	RUMBLE_ENTRY_FORCE2(150, 10, 10, 0.0f);	/* 振動セット */
	Na_StartSystemSe_F(NA_SE_SY_HINT_CHIME);	/* <SE> */
	Na_StopBgm(20);  /*  SE BGM */
    }
#endif
    if(door_check_time)
	door_check_time --;

/*


  
                         デモカメラ制御



*/
    switch(demo_mode) {
    case 100:
    case 0:
	break;
    case 1:
/* 	Demo_play_start(game_play, &game_play->demo_play); */
	demo_camera_no  = Gama_play_make_camera(game_play);
	Gama_play_set_camera_status(game_play, 0, CAM_STATUS_WAIT);
	Gama_play_set_camera_status(game_play, demo_camera_no, CAM_STATUS_ACTION);
	
	cam = Gama_play_get_camera(game_play, 0);
	
	demo_eye.x = cam->eye.x;
	demo_eye.y = cam->eye.y;
	demo_eye.z = cam->eye.z;
	demo_way.x = cam->center.x;
	demo_way.y = cam->center.y;
	demo_way.z = cam->center.z;
	demo_mode = 2;

	/* アイテムアイコン制御 */
/* 	shrink_window_setval(27);  */
/* 	alpha_change(5); */
	alpha_change(12);
#if 0
	cam = Gama_play_get_camera(game_play, demo_camera_no);
	
	setCameraFlag(cam, CAMIDCHK_WATER);
	
	Gama_play_set_camera_owner(
	    game_play,
	    demo_camera_no,
	    (Actor *)pla,
	    CAM_SET_FREE0);
#endif	    
	demo_morf = 0.0f;
    case 2:
	shrink_window_setval(27);
	
	ato2.x = lure_pos.x - pla->actor.world.position.x;
	ato2.z = lure_pos.z - pla->actor.world.position.z;

	range = sqrtf(ato2.x * ato2.x + ato2.z * ato2.z);
	
	yaf = atanf_table(ato2.z , ato2.x);
	
	Matrix_rotateY(	yaf, SET_MTX);
	
	mae.x = 0.0f   ;
	mae.y = 0.0f   ;
	mae.z = 100.0f /* + BREG(64) */;
	
	Matrix_Position(&mae, &ato2); /*  */
	
	if(lure_mode == LURE_MODE_CAST) {
	    pp = 0.2f/*  + (float)BREG(65)*0.1f */;
	} else {
	    pp = 0.1f/*  + (float)BREG(66)*0.1f */;
	}
	
	add_calc2(&demo_way.x,
		  lure_pos.x,
		  pp,
		  fabsf(ato2.x)*demo_morf);
	add_calc2(&demo_way.y,
		  lure_pos.y,
		  pp,
		  (50.0f/*+KAZ(43)*/)*demo_morf);
	add_calc2(&demo_way.z,
		  lure_pos.z,
		  pp,
		  fabsf(ato2.z)*demo_morf);

	mae.x = 0.0f /* + KAZ(36) */ - 30.0f;
	mae.x = 0.0f /* + KAZ(36) */ - demo_eye_xp;
	if(AGE != 1) { /* 17歳 */
	    mae.y = 90.0f /* + KAZ(37) */ - 10.0f;
	} else {
	    mae.y = 90.0f /* + KAZ(37) */ - 25.0f - 10.0f;
	}
	mae.z = -80.0f /* + KAZ(38) */;
	
	Matrix_Position(&mae, &ato); /*  */
	
	ato.x += pla->actor.world.position.x;
	ato.y += pla->actor.world.position.y;
	ato.z += pla->actor.world.position.z;

	add_calc2(&demo_eye_xp,
		  30.0f /*  + KAZ(49) */,
		  0.1f,
		  0.4f  /* + (float)KAZ(50)*0.01f */);
/*=========================================================
  カメラ距離切り替え
	  
  camera_zoom_switch : 0  プレイヤー後方 
                     : 1  小接近 
                     : 2  超接近 
                     : 3  小接近 

 =========================================================*/
	if(Pad_on_trigger(Z_TRIG) &&
	   camera_zoom_switch >= 0 &&
	   lure_hook_time == 0) { /* ヒット可能性がある時はパニクってるのでなし */
	    camera_zoom_switch ++;
	    if(camera_zoom_switch > 3)
		camera_zoom_switch = 0;
	    
	    if(camera_zoom_switch == 0 || camera_zoom_switch == 3) {
		Na_StartSystemSe_F(NA_SE_SY_CAMERA_ZOOM_DOWN);
	    } else {
		Na_StartSystemSe_F(NA_SE_SY_CAMERA_ZOOM_UP);
	    }
/*	    
	    if((camera_zoom_switch = 1 - camera_zoom_switch)) {
		Na_StartSystemSe_F(NA_SE_SY_CAMERA_ZOOM_DOWN);
	    } else {
		Na_StartSystemSe_F(NA_SE_SY_CAMERA_ZOOM_UP);
	    }*/
	}

	if(lure_mode >= LURE_MODE_ACTION) {
	    if(range < 110.0f /* + BREG(31) */) { /* 回収間近はノーマルカメラに戻す しかもカメラ切り替えもうできない */
		camera_zoom_switch = -1;
	    } else if(range > 300.0f) { /* さらに広がったらまたカメラ切り替え可能 */
		if(camera_zoom_switch < 0)
		    camera_zoom_switch = 0;
	    }
	}
	    
	if(camera_zoom_switch > 0) {
	    float p,r,rs;

	    r = sqrtf(ato2.x*ato2.x + ato2.z*ato2.z) * 0.001f;
	    if(r > 1.0f)
		r = 1.0f;

	    if(camera_zoom_switch == 2) { /* 超接近 */
		rs = 0.3f /* + (float)KAZ(43)*0.01f */;
	    } else {  /* 少し接近 */
		rs = 0.1f /* + (float)KAZ(44)*0.01f */;
	    }
	    p = 0.4f /*+ (float)(KAZ(44)+10)*0.01f + */ + rs + 
	    (r * (0.5f+(float)(/* KAZ(39) */-10)*0.01f));
	    
	    ato.x += (lure_pos.x - ato.x) * p;
	    ato.y += (lure_pos.y - ato.y) * p /* + KAZ(40)  */+ 20.0f;
	    ato.z += (lure_pos.z - ato.z) * p;
	    
	    /* アップなので細くしたほうが見栄えがいい */
	    line_scale = 0.01f * 0.15f + (float)(/* SEX(61) */-10)*0.0001f; 
	}
    
	mae.x = 0.0f   ;
	mae.y = 0.0f   ;
	mae.z = 100.0f /* + BREG(67) */;
	
	Matrix_Position(&mae, &ato2); /*  */
#if 0	
	if(lure_mode == LURE_MODE_CAST) {
	    pp = 0.3f /* + (float)BREG(68)*0.1f */;
	} else {
	    pp = 0.3f /*+ (float)BREG(69)*0.1f*/;
	}
#endif	
	pp = 0.3f /*+ (float)BREG(69)*0.1f*/;
/*
	if(rod_hooking_impact) {
	    pp = 0.8f  + (float)BREG(69)*0.1f;
	}
	*/
	add_calc2(&demo_eye.x,
		  ato.x,
		  pp,
		  fabsf(ato2.x)*demo_morf);
	add_calc2(&demo_eye.y,
		  ato.y,
		  pp,
		  (20.0f/*+KAZ(43)*/)*demo_morf);
	add_calc2(&demo_eye.z,
		  ato.z,
		  pp,
		  fabsf(ato2.z)*demo_morf);
	break;
	
    case 3:
	if(1) {
	    Camera *cam = Gama_play_get_camera((Game_play *)game, 0);
	    cam->eye = demo_eye;
	    cam->base_eye = demo_eye;
	    cam->center = demo_way;
	}
	Gama_play_shift2main_camera(game_play, demo_camera_no, 0 /* + KAZ(9) */); /* カメラ補間 */
	Demo_play_end(game_play, &game_play->demo_play);

	demo_mode = 0;
	demo_camera_no = 0;
	water_in_kankyo(game_play,  0);
	game_play->kankyo.add_light.fog_near = 0;

//	pla->fishing_mode = 0; /* */
        pla->fishing_mode =  -NEXT_CAST_WAIT; /* 次のキャストまでのウエイト */
	lure_time = NEXT_CAST_WAIT/*  + 10 */;
	break;

/* 竿持って出ようとしたときのデモ */	
    case 10:
	Demo_play_start(game_play, &game_play->demo_play);
	demo_camera_no  = Gama_play_make_camera(game_play);
	Gama_play_set_camera_status(game_play, 0, CAM_STATUS_WAIT);
	Gama_play_set_camera_status(game_play, demo_camera_no, CAM_STATUS_ACTION);
	player_demo_mode_set(game_play, (Actor *)this, P_DEMO_PLAY_BIKKURI);
	
	cam = Gama_play_get_camera(game_play, 0);
	
	demo_eye.x = cam->eye.x;
	demo_eye.y = cam->eye.y;
	demo_eye.z = cam->eye.z;
	demo_way.x = cam->center.x;
	demo_way.y = cam->center.y;
	demo_way.z = cam->center.z;
	
	message_set(game_play, 0x409e, NULL);  /* コラ！ */
	demo_mode = 11;
	RUMBLE_ENTRY_FORCE2(150, 10, 10, 0.0f);	/* 振動セット */
/*	break;*/
	
    case 11:
	pla->actor.world.position.z = 1360.0f;
	pla->actor.speedF = 0.0f;
	
	if (message_check( &( game_play->message ) ) == 0  ) {
	    Camera *cam = Gama_play_get_camera((Game_play *)game, 0);
	    cam->eye = demo_eye;
	    cam->base_eye = demo_eye;
	    cam->center = demo_way;
	    
	    Gama_play_shift2main_camera(game_play, demo_camera_no, 0); /* カメラ補間 */
#if 0	    
            Gama_play_clear_camera(game_play, demo_camera_no); /* デモカメラクリアー */
#endif	    
	    Demo_play_end(game_play, &game_play->demo_play);
	    player_demo_mode_set(game_play, (Actor *)this, P_DEMO_PLAY_END);
	    
	    demo_mode = 0;
	    demo_camera_no = 0;
	    door_check_time = 30;
	    water_in_kankyo(game_play,  0); /* 基本 */
	    game_play->kankyo.add_light.fog_near = 0;
	}
	break;
	
/* しずむルアーを拾ったときのデモ */	
    case 20:
	Demo_play_start(game_play, &game_play->demo_play);
	demo_camera_no  = Gama_play_make_camera(game_play);
	Gama_play_set_camera_status(game_play, 0, CAM_STATUS_WAIT);
	Gama_play_set_camera_status(game_play, demo_camera_no, CAM_STATUS_ACTION);
	player_demo_mode_set(game_play, (Actor *)this, P_DEMO_PLAY_BIKKURI);
	cam = Gama_play_get_camera(game_play, 0);
	
	demo_eye.x = cam->eye.x;
	demo_eye.y = cam->eye.y;
	demo_eye.z = cam->eye.z;
	demo_way.x = cam->center.x;
	demo_way.y = cam->center.y;
	demo_way.z = cam->center.z;
	
	message_set(game_play, 0x409a, NULL);  /* おっ！ こ これは！ */
	demo_mode = 21;
	demo_xa = 45.0f;
	door_check_time = 10;
/*	break;*/
	
    case 21:
	if(door_check_time == 0) {
	    if ( pad_on_check(game_play) ) {
		demo_mode = 22;
		door_check_time = 40;
		
		player_demo_mode_set(game_play, (Actor *)this, P_DEMO_PLAY_GET_ITEM);
		lure_hirotta_pos_y2 = 0.0f;
	    }
	}
	break;
	
    case 22:
	if(door_check_time == 30) {
#if 1	    
	    Na_StartBgm(NA_BGM_ITEM_GET);  /* BGM  */
#else	    
	    Na_StartFanfare(NA_BGM_ITEM_GET);
#endif	    
	}
	lure_hirotta = 1;

	add_calc2(&lure_hirotta_pos_y2,
		  /* KAZ(90) +  */71.0f,
		  0.5f,
		  3.0f /* + KAZ(92) */);
    
	Matrix_rotateY(	(float)pla->actor.shape.angle.sy/32768.0f*F_PI, SET_MTX);

	mae.x = sin_s(game_play->game_frame_counter * (0x1000/* +KAZ(59)*0x100 */)) * (/* KAZ(58) + */ 1.0f);
	mae.y = lure_hirotta_pos_y2;
	mae.z = 10.0f /* + KAZ(61) */ - 15.0f;
	
	if(AGE == 1) { /* 5歳 */
	    mae.y -= 20.0f;
	}
	
	Matrix_Position(&mae, &ato); /*  */
	
	lure_hirotta_pos.x = pla->actor.world.position.x + ato.x;
	lure_hirotta_pos.y = pla->actor.world.position.y + ato.y;
	lure_hirotta_pos.z = pla->actor.world.position.z + ato.z;
	
	add_calc2(&demo_xa,
		  15.0f,
		  0.1f,
		  0.75f);
	
	mae.x = 0.0f /* + KAZ(36) */ + demo_xa - 15.0f;

	if(AGE != 1) { /* 17歳 */
	    mae.y = 30.0f /* + KAZ(37) */         + 30.0f;
	    mae.z = 80.0f /* + KAZ(38)  */- 25.0f - 80.0f - 5.0f;
	} else {
	    mae.y = 30.0f /* + KAZ(37)  */- 20.0f + 30.0f;
	    mae.z = 80.0f /* + KAZ(38)  */- 30.0f - 80.0f - 5.0f;
	}
	Matrix_Position(&mae, &demo_eye); /*  */

	demo_eye.x += pla->actor.world.position.x;
	demo_eye.y += pla->actor.world.position.y;
	demo_eye.z += pla->actor.world.position.z;

	demo_way = pla->actor.world.position;
	if(AGE != 1) { /* 17歳 */
	    demo_way.y += /* KAZ(40)+ */30.0f + 10.0f + 22.0f;
	} else {
	    demo_way.y += /* KAZ(40)+ */30.0f - 5.0f + 15.0f;
	}

	if(door_check_time == 0) {
	    if ( message_check( &( game_play->message ) ) == 4 ||
		 message_check( &( game_play->message ) ) == 0) {	/* 原選択待ち？ */
		if ( pad_on_check(game_play) ) {
		    Camera *cam = Gama_play_get_camera((Game_play *)game, 0);
		    message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
		    
		    if(game_play->message.sel_pnt == 0) { /* さっそく使おう */
			lure_type = LURE_TYPE_WORM;
			seken_mes_ct = 0;
		    }
		    cam->eye = demo_eye;
		    cam->base_eye = demo_eye;
		    cam->center = demo_way;
		    Gama_play_shift2main_camera(game_play, demo_camera_no, 0); /* カメラ補間 */
		    Demo_play_end(game_play, &game_play->demo_play);
		    player_demo_mode_set(game_play, (Actor *)this, P_DEMO_PLAY_END);
/* 		    player_demo_mode_set(game_play, (Actor *)this, P_DEMO_PLAY_GET_ITEM_END); */
		    
		    demo_mode = 0;
		    demo_camera_no = 0;
/* 		    pla->fishing_mode = 0;  */
		    pla->fishing_mode =  -NEXT_CAST_WAIT; /* 次のキャストまでのウエイト */
		    lure_time = NEXT_CAST_WAIT/*  + 10 */;
		    lure_hirotta = 0;
		    lure_bgm_time = 20;
		    water_in_kankyo(game_play,  0); /* 基本 */
		    game_play->kankyo.add_light.fog_near = 0;
		}
	    }
	}
	break;
    }

    if(demo_camera_no) {
	Gama_play_camera_setting(game_play,
				 demo_camera_no,
				 &demo_way,
				 &demo_eye
	    );

	add_calc2(&demo_morf,
		  1.0f/*  + (float)BREG(14)*0.1f */,
		  1.0f,
		  0.02f/*  + (float)BREG(15)*0.001f */);
	
#if 01
	if(demo_eye.y <= (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy /* + KAZ(93) */+1.0f) {
	    water_in_kankyo(game_play,  1); /* 水中環境カラー */

	    if(mad_water) { /*にごってる日？ */
		game_play->kankyo.add_light.fog_near = 800 - 978 /* - KAZ(85) */;
	    } else {
		game_play->kankyo.add_light.fog_near = 950 - 996 /* - KAZ(86) */;
	    }
	} else {
	    water_in_kankyo(game_play,  0); /* 基本 */
	    game_play->kankyo.add_light.fog_near = 0;
	}
#endif
	
#if 0
	if((short)demo_eye.y <= game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy &&
	   demo_eye_old_y > game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
	    /* カメラ水入った瞬間 */
	    water_in_kankyo(game_play,  1);
	}
	if((short)demo_eye.y >= game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy &&
	   demo_eye_old_y < game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy) {
	    /* カメラ水出た瞬間 */
	    water_in_kankyo(game_play,  0);
	}
	
	demo_eye_old_y = (short)demo_eye.y;
#endif	
    }
/*    }*/

    /* プレイヤーの水底煙効果 */
    if(pla->actor.ground_y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 3.0f /* + BREG(13) */ &&
       pla->actor.world.position.y < pla->actor.ground_y + 3.0f &&
       pla->actor.speedF > 1.0f &&
       !(game_play->game_frame_counter & 0x01) ) {
	xyz_t pos;
	
	pos.x = pla->actor.world.position.x + rnd_fx(20.0f/* +BREG(29) */);
	pos.z = pla->actor.world.position.z + rnd_fx(20.0f/* +BREG(29) */);
	pos.y = pla->actor.ground_y + 5.0f;
	
	fs_smoke_ct(
	    NULL,
	    (Fishing_Eff *)game_play->special_effect,
	    &pos,
	    1.0f -0.5f /* + (float)BREG(28)*0.001f */
	    );
    }

    /* プレイヤーの水際水しぶき */
    if(pla->actor.ground_y < (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy /*  + BREG(44) */ &&
       pla->actor.ground_y > (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy - 10 /* + BREG(45) */ &&
       pla->actor.speedF >= (4.0f/*  + (float)BREG(46)*0.01f */) &&
       !(game_play->game_frame_counter & (0x03/* +BREG(47) */)) ) {
	short i;
	
	for(i=0;i<10/* +BREG(43) */;i++) {
	    xyz_t pos,vec;
	    float ad,ra;
	    
	    ad = /* (float)BREG(42)*0.1f + */   1.5f + rnd_f(1.5f);
	    
	    ra = rnd_f(6.28f);
	    
	    vec.x = sinf( ra ) * ad;
	    vec.z = cosf( ra ) * ad;
	    vec.y = /* (float)BREG(41)*0.1f + */ 2.0f + rnd_f(3.0f);
	    
	    pos = pla->actor.world.position;
	    pos.x += vec.x * 2.0f;
	    pos.y = (float)game_play->BGCheck.pbgdata->water_info_tbl->min_pos.sy;
	    pos.z += vec.z * 2.0f;
	    
	    fs_mizu_ct(
		NULL,
		(Fishing_Eff *)game_play->special_effect,
		&pos,
		&vec,
		(20.0f/* +GREG(2) */)*0.001f + rnd_f(0.010f)
		);
	}
    }

#if  FS_DEBUG
    if(SEX(15)) {
	if(rain != SEX(15)-1) {
	    if(rain == 0) {
		game_play->kankyo.rain_evt_trg = 1;
	    } else {
		game_play->kankyo.rain_evt_trg = 2;
	    }
	}
	rain = SEX(15)-1;
    }

    if(SEX(14) == 1) {
	game_play->kankyo.rain_evt_trg = 1;
    }
    if(SEX(14) == -1) {
	game_play->kankyo.rain_evt_trg = 2;
    }
    
    SEX(14) = 0;

    COLOR_GREEN();
    PRINTF("zelda_time %x\n",ZCommonGet(zelda_time));
    COLOR_NORMAL();
#endif

    if(wether > 1)
	wether --;
    
    if(wether  == 1 && /* 天気悪い？ */
       message_check(&(game_play->message)) == 0 && /* 止ってない？ */
       (fishing_time & 0xfff) == 0xfff
       /* (ZCommonGet(zelda_time) & 0xfff) == 0x0 */) { /* 降ったりやんだり */
	wether = 200; /* 連続防止 */
	
	if(rnd() < 0.5f) { 
	    rain = (u8)rnd_f(10.0f) + 5;
	    game_play->kankyo.rain_evt_trg = 1; /* 遠景曇りに */
	} else {
	    rain = 0;
	    game_play->kankyo.rain_evt_trg = 2; /* 遠景晴れに */
	}
    }
    add_calc2(&rain_S,
	      (float)rain,
	      1.0f,
	      0.05f
	      );
    if(rain_S > 0.0f) {
	float rse;
	
	rse = 0.8f + rain_S * 0.03f;
	if(rse > 1.2f)
	    rse = 1.2f;
	
	add_calc2(&rain_se_p,   /* 音のトーン */
		  rse,
		  1.0f,
		  0.01f
	    );
    }
    if(1) {
	float sep;
	sep = (10.0f - rain_S) * 150.1f;
	if(sep < 0.0f)
	    sep = 0.0f;
	
	add_calc2(&rain_se_pos.z, /* 音の大きさ */
		  sep,
		  1.0f,
		  5.0f /* + KAZ(33) */
	    );
	if(rain_se_pos.z < 1500.0f) {
	    Na_SetMotorSe((f32 *)&rain_se_pos, NA_SE_EV_RAIN, rain_se_p);
	}
    }
    if(rain) { /* 雨のときは暗くしよう */
	add_calc2(&add_light,
		  -200.0f /* + SEX(7) */,
		  1.0f,
		  2.0f);
    } else {
	add_calc0(&add_light,
		  1.0f,
		  2.0f);
    }
    
    game_play->kankyo.add_light.diffuse_col[0] = /* 太陽ライト */
	game_play->kankyo.add_light.diffuse_col[1] = 
	game_play->kankyo.add_light.diffuse_col[2] = (signed short)add_light;
#if 0    
    game_play->kankyo.vr_rectcol[0] = /* 背景マスク */
	game_play->kankyo.vr_rectcol[1] = 
	game_play->kankyo.vr_rectcol[2] = 0;
    
    if(game_play->kankyo.vr_rectcol[3] = (short)(-add_light * (0.8f /* + (float)SEX(6)*0.1f */))) {
	game_play->kankyo.vr_rect_pat = 1;
    } else {
	game_play->kankyo.vr_rect_pat = 0;
    }
#endif 
    if((u8)rain_S > 0) { /* 雨？ */
	short i;
	Camera *cam = Gama_play_get_camera((Game_play *)game, 0);
	xyz_t pos,ang,camera_pos;

	ang.x = F_PI*0.5f + (float)(/* SEX(13)+ */10)*0.01f;
	ang.y = (float)(/* SEX(12)+ */100)*0.01f;
	ang.z = (float)Camera_angleY(cam) * -(F_PI / 32768.0f) + ang.y;

	for(i=0;i<(u8)rain_S;i++) {
	    pos.x = game_play->view.eye.x + rnd_fx(700.0f /* + SEX(11) */);
	    pos.y = /* game_play->view.eye.y */ /* +  SEX(10) */ + 150.0f + rnd_f(100.0f/* +KAZ(37) */)/*  + KAZ(38) */ - 170.0f;
	    pos.z = game_play->view.eye.z + rnd_fx(700.0f /* + SEX(11) */);

	    if(pos.z < 1160.0f) { /* 軒下外？ */
		Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
					 (Skin_Vector *)&pos,
					 (Skin_Vector *)&camera_pos,
					 &float_dammy);
		
		if(camera_pos.z < 0.0f) {
		    i --; /* 少し危険 */
		} else {
		    fs_rain_ct(
			(Fishing_Eff *)game_play->special_effect,
			&pos,
			&ang
			);
		}
	    }
	}
    }
	
    /*
     * 流れ込みカメラポジションセット（前フレーム）
     */
    Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
			     (Skin_Vector *)&wall_pos,
			     (Skin_Vector *)&static_wall_pos,
			     &float_dammy);
    Na_StartObjectSe_F((f32 *)&static_wall_pos, NA_SE_EV_WATER_WALL);	/* <SE> */
	
#if 0    
    if(BREG(26)) {
	BREG(26) --;
	RUMBLE_ENTRY_FORCE2(BREG(27), BREG(28), BREG(29), 0.0f);	/* 振動セット */
    }
#endif


#if defined(PAL_VERSION)
    if( 1 ) {  /* PALはすべてポンド表示 */
	float r = (float)FishRangeForMessage;

	FISH_RANGE_FOR_MESSAGE = (u16)((r*r * 0.0036f) + 0.5f);
    }
#else
/* メッセージへ出力する魚大きさの国別変換 */
    if ( !J_N ) { /* 日本用 (cm) */
	FISH_RANGE_FOR_MESSAGE = FishRangeForMessage; /* そのまま */
    } else {      /* USA用  (lb) */
	float r = (float)FishRangeForMessage;

	FISH_RANGE_FOR_MESSAGE = (u16)((r*r * 0.0036f) + 0.5f);
    }
#endif

#if FS_DEBUG
    if(BREG(26)) {
	BREG(26) = 0;
	message_set( game_play, (u16)(0x407b + BREG(27)), NULL );	/* 強制メッセージセット */
    }
    
    PRINTF("HI_SCORE = %x\n",HI_SCORE(HS_FISH)); 

#endif

#if 0
    if(KAZ(6) < 0) {
	KAZ(6) = 0;
	Na_StartBgm(NA_BGM_KOKIRI);
    }
    if(KAZ(6) == 1) {
	Na_SetBgmPattern(NA_BGM_PTN_NORMAL);
	return;
    }
    if(KAZ(6) == 2) {
	Na_SetBgmPattern(NA_BGM_PTN_FIGHT);
	return;
    }
    Na_SetEnemyBgmDistance(0.0f);
    COLOR_GREEN();
    if(lure_hook_up &&
       lure_mode == LURE_MODE_FISHON) { /* 針掛り後は戦闘テーマ */
	PRINTF("NA_BGM_PTN_FIGHT\n");
	Na_SetBgmPattern(NA_BGM_PTN_FIGHT);
    } else {
	PRINTF("NA_BGM_PTN_NORMAL\n");
	Na_SetBgmPattern(NA_BGM_PTN_NORMAL);
    }
    COLOR_NORMAL();
#endif
}

static int bm_draw_sub(Game *game, int jyoint_no, Gfx **d, xyz_t *t, s_xyz *r, void *p)
{
/*     Game_play		*game_play  = (Game_play *)game; */
    Fishing_actor *this      = (Fishing_actor *)p;

    t;
    *d;
    game;
#if 0    
    if( jyoint_no == KAZ(32) ) {
	if(!(game_play->game_frame_counter & 0x03)) {
	    *d = NULL;
	}
	r->sx += KAZ(33)*100;
	r->sy += KAZ(34)*100;
	r->sz += KAZ(35)*100;
    }
#endif
    if( jyoint_no == 8) { /* 帽子？ */
	r->sx -= this->work[BM_KUBI_YA];
/*
	if(bm_head_no  == 0) {
	    *d = NULL;
	} else if (bm_head_no == 1) {
	    *d = fs_cap_model;
	} else {
	    *d = fs_zura_model;
	}*/
    }
    
    return 0;
}

static void bm_draw_sub2(Game *game, int jyoint_no, Gfx **d, s_xyz *r, void *p)
{
    game;
    d;
    r;
    p;

    if( jyoint_no == 8) { /* 頭？ */
	OPEN_DISP(game->graph);
	Matrix_Position(&zero, &bm_head_pos); /* 頭位置 */
	
	if(bm_head_no == 1) {  /* 帽子？ */
	    gSPDisplayList(NEXT_DISP, SEGMENT_TO_KSEG0(fs_cap_model));
	} else if (bm_head_no == 2) { /* かつら？ */
	    gSPDisplayList(NEXT_DISP, SEGMENT_TO_KSEG0(fs_zura_model));
	}
	CLOSE_DISP(game->graph);
    }
}

static unsigned char *bm_eye_tex_no[] = {
    &fs_eye01_CI00_txt[0],
    &fs_eye02_CI00_txt[0],
    &fs_eye03_CI00_txt[0],
};
static void bm_draw(Actor *thisx, Game *game)
{
    Game_play		*game_play = (Game_play *)game;
    Fishing_actor *this = (Fishing_actor *)thisx;
    pad_t		*pad = &game_play->g.pads[P_PAD];
    OPEN_DISP(game->graph);
    
    _texture_z_light_fog_prim(game->graph);
    _texture_z_light_fog_prim_xlu(game->graph);
    
    if(thisx->camera_position.z < 1500.0f &&
       fabsf(thisx->camera_position.x) < 100.0f + thisx->camera_position.z) {
	
	gSPSegment(NEXT_DISP, ANIME_TEXTURE_1_SEGMENT, SEGMENT_TO_KSEG0(  /* 目アニメ */
	    bm_eye_tex_no[this->work[BM_EYE_NO]]));
	
	Si2_draw_SV(game, (Rigid_ModelPointer *)this->skeleton.list,
		    this->skeleton.now_joint,
		    this->skeleton.model_num,
		    &bm_draw_sub,
		    &bm_draw_sub2,
		    this);
    }

/* 親がすべきこと */
    
    Fishing_Obj_disp(game_play); /* XLU_DISP使用の為,先に描画 */
    
    Fishing_Eff_disp(
	(Fishing_Eff *)game_play->special_effect,
	game_play);
    
    Minnow_disp(game_play);
    
    backwater_disp(game_play);

    if(lure_bgm_time) {
	lure_bgm_time --;
	if(lure_bgm_time == 0) {
/*	    
	    if(ZCommonGet(zelda_time) >= CHANGE_TIME(6.00f) &&
	       ZCommonGet(zelda_time) < CHANGE_TIME(19.00f)) {
		Na_NscSetCtrlFlag( NA_NS_TRIG_EVENING, NA_NS_CTRL_STOP );*/
		if(AGE != 1) { /* 17歳 */
		    Na_StartBgm(NA_BGM_KAKARIKO_ADULT);  /* BGM  */
		} else {
		    Na_StartBgm(NA_BGM_KAKARIKO_KID);  /* BGM  */
		}
#if 0		
		audio_flag = 0;
	    } else {
		Na_NscInitStart( game_play->sound_info.environment ); /* 環境音を鳴らす*/
		Na_NscSetCtrlFlag( NA_NS_TRIG_EVENING, NA_NS_CTRL_START );
		
		audio_flag = 2;
	    }
#endif
#if 0	
	    if(KAZ(5) == 0) {
#endif		
		if(AGE != 1) { /* 17歳 */
		    Na_StartBgm(NA_BGM_KAKARIKO_ADULT);  /* BGM  */
		} else {
		    Na_StartBgm(NA_BGM_KAKARIKO_KID);  /* BGM  */
		}
#if 0		
	    } else if(KAZ(5) == 1) {
		Na_StartBgm(NA_BGM_ZORA);  /* BGM  */
	    }
#endif	    
	}
#if 0	
	else {
	    Na_StopBgm(1);  /*  SE BGM */
	}
#endif	
    }
    
#if 0
    /* BGM＆環境音制御 */
    switch(audio_flag) {
    case 0:
	if(ZCommonGet(zelda_time) >= CHANGE_TIME(19.0f)) {
	    Na_StopBgm(240);  /*  SE BGM */
	    audio_flag = 1;
	}
	break;
	
    case 1:
	if(ZCommonGet(zelda_time) >= CHANGE_TIME(19.10f)) {
	    Na_NscInitStart( game_play->sound_info.environment ); /* 環境音を鳴らす*/
	    Na_NscSetCtrlFlag( NA_NS_TRIG_EVENING, NA_NS_CTRL_START );
	    audio_flag = 2;
	}
	break;
	
    case 2:
	if(ZCommonGet(zelda_time) >= CHANGE_TIME(6.00f)) {
	    Na_NscSetCtrlFlag( NA_NS_TRIG_EVENING, NA_NS_CTRL_STOP );
	    
	    if(AGE != 1) { /* 17歳 */
		Na_StartBgm(NA_BGM_KAKARIKO_ADULT);  /* BGM  */
	    } else {
		Na_StartBgm(NA_BGM_KAKARIKO_KID);  /* BGM  */
	    }
	    audio_flag = 0;
	}
	break;
    }
#endif
    
    if(fishing_game_mode && rod_disp) {
	/* fishing_time ++;  *//* 累計時間 */
/* 	lure_move(this, game_play); */
	
	rod_draw(game_play);

/*  	PRINTF("LINE G %f\n",line_G);  */
	
	line_control2(&line_pos[0]);
	
	line_control(game_play,
		     &line_base_pos,
		     &line_pos[0],
		     &line_angle[0],
		     &line_spd[0]
	    );

	/* ルアーと糸の表示 */
	fishing_draw(game_play,
		     &line_pos[0],
		     &line_angle[0]
	    );
	
	old_stick_x = Pad_stick_x();
	old_stick_y = Pad_stick_y();
    }

    rod_disp = 1;

    /* 水槽表示 */
    Matrix_translate(/* GREG(20)+ */130.0f,/*  GREG(21)+ */40.0f, /* GREG(22)+ */1280.0f + 20.0f, SET_MTX);
    Matrix_scale(/* (float)GREG(23)*0.01f + */ 0.08f,
		 /* (float)GREG(24)*0.01f + */ 0.12f,
		 /* (float)GREG(25)*0.01f + */ 0.13f + 0.01f,
		 MULT_MTX);
    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(NEXT_DISP, turi_suisou_model);
    gSPDisplayList(NEXT_POLY_XLU_DISP, turi_suisou_modelT);
    
    if(fishing_game_mode && lure_type == LURE_TYPE_WORM) { /* ワームは半透明だから後で描く */
	worm_disp(game_play);
    }
    CLOSE_DISP(game->graph);
}



/*
   makemask6105 rom
   nload -b 0xb3ff0000 rom
   nload -b 0xb3ff0000 -M rom
   nice -20 nload -v -b 0xb3ff0000 -M rom
   cp shape/zelda_fishing/zelda_fishing.o Fish.o
   
   mdlcnv soft37@ot29 basu.mdl basu.str bass
   mdlcnv soft37@ot29 nz_namazu.mdl nz_namazu.str snakehead

   cp /auto/idg10/disk2/soft37/SRD_DATA37/fs/fs_matsu*.* .
   
   cp /auto/ot29/usr/people/soft37/SRD_DATA/motion/fish/basu*.* .
   cp /auto/ot29/usr/people/soft37/SRD_DATA/motion/fish/nz_namazu*.* .
   
   
 */

#if 0
/*G_IM_FMT_RGBA G_IM_SIZ_16b 32 * 16 */
unsigned short test_rua_lure_txt[]={
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd6b, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d, 0x318d,  /*< 0>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd29, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53, 0x4a53,  /*< 1>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd29, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319, 0x6319,  /*< 2>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd6b, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf, 0x7bdf,  /*< 3>*/
	0xf801, 0xf801, 0xf8c7, 0xfbdd, 0xfe2d, 0xfbdd, 0xf8c7, 0xf801, 0xfa95, 0xfd6b, 0x94a5, 0x94a5, 0x94a5, 0xc5c1, 0x94a5, 0x94a5, 0x94a5, 0xc5c1, 0x94a5, 0x94a5, 0x94a5, 0x94a5, 0x94a5, 0xc5c1, 0x94a5, 0x94a5, 0x94a5, 0x94a5, 0xc5c1, 0x94a5, 0x94a5, 0x94a5,  /*< 4>*/
	0xf801, 0xf801, 0xfbdd, 0x3147, 0x0001, 0x3145, 0xfc1b, 0xf801, 0xfa95, 0xfd29, 0xad6b, 0xc5c1, 0xad6b, 0xad6b, 0xad6b, 0xad6b, 0xad6b, 0xad6b, 0xc5c1, 0xc5c1, 0xad6b, 0xad6b, 0xc5c1, 0xad6b, 0xc5c1, 0xc5c1, 0xad6b, 0xc5c1, 0xad6b, 0xad6b, 0xad6b, 0xad6b,  /*< 5>*/
	0xf801, 0xf801, 0xfe2d, 0x0001, 0x0001, 0x0001, 0xfe61, 0xf801, 0xfa95, 0xfd6b, 0xce31, 0xce73, 0xc631, 0xce73, 0xce73, 0xc5c1, 0xce73, 0xc5c1, 0xc5c1, 0xce73, 0xc5c1, 0xce73, 0xc5c1, 0xce73, 0xce73, 0xce73, 0xce73, 0xce73, 0xc5c1, 0xc5c1, 0xce73, 0xce73,  /*< 6>*/
	0xf801, 0xf801, 0xfbdd, 0x3947, 0x0001, 0x3145, 0xfc1b, 0xf801, 0xfa95, 0xfd6b, 0xc5c1, 0xc5c1, 0xe739, 0xe739, 0xe739, 0xe739, 0xe739, 0xe739, 0xe739, 0xe739, 0xc5c1, 0xe739, 0xe739, 0xe739, 0xc5c1, 0xe739, 0xe739, 0xe739, 0xe739, 0xe739, 0xc5c1, 0xe739,  /*< 7>*/
	0xf801, 0xf801, 0xf8c7, 0xfbdd, 0xfe2d, 0xfbdd, 0xf8c7, 0xf801, 0xfa95, 0xfd6b, 0xffbd, 0xffff, 0xffff, 0xffff, 0xffff, 0xc5c1, 0xffff, 0xffff, 0xc5c1, 0xffff, 0xffff, 0xffff, 0xffff, 0xc5c1, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xc5c1, 0xffff,  /*< 8>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd29, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xc5c1, 0xffff, 0xc5c1, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xc5c1, 0xffff, 0xffff, 0xffff, 0xffff,  /*< 9>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd29, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,  /*<10>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd6b, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,  /*<11>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd6b, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,  /*<12>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd29, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,  /*<13>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd6b, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,  /*<14>*/
	0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xf801, 0xfa95, 0xfd6b, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff,  /*<15>*/
};
/* 4 vertices */
static Vtx test_rua_all_v[]={
    {  -100, -100, 00,0,    0, 1024, 0, 127, 0, 0},   /* v0 p1/V1 used 2 times */ 
    {   100, -100, 00,0, 1024, 1024, 0, 127, 0, 0},   /* v1 p1/V2 used 1 times */ 
    {   100,  100, 00,0, 1024 ,   0, 0, 127, 0, 0},   /* v2 p1/V3 used 2 times */ 
    {  -100,  100, 00,0,    0,    0, 0, 127, 0, 0},   /* v3 p2/V3 used 1 times */ 
};
Gfx test_rua_body_model[]={

/* ======== rua_body ========*/
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPTexture(0xFFFF, 0xFFFF, 0, 0, G_ON),
	gsDPLoadMultiBlock(test_rua_lure_txt, 0, 0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
		G_TX_CLAMP, G_TX_CLAMP, 5, 4, 0, 0),
	gsDPSetCombineLERP(
		TEXEL0, 0, SHADE, 0,
		0, 0, 0, 1,
		COMBINED, 0, PRIMITIVE, 0,
		0, 0, 0, COMBINED
	),
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
	gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
	gsSPSetGeometryMode(G_LIGHTING | G_CULL_BACK | G_FOG),
	gsDPSetPrimColor( 0, 0, 255, 255, 255, 255),
	gsSPVertex(&test_rua_all_v[0],4,0),
        gsSP1Triangle(0, 1, 2, 0),
        gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

#endif
