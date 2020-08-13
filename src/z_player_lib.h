/*
 * $Id: z_player_lib.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 * $Log: z_player_lib.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.30  1998/10/14 08:06:02  iwawaki
 * *** empty log message ***
 *
 * Revision 1.29  1998-10-02 01:33:13+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.28  1998-09-30 19:54:30+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.27  1998-09-07 14:03:26+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.26  1998-09-02 00:31:30+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1998-09-01 00:31:46+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.24  1998-08-22 18:38:22+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.23  1998-08-20 18:31:50+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1998-08-01 15:26:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.21  1998-07-25 22:56:50+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1998-07-22 23:02:57+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.19  1998-07-13 22:53:33+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1998-07-10 23:08:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1998-07-07 22:57:02+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1998-06-16 23:06:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.15  1998-06-15 22:57:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1998-06-12 23:25:21+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1998-06-10 22:59:00+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1998-06-05 16:50:59+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1998-05-29 20:10:55+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1998-05-13 23:00:52+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.9  1998/05/07 14:20:36  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1998/04/25 11:44:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1998/04/07 14:12:03  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1998/04/04  11:55:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1998/03/18  01:57:25  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1998/03/17  13:53:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1998/03/16  04:43:54  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1998/03/10  11:24:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.1  1998/03/10  07:37:34  iwawaki
 * Initial revision
 *
 *
 * */


#ifndef INCLUDE_Z_PLAYER_LIB_H
#define INCLUDE_Z_PLAYER_LIB_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	プレイヤーライブラリー集
 *
 ************************************************************************/
#include "z_player.h"
#include "z_player_shape.h"

/*-----------------------------------------------------------------------
 *
 *	マクロ
 *
 *----------------------------------------------------------------------*/
/*
 * アニメーション情報
 */
#define	P_MAX_JOINT		(21+1)
#define	P_GLOBAL_JOINT		(0+1)
#define P_HEAD_JOINT     	(10+1)
#define	P_NECK_JOINT		P_HEAD_JOINT
#define	P_BODY_JOINT		(9+1)
#define	P_L_HAND_JOINT		(15+1)
#define	P_SWORD_JOINT		(15+1)
#define	P_R_HAND_JOINT		(18+1)
#define	P_CARRY_JOINT		(19+1)
#define	P_WAIST_JOINT		(1+1)
#define P_L_FOOT_JOINT          (8+1)
#define P_R_FOOT_JOINT          (5+1)
#define P_L_LEG_A_JOINT		(6+1)
#define P_L_LEG_B_JOINT		(7+1)
#define P_R_LEG_A_JOINT         (3+1)
#define P_R_LEG_B_JOINT         (4+1)
#define P_HAT_JOINT     	(11+1)
#define P_CHEST_JOINT     	(20+1)
#define P_L_ARM_A_JOINT     	(13+1)
#define P_L_ARM_B_JOINT     	(14+1)
#define P_R_ARM_A_JOINT     	(16+1)
#define P_R_ARM_B_JOINT     	(17+1)

#define	P_SKELETON_OFFSET_X		-57.400002f	
#define	P_CHILD_SKELETON_OFFSET_X	0.000000f	
#define	P_SKELETON_OFFSET_Y		3377.100098f	
#define	P_CHILD_SKELETON_OFFSET_Y	2376.000000f	
#define	P_SKELETON_OFFSET_Z		0.000000f	
#define	P_CHILD_SKELETON_OFFSET_Z	0.000000f	

#define	P_LEG_A_LENGTH			1304.0f	
#define	P_LEG_A_LENGTH_CHILD		695.0f
#define	P_LEG_B_LENGTH			1265.0f
#define	P_LEG_B_LENGTH_CHILD		826.0f
#define	P_LEG_A_SCALE_LENGTH		(P_LEG_A_LENGTH * P_SCALE)
#define	P_LEG_A_SCALE_LENGTH_CHILD	(P_LEG_A_LENGTH_CHILD * P_SCALE)
#define	P_LEG_B_SCALE_LENGTH		(P_LEG_B_LENGTH * P_SCALE)
#define	P_LEG_B_SCALE_LENGTH_CHILD	(P_LEG_B_LENGTH_CHILD * P_SCALE)
    
/*-----------------------------------------------------------------------
 *
 *	プレイヤー年齢別データ
 *
 *----------------------------------------------------------------------*/
/*
 * 骨格用データ
 */
extern Rigid_Mdl_Info	*skeleton_list[];

/*
 * シェイプリスト
 */
enum {
    L_LHAND_MODEL,		/* 左手 */
    L_LHANDG_MODEL,
    L_MIDDLE_SWORD_MODEL,
    L_LSWORDHAND_MODEL,
    L_LONGSWORD_MODEL,
    L_HAMMERHAND_MODEL,
    L_BOOMHAND_MODEL,
    L_BOTTLE_HAND_MODEL,
    L_RHAND_MODEL,		/* 右手 */
    L_RHANDG_MODEL,
    L_RSHIELDHAND_MODEL,
    L_BOW_RHAND_MODEL,
    L_PACHIHAND_MODEL,
    L_ELF_OKARIHAND_MODEL,
    L_OKARIHAND_MODEL,
    L_HOOK_HAND_MODEL,
    L_CARRYSWORD_MODEL,		/* 背負い物 */
    L_SWORDCASE_MODEL,
    CARRY_ALL_MODEL,
    CARRY_ALLB_MODEL,
    L_WAIST_MODEL,		/* 腰 */
    L_BAG_WAIST_MODEL
};

/*
 * 表情タイプ
 */
enum {
    P_FACE_NORMAL,
    P_FACE_CLOSE_1,
    P_FACE_CLOSE_2,
    P_FACE_NORMAL_2,
    P_FACE_CLOSE_1_2,
    P_FACE_CLOSE_2_2,
    P_FACE_UPPER,
    P_FACE_DOWN,
    P_FACE_DAMAGE,
    P_FACE_SURPRISE,
    P_FACE_RIGHT,
    P_FACE_LEFT,
    P_FACE_REGRET,
    P_FACE_SLEEPY,
    P_FACE_FINSH,
    P_FACE_MAX
};
/*
 * 目アニメーションパターン
 */
enum {
    P_EYE_1,
    P_EYE_2,
    P_EYE_3,
    P_EYE_4,
    P_EYE_5,
    P_EYE_6,
    P_EYE_7,
    P_EYE_8
};
/*
 * 口アニメーションパターン
 */
enum {
    P_MOUTH_1,
    P_MOUTH_2,
    P_MOUTH_3,
    P_MOUTH_4
};

/*-----------------------------------------------------------------------
 *
 *	表情クラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	eye;
    unsigned char	mouth;
} Face_Pattern;


/*-----------------------------------------------------------------------
 *
 *	プレイヤー性能データ設定
 *
 *----------------------------------------------------------------------*/
extern void player_performance_init(
    Game_play    *game_play,
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	注目モードチェック
 *
 *----------------------------------------------------------------------*/
extern int anchor_mode_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー状態チェック
 *
 *----------------------------------------------------------------------*/
extern int player_action_check(
    Game_play    *game_play,
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー状態チェック
 *
 *----------------------------------------------------------------------*/
extern int player_demo_check(
    Game_play *game_play
);

/*-----------------------------------------------------------------------
 *
 *	少年のハイラル盾モードチェック
 *
 *----------------------------------------------------------------------*/
extern int child_hyral_shield_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーアイテム別シェイプデータ
 *
 *----------------------------------------------------------------------*/
extern int item_shape_type_set(
    Player_actor *this,
    int 	 A_item
);

/*-----------------------------------------------------------------------
 *
 *	盾構えシェイプセット
 *
 *----------------------------------------------------------------------*/
extern void defense_shape_type_set(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーシェイプセット
 *
 *----------------------------------------------------------------------*/
extern void shape_set(
    Player_actor *this,
    int 	 type
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーシェイプタイプセット
 *
 *----------------------------------------------------------------------*/
extern void shape_type_set(
    Player_actor *this,
    int 	 type
);

/*-----------------------------------------------------------------------
 *
 *	一時アイテムキャンセル
 *
 *----------------------------------------------------------------------*/
extern void now_item_cancel(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	アイテム変更チェック
 *
 *----------------------------------------------------------------------*/
extern void player_ability_set(
    Game_play    *game_play,
    Player_actor *this
);

#define	player_ability_init(game_play, this)	player_ability_set((game_play), (this))

/*-----------------------------------------------------------------------
 *
 *	空ビンへの変更
 *
 *----------------------------------------------------------------------*/
extern void bottle_item_change(
    Game_play    *game_play,
    Player_actor *this,
    int		 next_H_item,
    int		 next_item_no
);

/*-----------------------------------------------------------------------
 *
 *	注目キャンセル
 *
 *----------------------------------------------------------------------*/
extern void anchor_cancel(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	注目解除設定
 *
 *----------------------------------------------------------------------*/
#define	NOW_CAMERA	Gama_play_get_camera(game_play, 0)

extern void anchor_reset(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	強制注目セット
 *
 *----------------------------------------------------------------------*/
extern void to_anchor_set(
    Game_play *game_play,
    Actor     *anchor_actor
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー乗馬モードチェック
 *
 *----------------------------------------------------------------------*/
extern int player_ride_horse_check(
    Game_play    *game_play
);

/*-----------------------------------------------------------------------
 *
 *	的当て屋モード初期設定
 *
 *----------------------------------------------------------------------*/
extern int to_bow_game_set(
    Game_play *game_play,
    int	      num
);

/*-----------------------------------------------------------------------
 *
 *	炎着きデクの棒ヒットチェック
 *
 *----------------------------------------------------------------------*/
extern int player_fire_stick_hit_check(
    Game_play *game_play,
    xyz_t     *pos,
    float     r,
    float     h
);

/*-----------------------------------------------------------------------
 *
 *	グローブチェック
 *
 *----------------------------------------------------------------------*/
enum {
    P_GROVE_TYPE_CHILD,
    P_GROVE_TYPE_BOY,		/* BURONZ */
    P_GROVE_TYPE_SILVER,
    P_GROVE_TYPE_GOLD
};
    
extern int player_grove_check(void);

/*-----------------------------------------------------------------------
 *
 *	お面チェック
 *
 *----------------------------------------------------------------------*/
extern int mask_check(
    Game_play *game_play
);

/*-----------------------------------------------------------------------
 *
 *	お面解除
 *
 *----------------------------------------------------------------------*/
extern int mask_cancel(
    Game_play *game_play
);

/*-----------------------------------------------------------------------
 *
 *	ミラーシールドチェック
 *
 *----------------------------------------------------------------------*/
extern int mirror_shield_check(
    Game_play *game_play
);

/*-----------------------------------------------------------------------
 *
 *	ミラーシールド装備チェック
 *
 *----------------------------------------------------------------------*/
extern int mirror_shield_set_check(
    Game_play *game_play
);

/*-----------------------------------------------------------------------
 *
 *	魔法モードチェック
 *
 *----------------------------------------------------------------------*/
extern int magic_item_check(
    Player_actor *this,
    int		 A_item
);

/*-----------------------------------------------------------------------
 *
 *	フックショットモードチェック
 *
 *----------------------------------------------------------------------*/
extern int hook_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	フックッショット発射中チェック
 *
 *----------------------------------------------------------------------*/
extern int hook_shoot_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	剣モードチェック
 *
 *----------------------------------------------------------------------*/
extern int sword_item_check(
    int A_item
);
extern int sword_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	長剣モードチェック
 *
 *----------------------------------------------------------------------*/
extern int longsword_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	折れたロングソードチェック
 *
 *----------------------------------------------------------------------*/
extern int break_longsword_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	ビンモードチェック
 *
 *----------------------------------------------------------------------*/
extern int bottle_item_check(
    Player_actor *this,
    int 	 A_item
);
extern int bottle_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	爆弾モードチェック
 *
 *----------------------------------------------------------------------*/
extern int bom_item_check(
    Player_actor *this,
    int 	 A_item
);
extern int bom_check(
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	ノーマル，戦闘モード切り替え可能チェック
 *
 *----------------------------------------------------------------------*/
extern int nom2figh_check(
    Player_actor *this,
    int		 A_item
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーコンディションチェック
 *
 *----------------------------------------------------------------------*/
extern int player_condition_check(
    Game_play *game_play
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーシェイプタイプデータ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	anime_type;
    unsigned char	L_hand;
    unsigned char	R_hand;
    unsigned char	carry;
    unsigned char	waist;
} Player_Shape_Type;

extern Player_Shape_Type	player_shape_type[];

/*-----------------------------------------------------------------------
 *
 *	プレイヤーシェイプデータ
 *
 *----------------------------------------------------------------------*/
extern Gfx	**player_shape_list[];

extern Gfx	*l_Lhand_model_data[];
extern Gfx	*l_boomhand_model_data[];
extern Gfx	*l_longsword_model_data[];
extern Gfx	*l_LhandG_model_data[];
extern Gfx	*l_RhandG_model_data[];
    
/************************************************************************
 *
 *	プレイヤーシェイプ表示
 *
 ************************************************************************/
extern Gfx	set_cull_back_model[];
extern Gfx	set_cull_front_model[];

extern void Player_shape_draw(
    Game 	       *game,
    Rigid_ModelPointer *skeleton_list,
    s_xyz	       *joint,
    int		       model_num,
    int		       LOD,
    int		       suit,
    int		       boots,
    int  	       face_pattern,
    int 	       (*before_draw_proc)(Game *, int, Gfx **, xyz_t *, s_xyz *, void *),
    void 	       (*after_draw_proc)(Game *, int, Gfx **, s_xyz *, void *),
    void	       *p
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー表示用関節操作処理
 *
 *----------------------------------------------------------------------*/
extern int player_before_draw_joint_move(
    Game  *game,
    int   jyoint_no,
    Gfx   **shape,
    xyz_t *t,
    s_xyz *r,
    void  *p
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー表示用関数
 *
 *----------------------------------------------------------------------*/
extern int player_before_draw(
    Game  *game,
    int   jyoint_no,
    Gfx   **shape,
    xyz_t *t,
    s_xyz *r,
    void  *p
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー表示用関数（ハイグレードモデル）
 *
 *----------------------------------------------------------------------*/
extern int before_high_draw(
    Game  *game,
    int   jyoint_no,
    Gfx   **shape,
    xyz_t *t,
    s_xyz *r,
    void  *p
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー表示用関数（表示無し）
 *
 *----------------------------------------------------------------------*/
extern int before_no_draw(
    Game  *game,
    int   jyoint_no,
    Gfx   **shape,
    xyz_t *t,
    s_xyz *r,
    void  *p
);

/*----------------------------------------------------------------------------
 *
 *	剣攻撃コリジョンセット
 *
 *---------------------------------------------------------------------------*/
extern int sword_attack_collision_set(
    Game_play   *game_play,
    ClObjSwrd	*at_info,
    SWORD_POS_S *prev_pos,
    xyz_t       *new_top_pos,
    xyz_t       *new_root_pos
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーゲットアイテム表示用関数
 *
 *----------------------------------------------------------------------*/
extern void get_item_draw(
    Game_play    *game_play,
    Player_actor *this
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー表示用関数
 *
 *----------------------------------------------------------------------*/
extern void player_after_draw(
    Game  *game,
    int   jyoint_no,
    Gfx   **shape,
    s_xyz *r,
    void  *p
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーシェイプ転送
 *
 *----------------------------------------------------------------------*/
extern void Player_shape_read(
    Game_play *game_play,
    char      *segment
);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーシェイプ表示
 *
 *----------------------------------------------------------------------*/
extern void Player_Shape_Draw(
    Game_play     *game_play,
    char          *segment,
    Skeleton_Info *skeleton,
    xyz_t	  *position,
    s_xyz	  *angle,
    float	  scale,
    int		  item,
    int		  suit,
    int		  shield,
    int		  boots
);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_player_lib.h end ***/
