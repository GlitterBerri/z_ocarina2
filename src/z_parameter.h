/* $Id: z_parameter.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $ */	
/* $Log: z_parameter.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.80  1998/10/10 13:56:30  soejima
 * *** empty log message ***
 *
 * Revision 1.79  1998-10-09 16:37:39+09  soejima
 * *** empty log message ***
 *
 * Revision 1.78  1998-10-08 23:08:35+09  soejima
 * *** empty log message ***
 *
 * Revision 1.77  1998-09-24 21:36:18+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/10/08  12:36:08  soejima
 * Initial revision
 * $LogÄÉ²Ã
 * */


#ifndef INCLUDE_Z_PARAMETER_H
#define INCLUDE_Z_PARAMETER_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif





/************************************************************************
 *									*
 *	¥¼¥ë¥À£¶£´ ¥Ñ¥é¥á¡¼¥¿¡¼						*
 *				1996Ç¯10·î 8Æü(²ÐÍËÆü) 17»þ00Ê¬00ÉÃ JST *
 *									*
 ************************************************************************/
typedef struct zelda_parameter_struct {
    View	view;			/* ¥«¥á¥é ¥Ó¥å¡¼ */
    
    Vtx_t	*parameter_frame_vtx;
    Vtx_t	*heartVtx;		/* ¥Ï¡¼¥È */

    char	*parameterSegment;	/* ¾ïÃó£Ð£Á£Ò£Á£Í£Å£Ô£Å£Ò¥»¥°¥á¥ó¥È */
    char	*do_actionSegment;	/* £Ä£Ï¥¢¥¯¥·¥ç¥ó¥»¥°¥á¥ó¥È */
    char	*icon_itemSegment;	/* ¥¢¥¤¥³¥ó¥¢¥¤¥Æ¥à¥»¥°¥á¥ó¥È */
    char	*mapSegment;		/* £Í£Á£Ð¥»¥°¥á¥ó¥È */
    char	map_palete[16*2];	/* £Í£Á£Ð¥Ñ¥ì¥Ã¥È */

    dma_t	dma;			/* ¥á¥â¥êÅ¾Á÷´Ø·¸ */
    dma_t	dma1;			/* ¥á¥â¥êÅ¾Á÷´Ø·¸ */
    dma_t	dma2;			/* ¥á¥â¥êÅ¾Á÷´Ø·¸ */
    OSMesgQueue	mq;			/*		  */
    OSMesg	m;			/*	  	  */

    irect	vw;			/* ¥·¥¶¨¡ÃÍ¡ÊTop,Bottom,Left,Right) */

    short	do_action_flg;		/* £Ä£Ï¥¢¥¯¥·¥ç¥ó ÀÚÂØ¥Õ¥é¥° */
    unsigned short	do_action;		/* £Ä£Ï¥¢¥¯¥·¥ç¥ó ¥Ý¥¤¥ó¥¿ */
    unsigned short	do_action_old;		/* £Ä£Ï¥¢¥¯¥·¥ç¥ó ¥Ý¥¤¥ó¥¿£Ï£Ì£Ä */
    float	do_action_rotate;	/* £Ä£Ï¥¢¥¯¥·¥ç¥ó ²óÅ¾¥«¥¦¥ó¥¿ */
    short	navi_flag;		/* ¥Ê¥ô¥£¥Õ¥é¥° */
    short	sp_action_flag;		/* ÆÃÊÌ¡Ê£Â¡Ë¥¢¥¯¥·¥ç¥ó ÀÚÂØ¥Õ¥é¥° */
    short	sp_action;		/* ÆÃÊÌ¡Ê£Â¡Ë¥¢¥¯¥·¥ç¥ó ¥Ý¥¤¥ó¥¿ */


/*¢­¢­¢­¢­¢­¢­¢­ ¹âÈª»ÈÍÑ ¢­¢­¢­¢­¢­¢­¢­*/
    short	dokidoki_meter;		/*  */
    short	now_mode;		/*  */
    short	dokidoki_prim[3];	/* ¥É¥­¥É¥­£Ð£Ò£É£Í¥«¥é¡¼ */
    short	dokidoki_env[3];	/* ¥É¥­¥É¥­£Å£Î£Ö¥«¥é¡¼ */
    short	doki_prim_r[2];		/* ¥É¥­¥É¥­£Ð£Ò£É£Í¡¼£Ò */
    short	doki_prim_g[2];		/* ¥É¥­¥É¥­£Ð£Ò£É£Í¡¼£Ç */
    short	doki_prim_b[2];		/* ¥É¥­¥É¥­£Ð£Ò£É£Í¡¼£Â */
    short	doki_env_r[2];		/* ¥É¥­¥É¥­£Å£Î£Ö¨¡£Ò */
    short	doki_env_g[2];		/* ¥É¥­¥É¥­£Å£Î£Ö¨¡£Ç */
    short	doki_env_b[2];		/* ¥É¥­¥É¥­£Å£Î£Ö¨¡£Â */
    short	dokidoki_max;		/*  */
    short	active_heart_timer;	/*  */
    short	dokidoki_wait;		/*  */
    short	dokidoki_flag;		/*  */
/*¢¬¢¬¢¬¢¬¢¬¢¬¢¬ ¹âÈª»ÈÍÑ ¢¬¢¬¢¬¢¬¢¬¢¬¢¬*/

    short	magic_mp;		/*             ¾ÃÈñËâË¡ÎÌ */
    short	magic_frame;		/*             Áý¸º¥Õ¥ì¡¼¥à */

    short	rpc[4];			/* ¥ë¥Ô¡¼¿ô */

    unsigned char	lash_ct;		/* ÊÜ¥«¥¦¥ó¥¿ */

    unsigned short	yabusame_score;		/* Î®Å­ÇÏÆÀÅÀ */
    unsigned short	yabusame_arrow;		/* Î®Å­ÇÏÌðËÜ¿ô */
    unsigned short	yabu_mode;		/* Î®Å­ÇÏÆâÉô¾õÂÖ */
    unsigned short	yabu_score;		/* Î®Å­ÇÏÆâÉôÆÀÅÀ */

    unsigned short	fill_alpha;		/* £Æ£é£ì£ì£Ò£å£ã£ô£á£î£ç£ì£å £Á£ì£ð£è£áÃÍ */
    unsigned short	a_alpha;		/* £Á¥Ü¥¿¥ó £Á£ì£ð£è£áÃÍ */
    unsigned short	b_alpha;		/* £Â¥Ü¥¿¥ó £Á£ì£ð£è£áÃÍ */
    unsigned short	c_alpha;		/* £Ã¥Ü¥¿¥ó £Á£ì£ð£è£áÃÍ¡Êº¸¡Ë*/
    unsigned short	c_alpha1;		/* £Ã¥Ü¥¿¥ó £Á£ì£ð£è£áÃÍ¡Ê²¼¡Ë*/
    unsigned short	c_alpha2;		/* £Ã¥Ü¥¿¥ó £Á£ì£ð£è£áÃÍ¡Ê±¦¡Ë*/
    unsigned short	heart_alpha;		/* ¥Ï¡¼¥È £Á£ì£ð£è£áÃÍ */
    unsigned short	meter_alpha;		/* ¥á¡¼¥¿¡¼ £Á£ì£ð£è£áÃÍ */
    unsigned short	map_alpha;		/* £Í£Á£Ð £Á£ì£ð£è£áÃÍ */
    short	start_alpha;		/* £Ó£Ô£Á£Ò£Ô £Á£ì£ð£è£áÃÍ */


    short	spot_map_no;		/* £Ó£Ð£Ï£Ô£Í£Á£Ð £Î£Ï. */
    short	dungeon_map_no;		/* ¥À¥ó¥¸¥ç¥ó£Í£Á£Ð £Î£Ï. */
    short	room_no;		/* ¸½ºßÉô²°£Î£ï¡¥*/
    short	map_palete_no;		/* ¸½ºßÉô²°£Ð£Á£Ì£Å£Ô£Å £Î£ï¡¥*/

    unsigned char	hold_rod;		/* Äà¤ê¤¶¤ª»ý¤Ã¤Æ¤¤¤ë¥Õ¥é¥° */

    unsigned char	marathon_fg;	/* ¥Þ¥é¥½¥ó¥Õ¥é¥° */


    /* ¥Ü¥¿¥óÀ©¸æ¥³¡¼¥É */
    unchar	h_gage;		/* ¥Ï¡¼¥È,ËâË¡¥²¡¼¥¸,¥ë¥Ô¡¼,¥«¥® */
    unchar	b_button;	/* £Â¥Ü¥¿¥ó */
    unchar	a_button;	/* £Á¥Ü¥¿¥ó */
    unchar	c_bottle;	/* ÉÓ */
    unchar	c_warasibe;	/* ¤ï¤é¤·¤Ù */
    unchar	c_hook;		/* ¥Õ¥Ã¥¯¥·¥ç¥Ã¥È */
    unchar	c_ocarina;	/* ¥ª¥«¥ê¥Ê */
    unchar	c_warp;		/* ¥ª¥«¥ê¥Ê¡Ê¥ï¡¼¥×¡Ë*/
    unchar	c_sunmoon;	/* ¥ª¥«¥ê¥Ê¡ÊÂÀÍÛ¤Î²Î¡Ë*/
    unchar	m_wind;		/* ËâË¡¡ÊÉ÷¡Ë*/
    unchar	m_magic;	/* ËâË¡¡Ê±ê¡¦°¦¡Ë*/
    unchar	another;	/* ¤½¤ÎÂ¾£Ã¥Ü¥¿¥ó */
    /*
     *		0 = É½¼¨ (»È¤¨¤ë)
     *		1 = È¾Æ©ÌÀÉ½¼¨ (»È¤¨¤Ê¤¤)
     *		2 = ÈóÉ½¼¨ (»È¤¨¤Ê¤¤)
     *		3 = »È¤¨¤ë¤¬¡¢¥ï¡¼¥×¥á¥í¥Ç¥£¤ò¼õ¤±ÉÕ¤±¤Ê¤¤
     *
     *    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
     *	 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     *	 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
     *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     *			   ¥Ï  £Â  £Á  ÉÓ  ¤ï  ¥Õ  ¥ª  ¥ª  ¥ª  Ëâ  Ëâ  ¤½
     *			   ¡Ã  ¥Ü  ¥Ü      ¤é  ¥Ã  ¥«  ¥«  ¥«  Ë¡  Ë¡  ¤Î
     *			   ¥È  ¥¿  ¥¿      ¤·  ¥¯  ¥ê  ¥ê  ¥ê  É÷  ±ê  Â¾
     *			   ¡¦  ¥ó  ¥ó      ¤Ù  ¥·  ¥Ê  ¥Ê  ¥Ê      ¡¦
     *			   Ëâ                  ¥ç  ¥¤  ¥ï  ÂÀ      °¦
     *			   Ë¡                  ¥Ã  ¥Ù  ¡Ã  ÍÛ 
     *			   ¥²                  ¥È  ¥ó  ¥×  ¤Î 
     *			   ¡Ã                      ¥È      ²Î
     *			   ¥¸                  
     *			   ¡¦                  
     *			   ¥ë             
     *			   ¥Ô             
     *			   ¡Ã             
     */

} Parameter;



/* ¥³¥ó¥¹¥È¥é¥¯¥È */
extern void
parameter_ct( Game_play *game_play );

/* ¥Ç¥¹¥È¥é¥¯¥È */
extern void
parameter_dt( Game_play *game_play );

/* ¥Ñ¥é¥á¡¼¥¿¡¼£Ä£Ò£Á£× */
extern void
parameter_draw( Game_play *game_play );

/* ¥Ñ¥é¥á¡¼¥¿¡¼£Í£Ï£Ö£Å */
extern void
parameter_move( Game_play *game_play );


#define ON_HOLD_ROD( game_play )	((game_play)->parameter.hold_rod = 1)
#define OFF_HOLD_ROD( game_play )	((game_play)->parameter.hold_rod = 0)
#define CHK_HOLD_ROD( game_play )	((game_play)->parameter.hold_rod)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_parameter.h end ***/
