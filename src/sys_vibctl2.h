/*
 * $Id: sys_vibctl2.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 *	振動パック制御（マルチバージョン）
 *
 * $Log: sys_vibctl2.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1998/10/01 01:38:56  okajima
 * *** empty log message ***
 *
 * Revision 1.1  1998-09-17 22:27:39+09  zelda
 * Initial revision
 *
 */

#ifndef __SYS_VIBCTL2_H_
#define __SYS_VIBCTL2_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "os.h"			/* MAXCONTROLLERS */

/*
 * 振動パターンクラス
 * 269 bytes(MAXCONTROLLERS==4 && VIBQUEUE==64のばあい)
 *
 *	コントローラ １ のみに対応 (でも on_flg だけは、MAXCONTROLLERS 使用)
 */
/*
 *	VIBQUEUE とは、振動登録最大数
 */
#define		VIBQUEUE	(64)
typedef struct VibCtl2 {
    /*
     *	振動パック ＯＮ / ＯＦＦ を コントローラ に 伝える
     */
    u8 on_flg[MAXCONTROLLERS];

    /*
     *	振動パワー 変数(０ 〜 ２５５)
     */
    u8 power[VIBQUEUE];
    
    /*
     *	最初の一定振動パワー時間 変数(０ 〜 ２５５ フレーム)
     */
    u8 start_power[VIBQUEUE];
    
    /*
     *	減衰振動パワー 変数(０ 〜 ２５５)
     */
    u8 stop_power[VIBQUEUE];
    
    /*
     *	振動計算用
     */
    u8 power_time[VIBQUEUE];

    /*
     *	振動パック強制停止フラグ 変数(０:振動禁止 １:振動許可 ２:振動初期化)
     */
    u8 vib_flg;

    /*
     *	振動パック一時停止フラグ 変数(０:振動一時停止 １:振動)
     */
    u8 vib_pause;

    /*
     *	振動パック連続振動時間計測 変数
     */
    u16 vib_on_time;

    /*
     *	振動パック連続停止時間計測 変数
     */
    u16 vib_off_time;

    /*
     *	強制振動パワー 変数(０ 〜 ２５５)
     */
    u8 force_power;
    
    /*
     *	強制最初の一定振動パワー時間 変数(０ 〜 ２５５ フレーム)
     */
    u8 force_start_power;
    
    /*
     *	強制減衰振動パワー 変数(０ 〜 ２５５)
     */
    u8 force_stop_power;
    
    /*
     *	強制振動計算用
     */
    u8 force_power_time;
} VibCtl2;

/*======================================================================*
 *	振動パックコントロール関数					*
 *======================================================================*/
extern void vibctl2_init(VibCtl2 *);
extern void vibctl2_cleanup(VibCtl2 *);
extern void vibctl2_move(VibCtl2 *);
#define vibctl2_on_flg(vibctl2) ((vibctl2)->on_flg)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __SYS_VIBCTL2_H_ */
