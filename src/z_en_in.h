/* $Id: z_en_in.h,v 2.1 1998-10-22 21:13:45+09 zelda Exp $
 * $Log: z_en_in.h,v $
 * Revision 2.1  1998-10-22 21:13:45+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.23  1998/10/13 13:53:06  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.22  1998-09-19 11:11:39+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.21  1998-09-01 16:48:11+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.20  1998-07-28 22:30:30+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.19  1998-07-02 22:10:15+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.18  1998-07-01 18:23:53+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.17  1998-06-30 23:46:40+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.16  1998-06-29 14:44:06+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.15  1998-06-26 22:40:38+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.14  1998-06-25 17:04:04+10  sumiyosi
 * とりあえず、つながりました。
 *
 * Revision 1.13  1998-06-25 00:25:32+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.12  1998-06-23 20:43:47+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.11  1998-06-20 23:54:38+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.10  1998-06-11 10:42:26+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.9  1998-06-05 23:20:48+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.8  1998-06-03 20:38:00+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.7  1998-05-11 23:44:52+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.6  1998/05/08 14:03:36  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.5  1998/04/30 13:52:49  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.4  1998/04/14 11:26:45  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.3  1998/03/26 10:56:17  yoshida
 * 標準的な処理を追加
 *
 * Revision 1.2  1998/03/18  13:48:22  yoshida
 * インゴー追加
 *
 * Revision 1.1  1998/03/18  10:01:58  yoshida
 * Initial revision
 *
 * Revision 1.2  1998/03/17  00:49:43  sasaki
 * *** empty log message ***
 *
 * Revision 1.1  1998/03/13  07:59:56  sasaki
 * Initial revision
 *
 * Revision 1.3  1998/02/09  14:03:16  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.2  1998/01/22  09:37:20  sumiyosi
 * 当り判定つけてみました…。
 *
 * Revision 1.1  1998/01/20  08:01:20  sumiyosi
 * Initial revision
 *
 *
 * */

/*-----------------------------------------------------------------------
 *
 * z_en_in.h
 * インゴー（ロンロン牧場乗っ取り野郎）
 * Program:ZULENKO
 * 1998/03/13 (Fri)
 *
 *----------------------------------------------------------------------*/
#ifndef INCLUDE_Z_EN_IN_H
#define INCLUDE_Z_EN_IN_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*-----------------------------------------------------------------------
 *
 *	各パーツの名称
 *
 *----------------------------------------------------------------------*/
enum {
    IN_DUMMY,
    CENTER,
    IN_LASI1,
    IN_LASI2,
    IN_LASI3_XX,
    IN_RASI1,
    IN_RASI2,
    IN_RASI3_XX,
    IN_KOSI,
    IN_MUNE,
    IN_LTE1,
    IN_LTE2,
    IN_LTE3,
    IN_RTE1,
    IN_RTE2,
    IN_RTE3,
    IN_ATAMA_XX,
    IN_LMAYU_XX,
    IN_RMAYU_XX,
    IN_HIGE_XX,
    IN_PARTS_MAX
};

/*-----------------------------------------------------------------------
 *
 *	インゴークラス
 *
 *----------------------------------------------------------------------*/
typedef struct En_In_actor_s {
    Actor actor;			/* 基底クラス			*/
    Skeleton_Info skeleton;	/* スケルトンシェイプクラス	*/
					/* 処理関数ポインタ		*/
    void (*process)(struct En_In_actor_s *,Game_play *);
    ClObjPipe all_pipe;		/* コリジョンデータ		*/
    float play_flame;
    signed char bankID;		/* 金持ちシェイプ	*/
    short anim_ID;
    short anim_id;
    short timer;			/* 自由に使ってタイマー		*/
    short snd_timer;			/* 自由に使ってタイマー		*/
    short count;			/* 自由に使ってカウンタ		*/
    short camera_no;
    short active_no;
    int	timer_set;
    short mesck_now;
    short mesck_old;
    short mesck_cnt;
    
    s_xyz		joint[ 2][IN_PARTS_MAX];
    xyz_t way;
    xyz_t eye;
    NpcBasicAct npcbasic;	/* 実験ネ！	*/

    s_xyz pw_work[IN_PARTS_MAX];	/* プログラムウェイト領域	*/
    
} En_In_Actor;

/*-----------------------------------------------------------------------
 *
 *	プロフィール
 *
 *----------------------------------------------------------------------*/
extern Actor_profile En_In_Profile;

/*-----------------------------------------------------------------------
 *
 *	☆  馬イベントにまつわるエトセトラ  ☆
 *
 *----------------------------------------------------------------------*/
#define SetContinueRace	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x8000)|(1<<15)))
#define ClrContinueRace	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x8000)))
#define ChkContinueRace (EVENT_INF( 0)&0x8000)

#define SetInRaceSeq(n)	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x000F)|(n% 16)))
#define InRaceSeq	(EVENT_INF( 0)&0x000F)
#define SetHorseType(n)	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x0010)|(n<< 4)))
#define HorseType	((EVENT_INF( 0)&0x0010)>> 4)
#define SetIn_Win	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x0020)|(1<< 5)))
#define ClrIn_Win	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x0020)))
#define In_WinChk	(EVENT_INF( 0)&0x0020)
#define SetIn_Los	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x0040)|(1<< 6)))
#define ClrIn_Los	(EVENT_INF( 0) =(EVENT_INF( 0)&(~0x0040)))
#define In_LosChk	(EVENT_INF( 0)&0x0040)
#define SetHorseRideExp	(SetInfo079)
#define ClrHorseRideExp	(SetInfo079)
#define ChkHorseRideExp	(GetInfo079)

enum{
    SCENE_1,	/* お客待ち		*/
    SCENE_2,	/* 体験乗馬		*/
    SCENE_3,	/* レース中		*/
    SCENE_4,	/* インゴー勝ち		*/
    SCENE_5,	/* インゴー負け  １回目	*/
    SCENE_6,	/* インゴー負け	 ２回目	*/
    SCENE_7,	/* 錯乱			*/
    SCENE_8	/* 再戦待ち		*/
};

/*-----------------------------------------------------------------------
 *
 *	☆  扉閉じデモにまつわるエトセトラ  ☆
 *
 *----------------------------------------------------------------------*/
#define DEMO_SWAY_X	(0.0f)		/* 始点・カメラ way.x	*/
#define DEMO_SWAY_Y	(50.0f)		/* 始点・カメラ way.y	*/
#define DEMO_SWAY_Z	(0.0f)		/* 始点・カメラ way.z	*/
#define DEMO_SEYE_X	(0.0f)		/* 始点・カメラ eye.x	*/
#define DEMO_SEYE_Y	(50.0f)		/* 始点・カメラ eye.y	*/
#define DEMO_SEYE_Z	(50.0f)		/* 始点・カメラ eye.z	*/

#define DEMO_EWAY_X	(0.0f)		/* 終点・カメラ way.x	*/
#define DEMO_EWAY_Y	(DEMO_SWAY_Y+  0.0f)
/* 終点・カメラ way.y	*/

#define DEMO_EWAY_Z	(0.0f)		/* 終点・カメラ way.z	*/
#define DEMO_EEYE_X	(0.0f)		/* 終点・カメラ eye.x	*/
#define DEMO_EEYE_Y	(DEMO_SEYE_Y+100.0f)
/* 終点・カメラ eye.y	*/

#define DEMO_EEYE_Z	(300.0f)	/* 終点・カメラ eye.z	*/

#define DEMO_OPNF	(10)		/* 門開き始めフレーム	*/
#define DEMO_ENDF	(50)		/* デモ終了フレーム	*/
#define DEMO_DOOR_SPD	(400)		/* 扉閉まるスピード	*/
#define DEMO_DOOR_LMT	(16384)		/* 扉可動範囲		*/

enum{
    DUMMY,	/* ダミー	*/
    SIGOTO,	/* 仕事		*/
    HORSE_RACE,	/* 馬イベント	*/
    NERU,	/* 寝る		*/
    PEKOPEKO	/* 改心		*/
};

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
/*** z_en_in.h ***/
