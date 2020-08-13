/*
 * $Id: game.h,v 2.2 1999-04-28 10:29:56+09 komatu Exp $
 *
 * ゲームクラス
 *
 * $Log: game.h,v $
 * Revision 2.2  1999-04-28 10:29:56+09  komatu
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.21  1998/07/31 11:32:37  ogawa
 * frame_counterをunsignedに
 *
 * Revision 1.20  1998-06-25 14:02:45+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.19  1998-06-25 10:23:12+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.18  1998-06-24 23:02:38+09  hayakawa
 * game_allocアライメントバリエーション
 *
 * Revision 1.17  1998-05-07 11:13:06+09  hayakawa
 * game_getFreeBytes追加
 *
 * Revision 1.16  1998-05-06 17:06:26+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.15  1998-04-01 11:47:14+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.14  1998/03/17  10:26:45  hayakawa
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.13  1997/05/29  14:03:13  hayakawa
 * HAYAKAWA_TESTdxテスト準備
 * game_set_next_game_null追加
 * Game_set_next_game_name追加
 * Game_set_next_game_null追加
 *
 * Revision 1.12  1997/04/07  09:45:38  hayakawa
 * game_set_next_game_nameマクロの追加
 *
 * Revision 1.11  1997/03/21  09:10:38  hayakawa
 * SetGameFrame/GetGameFrameを追加
 *
 * Revision 1.10  1997/02/05  10:06:17  hayakawa
 * 構造体変更
 *
 * Revision 1.9  1997/01/14  05:05:45  hayakawa
 * cleanup再び追加。なぜ消えた？
 *
 * Revision 1.8  1996/10/16  05:38:03  hayakawa
 * GameAlloc対応
 *
 * Revision 1.7  1996/09/27  05:15:01  hayakawa
 * game_alloc関係の変更
 *
 */

#ifndef __GAME_H_
#define __GAME_H_

#include "u64basic.h"
#include "graph.h"
#include "pad.h"
#include "gamealloc.h"

typedef struct game_s {
    Graph *graph;		/* グラフィッククラス */
    void (*exec)(struct game_s *); /* ゲームのメイン関数ポインタ */
#ifndef HAYAKAWA_TESTdx
    void (*cleanup)(struct game_s *); /* ゲームの後始末関数 */
#else
    int game_dlf_no;		/* このゲームのDLF番号 */
    DLFTBL *dlftbl;		/* このゲームのDLFテーブルへのポインタ */
#endif
#ifndef HAYAKAWA_TESTdx
    void (*next_game_init)(struct game_s *); /* 次のゲームの初期化関数 */
    size_t next_game_class_size; /* 次のゲームのクラスのサイズ */
#endif
    pad_t pads[MAXCONTROLLERS];	/* パッドの情報を保存する領域 */
    THA tha;			/* game_alloc用 */
    GameAlloc gamealloc;	/* gamealloc用 */
    int _doing;			/* ゲーム続行フラグ */
    unsigned int frame_counter;	/* ゲームフレームカウンタ
				   (ポーズ中に止めない) */
    int disable_prenmi;		/* !0:PRENMI処理を(一時的に)禁止する */
#ifdef HAYAKAWA_TESTdx
    int next_game_dlf_no;	/* 次のゲームのDLF番号 */
#endif
} game_t;
typedef game_t Game;

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/* メンバ関数 */
extern void game_main(Game *);
extern void fist_game_init(Game *);
extern void game_ct(Game *, void (*)(Game *), Graph *);
extern void game_dt(Game *);
#ifndef HAYAKAWA_TESTdx
extern void (*game_get_next_game_init(Game *this))(Game *);
#endif
extern size_t game_get_next_game_class_size(Game *);
extern int game_is_doing(Game *);
extern void *game_alloc(Game *, size_t);	/* ゲーム終了時に自動的に解放するmalloc */
extern void *game_alloc_DEBUG(Game *, size_t, char *file, int line);
#define game_allocAlign(this, size, mask) THA_allocAlign(&(this)->tha, size, mask)
#define game_alloc1(this, size)  game_allocAlign(this, size, ~(1-1))
#define game_alloc2(this, size)  game_allocAlign(this, size, ~(2-1))
#define game_alloc4(this, size)  game_allocAlign(this, size, ~(4-1))
#define game_alloc8(this, size)  game_allocAlign(this, size, ~(8-1))
#define game_alloc64(this, size) game_allocAlign(this, size, ~(64-1))
#ifdef FINAL_ROM
#define game_alloc16(this, size) THA_alloc16(&(this)->tha, size) /* 高速 */
#define game_alloc(this, size)   game_alloc16(this, size)
#else
#define game_alloc(this, size)   game_alloc_DEBUG(this, size, __FILE__, __LINE__)
#define game_alloc16(this, size) game_alloc(this, size)
#endif

extern int game_getFreeBytes(Game *);
extern void game_get_controller(Game *); /* コントローラーデータの取得 */
extern void game_resize_hyral(Game *this, size_t hyral_size);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

/*
 * next_gameの設定をする
 */
#ifndef HAYAKAWA_TESTdx
#define game_set_next_game_name(game, name) \
if (1) { \
    Game *_g = game; \
    (_g)->next_game_init = name##_init; \
    (_g)->next_game_class_size = sizeof(Game_##name); \
} else
#define game_set_next_game_null(game) \
if (1) { \
    Game *_g = game; \
    (_g)->next_game_init = NULL; \
    (_g)->next_game_class_size = 0; \
} else
#else
#define game_set_next_game_name(game, name) \
    ((game)->next_game_dlf_no = GAME_DLF_##name)
#define game_set_next_game_null(game) \
    ((game)->next_game_dlf_no = -1)
#endif
#define Game_set_next_game_name(name) \
    game_set_next_game_name(game, name)
#define Game_set_next_game_null() \
    game_set_next_game_null(game)
    
/* メモリーアロケーション簡略化 */
#define game_new(game, type) 	((type *)game_alloc(game, sizeof(type)))
#define Game_alloc(size) 	game_alloc(game, size)
#define Game_new(type) 		Game_new(game, type)
#define Game_getFreeBytes() 	game_getFreeBytes(game)

/* ゲームパッドアクセス簡略化 */
#define Game_pad_push_only(bit) pad_push_only(&game->pads[0], bit)
#define Game_pad_push_also(bit) pad_push_also(&game->pads[0], bit)
#define Game_pad_on_trigger(bit) pad_on_trigger(&game->pads[0], bit)
#define Game_pad_off_trigger(bit) pad_off_trigger(&game->pads[0], bit)
#define Game_pad_stick_x() pad_stick_x(&game->pads[0])
#define Game_pad_stick_y() pad_stick_y(&game->pads[0])
#define Game_pad_relative_stick_x() pad_relative_stick_x(&game->pads[0])
#define Game_pad_relative_stick_y() pad_relative_stick_y(&game->pads[0])
#define Game_pad_physical_stick_x() pad_physical_stick_x(&game->pads[0])
#define Game_pad_physical_stick_y() pad_physical_stick_y(&game->pads[0])
#define Game_pad_logical_stick_x() pad_logical_stick_x(&game->pads[0])
#define Game_pad_logical_stick_y() pad_logical_stick_y(&game->pads[0])
#define game_pad(game) ((game)->pads[0])
#define Game_pad() (game->pads[0])

/* ゲームフレーム数の設定／取得 */
#define GetGameFrame() ((int)SREG(30))
#define SetGameFrame(x) (SREG(30) = (short)(x))

#endif /* __GAME_H_ */
