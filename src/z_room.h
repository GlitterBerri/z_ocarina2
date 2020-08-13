/*
 * $Id: z_room.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 * $Log: z_room.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.21  1998/09/15 12:56:47  hayakawa
 * *** empty log message ***
 *
 * Revision 1.20  1998-09-05 18:02:24+09  goron
 * *** empty log message ***
 *
 * Revision 1.19  1998-07-04 22:31:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1998-06-25 22:58:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1998-06-16 23:06:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1998-03-19 22:01:41+09  komatu
 * *** empty log message ***
 *
 * Revision 1.15  1998/03/16  04:46:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1998/02/27  13:20:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1998/02/18  14:20:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1998/02/14  13:43:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1998/01/30  13:21:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1997/12/01  12:05:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.9  1997/10/22  14:45:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1997/10/16  11:19:14  hayakawa
 * Room_Moveの１っ回目と二回目が分かるようにした
 *
 * Revision 1.7  1997/08/07  14:00:14  hayakawa
 * Room_Moveの追加
 *
 * Revision 1.6  1997/07/23  08:35:58  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1997/07/16  05:07:28  hayakawa
 * *** empty log message ***
 *
 */


#ifndef INCLUDE_Z_ROOM_H
#define INCLUDE_Z_ROOM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    
#include "z_play_h.h"
#include "z_scene.h"
#include "z_actor.h"


/************************************************************************
 *
 *	気候タイプＮｏ
 *
 ************************************************************************/
enum {
    ROOM_WEATHER_NORMAL,
    ROOM_WEATHER_COLD,
    ROOM_WEATHER_HOT,
    ROOM_WEATHER_HEAVY_HOT,
    ROOM_WEATHER_WARM,
    ROOM_WEATHER_MILD,
    ROOM_WEATHER_COOL,
    ROOM_WEATHER_MAX
};

/************************************************************************
 *
 *	部屋タイプＮｏ
 *
 ************************************************************************/
enum {
    ROOM_TYPE_FIELD,
    ROOM_TYPE_DANGEON,
    ROOM_TYPE_ROOM,
    ROOM_TYPE_FOREST,
    ROOM_TYPE_TOWN,
    ROOM_TYPE_BOSS,
    ROOM_TYPE_MAX
};

/************************************************************************
 *
 *	部屋データクラス
 *
 ************************************************************************/
typedef struct {
    signed char		ID;			/* 部屋Ｎｏ */
    signed char		area;			/* エリアＮｏ */
    unsigned char	weather;		/* 気候タイプ */
    unsigned char	type;			/* 部屋タイプ */
    unsigned char	sound_echo_level;	/* サウンドエコーレベル */
    unsigned char	glass_mode;		/* 魔法のメガネモード */
    Ground_Shape	*ground_shape;		/* 地形シェイプデータポインタ */
    char		*Segment;		/* 部屋データポインタ */

    int			TOOL_OFFSET;		/* ツール用オフセット */	
} Room;

typedef struct {
    Room		now;			/* 現在部屋データ */
    Room		old;			/* 前回部屋データ */
    
    char		*buffer_address[2];	/* 入れ替えマップデータバッファ開始ポインタ */
    unsigned char	buffer_count;		/* 入れ替えマップデータバッファカウンタ */
    
    signed char		read_flag;		/* 新規読み込みフラグ */
    signed char		read_data;		/* 新規読み込みエリアＮｏ */
    char		*read_buffer_address;	/* 新規読み込みマップデータバッファポインタ */

    dma_t		dma;
    OSMesgQueue		mq;
    OSMesg		m;

    short		work[2];		/* 汎用変数 */
} Room_Info;

/*-----------------------------------------------------------------------
 *
 *	部屋シェイプデータ表示処理
 *
 *----------------------------------------------------------------------*/
extern void Room_Draw(
    Game_play *game_play,
    Room      *this,
    int       drawflag		/* 1:OPA, 2:XLU, 3:OPA&XLU */
);

/*-----------------------------------------------------------------------
 *
 *	部屋シェイプデータ表示以外処理
 *
 *----------------------------------------------------------------------*/
extern void Room_Move(
    Game_play *game_play,
    Room      *this,
    pad_t     *pad,
    int	      now_old		/* 0:now 1:old */
);

/************************************************************************
 *
 *	部屋データ入れ替えクラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	部屋データ入れ替えクラス コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Room_Info_ct(
    Game_play	*game_play,
    Room_Info   *this
);

/*-----------------------------------------------------------------------
 *
 *	部屋データ入れ替えクラス初期設定
 *
 *----------------------------------------------------------------------*/
extern size_t Room_Info_init(
    Game_play	*game_play,
    Room_Info   *this
);

/*-----------------------------------------------------------------------
 *
 *	部屋データ入れ替え開始設定
 *
 *----------------------------------------------------------------------*/
extern int Room_Info_exchange_start(
    Game_play *game_play,
    Room_Info *this,
    int	      read_room_ID
);

/*-----------------------------------------------------------------------
 *
 *	部屋データ入れ替えチェック
 *
 *----------------------------------------------------------------------*/
extern int Room_Info_exchange_check(
    Game_play *game_play,
    Room_Info *this
);

/*-----------------------------------------------------------------------
 *
 *	旧部屋データ削除
 *
 *----------------------------------------------------------------------*/
extern void Room_Info_old_room_clear(
    Game_play *game_play,
    Room_Info *this
);
/*
 * プリレンダー表示
 */
extern void
prerender_draw2(
    Gfx 	**glistpp,
    u16		*timg,		/* プリレンダー画面テクスチャ */
    u16		*tlut,		/* !NULL:パレットテーブル */
    u16 	width,		/* テクスチャ横幅 320 */
    u16 	height,		/* テクスチャ高さ 240 */
    u8		txlfmt,		/* G_IM_FMT_* */
    u8		txlsiz,		/* G_IM_SIZ_* */
    u16		tt,		/* G_TT_ */
    u16		pnum,		/* パレット数0-256 */
    float	xpos,
    float	ypos
);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_room.h end ***/
