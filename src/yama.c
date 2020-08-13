/* $Id: yama.c,v 2.2 1998-11-06 11:51:45+09 soejima Exp $
 *
 * 表示オブジェクトリスト
 *
 * $Log: yama.c,v $
 * Revision 2.2  1998-11-06 11:51:45+09  soejima
 * コメント
 *
 * $Log追加
 * */


unsigned char button_data[][4] = {
#define		print_object(a, b, c, d, e, f, i, g, h, j, k, l) \
    a << 6 | b << 4 | c << 2 | d, e << 6 | f << 4 | g << 2 | h, i << 6 | j << 4 | k << 2 | l
    /*
     *		● : 0 = 表示 (使える)
     *		◯ : 1 = 半透明表示 (使えない)
     *		× : 2 = 非表示 (使えない)
     *		▲ : 3 = 使えるが、ワープメロディを受け付けない
     *
     *			             ハ Ｂ Ａ 瓶 わ フ オ オ オ 魔 魔 そ
     *			             ｜ ボ ボ    ら ッ カ カ カ 法 法 の
     *			             ト タ タ    し ク リ リ リ 風 炎 他
     *			             ・ ン ン    べ シ ナ ナ ナ    ・
     *			             魔             ョ 太 イ ワ    愛
     *			             法             ッ 陽 ベ ｜ 
     *			             ゲ             ト の ン プ 
     *			             ｜             ・ 歌 ト    
     *			             ジ             ロ
     *			             ・             ン
     *			             ル             グ
     *			             ピ             フ
     *			             ｜             ッ
     *			                            ク
     */
    SPOT00,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 01 */
    SPOT01,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 02 */
    SPOT02,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 03 */
    SPOT03,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 04 */
    SPOT04,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 05 */
    SPOT05,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 06 */
    SPOT06,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 07 */
    SPOT07,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 08 */
    SPOT08,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 09 */
    SPOT09,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 10 */
    SPOT10,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 11 */
    SPOT11,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 12 */
    SPOT12,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 13 */
    SPOT13,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 14 */
    SPOT15,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 15 */
    GANONTOU,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 15 */
    SPOT16,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 16 */
    SPOT17,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 17 */
    SPOT18,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 18 */
    SPOT20,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 19 */
    TOKINOMA,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 20 */
    KENJYANOMA,		print_object(2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2),	/* 21 */
    SYATEKI,		print_object(0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1),	/* 22 */
    HAIRARUNIWA,	print_object(0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1),	/* 23 */
    HAIRARUNIWA_N,	print_object(0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1),	/* 23 */
    HAKAANA,		print_object(0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0),	/* 24 */
    HAKAANA2,		print_object(0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0),	/* 25 */
    HAKAANA_OUKE,	print_object(0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0),	/* 26 */
    DAIYOUSEI_IZUMI,	print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 27 */
    YIZUMI_TATE,	print_object(0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0),	/* 28 */
    YIZUMI_YOKO,	print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 29 */
    GANON_FINAL,	print_object(0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0),	/* 30 */
    NAKANIWA,		print_object(0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0),	/* 31 */
    TURIBORI,		print_object(0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1),	/* 32 */
    BOWLING,		print_object(0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1),	/* 33 */
    SOUKO,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 34,35 */
    MIHARIGOYA,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0),	/* 36 */
    MAHOUYA,		print_object(0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1),	/* 37 */
    TAKARAYA,		print_object(0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1),	/* 38 */
    KINSUTA,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 39 */
    ENTRA,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 40 */
    ENTRA_NIGHT,	print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/*    */
    ENTRA_RUINS,	print_object(0, 0, 0, 0, 0, 1, 3, 0, 0, 1, 1, 1),	/*    */
    MARKET_DAY,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 41 */
    MARKET_NIGHT,	print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/*    */
    MARKET_RUINS,	print_object(0, 0, 0, 0, 0, 1, 3, 0, 0, 1, 1, 1),	/*    */
    MARKET_ALLEY,	print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 42 */
    MARKET_ALLEY_N,	print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/*    */
    SHRINE,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 43 */
    SHRINE_N,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/*    */
    SHRINE_R,		print_object(0, 0, 0, 0, 0, 1, 3, 0, 0, 1, 1, 1),	/*    */
    LINK_HOME,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 44 */
    KAKARIKO,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 45 */
    KAKARIKO_HOME3,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 46 */
    KOKIRI_HOME,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 47 */
    KOKIRI_HOME3,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 48 */
    KOKIRI_HOME4,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 49 */
    KOKIRI_HOME5,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 50 */
    LONRON,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 51 */
    HAKAMORI_HOUSE,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 52 */
    IMPA_HOME,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 53 */
    LABO,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 54 */
    HYLIA_LABO,		print_object(0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 55 */
    TENTO,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 56 */
    SHIELD_SHOP,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 57 */
    KOKIRI_SHOP,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 58 */
    GORON_SHOP_N,	print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 59 */
    ZOORA_SHOP,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 60 */
    DRAG_SHOP,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 61 */
    ALLEY_SHOP,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 62 */
    NIGHT_SHOP,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 63 */
    FACE_SHOP,		print_object(0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1),	/* 64 */
    MEN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0),	/* 65 */
    /*
     *		● : 0 = 表示 (使える)
     *		◯ : 1 = 半透明表示 (使えない)
     *		× : 2 = 非表示 (使えない)
     *		▲ : 3 = 使えるが、ワープメロディを受け付けない
     *
     *			             ハ Ｂ Ａ 瓶 わ フ オ オ オ 魔 魔 そ
     *			             ｜ ボ ボ    ら ッ カ カ カ 法 法 の
     *			             ト タ タ    し ク リ リ リ 風 炎 他
     *			             ・ ン ン    べ シ ナ ナ ナ    ・
     *			             魔             ョ 太 イ ワ    愛
     *			             法             ッ 陽 ベ ｜ 
     *			             ゲ             ト の ン プ 
     *			             ｜             ・ 歌 ト    
     *			             ジ             ロ
     *			             ・             ン
     *			             ル             グ
     *			             ピ             フ
     *			             ｜             ッ
     *			                            ク
     */
    YDAN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 66 */
    YDAN_BOSS,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 67 */
    DDAN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 68 */
    DDAN_BOSS,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 69 */
    BDAN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 70 */
    BDAN_BOSS,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 71 */
    MORI1,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 72 */
    MORIBOSS,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 73 */
    HAKADAN_CH,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 74 */
    HAKADAN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 75 */
    HAKADAN_BOSS,	print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 76 */
    HIDAN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 77 */
    FIRE_BOSS,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 78 */
    MIZUSIN,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 79 */
    MIZUSIN_BOSS,	print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 80 */
    JYASINZOU,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 81 */
    JYASINZOU_BOSS,	print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 83 */
    GANON,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 84 */
    GANON_BOSS,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 85 */
    ICE_DOUKUTU,	print_object(0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0),	/* 86 */
    HAKASITARELAY,	print_object(0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 0),	/* 87 */
    GANONTIKA,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0),	/* 88 */
    GANON_DEMO,		print_object(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0),	/* 89 */
    GANON_SONOGO,	print_object(0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0),	/* 90 */
    GANONTIKA_SONOGO,	print_object(0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0),	/* 94 */
    GERUDOWAY,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0),	/* 95 */
    KAKUSIANA,		print_object(0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 0, 0),	/*101 */
    0xff,		print_object(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),	/* 最後 */
    /*
     *		● : 0 = 表示 (使える)
     *		◯ : 1 = 半透明表示 (使えない)
     *		× : 2 = 非表示 (使えない)
     *		▲ : 3 = 使えるが、ワープメロディを受け付けない
     *
     *			             ハ Ｂ Ａ 瓶 わ フ オ オ オ 魔 魔 そ
     *			             ｜ ボ ボ    ら ッ カ カ カ 法 法 の
     *			             ト タ タ    し ク リ リ リ 風 炎 他
     *			             ・ ン ン    べ シ ナ ナ ナ    ・
     *			             魔             ョ 太 イ ワ    愛
     *			             法             ッ 陽 ベ ｜ 
     *			             ゲ             ト の ン プ 
     *			             ｜             ・ 歌 ト    
     *			             ジ             ロ
     *			             ・             ン
     *			             ル             グ
     *			             ピ             フ
     *			             ｜             ッ
     *			                            ク
     */
};
