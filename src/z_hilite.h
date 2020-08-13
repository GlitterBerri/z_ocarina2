/*
 * $Id: z_hilite.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 * $Log: z_hilite.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.24  1998/09/26 14:58:27  goron
 * *** empty log message ***
 *
 * Revision 1.23  1998-09-20 02:06:00+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1998-09-11 20:30:37+09  goron
 * *** empty log message ***
 *
 * Revision 1.21  1998-03-23 11:16:06+09  yoshida
 * *** empty log message ***
 *
 * Revision 1.20  1997/07/16  12:40:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.19  1997/07/15  11:18:26  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/06/12  09:56:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1997/04/18  09:30:38  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1997/04/03  03:37:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.15  1997/03/28  07:13:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1997/03/28  07:05:36  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1997/03/28  06:37:53  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1997/03/28  05:15:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1997/03/20  10:48:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1997/03/14  04:41:42  iwawaki
 * *** empty log message ***
 *
 * Revision 1.9  1997/03/11  06:31:14  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1997/02/05  12:55:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1996/11/20  00:51:48  hayakawa
 * コメント入れた
 *
 */


#ifndef INCLUDE_Z_HILITE_H
#define INCLUDE_Z_HILITE_H


#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <ultra64.h>

//#define G_CC_REFLECTRGBX	TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
#define G_CC_REFLECTSHADE	/* G_CC_MODULATERGBA */ TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0
#define G_CC_REFLECTRGBX	/* G_CC_MODULATERGBA_PRIM */ TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
#define G_CC_HILITERGBA2X	/* G_CC_HILITERGBA2 */ ENVIRONMENT, COMBINED, TEXEL0, COMBINED, ENVIRONMENT, COMBINED, TEXEL0, COMBINED
//#define G_CC_HILITERGBA2X	TEXEL0, 0, ENVIRONMENT, COMBINED, TEXEL0, 0, ENVIRONMENT, COMBINED

#if 0
#define	gsCPReflectHilite_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(silver_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)
#endif
#if 1
#define	gsCPReflectHilite_Gold_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(gold2_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)
#else
#define	gsCPReflectHilite_Gold_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(silver2_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)
#endif

#define	gsCPReflectHilite_gold_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(gold_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)

#define	gsCPReflectHilite_gold2_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(gold2_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)

#define	gsCPReflectHilite_silver_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(silver_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetPrimColor(0,1, 255,255,255,255),\
	gsDPSetEnvColor(255,255,255,0)
    
#define	gsCPReflectHilite_silver2_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(silver2_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetPrimColor(0,1, 255,255,255,255),\
	gsDPSetEnvColor(255,255,255,0)
    
#if 0
#define	gsCPReflectHilite_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTRGBX, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(silver_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetPrimColor(0,1, 255,255,255,255),\
	gsDPSetEnvColor(255,255,255,0)
#endif
#define	gsCPReflectHilite_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(silver2_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetPrimColor(0,1, 255,255,255,255),\
	gsDPSetEnvColor(255,255,255,0)
#if 0
#define	gsCPReflectHilite_Gold_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTRGBX, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(gold2_env_txt, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0), \
	gsDPSetPrimColor(0,1, 255,255,255,0xff)
#endif
#define	gsCPReflectHiliteX_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTSHADE, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(reflect_tex, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)

#define	gsCPReflectHiliteXcolor_start \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_REFLECTRGBX, G_CC_HILITERGBA2X), \
	gsSPSetGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPLoadMultiBlock(hilite_tex, 256, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, \
			  		   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			  		   G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPDisplayList(&Gfx_Hilite), \
	gsDPLoadMultiBlock(reflect_tex, 0, G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, \
			  		   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, \
			  		   5, 5, G_TX_NOLOD, G_TX_NOLOD), \
	gsSPTexture(40<<6,40<<6,0,G_TX_RENDERTILE,G_ON), \
	gsDPSetEnvColor(255,255,255,0)
    
#define	gsCPReflectHilite_end \
	gsDPPipeSync(), \
	gsDPSetCombineMode(G_CC_MODULATERGBDECALA, G_CC_MODULATERGBA_PRIM2), \
	gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR), \
	gsDPSetPrimColor(0,0, 255,255,255,0xff)


extern unsigned char	hilite_tex[];
extern unsigned short	silver_env_txt[];
extern unsigned short	silver2_env_txt[];
extern unsigned short	gold_env_txt[];
extern unsigned short	gold2_env_txt[];
extern unsigned short	rupee_env_txt[];
extern unsigned short	blue_env_txt[];
extern unsigned short	red_env_txt[];
extern unsigned short	magenta_env_txt[];
extern unsigned short	sky_env_txt[];
extern unsigned short	orange_env_txt[];
extern unsigned short	silverI_env_txt[];
extern unsigned short	reflect_tex[];


#define	HILITE_GFX_MAX	2

extern Gfx	anime_hilite[];


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_hilite.h end ***/

