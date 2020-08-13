/*
 * $Id: sys_segment.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 *	スペック ファイル と 共通 の 宣言
 *
 * $Log: sys_segment.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.51  1998/09/24 14:05:46  hayakawa
 * DISKSEGMENT_START追加
 *
 * Revision 1.50  1998-09-22 22:07:18+09  hayakawa
 * DISK
 *
 * Revision 1.49  1998-07-24 22:19:03+09  soejima
 * *** empty log message ***
 *
 * Revision 1.48  1998-06-03 11:22:37+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.47  1998-04-28 19:31:47+09  soejima
 * ICON_ITEM_MAP_SEGMENT
 *
 * Revision 1.46  1998-01-05 21:13:23+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.45  1997/12/25  08:36:02  soejima
 * *** empty log message ***
 *
 * Revision 1.44  1997/10/22  05:05:41  soejima
 * *** empty log message ***
 *
 * Revision 1.43  1997/10/11  10:18:46  soejima
 * ＭＡＰ
 *
 * Revision 1.42  1997/10/07  13:51:00  soejima
 * *** empty log message ***
 *
 * Revision 1.41  1997/10/03  13:26:27  soejima
 * *** empty log message ***
 *
 * Revision 1.40  1997/10/01  13:54:45  soejima
 * *** empty log message ***
 *
 * Revision 1.39  1997/08/08  01:50:55  soejima
 * *** empty log message ***
 *
 * Revision 1.38  1997/08/07  05:08:19  soejima
 * *** empty log message ***
 *
 * Revision 1.37  1997/07/14  12:23:20  iwawaki
 * *** empty log message ***
 *
 * Revision 1.36  1997/06/27  06:26:23  soejima
 * PARAMETER3_SEGMENT
 *
 * Revision 1.35  1997/06/23  11:01:43  soejima
 * *** empty log message ***
 *
 * Revision 1.34  1997/06/20  05:02:30  soejima
 * ＳＥＧＭＥＮＴ（ＶＲ＿ＢＯＸ用）整理
 *
 * Revision 1.33  1997/06/19  00:43:12  soejima
 * ＶＲ＿ＢＯＸ（２５６Ｂｌｏｃｋテクスチャ）
 *
 * Revision 1.32  1997/06/18  03:02:33  soejima
 * ＶＲ＿ＢＯＸ（Ｂｌｏｃｋテクスチャ）
 *
 * Revision 1.31  1997/06/10  02:06:43  soejima
 * *** empty log message ***
 *
 * Revision 1.30  1997/06/09  12:09:38  soejima
 * ４５度角度ＶＲーＢＯＸ
 *
 * Revision 1.29  1997/06/04  11:11:59  soejima
 * アイテム・ショップ２５６
 *
 * Revision 1.28  1997/06/03  09:56:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.27  1997/06/02  12:27:41  soejima
 * 雲vr_box
 *
 * Revision 1.26  1997/05/30  01:18:18  soejima
 * item_shop_vr_box入荷
 *
 * Revision 1.25  1997/05/28  06:21:51  hayakawa
 * AUDIO_SEGMENT追加
 *
 * Revision 1.24  1997/05/22  00:55:32  soejima
 * fairy_vr_box入荷
 *
 * Revision 1.23  1997/05/20  12:12:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1997/05/06  07:42:39  iwawaki
 * new
 *
 * Revision 1.21  1997/04/18  09:29:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1997/04/02  10:25:50  soejima
 * てすとＶＲ＿ＢＯＸ入荷
 *
 * Revision 1.19  1997/03/18  13:27:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/03/10  00:23:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1997/02/24  10:37:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1997/02/04  02:09:28  soejima
 * KANROM2_SEGMENT外した。
 *
 * Revision 1.15  1996/12/16  08:53:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1996/12/16  08:50:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1996/12/09  12:57:07  iwawaki
 * STATIC_2_SEFMENT add
 *
 * Revision 1.12  1996/12/04  05:58:03  hayakawa
 * BOOT_STACK_SIZE	を実際に合わせた
 *
 * Revision 1.11  1996/11/18  09:50:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1996/11/18  01:07:31  iwawaki
 * BUMP_TEXTURE_SEGMENT追加
 *
 * Revision 1.9  1996/11/07  07:07:06  soejima
 * アンチエイリアス付 KANROM_SEGMENT
 * アンチエイリアス無 KANROM2_SEGMENT
 *
 * Revision 1.8  1996/11/06  11:44:18  soejima
 * 第１水準フォント セット
 *
 * Revision 1.7  1996/11/06  11:34:21  soejima
 * *** empty log message ***
 *
 * Revision 1.6  1996/10/30  11:31:30  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1996/10/30  04:33:08  iwawaki
 * COMMON_STATIC_SEGMENT追加
 *
 * Revision 1.4  1996/10/23  12:07:21  soejima
 * VR_BOXセグメント設定
 *
 */

#ifndef __SYS_SEGMENT_H_
#define __SYS_SEGMENT_H_


/*
 *	スタック サイズ
 */
#define	BOOT_STACK_SIZE		1024
#define	DISK_BOOT_STACK_SIZE	1024

/*
 *	各 セグメント の 番号
 */
#define PHYSICAL_SEGMENT		0
#define STATIC_SEGMENT			1
#define AUDIO_SEGMENT 			STATIC_SEGMENT /* 別に何番でもいい */
#define DYNAMIC_SEGMENT			2

/*
 * ------------	ゲーム用 ---------------
 */
#define SOFTSPRITE_MATRIX_SEGMENT		1

#define GAMEPLAY_SCENE_SEGMENT			2
#define GAMEPLAY_ROOM_SEGMENT			3
#define GAMEPLAY_KEEP_SEGMENT			4
#define GAMEPLAY_EXCHANGE_KEEP_SEGMENT		5

#define GAMEPLAY_OBJECT_EXCHANGE_SEGMENT	6

/*
 * 汎用
 */
/*- 	ただのダミーセグメント	-*/
#define GAMEPLAY_ELF_MESSAGE_SEGMENT		7

/*----------------------------------------------*/
#define	READ_ROM_DATA_SEGMENT		7

/*----------------------------------------------*/
/* ＶＲ＿ＢＯＸ */
#define VR_BOX0_SEGMENT			7
#define VR_BOX1_SEGMENT			8
#define VR_BOX_TLUT_SEGMENT		9

/*----------------------------------------------*/
/* メッセージ吹き出し */
#define MESSAGE0_SEGMENT		7
#define MESSAGE1_SEGMENT		8
#define MESSAGE2_SEGMENT		9

/*----------------------------------------------*/
#define KANROM_SEGMENT          	10

/*----------------------------------------------*/
/* パラメーター */
#define PARAMETER0_SEGMENT		7
#define MAP_SEGMENT			11

/*----------------------------------------------*/
/* カレイド・スコープ */
#define ICON_ITEM_SEGMENT		8
#define ICON_ITEM_24_SEGMENT		9
#define ITEM_NAME_SEGMENT		10
#define ICON_ITEM_MAP_SEGMENT		12
#define ICON_ITEM_JPN_NES_SEGMENT	13


/*----------------------------------------------*/
/* 太陽と月 */
#define	SUN_MOON_SEGMENT		7

/*----------------------------------------------*/
#define HILITE_SEGMENT			7

#define BUMP_TEXTURE_SEGMENT		8

#define ANIME_TEXTURE_1_SEGMENT		8
#define ANIME_TEXTURE_2_SEGMENT		9
#define ANIME_TEXTURE_3_SEGMENT		10
#define ANIME_TEXTURE_4_SEGMENT		11
#define ANIME_TEXTURE_5_SEGMENT		12
#define ANIME_TEXTURE_6_SEGMENT		13

#define ANIME_MODEL_1_SEGMENT		8
#define ANIME_MODEL_2_SEGMENT		9
#define ANIME_MODEL_3_SEGMENT		10
#define ANIME_MODEL_4_SEGMENT		11
#define ANIME_MODEL_5_SEGMENT		12
#define ANIME_MODEL_6_SEGMENT		13

#define ZB_SEGMENT			14
#define CFB_SEGMENT			15

#define DISKSEGMENT_START 0x80600000

#endif /* __SYS_SEGMENT_H_ */
