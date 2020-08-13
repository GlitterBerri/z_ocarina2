/*
 * $Id: u64basic.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * ６４用基本ヘッダ（ゲームの種類に依存しない）
 *
 * $Log: u64basic.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.1  1997/08/06 08:01:03  hayakawa
 * Initial revision
 *
 * Revision 1.6  1997/03/14  00:28:18  hayakawa
 * sched.h math64.h を排除、個別にインクルードしよう！
 *
 * Revision 1.5  1996/11/20  00:49:40  hayakawa
 * u64types.h,math64.h,macro.hの追加
 * コメント入れた
 *
 * Revision 1.4  1996/09/21  02:02:47  hayakawa
 * コメントの追加
 */

#ifndef __U64BASIC_H_
#define __U64BASIC_H_

#include "ultra64.h"		/* ＳＧＩ基本ヘッダ */
#include "u64patch.h"		/* 不具合修正など */
#include "u64macro.h"		/* ６４関係のマクロ */
#include "u64types.h"		/* ６４関係の型 */
#include "ramrom.h"		/* ＳＧＩ基本ヘッダ */
#include "macro.h"		/* 一般的なマクロ */

#endif /* __U64BASIC_H_ */
