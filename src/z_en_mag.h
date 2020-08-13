/*
 * $Id: z_en_mag.h,v 2.2 2002-05-27 16:19:20+09 zelda Exp $
 *
 * $Log: z_en_mag.h,v $
 * Revision 2.2  2002-05-27 16:19:20+09  zelda
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.8  1998/10/13 05:15:40  soejima
 * *** empty log message ***
 *
 * Revision 1.7  1998-10-06 18:47:12+09  soejima
 * *** empty log message ***
 *
 * Revision 1.6  1998-10-05 23:00:42+09  soejima
 * *** empty log message ***
 *
 * Revision 1.5  1998-09-22 17:27:06+09  takahata
 * *** empty log message ***
 *
 * Revision 1.4  1998-07-22 22:46:14+09  soejima
 * *** empty log message ***
 *
 * Revision 1.3  1998-07-18 22:42:09+09  soejima
 * *** empty log message ***
 *
 * Revision 1.2  1998-07-17 17:51:35+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998-07-16 21:24:54+09  soejima
 * Initial revision
 *
 *
 *
 * */
/*-----------------------------------------------------------------------------
 *
 *
 *----------------------------------------------------------------------*/
#ifndef INCLUDE_Z_EN_MAG_H
#define INCLUDE_Z_EN_MAG_H

/*-----------------------------------------------------------------------
 *
 *	¥·¡¼¥¯¥¯¥é¥¹
 *
 *----------------------------------------------------------------------*/
typedef struct En_Mag_actor_s {
    Actor actor;			/* ´ðÄì¥¯¥é¥¹			*/

    Sram	sram;		/* £Ó£Ò£Á£Í ¥¯¥é¥¹ */

    Kanfont	kanfont;		/* Ê¸»ú ¥¯¥é¥¹ */

    short	effect_rgb_fg;		/* ¥¨¥Õ¥§¥¯¥È£Ò£Ç£Â¥Õ¥é¥° */
    short	effect_rgb_ct;		/*                 ¥«¥¦¥ó¥¿¡¼ */
    short	title_mode;		/* ¥¿¥¤¥È¥ë£Í£Ï£Ä£Å */

    float	effect_prim_f;		/*                 £Ð£Ò£É£Í¡²£Æ */
    float	effect_prim[3];		/* ¥¨¥Õ¥§¥¯¥È£Ð£Ò£É£Í¡²£Ò£Ç£Â */
    float	effect_env[3];		/* ¥¨¥Õ¥§¥¯¥È£Å£Î£Ö¡²£Ò£Ç£Â */
    
    float	effect_alpha;		/* ¥¨¥Õ¥§¥¯¥È ¥¢¥ë¥Õ¥¡ÃÍ */
    float	title_alpha;		/* ¥¿¥¤¥È¥ë ¥¢¥ë¥Õ¥¡ÃÍ */
    float	sub_alpha;		/* ÆüËÜ¸ì¥¿¥¤¥È¥ë¥¢¥ë¥Õ¥¡ÃÍ */
    float	copy_alpha;		/* "£±£¹£¹£¸£Î£é£î£ô£å£î£ä£ï" ¥¢¥ë¥Õ¥¡ÃÍ */

    short	scroll_x;
    short	scroll_y;
    short	alpha_ct;
    short	alpha_fdin;
    short	alpha_fdout;

    /* £Ó£Ò£Á£Í¥¤¥Ë¥·¥ã¥é¥¤¥º´Ø·¸ */
    short	key_point;
    short	key_frame;

    int		old_key;
    int		key_wait;
} En_Mag_Actor;

/* /project/ZELDA/data/shape2/zelda_mag/ : ¥¿¥¤¥È¥ë */
#if defined(USE_NEW_DUNGEON)
extern unsigned char  g_title_ura_txt[];
#else /* defined(USE_NEW_DUNGEON) */
extern unsigned char  g_title_txt[];
#endif /* defined(USE_NEW_DUNGEON) */
extern unsigned char  g_title_sub_1_txt[];
extern unsigned char  g_title_sub_2_txt[];
extern unsigned char  g_title_sub_j_txt[];
extern unsigned char  g_title_efc_1_txt[];
extern unsigned char  g_title_efc_2_txt[];
extern unsigned char  g_title_efc_3_txt[];
extern unsigned char  g_title_efc_4_txt[];
extern unsigned char  g_title_efc_5_txt[];
extern unsigned char  g_title_efc_6_txt[];
extern unsigned char  g_title_efc_7_txt[];
extern unsigned char  g_title_efc_8_txt[];
extern unsigned char  g_title_efc_9_txt[];
#if defined(USE_NEW_DUNGEON)
extern unsigned char  g_title_cpr_ura_txt[];
#else /* defined(USE_NEW_DUNGEON) */
extern unsigned char  g_title_cpr_txt[];
#endif /* defined(USE_NEW_DUNGEON) */
extern unsigned char  g_title_mable_txt[];
extern unsigned char  g_dd_txt[];

/*-----------------------------------------------------------------------
 *
 *	¥×¥í¥Õ¥£¡¼¥ë
 *
 *----------------------------------------------------------------------*/
extern Actor_profile En_Mag_Profile;

#endif
/*** z_en_mag.h ***/


