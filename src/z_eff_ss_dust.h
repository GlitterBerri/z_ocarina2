/* $Id: z_eff_ss_dust.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/*-----------------------------------------------------------------------------
 *
 * 煙/ソフトスプライト エフェクト
 * z_eff_ss_dust.h
 *
 * Program:Kenji Matsutani
 *
 * $Log: z_eff_ss_dust.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.12  1998/09/18 07:09:38  umemiya
 * フォグオフ煙追加
 *
 * Revision 1.11  1998-09-01 00:20:12+09  matutani
 * *** empty log message ***
 *
 * Revision 1.10  1998-08-05 20:24:16+09  matutani
 * オーバーレイ化
 *
 * Revision 1.9  1998-06-18 14:35:59+09  matutani
 * ある位置を中心として,２０個の砂煙が広がる(XZ方向)
 *
 * Revision 1.8  1998-05-26 11:27:21+09  matutani
 * DREG減らし
 *
 * Revision 1.7  1998-03-18 19:50:33+09  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.6  1997/08/22  07:48:39  matutani
 *  Effect_SS_Dust_sc_co_ct()追加
 *
 * Revision 1.5  1997/07/30  12:54:02  umemiya
 * カウンター指定バージョン追加
 *
 * Revision 1.4  1997/06/25  06:51:42  matutani
 * スケール設定
 *
 * Revision 1.3  1997/04/14  08:05:41  matutani
 * 拡大追加（レジスター操作込み）
 *
 * Revision 1.2  1997/04/01  13:22:11  matutani
 * 色指定バージョン追加
 *
 * Revision 1.1  1997/03/28  12:15:09  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EFF_SS_DUST_H
#define INCLUDE_Z_EFF_SS_DUST_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif  

#include"z_basic.h"
#include"z_effect_soft_sprite_type.h"
#include"z_effect_soft_sprite_old_init.h"

#define DUST_DISP_FRAME 10
#define DUST_SCALE_DIFF 5

#define EFF_SS_DUST_STATUS_LIGHT_DEFAULT 0
#define EFF_SS_DUST_STATUS_LIGHT_ON (1<<0)
#define EFF_SS_DUST_STATUS_FOG_OFF (1<<1)
#define EFF_SS_DUST_RND_COLOR_SET  (1<<2)

/*============================================================================
 *
 * データセット構造体
 *
 *===========================================================================*/
typedef struct eff_ss2_dust_data {
    xyz_t pos;
    xyz_t vec;
    xyz_t acc;
    rgba_t prim;
    rgba_t env;
    short scale100;
    short scale_diff;
    short counter;

    /* status ビット */
    unsigned short status;

    /*
     * 初期セット:処理関数
     * 0 = Effect_SS2_Dust_func_proc
     * 1 = Effect_SS2_Dust_func_proc2
     */
    unsigned char mode_sw;
} EffSSDustData;

/*=============================================================================
 *
 * エフェクトプロフィール
 *
 *===========================================================================*/
extern EffectSSProfile Effect_Ss_Dust_Profile;

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif

/*** z_eff_ss_dust.h end ***/
