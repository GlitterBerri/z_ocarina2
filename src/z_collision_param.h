/* $Id: z_collision_param.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $ */
/*=============================================================================
 *
 * z_collision_param.h
 *
 * パラメータデータ
 *
 *
 *$Log: z_collision_param.h,v $
 *Revision 2.1  1998-10-22 20:45:49+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.81  1998/10/13 14:29:26  matutani
 *SPOT04の店の上の女の子用補正
 *
 *Revision 1.80  1998-10-12 22:25:28+09  matutani
 *CL_OC_BIT2_AC_JNT_SPH_ALL_CHECK追加
 *
 *Revision 1.79  1998-10-11 01:23:30+09  tarukado
 **** empty log message ***
 *
 *Revision 1.78  1998-10-10 15:23:42+09  matutani
 *ジャンプハンマー
 *
 *Revision 1.77  1998-10-08 20:23:18+09  matutani
 **** empty log message ***
 *
 *Revision 1.76  1998-10-07 21:40:29+09  matutani
 **** empty log message ***
 *
 *Revision 1.75  1998-09-29 23:13:44+09  matutani
 *CLE_AT_SPL_DAIDMG_FIRE追加
 *
 *Revision 1.74  1998-09-24 19:36:17+09  matutani
 *CLE_AC_SPL_RTN_ELEC_PLAYER追加
 *
 *Revision 1.73  1998-09-24 15:52:32+09  matutani
 *CLE_MTRL_NO_SE追加
 *
 *Revision 1.72  1998-09-18 20:56:51+09  matutani
 **** empty log message ***
 *
 *Revision 1.71  1998-09-17 00:36:10+09  matutani
 **** empty log message ***
 *
 *Revision 1.70  1998-09-05 22:58:00+09  matutani
 *OC ライン
 *
 *Revision 1.69  1998-08-31 23:10:55+09  matutani
 **** empty log message ***
 *
 *Revision 1.68  1998-07-09 15:01:22+09  matutani
 *新規ヒットマーク対応
 *
 *Revision 1.67  1998-07-08 16:32:16+09  sumiyosi
 **** empty log message ***
 *
 *Revision 1.66  1998-06-12 20:10:44+09  umemiya
 *バトルデータに光追加
 *
 *Revision 1.65  1998-06-08 11:50:36+09  tarukado
 **** empty log message ***
 *
 *Revision 1.64  1998-06-04 21:05:08+09  nisiwaki
 **** empty log message ***
 *
 *Revision 1.63  1998-06-03 22:25:39+09  matutani
 *エレメントヒットマクロ
 *
 *Revision 1.62  1998-06-02 17:34:22+09  matutani
 *ヒットマーク強制無し
 *
 *Revision 1.61  1998-06-02 11:32:29+09  matutani
 *cl_elem
 *ATへのヒット情報連絡禁止,バトルデータ計算禁止,リンクヒット時サウンド禁止
 *at_special
 *小ダメージモーションを起こす
 *
 *Revision 1.60  1998-05-28 19:41:53+09  matutani
 *馬種別、馬すり抜けＯＣビット
 *
 *Revision 1.59  1998-05-18 17:46:16+09  matutani
 *コメント追加
 *
 *Revision 1.58  1998-05-13 13:50:41+09  kuzuhara
 *攻撃マスクの追加
 *
 *Revision 1.57  1998-05-13 11:40:08+09  matutani
 **** empty log message ***
 *
 *Revision 1.56  1998-05-06 17:09:04+09  tarukado
 **** empty log message ***
 *
 *Revision 1.55  1998/05/01 06:10:51  umemiya
 *マクロをz_collision_btl_tbl.cから移動（各個人のCファイルで設定できるよう）
 *
 *Revision 1.54  1998-05-01 10:54:33+09  matutani
 *コメント（アドバイス）追加
 *
 *Revision 1.53  1998-04-29 15:46:21+09  matutani
 *マクロ訂正
 *
 *Revision 1.52  1998-04-29 15:28:45+09  matutani
 *マクロ訂正
 *
 *Revision 1.51  1998-04-29 15:00:55+09  matutani
 *プレイヤーとのOCヒット時立つビット
 *各チェックマクロ
 *
 *Revision 1.50  1998-04-28 22:20:15+09  umemiya
 *ラベル：闇の魔法（多分不要）を光の魔法に変更
 *
 *Revision 1.49  1998-04-28 20:41:55+09  umemiya
 *バトルデータ変更
 *
 *Revision 1.48  1998-04-28 19:47:01+09  umemiya
 **** empty log message ***
 *
 *Revision 1.47  1998-04-28 19:45:32+09  umemiya
 *バトルデータを変更
 *
 *Revision 1.46  1998-04-28 17:00:55+09  umemiya
 *バトルデータを変更
 *
 *Revision 1.45  1998-04-28 14:11:25+09  matutani
 **** empty log message ***
 *
 *Revision 1.44  1998-04-28 11:25:24+09  matutani
 **** empty log message ***
 *
 *Revision 1.43  1998-04-28 10:40:29+09  matutani
 *デクの実 光
 *
 *Revision 1.42  1998-04-23 22:32:00+09  matutani
 *回転切り
 *
 *Revision 1.41  1998-04-23 22:31:30+09  matutani
 **** empty log message ***
 *
 *Revision 1.40  1998-04-21 19:20:44+09  matutani
 *電撃ビリビリ吹っ飛ばし
 *
 *Revision 1.39  1998-04-21 18:09:25+09  sumiyosi
 **** empty log message ***
 *
 *Revision 1.38  1998/04/18 11:15:23  matutani
 **** empty log message ***
 *
 *Revision 1.37  1998-04-18 21:15:08+10  matutani
 **** empty log message ***
 *
 *Revision 1.36  1998-04-18 21:14:20+10  matutani
 *CLE_AT_SPL_TW_FIRE, 
 *CLE_AT_SPL_TW_ICE,
 *
 *Revision 1.35  1998-04-08 23:46:19+10  matutani
 *大ダメージモーションを起こす
 *
 * Revision 1.34  1998/04/06  05:32:37  matutani
 * CLE_AC_BIT_HOOK_PULL追加
 *
 * Revision 1.33  1998/04/04  14:09:04  matutani
 * *** empty log message ***
 *
 * Revision 1.32  1998/03/30  12:44:11  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.31  1998/03/30  06:46:01  matutani
 * *** empty log message ***
 *
 * Revision 1.30  1998/03/26  01:50:54  matutani
 * 総ての矢（パチンコ抜き）のビットタイプ追加
 *
 * Revision 1.29  1998/03/24  01:52:46  umemiya
 * CoCh_getPipeATTypeのバグ修正
 *
 * Revision 1.28  1998/03/24  01:50:56  umemiya
 * CoCh_getPipeATTypeのバグ修正
 *
 * Revision 1.27  1998/03/23  01:02:21  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.26  1998/03/21  11:59:58  matutani
 * 氷、電撃
 *
 * Revision 1.25  1998/03/18  03:00:15  ogawa
 * *** empty log message ***
 *
 * Revision 1.24  1998/03/09  13:37:47  matutani
 * ＯＣチェック変更
 *
 * Revision 1.23  1998/03/09  04:32:14  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.22  1998/02/26  06:05:19  matutani
 * 電撃返し追加
 *
 * Revision 1.21  1998/02/21  10:51:36  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.20  1998/01/26  12:01:36  morita
 * CLE_ATC_BIT_ANY_ARROW 追加
 *
 * Revision 1.19  1998/01/22  04:45:27  matutani
 * CLE_ATC_BIT_SHIELDを追加
 *
 * Revision 1.18  1997/12/18  08:13:49  sumiyosi
 * CL_EN_LBL_TYPE追加->CL_EN_SW(スタルウォール)
 *
 * Revision 1.17  1997/11/18  09:22:20  matutani
 * CoCh_SwrdGetMtrl()エラー
 *
 * Revision 1.16  1997/11/17  09:06:02  matutani
 * 暫定 CLE_MTRL_KANTSU を追加
 *
 * Revision 1.15  1997/11/14  14:27:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1997/11/14  13:40:39  iwawaki
 * p削除
 *
 * Revision 1.13  1997/11/14  11:35:46  matutani
 * *** empty log message ***
 *
 * Revision 1.12  1997/11/14  11:23:47  matutani
 * CoCh_ClObjSwrd_setAtType()追加
 *
 * Revision 1.11  1997/11/14  00:59:00  umemiya
 * 敵ラベル（ポウ、デクナッツ）追加
 *
 * Revision 1.10  1997/11/13  05:51:55  matutani
 * 追加／クリア停止処理
 *
 * Revision 1.9  1997/11/11  08:18:21  matutani
 * 盾花火追加
 *
 * Revision 1.8  1997/11/10  13:56:01  matutani
 * *** empty log message ***
 *
 * Revision 1.7  1997/11/10  06:40:47  matutani
 * 盾処理（ビット／簡易距離計算）／バトルデータ処理
 *
 * Revision 1.6  1997/11/04  12:54:11  matutani
 * ヒットマーク処理
 *
 * Revision 1.5  1997/10/31  07:51:49  matutani
 * CLE_MTRL_CORE追加
 *
 * Revision 1.4  1997/10/30  14:14:08  matutani
 * 修正
 *
 * Revision 1.3  1997/10/30  07:59:30  matutani
 * *** empty log message ***
 *
 * Revision 1.2  1997/10/30  02:36:03  matutani
 * *** empty log message ***
 *
 * Revision 1.1  1997/10/29  13:52:13  matutani
 * Initial revision
 *
 *
 *===========================================================================*/

#ifndef INCLUDE_Z_COLLISION_PARAM_H
#define INCLUDE_Z_COLLISION_PARAM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*==========================================================================
 *
 * コリジョンチェック構造体 statusビット
 *
 *=========================================================================*/
/*
 * デフォルト
 */
#define CLCH_STATUS_DEFAULT 0
/*
 * コリジョン情報の追加とクリアの禁止ビット
 * 停止時専用バージョンコリジョン追加関数あり。
 */
#define CLCH_STATUS_ALL_STOP_ADD_CLEAR (1<<0)


/*==========================================================================
 *
 * ClObjビット情報
 *
 *=========================================================================*/

/*---------------------------------------------------------------------------
 *
 * at_bitビット情報
 *
 *--------------------------------------------------------------------------*/
/* デフォルト */
#define CL_AT_BIT_NONE 0
/* 攻撃判定あり:剣など */
#define CL_AT_BIT_CHECK (1<<0)
/* 何か当った時:攻撃成功時 */
#define CL_AT_BIT_HIT (1<<1)
/* 盾にヒット:現状では盾を貫通して体にヒットした場合もヒットビットが立つ */
#define CL_AT_BIT_SHIELD_HIT (1<<2)
/* 攻撃者種別ビット:プレイヤー */
#define CL_AT_BIT_GRP_PLAYER (1<<3)
/* 攻撃者種別ビット:敵 */
#define CL_AT_BIT_GRP_ENEMY (1<<4)
/* 攻撃者種別ビット:その他 */
#define CL_AT_BIT_GRP_OTHER (1<<5)
/* 総てのグループ */
#define CL_AT_BIT_GRP_ALL (CL_AT_BIT_GRP_PLAYER|CL_AT_BIT_GRP_ENEMY| \
CL_AT_BIT_GRP_OTHER)
/* 同ActorのACにもヒット許可(ATと同じACにはヒットしない) */
#define CL_AT_BIT_SELFAT (1<<6)

/*----------------------------------------------------------------------------
 *
 * ac_bitビット情報
 *
 *---------------------------------------------------------------------------*/
/* デフォルト */
#define CL_AC_BIT_NONE 0
/* 攻撃に対する当り判定あり 体など */
#define CL_AC_BIT_CHECK (1<<0)
/* 何かあった時 */
#define CL_AC_BIT_HIT (1<<1)
/* このACが盾であるか？無いかデフォルトはゼロ */
#define CL_AC_BIT_SHIELD (1<<2)
/* 攻撃者として対象とする種別ビット (1<<3):プレイヤー */
#define CL_AC_BIT_GRP_PLAYER CL_AT_BIT_GRP_PLAYER
/* 攻撃者として対象とする種類ビット (1<<4):敵 */
#define CL_AC_BIT_GRP_ENEMY CL_AT_BIT_GRP_ENEMY
/* 攻撃者として対象とする種類ビット (1<<5):その他 */
#define CL_AC_BIT_GRP_OTHER CL_AT_BIT_GRP_OTHER
/* ダメージ計算処理をしない */
#define CL_AC_BIT_AUTO_DMG_CALC_OFF (1<<6)
/* 防御成功ビット:暫くは不正確(とにかく何かヒットしたとき立つ） */
#define CL_AC_BIT_SHIELD_SUCCESS (1<<7)
    
/*----------------------------------------------------------------------------
 *
 * oc_bitビット情報
 *
 *---------------------------------------------------------------------------*/
/* デフォルト */
#define CL_OC_BIT_NONE 0
/* OBJ当り判定あり:敵同士などの接触チェック */
#define CL_OC_BIT_CHECK (1<<0)
/* OBJの接触があった */
#define CL_OC_BIT_HIT (1<<1)
/* OBJの補正を行わない(チェックは行う） */
#define CL_OC_BIT_NO_POS_CORRECT (1<<2)
/* コリジョン対象種別ビット (1<<3):プレイヤー */
#define CL_OC_BIT_GRP_PLAYER CL_AT_BIT_GRP_PLAYER
/* コリジョン対象種別ビット (1<<4):敵 */
#define CL_OC_BIT_GRP_ENEMY CL_AT_BIT_GRP_ENEMY
/* コリジョン対象種別ビット (1<<5):その他 */
#define CL_OC_BIT_GRP_OTHER CL_AT_BIT_GRP_OTHER
/* 総てのグループ */
#define CL_OC_BIT_GRP_ALL (CL_OC_BIT_GRP_PLAYER|CL_OC_BIT_GRP_ENEMY| \
CL_OC_BIT_GRP_OTHER)
/*
 * 特殊補正１:プレイヤーのスピードを０にして、
 * 補正量総てをプレイヤーに送った。
 */
#define CL_OC_BIT_SPL1 (1<<6)

/*-----------------------------------------------------------------------------
 *
 * oc_bit2ビット情報
 *
 *---------------------------------------------------------------------------*/
/* コリジョン自己種別ビット */
/* デフォルト */
#define CL_OC_BIT2_NONE 0
/* プレイヤーとOCヒットした時 このビットが立つ */
#define CL_OC_BIT2_PLAYER_HIT (1<<0)
/* このocは馬ビット */
#define CL_OC_BIT2_HORSE (1<<1)
/* このocは馬すり抜け */
#define CL_OC_BIT2_HORSE_THROUGH (1<<2)
/* プレイヤー (1<<3) */
#define CL_OC_BIT2_SELF_PLAYER CL_AT_BIT_GRP_PLAYER
/* 敵 (1<<4) */
#define CL_OC_BIT2_SELF_ENEMY CL_AT_BIT_GRP_ENEMY
/* その他 (1<<5) */
#define CL_OC_BIT2_SELF_OTHER CL_AT_BIT_GRP_OTHER
/*
 * ＡＣチェックで関節球を総てチェックする。
 * チェックの打ち切り禁止
 */
#define CL_OC_BIT2_AC_JNT_SPH_ALL_CHECK (1<<6)
/* (1<<7) */

/*===========================================================================
 *
 * ClObjElem用
 * 各当たりの要素の基本構造体
 * メモ：各当たりを持つためのパーツに対して設定を行う。たとえば関節球の場合
 * 各球ごとにデータを持つ。
 *
 *==========================================================================*/
/*----------------------------------------------------------------------------
 *
 * 材質ラベル
 *
 *---------------------------------------------------------------------------*/
typedef enum {
    CLE_MTRL_NONE, /* 特に無し */
    CLE_MTRL_SKIN, /* 肌 */
    CLE_MTRL_METAL, /* 金属 */
    CLE_MTRL_CORE, /* 急所 */
    CLE_MTRL_KANTSU, /* 貫通 */
    CLE_MTRL_NO_SE, /* 音しません */
    CLE_MTRL_LAST_INDEX /* ラベル数 */
} CLE_MTRL_LBL_TYPE;

/*--------------------------------------------------------------------------
 *
 * 攻撃タイプ/マスクビット
 * 処理でこのビットを変数に保持するのなら、３２bitの領域を必要とするので,
 * unsigned longを使ってください。
 *
 *-------------------------------------------------------------------------*/
/*** プレイヤー ***/
#define CLE_ATC_BIT_DEKU_NUT (1<<0) /* デクの実 */
#define CLE_ATC_BIT_DEKU_ROD (1<<1) /* デクの棒 */
#define CLE_ATC_BIT_SLINGSHOT (1<<2) /* パチンコ */
#define CLE_ATC_BIT_BOMB (1<<3) /* 爆弾 */
#define CLE_ATC_BIT_BOOMERANG (1<<4) /* ブーメラン */

#define CLE_ATC_BIT_FAIRY_ARROW (1<<5) /* 妖精の弓矢 */
#define CLE_ATC_BIT_HAMMER (1<<6) /* ハンマー */
#define CLE_ATC_BIT_HOOK_SHOT (1<<7) /* フックショット */
#define CLE_ATC_BIT_KNIFE (1<<8) /* ナイフ */
#define CLE_ATC_BIT_MASTER_SWRD (1<<9) /* マスターソード */

#define CLE_ATC_BIT_GIANT_KNIFE (1<<10) /* 巨人のナイフ */
#define CLE_ATC_BIT_FIRE_ARROW (1<<11) /* 炎の矢 */
#define CLE_ATC_BIT_ICE_ARROW (1<<12) /* 氷の矢 */
#define CLE_ATC_BIT_LIGHT_ARROW (1<<13) /* 光の矢 */
#define CLE_ATC_BIT_WIND_ARROW (1<<14) /* 風の矢 */
    
#define CLE_ATC_BIT_SOUL_ARROW (1<<15) /* 魂の矢 */
#define CLE_ATC_BIT_DARK_ARROW (1<<16) /* 闇の矢 */
#define CLE_ATC_BIT_FIRE_MAGIC (1<<17) /* 炎の魔法 */
#define CLE_ATC_BIT_ICE_MAGIC (1<<18) /* 氷の魔法 */
#define CLE_ATC_BIT_LIGHT_MAGIC (1<<19) /* 光の魔法 */

#define CLE_ATC_BIT_SHIELD (1<<20) /* 盾 */
#define CLE_ATC_BIT_MIR_RAY (1<<21) /* 光の盾 */

#define CLE_ATC_BIT_ROLLING_KIRU_KF (1<<22) /* 回転ぎり:ナイフ */
#define CLE_ATC_BIT_ROLLING_KIRU_LS (1<<23) /* 回転ぎり:ロングソード */
#define CLE_ATC_BIT_ROLLING_KIRU_MS (1<<24) /* 回転ぎり:マスターソード */

#define CLE_ATC_BIT_ROLLING_KIRU_DKF (1<<25) /* 大回転切り:ナイフ */
#define CLE_ATC_BIT_ROLLING_KIRU_DLS (1<<26) /* 大回転切り:ロングソード */
#define CLE_ATC_BIT_ROLLING_KIRU_DMS (1<<27) /* 大回転切り:マスターソード */

#define CLE_ATC_BIT_DARK_MAGIC (1<<28) 	/* 闇の魔法 */
#define CLE_ATC_BIT_PL_NON_DEF (1<<29) 	/* プレイヤーガード不能 */
#define CLE_ATC_BIT_JUMP_HAMMER (1<<30) /* ジャンプハンマー */

/*
 * チェック用マスク
 */
/* 回転ぎり */
#define CLE_ATC_BIT_ROLLING_KIRU (CLE_ATC_BIT_ROLLING_KIRU_KF|CLE_ATC_BIT_ROLLING_KIRU_LS|CLE_ATC_BIT_ROLLING_KIRU_MS)  

/* 大回転切り */
#define CLE_ATC_BIT_ROLLING_KIRU_D (CLE_ATC_BIT_ROLLING_KIRU_DKF|CLE_ATC_BIT_ROLLING_KIRU_DLS|CLE_ATC_BIT_ROLLING_KIRU_DMS)

/*  "何でもあり"ですが、CLE_ATC_BIT_SHIELD,CLE_ATC_BIT_MIR_RAY を省く */
#define CLE_ATC_BIT_ANY_TYPE (0xFFFFFFFF & ~(CLE_ATC_BIT_SHIELD | CLE_ATC_BIT_MIR_RAY))

/* すべての矢 */
#define CLE_ATC_BIT_ANY_ARROW (CLE_ATC_BIT_FAIRY_ARROW | CLE_ATC_BIT_FIRE_ARROW | CLE_ATC_BIT_ICE_ARROW | CLE_ATC_BIT_LIGHT_ARROW | CLE_ATC_BIT_WIND_ARROW | CLE_ATC_BIT_SOUL_ARROW | CLE_ATC_BIT_DARK_ARROW | CLE_ATC_BIT_SLINGSHOT)

/* 総ての矢以外 */
#define CLE_ATC_BIT_NO_ARROW (0xFFFFFFFF & ~CLE_ATC_BIT_ANY_ARROW)

/* 総ての矢（パチンコ抜き）*/
#define CLE_ATC_BIT_ANY_ARROW_NO_SLSH (CLE_ATC_BIT_FAIRY_ARROW | CLE_ATC_BIT_FIRE_ARROW | CLE_ATC_BIT_ICE_ARROW | CLE_ATC_BIT_LIGHT_ARROW | CLE_ATC_BIT_WIND_ARROW | CLE_ATC_BIT_SOUL_ARROW | CLE_ATC_BIT_DARK_ARROW)

/* すべての剣 */
#define CLE_ATC_BIT_ANY_SWORD (CLE_ATC_BIT_DEKU_ROD | CLE_ATC_BIT_KNIFE | CLE_ATC_BIT_MASTER_SWRD | CLE_ATC_BIT_GIANT_KNIFE)

/*===========================================================================
 *
 * CleAtBtlInfo用ラベル
 *
 *==========================================================================*/
/*---------------------------------------------------------------------------
 *
 * AT特殊データ
 *
 *--------------------------------------------------------------------------*/
typedef enum cle_at_specail_type {
    CLE_AT_SPL_NONE, /* なし */
    CLE_AT_SPL_FIRE, /* 火 */
    CLE_AT_SPL_ICE, /* 氷 */
    CLE_AT_SPL_ELEC, /* 電撃 */
    CLE_AT_SPL_DAIDMG, /* 大ダメージモーションを起こす */
    CLE_AT_SPL_TW_FIRE, /* TW火攻撃 */
    CLE_AT_SPL_TW_ICE, /* TW氷攻撃 */
    CLE_AT_SPL_ELEC_DAIDMG, /* 電撃ビリビリ,ふっとばし */
    CLE_AT_SPL_SHOUDMG, /* 小ダメージモーションを起こす */
    CLE_AT_SPL_DAIDMG_FIRE, /* 大ダメージと火 */
    CLE_AT_SPL_LAST_INDEX
} CLE_AT_SPECIAL_TYPE;

/*===========================================================================
 *
 * CleAcBtlInfo用ラベル
 *
 *=========================================================================*/
/*---------------------------------------------------------------------------
 *
 * AC特殊データ
 *
 *-------------------------------------------------------------------------*/
typedef enum cle_ac_specail_type {
    CLE_AC_SPL_NONE, /* 無し */
    CLE_AC_SPL_RTN_ELEC, /* 電撃返し */
    CLE_AC_SPL_RTN_ELEC_PLAYER, /* プレイヤーとヒットしたときのみ電撃返し */
    CLE_AC_SPL_LAST_INDEX
} CLE_AC_SPECIAL_TYPE;

/*=========================================================================
 *
 * 当り要素ビット情報ビット内容
 * ClObjElem用
 *
 *=========================================================================*/
/*
 * ATビット情報
 *
 * 76543210
 * |||| ||+---- CLE_AT_BIT_CHECK
 * |||| |+---- CLE_AT_BIT_HIT
 * |||| +--- CLE_AT_BIT_SWRD_NEAR
 * |||+---  AT装甲ヒットマーク
 * ||+---- ヒットマーク AT制御 設定 
 * |+--- ヒットマーク表示済み (work)
 * +--- CLE_AT_BIT_SWRD_ROOT_NEAR
 */
/* 情報無し:デフォルト */
#define CLE_AT_BIT_NONE 0
/* 当り判定があるか */
#define CLE_AT_BIT_CHECK (1<<0)
/* 命中したかどうか */
#define CLE_AT_BIT_HIT (1<<1)
/*
 * 剣の命中判定でprevの中点に近い名中点を優先。
 */
#define CLE_AT_BIT_SWRD_NEAR (1<<2)
/* AT装甲ヒットマーク */
/*
 * メモ:ACのヒットマークが装甲タイプの物に当った時にどのヒットマークを
 * 出すか？を指定する
 * 76543210
 * ---**--- 4,3シフトした所を使用
 */
/* 作業マクロ */
#define CLE_AT_AR(x, y) (((x) << 4) | ((y) << 3))
/* PASSマスク */
#define CLE_AT_AR_HM_PASS_MASK CLE_AT_AR(1, 1)
/* 火花を出す:装甲側が金属盾出ない場合閃光になります。(金属系) */
#define CLE_AT_AR_HM_SPARK CLE_AT_AR(0, 0)
/* 閃光 */
#define CLE_AT_AR_HM_FLASH CLE_AT_AR(0, 1)
/* 煙:でくの棒など。モヤモヤしたマーク */
#define CLE_AT_AR_HM_SMOKE CLE_AT_AR(1, 0)
/* なし */
#define CLE_AT_AR_HM_NONE CLE_AT_AR(1, 1)

/* ATヒットマーク制御:装甲ヒットマーク優先禁止 */
#define CLE_AT_HMC_NO_AR (1<<5)
/* ヒットマーク表示済み */
#define CLE_AT_HMC_DISP_END (1<<6)
/* 剣の命中判定でprevのrootに近い点を優先 */
#define CLE_AT_BIT_SWRD_ROOT_NEAR (1<<7)

/*
 * ACビット情報
 */
/* 情報無し:デフォルト */
#define CLE_AC_BIT_NONE 0
/* 当りあり */
#define CLE_AC_BIT_CHECK (1<<0)
/* 当りがあった */
#define CLE_AC_BIT_HIT (1<<1)
/* フックショットで引ける */
#define CLE_AC_BIT_HOOK_PULL (1<<2)
/* ATへのヒット情報連絡禁止 */
#define CLE_AC_BIT_NO_AT_HIT_INFO (1<<3)
/* バトルデータ計算禁止:ダメージ計算 */
#define CLE_AC_BIT_NO_BTL_CALC (1<<4)
/* リンクヒット時サウンド禁止 */
#define CLE_AC_BIT_NO_LINK_HIT_SOUND (1<<5)
/* ヒットマーク強制無し */
#define CLE_AC_BIT_NO_HM (1<<6)
/* ヒットマーク表示待ち */
#define CLE_AC_BIT_HM_WAIT (1<<7)

/*
 * 通過マスク
 * 当たりのチェックはできるが攻撃は通過する。
 */
#define CLE_AC_BIT_THROUGH \
(CLE_AC_BIT_NO_AT_HIT_INFO|CLE_AC_BIT_NO_BTL_CALC|CLE_AC_BIT_NO_LINK_HIT_SOUND|CLE_AC_BIT_NO_HM)
    
/*
 * OBJビット情報
 */
/* デフォルト */
#define CLE_OC_BIT_NONE 0
/* 他のOBJビット情報が立っているものとコリジョンチェック */
#define CLE_OC_BIT_CHECK (1<<0)
/* OBJの接触あり */
#define CLE_OC_BIT_HIT (1<<1)

/*=========================================================================
 *
 * ClOCLine関連
 *
 *========================================================================*/
/* status ビット */
/* デフォルト */
#define CL_OC_LINE_STTS_DEFAULT 0
/* 交差 */
#define CL_OC_LINE_STTS_CROSS (1<<0)
    
/*=========================================================================
 *
 * Status情報パラメータ;
 *
 *========================================================================*/
/*-------------------------------------------------------------------------
 *
 * hitマークパラメータ
 * 血の色、ヒットマーク
 * z_collision_check.c のhitmark_functionとの整合を取ってください。
 *
 *------------------------------------------------------------------------*/
typedef enum {
    CL_HM_BB_HM1, /* 青い血,ヒットマーク１ */
    CL_HM_HM2, /* ヒットマーク２ */
    CL_HM_GB_HM2, /* 緑の血,ヒットマーク２ */
    CL_HM_HM1, /* ヒットマーク１:一応デフォルト */
    CL_HM_WB, /* 白血しぶき */
    CL_HM_HM3, /* ヒットマーク３ */
    CL_HM_GB_HM1, /* 緑の血,ヒットマーク１ */
    CL_HM_BE_HM1, /* 破裂効果,ヒットマーク１*/
    CL_HM_BB_HM3, /* 青い血,ヒットマーク３ */
    CL_HM_SH, /* 金属盾:for 装甲タイプ */
    CL_HM_NONE, /* 出さない:デバッグ用または特殊処理時 */
    CL_HM_WOOD, /* 木:for 装甲タイプ */
    CL_HM_SHELL, /* 石,岩,骸骨,甲殻:for 装甲タイプ */
    CL_HM_HM4, /* 金属破片,ぼこっ！ */
    CL_HM_LAST_INDEX
} CL_HM_TYPE;

/*----------------------------------------------------------------------------
 *
 * 血液型(細かい破片）
 *
 *--------------------------------------------------------------------------*/
typedef enum {
    CL_BLOOD_NONE, /* 血無し */
    CL_BLOOD_BLUE, /* 青い血 */
    CL_BLOOD_GREEN, /* 緑の血 */
    CL_BLOOD_WHITE, /* 白い血 */
    CL_BLOOD_BREAK, /* 血ではなく破裂効果 */
    CL_BLOOD_RED, /* 赤い血:一応使わない？ */
    CL_BLOOD_LAST_INDEX
} CL_BLOOD_TYPE;

/*---------------------------------------------------------------------------
 *
 * ヒットマーク
 *
 *-------------------------------------------------------------------------*/
typedef enum {
    CL_LBL_HM1, /* ヒットマーク１ */
    CL_LBL_HM2, /*             ２ */
    CL_LBL_HM3, /*             ３ */
    CL_LBL_HM_SH, /* 盾処理 */
    CL_LBL_HM4, /* 煙＋ぼこっ！ */
    CL_LBL_HM_LAST_INDEX
} CL_LBL_HM_TYPE;

/*============================================================================
 *
 * バトルデータ
 * 敵反応データラベル:
 * 敵固有の特殊処理の場合、CL_BTD_WORK_0から使用して下さい。
 * 汎用であると思われるものはCL_BTD_WORK_11から順次消して、
 * 新しいラベルをきって下さい。
 * ただし、そのWORKのラベルを誰も使用していないことを確認して下さい。
 *
 *===========================================================================*/
typedef enum {
    CL_BTD_NONE,			/* 無し */
    CL_BTD_STOP,			/* 止まる */
    CL_BTD_FIRE,			/* 燃える */
    CL_BTD_ICE,				/* 凍る */
    CL_BTD_LIGHT,			/* 光 */
    CL_BTD_WORK_10,
    CL_BTD_WORK_9,
    CL_BTD_WORK_8,
    CL_BTD_WORK_7,
    CL_BTD_WORK_6,
    CL_BTD_WORK_5,
    CL_BTD_WORK_4,
    CL_BTD_WORK_3,
    CL_BTD_WORK_2,
    CL_BTD_WORK_1,
    CL_BTD_WORK_0,
    CL_BTD_LAST_INDEX			/* これ以上増やさないこと */
} CL_BTD_TYPE;

#define NON(x) ((CL_BTD_NONE << 4) | x)
#define STP(x) ((CL_BTD_STOP << 4) | x)
#define FIR(x) ((CL_BTD_FIRE << 4) | x)
#define ICE(x) ((CL_BTD_ICE << 4) | x)
#define LIG(x) ((CL_BTD_LIGHT << 4) | x)
#define W10(x) ((CL_BTD_WORK_10 << 4) | x)
#define W09(x) ((CL_BTD_WORK_9 << 4) | x)
#define W08(x) ((CL_BTD_WORK_8 << 4) | x)
#define W07(x) ((CL_BTD_WORK_7 << 4) | x)
#define W06(x) ((CL_BTD_WORK_6 << 4) | x)
#define W05(x) ((CL_BTD_WORK_5 << 4) | x)
#define W04(x) ((CL_BTD_WORK_4 << 4) | x)
#define W03(x) ((CL_BTD_WORK_3 << 4) | x)
#define W02(x) ((CL_BTD_WORK_2 << 4) | x)
#define W01(x) ((CL_BTD_WORK_1 << 4) | x)
#define W00(x) ((CL_BTD_WORK_0 << 4) | x)

#if 0
/*============================================================================
 *
 * バトルデータ
 * 敵反応データラベル:ダメージと特殊処理の場合,新しいラベルをきって下さい。
 *
 *===========================================================================*/
typedef enum {
    CL_BTD_NONE = 0, /* 無し */
    CL_BTD_MAX_DMG = 20, /* ダメージマックス値 */
    CL_BTD_STOP, /* 止まる */
    CL_BTD_KO, /* KO */
    CL_BTD_FADE_OUT, /* 消える */
    CL_BTD_KOKERU, /* こける */
    CL_BTD_SHRINK, /* しぼむ */
    CL_BTD_ROT, /* 回転 */
    CL_BTD_DROP, /* 落下 */
    CL_BTD_BLOCK, /* ブロック */
    CL_BTD_RUN, /* 逃げる */
    CL_BTD_LAST_INDEX
} CL_BTD_TYPE;
#endif

/*============================================================================
 *
 * 敵ラベル
 * z_collision_btl_tbl.cのバトルデータと関連があり余す。
 *
 *==========================================================================*/
typedef enum {
    CL_EN_DEKUBABA,		/* デクババ		*/
    CL_EN_BIG_DEKUBABA,		/* ビッグデクババ	*/
    CL_EN_ST,			/* スタルチュラ		*/
    CL_EN_COGOMA,		/* コゴーマ		*/
    CL_EN_DODOJR,		/* ドドンゴJr		*/
    /* 5 */

    CL_EN_FIREFLY,		/* ファイヤーフライ	*/
    CL_EN_REEBA,		/* リーバ		*/
    CL_EN_WALLMAS,		/* ウオールマスター	*/
    CL_EN_OKUTA_ROCK,		/* オクタロック		*/
    CL_EN_BUBBLE,		/* 泡			*/

    /* 10 */
    
    CL_EN_BILI,			/* ビリ			*/
    CL_EN_HORSE,		/* お馬さん（テスト）	*/
    CL_EN_POH,			/* ポウ			*/
    CL_EN_DEKUNUTS,		/* デクナッツ		*/
    CL_EN_SW,			/* スタルウォール	*/

    /* 15 */
    
    CL_EN_FD,			/* フレイムダンサー	*/
    CL_EN_FW,			/* フレイムウォーカー	*/
    CL_EN_NPC2,			/* ＮＰＣ２		*/
    CL_EN_BB,			/* 泡			*/
    CL_EN_VALI,			/* バリ			*/

    /* 20 */

    CL_EN_EIYER,		/* エイヤー		*/
    CL_EN_BIGOKUTA,		/* ダイオクタ		*/
    CL_EN_NPC,			/* 人間			*/

    /* 25 */
    
    /* 30 */

    
    /* z_collision_btl_tbl.cの方も増やしてください:下もよんでね */
    /*
     * アドバイス:常駐のファイルに登録することがめんどうな場合や、
     * このファイルやz_collision_btl_tbl.cが触れない場合など,
     * バトルデータを各Actorの.cファイルや各アクターの構造体（
     * ダイナミックに変えれます）に領域をつくってポインターを渡せ
     * ば同じ処理が出来ます。(BtlDataの構造体が変化した時の作業
     * が大変な可能性はあります。）
     */
    
    CL_EN_LAST_INDEX		/* ラベル数(なし）	*/
} CL_EN_LBL_TYPE;
#define CL_EN_NONE CL_EN_LAST_INDEX

/*-----------------------------------------------------------------------------
 *
 * チェックマクロ
 * Check Macros
 *
 *---------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *
 * 各タイプAT,AC,OCヒットチェックマクロ
 *
 * 引数はClObjx = ClObjPipe, ClObjTris,...
 *
 * そのデータのどれかがヒットしたかどうかのビットをチェック。
 *
 *--------------------------------------------------------------------------*/
#define CollisionCheck_ClObjxATHit(x) \
(((x).cl_obj.at_bit & CL_AT_BIT_HIT) != 0)

#define CC_ATHIT(x) CollisionCheck_ClObjxATHit(x)
    
#define CollisionCheck_ClObjxACHit(x) \
    (((x).cl_obj.ac_bit & CL_AC_BIT_HIT) != 0)

#define CC_ACHit(x) CollisionCheck_ClObjxACHit(x)
    
#define CollisionCheck_ClObjxOCHit(x) \
    (((x).cl_obj.oc_bit & CL_OC_BIT_HIT) != 0)

#define CC_OCHit(x) CollisionCheck_ClObjxOCHit(x)

/*--- プレイヤーとのOCヒット:OCの自己グループ指定がプレイヤーとヒット ---*/
#define CC_OCPlayerHit(x) \
    (((x).cl_obj.oc_bit2 & CL_OC_BIT2_PLAYER_HIT) != 0)

/*---------------------------------------------------------------------------
 *
 * あるエレメントにヒットしたか？
 *
 *-------------------------------------------------------------------------*/
    
/* 関節球AT */
#define CC_JntSphElemATHit(x, i) \
    ((x).elem_tbl[(i)].cl_elem.at_bit & CLE_AT_BIT_HIT)
  
/* 関節球AC */
#define CC_JntSphElemACHit(x, i) \
    ((x).elem_tbl[(i)].cl_elem.ac_bit & CLE_AC_BIT_HIT)
    
/* 関節球OC */
#define CC_JntSphElemOCHit(x, i) \
    ((x).elem_tbl[(i)].cl_elem.oc_bit & CLE_OC_BIT_HIT)
    
/*----------------------------------------------------------------------------
 *
 * あるエレメントにヒットしたATのタイプビット情報を取得。
 * そのエレメントのヒットチェックをしておいて下さい。
 * メモ：
 * ac_hit_elemがNULLで無いことは確認してません。
 *
 *--------------------------------------------------------------------------*/
/*
 * ClObjJntSph *pjs: 関節球データへのポインター
 * int index : 球データへのインデックス
 */
#define CoCh_getJntSphATType(pjs, index) \
    ((pjs)->elem_tbl[(index)].cl_elem.ac_hit_elem->at_btl_info.at_type)

#define CC_getJntSphATType(pjs, index) CoCh_getJntSphATType(pjs, index)
    
/*
 * ClObjPipe *ppipe: パイプ情報へのポインター
 */
#define CoCh_getPipeATType(ppipe) \
    ((ppipe)->cl_elem.ac_hit_elem->at_btl_info.at_type)

#define CC_getPipeATType(ppipe) CoCh_getPipeATType(ppipe)

/*
 * ClObjTris *ptris:三角形情報へのポインター
 * int index : 三角形データ要素へのポインター
 */
#define CoCh_getTrisATType(ptris, index) \
    ((ptris)->elem_tbl[(index)].cl_elem.ac_hit_elem->at_btl_info.at_type)

#define CC_getTrisATType(ptris, index) CoCh_getTrisATType(ptris, index)
    
/*
 * ClObjSwrd *pswrd:剣情報へのポインター
 */
#define CoCh_getSwrdATType(pswrd) \
    ((pswrd)->cl_elem.ac_hit_elem->at_btl_info.at_type)

#define CC_getSwrdATType(pswrd) CoCh_getSwrdATType(pswrd)

/*--------------------------------------------------------------------------
 *
 * 盾にヒットしたかどうか？
 *
 * 引数はClObjx = ClObjPipe, ClObjTris,...
 *
 *--------------------------------------------------------------------------*/
       
#define CoCh_ClObjxATShieldHit(x) \
    (((x).cl_obj.at_bit & CL_AT_BIT_SHIELD_HIT) != 0)

#define CC_ATShieldHit(x) CoCh_ClObjxATShieldHit(x)

/*---------------------------------------------------------------------------
 *
 * 盾で防御したかどうか。
 *
 *  引数はClObjx = ClObjPipe, ClObjTris,...
 *
 *-------------------------------------------------------------------------*/
#define CoCh_ClObjxACShieldSuccess(x) \
    (((x).cl_obj.ac_bit & CL_AC_BIT_SHIELD_SUCCESS) != 0)

#define CC_ACShieldSuccess(x) CoCh_ClObjxACShieldSuccess(x)
    
/*----------------------------------------------------------------------------
 *
 * 剣構造体のビットタイプセット
 * メモ：clobjswrd ClObjSwrd
 *       at_type 攻撃タイプビット
 *
 *--------------------------------------------------------------------------*/
#define CoCh_ClObjSwrd_setAtType(clobjswrd, x) \
    ((clobjswrd).cl_elem.at_btl_info.at_type = (x))

#define CC_ClObjSwrd_setAtType(clobjswrd, x) \
    CoCh_ClObjSwrd_setAtType(clobjswrd, x)
    
/*----------------------------------------------------------------------------
 *
 * あるエレメントにヒットしたマテリアルを取得。
 * そのエレメントのヒットチェックをしておいて下さい。
 * メモ：
 * ac_hit_elemがNULLで無いことは確認してません。
 *
 *--------------------------------------------------------------------------*/
/*
 * ClObjJntSph *pjs: 関節球データへのポインター
 * int index : 球データへのインデックス
 */
#define CoCh_JntSphGetMtrl(pjs, index) \
    ((pjs)->elem_tbl[(index)].cl_elem.ac_hit_elem->material)

#define CC_JntSphGetMtrl(pjs, index) CoCh_JntSphGetMtrl(pjs, index)
    
/*
 * ClObjPipe *ppipe: パイプ情報へのポインター
 */
#define CoCh_PipeGetMtrl(ppipe) \
    ((ppipe)->cl_elem.ac_hit_elem->material)

#define CC_PipeGetMtrl(ppipe) CoCh_PipeGetMtrl(ppipe)

/*
 * ClObjTris *ptris:三角形情報へのポインター
 * int index : 三角形データ要素へのポインター
 */
#define CoCh_TrisGetMtrl(ptris, index) \
    ((ptris)->elem_tbl[(index)].cl_elem.ac_hit_elem->material)

#define CC_TrisGetMtrl(ptris, index) CoCh_TrisGetMtrl(ptris, index)
    
/*
 * ClObjSwrd *pswrd:剣情報へのポインター
 */
#define CoCh_SwrdGetMtrl(pswrd) \
    ((pswrd)->cl_elem.at_hit_elem->material)

#define CC_SwrdGetMtrl(pswrd) CoCh_SwrdGetMtrl(pswrd)

/*============================================================================
 *
 * OCライン用マクロ
 *
 *===========================================================================*/
/* 交差チェック */
#define CC_OCLineCross(pocline) ((pocline)->status & CL_OC_LINE_STTS_CROSS)
    
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/* z_collision_param.h end */
