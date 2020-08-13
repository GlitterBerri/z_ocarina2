/*
 * $Id: z_vibctl.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 *
 *	ゼルダ振動パック制御
 *
 * $Log: z_vibctl.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1998/09/18 01:21:35  zelda
 * マクロの引数修正
 *
 * Revision 1.6  1998-09-17 22:29:10+09  zelda
 * 自らの機能を停止し、マルチバージョンに依存するように変更
 *
 * Revision 1.5  1998-09-11 15:44:24+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.4  1998/08/22 10:44:33  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1998-07-17 20:44:05+09  hayakawa
 * 大幅修正
 *
 * Revision 1.2  1998-03-19 22:05:13+09  komatu
 * *** empty log message ***
 *
 * Revision 1.1  1997/11/06  05:25:43  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_VIBCTL_H_
#define __Z_VIBCTL_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#if 0

#include "sys_vibctl.h"			/* VibCtl */

/*
 * 振動パターンコードがパック形式で格納されます
 * ゲームフレーム毎に登録され、そのあと０にクリアされます。
 */
extern u32 sys_rumble_entry[4];

/*
 * 振動パックを振動させるパラメータをセットします
 * c:コントローラ番号(0-3)
 * p:振動パワー(0-255)
 * t:持続フレーム(0-255)
 * s:減衰パワー(0-255)
 */
#define RUMBLE_ENTRY_N(c, p, t, s) \
do { \
    sys_rumble_entry[c] = (((p) << 16) | ((t) << 8) | ((s) << 0)); \
} while (0)
    
/*
 * １コン専用という点を除いて RUMBLE_ENTRY_N と同じです
 * p:振動パワー(0-255)
 * t:持続フレーム(0-255)
 * s:減衰パワー(0-255)
 */
#define RUMBLE_ENTRY(p, t, s) RUMBLE_ENTRY_N(0, p, t, s)

/*
 * ゲームフレーム毎にゲームスレッドから呼ばれる
 */
extern void
z_vibctl_move(void);

/*
 * ゼルダもだえ石初期化
 */
extern void
z_vibctl_init(void);

/*
 * ゼルダもだえ石後始末
 */
extern void
z_vibctl_cleanup(void);
    
/*
 * ゼルダもだえ石存在確認
 * 0==なし
 * 0!=あり
 */
extern int
z_vibctl_RumblePackIsConnected(void);

/*
 * ゼルダもだえ石ステージ毎初期化
 */
extern void
z_vibctl_StageInit(void);

#else

#include "z_vibctl2.h"

#define RUMBLE_ENTRY_N(c, p, t, s) 	RUMBLE_ENTRY2_N(c, p, t, s, 0.0f)
#define RUMBLE_ENTRY(p, t, s) 		RUMBLE_ENTRY2(p, t, s, 0.0f)

#endif

/*
 * 旧バージョンでエラーにならないように一応定義します
 * 完全な互換性はありません
 * 使わないでください
 */
#define	VIB_ON(c, p, t, s) \
do { \
	int pp = (p), tt = (t), ss = (s); \
	RUMBLE_ENTRY_N(c, \
		       (pp > 100) ? 255 : pp * 255 / 100, \
		       (tt * 3 > 255) ? 255 : tt * 3, \
		       (ss > 100) ? 255 : ss * 255 / 100); \
} while (0)

#if 01				/* ヨッシーで使ってたマクロ  */
#define	VIB_A1(a) VIB_ON(0, a, 20, 9) /* 短振動 & 強減衰 */
#define	VIB_A2(a) VIB_ON(0, a, 20, 1) /* 短振動 & 弱減衰 */
#define	VIB_B1(a) VIB_ON(0, a, 50, 9) /* 長振動 & 強減衰 */
#define	VIB_B2(a) VIB_ON(0, a, 50, 1) /* 長振動 & 弱減衰 */
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_VIBCTL_H_ */
