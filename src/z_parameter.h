/* $Id: z_parameter.h,v 1.1.1.1 2003/03/10 22:42:54 tong Exp $ */	
/* $Log: z_parameter.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:54  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.80  1998/10/10 13:56:30  soejima
 * *** empty log message ***
 *
 * Revision 1.79  1998-10-09 16:37:39+09  soejima
 * *** empty log message ***
 *
 * Revision 1.78  1998-10-08 23:08:35+09  soejima
 * *** empty log message ***
 *
 * Revision 1.77  1998-09-24 21:36:18+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/10/08  12:36:08  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_PARAMETER_H
#define INCLUDE_Z_PARAMETER_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif





/************************************************************************
 *									*
 *	ゼルダ６４ パラメーター						*
 *				1996年10月 8日(火曜日) 17時00分00秒 JST *
 *									*
 ************************************************************************/
typedef struct zelda_parameter_struct {
    View	view;			/* カメラ ビュー */
    
    Vtx_t	*parameter_frame_vtx;
    Vtx_t	*heartVtx;		/* ハート */

    char	*parameterSegment;	/* 常駐ＰＡＲＡＭＥＴＥＲセグメント */
    char	*do_actionSegment;	/* ＤＯアクションセグメント */
    char	*icon_itemSegment;	/* アイコンアイテムセグメント */
    char	*mapSegment;		/* ＭＡＰセグメント */
    char	map_palete[16*2];	/* ＭＡＰパレット */

    dma_t	dma;			/* メモリ転送関係 */
    dma_t	dma1;			/* メモリ転送関係 */
    dma_t	dma2;			/* メモリ転送関係 */
    OSMesgQueue	mq;			/*		  */
    OSMesg	m;			/*	  	  */

    irect	vw;			/* シザ─値（Top,Bottom,Left,Right) */

    short	do_action_flg;		/* ＤＯアクション 切替フラグ */
    unsigned short	do_action;		/* ＤＯアクション ポインタ */
    unsigned short	do_action_old;		/* ＤＯアクション ポインタＯＬＤ */
    float	do_action_rotate;	/* ＤＯアクション 回転カウンタ */
    short	navi_flag;		/* ナヴィフラグ */
    short	sp_action_flag;		/* 特別（Ｂ）アクション 切替フラグ */
    short	sp_action;		/* 特別（Ｂ）アクション ポインタ */


/*↓↓↓↓↓↓↓ 高畑使用 ↓↓↓↓↓↓↓*/
    short	dokidoki_meter;		/*  */
    short	now_mode;		/*  */
    short	dokidoki_prim[3];	/* ドキドキＰＲＩＭカラー */
    short	dokidoki_env[3];	/* ドキドキＥＮＶカラー */
    short	doki_prim_r[2];		/* ドキドキＰＲＩＭーＲ */
    short	doki_prim_g[2];		/* ドキドキＰＲＩＭーＧ */
    short	doki_prim_b[2];		/* ドキドキＰＲＩＭーＢ */
    short	doki_env_r[2];		/* ドキドキＥＮＶ─Ｒ */
    short	doki_env_g[2];		/* ドキドキＥＮＶ─Ｇ */
    short	doki_env_b[2];		/* ドキドキＥＮＶ─Ｂ */
    short	dokidoki_max;		/*  */
    short	active_heart_timer;	/*  */
    short	dokidoki_wait;		/*  */
    short	dokidoki_flag;		/*  */
/*↑↑↑↑↑↑↑ 高畑使用 ↑↑↑↑↑↑↑*/

    short	magic_mp;		/*             消費魔法量 */
    short	magic_frame;		/*             増減フレーム */

    short	rpc[4];			/* ルピー数 */

    unsigned char	lash_ct;		/* 鞭カウンタ */

    unsigned short	yabusame_score;		/* 流鏑馬得点 */
    unsigned short	yabusame_arrow;		/* 流鏑馬矢本数 */
    unsigned short	yabu_mode;		/* 流鏑馬内部状態 */
    unsigned short	yabu_score;		/* 流鏑馬内部得点 */

    unsigned short	fill_alpha;		/* ＦｉｌｌＲｅｃｔａｎｇｌｅ Ａｌｐｈａ値 */
    unsigned short	a_alpha;		/* Ａボタン Ａｌｐｈａ値 */
    unsigned short	b_alpha;		/* Ｂボタン Ａｌｐｈａ値 */
    unsigned short	c_alpha;		/* Ｃボタン Ａｌｐｈａ値（左）*/
    unsigned short	c_alpha1;		/* Ｃボタン Ａｌｐｈａ値（下）*/
    unsigned short	c_alpha2;		/* Ｃボタン Ａｌｐｈａ値（右）*/
    unsigned short	heart_alpha;		/* ハート Ａｌｐｈａ値 */
    unsigned short	meter_alpha;		/* メーター Ａｌｐｈａ値 */
    unsigned short	map_alpha;		/* ＭＡＰ Ａｌｐｈａ値 */
    short	start_alpha;		/* ＳＴＡＲＴ Ａｌｐｈａ値 */


    short	spot_map_no;		/* ＳＰＯＴＭＡＰ ＮＯ. */
    short	dungeon_map_no;		/* ダンジョンＭＡＰ ＮＯ. */
    short	room_no;		/* 現在部屋Ｎｏ．*/
    short	map_palete_no;		/* 現在部屋ＰＡＬＥＴＥ Ｎｏ．*/

    unsigned char	hold_rod;		/* 釣りざお持っているフラグ */

    unsigned char	marathon_fg;	/* マラソンフラグ */


    /* ボタン制御コード */
    unchar	h_gage;		/* ハート,魔法ゲージ,ルピー,カギ */
    unchar	b_button;	/* Ｂボタン */
    unchar	a_button;	/* Ａボタン */
    unchar	c_bottle;	/* 瓶 */
    unchar	c_warasibe;	/* わらしべ */
    unchar	c_hook;		/* フックショット */
    unchar	c_ocarina;	/* オカリナ */
    unchar	c_warp;		/* オカリナ（ワープ）*/
    unchar	c_sunmoon;	/* オカリナ（太陽の歌）*/
    unchar	m_wind;		/* 魔法（風）*/
    unchar	m_magic;	/* 魔法（炎・愛）*/
    unchar	another;	/* その他Ｃボタン */
    /*
     *		0 = 表示 (使える)
     *		1 = 半透明表示 (使えない)
     *		2 = 非表示 (使えない)
     *		3 = 使えるが、ワープメロディを受け付けない
     *
     *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     *	 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     *	 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     *			   ハ  Ｂ  Ａ  瓶  わ  フ  オ  オ  オ  魔  魔  そ
     *			   ｜  ボ  ボ      ら  ッ  カ  カ  カ  法  法  の
     *			   ト  タ  タ      し  ク  リ  リ  リ  風  炎  他
     *			   ・  ン  ン      べ  シ  ナ  ナ  ナ      ・
     *			   魔                  ョ  イ  ワ  太      愛
     *			   法                  ッ  ベ  ｜  陽 
     *			   ゲ                  ト  ン  プ  の 
     *			   ｜                      ト      歌
     *			   ジ                  
     *			   ・                  
     *			   ル             
     *			   ピ             
     *			   ｜             
     */

} Parameter;



/* コンストラクト */
extern void
parameter_ct( Game_play *game_play );

/* デストラクト */
extern void
parameter_dt( Game_play *game_play );

/* パラメーターＤＲＡＷ */
extern void
parameter_draw( Game_play *game_play );

/* パラメーターＭＯＶＥ */
extern void
parameter_move( Game_play *game_play );


#define ON_HOLD_ROD( game_play )	((game_play)->parameter.hold_rod = 1)
#define OFF_HOLD_ROD( game_play )	((game_play)->parameter.hold_rod = 0)
#define CHK_HOLD_ROD( game_play )	((game_play)->parameter.hold_rod)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_parameter.h end ***/
