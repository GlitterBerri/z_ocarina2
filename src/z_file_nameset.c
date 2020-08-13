/* $Id: z_file_nameset.c,v 2.4 1999/01/19 02:15:16 soejima Exp $
 *
 * ¥Õ¥¡¥¤¥ëÁªÂò½èÍý¡ØÌ¾Á°ÅÐÏ¿¡Ù
 *
 * $Log: z_file_nameset.c,v $
 * Revision 2.4  1999/01/19  02:15:16  soejima
 * £Ç£Á£Ô£Å£×£Á£Ù»ÅÍÍ
 *
 * Revision 2.3  1999-01-07 13:27:56+09  soejima
 * £Ç£Á£Ô£Å£×£Á£Ù»ÅÍÍ
 *
 * Revision 2.2  1998-11-06 12:07:52+09  soejima
 * ¥³¥á¥ó¥È
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.72  1998/10/05 14:01:17  soejima
 * *** empty log message ***
 *
 * Revision 1.71  1998-10-02 23:07:14+09  soejima
 * *** empty log message ***
 *
 * Revision 1.70  1998-10-01 11:28:32+09  takahata
 * *** empty log message ***
 *
 * Revision 1.69  1998-09-25 22:18:30+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/07/31  09:56:47  soejima
 * Initial revision
 * $LogÄÉ²Ã
 * */


/************************************************************************
 *									*
 *	Ì¾Á°ÅÐÏ¿½èÍý £Í£Á£É£Î						*
 *				1997Ç¯04·î15Æü(²ÐÍËÆü) 14»þ00Ê¬00ÉÃ JST *
 ************************************************************************/
#include "z_basic.h"
#include "z_play.h"		/* game_set_next_game_nameÍÑ */
#include "z_rcp.h"		/* DisplayList_initializeÍÑ */
#include "z_define1.h"
#include "z_common_data.h"	/* z_common_data_t */

#include "z_file_choose.h"
#include "z_file_choose_h.h"
#include "z_file_choose_data.h"
#include "z_file_choose_parameterd.h"
#include "z_file_nameset.h"
#include "z_kaleido_moji.h"
#include "z_parameterd.h"
#include "z_sram.h"
#include "z_sram_h.h"
#include "z_common_data.h"
#include "z_save_area_h.h"


extern void
cursor_color_change( Game *thisx );

extern void
sram_sound_save( Sram *sram );


/*----------------------------------------------------------------------*/
/*									*/
/*----------------------------------------------------------------------*/
static char	H_Move_index;


/*=======================================================================
  =	Ê¸»ú¥»¥Ã¥È							=
  =======================================================================*/
extern void
file_choose_moji_set( Graph *graph, unchar *data, short j )
{
    OPEN_DISP( graph );

    gDPLoadTextureBlock_4b ( NEXT_DISP,
			     data, G_IM_FMT_I, 16, 16, 0,
			     G_TX_CLAMP,  G_TX_CLAMP,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD,  G_TX_NOLOD);
    gSP1Quadrangle( NEXT_DISP, j, j+2, j+3, j+1, 0 );

    CLOSE_DISP( graph );
}

/*=======================================================================
  =	¥â¨¡¥Õ¥£¥ó¥°Ê¸»ú¥»¥Ã¥È						=
  =======================================================================*/
extern void
morph_moji_set( Graph *graph, unchar *data, unchar *data1, short j )
{
    OPEN_DISP( graph );

    gDPLoadMultiBlock_4b( NEXT_DISP,
			  data, 0, G_TX_RENDERTILE,
			  G_IM_FMT_I, 16, 16, 0,
			  G_TX_NOMIRROR, G_TX_NOMIRROR,
			  G_TX_NOMASK, G_TX_NOMASK,
			  G_TX_NOLOD, G_TX_NOLOD );
    gDPLoadMultiBlock_4b( NEXT_DISP,
			  data1, 128, G_TX_RENDERTILE+1,
			  G_IM_FMT_I, 16, 16, 0,
			  G_TX_NOMIRROR, G_TX_NOMIRROR,
			  G_TX_NOMASK, G_TX_NOMASK,
			  G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, j, j+2, j+3, j+1, 0 );

    CLOSE_DISP( graph );
}



/*=======================================================================
  =	Ì¾Á°ÅÐÏ¿²èÌÌ£Ö£ô£ø¥Ç¡¼¥¿£á£ì£ì£ï£ã				=
  =======================================================================*/
static void
nameset_vtx_set( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    short	i, j, mjp, xp, yp;
#define	M_Size		12


    this->characterVtx = (Vtx_t *)graph_alloc(this->g.graph, sizeof(Vtx_t) * (13 * 5 * 4));
    /* ¤¢ ¤« ¤µ ¤¿ ¤Ê ¤Ï ¤Þ ¤ä ¤é ¤ï ¤¡ ¤ã ¤Ã */
    /* ¤¤ ¤­ ¤· ¤Á ¤Ë ¤Ò ¤ß    ¤ê    ¤£       */
    /* ¤¦ ¤¯ ¤¹ ¤Ä ¤Ì ¤Õ ¤à ¤æ ¤ë ¤ò ¤¥ ¤å ¨¡ */
    /* ¤¨ ¤± ¤» ¤Æ ¤Í ¤Ø ¤á    ¤ì    ¤§     ¡«*/
    /* ¤ª ¤³ ¤½ ¤È ¤Î ¤Û ¤â ¤è ¤í ¤ó ¤© ¤ç  ¡¬*/
	/* ¥¢ ¥« ¥µ ¥¿ ¥Ê ¥Ï ¥Þ ¥ä ¥é ¥ï ¥¡ ¥ã ¥Ã */
	/* ¥¤ ¥­ ¥· ¥Á ¥Ë ¥Ò ¥ß    ¥ê    ¥£       */
	/* ¥¦ ¥¯ ¥¹ ¥Ä ¥Ì ¥Õ ¥à ¥æ ¥ë ¥ò ¥¥ ¥å ¨¡ */
	/* ¥¨ ¥± ¥» ¥Æ ¥Í ¥Ø ¥á    ¥ì    ¥§    ¡« */
	/* ¥ª ¥³ ¥½ ¥È ¥Î ¥Û ¥â ¥è ¥í ¥ó ¥© ¥ç ¡¬ */
    /* £Á £Â £Ã £Ä £Å £Æ £Ç £È £É £Ê £Ë £Ì £Í */
    /* £Î £Ï £Ð £Ñ £Ò £Ó £Ô £Õ £Ö £× £Ø £Ù £Ú */
    /* £á £â £ã £ä £å £æ £ç £è £é £ê £ë £ì £í */
    /* £î £ï £ð £ñ £ò £ó £ô £õ £ö £÷ £ø £ù £ú */
    /* £± £² £³ £´ £µ £¶ £· £¸ £¹ £° ¡¥ ¨¡    */    
    yp = 38;
    for ( i = mjp = 0; mjp < 5; mjp++ ) {
	for ( xp = -96, j = 0; j < 13; j++, i+=4 ) {
	    this->characterVtx[i+0].ob[0] = this->characterVtx[i+2].ob[0] = xp;
	    this->characterVtx[i+1].ob[0] = this->characterVtx[i+3].ob[0] = (short)(xp + M_Size);
	    this->characterVtx[i+0].ob[1] = this->characterVtx[i+1].ob[1] = yp;
	    this->characterVtx[i+2].ob[1] = this->characterVtx[i+3].ob[1] = (short)(yp - M_Size);
	    this->characterVtx[i+0].ob[2] = this->characterVtx[i+1].ob[2] = 
		this->characterVtx[i+2].ob[2] = this->characterVtx[i+3].ob[2] = 0;
	    this->characterVtx[i+0].flag = this->characterVtx[i+1].flag = 
		this->characterVtx[i+2].flag = this->characterVtx[i+3].flag = 0;
	    this->characterVtx[i+0].tc[0] = this->characterVtx[i+0].tc[1] = 
		this->characterVtx[i+1].tc[1] = this->characterVtx[i+2].tc[0] = 0;
	    this->characterVtx[i+1].tc[0] = this->characterVtx[i+2].tc[1] = 
		this->characterVtx[i+3].tc[0] = this->characterVtx[i+3].tc[1] = 16<<5;
	    this->characterVtx[i+0].cn[0] = this->characterVtx[i+1].cn[0] = 
		this->characterVtx[i+2].cn[0] = this->characterVtx[i+3].cn[0] = 
		this->characterVtx[i+0].cn[1] = this->characterVtx[i+1].cn[1] = 
		this->characterVtx[i+2].cn[1] = this->characterVtx[i+3].cn[1] = 
		this->characterVtx[i+0].cn[2] = this->characterVtx[i+1].cn[2] = 
		this->characterVtx[i+2].cn[2] = this->characterVtx[i+3].cn[2] =
		this->characterVtx[i+0].cn[3] = this->characterVtx[i+1].cn[3] = 
		this->characterVtx[i+2].cn[3] = this->characterVtx[i+3].cn[3] = 255;
	    xp += 16;
	}
	yp -= 16;
    }
}    



/*=======================================================================
  =	Ì¾Á°ÅÐÏ¿²èÌÌ´ðËÜÉ½¼¨						=
  =======================================================================*/
static void
nameset_basic_display( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kanfont	*kanfont = (Kanfont *)&this->kanfont;

    static unchar *h_namae_txt_data[] = {
	h_namae_txt, h_namae_nes_txt,
    };
    static unshort *plate_no_data[] = {
	h_n_hira_txt, h_n_kata_txt, h_n_eisu_txt, h_n_modo_txt, h_n_kettei_txt,
    };
    static unshort plate_xsize[] = {
	44, 44, 28, 28, 44,
    };
    static short cursorXps[] = {
	-30,
	-16,  -6,   4,  14,  24,  34,  44,  54,
	-16, -16,
    };
    static short cursorYps[] = {
	 72,
	 69,  69,  69,  69,  69,  69,  69,  69,
	 69,  69,
    };

    short	i, j, mjp = 0;



    OPEN_DISP( this->g.graph );


    /* ¥¿¥¤¥È¥ëÌ¾ */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    gSPVertex( NEXT_DISP, &(menu_select_titlevtx[0]), 24, 0);
    gDPLoadTextureBlock( NEXT_DISP,
			 h_namae_txt_data[J_N], G_IM_FMT_IA, G_IM_SIZ_8b,
			 56, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );

    /* ³Æ¥×¥ì¡¼¥È */
    gDPPipeSync( NEXT_DISP );
    for ( i = 0, j = 4; i < 5; i++, j+=4 ) {
	if ( !J_N ) {
	    gDPPipeSync( NEXT_DISP );
/*	if ( this->name_page <= Eisu_eisu && i == this->name_page ) {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], WREG(4) );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	} else {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], 255 );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	}*/
	    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], 255 );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	    gDPLoadTextureBlock( NEXT_DISP,
				 plate_no_data[i], G_IM_FMT_IA, G_IM_SIZ_16b,
				 plate_xsize[i], 16, 0,
				 G_TX_NOMIRROR, G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
	} else if ( i >= 3 ) {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], 255 );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	    gDPLoadTextureBlock( NEXT_DISP,
				 plate_no_data[i], G_IM_FMT_IA, G_IM_SIZ_16b,
				 plate_xsize[i], 16, 0,
				 G_TX_NOMIRROR, G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
	}
    }

    /* Ì¾Á°£Ö£ô£ø¥Ç¡¼¥¿£á£ì£ì£ï£ã */
    this->cursorVtx = (Vtx_t *)graph_alloc(this->g.graph, sizeof(Vtx_t) * (1+8+2) * 4);
    for( i = j = 0; i < (1+8+2)*4; i+=4, j++ ) {
	    this->cursorVtx[i+0].ob[0] = this->cursorVtx[i+2].ob[0] = cursorXps[j] + this->shift_xp;
	    this->cursorVtx[i+1].ob[0] = this->cursorVtx[i+3].ob[0] = this->cursorVtx[i+0].ob[0] + 10;
	    this->cursorVtx[i+0].ob[1] = this->cursorVtx[i+1].ob[1] = cursorYps[j];
	    this->cursorVtx[i+2].ob[1] = this->cursorVtx[i+3].ob[1] = this->cursorVtx[i+0].ob[1] - 10;
	    this->cursorVtx[i+0].ob[2] = this->cursorVtx[i+1].ob[2] = 
		this->cursorVtx[i+2].ob[2] = this->cursorVtx[i+3].ob[2] = 0;
	    this->cursorVtx[i+0].flag = this->cursorVtx[i+1].flag = 
		this->cursorVtx[i+2].flag = this->cursorVtx[i+3].flag = 0;
	    this->cursorVtx[i+0].tc[0] = this->cursorVtx[i+0].tc[1] = 
		this->cursorVtx[i+1].tc[1] = this->cursorVtx[i+2].tc[0] = 0;
	    this->cursorVtx[i+1].tc[0] = this->cursorVtx[i+2].tc[1] = 
		this->cursorVtx[i+3].tc[0] = this->cursorVtx[i+3].tc[1] = 16 << 5;
 	    this->cursorVtx[i+0].cn[0] = this->cursorVtx[i+1].cn[0] = 
		this->cursorVtx[i+2].cn[0] = this->cursorVtx[i+3].cn[0] =
		this->cursorVtx[i+0].cn[1] = this->cursorVtx[i+1].cn[1] = 
		this->cursorVtx[i+2].cn[1] = this->cursorVtx[i+3].cn[1] =
		this->cursorVtx[i+0].cn[2] = this->cursorVtx[i+1].cn[2] = 
		this->cursorVtx[i+2].cn[2] = this->cursorVtx[i+3].cn[2] = 
		this->cursorVtx[i+0].cn[3] = this->cursorVtx[i+1].cn[3] = 
		this->cursorVtx[i+2].cn[3] = this->cursorVtx[i+3].cn[3] = 255;
    }

    /* Ì¾Á°¥×¥ì¡¼¥È */
    this->cursorVtx[1].ob[0] = this->cursorVtx[3].ob[0] = this->cursorVtx[0].ob[0] + 108;
    this->cursorVtx[2].ob[1] = this->cursorVtx[3].ob[1] = this->cursorVtx[0].ob[1] - 16;
    this->cursorVtx[1].tc[0] = this->cursorVtx[3].tc[0] = 108 << 5;
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->name_plate_alpha );
    gSPVertex( NEXT_DISP, &(this->cursorVtx[0]), 4, 0);
    gDPLoadTextureBlock( NEXT_DISP,
			 h_name_txt, G_IM_FMT_IA, G_IM_SIZ_16b,
			 108, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    /* Ì¾Á°¡Ê£¸Ê¸»ú¡Ë*/
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT4, G_CC_INT4 );
    gSPVertex( NEXT_DISP, &(this->cursorVtx[4]), 32, 0);
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->name_plate_alpha );
    for ( mjp = j = 0; j < 8*4; j+=4, mjp++ ) {
	file_choose_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(this->name[this->no][mjp])), j );
    }

    /* ¥«¡¼¥½¥ë */
    this->cursorVtx[36+1].tc[0] = this->cursorVtx[36+2].tc[1] = 
	this->cursorVtx[36+3].tc[0] = this->cursorVtx[36+3].tc[1] =
	this->cursorVtx[40+1].tc[0] = this->cursorVtx[40+2].tc[1] = 
	this->cursorVtx[40+3].tc[0] = this->cursorVtx[40+3].tc[1] = 24 << 5;
    if ( this->name_contents == 0 || this->name_contents == 1 || this->name_contents == 4 ) {
	this->cursorVtx[40+1].tc[0] = this->cursorVtx[40+3].tc[0] = 56 << 5;
    } else if ( this->name_contents == 2 || this->name_contents == 3 ) {
	this->cursorVtx[40+1].tc[0] = this->cursorVtx[40+3].tc[0] = 40 << 5;
    }


    CLOSE_DISP( this->g.graph );
}


/*=======================================================================
  =	Ì¾Á°ÅÐÏ¿²èÌÌÉ½¼¨						=
  =======================================================================*/
static void
nameset_display_set( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kanfont	*kanfont = (Kanfont *)&this->kanfont;

    short	i = 0, j, mjp = 0;


    OPEN_DISP( this->g.graph );

    kaleido_scope_prim( this->g.graph );
    gDPSetCycleType( NEXT_DISP, G_CYC_2CYCLE );
    gDPSetRenderMode( NEXT_DISP, G_RM_PASS, G_RM_XLU_SURF2 );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT5, G_CC_PASS2 );
    gDPSetPrimColor( NEXT_DISP, 0, this->page_alpha, 255, 255, 255, 255 );
	
    if ( this->name_page == Hira_hira || this->name_page == Hira_kata || this->name_page == Hira_eisu ) {
	/* ¤¢ ¤« ¤µ ¤¿ ¤Ê ¤Ï ¤Þ ¤ä ¤é ¤ï ¤¡ ¤ã ¤Ã */
	/* ¤¤ ¤­ ¤· ¤Á ¤Ë ¤Ò ¤ß    ¤ê    ¤£       */
	/* ¤¦ ¤¯ ¤¹ ¤Ä ¤Ì ¤Õ ¤à ¤æ ¤ë ¤ò ¤¥ ¤å ¨¡ */
	/* ¤¨ ¤± ¤» ¤Æ ¤Í ¤Ø ¤á    ¤ì    ¤§     ¡«*/
	/* ¤ª ¤³ ¤½ ¤È ¤Î ¤Û ¤â ¤è ¤í ¤ó ¤© ¤ç  ¡¬*/
	if ( this->name_page != Hira_eisu ) {
	    /* ¤Ò¤é¤¬¤Ê ¢ª ¥«¥¿¥«¥Ê */
	    for ( ; i < 256; i += 32 ) {
		gSPVertex( NEXT_DISP, &(this->characterVtx[0+i]), 32, 0);
		for ( j = 0; j < 8*4; j+=4, mjp++ ) {
		    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), j );
		}
	    }
	    gSPVertex( NEXT_DISP, &(this->characterVtx[256]), 4, 0);
	    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), 0 );
	} else {
	    /* ¤Ò¤é¤¬¤Ê ¢ª ±Ñ¿ô */
	    for ( ; i < 256; i += 32 ) {
		gSPVertex( NEXT_DISP, &(this->characterVtx[0+i]), 32, 0);
		for ( j = 0; j < 8*4; j+=4, mjp++ ) {
		    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), j );
		}
	    }
	    gSPVertex( NEXT_DISP, &(this->characterVtx[256]), 4, 0);
	    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), 0 );
	}
    } else if ( this->name_page == Kata_kata || this->name_page == Kata_hira || this->name_page == Kata_eisu ) {
	/* ¥¢ ¥« ¥µ ¥¿ ¥Ê ¥Ï ¥Þ ¥ä ¥é ¥ï ¥¡ ¥ã ¥Ã */
	/* ¥¤ ¥­ ¥· ¥Á ¥Ë ¥Ò ¥ß    ¥ê    ¥£       */
	/* ¥¦ ¥¯ ¥¹ ¥Ä ¥Ì ¥Õ ¥à ¥æ ¥ë ¥ò ¥¥ ¥å ¨¡ */
	/* ¥¨ ¥± ¥» ¥Æ ¥Í ¥Ø ¥á    ¥ì    ¥§    ¡« */
	/* ¥ª ¥³ ¥½ ¥È ¥Î ¥Û ¥â ¥è ¥í ¥ó ¥© ¥ç ¡¬ */
	if ( this->name_page != Kata_eisu ) {
	    /* ¥«¥¿¥«¥Ê ¢ª ¤Ò¤é¤¬¤Ê */
	    for ( ; i < 256; i += 32 ) {
		gSPVertex( NEXT_DISP, &(this->characterVtx[0+i]), 32, 0);
		for ( j = 0; j < 8*4; j+=4, mjp++ ) {
		    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), j );
		}
	    }
	    gSPVertex( NEXT_DISP, &(this->characterVtx[256]), 4, 0);
	    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), 0 );
	} else {
	    /* ¥«¥¿¥«¥Ê ¢ª ±Ñ¿ô */
	    for ( ; i < 256; i += 32 ) {
		gSPVertex( NEXT_DISP, &(this->characterVtx[0+i]), 32, 0);
		for ( j = 0; j < 8*4; j+=4, mjp++ ) {
		    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), j );
		}
	    }
	    gSPVertex( NEXT_DISP, &(this->characterVtx[256]), 4, 0);
	    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), 0 );
	}
    } else {
	/*    £Á £Â £Ã £Ä £Å £Æ £Ç £È £É £Ê £Ë    */
	/*    £Ì £Í £Î £Ï £Ð £Ñ £Ò £Ó £Ô £Õ £Ö    */
	/*    £× £Ø £Ù £Ú ¡¥ ¡¤                   */
	/*    £± £² £³ £´ £µ £¶ £· £¸ £¹ £° ¨¡    */
	/*					  */
	if ( this->name_page != Eisu_kata ) {
	    /* ±Ñ¿ô ¢ª ¤Ò¤é¤¬¤Ê */
	    for ( ; i < 256; i += 32 ) {
		gSPVertex( NEXT_DISP, &(this->characterVtx[0+i]), 32, 0);
		for ( j = 0; j < 8*4; j+=4, mjp++ ) {
		    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), j );
		}
	    }
	    gSPVertex( NEXT_DISP, &(this->characterVtx[256]), 4, 0);
	    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[mjp])), 0 );
	} else {
	    /* ±Ñ¿ô ¢ª ¥«¥¿¥«¥Ê */
	    for ( ; i < 256; i += 32 ) {
		gSPVertex( NEXT_DISP, &(this->characterVtx[0+i]), 32, 0);
		for ( j = 0; j < 8*4; j+=4, mjp++ ) {
		    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), j );
		}
	    }
	    gSPVertex( NEXT_DISP, &(this->characterVtx[256]), 4, 0);
	    morph_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[mjp])), ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[mjp])), 0 );
	}
    }
    
    CLOSE_DISP( this->g.graph );
}




/*===============================================================
  =	   Âù²»¡¿È¾Âù²» ÀÚÂØ½èÍý				=
 ===============================================================*/
static char
dakuonn_change( Game *thisx, short data, short ptd )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    /* Âù²»¡¿È¾Âù²» ÀÚÂØ¥Ç¡¼¥¿ */
    /* £Ú¥Ü¥¿¥óÀÚÂØ */
    static short	check_data00[] = {
	HKA, HHA, HGA, HBA, HPA,
	KKA, KHA, KGA, KBA, KPA,
	KUU, KVI,
    };
    static short	 check_data01[] = {
	HTO, HHO, HDO, HBO, HPO,
	KTO, KHO, KDO, KBO, KPO,
	KUU, KVI,
    };
    static short	 change_data0[] = {
	HGA - HKA, HBA - HHA, HKA - HGA, HPA - HBA, HHA - HPA,
	KGA - KKA, KBA - KHA, KKA - KGA, KPA - KBA, KHA - KPA,
	KVI - KUU, KUU - KVI,
    };
    /* ¡«ÀÚÂØ */
    static short	check_data10[] = {
	HKA, HHA, HPA,
	KKA, KHA, KPA,
	KUU, KVI,
    };
    static short	 check_data11[] = {
	HTO, HHO, HPO,
	KTO, KHO, KPO,
	KUU, KVI,
    };
    static short	 change_data1[] = {
	HGA - HKA, HBA - HHA, HBA - HPA,
	KGA - KKA, KBA - KHA, KBA - KPA,
	KVI - KUU, KUU - KVI,
    };
    /* ¡¬ÀÚÂØ */
    static short	check_data20[] = {
	HHA, HBA,
	KHA, KBA,
    };
    static short	 check_data21[] = {
	HHO, HBO,
	KHO, KBO,
    };
    static short	 change_data2[] = {
	HPA - HHA, HPA - HBA,
	KPA - KHA, KPA - KBA,
    };

    short	i;


    if ( data == SSS ) {		/* ¥¹¥Ú¡¼¥¹ */
	for ( i = 0; i < (sizeof(check_data00)/sizeof(short)); i++ ) {
	    if ( this->name[this->no][ptd] >= check_data00[i] && this->name[this->no][ptd] <= check_data01[i] ) {
		this->name[this->no][ptd] += change_data0[i];
		return(1);
	    }
	}
    } else if ( data == SPJ ) {		/* Âù²» */
	for ( i = 0; i < (sizeof(check_data10)/sizeof(short)); i++ ) {
	    if ( this->name[this->no][ptd] >= check_data10[i] && this->name[this->no][ptd] <= check_data11[i] ) {
		this->name[this->no][ptd] += change_data1[i];
		return(1);
	    }
	}
    } else if ( data == SPK ) {		/* È¾Âù²» */
	for ( i = 0; i < (sizeof(check_data20)/sizeof(short)); i++ ) {
	    if ( this->name[this->no][ptd] >= check_data20[i] && this->name[this->no][ptd] <= check_data21[i] ) {
		this->name[this->no][ptd] += change_data2[i];
		return(1);
	    }
	}
    }
    return(0);
}

/*===============================================================
  =	   Âù²»¡¿È¾Âù²» ÀÚÂØ¥Á¥§¥Ã¥¯				=
  =		¡ÚÆþÎÏ¥Ç¡¼¥¿¡ÛSSS ¡á £Ú¥Ü¥¿¥ó			=
  =			      SPJ ¡á Âù²»			=
  =			      SPK ¡á È¾Âù²»			=
 ===============================================================*/
static char
dakuonn_change_check( Game *thisx, short data )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    short	ptd;

    /* ¸½ºß°ÌÃÖ¥Á¥§¥Ã¥¯ */
    ptd = (short)this->name_index;
    if ( !dakuonn_change( thisx, data, ptd ) ) {
	if ( this->name_index ) {
	    /* £±¸ÄÁ°¥Á¥§¥Ã¥¯ */
	    ptd = (short)(this->name_index - 1);
	    if ( !dakuonn_change( thisx, data, ptd ) ) {
		return(0);
	    }
	} else return(0);
    }
    return(1);
}


# if 0
/*===============================================================
  =	¤Ò¤é¤¬¤Ê¡¿¥«¥¿¥«¥Ê ¢ª ±Ñ¿ô ¥«¡¼¥½¥ë°ÌÃÖ£Ò£Å£Ó£Å£Ô	=
 ===============================================================*/
static void
cursor_reset( Game_file_choose *this )
{
    if ( !this->name_xpos ) {
	this->name_xpos = 1;
	this->mjp++;
    } else if ( this->name_xpos == 12 ) {
	this->name_xpos = 11;
	this->mjp--;
    }
    if ( this->name_ypos == 4 ) {
	this->name_ypos = 3;
	this->mjp -= 13;
    }
}
# endif
/*=======================================================================
  =	Ì¾Á°ÅÐÏ¿É½¼¨							=
  =======================================================================*/
extern void
menu_nameset_display( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kanfont	*kanfont = (Kanfont *)&this->kanfont;

    pad_t	*pad = &this->g.pads[0];

    short	i, m;
    unshort	keep_time;

    OPEN_DISP( this->g.graph );


    /* Ì¾Á°ÅÐÏ¿²èÌÌ£Ö£ô£ø¥Ç¡¼¥¿£á£ì£ì£ï£ã */
    nameset_vtx_set( thisx );

    /* Ì¾Á°ÅÐÏ¿²èÌÌ´ðËÜÉ½¼¨ */
    nameset_basic_display( thisx );

    /*  ¥«¡¼¥½¥ë£Ð£Ò£É£Í¥«¥é¡¼·×»» */
    cursor_color_change( thisx );
    
    
    m = this->name_index * 4 + 4;
    this->cursorVtx[36].ob[0] = this->cursorVtx[36+2].ob[0] = this->cursorVtx[m].ob[0] - 6;
    this->cursorVtx[36+1].ob[0] = this->cursorVtx[36+3].ob[0] = this->cursorVtx[36].ob[0] + 24;
    this->cursorVtx[36].ob[1] = this->cursorVtx[36+1].ob[1] = this->cursorVtx[m].ob[1] + 7;
    this->cursorVtx[36+2].ob[1] = this->cursorVtx[36+3].ob[1] = this->cursorVtx[36].ob[1] - 24;
    if ( this->name_contents == 0 || this->name_contents == 1 || this->name_contents == 4 ) {
	if ( this->name_xpos != this->name_contents ) PRINTF("014 xpos=%d  contents=%d\n",this->name_xpos,this->name_contents);
	this->cursorVtx[40].ob[0] = this->cursorVtx[40+2].ob[0] = (short)menu_select_titlevtx[(this->name_xpos+1)*4].ob[0] - 4;
	this->cursorVtx[40+1].ob[0] = this->cursorVtx[40+3].ob[0] = this->cursorVtx[40].ob[0] + 52;
	this->cursorVtx[40].ob[1] = this->cursorVtx[40+1].ob[1] = (short)menu_select_titlevtx[(this->name_xpos+1)*4].ob[1] + 4;
    } else if ( this->name_contents == 2 || this->name_contents == 3 ) {
	if ( this->name_xpos != this->name_contents ) PRINTF("23 xpos=%d  contents=%d\n",this->name_xpos,this->name_contents);
	this->cursorVtx[40].ob[0] = this->cursorVtx[40+2].ob[0] = (short)menu_select_titlevtx[(this->name_xpos+1)*4].ob[0] - 4;
	this->cursorVtx[40+1].ob[0] = this->cursorVtx[40+3].ob[0] = this->cursorVtx[40].ob[0] + 40;
	this->cursorVtx[40].ob[1] = this->cursorVtx[40+1].ob[1] = (short)menu_select_titlevtx[(this->name_xpos+1)*4].ob[1] + 4;
    } else {
	if ( this->mjp >= 13*5 ) {
	    PRINTF("mjp=%d  xpos=%d  ypos=%d  name_contents=%d\n",this->mjp, this->name_xpos, this->name_ypos, this->name_contents);
	}
	this->cursorVtx[40].ob[0] = this->cursorVtx[40+2].ob[0] = (short)this->characterVtx[this->mjp*4].ob[0] - 6;
	this->cursorVtx[40+1].ob[0] = this->cursorVtx[40+3].ob[0] = this->cursorVtx[40].ob[0] + 24;
	this->cursorVtx[40].ob[1] = this->cursorVtx[40+1].ob[1] = (short)this->characterVtx[this->mjp*4].ob[1] + 6;
    }
    this->cursorVtx[40+2].ob[1] = this->cursorVtx[40+3].ob[1] = this->cursorVtx[40].ob[1] - 24;
    gSPVertex( NEXT_DISP, &(this->cursorVtx[36]), 8, 0);
#define  G_CC_INTZ      1, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INTZ, G_CC_INTZ );
    gDPSetPrimColor( NEXT_DISP, 0, 0, this->cursor_rgba[0], this->cursor_rgba[1], this->cursor_rgba[2], this->cursor_rgba[3] );
    gDPLoadTextureBlock( NEXT_DISP,
			 h_name_cursor1_txt, G_IM_FMT_I, G_IM_SIZ_8b,
			 24, 24, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    if ( this->name_contents == 0 || this->name_contents == 1 || this->name_contents == 4 ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_name_cursor2_txt, G_IM_FMT_I, G_IM_SIZ_8b,
			     56, 24, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
    } else if ( this->name_contents == 2 || this->name_contents == 3 ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_name_cursor3_txt, G_IM_FMT_I, G_IM_SIZ_8b,
			     40, 24, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
    }
    gSP1Quadrangle( NEXT_DISP, 4, 6, 7, 5, 0 );
    /* Ì¾Á°ÅÐÏ¿²èÌÌÉ½¼¨ */
    nameset_display_set( thisx );
    gDPPipeSync( NEXT_DISP );
    kaleido_scope_prim( this->g.graph );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT4, G_CC_INT4 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, 255 );
    

    if ( this->menu_pos == Menu_Nameset ) {
	if ( Pad_on_trigger(START_BUTTON) ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	    /* Ì¾Á°ÅÐÏ¿½ªÎ»¤Ø */
	    this->name_ypos = 5;
	    this->name_xpos = 4;
	} else if ( Pad_on_trigger(B_BUTTON) ) {
	    if ( this->name_index == 7 && this->name[this->no][7] != SSS ) {
		for ( i = this->name_index; i < 7; i++ ) {
		    this->name[this->no][i] = this->name[this->no][i+1];
		}
		this->name[this->no][i] = SSS;
		Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
	    } else {
		if ( --this->name_index < 0 ) {
		    this->name_index = 0;
		    this->menu_pos = Menu_Go_Select;
		} else {
		    for ( i = this->name_index; i < 7; i++ ) {
			this->name[this->no][i] = this->name[this->no][i+1];
		    }
		    this->name[this->no][i] = SSS;
		    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
		}
	    }
	} else {
	    if ( this->name_page <= Eisu_eisu ) {
		/* ÊäÂ­É½¼¨ */
		if ( this->name_ypos != 5 ) {
		    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 0, 255 );
		    if ( this->name_page == Hira_hira ) {
			gSPVertex( NEXT_DISP, &(this->characterVtx[this->mjp*4]), 4, 0);
			file_choose_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_hira[this->mjp])), 0 );
			if ( Pad_on_trigger(A_BUTTON) ) {
			    if ( title_name_hira[this->mjp] == SPJ || title_name_hira[this->mjp] == SPK ) {
				/* Âù²»¡¿È¾Âù²» ÀÚÂØ¥Á¥§¥Ã¥¯ */
				if ( !dakuonn_change_check( thisx, title_name_hira[this->mjp] ) ) {
				    Na_StartSystemSe( NA_SE_SY_FSEL_ERROR );
				} else {
				    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
				}
			    } else {
				Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
				this->name[this->no][this->name_index] = title_name_hira[this->mjp];
				if ( ++this->name_index >= 8 ) this->name_index = 7;
			    }
			}
		    } else if ( this->name_page == Kata_kata ) {
			gSPVertex( NEXT_DISP, &(this->characterVtx[this->mjp*4]), 4, 0);
			file_choose_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_kata[this->mjp])), 0 );
			if ( Pad_on_trigger(A_BUTTON) ) {
			    if ( title_name_hira[this->mjp] == SPJ || title_name_hira[this->mjp] == SPK ) {
				/* Âù²»¡¿È¾Âù²» ÀÚÂØ¥Á¥§¥Ã¥¯ */
				if ( !dakuonn_change_check( thisx, title_name_hira[this->mjp] ) ) {
				    Na_StartSystemSe( NA_SE_SY_FSEL_ERROR );
				} else {
				    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
				}
			    } else {
				Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
				this->name[this->no][this->name_index] = title_name_kata[this->mjp];
				if ( ++this->name_index >= 8 ) this->name_index = 7;
			    }
			}
		    } else {
			gSPVertex( NEXT_DISP, &(this->characterVtx[this->mjp*4]), 4, 0);
			file_choose_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(title_name_eisu[this->mjp])), 0 );
			if ( Pad_on_trigger(A_BUTTON) ) {
			    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
			    this->name[this->no][this->name_index] = title_name_eisu[this->mjp];
			    if ( ++this->name_index >= 8 ) this->name_index = 7;
			}
		    }
		} else if ( Pad_on_trigger(A_BUTTON) ) {
		    if ( this->name_page != this->name_contents ) {
			if ( this->name_contents == 0 ) {
			    /* ¤Ò¤é¤¬¤Ê */
			    if ( this->name_page == Kata_kata ) this->name_page = Kata_hira;
			    else				this->name_page = Eisu_hira;
			    Na_StartSystemSe(NA_SE_SY_LANGUAGE_CHANGE);
			} else if ( this->name_contents == 1 ) {
			    /* ¥«¥¿¥«¥Ê */
			    if ( this->name_page == Hira_hira ) this->name_page = Hira_kata;
			    else				this->name_page = Eisu_kata;
			    Na_StartSystemSe(NA_SE_SY_LANGUAGE_CHANGE);
			} else if ( this->name_contents == 2 ) {
			    /* ±Ñ¿ô */
			    if ( this->name_page == Hira_hira ) this->name_page = Hira_eisu;
			    else				this->name_page = Kata_eisu;
			    Na_StartSystemSe(NA_SE_SY_LANGUAGE_CHANGE);
			} else if ( this->name_contents == 3 ) {
			    /* Ìá¤ë */
			    if ( this->name_index == 7 && this->name[this->no][7] != SSS ) {
				for ( i = this->name_index; i < 7; i++ ) {
				    this->name[this->no][i] = this->name[this->no][i+1];
				}
				this->name[this->no][i] = SSS;
				Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
			    } else {
				if ( --this->name_index < 0 ) this->name_index = 0;
				for ( i = this->name_index; i < 7; i++ ) {
				    this->name[this->no][i] = this->name[this->no][i+1];
				}
				this->name[this->no][i] = SSS;
				Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
			    }
			} else if ( this->name_contents == 4 ) {
			    /* Ì¾Á°ÅÐÏ¿·èÄê¥Á¥§¥Ã¥¯ */
			    /* Ì¾Á°¥Á¥§¥Ã¥¯ */
			    for ( i = m = 0; i < 8; i++ ) {
				if ( this->name[this->no][i] != SSS ) {
				    m = 1;
				    break;
				}
			    }
			    if ( m ) {
				/* ·èÄê */
				Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
#if defined(GATEWAY_VERSION)
				this->menu_pos = Menu_Go_Select;
				this->plate_alpha[this->no] =
				    this->name_alpha[this->no] = BASE_ALPHA;

				this->cpdl_mct = FRAME_CT;
				this->decision_no = this->no;
				this->mode = File_choose_Decision;
				this->title_no1 = 1;
				this->decision_mode = Decision_GotoFdout;
				Na_StopAllSound( 15 );
#else
				z_common_data.file_no = this->no;
				keep_time = ZCommonGet(zelda_time);
				sram_start_save( this, &this->sram );
				ZCommonSet( zelda_time, keep_time );
				this->menu_pos = Menu_Go_Select;
				this->plate_alpha[this->no] =
				    this->name_alpha[this->no] = BASE_ALPHA;
				this->connect_alpha[this->no] = FRAME_ALPHA;
				RUMBLE_ENTRY2_TYPE_B( 300.0f );
#endif /* GATEWAY_VERSION */
			    } else {
				Na_StartSystemSe( NA_SE_SY_FSEL_ERROR );
			    }
			}
		    }
		}
		if ( Pad_on_trigger(R_CBUTTONS) ) {
		    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
		    if ( ++this->name_index > 7 ) this->name_index = 7;
		} else if ( Pad_on_trigger(L_CBUTTONS) ) {
		    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
		    if ( --this->name_index < 0 ) this->name_index = 0;
		} else if ( Pad_on_trigger(Z_TRIG) ) {
		    /* Âù²»¡¿È¾Âù²» ÀÚÂØ¥Á¥§¥Ã¥¯ */
		    if ( dakuonn_change_check( thisx, SSS ) ) {
			Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_S);
		    }
		}
	    }
	}
    }
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA );

    CLOSE_DISP( this->g.graph );
}
    
    
    
/*=======================================================================
  =	Ì¾Á°ÅÐÏ¿¥Õ¥§¡¼¥É¥¤¥ó						=
  =======================================================================*/
extern void
menu_nameset_fdin( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    this->name_plate_alpha += 25;
    if ( this->name_plate_alpha >= 255 ) this->name_plate_alpha = 255;
    this->shift_xp -= 30;
    if ( this->shift_xp <= 0 ) {
	this->shift_xp = 0;
	this->name_plate_alpha = 255;
	this->name_xpos = 0;
	this->name_ypos = 0;
	this->name_contents = 99;
	this->menu_pos = Menu_Nameset;
    }
}


/*=======================================================================
  =	Ì¾Á°ÅÐÏ¿½èÍý							=
  =======================================================================*/
extern void
menu_nameset_play( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;
    
    pad_t	*pad = &this->g.pads[0];

    float	length;
    short	mmm, angle;


/*    static short key_wait_x = 0;
    static short key_wait_y = 0;
    static short old_key_x = 0;
    static short old_key_y = 0;
    short	wkey_x = (short)Pad_stick_x();
    short	wkey_y = (short)Pad_stick_y();*/
    
    
    /* ÆþÎÏ£Ë£Å£Ù¥Á¥§¥Ã¥¯ */
/*    if ( wkey_x < -KEY_ANGLE_3D ) {
	if (  old_key_x == -1 ) {
	    if ( --key_wait_x < 0 ) key_wait_x = XREG(6);
	    else wkey_x = 0;
	} else {
	    key_wait_x = XREG(8);
	    old_key_x  = -1;
	}
    } else if ( wkey_x > KEY_ANGLE_3D ) {
	if (  old_key_x == 1 ) {
	    if ( --key_wait_x < 0 ) key_wait_x = XREG(6);
	    else wkey_x = 0;
	} else {
	    key_wait_x = XREG(8);
	    old_key_x  = 1;
	}
    } else old_key_x = 0;
    if ( wkey_y < -KEY_ANGLE_3D ) {
	if (  old_key_y == -1 ) {
	    if ( --key_wait_y < 0 ) key_wait_y = XREG(6);
	    else wkey_y = 0;
	} else {
	    key_wait_y = XREG(8);
	    old_key_y  = -1;
	}
    } else if ( wkey_y > KEY_ANGLE_3D ) {
	if (  old_key_y == 1 ) {
	    if ( --key_wait_y < 0 ) key_wait_y = XREG(6);
	    else wkey_y = 0;
	} else {
	    key_wait_y = XREG(8);
	    old_key_y  = 1;
	}
    } else old_key_y = 0; */


///////    stick_ratio_set( &length, &angle, pad );
///////    PRINTF("Length=%f,  Angle=%d\n",length, angle);
    if ( this->name_page <= Eisu_eisu ) {
	/* Ì¾Á°ÅÐÏ¿Ãæ */
	if ( Pad_on_trigger(R_TRIG) ) {
	    if ( !J_N ) {
		if ( this->name_page == Hira_hira ) {
		    this->name_page = Hira_kata;
		    Na_StartSystemSe( NA_SE_SY_LANGUAGE_CHANGE );
		} else if ( this->name_page == Kata_kata ) {
		    this->name_page = Kata_eisu;
		    Na_StartSystemSe( NA_SE_SY_LANGUAGE_CHANGE );
		    ////////		cursor_reset( this );
		} else if ( this->name_page == Eisu_eisu ) {
		    this->name_page = Eisu_hira;
		    Na_StartSystemSe( NA_SE_SY_LANGUAGE_CHANGE );
		}
	    }
	} else {
	    this->name_contents = 99;
	    /* £Ø°ÜÆ° */
	    if ( this->name_ypos != 5 ) {
		/* Ê¸»úÍ÷ */
		if ( this->wkey_x < -KEY_ANGLE_3D ) {
		    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
		    this->mjp--;
		    if ( (--this->name_xpos) < 0 ) {
			this->name_xpos = 12;
			this->mjp = this->name_ypos * 13 + this->name_xpos;
		    }
		} else if ( this->wkey_x > KEY_ANGLE_3D ) {
		    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
		    this->mjp++;
		    if ( (++this->name_xpos) > 12 ) {
			this->name_xpos = 0;
			this->mjp = this->name_ypos * 13 + this->name_xpos;
		    }
		}
	    } else {
		/* ¥Ñ¥Í¥ëÍ÷ */
		if ( !J_N ) {
		    if ( this->wkey_x < -KEY_ANGLE_3D ) {
			Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
			if ( (--this->name_xpos) < 0 ) this->name_xpos = 4;
		    } else if ( this->wkey_x > KEY_ANGLE_3D ) {
			Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
			if ( (++this->name_xpos) > 4 ) this->name_xpos = 0;
		    }
		} else {
		    if ( this->wkey_x < -KEY_ANGLE_3D ) {
			Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
			if ( (--this->name_xpos) < 3 ) this->name_xpos = 4;
		    } else if ( this->wkey_x > KEY_ANGLE_3D ) {
			Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
			if ( (++this->name_xpos) > 4 ) this->name_xpos = 3;
		    }
		    
		}
	    }
	    /* £Ù°ÜÆ° */
	    if ( this->wkey_y > KEY_ANGLE_3D ) {
		Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
		if ( (--this->name_ypos) < 0 ) {
		    if ( !J_N ) {
			this->name_ypos = 5;
			this->mjp += (13*4);
			mmm = this->name_xpos;
			if ( this->name_xpos < 3 ) this->name_xpos = 0;
			else if ( this->name_xpos < 6 )  this->name_xpos = 1;
			else if ( this->name_xpos < 8 )  this->name_xpos = 2;
			else if ( this->name_xpos < 10 ) this->name_xpos = 3;
			else if ( this->name_xpos < 13 ) this->name_xpos = 4;
			this->sub_menu_alpha[this->name_xpos] = mmm;
		    } else {
			if ( this->name_xpos < 8 ) {
			    this->name_ypos = 4;
			    this->mjp = (13*4) + this->name_xpos;
			} else {
			    this->name_ypos = 5;
			    this->mjp += (13*4);
			    mmm = this->name_xpos;
			    if ( this->name_xpos < 10 ) this->name_xpos = 3;
			    else if ( this->name_xpos < 13 ) this->name_xpos = 4;
			    this->sub_menu_alpha[this->name_xpos] = mmm;
			}
		    }
		} else {
		    this->mjp-=13;
		    if ( this->name_ypos == 4 ) {
			this->mjp = 13*4;
			this->name_xpos = this->sub_menu_alpha[this->name_xpos];
/*			if ( this->name_xpos == 0 ) this->name_xpos = 0;
			else if ( this->name_xpos == 1 ) this->name_xpos = 3;
			else if ( this->name_xpos == 2 ) this->name_xpos = 6;
			else if ( this->name_xpos == 3 ) this->name_xpos = 8;
			else if ( this->name_xpos == 4 ) this->name_xpos = 10;*/
# if 0
			if ( this->name_page == Eisu_eisu ) {
			    this->mjp-=13;
			    this->name_ypos = 3;
			    if ( !this->name_xpos ) this->name_xpos = 1;
			}
# endif
			this->mjp += this->name_xpos;
		    }
		}
	    } else if ( this->wkey_y < -KEY_ANGLE_3D ) {
		Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
		if ( (++this->name_ypos) > 5 ) {
		    this->name_ypos = 0;
		    this->name_xpos = this->sub_menu_alpha[this->name_xpos];
		    this->mjp = this->name_xpos;
		} else {
# if 0
		    if ( this->name_page == Eisu_eisu && this->name_ypos == 4 ) {
			this->name_ypos = 5;
			this->mjp+=13;
		    }
# endif
		    this->mjp+=13;
		    if ( this->name_ypos == 5 ) {
			if ( J_N ) {
			    if ( this->name_xpos < 8 ) {
				this->name_ypos = 0;
				this->mjp = this->name_xpos;
			    } else {
				mmm = this->name_xpos;
				if ( this->name_xpos < 3 ) this->name_xpos = 0;
				else if ( this->name_xpos < 6 )  this->name_xpos = 1;
				else if ( this->name_xpos < 8 )  this->name_xpos = 2;
				else if ( this->name_xpos < 10 ) this->name_xpos = 3;
				else if ( this->name_xpos < 13 ) this->name_xpos = 4;
				this->sub_menu_alpha[this->name_xpos] = mmm;
			    }
			} else {
			    mmm = this->name_xpos;
			    if ( this->name_xpos < 3 ) this->name_xpos = 0;
			    else if ( this->name_xpos < 6 )  this->name_xpos = 1;
			    else if ( this->name_xpos < 8 )  this->name_xpos = 2;
			    else if ( this->name_xpos < 10 ) this->name_xpos = 3;
			    else if ( this->name_xpos < 13 ) this->name_xpos = 4;
			    this->sub_menu_alpha[this->name_xpos] = mmm;
			}
		    }
		}
	    }
	    if ( this->name_ypos == 5 ) this->name_contents = this->name_xpos;
	}
    } else {
	/* £Î£å£ø£ôÊ¸»ú£Ï£ö£å£ò¡¼£Ì£á£ð */
	this->page_alpha += ZREG(9);
	if ( this->page_alpha >= 255 ) {
	    this->page_alpha = 0;
	    /* ¼¡¤Î¥â¡¼¥ÉÀßÄê */
	    this->name_page =  alpha_index[this->name_page];
	}
    }
}



/*
 *
 *  £Ï£Ð£Ô£É£Ï£Î
 *
 */
/*=======================================================================
  =	£Ï£Ð£Ô£É£Ï£Î¥Õ¥§¡¼¥É¥¤¥ó					=
  =======================================================================*/
extern void
menu_option_fdin( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    this->name_plate_alpha += 25;
    if ( this->name_plate_alpha >= 255 ) this->name_plate_alpha = 255;
    this->shift_xp -= 30;
    if ( this->shift_xp <= 0 ) {
	this->shift_xp = 0;
	this->name_plate_alpha = 255;
	this->menu_pos = Menu_Option;
    }
}


/*=======================================================================
  =	£Ï£Ð£Ô£É£Ï£Î½èÍý						=
  =======================================================================*/
extern void
menu_option_play( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Sram	*sram = (Sram *)&this->sram;

    pad_t	*pad = &this->g.pads[0];


/*    if ( Pad_on_trigger(A_BUTTON) ) {*/
    if ( Pad_on_trigger(B_BUTTON) ) {
	Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	this->menu_pos = Menu_Option_Select;
	sram->read_buff[0] = S_SOUND;
	sram->read_buff[1] = Z_ATTENTION;
	PRINTF("£Ó£Á£Ö£Å");
	sram_sound_save( sram );
	COLOR_YELLOW();
	PRINTF("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
	PRINTF("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
	PRINTF("Na_SetSoundOutputMode = %d\n",NA_SOUT_STEREO + S_SOUND);
	COLOR_NORMAL();
	Na_SetSoundOutputMode( NA_SOUT_STEREO + S_SOUND );	/* ¥µ¥¦¥ó¥É½ÐÎÏ¥»¥Ã¥È */
	PRINTF("½ªÎ»\n");
    } else {
	if ( this->wkey_x < -KEY_ANGLE_3D ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
	    if ( !H_Move_index ) {
		if ( (--S_SOUND) > 0xf0 ) S_SOUND = 3;
	    } else {
		Z_ATTENTION ^= 1;
	    }
	} else if ( this->wkey_x > KEY_ANGLE_3D ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
	    if ( !H_Move_index ) {
		if ( (++S_SOUND) > 3 ) S_SOUND = 0;
	    } else {
		Z_ATTENTION ^= 1;
	    }
	}
	if ( this->wkey_y < -KEY_ANGLE_3D || this->wkey_y > KEY_ANGLE_3D ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
	    H_Move_index^= 1;
	} else if ( Pad_on_trigger(A_BUTTON) ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	    H_Move_index^= 1;
	}
    }
}

/*=======================================================================
  =	£Ï£Ð£Ô£É£Ï£Î²èÌÌ´ðËÜÉ½¼¨					=
  =======================================================================*/
typedef struct {
    unchar	*tex[ 2 ];
    unshort	w, h;
} h_op_tex_info;

static void
option_basic_display( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

#if 01
    static h_op_tex_info h_op_data[] = {
	{ { h_mes_option_txt, h_mes_option_nes_txt, }, H_MES_OPTION_W, H_MES_OPTION_H },
	{ { h_op_sound_txt, h_op_sound_txt, }, H_OP_SOUND_W, H_OP_SOUND_H },
	{ { h_op_z_txt, h_op_z_nes_txt, }, H_OP_Z_W, H_OP_Z_H },
	{ { h_op_sample_txt, h_op_sample_nes_txt }, H_OP_SAMPLE_W, H_OP_SAMPLE_H },
    };
    static h_op_tex_info h_op_data2[] = {
	{ { h_op_stereo_txt, h_op_stereo_nes_txt, }, H_OP_STEREO_W, H_OP_STEREO_H },
	{ { h_op_mono_txt, h_op_mono_nes_txt, }, H_OP_MONO_W, H_OP_MONO_H },
	{ { h_op_headphones_txt, h_op_headphones_nes_txt, }, H_OP_HEADPHONES_W, H_OP_HEADPHONES_H },
	{ { h_op_3d_txt, h_op_3d_nes_txt, }, H_OP_3D_W, H_OP_3D_H },
	{ { h_op_switch_txt, h_op_switch_nes_txt, }, H_OP_SWITCH_W, H_OP_SWITCH_H },
	{ { h_op_hold_txt, h_op_hold_nes_txt, }, H_OP_HOLD_W, H_OP_HOLD_H },
    };
#else
    static unchar *h_mes_option_txt_data[] = {
	h_mes_option_txt, h_mes_option_nes_txt,
    };
    static unchar *option_no_data[][5] = {
	{ h_op_sound_txt, h_op_stereo_txt, h_op_mono_txt, h_op_headphones_txt, h_op_3d_txt, },
	{ h_op_sound_txt, h_op_stereo_nes_txt, h_op_mono_nes_txt, h_op_headphones_nes_txt, h_op_3d_txt, },
    };
    static unshort plate_xsize[] = {
	64, 48, 48, 48, 48,
    };
#endif

    short	i, j;
    short	rc, gc, bc;
    static short	p_red = 255, p_green = 255, p_blue = 255;
    static short	e_red = 0, e_green = 0, e_blue = 0;
    static short	mp = 1, mc = 20;
    static short	prim_col[][3] = {
	{ 255, 255, 255, },
	{   0, 255, 255, },
    };
    static short	env_col[][3] = {
	{   0,   0,   0, },
	{   0, 150, 150, },
    };



    OPEN_DISP( this->g.graph );

    /* »Ø¥«¡¼¥½¥ëÉ½¼¨ */
    rc = (ABS(p_red - prim_col[mp][0] )) / mc;
    gc = (ABS(p_green - prim_col[mp][1] )) / mc;
    bc = (ABS(p_blue - prim_col[mp][2] )) / mc;
    if ( p_red >= prim_col[mp][0] ) p_red -= rc;
    else			    p_red += rc;
    if ( p_green >= prim_col[mp][1] ) p_green -= gc;
    else			      p_green += gc;
    if ( p_blue >= prim_col[mp][2] ) p_blue -= bc;
    else		             p_blue += bc;
    rc = (ABS(e_red - env_col[mp][0] )) / mc;
    gc = (ABS(e_green - env_col[mp][1] )) / mc;
    bc = (ABS(e_blue - env_col[mp][2] )) / mc;
    if ( e_red >= env_col[mp][0] ) e_red -= rc;
    else			   e_red += rc;
    if ( e_green >= env_col[mp][1] ) e_green -= gc;
    else			     e_green += gc;
    if ( e_blue >= env_col[mp][2] ) e_blue -= bc;
    else		            e_blue += bc;
    if ( !(--mc) ) {
	p_red = prim_col[mp][0];
	p_green = prim_col[mp][1];
	p_blue = prim_col[mp][2];
	e_red = env_col[mp][0];
	e_green = env_col[mp][1];
	e_blue = env_col[mp][2];
	mc = 20;
	if ( ++mp >= 2 ) mp = 0;
    }



#if 01

    gSPVertex( NEXT_DISP, menu_option_titlevtx, OP_PLATE_VTX_SUU, 0);
    /* ¥¿¥¤¥È¥ë¡õ¥µ¥Ö¥¿¥¤¥È¥ë */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );

    for ( i = 0, j = 0; i < OP_TITLE_SUU; i ++, j += 4 ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_op_data[i].tex[J_N], G_IM_FMT_IA, G_IM_SIZ_8b,
			     h_op_data[i].w, h_op_data[i].h, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
    }

    gSPVertex( NEXT_DISP, menu_option_plate, OP_PLATE_VTX_SUU, 0);
    for ( i = 0, j = 0; i < OP_PLATE_0_SUU; i ++, j += 4 ) {
	gDPPipeSync( NEXT_DISP );
	if ( i == S_SOUND ) {
	    if ( !H_Move_index ) {
		gDPSetPrimColor( NEXT_DISP, 0, 0, p_red, p_green, p_blue, this->frame_title_alpha[0] );
		gDPSetEnvColor( NEXT_DISP, e_red, e_green, e_blue, 255 );
	    } else {
		gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
		gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );
	    }
	} else {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, 120, 120, 120, this->frame_title_alpha[0] );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );
	}
	gDPLoadTextureBlock( NEXT_DISP,
			     h_op_data2[i].tex[J_N], G_IM_FMT_IA, G_IM_SIZ_8b,
			     h_op_data2[i].w, h_op_data[i].h, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
    }

    for ( ; i < ( OP_PLATE_0_SUU + OP_PLATE_1_SUU ); i ++, j += 4 ) {
	gDPPipeSync( NEXT_DISP );
	if ( ( i - OP_PLATE_0_SUU ) == Z_ATTENTION ) {
	    if ( H_Move_index ) {
		gDPSetPrimColor( NEXT_DISP, 0, 0, p_red, p_green, p_blue, this->frame_title_alpha[0] );
		gDPSetEnvColor( NEXT_DISP, e_red, e_green, e_blue, 255 );
	    } else {
		gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
		gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );
	    }
	} else {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, 120, 120, 120, this->frame_title_alpha[0] );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );
	}
	gDPLoadTextureBlock( NEXT_DISP,
			     h_op_data2[i].tex[J_N], G_IM_FMT_IA, G_IM_SIZ_8b,
			     h_op_data2[i].w, h_op_data[i].h, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
    }

    gDPPipeSync( NEXT_DISP );
    gDPLoadTextureBlock_4b( NEXT_DISP,
			    h_op_contrast_txt, G_IM_FMT_IA,
			    H_OP_CONTRAST_W, H_OP_CONTRAST_H, 0,
			    G_TX_NOMIRROR, G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK,
			    G_TX_NOLOD, G_TX_NOLOD );

    gDPSetPrimColor( NEXT_DISP, 0, 0,
		     255-200,
		     255-200,
		     255-200,
		     this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP,
		    200-160,
		    200-160,
		    200-160,
		    255 );
    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );

    j += 4;
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0,
		     50-20,
		     50-20,
		     50-20,
		     this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP,
		    0,
		    0,
		    0,
		    255 );
    gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );

    j += 4;
    /* ¥é¥¤¥ó */

    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 0, 255, 255, this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    gDPLoadTextureBlock_4b( NEXT_DISP,
			    h_op_line_txt, G_IM_FMT_IA,
			    H_OP_LINE_W, H_OP_LINE_H, 0,
			    G_TX_NOMIRROR, G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK,
			    G_TX_NOLOD, G_TX_NOLOD );
    Matrix_push();
    Matrix_translate( 0.0f,
		      0.1f,
		      0.0f,
		      MULT_MTX );
    gSPMatrix( NEXT_DISP,
	       Matrix_to_Mtx_new(this->g.graph),
	       G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
    gSPVertex( NEXT_DISP, menu_option_line, 4, 0);
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    Matrix_pull();

    Matrix_push();
    Matrix_translate( 0.0f,
		      0.2f,
		      0.0f,
		      MULT_MTX );
    gSPMatrix( NEXT_DISP,
	       Matrix_to_Mtx_new(this->g.graph),
	       G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
    gSPVertex( NEXT_DISP, &(menu_option_line[4]), 4, 0);
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    Matrix_pull();

    Matrix_push();
    Matrix_translate( 0.0f,
		      0.4f,
		      0.0f,
		      MULT_MTX );
    gSPMatrix( NEXT_DISP,
	       Matrix_to_Mtx_new(this->g.graph),
	       G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
    gSPVertex( NEXT_DISP, &(menu_option_line[8]), 4, 0);
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    Matrix_pull();

    CLOSE_DISP( this->g.graph );

#else

    /* ¥¿¥¤¥È¥ëÌ¾ */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );
    gSPVertex( NEXT_DISP, &(menu_option_titlevtx[0]), 28, 0);
    gDPLoadTextureBlock( NEXT_DISP,
			 h_mes_option_txt_data[J_N], G_IM_FMT_IA, G_IM_SIZ_8b,
			 128, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );

    /* ³Æ¥×¥ì¡¼¥È */
    for ( i = 0, j = 4; i < 5; i++, j+=4 ) {
	gDPPipeSync( NEXT_DISP );
	if ( !i ) {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
	} else if ( (i - 1) == S_SOUND ) {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, p_red, p_green, p_blue, this->frame_title_alpha[0] );
	    gDPSetEnvColor( NEXT_DISP, e_red, e_green, e_blue, 255 );
	} else {
	    gDPSetPrimColor( NEXT_DISP, 0, 0, 120, 120, 120, this->frame_title_alpha[0] );
	    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 255 );
	}
	gDPLoadTextureBlock( NEXT_DISP,
			     option_no_data[J_N][i], G_IM_FMT_IA, G_IM_SIZ_8b,
			     plate_xsize[i], 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, j+0, j+2, j+3, j+1, 0 );
    }

    /* ¥é¥¤¥ó */
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0,   0, 255, 255, this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    gSPVertex( NEXT_DISP, &(menu_option_titlevtx[0]), 28, 0);
    gDPLoadTextureBlock_4b( NEXT_DISP,
			    h_op_line_txt, G_IM_FMT_IA,
			    256, 2, 0,
			    G_TX_NOMIRROR, G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK,
			    G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 24, 26, 27, 25, 0 );

    CLOSE_DISP( this->g.graph );
#endif
}
/*=======================================================================
  =	£Ï£Ð£Ô£É£Ï£ÎÉ½¼¨						=
  =======================================================================*/
extern void
menu_option_display( Game *thisx )
{
    /* £Ï£Ð£Ô£É£Ï£Î²èÌÌ´ðËÜÉ½¼¨ */
    option_basic_display( thisx );
}
    
    
    
