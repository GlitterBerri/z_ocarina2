/*
 * $Id: z_vibctl2.h,v 2.1 1998/10/22 11:51:48 zelda Exp $
 *
 * ゼルダもだえ石制御（マルチバージョン）
 *
 * $Log: z_vibctl2.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.5  1998/10/01 04:21:35  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-09-18 18:50:42+09  sasaki
 * ゼルダもだえ石ステージ使用強制禁止
 *
 * Revision 1.3  1998/09/18 02:28:30  zelda
 * RUMBLE_ENTRY2_TYPE_A,B,C追加
 *
 * Revision 1.2  1998-09-18 10:21:27+09  zelda
 * マクロの引数修正
 * コメント増強
 *
 * Revision 1.1  1998-09-17 22:26:56+09  zelda
 * Initial revision
 *
 */

#ifndef __Z_VIBCTL2_H_
#define __Z_VIBCTL2_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "sys_vibctl2.h"			/* VibCtl */

/*
 *	MAX_VIB_DISTANCE とは、振動する限界距離
 */
#define		MAX_VIB_DISTANCE	(1000)

/*
 *	ゼルダもだえ石ゲームフレーム処理
 *	強制振動にデータをセット
 */
extern void
z_vibctl2_vib_force_set(
    float	 	,
    unsigned char	,
    unsigned char	,
    unsigned char	
    );
/*
 * 振動パックを強制振動させるパラメータをセットします
 * １コン専用
 * p:振動パワー(0-255)
 * t:持続フレーム(0-255)
 * s:減衰パワー(0-255)
 * d:距離(0.0f - 1000.0f*1000.0f 以上は無視)
 */
#define RUMBLE_ENTRY_FORCE2(p, t, s, d) z_vibctl2_vib_force_set(d, p, t, s)

/*
 *	ゼルダもだえ石ゲームフレーム処理
 *	振動ＱＵＥＵＥにデータをセット
 */
extern void
z_vibctl2_vib_setQ(
    float	 	,
    unsigned char	,
    unsigned char	,
    unsigned char	
    );

/*
 * 振動パックを振動させるパラメータをセットします
 * c:コントローラ番号(0-3) 注：無視されます
 * p:振動パワー(0-255)
 * t:持続フレーム(0-255)
 * s:減衰パワー(0-255)
 * d:距離(0.0f - 1000.0f*1000.0f 以上は無視)
 */
#define RUMBLE_ENTRY2_N(c, p, t, s, d) 	((void)(c), z_vibctl2_vib_setQ(d, p, t, s))

/*
 * １コン専用という点を除いて RUMBLE_ENTRY2_N と同じです
 * p:振動パワー(0-255)
 * t:持続フレーム(0-255)
 * s:減衰パワー(0-255)
 * d:距離(0.0f - 1000.0f*1000.0f 以上は無視)
 */
#define RUMBLE_ENTRY2(p, t, s, d) 	RUMBLE_ENTRY2_N(0, p, t, s, d)

/*
 * 簡単設定マクロ ＡＢＣ
 * d:距離(0.0f - 1000.0f*1000.0f 以上は無視)
 */
#define RUMBLE_ENTRY2_TYPE_A(d) 	RUMBLE_ENTRY2(255, 20, 150, d)
#define RUMBLE_ENTRY2_TYPE_B(d) 	RUMBLE_ENTRY2(180, 20, 100, d)
#define RUMBLE_ENTRY2_TYPE_C(d) 	RUMBLE_ENTRY2(120, 20, 10, d)

/*
 * ゲームフレーム毎にゲームスレッドから呼ばれる
 */
extern void
z_vibctl2_move(void);

/*
 * ゼルダもだえ石初期化
 */
extern void
z_vibctl2_init(void);

/*
 * ゼルダもだえ石後始末
 */
extern void
z_vibctl2_cleanup(void);
    
/*
 * ゼルダもだえ石存在確認
 * 0==なし
 * 0!=あり
 */
extern int
z_vibctl2_RumblePackIsConnected(void);

/*
 * ゼルダもだえ石ステージ毎初期化
 */
extern void
z_vibctl2_StageInit(void);

/*
 * ゼルダもだえ石ステージ使用強制禁止
 */
extern void
z_vibctl2_StageCancel(void);

/*
 * ゼルダもだえ石振動許可フラグ設定
 * flag == 0 振動許可
 * flag != 0 振動不許可
 */
extern void
z_vibctl2_pause(int flag);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_VIBCTL2_H_ */
