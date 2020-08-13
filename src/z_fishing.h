/* $Id: z_fishing.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $ */
/* $Log: z_fishing.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.47  1998/10/19 13:20:19  morita
 * *** empty log message ***
 *
 * Revision 1.46  1998-09-28 23:44:49+09  morita
 * *** empty log message ***
 *
 * Revision 1.45  1998-09-26 22:36:35+09  morita
 * *** empty log message ***
 *
 * Revision 1.44  1998-09-25 18:26:51+09  morita
 * 新コリジョン
 *
 * Revision 1.43  1998-09-25 00:32:38+09  morita
 * *** empty log message ***
 *
 * Revision 1.42  1998-09-24 17:43:25+09  morita
 * *** empty log message ***
 *
 * Revision 1.41  1998-09-21 20:31:57+09  morita
 * *** empty log message ***
 *
 * Revision 1.40  1998-09-21 17:34:38+09  morita
 * *** empty log message ***
 *
 * Revision 1.39  1998-09-19 17:45:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.38  1998-09-18 22:12:14+09  morita
 * *** empty log message ***
 *
 * Revision 1.37  1998-09-18 17:12:35+09  morita
 * *** empty log message ***
 *
 * Revision 1.36  1998-09-18 00:13:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.35  1998-09-15 00:05:19+09  morita
 * *** empty log message ***
 *
 * Revision 1.34  1998-09-11 21:39:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.33  1998-09-11 18:42:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.32  1998-09-11 00:31:43+09  morita
 * *** empty log message ***
 *
 * Revision 1.31  1998-09-05 16:57:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.30  1998-09-04 20:26:48+09  morita
 * *** empty log message ***
 *
 * Revision 1.29  1998-09-03 23:59:11+09  morita
 * *** empty log message ***
 *
 * Revision 1.28  1998-09-02 22:05:12+09  morita
 * *** empty log message ***
 *
 * Revision 1.27  1998-09-01 18:11:53+09  morita
 * *** empty log message ***
 *
 * Revision 1.26  1998-08-31 22:19:10+09  morita
 * *** empty log message ***
 *
 * Revision 1.25  1998-08-29 23:29:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.24  1998-08-29 17:49:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.23  1998-08-26 21:05:30+09  morita
 * *** empty log message ***
 *
 * Revision 1.22  1998-08-26 17:54:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.21  1998-08-24 20:33:29+09  morita
 * *** empty log message ***
 *
 * Revision 1.20  1998-08-22 23:14:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.19  1998-08-21 22:03:42+09  morita
 * *** empty log message ***
 *
 * Revision 1.18  1998-08-20 22:09:56+09  morita
 * *** empty log message ***
 *
 * Revision 1.17  1998-08-18 21:17:01+09  morita
 * *** empty log message ***
 *
 * Revision 1.16  1998-08-13 22:42:47+09  morita
 * *** empty log message ***
 *
 * Revision 1.15  1998-08-13 15:47:09+09  morita
 * *** empty log message ***
 *
 * Revision 1.14  1998-08-12 22:19:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.13  1998-08-10 20:30:51+09  morita
 * *** empty log message ***
 *
 * Revision 1.12  1998-08-08 21:22:48+09  morita
 * *** empty log message ***
 *
 * Revision 1.11  1998-08-06 18:55:44+09  morita
 * *** empty log message ***
 *
 * Revision 1.10  1998-08-05 23:18:10+09  morita
 * *** empty log message ***
 *
 * Revision 1.9  1998-08-05 14:50:02+09  morita
 * *** empty log message ***
 *
 * Revision 1.8  1998-08-04 18:07:18+09  morita
 * *** empty log message ***
 *
 * Revision 1.7  1998-08-03 23:18:18+09  morita
 * *** empty log message ***
 *
 * Revision 1.6  1998-08-01 23:11:24+09  morita
 * *** empty log message ***
 *
 * Revision 1.5  1998-07-31 17:54:01+09  morita
 * *** empty log message ***
 *
 * Revision 1.4  1998-04-22 23:17:56+09  morita
 * *** empty log message ***
 *
 * Revision 1.3  1998/04/21 14:29:53  morita
 * *** empty log message ***
 *
 * Revision 1.2  1998/04/20 14:35:05  morita
 * *** empty log message ***
 *
 * Revision 1.1  1998/04/20 07:19:30  morita
 * Initial revision
 *
 */
   
/*-----------------------------------------------------------------------------
 * z_fishing.h
 * モーファ
 * Program:K.Morita
 * 1998/3/10
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_FISHING_H
#define INCLUDE_Z_FISHING_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_basic.h"
#include"z_collision_type.h"

/*-----------------------------------------------------------------------
 *
 *	釣り
 *
 *----------------------------------------------------------------------*/
#define FISHING_EFF_SIZE  100

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} rgb_u8_fs;

typedef struct {
    xyz_t               pos;
    xyz_t               vec;
    xyz_t               acc;
    u8                  mode;
    u8                  count;
    rgb_u8_fs           prim;
    short               prim_a;
    short               work[2];
    float               fwork[4];
} Fishing_Eff;

/* name */
#define FS_HAMON     (1)  /* 波紋 */
#define FS_MIZU      (2)  /* 飛散る水 */
#define FS_SMOKE     (3)  /* 水底煙 */
#define FS_BUBBLE    (4)  /* 泡 （水槽用）*/
#define FS_RAIN      (5)  /* 雨実験 */
#define FS_OYAJI_CAP    (6)  /* 親父のボウシ */
#define FS_RAIN_HAMON   (7)  /* 雨波紋実験 */
#define FS_RAIN_HAMON_2 (8)  /* 雨波紋実験 地面用 */

/*
 * work
 */
#define FISHING_EFF_STAT  (0)
#define FISHING_EFF_A_AD  (1) /* HAMON */
/*
 *fwork
 */
#define FISHING_EFF_SCALE     (0)
#define FISHING_EFF_SCALE_S   (1)
#define FISHING_EFF_SCALE_SP  (2)

/* BUBBLE */
#define FISHING_EFF_SPEEDF    (1)
/* MIZU */
#define FISHING_EFF_COL       (1)
#define FISHING_EFF_SCALE_Y   (2)
/* RAIN */
#define FISHING_EFF_XANG   (1)
#define FISHING_EFF_YANG   (2)
#define FISHING_EFF_ZANG   (3)



/* 簡易障害物 */
#define FISHING_OBJ_SIZE  140
typedef struct {
    xyz_t               pos;
    xyz_t               ang;
    xyz_t               camera_pos;
    float               scale;
    short               work;
    float               fwork;
    u8                  mode;
    short               count;
    u8                  cull_flag;
    float               cull_z;
} Fishing_Obj;

/* name */
#define FS_ASHI      (1)  /* 葦   */
#define FS_LILY      (2)  /* はす */
#define FS_ISHI      (3)  /* 石   */
#define FS_KUI       (4)  /* 杭   */


typedef struct {
    u8 mode;
    short x;
    short y;
    short z;
} Fishing_Obj_Data;

/* 簡易子魚 */
#define MINNOW_SIZE  60

typedef struct {
    u8                  mode;
    short               count;
    
    xyz_t               pos;
    xyz_t               t_pos;
    xyz_t               camera_pos;
    float               speedF;
    float               anime_range;
    float               anime_frame;
    float               anime_spd;
    float               anime_scale;
    s_xyz               ang;
    short               turn_a;
    u8                  cull_flag;
} Minnow;



/* イニシャル用 */
typedef struct {
    u8     kind;
    s_xyz  pos;     /* 位置 */
    u8     size;    /* 大きさ */
    float  brain;   /* 賢さ */ 
} Fishing_Fish_Data;

#define FISH_KIND_BASS      (0)
#define FISH_KIND_SNAKEHEAD (1)

#define FISHING_COLL_KAZU  (9+3) /* 汎用当り判定の球の数 */

typedef struct Fishing_actor_s{
    Actor		actor; 			/* 基底クラス */


    void		(*process)(		/* 処理関数ポインタ */
	struct Fishing_actor_s *,
	Game_play *
    );

    u8                  kind;
    u8                  power_move;
    u8                  yowari;                 /* 弱った */
    short               yowari_ya;              /* 弱った角度 */
    u8                  yowari_p;               /* 弱った角度に変化する速さ */

    u8                  hikiyose_power;         /* 竿強引にひいた */
    
    short               move_mode;              /* 動作状態 */
    short               move_mode_S;            /* 動作状態保存用 */
    short               work[15];               /* 汎用変数 */
    short		timer[4];		/* タイマー */
    float               fwork[7];              /* 汎用変数 */

    short               wall_hit;               /* 壁当り補正時間 */
    short               not_eat_time;
    short               wait_time;
    float               brain;                  /* ヒット確率 */
    float               size;

    float               angle_sp;
    xyz_t               target_pos;
    xyz_t               pl_catch_pos;

    short               body_ya[3];

    u8                  bubble_time;

    u8                  message_mode;
    u8                  message_wait;
    u8                  demo_mess_sel;
    
    Skeleton_Info	skeleton;		/* スケルトンシェイプクラス */
    
    Light_list		*light_list;	/* ライトデータリストポインタ */
    Light_data		light_data;	/* ライトデータ */
    
    ClObjJntSph         ishi_jntsph_info;  /* オブジェ石当り用 */       
    ClObjJntSphElem     jntsph_elem[FISHING_COLL_KAZU];
} Fishing_actor;

/*---------------------------------------------------------------------------
 *
 *	プロフィール
 *
 *--------------------------------------------------------------------------*/
//extern Actor_profile Fishing_Profile;

/************************************************************************
 *
 *	初期設定処理
 *
 ************************************************************************/
//extern void Fishing_actor_ct(Actor *thisx, Game *game);

/************************************************************************
 *
 *	デストラクター
 *
 ************************************************************************/
//extern void Fishing_actor_dt(Actor *thisx, Game *game);

/************************************************************************
 *
 *	 動作処理
 *
 ************************************************************************/
//extern void Fishing_actor_move(Actor *thisx, Game *game);

/************************************************************************
 *
 *	表示処理
 *
 ************************************************************************/
//extern void Fishing_actor_draw(Actor *thisx, Game *game);

extern Rigid_Mdl_Info_SV fs2_jump_mdl_info;
extern SoftAnimTblInfo2 fs2_jump_soft_anim_tbl_info;
extern SoftAnimTblInfo2 fs2_swim_soft_anim_tbl_info;

extern Rigid_Mdl_Info_SV basu_mdl_info;
extern SoftAnimTblInfo2 basu_soft_anim_tbl_info;
extern Rigid_Mdl_Info_SV nz_namazu_mdl_info;
extern SoftAnimTblInfo2 nz_namazu_soft_anim_tbl_info;

/* extern Gfx bass_DISP_MODE[]; */

extern Gfx fs_mizu_DISP_MODE[];
extern Gfx fs_mizu_modelT[];

extern Gfx fs_smoke_DISP_MODE[];
extern Gfx fs_smoke_modelT[];

extern Gfx fs_bubble_DISP_MODE[];
extern Gfx fs_bubble_model[];

/*
extern Gfx mo_core_model[];
*/
extern Gfx fs_line_MODE[];
extern Gfx fs_line_model[];
extern Gfx fs_rain_model[];
extern Gfx fs_rain_sibuki_DISP_MODE[];
extern Gfx fs_rain_sibuki_model[];

extern Gfx rod_MODE[];
extern Gfx rod_model[];

extern unsigned short hook_grip_0_txt[];
extern unsigned short hook_grip_1_txt[];
extern unsigned short hook_grip_2_txt[];

/* extern Gfx fishing_hook_model[]; */
extern Gfx rua_hari_model[];
extern Gfx rua_body_model[];

#define lure_hook_model  rua_hari_model 
#define lure_body_model  rua_body_model 

extern Gfx turi_hasu_DISP_MODE[];
extern Gfx turi_hasu_model[];

extern Gfx turi_kusa_DISP_MODE[];
extern Gfx turi_kusa_model[];

extern Gfx turi_isi_DISP_MODE[];
extern Gfx turi_isi_model[];

extern Gfx turi_kui_DISP_MODE[];
extern Gfx turi_kui_model[];

extern Gfx turi_suisou_model[];
extern Gfx turi_suisou_modelT[];

    
extern unsigned char fs_eye01_CI00_txt[];
extern unsigned char fs_eye02_CI00_txt[];
extern unsigned char fs_eye03_CI00_txt[];

extern Gfx fs_backwater_modelT[];

extern Gfx fs_minnow_DISP_MODE[];
extern Gfx fs_minnow_model[];

extern Gfx minnow_DISP_MODE[];
extern Gfx minnow_model[];

extern Gfx fs_cap_model[];
extern Gfx fs_zura_model[];



extern Rigid_Mdl_Info_SV	fs_matsu_mdl_info;

extern SoftAnimTblInfo2         fs_matsu_soft_anim_tbl_info;


extern void water_in_kankyo( Game_play *, int);

/* extern	Gfx		g_ripple_model[]; */
extern  Gfx             g_blast_model[]; 
extern unsigned char smoke1_1_txt[];

extern Gfx fs_ripple_DISP_MODE[];
extern Gfx fs_ripple_model[];

#if 0
extern Gfx mo_base_test[];
extern Gfx mo_body_1[];
extern Gfx mo_body_2[];
extern Gfx mo_body_3[];
extern Gfx mo_body_4[];
extern Gfx mo_body_5[];
extern Gfx mo_body_6[];
extern Gfx mo_body_7[];
extern Gfx mo_body_8[];
extern Gfx mo_body_9[];
extern Gfx mo_body_10[];

#else
extern Gfx worm_model[];
extern Gfx worm_DISP_MODE[];
#endif

extern Gfx	turibori_grp_sui_WTSCR1T[];

/* メッセージセット */
extern void
message_set( Game_play *, unshort , Actor * );
extern char
message_check( Message * );

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* INCLUDE_Z_FISHING_H */


/*** z_fishing.h ***/


