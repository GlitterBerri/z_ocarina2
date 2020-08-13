/********************************************************************************
 *
 * $Id: z_map_mark.h,v 2.2 2000-05-26 13:46:17+09 zelda Exp $
 *
 * $Log: z_map_mark.h,v $
 * Revision 2.2  2000-05-26 13:46:17+09  zelda
 * メイクエラー対策（マクロ定義）
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.19  1998/09/21 00:29:07  hayakawa
 * *** empty log message ***
 *
 * Revision 1.18  1998-09-17 17:16:26+09  ruto
 * *** empty log message ***
 *
 * Revision 1.17  1998-09-11 17:45:31+09  takahata
 * *** empty log message ***
 *
 * Revision 1.16  1998-09-03 19:55:52+09  hayakawa
 * InitMapMark,CleanupMapMarkプロトタイプ追加
 *
 * Revision 1.15  1998-09-02 11:59:29+09  hayakawa
 * MapMarkPos MapMarkをシェイプアップしてデータ圧縮
 * まだまだ改良の余地があるが時間がないので今日はここまで
 *
 * Revision 1.14  1998-06-15 18:55:37+09  takahata
 * *** empty log message ***
 *
 * Revision 1.13  1998-06-01 17:57:49+09  takahata
 * *** empty log message ***
 *
 * Revision 1.12  1998-03-26 10:25:08+09  takahata
 * （Ｃ＋＋） 対応！！
 *
 * Revision 1.11  1998/03/25  11:53:09  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.10  1998/02/20  10:42:54  takahata
 * *** empty log message ***
 *
 * Revision 1.9  1998/01/20  05:51:09  takahata
 * *** empty log message ***
 *
 * Revision 1.8  1998/01/20  02:22:38  takahata
 * *** empty log message ***
 *
 * Revision 1.7  1998/01/20  01:49:51  takahata
 * *** empty log message ***
 *
 * Revision 1.6  1998/01/19  08:55:12  takahata
 * *** empty log message ***
 *
 * Revision 1.5  1998/01/14  05:51:32  takahata
 * *** empty log message ***
 *
 * Revision 1.4  1998/01/13  07:48:06  takahata
 * *** empty log message ***
 *
 * Revision 1.3  1998/01/09  08:52:50  takahata
 * *** empty log message ***
 *
 * Revision 1.2  1998/01/08  09:44:37  soejima
 * DisplayMapMark( Game_play *game_play )
 *
 * Revision 1.1  1998/01/08  08:43:58  takahata
 * Initial revision
 *
 *
 ********************************************************************************/

#ifndef INCLUDE_Z_MAP_MARK_H
#define INCLUDE_Z_MAP_MARK_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*----------------------------------------------------------------------*/
/*	インクルードファイル						*/
/*----------------------------------------------------------------------*/
#include "gbi.h"
#include "z_play.h"		/* Game_play */
    
/*----------------------------------------------------------------------*/
/*									*/
/*----------------------------------------------------------------------*/
enum { 
	CUSTOM_G_IM_SIZ_4b, CUSTOM_G_IM_SIZ_8b,
	CUSTOM_G_IM_SIZ_16b, CUSTOM_G_IM_SIZ_32b
};

#define	custom_gDPLoadTextureBlock(pkt, timg, fmt, siz, width, height,			\
		pal, cms, cmt, masks, maskt, shifts, shiftt)				\
do {											\
	gDPSetTextureImage(pkt, fmt, custom_LOAD_BLOCK[siz], 1, timg);			\
	gDPSetTile(pkt, fmt, custom_LOAD_BLOCK[siz], 0, 0, G_TX_LOADTILE, 		\
		0 , cmt, maskt, shiftt, cms, masks, shifts);				\
	gDPLoadSync(pkt);								\
	gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, 						\
		(((width)*(height) + custom_INCR[siz]) >> custom_SHIFT[siz]) -1,	\
		CALC_DXT(width, custom_BYTES[siz])); 					\
	gDPPipeSync(pkt);								\
	gDPSetTile(pkt, fmt, custom_SIZ[siz],						\
		(((width) * custom_LINE_BYTES[siz])+7)>>3, 0,				\
		G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks,			\
		shifts);								\
	gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0,					\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,					\
		((height)-1) << G_TEXTURE_IMAGE_FRAC);					\
} while(0)


#define	MARK_Takarabako	{ h_dm_box_txt, G_IM_FMT_RGBA, CUSTOM_G_IM_SIZ_16b, 8, 8, 32, 32, 1024, 1024 }
#define	MARK_Boss	{ h_dm_boss_txt, G_IM_FMT_IA, CUSTOM_G_IM_SIZ_8b, 8, 8, 32, 32, 1024, 1024 }
/*#define	MARK_Karabako	{ h_dm_empty_txt, G_IM_FMT_IA, CUSTOM_G_IM_SIZ_8b, 8, 8, 32, 32, 1024, 1024 }*/

/*----------------------------------------------------------------------*/
/*									*/
/*----------------------------------------------------------------------*/
enum {
    NON_MARK = -1,
    MK_TAKARABAKO = 0,
    MK_BOSS = 1,
    MK_KARABAKO = 2,
    MAX_MARKKIND
};

#define	MAP_BASE_XPOS		( 204 )
#define	MAP_BASE_YPOS		( 140 )
#define	MAP_BASE_YPO2		( MAP_BASE_YPOS + 13 )

#define	LMAP_BASE_XPOS		( -36 )
#define	LMAP_BASE_YPOS		( 21 )

enum {
    MAX_MARKPOINT = 12
};

typedef struct {
    unsigned char	*timg;
    unsigned int	fmt;
    unsigned int	siz;
    unsigned int	width, height;
    unsigned int	lrx, lry;
    unsigned int	dsdx, dtdy;
} MapMarkInfo;

typedef struct {
    signed char		idx;	/* -1,0-15 */
    unsigned char	x, y;	/* 0-255,0-255 */
} MapMarkPos;

typedef struct {
    signed char		markID;	/* -1,0,1,2 */
    char		suu;	/* 1-MAX_MARKPOINT(10) */
    MapMarkPos		pos[ MAX_MARKPOINT ];
} MapMark;


/*----------------------------------------------------------------------*/
/*									*/
/*----------------------------------------------------------------------*/
extern void MapMarkInit(Game_play *game_play);
extern void MapMarkCleanup(Game_play *game_play);
extern void MapMarkDisplay( Game_play * );
extern void EnemyPosConvert( Game_play *, float, float, short *, short * );

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif	/* INCLUDE_Z_MAP_MARK_H */

