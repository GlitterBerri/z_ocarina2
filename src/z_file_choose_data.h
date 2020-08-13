/* $Id: z_file_choose_data.h,v 2.4 1998-10-29 16:15:00+09 soejima Exp $
 * $Log: z_file_choose_data.h,v $
 * Revision 2.4  1998-10-29 16:15:00+09  soejima
 * ＰＡＬ変更
 *
 * Revision 2.3  1998-10-28 18:35:17+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.2  1998-10-27 11:27:44+09  takahata
 * *** empty log message ***
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.11  1998/09/19 11:58:48  takahata
 * *** empty log message ***
 *
 * Revision 1.10  1998-09-17 21:00:56+09  takahata
 * *** empty log message ***
 *
 * Revision 1.9  1998-09-16 22:06:11+09  takahata
 * *** empty log message ***
 *
 * Revision 1.8  1998-07-06 22:20:31+09  soejima
 * *** empty log message ***
 *
 * Revision 1.7  1998-06-25 17:43:50+09  soejima
 * *** empty log message ***
 *
 * Revision 1.6  1998-06-01 09:52:24+09  soejima
 * *** empty log message ***
 *
 * Revision 1.5  1998-02-03 18:07:33+09  soejima
 * *** empty log message ***
 *
 * Revision 1.4  1997/09/30  09:17:13  soejima
 * Revision 1.3  1997/09/24  13:49:52  soejima
 * Revision 1.2  1997/09/18  13:18:53  soejima
 * Revision 1.1  1997/05/29  08:18:52  soejima
 * Initial revision
 * $Log追加
 * */

#ifndef PAL_VERSION


#ifndef INCLUDE_Z_FILE_CHOOSE_DATA_H
#define INCLUDE_Z_FILE_CHOOSE_DATA_DL_H

/************************************************************************
 *									*
 *	ＦＩＬＥ ＣＨＯＯＳＥ ディスプレイリスト			*
 *				1997年05月29日(木曜日) 11時45分00秒 JST *
 ************************************************************************/



/*----------------------------------------------------------------------*/
/*	DEFINE								*/
/*----------------------------------------------------------------------*/
#define	OP_TITLE_SUU		( 4 )
#define	OP_PLATE_0_SUU		( 4 )
#define	OP_PLATE_1_SUU		( 2 )
#define	OP_PLATE_2_SUU		( 2 )
#define	OP_PLATE_SUU		( 8 )
#define	OP_LINE_SUU		( 3 )
#define	OP_TITLE_VTX_SUU	( OP_TITLE_SUU * 4 )
#define	OP_PLATE_VTX_SUU	( OP_PLATE_SUU * 4 )
#define	OP_LINE_VTX_SUU		( OP_LINE_SUU  * 4 )

#define	DSP_OPT_BASE_X		( -120 )
#define	DSP_OPT_BASE_Y		( 80 )

#define	H_MES_OPTION_W		( 128 )
#define	H_MES_OPTION_H		( 16 )
#define	H_MES_OPTION_X1		( DSP_OPT_BASE_X + 26 )
#define	H_MES_OPTION_Y1		( DSP_OPT_BASE_Y - 8 )
#define	H_MES_OPTION_X2		( H_MES_OPTION_X1 + H_MES_OPTION_W )
#define	H_MES_OPTION_Y2		( H_MES_OPTION_Y1 - H_MES_OPTION_H )

#define	H_OP_SOUND_W		( 64 )
#define	H_OP_SOUND_H		( 16 )
#define	H_OP_SOUND_X1		( DSP_OPT_BASE_X + 20 )
#define	H_OP_SOUND_Y1		( H_MES_OPTION_Y2 - 12 )
#define	H_OP_SOUND_X2		( H_OP_SOUND_X1 + H_OP_SOUND_W )
#define	H_OP_SOUND_Y2		( H_OP_SOUND_Y1 - H_OP_SOUND_H )

#define	H_OP_LINE_W		( 256 )
#define	H_OP_LINE_H		( 2 )
#define	H_OP_LINE_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE_Y1		( H_OP_SOUND_Y2 )
#define	H_OP_LINE_X2		( H_OP_LINE_X1 + H_OP_LINE_W )
#define	H_OP_LINE_Y2		( H_OP_LINE_Y1 - H_OP_LINE_H )

#define	H_OP_MONO_W		( 48 )
#define	H_OP_MONO_H		( 16 )
#define	H_OP_MONO_X1		( H_OP_SOUND_X1 )
#define	H_OP_MONO_Y1		( H_OP_LINE_Y2 )
#define	H_OP_MONO_X2		( H_OP_MONO_X1 + H_OP_MONO_W )
#define	H_OP_MONO_Y2		( H_OP_MONO_Y1 - H_OP_MONO_H )

#define	H_OP_STEREO_W		( 48 )
#define	H_OP_STEREO_H		( 16 )
#define	H_OP_STEREO_X1		( H_OP_MONO_X2 + 4 )
#define	H_OP_STEREO_Y1		( H_OP_LINE_Y2 )
#define	H_OP_STEREO_X2		( H_OP_STEREO_X1 + H_OP_STEREO_W )
#define	H_OP_STEREO_Y2		( H_OP_STEREO_Y1 - H_OP_STEREO_H )

#define	H_OP_HEADPHONES_W	( 48 )
#define	H_OP_HEADPHONES_H	( 16 )
#define	H_OP_HEADPHONES_X1	( H_OP_STEREO_X2 + 4 )
#define	H_OP_HEADPHONES_Y1	( H_OP_LINE_Y2 )
#define	H_OP_HEADPHONES_X2	( H_OP_HEADPHONES_X1 + H_OP_HEADPHONES_W )
#define	H_OP_HEADPHONES_Y2	( H_OP_HEADPHONES_Y1 - H_OP_HEADPHONES_H )

#define	H_OP_3D_W		( 48 )
#define	H_OP_3D_H		( 16 )
#define	H_OP_3D_X1		( H_OP_HEADPHONES_X2 + 4 )
#define	H_OP_3D_Y1		( H_OP_LINE_Y2 )
#define	H_OP_3D_X2		( H_OP_3D_X1 + H_OP_3D_W )
#define	H_OP_3D_Y2		( H_OP_3D_Y1 - H_OP_3D_H )

#define	H_OP_Z_W		( 64 )
#define	H_OP_Z_H		( 16 )
#define	H_OP_Z_X1		( H_OP_SOUND_X1 )
#define	H_OP_Z_Y1		( H_OP_MONO_Y2 - 6 )
#define	H_OP_Z_X2		( H_OP_Z_X1 + H_OP_Z_W )
#define	H_OP_Z_Y2		( H_OP_Z_Y1 - H_OP_Z_H )

#define	H_OP_LINE2_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE2_Y1		( H_OP_Z_Y2 )
#define	H_OP_LINE2_X2		( H_OP_LINE2_X1 + H_OP_LINE_W )
#define	H_OP_LINE2_Y2		( H_OP_LINE2_Y1 - H_OP_LINE_H )

#define	H_OP_SWITCH_W		( 48 )
#define	H_OP_SWITCH_H		( 16 )
#define	H_OP_SWITCH_X1		( H_OP_SOUND_X1 )
#define	H_OP_SWITCH_Y1		( H_OP_LINE2_Y2 )
#define	H_OP_SWITCH_X2		( H_OP_SWITCH_X1 + H_OP_SWITCH_W )
#define	H_OP_SWITCH_Y2		( H_OP_SWITCH_Y1 - H_OP_SWITCH_H )

#define	H_OP_HOLD_W		( 48 )
#define	H_OP_HOLD_H		( 16 )
#define	H_OP_HOLD_X1		( H_OP_SWITCH_X2 + 4 )
#define	H_OP_HOLD_Y1		( H_OP_LINE2_Y2 )
#define	H_OP_HOLD_X2		( H_OP_HOLD_X1 + H_OP_HOLD_W )
#define	H_OP_HOLD_Y2		( H_OP_HOLD_Y1 - H_OP_HOLD_H )

#define	H_OP_SAMPLE_W		( 96 )
#define	H_OP_SAMPLE_H		( 16 )
#define	H_OP_SAMPLE_X1		( H_OP_SOUND_X1 )
#define	H_OP_SAMPLE_Y1		( H_OP_SWITCH_Y2 - 6 )
#define	H_OP_SAMPLE_X2		( H_OP_SAMPLE_X1 + H_OP_SAMPLE_W )
#define	H_OP_SAMPLE_Y2		( H_OP_SAMPLE_Y1 - H_OP_SAMPLE_H )

#define	H_OP_LINE3_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE3_Y1		( H_OP_SAMPLE_Y2 )
#define	H_OP_LINE3_X2		( H_OP_LINE3_X1 + H_OP_LINE_W )
#define	H_OP_LINE3_Y2		( H_OP_LINE3_Y1 - H_OP_LINE_H )

#define	H_OP_CONTRAST_W		( 96 )
#define	H_OP_CONTRAST_H		( 16 )
#define	H_OP_CONTRAST_X1	( H_OP_SOUND_X1 )
#define	H_OP_CONTRAST_Y1	( H_OP_LINE3_Y2 )
#define	H_OP_CONTRAST_X2	( H_OP_CONTRAST_X1 + H_OP_CONTRAST_W )
#define	H_OP_CONTRAST_Y2	( H_OP_CONTRAST_Y1 - H_OP_CONTRAST_H )

#define	H_OP_CONTRAST2_X1	( H_OP_CONTRAST_X2 )
#define	H_OP_CONTRAST2_Y1	( H_OP_CONTRAST_Y1 )
#define	H_OP_CONTRAST2_X2	( H_OP_CONTRAST2_X1 + H_OP_CONTRAST_W )
#define	H_OP_CONTRAST2_Y2	( H_OP_CONTRAST2_Y1 - H_OP_CONTRAST_H )

/*=======================================================================
  =	ディスプレイ・リスト						=
  =======================================================================*/
extern Vtx_t menu_select_titlevtx[];

extern Gfx menu_frame_dl000[];
extern Gfx menu_frame_dl001[];
extern Gfx menu_frame_dl002[];
extern Gfx menu_frame_dl100[];
extern Gfx menu_frame_dl101[];
extern Gfx menu_frame_dl102[];

extern Vtx_t menu_option_titlevtx[];
extern Vtx_t menu_option_plate[];
extern Vtx_t menu_option_line[];


/****************************************************************
 *	名前登録用 データ			      		*
 ****************************************************************/
/* 名前登録 文字テーブル */
extern short	title_name_eisu[];
extern short	title_name_hira[];
extern short	title_name_kata[];
extern short	alpha_index[];


# if 0
/* 選択チェック 範囲データ */
extern short 	moji_check_xdt0[];
extern short 	moji_check_xdt1[];
extern short 	moji_check_ydt0[];
extern short 	moji_check_ydt1[];
extern short 	moji_check_xdt2[];
extern short 	moji_check_xdt3[];
# endif


extern unsigned char	h_op_z_txt[];
extern unsigned char	h_op_z_nes_txt[];
extern unsigned char	h_op_switch_txt[];
extern unsigned char	h_op_switch_nes_txt[];
extern unsigned char	h_op_hold_txt[];
extern unsigned char	h_op_hold_nes_txt[];
extern unsigned char	h_op_contrast_txt[];
extern unsigned char	h_op_sample_txt[];
extern unsigned char	h_op_sample_nes_txt[];


#endif

/*** z_file_choose_data.h end ***/

#endif	/* !PAL_VERSION */

#ifdef PAL_VERSION

#ifndef INCLUDE_Z_FILE_CHOOSE_DATA_H
#define INCLUDE_Z_FILE_CHOOSE_DATA_DL_H

/************************************************************************
 *									*
 *	ＦＩＬＥ ＣＨＯＯＳＥ ディスプレイリスト			*
 *				1997年05月29日(木曜日) 11時45分00秒 JST *
 ************************************************************************/

/*** PAL 変更 ↓ ***/

/*----------------------------------------------------------------------*/
/*	DEFINE								*/
/*----------------------------------------------------------------------*/
#define	OP_TITLE_SUU		( 6 )
#define	OP_PLATE_0_SUU		( 4 )
#define	OP_PLATE_1_SUU		( 2 )
#define	OP_PLATE_2_SUU		( 2 )
#define	OP_PLATE_3_SUU		( 2 )
#define	OP_PLATE_SUU		( 8 )
#define	OP_LINE_SUU		( 4 )
#define	OP_TITLE_VTX_SUU	( OP_TITLE_SUU * 4 )
#define	OP_PLATE_VTX_SUU	( OP_PLATE_SUU * 4 )
#define	OP_PLATE2_VTX_SUU	( OP_PLATE_3_SUU * 4 )
#define	OP_LINE_VTX_SUU		( OP_LINE_SUU * 4 )

#define	OP_PLATE3_SUU		( 3 )
#define	OP_PLATE3_VTX_SUU	( OP_PLATE3_SUU * 4 )

#define	OP_TITLE_G_VTX_P	( 12 )



#define	DSP_OPT_BASE_X		( -120 )
#define	DSP_OPT_BASE_Y		( 80 )




#define	H_MES_OPTION_W		( 128 )
#define	H_MES_OPTION_H		( 16 )
#define	H_MES_OPTION_X1		( DSP_OPT_BASE_X + 26 )
#define	H_MES_OPTION_Y1		( DSP_OPT_BASE_Y - 8 )
#define	H_MES_OPTION_X2		( H_MES_OPTION_X1 + H_MES_OPTION_W )
#define	H_MES_OPTION_Y2		( H_MES_OPTION_Y1 - H_MES_OPTION_H )

#define	H_OP_SOUND_W		( 64 )
#define	H_OP_SOUND_H		( 16 )
#define	H_OP_SOUND_X1		( DSP_OPT_BASE_X + 20 )
#define	H_OP_SOUND_Y1		( H_MES_OPTION_Y2 - 10 )
#define	H_OP_SOUND_X2		( H_OP_SOUND_X1 + H_OP_SOUND_W )
#define	H_OP_SOUND_Y2		( H_OP_SOUND_Y1 - H_OP_SOUND_H )

#define	H_OP_LINE_W		( 256 )
#define	H_OP_LINE_H		( 2 )
#define	H_OP_LINE_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE_Y1		( H_OP_SOUND_Y2 + 4 )
#define	H_OP_LINE_X2		( H_OP_LINE_X1 + H_OP_LINE_W )
#define	H_OP_LINE_Y2		( H_OP_LINE_Y1 - H_OP_LINE_H )

#define	H_OP_MONO_W		( 48 )
#define	H_OP_MONO_H		( 16 )
#define	H_OP_MONO_X1		( H_OP_SOUND_X1 )
#define	H_OP_MONO_Y1		( H_OP_LINE_Y2 )
#define	H_OP_MONO_X2		( H_OP_MONO_X1 + H_OP_MONO_W )
#define	H_OP_MONO_Y2		( H_OP_MONO_Y1 - H_OP_MONO_H )

#define	H_OP_STEREO_W		( 48 )
#define	H_OP_STEREO_H		( 16 )
#define	H_OP_STEREO_X1		( H_OP_MONO_X2 + 4 )
#define	H_OP_STEREO_Y1		( H_OP_LINE_Y2 )
#define	H_OP_STEREO_X2		( H_OP_STEREO_X1 + H_OP_STEREO_W )
#define	H_OP_STEREO_Y2		( H_OP_STEREO_Y1 - H_OP_STEREO_H )

#define	H_OP_HEADPHONES_W	( 48 )
#define	H_OP_HEADPHONES_H	( 16 )
#define	H_OP_HEADPHONES_X1	( H_OP_STEREO_X2 + 4 )
#define	H_OP_HEADPHONES_Y1	( H_OP_LINE_Y2 )
#define	H_OP_HEADPHONES_X2	( H_OP_HEADPHONES_X1 + H_OP_HEADPHONES_W )
#define	H_OP_HEADPHONES_Y2	( H_OP_HEADPHONES_Y1 - H_OP_HEADPHONES_H )

#define	H_OP_3D_W		( 48 )
#define	H_OP_3D_H		( 16 )
#define	H_OP_3D_X1		( H_OP_HEADPHONES_X2 + 4 )
#define	H_OP_3D_Y1		( H_OP_LINE_Y2 )
#define	H_OP_3D_X2		( H_OP_3D_X1 + H_OP_3D_W )
#define	H_OP_3D_Y2		( H_OP_3D_Y1 - H_OP_3D_H )

#define	H_OP_Z_W		( 64 )
#define	H_OP_Z_W_G		( 144 )
#define	H_OP_Z_H		( 16 )
#define	H_OP_Z_X1		( H_OP_SOUND_X1 )
#define	H_OP_Z_Y1		( H_OP_MONO_Y2 + 1 )
#define	H_OP_Z_X2		( H_OP_Z_X1 + H_OP_Z_W )
#define	H_OP_Z_X2_G		( H_OP_Z_X1 + H_OP_Z_W_G )
#define	H_OP_Z_Y2		( H_OP_Z_Y1 - H_OP_Z_H )

#define	H_OP_LINE2_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE2_Y1		( H_OP_Z_Y2 + 4 )
#define	H_OP_LINE2_X2		( H_OP_LINE2_X1 + H_OP_LINE_W )
#define	H_OP_LINE2_Y2		( H_OP_LINE2_Y1 - H_OP_LINE_H )

#define	H_OP_SWITCH_W		( 48 )
#define	H_OP_SWITCH_W_G		( 80 )
#define	H_OP_SWITCH_H		( 16 )
#define	H_OP_SWITCH_X1		( H_OP_SOUND_X1 )
#define	H_OP_SWITCH_Y1		( H_OP_LINE2_Y2 )
#define	H_OP_SWITCH_X2		( H_OP_SWITCH_X1 + H_OP_SWITCH_W )
#define	H_OP_SWITCH_X2_G	( H_OP_SWITCH_X1 + H_OP_SWITCH_W_G )
#define	H_OP_SWITCH_Y2		( H_OP_SWITCH_Y1 - H_OP_SWITCH_H )

#define	H_OP_HOLD_W		( 48 )
#define	H_OP_HOLD_W_G		( 80 )
#define	H_OP_HOLD_H		( 16 )
#define	H_OP_HOLD_X1		( H_OP_SWITCH_X2 + 36 )
#define	H_OP_HOLD_Y1		( H_OP_LINE2_Y2 )
#define	H_OP_HOLD_X2		( H_OP_HOLD_X1 + H_OP_HOLD_W )
#define	H_OP_HOLD_X2_G		( H_OP_HOLD_X1 + H_OP_HOLD_W_G )
#define	H_OP_HOLD_Y2		( H_OP_HOLD_Y1 - H_OP_HOLD_H )


#define	H_OP_LANGUAGE_W		( 64 )
#define	H_OP_LANGUAGE_H		( 16 )
#define	H_OP_LANGUAGE_X1	( H_OP_SOUND_X1 )
#define	H_OP_LANGUAGE_Y1	( H_OP_SWITCH_Y2 + 1 )
#define	H_OP_LANGUAGE_X2	( H_OP_LANGUAGE_X1 + H_OP_LANGUAGE_W )
#define	H_OP_LANGUAGE_Y2	( H_OP_LANGUAGE_Y1 - H_OP_LANGUAGE_H )

#define	H_OP_LINE4_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE4_Y1		( H_OP_LANGUAGE_Y2 + 4 )
#define	H_OP_LINE4_X2		( H_OP_LINE4_X1 + H_OP_LINE_W )
#define	H_OP_LINE4_Y2		( H_OP_LINE4_Y1 - H_OP_LINE_H )

#define	H_OP_ENGLISH_W		( 48 )
#define	H_OP_ENGLISH_H		( 16 )
#define	H_OP_ENGLISH_X1		( H_OP_SOUND_X1 )
#define	H_OP_ENGLISH_Y1		( H_OP_LINE4_Y2 )
#define	H_OP_ENGLISH_X2		( H_OP_ENGLISH_X1 + H_OP_ENGLISH_W )
#define	H_OP_ENGLISH_Y2		( H_OP_ENGLISH_Y1 - H_OP_ENGLISH_H )

#define	H_OP_GERMAN_W		( 48 )
#define	H_OP_GERMAN_H		( 16 )
#define	H_OP_GERMAN_X1		( H_OP_ENGLISH_X2 + 4 )
#define	H_OP_GERMAN_Y1		( H_OP_LINE4_Y2 )
#define	H_OP_GERMAN_X2		( H_OP_GERMAN_X1 + H_OP_GERMAN_W )
#define	H_OP_GERMAN_Y2		( H_OP_GERMAN_Y1 - H_OP_GERMAN_H )

#define	H_OP_FRENCH_W		( 48 )
#define	H_OP_FRENCH_H		( 16 )
#define	H_OP_FRENCH_X1		( H_OP_GERMAN_X2 + 4 )
#define	H_OP_FRENCH_Y1		( H_OP_LINE4_Y2 )
#define	H_OP_FRENCH_X2		( H_OP_FRENCH_X1 + H_OP_FRENCH_W )
#define	H_OP_FRENCH_Y2		( H_OP_FRENCH_Y1 - H_OP_FRENCH_H )


#define	H_OP_SAMPLE_W		( 128 )
#define	H_OP_SAMPLE_H		( 16 )
#define	H_OP_SAMPLE_X1		( H_OP_SOUND_X1 )
#define	H_OP_SAMPLE_Y1		( H_OP_ENGLISH_Y2 + 1 )
#define	H_OP_SAMPLE_X2		( H_OP_SAMPLE_X1 + H_OP_SAMPLE_W )
#define	H_OP_SAMPLE_Y2		( H_OP_SAMPLE_Y1 - H_OP_SAMPLE_H )

#define	H_OP_LINE3_X1		( H_OP_SOUND_X1 )
#define	H_OP_LINE3_Y1		( H_OP_SAMPLE_Y2 + 4 )
#define	H_OP_LINE3_X2		( H_OP_LINE3_X1 + H_OP_LINE_W )
#define	H_OP_LINE3_Y2		( H_OP_LINE3_Y1 - H_OP_LINE_H )

#define	H_OP_CONTRAST_W		( 96 )
#define	H_OP_CONTRAST_H		( 16 )
#define	H_OP_CONTRAST_X1	( H_OP_SOUND_X1 )
#define	H_OP_CONTRAST_Y1	( H_OP_LINE3_Y2 )
#define	H_OP_CONTRAST_X2	( H_OP_CONTRAST_X1 + H_OP_CONTRAST_W )
#define	H_OP_CONTRAST_Y2	( H_OP_CONTRAST_Y1 - H_OP_CONTRAST_H )

#define	H_OP_CONTRAST2_X1	( H_OP_CONTRAST_X2 )
#define	H_OP_CONTRAST2_Y1	( H_OP_CONTRAST_Y1 )
#define	H_OP_CONTRAST2_X2	( H_OP_CONTRAST2_X1 + H_OP_CONTRAST_W )
#define	H_OP_CONTRAST2_Y2	( H_OP_CONTRAST2_Y1 - H_OP_CONTRAST_H )


/*** PAL 変更 ↑ ***/



/*=======================================================================
  =	ディスプレイ・リスト						=
  =======================================================================*/
extern Vtx_t menu_select_titlevtx[];

extern Gfx menu_frame_dl000[];
extern Gfx menu_frame_dl001[];
extern Gfx menu_frame_dl002[];
extern Gfx menu_frame_dl100[];
extern Gfx menu_frame_dl101[];
extern Gfx menu_frame_dl102[];

extern Vtx_t menu_option_titlevtx[];
extern Vtx_t menu_option_plate[];
extern Vtx_t menu_option_plate2[];
extern Vtx_t menu_option_plate3[];
extern Vtx_t menu_option_line[];


/****************************************************************
 *	名前登録用 データ			      		*
 ****************************************************************/
/* 名前登録 文字テーブル */
extern short	title_name_eisu[];



/*** PAL 変更 ↓ ***/
extern unsigned char	h_op_sample_e_txt[];
extern unsigned char	h_op_sample_g_txt[];
extern unsigned char	h_op_sample_f_txt[];
extern unsigned char	h_mes_option_g_txt[];
extern unsigned char	h_op_sound_e_txt[];
extern unsigned char	h_op_sound_f_txt[];
extern unsigned char	h_op_z_e_txt[];
extern unsigned char	h_op_z_g_txt[];
extern unsigned char	h_op_z_f_txt[];
extern unsigned char	h_op_sample_e_txt[];
extern unsigned char	h_op_sample_g_txt[];
extern unsigned char	h_op_sample_f_txt[];
extern unsigned char	h_op_language_e_txt[];
extern unsigned char	h_op_language_g_txt[];
extern unsigned char	h_op_language_f_txt[];

extern unsigned char	h_op_stereo_e_txt[];
extern unsigned char	h_op_stereo_f_txt[];
extern unsigned char	h_op_mono_e_txt[];
extern unsigned char	h_op_headphones_e_txt[];
extern unsigned char	h_op_headphones_g_txt[];
extern unsigned char	h_op_headphones_f_txt[];
extern unsigned char	h_op_3d_e_txt[];
extern unsigned char	h_op_switch_e_txt[];
extern unsigned char	h_op_switch_g_txt[];
extern unsigned char	h_op_switch_f_txt[];
extern unsigned char	h_op_hold_e_txt[];
extern unsigned char	h_op_hold_g_txt[];
extern unsigned char	h_op_hold_f_txt[];

extern unsigned char	h_op_contrast_txt[];


extern unsigned char 	g_op_l_eng_txt[];
extern unsigned char 	g_op_l_ger_txt[];
extern unsigned char 	g_op_l_fra_txt[];
extern unsigned char 	g_op_l_select_txt[];
extern unsigned char 	g_op_cursor_txt[];
/*** PAL 変更 ↑ ***/


#endif

/*** z_file_choose_data.h end ***/

#endif	/* PAL_VERSION */



