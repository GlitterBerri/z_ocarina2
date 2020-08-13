/* $Id: z_file_choose.h,v 1.1.1.1 2003/03/10 22:42:55 tong Exp $ */	
/* $Log: z_file_choose.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:55  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.3  1998-11-02 17:59:13+09  soejima
 * ＰＡＬ
 *
 * Revision 2.2  1998-10-29 21:07:04+09  soejima
 * ＰＡＬ
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.41  1998/09/23 11:14:56  soejima
 * *** empty log message ***
 *
 * Revision 1.40  1998-09-22 22:24:15+09  soejima
 * *** empty log message ***
 *
 * Revision 1.39  1998-09-21 15:35:02+09  soejima
 * *** empty log message ***
 *
 * Revision 1.38  1998-09-19 18:27:26+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/05/29  07:53:46  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_FILE_CHOOSE_H
#define INCLUDE_Z_FILE_CHOOSE_H


#include "z_kankyo.h"
#include "z_sram.h"
#include "z_vr_box.h"


/************************************************************************
 *
 *	ＦＩＬＥ ＣＨＯＯＳＥ
 *
 ************************************************************************/
#define Buf_Ct   	(128/8)

#if defined(PAL_VERSION)
/* ＰＡＬ版用 */
typedef struct {
    Game	g;		/* 基底クラス */

    Vtx_t	*frameVtx;	/* フレーム */


    char	*staticSegment;		/* スタティックセグメントポインタ */
    char	*parameterSegment;	/* 常駐バンクセグメントポインタ   */
    char	*titleSegment;		/* ＰＡＬ追加：タイトルバンクセグメントポインタ   */


    View	view;			/* ビュワークラス */
    Sram	sram;			/* ＳＲＡＭ クラス */
    Vr_box	vr_box;			/* ＶＲ＿ＢＯＸ クラス */
    Message	message;		/* メッセージ クラス */
    Kanfont	kanfont;		/* 文字 クラス */
    Kankyo	kankyo;			/* 環境 クラス */


    Vtx_t	*titleVtx;		/* タイトルＶｔｘ */
    Vtx_t	*selectVtx;		/* ファイル選択画面Ｖｔｘ */
    Vtx_t	*characterVtx;		/* 名前登録用文字Ｖｔｘ（ひらがな・カタカナ・英数）*/
    Vtx_t	*cursorVtx;		/* 名前Ｖｔｘ（名前プレート・名前・カーソル）*/
    
    unchar	flag_64dd;	/* ６４ＤＤメディアフラグ */

    unshort	save[3];	/* ＳＡＶＥ回数 */
    unchar	name[3][8];	/* 登録名前 */
    unshort	life[3];	/* 最大Ｌｉｆｅ数 */
    long	item[3];	/* 集めた精霊石/封印 */
    short	f_64dd[3];	/* ６４ＤＤフラグ */
    signed char heart_status[3]; /* ハート制御 */
    unshort	now_life[3];	/* ＰＡＬ追加：現在Ｌｉｆｅ数 */


    short	no;		/* 伝説の書選択ｎｏ．
				 *（０〜２:ファイル, ３：コピー, ４：消す）
				 */
    short	yes_no;		/* はい/いいえ */

    short	mode;		/* ＭＡＩＮポインタ
				 * ０：タイトル表示
				 * １：メイン メニュー
				 * ２：選択決定
				 */

    short	menu_pos;	/* メニュー ポインタ
				 * ０：ファイル選択
				 * １：Ｃｏｐｙ（どれをコピーしますか？）
				 * ２：        （どこにコピーしますか？）
				 * ３：        （本当にコピーしますか？）
				 * ４：        （コピーが終了しました）
				 * ５：Ｄｅｌ（どれを消しますか？）
				 * ６：      （本当に消しますか？）
				 * ７：      （消去しました）
				 * ８：名前登録
				 * ９：名前登録へ
				 *１０：ファイル選択へ
				 */

    short	menu_pos_old;	/* 現在のメニュー ポインタ */
    short	menu_pos_next;	/* 次のメニュー ポインタ */
    

    short	decision_mode;	/* 選択決定モード */
    short	decision_no;	/* 選択決定ポインタ */
    short	decision_no1;	/* 選択決定ポインタ */
    short	decision_ypd[3]; /* 選択決定 ＹＰＯＳ */

    short	cpdl_mct;	/* コピー/消す 移動カウンタ */
    short	cpdl_yp[6];	/* コピー/消す ＹＰＯＳ */
    short	copy_no;	/* コピー先ポインタ */

    short	caution_no;	/* 注意書きＮＯ. */
    short	caution_pt;	/* 注意書きポインタ */

    short	title_no0;		/* 表面タイトルＮｏ. */
    short	title_no1;		/* 裏面タイトルＮｏ. */
    short	frame_rgb[3];		/* 選択面ＲＧＢ */

    short	frame_title_alpha[2];	/* 選択面タイトルアルファ値 */
    short	base_alpha;		/* 土台フレームアルファ値 */
    short	file_alpha[3];		/* 選択ファイルＮｏ．アルファ値 */
    short	plate_alpha[3];		/* 選択ファイル名前プレートアルファ値 */
    short	name_alpha[3];		/* 選択ファイル名前アルファ値 */
    short	connect_alpha[3];	/* 選択ファイルコネクタ─アルファ値 */
    short	decision_alpha[3];	/* 選択決定パネルアルファ値 */
    short	panel_alpha[4];		/*（コピー/消す）（はい/やめる）パネルアルファ値 */
    short	option_alpha;		/*（オプション）パネルアルファ値 */
    short	name_plate_alpha;	/* 名前登録パネルアルファ値 */
    short	ab_alpha;		/* ＡＢボタン説明パネルアルファ値 */
    short	caution_alpha;		/* 注意書きパネルアルファ値 */

    short	cursor_rgba[4];		/* カーソルＲＧＢＡ */
    short	cursor_pt;		/* カーソルポインタ */
    short	cursor_ct;		/* カーソルカウンタ */
    short	panel_pt[2];		/* パネルポインタ */

    short	key_wait_x, key_wait_y;
    short	old_key_x, old_key_y;
    short	wkey_x, wkey_y;
    short	shift_xp;
    short	scroll_xp;


    /* 名前登録 */
    float	goto_angle;		/* 選択画面／名前登録画面 ＡＮＧＬＥ値 */
    short	name_contents;		/* 名前登録目次 */
    short	name_page;		/* 名前登録入替（０：ひらがな,
					                 １：カタカナ,
					                 ２：英数,
					                 ３：ひらがな→カタカナ,
					                 ４：カタカナ→ひらがな,
					                 ５：ひらがな→英数,
					                 ６：英数→ひらがな,
					                 ７：カタカナ→英数,
					                 ８：英数→カタカナ） */
    short	page_alpha;		/* 名前登録ページカラー */
    short	mjp;
    short	name_xpos;		/* 名前登録文字ポインター */
    short	name_ypos;		/* 名前登録文字ポインター */
    short	name_index;		/* 名前登録文字インデックス */

    short	sub_menu_alpha[5];
} Game_file_choose;
#else
/* ＮＴＳＣ版用 */
typedef struct {
    Game	g;		/* 基底クラス */

    Vtx_t	*frameVtx;	/* フレーム */


    char	*staticSegment;		/* スタティックセグメントポインタ */
    char	*parameterSegment;	/* 常駐バンクセグメントポインタ   */


    View	view;			/* ビュワークラス */
    Sram	sram;			/* ＳＲＡＭ クラス */
    Vr_box	vr_box;			/* ＶＲ＿ＢＯＸ クラス */
    Message	message;		/* メッセージ クラス */
    Kanfont	kanfont;		/* 文字 クラス */
    Kankyo	kankyo;			/* 環境 クラス */


    Vtx_t	*titleVtx;		/* タイトルＶｔｘ */
    Vtx_t	*selectVtx;		/* ファイル選択画面Ｖｔｘ */
    Vtx_t	*characterVtx;		/* 名前登録用文字Ｖｔｘ（ひらがな・カタカナ・英数）*/
    Vtx_t	*cursorVtx;		/* 名前Ｖｔｘ（名前プレート・名前・カーソル）*/
    
    unchar	flag_64dd;	/* ６４ＤＤメディアフラグ */

    unshort	save[3];	/* ＳＡＶＥ回数 */
    unchar	name[3][8];	/* 登録名前 */
    unshort	life[3];	/* 最大Ｌｉｆｅ数 */
    long	item[3];	/* 集めた精霊石/封印 */
    short	f_64dd[3];	/* ６４ＤＤフラグ */
    signed char heart_status[3]; /* ハート制御 */


    short	no;		/* 伝説の書選択ｎｏ．
				 *（０〜２:ファイル, ３：コピー, ４：消す）
				 */
    short	yes_no;		/* はい/いいえ */

    short	mode;		/* ＭＡＩＮポインタ
				 * ０：タイトル表示
				 * １：メイン メニュー
				 * ２：選択決定
				 */

    short	menu_pos;	/* メニュー ポインタ
				 * ０：ファイル選択
				 * １：Ｃｏｐｙ（どれをコピーしますか？）
				 * ２：        （どこにコピーしますか？）
				 * ３：        （本当にコピーしますか？）
				 * ４：        （コピーが終了しました）
				 * ５：Ｄｅｌ（どれを消しますか？）
				 * ６：      （本当に消しますか？）
				 * ７：      （消去しました）
				 * ８：名前登録
				 * ９：名前登録へ
				 *１０：ファイル選択へ
				 */

    short	menu_pos_old;	/* 現在のメニュー ポインタ */
    short	menu_pos_next;	/* 次のメニュー ポインタ */
    

    short	decision_mode;	/* 選択決定モード */
    short	decision_no;	/* 選択決定ポインタ */
    short	decision_no1;	/* 選択決定ポインタ */
    short	decision_ypd[3]; /* 選択決定 ＹＰＯＳ */

    short	cpdl_mct;	/* コピー/消す 移動カウンタ */
    short	cpdl_yp[6];	/* コピー/消す ＹＰＯＳ */
    short	copy_no;	/* コピー先ポインタ */

    short	caution_no;	/* 注意書きＮＯ. */
    short	caution_pt;	/* 注意書きポインタ */

    short	title_no0;		/* 表面タイトルＮｏ. */
    short	title_no1;		/* 裏面タイトルＮｏ. */
    short	frame_rgb[3];		/* 選択面ＲＧＢ */

    short	frame_title_alpha[2];	/* 選択面タイトルアルファ値 */
    short	base_alpha;		/* 土台フレームアルファ値 */
    short	file_alpha[3];		/* 選択ファイルＮｏ．アルファ値 */
    short	plate_alpha[3];		/* 選択ファイル名前プレートアルファ値 */
    short	name_alpha[3];		/* 選択ファイル名前アルファ値 */
    short	connect_alpha[3];	/* 選択ファイルコネクタ─アルファ値 */
    short	decision_alpha[3];	/* 選択決定パネルアルファ値 */
    short	panel_alpha[4];		/*（コピー/消す）（はい/やめる）パネルアルファ値 */
    short	option_alpha;		/*（オプション）パネルアルファ値 */
    short	name_plate_alpha;	/* 名前登録パネルアルファ値 */
    short	ab_alpha;		/* ＡＢボタン説明パネルアルファ値 */
    short	caution_alpha;		/* 注意書きパネルアルファ値 */

    short	cursor_rgba[4];		/* カーソルＲＧＢＡ */
    short	cursor_pt;		/* カーソルポインタ */
    short	cursor_ct;		/* カーソルカウンタ */
    short	panel_pt[2];		/* パネルポインタ */

    short	key_wait_x, key_wait_y;
    short	old_key_x, old_key_y;
    short	wkey_x, wkey_y;
    short	shift_xp;
    short	scroll_xp;


    /* 名前登録 */
    float	goto_angle;		/* 選択画面／名前登録画面 ＡＮＧＬＥ値 */
    short	name_contents;		/* 名前登録目次 */
    short	name_page;		/* 名前登録入替（０：ひらがな,
					                 １：カタカナ,
					                 ２：英数,
					                 ３：ひらがな→カタカナ,
					                 ４：カタカナ→ひらがな,
					                 ５：ひらがな→英数,
					                 ６：英数→ひらがな,
					                 ７：カタカナ→英数,
					                 ８：英数→カタカナ） */
    short	page_alpha;		/* 名前登録ページカラー */
    short	mjp;
    short	name_xpos;		/* 名前登録文字ポインター */
    short	name_ypos;		/* 名前登録文字ポインター */
    short	name_index;		/* 名前登録文字インデックス */

    short	sub_menu_alpha[5];
    
# if 0
    /** Ｅ３メニュー用 **/
    short	sub_menu_alpha[5];
    short	sub_no;
    short	sub_menu_cnt;
# endif
} Game_file_choose;
#endif




/*==============================================================*/
extern void
file_choose_cleanup( Game *thisx );

extern void
file_choose_init( Game *thisx );
/*==============================================================*/



#endif

/*** z_file_choose.h end ***/

