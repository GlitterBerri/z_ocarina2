/*
 * $Id: z_common_data.h,v 2.2 2000-06-19 10:09:52+09 hayakawa Exp $
 *
 * ゼルダ共通データ定義
 *
 * $Log: z_common_data.h,v $
 * Revision 2.2  2000-06-19 10:09:52+09  hayakawa
 * パッチ当て版
 *
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.106  1998/10/09 07:37:02  soejima
 * *** empty log message ***
 *
 * Revision 1.105  1998-10-08 23:05:44+09  soejima
 * *** empty log message ***
 *
 * Revision 1.104  1998-10-07 23:03:37+09  soejima
 * *** empty log message ***
 *
 * Revision 1.103  1998-10-06 23:07:39+09  soejima
 * *** empty log message ***
 *
 * Revision 1.102  1998-10-06 20:20:33+09  nisiwaki
 * shield_magic_timer を Game_Info に 追加
 *
 * Revision 1.101  1998-10-03 09:44:27+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.100  1998-10-01 22:38:13+09  soejima
 * *** empty log message ***
 *
 * Revision 1.99  1998-09-30 23:05:48+09  soejima
 * *** empty log message ***
 *
 * Revision 1.98  1998-09-29 10:42:27+09  soejima
 * *** empty log message ***
 *
 * Revision 1.97  1998-09-28 17:15:18+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.96  1998-09-26 01:13:30+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.95  1998-09-25 01:49:09+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.94  1998-09-24 00:51:53+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.93  1998-09-22 17:52:01+09  soejima
 * *** empty log message ***
 *
 * Revision 1.92  1998-09-21 19:11:58+09  sasaki
 * GAME_INFO_ENDING_DEMO add
 *
 * Revision 1.91  1998/09/19 17:23:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.90  1998-09-19 22:55:15+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.89  1998-09-19 18:26:37+09  soejima
 * *** empty log message ***
 *
 * Revision 1.88  1998-09-18 23:37:44+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.87  1998/09/16 16:03:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.86  1998-09-15 23:02:34+09  soejima
 * *** empty log message ***
 *
 * Revision 1.85  1998-09-15 13:59:40+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.84  1998/09/12 14:47:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.83  1998-09-12 21:49:34+09  sasaki
 * next_zelda_time add
 *
 * Revision 1.82  1998/09/11 15:18:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.81  1998-09-10 22:57:14+09  soejima
 * *** empty log message ***
 *
 * Revision 1.80  1998-09-08 16:34:24+09  soejima
 * *** empty log message ***
 *
 * Revision 1.79  1998-09-07 18:21:17+09  soejima
 * *** empty log message ***
 *
 * Revision 1.78  1998-09-05 18:42:13+09  soejima
 * *** empty log message ***
 *
 * Revision 1.77  1998-08-22 14:18:47+09  zelda
 * *** empty log message ***
 *
 * Revision 1.76  1998-08-22 14:17:14+09  soejima
 * *** empty log message ***
 *
 * Revision 1.75  1998-08-22 14:10:39+09  soejima
 * *** empty log message ***
 *
 * Revision 1.74  1998-08-21 19:10:06+09  sasaki
 * DOUKIDEMO 変更
 *
 * Revision 1.73  1998/08/20 15:13:35  iwawaki
 * *** empty log message ***
 *
 * Revision 1.72  1998-08-18 22:47:06+09  soejima
 * *** empty log message ***
 *
 * Revision 1.71  1998-08-12 22:49:38+09  soejima
 * *** empty log message ***
 *
 * Revision 1.70  1998-08-12 14:44:18+09  soejima
 * *** empty log message ***
 *
 * Revision 1.69  1998-08-03 21:44:52+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.68  1998-07-29 22:50:42+09  soejima
 * *** empty log message ***
 *
 * Revision 1.67  1998-07-23 23:13:44+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.66  1998-07-14 22:45:32+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/10/20  03:02:31  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_COMMON_DATA_H_
#define __Z_COMMON_DATA_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_scene.h"
#include "audio.h"
#include "z_scene_table.h"


enum {
    GAME_INFO_GAME,			/* 通常ゲーム		*/
    GAME_INFO_OPENING_DEMO,		/* オープニングデモ	*/
    GAME_INFO_OPENING_SELECT,		/* オープニングセレクト */
    GAME_INFO_ENDING_DEMO		/* エンディングデモ	*/
};



typedef struct {
    unchar	newf[6];		/* Ｎｅｗファイル・フラグ */

    unshort	savect;			/* セーブカウント */

    unchar	player_name[8];		/* プレイヤー登録名前 */

    short	f_64dd;			/* ６４ＤＤフラグ */

    short	max_life;		/* 最大Ｌｉｆｅ数 */
    short	now_life;		/* 現在Ｌｉｆｅ数 */
    
    signed char	magic_max;		/* 魔法メーターＭＡＸ容量ポインタ */
    signed char	magic_now;		/*             現在値 */

    short	lupy_count;		/* ルピー数 */

    unshort	long_sword_hp;		/* 巨人のナイフＨＰ */

    unshort	navi_timer;		/* ナヴィＴＩＭＥＲ */

    unchar	magic_mode;		/* 魔法状態 */
    
    unchar	sword_ability;		/* 剣の性能（タメ切り時間短縮）*/
    unchar	magic_ability;		/* 魔法の性能（魔法使用可能量倍）*/
    unchar	life_ability;		/* ＬＩＦＥの性能（ＬＩＦＥ減少半分）*/

    unchar	last_sword;		/* 最後の剣フラグ（折れない巨人のナイフ）*/

    unchar	ocarina_round;		/* 輪唱ポインタ */
    
    /* 子供時装備 */
    unchar	child_register_item[4];		/* 登録アイテム */
    unchar	child_register_item_pt[3];	/* 登録アイテムポインター */
    unshort	child_equip_item;		/* ポインターで登録 */
    /* 大人時装備 */
    unchar	adult_register_item[4];		/* 登録アイテム */
    unchar	adult_register_item_pt[3];	/* 登録アイテムポインター */
    unshort	adult_equip_item;		/* ポインターで登録 */

    /* ＷＡＲＰ */
    xyz_t		position;	/* ワープポイントプレイヤー座標 */
    short		angle_y;	/*       ”      プレイヤー角度 */
    Scene_No		scene;		/*       ”      シーンＮｏ */
    unchar		room_ID;	/*       ”      部屋Ｎｏ */
    unchar		flag;		/*	 ”      セットフラグ */


    short		scene_data_ID;	/* シーンデータＮｏ */
} Privatef_t;

typedef struct {
    unchar	register_item[4];	/* 登録アイテム */
    unchar	register_item_pt[3];	/* 登録アイテムポインター */

    /* 装備 */
    unshort	equip_item;		/* ポインターで登録 */
/*    5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     | ブーツ|  服   |  盾   |  剣   |
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+	*/
} Used_t;

typedef struct {
    /*---------- ＩＴＥＭ ----------*/
    unchar	item_register[6*4];	/* ＩＴＥＭ登録 */
    signed char	item_count[16];		/* ＩＴＥＭ数 : 0 : デクの棒
					                1 : デクの実
					                2 : 爆弾
					                3 : 妖精の弓
							4 :
							5 :
							6 : パチンコ
							7 : オカリナ
							8 : ボムチュウ
					                9 : フックショット
					               10 : 
					               11 :
					               12 : ブーメラン
					               13 : まことの虫メガネ
					               14 : 魔法のマメ
					               15 : メガトンハンマー  */

    /*---------- ＥＱＵＩＰＭＥＮＴ ----------*/
    /* 装備アイテム */
    unshort	equip_register;		/* Ｂｉｔのon/offで登録 */
/*    5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     | ブーツ|  服   |  盾   |  剣   |
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+	*/

    /* 非装備アイテム */
    long	non_equip_register;	/* ポインターで登録 */
/*    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     |                 |実袋 |棒袋 |種袋 |ｻｲﾌ| ｳﾛｺ |手袋 |爆弾 |矢立 |
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+	*/


    /*---------- ＣＯＬＬＥＣＴ ----------*/
#define C_SEAL		6		/* 封印ＭＡＸ数 */
#define C_MELODY	12		/* 楽譜ＭＡＸ数 */
#define C_HOLY		3		/* 精霊石ＭＡＸ数 */
#define C_ITEM		3		/* アイテムＭＡＸ数 */
#define C_HEART		1		/* ハートの欠片ＭＡＸ数 */
#define COLLECT_MAX	(C_SEAL+C_MELODY+C_HOLY+C_ITEM+C_HEART)	/* ＣＯＬＬＥＣＴ ＭＡＸ数 */
    long	collect_register;	/* Ｂｉｔのon/offで登録但し,ハート欠片のみポインター */
/*    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     | | ﾊｰﾄ | | | | 石[4] |精霊3|        楽譜[12]       |  封印[6]  |
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+	*/

    /*---------- ＭＡＰ ----------*/
    unchar	key_compass_map[20];	/* ボス部屋鍵,コンパス,マップ */
    signed char	key_register[20];	/* 鍵登録 */
    /* key_register[19]	──》 ハート制御 */



    short	n_coin_total;		/* Ｎ−ＣＯＩＮ総数 */
} Table_t;

#define ri_idx0	128
#define ri_idx1	7
typedef struct {
    long	room_inf[ri_idx0][ri_idx1];	/*  ０：宝箱
						 *  １：スイッチ
						 *  ２：敵全滅
						 *  ３：アイテム０
						 *  ４：アイテム１
						 *  ５：部屋情報(MAP-ON/off)
						 *  ６：階情報
						 */
    /* 金スタルチュラ（１２６）*/
    /* ハイスコア    （１２７）*/


    unshort	event_chk_inf[14];		/* ＥＶＥＮＴチェックＢｉｔ情報 */
    unshort	item_get_inf[4];		/* アイテム取得情報 */
    unshort	inf_table[30];			/* メッセージチェックＢｉｔ情報 */
////////    unchar	hold_sword;		/* inf_table[29] : 剣を持っているフラグ ０＝HOLD ０≒NON	*/

    int		scene_no_dungeon;	/* ダンジョンシーン番号 */

    long	area_arrival;		/* ＡＲＥＡ到着テーブル */
    int		dungeon_information;	/* ダンジョン紹介情報 */

    unchar	oca_rec_flag;		/* 録音案山子フラグ */
    unchar	oca_rec_buff[900];	/* 録音案山子ＢＵＦＦ */
    unchar	oca_rec_flag8;		/* ８音録音案山子フラグ */
    unchar	oca_rec_buff8[128];	/* ８音録音案山子ＢＵＦＦ */
} Information_t;

typedef struct {
    short		spot_no;		/* ＳＰＯＴ番号 */
    short		horse_x;		/* 馬Ｘ座標 */
    short		horse_y;		/* 馬Ｙ座標 */
    short		horse_z;		/* 馬Ｚ座標 */
    short		horse_a;		/* 馬ＡＮＧＬＥ */
} Horse_t;

typedef struct {
    unshort	check_sum;		/* チェック・サム */
} Save_t;



typedef struct {
    Privatef_t		privatef;		/* プライベート・データ */

    Used_t 		used;			/* 使用中・データ */

    Table_t		table;			/* テーブル・データ */

    Information_t	information;		/* ダンジョン・地上各情報 */

    Horse_t		horse;			/* 馬情報 */

    Save_t		save;			/* ＳＡＶＥチェック情報 */
} Memory;

/*----------------------------------------------------------------------*
 *
 *	ゲームスタート用
 *
 *----------------------------------------------------------------------*/
enum {
    RESTART_MODE_DOWN,		/* 部屋でやられて再スタート */
    RESTART_MODE_RETURN,	/* ワープしてきて帰る再スタート */
    RESTART_MODE_WARP		/* 風の魔法記憶ポイント */
};

typedef struct {
    xyz_t		player_pos;	/* 途中再スタートプレイヤー座標 */
    short		player_angle_y;	/*       ”      プレイヤー角度 */
    short		player_mode;	/*       ”      プレイヤー出現モード */
    Scene_No		scene;		/*       ”      シーンＮｏ */
    unsigned char	room_ID;	/*       ”      部屋Ｎｏ */
    signed char		work;		/*       ”      汎用データ */
    unsigned long	sw2;		/*       ”      ダンジョンセーブスイッチフラグ（２４ビット） */
    unsigned long	item2;		/*       ”      ダンジョンセーブアイテムフラグ（３２ビット） */
} Game_Restart_Data;

#define	GUIDE_STATUS_HEAT_AREA	(1)		/* 高温ダメージエリアメッセージ */
#define	GUIDE_STATUS_DIVE_AREA	(1<<1)		/* 水中ダメージエリアメッセージ */

typedef struct {
    int			mode;
    int			counter;
    
    int			restart_flag;		/* 途中再スタートフラグ */
    Game_Restart_Data	restart_data[3];	/* 途中再スタートデータ */

    float		player_wipe_speedF;	/* プレイヤーワイプ時速度 */
    u16			player_wipe_door_SE;	/* プレイヤードアワイプＳＥセットフラグ */
    unsigned char	player_wipe_item;	/* プレイヤーワイプ時アイテム装備 */

    unsigned char	next_walk;		/* 床コードによるシーン切り替えフラグ */
    short		dog_flag;		/* 犬連れフラグ */

    unsigned char	guide_status;		/* ガイドメッセージ情報フラグ */
    unsigned char	name_display;		/* コース名表示フラグ */

    short		shield_magic_timer;
} Game_Info;


/*
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！                                                                    注意！！
 *  注意！！    【z_common_data_t】内「ＳＡＶＥ」に変数を追加した時には,        注意！！
 *  注意！！    下の【SAVE_BASE】にも『Save_Size +\』を追加しておいて下さい。   注意！！
 *  注意！！                                                      by副島        注意！！
 *  注意！！                                                                    注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 *  注意！！注意！！注意！！注意！！注意！！注意！！！注意！！注意！！注意！！！注意！！
 */
#define Save_Size	(sizeof(int)/sizeof(unchar))
#define SAVE_BASE	( Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size +\
                          Save_Size +\
			  Save_Size )


typedef struct z_common_data_s {
    /* ＳＡＶＥ */
    int 		scene_no;		/* シーン番号 */

    int			link_age;		/* リンクの年齢フラグ（０：青年 １：少年） */

    int			day_time;		/* 時刻属性	*/
    unsigned short	zelda_time;		/* 現在時刻	*/
    int			asahiru_fg;		/* 朝昼フラグ	*/

    int			totalday;		/* 総日数	8/21 sasa add */
    int			eventday;		/* イベント日数	8/21 sasa add */

    Memory		memory;			/* プレイヤー個人色々情報 */
    /* 上記の【注意！！】を見てください！！！！！！！！！ */



    /* ＮＯ─ＳＡＶＥ */
    int 		file_no;		/* 選択Ｆｉｌｅ番号 */

    int			next_link_age;		/* 次のリンクの年齢フラグ（０：青年 １：少年） */

    Game_Info		game_info;		/* ゲーム情報		*/

    short		lupy_udct;		/* ルピー増減数		*/

    short		event_fg;		/* イベントフラグ */
    short		event_tm;		/* イベントタイマー */
    short		total_event_fg;		/* ＴＯＴＡＬイベントフラグ */
    short		total_event_tm;		/* ＴＯＴＡＬイベントタイマー */
    short		event_xp[2];		/* ＥＶＥＮＴタイマー表示Ｘ位置 */
    short		event_yp[2];		/*                   表示Ｙ位置 */

    short		aaaaaaaa; 	/* 空いてるよ */

    unsigned char	old_bgm;		/* 前回BGM */
    unsigned char	old_env;		/* 前回環境音 */

    unchar	button_item[5];		/* 保存Ｂｕｔｔｏｎ─ＩＴＥＭ（Ｂ）（左）（下）（右）（Ａ）*/
    unchar	ck_fg;			/* Ａ─ＩＴＥＭ切替フラグ */

    unshort	alpha_type;		/* メーターＡＬＰＨＡ・ＴＹＰＥ */
    unshort	prev_alpha_type;	/* 現在メーターＡＬＰＨＡ・ＴＹＰＥ */
    unshort	alpha_count;		/* メーターＡＬＰＨＡカウンタ */
    unshort	last_time_type;		/* 前回ＡＬＰＨＡ・ＴＹＰＥ */

    short	magic_flag;		/* 魔法メーター状態フラグ */
    short	keep_magic_flag;	/* 保存魔法メーター状態フラグ */
    short	magic_now_max;		/* 魔法メーターＭＡＸ値 */
    short	magic_now_now;		/* 魔法メーター現在量現在値 */
    short	magic_used;		/* 魔法メーター消費量 */

    unshort	event_inf[4];		/* 一時用ＥＶＥＮＴ */

    unshort	scene_ID;		/* scene_data_ID */

    unshort	yabusame_mode;		/* 流鏑馬状態 */
    unshort	yabusame_total;		/* 流鏑馬総得点 */

    unchar	no_save;		/* ＳＡＶＥ禁止フラグ */


    unchar	j_n;			/* ０：ＪＡＰＡＮ ／ １：ＮＥＳ */
    unchar	s_sound;		/* ＳＯＵＮＤ ステレオ／モノラル／ヘッドホン／３Ｄ */
    unchar	language;		/* 言語 */
    unchar	z_attention;		/* Ｚ注目方法 ０：スイッチ／１：ホールド */


    unshort	NottoriBgm;		/* 次シーン音楽設定	    8/21 sasa add	*/
    unchar	fade_go;		/* デモフェード受け渡し				*/
    unshort	next_daytime;		/* 次回デモシーン番号				*/
    unchar	doukidemo;		/* 通常シーンデモ開始トリガ			*/
    unchar	Kenjya_no;		/* 賢者の間用 賢者決定フラグ			*/

    unshort	next_zelda_time;	/* 次シーンでのゼルダ時間			*/
    unchar	fade_speed;		/* フェードスピード				*/
    unchar	wipe_speed;		/* ワイプ  スピード				*/
    unshort	kankyo_time;		/* ＶＲ＿ＢＯＸ ＆ 環境カラー専用ゼルダ時間	*/
    uchar	dog_event_flag;		/* 対 犬おばさん用 犬発見フラグ  毎朝ビット立て	*/
    uchar	next_wipe;		/* 次シーン強制ワイプイン番号			*/

    short	room_type;		/* 部屋 ＴＹＰＥ */
    short	area_type;		/* ＡＲＥＡ ＴＹＰＥ */

    short	sunmoon_flag;		/* 太陽の歌フラグ */

    short	life_mode;		/* ＬＩＦＥモード */
} z_common_data_t;

/*
 * ゼルダ共通データ定義
 * 必ずアクセスマクロを経由してください
 */
extern z_common_data_t z_common_data;

#ifdef __cplusplus
extern "C" {
#endif
    
    /*
     * ゼルダ共通データ初期化
     */
    extern void z_common_data_init(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

/*
 * アクセスマクロ
 */

#ifndef DISK_VERSION
/* メンバの値を取得 */
#define ZCommonGet(member) (0, z_common_data.member)
/* メンバのポインタを取得（構造体のアクセスはこれを推奨する） */
#define ZCommonGetP(member) (0, &z_common_data.member)
/* メンバに値を設定 */
#define ZCommonSet(member, value) (z_common_data.member = (value))
/* １次元配列用 */
#define ZCommonGetA(member, a1) (0, z_common_data.member[a1])
#define ZCommonSetA(member, a1, value) (0, z_common_data.member[a1] = (value))
/* ２次元配列用 */
#define ZCommonGetA2(member, a1, a2) (0, z_common_data.member[a1][a2])
#define ZCommonSetA2(member, a1, a2, value) (0, z_common_data.member[a1][a2] = (value))
#else  /* DISK_VERSION */
#define ZCommonGet(member) (0, disk_keeptable1.z_common_data->member)
#define ZCommonGetP(member) (0, &disk_keeptable1.z_common_data->member)
#define ZCommonSet(member, value) (disk_keeptable1.z_common_data->member = (value))
#endif /* DISK_VERSION */

/*
 * 個別アクセスマクロ
 */
#define ZCommon_LinkAgeGet()		(ZCommonGet(link_age) ? 5 : 17)
#define ZCommon_LinkAgeSet(year)	ZCommonSet(link_age, ((year) == 5))
#define ZCommon_LinkAgeIsAdult()	(ZCommon_LinkAgeGet() == 17)
#define ZCommon_LinkAgeBeAdult()	ZCommon_LinkAgeSet(17)
#define ZCommon_LinkAgeIsChild()	(ZCommon_LinkAgeGet() == 5)
#define ZCommon_LinkAgeBeChild()	ZCommon_LinkAgeSet(5)
#define ZCommon_SceneNoGet()		ZCommonGet(scene_no)		/* シーン番号獲得 */
#define ZCommon_SceneNoSet(no)		ZCommonSet(scene_no, no)	/* シーン番号セット */
#define ZCommon_FileNoGet()		ZCommonGet(file_no)		/* 選択Ｆｉｌｅ番号獲得 */
#define ZCommon_FileNoSet(no)		ZCommonSet(file_no, no)		/* 選択Ｆｉｌｅ番号セット */
#define	SceneNo_Check(no) 		(ZCommonGet(scene_no) == no) /* ＳｃｅｎｅＮｏ．チェック */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_COMMON_DATA_H_ */
