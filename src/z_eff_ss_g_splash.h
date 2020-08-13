/* $Id: z_eff_ss_g_splash.h,v 1.1.1.1 2003/03/10 22:42:53 tong Exp $ */
/* $Log: z_eff_ss_g_splash.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:53  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1998/08/18 10:51:23  umemiya
 * 水しぶきの色を設定できるよう変更
 *
 * Revision 1.6  1998-08-05 19:53:45+09  matutani
 * オーバーレイ化
 *
 * Revision 1.5  1998-04-09 14:24:00+09  umemiya
 * スケール設定できるよう変更
 *
 * Revision 1.4  1998/03/18  10:48:58  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.3  1997/08/22  00:42:16  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.2  1997/08/08  08:05:12  sumiyosi
 * *** empty log message ***
 *
 */
/*-----------------------------------------------------------------------------
 *
 * z_eff_ss_g_splash.h
 * 水しぶき
 * Program:N.Suiyosi
 * 1997/8/7
 *
 *---------------------------------------------------------------------------*/
#ifndef INCLUDE_Z_EFF_SS_G_SPLASH_H
#define INCLUDE_Z_EFF_SS_G_SPLASH_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif    

#include"z_basic.h" 
#include"z_effect_soft_sprite_type.h"
#include"z_effect_soft_sprite_old_init.h"

/*=======================================================================
 *
 * 初期セット用データ構造体
 *
 *=======================================================================*/
typedef struct {
    xyz_t pos;
    unsigned char no;
    unsigned char set_cl;
    short scale;
    rgba_t prim;
    rgba_t env;
} EffSSGSplashData;

/*============================================================================
 *
 * エフェクトプロフィール
 *
 *==========================================================================*/
extern EffectSSProfile Effect_Ss_G_Splash_Profile;
 
#define	EFF_G_SPLASH_1	0	/* 水しぶき	*/
#define	EFF_G_SPLASH_2	1	/* 水しぶき２	*/

#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif
    
/*** z_eff_ss_g_splash.h  end ***/
