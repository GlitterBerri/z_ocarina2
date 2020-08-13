/* $Id: z_effect_soft_sprite_label.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $ */
/*-----------------------------------------------------------------------------
 *
 * z_effect_soft_sprite_label.h
 *   
 * Program:Kenji Matsutnai
 *
 * ソフトスプライトエフェクトの列挙型のラベル
 *
 *$Log: z_effect_soft_sprite_label.h,v $
 *Revision 2.1  1998-10-22 21:13:45+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.39  1998/08/05 10:51:48  matutani
 *オーバーレイ化
 *
 *Revision 1.38  1998-06-16 22:49:06+09  matutani
 **** empty log message ***
 *
 *Revision 1.37  1998-06-16 14:16:57+09  umemiya
 *敵用 円柱型炎 効果 追加
 *
 *Revision 1.36  1998-06-03 11:31:56+09  kuzuhara
 *特殊効果の設定
 *
 *Revision 1.35  1998-05-02 22:52:28+09  tarukado
 **** empty log message ***
 *
 *Revision 1.34  1998/03/31 01:56:03  kuzuhara
 *射的場効果
 *
 * Revision 1.33  1998/03/25  07:33:15  kuzuhara
 * 射的場効果削除
 *
 * Revision 1.32  1998/03/25  05:01:12  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.31  1998/03/25  00:43:17  kuzuhara
 * 射的場効果
 *
 * Revision 1.30  1998/03/18  10:46:21  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.29  1998/02/27  03:32:56  morita
 * VB_HINOKO消した
 *
 * Revision 1.28  1998/02/26  10:30:44  morita
 * *** empty log message ***
 *
 * Revision 1.27  1998/02/21  10:53:52  sumiyosi
 * 結局、なにもかえてません。
 *
 * Revision 1.26  1998/02/04  10:43:03  sakakibara
 * パーティクルなかけら追加
 *
 * Revision 1.25  1998/02/03  01:25:31  kuzuhara
 * 城兵士サーチ玉作った原
 *
 * Revision 1.24  1998/02/02  11:47:21  morita
 * *** empty log message ***
 *
 * Revision 1.23  1998/01/12  13:33:11  morita
 * FHG_FLASH 追加
 *
 * Revision 1.22  1997/11/04  05:33:19  matutani
 * ヒットマークエフェクト追加
 *
 * Revision 1.21  1997/10/27  14:23:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1997/10/24  10:22:36  morita
 * *** empty log message ***
 *
 * Revision 1.19  1997/10/18  16:42:34  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/10/11  11:34:40  tarukado
 * *** empty log message ***
 *
 * Revision 1.17  1997/09/19  12:38:20  morita
 * ゴーマよう血しぶき追加
 *
 * Revision 1.16  1997/09/06  13:12:20  morita
 * *** empty log message ***
 *
 * Revision 1.15  1997/09/01  13:03:30  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.14  1997/08/27  05:35:10  sumiyosi
 * EFFECT_SS_TYPE_DUST2 を追加。
 *
 * Revision 1.13  1997/08/22  04:18:44  umemiya
 * EFFECT_SS_TYPE_DT_BUBBLE 追加
 *
 * Revision 1.12  1997/08/21  05:32:25  umemiya
 * EFFECT_SS_TYPE_LIGHTNING 追加
 *
 * Revision 1.11  1997/08/14  11:46:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1997/08/14  11:44:55  sumiyosi
 * 岩脇参上！！
 *
 * Revision 1.9  1997/08/07  11:07:19  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.8  1997/08/06  02:55:59  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.7  1997/08/05  05:25:52  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.6  1997/07/30  01:30:18  tarukado
 * *** empty log message ***
 *
 * Revision 1.5  1997/07/18  05:19:41  sumiyosi
 * *** empty log message ***
 * 
 * Revision 1.4  1997/07/08  05:57:32  tarukado
 * *** empty log message ***
 *
 * Revision 1.3  1997/07/02  12:02:03  tarukado
 * *** empty log message ***
 *
 * Revision 1.2  1997/07/01  05:07:30  tarukado
 * *** empty log message ***
 *
 * Revision 1.1  1997/04/14  01:15:57  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EFFECT_SOFT_SPRITE_LABEL_H
#define INCLUDE_Z_EFFECT_SOFT_SPRITE_LABEL_H
   
#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*============================================================================
 *
 * オーバーレイ対応
 *
 *==========================================================================*/
/*
 * ソフトスプライトの区別用ラベル
 * EFFECT_SS2_TYPE_LAST_LABELより前に追加してください。
 *
 * 多少内容が元とは変ります。
 *
 * マクロの展開結果
 * z_effect_soft_sprite_dlftbls.declに追加してください。
 *
 * efdecl0(Effect_Ss_Aa, EFFECT_SS_AA) -> _filler_EFFECT_SS_AA_NAME_filler
 * efdecl1(Effect_Ss_Bb, EFFECT_SS_BB) -> EFFECT_SS_BB_NAME
 *
 */
typedef enum {
    
#define efdecl0(name1, name2) _filler_EFFECT_SS2_TYPE_ ## name2 ## _filler,
#define efdecl1(name1, name2) name2 ##_NAME,
    
#include"z_effect_soft_sprite_dlftbls.decl"
    
#undef efdecl0
#undef efdecl1
    
    EFFECT_SS2_TYPE_LAST_LABEL
}  TYPE_EFFECT_SS2_LABEL;

#if 0

/*=============================================================================
 *
 * オーバーレイ非対応
 *
 *===========================================================================*/
       
/*
 * ソフトスプライトの区別用ラベル
 * EFFECT_SS_TYPE_LAST_LABELより前に追加してください。
 */
typedef enum {
    EFFECT_SS_TYPE_KIRAKIRA,
    EFFECT_SS_TYPE_BOMB,
    EFFECT_SS_TYPE_DUST,
    EFFECT_SS_TYPE_BOMB2,
    EFFECT_SS_TYPE_BLAST, 
    EFFECT_SS_TYPE_SPARK,
    EFFECT_SS_TYPE_DFIRE,
    EFFECT_SS_TYPE_BUBBLE,
    EFFECT_SS_TYPE_MAGIC,
#ifndef MATUTANI_OVL_TEST
    /* 使ってないので削除 */
    EFFECT_SS_TYPE_G_DDG_SMOKE,
#endif
    EFFECT_SS_TYPE_G_RIPPLE,
    EFFECT_SS_TYPE_G_SPLASH, 
    EFFECT_SS_TYPE_G_MAGMA,
    EFFECT_SS_TYPE_G_FIRE,
#if 0 
    /* どこで使ってんのかわからんので削除 */
    EFFECT_SS_TYPE_G_BUBBLE,
#endif 
    EFFECT_SS_TYPE_LIGHTNING, 
    EFFECT_SS_TYPE_DT_BUBBLE,
#ifndef MATUTANI_OVL_TEST
    /* どこで使ってんのかわからんので削除 */
    EFFECT_SS_TYPE_DUST2,
    EFFECT_SS_TYPE_DDJ_DUST,
#endif
    EFFECT_SS_TYPE_HAHEN,	/* ポリゴン破片 いまのところSSではないのだが.... */
    EFFECT_SS_TYPE_SIBUKI,	/* 複数表現用ボス血しぶき	*/ 
    EFFECT_SS_TYPE_SIBUKI2,	/* 一枚表現用ボス血しぶき	*/
    EFFECT_SS_TYPE_DB,		/* やられ汎用 炎		*/
    EFFECT_SS_TYPE_STICK,	/* 折れたデクの棒		*/
    EFFECT_SS_TYPE_MAGMA2,	/* Ddanボスベヤ溶岩		*/
    EFFECT_SS_TYPE_STONE1,	/* 光のつぶて			*/
    EFFECT_SS_TYPE_HITMARK,	/* ヒットマーク			*/
    EFFECT_SS_TYPE_FHG_FLASH,	/* ファントムガノンよう効果	*/
    EFFECT_SS_TYPE_K_FIRE,	/* 常駐火			*/
    EFFECT_SS_TYPE_SRCH_BALL,	/* 城兵士サーチ玉		*/
    EFFECT_SS_TYPE_KAKERA,	/* パーティクルなかけら		*/
#if 0
    /* ボス戦専用なのでボスファイルで制御 */  
    EFFECT_SS_TYPE_VB_HINOKO,	/* バルバジア面用火の粉		*/
#endif
    EFFECT_SS_TYPE_ICE_PIECE,
    EFFECT_SS_TYPE_FIRE_TAIL,
    EFFECT_SS_TYPE_EN_ICE,	/* 敵用 氷 効果			*/
    EFFECT_SS_TYPE_EXTRA,	/* いろいろ特殊効果		*/
    EFFECT_SS_TYPE_FIRE_CIRCLE,	/* 敵用 円柱型炎 効果 SSではない */
    
    EFFECT_SS_TYPE_LAST_LABEL
} TYPE_EFFECT_SS_LABEL;  

#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** z_effect_soft_sprite_label.h end ***/


    
