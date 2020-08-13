/*
 * $Id: n64dd_rom.spec,v 1.1 2003/03/10 22:42:55 tong Exp $ 
 *
 * ６４ＤＤ用スペックファイルその１（ＲＯＭイメージ）
 *
 * $Log: n64dd_rom.spec,v $
 * Revision 1.1  2003/03/10 22:42:55  tong
 * Initial revision
 *
 * Revision 2.16  2000-06-19 11:39:08+09  zelda
 * *** empty log message ***
 *
 * Revision 2.15  2000-06-19 11:11:43+09  zelda
 * 闇の神殿、井戸下、ゲルド修練場追加
 *
 * Revision 2.14  2000-06-19 10:15:09+09  hayakawa
 * パッチ当て版
 *
 * Revision 2.13  2000-06-08 16:55:31+09  zelda
 * *** empty log message ***
 *
 * Revision 2.12  2000-06-05 14:58:06+09  zelda
 * 炎の神殿、水の神殿ＤＤ版マップ追加
 *
 * Revision 2.11  2000-05-31 14:40:27+09  zelda
 * 「|| 1」を追加してマップ表示をＲＯＭと同一にする
 *
 * Revision 2.10  2000-05-30 09:32:29+09  zelda
 * 氷の洞窟
 *
 * Revision 2.9  2000-05-29 18:23:56+09  zelda
 * *** empty log message ***
 *
 * Revision 2.8  2000-05-29 18:08:34+09  zelda
 * ドドンゴ、森の神殿 ＤＤ版マップ追加
 *
 * Revision 2.7  2000-05-29 17:57:49+09  zelda
 * *** empty log message ***
 *
 * Revision 2.6  2000-05-22 16:07:46+09  zelda
 * *** empty log message ***
 *
 * Revision 2.5  2000-05-22 16:04:26+09  zelda
 * *** empty log message ***
 *
 * Revision 2.4  2000-05-22 15:42:35+09  zelda
 * Z2_DD_IKE、Z2_ReDeadを追加
 *
 * Revision 2.3  1999-01-07 13:15:46+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  1998-10-28 19:21:37+09  hayakawa
 * ＤＤ用メッセージ取込み
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.10  1998/10/13 00:41:08  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1998-10-10 17:15:33+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.8  1998-10-07 18:46:51+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.7  1998-10-03 23:01:05+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-10-02 21:11:37+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.5  1998-09-26 22:50:35+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-09-25 23:12:48+09  hayakawa
 * DISK変更
 *
 * Revision 1.3  1998-09-25 16:32:22+09  soejima
 * *** empty log message ***
 *
 * Revision 1.2  1998-09-25 16:26:33+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1998-09-22 22:00:28+09  hayakawa
 * Initial revision
 *
 * Revision 1.2  1998-08-31 11:31:14+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1998-07-07 19:53:01+09  hayakawa
 * Initial revision
 *
 */
#include "sys_segment.h" /* DISK_BOOT_STACK_SIZE, *_SEGMENT DISKSEGMENT_START */

#define DefSegX(segname, segnumber, seginclude) \
beginseg 			\
	name    segname 	\
	flags   OBJECT 		\
	number  segnumber	\
	include seginclude 	\
endseg

/*
 * boot セグメント定義
 */
beginseg
	name "disk_boot"
	flags BOOT OBJECT
	entry disk_boot
	stack disk_bootStack + DISK_BOOT_STACK_SIZE
	address 0x80000400 /* これ以上低位には置けない */
	include "disk_boot.o"
endseg

/*
 *  ディスク情報セグメント定義
 */
beginseg
	name "disk_info"
	number 1
	flags OBJECT
	include "disk_info.o"
endseg

/*
 *  ディスク情報セグメント定義
 */
beginseg
	name "disksegment"
	address DISKSEGMENT_START
	flags OBJECT
	include "disksegment.o"
	include "$(ZELDA_DATA)/gi_gerudomask.o"
#if defined(DISK_ROM_DATA)
	include "$(ZELDA_DATA)/message.o"
	include "$(ZELDA_DATA)/nes_c.o"
	include "$(ZELDA_DATA)/staff_c.o"
#else
	include "$(ZELDA_DATA)/dd_message.o"
	include "$(ZELDA_DATA)/dd_nes_c.o"
	include "$(ZELDA_DATA)/dd_staff_c.o"
#endif
	/* バージョン情報 */
	include "version.o"
endseg

/*
 * ＭＡＰテクスチャ
 */
#if defined(DISK_ROM_DATA)  || 1 /* 「|| 1」を追加してマップ表示をＲＯＭと同一にする */
DefSegX("disk_map_48x85_static", MAP_SEGMENT, "$(ZELDA_DATA)/map_48x85.o")
DefSegX("disk_map_i_static", MAP_SEGMENT, "$(ZELDA_DATA)/map_i.o")
#else
DefSegX("disk_map_48x85_static", MAP_SEGMENT, "$(ZELDA_DATA)/dd_map_48x85.o")
DefSegX("disk_map_i_static", MAP_SEGMENT, "$(ZELDA_DATA)/dd_map_i.o")
#endif

/*
 * ダミーセグメント
 */
DefSegX("gameplay_object_exchange_static", GAMEPLAY_OBJECT_EXCHANGE_SEGMENT, "$(ZELDA_ROOT)/data/shape/gameplay_object_exchange/gameplay_object_exchange.o")
DefSegX("bump_texture_static", BUMP_TEXTURE_SEGMENT, "$(ZELDA_DATA)/shape/bump_texture/bump_texture.o")
DefSegX("anime_model_1_static", ANIME_MODEL_1_SEGMENT, 	"$(ZELDA_DATA)/shape/anime_model_1/anime_model_1.o")
DefSegX("anime_model_2_static", ANIME_MODEL_2_SEGMENT, 	"$(ZELDA_DATA)/shape/anime_model_2/anime_model_2.o")
DefSegX("anime_model_3_static", ANIME_MODEL_3_SEGMENT, 	"$(ZELDA_DATA)/shape/anime_model_3/anime_model_3.o")
DefSegX("anime_model_4_static", ANIME_MODEL_4_SEGMENT, 	"$(ZELDA_DATA)/shape/anime_model_4/anime_model_4.o")
DefSegX("anime_model_5_static", ANIME_MODEL_5_SEGMENT, 	"$(ZELDA_DATA)/shape/anime_model_5/anime_model_5.o")
DefSegX("anime_model_6_static", ANIME_MODEL_6_SEGMENT, 	"$(ZELDA_DATA)/shape/anime_model_6/anime_model_6.o")
DefSegX("anime_texture_1_static", ANIME_TEXTURE_1_SEGMENT, "$(ZELDA_DATA)/shape/anime_texture_1/anime_texture_1.o")
DefSegX("anime_texture_2_static", ANIME_TEXTURE_2_SEGMENT, "$(ZELDA_DATA)/shape/anime_texture_2/anime_texture_2.o")
DefSegX("anime_texture_3_static", ANIME_TEXTURE_3_SEGMENT, "$(ZELDA_DATA)/shape/anime_texture_3/anime_texture_3.o")
DefSegX("anime_texture_4_static", ANIME_TEXTURE_4_SEGMENT, "$(ZELDA_DATA)/shape/anime_texture_4/anime_texture_4.o")
DefSegX("anime_texture_5_static", ANIME_TEXTURE_5_SEGMENT, "$(ZELDA_DATA)/shape/anime_texture_5/anime_texture_5.o")
DefSegX("anime_texture_6_static", ANIME_TEXTURE_6_SEGMENT, "$(ZELDA_DATA)/shape/anime_texture_6/anime_texture_6.o")
DefSegX("softsprite_matrix_static", SOFTSPRITE_MATRIX_SEGMENT, "$(ZELDA_DATA)/shape/softsprite_matrix/softsprite_matrix.o")


/*
 * シーンデータ
 */


#if defined(DISK_ROM_DATA)

DefSegX("ydan_scene",		GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Ydan_SCENE.o")
DefSegX("ydan_room_0",	 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM0.o")
DefSegX("ydan_room_1", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM1.o")
DefSegX("ydan_room_2", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM2.o")
DefSegX("ydan_room_3", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM3.o")
DefSegX("ydan_room_4", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM4.o")
DefSegX("ydan_room_5", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM5.o")
DefSegX("ydan_room_6", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM6.o")
DefSegX("ydan_room_7", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM7.o")
DefSegX("ydan_room_8", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM8.o")
DefSegX("ydan_room_9",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM9.o")
DefSegX("ydan_room_10",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM10.o")
DefSegX("ydan_room_11",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ydan_ROOM11.o")

DefSegX("ddan_scene", 	        GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Ddan_SCENE.o")
DefSegX("ddan_room_0", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM0.o")
DefSegX("ddan_room_1", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM1.o")
DefSegX("ddan_room_2", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM2.o")
DefSegX("ddan_room_3", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM3.o")
DefSegX("ddan_room_4", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM4.o")
DefSegX("ddan_room_5", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM5.o")
DefSegX("ddan_room_6", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM6.o")
DefSegX("ddan_room_7", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM7.o")
DefSegX("ddan_room_8", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM8.o")
DefSegX("ddan_room_9", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM9.o")
DefSegX("ddan_room_10", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM10.o")
DefSegX("ddan_room_11", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM11.o")
DefSegX("ddan_room_12", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM12.o")
DefSegX("ddan_room_13", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM13.o")
DefSegX("ddan_room_14", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM14.o")
DefSegX("ddan_room_15", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM15.o")
DefSegX("ddan_room_16", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Ddan_ROOM16.o")

DefSegX("bdan_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Bdan_SCENE.o")
DefSegX("bdan_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM0.o")
DefSegX("bdan_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM1.o")
DefSegX("bdan_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM2.o")
DefSegX("bdan_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM3.o")
DefSegX("bdan_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM4.o")
DefSegX("bdan_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM5.o")
DefSegX("bdan_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM6.o")
DefSegX("bdan_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM7.o")
DefSegX("bdan_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM8.o")
DefSegX("bdan_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM9.o")
DefSegX("bdan_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM10.o")
DefSegX("bdan_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM11.o")
DefSegX("bdan_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM12.o")
DefSegX("bdan_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM13.o")
DefSegX("bdan_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM14.o")
DefSegX("bdan_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bdan_ROOM15.o")

DefSegX("Bmori1_scene", 	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Bmori1_SCENE.o")
DefSegX("Bmori1_room_0", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM0.o")
DefSegX("Bmori1_room_1", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM1.o")
DefSegX("Bmori1_room_2", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM2.o")
DefSegX("Bmori1_room_3", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM3.o")
DefSegX("Bmori1_room_4", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM4.o")
DefSegX("Bmori1_room_5", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM5.o")
DefSegX("Bmori1_room_6", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM6.o")
DefSegX("Bmori1_room_7", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM7.o")
DefSegX("Bmori1_room_8", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM8.o")
DefSegX("Bmori1_room_9", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM9.o")
DefSegX("Bmori1_room_10", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM10.o")
DefSegX("Bmori1_room_11", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM11.o")
DefSegX("Bmori1_room_12", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM12.o")
DefSegX("Bmori1_room_13", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM13.o")
DefSegX("Bmori1_room_14", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM14.o")
DefSegX("Bmori1_room_15", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM15.o")
DefSegX("Bmori1_room_16", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM16.o")
DefSegX("Bmori1_room_17", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM17.o")
DefSegX("Bmori1_room_18", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM18.o")
DefSegX("Bmori1_room_19", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM19.o")
DefSegX("Bmori1_room_20", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM20.o")
DefSegX("Bmori1_room_21", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM21.o")
DefSegX("Bmori1_room_22", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1_ROOM22.o")

DefSegX("HIDAN_scene", 		GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Hidan_SCENE.o")
DefSegX("HIDAN_room_0", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM0.o")
DefSegX("HIDAN_room_1", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM1.o")
DefSegX("HIDAN_room_2", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM2.o")
DefSegX("HIDAN_room_3", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM3.o")
DefSegX("HIDAN_room_4", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM4.o")
DefSegX("HIDAN_room_5", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM5.o")
DefSegX("HIDAN_room_6", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM6.o")
DefSegX("HIDAN_room_7", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM7.o")
DefSegX("HIDAN_room_8", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM8.o")
DefSegX("HIDAN_room_9", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM9.o")
DefSegX("HIDAN_room_10", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM10.o")
DefSegX("HIDAN_room_11", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM11.o")
DefSegX("HIDAN_room_12", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM12.o")
DefSegX("HIDAN_room_13", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM13.o")
DefSegX("HIDAN_room_14", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM14.o")
DefSegX("HIDAN_room_15", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM15.o")
DefSegX("HIDAN_room_16", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM16.o")
DefSegX("HIDAN_room_17", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM17.o")
DefSegX("HIDAN_room_18", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM18.o")
DefSegX("HIDAN_room_19", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM19.o")
DefSegX("HIDAN_room_20", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM20.o")
DefSegX("HIDAN_room_21", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM21.o")
DefSegX("HIDAN_room_22", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM22.o")
DefSegX("HIDAN_room_23", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM23.o")
DefSegX("HIDAN_room_24", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM24.o")
DefSegX("HIDAN_room_25", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM25.o")
DefSegX("HIDAN_room_26", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hidan_ROOM26.o")

DefSegX("MIZUsin_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Mizusin_SCENE.o")
DefSegX("MIZUsin_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM0.o")
DefSegX("MIZUsin_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM1.o")
DefSegX("MIZUsin_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM2.o")
DefSegX("MIZUsin_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM3.o")
DefSegX("MIZUsin_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM4.o")
DefSegX("MIZUsin_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM5.o")
DefSegX("MIZUsin_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM6.o")
DefSegX("MIZUsin_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM7.o")
DefSegX("MIZUsin_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM8.o")
DefSegX("MIZUsin_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM9.o")
DefSegX("MIZUsin_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM10.o")
DefSegX("MIZUsin_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM11.o")
DefSegX("MIZUsin_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM12.o")
DefSegX("MIZUsin_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM13.o")
DefSegX("MIZUsin_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM14.o")
DefSegX("MIZUsin_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM15.o")
DefSegX("MIZUsin_room_16",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM16.o")
DefSegX("MIZUsin_room_17",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM17.o")
DefSegX("MIZUsin_room_18",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM18.o")
DefSegX("MIZUsin_room_19",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM19.o")
DefSegX("MIZUsin_room_20",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM20.o")
DefSegX("MIZUsin_room_21",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM21.o")
DefSegX("MIZUsin_room_22",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Mizusin_ROOM22.o")

DefSegX("jyasinzou_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Jyasinzou_SCENE.o")
DefSegX("jyasinzou_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM0.o")
DefSegX("jyasinzou_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM1.o")
DefSegX("jyasinzou_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM2.o")
DefSegX("jyasinzou_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM3.o")
DefSegX("jyasinzou_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM4.o")
DefSegX("jyasinzou_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM5.o")
DefSegX("jyasinzou_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM6.o")
DefSegX("jyasinzou_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM7.o")
DefSegX("jyasinzou_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM8.o")
DefSegX("jyasinzou_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM9.o")
DefSegX("jyasinzou_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM10.o")
DefSegX("jyasinzou_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM11.o")
DefSegX("jyasinzou_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM12.o")
DefSegX("jyasinzou_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM13.o")
DefSegX("jyasinzou_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM14.o")
DefSegX("jyasinzou_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM15.o")
DefSegX("jyasinzou_room_16",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM16.o")
DefSegX("jyasinzou_room_17",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM17.o")
DefSegX("jyasinzou_room_18",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM18.o")
DefSegX("jyasinzou_room_19",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM19.o")
DefSegX("jyasinzou_room_20",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM20.o")
DefSegX("jyasinzou_room_21",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM21.o")
DefSegX("jyasinzou_room_22",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM22.o")
DefSegX("jyasinzou_room_23",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM23.o")
DefSegX("jyasinzou_room_24",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM24.o")
DefSegX("jyasinzou_room_25",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM25.o")
DefSegX("jyasinzou_room_26",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM26.o")
DefSegX("jyasinzou_room_27",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM27.o")
DefSegX("jyasinzou_room_28",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Jyasinzou_ROOM28.o")

DefSegX("HAKAdan_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Hakadan_SCENE.o")
DefSegX("HAKAdan_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM0.o")
DefSegX("HAKAdan_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM1.o")
DefSegX("HAKAdan_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM2.o")
DefSegX("HAKAdan_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM3.o")
DefSegX("HAKAdan_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM4.o")
DefSegX("HAKAdan_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM5.o")
DefSegX("HAKAdan_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM6.o")
DefSegX("HAKAdan_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM7.o")
DefSegX("HAKAdan_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM8.o")
DefSegX("HAKAdan_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM9.o")
DefSegX("HAKAdan_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM10.o")
DefSegX("HAKAdan_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM11.o")
DefSegX("HAKAdan_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM12.o")
DefSegX("HAKAdan_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM13.o")
DefSegX("HAKAdan_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM14.o")
DefSegX("HAKAdan_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM15.o")
DefSegX("HAKAdan_room_16",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM16.o")
DefSegX("HAKAdan_room_17",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM17.o")
DefSegX("HAKAdan_room_18",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM18.o")
DefSegX("HAKAdan_room_19",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM19.o")
DefSegX("HAKAdan_room_20",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM20.o")
DefSegX("HAKAdan_room_21",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM21.o")
DefSegX("HAKAdan_room_22",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ROOM22.o")

DefSegX("HAKAdanCH_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Hakadan_ch_SCENE.o")
DefSegX("HAKAdanCH_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM0.o")
DefSegX("HAKAdanCH_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM1.o")
DefSegX("HAKAdanCH_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM2.o")
DefSegX("HAKAdanCH_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM3.o")
DefSegX("HAKAdanCH_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM4.o")
DefSegX("HAKAdanCH_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM5.o")
DefSegX("HAKAdanCH_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_ch_ROOM6.o")

DefSegX("ice_doukutu_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_SCENE.o")
DefSegX("ice_doukutu_room_0",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM0.o")
DefSegX("ice_doukutu_room_1",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM1.o")
DefSegX("ice_doukutu_room_2",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM2.o")
DefSegX("ice_doukutu_room_3",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM3.o")
DefSegX("ice_doukutu_room_4",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM4.o")
DefSegX("ice_doukutu_room_5",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM5.o")
DefSegX("ice_doukutu_room_6",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM6.o")
DefSegX("ice_doukutu_room_7",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM7.o")
DefSegX("ice_doukutu_room_8",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM8.o")
DefSegX("ice_doukutu_room_9",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM9.o")
DefSegX("ice_doukutu_room_10",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM10.o")
DefSegX("ice_doukutu_room_11",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutu_ROOM11.o")

DefSegX("men_scene",		GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Men_SCENE.o")
DefSegX("men_room_0",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM0.o")
DefSegX("men_room_1",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM1.o")
DefSegX("men_room_2",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM2.o")
DefSegX("men_room_3",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM3.o")
DefSegX("men_room_4",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM4.o")
DefSegX("men_room_5",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM5.o")
DefSegX("men_room_6",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM6.o")
DefSegX("men_room_7",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM7.o")
DefSegX("men_room_8",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM8.o")
DefSegX("men_room_9",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM9.o")
DefSegX("men_room_10",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Men_ROOM10.o")

#else

DefSegX("ydanDD_scene",			GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/YdanDD_SCENE.o")
DefSegX("ydanDD_room_0",	 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM0.o")
DefSegX("ydanDD_room_1", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM1.o")
DefSegX("ydanDD_room_2", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM2.o")
DefSegX("ydanDD_room_3", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM3.o")
DefSegX("ydanDD_room_4", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM4.o")
DefSegX("ydanDD_room_5", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM5.o")
DefSegX("ydanDD_room_6", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM6.o")
DefSegX("ydanDD_room_7", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM7.o")
DefSegX("ydanDD_room_8", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM8.o")
DefSegX("ydanDD_room_9",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM9.o")
DefSegX("ydanDD_room_10",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM10.o")
DefSegX("ydanDD_room_11",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/YdanDD_ROOM11.o")

DefSegX("ddanDD_scene", 	        GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/DdanDD_SCENE.o")
DefSegX("ddanDD_room_0", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM0.o")
DefSegX("ddanDD_room_1", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM1.o")
DefSegX("ddanDD_room_2", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM2.o")
DefSegX("ddanDD_room_3", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM3.o")
DefSegX("ddanDD_room_4", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM4.o")
DefSegX("ddanDD_room_5", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM5.o")
DefSegX("ddanDD_room_6", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM6.o")
DefSegX("ddanDD_room_7", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM7.o")
DefSegX("ddanDD_room_8", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM8.o")
DefSegX("ddanDD_room_9", 		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM9.o")
DefSegX("ddanDD_room_10", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM10.o")
DefSegX("ddanDD_room_11", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM11.o")
DefSegX("ddanDD_room_12", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM12.o")
DefSegX("ddanDD_room_13", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM13.o")
DefSegX("ddanDD_room_14", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM14.o")
DefSegX("ddanDD_room_15", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM15.o")
DefSegX("ddanDD_room_16", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/DdanDD_ROOM16.o")

DefSegX("bdanDD_scene",		GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/BdanDD_SCENE.o")
DefSegX("bdanDD_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM0.o")
DefSegX("bdanDD_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM1.o")
DefSegX("bdanDD_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM2.o")
DefSegX("bdanDD_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM3.o")
DefSegX("bdanDD_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM4.o")
DefSegX("bdanDD_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM5.o")
DefSegX("bdanDD_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM6.o")
DefSegX("bdanDD_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM7.o")
DefSegX("bdanDD_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM8.o")
DefSegX("bdanDD_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM9.o")
DefSegX("bdanDD_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM10.o")
DefSegX("bdanDD_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM11.o")
DefSegX("bdanDD_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM12.o")
DefSegX("bdanDD_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM13.o")
DefSegX("bdanDD_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM14.o")
DefSegX("bdanDD_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/BdanDD_ROOM15.o")

DefSegX("Bmori1DD_scene", 	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Bmori1DD_SCENE.o")
DefSegX("Bmori1DD_room_0", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM0.o")
DefSegX("Bmori1DD_room_1", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM1.o")
DefSegX("Bmori1DD_room_2", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM2.o")
DefSegX("Bmori1DD_room_3", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM3.o")
DefSegX("Bmori1DD_room_4", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM4.o")
DefSegX("Bmori1DD_room_5", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM5.o")
DefSegX("Bmori1DD_room_6", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM6.o")
DefSegX("Bmori1DD_room_7", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM7.o")
DefSegX("Bmori1DD_room_8", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM8.o")
DefSegX("Bmori1DD_room_9", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM9.o")
DefSegX("Bmori1DD_room_10", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM10.o")
DefSegX("Bmori1DD_room_11", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM11.o")
DefSegX("Bmori1DD_room_12", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM12.o")
DefSegX("Bmori1DD_room_13", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM13.o")
DefSegX("Bmori1DD_room_14", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM14.o")
DefSegX("Bmori1DD_room_15", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM15.o")
DefSegX("Bmori1DD_room_16", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM16.o")
DefSegX("Bmori1DD_room_17", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM17.o")
DefSegX("Bmori1DD_room_18", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM18.o")
DefSegX("Bmori1DD_room_19", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM19.o")
DefSegX("Bmori1DD_room_20", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM20.o")
DefSegX("Bmori1DD_room_21", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM21.o")
DefSegX("Bmori1DD_room_22", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Bmori1DD_ROOM22.o")

DefSegX("HIDANDD_scene", 		GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/HidanDD_SCENE.o")
DefSegX("HIDANDD_room_0", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM0.o")
DefSegX("HIDANDD_room_1", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM1.o")
DefSegX("HIDANDD_room_2", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM2.o")
DefSegX("HIDANDD_room_3", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM3.o")
DefSegX("HIDANDD_room_4", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM4.o")
DefSegX("HIDANDD_room_5", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM5.o")
DefSegX("HIDANDD_room_6", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM6.o")
DefSegX("HIDANDD_room_7", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM7.o")
DefSegX("HIDANDD_room_8", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM8.o")
DefSegX("HIDANDD_room_9", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM9.o")
DefSegX("HIDANDD_room_10", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM10.o")
DefSegX("HIDANDD_room_11", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM11.o")
DefSegX("HIDANDD_room_12", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM12.o")
DefSegX("HIDANDD_room_13", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM13.o")
DefSegX("HIDANDD_room_14", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM14.o")
DefSegX("HIDANDD_room_15", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM15.o")
DefSegX("HIDANDD_room_16", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM16.o")
DefSegX("HIDANDD_room_17", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM17.o")
DefSegX("HIDANDD_room_18", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM18.o")
DefSegX("HIDANDD_room_19", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM19.o")
DefSegX("HIDANDD_room_20", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM20.o")
DefSegX("HIDANDD_room_21", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM21.o")
DefSegX("HIDANDD_room_22", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM22.o")
DefSegX("HIDANDD_room_23", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM23.o")
DefSegX("HIDANDD_room_24", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM24.o")
DefSegX("HIDANDD_room_25", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM25.o")
DefSegX("HIDANDD_room_26", 	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HidanDD_ROOM26.o")

DefSegX("MIZUsinDD_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/MizusinDD_SCENE.o")
DefSegX("MIZUsinDD_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM0.o")
DefSegX("MIZUsinDD_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM1.o")
DefSegX("MIZUsinDD_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM2.o")
DefSegX("MIZUsinDD_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM3.o")
DefSegX("MIZUsinDD_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM4.o")
DefSegX("MIZUsinDD_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM5.o")
DefSegX("MIZUsinDD_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM6.o")
DefSegX("MIZUsinDD_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM7.o")
DefSegX("MIZUsinDD_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM8.o")
DefSegX("MIZUsinDD_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM9.o")
DefSegX("MIZUsinDD_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM10.o")
DefSegX("MIZUsinDD_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM11.o")
DefSegX("MIZUsinDD_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM12.o")
DefSegX("MIZUsinDD_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM13.o")
DefSegX("MIZUsinDD_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM14.o")
DefSegX("MIZUsinDD_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM15.o")
DefSegX("MIZUsinDD_room_16",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM16.o")
DefSegX("MIZUsinDD_room_17",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM17.o")
DefSegX("MIZUsinDD_room_18",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM18.o")
DefSegX("MIZUsinDD_room_19",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM19.o")
DefSegX("MIZUsinDD_room_20",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM20.o")
DefSegX("MIZUsinDD_room_21",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM21.o")
DefSegX("MIZUsinDD_room_22",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MizusinDD_ROOM22.o")

DefSegX("jyasinzouDD_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/JyasinzouDD_SCENE.o")
DefSegX("jyasinzouDD_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM0.o")
DefSegX("jyasinzouDD_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM1.o")
DefSegX("jyasinzouDD_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM2.o")
DefSegX("jyasinzouDD_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM3.o")
DefSegX("jyasinzouDD_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM4.o")
DefSegX("jyasinzouDD_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM5.o")
DefSegX("jyasinzouDD_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM6.o")
DefSegX("jyasinzouDD_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM7.o")
DefSegX("jyasinzouDD_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM8.o")
DefSegX("jyasinzouDD_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM9.o")
DefSegX("jyasinzouDD_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM10.o")
DefSegX("jyasinzouDD_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM11.o")
DefSegX("jyasinzouDD_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM12.o")
DefSegX("jyasinzouDD_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM13.o")
DefSegX("jyasinzouDD_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM14.o")
DefSegX("jyasinzouDD_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM15.o")
DefSegX("jyasinzouDD_room_16",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM16.o")
DefSegX("jyasinzouDD_room_17",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM17.o")
DefSegX("jyasinzouDD_room_18",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM18.o")
DefSegX("jyasinzouDD_room_19",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM19.o")
DefSegX("jyasinzouDD_room_20",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM20.o")
DefSegX("jyasinzouDD_room_21",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM21.o")
DefSegX("jyasinzouDD_room_22",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM22.o")
DefSegX("jyasinzouDD_room_23",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM23.o")
DefSegX("jyasinzouDD_room_24",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM24.o")
DefSegX("jyasinzouDD_room_25",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM25.o")
DefSegX("jyasinzouDD_room_26",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM26.o")
DefSegX("jyasinzouDD_room_27",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM27.o")
DefSegX("jyasinzouDD_room_28",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/JyasinzouDD_ROOM28.o")

DefSegX("HAKAdanDD_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/HakadanDD_SCENE.o")
DefSegX("HAKAdanDD_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM0.o")
DefSegX("HAKAdanDD_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM1.o")
DefSegX("HAKAdanDD_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM2.o")
DefSegX("HAKAdanDD_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM3.o")
DefSegX("HAKAdanDD_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM4.o")
DefSegX("HAKAdanDD_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM5.o")
DefSegX("HAKAdanDD_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM6.o")
DefSegX("HAKAdanDD_room_7",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM7.o")
DefSegX("HAKAdanDD_room_8",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM8.o")
DefSegX("HAKAdanDD_room_9",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM9.o")
DefSegX("HAKAdanDD_room_10",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM10.o")
DefSegX("HAKAdanDD_room_11",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM11.o")
DefSegX("HAKAdanDD_room_12",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM12.o")
DefSegX("HAKAdanDD_room_13",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM13.o")
DefSegX("HAKAdanDD_room_14",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM14.o")
DefSegX("HAKAdanDD_room_15",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM15.o")
DefSegX("HAKAdanDD_room_16",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM16.o")
DefSegX("HAKAdanDD_room_17",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM17.o")
DefSegX("HAKAdanDD_room_18",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM18.o")
DefSegX("HAKAdanDD_room_19",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM19.o")
DefSegX("HAKAdanDD_room_20",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM20.o")
DefSegX("HAKAdanDD_room_21",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM21.o")
DefSegX("HAKAdanDD_room_22",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/HakadanDD_ROOM22.o")

DefSegX("HAKAdanCHDD_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Hakadan_chDD_SCENE.o")
DefSegX("HAKAdanCHDD_room_0",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM0.o")
DefSegX("HAKAdanCHDD_room_1",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM1.o")
DefSegX("HAKAdanCHDD_room_2",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM2.o")
DefSegX("HAKAdanCHDD_room_3",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM3.o")
DefSegX("HAKAdanCHDD_room_4",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM4.o")
DefSegX("HAKAdanCHDD_room_5",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM5.o")
DefSegX("HAKAdanCHDD_room_6",	GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/Hakadan_chDD_ROOM6.o")

DefSegX("ice_doukutuDD_scene",	GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_SCENE.o")
DefSegX("ice_doukutuDD_room_0",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM0.o")
DefSegX("ice_doukutuDD_room_1",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM1.o")
DefSegX("ice_doukutuDD_room_2",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM2.o")
DefSegX("ice_doukutuDD_room_3",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM3.o")
DefSegX("ice_doukutuDD_room_4",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM4.o")
DefSegX("ice_doukutuDD_room_5",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM5.o")
DefSegX("ice_doukutuDD_room_6",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM6.o")
DefSegX("ice_doukutuDD_room_7",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM7.o")
DefSegX("ice_doukutuDD_room_8",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM8.o")
DefSegX("ice_doukutuDD_room_9",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM9.o")
DefSegX("ice_doukutuDD_room_10",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM10.o")
DefSegX("ice_doukutuDD_room_11",	GAMEPLAY_ROOM_SEGMENT, "$(ZELDA_ROOT)/data/Ice_doukutuDD_ROOM11.o")

DefSegX("menDD_scene",		GAMEPLAY_SCENE_SEGMENT, "$(ZELDA_ROOT)/data/MenDD_SCENE.o")
DefSegX("menDD_room_0",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM0.o")
DefSegX("menDD_room_1",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM1.o")
DefSegX("menDD_room_2",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM2.o")
DefSegX("menDD_room_3",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM3.o")
DefSegX("menDD_room_4",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM4.o")
DefSegX("menDD_room_5",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM5.o")
DefSegX("menDD_room_6",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM6.o")
DefSegX("menDD_room_7",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM7.o")
DefSegX("menDD_room_8",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM8.o")
DefSegX("menDD_room_9",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM9.o")
DefSegX("menDD_room_10",		GAMEPLAY_ROOM_SEGMENT, 	"$(ZELDA_ROOT)/data/MenDD_ROOM10.o")

#endif /* defined(DISK_ROM_DATA) */

/*
 * ウェーブの定義
 */
beginwave
	name "zelda_n64dd_rom"

	include "disk_boot"

	include "disk_info"
	include "disksegment"

/*
 * ＭＡＰテクスチャ
 */
	include "disk_map_48x85_static"
	include "disk_map_i_static"

/*
 * ダミーセグメント
 */
	include "gameplay_object_exchange_static"
	include "bump_texture_static"
	include "anime_model_1_static"
	include "anime_model_2_static"
	include "anime_model_3_static"
	include "anime_model_4_static"
	include "anime_model_5_static"
	include "anime_model_6_static"
	include "anime_texture_1_static"
	include "anime_texture_2_static"
	include "anime_texture_3_static"
	include "anime_texture_4_static"
	include "anime_texture_5_static"
	include "anime_texture_6_static"
	include "softsprite_matrix_static"

/*
 * シーンデータ
 */


#if defined(DISK_ROM_DATA)

	include "ydan_scene"
	include "ydan_room_0"
	include "ydan_room_1"
	include "ydan_room_2"
	include "ydan_room_3"
	include "ydan_room_4"
	include "ydan_room_5"
	include "ydan_room_6"
	include "ydan_room_7"
	include "ydan_room_8"
	include "ydan_room_9"
	include "ydan_room_10"
	include "ydan_room_11"

	include "ddan_scene"
	include "ddan_room_0"
	include "ddan_room_1"
	include "ddan_room_2"
	include "ddan_room_3"
	include "ddan_room_4"
	include "ddan_room_5"
	include "ddan_room_6"
	include "ddan_room_7"
	include "ddan_room_8"
	include "ddan_room_9"
	include "ddan_room_10"
	include "ddan_room_11"
	include "ddan_room_12"
	include "ddan_room_13"
	include "ddan_room_14"
	include "ddan_room_15"
	include "ddan_room_16"

	include "bdan_scene"
	include "bdan_room_0"
	include "bdan_room_1"
	include "bdan_room_2"
	include "bdan_room_3"
	include "bdan_room_4"
	include "bdan_room_5"
	include "bdan_room_6"
	include "bdan_room_7"
	include "bdan_room_8"
	include "bdan_room_9"
	include "bdan_room_10"
	include "bdan_room_11"
	include "bdan_room_12"
	include "bdan_room_13"
	include "bdan_room_14"
	include "bdan_room_15"

	include "Bmori1_scene"
	include "Bmori1_room_0"
	include "Bmori1_room_1"
	include "Bmori1_room_2"
	include "Bmori1_room_3"
	include "Bmori1_room_4"
	include "Bmori1_room_5"
	include "Bmori1_room_6"
	include "Bmori1_room_7"
	include "Bmori1_room_8"
	include "Bmori1_room_9"
	include "Bmori1_room_10"
	include "Bmori1_room_11"
	include "Bmori1_room_12"
	include "Bmori1_room_13"
	include "Bmori1_room_14"
	include "Bmori1_room_15"
	include "Bmori1_room_16"
	include "Bmori1_room_17"
	include "Bmori1_room_18"
	include "Bmori1_room_19"
	include "Bmori1_room_20"
	include "Bmori1_room_21"
	include "Bmori1_room_22"

	include "HIDAN_scene"
	include "HIDAN_room_0"
	include "HIDAN_room_1"
	include "HIDAN_room_2"
	include "HIDAN_room_3"
	include "HIDAN_room_4"
	include "HIDAN_room_5"
	include "HIDAN_room_6"
	include "HIDAN_room_7"
	include "HIDAN_room_8"
	include "HIDAN_room_9"
	include "HIDAN_room_10"
	include "HIDAN_room_11"
	include "HIDAN_room_12"
	include "HIDAN_room_13"
	include "HIDAN_room_14"
	include "HIDAN_room_15"
	include "HIDAN_room_16"
	include "HIDAN_room_17"
	include "HIDAN_room_18"
	include "HIDAN_room_19"
	include "HIDAN_room_20"
	include "HIDAN_room_21"
	include "HIDAN_room_22"
	include "HIDAN_room_23"
	include "HIDAN_room_24"
	include "HIDAN_room_25"
	include "HIDAN_room_26"

	include "MIZUsin_scene"
	include "MIZUsin_room_0"
	include "MIZUsin_room_1"
	include "MIZUsin_room_2"
	include "MIZUsin_room_3"
	include "MIZUsin_room_4"
	include "MIZUsin_room_5"
	include "MIZUsin_room_6"
	include "MIZUsin_room_7"
	include "MIZUsin_room_8"
	include "MIZUsin_room_9"
	include "MIZUsin_room_10"
	include "MIZUsin_room_11"
	include "MIZUsin_room_12"
	include "MIZUsin_room_13"
	include "MIZUsin_room_14"
	include "MIZUsin_room_15"
	include "MIZUsin_room_16"
	include "MIZUsin_room_17"
	include "MIZUsin_room_18"
	include "MIZUsin_room_19"
	include "MIZUsin_room_20"
	include "MIZUsin_room_21"
	include "MIZUsin_room_22"

	include "jyasinzou_scene"
	include "jyasinzou_room_0"
	include "jyasinzou_room_1"
	include "jyasinzou_room_2"
	include "jyasinzou_room_3"
	include "jyasinzou_room_4"
	include "jyasinzou_room_5"
	include "jyasinzou_room_6"
	include "jyasinzou_room_7"
	include "jyasinzou_room_8"
	include "jyasinzou_room_9"
	include "jyasinzou_room_10"
	include "jyasinzou_room_11"
	include "jyasinzou_room_12"
	include "jyasinzou_room_13"
	include "jyasinzou_room_14"
	include "jyasinzou_room_15"
	include "jyasinzou_room_16"
	include "jyasinzou_room_17"
	include "jyasinzou_room_18"
	include "jyasinzou_room_19"
	include "jyasinzou_room_20"
	include "jyasinzou_room_21"
	include "jyasinzou_room_22"
	include "jyasinzou_room_23"
	include "jyasinzou_room_24"
	include "jyasinzou_room_25"
	include "jyasinzou_room_26"
	include "jyasinzou_room_27"
	include "jyasinzou_room_28"

	include "HAKAdan_scene"
	include "HAKAdan_room_0"
	include "HAKAdan_room_1"
	include "HAKAdan_room_2"
	include "HAKAdan_room_3"
	include "HAKAdan_room_4"
	include "HAKAdan_room_5"
	include "HAKAdan_room_6"
	include "HAKAdan_room_7"
	include "HAKAdan_room_8"
	include "HAKAdan_room_9"
	include "HAKAdan_room_10"
	include "HAKAdan_room_11"
	include "HAKAdan_room_12"
	include "HAKAdan_room_13"
	include "HAKAdan_room_14"
	include "HAKAdan_room_15"
	include "HAKAdan_room_16"
	include "HAKAdan_room_17"
	include "HAKAdan_room_18"
	include "HAKAdan_room_19"
	include "HAKAdan_room_20"
	include "HAKAdan_room_21"
	include "HAKAdan_room_22"

	include "HAKAdanCH_scene"
	include "HAKAdanCH_room_0"
	include "HAKAdanCH_room_1"
	include "HAKAdanCH_room_2"
	include "HAKAdanCH_room_3"
	include "HAKAdanCH_room_4"
	include "HAKAdanCH_room_5"
	include "HAKAdanCH_room_6"

	include "ice_doukutu_scene"
	include "ice_doukutu_room_0"
	include "ice_doukutu_room_1"
	include "ice_doukutu_room_2"
	include "ice_doukutu_room_3"
	include "ice_doukutu_room_4"
	include "ice_doukutu_room_5"
	include "ice_doukutu_room_6"
	include "ice_doukutu_room_7"
	include "ice_doukutu_room_8"
	include "ice_doukutu_room_9"
	include "ice_doukutu_room_10"
	include "ice_doukutu_room_11"

	include "men_scene"
	include "men_room_0"
	include "men_room_1"
	include "men_room_2"
	include "men_room_3"
	include "men_room_4"
	include "men_room_5"
	include "men_room_6"
	include "men_room_7"
	include "men_room_8"
	include "men_room_9"
	include "men_room_10"

#else

	include "ydanDD_scene"
	include "ydanDD_room_0"
	include "ydanDD_room_1"
	include "ydanDD_room_2"
	include "ydanDD_room_3"
	include "ydanDD_room_4"
	include "ydanDD_room_5"
	include "ydanDD_room_6"
	include "ydanDD_room_7"
	include "ydanDD_room_8"
	include "ydanDD_room_9"
	include "ydanDD_room_10"
	include "ydanDD_room_11"

	include "ddanDD_scene"
	include "ddanDD_room_0"
	include "ddanDD_room_1"
	include "ddanDD_room_2"
	include "ddanDD_room_3"
	include "ddanDD_room_4"
	include "ddanDD_room_5"
	include "ddanDD_room_6"
	include "ddanDD_room_7"
	include "ddanDD_room_8"
	include "ddanDD_room_9"
	include "ddanDD_room_10"
	include "ddanDD_room_11"
	include "ddanDD_room_12"
	include "ddanDD_room_13"
	include "ddanDD_room_14"
	include "ddanDD_room_15"
	include "ddanDD_room_16"

	include "bdanDD_scene"
	include "bdanDD_room_0"
	include "bdanDD_room_1"
	include "bdanDD_room_2"
	include "bdanDD_room_3"
	include "bdanDD_room_4"
	include "bdanDD_room_5"
	include "bdanDD_room_6"
	include "bdanDD_room_7"
	include "bdanDD_room_8"
	include "bdanDD_room_9"
	include "bdanDD_room_10"
	include "bdanDD_room_11"
	include "bdanDD_room_12"
	include "bdanDD_room_13"
	include "bdanDD_room_14"
	include "bdanDD_room_15"

	include "Bmori1DD_scene"
	include "Bmori1DD_room_0"
	include "Bmori1DD_room_1"
	include "Bmori1DD_room_2"
	include "Bmori1DD_room_3"
	include "Bmori1DD_room_4"
	include "Bmori1DD_room_5"
	include "Bmori1DD_room_6"
	include "Bmori1DD_room_7"
	include "Bmori1DD_room_8"
	include "Bmori1DD_room_9"
	include "Bmori1DD_room_10"
	include "Bmori1DD_room_11"
	include "Bmori1DD_room_12"
	include "Bmori1DD_room_13"
	include "Bmori1DD_room_14"
	include "Bmori1DD_room_15"
	include "Bmori1DD_room_16"
	include "Bmori1DD_room_17"
	include "Bmori1DD_room_18"
	include "Bmori1DD_room_19"
	include "Bmori1DD_room_20"
	include "Bmori1DD_room_21"
	include "Bmori1DD_room_22"

	include "HIDANDD_scene"
	include "HIDANDD_room_0"
	include "HIDANDD_room_1"
	include "HIDANDD_room_2"
	include "HIDANDD_room_3"
	include "HIDANDD_room_4"
	include "HIDANDD_room_5"
	include "HIDANDD_room_6"
	include "HIDANDD_room_7"
	include "HIDANDD_room_8"
	include "HIDANDD_room_9"
	include "HIDANDD_room_10"
	include "HIDANDD_room_11"
	include "HIDANDD_room_12"
	include "HIDANDD_room_13"
	include "HIDANDD_room_14"
	include "HIDANDD_room_15"
	include "HIDANDD_room_16"
	include "HIDANDD_room_17"
	include "HIDANDD_room_18"
	include "HIDANDD_room_19"
	include "HIDANDD_room_20"
	include "HIDANDD_room_21"
	include "HIDANDD_room_22"
	include "HIDANDD_room_23"
	include "HIDANDD_room_24"
	include "HIDANDD_room_25"
	include "HIDANDD_room_26"

	include "MIZUsinDD_scene"
	include "MIZUsinDD_room_0"
	include "MIZUsinDD_room_1"
	include "MIZUsinDD_room_2"
	include "MIZUsinDD_room_3"
	include "MIZUsinDD_room_4"
	include "MIZUsinDD_room_5"
	include "MIZUsinDD_room_6"
	include "MIZUsinDD_room_7"
	include "MIZUsinDD_room_8"
	include "MIZUsinDD_room_9"
	include "MIZUsinDD_room_10"
	include "MIZUsinDD_room_11"
	include "MIZUsinDD_room_12"
	include "MIZUsinDD_room_13"
	include "MIZUsinDD_room_14"
	include "MIZUsinDD_room_15"
	include "MIZUsinDD_room_16"
	include "MIZUsinDD_room_17"
	include "MIZUsinDD_room_18"
	include "MIZUsinDD_room_19"
	include "MIZUsinDD_room_20"
	include "MIZUsinDD_room_21"
	include "MIZUsinDD_room_22"

	include "jyasinzouDD_scene"
	include "jyasinzouDD_room_0"
	include "jyasinzouDD_room_1"
	include "jyasinzouDD_room_2"
	include "jyasinzouDD_room_3"
	include "jyasinzouDD_room_4"
	include "jyasinzouDD_room_5"
	include "jyasinzouDD_room_6"
	include "jyasinzouDD_room_7"
	include "jyasinzouDD_room_8"
	include "jyasinzouDD_room_9"
	include "jyasinzouDD_room_10"
	include "jyasinzouDD_room_11"
	include "jyasinzouDD_room_12"
	include "jyasinzouDD_room_13"
	include "jyasinzouDD_room_14"
	include "jyasinzouDD_room_15"
	include "jyasinzouDD_room_16"
	include "jyasinzouDD_room_17"
	include "jyasinzouDD_room_18"
	include "jyasinzouDD_room_19"
	include "jyasinzouDD_room_20"
	include "jyasinzouDD_room_21"
	include "jyasinzouDD_room_22"
	include "jyasinzouDD_room_23"
	include "jyasinzouDD_room_24"
	include "jyasinzouDD_room_25"
	include "jyasinzouDD_room_26"
	include "jyasinzouDD_room_27"
	include "jyasinzouDD_room_28"

	include "HAKAdanDD_scene"
	include "HAKAdanDD_room_0"
	include "HAKAdanDD_room_1"
	include "HAKAdanDD_room_2"
	include "HAKAdanDD_room_3"
	include "HAKAdanDD_room_4"
	include "HAKAdanDD_room_5"
	include "HAKAdanDD_room_6"
	include "HAKAdanDD_room_7"
	include "HAKAdanDD_room_8"
	include "HAKAdanDD_room_9"
	include "HAKAdanDD_room_10"
	include "HAKAdanDD_room_11"
	include "HAKAdanDD_room_12"
	include "HAKAdanDD_room_13"
	include "HAKAdanDD_room_14"
	include "HAKAdanDD_room_15"
	include "HAKAdanDD_room_16"
	include "HAKAdanDD_room_17"
	include "HAKAdanDD_room_18"
	include "HAKAdanDD_room_19"
	include "HAKAdanDD_room_20"
	include "HAKAdanDD_room_21"
	include "HAKAdanDD_room_22"

	include "HAKAdanCHDD_scene"
	include "HAKAdanCHDD_room_0"
	include "HAKAdanCHDD_room_1"
	include "HAKAdanCHDD_room_2"
	include "HAKAdanCHDD_room_3"
	include "HAKAdanCHDD_room_4"
	include "HAKAdanCHDD_room_5"
	include "HAKAdanCHDD_room_6"

	include "ice_doukutuDD_scene"
	include "ice_doukutuDD_room_0"
	include "ice_doukutuDD_room_1"
	include "ice_doukutuDD_room_2"
	include "ice_doukutuDD_room_3"
	include "ice_doukutuDD_room_4"
	include "ice_doukutuDD_room_5"
	include "ice_doukutuDD_room_6"
	include "ice_doukutuDD_room_7"
	include "ice_doukutuDD_room_8"
	include "ice_doukutuDD_room_9"
	include "ice_doukutuDD_room_10"
	include "ice_doukutuDD_room_11"

	include "menDD_scene"
	include "menDD_room_0"
	include "menDD_room_1"
	include "menDD_room_2"
	include "menDD_room_3"
	include "menDD_room_4"
	include "menDD_room_5"
	include "menDD_room_6"
	include "menDD_room_7"
	include "menDD_room_8"
	include "menDD_room_9"
	include "menDD_room_10"

#endif /* defined(DISK_ROM_DATA) */

endwave
