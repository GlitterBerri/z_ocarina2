/* $Id: z_scene.h,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $ */	
/* $Log: z_scene.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.2  1998/10/28  05:10:35  iwawaki
 * ＰＡＬ用
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.59  1998/07/30 14:18:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.58  1998-07-08 22:20:44+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/10/18  08:29:59  sasaki
 * Initial revision
 *
* */

#ifndef INCLUDE_Z_SCENE_H
#define INCLUDE_Z_SCENE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	シーン設定
 *
 ************************************************************************/
#include "z_scene_h.h"
#include "z_basic.h"
#include "z_play_h.h"
#include "z_bgcheck.h"
#include "z_kankyo.h"
#include "z_actor.h"

/*-----------------------------------------------------------------------
 *
 *	シーン設定コード
 *
 *----------------------------------------------------------------------*/
enum {
    SCENE_ID_PLAYER_PTR,
    SCENE_ID_ACTOR_PTR,
    SCENE_ID_CAMERA_DATA_PTR,
    SCENE_ID_BGCHECK_PTR,
    SCENE_ID_ROOM_ROM_ADDRESS_PTR,
    SCENE_ID_WIND_SET,
    SCENE_ID_ROOM_STATUS_PTR,
    SCENE_ID_EXCHANGE_KEEP_BANK,
    SCENE_ID_ROOM_TYPE,
    SCENE_ID_SOUND_TYPE,
    SCENE_ID_GROUND_SHAPE_STATUS_PTR,
    SCENE_ID_OBJECT_EXCHANGE_BANK_PTR,
    SCENE_ID_LIGHT_DATA_PTR,
    SCENE_ID_PATH_DATA_PTR,
    SCENE_ID_DOOR_DATA_PTR,
    SCENE_ID_KCOLOR_DATA_PTR,		/* 入れ替え新規 環境カラー設定				*/
    SCENE_ID_TIME_SET,			/* 入れ替え新規 時間設定！				*/
    SCENE_ID_KANKYO_SCENE_TYPE,
    SCENE_ID_KANKYO_ROOM_TYPE,
    SCENE_ID_NEXT_SCENE_PTR,
    SCENE_ID_END,
    SCENE_ID_SCENE_SOUND,
    SCENE_ID_ROOM_SOUND,
    SCENE_ID_DEMO_DATA_PTR,
    SCENE_ID_DEMO_SCENE_DATA_PTR,
    SCENE_ID_SCENE_TYPE
};

#define	Scene_ID_Player_Ptr(num, ptr)\
		{SCENE_ID_PLAYER_PTR, num, (unsigned int)ptr}			/* プレイヤーデータポインタ */
#define	Scene_ID_Actor_Ptr(num, ptr)\
		{SCENE_ID_ACTOR_PTR, num, (unsigned int)ptr}			/* アクターデータポインタ */	
#define	Scene_ID_Camera_Data_Ptr(num, ptr)\
		{SCENE_ID_CAMERA_DATA_PTR, num, (unsigned int)ptr}		/* カメラデータポインタ */	
#define	Scene_ID_BGcheck_Ptr(ptr)\
		{SCENE_ID_BGCHECK_PTR, 0, (unsigned int)ptr}			/* 地形チェックデータポインタ */
#define	Scene_ID_Room_Rom_Address_Ptr(num, ptr)\
		{SCENE_ID_ROOM_ROM_ADDRESS_PTR, num, (unsigned int)ptr}		/* 部屋データＲＯＭアドレスデータポインタ */
#define	Scene_ID_Wind_Set(ptr)\
		{SCENE_ID_WIND_SET, 0, (unsigned int)ptr}			/* 部屋データポインタ */
#define	Scene_ID_Room_Status_Ptr(ptr)\
		{SCENE_ID_ROOM_STATUS_PTR, 0, (unsigned int)ptr}		/* 部屋情報データポインタ */
#define	Scene_ID_Exchange_Keep_Bank(data)\
		{SCENE_ID_EXCHANGE_KEEP_BANK, 0, (unsigned int)data}		/* 入れ替え常駐データバンク */	
#define	Scene_ID_Exchange_Keep_Bank_Message(data1, data2)\
		{SCENE_ID_EXCHANGE_KEEP_BANK, data2, (unsigned int)data1}	/* 入れ替え常駐データバンク＆メッセージ */
#define	Scene_ID_Room_Type(data)\
		{SCENE_ID_ROOM_TYPE, data, 0}					/* 部屋タイプ */
#define	Scene_ID_Room_Type2(data1, data2)\
		{SCENE_ID_ROOM_TYPE, data1, (unsigned int)data2}		/* 部屋タイプ（気候設定） */
#define	Scene_ID_Room_Type3(data1, data2, data3)\
		{SCENE_ID_ROOM_TYPE, data1, (unsigned int)(data2 | ((data3)<<8))} /* 部屋タイプ（気候＆メガネ設定） */
#define	Scene_ID_Room_Type4(data1, data2, data3, data4)\
		{SCENE_ID_ROOM_TYPE, data1, (unsigned int)(data2 | ((data3)<<8) | ((data4)<<10))} /* 部屋タイプ（ワープ） */
#define	Scene_ID_Sound_Type(data)\
		{SCENE_ID_SOUND_TYPE, 0, (unsigned int)data}			/* サウンドタイプ */	
#define	Scene_ID_Ground_Shape_Status_Ptr(ptr)\
		{SCENE_ID_GROUND_SHAPE_STATUS_PTR, 0, (unsigned int)ptr}	/* 地形シェイプ情報データポインタ */	
#define	Scene_ID_Object_Exchange_Bank_Ptr(num, ptr)\
		{SCENE_ID_OBJECT_EXCHANGE_BANK_PTR, num, (unsigned int)ptr}	/* オブジェクトシェイプバンクデータポインタ */
#define	Scene_ID_Light_Data_Ptr(num, ptr)\
		{SCENE_ID_LIGHT_DATA_PTR, num, (unsigned int)ptr}		/* ライトデータポインタ */	
#define	Scene_ID_Path_Data_Ptr(ptr)\
		{SCENE_ID_PATH_DATA_PTR, 0, (unsigned int)ptr}			/* パスデータポインタ */	
#define	Scene_ID_Door_Data_Ptr(num, ptr)\
		{SCENE_ID_DOOR_DATA_PTR, num, (unsigned int)ptr}		/* ドアデータポインタ */	
#define	Scene_ID_Kcolor_Data_Ptr(num, ptr)\
                {SCENE_ID_KCOLOR_DATA_PTR, num, (unsigned int)ptr}		/* 環境カラーデータポインタ */	
#define	Scene_ID_Kankyo_Scene_Type( data1 )\
		{SCENE_ID_KANKYO_SCENE_TYPE, 0, (unsigned int)data1}		/* 環境タイプ	シーンごとの設定 */	
#define	Scene_ID_Kankyo_Room_Type( data1  )\
		{SCENE_ID_KANKYO_ROOM_TYPE,  0, (unsigned int)data1}		/* 環境タイプ	ルームごとの設定 */	
#define	Scene_ID_Time_Set( data1 )\
		{SCENE_ID_TIME_SET, 0, (unsigned int)data1}			/* 開始時間設定 */	
#define	Scene_ID_Next_Scene_Ptr(ptr)\
		{SCENE_ID_NEXT_SCENE_PTR, 0, (unsigned int)ptr}			/* 次のシーンデータポインタ */	
#define	Scene_ID_Scene_Sound(mode, BGM, env)\
		{SCENE_ID_SCENE_SOUND, mode, (unsigned int)((env<<8)|BGM)}	/* シーンサウンドメモリーモード，ＢＧＭ */
#define	Scene_ID_Room_Sound(type, echo)\
		{SCENE_ID_ROOM_SOUND, type, (unsigned int)echo}			/* 部屋サウンドエコーレベル（タイプは未定）*/
#define	Scene_ID_Demo_Data_Ptr(ptr)\
		{SCENE_ID_DEMO_DATA_PTR, 0, (unsigned int)ptr}			/* デモデータポインタ */
#define	Scene_ID_Demo_Scene_Data_Ptr(ptr)\
		{SCENE_ID_DEMO_SCENE_DATA_PTR, 0, (unsigned int)ptr}		/* デモシーンデータポインタ */
#define	Scene_ID_Scene_Type(data1, data2)\
		{SCENE_ID_SCENE_TYPE, data1, data2}			/* シーンＴＹＰＥ, ＡＲＥＡ */
#define	Scene_ID_End()\
		{SCENE_ID_END, 0, 0}						/* データＥＮＤ */			

/************************************************************************
 *
 *	カメラデータクラス
 *
 ************************************************************************/
#define	CAMERA_DATA_NORMAL_EYE_X	data[0]
#define	CAMERA_DATA_NORMAL_EYE_Y	data[1]
#define	CAMERA_DATA_NORMAL_EYE_Z	data[2]
#define	CAMERA_DATA_FIXED_CENTER_X	data[3]
#define	CAMERA_DATA_FIXED_CENTER_Y	data[4]
#define	CAMERA_DATA_FIXED_CENTER_Z	data[5]
#define	CAMERA_DATA_FIXED_FOBBY		data[6]

typedef struct {
    short	type;		/* 0:ノーマル 1:プリレンダーv1 2:プリレンダーv2 */
    short	data[7];
} Camera_data;
#if 0
typedef struct {
    long	type;		/* 0x0000-0x00ff:ノーマル 0x0100-0x01ff:プリレンダーfovy90 0x0200:プリレンダー */
    float	data[7];
} Camera_data_newtype;
typedef Camera_data_oldtype Camera_data;
//typedef Camera_data_newtype Camera_data;
#endif

/* プリレンダー用カメラデータマクロ（暫定）fovy=90固定 scaleでshortの範囲にスケーリングする */
#define CAMERA_DECL_PRERENDER_v1(mode, eyex, eyey, eyez, lookx, looky, lookz, fovy, scale) \
{mode, {(eyex)*(scale), (eyey)*(scale), (eyez)*(scale), (lookx)*(scale), (looky)*(scale), (lookz)*(scale), (scale)}}
#define CAMERA_DECL_PRERENDER_v2(mode, eyex, eyey, eyez, lookx, looky, lookz, fovy, scale) \
{mode, {(eyex)*(40.0), (eyey)*(40.0), (eyez)*(40.0), (lookx)*(40.0), (looky)*(40.0), (lookz)*(40.0), (fovy)*(40.0)}}
#define CAMERA_DECL_PRERENDER(mode, eyex, eyey, eyez, lookx, looky, lookz, fovy, scale) \
	CAMERA_DECL_PRERENDER_v##mode(mode, eyex, eyey, eyez, lookx, looky, lookz, fovy, scale)
    
/*-----------------------------------------------------------------------
 *
 *	パスデータ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	num;		/* データ数 */
    s_xyz		*data;		/* データポインタ */
} Path_Info;

/*-----------------------------------------------------------------------
 *
 *	サウンドデータ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	BGM;		/* ＢＧＭフラグ */
    unsigned char	environment;	/* 環境音フラグ */
    unsigned char	echo_level;	/* エコーレベル */
} Sound_Info;

/*-----------------------------------------------------------------------
 *
 *	部屋データＲＯＭアドレスデータ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	num;
    Rom_Address		*data;
} Room_Rom_Address;

/*-----------------------------------------------------------------------
 *
 *	部屋情報データ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	player_ID;
    unsigned char	room_ID;
} Room_Status;
typedef struct {
    unsigned char	num;
    Room_Status		*data;
} Room_Status_Info;

/*-----------------------------------------------------------------------
 *
 *	地形シェイプ情報データ
 *
 *----------------------------------------------------------------------*/
enum {
    GROUND_SHAPE_POLYGON,
    GROUND_SHAPE_PRERENDER,
    GROUND_SHAPE_POLYGON2
};

typedef struct {
    Gfx		*model[2];
} Shapes;
typedef struct {
    short	cx;
    short	cy;
    short	cz;
    short	r;
    Gfx		*model[2];
} Shapes2;
typedef struct {			/* ポリゴン地形シェイプ情報データ */
    unsigned char	type;
    unsigned char	num;
    Shapes		*shapes;
    unsigned char	*culling;
} Ground_Shape_Polygon;
typedef struct {			/* ポリゴン地形シェイプ情報データ */
    unsigned char	type;
    unsigned char	num;
    Shapes2		*shapes2;
    unsigned char	*culling;
} Ground_Shape_Polygon2;

typedef struct {		/* プリレンダ地形シェイプ情報データ */
    u8		type;		/* GROUND_SHAPE_PRERENDER */
    u8		version;	/* データフォーマットバージョン */
    u8		padding[2];
} Ground_Shape_PrerenderX;

#if 0
typedef struct {		/* プリレンダ地形シェイプ情報データ */
    unsigned char	type;
    unsigned short	*texture; /* プリレンダー画面テクスチャRGBA16 */
    unsigned short	*zbuffer; /* 対応するＺテクスチャ（オプション） */
    Shapes		*shapes; /* Ｚ作成用＆半透明地形用 */
    int 		width;	/* テクスチャ横幅 320 */
    int 		height;	/* テクスチャ高さ 240 */
} Ground_Shape_Prerender0;
#endif

typedef struct {		/* プリレンダ地形シェイプ情報データ */
    u8		type;		/* GROUND_SHAPE_PRERENDER */
    u8		version;	/* データフォーマットバージョン */
    u8		padding[2];
    
    Shapes	*shapes;	/* Ｚ作成用＆半透明地形用 */
    void	*texture;	/* プリレンダー画面テクスチャ */
    u16		*zbuffer;	/* !NULL:対応するＺテクスチャ（オプション） */
    u16		*tlut;		/* !NULL:パレットテーブル */
    u16 	width;		/* テクスチャ横幅 320 */
    u16 	height;		/* テクスチャ高さ 240 */
    u8		txlfmt;		/* G_IM_FMT_* */
    u8		txlsiz;		/* G_IM_SIZ_* */
    u16		tt;		/* G_TT_ */
    u16		pnum;		/* パレット数0-256 */
} Ground_Shape_Prerender1;
typedef Ground_Shape_Prerender1 Ground_Shape_Prerender;

typedef struct {		/* プリレンダ地形シェイプ情報データ */
    u8		padding1[2];
    u8		cam_id;		/* 対応するカメラＩＤ */
    u8		padding2[1];
    
    void	*texture;	/* プリレンダー画面テクスチャ */
    u16		*zbuffer;	/* !NULL:対応するＺテクスチャ（オプション） */
    u16		*tlut;		/* !NULL:パレットテーブル */
    u16 	width;		/* テクスチャ横幅 320 */
    u16 	height;		/* テクスチャ高さ 240 */
    u8		txlfmt;		/* G_IM_FMT_* */
    u8		txlsiz;		/* G_IM_SIZ_* */
    u16		tt;		/* G_TT_ */
    u16		pnum;		/* パレット数0-256 */
} Ground_Shape_Prerender2_sub;
typedef struct {		/* プリレンダ地形シェイプ情報データ */
    u8		type;		/* GROUND_SHAPE_PRERENDER */
    u8		version;	/* データフォーマットバージョン */
    u8		padding[2];
    
    Shapes	*shapes;	/* Ｚ作成用＆半透明地形用 */
    u8		sub_max;	/* サブデータテーブル数 */
    Ground_Shape_Prerender2_sub *sub; /* サブデータテーブル先頭ポインタ */
} Ground_Shape_Prerender2;

#define Ground_Shape_Prerender_decl_v0( _type_, _texture_, _zbuffer_, _shapes_, _width_, _height_ ) \
      { _type_, 1, _shapes_, _texture_, _zbuffer_, NULL, _width_, _height_, G_IM_FMT_RGBA, G_IM_SIZ_16b, G_TT_NONE, 0 }

#define Ground_Shape_Prerender_decl_v1( _shapes_, _texture_, _zbuffer_, _tlut_, _width_, _height_, _txlfmt_, _txlsiz_, _tt_, _pnum_ ) \
      { GROUND_SHAPE_PRERENDER, 1, 0, 0, _shapes_, _texture_, _zbuffer_, _tlut_, _width_, _height_, _txlfmt_, _txlsiz_, _tt_, _pnum_ }

#define Ground_Shape_Prerender2_sub_decl_v2( _camid_, _texture_, _zbuffer_, _tlut_, _width_, _height_, _txlfmt_, _txlsiz_, _tt_, _pnum_ ) \
      { 0, 2 + 128, _camid_, 0, _texture_, _zbuffer_, _tlut_, _width_, _height_, _txlfmt_, _txlsiz_, _tt_, _pnum_ }
#define Ground_Shape_Prerender2_decl_v2( _shapes_, _nums_, _tbls_ ) \
      { GROUND_SHAPE_PRERENDER, 2, 0, 0, _shapes_, _nums_, _tbls_ }

typedef union {
    Ground_Shape_Polygon	polygon;
    Ground_Shape_PrerenderX	prerender;
    Ground_Shape_Prerender1	prerender1;
    Ground_Shape_Prerender2	prerender2;
} Ground_Shape;

#ifndef PAL_VERSION	/* 日本 ＆ ＮＥＳ */
#define	OBJECT_EXCHANGE_BUFFER_SIZE	((200+200+150+100+300 +50)*1024)    /* 転送バッファサイズ（９５０Ｋ） */
#else			/* ＰＡＬ */
#define	OBJECT_EXCHANGE_BUFFER_SIZE	(((200+200+150+100+300 +50) - 4)*1024)    /* 転送バッファサイズ（９５０Ｋー４Ｋ） */
#endif
#define	OBJECT_EXCHANGE_BANK_MAX	(3+16)  			/* 最大バンク数 */

typedef struct {
    Object_Bank	bank;		/* 負数は読み込み中 */
    char	*Segment;
    dma_t	dma;
    OSMesgQueue	mq;
    OSMesg	m;
} Object_Exchange_Status;

typedef struct {
    char			*startSegment;
    char			*endSegment;
    unsigned char		num;
    unsigned char		keep_num;
    unsigned char		keep_ID;
    unsigned char		exchange_keep_ID;
    Object_Exchange_Status	status[OBJECT_EXCHANGE_BANK_MAX];
} Object_Exchange;

extern void Object_Exchange_ct(Game *game, Object_Exchange *this);
extern void Object_Exchange_check(Object_Exchange *this);
extern int  Object_Exchange_bank_check(Object_Exchange *this, Object_Bank bank);
extern int  Object_Exchange_bank_dma_check(Object_Exchange *this, int bank_ID);
extern void Object_Exchange_read_all(Object_Exchange *this);
extern char *Object_Exchange_change(Object_Exchange *this, int bank_ID, Object_Bank object_bank);


/*-----------------------------------------------------------------------
 *
 *	ドアデータ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    signed char		room_status_ID;
    signed char		camera_ID;
} Door_data_Status;
typedef struct {
    Door_data_Status	status[2];
    short		profile;
    s_xyz		position;
    short		angle_y;
    short		arg_data;
} Door_data;
typedef struct {
    unsigned char	num;
    Door_data		*data;
} Door_Info;

extern void Door_info_ct(Game *game, Door_Info *this);

/*-----------------------------------------------------------------------
 *
 *	妖精メッセージ
 *
 *----------------------------------------------------------------------*/
enum {
    Elf_Message_Non,
    Elf_Message_Field,
    Elf_Message_Ydan,
    Elf_Message_Max
};

/*=======================================================================*/
#if 0
/*-----------------------------------------------------------------------
 *
 *	フォグデータ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	r;
    unsigned char	g;
    unsigned char	b;
    short		near;
    short		far;
} Fog_data;
#endif
/*=======================================================================*/



/*-----------------------------------------------------------------------
 *
 *	シーンＮｏ
 *
 *----------------------------------------------------------------------*/
typedef	short	Scene_No;

/*-----------------------------------------------------------------------
 *
 *	シーン設定データ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	data1;	/* データ */
    unsigned int	data2;	/* データ */
} Scene_Word_Base;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Actor_data		*data;	/* ポインタ */
} Scene_Word_Actor;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Camera_data		*data;	/* ポインタ */
} Scene_Word_Camera;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	pad;	/* 未使用 */
    T_BGDataInfo	*data;	/* ポインタ */
} Scene_Word_BGcheck;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Rom_Address		*data;	/* ポインタ */
} Scene_Word_ROM_address;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	pad;	/* 未使用 */
    Scene_Word		**data;	/* ポインタ */
} Scene_Word_Scene_Word_Ptr;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Room_Status		*data;	/* ポインタ */
} Scene_Word_Room_Status;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	pad;	/* 未使用 */
    Ground_Shape	*data;	/* ポインタ */
} Scene_Word_Ground_Shape;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Object_Bank		*data;	/* ポインタ */
} Scene_Word_Object_Bank;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Light_data		*data;	/* ポインタ */
} Scene_Word_Light;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	pad;	/* 未使用 */
    Path_Info		*data;	/* ポインタ */
} Scene_Word_Path;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Door_data		*data;	/* ポインタ */
} Scene_Word_Door;
typedef struct {
    unsigned char	code;	/* 制御コード	*/
    unsigned char	dammy0;	/* データ１	*/
    unsigned char	dammy1;	/* データ１	*/
    unsigned char	dammy2;	/* データ１	*/
    unsigned char	data1;	/* データ１	*/
    unsigned char	data2;	/* データ２	*/
    unsigned char	data3;	/* データ３	*/
    unsigned char	data4;	/* データ４	*/
} Scene_Word_Kankyo;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	pad;	/* 未使用 */
    Scene_No		*data;	/* ポインタ */
} Scene_Word_Next_Scene;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Light_info		*data;	/* ポインタ */
} Scene_Word_Kcolor;
typedef struct {
    unsigned char	code;	/* 制御コード */
    unsigned char	num;	/* セット数 */
    Light_info		*data;	/* ポインタ */
} Scene_Word_Time;
typedef struct {
    unsigned char	code;		/* 制御コード */
    unsigned char	mode;		/* メモリーモード */
    unsigned char	pad0;
    unsigned char	pad1;
    unsigned char	pad2;
    unsigned char	pad3;
    unsigned char	environment;	/* 環境音フラグ */
    unsigned char	BGM;		/* ＢＧＭフラグ */
} Scene_Word_Scene_Sound;
typedef struct {
    unsigned char	code;		/* 制御コード */
    unsigned char	type;		/* ダミー */
    unsigned char	pad0;
    unsigned char	pad1;
    unsigned char	pad2;
    unsigned char	pad3;
    unsigned char	pad4;
    unsigned char	echo_level;	/* エコーレベル */
} Scene_Word_Room_Sound;
typedef struct {
    unsigned char	code;	/* 制御コード			*/
    unsigned char	pad;	/* セット数			*/
    char		*data;	/* ポインタ 12/17 ** -> *	*/
} Scene_Word_Demo_Data;
typedef struct {
    unsigned char	code;	/* 制御コード			*/
    unsigned char	pad;	/* セット数			*/
    Scene_Word		**data;	/* ポインタ 12/17 ** -> *	*/
} Scene_Word_Demo_Scene_Data;

union SCENE_WORD {
    Scene_Word_Base		base;
    Scene_Word_Actor		actor;
    Scene_Word_Camera		camera;
    Scene_Word_BGcheck		BGcheck;
    Scene_Word_ROM_address	ROM_address;
    Scene_Word_Scene_Word_Ptr	scene_word_ptr;
    Scene_Word_Room_Status	room_status;
    Scene_Word_Ground_Shape	ground_shape;
    Scene_Word_Object_Bank	object_bank;
    Scene_Word_Light		light;
    Scene_Word_Path		path;
    Scene_Word_Door		door;
    Scene_Word_Kankyo		kankyo;
    Scene_Word_Next_Scene	next_scene;
    Scene_Word_Kcolor		kcolor;
    Scene_Word_Time		time;
    Scene_Word_Scene_Sound	scene_sound;
    Scene_Word_Room_Sound	room_sound;
    Scene_Word_Demo_Data	demo_data;
    Scene_Word_Demo_Scene_Data	demo_scene_data;
};

/*-----------------------------------------------------------------------
 *
 *	シーンコンストラクト
 *
 *----------------------------------------------------------------------*/
extern int Scene_ct(Game_play *game_play, Scene_Word *scene_info);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_scene.h end ***/
