/* $Id: z_message.h,v 2.1 1998/10/22 12:17:25 zelda Exp $ */	
/* $Log: z_message.h,v $
 * Revision 2.1  1998/10/22  12:17:25  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.73  1998/10/05 01:02:09  zelda
 * *** empty log message ***
 *
 * Revision 1.72  1998-10-03 23:07:09+09  hayakawa
 * メッセージテーブルポインタ初期化
 *
 * Revision 1.71  1998-10-03 23:00:27+09  soejima
 * *** empty log message ***
 *
 * Revision 1.70  1998-10-03 18:00:57+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.69  1998-09-19 18:29:13+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/11/07  00:10:43  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_MESSAGE_H_H
#define INCLUDE_Z_MESSAGE_H_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_actor_h.h"
#include "z_kanfont.h"


/************************************************************************
 *									*
 *	ＭＥＳＳＡＧＥ							*
 *				1996年11月05日(火曜日) 10時30分00秒 	*
 ************************************************************************/
typedef struct zelda_message_struct {
    View	view;			/* カメラ ビュー */

    Kanfont	kanfont;		/* 文字 クラス 			*/

    char	*fukidashiSegment;	/* 吹き出しセグメント */
    char	*textuteSegment;	/* テクスチャセグメント */


    NA_OCARINA_PLAY_INFO	*info;	/* オカリナ */
    
    
    dma_t	dma;			/* メモリ転送関係 */
    OSMesgQueue	mq;			/*		  */
    OSMesg	m;			/*	  	  */


    unsigned short	msgno;			/* 現在表示メッセージＮＯ． */
    unsigned short	sel_msgno;		/* 選択メッセージＮＯ． */
    unsigned char 	msg_disp_type;		/* 表示Ｔｙｐｅ */
    unsigned char 	msg_disp_type0;		/* 表示吹き出しＴｙｐｅ */
    unsigned char 	msg_disp_type1;		/* 表示位置Ｔｙｐｅ */
    unsigned char  	*msg_data;		/* メッセージ アドレス */

    unsigned char	msg_mode;		/* 表示 */
    union {
	unsigned short	msg_buff[100];		/* 表示用読み込みバッファ */
	unsigned char	nes_msg_b[200];		/* 表示用読み込みバッファ */
    } msg_b;
    unsigned short  	rdp;			/* バッファＲＥＡＤポインタ */
    unsigned short  	ldp;			/* バッファＬＯＡＤポインタ */
    unsigned short  	end;			/* バッファＬＯＡＤ-ＥＮＤポインタ */
    unsigned short  	rd_end;			/* バッファＬＯＡＤ-ＥＮＤポインタ */
    unsigned short	nonono_fg;		/* 早送り禁止フラグ */

    short	mxp, myp;		/* メッセージ表示位置 */
    short	color_r;
    short	color_g;
    short	color_b;
    short	color_a;		/* 表示文字カラー */


    unsigned char	select;			/* 選択モード */
    unsigned char	sel_pnt;		/* 選択 */

    unsigned char	item_dp;		/* アイテム表示中フラグ */


    char	wct;			/* ウィンドウ カウンター */

    unsigned short	mspd;			// メッセージ表示スピード
    unsigned short	tspd;			//                       原本

    unsigned short	ocarina;		// オカリナ演奏番号
    unsigned short	ocarina_mode;		// オカリナモード
    unsigned short	ocarina_no;		// オカリナ自動演奏番号
    unsigned short	chk_ocarina_no;		// チェックオカリナ演奏番号
    unsigned short	sun_song;		// ”太陽の歌”フラグ

    unsigned short	mes_board;		/* メッセージボードＮＯ．*/
    unsigned char	mes_board_prim;		/*                 ＰＲＩＭカラー */
    unsigned char	mes_board_shadow;	/*                 影カラー */
    unsigned char	mes_board_shift;	/*                 シフト値 */
    unsigned char	mes_board_anime;	/*                 アニメーション */
    

    short	fukidashi_no;		// 吹き出しポインタ（０：通常
                                        //		     １：立て札
    					//                   ２：ナレーション
    					//		     ３：オカリナ
    short	fc_r, fc_g, fc_b, fc_a;	// 吹き出しカラー（ＲＧＢＡ）
    short	fc_alpha;		/* 吹き出しａｌｐｈａ */
    
    Actor	*talk_actor;		/* 会話相手のＡｃｔｏｒポインタ */

    short	warp_flg;		/* ＷＡＲＰ許可フラグ（０＝ＯＫ, ０≒ダメ）*/
    short	sunmoon_flg;		/* 太陽の歌許可フラグ（０＝ＯＫ, ０≒ダメ）*/

    unsigned char	frame_cfg;	/*  */
} Message;



/* コンストラクト */
extern void
message_ct( Game_play *game_play );

/* メッセージＤＲＡＷ */
extern void
message_draw( Game_play *game_play );

/* メッセージＭＯＶＥ */
extern void
message_move( Game_play *game_play );

/* メッセージテーブルポインタ初期化 */
extern void message_tbl_p_init(void);




#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_message_h.h end ***/
