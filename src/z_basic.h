/*
 * $Id: z_basic.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $
 *
 * ゼルダ６４基本ヘッダファイル
 *
 * $Log: z_basic.h,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.18  1998/04/30 12:35:27  hayakawa
 * z_moji.hはずした
 *
 * Revision 1.17  1998-03-19 19:32:04+09  sakakibara
 * *** empty log message ***
 *
 * Revision 1.16  1997/11/06  05:50:18  hayakawa
 * sys_lib.h削除
 * z_vibctl.h追加
 *
 * Revision 1.15  1997/04/15  00:15:45  hayakawa
 * NewDelete.h追加
 *
 * Revision 1.14  1997/03/21  09:18:14  hayakawa
 * z_displib.hが２回インクルードされていた
 *
 * Revision 1.13  1997/03/19  13:48:01  hayakawa
 * sys_cfb.h→sys_screen.h
 *
 * Revision 1.12  1996/12/24  06:41:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1996/12/24  06:23:12  iwawaki
 * z_debug_display.h追加
 *
 * Revision 1.10  1996/11/22  06:29:49  hayakawa
 * debug.hを追加
 *
 * Revision 1.9  1996/11/20  01:24:58  hayakawa
 * limits.hの追加
 *
 * Revision 1.8  1996/11/20  00:52:46  hayakawa
 * u64types.h,macro.hをu64basic.hに移した
 *
 * Revision 1.7  1996/11/04  09:10:47  hayakawa
 * sys_cfb.hを追加（あとで消すかも）
 *
 * Revision 1.6  1996/10/28  04:32:27  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1996/09/28  11:11:54  iwawaki
 * z_skelanime.h追加
 *
 * Revision 1.4  1996/09/20  10:34:09  iwawaki
 * z_view.hを追加
 *
 * Revision 1.3  1996/09/18  09:05:44  iwawaki
 * $Log追加
 */

#ifndef __Z_BASIC_H_
#define __Z_BASIC_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "u64basic.h"
#include "debug.h"		/* PRINTF,disp */
#include "limits.h"
#include "malloc.h"		/* malloc,free,calloc,realloc */
//#include "uty.h"
#include "NewDelete.h"		/* New,Delete,NewA,DeleteA */
#include "game.h"
#include "graph.h"
#include "z_types.h"
//#include "sys_lib.h"
#include "sys_math.h"
#include "sys_matrix.h"
#include "sys_skeleton.h"
#include "sys_math3d.h"
#include "z_lib.h"
#include "z_lights.h"
#include "z_view.h"
#include "z_displib.h"
#include "z_skelanime.h"
//#include "z_moji.h"
#include "z_rcp.h"
#include "z_pause.h"
#include "z_debug.h"		/* xREG() */
#include "z_vibctl.h"		/* 振動パック */
#include "sys_screen.h"		/* ScreenWidth, ScreenHeight */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_BASIC_H_ */
