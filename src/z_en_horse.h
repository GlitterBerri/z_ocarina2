/* $Id: z_en_horse.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/*
 * $Log: z_en_horse.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.115  1998/10/07 15:14:40  matutani
 * *** empty log message ***
 *
 * Revision 1.114  1998-10-07 01:27:23+09  matutani
 * *** empty log message ***
 *
 * Revision 1.113  1998-09-26 22:59:51+09  matutani
 * *** empty log message ***
 *
 * Revision 1.112  1998-09-23 14:46:51+09  matutani
 * *** empty log message ***
 *
 * Revision 1.111  1998-09-18 20:56:57+09  matutani
 * *** empty log message ***
 *
 * Revision 1.110  1998-09-14 14:46:15+09  matutani
 * シーン侵入時操作停止カウンター
 *
 * Revision 1.109  1998-09-03 23:57:04+09  matutani
 * *** empty log message ***
 *
 * Revision 1.108  1998-09-01 20:16:43+09  matutani
 * *** empty log message ***
 *
 * Revision 1.107  1998-08-31 23:08:57+09  matutani
 * *** empty log message ***
 *
 * Revision 1.106  1998-08-25 20:50:12+09  matutani
 * インゴ─錯乱中
 * 馬降り禁止
 *
 * Revision 1.105  1998-08-12 12:00:45+09  matutani
 * サウンド位置計算
 *
 * Revision 1.104  1998-08-11 21:22:15+09  matutani
 * ジャンプ暫定調整バージョン
 * エフェクトつき
 *
 * Revision 1.103  1998-08-11 16:41:35+09  matutani
 * 馬ジャンプ暫定版
 *
 * Revision 1.102  1998-08-10 22:02:34+09  matutani
 * *** empty log message ***
 *
 * Revision 1.101  1998-08-10 09:25:43+09  matutani
 * *** empty log message ***
 *
 * Revision 1.100  1998-08-04 15:56:45+09  matutani
 * *** empty log message ***
 *
 * Revision 1.99  1998-07-24 20:35:13+09  matutani
 * 汎用馬時、騎乗するときに馬が移動するのを訂正。
 *
 * Revision 1.98  1998-07-07 22:09:28+09  matutani
 * 停止移動系ツールデモ対応
 *
 * Revision 1.97  1998-06-24 19:19:30+09  matutani
 * *** empty log message ***
 *
 * Revision 1.96  1998-06-19 13:43:59+09  matutani
 * 流鏑馬フェードアウトカウンター
 *
 * Revision 1.95  1998-06-18 15:42:54+09  matutani
 * ツールデモ終了時のアニメーション不連続訂正
 *
 * Revision 1.94  1998-06-17 21:37:02+09  matutani
 * シーン切り替え時小走り
 *
 * Revision 1.93  1998-06-11 22:29:09+09  matutani
 * *** empty log message ***
 *
 * Revision 1.92  1998-06-10 22:53:56+09  matutani
 * *** empty log message ***
 *
 * Revision 1.91  1998-06-10 19:16:53+09  matutani
 * spot20スタートセット
 *
 * Revision 1.90  1998-06-08 16:27:42+09  matutani
 * インゴ─のいかさまセット
 *
 * Revision 1.89  1998-06-08 14:59:10+09  matutani
 * レース中に”おりる”がでるのをなくした。
 *
 * Revision 1.88  1998-06-06 22:59:11+09  matutani
 * *** empty log message ***
 *
 * Revision 1.87  1998-06-05 18:18:36+09  matutani
 * *** empty log message ***
 *
 * Revision 1.86  1998-06-04 20:35:06+09  matutani
 * 外ヅラマクロ追加
 *
 * Revision 1.85  1998-05-12 22:44:34+09  matutani
 * *** empty log message ***
 *
 * Revision 1.84  1998-05-11 22:39:39+09  matutani
 * *** empty log message ***
 *
 * Revision 1.83  1998-05-06 22:54:57+09  matutani
 * *** empty log message ***
 *
 * Revision 1.82  1998-05-05 22:27:19+09  matutani
 * *** empty log message ***
 *
 * Revision 1.81  1998-04-22 21:52:27+09  matutani
 * *** empty log message ***
 *
 * Revision 1.80  1998-04-18 22:17:51+09  matutani
 * *** empty log message ***
 *
 * Revision 1.79  1998-04-17 22:47:34+10  matutani
 * *** empty log message ***
 *
 * Revision 1.78  1998-04-14 00:06:51+10  matutani
 * *** empty log message ***
 *
 * Revision 1.77  1998/04/09  13:45:19  matutani
 * *** empty log message ***
 *
 * Revision 1.76  1998/04/08  02:58:44  matutani
 * ゲルド鞍
 *
 * Revision 1.75  1998/04/07  09:27:57  matutani
 * *** empty log message ***
 *
 * Revision 1.74  1998/04/06  13:34:53  matutani
 * *** empty log message ***
 *
 * Revision 1.73  1998/03/30  06:45:52  matutani
 * *** empty log message ***
 *
 * Revision 1.72  1998/03/24  07:45:05  matutani
 * *** empty log message ***
 *
 * Revision 1.71  1998/03/23  13:26:48  matutani
 * *** empty log message ***
 *
 * Revision 1.70  1998/03/21  12:36:46  matutani
 * 草笛調整
 *
 * Revision 1.69  1998/03/20  04:47:41  matutani
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.68  1998/03/18  08:19:38  matutani
 * 草笛用処理（基本動作）
 *
 * Revision 1.67  1998/03/16  14:09:49  matutani
 * ARGのラベル順を変えた
 *
 * Revision 1.66  1998/03/13  13:35:25  matutani
 * *** empty log message ***
 *
 * Revision 1.65  1998/03/10  06:50:20  matutani
 * *** empty log message ***
 *
 * Revision 1.64  1998/02/25  03:09:33  matutani
 * *** empty log message ***
 *
 * Revision 1.63  1998/02/18  13:12:29  matutani
 * ソース整理
 *
 * Revision 1.62  1998/02/16  13:43:19  matutani
 * *** empty log message ***
 *
 * Revision 1.61  1998/02/09  13:05:52  matutani
 * マクロ訂正
 *
 * Revision 1.60  1998/02/09  13:04:08  matutani
 * *** empty log message ***
 *
 * Revision 1.59  1997/12/01  07:06:12  matutani
 * En_Horse_CheckJump追加
 *
 * Revision 1.58  1997/11/11  11:21:41  matutani
 * *** empty log message ***
 *
 * Revision 1.57  1997/11/10  07:53:31  matutani
 * コリジョンのデバッグに使用／音追加
 *
 * Revision 1.56  1997/11/06  06:42:47  matutani
 * *** empty log message ***
 *
 * Revision 1.55  1997/11/01  12:00:00  matutani
 * *** empty log message ***
 *
 * Revision 1.54  1997/10/28  05:46:03  matutani
 * Jump訂正
 *
 * Revision 1.53  1997/10/18  14:12:22  matutani
 * コリジョン情報構造体追加
 *
 * Revision 1.52  1997/10/06  11:13:31  matutani
 * *** empty log message ***
 *
 * Revision 1.51  1997/10/06  08:06:26  matutani
 * データ差し換え
 *
 * Revision 1.50  1997/10/02  12:56:54  matutani
 * *** empty log message ***
 *
 * Revision 1.49  1997/09/25  06:51:23  matutani
 * 鞭を当てたときに鳴くのをタイマーチェック
 *
 * Revision 1.48  1997/09/24  13:56:04  matutani
 * *** empty log message ***
 *
 * Revision 1.47  1997/09/24  03:09:54  matutani
 * リンク鞭入れ
 *
 * Revision 1.46  1997/09/22  12:04:07  matutani
 * *** empty log message ***
 *
 * Revision 1.45  1997/09/19  14:02:59  matutani
 * *** empty log message ***
 *
 * Revision 1.44  1997/09/17  05:57:42  matutani
 * *** empty log message ***
 *
 * Revision 1.43  1997/09/16  10:15:21  matutani
 * *** empty log message ***
 *
 * Revision 1.42  1997/09/11  05:00:19  matutani
 * むちメーター
 * 
 * Revision 1.41  1997/09/10  13:41:29  matutani
 * *** empty log message ***
 *
 * Revision 1.40  1997/09/09  11:04:15  matutani
 * 騎乗後発進 
 *
 * Revision 1.39  1997/09/09  00:34:11  matutani
 * *** empty log message ***
 *
 * Revision 1.38  1997/09/06  13:57:00  matutani
 * *** empty log message ***
 *
 * Revision 1.37  1997/09/04  10:35:48  matutani
 * *** empty log message ***
 *
 * Revision 1.36  1997/09/01  04:36:36  matutani
 *  障害衝突時─＞前進／バック
 *
 * Revision 1.35  1997/08/30  05:53:51  matutani
 * 旧馬アニメーション削除
 *
 * Revision 1.34  1997/08/27  02:59:02  matutani
 * *** empty log message ***
 *
 * Revision 1.33  1997/08/25  11:48:54  matutani
 * 侵入禁止チェック
 *
 * Revision 1.32  1997/08/23  12:37:35  matutani
 * *** empty log message ***
 *
 * Revision 1.31  1997/08/23  09:26:26  matutani
 * 煙エフェクト追加
 *
 * Revision 1.30  1997/08/22  06:21:11  matutani
 * *** empty log message ***
 *
 * Revision 1.29  1997/08/21  09:55:34  matutani
 * *** empty log message ***
 *
 * Revision 1.28  1997/08/21  01:37:03  matutani
 * En_Horse_Actor_mode_wait02追加
 *
 * Revision 1.27  1997/08/19  13:26:02  matutani
 * *** empty log message ***
 *
 * Revision 1.26  1997/08/18  00:46:43  matutani
 * 法線処理
 *
 * Revision 1.25  1997/08/11  02:11:17  matutani
 * 降りれるか？
 *
 * Revision 1.24  1997/08/09  12:15:11  matutani
 *  弓発射時／状態固定
 *
 * Revision 1.23  1997/08/07  01:32:37  matutani
 * *** empty log message ***
 *
 * Revision 1.22  1997/08/05  05:21:08  matutani
 * 新シェイプ
 *
 * Revision 1.21  1997/08/04  05:17:44  matutani
 * その場回転／後進
 *
 * Revision 1.20  1997/07/18  11:12:54  matutani
 * 騎乗位置
 *
 * Revision 1.19  1997/07/16  08:36:36  matutani
 * 3Dサウンド
 *
 * Revision 1.18  1997/07/16  07:14:57  matutani
 * 馬の音暫定版
 *
 * Revision 1.17  1997/07/11  12:45:26  matutani
 * *** empty log message ***
 *
 * Revision 1.16  1997/07/11  12:44:50  matutani
 * *** empty log message ***
 *
 * Revision 1.15  1997/07/11  12:44:11  matutani
 * EN_HORSE_CS_OTHER_SIN 0.939692f
 *
 * Revision 1.14  1997/07/11  11:37:39  matutani
 * test
 *
 * Revision 1.13  1997/07/11  11:37:12  matutani
 * *** empty log message ***
 *
 * Revision 1.12  1997/07/11  11:34:17  matutani
 * コメント追加
 * 
 *  * アニメーション種類
 *  * 追加時/順番変更はプレイヤーに連絡
 *  
 * Revision 1.11  1997/07/11  08:18:45  matutani
 * アニメーションタイプ／フレーム数取得マクロ追加
 *
 * Revision 1.10  1997/07/11  07:10:21  matutani
 * 馬状態（アニメーション／フレーム数）
 *
 * Revision 1.9  1997/07/11  05:38:52  matutani
 * PRINTFを消した
 *
 * Revision 1.8  1997/07/11  04:58:45  matutani
 * うま騎乗テスト
 *
 * Revision 1.7  1997/07/09  10:05:12  matutani
 * 騎乗処理テスト
 *
 * Revision 1.6  1997/07/09  05:37:00  matutani
 * 騎乗スタート
 *
 * Revision 1.5  1997/06/23  05:56:18  matutani
 * 馬のシェイプのx回転付加
 *
 * Revision 1.4  1997/04/14  01:15:19  matutani
 * エフェクトテスト
 *
 * Revision 1.3  1997/03/28  12:14:44  matutani
 * シェイプのグローバル位置計算テスト
 *
 * Revision 1.2  1997/03/25  07:46:47  matutani
 * スキン処理追加
 *
 * Revision 1.1  1997/02/25  08:04:16  matutani
 * Initial revision
 *
 *
 */
    
/*----------------------------------------------------------------------------
 *
 * z_en_horse.h
 *
 * スキン処理 うま
 *
 * Program:Kenji Matsutani
 * 1997/02/25
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EN_HORSE_H
#define INCLUDE_Z_EN_HORSE_H
 
#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
#include"z_actor.h"
#include"z_basic.h"
#include"z_collision_type.h"
#include"z_skin.h"
#include"z_fcurve_data_skelanime_type.h"

/* デバッグオプション */
#undef HL_COL_TEST
    
/*
 * 馬動作モード
 * z_en_horse.c のmode_functionと関連あり。
 */
typedef enum {
    /* 放牧中 */
    EN_HORSE_MODE_WAIT_LOCK, /* 6 */
    
    /* スリープモード */
    EN_HORSE_MODE_SLEEP,

    /* 基本動作モード */
    EN_HORSE_MODE_BASE_WAIT,
    EN_HORSE_MODE_BASE_MOVE,

    /* 自動走行 */
    EN_HORSE_MODE_RACE_RUN,
    
    /* 以下 制御下 */
    /* wait */
    EN_HORSE_MODE_CONTROL_WAIT, /* 7 */
    EN_HORSE_MODE_CONTROL_WAIT02, /* 8 */
    EN_HORSE_MODE_CONTROL_ROT_WAIT, /* 9 */
    /* 走行時 */
    EN_HORSE_MODE_CONTROL_WALK, /* 10 */
    EN_HORSE_MODE_CONTROL_SLOW_RUN, /* 11 */
    EN_HORSE_MODE_CONTROL_FAST_RUN, /* 12 */
    /* その他 */
    EN_HORSE_MODE_CONTROL_STANDING, /* 13 */
    EN_HORSE_MODE_CONTROL_STOP, /* 14 */
    EN_HORSE_MODE_CONTROL_BACK_WALK,
    /* デモ */
    EN_HORSE_MODE_DEMO_JUMP100,
    EN_HORSE_MODE_DEMO_JUMP200,
    EN_HORSE_MODE_DEMO_SPOT09_BRIDGE_JUMP,
    
    /* ツールデモ */
    EN_HORSE_MODE_TD_MOVE,

    /* 流鏑馬モード */
    EN_HORSE_MODE_YABUSAME_MODE,

    /* 初期設置Spot20:逃げモード */
    EN_HORSE_MODE_SPOT20_START_RUN,
    
    EN_HORSE_MODE_LAST_INDEX
} EN_HORSE_ACTION_MODE;

/*
 * アニメーション種類
 * 追加時/順番変更はプレイヤーに連絡
 * また、z_en_horse.cのskin_horse_anm_tblとも関連あり。
 */
typedef enum {
    EN_HORSE_ANIM_HL_WAIT,
    EN_HORSE_ANIM_HL_WAIT02,
    EN_HORSE_ANIM_HL_STOP,
    EN_HORSE_ANIM_HL_STAND,
    
    EN_HORSE_ANIM_HL_WALK,
    EN_HORSE_ANIM_HL_SLOWRUN,
    EN_HORSE_ANIM_HL_FASTRUN,

    EN_HORSE_ANIM_HL_JUMP100,
    EN_HORSE_ANIM_HL_JUMP200,

    EN_HORSE_ANIM_LAST_INDEX
} EN_HORSE_ANIM_TYPE;

/*
 * 馬用
 * arg_dataラベル
 */
typedef enum {
    /* リンクが乗っていない */
    EN_HORSE_NO_SET, /* なし:０ */
    EN_HORSE_ARGD_NO_WALK, /* 放牧中にうろうろしない:１ */
    EN_HORSE_ARGD_SLEEP, /* sleep状態:２ */
    EN_HORSE_ARGD_SPOT20_RIVAL, /* spot20の相手の馬:３ */
    
    /* リンクが乗っている: */
    EN_HORSE_ARGD_LOCK_RUN_RIDE, /* lock(wait)-->run:４ */
    EN_HORSE_ARGD_NORMAL_WAIT_RIDE, /* ロックしない:５ */
    EN_HORSE_ARGD_SPOT20_RIDE, /* spot20用騎乗セット:１０ */
    EN_HORSE_ARGD_TD, /* ツールデモ:１１ */
    EN_HORSE_ARGD_SPOT12_RIDE, /* spot12用騎乗セット:１２ */
    EN_HORSE_ARGD_SCENE_CHANGE_WALK, /* シーン切り替え時にスピードを持っている。 */
    EN_HORSE_ARGD_TD_2_CONTROL, /* ツールデモから操作モードへ */
    
    EN_HORSE_ARGD_LAST_INDEX /* ARGを増やしたら,grepでこれを確認すべし。 */
} EN_HORSE_ARG_DATA;

/*
 * 馬：メジャーモード
 * どういう動作を馬にさせるか。
 */
typedef enum {
    EN_HL_NONE_MM, /* 特に無し */
    EN_HL_LINK_DROP_RETURN_MM, /* 下ろして、返る */
    EN_HL_LAST_INDEX_MM
} EN_HL_MM;

/* 状態ビット */
/* なし:これを基本とする */
#define EN_HORSE_STATUS_NO_MASK 0
/* ムチ入れ加速中 */
#define EN_HORSE_STATUS_MUTI (1<<0)
/* ムチ入れ減速中 */
#define EN_HORSE_STATUS_MUTI_REDUCE_SPEED (1<<1)
/* ジャンプ中 */
#define EN_HORSE_STATUS_JUMP (1<<2)
/* 描画中のride_pos セット中止 */
#define EN_HORSE_STATUS_STOP_RIDE_POS_SET (1<<3)
/* 緊急停止状態フラグ(前方） */
#define EN_HORSE_STATUS_FRONT_EMERGENCY_STOP_FLAG (1<<4)
/* 緊急停止状態フラグ(後方） */
#define EN_HORSE_STATUS_BACK_EMERGENCY_STOP_FLAG (1<<5)
/* ”降りて！！”フラグ (1<<6) */
#define EN_HORSE_STATUS_ORITE_FLAG (1<<6)
/* 放牧waitのみセット */
#define EN_HORSE_STATUS_GRAZING_WAIT_ONLY (1<<7)
/* 鞭アニメーションセット */
#define EN_HORSE_STATUS_LINK_WHIP_ANIM_SET (1<<8)
/* スタート時の鞭セット */
#define EN_HORSE_STATUS_LINK_START_WHIP_ANIM_SET (1<<9)
/* ストップ時のいななくフラグ （ウエイト中） */
#define EN_HORSE_STATUS_STOP_NEIGH_WAIT (1<<10)
/* いななき時,足音セットフラグ */
#define EN_HORSE_STATUS_STANDING_LAND2_SE (1<<11)
/* wait時,足すり音セット */
#define EN_HORSE_STATUS_WAIT_SANDDUST_SE (1<<12)
/* 馬寝ているマスク */
#define EN_HORSE_STATUS_SLEEP_ON (1<<13)
/* 障害あり:move処理内でチェックをすること */
#define EN_HORSE_STATUS_OBSTACLE (1<<14)
/* base_move用 standing向き変更中フラグ */
#define EN_HORSE_STATUS_BASE_MOVE_STANDING_ROT (1<<15)
/* リンクの騎乗リクエストを行わない */
#define EN_HORSE_STATUS_NO_RIDE_REQUEST (1<<16)
/* これが立っている間はジャンプを行えない */
#define EN_HORSE_STATUS_NO_JUMP (1<<17)
/* ゲルド鞍（このビットが立っていて,外見がレース馬の場合） */
#define EN_HORSE_STATUS_GELD_KURA (1<<18)
/* スポット２０レース用 */
#define EN_HORSE_STATUS_SPOT20_RACE (1<<19)
/* スポット２０レース ２回目汎用馬スタート時大暴れ１ */
#define EN_HORSE_STATUS_SPOT20_RACE_SECOND_STOP1 (1<<20)
/* スポット２０レース ２回目汎用馬スタート時大暴れ２ */
#define EN_HORSE_STATUS_SPOT20_RACE_SECOND_STOP2 (1<<21)
/* 鞭１回目回復まだ */
#define EN_HORSE_STATUS_MUTI_FIRST_RECOVER (1<<22)
/* インゴー馬のゴール */
#define EN_HORSE_STATUS_INGO_GOAL (1<<23)
/* BGチェックとxrotをはずす */
#define EN_HORSE_STATUS_BG_XROT_OFF (1<<24)
/* 降りれない */
#define EN_HORSE_STATUS_CANT_ORIRU (1<<25)
/* Spot20タイムアタック専用ジャンプ指定 （うま柵のみジャンプ可能） */
#define EN_HORSE_STATUS_SPOT20_TA_JUMP (1<<26)
/* Drawをおこなった？ */
#define EN_HORSE_STATUS_DRAW_ON (1<<27)
 
/* プレイヤーとの位置関係 */
typedef enum {
    PPR_FR, /* 前右 */
    PPR_FL, /* 前左 */
    PPR_RR, /* 後ろ右 */
    PPR_RL, /* 後ろ左 */
    PPR_SR, /* 横右 */
    PPR_SL  /* 横左 */
} PLAYER_POS_RELATION;


/* 馬:外ヅラ指定 */
typedef enum {
    HL_EPONA_OUTSIDE, /* エポナ */
    HL_HNI_OUTSIDE, /* インゴー馬 */
    HL_OUTSIDE_LAST_INDEX
} HL_OUTSIDE;

/*===========================================================================
 *
 * デモ関連情報
 *
 *==========================================================================*/

/* 現在のデモモード */
typedef enum {
    HL_DEMO_NULL,
    HL_DEMO_RUN,
    HL_DEMO_JUMP,
    HL_DEMO_WAIT,
    HL_DEMO_CHANGE_POS_RUN,
    HL_DEMO_CHANGE_POS_WAIT,
    HL_DEMO_LAST_INDEX
} HL_DEMO;

/* デモ用状態ビット */
/* デフォルト */
#define HL_DEMO_STTS_DEFAULT (0)
/* ジャンプ終了 */
#define HL_DEMO_STTS_JUMP_END (1<<0)
/* wait中standing済み */
#define HL_DEMO_STTS_WAIT_STAND (1<<2)

/* デモデータ構造体 */
typedef struct hl_demo_type {
    HL_DEMO mode; /* デモモード */
    unsigned short status; /* 状態ビット */
} HL_DEMO_TYPE;

/*===========================================================================
 *
 * レース関連データ
 *
 *=========================================================================*/
/* レース用状態ビット */
/* デフォルト */
#define HL_RACE_STTS_DEFAULT (0)
/* 鞭当て */
#define HL_RACE_STTS_MUTI (1<<0)

/* レースデータ構造体 */
typedef struct hl_race_type {
    int start_flag;
    Actor *rider;
    int muti_counter; /* 鞭カウンター */
    unsigned short status; /* 状態ビット */
    float near_max_speed;
} HL_RACE_TYPE;

/*===========================================================================
 *
 * 流鏑馬構造体
 *
 *==========================================================================*/
/* モード列挙型 */
typedef enum {
    HL_YABU_START,
    HL_YABU_TURN_A,
    HL_YABU_RETURN,
    HL_YABU_TURN_B
} HL_YABU_MODE;

/*
 * 状態ビット
 */
/* デフォルト */
#define HL_YABU_STTS_DEFAULT 0
/* 停止 ＆ 流鏑馬終了停止 */
#define HL_YABU_STTS_STOP (1<<0)
/* 停止 ＆ 流鏑馬終了手前 */
#define HL_YABU_STTS_END (1<<1)
/* BGM済み */
#define HL_YABU_STTS_BGM_END (1<<2)

/* データ構造体 */
typedef struct hl_yabusame_type {
    HL_YABU_MODE mode; /* 動作モード */
    int start_flag; /* スタートフラッグ */
    unsigned int status; /* 状態ビット */
    int fade_counter; /* アローがゼロになったときのフェードタイマー */
} HL_YABUSAME_TYPE;

/*===========================================================================
 *
 * Spot09馬ジャンプ構造体
 *
 *==========================================================================*/
typedef struct spot09_bridge_jump {
    unsigned char jump_index;
    xyz_t jump_start_pos;
    int counter;
    float vy;
    short start_diff_angle_sy;
} Spot09BridgeJump;

/*==========================================================================
 *
 * Dust Effect 構造体
 *
 *=========================================================================*/
#define HL_DUST_FR_ON (1<<0)
#define HL_DUST_FL_ON (1<<1)
#define HL_DUST_RR_ON (1<<2)
#define HL_DUST_RL_ON (1<<3)
typedef struct hl_dust {
    unsigned short flag;
    /* 前 */
    xyz_t fr;
    xyz_t fl;
    /* 後ろ */
    xyz_t rr;
    xyz_t rl;
} HlDust;

/*===========================================================================
 *
 * 馬 アクター構造体
 *
 *==========================================================================*/
typedef struct en_horse_actor {
    Actor actor; /* 基底クラス */

    /*-------------
     *
     * 汎用データ
     *
     *-------------*/
    EN_HORSE_ACTION_MODE mode;

    int timer; /* タイマー */
    int max_timer; /* タイマー最大値 */
    
    HL_OUTSIDE outside; /* 外ヅラ */
    signed char change_bank_ID;	/* 変更バンクＮｏ */
    Skin_AnimationWorkBuffer2 skin_awb2;

    unsigned long status; /* bit状態ステータス */

    xyz_t old_pos; /* 一つ前の位置 */
    short old_angle_sy; /* そのフレームの動作前のshape.angle.sx */

    int rail_wrk;

    /* 性能パラメータ */
    int muti_speed;
    
    /* 制御下にあるかどうかのフラグ */
    int control_flag;
    
    /*
     * アニメーションの種類
     */
    EN_HORSE_ANIM_TYPE anim_type;

    /*
     * 現在の表示フレーム:他の参照用
     */
    float current_frame;
    
    /*
     * サウンド作業カウンター
     */
    int sound_cnt;
    xyz_t sound_head_pos;
    xyz_t sound_head_calc_pos;

    /*
     * エフェクト作業カウンタ
     * 各エフェクトで利用目的が変る可能性あり
     */
    int effect_cnt;

    /*
     * ムチ入れカウンター
     */
    unsigned char muti_counter;
    int muti_recover_timer; /* ０以外の時は回復のためのカウンタ */
    int muti_timer; /* 作業用 */
    
    /*
     * 描画後処理
     * NULLの時処理しない
     */
    void (* draw_after)(struct en_horse_actor *this,
		       Game_play *pgame_play);

    /*
     * 足下位置
     */
    float front_y;
    float back_y;

    /* 追跡時用 */
    /* フレームカウンタ */
    short frame_cnt;
    
    /*---------------------
     *
     * 自動動作関連データ
     *
     *---------------------*/

    /*----------------------
     *
     * 切り替え時
     *
     *----------------------*/
    EN_HORSE_ACTION_MODE mode_old; /* 一つ前のモード */

    /*-----------------------
     *
     * control モード関連
     *
     *----------------------*/
    /*
     * 騎乗位置
     */
    xyz_t ride_pos;

    /* 現在のスティック情報 */
    xy_t stick;
    /* 一つ前のスティック情報 */
    xy_t old_stick;

    /*----------------------
     *
     * デモモード関連
     *
     *----------------------*/
    float demo_start_y; /* デモ開始時のy座標 */

    /*-------------------------
     *
     * コリジョン情報
     *
     *------------------------*/
    ClObjPipe acoc_pipe_info; /* Obj Collision:前部 */
    ClObjPipe acoc_pipe_info_back; /* 後部 */
    ClObjJntSph acoc_jntsph_info; /* 頭部 */
    ClObjJntSphElem sph[1]; /* 球１個 */

    /* プレイヤーとの位置関係 */
    PLAYER_POS_RELATION ppr;

    /* standing rotターゲット */
    short standing_rot_y; /* 特殊処理 */
    short target_angle;
    short target_step_angle;
    
    /* 目パチインデックス */
    unsigned char mepachi_index;
    
    /*------------------------
     *
     * 作業領域
     *
     *-----------------------*/
    short work[1];
#ifdef HL_COL_TEST
    ClObjTris tri;
    ClObjJntSph sph;
#endif
    
    HL_DEMO_TYPE demo;
    HL_RACE_TYPE race;
    HL_YABUSAME_TYPE yabu;
    Spot09BridgeJump spot09_bj;
    HlDust dust;
} En_Horse_Actor;

/*
 * 新ジョイントインデックス
 */
#define EN_HORSE_HL_HEAD_SKIN_MDL 13
#define EN_HORSE_HL_TAILB_JNT 2
#define EN_HORSE_HL_TAILA_JNT 3
#define EN_HORSE_HL_NECKB_JI 9
#define EN_HORSE_HL_CENTER_JI 0
#define EN_HORSE_HL_KURA_JI 30
#define EN_HORSE_HL_FLFOOT_JI 20
#define EN_HORSE_HL_FRFOOT_JI 28
#define EN_HORSE_HL_RLFOOT_JI 37
#define EN_HORSE_HL_RRFOOT_JI 45


/*----------------------------------------------------------------------
 *
 * 馬処理関数
 *
 *----------------------------------------------------------------------*/

/*---------------------------------------------------------------------------
 *
 * en_skeleton1 プロフィール
 *
 *--------------------------------------------------------------------------*/
extern Actor_profile En_Horse_Profile;

/*           
 * 固定値
 */
#define EN_HORSE_SCALE (1.0f/100.0f)
#define EN_HORSE_GRAVITY -3.5f
#define EN_HORSE_EYE_OFFSET_POS 70.0f
#define FAST_SPEED 8

/*
 * マクロ
 */

/*------------------------------------------------------------------------
 *
 * うま最大速度:100倍でない
 *
 *----------------------------------------------------------------------*/
#define En_Horse_get_max_speed() FAST_SPEED

/*------------
 * Check Side
 *------------*/

/*
 * どちら側にいるかチェック
 */
#define EN_HORSE_CS_RIGHT 1
#define EN_HORSE_CS_LEFT (-1)
#define EN_HORSE_CS_OTHER 0
/*
 * 位置チェックの前方／後方（OTHER）の広がり
 */
/*
 * sin(60') = 0.8660254f
 * sin(70') = 0.86602f
 * sin(80') = 0.98480775f
 * sin(85') = 0.996194f
 */
#define EN_HORSE_CS_OTHER_SIN 0.8660254f

/*
 * メンバー取得マクロ
 */
#define En_Horse_getAnimType(actor) (((En_Horse_Actor *)(actor))->anim_type)
#define En_Horse_getCurrentFrame(actor) \
(((En_Horse_Actor *)(actor))->current_frame)

/*------------
 * Ride Check
 *------------*/
/*
 * どちら側から騎乗できるか？
 */
#define EN_HORSE_CR_LEFT_OK (-1)
#define EN_HORSE_CR_RIGHT_OK (1)
#define EN_HORSE_CR_OTHER_BAD 0
/*
 * 騎乗距離
 */
#define EN_HORSE_CR_OK_LEN (75.0f)
#define EN_HORSE_CR_OK_HEIGHT (30.0f)
    
/*
 * プレイヤーから馬を見たときの騎乗OKの角度範囲
 */
/*
 * cos(80') = 0.17364818f
 */
#define EN_HORSE_CR_PLAYER_OK_ANGLE_COS (0.17364818f)


/*
 * 現在馬からおりれるか？ 
 * 停止系モード＆レース中でない
 */
#define En_Horse_CheckOriru(actor) \
(((((En_Horse_Actor *)(actor))->mode == EN_HORSE_MODE_CONTROL_WAIT  || \
   ((En_Horse_Actor *)(actor))->mode == EN_HORSE_MODE_WAIT_LOCK || \
   ((En_Horse_Actor *)(actor))->mode == EN_HORSE_MODE_CONTROL_WAIT02) && \
  ((((En_Horse_Actor *)(actor))->status & EN_HORSE_STATUS_SPOT20_RACE) \
   == 0) && \
  ((((En_Horse_Actor *)(actor))->status & EN_HORSE_STATUS_CANT_ORIRU) \
  == 0)) \
 ? True : False)
    
/* 馬から降りて!! */
#define En_Horse_CheckOrite(actor) \
    ((((En_Horse_Actor *)(actor))->status & EN_HORSE_STATUS_ORITE_FLAG) ? \
     True : False)

/* リンク鞭アニメーション */
#define En_Horse_CheckWhipAnim(actor) \
    ((((En_Horse_Actor *)(actor))->status & \
      EN_HORSE_STATUS_LINK_WHIP_ANIM_SET) \
     ? True : False)

/* リンク鞭アニメーションビットクリアー */
#define En_Horse_ClearWhipAnimBit(actor) \
    (((En_Horse_Actor *)(actor))->status &= \
     ~EN_HORSE_STATUS_LINK_WHIP_ANIM_SET)

/* リンクスタート時鞭アニメーション */
#define En_Horse_CheckStartWhipAnim(actor) \
    ((((En_Horse_Actor *)(actor))->status & \
      EN_HORSE_STATUS_LINK_START_WHIP_ANIM_SET) \
     ? True : False)

/* リンク馬ジャンプ中かどうか？ */
#define En_Horse_CheckJump(actor) \
    ((((En_Horse_Actor *)(actor))->status & \
      EN_HORSE_STATUS_JUMP) ? True : False)

/* 外ヅラマクロ */
#define En_Horse_CheckOutSide(game_play) \
    (((En_Horse_Actor *)(((Player_actor *)(get_player_actor(game_play)))->ride.actor))->outside)
    
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif
   
#endif

/*** z_en_horse.h ***/

