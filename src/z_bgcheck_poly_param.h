/* $Id: z_bgcheck_poly_param.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $ */
/*-------------------------------------------------------------------------
 *
 * z_bgcheck_poly_param.h
 *
 * Progaram:Kenji Matsutnai
 *
 * date:1997年 6月25日(水曜日) 10時27分17秒 JST
 *
 *-------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 *
 * $Log: z_bgcheck_poly_param.h,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.39  1998/09/23 13:51:05  matutani
 * *** empty log message ***
 *
 * Revision 1.38  1998-08-26 23:33:40+09  matutani
 * サウンド金属追加
 *
 * Revision 1.37  1998-08-04 16:58:02+09  matutani
 * スペルミス
 *
 * Revision 1.36  1998-08-04 16:48:15+09  matutani
 * ダンジョン間切り替え
 *
 * Revision 1.35  1998-07-31 22:05:45+09  matutani
 * BG_POLY_AJ_DROP2追加
 *
 * Revision 1.34  1998-07-04 20:31:17+09  matutani
 * オートジャンプコードに飛び込み追加
 *
 * Revision 1.33  1998-06-09 16:27:05+09  matutani
 * 停止切り替え２追加
 *
 * Revision 1.32  1998-05-16 22:31:13+09  matutani
 * カメラ用属性コード（Obj当たりなし用）の草むら(砂嵐）追加
 *
 * Revision 1.31  1998-05-16 20:37:39+09  matutani
 * 停止切り替え
 *
 * Revision 1.30  1998-04-28 15:33:26+09  matutani
 * 即死マグマ
 *
 * Revision 1.29  1998-04-21 18:31:26+09  matutani
 * *** empty log message ***
 *
 * Revision 1.28  1998-03-31 11:20:59+09  matutani
 * BG_POLY_AJ_DEMO0追加
 *
 * Revision 1.27  1998/03/18  01:32:12  takahata
 * *** empty log message ***
 *
 * Revision 1.26  1998/03/13  11:20:28  matutani
 * *** empty log message ***
 *
 * Revision 1.25  1998/03/11  02:22:49  matutani
 * サウンド関係追加
 *
 * Revision 1.24  1998/03/09  05:22:54  matutani
 * ポリゴン属性”魚の中”を追加
 *
 * Revision 1.23  1998/02/25  06:40:06  matutani
 * *** empty log message ***
 *
 * Revision 1.22  1998/02/25  06:37:57  matutani
 * *** empty log message ***
 *
 * Revision 1.21  1998/02/21  10:42:11  matutani
 * 属性コード＝深い砂漠追加
 *
 * Revision 1.20  1998/02/13  12:00:13  matutani
 * 透明壁
 *
 * Revision 1.19  1998/02/13  06:05:30  matutani
 * 砂嵐
 *
 * Revision 1.18  1998/02/13  06:05:00  matutani
 * *** empty log message ***
 *
 * Revision 1.17  1998/01/29  12:01:06  matutani
 * さばく、こおり、やわらかい、おっとっと
 *
 * Revision 1.16  1998/01/29  11:59:21  matutani
 * *** empty log message ***
 *
 * Revision 1.15  1998/01/12  11:36:34  matutani
 * *** empty log message ***
 *
 * Revision 1.14  1998/01/08  05:14:51  matutani
 * 横穴シーン切り替えコード
 *
 * Revision 1.13  1997/12/25  09:39:50  matutani
 * *** empty log message ***
 *
 * Revision 1.12  1997/12/09  08:33:50  matutani
 * 強制よじ登り
 *
 * Revision 1.11  1997/12/03  08:31:05  matutani
 * 水情報用ラベル
 *
 * Revision 1.10  1997/11/16  09:03:24  matutani
 * オートジャンプコード
 *
 * Revision 1.9  1997/11/06  07:31:38  matutani
 * 属性コード
 *
 * Revision 1.8  1997/11/06  07:31:16  matutani
 * *** empty log message ***
 *
 * Revision 1.7  1997/09/03  04:14:05  matutani
 * サウンドコード
 *
 * Revision 1.6  1997/08/27  11:21:25  matutani
 * *** empty log message ***
 *
 * Revision 1.5  1997/06/30  13:27:34  matutani
 * 梯子UP追加
 *
 * Revision 1.4  1997/06/28  12:39:06  matutani
 * データを入れていた。間違い
 *
 * Revision 1.3  1997/06/28  12:11:23  matutani
 * 間違い & -> |
 *
 * Revision 1.2  1997/06/26  07:34:15  matutani
 * z_bgcheck.cを出すのでついでに、梯子追加
 *
 * Revision 1.1  1997/06/26  00:37:01  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/

#define MAX_WALL_CODE_MAX 32

#ifndef Z_BGCHECK_POLY_PARAM_H
#define Z_BGCHECK_POLY_PARAM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*
 *
 * 壁コードテーブル
 *
 */
/* 壁登らないコード */
#define WALL_NOT_CLIB_BIT (1<<0)
/* 梯子 */
#define WALL_LADDER_BIT (1<<1)
/* 梯子UP */
#define WALL_LADDER_UP_BIT (1<<2)
/* フリークライム */
#define WALL_FREE_CLIB_BIT (1<<3)
/* 横穴 */
#define WALL_SIDE_HOLE (1<<4)
/* 横穴シーン切り替えコード */
#define WALL_SIDE_HOLE_SCENE_CHANGE (1<<5)
/* 押す引く */
#define WALL_PUSH_PULL_BIT (1<<6)


/* 壁コード */
extern unsigned int Bg_Wall_Code[MAX_WALL_CODE_MAX];
 
/*
 * サウンド属性
 * z_bgcheck.c内のBg_PolygonAttr2SoundGroundLabel[]に対応している。
 * 4bit
 */
typedef enum {
    BG_POLY_SND_GROUND, /* 土 */
    BG_POLY_SND_SAND, /* 砂 */
    BG_POLY_SND_CONCRETE, /* コンクリート/岩 */
    BG_POLY_SND_DIRT, /* 泥／粘土 */
    BG_POLY_SND_WATER0, /* 浅瀬 */
    BG_POLY_SND_WATER1, /* 深瀬 */
    BG_POLY_SND_WATER2, /* 水流 */
    BG_POLY_SND_MAGMA, /* 溶岩 */
    BG_POLY_SND_GRASS, /* 草 */
    BG_POLY_SND_GLASS, /* ガラス */
    
    BG_POLY_SND_WOOD, /* 木 */
    BG_POLY_SND_BREAK_WALL, /* 壊れ壁:サウンド地面指定ラベルはない */
    BG_POLY_SND_ICE, /* 氷 */
    BG_POLY_SND_IRON, /* 金属 */
#if 0
    BG_POLY_SND_EV_FOUNTAIN, /* 噴水 */
#endif
    BG_POLY_SND_MAX_INDEX
} BG_POLYGON_SND;

/*
 * 属性コード(5bit)
 */
typedef enum {
    BG_POLY_ATR_NONE, /* 属性なし */
    BG_POLY_ATR_SAND_STORM, /* 砂嵐(元ダミー／溶岩小） */
    BG_POLY_ATR_MAGMA_M, /* 溶岩中 */
    BG_POLY_ATR_MAGMA_L, /* 溶岩大 */
    BG_POLY_ATR_DESERT, /* 砂漠 */
    BG_POLY_ATR_ICE, /* 氷 */
    BG_POLY_ATR_SOFT, /* 柔らかい */
    BG_POLY_ATR_DEEP_DESERT, /* 深い砂漠 */
    BG_POLY_ATR_IN_FISH, /* 魚の中 */
    BG_POLY_ATR_MAGMA_IDEAD, /* 即死マグマ */
    BG_POLY_ATR_STOP_CHANGE, /* 停止切り替え */
    BG_POLY_ATR_STOP_CHANGE2, /* 停止切り替え２ */
    BG_POLY_ATR_DESERT3, /* 砂漠３ */
    BG_POLY_ATR_MAX_INDEX
} BG_POLY_ATR;
/*
 * カメラ用属性コード（Obj当たりなし用）
 */
/* 草むら(砂嵐） */
#define BG_POLY_CATR_BUSH BG_POLY_ATR_SAND_STORM

/*
 * 床コード（オートジャンプコード:4bit）
 * 関数：
 * extern int T_BGCheck_GroundAutoJumpType_ai(
 *   T_BGCheck *this,
 *   T_Polygon *ppoly,
 *   int bg_actor_index);
 */
typedef enum {
    BG_POLY_AJ_A,
    BG_POLY_AJ_B,
    BG_POLY_AJ_C,
    BG_POLY_AJ_D,
    BG_POLY_AJ_E,
    BG_POLY_AJ_DROP_DETH,
    BG_POLY_AJ_FORCE_FC,
    BG_POLY_AJ_OTTOTTO, /* おっとっと:3bit限界 */
    BG_POLY_AJ_CLEAR_WALL, /* 透明壁 */
    BG_POLY_AJ_FORBID, /* オートジャンプ禁止 */
    BG_POLY_AJ_DEMO0, /* デモ0用開始コード */
    BG_POLY_AJ_TOBIKOMI, /* 飛び込み */
    BG_POLY_AJ_DROP2, 
    BG_POLY_AJ_LAST_INDEX
} BG_POLY_AJ_TYPE;

/*
 *
 * 水情報
 *
 */
/* 常駐水情報 */
#define WI_CONST_INDEX 0x3f

/*
 * 水流/ベルト パワータイプ列挙
 * T_BGCheck_getSlidePowerIndex()の返り値
 * 残りの４から７は未定
 */
typedef enum {
    BG_SPI_NONE, /* 無し:0 */
    BG_SPI_LOW, /* 弱:1 */
    BG_SPI_MID, /* 中:2 */
    BG_SPI_HIGH /* 強:3 */
} BG_SPI_TYPE;


/*
 * まさつ
 */
typedef enum {
    BG_FRC_NONE, /* 無し */
    BG_FRC_SLIP_SLOPE, /* 滑る坂 */
    BG_FRC_DUNGEON_CHANGE, /* ダンジョン間切り替え */
    BG_FRC_LAST_INDEX
} BG_FRC_TYPE;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */ 
#endif

#endif

/*** z_bgcheck_poly_param.h EOF ***/

