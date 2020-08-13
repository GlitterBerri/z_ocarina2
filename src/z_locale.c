/*
 * $Id: z_locale.c,v 1.1.1.1 2003/03/10 22:42:46 tong Exp $
 *
 * ロケールクラス
 *
 * $Log: z_locale.c,v $
 * Revision 1.1.1.1  2003/03/10 22:42:46  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.9  2001/06/06  05:28:53  zelda
 * *** empty log message ***
 *
 * Revision 2.8  2001-06-01 20:17:06+09  zelda
 * 日本・アメリカ切り替えの復活＆変更
 *
 * Revision 2.7  2000-06-13 15:17:09+09  hayakawa
 * ははは
 * デバッグ
 *
 * Revision 2.6  2000-06-13 13:58:06+09  hayakawa
 * 木村さんの要望で判定ルーチンを殺します
 *
 * Revision 2.5  1999-01-07 13:15:03+09  hayakawa
 * ゲートウェイシステム対応
 *
 * Revision 2.4  1998-10-27 20:16:11+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.3  1998-10-27 19:32:41+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  1998-10-23 18:07:31+09  hayakawa
 * PRINTFを消しただけ
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.11  1998-10-20 19:49:59+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.10  1998-10-05 22:09:57+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1998-10-03 16:04:56+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.8  1998-09-22 09:29:29+09  hayakawa
 * 型の不一致を修正
 *
 * Revision 1.7  1998-09-17 11:20:06+09  hayakawa
 * イニシャルコードをちゃんと読めるように修正
 *
 * Revision 1.6  1998-09-04 10:09:32+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.5  1998-08-25 21:38:56+09  hayakawa
 * ３コンが挿さっているかどうかで日本／ＵＳを切替る様に一応してみた
 *
 * Revision 1.4  1998-07-03 09:32:54+09  hayakawa
 * FINAL_ROMのときにエラーになっていた
 *
 * Revision 1.3  1998-07-02 21:58:22+09  hayakawa
 * デバッグ時は関数の方が良さげ
 *
 * Revision 1.2  1998-06-12 12:07:04+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1998-06-08 20:58:10+09  hayakawa
 * Initial revision
 *
 */

#include "z_locale.h"
#include "system.h"		/* carthandle */
#include "debug.h"		/* PRINTF */
#include "assert64.h"		/* assert */
#include "padmgr.h"

extern padmgr_t padmgr;

#define ROM_ENTRY_ADDR 0x20
#define ROM_ENTRY_INITIAL_CODE_ADDR (ROM_ENTRY_ADDR+20+7)
#define ROM_ENTRY_LOCAL_DATA_ADDR (ROM_ENTRY_INITIAL_CODE_ADDR+1)

struct rom_entry_data_s {
    char game_title[20];	/* ゲームタイトル */
    char reserve_area[7];	/* 予備エリア */
    char initial_code[4];	/* イニシャルコード */
    char maskrom_version;	/* マスクＲＯＭバージョン */
};

union rom_locale_data_u {
    u32  u32;
    u8   u8[4];	/* イニシャルコード（後ろ３桁）+ マスクＲＯＭバージョン */
};

extern z_locale_mode_e z_locale_mode = Z_LOCALE_MODE_UNKNOWN;

extern void
z_locale_init(void)
{
    union rom_locale_data_u locale_data;
    
    osEPiReadIo(carthandle, ROM_ENTRY_LOCAL_DATA_ADDR, (u32 *)&locale_data);
    dump(&locale_data, sizeof(locale_data));
#if 0
    switch (locale_data.u8[2]) {
#if defined(GATEWAY_VERSION)
    case 'G':			/* GATEWAY NTSC */
	z_locale_mode = Z_LOCALE_MODE_USA;
	break;
    case 'L':			/* GATEWAY PAL */
	z_locale_mode = Z_LOCALE_MODE_PAL; /* FRANCE or GERMAN */
	break;
#else  /* defined(GATEWAY_VERSION) */
    case 'J':
	z_locale_mode = Z_LOCALE_MODE_JAPAN;
	break;
    case 'E':
	z_locale_mode = Z_LOCALE_MODE_USA;
	break;
    case 'P':
	z_locale_mode = Z_LOCALE_MODE_PAL; /* FRANCE or GERMAN */
	break;
#endif /* defined(GATEWAY_VERSION) */
    default:
	COLOR_ERROR();
	PRINTF("z_locale_init: 日本用かアメリカ用か判別できません\n");
	HungUp();
	COLOR_NORMAL();
    }
#endif
    z_locale_mode = Z_LOCALE_MODE_USA;
#ifndef ROM_F
    PRINTF("z_locale_init:日本用かアメリカ用か３コンで判断させる\n");
#endif
}

extern void
z_locale_cleanup(void)
{
    z_locale_mode = Z_LOCALE_MODE_UNKNOWN;
}

#ifndef ROM_F
extern int
z_locale_IsJapan(void)
{
    if (z_locale_mode == Z_LOCALE_MODE_PAL)
	return 0;

#if 1				/* 木村さんの要望で判定ルーチンを殺します→復活 */
    if ( (padmgr_GetPadPattern(&padmgr) & 0x4) ) {
	//PRINTF("z_locale_IsJapan: ３コン挿さっているので、アメリカ用とします\n");
	return 0;
    } else {
	//PRINTF("z_locale_IsJapan: ３コン挿さってないので、日本用とします\n");
	return 1;
    }
#else
    return 1;
#endif
#if 0
    assert(z_locale_mode != Z_LOCALE_MODE_UNKNOWN);
    return (z_locale_mode == Z_LOCALE_MODE_JAPAN);
#endif
}

extern int
z_locale_IsUSA(void)
{
    if (z_locale_mode == Z_LOCALE_MODE_PAL)
	return 0;
    
#if 1				/* 木村さんの要望で判定ルーチンを殺します→復活 */
    if ( (padmgr_GetPadPattern(&padmgr) & 0x4) ) {
	//PRINTF("z_locale_IsUSA: ３コン挿さっているので、アメリカ用とします\n");
	return 1;
    } else {
	//PRINTF("z_locale_IsUSA: ３コン挿さってないので、日本用とします\n");
	return 0;
    }
#else
    return 0;
#endif
#if 0
    assert(z_locale_mode != Z_LOCALE_MODE_UNKNOWN);
    return (z_locale_mode == Z_LOCALE_MODE_USA);
#endif
}

extern int
z_locale_IsPAL(void)
{
    return (z_locale_mode == Z_LOCALE_MODE_PAL);
}
#endif
