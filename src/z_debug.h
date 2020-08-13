/*
 * $Id: z_debug.h,v 2.1 1998/10/22 11:45:49 zelda Exp $
 *
 * $Log: z_debug.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.41  1998/10/16 07:27:05  morita
 * *** empty log message ***
 *
 * Revision 1.40  1998-10-16 14:03:44+09  zelda
 * NS1削除
 * dREG追加
 *
 * Revision 1.39  1998-10-13 10:35:12+09  hayakawa
 * UREG使用できなくした
 *
 * Revision 1.38  1998-10-12 11:59:23+09  zelda
 * *** empty log message ***
 *
 * Revision 1.37  1998-10-10 13:26:52+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.36  1998-09-12 21:13:48+09  morita
 * 使用削除チェック
 *
 * Revision 1.35  1998-09-12 21:03:08+09  morita
 * *** empty log message ***
 *
 * Revision 1.34  1998-08-17 19:36:27+09  hayakawa
 * マクロ定義の基本を間違えていた
 *
 * Revision 1.33  1998-03-20 23:28:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.32  1998/03/18  03:03:13  ogawa
 * *** empty log message ***
 *
 * Revision 1.31  1998/03/09  12:38:36  hayakawa
 * z_debug_mode.hとの分離
 *
 * Revision 1.30  1998/02/20  08:56:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.29  1998/01/30  01:04:58  iwawaki
 * *** empty log message ***
 *
 * Revision 1.28  1998/01/05  12:13:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.27  1997/12/17  01:48:15  takahata
 * *** empty log message ***
 *
 * Revision 1.26  1997/10/19  12:31:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1997/09/24  00:25:40  hayakawa
 * 自立化
 *
 * Revision 1.24  1997/09/05  05:35:38  ogawa
 * *** empty log message ***
 *
 * Revision 1.23  1997/09/05  04:39:59  ogawa
 * *** empty log message ***
 *
 * Revision 1.22  1997/09/02  12:31:08  ogawa
 * Debug_Print2_output 追加
 *
 * Revision 1.21  1997/08/28  02:36:05  soejima
 * VREG追加
 *
 * Revision 1.20  1997/08/11  08:11:13  matutani
 * AREG追加
 *
 * Revision 1.19  1997/07/14  02:29:15  ogawa
 * *** empty log message ***
 *
 * Revision 1.18  1997/07/08  04:48:26  hayakawa
 * includeでエラーになるのを修正
 *
 * Revision 1.17  1997/07/01  09:39:56  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1997/06/26  09:46:05  soejima
 * WREG追加
 *
 * Revision 1.15  1997/06/09  01:25:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1997/06/06  00:48:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1997/04/17  07:19:52  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1997/03/18  07:21:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1997/03/17  09:39:13  iwawaki
 * 文字列表示追加
 *
 * Revision 1.10  1997/02/05  00:46:47  iwawaki
 * *** empty log message ***
 *
 * Revision 1.9  1997/02/05  00:30:54  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1996/10/28  07:19:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1996/10/28  06:26:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1996/10/28  05:04:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1996/10/08  05:40:54  iwawaki
 * 何回もインクルードされても大丈夫な様に変更
 *
 * Revision 1.4  1996/09/20  03:09:13  iwawaki
 * new_Debug_modeを引数変更
 *
 * Revision 1.3  1996/09/18  09:14:32  iwawaki
 * $Log追加
 * */

#ifndef INCLUDE_Z_DEBUG_H
#define INCLUDE_Z_DEBUG_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	デバッグモードクラス
 *
 ************************************************************************/

#define	DEBUG_KEYWAIT	16
#define	DEBUG_KEYWAIT_T	1

#define	DEBUG_TYPE_MAX	29

#define	DEBUG_REG_MAX	16
#define	DEBUG_REG_GRP	6

typedef struct {
    int		mode;
    int		type;
    int		input_r;
    int		old_key;
    int		key_wait;
    short	r[DEBUG_REG_MAX * (DEBUG_REG_GRP * DEBUG_TYPE_MAX)];
} Debug_mode;

extern Debug_mode	*debug_mode;	/* デバッグモードクラスポインター */

#define VOID_GETREG(g, n) ((void)(g), (void)(n), (short)0)
#define VOID_SETREG(g, n, v) ((void)(g), (void)(n), (void)(v))

#ifndef VOID_REG
#define GETREG(g, n) ((short)debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*(g))])
#define SETREG(g, n, v) (debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*(g))] = (v))
#else
#define GETREG(g, n) VOID_GETREG(g, n)
#define SETREG(g, n, v) VOID_SETREG(g, n, v)
#endif

#define	GETSREG(n)	GETREG(1, n)
#define	GETOREG(n)	GETREG(2, n)
#define	GETPREG(n)	GETREG(3, n)
#define	GETQREG(n)	GETREG(4, n)
#define	GETMREG(n)	GETREG(5, n)
#define	GETYREG(n)	GETREG(6, n)
#define	GETDREG(n)	GETREG(7, n)
#define	GETUREG(n)	GETREG(8, n)
#define	GETIREG(n)	GETREG(9, n)
#define	GETZREG(n)	GETREG(10, n)
#define	GETCRV(n)	GETREG(11, n)
#define	GETNS1(n)	GETREG(12, n)
#define	GETKAZ(n)	GETREG(13, n)
#define	GETXREG(n)	GETREG(14, n)
#define	GETCRV2(n)	GETREG(15, n)
#define	GETSEX(n)	GETREG(16, n)
#define	GETTREG(n)	GETREG(17, n)
#define	GETWREG(n)	GETREG(18, n)
#define	GETAREG(n)	GETREG(19, n)
#define	GETVREG(n)	GETREG(20, n)
#define	GETHREG(n)	GETREG(21, n)
#define	GETGREG(n)	GETREG(22, n)
#define	GETmREG(n)	GETREG(23, n)
#define	GETnREG(n)	GETREG(24, n)
#define	GETBREG(n)	GETREG(25, n)
#define	GETDORO(n)	GETREG(26, n)
#define	GETkREG(n)	GETREG(27, n)
#define	GETBAK(n)	GETREG(28, n)

#define	SETSREG(n, v)	SETREG(1, n, v)
#define	SETOREG(n, v)	SETREG(2, n, v)
#define	SETPREG(n, v)	SETREG(3, n, v)
#define	SETQREG(n, v)	SETREG(4, n, v)
#define	SETMREG(n, v)	SETREG(5, n, v)
#define	SETYREG(n, v)	SETREG(6, n, v)
#define	SETDREG(n, v)	SETREG(7, n, v)
#define	SETUREG(n, v)	SETREG(8, n, v)
#define	SETIREG(n, v)	SETREG(9, n, v)
#define	SETZREG(n, v)	SETREG(10, n, v)
#define	SETCRV(n, v)	SETREG(11, n, v)
#define	SETNS1(n, v)	SETREG(12, n, v)
#define	SETKAZ(n, v)	SETREG(13, n, v)
#define	SETXREG(n, v)	SETREG(14, n, v)
#define	SETCRV2(n, v)	SETREG(15, n, v)
#define	SETSEX(n, v)	SETREG(16, n, v)
#define	SETTREG(n, v)	SETREG(17, n, v)
#define	SETWREG(n, v)	SETREG(18, n, v)
#define	SETAREG(n, v)	SETREG(19, n, v)
#define	SETVREG(n, v)	SETREG(20, n, v)
#define	SETHREG(n, v)	SETREG(21, n, v)
#define	SETGREG(n, v)	SETREG(22, n, v)
#define	SETmREG(n, v)	SETREG(23, n, v)
#define	SETnREG(n, v)	SETREG(24, n, v)
#define	SETBREG(n, v)	SETREG(25, n, v)
#define	SETDORO(n, v)	SETREG(26, n, v)
#define	SETkREG(n, v)	SETREG(27, n, v)
#define	SETBAK(n, v)	SETREG(28, n, v)

#if 01
				/* ワーニング出さない */
#define	REG(n)		(debug_mode->r[n])
#define	SREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*1)])
#define	OREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*2)])
#define	PREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*3)])
#define	QREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*4)])
#define	MREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*5)])
#define	YREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*6)])
#define	DREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*7)])
#define	UREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*8)])
#define	IREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*9)])
#define	ZREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*10)])
#define	CRV(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*11)])
#define	NS1(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*12)])

#if 01 /* */
#define	KAZ(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*13)])
#define	SEX(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*16)])
#define	BREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*25)])
#define	GREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*22)])
#endif

#define	XREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*14)])
#define	CRV2(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*15)])
#define	TREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*17)])
#define	WREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*18)])
#define	AREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*19)])
#define	VREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*20)])
#define	HREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*21)])
#define	mREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*23)])
#define	nREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*24)])
#define	DORO(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*26)])
#define	kREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*27)])
#define	BAK(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*28)])

#else

				/* ワーニング出す */
#define	REG(n)		GETREG(0, n)
#define	SREG(n)		GETREG(1, n)
#define	OREG(n)		GETREG(2, n)
#define	PREG(n)		GETREG(3, n)
#define	QREG(n)		GETREG(4, n)
#define	MREG(n)		GETREG(5, n)
#define	YREG(n)		GETREG(6, n)
#define	DREG(n)		GETREG(7, n)
#define	UREG(n)		GETREG(8, n)
#define	IREG(n)		GETREG(9, n)
#define	ZREG(n)		GETREG(10, n)
#define	CRV(n)		GETREG(11, n)
#define	NS1(n)		GETREG(12, n)
#define	KAZ(n)		GETREG(13, n)
#define	XREG(n)		GETREG(14, n)
#define	CRV2(n)		GETREG(15, n)
#define	SEX(n)		GETREG(16, n)
#define	TREG(n)		GETREG(17, n)
#define	WREG(n)		GETREG(18, n)
#define	AREG(n)		GETREG(19, n)
#define	VREG(n)		GETREG(20, n)
#define	HREG(n)		GETREG(21, n)
#define	GREG(n)		GETREG(22, n)
#define	mREG(n)		GETREG(23, n)
#define	nREG(n)		GETREG(24, n)
#define	BREG(n)		GETREG(25, n)
#define	DORO(n)		GETREG(26, n)
#define	kREG(n)		GETREG(27, n)
#define	BAK(n)		GETREG(28, n)

#endif

/* 早川 */
#ifdef ROM_F
#undef  GETHREG
#undef  SETHREG
#undef  HREG
#define	GETHREG(n)	VOID_GETREG(21, n)
#define	SETHREG(n, v)	VOID_SETREG(21, n, v)
#define	HREG(n)		VOID_GETREG(21, n)
#endif /* ROM_F */

/* 梅宮 */
#undef  GETUREG
#undef  SETUREG
#undef  UREG

#if defined(ROM_D)
/* 共通 ROM_D 専用レジスタ */
#define	GETdREG(n)	GETREG(8, n)
#define	SETdREG(n, v)	SETREG(8, n, v)
#define	dREG(n)		(debug_mode->r[(n)+(DEBUG_REG_MAX*DEBUG_REG_GRP*8)])
#endif

/* 樽角 */
#undef  GETNS1
#undef  SETNS1
#undef  NS1

#include "z_debug_mode.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* INCLUDE_Z_DEBUG_H */
