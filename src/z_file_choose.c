/* $Id: z_file_choose.c,v 2.7 2002/05/27 07:20:23 zelda Exp $
 *
 * ファイル選択処理
 *
 * $Log: z_file_choose.c,v $
 * Revision 2.7  2002/05/27  07:20:23  zelda
 * *** empty log message ***
 *
 * Revision 2.6  2001-04-04 16:21:47+09  zelda
 * ドルフィンエミュレータ用仮ぐみ版 CICと64DD対応部分をはずしたバージョン
 *
 * Revision 2.5  1999-01-08 10:27:18+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.4  1999-01-07 17:15:27+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.3  1999-01-07 13:26:24+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.2  1998-11-06 12:02:01+09  soejima
 * コメント
 *
 *
 * Revision 1.1  1997/10/18  06:38:01  soejima
 * Initial revision
 * $Log追加
 *
 */

/************************************************************************
 *
 *	ＦＩＬＥ ＣＨＯＯＳＥ
 *
 ************************************************************************/
#include "z_basic.h"
#include "sys_segment.h"
#include "assert64.h"		/* assert */
#include "z_hilite.h"
#include "z_play.h"
#include "z_select.h"
#if defined(USE_N64DD)
#include "z_n64dd.h"
#include "z_n64dd_keep.h"
#endif /* defined(USE_N64DD) */
#include "z_common_data.h"	/* z_common_data_t */
#include "z_sram.h"
#include "z_define1.h"

#include "z_file_choose.h"
#include "z_sram_h.h"
#include "z_file_choose_h.h"
#include "z_file_choose_data.h"
#include "z_file_choose_parameterd.h"
#include "z_file_nameset.h"
#include "z_file_copy_del.h"
#include "z_message_h.h"
#include "z_kaleido_moji.h"
#include "z_kaleido_scope_h.h"
#include "z_save_area_h.h"
#include "z_parameter_h.h"
#ifdef USE_N64DD
#include "z_n64dd.h"		/* n64dd_isConnected */
#endif





/* 外部シンボル宣言 */
EXTERN_DEFSEG_DATA(title_static);
EXTERN_DEFSEG_DATA(parameter_static);

extern unsigned char heart24_txt[];	/* 4/4 */
extern unsigned char heart24_2_txt[];	/* 4/4 */


extern void Kankyo_vrbox_change( unsigned char vr_box_flag, Kankyo *this, Vr_box *this2 );

extern void shrink_window_setval(int);

extern void save_initialize999( void );

# if 0
#ifdef SHOW_VERSION
#include "zurumode.h"		/* isZuruMode */
/* Ｅ３ */
extern void (*menu_playE3[])( Game *thisx );
extern void (*file_decision_playE3[])( Game *thisx );
extern void menu_file_chooseE3_vtxset( Game *thisx );
extern void menu_file_chooseE3_display( Game *thisx );
/* Ｅ３ */
#endif /* SHOW_VERSION */
# endif


#if defined(GATEWAY_VERSION)
extern void
save_initialize_GATEWAY_SET( Game *thisx );
extern void
gateway_start_load( Game_file_choose *this, Sram *sram );
/* 外部シンボル宣言 */
EXTERN_DEFSEG_DATA(gateway_title_static);
#endif	/* GATEWAY_VERSION */



#define XREG_0 		 44		/* ファイル選択面表示Ｙ位置 */
#define XREG_6 		  2		/* カレイド・スコープＷａｉｔフレーム */
#define XREG_8 		 10		/* ＫＥＹ Ｗａｉｔフレーム */
#define VREG_3 		 20		/* ファイル選択面スクロール速度 */
static short	xreg_1 = -94 + 200;	/*                   Ｘ位置 */
static short	fill_alpha = 255;


static Gfx fbdemo_fade_gfx_init[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH |
			  G_FOG | G_LIGHTING | G_TEXTURE_GEN |
			  G_TEXTURE_GEN_LINEAR | G_LOD | G_ZBUFFER),
    gsDPSetOtherModeHL(G_PM_1PRIMITIVE|G_CYC_1CYCLE|G_TP_NONE|G_TD_CLAMP|
		       G_TL_TILE|G_TT_NONE|G_TF_BILERP|G_TC_FILT|G_CK_NONE|
		       G_CD_MAGICSQ|G_AD_DISABLE,
		       G_AC_NONE|G_ZS_PIXEL|G_RM_CLD_SURF|G_RM_CLD_SURF2),
    gsDPSetCombineMode( G_CC_PRIMITIVE, G_CC_PRIMITIVE ),
    gsSPEndDisplayList(),
};


static short decision_xpd[] = {
    36, 36, 36, 36, 24,
};

static short frame_rgb[][3] = {
    { 100, 150, 255, },
    { 100, 100, 100, },
};




/*===============================================================
  =	ビュー設定						=
 ===============================================================*/
extern void
view_setting( Game_file_choose *this, float ex, float ey, float ez )
{
    xyz_t	eye, center, up;


    /*
     * ビュー設定
     */
    eye.x = ex;
    eye.y = ey;
    eye.z = ez;
    center.x = center.y = center.z = 0.0f;
    up.x = up.z = 0.0f;
    up.y = 1.0f;
	
    setLookAtView(&this->view, &eye, &center, &up);

    showView(&this->view, VIEW_DO_PERSALL);
}


/*===============================================================
  =	（ＩＡ／８）Ｔｅｃｔｕｒｅ＿Ｑｕａｄｒａｎｇｌｅ	=
  ===============================================================*/
static Gfx
*texture_quadrangleA8( Gfx *gp, void *timg,
		       short width, short height, short k )
{
    gDPLoadTextureBlock( gp++,
			 timg, G_IM_FMT_IA, G_IM_SIZ_8b,
			 width, height, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD );
    gSP1Quadrangle( gp++, k+0, k+2, k+3, k+1, 0 );

    return gp;
}


# if 0
/*===============================================================
  =	（Ｉ／８）Ｔｅｃｔｕｒｅ＿Ｒｅｃｔａｎｇｌｅ		=
  ===============================================================*/
static Gfx
*texture_rectangleI8( Gfx *gp, void *timg,
		       short width, short height,
		       short xpos,  short ypos,
		       short xsize, short ysize,
		       unshort xscale, unshort yscale )
{
    gDPLoadTextureBlock( gp++,
			 timg, G_IM_FMT_I, G_IM_SIZ_8b,
			 width, height, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD );
    gSPTextureRectangle( gp++,
			 ((xpos) * 0x4), ((ypos) * 0x4),
			 ((xpos + xsize) * 0x4), ((ypos + ysize) * 0x4),
			 G_TX_RENDERTILE, 0, 0, xscale, yscale );

    return gp;
}
/*===============================================================================
  =	（Ｉ/４＆ＩＡ/８）Ｔｅｃｔｕｒｅ＿Ｍｕｌｔｉ＿Ｒｅｃｔａｎｇｌｅ	=
  ===============================================================================*/
static Gfx
*texture_multi_rectangle( Gfx *gp, void *timg1, void *timg2,
			  short width1, short height1,
			  short width2, short height2,
			  short xpos,  short ypos,
			  short xsize, short ysize,
			  unshort xscale, unshort yscale,
			  unshort xscale2, unshort yscale2,
			  unshort flag )
{
    gDPLoadMultiBlock_4b( gp++,
			  timg1, 0, G_TX_RENDERTILE,
			  G_IM_FMT_I, width1, height1, 0,
			  G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			  G_TX_NOMASK, G_TX_NOMASK,
			  G_TX_NOLOD, G_TX_NOLOD );
    if ( !flag ) {
	gDPLoadMultiBlock( gp++,
			   timg2, 256, G_TX_RENDERTILE+1,
			   G_IM_FMT_I, G_IM_SIZ_8b, width2, height2, 0,
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			   G_TX_NOMASK, 5,
			   xscale2, yscale2 );
	gDPSetTileSize( gp++, G_TX_RENDERTILE+1, 0,  VREG(27)&0x7f, 31<<2, (VREG(27)&0x7f) + (31<<2) );
    }
    gSPTextureRectangle( gp++,
			 ((xpos) * 0x4), ((ypos) * 0x4),
			 ((xpos + xsize) * 0x4), ((ypos + ysize) * 0x4),
			 G_TX_RENDERTILE, 0, 0, xscale, yscale );

    return gp;
}
/*=======================================================================
  =	ＲＧＢＡテクスチャ─ セット【３２ビット用】			=
  =======================================================================*/
static void
display_rgba32b ( Graph *graph, short cx, short cy, unchar *addr, unint sizex, unint sizey )
{

    int		i, cnt, sx, sy;
    int		cuty, size, amari, texsize;
    unchar	*imageaddr;

    OPEN_DISP( graph );

    /* モード設定 */
    rgba32texture( graph );

    imageaddr = addr;

////    PRINTF("\n=============(%3d)==(%3d)====================\n",sizex,sizey);
    size    = (int)(sizex*sizey*4);
    sx      = cx - (int)(sizex/2);
    sy      = cy - (int)(sizey/2);
    cuty    = (int)(4096/(sizex*4));
    texsize = (int)sizex*cuty*4;
    
    cnt     = (int)size/texsize;
    amari   = size%texsize;
    if (amari) cnt++;
////    PRINTF("size=%d, cuty=%d, texsize=%d, shou=%d, amari=%d cnt=%d\n",size,cuty,texsize,shou,amari,cnt);
    

    gDPSetImageTile (NEXT_DISP,G_IM_FMT_RGBA,G_IM_SIZ_32b,
		     0,0,(sizex-1),(cuty-1),0,
		     G_TX_NOMIRROR| G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
		     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    
    size -= texsize;

    for	( i =0; i< cnt; i++ ) {
////	PRINTF("size=%d    ",size);
	gDPSetTextureImage(NEXT_DISP,G_IM_FMT_RGBA,G_IM_SIZ_32b,sizex,imageaddr);
	gDPLoadSync(NEXT_DISP);
	gDPLoadTile(NEXT_DISP, G_TX_LOADTILE,
		    0,
		    0,
		    (sizex-1)<<G_TEXTURE_IMAGE_FRAC,
		    (cuty-1)<<G_TEXTURE_IMAGE_FRAC);
	
	gSPTextureRectangle ( NEXT_DISP, sx<<2, sy<<2,
			     (sx+(int)sizex)<<2, (sy+(int)cuty)<<2,
			     0, 0<<5, 0<<5, 1<<10, 1<<10 );
	

	imageaddr += texsize;
	sy        += cuty;

////	PRINTF("size-texsize=%d\n",size-texsize);
	if (size-texsize < 0){
	    if (size > 0){
		cuty  = size/(int)(sizex*4);
		size -= texsize;
////		PRINTF("cuty=%d,  size=%d\n",cuty,size);
		gDPSetImageTile (NEXT_DISP,G_IM_FMT_RGBA,G_IM_SIZ_32b,
				 0,0,(sizex-1),(cuty-1),0,
				 G_TX_NOMIRROR| G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
				 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	    }      	
	}      	
	else 	size -= texsize;
	
    }
    CLOSE_DISP( graph );
}
/*===============================================================
  =	文字テクスチャ─表示					=
 ===============================================================*/
static void
moji_display( Graph *graph, unchar *data, int xpos, int ypos )
{
    OPEN_DISP( graph );

    gDPLoadTextureBlock_4b ( NEXT_DISP,
			     data, G_IM_FMT_I, 16, 16, 0,
			     G_TX_CLAMP, G_TX_CLAMP,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle( NEXT_DISP,
			 xpos << 2, ypos << 2,
			 (xpos + 13) << 2, (ypos + 13) << 2,
			 G_TX_RENDERTILE, 0, 0, 650 << 1, 650 << 1 );

    CLOSE_DISP( graph );
}
/*===============================================================================
  =================================  タイトル   =================================
  ===============================================================================*/
# endif


/************************************************************************
 *									*
 *	タイトルＭＯＶＥ						*
 *									*
 ************************************************************************/
extern void
file_choose_title_move( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;
    
//    pad_t	*pad = &this->g.pads[0];

    if ( this->mode == File_choose_Title ) {
////////	this->alpha_mode = Title_Goto;
	this->mode = File_choose_Select;
	this->menu_pos = Menu_Fadein;
	this->title_no1 = 1;
	/* ＳＲＡＭ ＳＴＡＲＴ─ＬＯＡＤ */
#if defined(GATEWAY_VERSION)
	PRINTF("ＧＡＴＥＷＡＹ Ｓｔａｒｔ─Ｌｏａｄ  》》》》》  ");
	gateway_start_load( this, &this->sram );
#else
	PRINTF("Ｓｒａｍ Ｓｔａｒｔ─Ｌｏａｄ  》》》》》  ");
	sram_start_load( this, &this->sram );
	PRINTF("終了！！！\n");
#endif	/* GATEWAY_VERSION */
    }

# if 0
    if ( Pad_on_trigger(U_CBUTTONS) )  this->alpha_mode = Title_Fillout;

    if ( this->bgm_ct < 4626 ) {
	if ( !VREG(9) ) {	/* ＦＩＬＬ フェードイン */
	    if ( !VREG(8) ) {	/* ＷＡＩＴ */
		if ( this->effect_alpha < 255 ) {	/* エフェクト フェードイン */
		    if ( (this->effect_alpha += VREG(4)) >= 255 ) this->effect_alpha = 255;
		}
		if ( this->effect_alpha > VREG(29) ) {	
		    if ( (this->title_alpha += VREG(5)) >= 210 ) {	/* タイトル フェードイン */
			this->title_alpha = 210;
			if ( (this->sub_alpha += VREG(6)) >= 255 ) {	/* 日本語タイトル フェードイン */
			    this->sub_alpha = 255;
			    if ( (this->logo_alpha += VREG(7)) >= 255 ) {	/* "１９９７Ｎｉｎｔｅｎｄｏ" フェードイン */
				this->logo_alpha = 255;
			    }
			}
		    }
		}
	    } else --VREG(8);
	} else {
	    VREG(9) -= VREG(10);
	    if ( VREG(9) <= 0 ) VREG(9) = 0;
	}
    } else {
	if ( !this->logo_alpha ) {
	    if ( !this->sub_alpha ) {
		if ( !this->title_alpha ) {
		    if ( !this->effect_alpha ) {
			if ( !VREG(8) ) {
			    VREG(9)+= VREG(10);
			    if ( VREG(9) > 254 ) {
				VREG(9) = 255;
				z_common_data.game_info.mode = GAME_INFO_OPENING_DEMO;
				this->g._doing = 0;
				ZCommon_LinkAgeBeChild( );
				save_initialize999( );
				ZCommonSet( day_time, 0xFFF0+VREG(94) );
				game_set_next_game_name(&this->g, play);
			    }
			} else --VREG(8);
		    } else if ( (this->effect_alpha -= VREG(29)) < 0 ) {
			this->effect_alpha = 0;
			VREG(8) = 20;
		    }
		} else if ( (this->title_alpha -= VREG(5)) < 0 ) this->title_alpha = 0;
	    } else if ( (this->sub_alpha -= VREG(6)) < 0 ) this->sub_alpha = 0;
	} else if ( (this->logo_alpha -= VREG(7)) < 0 ) this->logo_alpha = 0;
    }
# if 0 	
    switch ( this->alpha_mode ) {
    case Title_Fillin:		/* ＦＩＬＬ フェードイン */
	VREG(9) -= VREG(10);
	if ( VREG(9) <= 0 ) {
	    VREG(9) = 0;
	    this->alpha_mode = Title_Wait;
	}
	break;

    case Title_Wait:		/* ＷＡＩＴ */
	if ( !--VREG(8) ) this->alpha_mode = Title_Effectin;
	break;

    case Title_Effectin:	/* エフェクト フェードイン */
	if ( (this->effect_alpha += VREG(4)) >= 255 ) {
	    this->effect_alpha = 255;
	    this->alpha_mode = Title_Fadein;
	}
	break;

    case Title_Fadein:		/* タイトル フェードイン */
	if ( (this->title_alpha += VREG(5)) >= 210 ) {
	    this->title_alpha = 210;
	    this->alpha_mode = Title_Effectout;
	}
	break;

    case Title_Effectout:	/* エフェクト フェードアウト */
	if ( (this->effect_alpha -= VREG(7)) <= 0 ) {
	    this->effect_alpha = 0;
	    this->alpha_mode = Title_Logoin;
	}
	break;

    case Title_Logoin:		/* "１９９７Ｎｉｎｔｅｎｄｏ" フェードイン */
	if ( (this->logo_alpha += VREG(6)) >= 255 ) {
	    this->logo_alpha = 255;
	    this->alpha_mode = Title_Timewait;
	}
	break;

    case Title_Timewait:	/* 時間待ち */
	if ( this->bgm_ct >= 4626 ) {
	    Na_StopBgm( VREG(11) );
	    VREG(9) = 0;
	    this->alpha_mode = Title_Fillout;
	}
	break;

    case Title_Fillout:		/* ＦＩＬＬ フェードアウト */
	VREG(9)+= VREG(10);
	if ( VREG(9) > 254 ) {
	    VREG(9) = 255;
	    z_common_data.game_info.mode = GAME_INFO_OPENING_DEMO;
	    this->g._doing = 0;
	    ZCommon_LinkAgeBeChild( );
	    save_initialize999( );
	    ZCommonSet( day_time, 0xFFF0+VREG(94) );
	    game_set_next_game_name(&this->g, play);
////////	    sram_start_check( thisx );
	}
	break;

    case Title_Goto:		/* ＧＯＴＯ選択面 */
	this->title_alpha -= VREG(0);
	this->logo_alpha -= VREG(0);
	this->effect_alpha -= VREG(0);
	if ( this->title_alpha <= 0 ) {
	    this->title_alpha = 0;
	}
	if ( this->logo_alpha <= 0 ) {
	    this->logo_alpha = 0;
	}
	if ( this->effect_alpha <= 0 ) {
	    this->effect_alpha = 0;
	}
    default:
	break;
    }
# endif

    if ( !this->alpha_mode ) {
	if ( Pad_on_trigger(START_BUTTON) || Pad_on_trigger(A_BUTTON) || Pad_on_trigger(B_BUTTON) ) {	/* 選択画面へ */
	    VREG(8) = VREG(9) = 0;
	    this->effect_alpha = 255;
	    this->title_alpha = 210;
	    this->sub_alpha = 255;
	    this->logo_alpha = 255;
	    this->alpha_mode = 1;
	}
    } else {
	if ( this->mode == File_choose_Title ) {
	    if ( !NO_CONTROLLER ) {
		if ( Pad_on_trigger(START_BUTTON) || Pad_on_trigger(A_BUTTON) || Pad_on_trigger(B_BUTTON) ) {	/* 選択画面へ */
		    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
		    this->alpha_mode = Title_Goto;
		    this->mode = File_choose_Select;
		    this->menu_pos = Menu_Fadein;
		    this->title_no1 = 1;
		    /* ＳＲＡＭ ＳＴＡＲＴ─ＬＯＡＤ */
#if defined(GATEWAY_VERSION)
		    PRINTF("ＧＡＴＥＷＡＹ ＳＴＡＲＴ─ＬＯＡＤ ");
#else
		    PRINTF("ＳＲＡＭ ＳＴＡＲＴ─ＬＯＡＤ ");
		    sram_start_load( this, &this->sram );
#endif	/* GATEWAY_VERSION */
		    PRINTF("終了！！！\n");
		}
	    }
	}
    }
    ++this->bgm_ct;
# endif
}


/************************************************************************
 *									*
 *	タイトルＤＲＡＷ						*
 *									*
 ************************************************************************/
extern void
file_choose_title_draw( Game *thisx )
{
    thisx;
# if 0
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kanfont	*kanfont = (Kanfont *)&this->kanfont;


    float	eye_x, eye_y, eye_z;
    unshort	i, j, k, xpos, ypos;
    static short	no_alpha = 0;
    static short	no_alpha_mode = 0;
    static short	no_alpha_ct = 0;
    static unchar no_controller[] = {
	AAN, AAO, AAC, AAO, AAN, AAT, AAR, AAO, AAL, AAL, AAE, AAR,
    };
    static unchar *g_title_efc_txt_data[] = {
	g_title_efc_1_txt, g_title_efc_2_txt, g_title_efc_3_txt,
	g_title_efc_4_txt, g_title_efc_5_txt, g_title_efc_6_txt,
	g_title_efc_7_txt, g_title_efc_8_txt, g_title_efc_9_txt,
    };

    OPEN_DISP(this->g.graph);

    /*
     * ＴＩＴＬＥ表示
     */
    gDPPipeSync( NEXT_DISP );

    if ( this->mode == File_choose_Title ) {
	/* ＶＲーＢＯＸ表示 */
	eye_x = (1000.0f * cos_s(ZREG(11))) - (1000.0f * sin_s(ZREG(11)));
	eye_y = (float)ZREG(13);
	eye_z = (1000.0f * sin_s(ZREG(11))) + (1000.0f * cos_s(ZREG(11)));
	view_setting( this, eye_x, eye_y, eye_z );
	
	vr_box_draw( &this->vr_box, this->g.graph, 1, this->kankyo.vr_box_scale, eye_x, eye_y, eye_z );
	gDPSetTextureLUT ( NEXT_DISP, G_TT_NONE );
	ZREG(11) += ZREG(10);

	/* 環境設定 */
/////////	Kankyo_vrbox_change( 1, &this->kankyo, &this->vr_box );
/////////	ZCommonSet(zelda_time, ZCommonGet(zelda_time) + TIME_SPEED );
    }

    /*
     * タイトル表示
     */
    rectangle_a_prim(this->g.graph);
    /* ロゴ本体を覆う光のエフェクト */
#define G_CC_INT550	TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, 1, PRIM_LOD_FRAC, TEXEL0
#define G_CC_INT551	PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0
    VREG(27) -= 2;
    gDPSetCycleType( NEXT_DISP, G_CYC_2CYCLE );
    gDPSetRenderMode( NEXT_DISP, G_RM_PASS, G_RM_XLU_SURF2 );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT550, G_CC_INT551 );
    gDPSetPrimColor( NEXT_DISP, 0, 128, 255, 255, 170, this->effect_alpha );
    gDPSetEnvColor( NEXT_DISP, 255, 100,   0, 255 );
    for ( i = k = 0, ypos = 0; i < 3; i++ ) {
	for ( j = 0, xpos = VREG(30); j < 3; j++, k++, xpos += 64 ) {
	    SET_NOW_DISP( texture_multi_rectangle( NOW_DISP,
						   g_title_efc_txt_data[k],
						   g_title_mable_txt,
						   64, 64,
						   32, 32,
						   xpos, ypos,
						   64, 64,
						   1 << 10, 1 << 10,
						   VREG(17), VREG(18),
						   k )
			  );
	}
	ypos += 64;
    }
    rectangle_a_prim(this->g.graph);
     /* 剣と盾、『ZELDA』 */
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->title_alpha );
#if defined(USE_NEW_DUNGEON)
    display_rgba32b ( this->g.graph, ZREG(16), ZREG(17), g_title_ura_txt, 160, 160 );
#else /* defined(USE_NEW_DUNGEON) */
    display_rgba32b ( this->g.graph, ZREG(16), ZREG(17), g_title_txt, 160, 160 );
#endif /* defined(USE_NEW_DUNGEON) */
    /* タイトルロゴ */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 0, 0, 0, this->title_alpha );
    gDPSetEnvColor( NEXT_DISP, 100, 0, 100, 255 );
    SET_NOW_DISP( texture_rectangleI8( NOW_DISP, g_title_sub_1_txt,
				       72, 8,
				       VREG(31), 73,
				       72, 8,
				       1 << 10, 1 << 10 )
		  );
    SET_NOW_DISP( texture_rectangleI8( NOW_DISP, g_title_sub_2_txt,
				       96, 8,
				       VREG(32), 127,
				       96, 8,
				       1 << 10, 1 << 10 )
		  );
    if ( !J_N ) {
#define G_CC_INT552	TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, 0, 0, 0, TEXEL0
#define G_CC_INT553	PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0
	VREG(28) += 1;
	gDPPipeSync( NEXT_DISP );
	gDPSetCycleType( NEXT_DISP, G_CYC_2CYCLE );
	gDPSetRenderMode( NEXT_DISP, G_RM_PASS, G_RM_XLU_SURF2 );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT552, G_CC_INT553 );
	gDPSetPrimColor( NEXT_DISP, 0, 128, 255, 255, 170, this->sub_alpha );
	gDPSetEnvColor( NEXT_DISP, 255, 150,   0, 255 );
	gDPLoadMultiBlock( NEXT_DISP,
			   g_title_sub_j_txt, 0, G_TX_RENDERTILE,
			   G_IM_FMT_I, G_IM_SIZ_8b, 128, 16, 0,
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			   G_TX_NOMASK, G_TX_NOMASK,
			   G_TX_NOLOD, G_TX_NOLOD );
	gDPLoadMultiBlock( NEXT_DISP,
			   g_title_mable_txt, 256, G_TX_RENDERTILE+1,
			   G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
			   G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			   5, 5,
			   VREG(25), VREG(26) );
	gDPSetTileSize( NEXT_DISP, G_TX_RENDERTILE+1, VREG(28)&0x7f,  VREG(27)&0x7f, (VREG(28)&0x7f) + (31<<2), (VREG(27)&0x7f) + (31<<2) );
	gSPTextureRectangle( NEXT_DISP,
			     (VREG(33) * 0x4), (144 * 0x4),
			     ((VREG(33) + 128) * 0x4), ((144 + 16) * 0x4),
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	
	rectangle_a_prim(this->g.graph);
    }
# if 0
	/* トライフォース */
	display_rgba32b ( this->g.graph, ZREG(16), ZREG(17), g_title2, 112, 96 );
	/* タイトルロゴ */
	display_rgba32b ( this->g.graph, ZREG(14), ZREG(15), g_title1, 192, 48 );
	/* サブタイトル */
	display_rgba32b ( this->g.graph, ZREG(18), ZREG(19), g_title3, 128, 32 );
	/* エフェクト表示 */
#define  G_CC_INT10      PRIMITIVE, ENVIRONMENT, TEXEL0,          ENVIRONMENT, TEXEL0,      0, PRIMITIVE,     ENVIRONMENT
#define  G_CC_INT11      PRIMITIVE, ENVIRONMENT, TEXEL0,          ENVIRONMENT, TEXEL0,      0, ENVIRONMENT,   0
	if ( !ZREG(5) ) {
	    gDPSetCombineMode( NEXT_DISP, G_CC_INT10, G_CC_INT10 );
	} else if ( ZREG(5) == 1 ) {
	    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
	}
	gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->effect_alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 255, 255, 0 );
	for ( i = 0, ypos = ZREG(8)-7; i < 27; i++, ypos+=7 ) {
	    gDPLoadTextureBlock( NEXT_DISP,
				 g_title4_txt+(264*7*i), G_IM_FMT_I, G_IM_SIZ_8b, 264, 7, 0,
				 G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	    gSPTextureRectangle( NEXT_DISP,
				 ZREG(7) << 2, ypos << 2,
				 (ZREG(7) + 264) << 2, (ypos + 7) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 <<10, 1 << 10 );
	}
	gDPLoadTextureBlock( NEXT_DISP,
			     g_title4_txt+(264*7*i), G_IM_FMT_I, G_IM_SIZ_8b, 264, 3, 0,
			     G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_DISP,
			     ZREG(7) << 2, ypos << 2,
			     (ZREG(7) + 264) << 2, (ypos + 3) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 <<10, 1 << 10 );
# endif
    /* １９９７Ｎｉｎｔｅｎｄｏ */
    rectangle_a_prim(this->g.graph);
#define  G_CC_INT444	0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0
    gDPSetCombineMode( NEXT_DISP, G_CC_INT3, G_CC_INT3 );
////////    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->logo_alpha );
    gDPSetPrimColor( NEXT_DISP, 0, 0, this->logo_alpha, this->logo_alpha, this->logo_alpha, this->logo_alpha );
#if defined(USE_NEW_DUNGEON)
    gDPLoadTextureBlock ( NEXT_DISP,
			  g_title_cpr_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 16, 0,
			  G_TX_CLAMP, G_TX_CLAMP,
			  G_TX_NOMASK, G_TX_NOMASK,
			  G_TX_NOLOD, G_TX_NOLOD);
#else /* defined(USE_NEW_DUNGEON) */
    gDPLoadTextureBlock ( NEXT_DISP,
			  g_title_cpr_ura_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 16, 0,
			  G_TX_CLAMP, G_TX_CLAMP,
			  G_TX_NOMASK, G_TX_NOMASK,
			  G_TX_NOLOD, G_TX_NOLOD);
#endif /* defined(USE_NEW_DUNGEON) */
    gSPTextureRectangle( NEXT_DISP,
			 94 << 2, 198 << 2,
			 (94 + 128) << 2, (198 + 16) << 2,
			 G_TX_RENDERTILE, 0, 0, 1 <<10, 1 << 10 );

    
    if ( z_common_data.file_no == 0xFEDC ) {
	no_alpha = (260/VREG(24)) * no_alpha_ct;
	if ( no_alpha >= 255 ) no_alpha = 255;
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT4, G_CC_INT4 );
	gDPSetPrimColor( NEXT_DISP, 0, 0,   0,   0,   0, no_alpha );
	xpos = VREG(20) + 1;
	for ( i = 0; i < 12; i++ ) {
	    moji_display( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*no_controller[i]), xpos, VREG(21)+1 );
	    xpos += VREG(22);
	    if ( i == 1 ) xpos += VREG(23);
	}
	gDPPipeSync( NEXT_DISP );
	gDPSetPrimColor( NEXT_DISP, 0, 0, 100, 255, 255, no_alpha );
	xpos = VREG(20);
	for ( i = 0; i < 12; i++ ) {
	    moji_display( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*no_controller[i]), xpos, VREG(21) );
	    xpos += VREG(22);
	    if ( i == 1 ) xpos += VREG(23);
	}
	if ( no_alpha_mode ) {
	    if ( !(--no_alpha_ct) ) no_alpha_mode = 0;
	} else {
	    if ( (++no_alpha_ct) >= VREG(24) ) no_alpha_mode = 1;
	}
    }

    if ( this->mode == File_choose_Title ) {
	Gfx *gp;
	/* バージョン表示 */
	gp = NOW_OVERLAY_DISP();
	draw_version(&gp);
	SET_NOW_OVERLAY_DISP(gp);
    }

    CLOSE_DISP(this->g.graph);
# endif
}


















/*===============================================================================
  ==============================  メイン メニュー   =============================
  ===============================================================================*/
/*===============================================================
  =	   Ａｌｐｈａ値変更					=
 ===============================================================*/
static void
alpha_set( Game_file_choose *this )
{
    Sram	*sram = (Sram *)&this->sram;

    short	i;

    this->frame_title_alpha[0] += VREG(1);
    this->base_alpha += VREG(2);
    for ( i = 0; i < 3; i++ ) {
	this->file_alpha[i] = this->base_alpha;
	if ( REGCK_ALL( i ) ) {
		this->plate_alpha[i] =
		this->name_alpha[i] = this->base_alpha;
		this->connect_alpha[i] += VREG(1);
		if ( this->connect_alpha[i] >= FRAME_ALPHA ) this->connect_alpha[i] = FRAME_ALPHA;
	}
    }
    this->panel_alpha[0] = 
	this->panel_alpha[1] =
	this->option_alpha = this->base_alpha;
}

/*===============================================================
  =	   セーブ回数カウントチェック				=
 ===============================================================*/
static void
savect_count( unshort savect, short *ct0, short *ct1, short *ct2 )
{
    *ct0 = 0;
    *ct1 = 0;
    *ct2 = savect;
    do {
	if ( (*ct2 - 100) < 0 ) break;
	*ct0 += 1;
	*ct2 -= 100;
    } while( 1 );
    do {
	if ( (*ct2 - 10) < 0 ) break;
	*ct1 += 1;
	*ct2 -= 10;
    } while( 1 );
}


/*===============================================================
  =	   フェードイン（＆スクロール）				=
 ===============================================================*/
static void
menu_fade_in( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

////////    file_choose_title_move( thisx );

    alpha_set( this );

    fill_alpha -= 40;
    this->scroll_xp -= VREG_3;
    if ( this->scroll_xp <= -94 ) {
	this->scroll_xp = -94;
	this->menu_pos = Menu_Fadein1;
	fill_alpha = 0;
    }
}
/*===============================================================
  =	   フェードイン						=
 ===============================================================*/
static void
menu_fade_in1( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


////////    file_choose_title_move( thisx );

    this->ab_alpha += VREG(1);
    alpha_set( this );
    if ( this->frame_title_alpha[0] >= FRAME_ALPHA ) {
	this->frame_title_alpha[0] = FRAME_ALPHA;
	this->ab_alpha = FRAME_ALPHA;
	this->base_alpha = BASE_ALPHA;
	this->menu_pos = Menu_Select;
    }
}


/*===============================================================
  =	   ファイル選択処理					=
 ===============================================================*/
static void
menu_select_play( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Sram	*sram = (Sram *)&this->sram;

    pad_t	*pad = &this->g.pads[0];

    static unchar sample_name[] = {
	SSS, SSS, SSS, SSS, SSS, SSS, SSS, SSS,	/* player_name[8] */
    };


    if ( Pad_on_trigger(START_BUTTON) || Pad_on_trigger(A_BUTTON) ) {
#if defined(GATEWAY_VERSION)
	if ( !this->no ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	    /* 名前登録へ */
	    this->menu_pos = Menu_Go_Nameset;
	    this->name_contents = 99;
	    this->name_page = 0;
	    if ( J_N ) this->name_page = Eisu_eisu;
	    this->name_xpos = 0;
	    this->name_ypos = 0;
	    this->mjp = 0;
	    this->page_alpha = 0;
	    this->name_index = 0;
	    this->shift_xp = 120;
	    this->name_plate_alpha =  0;	// 名前登録パネルアルファ値
	    Memcpy( &this->name[this->no], sample_name, 8 );
	} else {
	    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	    this->menu_pos_old = this->menu_pos;
	    this->menu_pos = Menu_Go_Option;
	    this->name_contents = 0;
	    this->name_xpos = 0;
	    this->name_ypos = 0;
	    this->page_alpha = 0;
	    this->name_index = 0;
	    this->shift_xp = 120;
	    this->cpdl_mct = FRAME_CT;
	}
#else
	if ( this->no < 3 ) {
	    PRINTF("REGCK_ALL[%x]=%x,%x,%x,%x,%x,%x\n",this->no, sram->read_buff[sram_save_address[this->no]+(SAVE_BASE)+0], sram->read_buff[sram_save_address[this->no]+(SAVE_BASE)+1], sram->read_buff[sram_save_address[this->no]+(SAVE_BASE)+2], sram->read_buff[sram_save_address[this->no]+(SAVE_BASE)+3], sram->read_buff[sram_save_address[this->no]+(SAVE_BASE)+4], sram->read_buff[sram_save_address[this->no]+(SAVE_BASE)+5]);
	    if ( !(REGCK_ALL( this->no )) ) {
		Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
		/* 名前登録へ */
		this->menu_pos = Menu_Go_Nameset;
		this->name_contents = 99;
		this->name_page = 0;
		if ( J_N ) this->name_page = Eisu_eisu;
		this->name_xpos = 0;
		this->name_ypos = 0;
		this->mjp = 0;
		this->page_alpha = 0;
		this->name_index = 0;
		this->shift_xp = 120;
		this->name_plate_alpha =  0;	// 名前登録パネルアルファ値
		Memcpy( &this->name[this->no], sample_name, 8 );
	    } else {
		if ( this->f_64dd[this->no] == this->flag_64dd ) {
		    /* ゲーム */
		    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
////////		this->menu_pos_next = Menu_kettei;
////////		this->menu_pos_old = this->menu_pos;
////////		this->menu_pos = Menu_Next;
		    this->cpdl_mct = FRAME_CT;
		    this->decision_mode = 0;
		    this->decision_no = this->no;
		    this->mode = File_choose_Decision;
		    this->title_no1 = 1;
		} else {
		    if ( !this->f_64dd[this->no] ) {
			Na_StartSystemSe(NA_SE_SY_FSEL_ERROR);
		    } else {
#ifdef USE_N64DD
			if (n64dd_isInitialized()) {
			    PRINTF(ESC_CYAN "ゼルダディスクは入ってる？\n" ESC_NORMAL);
			    n64dd_MediumCheck();
			    
			    Na_StartIntroCutBgm( NA_BGM_FILE_SELECT );
			}
#endif /* USE_N64DD */
		    }
		}
	    }
	} else {
	    if ( this->caution_no == -1 ) {
		/* コピー/消す */
		Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
		this->menu_pos_old = this->menu_pos;
		if ( this->no == 3 ) {
		    /* コピー */
		    this->menu_pos = Menu_Copy_0;
		    this->title_no1 = 2;
		} else if ( this->no == 4 ) {
		    /* 消す */
		    this->menu_pos = Menu_Delt_0;
		    this->title_no1 = 6;
		} else {
		    /* ＯＰＴＩＯＮ */
		    this->menu_pos = Menu_Go_Option;
		    this->name_contents = 0;
		    this->name_xpos = 0;
		    this->name_ypos = 0;
		    this->page_alpha = 0;
		    this->name_index = 0;
		    this->shift_xp = 120;
		}
		this->cpdl_mct = FRAME_CT;
	    } else {
		Na_StartSystemSe(NA_SE_SY_FSEL_ERROR);
	    }
	}
#endif /* GATEWAY_VERSION */
    } else {
	if ( ABS(this->wkey_y) > KEY_ANGLE_3D ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
#if defined(GATEWAY_VERSION)
	    this->no ^= 1;
#else
	    if ( this->wkey_y > KEY_ANGLE_3D ) {
		if ( (--this->no) <  0 ) this->no = 5;
	    } else {
		if ( (++this->no) >= 6 ) this->no = 0;
	    }
#endif	/* GATEWAY_VERSION */
	}
#if defined(GATEWAY_VERSION)
#else
	if ( this->no == 3 ) {
	    if ( !(REGCK_ALL( 0 ) || REGCK_ALL( 1 ) || REGCK_ALL( 2 )) ) {
		/* 「コピーするファイルがありません」 */
		this->caution_pt = this->no;
		this->caution_no = 0;
		this->caution_alpha = FRAME_ALPHA;
	    } else if ( REGCK_ALL( 0 ) && REGCK_ALL( 1 ) && REGCK_ALL( 2 ) ) {
		/* 「ファイルの空きがありません」 */
		this->caution_pt = this->no;
		this->caution_no = 2;
		this->caution_alpha = FRAME_ALPHA;
	    } else this->caution_no = -1;
	} else if ( this->no == 4 ) {
	    if ( !(REGCK_ALL( 0 ) || REGCK_ALL( 1 ) || REGCK_ALL( 2 )) ) {
		/* 「消すファイルがありません」 */
		this->caution_pt = this->no;
		this->caution_no = 1;
		this->caution_alpha = FRAME_ALPHA;
	    } else this->caution_no = -1;
	} else this->caution_no = -1;
#endif	/* GATEWAY_VERSION */
    }
}


/*===============================================================
  =	   ファイル選択処理					=
 ===============================================================*/
static void
menu_kettei( Game *thisx )
{
    thisx;
}
/*===============================================================
  =	   ファイル選択処理					=
 ===============================================================*/
static void
menu_next( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    XREG(73) += 2;
    if ( XREG(73) == 254 ) {
	this->menu_pos = this->menu_pos_next;
	XREG(73) = 0;
    }
}


/*===============================================================
  =	   名前登録へ 						=
 ===============================================================*/
static void
menu_go_nameset( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    if ( (this->goto_angle += VREG(16)) >= 314.0f ) {
	this->goto_angle = 314.0f;
	this->menu_pos = Menu_Nameset_Fdin;
    }
}


/*===============================================================
  =	   ＯＰＴＩＯＮへ 					=
 ===============================================================*/
static void
menu_go_option( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    if ( (this->goto_angle += VREG(16)) >= 314.0f ) {
	this->goto_angle = 314.0f;
	this->menu_pos = Menu_Option_Fdin;
    }
}

/*===============================================================
  =	   ファイル選択へ					=
 ===============================================================*/
static void
menu_go_select( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    if ( (this->goto_angle += VREG(16)) >= 628.0f ) {
	this->goto_angle = 0.0f;
	this->menu_pos = Menu_Select;
    }
}

/*===============================================================
  =	   メニュー処理						=
 ===============================================================*/
static void
(*menu_play[Menu_Point])( Game *thisx ) =
{
    menu_fade_in,		/* ０：フェードイン（＆スクロール）*/
    menu_fade_in1,		/* １：フェードイン */
    menu_select_play,		/* ２：ファイル選択 */
    menu_copy_init,		/* ３：Ｃｏｐｙ（イニシャル ＆ 移動） */
    menu_copy_which,		/* ４：        （どれをコピーしますか？）*/
    menu_copy_move1,		/* ５：        （移動１） */
    menu_copy_fdin1,		/* ６：        （フェードイン１） */
    menu_copy_where,		/* ７：        （どこにコピーしますか？）*/
    menu_copy_fdout1,		/* ８：        （フェードアウト１） */
    menu_copy_cancel1,		/* ９：        （キャンセル１） */
    menu_copy_move2,		/*１０：       （移動２） */
    menu_copy_fdin2,		/*１１：       （フェードイン２） */
    menu_copy_ok,		/*１２：       （本当にコピーしますか？）*/
    menu_copy_fdout2,		/*１３：       （フェードアウト２） */
    menu_copy_move3,		/*１４：       （移動３） */
    menu_copy_fdin3,		/*１５：       （フェードイン３） */
    menu_copy_end,		/*１６：       （コピーが終了しました）*/
    menu_copy_end1,		/*１７：       （コピーが終了しました）*/
    menu_copy_end2,		/*１８：       （コピーが終了しました）*/
    menu_copy_return,		/*１９：       （ＲＥＴＵＲＮ）*/
    menu_delt_init,		/*２０：Ｄｅｌ（イニシャル ＆ 移動） */
    menu_delt_where,		/*２１：      （どれを消しますか？） */
    menu_delt_move,		/*２２：      （移動） */
    menu_delt_fdin,		/*２３：      （フェードイン） */
    menu_delt_ok,		/*２４：      （本当に消しますか？） */
    menu_delt_fdout,		/*２５：      （フェードアウト） */
    menu_delt_cancel,		/*２６：      （キャンセル） */
    menu_delt_end,		/*２７：      （消去しました） */
    menu_delt_end1,		/*２８：      （消去しました） */
    menu_delt_end2,		/*２９：      （消去しました） */
    menu_delt_return,		/*３０：      （ＲＥＴＵＲＮ） */
    menu_kettei,		/*３１：ファイル決定 */
    menu_go_nameset,		/*３２：ファイル選択から名前登録へ */
    menu_nameset_play,		/*３３：名前登録 */
    menu_nameset_fdin,		/*３４：名前登録フェードイン */
    menu_go_select,		/*３５：名前登録からファイル選択へ */
    menu_go_option,		/*３６：ファイル選択からＯＰＴＩＯＮへ */
    menu_option_play,		/*３７：ＯＰＴＩＯＮ */
    menu_option_fdin,		/*３８：ＯＰＴＩＯＮフェードイン */
    menu_go_select,		/*３９：ＯＰＴＩＯＮからファイル選択へ */
    menu_next,			/*４０：次のメニューへ */
};


# if 0
/*===============================================================
  =	   フレームＰＲＩＭカラー計算				=
 ===============================================================*/
static void
frame_color_change( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    short	rc, gc, bc, k;


    /* フレームＰＲＩＭカラー計算 */
    if ( this->kankyo.vr_box_scale ) {
	k = 256 - this->kankyo.vr_box_scale;
	rc = (ABS(this->frame_rgb[0] - XREG(84+this->kankyo.vrbox_tenso_1) )) / k;
	gc = (ABS(this->frame_rgb[1] - XREG(88+this->kankyo.vrbox_tenso_1) )) / k;
	bc = (ABS(this->frame_rgb[2] - XREG(92+this->kankyo.vrbox_tenso_1) )) / k;
	
	if ( this->frame_rgb[0] >= XREG(84+this->kankyo.vrbox_tenso_1) ) this->frame_rgb[0] -= rc;
	else                                                             this->frame_rgb[0] += rc;
	if ( this->frame_rgb[1] >= XREG(88+this->kankyo.vrbox_tenso_1) ) this->frame_rgb[1] -= gc;
	else                                                             this->frame_rgb[1] += gc;
	if ( this->frame_rgb[2] >= XREG(92+this->kankyo.vrbox_tenso_1) ) this->frame_rgb[2] -= bc;
	else                                                             this->frame_rgb[2] += bc;
    } else {
	this->frame_rgb[0] = XREG(84+this->kankyo.vrbox_tenso_0);
	this->frame_rgb[1] = XREG(88+this->kankyo.vrbox_tenso_0);
	this->frame_rgb[2] = XREG(92+this->kankyo.vrbox_tenso_0);
    }
}
# endif
/*===============================================================
  =	   カーソルＰＲＩＭカラー計算				=
 ===============================================================*/
extern void
cursor_color_change( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


# if 0
    static short cursor_color[][3] = {
    	{ 255, 200, 200, },	// 朝
    	{ 220, 220, 255, },	// 昼
    	{ 255, 200,  70, },	// 夕
    	{ 155, 255, 255, },	// 夜
    };
# endif
    static short cursor_alpha[] = {
	70, 200,
    };
////////    short	rc, gc, bc, ac;
    short	ac;


# if 0
    if ( this->kankyo.vr_box_scale ) {
	ac = 256 - this->kankyo.vr_box_scale;
	rc = (ABS(this->cursor_rgba[0] - cursor_color[this->kankyo.vrbox_tenso_1][0])) / ac;
	gc = (ABS(this->cursor_rgba[1] - cursor_color[this->kankyo.vrbox_tenso_1][1])) / ac;
	bc = (ABS(this->cursor_rgba[2] - cursor_color[this->kankyo.vrbox_tenso_1][2])) / ac;
	
	if ( this->cursor_rgba[0] >= cursor_color[this->kankyo.vrbox_tenso_1][0] ) this->cursor_rgba[0] -= rc;
	else                                                                       this->cursor_rgba[0] += rc;
	if ( this->cursor_rgba[1] >= cursor_color[this->kankyo.vrbox_tenso_1][1] ) this->cursor_rgba[1] -= gc;
	else                                                                       this->cursor_rgba[1] += gc;
	if ( this->cursor_rgba[2] >= cursor_color[this->kankyo.vrbox_tenso_1][2] ) this->cursor_rgba[2] -= bc;
	else                                                                       this->cursor_rgba[2] += bc;
    } else {
	this->cursor_rgba[0] = cursor_color[this->kankyo.vrbox_tenso_0][0];
	this->cursor_rgba[1] = cursor_color[this->kankyo.vrbox_tenso_0][1];
	this->cursor_rgba[2] = cursor_color[this->kankyo.vrbox_tenso_0][2];
    }
# endif
    /* カーソル点滅 */
    ac = (ABS(this->cursor_rgba[3] - cursor_alpha[this->cursor_pt] )) / XREG(35);
    if ( this->cursor_rgba[3] >= cursor_alpha[this->cursor_pt] ) this->cursor_rgba[3] -= ac;
    else							 this->cursor_rgba[3] += ac;
    if ( !(--XREG(35)) ) {
	this->cursor_rgba[3] = cursor_alpha[this->cursor_pt];
	XREG(35) = XREG(36 + this->cursor_pt);
	this->cursor_pt ^= 1;
    }
}
/************************************************************************
 *									*
 *	メイン メニューＭＯＶＥ						*
 *									*
 ************************************************************************/
static void
file_choose_menu_move( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    /* ＰＬＡＹ */
# if 0
#ifndef SHOW_VERSION
    menu_play[this->menu_pos]( thisx );
#else
    if ( isZuruMode() ) {
	menu_play[this->menu_pos]( thisx );
    } else {
	menu_playE3[this->menu_pos]( thisx );
    }
#endif /* SHOW_VERSION */
# else
    menu_play[this->menu_pos]( thisx );
# endif
}



/*===============================================================
  =	ファイル選択フレーム表示				=
 ===============================================================*/
static void
frame_vtx_set( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    short	i, j, kk, xp, yp, xxp;

    /*
     * フレーム Ｖｔｘデータａｌｌｏｃ
     */
    /* ＩＴＥＭフレーム */
    this->frameVtx = (Vtx_t *)graph_alloc(this->g.graph, sizeof(Vtx_t) * ((5*4) * 4) );
    xp = (this->scroll_xp-26) - 64;
    for ( i = j = 0; i < 4; i++ ) {
	xp += 64;
	if ( i == 3 ) xxp = 48;
	else          xxp = 64;
	for ( kk = 0, yp = 80; kk < 5; j+=4, kk++, yp -= 32 ) {
	    this->frameVtx[j+0].ob[0] = this->frameVtx[j+2].ob[0] = xp;
	    this->frameVtx[j+1].ob[0] = this->frameVtx[j+3].ob[0] = (short)(xp+xxp);
	    this->frameVtx[j+0].ob[1] = this->frameVtx[j+1].ob[1] = yp;
	    this->frameVtx[j+2].ob[1] = this->frameVtx[j+3].ob[1] = (short)(yp-32);
	    this->frameVtx[j+0].ob[2] = this->frameVtx[j+1].ob[2] =
		this->frameVtx[j+2].ob[2] = this->frameVtx[j+3].ob[2] = 0;
	    this->frameVtx[j+0].flag = this->frameVtx[j+1].flag =
		this->frameVtx[j+2].flag = this->frameVtx[j+3].flag = 0;
	    this->frameVtx[j].tc[0] = this->frameVtx[j].tc[1] =
		this->frameVtx[j+1].tc[1] = this->frameVtx[j+2].tc[0] = 0;
	    this->frameVtx[j+1].tc[0] = this->frameVtx[j+3].tc[0] = xxp << 5;
	    this->frameVtx[j+2].tc[1] = this->frameVtx[j+3].tc[1] = 32 << 5;
	    this->frameVtx[j+0].cn[0] = this->frameVtx[j+2].cn[0] = 
		this->frameVtx[j+0].cn[1] = this->frameVtx[j+2].cn[1] =
		this->frameVtx[j+0].cn[2] = this->frameVtx[j+2].cn[2] =
		this->frameVtx[j+1].cn[0] = this->frameVtx[j+3].cn[0] =
		this->frameVtx[j+1].cn[1] = this->frameVtx[j+3].cn[1] =
		this->frameVtx[j+1].cn[2] = this->frameVtx[j+3].cn[2] =
		this->frameVtx[j+0].cn[3] = this->frameVtx[j+2].cn[3] =
		this->frameVtx[j+1].cn[3] = this->frameVtx[j+3].cn[3] = 255;
	}
    }
}

/*===============================================================
  =	ファイル選択画面Ｖｔｘセット				=
 ===============================================================*/
static void
menu_file_choose_vtxset( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Sram	*sram = (Sram *)&this->sram;


    static short save_count_xpd0[] = {
	26, 10, 10, 10,
    };
    static short save_count_xpd1[] = {
	32, 12, 12, 12,
    };
    static short save_count_ypd[] = {
	16, 12, 12, 12,
    };
    
    static short select_vtx_pt[] = {
	F_INDEX1, F_INDEX2, F_INDEX3, CD_INDEX+0, CD_INDEX+4, CD_INDEX+8,
    };
    static short copy_del_vtx_pt[] = {
	F_INDEX1, F_INDEX2, F_INDEX3, CD_INDEX+4,
    };
    static short copy_del_decision_vtx_pt[] = {
	CD_INDEX+0, CD_INDEX+4,
    };
    static short decision_vtx_pt[] = {
	CD_INDEX+0, CD_INDEX+4,
    };

    short	i, j, k, kk, xp, yp;


    
    /* ファイル選択画面Ｖｔｘデータａｌｌｏｃ */
    this->selectVtx = (Vtx_t *)graph_alloc(this->g.graph, sizeof(Vtx_t) * SELECTVTX );
    for( i = 0; i < SELECTVTX; i+=4 ) {
	    this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = 300;
	    this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = this->selectVtx[i+0].ob[0] + 16;
	    this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = 0;
	    this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = this->selectVtx[i+0].ob[1] - 16;
	    this->selectVtx[i+0].ob[2] = this->selectVtx[i+1].ob[2] = 
	    this->selectVtx[i+2].ob[2] = this->selectVtx[i+3].ob[2] = 0;
	    this->selectVtx[i+0].flag = this->selectVtx[i+1].flag = 
	    this->selectVtx[i+2].flag = this->selectVtx[i+3].flag = 0;
	    this->selectVtx[i+0].tc[0] = this->selectVtx[i+0].tc[1] = 
	    this->selectVtx[i+1].tc[1] = this->selectVtx[i+2].tc[0] = 0;
	    this->selectVtx[i+1].tc[0] = this->selectVtx[i+2].tc[1] = 
	    this->selectVtx[i+3].tc[0] = this->selectVtx[i+3].tc[1] = 16 << 5;
 	    this->selectVtx[i+0].cn[0] = this->selectVtx[i+1].cn[0] = 
		this->selectVtx[i+2].cn[0] = this->selectVtx[i+3].cn[0] =
		this->selectVtx[i+0].cn[1] = this->selectVtx[i+1].cn[1] = 
		this->selectVtx[i+2].cn[1] = this->selectVtx[i+3].cn[1] =
		this->selectVtx[i+0].cn[2] = this->selectVtx[i+1].cn[2] = 
		this->selectVtx[i+2].cn[2] = this->selectVtx[i+3].cn[2] = 
		this->selectVtx[i+0].cn[3] = this->selectVtx[i+1].cn[3] = 
		this->selectVtx[i+2].cn[3] = this->selectVtx[i+3].cn[3] = 255;
    }


    /* タイトル */
    this->selectVtx[0].ob[0] = this->selectVtx[2].ob[0] = this->scroll_xp;
    this->selectVtx[1].ob[0] = this->selectVtx[3].ob[0] = (short)(this->selectVtx[0].ob[0] + 128);
    this->selectVtx[0].ob[1] = this->selectVtx[1].ob[1] = XREG_0 + 16 + 12;
    this->selectVtx[2].ob[1] = this->selectVtx[3].ob[1] = (short)(this->selectVtx[0].ob[1] - 16);
    this->selectVtx[1].tc[0] = this->selectVtx[3].tc[0] = 128 << 5;
    
    
    /* 拡張プレート */
    yp = XREG_0;
    for ( i = 4, k = 0; k < 3; k++ ) {
	xp = this->scroll_xp - 6;
	for ( j = 0; j < 5; xp+=decision_xpd[j], j++, i+=4 ) {
	    this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
	    this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + decision_xpd[j]);
	    this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = yp + this->decision_ypd[k];
	    this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 56);
	    this->selectVtx[i+1].tc[0] = this->selectVtx[i+3].tc[0] = decision_xpd[j] << 5;
	    this->selectVtx[i+2].tc[1] = this->selectVtx[i+3].tc[1] = 56 << 5;
	}
    }


    /* 伝説の書ｘ（）*/
    yp = XREG_0;
    xp = this->scroll_xp - 6;
    for ( j = 0; j < 3; j++, i+=(5*4), yp-=16 ) {
	/* ＦＩＬＥプレート */
	this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
	this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + 64);
	this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = yp + this->cpdl_yp[j];
	this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 16);
	this->selectVtx[i+1].tc[0] = this->selectVtx[i+3].tc[0] = 64 << 5;

	/* 名前プレート */
	this->selectVtx[i+4].ob[0] = this->selectVtx[i+6].ob[0] = (short)(xp + 64);
	this->selectVtx[i+5].ob[0] = this->selectVtx[i+7].ob[0] = (short)(this->selectVtx[i+4].ob[0] + 108);
	this->selectVtx[i+4].ob[1] = this->selectVtx[i+5].ob[1] = yp + this->cpdl_yp[j];
	this->selectVtx[i+6].ob[1] = this->selectVtx[i+7].ob[1] = (short)(this->selectVtx[i+4].ob[1] - 16);
	this->selectVtx[i+5].tc[0] = this->selectVtx[i+7].tc[0] = 108 << 5;
	
	/* ６４ＤＤプレート */
	if ( this->menu_pos == Menu_Copy_E && j == this->copy_no ) {
	    kk = XREG_0 + this->decision_ypd[j];
	} else if ( (this->menu_pos == Menu_Copy_F || this->menu_pos == Menu_Copy_G) && j == this->copy_no ) {
	    kk = yp + this->cpdl_yp[j];
	} else {
	    kk = yp + this->cpdl_yp[j] + this->decision_ypd[j];
	}
	this->selectVtx[i+8].ob[0] = this->selectVtx[i+10].ob[0] = (short)(xp + 64 + 108 - 4);
	this->selectVtx[i+9].ob[0] = this->selectVtx[i+11].ob[0] = (short)(this->selectVtx[i+8].ob[0] + 44);
	this->selectVtx[i+8].ob[1] = this->selectVtx[i+9].ob[1] = kk;
	this->selectVtx[i+10].ob[1] = this->selectVtx[i+11].ob[1] = (short)(this->selectVtx[i+8].ob[1] - 16);
	this->selectVtx[i+9].tc[0] = this->selectVtx[i+11].tc[0] = 44 << 5;
	
	/* コネクタ */
	this->selectVtx[i+12].ob[0] = this->selectVtx[i+14].ob[0] = (short)(xp + 52);
	this->selectVtx[i+13].ob[0] = this->selectVtx[i+15].ob[0] = (short)(this->selectVtx[i+12].ob[0] + 24);
	this->selectVtx[i+12].ob[1] = this->selectVtx[i+13].ob[1] = yp + this->cpdl_yp[j];
	this->selectVtx[i+14].ob[1] = this->selectVtx[i+15].ob[1] = (short)(this->selectVtx[i+12].ob[1] - 16);
	this->selectVtx[i+13].tc[0] = this->selectVtx[i+15].tc[0] = 24 << 5;
	
	/* ６４ＤＤコネクタ */
	this->selectVtx[i+16].ob[0] = this->selectVtx[i+18].ob[0] = (short)(xp + 52 + 108 - 4);
	this->selectVtx[i+17].ob[0] = this->selectVtx[i+19].ob[0] = (short)(this->selectVtx[i+16].ob[0] + 24);
	this->selectVtx[i+16].ob[1] = this->selectVtx[i+17].ob[1] = yp + this->cpdl_yp[j];
	this->selectVtx[i+18].ob[1] = this->selectVtx[i+19].ob[1] = (short)(this->selectVtx[i+16].ob[1] - 16);
	this->selectVtx[i+17].tc[0] = this->selectVtx[i+19].tc[0] = 24 << 5;
    }


    /* （名前）*/
    yp = XREG_0;
    for ( j = 0; j < 3; j++, yp-=WREG(38)/*16*/ ) {
	if ( REGCK_ALL( j ) ) {
	    /* 名前 */
	    xp = this->scroll_xp - WREG(39)/*9*/;
	    if ( this->menu_pos == Menu_Copy_E && j == this->copy_no ) {
		kk = XREG_0 + this->decision_ypd[j];
	    } else if ( (this->menu_pos == Menu_Copy_F || this->menu_pos == Menu_Copy_G) && j == this->copy_no ) {
		kk = yp + this->cpdl_yp[j];
	    } else {
		kk = yp + this->cpdl_yp[j] + this->decision_ypd[j];
	    }
	    kk += 2;
	    for ( k = 0; k < 8; k++, i+=4, xp+=WREG(40)/*11*/ ) {
		this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = (short)(xp + (64+WREG(41)/*14*/));
		this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + WREG(42)/*12*/);
		this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = (short)(kk - 3);
		this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - WREG(43)/*12*/);
	    }
	    /* セーブ回数 */
	    xp = this->scroll_xp - 6 + 6 - 14;
	    kk = kk - 16 - 6;
	    for ( k = 0; k < 4; xp+=save_count_xpd0[k], k++, i+=4  ) {
		this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
		this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + save_count_xpd1[k]);
		this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = kk;
		this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - save_count_ypd[k]);
	    }
	    this->selectVtx[i-16+1].tc[0] = this->selectVtx[i-16+3].tc[0] = 32 << 5;
	    /* ＬＩＦＥ */
	    xp = this->scroll_xp - 6 + 26 + 10 + 10 + 12 + 11;
	    kk += 4;
	    for ( k = 0; k < 20; k++, i+=4, xp+=9 ) {
		this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
		this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + 10);
		this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = kk;
		this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 10);
		if ( k == 9 ) {
		    xp = this->scroll_xp -6 + 26 + 10 + 10 + 12 + 11 - 9;
		    kk -= 8;
		}
	    }
	    /* 集めた精霊石/封印 */
	    xp = this->scroll_xp -6 + 10;
	    kk -= 10;
	    for ( k = 0; k < 10; k++, i+=4, xp+=16 ) {
		this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
		this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + 16);
		this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = kk;
		this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 16);
	    }
	} else i += (8+4+20+10)*4;
    }
    
    
    /* コピー/消す */
    yp = XREG_0 - ((16*3)+8);
    xp = this->scroll_xp - 6;
    for ( j = 0; j < 2; j++, i+=4, yp-=16 ) {
	this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
	this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + 64);
	this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = yp + this->cpdl_yp[j+3];
	this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 16);
	this->selectVtx[i+1].tc[0] = this->selectVtx[i+3].tc[0] = 64 << 5;
    }

    /* オプション */
    yp = XREG_0 - ((16*3)+8) - ((16*2)+8);
    this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = xp;
    this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = this->selectVtx[i+0].ob[0] + 64;
    this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = yp + this->cpdl_yp[5];
    this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 16);
    this->selectVtx[i+1].tc[0] = this->selectVtx[i+3].tc[0] = 64 << 5;
    i += 4;
    
#if defined(GATEWAY_VERSION)
	this->selectVtx[F_INDEX1+0].ob[1] =
	    this->selectVtx[F_INDEX1+1].ob[1] = this->selectVtx[F_INDEX1].ob[1] + ZREG(4);
	this->selectVtx[F_INDEX1+2].ob[1] =
	    this->selectVtx[F_INDEX1+3].ob[1] = this->selectVtx[F_INDEX1].ob[1] - 16;
	
	this->selectVtx[CD_INDEX+0].ob[1] =
	    this->selectVtx[CD_INDEX+1].ob[1] = this->selectVtx[CD_INDEX].ob[1] + ZREG(5);
	this->selectVtx[CD_INDEX+2].ob[1] =
	    this->selectVtx[CD_INDEX+3].ob[1] = this->selectVtx[CD_INDEX].ob[1] - 16;
#endif /* GATEWAY_VERSION */

	/* カーソル */
    if ( (this->mode == File_choose_Select && this->menu_pos >= Menu_Select) || (this->mode == File_choose_Decision && this->decision_mode == Decision_Decision) ) {
	if ( this->mode == File_choose_Select ) {
	    if ( (this->menu_pos == Menu_Copy_1 || this->menu_pos == Menu_Copy_5) || (this->menu_pos == Menu_Delt_1) ) {
		j = copy_del_vtx_pt[this->no];
	    } else if ( this->menu_pos == Menu_Delt_4  || this->menu_pos == Menu_Copy_A ) {
		j = copy_del_decision_vtx_pt[this->no];
	    } else {
		j = select_vtx_pt[this->no];
	    }
	} else {
	    j = decision_vtx_pt[this->yes_no];
	}
#if defined(GATEWAY_VERSION)
	if ( !this->no ) j = F_INDEX1;
	else             j = CD_INDEX+0;
#endif /* GATEWAY_VERSION */
	this->selectVtx[i+0].ob[0] = this->selectVtx[i+2].ob[0] = (short)(this->scroll_xp - 6 - 4);
	this->selectVtx[i+1].ob[0] = this->selectVtx[i+3].ob[0] = (short)(this->selectVtx[i+0].ob[0] + 72);
	this->selectVtx[i+0].ob[1] = this->selectVtx[i+1].ob[1] = (short)(this->selectVtx[j].ob[1] + 4);
	this->selectVtx[i+2].ob[1] = this->selectVtx[i+3].ob[1] = (short)(this->selectVtx[i+0].ob[1] - 24);
	this->selectVtx[i+1].tc[0] = this->selectVtx[i+3].tc[0] = 72 << 5;
	this->selectVtx[i+2].tc[1] = this->selectVtx[i+3].tc[1] = 24 << 5;
    }
# if 0
    /* ＡＢボタン説明 */
    this->selectVtx[i+4].ob[0] = this->selectVtx[i+6].ob[0] = -72;
    this->selectVtx[i+5].ob[0] = this->selectVtx[i+7].ob[0] = this->selectVtx[i+4].ob[0] + 144;
    this->selectVtx[i+4].ob[1] = this->selectVtx[i+5].ob[1] = -80;
    this->selectVtx[i+6].ob[1] = this->selectVtx[i+7].ob[1] = this->selectVtx[i+4].ob[1] - 16;
    this->selectVtx[i+5].tc[0] = this->selectVtx[i+7].tc[0] = 144 << 5;
	
    /* 注意書き */
    this->selectVtx[i+8].ob[0] = this->selectVtx[i+10].ob[0] = this->scroll_xp - 6 + 64;
    this->selectVtx[i+9].ob[0] = this->selectVtx[i+11].ob[0] = this->selectVtx[i+8].ob[0] + 128;
    this->selectVtx[i+8].ob[1] = this->selectVtx[i+9].ob[1] = this->selectVtx[select_vtx_pt[this->caution_pt]].ob[1];
    this->selectVtx[i+10].ob[1] = this->selectVtx[i+11].ob[1] = this->selectVtx[i+8].ob[1] - 16;
    this->selectVtx[i+9].tc[0] = this->selectVtx[i+11].tc[0] = 128 << 5;
# else
    /* 注意書き */
    this->selectVtx[i+4].ob[0] = this->selectVtx[i+6].ob[0] = this->scroll_xp - 6 + 64;
    this->selectVtx[i+5].ob[0] = this->selectVtx[i+7].ob[0] = this->selectVtx[i+4].ob[0] + 128;
    this->selectVtx[i+4].ob[1] = this->selectVtx[i+5].ob[1] = this->selectVtx[select_vtx_pt[this->caution_pt]].ob[1];
    this->selectVtx[i+6].ob[1] = this->selectVtx[i+7].ob[1] = this->selectVtx[i+4].ob[1] - 16;
    this->selectVtx[i+5].tc[0] = this->selectVtx[i+7].tc[0] = 128 << 5;
# endif
}

/*===============================================================
  =	ファイル情報表示					=
 ===============================================================*/
static void
file_information_draw( Game *thisx, short no, short kkk )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kanfont	*kanfont = (Kanfont *)&this->kanfont;

    static unshort file_no[] = {
	N0_INDEX, N1_INDEX, N2_INDEX,
    };
    static unchar *item_name[] = {
	h_file_jewel_1_txt, h_file_jewel_2_txt, h_file_jewel_3_txt,
	h_fileseal_1_txt, h_fileseal_2_txt, h_fileseal_3_txt,
	h_fileseal_4_txt, h_fileseal_5_txt, h_fileseal_6_txt,
    };
    static short item_pr[] = {
	255, 255, 255,
	  0, 255,   0, 255, 200, 200,
    };
    static short item_pg[] = {
	255, 255, 255,
	255,  60, 100, 130,  50, 200,
    };
    static short item_pb[] = {
	255, 255, 255,
	  0,   0, 255,   0, 255,   0,
    };
    static short check_shift[] = {
	C_SEAL+C_MELODY+0, C_SEAL+C_MELODY+1, C_SEAL+C_MELODY+2,
	0, 1, 2, 3, 4, 5,
    };
    static unchar *h_file_save_data[] = {
	h_file_save_txt, h_file_save_nes_txt,
    };
    static short name_rgb[][3] = {
	{ 255, 255, 255, },
	{ 100, 100, 100, },
    };
    static unchar *heart_txt[] = {
	heart24_txt, heart24_2_txt,
    };
    static short heart_prim[][3] = {
	{ 255,  70,  50, },
	{ 200,   0,   0, },
    };
    static short heart_env[][3] = {
	{  50,  40,  60, },
	{ 255, 255, 255, },
    };
    
    short	i, j, k, mmm, mjp;
    short	ct[3];


    OPEN_DISP( this->g.graph );

    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT4, G_CC_INT4 );
    if ( this->name_alpha[no] ) {
	gSPVertex( NEXT_DISP, &(this->selectVtx[file_no[no]]), 32, 0);
////////    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->name_alpha[no] );
	gDPSetPrimColor( NEXT_DISP, 0, 0, name_rgb[kkk][0], name_rgb[kkk][1], name_rgb[kkk][2], this->name_alpha[no] );
	/* 登録ＮＡＭＥ表示 */
	for ( mjp = j = 0; j < 8*4; j+=4, mjp++ ) {
	    file_choose_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(this->name[no][mjp])), j );
	}
    }
    if ( this->decision_no == no || this->copy_no == no ) {
	/* セーブ回数 */
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT2, G_CC_INT2 );
	gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->decision_alpha[no] );
	gSPVertex( NEXT_DISP, &(this->selectVtx[file_no[no]+SaveVtx+4]), 12, 0);
	savect_count( this->save[no], &ct[0], &ct[1], &ct[2] );
	for ( j = k = 0; k < 3; k++, j+=4 ) {
	    file_choose_moji_set( this->g.graph, ((unchar *)kanfont->kbuffer4)+(BUF_CT*(ct[k])), j );
	}
	gDPPipeSync( NEXT_DISP );
/*
	gSPVertex( NEXT_DISP, &(this->selectVtx[file_no[no]+SaveVtx]), 4, 0);
	gDPSetPrimColor( NEXT_DISP, 0, 0, 0, 0, 0, this->decision_alpha[no] );
	gDPLoadTextureBlock_4b ( NEXT_DISP,
				 h_file_save_data[J_N], G_IM_FMT_I, 32, 16, 0,
				 G_TX_CLAMP,  G_TX_CLAMP,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD,  G_TX_NOLOD);
	gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
	*/
	/* ＬＩＦＥ */
	if ( !this->heart_status[no] ) mmm = 0;
	else                           mmm = 1;
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
	gDPSetPrimColor( NEXT_DISP, 0, 0, heart_prim[mmm][0], heart_prim[mmm][1], heart_prim[mmm][2], this->decision_alpha[no] );
	gDPSetEnvColor( NEXT_DISP, heart_env[mmm][0], heart_env[mmm][1], heart_env[mmm][2], 255 );
	k = this->life[no] / LIFE_CT;
	for ( i = j = 0; i < k; i++, j+=4 ) {
	    gSPVertex( NEXT_DISP, &(this->selectVtx[file_no[no]+LifeVtx+j]), 4, 0);
	    SET_NOW_DISP( texture_quadrangleA8( NOW_DISP, heart_txt[mmm],
							16, 16, 0 )
		);
/*	    gDPLoadTextureBlock( NEXT_DISP,
				 heart24_txt, G_IM_FMT_IA, G_IM_SIZ_8b,
				 16, 16, 0, G_TX_NOMIRROR, G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );*/
	}
	/* 集めた精霊石/封印 */
	gDPPipeSync( NEXT_DISP );
	for ( i = j = 0; i < 9; i++, j+=4 ) {
////////	    if ( this->item[no] & check_bit[8-i] ) {
	    if ( this->item[no] & check_bit[check_shift[i]] ) {
		gSPVertex( NEXT_DISP, &(this->selectVtx[file_no[no]+ItemVtx+j]), 4, 0);
		gDPPipeSync( NEXT_DISP );
		gDPSetPrimColor( NEXT_DISP, 0, 0, item_pr[i], item_pg[i], item_pb[i], this->decision_alpha[no] );
		gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
		if ( i < 3 ) {
		    gDPLoadTextureBlock( NEXT_DISP,
					 item_name[i], G_IM_FMT_RGBA, G_IM_SIZ_32b,
					 16, 16, 0,
					 G_TX_WRAP | G_TX_NOMIRROR,
					 G_TX_WRAP | G_TX_NOMIRROR,
					 G_TX_NOMASK, G_TX_NOMASK,
					 G_TX_NOLOD, G_TX_NOLOD);
		    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
		} else {
		    SET_NOW_DISP( texture_quadrangleA8( NOW_DISP, item_name[i],
							16, 16, 0 )
			);
/*		    gDPLoadTextureBlock( NEXT_DISP,
					 item_name[i], G_IM_FMT_IA, G_IM_SIZ_8b,
					 16, 16, 0,
					 G_TX_WRAP | G_TX_NOMIRROR,
					 G_TX_WRAP | G_TX_NOMIRROR,
					 G_TX_NOMASK, G_TX_NOMASK,
					 G_TX_NOLOD, G_TX_NOLOD);
		    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );*/
		}
	    }
	}
    }

    CLOSE_DISP( this->g.graph );
}


/*===============================================================
  =	ファイル選択画面表示					=
 ===============================================================*/
static void
menu_file_choose_display( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    static unshort *decision_data[] = {
	h_name2_1_txt, h_name2_2_txt, h_name2_3_txt, h_name2_4_txt, h_name2_5_txt,
    };
    /*
     *  日本版
     */
    static unchar *title_no_data[][9] = {
	{ h_mes_file_txt,		/* 0 : ファイルを選んでください */
	  h_mes_file2_txt,	/* 1 : ファイルを開きますか？ */
	  h_mes_copy_1_txt,	/* 2 : どれをコピーしますか？ */
	  h_mes_copy_2_txt,	/* 3 : どこにコピーしますか？ */
	  h_mes_copy_2_5_txt,	/* 4 : 本当にコピーしますか？ */
	  h_mes_copy_3_txt,	/* 5 : コピーが終了しました */
	  h_mes_kesu_1_txt,	/* 6 : どれを消しますか？ */
	  h_mes_kesu_2_txt,	/* 7 : 本当に消しますか？ */
	  h_mes_kesu_3_txt,	/* 8 : 消去しました */
	},
	{ h_mes_file_nes_txt,	/* 0 : ファイルを選んでください */
	  h_mes_file2_nes_txt,	/* 1 : ファイルを開きますか？ */
	  h_mes_copy_1_nes_txt,	/* 2 : どれをコピーしますか？ */
	  h_mes_copy_2_nes_txt,	/* 3 : どこにコピーしますか？ */
	  h_mes_copy_2_5_nes_txt,	/* 4 : 本当にコピーしますか？ */
	  h_mes_copy_3_nes_txt,	/* 5 : コピーが終了しました */
	  h_mes_kesu_1_nes_txt,	/* 6 : どれを消しますか？ */
	  h_mes_kesu_2_nes_txt,	/* 7 : 本当に消しますか？ */
	  h_mes_kesu_3_nes_txt,	/* 8 : 消去しました */
	},
    };
    static unchar *caution_data[][5] = {
	{ h_caution_1_txt,	/* 0 :「コピーするファイルがありません」 */
	  h_caution_2_txt,	/* 1 :「消すファイルがありません」 */
	  h_caution_3_txt,	/* 2 :「ファイルの空きがありません」 */
	  h_caution_4_txt,	/* 3 :「これは空きファイルです」 */
	  h_caution_5_txt,	/* 4 :「これは使用しています」 */
	},
	{ h_caution_1_nes_txt,	/* 0 :「コピーするファイルがありません」 */
	  h_caution_2_nes_txt,	/* 1 :「消すファイルがありません」 */
	  h_caution_3_nes_txt,	/* 2 :「ファイルの空きがありません」 */
	  h_caution_4_nes_txt,	/* 3 :「これは空きファイルです」 */
	  h_caution_5_nes_txt,	/* 4 :「これは使用しています」 */
	},
    };
    static unshort *file_no_data[][3] = {
	{ h_file_1_txt, h_file_2_txt, h_file_3_txt, },
	{ h_file_1_nes_txt, h_file_2_nes_txt, h_file_3_nes_txt, },
    };
    static unshort *select_no_data[][4] = {
	{ h_copy_txt, h_kesu_txt, h_hai_txt, h_yameru_txt, },
	{ h_copy_nes_txt, h_kesu_nes_txt, h_hai_nes_txt, h_yameru_nes_txt, },
    };
    static unshort *h_option_data[] = {
	h_option_txt, h_option_nes_txt,
    };



    short	i, j, k, kk, kkk;


    OPEN_DISP( this->g.graph );
    
	
    /* タイトル名 */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[0] );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    gSPVertex( NEXT_DISP, &(this->selectVtx[0]), 4, 0);
#if defined(GATEWAY_VERSION)
    gDPLoadTextureBlock( NEXT_DISP,
			 h_mes_file_gate_txt,
			 G_IM_FMT_IA, G_IM_SIZ_8b,
			 128, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
#else
    gDPLoadTextureBlock( NEXT_DISP,
			 title_no_data[J_N][this->title_no0],
			 G_IM_FMT_IA, G_IM_SIZ_8b,
			 128, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->frame_title_alpha[1] );
    gDPLoadTextureBlock( NEXT_DISP,
			 title_no_data[J_N][this->title_no1],
			 G_IM_FMT_IA, G_IM_SIZ_8b,
			 128, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
#endif	/* GATEWAY_VERSION */

    /* 拡張決定プレート */
    kk = 4;
    gDPPipeSync( NEXT_DISP );
    for ( i = 0; i < 3; i++, kk+=20 ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->decision_alpha[i] );
	gSPVertex( NEXT_DISP, &(this->selectVtx[kk]), 20, 0);
	for ( j = k = 0; j < 5; j++, k+=4 ) {
	    gDPLoadTextureBlock( NEXT_DISP,
				 decision_data[j], G_IM_FMT_IA, G_IM_SIZ_16b,
				 decision_xpd[j], 56, 0,
				 G_TX_NOMIRROR, G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, k+0, k+2, k+3, k+1, 0 );
	}
    }

    /* ファイルＮｏ．*/
#if defined(GATEWAY_VERSION)
	gSPVertex( NEXT_DISP, &(this->selectVtx[kk]), 4, 0);
	/* 拡張プレート */
	gDPSetPrimColor( NEXT_DISP, 0, 0, frame_rgb[0][0], frame_rgb[0][1], frame_rgb[0][2], this->file_alpha[0] );
	gDPLoadTextureBlock( NEXT_DISP,
			     h_file_start_gate_txt,
			     G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
#else
	for ( j = 0; j < 3; j++, kk+=20 ) {
	gSPVertex( NEXT_DISP, &(this->selectVtx[kk]), 20, 0);
	if ( this->f_64dd[j] == this->flag_64dd || !this->plate_alpha[j] ) kkk = 0;
	else                                                               kkk = 1;
	/* 拡張プレート */
	gDPSetPrimColor( NEXT_DISP, 0, 0, frame_rgb[kkk][0], frame_rgb[kkk][1], frame_rgb[kkk][2], this->file_alpha[j] );
	gDPLoadTextureBlock( NEXT_DISP,
			     file_no_data[J_N][j],
			     G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
	/* 名前プレート */
	gDPSetPrimColor( NEXT_DISP, 0, 0, frame_rgb[kkk][0], frame_rgb[kkk][1], frame_rgb[kkk][2], this->plate_alpha[j] );
	gDPLoadTextureBlock( NEXT_DISP,
			     h_name_txt, G_IM_FMT_IA, G_IM_SIZ_16b,
			     108, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 4, 6, 7, 5, 0 );

	if ( this->f_64dd[j] ) {
	    /* ６４ＤＤ */
	    gDPSetPrimColor( NEXT_DISP, 0, 0, frame_rgb[kkk][0], frame_rgb[kkk][1], frame_rgb[kkk][2], this->name_alpha[j] );
////////	    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->name_alpha[j] );
	    gDPLoadTextureBlock( NEXT_DISP,
				 h_file_64dd_txt, G_IM_FMT_IA, G_IM_SIZ_16b,
				 44, 16, 0,
				 G_TX_NOMIRROR, G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD );
	    gSP1Quadrangle( NEXT_DISP, 8, 10, 11, 9, 0 );
	}

	/* コネクタ */
	gDPSetPrimColor( NEXT_DISP, 0, 0, frame_rgb[kkk][0], frame_rgb[kkk][1], frame_rgb[kkk][2], this->connect_alpha[j] );
	gDPLoadTextureBlock( NEXT_DISP,
			     h_con_txt, G_IM_FMT_IA, G_IM_SIZ_8b,
			     24, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 12, 14, 15, 13, 0 );

	if ( this->f_64dd[j] ) {
	    /* ６４ＤＤコネクタ */
	    gSP1Quadrangle( NEXT_DISP, 16, 18, 19, 17, 0 );
	}
    }
#endif	/* GATEWAY_VERSION */



    for ( i = 0; i < 3; i++ ) {
	if ( this->f_64dd[i] == this->flag_64dd || !this->plate_alpha[i] ) kkk = 0;
	else                                                               kkk = 1;
	file_information_draw( thisx, i, kkk );
    }

    /* コピー/消す */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    gSPVertex( NEXT_DISP, &(this->selectVtx[CD_INDEX]), 20, 0);
#if defined(GATEWAY_VERSION)
    gDPPipeSync( NEXT_DISP );
    for ( j = k = 0; j < 2; j++, k+=4 ) {
	kk = this->panel_pt[j];
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->panel_alpha[2+j] );
	gDPLoadTextureBlock( NEXT_DISP,
			     select_no_data[J_N][kk],
			     G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, k+0, k+2, k+3, k+1, 0 );
    }
#else
    for ( j = k = 0; j < 2; j++, k+=4 ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->panel_alpha[j] );
	gDPLoadTextureBlock( NEXT_DISP,
			     select_no_data[J_N][j], G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, k+0, k+2, k+3, k+1, 0 );
    }
    gDPPipeSync( NEXT_DISP );
    for ( j = k = 0; j < 2; j++, k+=4 ) {
	kk = this->panel_pt[j];
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->panel_alpha[2+j] );
	gDPLoadTextureBlock( NEXT_DISP,
			     select_no_data[J_N][kk],
			     G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, k+0, k+2, k+3, k+1, 0 );
    }
#endif	/* GATEWAY_VERSION */

    /* オプション */
    gDPPipeSync( NEXT_DISP );
    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->option_alpha );
# if 0
    if ( !J_N ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_option_txt, G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
    } else {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_option_nes_txt, G_IM_FMT_IA, G_IM_SIZ_16b,
			     64, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
    }
# endif
    gDPLoadTextureBlock( NEXT_DISP,
			 h_option_data[J_N], G_IM_FMT_IA, G_IM_SIZ_16b,
			 64, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
#if defined(GATEWAY_VERSION)
    gSP1Quadrangle( NEXT_DISP, 0, 2, 3, 1, 0 );
#else
    gSP1Quadrangle( NEXT_DISP, 8, 10, 11, 9, 0 );
#endif	/* GATEWAY_VERSION */
    
    /* カーソル */
    if ( (this->mode == File_choose_Select && (this->menu_pos == Menu_Select || (this->menu_pos == Menu_Copy_1 || this->menu_pos == Menu_Copy_5 || this->menu_pos == Menu_Copy_A) || (this->menu_pos == Menu_Delt_1 || this->menu_pos == Menu_Delt_4)))  || (this->mode == File_choose_Decision && this->decision_mode == Decision_Decision) ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT2, G_CC_INT2 );
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->cursor_rgba[0], this->cursor_rgba[1], this->cursor_rgba[2], this->cursor_rgba[3] );
	gDPLoadTextureBlock( NEXT_DISP,
			     h_file_cursor_txt, G_IM_FMT_I, G_IM_SIZ_8b,
			     72, 24, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 12, 14, 15, 13, 0 );
    }
# if 0
    /* ＡＢボタン説明 */
    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 0, this->ab_alpha );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    gDPLoadTextureBlock( NEXT_DISP,
			 h_file_ab_txt, G_IM_FMT_IA, G_IM_SIZ_8b,
			 144, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_DISP, 12, 14, 15, 13, 0 );
# endif
    /* 注意書き */
    if ( this->caution_no >= 0 ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
	gDPSetPrimColor( NEXT_DISP, 0, 0, 255, 255, 255, this->caution_alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	gDPLoadTextureBlock( NEXT_DISP,
			     caution_data[J_N][this->caution_no],
			     G_IM_FMT_IA, G_IM_SIZ_8b,
			     128, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSP1Quadrangle( NEXT_DISP, 16, 18, 19, 17, 0 );
    }

    gDPPipeSync( NEXT_DISP );
    gDPSetCombineMode( NEXT_DISP, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA );
    
    CLOSE_DISP( this->g.graph );
}




/************************************************************************
 *									*
 *	メイン メニューＤＲＡＷ						*
 *									*
 ************************************************************************/
static void
file_choose_menu_draw( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    float	eye_x, eye_y, eye_z;



    OPEN_DISP(this->g.graph);


    /*
     * ＴＩＴＬＥ表示
     */
    gDPPipeSync( NEXT_DISP );


    /* ＶＲーＢＯＸ表示 */
    eye_x = (1000.0f * cos_s(ZREG(11))) - (1000.0f * sin_s(ZREG(11)));
    eye_y = (float)ZREG(13);
    eye_z = (1000.0f * sin_s(ZREG(11))) + (1000.0f * cos_s(ZREG(11)));
    view_setting( this, eye_x, eye_y, eye_z );

    vr_box_draw( &this->vr_box, this->g.graph, 1, this->kankyo.vr_box_scale, eye_x, eye_y, eye_z );
    gDPSetTextureLUT ( NEXT_DISP, G_TT_NONE );
    ZREG(11) += ZREG(10);


    /* 環境設定 */
    Kankyo_vrbox_change( 1, &this->kankyo, &this->vr_box );
/////////    ZCommonSet(zelda_time, ZCommonGet(zelda_time) + TIME_SPEED );
# if 0
    if ( this->menu_pos <= Menu_Fadein1 ) {
	file_choose_title_draw( thisx );
    }
# endif
    /*
     * 選択画面作成
     */
    gDPPipeSync( NEXT_DISP );
    /* モード設定 */
    kaleido_scope_prim( this->g.graph );
    /* ビュー設定 */
    view_setting( this, 0.0f, 0.0f, 64.0f );

    /* フレームＶｔｘセット */
    frame_vtx_set( thisx );
    /* Ｖｔｘセット */
# if 0
#ifndef SHOW_VERSION
    menu_file_choose_vtxset( thisx );
#else
    if ( isZuruMode() ) {
	menu_file_choose_vtxset( thisx );
    } else {
	menu_file_chooseE3_vtxset( thisx );
    }
#endif /* SHOW_VERSION */
# else
    menu_file_choose_vtxset( thisx );
# endif
    /*================= ファイル選択面 =================*/
    if ( !(this->menu_pos == Menu_Nameset || this->menu_pos == Menu_Nameset_Fdin) ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode(NEXT_DISP, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->base_alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	Matrix_translate( 0.0f, 0.0f, -TRANSLATE_E/10.0f, SET_MTX );
	Matrix_scale( (float)SCALE_X/10000.0f, (float)SCALE_Y/10000.0f, (float)SCALE_Z/10000.0f, MULT_MTX );
    if ( this->goto_angle ) {
	Matrix_rotateX( this->goto_angle/100.0f, MULT_MTX );
    }
	gSPMatrix( NEXT_DISP, Matrix_to_Mtx_new(this->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
	gSPVertex(NEXT_DISP, &(this->frameVtx[0]), 32, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl000 );
	gSPVertex(NEXT_DISP, &(this->frameVtx[32]), 32, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl001 );
	gSPVertex(NEXT_DISP, &(this->frameVtx[64]), 16, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl002 );

	gDPPipeSync( NEXT_DISP );
# if 0
#ifndef SHOW_VERSION
	menu_file_choose_display( thisx );
#else
	if ( isZuruMode() ) {
	    menu_file_choose_display( thisx );
	} else {
	    menu_file_chooseE3_display( thisx );
	}
#endif /* SHOW_VERSION */
# else
	menu_file_choose_display( thisx );
# endif
    }

    /*================ 名前登録面 ================*/
////////    if ( this->menu_pos != Menu_Select ) {
    if ( this->menu_pos >= Menu_Go_Nameset && this->menu_pos <= Menu_Go_Select ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode(NEXT_DISP, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->base_alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	Matrix_translate( 0.0f, 0.0f, -TRANSLATE_E/10.0f, SET_MTX );
	Matrix_scale( (float)SCALE_X/10000.0f, (float)SCALE_Y/10000.0f, (float)SCALE_Z/10000.0f, MULT_MTX );
	Matrix_rotateX( (this->goto_angle - 314.0f)/100.0f, MULT_MTX );
	gSPMatrix( NEXT_DISP, Matrix_to_Mtx_new(this->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
	gSPVertex(NEXT_DISP, &(this->frameVtx[0]), 32, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl000 );
	gSPVertex(NEXT_DISP, &(this->frameVtx[32]), 32, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl001 );
	gSPVertex(NEXT_DISP, &(this->frameVtx[64]), 16, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl002 );

	gDPPipeSync( NEXT_DISP );
	menu_nameset_display( thisx );
    }

    /*================ ＯＰＴＩＯＮ ================*/
    if ( this->menu_pos >= Menu_Go_Option && this->menu_pos <= Menu_Option_Select ) {
	gDPPipeSync( NEXT_DISP );
	gDPSetCombineMode(NEXT_DISP, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
	gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->base_alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	Matrix_translate( 0.0f, 0.0f, -TRANSLATE_E/10.0f, SET_MTX );
	Matrix_scale( (float)SCALE_X/10000.0f, (float)SCALE_Y/10000.0f, (float)SCALE_Z/10000.0f, MULT_MTX );
	Matrix_rotateX( (this->goto_angle - 314.0f)/100.0f, MULT_MTX );
	gSPMatrix( NEXT_DISP, Matrix_to_Mtx_new(this->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
	gSPVertex(NEXT_DISP, &(this->frameVtx[0]), 32, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl000 );
	gSPVertex(NEXT_DISP, &(this->frameVtx[32]), 32, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl001 );
	gSPVertex(NEXT_DISP, &(this->frameVtx[64]), 16, 0);
	gSPDisplayList( NEXT_DISP, menu_frame_dl002 );

	gDPPipeSync( NEXT_DISP );
	menu_option_display( thisx );
    }
    
    gDPPipeSync( NEXT_DISP );
    view_setting( this, 0.0f, 0.0f, 64.0f );

    CLOSE_DISP(this->g.graph);
}
















/*===============================================================================
  =================================  選択決定   =================================
  ===============================================================================*/
/*===============================================================
  =	   選択決定イニシャル ＆ 移動				=
 ===============================================================*/
static void
file_decision_init( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Sram	*sram = (Sram *)&this->sram;

    short	i;


    for ( i = 0; i < 3; i++ ) {
	if ( i != this->no ) {
	    this->file_alpha[i] -= B_A_CT;
	    this->panel_alpha[0] = 
		this->panel_alpha[1] = 
		this->option_alpha = this->file_alpha[i];
	    if ( REGCK_ALL( i ) ) {
		this->name_alpha[i] =
		    this->plate_alpha[i] = this->file_alpha[i];
		this->connect_alpha[i] -= F_A_CT;
	    }
	}
    }

    this->frame_title_alpha[0] -= F_A_CT;
    this->frame_title_alpha[1] += F_A_CT;

    if ( !(--this->cpdl_mct) ) {
	this->cpdl_mct = FRAME_CT;
	this->decision_mode++;
	this->yes_no = 0;
    }
}
/*===============================================================
  =	   選択決定移動						=
 ===============================================================*/
static void
file_decision_move( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    static short	move_ypd[] = {
	0, 16, 32,
    };
    short	k;

    
    k = (ABS(this->cpdl_yp[this->no] - move_ypd[this->no])) / this->cpdl_mct;
    this->cpdl_yp[this->no] += k;
    if ( !(--this->cpdl_mct) || this->cpdl_yp[this->no] == move_ypd[this->no] ) {
	this->cpdl_yp[3] =
	    this->cpdl_yp[4] = -(16+8);
	this->cpdl_mct = FRAME_CT;
	this->decision_mode++;
    }
}
/*===============================================================
  =	   選択決定フェードイン					=
 ===============================================================*/
static void
file_decision_fdin( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    this->decision_alpha[this->no] += B_A_CT;
    this->plate_alpha[this->no] -= (B_A_CT*2);		/* 選択プレート消去 */
    if ( this->plate_alpha[this->no] <= 0 ) this->plate_alpha[this->no] = 0;
    if ( !(--this->cpdl_mct) ) {
	this->decision_alpha[this->no] = BASE_ALPHA;
	this->cpdl_mct = FRAME_CT;
	this->decision_mode++;
    }
    this->panel_alpha[2] = 
	this->panel_alpha[3] = this->decision_alpha[this->no];
}
/*===============================================================
  =	   選択決定						=
 ===============================================================*/
static void
file_decision_decision( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    pad_t	*pad = &this->g.pads[0];


///////    no = this->no << 2;
///////    no |= this->decision_no;
///////    z_common_data.file_no = no;
    if ( Pad_on_trigger(START_BUTTON) || Pad_on_trigger(A_BUTTON) ) {
	if ( !this->yes_no ) {
	    RUMBLE_ENTRY2_TYPE_B( 300.0f );
	    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	    this->decision_mode = Decision_GotoFdout;
	    Na_StopAllSound( 15 );
	} else {
	    Na_StartSystemSe(NA_SE_SY_FSEL_CANCEL);
	    this->decision_mode++;
	}
    } else if ( Pad_on_trigger(B_BUTTON) ) {
	Na_StartSystemSe(NA_SE_SY_FSEL_CANCEL);
	this->decision_mode++;
    } else {
	if ( ABS(this->wkey_y) >= KEY_ANGLE_3D ) {
	    Na_StartSystemSe(NA_SE_SY_FSEL_CURSOR);
	    this->yes_no ^= 1;
	}
    }
}
/*===============================================================
  =	   選択決定フェードアウト				=
 ===============================================================*/
static void
file_decision_fdout( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    this->decision_alpha[this->no] -= B_A_CT;
    this->plate_alpha[this->no] += B_A_CT;
    if ( !(--this->cpdl_mct) ) {
	this->cpdl_yp[3] =
	    this->cpdl_yp[4] = 0;
	this->plate_alpha[this->no] = BASE_ALPHA;
	this->decision_alpha[this->no] = 0;
	this->title_no1 = 0;
	this->cpdl_mct = FRAME_CT;
	this->decision_mode++;
    }
    this->panel_alpha[2] =
	this->panel_alpha[3] = this->decision_alpha[this->no];
}
/*===============================================================
  =	   選択決定バック ＆ リターン				=
 ===============================================================*/
static void
file_decision_back( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Sram	*sram = (Sram *)&this->sram;

    short	i, k;


    k = (ABS(this->cpdl_yp[this->no])) / this->cpdl_mct;
    this->cpdl_yp[this->no] -= k;
    if ( this->cpdl_yp[this->no] <= 0 ) {
	this->cpdl_yp[this->no] = 0;
    }

    for ( i = 0; i < 3; i++ ) {
	if ( i != this->no ) {
	    this->file_alpha[i] += B_A_CT;
	    if ( this->file_alpha[i] >= BASE_ALPHA ) {
		this->file_alpha[i] = BASE_ALPHA;
	    }
	    this->panel_alpha[0] = 
		this->panel_alpha[1] =
		this->option_alpha = this->file_alpha[i];
	    if ( REGCK_ALL( i ) ) {
		this->plate_alpha[i] =
		    this->name_alpha[i] = this->file_alpha[i];
		this->connect_alpha[i] += F_A_CT;
	    }
	}
    }
    this->frame_title_alpha[0] -= F_A_CT;
    this->frame_title_alpha[1] += F_A_CT;
    if ( !(--this->cpdl_mct) ) {
	this->frame_title_alpha[0] = FRAME_ALPHA;
	this->frame_title_alpha[1] = 0;
	this->title_no0 = this->title_no1;
	this->cpdl_mct = FRAME_CT;
	this->mode = File_choose_Select;
	this->menu_pos = Menu_Select;
	this->menu_pos_next = Menu_Select;
	this->decision_mode = 0;
    }
}
/*===============================================================
  =	   選択決定ＧｏｔｏＧＡＭＥフェードアウト		=
 ===============================================================*/
static void
file_decision_gotofdout( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    fill_alpha += VREG(10);
    if ( fill_alpha > 254 ) {
	fill_alpha = 255;
	this->decision_mode++;
    }
}
/*===============================================================
  =	   選択決定ＧｏｔｏＧＡＭＥ				=
 ===============================================================*/
static void
file_decision_gotogame( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    unshort	zzz;

#if defined(GATEWAY_VERSION)
    save_initialize_GATEWAY_SET( thisx );
    ZCommonSet( game_info.mode, GAME_INFO_GAME );
    game_set_next_game_name(&this->g, play);
    this->g._doing = 0;
#else
#if !defined(ROM_F)
//    if ( this->flag_64dd ) n64dd_LoadDiskOverlay();
    /* ゲーム */
    if ( !this->no ) {
	Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
/*
  [22:00:35]☆★☆★☆★ 早川 賢三 からのお知らせです ☆★☆★☆★
  64dd のデータでゲームを始める際に一回だけ
  #include "z_n64dd_keep.h"
  n64dd_LoadDiskOverlay()
  を呼んでください
  ＞副島さん
  */
	ZCommonSet( file_no, this->no );
	/* ゲーム開始ＳＲＡＭ ＬＯＡＤ＆ＣＨＥＣＫ */
	sram_load_check( &this->sram );
	ZCommonSet( game_info.mode, GAME_INFO_GAME );
	game_set_next_game_name(&this->g, select);
	this->g._doing = 0;
    } else {
	Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
	ZCommonSet( file_no, this->no );
	/* ゲーム開始ＳＲＡＭ ＬＯＡＤ＆ＣＨＥＣＫ */
	sram_load_check( &this->sram );
	ZCommonSet( game_info.mode, GAME_INFO_GAME );
	game_set_next_game_name(&this->g, play);
	this->g._doing = 0;
    }
# else
    Na_StartSystemSe(NA_SE_SY_FSEL_DECIDE_L);
    ZCommonSet( file_no, this->no );
    /* ゲーム開始ＳＲＡＭ ＬＯＡＤ＆ＣＨＥＣＫ */
//    if ( this->flag_64dd ) n64dd_LoadDiskOverlay();
    sram_load_check( &this->sram );
    ZCommonSet( game_info.mode, GAME_INFO_GAME );
    game_set_next_game_name(&this->g, play);
    this->g._doing = 0;
# endif	/* ROM_F */
# endif	/* GATEWAY_VERSION */
    /* ゲーム前ＣＬＥＡＲ─ＲＡＭ */
    ZCommonSet(game_info.restart_flag, 0);
    ZCommonSet(game_info.restart_data[0].scene, -1);
    ZCommonSet(old_bgm, 255);
    ZCommonSet(old_env, 255);
    ZCommonSet(game_info.name_display, ON);
    ZCommonSet(game_info.dog_flag, 0);
    ZCommonSet( event_fg, Event_MD0 );
    ZCommonSet( total_event_fg, TEvent_MD0 );
    ZCommonSet(event_inf[0], 0);
    ZCommonSet(event_inf[1], 0);
    ZCommonSet(event_inf[2], 0);
    ZCommonSet(event_inf[3], 0);
    ZCommonSet(last_time_type, 50);
    ZCommonSet(game_info.shield_magic_timer, 0);
    ZCommonSet(life_mode, 0);
    ZCommonSet(magic_flag, 0);
    ZCommonSet(keep_magic_flag, 0);
    /*[ファイル選択時 に お願いしたい物]*/
    ZCommonSet( NottoriBgm,   0 );
    ZCommonSet( kankyo_time,  0 );
    ZCommonSet( next_wipe,    0xff );
    ZCommonSet( next_daytime, 0xffef );
    ZCommonSet( doukidemo,    0 );
    ZCommonSet( Kenjya_no,    0 );
    ZCommonSet( next_zelda_time, 0xffff );
    ZCommonSet( game_info.next_walk, 0 );

    Z_BTN_ITEM(0) = 
	Z_BTN_ITEM(1) = 
	Z_BTN_ITEM(2) = 
	Z_BTN_ITEM(3) = 
	Z_BTN_ITEM(4) = 0;
    Z_CK_FG =
	Z_ALPHA_TYPE =
	Z_PREV_ALPHA_TYPE =
	Z_ALPHA_COUNT =
	Z_MAGIC_NOW_MAX = 0;
    Z_MAGIC_NOW_NOW = MAGIC_NOW;
    MAGIC_MAX =
	MAGIC_NOW = 0;
    COLOR_GREEN();
    PRINTF("Z_MAGIC_NOW_NOW=%d  MAGIC_NOW=%d\n",Z_MAGIC_NOW_NOW, MAGIC_NOW );
    COLOR_NORMAL();
    /* ナビーの会話タイマー */
    NAVI_TIMER = 0;
    /* プレイヤーＢボタン【剣】チェック */
    if ( !(Register_Item(0) == H_sword_0 ||		/* ナイフ */
	   Register_Item(0) == H_sword_1 ||		/* マスターソード */
	   Register_Item(0) == H_sword_2 ||		/* 巨人のナイフ */
	   Register_Item(0) == H_sword_3) ) { 		/* 折れた巨人のナイフ */
	Register_Item(0) = 0xff;
	zzz = Equip_Item & bit_check_data[E_Sword];
	Equip_Item &= bit_and_data[E_Sword];
	EorEquip_Register( E_Sword, check_bit[zzz-1] );
    }
    
#if defined(USE_N64DD)
    if (n64dd_isInitialized()) {
	n64dd_SetDiskVersion(this->f_64dd[ZCommonGet( file_no )]);
    }
#endif /* defined(USE_N64DD) */
}    

/************************************************************************
 *	選択決定							*
 ************************************************************************/
static void
(*file_decision_play[Decision_Point])( Game *thisx ) =
{
    file_decision_init,		/* ０：選択決定イニシャル */
    file_decision_move,		/* １：選択決定移動 */
    file_decision_fdin,		/* ２：選択決定フェードイン */
    file_decision_decision,	/* ３：選択決定 */
    file_decision_fdout,	/* ４：選択決定フェードアウト */
    file_decision_back,		/* ５：選択決定バック ＆ リターン */
    file_decision_gotofdout,	/* ６：ＧＯＴＯＧＡＭＥ フェードアウト */
    file_decision_gotogame,	/* ７：ＧＯＴＯ ＧＡＭＥ */
};


/************************************************************************
 *									*
 *	選択決定ＭＯＶＥ						*
 *									*
 ************************************************************************/
static void
file_choose_decision_move( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;


    /* ＰＬＡＹ */
# if 0
#ifndef SHOW_VERSION
    file_decision_play[this->decision_mode]( thisx );
#else
    if ( isZuruMode() ) {
	file_decision_play[this->decision_mode]( thisx );
    } else {
	file_decision_playE3[this->decision_mode]( thisx );
    }
#endif /* SHOW_VERSION */
# else
    file_decision_play[this->decision_mode]( thisx );
# endif
}





/************************************************************************
 *									*
 *	選択決定ＤＲＡＷ						*
 *									*
 ************************************************************************/
static void
file_choose_decision_draw( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    float	eye_x, eye_y, eye_z;



    OPEN_DISP(this->g.graph);


    /*
     * ＴＩＴＬＥ表示
     */
    gDPPipeSync( NEXT_DISP );


    /* ＶＲーＢＯＸ表示 */
    eye_x = (1000.0f * cos_s(ZREG(11))) - (1000.0f * sin_s(ZREG(11)));
    eye_y = (float)ZREG(13);
    eye_z = (1000.0f * sin_s(ZREG(11))) + (1000.0f * cos_s(ZREG(11)));
    view_setting( this, eye_x, eye_y, eye_z );

    vr_box_draw( &this->vr_box, this->g.graph, 1, this->kankyo.vr_box_scale, eye_x, eye_y, eye_z );
    gDPSetTextureLUT ( NEXT_DISP, G_TT_NONE );
    ZREG(11) += ZREG(10);


    /* 環境設定 */
    Kankyo_vrbox_change( 1, &this->kankyo, &this->vr_box );
/////////    ZCommonSet(zelda_time, ZCommonGet(zelda_time) + TIME_SPEED );

    /*
     * 選択画面作成
     */
    gDPPipeSync( NEXT_DISP );
    /* モード設定 */
    kaleido_scope_prim( this->g.graph );
    /* ビュー設定 */
    view_setting( this, 0.0f, 0.0f, 64.0f );

    /* フレームＶｔｘセット */
    frame_vtx_set( thisx );
    /* Ｖｔｘセット */
# if 0
#ifndef SHOW_VERSION
    menu_file_choose_vtxset( thisx );
#else
    if ( isZuruMode() ) {
	menu_file_choose_vtxset( thisx );
    } else {
	menu_file_chooseE3_vtxset( thisx );
    }
#endif /* SHOW_VERSION */
# else
    menu_file_choose_vtxset( thisx );
# endif

    /*================= ファイル選択面 =================*/
    gDPSetCombineMode(NEXT_DISP, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor( NEXT_DISP, 0, 0, this->frame_rgb[0], this->frame_rgb[1], this->frame_rgb[2], this->base_alpha );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    Matrix_translate( 0.0f, 0.0f, -TRANSLATE_E/10.0f, SET_MTX );
    Matrix_scale( (float)SCALE_X/10000.0f, (float)SCALE_Y/10000.0f, (float)SCALE_Z/10000.0f, MULT_MTX );
    Matrix_rotateX( this->goto_angle/100.0f, MULT_MTX );
    gSPMatrix( NEXT_DISP, Matrix_to_Mtx_new(this->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
    gSPVertex(NEXT_DISP, &(this->frameVtx[0]), 32, 0);
    gSPDisplayList( NEXT_DISP, menu_frame_dl000 );
    gSPVertex(NEXT_DISP, &(this->frameVtx[32]), 32, 0);
    gSPDisplayList( NEXT_DISP, menu_frame_dl001 );
    gSPVertex(NEXT_DISP, &(this->frameVtx[64]), 16, 0);
    gSPDisplayList( NEXT_DISP, menu_frame_dl002 );

# if 0
#ifndef SHOW_VERSION
    menu_file_choose_display( thisx );
#else
    if ( isZuruMode() ) {
	menu_file_choose_display( thisx );
    } else {
	menu_file_chooseE3_display( thisx );
    }
#endif /* SHOW_VERSION */
# else
    menu_file_choose_display( thisx );
# endif
    gDPPipeSync( NEXT_DISP );
    view_setting( this, 0.0f, 0.0f, 64.0f );

    CLOSE_DISP(this->g.graph);
}














/*===============================================================================
  =================================  ＭＡＩＮ   =================================
  ===============================================================================*/
/*===============================================================
  =	   ＤＲＡＷ処理						=
 ===============================================================*/
extern void
(*file_choose_draw[File_choose_Point])( Game *thisx ) =
{
    file_choose_title_draw,	/* タイトル表示 */
    file_choose_menu_draw,	/* メイン メニュー */
    file_choose_decision_draw,	/* 選択決定 */
};

/*===============================================================
  =	   ＭＯＶＥ処理						=
 ===============================================================*/
extern void
(*file_choose_move[File_choose_Point])( Game *thisx ) =
{
    file_choose_title_move,	/* タイトル表示 */
    file_choose_menu_move,	/* メイン メニュー */
    file_choose_decision_move,	/* 選択決定 */
};



/************************************************************************
 *	ＦＩＬＥ ＣＨＯＯＳＥ メイン処理				*
 ************************************************************************/
static void
file_choose_main( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    pad_t	*pad = &this->g.pads[0];

    static unshort *h_file_ab_data[] = {
	h_file_ab_txt, h_file_ab_nes_txt,
    };
    
    
    OPEN_DISP( this->g.graph );


#if defined(USE_N64DD)
    /*  ６４ＤＤメディアチェック */
    if ( n64dd_isInitialized() && n64dd_isInMedium() ) this->flag_64dd = 1;
    else                                               this->flag_64dd = 0;
////////    PRINTF("６４ＤＤメディア（%d） n64dd_isInitialized&&n64dd_isInMedium=%d\n",this->flag_64dd, n64dd_isInitialized() && n64dd_isInMedium() );
#else
    this->flag_64dd = 0;
#endif /* defined(USE_N64DD) */


    /*
     * セグメントアドレス設定
     */
    gSPSegment( NEXT_DISP, 0, 0x0 );	/* Physical address segment */
    gSPSegment( NEXT_DISP, STATIC_SEGMENT,  this->staticSegment );
    gSPSegment( NEXT_DISP, DYNAMIC_SEGMENT, this->parameterSegment );

    /*
     * ディスプレイリスト初期設定
     */
    DisplayList_initialize( this->g.graph, 0, 0, 0 );


    /*
     * ＭＯＶＥ処理
     */
    this->wkey_x = (short)Pad_stick_x();
    this->wkey_y = (short)Pad_stick_y();
    /* 入力ＫＥＹチェック */
    if ( this->wkey_x < -KEY_ANGLE_3D ) {
	if (  this->old_key_x == -1 ) {
	    if ( --this->key_wait_x < 0 ) this->key_wait_x = XREG_6;
	    else this->wkey_x = 0;
	} else {
	    this->key_wait_x = XREG_8;
	    this->old_key_x  = -1;
	}
    } else if ( this->wkey_x > KEY_ANGLE_3D ) {
	if (  this->old_key_x == 1 ) {
	    if ( --this->key_wait_x < 0 ) this->key_wait_x = XREG_6;
	    else this->wkey_x = 0;
	} else {
	    this->key_wait_x = XREG_8;
	    this->old_key_x  = 1;
	}
    } else this->old_key_x = 0;
    if ( this->wkey_y < -KEY_ANGLE_3D ) {
	if (  this->old_key_y == -1 ) {
	    if ( --this->key_wait_y < 0 ) this->key_wait_y = XREG_6;
	    else this->wkey_y = 0;
	} else {
	    this->key_wait_y = XREG_8;
	    this->old_key_y  = -1;
	}
    } else if ( this->wkey_y > KEY_ANGLE_3D ) {
	if (  this->old_key_y == 1 ) {
	    if ( --this->key_wait_y < 0 ) this->key_wait_y = XREG_6;
	    else this->wkey_y = 0;
	} else {
	    this->key_wait_y = XREG_8;
	    this->old_key_y  = 1;
	}
    } else this->old_key_y = 0;
    this->caution_alpha = 0;

# if 0
    /* フレームＰＲＩＭカラー計算 */
    frame_color_change( thisx );
# endif
    /* カーソルＰＲＩＭカラー計算 */
    cursor_color_change( thisx );

    /* ＭＯＶＥ処理 */
    file_choose_move[this->mode]( thisx );

    /*
     * ＤＲＡＷ処理
     */
    file_choose_draw[this->mode]( thisx );

    /* ＡＢボタン説明 */
#if defined(GATEWAY_VERSION)
    rectangle_a_prim( this->g.graph );
    gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 100, 255, 255, this->ab_alpha );
    gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
    if ( !(this->menu_pos >= Menu_Go_Option && this->menu_pos <= Menu_Option_Select) ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_file_ab_1_gate_txt, G_IM_FMT_IA, G_IM_SIZ_8b,
			     144, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_DISP,
			     (90 * 0x4), (204 * 0x4),
			     ((90 + 144) * 0x4), ((204 + 16) * 0x4),
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
    } else if ( this->menu_pos == Menu_Option ) {
	gDPLoadTextureBlock( NEXT_DISP,
			     h_file_ab_2_gate_txt, G_IM_FMT_IA, G_IM_SIZ_8b,
			     144, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_DISP,
			     (90 * 0x4), (204 * 0x4),
			     ((90 + 144) * 0x4), ((204 + 16) * 0x4),
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
    }
#else
    if ( !(this->menu_pos >= Menu_Go_Option && this->menu_pos <= Menu_Option_Select) ) {
	rectangle_a_prim( this->g.graph );
	gDPSetCombineMode( NEXT_DISP, G_CC_INT9, G_CC_INT9 );
	gDPSetPrimColor( NEXT_DISP, 0, 0, 100, 255, 255, this->ab_alpha );
	gDPSetEnvColor( NEXT_DISP, 0, 0, 0, 0 );
	gDPLoadTextureBlock( NEXT_DISP,
			     h_file_ab_data[J_N], G_IM_FMT_IA, G_IM_SIZ_8b,
			     144, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK,
			     G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_DISP,
			     (90 * 0x4), (204 * 0x4),
			     ((90 + 144) * 0x4), ((204 + 16) * 0x4),
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
    }
#endif	/* GATEWAY_VERSION */

    gDPPipeSync( NEXT_DISP );
    gSPDisplayList( NEXT_DISP, fbdemo_fade_gfx_init );
    gDPSetPrimColor( NEXT_DISP, 0, 0, 0, 0, 0, fill_alpha );
    gDPFillRectangle( NEXT_DISP, 0, 0, ScreenWidth-1, ScreenHeight-1 );


    CLOSE_DISP( this->g.graph );
}




/*=======================================================================
  =	変数初期化							=
  =======================================================================*/
static void
common_initialize( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kankyo		*kankyo = (Kankyo *)&this->kankyo;


    /*
     * ＳＲＡＭクラス コンストラクト 
     */
    sram_title_ct( thisx, &this->sram );
    /* ＳＲＡＭイニシャライズチェック */
//    sram_initialize( thisx, &this->sram );



    
    ZREG(7) = 32;		// エフェクト表示Ｘ位置
    ZREG(8) = 22;		//               Ｙ位置
    ZREG(9) = 20;		/* 名前登録 モ-フィングスピード */
    
    ZREG(10) = -10;		// ＶＲボックス回転速度
    ZREG(11) = 0;		/* ＶＲボックス回転角Ｙ */
    ZREG(12) = 1000;		/* ＶＲボックス回転角Ｙ */
    ZREG(13) = -700;		/* ＶＲヴボックス回転角Ｙ */

    ZREG(14) = 164;		/* タイトルＸ座標 */
    ZREG(15) = 104;		/*         Ｙ座標 */
    ZREG(16) = 160;		/* タイトルＸ座標 */
    ZREG(17) = 100;		/*         Ｙ座標 */
    ZREG(18) = 162;		/* タイトルＸ座標 */
    ZREG(19) = 152;		/*         Ｙ座標 */
    ZREG(20) = 214;		/*         Ｙ座標 */



    XREG(13) = 580;
    XREG(14) = 400;

    XREG(35) = 20;		/* カーソル点滅カウンター */
    XREG(36) = 20;		/*  カーソル点滅カウンター ０ */
    XREG(37) = 20;		/*                         １ */


    XREG(43) = 8;		// コース選択Ｘ位置
    XREG(44) = -78;		//           Ｙ位置
    
    XREG(45) = 0;		// コース１ Ａｌｐｈａ
    XREG(46) = 0;		// コース２ Ａｌｐｈａ
    XREG(47) = 0;		// コース３ Ａｌｐｈａ
    XREG(48) = 0;		// コース４ Ａｌｐｈａ

    XREG(49) = 3;		// コース選択移動スピード
    XREG(50) = 8;		// フェードアウト スピード
    XREG(51) = 8;		// 名前プレート（拡張）フェードインスピード
    XREG(52) = 10;		// 名前プレートフェードアウトスピード

    XREG(73) = 0;
# if 0    
    XREG(84) = 255;		// Ｆｒａｍｅ ＰＲＩＭ─Ｒ（朝）
    XREG(85) = 150;		//                        （昼）
    XREG(86) = 200;		//                        （夕）
    XREG(87) = 100;		//                        （夜）
    XREG(88) = 215;		// Ｆｒａｍｅ ＰＲＩＭ─Ｇ（朝）
    XREG(89) = 150;		//                        （昼）
    XREG(90) = 150;		//                        （夕）
    XREG(91) = 150;		//                        （夜）
    XREG(92) = 225;		// Ｆｒａｍｅ ＰＲＩＭ─Ｂ（朝）
    XREG(93) = 255;		//                        （昼）
    XREG(94) = 100;		//                        （夕）
    XREG(95) = 255;		//                        （夜）
# endif
    
    VREG(0) = 14;		// タイトルフェードアウト速度
    VREG(1) = 5;		// ファイルプレートフェードイン速度
    VREG(2) = 4;		// ファイルフレームフェードイン速度
    VREG(4) =  1;		// エフェクトフェードイン速度
    VREG(5) =  6;		// タイトルフェードイン速度
    VREG(6) =  2;		// サブタイトルフェードイン速度
    VREG(7) =  6;		// "１９９７Ｎｉｎｔｅｎｄｏ" フェードイン速度
    VREG(8) =  80;		// ＦＩＬＬフェードイン後のＷＡＩＴ
    fill_alpha =  255;		// ＦＩＬＬアルファ値
    VREG(10) = 10;		// ＦＩＬＬフェードイン/フェードアウト速度
    VREG(11) = 30;		// Na_StopBgm
    VREG(12) = -100;		// ＡＢボタン説明表示Ｘ
    VREG(13) = -85;		//                   Ｙ
    VREG(14) = 4;


    VREG(16) = 25;		/* 名前登録回転速度 */

    VREG(17) = 1;
    VREG(18) = 1;
    
    VREG(20) = 92;
    VREG(21) = 171;
    VREG(22) = 11;
    VREG(23) = 10;
    VREG(24) = 26;

    VREG(25) = 2;
    VREG(26) = 1;

    VREG(27) = 0;
    VREG(28) = 0;
    VREG(29) = 160;

    VREG(30) = 64;
    VREG(31) = 154;
    VREG(32) = 152;
    VREG(33) = 106;


    WREG(38) = 16;
    WREG(39) = 9;
    WREG(40) = 10;
    WREG(41) = 14;
    WREG(42) = 11;
    WREG(43) = 12;
    
    
    this->mode	= File_choose_Title;
    this->no =
	this->decision_mode =
	this->decision_no =
	this->copy_no =
	this->yes_no = 0;
    this->panel_pt[0] = 2;
    this->panel_pt[1] = 3;


    this->title_no0 = 0;
    this->title_no1 = 1;
    
# if 0
    this->alpha_mode = Title_Fillin;	/* アルファ モード */
    this->effect_alpha =		/* エフェクト アルファ値 */
    this->title_alpha =			/* タイトル アルファ値 */
    this->sub_alpha =			/* 日本語タイトル アルファ値 */
    this->logo_alpha = 0;		/* "１９９７Ｎｉｎｔｅｎｄｏ" アルファ値 */
    this->bgm_ct = 0;			/* ＢＧＭカウンター */
# endif
    this->cursor_pt = 1;
    this->cursor_ct = 12;
    this->cursor_rgba[0] = 155;
    this->cursor_rgba[1] = 255;
    this->cursor_rgba[2] = 255;
    this->cursor_rgba[3] = 70;

    this->menu_pos = Menu_Fadein;
    this->goto_angle = 0.0f;
    this->old_key_x = this->key_wait_x = 0;
    this->old_key_y = this->key_wait_y = 0;
    this->name_xpos =
	this->name_ypos =
	this->mjp = 0;
    this->name_contents = 99;

    this->frame_rgb[0] = 100;		// Ｆｒａｍｅ ＰＲＩＭ─Ｒ
    this->frame_rgb[1] = 150;		//                      Ｇ
    this->frame_rgb[2] = 255;		//                      Ｂ
    this->base_alpha  = 		//                      Ａ
	this->frame_title_alpha[0] =	// 選択面タイトルアルファ値
	this->frame_title_alpha[1] =	// 選択面タイトルアルファ値
	this->file_alpha[0] = 		// ファイル１ Ａｌｐｈａ
	this->file_alpha[1] = 		// ファイル２ Ａｌｐｈａ
	this->file_alpha[2] = 		// ファイル３ Ａｌｐｈａ
	this->plate_alpha[0] = 		// 名前プレート１ Ａｌｐｈａ
	this->plate_alpha[1] = 		// 名前プレート２ Ａｌｐｈａ
	this->plate_alpha[2] = 		// 名前プレート３ Ａｌｐｈａ
	this->name_alpha[0] =		// 名前１ Ａｌｐｈａ
	this->name_alpha[1] =		// 名前２ Ａｌｐｈａ
	this->name_alpha[2] =		// 名前３ Ａｌｐｈａ
	this->connect_alpha[0] =	// コネクタ─１ Ａｌｐｈａ
	this->connect_alpha[1] =	// コネクタ─２ Ａｌｐｈａ
	this->connect_alpha[2] =	// コネクタ─３ Ａｌｐｈａ
	this->decision_alpha[0] =	// 選択決定パネルアルファ値
	this->decision_alpha[1] =	// 選択決定パネルアルファ値
	this->decision_alpha[2] =	// 選択決定パネルアルファ値
	this->panel_alpha[0] = 		// コピーパネルアルファ値
	this->panel_alpha[1] = 		// 消すパネルアルファ値
	this->panel_alpha[2] = 		// 消すパネルアルファ値
	this->panel_alpha[3] = 		// 消すパネルアルファ値
	this->option_alpha =		// オプションアルファ値
	this->name_plate_alpha =	// 名前登録パネルアルファ値
	this->ab_alpha =		// ＡＢボタン説明パネルアルファ値
	this->caution_alpha =  0;	// 注意書きパネルアルファ値

    this->scroll_xp = -94 + 100;	/*                   Ｘ位置 */

    this->cpdl_mct = FRAME_CT;
    this->caution_no = -1;
    this->caution_pt =
	this->cpdl_yp[0] = 
	this->cpdl_yp[1] = 
	this->cpdl_yp[2] = 
	this->cpdl_yp[3] = 
	this->cpdl_yp[4] =
	this->cpdl_yp[5] =
	this->decision_ypd[0] =
	this->decision_ypd[1] =
	this->decision_ypd[2] = 0;
# if 0
    /** Ｅ３メニュー用 **/
    this->sub_menu_alpha[0] = 0;
    this->sub_menu_alpha[1] = 0;
    this->sub_menu_alpha[2] = 0;
    this->sub_menu_alpha[3] = 0;
    this->sub_menu_alpha[4] = 0;
    this->sub_no = 0;
    this->sub_menu_cnt = 4;
# endif
# if 1
    this->sub_menu_alpha[0] = 0;
    this->sub_menu_alpha[1] = 3;
    this->sub_menu_alpha[2] = 6;
    this->sub_menu_alpha[3] = 8;
    this->sub_menu_alpha[4] = 10;
# endif

    shrink_window_setval( 0 );
    /*
     * ＶＲ＿ＢＯＸクラス コンストラクト 
     */
    ZCommonSet( kankyo_time, 0 );
    ZCommonSet( zelda_time, 0 );
    vr_box_ct( thisx, &this->vr_box, 1 );

    /* 環境初期化 */
    TIME_SPEED = 10;
    kankyo->mode = 0;			/* イベント切り替え指令	(vr_box)	*/
    kankyo->patchg_time	= 0;		/* 切り替え時間タイマー			*/
    kankyo->mode2 = 0;			/* イベント切り替え指令	(カラー)	*/
    kankyo->patchg_time2 = 0;		/* 切り替え時間タイマー			*/
    kankyo->read_flag = OFF;		/* vr_box転送監視フラグ			*/
    kankyo->vrbox_tenso_0 = 99;		/* 現在VR_BOX0に転送ずみのvr_box番号	*/
    kankyo->vrbox_tenso_1 = 99;		/* 現在VR_BOX1に転送ずみのvr_box番号	*/
    kankyo->all_fade_wk	= 0.0f;		/* レンズフレアの白フェード用ワーク	*/
    kankyo->naiseki_wk = 0.0f;		/* 					*/
    kankyo->kcolor_pat = 0;
    kankyo->kcolor_eve_pat= 0;
    kankyo->polcolor = 0;
    kankyo->vr_box_pat = 2;
    kankyo->vr_box_dsp = 0;
    kankyo->vr_box_scale = 0;

    /* 環境設定 */
    Kankyo_vrbox_change( 1, &this->kankyo, &this->vr_box );


    Z_BTN_ITEM(0) = 
	Z_BTN_ITEM(1) = 
	Z_BTN_ITEM(2) = 
	Z_BTN_ITEM(3) = 
	Z_BTN_ITEM(4) = 0;


    this->f_64dd[0] =
	this->f_64dd[1] =
	this->f_64dd[2] =
	this->heart_status[0] =
	this->heart_status[1] =
	this->heart_status[2] = 0;
}





/************************************************************************
 *	ＦＩＬＥ ＣＨＯＯＳＥ画面後始末					*
 * 	・メンバ変数の後始末						*
 ************************************************************************/
extern void
file_choose_cleanup( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

#define view_cleanup(view) ((void)(view))
    view_cleanup(&this->view);
}



/************************************************************************
 *	ＦＩＬＥ ＣＨＯＯＳＥ初期化					*
 * 	・exec, cleanupメンバの設定					*
 * 	・他のメンバ変数の初期化					*
 * 	・ＲＯＭデータのＤＭＡ転送（必要なら）				*
 * 	（注意）描画やキー入力はできません				*
 ************************************************************************/
extern void
file_choose_init( Game *thisx )
{
    Game_file_choose	*this = (Game_file_choose *)thisx;

    Kanfont	*kanfont = (Kanfont *)&this->kanfont;

    u32		size;

    
#ifdef USE_N64DD
    if (n64dd_isInitialized()) {
	PRINTF(ESC_CYAN "ゼルダディスクは入ってる？\n" ESC_NORMAL);
	n64dd_MediumCheck();
    }
#endif /* USE_N64DD */
    
    /*
     * 初期化
     */
    SetGameFrame(1);	/* ゲームフレーム＝１ */
    /*
     * スタティックデータの転送
     */
#if defined(GATEWAY_VERSION)
    size = (u32)_title_staticSegmentRomEnd - (u32)_title_staticSegmentRomStart;
    PRINTF("SIZE=%x\n",size);
    this->staticSegment = (char *)game_alloc(&this->g, (size_t)size);
    assert(this->staticSegment != NULL);
    dmacopy_fg(this->staticSegment, (u32)_title_staticSegmentRomStart, size);

    /* ＧＡＴＥＷＡＹセグメント */
    size = (u32)_gateway_title_staticSegmentRomEnd - (u32)_gateway_title_staticSegmentRomStart;
    this->parameterSegment = (char *)game_alloc( &this->g, (size_t)size );
    assert(this->parameterSegment != NULL);
    dmacopy_fg(this->parameterSegment, (u32)_gateway_title_staticSegmentRomStart, size );

    ZREG(4) = 0;
    ZREG(5) = 35;
#else
    size = (u32)_title_staticSegmentRomEnd - (u32)_title_staticSegmentRomStart;
    PRINTF("SIZE=%x\n",size);
    this->staticSegment = (char *)game_alloc(&this->g, (size_t)size);
    assert(this->staticSegment != NULL);
    dmacopy_fg(this->staticSegment, (u32)_title_staticSegmentRomStart, size);

    /* 常駐ＰＡＲＡＭＥＴＥＲセグメント */
    size = (u32)_parameter_staticSegmentRomEnd - (u32)_parameter_staticSegmentRomStart;
    this->parameterSegment = (char *)game_alloc( &this->g, (size_t)size );
    assert(this->parameterSegment != NULL);
    dmacopy_fg(this->parameterSegment, (u32)_parameter_staticSegmentRomStart, size );
#endif	/* GATEWAY_VERSION */

    /*
     * 行列計算クラス宣言
     */
    new_Matrix( thisx );
    
    /*
     * ビュワー初期設定
     */ 
    view_init( &this->view, this->g.graph );

    /*
     * Game必須変数初期化
     */
    this->g.exec	= file_choose_main;
    this->g.cleanup	= file_choose_cleanup;

    /* 変数初期化 */
    common_initialize( thisx );



# if 0
    /*
     * ＳＲＡＭクラス コンストラクト 
     */
    sram_title_ct( thisx, &this->sram );
    /* ＳＲＡＭイニシャライズチェック */
    sram_initialize( thisx, &this->sram );
# endif
    
    /* 文字フォント セット */
    kscope_kanfont_get( kanfont );


    Na_ChangeSoundMode( NA_MODE_TITLE );
    /* ＢＧＭ */
////////    Na_StartBgm( NA_BGM_TITLE );
    Na_StartIntroCutBgm( NA_BGM_FILE_SELECT );
    /* ＢＧＭ（ナレーション）*/
////////    Na_StartNarration( NA_NAR_HIRAL );

}


