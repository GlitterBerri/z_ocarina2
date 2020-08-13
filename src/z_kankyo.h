/* $Id: z_kankyo.h,v 1.1.1.1 2003/03/10 22:42:55 tong Exp $ */	
/* $Log: z_kankyo.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:55  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.70  1998/10/14 15:26:11  sasaki
 * *** empty log message ***
 *
 * Revision 1.69  1998-10-14 14:19:24+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.68  1998-10-13 23:43:53+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.67  1998-10-13 00:29:50+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.66  1998-10-10 22:46:56+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.65  1998-10-08 11:27:55+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.64  1998-10-01 21:59:22+09  sasaki
 * define	TIME_SPEED
 *
 * Revision 1.63  1998-09-26 00:06:25+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.62  1998-09-17 22:56:31+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.61  1998/09/15 15:23:10  sasaki
 * *** empty log message ***
 *
 * Revision 1.60  1998/09/11 12:45:52  sasaki
 * time define add
 *
 * Revision 1.59  1998/09/05 05:08:15  sasaki
 * define add
 *
 * Revision 1.58  1998/09/03 11:38:38  sasaki
 * *** empty log message ***
 *
 * Revision 1.57  1998/09/01 12:13:15  sasaki
 * *** empty log message ***
 *
 * Revision 1.56  1998/09/01 02:05:23  sasaki
 * define add
 *
 * Revision 1.55  1998/08/27 15:03:56  sasaki
 * add
 *
 * Revision 1.54  1998/08/21 01:59:17  komatu
 * *** empty log message ***
 *
 * Revision 1.53  1998-08-21 10:55:54+09  nisiwaki
 * extern 宣言をした
 *
 * Revision 1.52  1998-08-20 13:41:32+09  hayakawa
 * vr_kakusiのプロトタイプを追加
 * extern 関数、変数はヘッダで宣言してください。
 *
 * Revision 1.51  1998-08-18 23:17:51+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.50  1998/08/13 02:08:40  soejima
 * define
 *
 * Revision 1.49  1998-07-24 14:48:31+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.48  1998/07/24 05:03:56  sasaki
 * *** empty log message ***
 *
 * Revision 1.47  1998/07/22 08:27:11  sasaki
 * *** empty log message ***
 *
 * Revision 1.46  1998/07/02 12:04:04  nisiwaki
 * set_add_light_global を 追加
 *
 * Revision 1.45  1998-05-28 22:31:48+09  sasaki
 * *** empty log message ***
 *
 * Revision 1.44  1998/05/15 06:24:20  hayakawa
 * *** empty log message ***
 *
 * Revision 1.43  1998-05-15 14:38:10+09  hayakawa
 * エラー撲滅キャンペーン中につき勝手に直しておきました。
 * 関数プロトタイプの登録をしました
 *
 * Revision 1.42  1998-03-23 11:21:01+09  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.41  1998/02/23  13:29:02  sasaki
 * *** empty log message ***
 *
 * Revision 1.40  1998/02/03  11:04:07  sasaki
 * *** empty log message ***
 *
 * Revision 1.39  1997/12/01  13:59:09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.38  1997/12/01  12:05:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.37  1997/12/01  07:37:32  sasaki
 * *** empty log message ***
 *
 *
 * Revision 1.13  1997/03/25  12:09:42  soejima
 * ZELDATIMEのＳＴＯＰ
 *
 * Revision 1.12  1997/02/26  11:22:11  soejima
 * z_message_h.h を z_message.h に変更
 *
 * Revision 1.11  1997/02/06  04:47:47  soejima
 * z_kscope.hを、z_kaleido_scope.hに変更。
 *
 * Revision 1.10  1996/12/16  06:48:41  soejima
 * ポーズによるZELDATIMEのＳＴＯＰ
 *
 * Revision 1.7  1996/10/21  12:20:43  sasaki
 * kankyo test
 *
 * $Log追加
 * */

#ifndef INCLUDE_Z_KANKYO_H
#define INCLUDE_Z_KANKYO_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_kaleido_scope.h"
#include "z_message.h"
#include "z_gameover.h"
#include "z_vr_box.h"

/************************************************************************
 *
 *	環境
 *
 ************************************************************************/
/*-----------------------------------------------------------------------

  時間	値
  00    0x0000      05    0x3556      10    0x6aab      15    0xa000      20    0xd556
  01	0x0aab      06    0x4000      11    0x7556	16    0xaaab	  21	0xe000
  02	0x1556      07    0x4aab      12    0x8001	17    0xb556	  22	0xeaab
  03	0x2001      08    0x5556      13    0x8aac	18    0xc001	  23	0xf556
  04	0x2aac      09    0x6000      14    0x9556	19    0xcaac	  24	0x0000

*------------------------------------------------------------------------*/

#define	MORNING_TIME		0x4555		/* 朝 */
#define	NIGHT_TIME		0xc001		/* 夜 */
#define	TIME_00			0x0000		/* ジャスト   ０時（深夜） */
#define	TIME_01			0x0aab		/* ジャスト   １時	   */
#define	TIME_02			0x1556		/* ジャスト   ２時	   */
#define	TIME_03			0x2001		/* ジャスト   ３時	   */
#define	TIME_04			0x2aac		/* ジャスト   ４時	   */
#define	TIME_05			0x3556		/* ジャスト   ５時	   */
#define	TIME_06			0x4000		/* ジャスト   ６時	   */
#define	TIME_07			0x4aab		/* ジャスト   ７時	   */
#define	TIME_08			0x5556		/* ジャスト   ８時	   */
#define	TIME_09			0x6000		/* ジャスト   ９時	   */
#define	TIME_10			0x6aab		/* ジャスト １０時	   */
#define	TIME_11			0x7556		/* ジャスト １１時	   */
#define	TIME_12			0x8001		/* ジャスト １２時（お昼） */
#define	TIME_13			0x8aac		/* ジャスト １３時	   */
#define	TIME_14			0x9556		/* ジャスト １４時	   */
#define	TIME_15			0xa000		/* ジャスト １５時	   */
#define	TIME_16			0xaaab		/* ジャスト １６時	   */
#define	TIME_17			0xb556		/* ジャスト １７時	   */
#define	TIME_18			0xc001		/* ジャスト １８時	   */
#define	TIME_19			0xcaac		/* ジャスト １９時	   */
#define	TIME_20			0xd556		/* ジャスト ２０時	   */
#define	TIME_21			0xe000		/* ジャスト ２１時	   */
#define	TIME_22			0xeaab		/* ジャスト ２２時	   */
#define	TIME_23			0xf556		/* ジャスト ２３時	   */

#define	TIME_06_30		0x4555		/* ６時３０分		   */
#define	TIME_07_15		0x4d55		/* ７時１５分		   */
#define	TIME_07_30		0x5000		/* ７時３０分		   */


/************************************************************************
 *
 *	環境クラス
 *
 ************************************************************************/
typedef struct {
    unsigned char	ambient_col[RGB_NUM];	/* アンビエントライトカラー   */
    signed   char	parallel_pos[3];	/* diffuse ポジション         */
    unsigned char	parallel_col[RGB_NUM];	/*         ライトカラー       */
    signed   char	parallel2_pos[3];	/*         ポジション         */
    unsigned char	parallel2_col[RGB_NUM];	/*         ライトカラー       */
    unsigned char	fog_col[RGB_NUM];	/* フォグカラー 	      */
    short		fog_near;		/* フォグ 近さ		      */
    short		fog_far;		/* フォグ 奥行き	      */
} Light_info;

/*----------------------------------------------------------------------------*/
#if 0		/* 7/30 cut	*/
typedef struct {
    Light_info		*light_info_asa;	/* 環境ライト情報  （朝）	*/
    Light_info		*light_info_hiru;	/* 		   （昼）	*/
    Light_info		*light_info_yuu;	/* 		   （夕）	*/
    Light_info		*light_info_yoru;	/* 		   （夜）	*/
} Kankyo_daylight;
#endif
/*----------------------------------------------------------------------------*/

typedef struct {
    signed short	ambient_col[RGB_NUM];	/* アンビエントライトカラー   */
    signed short	diffuse_col[RGB_NUM];	/* ディフューズライトカラー   */
    signed short	fog_col[RGB_NUM];	/* フォグカラー 	      */
    short		fog_near;		/*       近さ		      */
    short		fog_far;		/*       奥行き		      */
} Add_light;

typedef struct
{
    unsigned short	day_time;		/* １日の流れ			*/
    unsigned short	day_time_plus;		/*		加算値		*/

    float		sun_pos_x;		/* 太陽の位置	Ｘ		*/ 
    float		sun_pos_y;		/* 太陽の位置	Ｙ		*/
    float		sun_pos_z;		/* 太陽の位置	Ｚ		*/

    unsigned char	vrbox_tenso_0;		/* 転送用			*/
    unsigned char	vrbox_tenso_1;		/*				*/
    unsigned char	vrbox_tenso_cnt;	/*				*/

    unsigned char	vr_box_scale;		/*          変化率		*/

    unsigned char	vr_box_sw;		/* VR_BOX種別			*/
    unsigned char	vr_box_dsp;		/* VR_BOX表示フラグ		*/
    unsigned char	sunmoon_dsp;		/* 太陽と月表示フラグ		*/
    unsigned char	vr_box_pat;		/* VR_BOX切替方式		*/
    unsigned char	vr_eve_pat;		/* イベント変更用 VR_BOX	*/
    unsigned char	mode;			/* イベント実行判定スイッチ	*/
    unsigned short	patchg_time;		/* 天候変化補間タイマー		*/
    unsigned short	patchg_time_max;	/* 天候変化補間タイマー最大値	*/

    unsigned char	kcolor_sw;		/* 環境色選択			*/
    unsigned char	kcolor_pat;		/* 環境色切替方式		*/
    unsigned char	kcolor_eve_pat;		/* イベント変更用環境カラー	*/
    unsigned char	mode2;			/* イベント実行判定スイッチ2	*/
    unsigned short	patchg_time2;		/* 天候変化補間タイマー2	*/
    unsigned short	patchg_time2_max;	/* 天候変化補間タイマー2最大値	*/

    unsigned char	diffuse_pat;		/* ディフュースライト位置タイプ	*/
    Light_data		sun_light;		/* 太陽光			*/
    Light_data		sun_light2;		/* 太陽光(反対)			*/

    signed char		read_flag;		/* 新規読み込みフラグ		*/

    dma_t		dma;			/* メモリ転送関係		*/
    OSMesgQueue		mq;			/*				*/
    OSMesg		m;			/*				*/

    float		all_fade_wk;		/* レンズフレアフェードワーク	*/
    float		naiseki_wk;		/* 				*/

    Add_light		add_light;		/* 画面効果用ライト加算値	*/
    float		add_light_pst;		/* 画面効果用ライト影響率	*/

    s_xyz		wind_direction;		/* 風の吹く方向			*/
    float		wind_speed;		/* 風の吹く強さ			*/

    char		num;			/* カラーデータ設定個数（マップごとの）	*/
    Light_info		*data;			/* 	           領域			*/

    unsigned char	colfirst_flg;		/* そのシーンでのカラー設定 初回	*/
    unsigned char	polcolor;		/* ポリゴンから取得したカラー番号	*/
    unsigned char	polcolor_bak;		/* ポリゴンから取得したカラー番号BACKUP	*/

    char		custom_flg;		/* 最優先 色変換用 スイッチ		*/
    Light_info		custom_col;		/* 最優先 環境色			*/
    unsigned short	custom_speed;		/* スピード				*/
    float		custom_parcent;		/* 変化率				*/
    unsigned char	custom_blend_flg;	/* 変化率固定フラグ			*/

    unsigned char	rain_evt_trg;		/* 雨発生フラグ				*/
    unsigned char	rain_evt_mode;		/* 雨発生中処理モード			*/

    unsigned char	thunder_evt_trg;	/* 雷発生フラグ				*/
    unsigned char	sound_status;		/* 音楽変化ステータス			*/

    unsigned char	rect_pattern;		/* レクトアングルの表示位置設定		*/
    unsigned char	rectcol_[4];		/* レクトアングルの色  RGBA		*/

    unsigned char	sandstorm_mode;		/* 砂嵐 				*/
    unsigned char	sstorm_prima;		/*			  		*/
    unsigned char	sstorm_enva;		/*			  		*/

    unsigned char	vr_rect_pat;		/* ＶＲ前レクトアングルの表示設定	*/
    unsigned char	vr_rectcol[4];		/* ＶＲ前レクトアングルの色  RGBA	*/

    unsigned char	wether_work[8];		/* 天候タグ用ワーク			*/
    unsigned char	fade_work[4];		/* フェード用ワーク			*/
} Kankyo;

/*-----------------------------------------------------------------------
 *
 *	「もののけ姫に出てくる木霊のような物」
 *
 *----------------------------------------------------------------------*/
typedef struct
{
    char		mode;		/* 処理モード	*/
    xyz_t		direction;	/* 今回出力位置	*/
    xyz_t		direction_old;	/* 前回出力位置	*/
    xyz_t		kihon;		/*     基本位置	*/
    float		sin_cnt_x;	/* サイン移動用	*/
    float		sin_cnt_y;	/*		*/
    float		sin_cnt_z;	/*		*/
    float		speed;		/*     移動速度	*/
    float		speed_target;	/* 目標移動速度	*/
    unsigned short	timer;		/* タイマー	*/
    unsigned short	kaiten;		/* 		*/
    unsigned char	alpha;
    float		scale;
    unsigned short	kspeed;
    unsigned short	khaba;
    float		sinpuku;
    unsigned short	waittimer;
} MONONOKE;

/*-----------------------------------------------------------------------
 *
 *	「かみなりさま」
 *
 *----------------------------------------------------------------------*/
typedef struct
{
    char		mode;		/* 処理モード	*/
    xyz_t		direction;	/* 出力位置	*/
    xyz_t		kihon;		/* 基本位置	*/
    signed char		r_x;		/* 		*/
    signed char		r_z;		/* 		*/
    unsigned char	anmcnt;		/* 		*/
    unsigned char	timer;		/* 		*/
} THUNDER;

/*------------------------------------------------------------------------------*
 *										*
 *	エレクトリックサンダー							*
 *										*
 *------------------------------------------------------------------------------*/
typedef struct {
    unsigned char	electric_proc;	/* アンビエントライトカラー   */
    unsigned char	rect_red;
    unsigned char	rect_green;
    unsigned char	rect_blue;
    unsigned char	rect_alpha;
    float		timer;
} ELEKI;

/*-----------------------------------------------------------------------
 *
 *	「火山岩 落下」
 *
 *----------------------------------------------------------------------*/
typedef struct
{
    char	mode;		/* 処理モード	*/
    xyz_t	direction;	/* 出力位置	*/
    xyz_t	old_direction;	/* 出力位置	*/
    xyz_t	kihon;		/* 基本位置	*/
    float	sin_cnt;
    float	speed;
} KAZAN;

/*-----------------------------------------------------------------------
 *
 *	「環境データ用」
 *
 *----------------------------------------------------------------------*/
typedef struct
{
    unsigned short	start_time;		/* 開始時間			*/
    unsigned short	end_time;		/* 終了時間			*/
    unsigned char	kankyo_pat;		/* 環境ライト設定値		*/
    unsigned char	kankyo_pat2;		/* 				*/
} KLIGHT_CHG;

typedef struct
{
    unsigned short	start_time;		/* 開始時間			*/
    unsigned short	end_time;		/* 終了時間			*/
    unsigned char	ovr_sw;			/* オーバーラップするのかフラグ	*/
    unsigned char	vrbox_dsp;		/* VR_BOX  種類			*/
    unsigned char	vrbox_dsp2;		/* VR_BOX2 種類			*/
    unsigned char	tenso_sw;		/* 転送用ワーク			*/
} VRBOX_CHG;

typedef struct
{
						/* テキスチャーデータ		*/
    u32			start_adr;		/* 開始アドレス			*/
    u32			end_adr;		/* 終了アドレス			*/

						/* パレットデータ		*/
    u32			p_start_adr;		/* 開始アドレス			*/
    u32			p_end_adr;		/* 終了アドレス			*/
} VRBOX_TENSO;

/************************************************************************
 *
 *	関数宣言
 *
 ************************************************************************/
extern void Global_kankyo_ct( Game *game,
			      Kankyo *this,
			      unsigned short daytime );

extern void Global_kankyo_set( Game_play	*gplay,
			       Kankyo		*this,
			       Global_light	*this3,
			       Kscope		*this4,
			       Message		*this5,
			       Gover		*this6,
			       Graph		*graph );

extern void water_in_kankyo( Game_play *, int );
extern void set_add_light_global(Game_play *,float ,float,float,float );
extern int Get_Eventday( void );
extern int Get_Totalday( void );
extern void Clr_Eventday( void );
extern void Nottori_Bgm( u16 );
extern char Nottori_Bgmoff_check( void );
extern void vr_kakusi( Game_play *game_play );
extern float get_parcent(unsigned short ,unsigned short ,unsigned short );
extern float get_parcent_forAccelBrake(unsigned short end_frame_us,
				       unsigned short start_frame_us,
				       unsigned short now_frame_us,
				       unsigned short accel_between_us,
				       unsigned short brake_between_us);
extern void		stagemusic_play( Game_play *game_play );
extern void Rain_sound_set_on( Game_play *game_play );
extern void Rain_sound_set_off( Game_play *game_play );
extern void OcaWarpJumpProc( Game_play *game_play );
extern void Kankyo_vrbox_change( unsigned char vr_box_flag, Kankyo *this, Vr_box *this2 );

extern VRBOX_CHG	vrbox_chg[4][9];
extern VRBOX_TENSO	vrbox_tenso[];

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

extern unsigned char	DEMOCAM_SW;
extern unsigned char	E_wether_flg;
extern unsigned char    E_water_colbak;
extern unsigned char	E_wether_apl;
extern unsigned char	E_vr_box_ovl;
extern unsigned short	E_day_time_plus;

/* #define	TIME_SPEED	REG(15)*/		/* 時間経過速度		   */
#define	TIME_SPEED	E_day_time_plus		/* 時間経過速度		   */

#endif
/*** z_kankyo.h end ***/
