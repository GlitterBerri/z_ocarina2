/* $Id: z_player_item.h,v 1.1.1.1 2003/03/10 22:42:51 tong Exp $ */	
/* $Log: z_player_item.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:51  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.37  1998/10/12 16:11:52  iwawaki
 * *** empty log message ***
 *
 * Revision 1.36  1998-09-14 15:54:47+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.35  1998-09-03 23:59:38+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.34  1998-09-01 00:31:33+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.33  1998-08-29 22:22:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.32  1998-08-26 00:19:49+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.31  1998-08-22 23:11:07+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.30  1998-08-06 12:50:51+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.29  1998-08-04 13:54:47+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.28  1998-07-31 18:39:55+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.27  1998-07-24 13:54:44+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.26  1998-07-20 22:41:47+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1998-07-15 22:58:37+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.24  1998-07-10 23:08:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.23  1998-06-29 22:28:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1998-06-25 14:13:13+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.21  1998-06-25 14:12:10+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.20  1998-06-24 22:57:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.19  1998-06-19 22:41:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1998-06-16 16:03:56+09  soejima
 * わらしべ変更
 *
 * Revision 1.17  1998-06-15 19:27:17+09  nisiwaki
 * GET_ITEM_RONMILK 追加
 *
 * Revision 1.16  1998-06-10 22:59:00+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.15  1998-06-02 22:56:10+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1998-05-15 11:06:00+09  nisiwaki
 * PUT_ITEM 系列追加
 *
 * Revision 1.13  1998/05/14 11:35:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1998/04/30 10:23:25  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1998/04/28 14:21:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1998/04/09 08:24:32  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.9  1998/03/25  11:48:15  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.8  1998/03/18  02:25:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1998/02/17  13:06:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1998/02/17  05:40:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1998/01/30  13:21:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1997/11/17  12:44:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1997/11/10  17:17:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1997/11/01  14:58:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.1  1997/11/01  06:00:07  iwawaki
 * Initial revision
 *
 *
 * Revision 1.1  1997/06/19  05:21:53  iwawaki
 * Initial revision
 * */


#ifndef INCLUDE_Z_PLAYER_ITEM_H
#define INCLUDE_Z_PLAYER_ITEM_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	アイテムタイプ（＜０宝箱から）	Ｂｙ山田さん
 *
 ************************************************************************/
enum {
    GET_ITEM_NON,
    GET_ITEM_BOM_5,		/*   1:爆弾（５個） */
    GET_ITEM_NUTS,		/*   2:デクの実（１個） */
    GET_ITEM_BOM_RAT,		/*   3:ボムチュウ（１０個） */
    GET_ITEM_ELF_BOW,		/*   4:妖精の弓 */
    GET_ITEM_PACHINKO,		/*   5:妖精のパチンコ */
    GET_ITEM_BOOMERAN,		/*   6:ブーメラン */
    GET_ITEM_STICK,		/*   7:デクの棒（１本） */
    GET_ITEM_FUCK_S,		/*   8:フックショット */
    GET_ITEM_FUCK_L,		/*   8:ロングフック */
    GET_ITEM_MUSIMEGANE, 	/*  10:まことの虫眼鏡 */
    GET_ITEM_MAIL_Z,		/*  11:ゼルダの手紙 */
    GET_ITEM_OKARINA,		/*  12:時のオカリナ */
    GET_ITEM_HAMMER,		/*  13:メガトンハンマー */
    GET_ITEM_KOJIRO,		/*  14:わらしべ (コジロー) */
    GET_ITEM_BIN_NUL,		/*  15:瓶 (空) */
    GET_ITEM_BIN_RED,		/*  16:瓶 (赤) */
    GET_ITEM_BIN_GREEN,		/*  17:瓶 (緑) */
    GET_ITEM_BIN_BLUE,		/*  18:瓶 (青) */
    GET_ITEM_BIN_ELF,		/*  19:瓶 (妖精の魂) */
    GET_ITEM_BIN_RONMILK,	/*  20:瓶 ロンロン牛乳 */
    GET_ITEM_BIN_MAIL,		/*  21:瓶 (手紙) */
    GET_ITEM_MAGIC_BEAN,	/*  22:魔法の豆 */
    GET_ITEM_MASK_SKJ,		/*  23:わらしべ (ドクロのお面) */
    GET_ITEM_MASK_RE_DEAD,	/*  24:わらしべ (こわそなお面) */
    GET_ITEM_NIWATORI,		/*  25:わらしべ (めざましドリ) */
    GET_ITEM_MASK_KI_TAN,	/*  26:わらしべ (キータンのお面) */
    GET_ITEM_MASK_RABIT,	/*  27:わらしべ (ウサギずきん) */
    GET_ITEM_MASK_TRUTH,	/*  28:わらしべ (まことの仮面) */
    GET_ITEM_POCKET_EGG,	/*  29:わらしべ (ポケットタマゴ) */
    GET_ITEM_HANDY_COCK,	/*  30:わらしべ (てのりコッコ) */
    GET_ITEM_AYASHII_KINOKO,	/*  31:わらしべ (あやしいキノコ) */
    GET_ITEM_AYASHII_DRUG,	/*  32:わらしべ (あやしい薬) */
    GET_ITEM_NOKOGIRI,		/*  33:わらしべ (密猟者のノコギリ) */
    GET_ITEM_BREAKE_GORON_SWORD,/*  34:わらしべ (折れたゴロン刀) */
    GET_ITEM_SPECIAL_DRUG,	/*  35:わらしべ (処方せん) */
    GET_ITEM_MEDAMA_FROG,	/*  36:わらしべ (メダマガエル) */
    GET_ITEM_EYES_DRUG,		/*  37:わらしべ (特製本生目薬) */
    GET_ITEM_GORON_SWORD_CARD,	/*  38:わらしべ (ゴロン刀引換券) */
    GET_ITEM_KNIFE,		/*  39:ナイフ */
    GET_ITEM_G_KNIFE,		/*  40:巨人のナイフ */
    GET_ITEM_WOOD_SHIELD,	/*  41:デクの盾 */
    GET_ITEM_HIRARU_SHILD,	/*  42:ハイラルの盾 */
    GET_ITEM_MIRROR_SHILD,	/*  43:ミラーシールド */
    GET_ITEM_GORON_FUKU,	/*  44:ゴロンの服 */
    GET_ITEM_ZORA_FUKU,		/*  45:ゾーラの服 */
    GET_ITEM_HEAVY_BOOT,	/*  46:ヘビーブーツ */
    GET_ITEM_HOVA_BOOT,		/*  47:ホバーブーツ */
    GET_ITEM_BIG_ARROW_CASE,	/*  48:大きな矢立て */
    GET_ITEM_HUG_ARROW_CASE,	/*  49:もっと大きな矢立て */
    GET_ITEM_BOM_BAG,		/*  50:爆弾袋*/
    GET_ITEM_BIG_BOM_BAG,	/*  51:大きな袋 */
    GET_ITEM_HUG_BOM_BAG,	/*  52:もっと大きな袋 */
    GET_ITEM_SILVER_GLOVE,	/*  53:銀のグローブ */
    GET_ITEM_GOLD_GLOVE,	/*  54:金のグローブ */
    GET_ITEM_SILVER_SCALE,	/*  55:銀の鱗 */
    GET_ITEM_GOLD_SCALE,	/*  56:金の鱗 */
    GET_ITEM_MODAE_STONE,	/*  57:もだえ石 */
    GET_ITEM_GUILD_CAARD,	/*  58:ギルド会員証 */
    GET_ITEM_OKARINA2,		/*  59:妖精のオカリナ*/
    GET_ITEM_SEED,		/*  60:デクのタネ */
    GET_ITEM_HEART_BOTTLE,	/*  61:ハートの器 */
    GET_ITEM_HEART_PARTS,	/*  62:ハートの欠片 */
    GET_ITEM_BOSS_KEY,		/*  63:ボス部屋のカギ */
    GET_ITEM_COMPASS,		/*  64:コンパス  */
    GET_ITEM_MAP,		/*  65:ダンジョンマップ */
    GET_ITEM_KEY,		/*  66:小さなカギ */
    GET_ITEM_S_MAGIC_POT,	/*  67:魔法の壺(小) */
    GET_ITEM_B_MAGIC_POT,	/*  68:魔法の壺(大) */
    GET_ITEM_BIG_PURSE,		/*  69:大人の財布 */
    GET_ITEM_GIANT_PURSE,	/*  70:巨人の財布 */
    GET_ITEM_COOK_EGG,		/*  71:わらしべ（鶏の卵） */
    GET_ITEM_HEAL_HEART,	/*  72:回復のハート */
    GET_ITEM_ARROW_0,		/*  73:矢（１０本） */
    GET_ITEM_ARROW_1,		/*  74:矢（３０本） */
    GET_ITEM_ARROW_2,		/*  75:矢（５０本） */
    GET_ITEM_20RUPPE,		/*  76:ルピー緑 */
    GET_ITEM_RUPPE_BLUE,	/*  77:ルピー青 */
    GET_ITEM_RUPPE_RED,		/*  78:ルピー赤 */
    GET_ITEM_BOSS_HEART,	/*  79:ボス倒して貰えるハートの器 */
    GET_ITEM_RONMILK,		/*  80:ロンロン牛乳 */
    GET_ITEM_MASK_GOLON,	/*  81:ゴロンのお面 */
    GET_ITEM_MASK_ZOLA,		/*  82:ゾ─ラのお面 */
    GET_ITEM_MASK_GELD,		/*  83:ゲルドのお面 */
    GET_ITEM_BRACELET,		/*  84:ゴロンのうでわ */
    GET_ITEM_BIG_RUPPE,		/*  85:大ルピー */
    GET_ITEM_GIANT_RUPPE,	/*  86:特大ルピー */
    GET_ITEM_GOLON_SWORD,	/*  87:ダイゴロン刀 */
    GET_ITEM_FIREMAGICARROW,	/*  88:炎の矢 */
    GET_ITEM_ICEMAGICARROW,	/*  89:氷の矢 */
    GET_ITEM_SHINEMAGICARROW,	/*  90:光の矢 */
    GET_ITEM_SUTARU,		/*  91:黄金の魂 */
    GET_ITEM_FIRE_GODDESS,	/*  92:ディンの炎 */
    GET_ITEM_WIND_GODDESS,	/*  93:フロルの風 */
    GET_ITEM_LOVE_GODDESS,	/*  94:ネールの愛 */
    GET_ITEM_DEKU_POUCH_S,	/*  95:デクのタネ袋（２０） */
    GET_ITEM_DEKU_POUCH_M,	/*  96:デクのタネ袋（３０） */
    GET_ITEM_STICK_5,		/*  97:デクの棒（５本） */
    GET_ITEM_STICK_10,		/*  98:デクの棒（１０本） */
    GET_ITEM_NUTS_5,		/*  99:デクの実（５個） */
    GET_ITEM_NUTS_10,		/* 100:デクの実（１０個） */
    GET_ITEM_BOM,		/* 101:爆弾（１個） */
    GET_ITEM_BOM_10,		/* 102:爆弾（１０個） */
    GET_ITEM_BOM_20,		/* 103:爆弾（２０個） */
    GET_ITEM_BOM_30,		/* 104:爆弾（３０個） */
    GET_ITEM_SEED_30,		/* 105:デクのタネ（３０個） */
    GET_ITEM_BOM_RAT_5,		/* 106:ボムチュウ（５個） */
    GET_ITEM_BOM_RAT_20,	/* 107:ボムチュウ（２０個） */
    GET_ITEM_FISH,		/* 108:魚 */
    GET_ITEM_INSECT,		/* 109:虫 */
    GET_ITEM_FIRE,		/* 110:炎 */
    GET_ITEM_GHOST,		/* 111:ポウ */
    GET_ITEM_GHOSTBIG,		/* 112:ビッグポウ */
    GET_ITEM_BOX_KEY,		/* 113:小さなカギ（宝箱屋） */
    GET_ITEM_BOX_RUPPE_GREEN,	/* 114:ルピー緑 */
    GET_ITEM_BOX_RUPPE_BLUE,	/* 115:ルピー青 */
    GET_ITEM_BOX_RUPPE_RED,	/* 116:ルピー赤 */
    GET_ITEM_BOX_BIG_RUPPE,	/* 117:大ルピー */
    GET_ITEM_BOX_HEART_PARTS,	/* 118:ハートの欠片 */
    GET_ITEM_STICK_MAX_20,	/* 119:デクの棒を２０本へ */
    GET_ITEM_STICK_MAX_30,	/* 120:デクの棒を３０本へ */
    GET_ITEM_NUTS_MAX_30,	/* 121:デクの実を３０個へ */
    GET_ITEM_NUTS_MAX_40,	/* 122:デクの実を４０個へ */
    GET_ITEM_DEKU_POUCH_L,	/* 123:デクのタネ袋（４０） */
    GET_ITEM_ICE_SMOKE,		/* 124:氷のけむり */
    GET_ITEM_35,		/* 125:３。。５。。 */
    
    /* 最後 */
    GET_ITEM_CATCH		/* 113:捕まえるもの */
};

/************************************************************************
 *
 *	差し出しアイテムタイプ
 *
 ************************************************************************/
enum {
    PUT_ITEM_NON,
    PUT_ITEM_LETTER,		/* わらしべ（ゼルダの手紙） */
    PUT_ITEM_COOK_EGG,		/* わらしべ（めざましタマゴ） */
    PUT_ITEM_NIWATORI,		/* わらしべ (めざましドリ) */
    PUT_ITEM_BEAN,		/* 魔法の豆 */
    PUT_ITEM_POCKET_EGG,	/* わらしべ (ポケットタマゴ) */
    PUT_ITEM_HANDY_COCK,	/* わらしべ (てのりコッコ) */
    PUT_ITEM_KOJIRO,		/* わらしべ (小次郎) */
    PUT_ITEM_AYASHII_KINOKO,	/* わらしべ (あやしいキノコ) */
    PUT_ITEM_AYASHII_DRUG,	/* わらしべ (あやしい薬) */
    PUT_ITEM_NOKOGIRI,		/* わらしべ (密猟者のノコギリ) */
    PUT_ITEM_BREAKE_GORON_SWORD,/* わらしべ (折れたゴロン刀) */
    PUT_ITEM_SPECIAL_DRUG,	/* わらしべ (処方せん) */
    PUT_ITEM_MEDAMA_FROG,	/* わらしべ (メダマガエル) */
    PUT_ITEM_EYES_DRUG,		/* わらしべ (特製本生目薬) */
    PUT_ITEM_GORON_SWORD_CARD,	/* わらしべ (ゴロン刀引換券) */
    PUT_ITEM_MASK_SKJ,		/* わらしべ (ドクロのお面) */
    PUT_ITEM_MASK_RE_DEAD,	/* わらしべ (こわそなお面) */
    PUT_ITEM_MASK_KI_TAN,	/* わらしべ (キータンのお面) */
    PUT_ITEM_MASK_RABIT,	/* わらしべ (ウサギずきん) */
    PUT_ITEM_MASK_TRUTH,	/* わらしべ (まことの仮面) */
    PUT_ITEM_MASK_GOLON,	/* わらしべ (ゴロンのお面) */
    PUT_ITEM_MASK_ZOLA,		/* わらしべ (ゾ─ラのお面) */
    PUT_ITEM_MASK_GELD,		/* わらしべ (ゲルドのお面) */
    PUT_ITEM_BIN_FISH,		/* 魚 */
    PUT_ITEM_BIN_FIRE,		/* 炎 */
    PUT_ITEM_BIN_BUG,		/* 虫 */
    PUT_ITEM_BIN_POH,		/* ポウ */
    PUT_ITEM_BIN_BIGPOH,	/* ビッグポウ */
    PUT_ITEM_BIN_MAIL,		/* ルトの手紙 */
    PUT_ITEM_MAX
};
    

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_player_item.h end ***/
