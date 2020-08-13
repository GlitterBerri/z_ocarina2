/*
 * $Id: u64newgbi.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * ６４ gbi.h 拡張マクロ
 *
 * $Log: u64newgbi.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.4  1999-08-06 21:18:10+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1999-08-03 15:59:20+09  hayakawa
 * gDPSetCDAD追加
 *
 * Revision 1.2  1999-07-26 17:26:44+09  hayakawa
 * G_RM_RA_XLU_SURF/G_RM_RA_CLD_SURFの追加
 *
 * Revision 1.1  1999-04-07 15:49:05+09  hayakawa
 * Initial revision
 *
 */

#ifndef __U64NEWGBI_H_
#define __U64NEWGBI_H_

#include "ultra64.h"

#define TEXRECT_FRAC 2		/* gSPTextureRectangle の 表示座標の小数桁数 */
#define TEXCOORD_FRAC 5		/* gSPTextureRectangle の s, t座標の小数桁数 */
#define DELTA_FRAC 10		/* gSPTextureRectangle の dsdx,dtdyの小数桁数 */

/*
 * 新しいコンバインモード
 */
/* テクスチャ表示用(アルファ無効) */
#define	G_CC_RGB		0, 0, 0, TEXEL0, 0, 0, 0, 1
#define	G_CC_RGB1		G_CC_RGB
/* テクスチャ表示(アルファ有効)G_CC_DECALRGBAと同じ */
#define	G_CC_RGBA		0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0
/* ライト×プリミティブカラー */
#define	G_CC_SHADE_PRIM		SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0
/* ライト×プリミティブカラー(アルファ値はPrimLODに設定しPrimAlpha=1とする) */
#define	G_CC_SHADE_PRIM_PLF	SHADE, 0, PRIMITIVE, 0, SHADE, 0, PRIM_LOD_FRAC, PRIMITIVE
/* テクスチャ×環境カラー */
#define	G_CC_MODULATEIA_ENV	TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0
#define	G_CC_MODULATERGBA_ENV	G_CC_MODULATEIA_ENV
/* プリミティブカラーと環境カラーの線形補完（係数はテクスチャカラー）  */    
#define	G_CC_BLENDPERGBA	PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT
/* テクスチャカラーとプリミティブカラーの線形補完（係数は環境カラー） */
#define	G_CC_BLENDPRGBA_ENV	PRIMITIVE, TEXEL0, ENVIRONMENT, TEXEL0, PRIMITIVE, TEXEL0, ENVIRONMENT, TEXEL0
/* テクスチャカラーとプリミティブカラーの線形補完（係数はプリミティブＬＯＤ） */
#define	G_CC_BLENDPRGBA_PLF	PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, TEXEL0
/* 色つきアルファテクスチャ */
#define G_CC_PRIMDECALA 	0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0
/* エッジがきれいなカラーテクスチャ（RGBA16とI4(A4)を結合するための）モード（２サイクルモードの１サイクル目） */
#define G_CC_MULTIBIT_ALPHA 	0, 0, 0, TEXEL0, 0, 0, 0, TEXEL1
/* G_CC_MULTIBIT_ALPHAをポリゴンに貼る */
#define G_CC_MODULATEIA_2TEX 	TEXEL0, 0, SHADE, 0, TEXEL1, 0, SHADE, 0

/*
 * G_CC_MODULATERGBA_PRIMの式を変化したもの
 * EnvColorを加えることで、α＝255を可能にするコンバインモード
 * 通常 EnvColor=(0,0,0,1) or (1,1,1,1) とするとよい。
 */
#define	G_CC_MODULATEIA_PRIM_ADDENV	TEXEL0, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, ENVIRONMENT
#define	G_CC_MODULATERGBA_PRIM_ADDENV	G_CC_MODULATEIA_PRIM_ADDENV
/*
 * BLENDPEDECALA のα式を変化したもの
 * PrimAlpha=255, EnvAlpha=1で、BLENDPEDECALAとほぼ同じになる。
 * α補完する場合は PrimAlpha = α１−α２ EnvAlpha = α２ とする
 * ただし、 α１≧α２ とならなければならない制限がある。
 */
#define	G_CC_BLENDPERGBA_ADDENV		PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, ENVIRONMENT

/* ニンジェン変換用につくった */
#define G_CC_MODULATEIA_SHADEPRIM TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0 /* ライトが当たって、プリミティブアルファを持つテクスチャ */
#define G_CC_MODULATERGBA_SHADEPRIM G_CC_MODULATEIA_SHADEPRIM
#define G_CC_SHADEPRIM_TRANSP	SHADE, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE /* ライトが当たらず、プリミティブアルファを持つポリゴン */
#define G_CC_SHADE_TRANSP	0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE /* 不要？ */

#define G_CC_REFLECT_SHADE	TEXEL0, 0, PRIMITIVE, SHADE, TEXEL0, 0, PRIMITIVE, 0 /* テスト:ノーマルライト＋鏡面光 */
#define G_CC_MORPH_2TEX		TEXEL1, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0 /* ２つのテクスチャのモーフィング */
#define G_CC_NOISE2 		NOISE, 0, COMBINED, 0, 0, 0, 0, COMBINED /* １サイクル目につくった色に対して、２サイクル目にノイズをかける */

/*
 * 新しいレンダーモード
 */

/*
 * コンバインアルファを使った加算モード
 * メモリカラー＋コンバインカラー×コンバインアルファ → メモリカラー
 * （２サイクルモードの１サイクル目）
 */
#define	RM_ADD_ALPHA(clk)						\
	IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1)
#define G_RM_ADD_ALPHA		RM_ADD_ALPHA(1)
#define G_RM_ADD_ALPHA2      	RM_ADD_ALPHA(2)

/*
 * メモリの色を掛け算する
 * メモリカラー＋メモリカラー×コンバインアルファ → メモリカラー
 * （２サイクルモードの１サイクル目）
 */
#define	RM_MUL(clk)							\
	IM_RD | CVG_DST_SAVE | FORCE_BL |  ZMODE_OPA | 			\
	GBL_c##clk(G_BL_CLR_MEM, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1)
#define	G_RM_MUL		RM_MUL(1)
#define	G_RM_MUL2		RM_MUL(2)

/* ADDやMULの時の２サイクル目 */
#define	G_RM_FOG_SHADE_A2	GBL_c2(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)
#define	G_RM_FOG_PRIM_A2	GBL_c2(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA)
#define	G_RM_PASS2		GBL_c2(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

/*
 * １サイクル不透明フォグモード
 * （未テスト）
 */
#define	RM_ZB_OPA_SURF_FOG(clk)					\
	Z_CMP | Z_UPD | CVG_DST_FULL | ALPHA_CVG_SEL |		\
	ZMODE_OPA |						\
	GBL_c##clk(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)
#define	G_RM_ZB_OPA_SURF_FOG	RM_ZB_OPA_SURF_FOG(1)
#define	G_RM_ZB_OPA_SURF_FOG2	RM_ZB_OPA_SURF_FOG(2)

/*
 * １サイクル不透明フォグモード
 * レデュースアンチエイリアス
 * （未テスト）
 */
#define	RM_RA_ZB_OPA_SURF_FOG(clk)				\
	AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP |			\
	ZMODE_OPA | ALPHA_CVG_SEL |				\
	GBL_c##clk(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)
#define	G_RM_RA_ZB_OPA_SURF_FOG	RM_RA_ZB_OPA_SURF_FOG(1)
#define	G_RM_RA_ZB_OPA_SURF_FOG2	RM_RA_ZB_OPA_SURF_FOG(2)

/* 半透明のデカル(半透明の影) */
#define	RM_ZB_CLD_DECAL(clk)					\
	Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_DEC |	\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_ZB_CLD_DECAL	RM_ZB_CLD_DECAL(1)
#define	G_RM_ZB_CLD_DECAL2	RM_ZB_CLD_DECAL(2)

/*
 * 透明部分のカバレッジに影響を与えず、
 * 不透明部分のカバレッジをフルにする。
 * 半透明部分のカバレッジに少し影響を与える。
 * (本当の半透明には向かない)
 */
#define	RM_AA_TEX_CVG(clk)					\
	AA_EN | IM_RD | CVG_DST_CLAMP | 	 		\
	ZMODE_OPA | CVG_X_ALPHA | 				\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_RM_AA_TEX_CVG    RM_AA_TEX_CVG(1)
#define G_RM_AA_TEX_CVG2   RM_AA_TEX_CVG(2)

#define	RM_AA_ZB_TEX_CVG(clk)					\
	AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | 	\
	ZMODE_OPA | CVG_X_ALPHA | 				\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define G_RM_AA_TEX_CVG    RM_AA_TEX_CVG(1)
#define G_RM_AA_TEX_CVG2   RM_AA_TEX_CVG(2)

/*
 * RAバージョンのG_RM_AA_TEX_EDGE
 */
#define	RM_RA_TEX_EDGE(clk)					\
	AA_EN | CVG_DST_CLAMP |					\
	CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE |	\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define	G_RM_RA_TEX_EDGE	RM_RA_TEX_EDGE(1)
#define	G_RM_RA_TEX_EDGE2	RM_RA_TEX_EDGE(2)
#define	RM_RA_TEX_EDGE_BL(clk)					\
	AA_EN | CVG_DST_CLAMP |					\
	CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE |	\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_BL, G_BL_1MA)
#define	G_RM_RA_TEX_EDGE_BL	RM_RA_TEX_EDGE_BL(1)
#define	G_RM_RA_TEX_EDGE_BL2	RM_RA_TEX_EDGE_BL(2)

/*
 * ヌキの部分を更新しないので少し速い。
 * 内部エッジの処理は正しく行われない。
 * テクスチャレクタングルに向く
 * 
 */
#define RM_CLD_TEX_EDGE(clk) 						\
	IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA |  			\
	AA_EN | CVG_X_ALPHA | TEX_EDGE | 				\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_CLD_TEX_EDGE(clk) 					\
	Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA | 		\
	AA_EN | CVG_X_ALPHA | TEX_EDGE |				\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define	G_RM_CLD_TEX_EDGE	RM_CLD_TEX_EDGE(1)
#define	G_RM_CLD_TEX_EDGE2	RM_CLD_TEX_EDGE(2)
#define	G_RM_ZB_CLD_TEX_EDGE	RM_ZB_CLD_TEX_EDGE(1)
#define	G_RM_ZB_CLD_TEX_EDGE2	RM_ZB_CLD_TEX_EDGE(2)

#define RM_XLU_TEX_EDGE(clk) 						\
	IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_OPA |  			\
	AA_EN | CVG_X_ALPHA | TEX_EDGE | 				\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_XLU_TEX_EDGE(clk) 					\
	Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_OPA | 		\
	AA_EN | CVG_X_ALPHA | TEX_EDGE |				\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define	G_RM_XLU_TEX_EDGE	RM_XLU_TEX_EDGE(1)
#define	G_RM_XLU_TEX_EDGE2	RM_XLU_TEX_EDGE(2)
#define	G_RM_ZB_XLU_TEX_EDGE	RM_ZB_XLU_TEX_EDGE(1)
#define	G_RM_ZB_XLU_TEX_EDGE2	RM_ZB_XLU_TEX_EDGE(2)

/*
 * Ｚ値を更新する半透明
 */
#define	RM_AA_ZU_XLU_SURF(clk)					\
	AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_WRAP | CLR_ON_CVG |	\
	FORCE_BL | ZMODE_XLU |					\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_AA_ZU_XLU_SURF	RM_AA_ZU_XLU_SURF(1)
#define	G_RM_AA_ZU_XLU_SURF2	RM_AA_ZU_XLU_SURF(2)

/*
 * Ｚ値を更新する半透明
 * (梅宮スペシャル)
 */
#define	RM_ZU_XLU_SURF(clk)					\
	Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | 			\
	FORCE_BL | ZMODE_XLU |					\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_ZU_XLU_SURF	RM_ZU_XLU_SURF(1)
#define	G_RM_ZU_XLU_SURF2	RM_ZU_XLU_SURF(2)

/*
 * Ｚ値を比較無しで更新する不透明
 * ゼルダ用？（吉田スペシャル）
 */
#define	RM_AA_ZO_OPA_SURF(clk)					\
	AA_EN | IM_RD | CVG_DST_CLAMP |				\
	Z_UPD | ZMODE_OPA | ALPHA_CVG_SEL |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define	G_RM_AA_ZO_OPA_SURF	RM_AA_ZO_OPA_SURF(1)
#define	G_RM_AA_ZO_OPA_SURF2	RM_AA_ZO_OPA_SURF(2)

#define	RM_ZO_OPA_SURF(clk)					\
	CVG_DST_FULL |						\
	Z_UPD | ZMODE_OPA | ALPHA_CVG_SEL |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)
#define	G_RM_ZO_OPA_SURF	RM_ZO_OPA_SURF(1)
#define	G_RM_ZO_OPA_SURF2	RM_ZO_OPA_SURF(2)

/*
 * Ｚ値を比較無しで更新する半透明
 * ゼルダ（マーケット）で使用
 */
#define	RM_AA_ZO_XLU_SURF(clk)					\
	AA_EN | CVG_DST_WRAP | CLR_ON_CVG |			\
	Z_UPD | IM_RD | FORCE_BL | ZMODE_OPA |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_AA_ZO_XLU_SURF	RM_AA_ZO_XLU_SURF(1)
#define	G_RM_AA_ZO_XLU_SURF2	RM_AA_ZO_XLU_SURF(2)

#define	RM_ZO_XLU_SURF(clk)					\
	CVG_DST_FULL | 						\
	Z_UPD | IM_RD | FORCE_BL | ZMODE_OPA |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_ZO_XLU_SURF	RM_ZO_XLU_SURF(1)
#define	G_RM_ZO_XLU_SURF2	RM_ZO_XLU_SURF(2)

/*
 * Ｚ値を比較無しで更新する半透明
 * ゼルダ（虫眼鏡）で使用
 * アルファコンペアをスレッショルドにして形状を制御できます
 */
#define	RM_ZO_CLD_SURF(clk)					\
	CVG_DST_SAVE |						\
	Z_UPD | IM_RD | FORCE_BL | ZMODE_OPA |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_ZO_CLD_SURF	RM_ZO_CLD_SURF(1)
#define	G_RM_ZO_CLD_SURF2	RM_ZO_CLD_SURF(2)

/*
 * Ｚ値を比較無しで更新する完全透明
 * ゼルダ（虫眼鏡）で使用
 * アルファコンペアをスレッショルドにして形状を制御できます
 */
#define	RM_ZO_CLR_SURF(clk)					\
	CVG_DST_SAVE |						\
	Z_UPD | IM_RD | FORCE_BL | ZMODE_OPA |			\
	GBL_c##clk(G_BL_CLR_BL, G_BL_0, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_ZO_CLR_SURF	RM_ZO_CLR_SURF(1)
#define	G_RM_ZO_CLR_SURF2	RM_ZO_CLR_SURF(2)

/*
 * Ｚ値を無条件更新する
 * フォグレジスタで色をつけることもできる
 * アルファコンペアをスレッショルドにして形状を制御する
 */
#define	RM_ZO_FOG_SURF(clk)					\
	CVG_DST_SAVE |						\
	Z_UPD | IM_RD | FORCE_BL | ZMODE_OPA |			\
	GBL_c##clk(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_ZO_FOG_SURF	RM_ZO_FOG_SURF(1)
#define	G_RM_ZO_FOG_SURF2	RM_ZO_FOG_SURF(2)

/* 半透明の影 */
#define	G_RM_ZB_SHADOW 		G_RM_ZB_CLD_DECAL
#define	G_RM_ZB_SHADOW2 	G_RM_ZB_CLD_DECAL2

/*
 * エッジの綺麗な半透明ポリゴン
 * エッジが浮き出てしまうので独立三角形用です。
 * XLUはカバレッジをフルにし CLDはカバレッジを保存します
 */
#define RM_RA_XLU_SURF(clk)					\
	IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_OPA |  		\
	AA_EN | CVG_X_ALPHA | ALPHA_CVG_SEL |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_RA_XLU_SURF	RM_RA_XLU_SURF(1)
#define	G_RM_RA_XLU_SURF2	RM_RA_XLU_SURF(2)

#define RM_RA_CLD_SURF(clk)					\
	IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA |  		\
	AA_EN | CVG_X_ALPHA | ALPHA_CVG_SEL |			\
	GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
#define	G_RM_RA_CLD_SURF	RM_RA_CLD_SURF(1)
#define	G_RM_RA_CLD_SURF2	RM_RA_CLD_SURF(2)

/*
 * ＤＰのOtherModeを直接設定する。
 * 注意）ＳＰのキャッシュも同時に設定される。
 * ＳＰのOtherModeを直接設定する
 * 注意）同時にＤＰのOtherModeも設定される
 * 開発３部マイクロコードは 32bit 設定可能になるはず。
 * F3DEX2マイクロコードの場合はGfxの数が変化するので注意
 */
#ifdef  F3DEX_GBI_2
#define	gDPSetOtherModeHL(pkt, high, low) 				\
	gDPSetOtherMode(pkt, high, low)
#define	gsDPSetOtherModeHL(high, low) 					\
	gsDPSetOtherMode(high, low)
#else  /* !F3DEX_GBI_2 */
#define gsDPSetOtherModeHL(high, low) 					\
	gsSPSetOtherMode(G_SETOTHERMODE_H, 0, 24, high), 		\
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 3, low), 			\
	gsSPSetOtherMode(G_SETOTHERMODE_L, 3, 29, low)
#define gDPSetOtherModeHL(pkt, high, low) 				\
do {									\
	gSPSetOtherMode(pkt, G_SETOTHERMODE_H, 0, 24, high); 		\
	gSPSetOtherMode(pkt, G_SETOTHERMODE_L, 0, 3, low); 		\
	gSPSetOtherMode(pkt, G_SETOTHERMODE_L, 3, 29, low);		\
} while (0)
#endif /* !F3DEX_GBI_2 */

/*
 * gSPSetADCDCKTCTFTTTLTDTP (エキスパートユーザ用)
 *
 * このコマンドはたくさんの othermode パラメータを設定します.
 * 
 * [Usage]
 *	gSPSetADCDCKTCTFTTTLTDTP(pkt, modeA)
 *
 *      'modeA' is described all parameters of GroupA GBI command.
 *              exclude gDPPipelineMode, gDPSetCycleType.
 *
 *	GroupA:
 *	  gDPSetTexturePersp,
 *	  gDPSetTextureDetail, gDPSetTextureLOD, gDPSetTextureLUT,
 *	  gDPSetTextureFilter, gDPSetTextureConvert, gDPSetCombineKey,
 *	  gDPSetColorDither, gDPSetAlphaDither
 *
 *	Use 'OR' operation to get modeA.
 *
 *	modeA = G_TP_* | G_TD_* | G_TL_* | G_TT_* | G_TF_*
 *		G_TC_* | G_CK_*  | G_CD_* | G_AD_*;
 */

#define	gDPSetTPTDTLTTTFTCCKCDAD(pkt, mode)	\
	gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, G_MDSFT_CYCLETYPE - G_MDSFT_ALPHADITHER, mode)
#define	gsDPSetTPTDTLTTTFTCCKCDAD(mode)		\
	gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, G_MDSFT_CYCLETYPE - G_MDSFT_ALPHADITHER, mode)

/* gSetColorDither & gSetAlphaDither */
#define	gDPSetCDAD(pkt, mode)	\
	gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2 + 2, mode)
#define	gsDPSetCDAD(mode)		\
	gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2 + 2, mode)

#define	gDPSetOtherModeH2(pkt, mode)		\
        gDPSetTPTDTLTTTFTCCKCDAD(pkt, mode)
#define	gsDPSetOtherModeH2(mode)		\
        gsDPSetTPTDTLTTTFTCCKCDAD(mode)

/*
 * EXマイクロコード用のgbiをSGIマイクロコードのgbiでエミュレートする
 */
#ifndef gSP2Triangles
#define gSP2Triangles(pkt, v00, v01, v02, flag0, v10, v11, v12, flag1)	\
do { gSP1Triangle(pkt, v00, v01, v02, flag0); \
     gSP1Triangle(pkt, v10, v11, v12, flag1); \
} while (0)
#endif
#ifndef gsSP2Triangles
#define gsSP2Triangles(v00, v01, v02, flag0, v10, v11, v12, flag1)	\
	gsSP1Triangle(v00, v01, v02, flag0), \
	gsSP1Triangle(v10, v11, v12, flag1)
#endif
#ifndef gSP1Quadrangle
#define gSP1Quadrangle(pkt, v0, v1, v2, v3, flag)			\
        gSP2Triangles(pkt, v1, v2, v3, 0, v1, v3, v0, 0)
#endif
#ifndef gsSP1Quadrangle
#define gsSP1Quadrangle(v0, v1, v2, v3, flag)				\
        gsSP2Triangles(v1, v2, v3, 0, v1, v3, v0, 0)
#endif

    
/*
 * 行列関連の便をはかる
 * 注意）gSPPushMatrix,gSPLoadIdentityはグローバル変数を参照するので注意
 */
#define	gSPMultMatrix(pkt, m, n)  					\
    	gSPMatrix(pkt, m, (n)|G_MTX_MUL)

#define	gsSPMultMatrix(m, n) 						\
    	gsSPMatrix(m, (n)|G_MTX_MUL)

#define	gSPLoadMatrix(pkt, m, n)  					\
    	gSPMatrix(pkt, m, (n)|G_MTX_LOAD)

#define	gsSPLoadMatrix(m, n) 						\
    	gsSPMatrix(m, (n)|G_MTX_LOAD)

#ifdef USE_IDENTITYMTX
#include "identitymtx.h"	/* extern Mtx2 IdentityMtx; */
#define	gSPPushMatrix(pkt, n)     					\
    	gSPMatrix(pkt, (IdentityMtx.m), (n)|G_MTX_MUL|G_MTX_PUSH)

#define	gsSPPushMatrix(n)    						\
    	gsSPMatrix((IdentityMtx.m), (n)|G_MTX_MUL|G_MTX_PUSH)

#define	gSPLoadIdentity(pkt, n)   					\
    	gSPMatrix(pkt, (IdentityMtx.m), (n)|G_MTX_LOAD)

#define	gsSPLoadIdentity(n)  						\
    	gsSPMatrix((IdentityMtx.m), (n)|G_MTX_LOAD)
#endif /* USE_IDENTITYMTX */
    
/*
 * 色をパック形式で設定する（高速です）
 */
#define	gDPSetEnvColor_rgba8888(pkt, rgba8888)				\
            gDPSetColor(pkt, G_SETENVCOLOR, rgba8888)
#define	gDPSetBlendColor_rgba8888(pkt, rgba8888)			\
            gDPSetColor(pkt, G_SETBLENDCOLOR, rgba8888)
#define	gDPSetFogColor_rgba8888(pkt, rgba8888)				\
            gDPSetColor(pkt, G_SETFOGCOLOR, rgba8888)
#define	gDPSetPrimColor_rgba8888(pkt, m, l, rgba8888)			\
{									\
	Gfx *_g = (Gfx *)(pkt);						\
									\
	_g->words.w0 =	(_SHIFTL(G_SETPRIMCOLOR, 24, 8) | 		\
			 _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8));		\
	_g->words.w1 =  (unsigned int)(rgba8888);			\
}

/*
 * Vtx型の頂点データを設定するマクロ
 * makeVtx：全項目設定
 * makeVtxTC：頂点座標とテクスチャ座標のみ設定（例:テクスチャのみの表示）
 * makeVtxOB：頂点座標のみ設定（例:プリミティブカラーで表示）
 */
#define makeVtx(vtx, x, y, z, f, s, t, r, g, b, a) 			\
{									\
    Vtx *_v = (Vtx *)(vtx);						\
									\
    (_v)->v.ob[0] = (short)(x); 					\
    (_v)->v.ob[1] = (short)(y); 					\
    (_v)->v.ob[2] = (short)(z); 					\
    (_v)->v.flag  = (unsigned short)(f); 				\
    (_v)->v.tc[0] = (short)(s); 					\
    (_v)->v.tc[1] = (short)(t); 					\
    (_v)->v.cn[0] = (unsigned char)(r); 				\
    (_v)->v.cn[1] = (unsigned char)(g); 				\
    (_v)->v.cn[2] = (unsigned char)(b); 				\
    (_v)->v.cn[3] = (unsigned char)(a);					\
}

#define makeVtxTC(vtx, x, y, z, s, t) 					\
{									\
    Vtx *_v = (Vtx *)(vtx);						\
									\
    (_v)->v.ob[0] = (short)(x); 					\
    (_v)->v.ob[1] = (short)(y); 					\
    (_v)->v.ob[2] = (short)(z); 					\
    (_v)->v.tc[0] = (short)(s); 					\
    (_v)->v.tc[1] = (short)(t);					\
}
    
#define makeVtxOB(vtx, x, y, z) 					\
{									\
    Vtx *_v = (Vtx *)(vtx);						\
									\
    (_v)->v.ob[0] = (short)(x); 					\
    (_v)->v.ob[1] = (short)(y); 					\
    (_v)->v.ob[2] = (short)(z);						\
}

#endif /* __U64NEWGBI_H_ */
