/*
 * $Id: z_demo.h,v 2.1 1998/10/22 11:45:49 zelda Exp $
 *
 * デモ
 *
 * $Log: z_demo.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.16  1998/10/15 06:54:15  hayakawa
 * *** empty log message ***
 *
 * Revision 1.15  1998-10-15 14:32:50+09  hayakawa
 * set_showdata追加
 *
 * Revision 1.14  1998-09-24 00:08:14+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.13  1998-08-18 23:05:27+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.12  1998/03/18 03:05:43  ogawa
 * *** empty log message ***
 *
 * Revision 1.11  1998/02/24  09:23:54  sasaki
 * *** empty log message ***
 *
 * Revision 1.10  1998/02/19  09:19:32  sasaki
 * *** empty log message ***
 *
 * Revision 1.9  1997/12/22  08:26:15  sasaki
 * *** empty log message ***
 *
 * Revision 1.8  1997/12/17  01:39:22  sasaki
 * *** empty log message ***
 *
 * Revision 1.7  1997/11/07  11:58:59  sasaki
 * *** empty log message ***
 *
 * Revision 1.6  1997/11/06  12:14:38  sasaki
 * *** empty log message ***
 *
 * Revision 1.5  1997/10/23  09:51:04  sasaki
 * *** empty log message ***
 *
 * Revision 1.4  1997/10/22  14:45:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1997/10/08  06:36:20  sasaki
 * *** empty log message ***
 *
 * Revision 1.2  1997/10/01  12:54:48  sasaki
 * *** empty log message ***
 *
 * Revision 1.1  1997/08/29  04:40:54  iwawaki
 * Initial revision
 * */

#ifndef INCLUDE_Z_DEMO_H
#define INCLUDE_Z_DEMO_H
#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	デモ
 *
 ************************************************************************/
#include "z_play_h.h"
#include "camdemo.h"


/************************************************************************
 *
 *	デモ データ構造体
 *
 ************************************************************************/
typedef struct {
    unsigned short	dousa;		/* 動作			*/
    unsigned short	start_flame;	/* スタートのフレーム	*/
    unsigned short	goal_flame;	/* ゴールのフレーム	*/

    unsigned short	x_angle;	/* Ｘの角度		*/
    unsigned short	y_angle;	/* Ｙの角度		*/
    unsigned short	z_angle;	/* Ｚの角度		*/

    unsigned long	x_pos_start;	/* Ｘのスタート位置	*/
    unsigned long	y_pos_start;	/* Ｙのスタート位置	*/
    unsigned long	z_pos_start;	/* Ｚのスタート位置	*/

    unsigned long	x_pos_goal;	/* Ｘのゴール位置	*/
    unsigned long	y_pos_goal;	/* Ｙのゴール位置	*/
    unsigned long	z_pos_goal;	/* Ｚのゴール位置	*/

    unsigned long	x_speed;	/* Ｘのスピード		*/
    unsigned long	y_speed;	/* Ｙのスピード		*/
    unsigned long	z_speed;	/* Ｚのスピード		*/
}DEMO_SEQ_TBL;

typedef struct {
    unsigned short	dousa;		/* 動作			*/
    unsigned short	start_flame;	/* スタートのフレーム	*/
    unsigned short	goal_flame;	/* ゴールのフレーム	*/
}CAMERA_DEMO_TBL;

typedef struct {
    unsigned short	dousa;		/* 動作			*/
    unsigned short	start_flame;	/* スタートのフレーム	*/
    unsigned short	goal_flame;	/* ゴールのフレーム	*/
}DEMO_KANKYO_TBL;

typedef struct {
    unsigned short	dousa;		/* 動作				*/
    unsigned short	start_flame;	/* スタートのフレーム		*/
    unsigned short	goal_flame;	/* ゴールのフレーム		*/
    unsigned short	code;		/* コード			*/
    unsigned short	mes_no1;	/* 選択メッセージ（上側）	*/
    unsigned short	mes_no2;	/* コード			*/
}DEMO_MESSAGE_TBL;

typedef struct {
    unsigned short	dousa;		/* 動作				*/
    unsigned short	start_flame;	/* スタートのフレーム		*/
    unsigned short	goal_flame;	/* ゴールのフレーム		*/
    unsigned char	data01;		/*				*/
    unsigned char	data02;		/*				*/
    unsigned char	data03;		/* 				*/
    unsigned char	data04;		/* 				*/
    unsigned char	data05;		/* 				*/
    unsigned char	data06;		/* 				*/
}DEMO_INPUT_TBL;

/************************************************************************
 *
 *	デモクラス
 *
 ************************************************************************/
enum {
    DEMO_PLAY_MODE_NON,
    DEMO_PLAY_MODE_START,
    DEMO_PLAY_MODE_PROC,
    DEMO_PLAY_MODE_END,
    DEMO_PLAY_MODE_WAIT
};

#define NPCDEMPMAX	10

typedef struct {
    unsigned char	num;
    char		*data;

    unsigned char	mode;
    float		counter;
    unsigned short	flamecnt;
    unsigned short	demo_no;
    int			camera_ID;
    unsigned short	start_flame_bak;
    unsigned char	lookat_sw;		/* 設定したかな？フラグ	 みてる位置	*/
    unsigned char	camera_sw;		/*		   	 位置		*/
    SplinedatZ		*lookat_pos;		/* スプラインカメラ	 みてる位置	*/
    SplinedatZ		*camera_pos;		/*		   	 位置		*/

    DEMO_SEQ_TBL	*linkdemopnt;		/* リンク用	 デモデータポインタ	*/
    DEMO_SEQ_TBL	*npcdemopnt[NPCDEMPMAX];/* デモキャラ０用デモデータポインタ	*/
} Demo_play;

/*-----------------------------------------------------------------------
 *
 *	デモクラス コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Demo_play_ct(Game_play *game_play, Demo_play *this);

/*-----------------------------------------------------------------------
 *
 *	デモ開始セット
 *
 *----------------------------------------------------------------------*/
extern void Demo_play_start(Game_play *game_play, Demo_play *this);

/*-----------------------------------------------------------------------
 *
 *	デモ終了セット
 *
 *----------------------------------------------------------------------*/
extern void Demo_play_end(Game_play *game_play, Demo_play *this);

/*-----------------------------------------------------------------------
 *
 *	デモ処理
 *
 *----------------------------------------------------------------------*/
extern void Demo_play_move(Game_play *game_play, Demo_play *this);
extern void Tool_Demo_play_move(Game_play *game_play, Demo_play *this);

/*
 * デモデータポインタセット
 */
extern void set_showdata(Game_play *game_play, char *romdata);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_demo.h ***/



