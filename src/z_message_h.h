/* $Id: z_message_h.h,v 2.2 1998-10-27 21:26:19+09 soejima Exp $
 * $Log: z_message_h.h,v $
 * Revision 2.2  1998-10-27 21:26:19+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.85  1998/10/07 04:23:41  soejima
 * *** empty log message ***
 *
 * Revision 1.84  1998-10-03 23:03:45+09  soejima
 * *** empty log message ***
 *
 * Revision 1.83  1998-10-01 22:43:12+09  soejima
 * *** empty log message ***
 *
 * Revision 1.82  1998-09-19 22:02:41+09  soejima
 * *** empty log message ***
 *
 * Revision 1.81  1998-09-16 17:00:28+09  soejima
 * *** empty log message ***
 *
 * Revision 1.80  1998-09-15 23:05:20+09  soejima
 * *** empty log message ***
 *
 * Revision 1.79  1998-09-09 22:58:10+09  soejima
 * *** empty log message ***
 *
 * Revision 1.78  1998-09-07 23:04:30+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/10/02  06:17:41  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_MESSAGE_H
#define INCLUDE_Z_MESSAGE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


/************************************************************************
 *									*
 *	ＭＥＳＳＡＧＥ							*
 *				1996年11月05日(火曜日) 10時30分00秒 JST *
 ************************************************************************/
/* メッセージ セット（基本） */
extern void
message_set( Game_play *game_play, unshort message_no, Actor *talk_actor );
/* メッセージ セット（追加基本） */
extern void
message_set2( Game_play *game_play, unshort message_no );

/* メッセージ 終了チェック */
extern char
message_check( Message *this );

/* メッセージＣＬＯＳＥ	*/
extern void
message_close( Game_play *game_play );

/* ＫＥＹ入力チェック */
extern char
pad_on_check( Game_play *game_play );

/* 輪唱ＮＥＸＴ */
extern void
ocarina_round_next( Game_play *game_play );

/* メロディＴＡＢＬＥ */
extern short ocarina_number[];



typedef struct {
    unshort 	msg_num;			/* メッセージＮｏ．*/
    unchar 	msg_tp;				/* 表示Ｔｙｐｅ */
    unshort 	*msg_add;			/* メッセージ アドレス */
} MSG_T;
typedef struct {
    unshort 	msg_num;			/* メッセージＮｏ．*/
    unchar 	msg_tp;				/* 表示Ｔｙｐｅ */
    unchar 	*msg_add;			/* メッセージ アドレス */
} MSG_NT;
typedef struct {
    unchar 	*msg_add;			/* メッセージ アドレス */
} MSG_PT;


/* メッセージ Ｒｅｔｒｕｎ値 */
enum {
    Mes_Null,		/*  ０：メッセージＮｕｌｌ */
    Mes_Next,		/*  １：次のメッセージ有り */
    Mes_End,		/*  ２：メッセージ終了 */
    Mes_Draw,		/*  ３：メッセージ出力中 */
    Mes_Select,		/*  ４：選択 */
    Mes_Enemy,		/*  ５：敵側制御 */
    Mes_DpEnd,		/*  ６：メッセージ出力終了 */
    Mes_Oca00,		/*  ７：オカリナ自動演奏終了 */
    Mes_Oca10,		/*  ８：オカリナ演奏正解 */
    Mes_Oca20,		/*  ９：オカリナ演奏誤り */
    Mes_Keywait,	/*１０：改行待ち */
    Mes_Point
};




/* オカリナ演奏 */
extern void
ocarina_set( Game_play *game_play, unshort ocarina_no );
extern void
ocarina_set_111( Game_play *game_play, unshort ocarina_no );
/* オカリナ状態取得 */
#define	OCARINA_MODE( game_play )	(game_play)->message.ocarina_mode
enum {
    Oca_Null,		/* オカリナ無し */
    Oca_Play,		/* オカリナ演奏中 */
    Oca_Warp,		/* オカリナＷＡＲＰ正解 */
    Oca_Hit,		/* オカリナ正解 */
    Oca_Stop,		/* オカリナ中止 */
    Oca_Salia,		/* とりあえずＯＫ《サリアの歌》*/
    Oca_Epona,		/* とりあえずＯＫ《エポナの歌》*/
    Oca_Zelda,		/* とりあえずＯＫ《ゼルダの子守歌》*/
    Oca_Sun,		/* とりあえずＯＫ《太陽の歌》*/
    Oca_Time,		/* とりあえずＯＫ《時の歌》*/
    Oca_Storm,		/* とりあえずＯＫ《嵐の歌》*/
    Oca_Kakasi,		/* とりあえずＯＫ《案山子の歌》*/
    Oca_Round,		/* 輪唱成功 */
    Oca_Scarecrow,	/* 案山子ＯＫ */
    Oca_Flog,		/* カエルＯＫ */
    Oca_PlayE,		/* 再生終了 */
    Oca_Pt
};
/* オカリナ演奏番号 */
#define OCARINA_BASE	0x86E
enum {
    Ocarina_0,		/* 00:基本オカリナ演奏（ＷＡＲＰ）*/
    Ocarina_Free,	/* 01:基本オカリナ演奏（ＦＲＥＥ演奏）: ５線符なし */
    Ocarina_Wind,	/* 02:風のメヌエット */
    Ocarina_Flame,	/* 03:炎のボレロ */
    Ocarina_Water,	/* 04:水のセレナーデ */
    Ocarina_Soul,	/* 05:魂のレクイエム */
    Ocarina_Darkness,	/* 06:闇のノクターン */
    Ocarina_Light,	/* 07:光のプレリュード */
    Ocarina_Salia,	/* 08:サリアの歌 */
    Ocarina_Epona,	/* 09:エポナの歌 */
    Ocarina_Zelda,	/* 10:ゼルダの子守歌 */
    Ocarina_Sun,	/* 11:太陽の歌 */
    Ocarina_Time,	/* 12:時の歌 */
    Ocarina_Storm,	/* 13:嵐の歌 */
    Ocarina_Kakasi,	/* 14:案山子の歌 */
    Ocarina_C_Wind,	/* 15:風のメヌエット演奏学習 */
    Ocarina_C_Flame,	/* 16:炎のボレロ演奏学習 */
    Ocarina_C_Water,	/* 17:水のセレナーデ演奏学習 */
    Ocarina_C_Soul,	/* 17:魂のレクイエム演奏学習 */
    Ocarina_C_Darkness,	/* 18:闇のノクターン演奏学習 */
    Ocarina_C_Light,	/* 20:光のプレリュード演奏学習 */
    Ocarina_C_Salia,	/* 21:サリアの歌演奏学習 */
    Ocarina_C_Epona,	/* 22:エポナの歌演奏学習 */
    Ocarina_C_Zelda,	/* 23:ゼルダの子守歌演奏学習 */
    Ocarina_C_Sun,	/* 24:太陽の歌演奏学習 */
    Ocarina_C_Time,	/* 25:時の歌演奏学習 */
    Ocarina_C_Storm,	/* 26:嵐の歌演奏学習 */
    Ocarina_C_Kakasi,	/* 27:案山子の歌演奏学習 */
    Ocarina_PC_Wind,	/* 28:風のメヌエット演奏チェック */
    Ocarina_PC_Flame,	/* 29:炎のボレロ演奏チェック */
    Ocarina_PC_Water,	/* 30:水のセレナーデ演奏チェック */
    Ocarina_PC_Soul,	/* 31:魂のレクイエム演奏チェック */
    Ocarina_PC_Darkness,/* 32:闇のノクターン演奏チェック */
    Ocarina_PC_Light,	/* 33:光のプレリュード演奏チェック */
    Ocarina_PC_Salia,	/* 34:サリアの歌演奏チェック */
    Ocarina_PC_Epona,	/* 35:エポナの歌演奏チェック */
    Ocarina_PC_Zelda,	/* 36:ゼルダの子守歌演奏チェック */
    Ocarina_PC_Sun,	/* 37:太陽の歌演奏チェック */
    Ocarina_PC_Time,	/* 38:時の歌演奏チェック */
    Ocarina_PC_Storm,	/* 39:嵐の歌演奏チェック */
    Ocarina_PC_Kakasi,	/* 40:案山子の歌演奏チェック */
    Ocarina_FreeFree,	/* 41:基本オカリナ演奏（ＦＲＥＥ演奏）: ５線符あり */
    Ocarina_Record,	/* 42:録音 */
    Ocarina_PlayBack,	/* 43:録音再生 */
    Ocarina_Scarecrow,	/* 44:８音録音 */
    Ocarina_ScarecrowP,	/* 45:８音録音再生 */
    Ocarina_Round,	/* 46:輪唱 */
    Ocarina_Chorus,	/* 47:カエルの合唱 */
    Ocarina_Flog,	/* 48:カエル : ５線符なし */
    Ocarina_FrogFrog,	/* 49:カエル : ５線符あり */
    Ocarina_No
};





/*=======================================================================
  =	ｄｅｆｉｎｅ集							=
  =======================================================================*/
#define		MJSZ		16		/* 文字サイズ */
#define		MXSZ		11		/* 文字Ｘ 幅 */
#define		MYSZ		16		/* 文字Ｙ 高さ */
#define		MSPC		 6		/* スペース幅 */
#define		ITEMSIZE	32		/* アイテムＸサイズ */
#define		BALSZ		((128*64)/2)	/* 吹き出しサイズ */

enum {
    M_NULL,		// 
    M_MOVE,		// カメラ移動
    M_OPEN,		// 吹き出しＯＰＥＮ
    M_WAIT,		// Ｗａｉｔ
    M_READ,		// バッファ読み込み
    M_REST,		// 一時停止
    M_DISPLAY,		// 出力
    M_PAUSE,		// ＰＡＵＳＥ
    M_TIMER,		// タイマー改行
    M_OCARINA0,		// オカリナ（初期化）
    M_OCARINA10_S,	// オカリナ（初期化）
    M_OCARINA20_S,	// オカリナ（初期化）
    M_OCARINA1,		// オカリナ（入力）
    M_OCARINA2,		// オカリナ（正解）
    M_OCARINA3,		// オカリナ（不正解）
    M_OCARINA4,		// オカリナ（キャンセル）
    M_OCARINA5,		// オカリナ（音符落下）
    M_OCARINA6,		// オカリナ（正解模範演奏）
    M_OCARINA7,		// オカリナ（）
    M_OCARINA8,		// オカリナ（）
    M_OCARINA9,		// オカリナ（）
    M_OCARINAA,		// オカリナ（）
    M_OCARINAB,		// オカリナ（）
    M_OCARINAC,		// オカリナ（）
    M_OCARINA10,	// オカリナ（模範演奏Ｗａｉｔ）
    M_OCARINA11,	// オカリナ（模範演奏）
    M_OCARINA12,	// オカリナ（模範演奏終了）
    M_OCARINA20,	// オカリナ（演奏チェック）
    M_OCARINA21,	// オカリナ（演奏チェック：正解）
    M_OCARINA22,	// オカリナ（演奏チェック：誤り）
    M_OCARINA23,	// オカリナ（演奏チェック：音符落下）
    M_OCARINA24,	// オカリナ（演奏チェック：誤りＷａｉｔ）
    M_OCARINA_FREE,	// オカリナ（ＦＲＥＥ演奏チェック）
    M_OCARINA40,	// オカリナ（録音開始）
    M_OCARINA41,	// オカリナ（録音中）
    M_OCARINA42,	// オカリナ（録音再生）
    M_OCARINA50,	// オカリナ（８音録音開始）
    M_OCARINA51,	// オカリナ（８音録音中）
    M_OCARINA52,	// オカリナ（８音録音間違い）
    M_OCARINA53,	// オカリナ（８音録音ＯＫ！）
    M_OCARINA54,	// オカリナ（８音録音再生）
    M_OCARINA60,	// オカリナ（輪唱開始）
    M_OCARINA61,	// オカリナ（輪唱１init）
    M_OCARINA62,	// オカリナ（輪唱１play）
    M_OCARINA63,	// オカリナ（輪唱２init）
    M_OCARINA64,	// オカリナ（輪唱２play）
    M_OCARINA65,	// オカリナ（輪唱プレイヤーplay）
    M_OCARINA66,	// オカリナ（輪唱プレイヤーwait）
    M_OCARINA67,	// オカリナ（輪唱プレイヤー終了チェック）
    M_OCARINA80,	// オカリナ（カエルの合唱開始）
    M_OCARINA81,	// オカリナ（カエルの合唱中）
    M_OCARINA82,	// オカリナ（カエルの合唱チェック）
    M_NEXT,		// 改ページ
    M_END,		// 終了チェック
    M_CLOSE,		// 吹き出しＣＬＯＳＥ
    M_KOMATSU,		// 小松スペシャル
    M_POINT
};



#define __2_SELECT	0x10
#define __3_SELECT	0x20
#define __Next_Message	0x30
#define __DISPSTOP	0x40
#define __ENEMY		0x50
#define __TIMER		0x60


#define	SceneID(no)	(game_play->scene_data_ID == no)



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_message.h end ***/
