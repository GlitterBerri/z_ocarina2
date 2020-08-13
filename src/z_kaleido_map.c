/* $Id: z_kaleido_map.c,v 2.3 1998/11/06 04:26:35 soejima Exp $
 *
 * ¥«¥ì¥¤¥É¡¦¥¹¥³¡¼¥×¡Ø£Í£Á£Ð¡Ù
 *
 * $Log: z_kaleido_map.c,v $
 * Revision 2.3  1998/11/06  04:26:35  soejima
 * ¥³¥á¥ó¥È
 *
 * Revision 2.2  1998-10-26 19:15:18+09  hayakawa
 * HREG¤Î¥Æ¥¹¥È¤ò³°¤·¤¿
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.110  1998/10/19 06:08:14  soejima
 * *** empty log message ***
 *
 * Revision 1.109  1998-10-12 23:08:48+09  soejima
 * *** empty log message ***
 *
 * Revision 1.108  1998-10-10 14:35:48+09  zelda
 * HREG ¢ª SETHREG ÊÑ¹¹
 *
 * Revision 1.107  1998-10-07 23:04:07+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/02/06  04:46:49  soejima
 * Initial revision
 * $LogÄÉ²Ã
 * */


/************************************************************************
 *									*
 *	¥«¥ì¥¤¥É¡¦¥¹¥³¡¼¥× £Í£Á£Ð					*
 *				1997Ç¯02·î06Æü(ÌÚÍËÆü) 09»þ00Ê¬00ÉÃ JST *
 ************************************************************************/
#include "z_basic.h"
#include "z_play.h"

#include "z_kaleido_scope_h.h"
#include "z_kaleido_moji.h"

#include "z_define1.h"
#include "z_parameter_h.h"
#include "z_parameterd.h"
#include "z_map_exp.h"
#include "z_save_area_h.h"

/* for s2dex2 by hayakawa */
#include "gbi.h"
#include "gs2dex.h"
#include "ucode.h"		/* SP_UCODE_DATA_SIZE */
#include "sys_ucode.h"

#include "z_map_exp.h"		/* map_exp_data_tbl_p */
#include "z_map_exp_data.h"	/* MAP_EXP_DATA_TBL */


/*===============================================================
  =	   ¥À¥ó¥¸¥ç¥ó£Í£Á£ÐÌÌ ºîÀ®				=
  ===============================================================*/
extern void
dungeon_map_disp( Game_play *game_play, Graph *graph )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Kscope		*kscope = (Kscope *)&game_play->kscope;

    static unchar *dungeon_keep_data[] = {
	h_24_boss_key_txt, h_24_compass_txt, h_24_map_txt,
    };

    static unchar *dungeon_name_data[] = {
	 h_dt_1_txt,  h_dt_2_txt,  h_dt_3_txt,  h_dt_4_txt,
	 h_dt_5_txt,  h_dt_6_txt,  h_dt_7_txt,  h_dt_8_txt,
	 h_dt_9_txt, h_dt_10_txt,
    };
    static unchar *floor_data[] = {
	h_0f_txt,
	h_8f_txt, h_7f_txt, h_6f_txt, h_5f_txt, h_4f_txt, h_3f_txt, h_2f_txt, h_1f_txt,
	h_b1_txt, h_b2_txt, h_b3_txt, h_b4_txt, h_b5_txt, h_b6_txt, h_b7_txt, h_b8_txt,
    };
#if 0
    static unchar dungeon_floor_data[][8] = {
    	{ F00, F00, F00, F3F, F2F, F1F, FB1, FB2, },	// ÍÅÀº¤Î¼ù
    	{ F00, F00, F00, F00, F00, F00, F2F, F1F, },	// ¥É¥É¥ó¥´
    	{ F00, F00, F00, F00, F00, F00, F1F, FB1, },	// ¥¸¥ã¥Ö¥¸¥ã¥ÖÍÍ
    	{ F00, F00, F00, F00, F2F, F1F, FB1, FB2, },	// ¿¹¤Î¿ÀÅÂ
    	{ F00, F00, F00, F5F, F4F, F3F, F2F, F1F, },	// ±ê¤Î¿ÀÅÂ
    	{ F00, F00, F00, F00, F3F, F2F, F1F, FB1, },	// ¿å¤Î¿ÀÅÂ
    	{ F00, F00, F00, F00, F4F, F3F, F2F, F1F, },	// º²¤Î¿ÀÅÂ
    	{ F00, F00, F00, F00, FB1, FB2, FB3, FB4, },	// °Ç¤Î¿ÀÅÂ
    	{ F00, F00, F00, F00, F00, FB1, FB2, FB3, },	// º²¤Î¿ÀÅÂ(¤³¤É¤â)
    	{ F00, F00, F00, F00, F00, F00, F00, F1F, },	// É¹¤ÎÆ¶·¢
    };
    static short boss_position[] = {
	BOSS_7,		// ÍÅÀº¤Î¼ù
	BOSS_7,		// ¥É¥É¥ó¥´
	BOSS_6,		// ¥¸¥ã¥Ö¥¸¥ã¥ÖÍÍ
	BOSS_7,		// ¿¹¤Î¿ÀÅÂ
	BOSS_7,		// ±ê¤Î¿ÀÅÂ
	BOSS_4,		// ¿å¤Î¿ÀÅÂ
	BOSS_5,		// º²¤Î¿ÀÅÂ
	BOSS_7,		// °Ç¤Î¿ÀÅÂ
	BOSS_8,		// º²¤Î¿ÀÅÂ(¤³¤É¤â)
	BOSS_8,		// É¹¤ÎÆ¶·¢
    };
#endif
    static unshort map_color[][3] = {
	{ (MAP_COLOR & 0xf800)>>11, (MAP_COLOR & 0x07c0)>>6, (MAP_COLOR & 0x003e)>>1 },
	{ (LINK_MAP & 0xf800)>>11,  (LINK_MAP & 0x07c0)>>6,  (LINK_MAP & 0x003e)>>1 },
    };


    short	i, j;
    short	nowp;
    short	r0, g0, b0;
    unshort	rgb;
    static short	rc = (LINK_MAP & 0xf800)>>11;
    static short	gc = (LINK_MAP & 0x07c0)>>6;
    static short	bc = (LINK_MAP & 0x003e)>>1;
    static unshort	cnt = 20, pt = 0;
    

    OPEN_DISP( graph );

    if ( kscope->pause == Pause_Play && !kscope->kscp_status && kscope->kscp_pos == Display_Map ) {
	kscope->cursor_colp = Cursor_Red;
	nowp = kscope->cursor_point[Display_Map];
	if ( !kscope->key_angle ) {
	    /* ¥¢¥¤¥Æ¥à¥«¡¼¥½¥ë°ÌÃÖ¥Á¥§¥Ã¥¯ */
	    if ( kscope->wkey_x > KEY_ANGLE_3D ) {
		if ( kscope->cur_xpt[Display_Map] ) {
		    key_arrangement( game_play, HD_RIGHT );
		} else {
		    kscope->cur_xpt[Display_Map] = 1;
		    kscope->cursor_point[Display_Map] = 0;
		    if ( !GetKeyCompassMap(Scene_ID,H_boss_key) ) {
			kscope->cursor_point[Display_Map]++;
			if ( !GetKeyCompassMap(Scene_ID,H_compass) ) {
			    kscope->cursor_point[Display_Map]++;
			    if ( !GetKeyCompassMap(Scene_ID,H_map) ) 
				key_arrangement( game_play, HD_RIGHT );
			}
		    }
		}
	    } else if ( kscope->wkey_x < -KEY_ANGLE_3D ) {
		if ( !kscope->cur_xpt[Display_Map] ) {
		    key_arrangement( game_play, HD_LEFT );
		} else {
		    kscope->cur_xpt[Display_Map] = 0;
		    kscope->cursor_point[Display_Map] = kscope->dungeon_map_pt;
		    /* £Í£Á£Ð £Ä£Í£Á */
		    PRINTF("kscope->cursor_point=%d\n",kscope->cursor_point[Display_Map]);
		    VREG(13) = VREG(12)+MAP_EXP_DATA_TBL(map_no_data)[Scene_ID][kscope->cursor_point[Display_Map]-3];
		    map_dma( game_play );
		}
	    }
	    if ( kscope->cursor_point[Display_Map] < 3 ) {
		if ( kscope->wkey_y > KEY_ANGLE_3D ) {
		    if ( kscope->cursor_point[Display_Map] ) {
			for ( i = kscope->cursor_point[Display_Map]-1; i > -1; i-- ) {
			    if ( GetKeyCompassMap(Scene_ID,H_boss_key+i) ) {
				kscope->cursor_point[Display_Map] = i;
				break;
			    }
			}
		    }
		} else if ( kscope->wkey_y < -KEY_ANGLE_3D ) {
		    if ( kscope->cursor_point[Display_Map] != 2 ) {
			for ( i = kscope->cursor_point[Display_Map]+1; i < 3; i++ ) {
			    if ( GetKeyCompassMap(Scene_ID,H_boss_key+i) ) {
				kscope->cursor_point[Display_Map] = i;
				break;
			    }
			}
		    }
		}
	    } else {
		if ( kscope->wkey_y > KEY_ANGLE_3D ) {
		    if ( kscope->cursor_point[Display_Map] > 3 ) {
			for ( i = kscope->cursor_point[Display_Map]-3-1; i > -1; i-- ) {
			    if ( Room_Inf[Scene_ID][Inf_Floor] & check_bit[i] || (GetKeyCompassMap(Scene_ID,H_map) && MAP_EXP_DATA_TBL(dungeon_floor_data)[parameter->dungeon_map_no][i] != F00) ) {
				kscope->cursor_point[Display_Map] = i + 3;
				break;
			    }
			}
		    }
		} else if ( kscope->wkey_y < -KEY_ANGLE_3D ) {
		    if ( kscope->cursor_point[Display_Map] != 10 ) {
			for ( i = kscope->cursor_point[Display_Map]-3+1; i < 11; i++ ) {
			    if ( Room_Inf[Scene_ID][Inf_Floor] & check_bit[i] || (GetKeyCompassMap(Scene_ID,H_map) && MAP_EXP_DATA_TBL(dungeon_floor_data)[parameter->dungeon_map_no][i] != F00) ) {
				kscope->cursor_point[Display_Map] = i + 3;
				break;
			    }
			}
		    }
		}
		/* £Í£Á£Ð £Ä£Í£Á */
		i = VREG(13);
		VREG(13) = VREG(12)+MAP_EXP_DATA_TBL(map_no_data)[Scene_ID][kscope->cursor_point[Display_Map]-3];
		kscope->dungeon_map_pt = kscope->cursor_point[Display_Map];
		if ( i != VREG(13) ) map_dma( game_play );
	    }
	} else {
	    if ( kscope->key_angle == HD_LEFT ) {
		if ( kscope->wkey_x > KEY_ANGLE_3D ) {
		    kscope->name_flush = 0;
		    kscope->key_angle = 0;
		    kscope->cur_xpt[Display_Map] = 0;
		    kscope->select_pt[Display_Map] = 
			kscope->cursor_point[Display_Map] = kscope->dungeon_map_pt;
		    j = (kscope->select_pt[Display_Map] + 18)*4;
		    cursol_defalute( kscope, j, kscope->map_frame_Vtx );
		    Na_StartSystemSe( NA_SE_SY_CURSOR );
		}
	    } else {
		if ( kscope->wkey_x < -KEY_ANGLE_3D ) {
		    kscope->name_flush = 0;
		    kscope->key_angle = 0;
		    kscope->cur_xpt[Display_Map] = 1;
		    kscope->cursor_point[Display_Map] = 0;
		    if ( !GetKeyCompassMap(Scene_ID,H_boss_key) ) {
			kscope->cursor_point[Display_Map]++;
			if ( !GetKeyCompassMap(Scene_ID,H_compass) ) {
			    kscope->cursor_point[Display_Map]++;
			    if ( !GetKeyCompassMap(Scene_ID,H_map) ) {
				kscope->cur_xpt[Display_Map] = 0;
				kscope->select_pt[Display_Map] = 
				    kscope->cursor_point[Display_Map] = kscope->dungeon_map_pt;
				/* £Í£Á£Ð £Ä£Í£Á */
				VREG(13) = VREG(12)+MAP_EXP_DATA_TBL(map_no_data)[Scene_ID][kscope->cursor_point[Display_Map]-3];
				map_dma( game_play );
			    }
			}
		    } else {
		    kscope->select_pt[Display_Map] = kscope->cursor_point[Display_Map];
		    }
		    PRINTF("kscope->cursor_point====%d\n",kscope->cursor_point[Display_Map]);
		    j = (kscope->select_pt[Display_Map] + 18)*4;
		    cursol_defalute( kscope, j, kscope->map_frame_Vtx );
		    Na_StartSystemSe( NA_SE_SY_CURSOR );
		}
	    }
	}
	if ( nowp != kscope->cursor_point[Display_Map] )
	    Na_StartSystemSe( NA_SE_SY_CURSOR );
    }
    if ( !kscope->key_angle ) {
	if ( kscope->cursor_point[Display_Map] < 3 )
	    kscope->select_name[Display_Map] = H_boss_key + kscope->cursor_point[Display_Map];
	else kscope->select_name[Display_Map] = 999;
	kscope->select_pt[Display_Map] = kscope->cursor_point[Display_Map];
	j = (kscope->select_pt[Display_Map] + 18)*4;
	cursol_defalute( kscope, j, kscope->map_frame_Vtx );
	if ( !kscope->cur_xpt[Display_Map] ) {
	    kscope->map_frame_Vtx[j].ob[0]   = kscope->map_frame_Vtx[j+2].ob[0] = (short)(kscope->map_frame_Vtx[j].ob[0] - 2);
	    kscope->map_frame_Vtx[j+1].ob[0] = kscope->map_frame_Vtx[j+3].ob[0] = (short)(kscope->map_frame_Vtx[j+1].ob[0] + 4);
	    kscope->map_frame_Vtx[j].ob[1]   = kscope->map_frame_Vtx[j+1].ob[1] = (short)(kscope->map_frame_Vtx[j].ob[1] + 2);
	    kscope->map_frame_Vtx[j+2].ob[1] = kscope->map_frame_Vtx[j+3].ob[1] = (short)(kscope->map_frame_Vtx[j+2].ob[1] - 4);
	}
    }

    /* ¥À¥ó¥¸¥ç¥óÌ¾ */
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, kscope->alpha );
    gDPSetCombineMode( NEXT_DISP, G_CC_MODULATEIA, G_CC_MODULATEIA );
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[68]), 16,  0);
    gDPLoadTextureBlock( NEXT_DISP,
			 dungeon_name_data[Scene_ID], G_IM_FMT_IA, G_IM_SIZ_8b, 96, 16, 0,
			 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );


    /* ¥À¥ó¥¸¥ç¥ó»ý¤ÁÊª */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
    for ( i = 0, j = 4; i < 3; i++, j+=4 ) {
	if ( GetKeyCompassMap(Scene_ID,H_boss_key+i) ) {
	    gDPLoadTextureBlock( NEXT_DISP,
				 dungeon_keep_data[i], G_IM_FMT_RGBA, G_IM_SIZ_32b, 24, 24, 0,
				 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
	}
    }


    /* ³¬ÁØ */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 200, kscope->alpha );
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[84]), 32, 0);
    for ( i = j = 0; i < 8; i++, j+=4 ) {
	if ( Room_Inf[Scene_ID][Inf_Floor] & check_bit[i] || GetKeyCompassMap(Scene_ID,H_map) ) {
	    if ( i != (kscope->dungeon_map_pt - 3) ) {
		gDPLoadTextureBlock( NEXT_DISP,
				     floor_data[MAP_EXP_DATA_TBL(dungeon_floor_data)[parameter->dungeon_map_no][i]],
				     G_IM_FMT_IA, G_IM_SIZ_8b, 24, 16, 0,
				     G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
		gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
	    }
	}
    }
    j = (kscope->dungeon_map_pt - 3) * 4;
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 150, 150, 255, kscope->alpha );
    gDPLoadTextureBlock( NEXT_DISP,
			 floor_data[MAP_EXP_DATA_TBL(dungeon_floor_data)[parameter->dungeon_map_no][kscope->dungeon_map_pt - 3]],
			 G_IM_FMT_IA, G_IM_SIZ_8b, 24, 16, 0,
			 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );


    kscope->map_frame_Vtx[116+8].ob[0] = kscope->map_frame_Vtx[116+10].ob[0] = kscope->map_frame_Vtx[116+8].ob[0] + 2;
    kscope->map_frame_Vtx[116+9].ob[0] = kscope->map_frame_Vtx[116+11].ob[0] = kscope->map_frame_Vtx[116+8].ob[0] + 19;
    kscope->map_frame_Vtx[116+8].ob[1] = kscope->map_frame_Vtx[116+9].ob[1] = kscope->map_frame_Vtx[116+8].ob[1] - 2;
    kscope->map_frame_Vtx[116+10].ob[1] = kscope->map_frame_Vtx[116+11].ob[1] = kscope->map_frame_Vtx[116+8].ob[1] - 19;
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[116]), 12, 0);
   /* ¥ê¥ó¥¯¤Î´é */
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, kscope->alpha );
    kscope->map_frame_Vtx[116].ob[1] = kscope->map_frame_Vtx[117].ob[1] = 50 + kscope->yp - (14*VREG(30)) - 1;
    kscope->map_frame_Vtx[118].ob[1] = kscope->map_frame_Vtx[119].ob[1] = kscope->map_frame_Vtx[116].ob[1] - 16;
    gDPLoadTextureBlock( NEXT_DISP,
			 h_link_txt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
			 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    /* ¥Ü¥¹ */
    if ( GetKeyCompassMap(Scene_ID,H_compass) && MAP_EXP_DATA_TBL(boss_position)[Scene_ID] != BOSS_8 ) {	/* ¥³¥ó¥Ñ¥¹»ý¤Ã¤Æ¤¤¤ë¤«¡© */
	kscope->map_frame_Vtx[120].ob[1] = kscope->map_frame_Vtx[121].ob[1] = MAP_EXP_DATA_TBL(boss_position)[Scene_ID] + kscope->yp;
	kscope->map_frame_Vtx[122].ob[1] = kscope->map_frame_Vtx[123].ob[1] = kscope->map_frame_Vtx[120].ob[1] - 16;
	gDPLoadTextureBlock( NEXT_DISP,
			     h_boss_txt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
			     G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 4, 6, 7, 5, 0 );
    }
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, kscope->alpha );

    /* ¶â¥¹¥¿¥Þ¡¼¥¯ */
    if ( Get_KIN_STA( Scene_ID ) == kin_sta_suu[Scene_ID] ) {
	kaleido_scope_item_set( graph, h_24_item_3_txt, 24, 24, 8 );
    }



    /* ¥À¥ó¥¸¥ç¥ó£Í£Á£Ð */
////////    if ( !(game_play->scene_data_ID == YDAN_BOSS || game_play->scene_data_ID == DDAN_BOSS || game_play->scene_data_ID == FIRE_BOSS  || game_play->scene_data_ID == MORIBOSS) ) {
    if ( game_play->scene_data_ID >= YDAN && game_play->scene_data_ID < YDAN_BOSS ) {
	r0 = (rc - map_color[pt][0])/cnt;
	g0 = (gc - map_color[pt][1])/cnt;
	b0 = (bc - map_color[pt][2])/cnt;
	rc -= r0;
	gc -= g0;
	bc -= b0;
	rgb = ((rc&0x1f)<<11) | ((gc&0x1f)<<6) | ((bc&0x1f)<<1) | 1;
	parameter->map_palete[28] = ((rgb & 0xff00)>>8);
	parameter->map_palete[29] = (rgb & 0x00ff);
	if ( !(--cnt) ) {
	    pt ^= 1;
	    cnt = 20;
	}
    }
    gDPPipeSync( NEXT_DISP );
    gDPSetTextureFilter( NEXT_DISP, G_TF_POINT );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, kscope->alpha );
    gDPLoadTLUT_pal16( NEXT_DISP, 0, parameter->map_palete );
    gDPSetTextureLUT( NEXT_DISP, G_TT_RGBA16 );
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[60]), 8, 0);
    gDPLoadTextureBlock_4b( NEXT_DISP,
			    parameter->mapSegment, G_IM_FMT_CI, 48, 85, 0,
			    G_TX_NOMIRROR, G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    gDPLoadTextureBlock_4b( NEXT_DISP,
			    parameter->mapSegment+4096/2, G_IM_FMT_CI, 48, 85, 0,
			    G_TX_NOMIRROR, G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 4, 6, 7, 5, 0 );
////////    }

    gDPPipeSync( NEXT_DISP );
    gDPSetTextureFilter( NEXT_DISP, G_TF_BILERP );

    CLOSE_DISP( graph );
}





















/*¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷
  ¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷
  ¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷   ¥Õ¥£¡¼¥ë¥ÉÌÌ   ¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷
  ¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷
  ¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷¡÷*/

/*===============================================================
  =	   ¥Õ¥£¡¼¥ë¥É£Í£Á£ÐÌÌ ºîÀ®				=
  ===============================================================*/
extern void
field_map_disp( Game_play *game_play, Graph *graph )
{
    Kscope		*kscope = (Kscope *)&game_play->kscope;

# if 0
    /* ¥«¡¼¥½¥ëÁªÂò£Ø°ÌÃÖ */
    static short check_xdata[] = {
	 -24,  -23, -200,  -24,
	-200, -200,  -48,   34,
	-200, -200, -200, -200,
	-200,   13, -200, -200,
	-200,   60, -200,  -80,
	 -84, -200, -200,
    };	
    /* ¥«¡¼¥½¥ëÁªÂò£Ù°ÌÃÖ */
    static short check_ydata[] = {
	  -9,   18, -200,   32,
	-200, -200,  -37,  -25,
	-200, -200, -200, -200,
	-200,   56, -200, -200,
	-200,   33, -200,    5,
	  28, -200, -200,
    };
    /* ¥«¡¼¥½¥ëÁªÂòÉý */
    static short check_data[] = {
	 24,  24,  24,  24,
	 24,  24,  24,  24,
	 24,  24,  24,  24,
	 24,  24,  24,  24,
	 24,  24,  24,  24,
	 24,  24,  24,
    };	
# endif    
    short	i, j, k, n;
    short	nowp;

    static unchar *cloud_txt_dt[] = {
	h_cloud_16_txt, h_cloud_15_txt, h_cloud_14_txt, h_cloud_13_txt,
	h_cloud_12_txt, h_cloud_11_txt, h_cloud_10_txt, h_cloud_09_txt,
	h_cloud_08_txt, h_cloud_07_txt, h_cloud_06_txt, h_cloud_05_txt,
	h_cloud_04_txt, h_cloud_03_txt, h_cloud_02_txt, h_cloud_01_txt,
    };
/*
    static unshort cloud_x[] = {
	 32,112, 32, 48, 32, 32, 32, 48,
	 32, 64, 32, 48, 48, 48, 48, 64,
	112,112,
    };
    static unshort cloud_y[] = {
	24, 24, 13, 22, 19, 20, 19, 27,
	14, 26, 22, 21, 49, 32, 45, 60,
	24, 24,
    };
    */
    static unshort cloud_number[] = {
	  5,  0, 19, 14,
	 15,  1,  2, 16,
	 18,  3,  7,  8,
	  9, 12, 11,  6,
    };


    static short prim_rgb[3] = {
	0,   0, 255,
    };
    static short prim_color[][3] = {
    	{   0,   0, 255, },
    	{ 255, 255,   0, },	// ´ðËÜ
    };
    static short env_rgb[3] = {
	255, 255, 0,
    };
    static short env_color[][3] = {
    	{ 255, 255,   0, },
    	{   0,   0, 255, },	// ´ðËÜ
    };
    static short mark_color_pt = 1;
    static short mark_color_ct = 20;
    short	rc, gc, bc;
    static short xsize[] = {
	64, 64, 64, 28,
    };

    static short area_xdt[] = {
	-41,  19,  44,  40,
	 49,  51, -49,  83,
	 80, -67,  50,-109,
	-76, -86, -10,  -6,
	 19,  24,  11, -17,
	 37,  -6,
    };
    static short area_xsz[] = {
	96, 32, 32, 48,
	48, 32, 48, 32,
	32, 32, 16, 32,
	32, 16, 32, 32,
	32, 32, 32, 32,
	16, 32,
    };
    static short area_ydt[] = {
	 30,  36,  35,  26,
	  7,  11, -31,  30,
	 38,  23,   2,  42,
	 40,  32,  38,  50,
	 57,  58,  56,  12,
	 36,  50,
    };
    static short area_ysz[] = {
	59, 19, 13, 19,
	38, 17, 38, 17,
	13, 26, 16, 26,
	26, 16, 19, 17,
	26, 13, 17, 17,
	16, 17,
    };
    static unchar *area_data_txt[] = {
	h_area_g_txt, h_area_a_txt, h_area_d_txt, h_area_f_txt,
	h_area_b_txt, h_area_c_txt, h_area_b_txt, h_area_c_txt,
	h_area_d_txt, h_area_e_txt, h_area_h_txt, h_area_e_txt,
	h_area_e_txt, h_area_h_txt, h_area_a_txt, h_area_c_txt,
	h_area_e_txt, h_area_d_txt, h_area_c_txt, h_area_c_txt,
	h_area_h_txt, h_area_c_txt,
    };
    static unchar *here_txt[] = {
	h_here_txt, h_here_nes_txt,
    };
/*    static short area_color[][4] = {
    	{100, 255, 255, 255, },
    	{  0, 255, 255, 100, },
    };
    static short	mc = 20, mp = 0;
    static short	red = 0, green = 255, blue = 255, alpha = 100;*/
    static unshort	spot_timer = 0;
#define MAP_PT 11
    
    OPEN_DISP( graph );

    if ( kscope->pause == Pause_Play && !kscope->kscp_status && kscope->kscp_pos == Display_Map ) {
	kscope->cursor_colp = Cursor_Red;
	nowp = kscope->cursor_point[Display_Map_Field]; 
	if ( !kscope->key_angle ) {
	    /* ¥¢¥¤¥Æ¥à¥«¡¼¥½¥ë°ÌÃÖ¥Á¥§¥Ã¥¯ */
	    if ( kscope->wkey_x > KEY_ANGLE_3D ) {
		do {
		    spot_timer = 0;
		    if ( ++kscope->cursor_point[Display_Map_Field] > MAP_PT ) {
			kscope->cursor_point[Display_Map_Field] = MAP_PT;
			key_arrangement( game_play, HD_RIGHT );
			break;
		    }
		} while ( !kscope->field_map_evt[kscope->cursor_point[Display_Map_Field]] );
	    } else if ( kscope->wkey_x < -KEY_ANGLE_3D ) {
		do {
		    spot_timer = 0;
		    if ( --kscope->cursor_point[Display_Map_Field] < 0 ) {
			kscope->cursor_point[Display_Map_Field] = 0;
			key_arrangement( game_play, HD_LEFT );
			break;
		    }
		} while ( !kscope->field_map_evt[kscope->cursor_point[Display_Map_Field]] );
	    } else {
		++spot_timer;
	    }
	    kscope->select_name[Display_Map] = kscope->cursor_point[Display_Map_Field];
/*	    if ( spot_timer >= 0x40 && (spot_timer & 0x20) ) kscope->select_name[Display_Map] = YREG(21) + ((H_place00 - H_map00) << 1);*/
	    kscope->select_pt[Display_Map] = kscope->cursor_point[Display_Map_Field] + ((5*3)+16);
	    cursol_defalute( kscope, kscope->select_pt[Display_Map]*4, kscope->map_frame_Vtx );
	} else {
	    kscope->select_name[Display_Map] = ZCommonGet( area_type )/*YREG(21)*/ + ((H_place00 - H_map00) << 1);
	    if ( kscope->key_angle == HD_LEFT ) {
		if ( kscope->wkey_x > KEY_ANGLE_3D ) {
		    kscope->key_angle = 0;
		    kscope->cursor_point[Display_Map_Field] = 0;
		    while ( !kscope->field_map_evt[kscope->cursor_point[Display_Map_Field]] ){
			++kscope->cursor_point[Display_Map_Field];
		    }
		    kscope->select_name[Display_Map] = kscope->cursor_point[Display_Map_Field];
		    kscope->select_pt[Display_Map] = kscope->cursor_point[Display_Map_Field] + ((5*3)+16);
		    cursol_defalute( kscope, kscope->select_pt[Display_Map]*4, kscope->map_frame_Vtx );
		    Na_StartSystemSe( NA_SE_SY_CURSOR );
		    spot_timer = 0;
		}
	    } else {
		if ( kscope->wkey_x < -KEY_ANGLE_3D ) {
		    kscope->key_angle = 0;
		    kscope->cursor_point[Display_Map_Field] = MAP_PT;
		    while ( !kscope->field_map_evt[kscope->cursor_point[Display_Map_Field]] ){
			--kscope->cursor_point[Display_Map_Field];
		    }
		    kscope->select_name[Display_Map] = kscope->cursor_point[Display_Map_Field];
		    kscope->select_pt[Display_Map] = kscope->cursor_point[Display_Map_Field] + ((5*3)+16);
		    cursol_defalute( kscope, kscope->select_pt[Display_Map]*4, kscope->map_frame_Vtx );
		    Na_StartSystemSe( NA_SE_SY_CURSOR );
		    spot_timer = 0;
		}
	    }
	}
	if ( !kscope->field_map_evt[kscope->cursor_point[Display_Map_Field]] )
	    kscope->select_name[Display_Map] = 999;
	if ( nowp != kscope->cursor_point[Display_Map_Field] )
	    Na_StartSystemSe( NA_SE_SY_CURSOR );
    }
    /* ¥Õ¥£¡¼¥ë¥É£Í£Á£ÐÉ½¼¨ */
    gDPPipeSync( NEXT_DISP );
    gDPSetTextureFilter( NEXT_DISP, G_TF_POINT );
    gDPLoadTLUT_pal256 ( NEXT_DISP, h_fieldmap_pal );
    gDPSetTextureLUT ( NEXT_DISP, G_TT_RGBA16 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, kscope->alpha );
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16+12+1+1+1+1)*4]), 32, 0);
    for ( j = k = n = 0; n < 8; n++, k++, j+=4 ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_fieldmap+(216*9*k), G_IM_FMT_CI, G_IM_SIZ_8b, 216, 9, 0,
			     G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
    }
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16+12+1+1+1+1+8)*4]), 28, 0);
    for ( j = n = 0; n < 6; n++, k++, j+=4 ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_fieldmap+(216*9*k), G_IM_FMT_CI, G_IM_SIZ_8b, 216, 9, 0,
			     G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
    }
    gDPLoadTextureBlock( NEXT_DISP,
			 h_fieldmap+(216*9*k), G_IM_FMT_CI, G_IM_SIZ_8b, 216, 2, 0,
			 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );


    /* ±ÀÉ½¼¨ */
    if ( !ZREG(38) ) {
    gDPPipeSync( NEXT_DISP );
    gDPSetTextureFilter( NEXT_DISP, G_TF_BILERP );
    kaleido_scope_prim( graph );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT2, G_CC_INT2 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 235, 235, 235, kscope->alpha );
    for ( i = 0; i < 15; i+=8 ) {
	gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+i)*4]), 32, 0);
	for ( j = n = 0; n < 8; n++, j+=4 ) {
	    if ( !(S_Information.area_arrival & check_bit[cloud_number[i+n]]) ) {
		gDPLoadTextureBlock_4b( NEXT_DISP,
					cloud_txt_dt[i+n], G_IM_FMT_I,
////////					cloud_x[i+n], cloud_y[i+n], 0,
					partvtx_mapg_xsz[i+n], partvtx_mapg_ysz[i+n], 0,
					G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
					G_TX_NOMASK, G_TX_NOMASK,
					G_TX_NOLOD, G_TX_NOLOD );
		gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
	    }
	}
    }
# if 0
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16)*4]), 8, 0);
    if ( !(S_Information.area_arrival & check_bit[cloud_number[1]]) ) {
	for ( j = n = 0; n < 2; n++, j+=4 ) {
	    gDPLoadTextureBlock_4b( NEXT_DISP,
				    cloud_txt_dt[16+n], G_IM_FMT_I,
////////				    cloud_x[16+n], cloud_y[16+n], 0,
				    partvtx_mapg_xsz[16+n], partvtx_mapg_ysz[16+n], 0,
				    G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
				    G_TX_NOMASK, G_TX_NOMASK,
				    G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
	}
    }
# endif
    }

    /* ¥¨¥ê¥¢É½¼¨ */
    if ( ZCommonGet( area_type )/*YREG(21)*/ <= 21 ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetTextureFilter( NEXT_DISP, G_TF_POINT );
	kscope->map_frame_Vtx[((5*3)+16+12)*4+0].ob[0] = kscope->map_frame_Vtx[((5*3)+16+12)*4+2].ob[0] = area_xdt[ZCommonGet( area_type )/*YREG(21)*/];
	kscope->map_frame_Vtx[((5*3)+16+12)*4+1].ob[0] = kscope->map_frame_Vtx[((5*3)+16+12)*4+3].ob[0] = kscope->map_frame_Vtx[((5*3)+16+12)*4].ob[0] + area_xsz[ZCommonGet( area_type )/*YREG(21)*/];
	kscope->map_frame_Vtx[((5*3)+16+12)*4+0].ob[1] = kscope->map_frame_Vtx[((5*3)+16+12)*4+1].ob[1] = area_ydt[ZCommonGet( area_type )/*YREG(21)*/] + kscope->yp;
	kscope->map_frame_Vtx[((5*3)+16+12)*4+2].ob[1] = kscope->map_frame_Vtx[((5*3)+16+12)*4+3].ob[1] = kscope->map_frame_Vtx[((5*3)+16+12)*4+0].ob[1] - area_ysz[ZCommonGet( area_type )/*YREG(21)*/];
	
	kscope->map_frame_Vtx[((5*3)+16+12)*4+1].tc[0] = kscope->map_frame_Vtx[((5*3)+16+12)*4+3].tc[0] = area_xsz[ZCommonGet( area_type )/*YREG(21)*/] << 5;
	kscope->map_frame_Vtx[((5*3)+16+12)*4+2].tc[1] = kscope->map_frame_Vtx[((5*3)+16+12)*4+3].tc[1] = area_ysz[ZCommonGet( area_type )/*YREG(21)*/] << 5;
	/* »Ø¥«¡¼¥½¥ëÉ½¼¨ */
/*    rc = (ABS(red - area_color[mp][0] )) / mc;
      gc = (ABS(green - area_color[mp][1] )) / mc;
      bc = (ABS(blue - area_color[mp][2] )) / mc;
      ac = (ABS(alpha - area_color[mp][3] )) / mc;
      if ( red >= area_color[mp][0] ) red -= rc;
      else                            red += rc;
      if ( green >= area_color[mp][1] ) green -= gc;
      else                              green += gc;
      if ( blue >= area_color[mp][2] ) blue -= bc;
      else                             blue += bc;
      if ( alpha >= area_color[mp][3] ) alpha -= ac;
      else                              alpha += ac;
      if ( !(--mc) ) {
      red = area_color[mp][0];
      green = area_color[mp][1];
      blue = area_color[mp][2];
      alpha = area_color[mp][3];
      mc = 40;
      mp ^= 1;
      }*/
	gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16+12)*4]), 4, 0);
/*
  if ( ZCommonGet( area_type ) == 10 || ZCommonGet( area_type ) == 13 || ZCommonGet( area_type ) == 20 ) {
  gDPSetCombineMode( NEXT_DISP, G_CC_INT3, G_CC_INT3 );
////////	gDPSetPrimColor( NEXT_DISP, 0, 0, 100, 255, 255, kscope->alpha );
gDPSetPrimColor( NEXT_DISP, 0, 0, red, green, blue, alpha );
gDPLoadTextureBlock( NEXT_DISP,
area_data_txt[ZCommonGet( area_type )], G_IM_FMT_IA, G_IM_SIZ_8b,
area_xsz[ZCommonGet( area_type )], area_ysz[ZCommonGet( area_type )], 0,
G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
} else {
////////	gDPSetCombineMode( NEXT_DISP, G_CC_INT2, G_CC_INT2 );
////////	gDPSetPrimColor( NEXT_DISP, 0, 0, red, green, blue, alpha );
gDPSetCombineMode( NEXT_DISP, G_CC_INT3, G_CC_INT3 );
gDPSetPrimColor( NEXT_DISP, 0, 0, 0, 255, 255, kscope->alpha );
gDPLoadTextureBlock_4b( NEXT_DISP,
area_data_txt[ZCommonGet( area_type )], G_IM_FMT_IA,
				area_xsz[ZCommonGet( area_type )], area_ysz[ZCommonGet( area_type )], 0,
				G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
				G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
				}*/
	gDPSetCombineMode( NEXT_DISP, G_CC_INT3, G_CC_INT3 );
	gDPSetPrimColor( NEXT_DISP, 0, 0, 100, 255, 255, kscope->alpha );
	gDPLoadTextureBlock_4b( NEXT_DISP,
				area_data_txt[ZCommonGet( area_type )/*YREG(21)*/], G_IM_FMT_IA,
				area_xsz[ZCommonGet( area_type )/*YREG(21)*/], area_ysz[ZCommonGet( area_type )/*YREG(21)*/], 0,
				G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
				G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
	
	gDPPipeSync( NEXT_DISP );
	gDPSetTextureFilter( NEXT_DISP, G_TF_BILERP );
    }


    /* ¥À¥ó¥¸¥ç¥ó¡¦¥Þ¡¼¥¯ÅÀÌÇ */
    rc = (ABS(prim_rgb[0] - prim_color[mark_color_pt][0] )) / mark_color_ct;
    gc = (ABS(prim_rgb[1] - prim_color[mark_color_pt][1] )) / mark_color_ct;
    bc = (ABS(prim_rgb[2] - prim_color[mark_color_pt][2] )) / mark_color_ct;
    if ( prim_rgb[0] >= prim_color[mark_color_pt][0] ) prim_rgb[0] -= rc;
    else                                               prim_rgb[0] += rc;
    if ( prim_rgb[1] >= prim_color[mark_color_pt][1] ) prim_rgb[1] -= gc;
    else                                               prim_rgb[1] += gc;
    if ( prim_rgb[2] >= prim_color[mark_color_pt][2] ) prim_rgb[2] -= bc;
    else                                               prim_rgb[2] += bc;

    rc = (ABS(env_rgb[0] - env_color[mark_color_pt][0] )) / mark_color_ct;
    gc = (ABS(env_rgb[1] - env_color[mark_color_pt][1] )) / mark_color_ct;
    bc = (ABS(env_rgb[2] - env_color[mark_color_pt][2] )) / mark_color_ct;
    if ( env_rgb[0] >= env_color[mark_color_pt][0] ) env_rgb[0] -= rc;
    else                                             env_rgb[0] += rc;
    if ( env_rgb[1] >= env_color[mark_color_pt][1] ) env_rgb[1] -= gc;
    else                                             env_rgb[1] += gc;
    if ( env_rgb[2] >= env_color[mark_color_pt][2] ) env_rgb[2] -= bc;
    else                                             env_rgb[2] += bc;

    if ( !(--mark_color_ct) ) {
	prim_rgb[0] = prim_color[mark_color_pt][0];
	prim_rgb[1] = prim_color[mark_color_pt][1];
	prim_rgb[2] = prim_color[mark_color_pt][2];
	env_rgb[0] = env_color[mark_color_pt][0];
	env_rgb[1] = env_color[mark_color_pt][1];
	env_rgb[2] = env_color[mark_color_pt][2];
	mark_color_ct = 20;
	mark_color_pt ^= 1;
    }

    kaleido_scope_prim( graph );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPLoadTextureBlock( NEXT_DISP,
			 h_dungeon_mark_0_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0,
			 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    for ( j = n = 0; n < 12; n++, k++, j+=4 ) {
	if ( kscope->field_map_evt[n] ) {
	    gDPPipeSync( NEXT_DISP );
	    if ( kscope->field_map_evt[n] == 1 ) {
		gDPSetPrimColor( NEXT_DISP, 0, 0, prim_color[0][0], prim_color[0][1], prim_color[0][2], kscope->alpha );
		gDPSetEnvColor( NEXT_DISP, env_color[0][0], env_color[0][1], env_color[0][2], 0 );
	    } else {
		gDPSetPrimColor( NEXT_DISP, 0, 0, prim_rgb[0], prim_rgb[1], prim_rgb[2], kscope->alpha );
		gDPSetEnvColor( NEXT_DISP, env_rgb[0], env_rgb[1], env_rgb[2], 0 );
	    }
	    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16+n)*4]), 4, 0);
	    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
	}
    }


    /* ¥¢¥¤¥Æ¥à¥«¡¼¥½¥ëÉ½¼¨ */
    if ( !kscope->key_angle ) {
	cursor_draw( game_play, Display_Map );
    }

    /* ¤ï¤é¤·¤Ù¥Þ¡¼¥¯ */
    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16+12+1)*4]), 16, 0);
    if ( kscope->warashibe_flag != 0xff ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT3, G_CC_INT3 );
//    gSPVertex( NEXT_DISP, &(kscope->map_frame_Vtx[((5*3)+16+12+1)*4]), 4, 0);
	gDPSetPrimColor( NEXT_DISP, 0, 0, 255, prim_rgb[0],  0, kscope->alpha );
	gDPLoadTextureBlock( NEXT_DISP,
			     h_wara_yajirusi_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 8, 0,
			     G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    }

    if ( ZCommonGet( area_type )/*YREG(21)*/ <= 21 ) {
	/* ¸½ºßÃÏÌ¾ */
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode(NEXT_DISP, G_CC_INT9, G_CC_INT9);
	gDPSetPrimColor( NEXT_DISP, 0, 0, 150, 255, 255, kscope->alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
/*    gDPLoadTextureBlock( NEXT_DISP,
      kscope->item_nameSegment + I_N_PT, G_IM_FMT_IA, G_IM_SIZ_8b, 80, 32, 0,
      G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
      G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
      gSP1Quadrangle( NEXT_DISP, 4, 6, 7, 5, 0 );*/
	SET_NOW_DISP( texture_QuadrangleIA8( NOW_DISP, kscope->item_nameSegment + (I_N_PT/2),
					     80, 32,
					     4 )
	    );
    }

    /* ¸½ºßÃÏ */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode(NEXT_DISP, G_CC_INT2, G_CC_INT2);
    gDPSetPrimColor( NEXT_DISP, 0, 0, 0, 0, 0, kscope->alpha );
    gDPLoadTextureBlock_4b( NEXT_DISP,
			    here_txt[J_N], G_IM_FMT_I, 64, 8, 0,
			    G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 8, 10, 11, 9, 0 );

    gDPPipeSync( NEXT_DISP );
    
    CLOSE_DISP( graph );
}

