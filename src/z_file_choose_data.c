/* $Id: z_file_choose_data.c,v 2.2 1998/11/06 03:04:07 soejima Exp $
 *
 * ファイル選択処理ＤＡＴＡ
 *
 * $Log: z_file_choose_data.c,v $
 * Revision 2.2  1998/11/06  03:04:07  soejima
 * コメント
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.14  1998/09/19 11:58:52  takahata
 * *** empty log message ***
 *
 * Revision 1.13  1998-09-17 21:01:00+09  takahata
 * *** empty log message ***
 *
 * Revision 1.12  1998-07-06 22:20:38+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/05/29  08:19:00  soejima
 * Initial revision
 * $Log追加
 * */


/************************************************************************
 *									*
 *	ＦＩＬＥ ＣＨＯＯＳＥ ディスプレイリスト			*
 *				1997年05月29日(木曜日) 11時45分00秒 JST *
 ************************************************************************/
#include "z_basic.h"
#include "z_define1.h"
#include "z_file_choose_h.h"
#include "z_kaleido_moji.h"
#include "z_file_choose_data.h"




/************************************************************************
 *									*
 *									*
 *									*
 ************************************************************************/
/****************************************************************
 *	タイトルＶｔｘデータ			      		*
 ****************************************************************/
Vtx_t menu_select_titlevtx[] = {
    /* タイトル（名前登録）*/
    	{  -94,  72,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  -38,  72,  0,  0,  56<<5,      0,  255, 255, 255, 255, },
	{  -94,  56,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{  -38,  56,  0,  0,  56<<5,  16<<5,  255, 255, 255, 255, },


    /* プレート（ひらがな） */
    	{  -96, -48,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  -52, -48,  0,  0,  44<<5,      0,  255, 255, 255, 255, },
	{  -96, -64,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{  -52, -64,  0,  0,  44<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（カタカナ） */
    	{  -48, -48,  0,  0,      0,      0,  255, 255, 255, 255, },
	{   -4, -48,  0,  0,  44<<5,      0,  255, 255, 255, 255, },
	{  -48, -64,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{   -4, -64,  0,  0,  44<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（英数） */
    	{    0, -48,  0,  0,      0,      0,  255, 255, 255, 255, },
	{   28, -48,  0,  0,  28<<5,      0,  255, 255, 255, 255, },
	{    0, -64,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{   28, -64,  0,  0,  28<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（戻る） */
    	{   32, -48,  0,  0,      0,      0,  255, 255, 255, 255, },
	{   60, -48,  0,  0,  28<<5,      0,  255, 255, 255, 255, },
	{   32, -64,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{   60, -64,  0,  0,  28<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（決定） */
    	{   64, -48,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  108, -48,  0,  0,  44<<5,      0,  255, 255, 255, 255, },
	{   64, -64,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{  108, -64,  0,  0,  44<<5,  16<<5,  255, 255, 255, 255, },
};






/* 名前登録 文字テーブル */
short 	title_name_hira[] = {
/* 	 あ   か   さ   た   な   は   ま   や   ら   わ   ぁ    ゃ    っ  */
    	HAA, HKA, HSA, HTA, HNA, HHA, HMA, HYA, HRA, HWA, HXA, HXYA, HXTU,
/*	 い   き   し   ち   に   ひ   み        り        ぃ              */
    	HII, HKI, HSI, HTI, HNI, HHI, HMI, SSS, HRI, SSS, HXI,  SSS,  SSS,
/*	 う   く   す   つ   ぬ   ふ   む   ゆ   る   を   ぅ    ゅ    ─  */
    	HUU, HKU, HSU, HTU, HNU, HHU, HMU, HYU, HRU, HWO, HXU, HXYU,  SPD,
/*	 え   け   せ   て   ね   へ   め        れ        ぇ          ゛  */
    	HEE, HKE, HSE, HTE, HNE, HHE, HME, SSS, HRE, SSS, HXE,  SSS,  SPJ,
/*	 お   こ   そ   と   の   ほ   も   よ   ろ   ん   ぉ    ょ    ゜  */
    	HOO, HKO, HSO, HTO, HNO, HHO, HMO, HYO, HRO, HNN, HXO, HXYO,  SPK,
};

short 	title_name_kata[] = {
/*	 ア   カ   サ   タ   ナ   ハ   マ   ヤ   ラ   ワ   ァ    ャ    ッ  */
	KAA, KKA, KSA, KTA, KNA, KHA, KMA, KYA, KRA, KWA, KXA, KXYA, KXTU,
/*	 イ   キ   シ   チ   ニ   ヒ   ミ        リ        ィ              */
	KII, KKI, KSI, KTI, KNI, KHI, KMI, SSS, KRI, SSS, KXI,  SSS,  SSS,
/*	 ウ   ク   ス   ツ   ヌ   フ   ム   ユ   ル   ヲ   ゥ    ュ    ─  */
	KUU, KKU, KSU, KTU, KNU, KHU, KMU, KYU, KRU, KWO, KXU, KXYU,  SPD,
/*	 エ   ケ   セ   テ   ネ   ヘ   メ        レ        ェ          ゛  */
	KEE, KKE, KSE, KTE, KNE, KHE, KME, SSS, KRE, SSS, KXE,  SSS,  SPJ,
/*	 オ   コ   ソ   ト   ノ   ホ   モ   ヨ   ロ   ン   ォ    ョ    ゜  */
	KOO, KKO, KSO, KTO, KNO, KHO, KMO, KYO, KRO, KNN, KXO, KXYO,  SPK,
};

short 	title_name_eisu[] = {
/*	 Ａ   Ｂ   Ｃ   Ｄ   Ｅ   Ｆ   Ｇ   Ｈ   Ｉ   Ｊ   Ｋ   Ｌ   Ｍ    */
	AAA, AAB, AAC, AAD, AAE, AAF, AAG, AAH, AAI, AAJ, AAK, AAL, AAM,
/*	 Ｎ   Ｏ   Ｐ   Ｑ   Ｒ   Ｓ   Ｔ   Ｕ   Ｖ   Ｗ   Ｘ   Ｙ   Ｚ    */
	AAN, AAO, AAP, AAQ, AAR, AAS, AAT, AAU, AAV, AAW, AAX, AAY, AAZ,
/*	 ａ   ｂ   ｃ   ｄ   ｅ   ｆ   ｇ   ｈ   ｉ   ｊ   ｋ   ｌ   ｍ    */
	AXA, AXB, AXC, AXD, AXE, AXF, AXG, AXH, AXI, AXJ, AXK, AXL, AXM,
/*	 ｎ   ｏ   ｐ   ｑ   ｒ   ｓ   ｔ   ｕ   ｖ   ｗ   ｘ   ｙ   ｚ    */
	AXN, AXO, AXP, AXQ, AXR, AXS, AXT, AXU, AXV, AXW, AXX, AXY, AXZ,
/*	 １   ２   ３   ４   ５   ６   ７   ８   ９   ０  ─               */
	SS1, SS2, SS3, SS4, SS5, SS6, SS7, SS8, SS9, SS0, SPO, SPD, SSS,
};


short alpha_index[] = {
/*	Hira_hira  Kata_kata  Eisu_eisu  */
	Hira_hira, Kata_kata, Eisu_eisu,
/*      Hira_kata  Kata_hira  Hira_eisu  Eisu_hira  Kata_eisu  Eisu_kata  */
	Kata_kata, Hira_hira, Eisu_eisu, Hira_hira, Eisu_eisu, Kata_kata,
};


#define	KS	(KEY_SHIFT/10)
# if 0
/* 選択チェック 範囲データ */
short moji_check_xdt0[] = {	/* 左 */
    (-96-7)*KS,  (-80-7)*KS, (-64-7)*KS, (-48-7)*KS, (-32-7)*KS,  (-16-7)*KS, (0-7)*KS, (16-7)*KS, (32-7)*KS, (48-7)*KS, (64-7)*KS, (80-7)*KS, (96-7)*KS,
};
short moji_check_xdt1[] = {	/* 右 */
    (-80-7)*KS, (-64-7)*KS, (-48-7)*KS, (-32-7)*KS,  (-16-7)*KS, (0-7)*KS, (16-7)*KS, (32-7)*KS, (48-7)*KS, (64-7)*KS, (80-7)*KS, (96-7)*KS, (112-7)*KS
};
short moji_check_ydt0[] = {	/* 上 */
    (38+8)*KS, (22+8)*KS, (6+8)*KS, (-10+8)*KS, (-26+8)*KS, (-42+8)*KS,
};
short moji_check_ydt1[] = {	/* 下 */
    (22+8)*KS, (6+8)*KS, (-10+8)*KS, (-26+8)*KS, (-42+8)*KS, (-58+8)*KS,
};
short moji_check_xdt2[] = {	/* 左 */
	-119*KS, -58*KS, 8*KS, 50*KS, 92*KS,
};
short moji_check_xdt3[] = {	/* 右 */
	-58*KS, 8*KS, 50*KS, 92*KS, 113*KS,
};
# endif




/****************************************************************
 *	ＯＰＴＩＯＮＶｔｘデータ		      		*
 ****************************************************************/


#if 01

Vtx_t menu_option_titlevtx[ OP_TITLE_VTX_SUU ] = {
    /* タイトル（ＯＰＴＩＯＮ）*/
    	{ H_MES_OPTION_X1, H_MES_OPTION_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_MES_OPTION_X2, H_MES_OPTION_Y1, 0, 0, H_MES_OPTION_W<<5, 0, 255, 255, 255, 255, },
	{ H_MES_OPTION_X1, H_MES_OPTION_Y2, 0, 0, 0, H_MES_OPTION_H<<5, 255, 255, 255, 255, },
	{ H_MES_OPTION_X2, H_MES_OPTION_Y2, 0, 0,
	  H_MES_OPTION_W<<5, H_MES_OPTION_H<<5, 255, 255, 255, 255, },

    /* プレート（ＳＯＵＮＤ）*/
    	{ H_OP_SOUND_X1, H_OP_SOUND_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_SOUND_X2, H_OP_SOUND_Y1, 0, 0, H_OP_SOUND_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_SOUND_X1, H_OP_SOUND_Y2, 0, 0, 0, H_MES_OPTION_H<<5, 255, 255, 255, 255, },
	{ H_OP_SOUND_X2, H_OP_SOUND_Y2, 0, 0, H_OP_SOUND_W<<5, H_MES_OPTION_H<<5, 255, 255, 255, 255, },

    /* Ｚ注目タイプ */
    	{ H_OP_Z_X1, H_OP_Z_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_Z_X2, H_OP_Z_Y1, 0, 0, H_OP_Z_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_Z_X1, H_OP_Z_Y2, 0, 0, 0, H_OP_Z_H<<5, 255, 255, 255, 255, },
	{ H_OP_Z_X2, H_OP_Z_Y2, 0, 0, H_OP_Z_W<<5, H_OP_Z_H<<5, 255, 255, 255, 255, },

    /* サンプル */
    	{ H_OP_SAMPLE_X1, H_OP_SAMPLE_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_SAMPLE_X2, H_OP_SAMPLE_Y1, 0, 0, H_OP_SAMPLE_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_SAMPLE_X1, H_OP_SAMPLE_Y2, 0, 0, 0, H_OP_SAMPLE_H<<5, 255, 255, 255, 255, },
	{ H_OP_SAMPLE_X2, H_OP_SAMPLE_Y2, 0, 0, H_OP_SAMPLE_W<<5, H_OP_SAMPLE_H<<5, 255, 255, 255, 255, },
};

Vtx_t menu_option_plate[ OP_PLATE_VTX_SUU ] = {
    /* プレート（モノラル）*/
    	{ H_OP_MONO_X1, H_OP_MONO_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_MONO_X2, H_OP_MONO_Y1, 0, 0, H_OP_MONO_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_MONO_X1, H_OP_MONO_Y2, 0, 0, 0, H_OP_MONO_H<<5, 255, 255, 255, 255, },
	{ H_OP_MONO_X2, H_OP_MONO_Y2, 0, 0, H_OP_MONO_W<<5, H_OP_MONO_H<<5, 255, 255, 255, 255, },

    /* プレート（ステレオ）*/
    	{ H_OP_STEREO_X1, H_OP_STEREO_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_STEREO_X2, H_OP_STEREO_Y1, 0, 0, H_OP_STEREO_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_STEREO_X1, H_OP_STEREO_Y2, 0, 0, 0, H_OP_MONO_H<<5, 255, 255, 255, 255, },
	{ H_OP_STEREO_X2, H_OP_STEREO_Y2, 0, 0, H_OP_STEREO_W<<5, H_OP_MONO_H<<5, 255, 255, 255, 255, },

    /* プレート（ヘッドホン）*/
    	{ H_OP_HEADPHONES_X1, H_OP_HEADPHONES_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_HEADPHONES_X2, H_OP_HEADPHONES_Y1, 0, 0, H_OP_HEADPHONES_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_HEADPHONES_X1, H_OP_HEADPHONES_Y2, 0, 0, 0, H_OP_STEREO_H<<5, 255, 255, 255, 255, },
	{ H_OP_HEADPHONES_X2, H_OP_HEADPHONES_Y2, 0, 0,
	  H_OP_HEADPHONES_W<<5, H_OP_STEREO_H<<5, 255, 255, 255, 255, },

    /* プレート（３Ｄ）*/
    	{ H_OP_3D_X1, H_OP_3D_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_3D_X2, H_OP_3D_Y1, 0, 0, H_OP_3D_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_3D_X1, H_OP_3D_Y2, 0, 0, 0, H_OP_3D_H<<5, 255, 255, 255, 255, },
	{ H_OP_3D_X2, H_OP_3D_Y2, 0, 0, H_OP_3D_W<<5, H_OP_3D_H<<5, 255, 255, 255, 255, },


    /* スイッチ */
    	{ H_OP_SWITCH_X1, H_OP_SWITCH_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_SWITCH_X2, H_OP_SWITCH_Y1, 0, 0, H_OP_SWITCH_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_SWITCH_X1, H_OP_SWITCH_Y2, 0, 0, 0, H_OP_SWITCH_H<<5, 255, 255, 255, 255, },
	{ H_OP_SWITCH_X2, H_OP_SWITCH_Y2, 0, 0, H_OP_SWITCH_W<<5, H_OP_SWITCH_H<<5, 255, 255, 255, 255, },


    /* ホールド */
    	{ H_OP_HOLD_X1, H_OP_HOLD_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_HOLD_X2, H_OP_HOLD_Y1, 0, 0, H_OP_HOLD_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_HOLD_X1, H_OP_HOLD_Y2, 0, 0, 0, H_OP_HOLD_H<<5, 255, 255, 255, 255, },
	{ H_OP_HOLD_X2, H_OP_HOLD_Y2, 0, 0, H_OP_HOLD_W<<5, H_OP_HOLD_H<<5, 255, 255, 255, 255, },


    /* コントラスト */
    	{ H_OP_CONTRAST_X1, H_OP_CONTRAST_Y1, 0, 0,
	  0, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST_X2, H_OP_CONTRAST_Y1, 0, 0,
	  H_OP_CONTRAST_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST_X1, H_OP_CONTRAST_Y2, 0, 0,
	  0, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },
	{ H_OP_CONTRAST_X2, H_OP_CONTRAST_Y2, 0, 0,
	  H_OP_CONTRAST_W<<5, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },

    /* コントラスト２ */
    	{ H_OP_CONTRAST2_X1, H_OP_CONTRAST2_Y1, 0, 0,
	  0, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST2_X2, H_OP_CONTRAST2_Y1, 0, 0,
	  H_OP_CONTRAST_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST2_X1, H_OP_CONTRAST2_Y2, 0, 0,
	  0, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },
	{ H_OP_CONTRAST2_X2, H_OP_CONTRAST2_Y2, 0, 0,
	  H_OP_CONTRAST_W<<5, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },
};

Vtx_t menu_option_line[ OP_LINE_VTX_SUU ] = {
    /* ＬＩＮＥ */
    	{ H_OP_LINE_X1, H_OP_LINE_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_LINE_X2, H_OP_LINE_Y1, 0, 0, H_OP_LINE_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_LINE_X1, H_OP_LINE_Y2, 0, 0, 0, H_OP_LINE_H<<5, 255, 255, 255, 255, },
	{ H_OP_LINE_X2, H_OP_LINE_Y2, 0, 0, H_OP_LINE_W<<5, H_OP_LINE_H<<5, 255, 255, 255, 255, },

    /* ＬＩＮＥ２ */
    	{ H_OP_LINE2_X1, H_OP_LINE2_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_LINE2_X2, H_OP_LINE2_Y1, 0, 0, H_OP_LINE_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_LINE2_X1, H_OP_LINE2_Y2, 0, 0, 0, H_OP_LINE_H<<5, 255, 255, 255, 255, },
	{ H_OP_LINE2_X2, H_OP_LINE2_Y2, 0, 0, H_OP_LINE_W<<5, H_OP_LINE_H<<5, 255, 255, 255, 255, },

    /* ＬＩＮＥ３ */
    	{ H_OP_LINE3_X1, H_OP_LINE3_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_LINE3_X2, H_OP_LINE3_Y1, 0, 0, H_OP_LINE_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_LINE3_X1, H_OP_LINE3_Y2, 0, 0, 0, H_OP_LINE_H<<5, 255, 255, 255, 255, },
	{ H_OP_LINE3_X2, H_OP_LINE3_Y2, 0, 0, H_OP_LINE_W<<5, H_OP_LINE_H<<5, 255, 255, 255, 255, },

};


#else

Vtx_t menu_option_titlevtx[] = {
    /* タイトル（ＯＰＴＩＯＮ）*/
    	{  -94,  72,  0,  0,      0,      0,  255, 255, 255, 255, },
	{   34,  72,  0,  0, 128<<5,      0,  255, 255, 255, 255, },
	{  -94,  56,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{   34,  56,  0,  0, 128<<5,  16<<5,  255, 255, 255, 255, },


    /* プレート（ＳＯＵＮＤ）*/
    	{ -100,  44,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  -36,  44,  0,  0,  64<<5,      0,  255, 255, 255, 255, },
	{ -100,  28,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{  -36,  28,  0,  0,  64<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（モノラル）*/
    	{ -100,  26,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  -52,  26,  0,  0,  48<<5,      0,  255, 255, 255, 255, },
	{ -100,  10,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{  -52,  10,  0,  0,  48<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（ステレオ）*/
    	{  -48,  26,  0,  0,      0,      0,  255, 255, 255, 255, },
	{    0,  26,  0,  0,  48<<5,      0,  255, 255, 255, 255, },
	{  -48,  10,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{    0,  10,  0,  0,  48<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（ヘッドホン）*/
    	{    4,  26,  0,  0,      0,      0,  255, 255, 255, 255, },
	{   52,  26,  0,  0,  48<<5,      0,  255, 255, 255, 255, },
	{    4,  10,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{   52,  10,  0,  0,  48<<5,  16<<5,  255, 255, 255, 255, },

    /* プレート（３Ｄ）*/
    	{   56,  26,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  104,  26,  0,  0,  48<<5,      0,  255, 255, 255, 255, },
	{   56,  10,  0,  0,      0,  16<<5,  255, 255, 255, 255, },
	{  104,  10,  0,  0,  48<<5,  16<<5,  255, 255, 255, 255, },


    /* ＬＩＮＥ */
    	{ -100,  28,  0,  0,      0,      0,  255, 255, 255, 255, },
	{  156,  28,  0,  0, 256<<5,      0,  255, 255, 255, 255, },
	{ -100,  26,  0,  0,      0,   2<<5,  255, 255, 255, 255, },
	{  156,  26,  0,  0, 256<<5,   2<<5,  255, 255, 255, 255, },


    /* ＬＩＮＥ２ */
    	{ H_OP_LINE2_X1, H_OP_LINE2_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_LINE2_X2, H_OP_LINE2_Y1, 0, 0, H_OP_LINE_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_LINE2_X1, H_OP_LINE2_Y2, 0, 0, 0, H_OP_LINE_H<<5, 255, 255, 255, 255, },
	{ H_OP_LINE2_X2, H_OP_LINE2_Y2, 0, 0, H_OP_LINE_W<<5, H_OP_LINE_H<<5, 255, 255, 255, 255, },



/* ここから ＶＴＸ データの ３３個目 */


    /* Ｚ注目タイプ */
    	{ H_OP_Z_X1, H_OP_Z_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_Z_X2, H_OP_Z_Y1, 0, 0, H_OP_Z_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_Z_X1, H_OP_Z_Y2, 0, 0, 0, H_OP_Z_H<<5, 255, 255, 255, 255, },
	{ H_OP_Z_X2, H_OP_Z_Y2, 0, 0, H_OP_Z_W<<5, H_OP_Z_H<<5, 255, 255, 255, 255, },


    /* スイッチ */
    	{ H_OP_SWITCH_X1, H_OP_SWITCH_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_SWITCH_X2, H_OP_SWITCH_Y1, 0, 0, H_OP_SWITCH_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_SWITCH_X1, H_OP_SWITCH_Y2, 0, 0, 0, H_OP_SWITCH_H<<5, 255, 255, 255, 255, },
	{ H_OP_SWITCH_X2, H_OP_SWITCH_Y2, 0, 0, H_OP_SWITCH_W<<5, H_OP_SWITCH_H<<5, 255, 255, 255, 255, },


    /* ホールド */
    	{ H_OP_HOLD_X1, H_OP_HOLD_Y1, 0, 0, 0, 0, 255, 255, 255, 255, },
	{ H_OP_HOLD_X2, H_OP_HOLD_Y1, 0, 0, H_OP_HOLD_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_HOLD_X1, H_OP_HOLD_Y2, 0, 0, 0, H_OP_HOLD_H<<5, 255, 255, 255, 255, },
	{ H_OP_HOLD_X2, H_OP_HOLD_Y2, 0, 0, H_OP_HOLD_W<<5, H_OP_HOLD_H<<5, 255, 255, 255, 255, },


    /* コントラスト */
    	{ H_OP_CONTRAST_X1, H_OP_CONTRAST_Y1, 0, 0,
	  0, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST_X2, H_OP_CONTRAST_Y1, 0, 0,
	  H_OP_CONTRAST_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST_X1, H_OP_CONTRAST_Y2, 0, 0,
	  0, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },
	{ H_OP_CONTRAST_X2, H_OP_CONTRAST_Y2, 0, 0,
	  H_OP_CONTRAST_W<<5, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },


    /* コントラスト２ */
    	{ H_OP_CONTRAST2_X1, H_OP_CONTRAST2_Y1, 0, 0,
	  0, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST2_X2, H_OP_CONTRAST2_Y1, 0, 0,
	  H_OP_CONTRAST_W<<5, 0, 255, 255, 255, 255, },
	{ H_OP_CONTRAST2_X1, H_OP_CONTRAST2_Y2, 0, 0,
	  0, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },
	{ H_OP_CONTRAST2_X2, H_OP_CONTRAST2_Y2, 0, 0,
	  H_OP_CONTRAST_W<<5, H_OP_CONTRAST_H<<5, 255, 255, 255, 255, },
};

#endif





