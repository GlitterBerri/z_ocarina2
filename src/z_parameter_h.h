/* $Id: z_parameter_h.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 * $Log: z_parameter_h.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.175  1998/10/14 08:20:03  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/05/21  01:12:28  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_PARAMETER_H_H
#define INCLUDE_Z_PARAMETER_H_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_save_area_h.h"




/************************************************************************
 *									*
 *	ゼルダ６４ パラメーター						*
 *				1997年05月21日(水曜日) 10時00分00秒 JST *
 *									*
 ************************************************************************/
/* アイテム番号表 */
enum {
    H_stick,		/* 00『デクの棒』１本 */
    H_deku_nut,		/* 01『デクの実』１個 */
    H_bomb_1,		/* 02『爆弾』１個 */
    H_bow,		/* 03『妖精の弓』１本 */
    H_arrow_1,		/* 04『炎の矢』 */
    H_goddess_1,	/* 05『ディンの炎』 */
    H_pachinko,		/* 06『パチンコ』１０個 */
    H_ocarina_1,	/* 07『妖精のオカリナ』 */
    H_ocarina_2,	/* 08『時のオカリナ』 */
    H_bomb_2,		/* 09『ボムチュウ』１０個 */
    H_S_hookshot,	/* 10『ショート・フックショット』 */
    H_L_hookshot,	/* 11『ロング・フックショット』 */
    H_arrow_2,		/* 12『氷の矢』 */
    H_goddess_2,	/* 13『フロルの風』 */
    H_boomerang,	/* 14『ブーメラン』 */
    H_magicglass,	/* 15『まことの虫メガネ』 */
    H_bean,		/* 16『魔法のマメ』 */
    H_hammer,		/* 17『メガトンハンマー』 */
    H_arrow_3,		/* 18『光の矢』 */
    H_goddess_3,	/* 19『ネールの愛』 */
    H_bottle,		/* 20『空瓶』 */
    H_bottle_1,		/* 21『赤（ライフ）』 */
    H_bottle_2,		/* 22『緑（魔法）』 */
    H_bottle_3,		/* 23『青（ライフ＆魔法）』 */
    H_bottle_4,		/* 24『妖精の魂』 */
    H_bottle_5,		/* 25『魚』 */
    H_bottle_6,		/* 26『ロンロン牛乳』 */
    H_bottle_7,		/* 27『ルトの手紙』 */
    H_bottle_8,		/* 28『炎』 */
    H_bottle_9,		/* 29『ムシ』 */
    H_bottle_10,	/* 30『ビック・ポウ』 */
    H_bottle_11,	/* 31『ロンロン牛乳（半分）』 */
    H_bottle_12,	/* 32『ポウ』 */
    H_reserve_00,	/* 33わらしべ子供『ふしぎなタマゴ』 */
    H_reserve_01,	/* 34        子供『めざましトリ』 */
    H_reserve_02,	/* 35        子供『ゼルダの手紙』 */
    H_reserve_03,	/* 36        子供『キータンのお面』 */
    H_reserve_04,	/* 37        子供『ドクロのお面』 */
    H_reserve_05,	/* 38        子供『こわそうなお面』 */
    H_reserve_06,	/* 39        子供『ウサギずきん』 */
    H_reserve_07,	/* 40        子供『ゴロンのお面』 */
    H_reserve_08,	/* 41        子供『ゾ─ラのお面』 */
    H_reserve_09,	/* 42        子供『ゲルドのお面』 */
    H_reserve_10,	/* 43        子供『まことの仮面』 */
    H_reserve_11,	/* 44        子供『ＳＯＬＤ─ＯＵＴ』 */
    H_reserve_20,	/* 45わらしべ大人『ポケットタマゴ』 */
    H_reserve_21,	/* 46        大人『てのりコッコ』 */
    H_reserve_22,	/* 47        大人『コジロー』 */
    H_reserve_23,	/* 48        大人『あやしいキノコ』 */
    H_reserve_24,	/* 49        大人『あやしい薬』 */
    H_reserve_25,	/* 40        大人『密猟者のノコギリ』 */
    H_reserve_26,	/* 41        大人『折れたゴロン刀』 */
    H_reserve_27,	/* 52        大人『処方せん』 */
    H_reserve_28,	/* 53        大人『メダマガエル』 */
    H_reserve_29,	/* 54        大人『特製本生目薬』 */
    H_reserve_30,	/* 55        大人『ゴロン刀引換券』 */
    H_m_bow_1,		/* 56『炎の弓』 */
    H_m_bow_2,		/* 57『氷の弓』 */
    H_m_bow_3,		/* 58『光の弓』 */
    H_sword_0,		/* 59『ナイフ』 */
    H_sword_1,		/* 60『マスターソード』 */
    H_sword_2,		/* 61『巨人のナイフ』 */
    H_shield_1,		/* 62『デクの盾』 */
    H_shield_2,		/* 63『ハイリアの盾』 */
    H_shield_3,		/* 64『ミラーシールド』 */
    H_clothes_1,	/* 65『いつもの服』 */
    H_clothes_2,	/* 66『ゴロンの服』 */
    H_clothes_3,	/* 67『ゾ─ラの服』 */
    H_boots_1,		/* 68『いつものブーツ』 */
    H_boots_2,		/* 69『ヘビィブーツ』 */
    H_boots_3,		/* 70『ホバーブーツ』 */
    H_dekupouch_1,	/* 71『デグのタネ袋（３０）』 */
    H_dekupouch_2,	/* 72『デグのタネ袋（４０）』 */
    H_dekupouch_3,	/* 73『デグのタネ袋（５０）』 */
    H_arrowcase_1,	/* 74『小さな矢立て（３０）』 */
    H_arrowcase_2,	/* 75『大きな矢立て（４０）』 */
    H_arrowcase_3,	/* 76『もっと大きな矢立て（５０）』 */
    H_bombpouch_1,	/* 77『小さな袋（２０）』 */
    H_bombpouch_2,	/* 78『大きな袋（３０）』 */
    H_bombpouch_3,	/* 79『もっと大きな袋（４０）』 */
    H_bracelet,		/* 80『銅のブレスレット』 */
    H_gloves_1,		/* 81『銀のグローブ』 */
    H_gloves_2,		/* 82『金のグローブ』 */
    H_scale_1,		/* 83『銀のウロコ』 */
    H_scale_2,		/* 84『金のウロコ』 */
    H_sword_3,		/* 85『折れた巨人のナイフ』 */
    H_purse_2,		/* 86『大人のがま口』 */
    H_purse_3,		/* 87『大金持ちがま口』 */
    H_deku_seed,	/* 88『デクのタネ』 */
    H_rod,		/* 89『つりざお』 */
    H_melody_1,		/* 90『風のメヌエット』 */
    H_melody_2,		/* 91『炎のボレロ』 */
    H_melody_3,		/* 92『水のセレナーデ』 */
    H_melody_4,		/* 93『魂のレクイエム』 */
    H_melody_5,		/* 94『闇のノクターン』 */
    H_melody_6,		/* 95『光のプレリュード』 */
    H_melody_9,		/* 96『ゼルダの子守歌』 */
    H_melody_8,		/* 97『エポナの歌』 */
    H_melody_7,		/* 98『サリアの歌』 */
    H_melody_10,	/* 99『太陽の歌』 */
    H_melody_11,	/*100『時の歌』 */
    H_melody_12,	/*101『嵐の歌』 */
    H_seal_medal_1,	/*102『サリアの封印』 */
    H_seal_medal_2,	/*103『ダルニアの封印』 */
    H_seal_medal_3,	/*104『ルトの封印』 */
    H_seal_medal_4,	/*105『ナボールの封印』 */
    H_seal_medal_5,	/*106『インパの封印』 */
    H_seal_medal_6,	/*107『ラウルの封印』 */
    H_holystone_1,	/*108『コキリのヒスイ』 */
    H_holystone_2,	/*109『ゴロンのルビー』 */
    H_holystone_3,	/*110『ゾーラのサファイア』 */
    H_shake_stone,	/*111『もだえ石』 */
    H_gerudoC,		/*112『ゲルドの会員証』 */
    H_N_coin, 		/*113『Ｎコイン』 */
    H_heart,		/*114『ハートの器』 */
    H_heartpiece,	/*115『ハート欠片』 */
    H_boss_key,		/*116『ボス部屋鍵』 */
    H_compass,		/*117『コンパス』 */
    H_map,		/*118『マップ』 */
    H_key,		/*119『ダンジョンの鍵』*/
    H_magic_pot_0,	/*120『魔法の壷（小）』*/
    H_magic_pot_1,	/*121『魔法の壷（大）』*/
    H_heart_1,		/*122『ハートの欠片（１／４）』 */
    H_heart_2,		/*123『ハートの欠片（２／４）』 */
    H_heart_3,		/*124『ハートの欠片（３／４）』 */
    H_note_1,		/*125『音符：上』 */
    H_note_2,		/*126『音符：下』 */
    H_note_3,		/*127『音符：左』 */
    H_note_4,		/*128『音符：右』 */
    H_note_5,		/*129『音符：Ａ』 */
    H_lonron_milk,	/*130『ロンロン牛乳（中味）』 */
    H_life,		/*131『回復ハート』 */
    H_rupy00,		/*132『ルピー緑（１ルピー）』 */
    H_rupy01,		/*133『ルピー青（５ルピー）』 */
    H_rupy02,		/*134『ルピー赤（２０ルピー）』 */
    H_rupy03,		/*135『大ルピー（５０ルピー）』 */
    H_rupy04,		/*136『特大ルピー（２００ルピー）』 */
    H_rupy05,		/*137『銀のルピー（１０ルピー）』 */
    H0_stick,		/*138『デクの棒』５本 */
    H1_stick,		/*139『デクの棒』１０本 */
    H0_deku_nut,	/*140『デクの実』５個 */
    H1_deku_nut,	/*141『デクの実』１０個 */
    H0_bomb_1,		/*142『爆弾』５個 */
    H1_bomb_1,		/*143『爆弾』１０個 */
    H2_bomb_1,		/*144『爆弾』２０個 */
    H3_bomb_1,		/*145『爆弾』３０個 */
    H0_arrow,		/*146『矢』１０本 */
    H1_arrow,		/*147『矢』３０本 */
    H2_arrow,		/*148『矢』５０本 */
    H0_deku_seed,	/*149『デクのタネ』３０個 */
    H0_bomb_2,		/*150『ボムチュウ』５個 */
    H1_bomb_2,		/*151『ボムチュウ』２０個 */
    H0_stick_bag,	/*152『デクの棒』２０本袋 */
    H1_stick_bag,	/*153『デクの棒』３０本袋 */
    H0_deku_nut_bag,	/*154『デクの実』３０個袋 */
    H1_deku_nut_bag,	/*155『デクの実』４０個袋 */
    H_map00,		/* 『幻影の砂漠』 */
    H_map01,		/* 『ゲルドの砦』 */
    H_map02,		/* 『ゲルドの谷』 */
    H_map03,		/* 『ハイリア湖畔』 */
    H_map04,		/* 『ロンロン牧場』 */
    H_map05,		/* 『城下町』 */
    H_map06,		/* 『ハイラル平原』 */
    H_map07,		/* 『デスマウンテン』 */
    H_map08,		/* 『カカリコ村』 */
    H_map09,		/* 『迷いの森』 */
    H_map10,		/* 『コキリの森』 */
    H_map11,		/* 『ゾ─ラの里』 */
    H_place00,		/* 『ハイラル平原』 */
    H_place01,		/* 『カカリコ村』 */
    H_place02,		/* 『墓地』 */
    H_place03,		/* 『ゾ─ラ川』 */
    H_place04,		/* 『コキリの森』 */
    H_place05,		/* 『森の聖域』 */
    H_place06,		/* 『ハイリア湖畔』 */
    H_place07,		/* 『ゾ─ラの里』 */
    H_place08,		/* 『ゾ─ラの泉』 */
    H_place09,		/* 『ゲルドの谷』 */
    H_place10,		/* 『迷いの森』 */
    H_place11,		/* 『巨大邪神像』 */
    H_place12,		/* 『ゲルドの砦』 */
    H_place13,		/* 『幻影の砂漠』 */
    H_place14,		/* 『城下町』 */
    H_place15,		/* 『ハイラル城』 */
    H_place16,		/* 『デスマウンテン登山道』 */
    H_place17,		/* 『デスマウンテン火口』 */
    H_place18,		/* 『ゴロンシティ』 */
    H_place19,		/* 『ロンロン牧場』 */
    H_place20,		/* 『？』 */
    H_place21,		/* 『ガノン城』 */
    H_Botton_Select,	/* 『ボタンで選択』 */
    H_power_1,		/* 『炎のパワー』 */
    H_power_2,		/* 『氷のパワー』 */
    H_power_3,		/* 『光のパワー』 */
    H_Icon_Item_Point
};
#define	BEAN_COUNT H_hammer

/* アイテム切替 */
extern void
item_textuer_dma( Game_play *game_play, unshort item_no );
extern void
item_textuer_dma1( Game_play *game_play, unshort item_no );


# if 0
/* アイテム取得チェック */
extern unchar
item_get_check( unchar item_no );
# endif
/* アイテム取得セッティング */
extern unchar
item_get_setting( Game_play *game_play, unchar item_no );
/* アイテムセッティング */
extern unchar
item_get_non_setting( unchar item_no );
/* アイテム切替セッティング */
extern char
item_change_setting( Game_play *game_play, unshort item0, unshort item1 );
/* ＢＯＴＴＬＥ（中身）買えるかどうかのチェック処理 */
extern int
findEmptyBottle( void );
/* ＢＯＴＴＬＥ（中身）チェック */
extern int
bottle_interior_check( unchar item_no );
/* ＢＯＴＴＬＥ（中身）取得処理 */
extern void
bottle_getting( Game_play *game_play, unchar item_no, unchar c_no );
/* ＢＯＴＴＬＥ（妖精使用チェック）*/
extern char
bottle_fairy_use( Game_play *game_play );
/* データサイズ */
#define	I_IT_PT	(32*32*4)
#define	I_IT_P1	(24*24*4)
#define	I_IT_P2	((24*24)/2)

/* Ｅｑｕｉｐアイテム番号表 */
enum {
    E_Sword,
    E_Shield,
    E_Clothes,
    E_Boots,
    E_Point
};
enum {
    E_sword_0,		/* 『ナイフ』 */
    E_sword_1,		/* 『マスターソード』 */
    E_sword_2,		/* 『巨人のナイフ』 */
    E_sword_z,
    E_shield_1,		/* 『デクの盾』 */
    E_shield_2,		/* 『ハイリアの盾』 */
    E_shield_3,		/* 『ミラーシールド』 */
    E_shield_z,
    E_clothes_1,	/* 『いつもの服』 */
    E_clothes_2,	/* 『ゴロンの服』 */
    E_clothes_3,	/* 『ゾ─ラの服』 */
    E_clothes_z,
    E_boots_1,		/* 『いつものブーツ』 */
    E_boots_2,		/* 『ヘビィブーツ』 */
    E_boots_3,		/* 『ホバーブーツ』 */
    E_item
};
/* ＮｏｎーＥｑｕｉｐアイテム番号表 */
enum {
    NE_Bow,		/* 弓矢 */
    NE_Bomb,		/* 爆弾 */
    NE_Grove,
    NE_Scale,
    NE_Purse,		/* 財布 */
    NE_Pachinko,	/* パチンコ */
    NE_Stick,		/* デクの棒 */
    NE_Deck_Nut,	/* デクの実 */
    NE_Point
};


/*
 * ＤＯアクション
 */
/* ポイント セット */
extern void
do_action_point_set( Game_play *game_play, unshort action );
#define	DO_ACTION_POINT_SET( game_play, action ) do_action_point_set( game_play, action )
extern void
do_action_navi_set( Game_play *game_play, unshort action );
#define	DO_ACTION_NAVI( game_play, action ) do_action_navi_set( game_play, action )
extern void
sp_action_set( Game_play *game_play, unshort action );
#define	DO_ACTION_SPECIAL( game_play, action ) sp_action_set( game_play, action )
/* ポインタ */
enum {
    DO_Attack,		/* 『アタック』 */
    DO_Check,		/* 『チェック』 */
    DO_Hairu,		/* 『はいる』 */
    DO_Modoru,		/* 『もどる』 */
    DO_Hiraku,		/* 『ひらく』 */
    DO_Jump,		/* 『ジャンプ』 */
    DO_Kettei,		/* 『けってい』 */
    DO_Moguru,		/* 『もぐる』 */
    DO_Lash,		/* 『ムチ』 */
    DO_Nageru,		/* 『なげる』 */
    DO_Navi,		/* 『ナビィ』 */
    DO_Noru,		/* 『のる』 */
    DO_Oku,		/* 『おく』 */
    DO_Oriru,		/* 『おりる』 */
    DO_Save,		/* 『セーブ』 */
    DO_Syaberu,		/* 『しゃべる』 */
    DO_Tsugihe,		/* 『つぎへ』 */
    DO_Tukamu,		/* 『つかむ』 */
    DO_Yameru,		/* 『やめる』 */
    DO_Simau,		/* 『しまう』 */
    DO_Maku,		/* 『まく』 */
    DO_Moguru1,		/* 『１』 */
    DO_Moguru2,		/* 『２』 */
    DO_Moguru3,		/* 『３』 */
    DO_Moguru4,		/* 『４』 */
    DO_Moguru5,		/* 『５』 */
    DO_Moguru6,		/* 『６』 */
    DO_Moguru7,		/* 『７』 */
    DO_Moguru8,		/* 『８』 */
    DO_F_Navi,		/* 点滅『ナビィ』開始 */
    DO_P_Navi,		/* 点滅『ナビィ』開始（音付き）*/
    DO_E_Navi,		/* 点滅『ナビィ』終了 */
    DO_S_Yameru,	/* オカリナ『やめる』 */
    DO_S_Kettei,	/* カレイド『けってい』 */
    DO_S_Modoru,	/* カレイド『もどる』 */
    DO_Action_Point
};
/* データサイズ */
#define	G_B_PT	(48*16/2)






/*
 * 魔法メーター
 */
enum {
    Magic_Null,		/* 無し */
    Magic_Attack,	/* 攻撃 */
    Magic_Hit,		/* ＦＩＲＥ */
    Magic_Wait,		/* 終了待ち */
    Magic_Save,		/* 魔法充電 */
    Magic_End,		/* 終了 */
    Magic_Defence,	/* 補助 */
    Magic_Glass,	/* まことの虫眼鏡 */
    Magic_Start,	/* 魔法メーターＯＮ */
    Magic_Charge,	/* 蓄電 */
    Magic_Recovery,	/* ＭＰ回復 */
    Magic_Point
};
/* 魔法メーター充電処理 */
extern short
magic_meter_check( Game_play *game_play, short count, short magic_type );
extern void
/* 魔法メーター状態チェック */
magic_mode_check( Game_play *game_play );

#define MAGIC_CHARGE( game_play, mp, magic_type ) magic_meter_check( game_play, mp, magic_type )
/* 魔法発動 */
#define MAGIC_FIRE( game_play )		(ZCommonSet( magic_flag, Magic_Hit))
/* 魔法キャンセル */
extern void
magic_cancel_check( Game_play *game_play );
#define MAGIC_CANCEL( game_play ) 	magic_cancel_check( game_play )
/* 魔法ドリンク */
#define MAGIC_DRINK( game_play ) 	magic_mode_check( game_play )
/* 魔法メーター表示位置データ */
#define MAGIC_VALUE	48	/* 魔法メーター ３（消費量）表示位置Ｙ */
#define MAGIC_YPD	 3	/* 魔法メーター ３（消費量）表示位置Ｙ */
#define MAGIC_YSZ	10	/* 魔法メーター ３（消費量）表示Ｙサイズ */
/* 魔法種類 */
#define MAGIC_ATTACK	0	/* 攻撃魔法 */
#define MAGIC_DEFENCE	1	/* 補助魔法 */
#define MAGIC_ARROW	2	/* 魔法の弓矢 */
#define MAGIC_GLASS	3	/* まことの虫メガネ */
#define MAGIC_SAVE	4	/* 魔法充電 */
#define MAGIC_RECOVERY	5	/* ＭＰ回復 */

/* 体力全回復 */
#define LIFE_DRINK( game_play ) 	(ZCommonSet( life_mode, LIFE_CT*20))
/* 体力（ハート５個分）回復 */
#define MILK_DRINK( game_play ) 	(ZCommonSet( life_mode, LIFE_CT*5))




/* ライフメーター 増減処理 */
extern char
life_meter_play( Game_play *game_play, short count );

/* ライフメーター ＭＡＸ値増減処理 */
extern void
life_meter_max( short count );

/* ルピー数 増減処理 */
extern void
lupy_increase( short count );


/* 各アイテム数増減 (デクの棒,爆弾,デクの実,地雷,妖精の弓矢) */
extern void
item_count_vary( short kind, short count );
#define	ITEM_COUNT_VARY( kind, count )	item_count_vary( kind, count )

#define deku_stick_count( count )	item_count_vary( H_stick, count)



/*
 * Ｃボタン
 */
#define BUTTON_SIZE	32
#define AB_BUTTON_SIZE	28
#define C_BUTTON_SIZE	24
#define ITEM_SIZE	32
#define A_ITEM_SIZE	26
#define C_ITEM_SIZE	22



/*
 * アルファ値セッテング
 */
#define ALPHA		32
extern void
alpha_change( unshort type );







/*
 * イベントタイマー ポインタ
 */
enum {
    Event_MD0,		/* 無し */
    Event_MD1,		/* 水中・炎 スタート */
    Event_MD2,		/* ＷａｉＴ */
    Event_MD3,		/* 移動 */
    Event_MD4,		/* イベントタイマー */
    Event_MD5,		/* 固定タイマー */
    Event_MD6,		/* 固定タイマーＷａｉＴ */
    Event_MD7,		/* 固定タイマー移動 */
    Event_MD20,		/* 固定イベントタイマー */
    Event_Wait,		/* 終了待ち */
    Event_End,		/* 終了 */
    Event_MD30,		/* 固定イベントタイマー */
    Event_MD31,		/* 固定イベントタイマー */
    Event_MD32,		/* 固定イベントタイマー */
    Event_MD33,		/* 固定イベントタイマー */
    Event_MD34,		/* 固定イベントタイマー */
    Event_Point
};
extern void
event_timer_set( short event_time );
/*
 * ＴＯＴＡＬイベントタイマー ポインタ
 */
enum {
    TEvent_MD0,		/* 無し */
    TEvent_MD1,		/* 減算スタート */
    TEvent_MD2,		/* ＷａｉＴ */
    TEvent_MD3,		/* 移動 */
    TEvent_MD4,		/* イベントタイマー */
    TEvent_MD5,		/* イベントタイマー */
    TEvent_Wait,	/* 終了待ち */
    TEvent_MD11,	/* 加算スタート */
    TEvent_MD12,	/* ＷａｉＴ */
    TEvent_MD13,	/* 移動 */
    TEvent_MD14,	/* イベントタイマー */
    TEvent_MD15,	/* イベントタイマー */
    TEvent_Point
};
extern void
total_event_timer_set( short event_time );


/*
 * 流鏑馬
 */
enum {
    Yabu_NULL,		/* 無し */
    Yabu_START,		/* スタート */
    Yabu_WAIT,		/* 終了待ち */
    Yabu_END,		/* 終了 */
    Yabu_Point
};
extern void
yabusame_game_start( Game_play *game_play );
#define YABU_START( game_play )		yabusame_game_start( game_play )
#define	YABU_SCORE( game_play, score )	(game_play)->parameter.yabusame_score = score

#define YABU_ARROW( game_play, count )	((game_play)->parameter.yabusame_arrow += count)
#define YABU_ARROW_CT( game_play )	(game_play)->parameter.yabusame_arrow



/* 子供／大人 装備デフォルト設定処理 */
extern void
equip_default_set( void );



/* わらしべチェックデータ */
extern short 	Warashibe_item[];
extern short 	Warashibe_before_item[];


/* ボタン表示関係データ設定 */
extern void
button_status_set( Game_play *game_play );
/* ＴＯＴＡＬ─ＥｖｅｎｔＴｉｍｅｒ強制終了 */
extern void
total_event_timer_end( Game_play *game_play );



#define	LIFE_MODE		ZCommonGet( life_mode )
#define	Set_LIFE_MODE( point )	(ZCommonSet( life_mode, point ))
#define	MAGIC_FLAG		ZCommonGet( magic_flag )
#define	Set_MAGIC_FLAG( point )	(ZCommonSet( magic_flag, point ))

#define FULL_ALPHA		255 	/* Ａ・Ｃボタン不透明アルファ値 */
#define CLEAR_ALPHA		70 	/* Ａ・Ｃボタン半透明アルファ値 */



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_parameter_h.h end ***/
