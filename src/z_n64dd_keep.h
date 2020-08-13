/*
 * $Id: z_n64dd_keep.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 * ６４ＤＤインターフェース関数
 * 常駐部
 *
 * $Log: z_n64dd_keep.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1998/10/08 10:58:01  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1998-10-07 10:44:38+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.5  1998-10-03 13:52:09+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-09-24 23:08:57+09  hayakawa
 * n64dd_LoadDiskOverlay追加
 *
 * Revision 1.3  1998-09-22 14:20:55+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1998-09-17 15:33:35+09  hayakawa
 * n64dd_isDiskModeのレジスタ条件反転
 *
 * Revision 1.1  1998-09-15 21:44:40+09  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_N64DD_KEEP_H_
#define __Z_N64DD_KEEP_H_

#include "z_debug.h"		/* SREG */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*
 * グローバル変数宣言
 */
extern char _n64dd_isStay;	/* !0:６４ＤＤ非常駐部が存在する */
extern char _n64dd_isConnected;	/* !0:６４ＤＤが接続されている */
extern char _n64dd_isInitialized; /* !0:６４ＤＤ初期化済み */
extern volatile char _n64dd_isAvaliable; /* !0:６４ＤＤ使用可能(no busy) */
extern volatile char _n64dd_isSoundStopped; /* !0:サウンド止めている */
extern char _n64dd_isEnable;	/* ??? */

/*
 * n64dd_isStay()		!0:６４ＤＤ非常駐部が存在する
 * n64dd_isConnected()		!0:６４ＤＤが接続されている
 * n64dd_isInitialized()	!0:６４ＤＤ初期化済み
 */
#define n64dd_isStay() 		((void)0, _n64dd_isStay)
#define n64dd_isConnected() 	((void)0, _n64dd_isConnected)
#define n64dd_isInitialized() 	((void)0, _n64dd_isInitialized)

/*
 * n64ddセグメントロード
 */
extern void n64dd_LoadOverlay(void);
/*
 * n64ddセグメントアンロード
 */
extern void n64dd_UnloadOverlay(void);
/*
 * DISKからオーバーレイプログラムをロードする
 */
extern int n64dd_LoadDiskOverlay(void);
/*
 * ＲＯＭ／ディスクバージョンセット
 * ゲームデータロード直後に呼び出される
 */
extern void
n64dd_SetDiskVersion(
    int flag		/* 0:ROM VERSION !0:DISK VERSION */
    );

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_N64DD_KEEP_H_ */
