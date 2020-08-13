/*
 * $Id: z_types.h,v 2.1 1998/10/22 11:51:48 zelda Exp $
 * $Log: z_types.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.25  1998/09/19 04:57:41  hayakawa
 * z_define.hの補完
 *
 * Revision 1.24  1998-08-12 20:16:58+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.23  1998-07-09 22:04:36+09  hayakawa
 * OtherModeマクロ変更
 *
 * Revision 1.22  1998-05-29 11:43:37+09  hayakawa
 * パディングしたらいかんかった
 *
 * Revision 1.21  1998-05-29 10:38:43+09  hayakawa
 * s_xyz型にパディング用ダミー変数を追加
 *
 * Revision 1.20  1998-03-19 22:04:59+09  komatu
 * *** empty log message ***
 *
 * Revision 1.19  1998/03/07  14:24:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/04/05  06:37:22  iwawaki
 * ColorF追加
 *
 * Revision 1.17  1997/03/07  08:40:42  hayakawa
 * コメントアウトの削除
 *
 * Revision 1.16  1997/02/28  11:17:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.15  1997/02/13  11:42:30  hayakawa
 * ワーニング抑制
 *
 * Revision 1.14  1997/01/13  12:34:08  iwawaki
 * Gfx_Shape追加
 *
 * Revision 1.13  1996/12/24  00:18:53  iwawaki
 * Color構造体追加
 *
 * Revision 1.12  1996/11/20  01:34:04  hayakawa
 * XLU_TEX_EDGE復活
 *
 * Revision 1.11  1996/11/20  00:51:01  hayakawa
 * RmonPrintfを消した
 * G_ZBUFFER2を消した
 * limits.hにだぶっているマクロを消した
 *
 * Revision 1.10  1996/10/05  09:25:12  hayakawa
 * gSPSetOtherModeの不具合に対応
 *
 * Revision 1.9  1996/09/27  06:26:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1996/09/27  01:46:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1996/09/26  11:05:47  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1996/09/26  11:04:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1996/09/21  09:17:25  hayakawa
 * enum を変えた
 * 多重インクルードに対応
 *
 * Revision 1.4  1996/09/21  07:23:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1996/09/18  09:45:58  iwawaki
 * $Log追加
 * */

#ifndef __Z_TYPES_H_
#define __Z_TYPES_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "u64types.h"		/* xyz_t */

#define g_Nin_SetUpTileDescrip(displist,fmt,siz,width,height,tmem,tt,cs,ms,ss,ct,mt,st)	\
	gDPTileSync(displist);	\
	gDPSetTile(displist, fmt,siz,((((width)*siz##_LINE_BYTES)+7)>>3),tmem,tt,0,ct,mt,st,cs,ms,ss);	\
	gDPSetTileSize(displist, tt,0,0,(width-1)<<G_TEXTURE_IMAGE_FRAC,(height-1)<<G_TEXTURE_IMAGE_FRAC);

#define g_Nin_SetUpTileDescrip2(displist,fmt,siz,width,height,tmem,tt,cs,ms,ss,ct,mt,st,uls,urt)	\
	gDPTileSync(displist);	\
	gDPSetTile(displist, fmt,siz,((((width)*siz##_LINE_BYTES)+7)>>3),tmem,tt,0,ct,mt,st,cs,ms,ss);	\
	gDPSetTileSize(displist, tt,uls,urt,(width-1)<<G_TEXTURE_IMAGE_FRAC,(height-1)<<G_TEXTURE_IMAGE_FRAC);

#define g_Nin_LoadTextureImage(displist,timg,fmt,siz,width,height,tmem,tt)	\
	gDPSetTextureImage(displist, fmt,siz,1,timg);	\
	gDPTileSync(displist);	\
	gDPSetTile(displist, fmt,siz,0,tmem,tt,0,0,0,0,0,0,0);	\
	gDPLoadSync(displist);	\
	gDPLoadBlock(displist, tt,0,0,width*height-1,CALC_DXT(width,siz##_BYTES));

#define gs_Nin_SetUpTileDescrip(fmt,siz,width,height,tmem,tt,cs,ms,ss,ct,mt,st)	\
	gsDPTileSync(),	\
	gsDPSetTile(fmt,siz,((((width)*siz##_LINE_BYTES)+7)>>3),tmem,tt,0,ct,mt,st,cs,ms,ss),	\
	gsDPSetTileSize(tt,0,0,(width-1)<<G_TEXTURE_IMAGE_FRAC,(height-1)<<G_TEXTURE_IMAGE_FRAC)

#define gs_Nin_LoadTextureImage(timg,fmt,siz,width,height,tmem,tt)	\
	gsDPSetTextureImage(fmt,siz,1,timg),	\
	gsDPTileSync(),	\
	gsDPSetTile(fmt,siz,0,tmem,tt,0,0,0,0,0,0,0),	\
	gsDPLoadSync(),	\
	gsDPLoadBlock(tt,0,0,width*height-1,CALC_DXT(width,siz##_BYTES))

/*======================================================================*
 *									*
 *	ＲＣＰのモードセット						*
 *									*
 *======================================================================*/
/*
 *	cycle	<-- G_CYC_FILL, G_CYC_COPY, G_CYC_2CYCLE, G_CYC_1CYCLE
 *
 *	gmode	<-- G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE |
 *		    G_SHADING_SMOOTH | G_CULL_FRONT | G_CULL_BACK |
 *		    G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
 *		    G_TEXTURE_GEN_LINEAR | G_LOD
 *
 *	texture	<-- G_ON, G_OFF
 *
 *	a0, b0, c0, d0, a1, b1, c1, d1
 *		<-- G_CCMUX_COMBINED, G_CCMUX_TEXEL0, G_CCMUX_TEXEL1,
 *		    G_CCMUX_PRIMITIVE, G_CCMUX_SHADE, G_CCMUX_ENVIRONMENT,
 *		    G_CCMUX_CENTER, G_CCMUX_SCALE, G_CCMUX_COMBINED_ALPHA,
 *		    G_CCMUX_TEXEL0_ALPHA, G_CCMUX_TEXEL1_ALPHA,
 *		    G_CCMUX_PRIMITIVE_ALPHA, G_CCMUX_SHADE_ALPHA,
 *		    G_CCMUX_ENV_ALPHA, G_CCMUX_LOD_FRACTION,
 *		    G_CCMUX_PRIM_LOD_FRAC, G_CCMUX_NOISE, G_CCMUX_K4,
 *		    G_CCMUX_K5, G_CCMUX_1, G_CCMUX_0
 *
 *	Aa0, Ab0, Ac0, Ad0, Aa1, Ab1, Ac1, Ad1
 *		<-- G_ACMUX_COMBINED, G_ACMUX_TEXEL0, G_ACMUX_TEXEL1,
 *		    G_ACMUX_PRIMITIVE, G_ACMUX_SHADE, G_ACMUX_ENVIRONMENT,
 *		    G_ACMUX_LOD_FRACTION, G_ACMUX_PRIM_LOD_FRAC,
 *		    G_ACMUX_1, G_ACMUX_0
 *
 *	render1, render2
 *		<-- AA_EN | Z_CMP | Z_UPD | IM_RD | CLR_ON_CVG |
 *		    CVG_DST_CLAMP | CVG_DST_WRAP | CVG_DST_FULL |
 *		    CVG_DST_SAVE | ZMODE_OPA | ZMODE_INTER | ZMODE_XLU |
 *		    ZMODE_DEC | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL |
 *		    TEX_EDGE
 *
 *	m1a1, m1b1, m2a1, m2b1, m1a2, m1b2, m2a2, m2b2
 *		<-- G_BL_CLR_IN, G_BL_CLR_MEM, G_BL_CLR_BL, G_BL_CLR_FOG,
 *		    G_BL_1MA, G_BL_A_MEM, G_BL_A_IN, G_BL_A_FOG, G_BL_A_SHADE,
 *		    G_BL_1, G_BL_0,
 */
#define G_GM_ALL_CLEAR (G_ZBUFFER | /*G_SHADE | G_SHADING_SMOOTH |*/ G_CULL_BOTH | \
			G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD) 

/* gbi*4 */
#define gCPSetModeLERP(gfx, pm,ct,tp,td, tl, tt, tf, tc, ck, cd, ad, ac, zs, gm, ton, \
			a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0, a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1, rd1, rd2)  \
do {								\
    unsigned int	data_l, data_h;				\
								\
    data_l = ac | zs | rd1 | rd2;				\
    data_h = pm | ct | tp  | td | tl | tt | tf | tc | ck | cd | ad;	\
								\
								\
    gSPTexture(gfx, 0xffff, 0xffff, 0, 0, ton);			\
								\
    gDPSetCombineLERP(gfx, a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0,	\
			a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1);    \
								\
    gDPSetOtherModeHL(gfx, data_h, data_l);			\
    gSPLoadGeometryMode(gfx, gm);				\
								\
} while (0)
	
/* gbi*4 */
#define gsCPSetModeLERP(pm,ct,tp,td, tl, tt, tf, tc, ck, cd, ad, ac, zs, gm, ton, \
			a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0, a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1, rd1, rd2)  \
    gsSPTexture(0xffff, 0xffff, 0, 0, ton),			\
								\
    gsDPSetCombineLERP(a0, b0, c0, d0, Aa0, Ab0, Ac0, Ad0,	\
			a1, b1, c1, d1, Aa1, Ab1, Ac1, Ad1),    \
								\
    gsDPSetOtherModeHL(pm | ct | tp  | td | tl | tt | tf | tc | ck | cd | ad, ac | zs | rd1 | rd2),			\
    gsSPLoadGeometryMode(gm)

#define gCPSetMode(gfx, pm,ct,tp,td, tl, tt, tf, tc, ck, cd, ad, ac, zs,gm,ton, cc0, cc1, rd1, rd2)		\
	gCPSetModeLERP(						\
	    gfx,						\
	    pm,		/*H gPipelineMode*/			\
	    ct,		/*H gSetCycleType*/			\
	    tp,		/*H gSetTexturePersp*/			\
	    td,		/*H gSetTextureDetail*/			\
	    tl,		/*H gSetTextureLOD*/			\
	    tt,		/*H gSetTextureLUT*/			\
	    tf,		/*H gSetTextureFilter*/			\
	    tc,		/*H gSetTextureConver*/			\
	    ck,		/*H gSetCombineKey*/			\
	    cd,		/*H gSetColorDither*/			\
	    ad,		/*H gSetAlphaDither*/			\
	    ac,		/*L gSetAlphaCompare*/			\
	    zs,		/*L gSetDepthSource*/			\
	    gm,		/*  gSetGeometryMode*/			\
	    ton,	/*  gTexture*/				\
	    cc0, cc1,						\
	    rd1, rd2						\
	)

#define gsCPSetMode(pm,ct,tp,td, tl, tt, tf, tc, ck, cd, ad, ac, zs,gm,ton, cc0, cc1, rd1, rd2)		\
	gsCPSetModeLERP(						\
	    pm,		/*H gPipelineMode*/			\
	    ct,		/*H gSetCycleType*/			\
	    tp,		/*H gSetTexturePersp*/			\
	    td,		/*H gSetTextureDetail*/			\
	    tl,		/*H gSetTextureLOD*/			\
	    tt,		/*H gSetTextureLUT*/			\
	    tf,		/*H gSetTextureFilter*/			\
	    tc,		/*H gSetTextureConver*/			\
	    ck,		/*H gSetCombineKey*/			\
	    cd,		/*H gSetColorDither*/			\
	    ad,		/*H gSetAlphaDither*/			\
	    ac,		/*L gSetAlphaCompare*/			\
	    zs,		/*L gSetDepthSource*/			\
	    gm,		/*  gSetGeometryMode*/			\
	    ton,	/*  gTexture*/				\
	    cc0, cc1,						\
	    rd1, rd2						\
	)


/*-----------------------------------------------------------------------
 *									
 *	ラベル宣言		
 *									
 *----------------------------------------------------------------------*/
#ifndef offsetof
#define offsetof(s, m)	(size_t)(&(((s *)0)->m))
#endif

#define	FALSE		0
#define	TRUE		1

#define	OFF		0
#define	ON		1
    
enum RGB_e {
    RGB_R,
    RGB_G,
    RGB_B,
    RGB_NUM
};

enum XYZ_e {
    XYZ_X,
    XYZ_Y,
    XYZ_Z,
    XYZ_NUM
};

/*-----------------------------------------------------------------------
 *									
 *	タイプ宣言		
 *									
 *----------------------------------------------------------------------*/

/*
 * z_define.h の名残り
 */
#ifndef INCLUDE_Z_DEFINE_H
#define INCLUDE_Z_DEFINE_H
#else
#undef unint
#undef unshort
#undef unchar
#endif
typedef unsigned long long	unlonglong;
typedef unsigned long 		unlong;
typedef unsigned int 		unint;
typedef unsigned short 		unshort;
typedef unsigned char 		unchar;


typedef float        MtxF[4][4];

typedef struct {
    short	sx;
    short	sy;
    short	sz;
} s_xyz;
    
typedef struct {
    xyz_t	position;
    s_xyz	angle;
} Position_Angle;

typedef struct {
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
    unsigned char	a;
} Color;

typedef struct {
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
} ColorRGB;

typedef struct {
    float	fr;
    float	fg;
    float	fb;
    float	fa;
} ColorF;

typedef struct {
    Gfx		*opa;
    Gfx		*xlu;
} Gfx_Shape;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_TYPES_H_ */
