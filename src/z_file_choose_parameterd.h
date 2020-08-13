/* $Id: z_file_choose_parameterd.h,v 1.1.1.1 2003/03/10 22:42:46 tong Exp $ */	
/* $Log: z_file_choose_parameterd.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:46  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.3  1998-11-02 17:59:32+09  soejima
 * ＰＡＬ
 *
 * Revision 2.2  1998-10-27 21:25:24+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.21  1998/09/22 13:24:43  soejima
 * *** empty log message ***
 *
 * Revision 1.20  1998-09-22 11:12:00+09  takahata
 * *** empty log message ***
 *
 * Revision 1.19  1998-09-18 23:04:34+09  soejima
 * *** empty log message ***
 *
 * Revision 1.18  1998-07-17 17:51:44+09  soejima
 * *** empty log message ***
 *
 * Revision 1.17  1998-07-10 22:49:49+09  soejima
 * *** empty log message ***
 *
 * Revision 1.16  1998-07-06 22:20:42+09  soejima
 * *** empty log message ***
 *
 * Revision 1.15  1998-07-04 11:16:40+09  soejima
 * *** empty log message ***
 *
 * Revision 1.14  1998-06-17 17:01:47+09  soejima
 * *** empty log message ***
 *
 * Revision 1.13  1998-06-11 15:59:09+09  soejima
 * Ｂ＿ＢＵＴＴＯＮ操作変更
 *
 * Revision 1.12  1998-03-03 19:40:40+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/09/18  10:50:08  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_FILE_CHOOSE_PARAMETERD_H
#define INCLUDE_Z_FILE_CHOOSE_PARAMETERD_DL_H

/************************************************************************
 *									*
 *	ＦＩＬＥ ＣＨＯＯＳＥ ディスプレイリスト			*
 *				1997年09月18日(木曜日) 18時45分00秒 JST *
 ************************************************************************/
#include "z_basic.h"


#if defined(PAL_VERSION)
/*=======================================================================
  =									=
  =======================================================================*/
/* shape/TEXTURE/TITLE/file_name : フレーム */
extern unsigned char ff_00_txt[];
extern unsigned char ff_01_txt[];
extern unsigned char ff_02_txt[];
extern unsigned char ff_03_txt[];
extern unsigned char ff_10_txt[];
extern unsigned char ff_11_txt[];
extern unsigned char ff_12_txt[];
extern unsigned char ff_13_txt[];
extern unsigned char ff_20_txt[];
extern unsigned char ff_21_txt[];
extern unsigned char ff_22_txt[];
extern unsigned char ff_23_txt[];
extern unsigned char ff_30_txt[];
extern unsigned char ff_31_txt[];
extern unsigned char ff_32_txt[];
extern unsigned char ff_33_txt[];
extern unsigned char ff_40_txt[];
extern unsigned char ff_41_txt[];
extern unsigned char ff_42_txt[];
extern unsigned char ff_43_txt[];


extern unsigned char h_op_line_txt[];		// ライン
extern unsigned char h_con_txt[];		// コネクタ
extern unsigned short h_file_64dd_txt[];	// ６４ＤＤ 

extern unsigned char h_file_cursor_txt[];	// ファイル選択画面用カーソル
extern unsigned char h_name_cursor1_txt[];	// 名前登録用カーソル１
extern unsigned char h_name_cursor2_txt[];	// 名前登録用カーソル２
extern unsigned char h_name_cursor3_txt[];	// 名前登録用カーソル３
extern unsigned short h_name2_1_txt[];		// 名前プレート（拡張１）
extern unsigned short h_name2_2_txt[];		// 名前プレート（拡張２）
extern unsigned short h_name2_3_txt[];		// 名前プレート（拡張３）
extern unsigned short h_name2_4_txt[];		// 名前プレート（拡張４）
extern unsigned short h_name2_5_txt[];		// 名前プレート（拡張５）

extern unsigned short h_n_hira_txt[];		// 『ひらがな』
extern unsigned short h_n_kata_txt[];		// 『カタカナ』
extern unsigned short h_n_eisu_txt[];		// 『英数』
extern unsigned short h_n_modo_txt[];		// 『戻る』
extern unsigned short h_name_txt[];		// 名前プレート

extern unsigned char h_file_jewel_1_txt[];	// 精霊石（コキリのヒスイ）
extern unsigned char h_file_jewel_2_txt[];	// 精霊石（ゴロンのルピー）
extern unsigned char h_file_jewel_3_txt[];	// 精霊石（ゾ─ラのサファイア）
extern unsigned char h_fileseal_1_txt[];	// 封印（風の封印）
extern unsigned char h_fileseal_2_txt[];	// 封印（炎の封印）
extern unsigned char h_fileseal_3_txt[];	// 封印（氷の封印）
extern unsigned char h_fileseal_4_txt[];	// 封印（魂の封印）
extern unsigned char h_fileseal_5_txt[];	// 封印（闇の封印）
extern unsigned char h_fileseal_6_txt[];	// 封印（光の封印）

extern unsigned char h_op_english_e_txt[];
extern unsigned char h_op_german_g_txt[];
extern unsigned char h_op_french_f_txt[];
extern unsigned char h_op_sound_e_txt[];
extern unsigned char h_op_sound_f_txt[];
extern unsigned char h_op_z_e_txt[];
extern unsigned char h_op_z_g_txt[];
extern unsigned char h_op_z_f_txt[];
extern unsigned char h_op_sample_e_txt[];
extern unsigned char h_op_sample_g_txt[];
extern unsigned char h_op_sample_f_txt[];
extern unsigned char h_op_language_e_txt[];
extern unsigned char h_op_language_g_txt[];
extern unsigned char h_op_language_f_txt[];
extern unsigned char h_op_stereo_e_txt[];	// 『ステレオ』
extern unsigned char h_op_stereo_f_txt[];	// 『ステレオ』
extern unsigned char h_op_mono_e_txt[];		// 『モノラル』
extern unsigned char h_op_headphones_e_txt[];	// 『ヘッドホン』
extern unsigned char h_op_headphones_g_txt[];	// 『ヘッドホン』
extern unsigned char h_op_headphones_f_txt[];	// 『ヘッドホン』
extern unsigned char h_op_3d_e_txt[];		/* 『ステレオ』 */
extern unsigned char h_op_switch_e_txt[];	/* 『スイッチ』 */
extern unsigned char h_op_switch_g_txt[];	/* 『スイッチ』 */
extern unsigned char h_op_switch_f_txt[];	/* 『スイッチ』 */
extern unsigned char h_op_hold_e_txt[];		/* 『ホールド』 */
extern unsigned char h_op_hold_g_txt[];		/* 『ホールド』 */
extern unsigned char h_op_hold_f_txt[];		/* 『ホールド』 */

/*
 *
 *  ＮＥＳ用
 *
 */
extern unsigned char h_caution_1_nes_txt[];	// 『コピーするファイルがありません』
extern unsigned char h_caution_2_nes_txt[];	// 『消すファイルがありません』
extern unsigned char h_caution_3_nes_txt[];	// 『ファイルの空きがありません』
extern unsigned char h_caution_4_nes_txt[];	// 『これは空ファイルです』
extern unsigned char h_caution_5_nes_txt[];	// 『これは使用しています』
extern unsigned char h_mes_copy_1_nes_txt[];	// 『どれをコピーしますか？』
extern unsigned char h_mes_copy_2_nes_txt[];	// 『どこにコピーしますか？』
extern unsigned char h_mes_copy_2_5_nes_txt[];	// 『本当にコピーしますか？』
extern unsigned char h_mes_copy_3_nes_txt[];	// 『コピーが終了しました』
extern unsigned char h_mes_file_nes_txt[];	// 『ファイルをえらんでください』
extern unsigned char h_mes_file2_nes_txt[];	// 『ファイルを開きますか？』
extern unsigned char h_mes_kesu_1_nes_txt[];	// 『どれを消しますか？』
extern unsigned char h_mes_kesu_2_nes_txt[];	// 『本当に消しますか？』
extern unsigned char h_mes_kesu_3_nes_txt[];	// 『消去しました』
extern unsigned char h_mes_option_nes_txt[];	// 『オプション』
extern unsigned char h_namae_nes_txt[];		// 『名前入力』
extern unsigned short h_copy_nes_txt[];		// 『コピー』
extern unsigned short h_file_1_nes_txt[];	// 『ファイル１』
extern unsigned short h_file_2_nes_txt[];	// 『ファイル２』
extern unsigned short h_file_3_nes_txt[];	// 『ファイル３』
extern unsigned short h_hai_nes_txt[];		// 『はい』
extern unsigned short h_kesu_nes_txt[];		// 『消す』
extern unsigned short h_option_nes_txt[];	// 『オプション』
extern unsigned short h_yameru_nes_txt[];	// 『やめる』
extern unsigned short h_file_ab_nes_txt[];	// ＡＢ説明
extern unsigned short h_n_kettei_txt[];		// 『決定』



/*
 *
 *  ＰＡＬ（ドイツ語）
 *
 */
extern unsigned char h_mes_option_g_txt[];	// 『オプション』
extern unsigned char h_caution_1_g_txt[];	// 『コピーするファイルがありません』
extern unsigned char h_caution_2_g_txt[];	// 『消すファイルがありません』
extern unsigned char h_caution_3_g_txt[];	// 『ファイルの空きがありません』
extern unsigned char h_caution_4_g_txt[];	// 『これは空ファイルです』
extern unsigned char h_caution_5_g_txt[];	// 『これは使用しています』
extern unsigned char h_mes_copy_1_g_txt[];	// 『どれをコピーしますか？』
extern unsigned char h_mes_copy_2_g_txt[];	// 『どこにコピーしますか？』
extern unsigned char h_mes_copy_2_5_g_txt[];	// 『本当にコピーしますか？』
extern unsigned char h_mes_copy_3_g_txt[];	// 『コピーが終了しました』
extern unsigned char h_mes_file_g_txt[];	// 『ファイルをえらんでください』
extern unsigned char h_mes_file2_g_txt[];	// 『ファイルを開きますか？』
extern unsigned char h_mes_kesu_1_g_txt[];	// 『どれを消しますか？』
extern unsigned char h_mes_kesu_2_g_txt[];	// 『本当に消しますか？』
extern unsigned char h_mes_kesu_3_g_txt[];	// 『消去しました』
extern unsigned short h_copy_g_txt[];		// 『コピー』
extern unsigned short h_file_1_g_txt[];		// 『ファイル１』
extern unsigned short h_file_2_g_txt[];		// 『ファイル２』
extern unsigned short h_file_3_g_txt[];		// 『ファイル３』
extern unsigned short h_hai_g_txt[];		// 『はい』
extern unsigned short h_kesu_g_txt[];		// 『消す』
extern unsigned short h_yameru_g_txt[];		// 『やめる』
extern unsigned short h_file_ab_g_txt[];	// ＡＢ説明
extern unsigned short h_n_kettei_g_txt[];	// 『決定』
extern unsigned short h_option_g_txt[];		// 『オプション』



/*
 *
 *  ＰＡＬ（フランス語）
 *
 */
extern unsigned char h_mes_option_f_txt[];	// 『オプション』
extern unsigned char h_caution_1_f_txt[];	// 『コピーするファイルがありません』
extern unsigned char h_caution_2_f_txt[];	// 『消すファイルがありません』
extern unsigned char h_caution_3_f_txt[];	// 『ファイルの空きがありません』
extern unsigned char h_caution_4_f_txt[];	// 『これは空ファイルです』
extern unsigned char h_caution_5_f_txt[];	// 『これは使用しています』
extern unsigned char h_mes_copy_1_f_txt[];	// 『どれをコピーしますか？』
extern unsigned char h_mes_copy_2_f_txt[];	// 『どこにコピーしますか？』
extern unsigned char h_mes_copy_2_5_f_txt[];	// 『本当にコピーしますか？』
extern unsigned char h_mes_copy_3_f_txt[];	// 『コピーが終了しました』
extern unsigned char h_mes_file_f_txt[];	// 『ファイルをえらんでください』
extern unsigned char h_mes_file2_f_txt[];	// 『ファイルを開きますか？』
extern unsigned char h_mes_kesu_1_f_txt[];	// 『どれを消しますか？』
extern unsigned char h_mes_kesu_2_f_txt[];	// 『本当に消しますか？』
extern unsigned char h_mes_kesu_3_f_txt[];	// 『消去しました』
extern unsigned short h_copy_f_txt[];		// 『コピー』
extern unsigned short h_file_1_f_txt[];		// 『ファイル１』
extern unsigned short h_file_2_f_txt[];		// 『ファイル２』
extern unsigned short h_file_3_f_txt[];		// 『ファイル３』
extern unsigned short h_hai_f_txt[];		// 『はい』
extern unsigned short h_kesu_f_txt[];		// 『消す』
extern unsigned short h_yameru_f_txt[];		// 『やめる』
extern unsigned short h_file_ab_f_txt[];	// ＡＢ説明
extern unsigned char h_namae_f_txt[];		// 『名前入力』
extern unsigned short h_n_kettei_f_txt[];	// 『決定』
#else
/*=======================================================================
  =									=
  =======================================================================*/
# if 0
/* /project/ZELDA/data/shape/zelda_title : タイトル */
extern unsigned char  g_title_txt[];
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
extern unsigned char  g_title_cpr_txt[];
extern unsigned char  g_title_mable_txt[];
# endif


/* shape/TEXTURE/TITLE/file_name : フレーム */
extern unsigned char ff_00_txt[];
extern unsigned char ff_01_txt[];
extern unsigned char ff_02_txt[];
extern unsigned char ff_03_txt[];
extern unsigned char ff_10_txt[];
extern unsigned char ff_11_txt[];
extern unsigned char ff_12_txt[];
extern unsigned char ff_13_txt[];
extern unsigned char ff_20_txt[];
extern unsigned char ff_21_txt[];
extern unsigned char ff_22_txt[];
extern unsigned char ff_23_txt[];
extern unsigned char ff_30_txt[];
extern unsigned char ff_31_txt[];
extern unsigned char ff_32_txt[];
extern unsigned char ff_33_txt[];
extern unsigned char ff_40_txt[];
extern unsigned char ff_41_txt[];
extern unsigned char ff_42_txt[];
extern unsigned char ff_43_txt[];




extern unsigned char h_mes_file_txt[];		// 『ファイルをえらんでください』
extern unsigned char h_mes_file2_txt[];		// 『ファイルを開きますか？』
extern unsigned char h_mes_copy_1_txt[];	// 『どれをコピーしますか？』
extern unsigned char h_mes_copy_2_txt[];	// 『どこにコピーしますか？』
extern unsigned char h_mes_copy_2_5_txt[];	// 『本当にコピーしますか？』
extern unsigned char h_mes_copy_3_txt[];	// 『コピーが終了しました』
extern unsigned char h_mes_kesu_1_txt[];	// 『どれを消しますか？』
extern unsigned char h_mes_kesu_2_txt[];	// 『本当に消しますか？』
extern unsigned char h_mes_kesu_3_txt[];	// 『消去しました』
extern unsigned char h_mes_option_txt[];	// 『オプション』
extern unsigned char h_op_sound_txt[];		// 『ＳＯＵＮＤ』
extern unsigned char h_op_headphones_txt[];	// 『ヘッドホン』
extern unsigned char h_op_mono_txt[];		// 『モノラル』
extern unsigned char h_op_stereo_txt[];		// 『３Ｄ』
extern unsigned char h_op_3d_txt[];		// 『ステレオ』
extern unsigned char h_op_line_txt[];		// ライン
extern unsigned short h_file_1_txt[];		// 『ファイル１』
extern unsigned short h_file_2_txt[];		// 『ファイル２』
extern unsigned short h_file_3_txt[];		// 『ファイル３』
extern unsigned short h_copy_txt[];		// 『コピー』
extern unsigned short h_kesu_txt[];		// 『消す』
extern unsigned short h_yameru_txt[];		// 『やめる』
extern unsigned short h_option_txt[];		// 『オプション』
extern unsigned short h_hai_txt[];		// 『はい』
extern unsigned short h_name_txt[];		// 名前プレート
extern unsigned short h_file_ab_txt[];		// ＡＢ説明
extern unsigned char h_con_txt[];		// コネクタ
extern unsigned short h_file_64dd_txt[];	// ６４ＤＤ 

extern unsigned char h_namae_txt[];		// 『名前入力』
extern unsigned short h_n_hira_txt[];		// 『ひらがな』
extern unsigned short h_n_kata_txt[];		// 『カタカナ』
extern unsigned short h_n_kettei_txt[];		// 『決定』
extern unsigned short h_n_eisu_txt[];		// 『英数』
extern unsigned short h_n_modo_txt[];		// 『戻る』

extern unsigned short h_name2_1_txt[];		// 名前プレート（拡張１）
extern unsigned short h_name2_2_txt[];		// 名前プレート（拡張２）
extern unsigned short h_name2_3_txt[];		// 名前プレート（拡張３）
extern unsigned short h_name2_4_txt[];		// 名前プレート（拡張４）
extern unsigned short h_name2_5_txt[];		// 名前プレート（拡張５）

extern unsigned char h_file_cursor_txt[];	// ファイル選択画面用カーソル
extern unsigned char h_file_save_txt[];		// セーブ回数ｘ
extern unsigned char h_name_cursor1_txt[];	// 名前登録用カーソル１
extern unsigned char h_name_cursor2_txt[];	// 名前登録用カーソル２
extern unsigned char h_name_cursor3_txt[];	// 名前登録用カーソル３

////////extern unsigned char h_ab_txt[];		// 『Ａボタンで決定・Ｂボタンで戻る』
extern unsigned char h_caution_1_txt[];		// 『コピーするファイルがありません』
extern unsigned char h_caution_2_txt[];		// 『消すファイルがありません』
extern unsigned char h_caution_3_txt[];		// 『ファイルの空きがありません』
extern unsigned char h_caution_4_txt[];		// 『これは空ファイルです』
extern unsigned char h_caution_5_txt[];		// 『これは使用しています』

extern unsigned char h_file_jewel_1_txt[];	// 精霊石（コキリのヒスイ）
extern unsigned char h_file_jewel_2_txt[];	// 精霊石（ゴロンのルピー）
extern unsigned char h_file_jewel_3_txt[];	// 精霊石（ゾ─ラのサファイア）
extern unsigned char h_fileseal_1_txt[];	// 封印（風の封印）
extern unsigned char h_fileseal_2_txt[];	// 封印（炎の封印）
extern unsigned char h_fileseal_3_txt[];	// 封印（氷の封印）
extern unsigned char h_fileseal_4_txt[];	// 封印（魂の封印）
extern unsigned char h_fileseal_5_txt[];	// 封印（闇の封印）
extern unsigned char h_fileseal_6_txt[];	// 封印（光の封印）



/*
 *
 *  ＮＥＳ用
 *
 */
extern unsigned char h_caution_1_nes_txt[];	// 『コピーするファイルがありません』
extern unsigned char h_caution_2_nes_txt[];	// 『消すファイルがありません』
extern unsigned char h_caution_3_nes_txt[];	// 『ファイルの空きがありません』
extern unsigned char h_caution_4_nes_txt[];	// 『これは空ファイルです』
extern unsigned char h_caution_5_nes_txt[];	// 『これは使用しています』
extern unsigned char h_mes_copy_1_nes_txt[];	// 『どれをコピーしますか？』
extern unsigned char h_mes_copy_2_nes_txt[];	// 『どこにコピーしますか？』
extern unsigned char h_mes_copy_2_5_nes_txt[];	// 『本当にコピーしますか？』
extern unsigned char h_mes_copy_3_nes_txt[];	// 『コピーが終了しました』
extern unsigned char h_mes_file_nes_txt[];	// 『ファイルをえらんでください』
extern unsigned char h_mes_file2_nes_txt[];	// 『ファイルを開きますか？』
extern unsigned char h_mes_kesu_1_nes_txt[];	// 『どれを消しますか？』
extern unsigned char h_mes_kesu_2_nes_txt[];	// 『本当に消しますか？』
extern unsigned char h_mes_kesu_3_nes_txt[];	// 『消去しました』
extern unsigned char h_mes_option_nes_txt[];	// 『オプション』
extern unsigned char h_namae_nes_txt[];		// 『名前入力』
extern unsigned char h_op_headphones_nes_txt[];	// 『ヘッドホン』
extern unsigned char h_op_mono_nes_txt[];	// 『モノラル』
extern unsigned char h_op_stereo_nes_txt[];	// 『ステレオ』
extern unsigned short h_copy_nes_txt[];		// 『コピー』
extern unsigned short h_file_1_nes_txt[];	// 『ファイル１』
extern unsigned short h_file_2_nes_txt[];	// 『ファイル２』
extern unsigned short h_file_3_nes_txt[];	// 『ファイル３』
extern unsigned short h_hai_nes_txt[];		// 『はい』
extern unsigned short h_kesu_nes_txt[];		// 『消す』
extern unsigned short h_option_nes_txt[];	// 『オプション』
extern unsigned short h_yameru_nes_txt[];	// 『やめる』
extern unsigned short h_file_ab_nes_txt[];	// ＡＢ説明
extern unsigned char h_file_save_nes_txt[];	// セーブ回数ｘ
extern unsigned char h_op_3d_nes_txt[];		/* 『ステレオ』 */
#endif

#endif

/*** z_file_choose_parameterd.h end ***/
