/*
####
###  ゼルダカメラ Ｃヘッダファイル
####
###
##   作成者 : hiratsu@crucian
##   作成日 : 103年2月28日(金) 16時21分
###
####
*/

#ifndef __CAMERA_PARAM_DATA_H__
#define __CAMERA_PARAM_DATA_H__

struct zelda_camera_set_control;
struct zelda_camera_mode_control;
struct zelda_camera_parameter_control;

typedef struct zelda_camera_set_control       CameraCtlList;
typedef struct zelda_camera_mode_control      CameraMode;
typedef struct zelda_camera_parameter_control CameraParam;

/*
## セット
##
*/
enum camera_set {
	CAM_SET_NONE,           /* 特定しない       */
	CAM_SET_NORMAL0,    	/* 通常カメラＡ     */
	CAM_SET_NORMAL1,    	/* 通常カメラＢ     */
	CAM_SET_DUNGEON0,   	/* 洞窟カメラＡ     */
	CAM_SET_DUNGEON1,   	/* 洞窟カメラＢ     */
	CAM_SET_NORMAL3,    	/* 通常カメラＤ     */
	CAM_SET_HORSE0,     	/* 馬カメラＡ       */
	CAM_SET_BOSS_GOMA,  	/* ボスゴーマカメラ */
	CAM_SET_BOSS_DODO,  	/* 王ドドンゴカメラ */
	CAM_SET_BOSS_BARI,  	/* バリネードカメラ */
	CAM_SET_BOSS_FGANON,	/* 幽霊ガノンカメラ */
	CAM_SET_BOSS_BAL,   	/* バルバジアカメラ */
	CAM_SET_BOSS_SHADES,	/* 影ストーカカメラ */
	CAM_SET_BOSS_MOFA,  	/* モーファカメラ   */
	CAM_SET_BOSS_TWIN0, 	/* 双子老婆カメラ上 */
	CAM_SET_BOSS_TWIN1, 	/* 双子老婆カメラ下 */
	CAM_SET_BOSS_GANON1,	/* 人ガノンカメラ   */
	CAM_SET_BOSS_GANON2,	/* 豚ガノンカメラ   */
	CAM_SET_TOWER0,     	/* 塔カメラＡ       */
	CAM_SET_TOWER1,     	/* 塔カメラＢ       */
	CAM_SET_FIXED0,     	/* 固定カメラＡ     */
	CAM_SET_FIXED1,     	/* 固定カメラＢ     */
	CAM_SET_CIRCLE0,    	/* 定点カメラＡ     */
	CAM_SET_CIRCLE2,    	/* 定点カメラＣ     */
	CAM_SET_CIRCLE3,    	/* 定点カメラＤ     */
	CAM_SET_PREREND0,   	/* ＰＲカメラＡ     */
	CAM_SET_PREREND1,   	/* ＰＲカメラＢ     */
	CAM_SET_PREREND3,   	/* ＰＲカメラＤ     */
	CAM_SET_DOOR0,      	/* ドアカメラＡ     */
	CAM_SET_DOORC,      	/* ドアカメラ梅     */
	CAM_SET_RAIL3,      	/* レールカメラＤ   */
	CAM_SET_START0,     	/* 開始カメラＡ     */
	CAM_SET_START1,     	/* 開始カメラＢ     */
	CAM_SET_FREE0,      	/* 自由カメラＡ     */
	CAM_SET_FREE2,      	/* 自由カメラＣ     */
	CAM_SET_CIRCLE4,    	/* 定点カメラＥ     */
	CAM_SET_CIRCLE5,    	/* 定点カメラＦ     */
	CAM_SET_DEMO0,      	/* デモカメラＡ     */
	CAM_SET_DEMO1,      	/* デモカメラＢ     */
	CAM_SET_MORI1,      	/* 森ダンカメラＡ   */
	CAM_SET_ITEM0,      	/* お宝カメラＡ     */
	CAM_SET_ITEM1,      	/* お宝カメラＢ     */
	CAM_SET_DEMO3,      	/* デモカメラＤ     */
	CAM_SET_DEMO4,      	/* デモカメラＥ     */
	CAM_SET_UFOBEAN,    	/* 豆ＵＦＯカメラ   */
	CAM_SET_LIFTBEAN,   	/* 豆リフトカメラ   */
	CAM_SET_SCENE0,     	/* 切替カメラＡ     */
	CAM_SET_SCENE1,     	/* 切替カメラＢ     */
	CAM_SET_HIDAN1,     	/* 火ダンカメラＡ   */
	CAM_SET_HIDAN2,     	/* 火ダンカメラＢ   */
	CAM_SET_MORI2,      	/* 森ダンカメラＢ   */
	CAM_SET_MORI3,      	/* 森ダンカメラＣ   */
	CAM_SET_TAKO,       	/* 大だこカメラ     */
	CAM_SET_SPOT05A,    	/* ＳＰＯＴ０５Ａ   */
	CAM_SET_SPOT05B,    	/* ＳＰＯＴ０５Ｂ   */
	CAM_SET_HIDAN3,     	/* 火ダンカメラＣ   */
	CAM_SET_ITEM2,      	/* お宝カメラＣ     */
	CAM_SET_CIRCLE6,    	/* 定点カメラＧ     */
	CAM_SET_NORMAL2,    	/* 通常カメラＣ     */
	CAM_SET_FISHING,    	/* 釣りカメラ       */
	CAM_SET_DEMOC,      	/* デモカメラ梅     */
	CAM_SET_UO_FIBER,   	/* 魚神経カメラ     */
	CAM_SET_DUNGEON2,   	/* 洞窟カメラＣ     */
	CAM_SET_TEPPEN,     	/* 前見ないカメラ   */
	CAM_SET_CIRCLE7,    	/* 定点カメラＨ     */
	CAM_SET_NORMAL4,    	/* 通常カメラＥ     */
	CAM_SET_NUM
};

/*
## モード
##
*/
enum camera_mode {
	CAM_MODE_NORMAL,    	/* 通常             */
	CAM_MODE_PARALLEL,  	/* 平行             */
	CAM_MODE_KEEPON,    	/* 注目             */
	CAM_MODE_TALK,      	/* 会話             */
	CAM_MODE_BATTLE,    	/* 戦闘             */
	CAM_MODE_CLIMB,     	/* よじ登り         */
	CAM_MODE_SUBJECT,   	/* 主観             */
	CAM_MODE_BOWARROW,  	/* 弓矢             */
	CAM_MODE_BOWARROWZ, 	/* 弓矢注目         */
	CAM_MODE_FOOKSHOT,  	/* フックショット   */
	CAM_MODE_BOOMERANG, 	/* ブーメラン       */
	CAM_MODE_PACHINCO,  	/* パチンコ         */
	CAM_MODE_CLIMBZ,    	/* よじ登り注目     */
	CAM_MODE_JUMP,      	/* ジャンプ         */
	CAM_MODE_HANG,      	/* ぶら下り         */
	CAM_MODE_HANGZ,     	/* ぶら下り注目     */
	CAM_MODE_FREEFALL,  	/* 落下             */
	CAM_MODE_CHARGE,    	/* ため切り         */
	CAM_MODE_STILL,     	/* 一時停止         */
	CAM_MODE_PUSHPULL,  	/* 押引             */
	CAM_MODE_BOOKEEPON, 	/* ブメラン注目     */
	CAM_MODE_NUM
};

/*
###
##  カメラセット制御オブジェクト
###
*/
struct zelda_camera_set_control {
    unsigned int      modemsk;               /* 有効モード識別用マスク*/
    CameraMode        *modes;                /* モードテーブル        */
};

/*
###
##  カメラモード制御オブジェクト
###
*/
struct zelda_camera_mode_control {
    short             func;                  /* アルゴリズム          */
    short             nparams;               /* パラメータ数          */
    CameraParam       *params;               /* パラメータテーブル    */
};

/*
###
##  カメラパラメータ制御オブジェクト
###
*/
struct zelda_camera_parameter_control {
    short             value;                 /* 値                     */
    short             regno;                 /* デバッグ用レジスタ番号 */
};

/*
## デバッグ用レジスタ
##
*/
#define CAM_PARAM_CTRH              0	/* 注目高 etc.                    */
#define CAM_PARAM_MIND              1	/* 最小距離 etc.                  */
#define CAM_PARAM_MAXD              2	/* 最大距離 etc.                  */
#define CAM_PARAM_ANGV              3	/* 縦角度 etc.                    */
#define CAM_PARAM_CUSH              4	/* 横クッション etc.              */
#define CAM_PARAM_CUSC              5	/* 地形角クッション etc.          */
#define CAM_PARAM_SPRH              6	/* 横スピード依存度 etc.          */
#define CAM_PARAM_FOVY              7	/* 視野角 etc.                    */
#define CAM_PARAM_SHFT              8	/* 中心移動 etc.                  */
#define CAM_PARAM_FLAG              9	/* フラグ etc.                    */
#define CAM_PARAM_ANGH             10	/* 横角度 etc.                    */
#define CAM_PARAM_CTRU             11	/* 空注目高 etc.                  */
#define CAM_PARAM_SHFU             12	/* 空中心移動 etc.                */
#define CAM_PARAM_NARC             13	/* 最近横振り etc.                */
#define CAM_PARAM_FARC             14	/* 最遠横振り etc.                */
#define CAM_PARAM_NARV             15	/* 最近縦角度 etc.                */
#define CAM_PARAM_FARV             16	/* 最遠縦角度 etc.                */
#define CAM_PARAM_ADJV             17	/* 縦角度補正 etc.                */
#define CAM_PARAM_MARD             18	/* 距離マージン etc.              */
#define CAM_PARAM_ADJX             19	/* 位置補正Ｘ etc.                */
#define CAM_PARAM_ADJY             20	/* 位置補正Ｙ etc.                */
#define CAM_PARAM_ADJZ             21	/* 位置補正Ｚ etc.                */
#define CAM_PARAM_TIME             22	/* タイマー etc.                  */
#define CAM_PARAM_MAXH             23	/* 最大横角度 etc.                */
#define CAM_PARAM_ADJF             24	/* 視野角調整 etc.                */
#define CAM_PARAM_CTRR             25	/* 注目位置 etc.                  */
#define CAM_PARAM_CUSL             26	/* 地形角クッション etc.          */

/* 以降 z_camera.c でしか見えない */
#ifdef __CAMERA_C_

static short  p_reg_init_data[] = {
	-20,	/*           CAM_PARAM_CTRH 注目高 etc.                    */
	200,	/*           CAM_PARAM_MIND 最小距離 etc.                  */
	300,	/*           CAM_PARAM_MAXD 最大距離 etc.                  */
	 10,	/*           CAM_PARAM_ANGV 縦角度 etc.                    */
	 12,	/*           CAM_PARAM_CUSH 横クッション etc.              */
	 10,	/*           CAM_PARAM_CUSC 地形角クッション etc.          */
	 35,	/*           CAM_PARAM_SPRH 横スピード依存度 etc.          */
	 60,	/*           CAM_PARAM_FOVY 視野角 etc.                    */
	 60,	/*           CAM_PARAM_SHFT 中心移動 etc.                  */
	  3,	/*           CAM_PARAM_FLAG フラグ etc.                    */
	  0,	/*           CAM_PARAM_ANGH 横角度 etc.                    */
	-40,	/*           CAM_PARAM_CTRU 空注目高 etc.                  */
	 20,	/*           CAM_PARAM_SHFU 空中心移動 etc.                */
	 25,	/*           CAM_PARAM_NARC 最近横振り etc.                */
	 45,	/*           CAM_PARAM_FARC 最遠横振り etc.                */
	 -5,	/*           CAM_PARAM_NARV 最近縦角度 etc.                */
	 15,	/*           CAM_PARAM_FARV 最遠縦角度 etc.                */
	 15,	/*           CAM_PARAM_ADJV 縦角度補正 etc.                */
	 20,	/*           CAM_PARAM_MARD 距離マージン etc.              */
	  0,	/*           CAM_PARAM_ADJX 位置補正Ｘ etc.                */
	  0,	/*           CAM_PARAM_ADJY 位置補正Ｙ etc.                */
	  0,	/*           CAM_PARAM_ADJZ 位置補正Ｚ etc.                */
	  6,	/*           CAM_PARAM_TIME タイマー etc.                  */
	 60,	/*           CAM_PARAM_MAXH 最大横角度 etc.                */
	 30,	/*           CAM_PARAM_ADJF 視野角調整 etc.                */
	  0,	/*           CAM_PARAM_CTRR 注目位置 etc.                  */
	  5,	/*           CAM_PARAM_CUSL 地形角クッション etc.          */
};
static short  n_p_reg_init_data = 27;

#ifdef CAM_DBG_MSG
/*
## デバッグ用文字列（セット）
##
*/
static char _set_str[CAM_SET_NUM][12] = {
	"NONE      ",   /* 特定しない       */
	"NORMAL0    ",	/* 通常カメラＡ     */
	"NORMAL1    ",	/* 通常カメラＢ     */
	"DUNGEON0   ",	/* 洞窟カメラＡ     */
	"DUNGEON1   ",	/* 洞窟カメラＢ     */
	"NORMAL3    ",	/* 通常カメラＤ     */
	"HORSE0     ",	/* 馬カメラＡ       */
	"BOSS_GOMA  ",	/* ボスゴーマカメラ */
	"BOSS_DODO  ",	/* 王ドドンゴカメラ */
	"BOSS_BARI  ",	/* バリネードカメラ */
	"BOSS_FGANON",	/* 幽霊ガノンカメラ */
	"BOSS_BAL   ",	/* バルバジアカメラ */
	"BOSS_SHADES",	/* 影ストーカカメラ */
	"BOSS_MOFA  ",	/* モーファカメラ   */
	"BOSS_TWIN0 ",	/* 双子老婆カメラ上 */
	"BOSS_TWIN1 ",	/* 双子老婆カメラ下 */
	"BOSS_GANON1",	/* 人ガノンカメラ   */
	"BOSS_GANON2",	/* 豚ガノンカメラ   */
	"TOWER0     ",	/* 塔カメラＡ       */
	"TOWER1     ",	/* 塔カメラＢ       */
	"FIXED0     ",	/* 固定カメラＡ     */
	"FIXED1     ",	/* 固定カメラＢ     */
	"CIRCLE0    ",	/* 定点カメラＡ     */
	"CIRCLE2    ",	/* 定点カメラＣ     */
	"CIRCLE3    ",	/* 定点カメラＤ     */
	"PREREND0   ",	/* ＰＲカメラＡ     */
	"PREREND1   ",	/* ＰＲカメラＢ     */
	"PREREND3   ",	/* ＰＲカメラＤ     */
	"DOOR0      ",	/* ドアカメラＡ     */
	"DOORC      ",	/* ドアカメラ梅     */
	"RAIL3      ",	/* レールカメラＤ   */
	"START0     ",	/* 開始カメラＡ     */
	"START1     ",	/* 開始カメラＢ     */
	"FREE0      ",	/* 自由カメラＡ     */
	"FREE2      ",	/* 自由カメラＣ     */
	"CIRCLE4    ",	/* 定点カメラＥ     */
	"CIRCLE5    ",	/* 定点カメラＦ     */
	"DEMO0      ",	/* デモカメラＡ     */
	"DEMO1      ",	/* デモカメラＢ     */
	"MORI1      ",	/* 森ダンカメラＡ   */
	"ITEM0      ",	/* お宝カメラＡ     */
	"ITEM1      ",	/* お宝カメラＢ     */
	"DEMO3      ",	/* デモカメラＤ     */
	"DEMO4      ",	/* デモカメラＥ     */
	"UFOBEAN    ",	/* 豆ＵＦＯカメラ   */
	"LIFTBEAN   ",	/* 豆リフトカメラ   */
	"SCENE0     ",	/* 切替カメラＡ     */
	"SCENE1     ",	/* 切替カメラＢ     */
	"HIDAN1     ",	/* 火ダンカメラＡ   */
	"HIDAN2     ",	/* 火ダンカメラＢ   */
	"MORI2      ",	/* 森ダンカメラＢ   */
	"MORI3      ",	/* 森ダンカメラＣ   */
	"TAKO       ",	/* 大だこカメラ     */
	"SPOT05A    ",	/* ＳＰＯＴ０５Ａ   */
	"SPOT05B    ",	/* ＳＰＯＴ０５Ｂ   */
	"HIDAN3     ",	/* 火ダンカメラＣ   */
	"ITEM2      ",	/* お宝カメラＣ     */
	"CIRCLE6    ",	/* 定点カメラＧ     */
	"NORMAL2    ",	/* 通常カメラＣ     */
	"FISHING    ",	/* 釣りカメラ       */
	"DEMOC      ",	/* デモカメラ梅     */
	"UO_FIBER   ",	/* 魚神経カメラ     */
	"DUNGEON2   ",	/* 洞窟カメラＣ     */
	"TEPPEN     ",	/* 前見ないカメラ   */
	"CIRCLE7    ",	/* 定点カメラＨ     */
	"NORMAL4    ",	/* 通常カメラＥ     */
};

/*
## デバッグ用文字列（モード）
##
*/
static char _mode_str[CAM_MODE_NUM][12] = {
	"NORMAL     ",	/* 通常             */
	"PARALLEL   ",	/* 平行             */
	"KEEPON     ",	/* 注目             */
	"TALK       ",	/* 会話             */
	"BATTLE     ",	/* 戦闘             */
	"CLIMB      ",	/* よじ登り         */
	"SUBJECT    ",	/* 主観             */
	"BOWARROW   ",	/* 弓矢             */
	"BOWARROWZ  ",	/* 弓矢注目         */
	"FOOKSHOT   ",	/* フックショット   */
	"BOOMERANG  ",	/* ブーメラン       */
	"PACHINCO   ",	/* パチンコ         */
	"CLIMBZ     ",	/* よじ登り注目     */
	"JUMP       ",	/* ジャンプ         */
	"HANG       ",	/* ぶら下り         */
	"HANGZ      ",	/* ぶら下り注目     */
	"FREEFALL   ",	/* 落下             */
	"CHARGE     ",	/* ため切り         */
	"STILL      ",	/* 一時停止         */
	"PUSHPULL   ",	/* 押引             */
	"BOOKEEPON  ",	/* ブメラン注目     */
};

#endif /* CAM_DBG_MSG */

/*
## パラメータ
##
*/

/*
** パラメータリスト 0 
**
** 通常カメラＡ(通常)
*/
static CameraParam cam_param_list0[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 1 
**
** 通常カメラＡ(平行)
** ボスゴーマカメラ(平行)
** 王ドドンゴカメラ(平行)
** バリネードカメラ(平行)
** 幽霊ガノンカメラ(平行)
** バルバジアカメラ(平行)
** 影ストーカカメラ(平行)
** モーファカメラ(平行)
** 双子老婆カメラ上(平行)
** 双子老婆カメラ下(平行)
** 人ガノンカメラ(平行)
** 豚ガノンカメラ(平行)
** 塔カメラＡ(平行)
** 塔カメラＢ(平行)
** 定点カメラＤ(平行)
** 通常カメラＣ(平行)
** 魚神経カメラ(平行)
** 前見ないカメラ(平行)
** 通常カメラＥ(平行)
*/
static CameraParam cam_param_list1[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 2 
**
** 通常カメラＡ(注目)
** 通常カメラＤ(注目)
** ボスゴーマカメラ(注目)
** 王ドドンゴカメラ(注目)
** バリネードカメラ(注目)
** 幽霊ガノンカメラ(注目)
** バルバジアカメラ(注目)
** 影ストーカカメラ(注目)
** モーファカメラ(注目)
** 双子老婆カメラ上(注目)
** 双子老婆カメラ下(注目)
** 人ガノンカメラ(注目)
** 豚ガノンカメラ(注目)
** 塔カメラＡ(注目)
** 塔カメラＢ(注目)
** 定点カメラＤ(注目)
** 豆ＵＦＯカメラ(注目)
** 豆リフトカメラ(注目)
** 通常カメラＣ(注目)
** 魚神経カメラ(注目)
** 通常カメラＥ(注目)
*/
static CameraParam cam_param_list2[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 最小距離             */
	{   140,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    25,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    45,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    -5,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    15,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    15,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8193,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    30,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 3 
**
** 通常カメラＡ(会話)
** 通常カメラＢ(会話)
** 洞窟カメラＡ(会話)
** ボスゴーマカメラ(会話)
** 王ドドンゴカメラ(会話)
** バリネードカメラ(会話)
** 幽霊ガノンカメラ(会話)
** バルバジアカメラ(会話)
** 影ストーカカメラ(会話)
** モーファカメラ(会話)
** 双子老婆カメラ上(会話)
** 双子老婆カメラ下(会話)
** 人ガノンカメラ(会話)
** 豚ガノンカメラ(会話)
** 塔カメラＡ(会話)
** 塔カメラＢ(会話)
** 定点カメラＤ(会話)
** 豆ＵＦＯカメラ(会話)
** 豆リフトカメラ(会話)
** 大だこカメラ(会話)
** 通常カメラＣ(会話)
** 魚神経カメラ(会話)
** 洞窟カメラＣ(会話)
** 定点カメラＨ(会話)
*/
static CameraParam cam_param_list3[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{    70,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13568,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 4 
**
** 通常カメラＡ(戦闘)
** 通常カメラＤ(戦闘)
** 塔カメラＡ(戦闘)
** 塔カメラＢ(戦闘)
** 前見ないカメラ(戦闘)
*/
static CameraParam cam_param_list4[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    80,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    50,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    25,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 5 
**
** 通常カメラＡ(よじ登り)
** 通常カメラＤ(よじ登り)
** ボスゴーマカメラ(よじ登り)
** 王ドドンゴカメラ(よじ登り)
** バリネードカメラ(よじ登り)
** 幽霊ガノンカメラ(よじ登り)
** バルバジアカメラ(よじ登り)
** 影ストーカカメラ(よじ登り)
** モーファカメラ(よじ登り)
** 双子老婆カメラ上(よじ登り)
** 双子老婆カメラ下(よじ登り)
** 人ガノンカメラ(よじ登り)
** 豚ガノンカメラ(よじ登り)
** 塔カメラＡ(よじ登り)
** 塔カメラＢ(よじ登り)
** 定点カメラＤ(よじ登り)
** 豆ＵＦＯカメラ(よじ登り)
** 豆リフトカメラ(よじ登り)
** 通常カメラＣ(よじ登り)
** 魚神経カメラ(よじ登り)
** 前見ないカメラ(よじ登り)
** 通常カメラＥ(よじ登り)
*/
static CameraParam cam_param_list5[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 6 
**
** 通常カメラＡ(主観)
** 通常カメラＢ(主観)
** 洞窟カメラＡ(主観)
** 洞窟カメラＢ(主観)
** 通常カメラＤ(主観)
** ボスゴーマカメラ(主観)
** 王ドドンゴカメラ(主観)
** バリネードカメラ(主観)
** 幽霊ガノンカメラ(主観)
** バルバジアカメラ(主観)
** 影ストーカカメラ(主観)
** モーファカメラ(主観)
** 双子老婆カメラ上(主観)
** 双子老婆カメラ下(主観)
** 人ガノンカメラ(主観)
** 豚ガノンカメラ(主観)
** 塔カメラＡ(主観)
** 塔カメラＢ(主観)
** 定点カメラＤ(主観)
** 豆ＵＦＯカメラ(主観)
** 豆リフトカメラ(主観)
** 大だこカメラ(主観)
** 通常カメラＣ(主観)
** 魚神経カメラ(主観)
** 洞窟カメラＣ(主観)
** 前見ないカメラ(主観)
** 定点カメラＨ(主観)
** 通常カメラＥ(主観)
*/
static CameraParam cam_param_list6[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{     5,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{     0,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{     0,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{     0,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 7 
**
** 通常カメラＡ(弓矢)
** 通常カメラＢ(弓矢)
** 洞窟カメラＡ(弓矢)
** 洞窟カメラＢ(弓矢)
** 通常カメラＤ(弓矢)
** ボスゴーマカメラ(弓矢)
** 王ドドンゴカメラ(弓矢)
** バリネードカメラ(弓矢)
** 幽霊ガノンカメラ(弓矢)
** バルバジアカメラ(弓矢)
** 影ストーカカメラ(弓矢)
** モーファカメラ(弓矢)
** 双子老婆カメラ上(弓矢)
** 双子老婆カメラ下(弓矢)
** 人ガノンカメラ(弓矢)
** 豚ガノンカメラ(弓矢)
** 塔カメラＡ(弓矢)
** 塔カメラＢ(弓矢)
** 定点カメラＤ(弓矢)
** 豆ＵＦＯカメラ(弓矢)
** 豆リフトカメラ(弓矢)
** 大だこカメラ(弓矢)
** 通常カメラＣ(弓矢)
** 魚神経カメラ(弓矢)
** 洞窟カメラＣ(弓矢)
** 前見ないカメラ(弓矢)
** 定点カメラＨ(弓矢)
** 通常カメラＥ(弓矢)
*/
static CameraParam cam_param_list7[] = {
	{    -7,            CAM_PARAM_CTRH },	/* 注目高               */
	{    14,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{     0,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{   -30,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{    -5,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 8 
**
** 通常カメラＡ(弓矢注目)
** 通常カメラＢ(弓矢注目)
** 洞窟カメラＡ(弓矢注目)
** 洞窟カメラＢ(弓矢注目)
** 通常カメラＤ(弓矢注目)
** 馬カメラＡ(弓矢注目)
** ボスゴーマカメラ(弓矢注目)
** 王ドドンゴカメラ(弓矢注目)
** バリネードカメラ(弓矢注目)
** 幽霊ガノンカメラ(弓矢注目)
** バルバジアカメラ(弓矢注目)
** 影ストーカカメラ(弓矢注目)
** モーファカメラ(弓矢注目)
** 双子老婆カメラ上(弓矢注目)
** 双子老婆カメラ下(弓矢注目)
** 人ガノンカメラ(弓矢注目)
** 豚ガノンカメラ(弓矢注目)
** 塔カメラＡ(弓矢注目)
** 塔カメラＢ(弓矢注目)
** 定点カメラＤ(弓矢注目)
** 豆ＵＦＯカメラ(弓矢注目)
** 豆リフトカメラ(弓矢注目)
** 大だこカメラ(弓矢注目)
** 通常カメラＣ(弓矢注目)
** 魚神経カメラ(弓矢注目)
** 洞窟カメラＣ(弓矢注目)
** 前見ないカメラ(弓矢注目)
** 通常カメラＥ(弓矢注目)
*/
static CameraParam cam_param_list8[] = {
	{    20,            CAM_PARAM_CTRH },	/* 注目高               */
	{    70,            CAM_PARAM_MIND },	/* 距離                 */
	{    70,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{  -120,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{    20,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{     0,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 9 
**
** 通常カメラＡ(フックショット)
** 通常カメラＤ(フックショット)
** ボスゴーマカメラ(フックショット)
** 王ドドンゴカメラ(フックショット)
** バリネードカメラ(フックショット)
** 幽霊ガノンカメラ(フックショット)
** バルバジアカメラ(フックショット)
** 影ストーカカメラ(フックショット)
** モーファカメラ(フックショット)
** 双子老婆カメラ上(フックショット)
** 双子老婆カメラ下(フックショット)
** 人ガノンカメラ(フックショット)
** 豚ガノンカメラ(フックショット)
** 塔カメラＡ(フックショット)
** 塔カメラＢ(フックショット)
** 定点カメラＤ(フックショット)
** 豆ＵＦＯカメラ(フックショット)
** 豆リフトカメラ(フックショット)
** 通常カメラＣ(フックショット)
** 魚神経カメラ(フックショット)
** 前見ないカメラ(フックショット)
** 定点カメラＨ(フックショット)
** 通常カメラＥ(フックショット)
*/
static CameraParam cam_param_list9[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{    80,            CAM_PARAM_MIND },	/* 距離                 */
	{   250,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    45,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     6,            CAM_PARAM_TIME },	/* タイマー             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 10 
**
** 通常カメラＡ(ブーメラン)
** 通常カメラＢ(ブーメラン)
** 洞窟カメラＡ(ブーメラン)
** 洞窟カメラＢ(ブーメラン)
** ボスゴーマカメラ(ブーメラン)
** 王ドドンゴカメラ(ブーメラン)
** バリネードカメラ(ブーメラン)
** 幽霊ガノンカメラ(ブーメラン)
** バルバジアカメラ(ブーメラン)
** 影ストーカカメラ(ブーメラン)
** モーファカメラ(ブーメラン)
** 双子老婆カメラ上(ブーメラン)
** 双子老婆カメラ下(ブーメラン)
** 人ガノンカメラ(ブーメラン)
** 豚ガノンカメラ(ブーメラン)
** 塔カメラＡ(ブーメラン)
** 塔カメラＢ(ブーメラン)
** 定点カメラＤ(ブーメラン)
** 豆ＵＦＯカメラ(ブーメラン)
** 豆リフトカメラ(ブーメラン)
** 大だこカメラ(ブーメラン)
** 通常カメラＣ(ブーメラン)
** 魚神経カメラ(ブーメラン)
** 洞窟カメラＣ(ブーメラン)
** 前見ないカメラ(ブーメラン)
** 定点カメラＨ(ブーメラン)
** 通常カメラＥ(ブーメラン)
*/
static CameraParam cam_param_list10[] = {
	{     5,            CAM_PARAM_CTRH },	/* 注目高               */
	{    50,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{     0,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{     0,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{     0,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 11 
**
** 通常カメラＡ(パチンコ)
** 通常カメラＢ(パチンコ)
** 洞窟カメラＡ(パチンコ)
** 洞窟カメラＢ(パチンコ)
** ボスゴーマカメラ(パチンコ)
** 王ドドンゴカメラ(パチンコ)
** バリネードカメラ(パチンコ)
** 幽霊ガノンカメラ(パチンコ)
** バルバジアカメラ(パチンコ)
** 影ストーカカメラ(パチンコ)
** モーファカメラ(パチンコ)
** 双子老婆カメラ上(パチンコ)
** 双子老婆カメラ下(パチンコ)
** 人ガノンカメラ(パチンコ)
** 豚ガノンカメラ(パチンコ)
** 塔カメラＡ(パチンコ)
** 塔カメラＢ(パチンコ)
** 定点カメラＤ(パチンコ)
** 豆ＵＦＯカメラ(パチンコ)
** 豆リフトカメラ(パチンコ)
** 大だこカメラ(パチンコ)
** 通常カメラＣ(パチンコ)
** 魚神経カメラ(パチンコ)
** 洞窟カメラＣ(パチンコ)
** 前見ないカメラ(パチンコ)
** 定点カメラＨ(パチンコ)
** 通常カメラＥ(パチンコ)
*/
static CameraParam cam_param_list11[] = {
	{    -7,            CAM_PARAM_CTRH },	/* 注目高               */
	{    14,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{    -9,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{   -63,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{   -30,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 12 
**
** 通常カメラＡ(よじ登り注目)
** 通常カメラＤ(よじ登り注目)
** ボスゴーマカメラ(よじ登り注目)
** 王ドドンゴカメラ(よじ登り注目)
** バリネードカメラ(よじ登り注目)
** 幽霊ガノンカメラ(よじ登り注目)
** バルバジアカメラ(よじ登り注目)
** 影ストーカカメラ(よじ登り注目)
** モーファカメラ(よじ登り注目)
** 双子老婆カメラ上(よじ登り注目)
** 双子老婆カメラ下(よじ登り注目)
** 人ガノンカメラ(よじ登り注目)
** 豚ガノンカメラ(よじ登り注目)
** 塔カメラＡ(よじ登り注目)
** 塔カメラＢ(よじ登り注目)
** 定点カメラＤ(よじ登り注目)
** 豆ＵＦＯカメラ(よじ登り注目)
** 豆リフトカメラ(よじ登り注目)
** 通常カメラＣ(よじ登り注目)
** 魚神経カメラ(よじ登り注目)
** 前見ないカメラ(よじ登り注目)
** 通常カメラＥ(よじ登り注目)
*/
static CameraParam cam_param_list12[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{   999,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8198,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 13 
**
** 通常カメラＡ(ジャンプ)
** 通常カメラＤ(ジャンプ)
** 通常カメラＤ(落下)
** ボスゴーマカメラ(ジャンプ)
** ボスゴーマカメラ(落下)
** 王ドドンゴカメラ(ジャンプ)
** 王ドドンゴカメラ(落下)
** バリネードカメラ(ジャンプ)
** バリネードカメラ(落下)
** 幽霊ガノンカメラ(ジャンプ)
** 幽霊ガノンカメラ(落下)
** バルバジアカメラ(ジャンプ)
** バルバジアカメラ(落下)
** モーファカメラ(ジャンプ)
** モーファカメラ(落下)
** 双子老婆カメラ上(ジャンプ)
** 双子老婆カメラ上(落下)
** 双子老婆カメラ下(ジャンプ)
** 双子老婆カメラ下(落下)
** 人ガノンカメラ(ジャンプ)
** 人ガノンカメラ(落下)
** 豚ガノンカメラ(ジャンプ)
** 豚ガノンカメラ(落下)
** 塔カメラＡ(落下)
** 塔カメラＢ(落下)
** 豆ＵＦＯカメラ(落下)
** 豆リフトカメラ(落下)
** 通常カメラＣ(ジャンプ)
** 通常カメラＣ(落下)
** 魚神経カメラ(ジャンプ)
** 魚神経カメラ(落下)
** 前見ないカメラ(ジャンプ)
** 前見ないカメラ(落下)
** 通常カメラＥ(ジャンプ)
** 通常カメラＥ(落下)
*/
static CameraParam cam_param_list13[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 14 
**
** 通常カメラＡ(ぶら下り)
** 通常カメラＤ(ぶら下り)
** ボスゴーマカメラ(ぶら下り)
** 王ドドンゴカメラ(ぶら下り)
** バリネードカメラ(ぶら下り)
** 幽霊ガノンカメラ(ぶら下り)
** バルバジアカメラ(ぶら下り)
** 影ストーカカメラ(ぶら下り)
** モーファカメラ(ぶら下り)
** 双子老婆カメラ上(ぶら下り)
** 双子老婆カメラ下(ぶら下り)
** 人ガノンカメラ(ぶら下り)
** 豚ガノンカメラ(ぶら下り)
** 塔カメラＡ(ぶら下り)
** 塔カメラＢ(ぶら下り)
** 通常カメラＣ(ぶら下り)
** 魚神経カメラ(ぶら下り)
** 前見ないカメラ(ぶら下り)
** 通常カメラＥ(ぶら下り)
*/
static CameraParam cam_param_list14[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 15 
**
** 通常カメラＡ(ぶら下り注目)
** 通常カメラＤ(ぶら下り注目)
** ボスゴーマカメラ(ぶら下り注目)
** 王ドドンゴカメラ(ぶら下り注目)
** バリネードカメラ(ぶら下り注目)
** 幽霊ガノンカメラ(ぶら下り注目)
** バルバジアカメラ(ぶら下り注目)
** 影ストーカカメラ(ぶら下り注目)
** モーファカメラ(ぶら下り注目)
** 双子老婆カメラ上(ぶら下り注目)
** 双子老婆カメラ下(ぶら下り注目)
** 人ガノンカメラ(ぶら下り注目)
** 豚ガノンカメラ(ぶら下り注目)
** 塔カメラＡ(ぶら下り注目)
** 塔カメラＢ(ぶら下り注目)
** 通常カメラＣ(ぶら下り注目)
** 魚神経カメラ(ぶら下り注目)
** 前見ないカメラ(ぶら下り注目)
** 通常カメラＥ(ぶら下り注目)
*/
static CameraParam cam_param_list15[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 16 
**
** 通常カメラＡ(落下)
*/
static CameraParam cam_param_list16[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 17 
**
** 通常カメラＡ(ため切り)
** 通常カメラＤ(ため切り)
** 王ドドンゴカメラ(ため切り)
** バリネードカメラ(ため切り)
** 幽霊ガノンカメラ(ため切り)
** バルバジアカメラ(ため切り)
** 影ストーカカメラ(ため切り)
** モーファカメラ(ため切り)
** 双子老婆カメラ上(ため切り)
** 双子老婆カメラ下(ため切り)
** 豚ガノンカメラ(ため切り)
** 塔カメラＡ(ため切り)
** 塔カメラＢ(ため切り)
** 定点カメラＤ(ため切り)
** 豆ＵＦＯカメラ(ため切り)
** 豆リフトカメラ(ため切り)
** 通常カメラＣ(ため切り)
** 魚神経カメラ(ため切り)
** 洞窟カメラＣ(ため切り)
** 前見ないカメラ(ため切り)
** 通常カメラＥ(ため切り)
*/
static CameraParam cam_param_list17[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     2,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4096,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 18 
**
** 通常カメラＡ(一時停止)
** 通常カメラＤ(一時停止)
** ボスゴーマカメラ(一時停止)
** 王ドドンゴカメラ(一時停止)
** バリネードカメラ(一時停止)
** 幽霊ガノンカメラ(一時停止)
** バルバジアカメラ(一時停止)
** 影ストーカカメラ(一時停止)
** モーファカメラ(一時停止)
** 双子老婆カメラ上(一時停止)
** 双子老婆カメラ下(一時停止)
** 人ガノンカメラ(一時停止)
** 豚ガノンカメラ(一時停止)
** 塔カメラＡ(一時停止)
** 塔カメラＢ(一時停止)
** 定点カメラＤ(一時停止)
** 通常カメラＣ(一時停止)
** 魚神経カメラ(一時停止)
** 前見ないカメラ(一時停止)
** 通常カメラＥ(一時停止)
*/
static CameraParam cam_param_list18[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     5,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4093,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 19 
**
** 通常カメラＡ(押引)
** 通常カメラＢ(押引)
** 洞窟カメラＡ(押引)
** 通常カメラＤ(押引)
** ボスゴーマカメラ(押引)
** 王ドドンゴカメラ(押引)
** バリネードカメラ(押引)
** 幽霊ガノンカメラ(押引)
** バルバジアカメラ(押引)
** 影ストーカカメラ(押引)
** モーファカメラ(押引)
** 双子老婆カメラ上(押引)
** 双子老婆カメラ下(押引)
** 人ガノンカメラ(押引)
** 豚ガノンカメラ(押引)
** 塔カメラＡ(押引)
** 塔カメラＢ(押引)
** 定点カメラＤ(押引)
** 豆ＵＦＯカメラ(押引)
** 豆リフトカメラ(押引)
** 大だこカメラ(押引)
** 通常カメラＣ(押引)
** 魚神経カメラ(押引)
** 前見ないカメラ(押引)
** 通常カメラＥ(押引)
*/
static CameraParam cam_param_list19[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{    25,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8298,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -20,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    30,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 20 
**
** 通常カメラＡ(ブメラン注目)
** 通常カメラＢ(ブメラン注目)
** 洞窟カメラＡ(ブメラン注目)
** 洞窟カメラＢ(ブメラン注目)
** ボスゴーマカメラ(ブメラン注目)
** 王ドドンゴカメラ(ブメラン注目)
** バリネードカメラ(ブメラン注目)
** 幽霊ガノンカメラ(ブメラン注目)
** バルバジアカメラ(ブメラン注目)
** 影ストーカカメラ(ブメラン注目)
** モーファカメラ(ブメラン注目)
** 双子老婆カメラ上(ブメラン注目)
** 双子老婆カメラ下(ブメラン注目)
** 人ガノンカメラ(ブメラン注目)
** 豚ガノンカメラ(ブメラン注目)
** 塔カメラＡ(ブメラン注目)
** 塔カメラＢ(ブメラン注目)
** 定点カメラＤ(ブメラン注目)
** 豆ＵＦＯカメラ(ブメラン注目)
** 豆リフトカメラ(ブメラン注目)
** 大だこカメラ(ブメラン注目)
** 通常カメラＣ(ブメラン注目)
** 魚神経カメラ(ブメラン注目)
** 洞窟カメラＣ(ブメラン注目)
** 前見ないカメラ(ブメラン注目)
** 通常カメラＥ(ブメラン注目)
*/
static CameraParam cam_param_list20[] = {
	{    -5,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 最小距離             */
	{   140,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     5,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    85,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    10,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8193,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -15,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    30,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 21 
**
** 通常カメラＢ(通常)
*/
static CameraParam cam_param_list21[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    20,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 22 
**
** 通常カメラＢ(平行)
*/
static CameraParam cam_param_list22[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 23 
**
** 通常カメラＢ(注目)
** 洞窟カメラＢ(注目)
*/
static CameraParam cam_param_list23[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 最小距離             */
	{   140,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    25,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    45,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    -5,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    15,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    15,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8193,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 24 
**
** 通常カメラＢ(戦闘)
** 定点カメラＤ(戦闘)
** 豆ＵＦＯカメラ(戦闘)
** 豆リフトカメラ(戦闘)
** 通常カメラＣ(戦闘)
** 通常カメラＥ(戦闘)
*/
static CameraParam cam_param_list24[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    80,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    50,            CAM_PARAM_FOVY },	/* 視野角               */
	{    65,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    25,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 25 
**
** 通常カメラＢ(フックショット)
** 洞窟カメラＡ(フックショット)
** 洞窟カメラＢ(フックショット)
** 大だこカメラ(フックショット)
** 洞窟カメラＣ(フックショット)
*/
static CameraParam cam_param_list25[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{    80,            CAM_PARAM_MIND },	/* 距離                 */
	{   250,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{     6,            CAM_PARAM_TIME },	/* タイマー             */
	{    45,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 26 
**
** 通常カメラＢ(ジャンプ)
*/
static CameraParam cam_param_list26[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 27 
**
** 通常カメラＢ(落下)
*/
static CameraParam cam_param_list27[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    30,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 28 
**
** 通常カメラＢ(よじ登り)
*/
static CameraParam cam_param_list28[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 29 
**
** 通常カメラＢ(よじ登り注目)
*/
static CameraParam cam_param_list29[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{   999,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8198,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 30 
**
** 通常カメラＢ(ため切り)
*/
static CameraParam cam_param_list30[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     2,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4096,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 31 
**
** 通常カメラＢ(ぶら下り)
*/
static CameraParam cam_param_list31[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 32 
**
** 通常カメラＢ(ぶら下り注目)
*/
static CameraParam cam_param_list32[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   400,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 33 
**
** 通常カメラＢ(一時停止)
*/
static CameraParam cam_param_list33[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   400,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    20,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     5,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4093,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 34 
**
** 洞窟カメラＡ(通常)
*/
static CameraParam cam_param_list34[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     5,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    10,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    30,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 35 
**
** 洞窟カメラＡ(平行)
** 洞窟カメラＢ(平行)
** 大だこカメラ(平行)
*/
static CameraParam cam_param_list35[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 36 
**
** 洞窟カメラＡ(注目)
** 大だこカメラ(注目)
** 洞窟カメラＣ(注目)
*/
static CameraParam cam_param_list36[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 最小距離             */
	{   140,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    25,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    45,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    -5,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    15,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    15,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8193,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 37 
**
** 洞窟カメラＡ(戦闘)
** 洞窟カメラＢ(戦闘)
*/
static CameraParam cam_param_list37[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    80,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    25,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 38 
**
** 洞窟カメラＡ(ジャンプ)
** 大だこカメラ(ジャンプ)
*/
static CameraParam cam_param_list38[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 39 
**
** 洞窟カメラＡ(落下)
** 大だこカメラ(落下)
*/
static CameraParam cam_param_list39[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 40 
**
** 洞窟カメラＡ(よじ登り)
** 大だこカメラ(よじ登り)
*/
static CameraParam cam_param_list40[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 41 
**
** 洞窟カメラＡ(よじ登り注目)
** 大だこカメラ(よじ登り注目)
*/
static CameraParam cam_param_list41[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{   999,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8198,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 42 
**
** 洞窟カメラＡ(ため切り)
** ボスゴーマカメラ(ため切り)
** 大だこカメラ(ため切り)
*/
static CameraParam cam_param_list42[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     2,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4096,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 43 
**
** 洞窟カメラＡ(ぶら下り)
** 大だこカメラ(ぶら下り)
*/
static CameraParam cam_param_list43[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 44 
**
** 洞窟カメラＡ(ぶら下り注目)
** 大だこカメラ(ぶら下り注目)
*/
static CameraParam cam_param_list44[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 45 
**
** 洞窟カメラＡ(一時停止)
*/
static CameraParam cam_param_list45[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     5,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     5,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4093,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 46 
**
** 洞窟カメラＢ(通常)
*/
static CameraParam cam_param_list46[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    10,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    30,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 47 
**
** 洞窟カメラＢ(会話)
*/
static CameraParam cam_param_list47[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{    70,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13568,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 48 
**
** 洞窟カメラＢ(ジャンプ)
*/
static CameraParam cam_param_list48[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 49 
**
** 洞窟カメラＢ(落下)
*/
static CameraParam cam_param_list49[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   180,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 50 
**
** 洞窟カメラＢ(よじ登り)
*/
static CameraParam cam_param_list50[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 51 
**
** 洞窟カメラＢ(よじ登り注目)
*/
static CameraParam cam_param_list51[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{   999,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8198,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 52 
**
** 洞窟カメラＢ(ため切り)
*/
static CameraParam cam_param_list52[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     2,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4096,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 53 
**
** 洞窟カメラＢ(ぶら下り)
*/
static CameraParam cam_param_list53[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 54 
**
** 洞窟カメラＢ(ぶら下り注目)
*/
static CameraParam cam_param_list54[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 55 
**
** 洞窟カメラＢ(一時停止)
*/
static CameraParam cam_param_list55[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     5,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4093,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 56 
**
** 洞窟カメラＢ(押引)
*/
static CameraParam cam_param_list56[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 距離                 */
	{    25,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8298,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -20,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    30,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 57 
**
** 通常カメラＤ(通常)
*/
static CameraParam cam_param_list57[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   280,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     4,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 58 
**
** 通常カメラＤ(平行)
*/
static CameraParam cam_param_list58[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 59 
**
** 通常カメラＤ(会話)
*/
static CameraParam cam_param_list59[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{    70,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    10,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    20,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13568,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 60 
**
** 通常カメラＤ(水面下)
*/
static CameraParam cam_param_list60[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    -5,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    18,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     5,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 61 
**
** 馬カメラＡ(通常)
*/
static CameraParam cam_param_list61[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   220,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    16,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    20,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  1536,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 62 
**
** 馬カメラＡ(平行)
*/
static CameraParam cam_param_list62[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 最小距離             */
	{   220,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    -2,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{   100,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  9728,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 63 
**
** 馬カメラＡ(弓矢)
*/
static CameraParam cam_param_list63[] = {
	{    -7,            CAM_PARAM_CTRH },	/* 注目高               */
	{    14,            CAM_PARAM_MIND },	/* 距離                 */
	{   100,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{     0,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{   -30,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{    -5,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    40,            CAM_PARAM_FOVY },	/* 視野角               */
	{  9728,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 64 
**
** 馬カメラＡ(注目)
*/
static CameraParam cam_param_list64[] = {
	{   -60,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 最小距離             */
	{   220,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    25,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    45,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    -5,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    15,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    15,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  9729,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -60,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 65 
**
** 馬カメラＡ(会話)
*/
static CameraParam cam_param_list65[] = {
	{   -60,            CAM_PARAM_CTRH },	/* 注目高               */
	{   140,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13568,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 66 
**
** ボスゴーマカメラ(通常)
*/
static CameraParam cam_param_list66[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     1,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 67 
**
** ボスゴーマカメラ(戦闘)
*/
static CameraParam cam_param_list67[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    40,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{   -10,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     0,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 68 
**
** 王ドドンゴカメラ(通常)
*/
static CameraParam cam_param_list68[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 69 
**
** 王ドドンゴカメラ(戦闘)
*/
static CameraParam cam_param_list69[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   160,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    60,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    -5,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     0,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 70 
**
** バリネードカメラ(通常)
*/
static CameraParam cam_param_list70[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    -5,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    70,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 71 
**
** バリネードカメラ(戦闘)
*/
static CameraParam cam_param_list71[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{   125,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     0,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    50,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 72 
**
** 幽霊ガノンカメラ(通常)
*/
static CameraParam cam_param_list72[] = {
	{    10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    15,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 73 
**
** 幽霊ガノンカメラ(戦闘)
** 人ガノンカメラ(戦闘)
*/
static CameraParam cam_param_list73[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{    45,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    40,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     5,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    -5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    35,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    60,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 74 
**
** バルバジアカメラ(通常)
*/
static CameraParam cam_param_list74[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    16,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 75 
**
** バルバジアカメラ(戦闘)
*/
static CameraParam cam_param_list75[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{    20,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    60,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    15,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 76 
**
** 影ストーカカメラ(通常)
*/
static CameraParam cam_param_list76[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{   131,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 77 
**
** 影ストーカカメラ(戦闘)
*/
static CameraParam cam_param_list77[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{    20,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    60,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    15,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8322,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 78 
**
** 影ストーカカメラ(ジャンプ)
** 影ストーカカメラ(落下)
*/
static CameraParam cam_param_list78[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{   131,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 79 
**
** モーファカメラ(通常)
*/
static CameraParam cam_param_list79[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   100,            CAM_PARAM_MIND },	/* 最小距離             */
	{   150,            CAM_PARAM_MAXD },	/* 最大距離             */
	{   -10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    80,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 80 
**
** モーファカメラ(戦闘)
*/
static CameraParam cam_param_list80[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    80,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{   -10,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 81 
**
** 双子老婆カメラ上(通常)
*/
static CameraParam cam_param_list81[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 82 
**
** 双子老婆カメラ上(戦闘)
** 双子老婆カメラ下(戦闘)
*/
static CameraParam cam_param_list82[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   400,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    60,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{   -10,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -20,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 83 
**
** 双子老婆カメラ下(通常)
*/
static CameraParam cam_param_list83[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{   -10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 84 
**
** 人ガノンカメラ(通常)
*/
static CameraParam cam_param_list84[] = {
	{    40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   330,            CAM_PARAM_MIND },	/* 最小距離             */
	{   330,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    -5,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    15,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 85 
**
** 人ガノンカメラ(ため切り)
*/
static CameraParam cam_param_list85[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     2,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4096,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 86 
**
** 豚ガノンカメラ(通常)
*/
static CameraParam cam_param_list86[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 87 
**
** 豚ガノンカメラ(戦闘)
*/
static CameraParam cam_param_list87[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 距離                 */
	{    20,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    60,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 88 
**
** 塔カメラＡ(通常)
*/
static CameraParam cam_param_list88[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 最小距離             */
	{   280,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    60,            CAM_PARAM_MAXH },	/* 最大横角度           */
	{     8,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 89 
**
** 塔カメラＡ(ジャンプ)
*/
static CameraParam cam_param_list89[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 最小距離             */
	{   280,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    60,            CAM_PARAM_MAXH },	/* 最大横角度           */
	{     8,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    40,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{   128,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 90 
**
** 塔カメラＢ(通常)
*/
static CameraParam cam_param_list90[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   270,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{   120,            CAM_PARAM_MAXH },	/* 最大横角度           */
	{     8,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    60,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 91 
**
** 塔カメラＢ(ジャンプ)
*/
static CameraParam cam_param_list91[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   270,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{   120,            CAM_PARAM_MAXH },	/* 最大横角度           */
	{     6,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    60,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   100,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 92 
**
** 固定カメラＡ(通常)
*/
static CameraParam cam_param_list92[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   100,            CAM_PARAM_CUSH },	/* クッション           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 93 
**
** 固定カメラＡ(注目)
*/
static CameraParam cam_param_list93[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   100,            CAM_PARAM_CUSH },	/* クッション           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 94 
**
** 固定カメラＡ(会話)
*/
static CameraParam cam_param_list94[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   100,            CAM_PARAM_CUSH },	/* クッション           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{ 13568,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 95 
**
** 固定カメラＢ(通常)
*/
static CameraParam cam_param_list95[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{    25,            CAM_PARAM_CUSH },	/* クッション           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 96 
**
** 定点カメラＡ(通常)
*/
static CameraParam cam_param_list96[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{    50,            CAM_PARAM_CUSH },	/* 視点クッション       */
	{    80,            CAM_PARAM_CUSC },	/* 注目点クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     1,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 97 
**
** 定点カメラＣ(通常)
*/
static CameraParam cam_param_list97[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{ 16128,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 98 
**
** 定点カメラＤ(通常)
** 定点カメラＨ(通常)
** 定点カメラＨ(注目)
*/
static CameraParam cam_param_list98[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{    50,            CAM_PARAM_CUSH },	/* 視点クッション       */
	{    80,            CAM_PARAM_CUSC },	/* 注目点クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     4,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 99 
**
** ＰＲカメラＡ(通常)
** ＰＲカメラＤ(通常)
** 開始カメラＡ(通常)
** 火ダンカメラＡ(通常)
*/
static CameraParam cam_param_list99[] = {
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 100 
**
** ＰＲカメラＡ(注目)
** ＰＲカメラＡ(会話)
*/
static CameraParam cam_param_list100[] = {
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 101 
**
** ＰＲカメラＢ(通常)
*/
static CameraParam cam_param_list101[] = {
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 102 
**
** ＰＲカメラＢ(注目)
*/
static CameraParam cam_param_list102[] = {
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 103 
**
** ＰＲカメラＢ(会話)
*/
static CameraParam cam_param_list103[] = {
	{    30,            CAM_PARAM_ADJF },	/* 視野角調整           */
	{     0,            CAM_PARAM_CTRR },	/* 注目位置             */
	{     4,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13568,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 104 
**
** ドアカメラＡ(通常)
*/
static CameraParam cam_param_list104[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{ 12800,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 105 
**
** ドアカメラ梅(通常)
*/
static CameraParam cam_param_list105[] = {
	{    -5,            CAM_PARAM_CTRH },	/* 注目高               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{ 12802,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 106 
**
** ドアカメラ梅(平行)
*/
static CameraParam cam_param_list106[] = {
	{    -5,            CAM_PARAM_CTRH },	/* 注目高               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{ 12810,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 107 
**
** レールカメラＤ(通常)
*/
static CameraParam cam_param_list107[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{     2,            CAM_PARAM_MIND },	/* 距離                 */
	{    30,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{ 12800,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 108 
**
** 開始カメラＢ(通常)
*/
static CameraParam cam_param_list108[] = {
	{     1,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 109 
**
** 自由カメラＡ(通常)
*/
static CameraParam cam_param_list109[] = {
	{  -256,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 110 
**
** 自由カメラＣ(通常)
*/
static CameraParam cam_param_list110[] = {
	{  -255,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 111 
**
** 定点カメラＥ(通常)
*/
static CameraParam cam_param_list111[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   100,            CAM_PARAM_CUSH },	/* 視点クッション       */
	{    80,            CAM_PARAM_CUSC },	/* 注目点クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 112 
**
** 定点カメラＦ(通常)
*/
static CameraParam cam_param_list112[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{    60,            CAM_PARAM_MIND },	/* 距離                 */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 113 
**
** 定点カメラＦ(平行)
*/
static CameraParam cam_param_list113[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{    45,            CAM_PARAM_MIND },	/* 距離                 */
	{   100,            CAM_PARAM_FOVY },	/* 視野角               */
	{  8193,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 114 
**
** デモカメラＡ(通常)
** デモカメラＢ(通常)
** デモカメラＥ(通常)
** 火ダンカメラＢ(通常)
** 森ダンカメラＢ(通常)
** 森ダンカメラＣ(通常)
*/
static CameraParam cam_param_list114[] = {
	{ 12800,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 115 
**
** 森ダンカメラＡ(通常)
*/
static CameraParam cam_param_list115[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   450,            CAM_PARAM_MIND },	/* 距離                 */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   180,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    12,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 116 
**
** 森ダンカメラＡ(会話)
*/
static CameraParam cam_param_list116[] = {
	{ 13569,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 117 
**
** お宝カメラＡ(通常)
** お宝カメラＢ(通常)
*/
static CameraParam cam_param_list117[] = {
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 視野角２             */
	{ 12800,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 118 
**
** デモカメラＤ(通常)
*/
static CameraParam cam_param_list118[] = {
	{ 12818,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 119 
**
** 豆ＵＦＯカメラ(通常)
*/
static CameraParam cam_param_list119[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    50,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 120 
**
** 豆ＵＦＯカメラ(平行)
*/
static CameraParam cam_param_list120[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 121 
**
** 豆ＵＦＯカメラ(ジャンプ)
*/
static CameraParam cam_param_list121[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 122 
**
** 豆ＵＦＯカメラ(ぶら下り)
*/
static CameraParam cam_param_list122[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    60,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 123 
**
** 豆ＵＦＯカメラ(ぶら下り注目)
*/
static CameraParam cam_param_list123[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    50,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 124 
**
** 豆ＵＦＯカメラ(一時停止)
*/
static CameraParam cam_param_list124[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    50,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4094,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 125 
**
** 豆リフトカメラ(通常)
*/
static CameraParam cam_param_list125[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    16,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 126 
**
** 豆リフトカメラ(平行)
*/
static CameraParam cam_param_list126[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 127 
**
** 豆リフトカメラ(ジャンプ)
*/
static CameraParam cam_param_list127[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 128 
**
** 豆リフトカメラ(ぶら下り)
*/
static CameraParam cam_param_list128[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 129 
**
** 豆リフトカメラ(ぶら下り注目)
*/
static CameraParam cam_param_list129[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    60,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    50,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 130 
**
** 豆リフトカメラ(一時停止)
*/
static CameraParam cam_param_list130[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4094,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 131 
**
** 切替カメラＡ(通常)
*/
static CameraParam cam_param_list131[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   266,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 132 
**
** 切替カメラＢ(通常)
*/
static CameraParam cam_param_list132[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   150,            CAM_PARAM_MIND },	/* 距離                 */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{   528,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 133 
**
** 大だこカメラ(通常)
*/
static CameraParam cam_param_list133[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   400,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    35,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    14,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    20,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    18,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 134 
**
** 大だこカメラ(戦闘)
*/
static CameraParam cam_param_list134[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{     5,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    30,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    20,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    25,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 135 
**
** 大だこカメラ(一時停止)
*/
static CameraParam cam_param_list135[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    60,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     8,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    18,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 136 
**
** ＳＰＯＴ０５Ａ(通常)
*/
static CameraParam cam_param_list136[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    18,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 137 
**
** ＳＰＯＴ０５Ａ(平行)
*/
static CameraParam cam_param_list137[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 距離                 */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8218,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    40,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 138 
**
** ＳＰＯＴ０５Ａ(戦闘)
*/
static CameraParam cam_param_list138[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 距離                 */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8218,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    40,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 139 
**
** ＳＰＯＴ０５Ａ(よじ登り)
*/
static CameraParam cam_param_list139[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    18,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 140 
**
** ＳＰＯＴ０５Ｂ(通常)
*/
static CameraParam cam_param_list140[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   750,            CAM_PARAM_MIND },	/* 最小距離             */
	{   750,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    18,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 141 
**
** ＳＰＯＴ０５Ｂ(平行)
*/
static CameraParam cam_param_list141[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   750,            CAM_PARAM_MIND },	/* 距離                 */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8218,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    40,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 142 
**
** ＳＰＯＴ０５Ｂ(戦闘)
*/
static CameraParam cam_param_list142[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   750,            CAM_PARAM_MIND },	/* 距離                 */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    40,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 143 
**
** ＳＰＯＴ０５Ｂ(よじ登り)
*/
static CameraParam cam_param_list143[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   750,            CAM_PARAM_MIND },	/* 最小距離             */
	{   750,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    18,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 144 
**
** 火ダンカメラＣ(通常)
*/
static CameraParam cam_param_list144[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 145 
**
** 火ダンカメラＣ(平行)
*/
static CameraParam cam_param_list145[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 距離                 */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    40,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 146 
**
** 火ダンカメラＣ(戦闘)
*/
static CameraParam cam_param_list146[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 距離                 */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    40,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 147 
**
** 火ダンカメラＣ(よじ登り)
*/
static CameraParam cam_param_list147[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   500,            CAM_PARAM_MIND },	/* 最小距離             */
	{   500,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    80,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 148 
**
** お宝カメラＣ(通常)
*/
static CameraParam cam_param_list148[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{   120,            CAM_PARAM_MIND },	/* 距離                 */
	{   -10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   170,            CAM_PARAM_ANGH },	/* 横角度               */
	{     0,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{  9474,            CAM_PARAM_FLAG },	/* フラグ               */
	{    25,            CAM_PARAM_CUSH },	/* クッション           */
	{     6,            CAM_PARAM_TIME },	/* タイマー             */
};

/*
** パラメータリスト 149 
**
** 定点カメラＧ(通常)
*/
static CameraParam cam_param_list149[] = {
	{    20,            CAM_PARAM_CUSH },	/* クッション           */
	{ 12800,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 150 
**
** 通常カメラＣ(通常)
** 通常カメラＥ(通常)
*/
static CameraParam cam_param_list150[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 151 
**
** 釣りカメラ(通常)
*/
static CameraParam cam_param_list151[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    55,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  3842,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 152 
**
** 釣りカメラ(平行)
*/
static CameraParam cam_param_list152[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ 12042,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 153 
**
** 釣りカメラ(注目)
** 釣りカメラ(戦闘)
*/
static CameraParam cam_param_list153[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   250,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    80,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     0,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    55,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ 12034,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    25,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 154 
**
** 釣りカメラ(会話)
*/
static CameraParam cam_param_list154[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{    70,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 16160,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 155 
**
** 釣りカメラ(主観)
*/
static CameraParam cam_param_list155[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{     5,            CAM_PARAM_MIND },	/* 距離                 */
	{    50,            CAM_PARAM_MAXD },	/* 自動パン距離         */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{     0,            CAM_PARAM_ADJX },	/* 位置補正Ｘ           */
	{     0,            CAM_PARAM_ADJY },	/* 位置補正Ｙ           */
	{     0,            CAM_PARAM_ADJZ },	/* 位置補正Ｚ           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{  3840,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 156 
**
** 釣りカメラ(ジャンプ)
*/
static CameraParam cam_param_list156[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    12,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    35,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  3840,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 157 
**
** 釣りカメラ(落下)
*/
static CameraParam cam_param_list157[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  3840,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 158 
**
** 釣りカメラ(ぶら下り)
*/
static CameraParam cam_param_list158[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  3840,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 159 
**
** 釣りカメラ(ぶら下り注目)
*/
static CameraParam cam_param_list159[] = {
	{  -120,            CAM_PARAM_CTRH },	/* 注目高               */
	{   300,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ 12032,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 160 
**
** デモカメラ梅(通常)
*/
static CameraParam cam_param_list160[] = {
	{ 16128,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 161 
**
** 魚神経カメラ(通常)
*/
static CameraParam cam_param_list161[] = {
	{    30,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   300,            CAM_PARAM_MAXD },	/* 最大距離             */
	{   -20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSL },	/* 地形角クッション     */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    70,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 162 
**
** 魚神経カメラ(戦闘)
*/
static CameraParam cam_param_list162[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{   160,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     0,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 163 
**
** 洞窟カメラＣ(通常)
*/
static CameraParam cam_param_list163[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    30,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    60,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     3,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 164 
**
** 洞窟カメラＣ(平行)
*/
static CameraParam cam_param_list164[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 距離                 */
	{     0,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8202,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    20,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 165 
**
** 洞窟カメラＣ(戦闘)
*/
static CameraParam cam_param_list165[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 距離                 */
	{    10,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    80,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{   -10,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    10,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    25,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8194,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -40,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    25,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 166 
**
** 洞窟カメラＣ(ジャンプ)
*/
static CameraParam cam_param_list166[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    10,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    50,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 167 
**
** 洞窟カメラＣ(落下)
*/
static CameraParam cam_param_list167[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    15,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    20,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 168 
**
** 洞窟カメラＣ(よじ登り)
*/
static CameraParam cam_param_list168[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 169 
**
** 洞窟カメラＣ(よじ登り注目)
*/
static CameraParam cam_param_list169[] = {
	{   -40,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_MARD },	/* 距離マージン         */
	{   999,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 注目高クッション     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    40,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8198,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 170 
**
** 洞窟カメラＣ(ぶら下り)
*/
static CameraParam cam_param_list170[] = {
	{   -50,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     0,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 171 
**
** 洞窟カメラＣ(ぶら下り注目)
*/
static CameraParam cam_param_list171[] = {
	{  -100,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    70,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    10,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8192,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 172 
**
** 洞窟カメラＣ(一時停止)
*/
static CameraParam cam_param_list172[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   350,            CAM_PARAM_MIND },	/* 最小距離             */
	{   350,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    20,            CAM_PARAM_ANGV },	/* 縦角度               */
	{   100,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{   100,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{     5,            CAM_PARAM_SHFT },	/* 中心移動             */
	{ -4093,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 173 
**
** 洞窟カメラＣ(押引)
*/
static CameraParam cam_param_list173[] = {
	{     0,            CAM_PARAM_CTRH },	/* 注目高               */
	{   280,            CAM_PARAM_MIND },	/* 距離                 */
	{    25,            CAM_PARAM_ANGV },	/* 縦角度               */
	{     0,            CAM_PARAM_ANGH },	/* 横角度               */
	{     5,            CAM_PARAM_CUSH },	/* 横クッション         */
	{     5,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    70,            CAM_PARAM_FOVY },	/* 視野角               */
	{    30,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8298,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -20,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    30,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 174 
**
** 前見ないカメラ(通常)
*/
static CameraParam cam_param_list174[] = {
	{   -10,            CAM_PARAM_CTRH },	/* 注目高               */
	{   280,            CAM_PARAM_MIND },	/* 最小距離             */
	{   320,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    -8,            CAM_PARAM_ANGV },	/* 縦角度               */
	{    20,            CAM_PARAM_CUSH },	/* 横クッション         */
	{    10,            CAM_PARAM_CUSC },	/* 地形角クッション     */
	{    80,            CAM_PARAM_SPRH },	/* 横スピード依存度     */
	{    60,            CAM_PARAM_FOVY },	/* 視野角               */
	{    80,            CAM_PARAM_SHFT },	/* 中心移動             */
	{     2,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 175 
**
** 前見ないカメラ(注目)
*/
static CameraParam cam_param_list175[] = {
	{   -20,            CAM_PARAM_CTRH },	/* 注目高               */
	{   180,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    35,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    45,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    -5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    20,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    50,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{  8193,            CAM_PARAM_FLAG },	/* フラグ               */
	{   -50,            CAM_PARAM_CTRU },	/* 空注目高             */
	{    30,            CAM_PARAM_SHFU },	/* 空中心移動           */
};

/*
** パラメータリスト 176 
**
** 前見ないカメラ(会話)
*/
static CameraParam cam_param_list176[] = {
	{   -80,            CAM_PARAM_CTRH },	/* 注目高               */
	{   200,            CAM_PARAM_MIND },	/* 最小距離             */
	{   250,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    30,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{    -8,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{    -8,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    30,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    50,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13600,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
** パラメータリスト 177 
**
** 通常カメラＥ(会話)
*/
static CameraParam cam_param_list177[] = {
	{   -30,            CAM_PARAM_CTRH },	/* 注目高               */
	{    70,            CAM_PARAM_MIND },	/* 最小距離             */
	{   200,            CAM_PARAM_MAXD },	/* 最大距離             */
	{    40,            CAM_PARAM_NARC },	/* 最近横振り           */
	{    10,            CAM_PARAM_FARC },	/* 最遠横振り           */
	{     0,            CAM_PARAM_NARV },	/* 最近縦角度           */
	{     5,            CAM_PARAM_FARV },	/* 最遠縦角度           */
	{    70,            CAM_PARAM_ADJV },	/* 縦角度補正           */
	{    45,            CAM_PARAM_FOVY },	/* 視野角               */
	{    50,            CAM_PARAM_SHFT },	/* 中心移動             */
	{    10,            CAM_PARAM_CUSH },	/* クッション           */
	{ 13728,            CAM_PARAM_FLAG },	/* フラグ               */
};

/*
## モードテーブル
##
*/

/*
** モードテーブル 1
**
** CAM_SET_NORMAL0 (通常カメラＡ)
*/
static CameraMode  cam_mode_tbl1[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list0   },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list4   },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list16  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 2
**
** CAM_SET_NORMAL1 (通常カメラＢ)
*/
static CameraMode  cam_mode_tbl2[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list21  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list22  },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list23  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list24  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list28  },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list25  },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list29  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list26  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list31  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list32  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list27  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list30  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list33  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 3
**
** CAM_SET_DUNGEON0 (洞窟カメラＡ)
*/
static CameraMode  cam_mode_tbl3[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list34  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list35  },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list36  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list37  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list40  },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list25  },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list41  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list38  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list43  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list44  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list39  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list42  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list45  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 4
**
** CAM_SET_DUNGEON1 (洞窟カメラＢ)
*/
static CameraMode  cam_mode_tbl4[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list46  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list35  },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list23  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list47  },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list37  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list50  },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list25  },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list51  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list48  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list53  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list54  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list49  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list52  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list55  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list56  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 5
**
** CAM_SET_NORMAL3 (通常カメラＤ)
*/
static CameraMode  cam_mode_tbl5[] = {
    { CAM_FUNC_JUMP3, 10, cam_param_list57  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list58  },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list59  },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list4   },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_JUMP3, 10, cam_param_list60  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
};

/*
** モードテーブル 6
**
** CAM_SET_HORSE0 (馬カメラＡ)
*/
static CameraMode  cam_mode_tbl6[] = {
    { CAM_FUNC_NORM3,  9, cam_param_list61  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_NORM3,  9, cam_param_list62  },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list64  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list65  },	/* CAM_MODE_TALK        */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list63  },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
};

/*
** モードテーブル 7
**
** CAM_SET_BOSS_GOMA (ボスゴーマカメラ)
*/
static CameraMode  cam_mode_tbl7[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list66  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list67  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list42  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 8
**
** CAM_SET_BOSS_DODO (王ドドンゴカメラ)
*/
static CameraMode  cam_mode_tbl8[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list68  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list69  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 9
**
** CAM_SET_BOSS_BARI (バリネードカメラ)
*/
static CameraMode  cam_mode_tbl9[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list70  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list71  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 10
**
** CAM_SET_BOSS_FGANON (幽霊ガノンカメラ)
*/
static CameraMode  cam_mode_tbl10[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list72  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list73  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 11
**
** CAM_SET_BOSS_BAL (バルバジアカメラ)
*/
static CameraMode  cam_mode_tbl11[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list74  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list75  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 12
**
** CAM_SET_BOSS_SHADES (影ストーカカメラ)
*/
static CameraMode  cam_mode_tbl12[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list76  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list77  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_NORM1, 10, cam_param_list78  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_NORM1, 10, cam_param_list78  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 13
**
** CAM_SET_BOSS_MOFA (モーファカメラ)
*/
static CameraMode  cam_mode_tbl13[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list79  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list80  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 14
**
** CAM_SET_BOSS_TWIN0 (双子老婆カメラ上)
*/
static CameraMode  cam_mode_tbl14[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list81  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list82  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 15
**
** CAM_SET_BOSS_TWIN1 (双子老婆カメラ下)
*/
static CameraMode  cam_mode_tbl15[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list83  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list82  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 16
**
** CAM_SET_BOSS_GANON1 (人ガノンカメラ)
*/
static CameraMode  cam_mode_tbl16[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list84  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list73  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list85  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 17
**
** CAM_SET_BOSS_GANON2 (豚ガノンカメラ)
*/
static CameraMode  cam_mode_tbl17[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list86  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list87  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 18
**
** CAM_SET_TOWER0 (塔カメラＡ)
*/
static CameraMode  cam_mode_tbl18[] = {
    { CAM_FUNC_NORM2,  9, cam_param_list88  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list4   },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_NORM2,  9, cam_param_list89  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 19
**
** CAM_SET_TOWER1 (塔カメラＢ)
*/
static CameraMode  cam_mode_tbl19[] = {
    { CAM_FUNC_NORM2,  9, cam_param_list90  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list4   },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_NORM2,  9, cam_param_list91  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 20
**
** CAM_SET_FIXED0 (固定カメラＡ)
*/
static CameraMode  cam_mode_tbl20[] = {
    { CAM_FUNC_FIXD1,  4, cam_param_list92  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_FIXD1,  4, cam_param_list93  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_FIXD1,  4, cam_param_list94  },	/* CAM_MODE_TALK        */
};

/*
** モードテーブル 21
**
** CAM_SET_FIXED1 (固定カメラＢ)
*/
static CameraMode  cam_mode_tbl21[] = {
    { CAM_FUNC_FIXD1,  4, cam_param_list95  },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 22
**
** CAM_SET_CIRCLE0 (定点カメラＡ)
*/
static CameraMode  cam_mode_tbl22[] = {
    { CAM_FUNC_FIXD2,  5, cam_param_list96  },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 23
**
** CAM_SET_CIRCLE2 (定点カメラＣ)
*/
static CameraMode  cam_mode_tbl23[] = {
    { CAM_FUNC_DATA4,  3, cam_param_list97  },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 24
**
** CAM_SET_CIRCLE3 (定点カメラＤ)
*/
static CameraMode  cam_mode_tbl24[] = {
    { CAM_FUNC_FIXD4,  5, cam_param_list98  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list24  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_HANG        */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 25
**
** CAM_SET_PREREND0 (ＰＲカメラＡ)
*/
static CameraMode  cam_mode_tbl25[] = {
    { CAM_FUNC_FIXD3,  1, cam_param_list99  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_FIXD3,  1, cam_param_list100 },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_FIXD3,  1, cam_param_list100 },	/* CAM_MODE_TALK        */
};

/*
** モードテーブル 26
**
** CAM_SET_PREREND1 (ＰＲカメラＢ)
*/
static CameraMode  cam_mode_tbl26[] = {
    { CAM_FUNC_UNIQ7,  2, cam_param_list101 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_UNIQ7,  2, cam_param_list102 },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP0,  4, cam_param_list103 },	/* CAM_MODE_TALK        */
};

/*
** モードテーブル 27
**
** CAM_SET_PREREND3 (ＰＲカメラＤ)
*/
static CameraMode  cam_mode_tbl27[] = {
    { CAM_FUNC_SPEC6,  1, cam_param_list99  },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 28
**
** CAM_SET_DOOR0 (ドアカメラＡ)
*/
static CameraMode  cam_mode_tbl28[] = {
    { CAM_FUNC_UNIQ3,  3, cam_param_list104 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 29
**
** CAM_SET_DOORC (ドアカメラ梅)
*/
static CameraMode  cam_mode_tbl29[] = {
    { CAM_FUNC_SPEC9,  3, cam_param_list105 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_SPEC9,  3, cam_param_list106 },	/* CAM_MODE_PARALLEL    */
};

/*
** モードテーブル 30
**
** CAM_SET_RAIL3 (レールカメラＤ)
*/
static CameraMode  cam_mode_tbl30[] = {
    { CAM_FUNC_SUBJ4,  6, cam_param_list107 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 31
**
** CAM_SET_START0 (開始カメラＡ)
*/
static CameraMode  cam_mode_tbl31[] = {
    { CAM_FUNC_UNIQ0,  1, cam_param_list99  },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 32
**
** CAM_SET_START1 (開始カメラＢ)
*/
static CameraMode  cam_mode_tbl32[] = {
    { CAM_FUNC_UNIQ0,  1, cam_param_list108 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 33
**
** CAM_SET_FREE0 (自由カメラＡ)
*/
static CameraMode  cam_mode_tbl33[] = {
    { CAM_FUNC_UNIQ6,  1, cam_param_list109 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 34
**
** CAM_SET_FREE2 (自由カメラＣ)
*/
static CameraMode  cam_mode_tbl34[] = {
    { CAM_FUNC_UNIQ6,  1, cam_param_list110 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 35
**
** CAM_SET_CIRCLE4 (定点カメラＥ)
*/
static CameraMode  cam_mode_tbl35[] = {
    { CAM_FUNC_FIXD2,  5, cam_param_list111 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 36
**
** CAM_SET_CIRCLE5 (定点カメラＦ)
*/
static CameraMode  cam_mode_tbl36[] = {
    { CAM_FUNC_UNIQ2,  4, cam_param_list112 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_UNIQ2,  4, cam_param_list113 },	/* CAM_MODE_PARALLEL    */
};

/*
** モードテーブル 37
**
** CAM_SET_DEMO0 (デモカメラＡ)
*/
static CameraMode  cam_mode_tbl37[] = {
    { CAM_FUNC_DEMO1,  1, cam_param_list114 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 38
**
** CAM_SET_DEMO1 (デモカメラＢ)
*/
static CameraMode  cam_mode_tbl38[] = {
    { CAM_FUNC_DEMO2,  1, cam_param_list114 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 39
**
** CAM_SET_MORI1 (森ダンカメラＡ)
*/
static CameraMode  cam_mode_tbl39[] = {
    { CAM_FUNC_PARA1, 11, cam_param_list115 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_PARA3,  1, cam_param_list116 },	/* CAM_MODE_TALK        */
};

/*
** モードテーブル 40
**
** CAM_SET_ITEM0 (お宝カメラＡ)
*/
static CameraMode  cam_mode_tbl40[] = {
    { CAM_FUNC_DEMO3,  3, cam_param_list117 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 41
**
** CAM_SET_ITEM1 (お宝カメラＢ)
*/
static CameraMode  cam_mode_tbl41[] = {
    { CAM_FUNC_DEMO4,  3, cam_param_list117 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 42
**
** CAM_SET_DEMO3 (デモカメラＤ)
*/
static CameraMode  cam_mode_tbl42[] = {
    { CAM_FUNC_DEMO9,  1, cam_param_list118 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 43
**
** CAM_SET_DEMO4 (デモカメラＥ)
*/
static CameraMode  cam_mode_tbl43[] = {
    { CAM_FUNC_DEMO5,  1, cam_param_list114 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 44
**
** CAM_SET_UFOBEAN (豆ＵＦＯカメラ)
*/
static CameraMode  cam_mode_tbl44[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list119 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list120 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list24  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list121 },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list122 },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list123 },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list124 },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 45
**
** CAM_SET_LIFTBEAN (豆リフトカメラ)
*/
static CameraMode  cam_mode_tbl45[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list125 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list126 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list24  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list127 },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list128 },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list129 },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list130 },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 46
**
** CAM_SET_SCENE0 (切替カメラＡ)
*/
static CameraMode  cam_mode_tbl46[] = {
    { CAM_FUNC_SPEC9,  3, cam_param_list131 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 47
**
** CAM_SET_SCENE1 (切替カメラＢ)
*/
static CameraMode  cam_mode_tbl47[] = {
    { CAM_FUNC_UNIQ2,  4, cam_param_list132 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 48
**
** CAM_SET_HIDAN1 (火ダンカメラＡ)
*/
static CameraMode  cam_mode_tbl48[] = {
    { CAM_FUNC_SPEC7,  1, cam_param_list99  },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 49
**
** CAM_SET_HIDAN2 (火ダンカメラＢ)
*/
static CameraMode  cam_mode_tbl49[] = {
    { CAM_FUNC_SPEC4,  1, cam_param_list114 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 50
**
** CAM_SET_MORI2 (森ダンカメラＢ)
*/
static CameraMode  cam_mode_tbl50[] = {
    { CAM_FUNC_UNIQ5,  1, cam_param_list114 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 51
**
** CAM_SET_MORI3 (森ダンカメラＣ)
*/
static CameraMode  cam_mode_tbl51[] = {
    { CAM_FUNC_DEMO6,  1, cam_param_list114 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 52
**
** CAM_SET_TAKO (大だこカメラ)
*/
static CameraMode  cam_mode_tbl52[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list133 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list35  },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list36  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list134 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list40  },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list25  },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list41  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list38  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list43  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list44  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list39  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list42  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list135 },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 53
**
** CAM_SET_SPOT05A (ＳＰＯＴ０５Ａ)
*/
static CameraMode  cam_mode_tbl53[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list136 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list137 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_TALK        */
    { CAM_FUNC_PARA1, 11, cam_param_list138 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_NORM1, 10, cam_param_list139 },	/* CAM_MODE_CLIMB       */
};

/*
** モードテーブル 54
**
** CAM_SET_SPOT05B (ＳＰＯＴ０５Ｂ)
*/
static CameraMode  cam_mode_tbl54[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list140 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list141 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_TALK        */
    { CAM_FUNC_PARA1, 11, cam_param_list142 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_NORM1, 10, cam_param_list143 },	/* CAM_MODE_CLIMB       */
};

/*
** モードテーブル 55
**
** CAM_SET_HIDAN3 (火ダンカメラＣ)
*/
static CameraMode  cam_mode_tbl55[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list144 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list145 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_TALK        */
    { CAM_FUNC_PARA1, 11, cam_param_list146 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_NORM1, 10, cam_param_list147 },	/* CAM_MODE_CLIMB       */
};

/*
** モードテーブル 56
**
** CAM_SET_ITEM2 (お宝カメラＣ)
*/
static CameraMode  cam_mode_tbl56[] = {
    { CAM_FUNC_KEEP4,  9, cam_param_list148 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 57
**
** CAM_SET_CIRCLE6 (定点カメラＧ)
*/
static CameraMode  cam_mode_tbl57[] = {
    { CAM_FUNC_SPEC0,  2, cam_param_list149 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 58
**
** CAM_SET_NORMAL2 (通常カメラＣ)
*/
static CameraMode  cam_mode_tbl58[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list150 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list24  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 59
**
** CAM_SET_FISHING (釣りカメラ)
*/
static CameraMode  cam_mode_tbl59[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list151 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list152 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_BATT1, 12, cam_param_list153 },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list154 },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list153 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list155 },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list156 },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list158 },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list159 },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list157 },	/* CAM_MODE_FREEFALL    */
};

/*
** モードテーブル 60
**
** CAM_SET_DEMOC (デモカメラ梅)
*/
static CameraMode  cam_mode_tbl60[] = {
    { CAM_FUNC_UNIQ9,  1, cam_param_list160 },	/* CAM_MODE_NORMAL      */
};

/*
** モードテーブル 61
**
** CAM_SET_UO_FIBER (魚神経カメラ)
*/
static CameraMode  cam_mode_tbl61[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list161 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list162 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 62
**
** CAM_SET_DUNGEON2 (洞窟カメラＣ)
*/
static CameraMode  cam_mode_tbl62[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list163 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list164 },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list36  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list165 },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list168 },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list25  },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list169 },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list166 },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list170 },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list171 },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list167 },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list172 },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list173 },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 63
**
** CAM_SET_TEPPEN (前見ないカメラ)
*/
static CameraMode  cam_mode_tbl63[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list174 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list175 },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list176 },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list4   },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
** モードテーブル 64
**
** CAM_SET_CIRCLE7 (定点カメラＨ)
*/
static CameraMode  cam_mode_tbl64[] = {
    { CAM_FUNC_FIXD4,  5, cam_param_list98  },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_FIXD4,  5, cam_param_list98  },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list3   },	/* CAM_MODE_TALK        */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_NONE,   0, NULL              },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
};

/*
** モードテーブル 65
**
** CAM_SET_NORMAL4 (通常カメラＥ)
*/
static CameraMode  cam_mode_tbl65[] = {
    { CAM_FUNC_NORM1, 10, cam_param_list150 },	/* CAM_MODE_NORMAL      */
    { CAM_FUNC_PARA1, 11, cam_param_list1   },	/* CAM_MODE_PARALLEL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list2   },	/* CAM_MODE_KEEPON      */
    { CAM_FUNC_KEEP3, 12, cam_param_list177 },	/* CAM_MODE_TALK        */
    { CAM_FUNC_BATT1, 12, cam_param_list24  },	/* CAM_MODE_BATTLE      */
    { CAM_FUNC_JUMP2,  9, cam_param_list5   },	/* CAM_MODE_CLIMB       */
    { CAM_FUNC_SUBJ3,  9, cam_param_list6   },	/* CAM_MODE_SUBJECT     */
    { CAM_FUNC_SUBJ3,  9, cam_param_list7   },	/* CAM_MODE_BOWARROW    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list8   },	/* CAM_MODE_BOWARROWZ   */
    { CAM_FUNC_SPEC5,  8, cam_param_list9   },	/* CAM_MODE_FOOKSHOT    */
    { CAM_FUNC_SUBJ3,  9, cam_param_list10  },	/* CAM_MODE_BOOMERANG   */
    { CAM_FUNC_SUBJ3,  9, cam_param_list11  },	/* CAM_MODE_PACHINCO    */
    { CAM_FUNC_JUMP2,  9, cam_param_list12  },	/* CAM_MODE_CLIMBZ      */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_JUMP        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list14  },	/* CAM_MODE_HANG        */
    { CAM_FUNC_UNIQ1,  7, cam_param_list15  },	/* CAM_MODE_HANGZ       */
    { CAM_FUNC_JUMP1,  8, cam_param_list13  },	/* CAM_MODE_FREEFALL    */
    { CAM_FUNC_BATT4,  7, cam_param_list17  },	/* CAM_MODE_CHARGE      */
    { CAM_FUNC_NORM1, 10, cam_param_list18  },	/* CAM_MODE_STILL       */
    { CAM_FUNC_PARA1, 11, cam_param_list19  },	/* CAM_MODE_PUSHPULL    */
    { CAM_FUNC_KEEP1, 13, cam_param_list20  },	/* CAM_MODE_BOOKEEPON   */
};

/*
## コントロールテーブル
##
*/
static CameraCtlList cam_ctl_tbl_0[CAM_SET_NUM] = {
  { 0x00000000, NULL           }, /* CAM_SET_NONE        (ダミー)         */
  { 0x051fffff, cam_mode_tbl1  }, /* CAM_SET_NORMAL0     (通常カメラＡ)   */
  { 0x051fffff, cam_mode_tbl2  }, /* CAM_SET_NORMAL1     (通常カメラＢ)   */
  { 0x051fffff, cam_mode_tbl3  }, /* CAM_SET_DUNGEON0    (洞窟カメラＡ)   */
  { 0x051fffff, cam_mode_tbl4  }, /* CAM_SET_DUNGEON1    (洞窟カメラＢ)   */
  { 0x050ff7ff, cam_mode_tbl5  }, /* CAM_SET_NORMAL3     (通常カメラＤ)   */
  { 0x8500018f, cam_mode_tbl6  }, /* CAM_SET_HORSE0      (馬カメラＡ)     */
  { 0x051fffff, cam_mode_tbl7  }, /* CAM_SET_BOSS_GOMA   (ボスゴーマカメラ) */
  { 0x051fffff, cam_mode_tbl8  }, /* CAM_SET_BOSS_DODO   (王ドドンゴカメラ) */
  { 0x051fffff, cam_mode_tbl9  }, /* CAM_SET_BOSS_BARI   (バリネードカメラ) */
  { 0x051fffff, cam_mode_tbl10 }, /* CAM_SET_BOSS_FGANON (幽霊ガノンカメラ) */
  { 0x051fffff, cam_mode_tbl11 }, /* CAM_SET_BOSS_BAL    (バルバジアカメラ) */
  { 0x051fffff, cam_mode_tbl12 }, /* CAM_SET_BOSS_SHADES (影ストーカカメラ) */
  { 0x051fffff, cam_mode_tbl13 }, /* CAM_SET_BOSS_MOFA   (モーファカメラ) */
  { 0x051fffff, cam_mode_tbl14 }, /* CAM_SET_BOSS_TWIN0  (双子老婆カメラ上) */
  { 0x051fffff, cam_mode_tbl15 }, /* CAM_SET_BOSS_TWIN1  (双子老婆カメラ下) */
  { 0x051fffff, cam_mode_tbl16 }, /* CAM_SET_BOSS_GANON1 (人ガノンカメラ) */
  { 0x051fffff, cam_mode_tbl17 }, /* CAM_SET_BOSS_GANON2 (豚ガノンカメラ) */
  { 0x851fffff, cam_mode_tbl18 }, /* CAM_SET_TOWER0      (塔カメラＡ)     */
  { 0x851fffff, cam_mode_tbl19 }, /* CAM_SET_TOWER1      (塔カメラＢ)     */
  { 0x8500000d, cam_mode_tbl20 }, /* CAM_SET_FIXED0      (固定カメラＡ)   */
  { 0x85000001, cam_mode_tbl21 }, /* CAM_SET_FIXED1      (固定カメラＢ)   */
  { 0x85000001, cam_mode_tbl22 }, /* CAM_SET_CIRCLE0     (定点カメラＡ)   */
  { 0x85000001, cam_mode_tbl23 }, /* CAM_SET_CIRCLE2     (定点カメラＣ)   */
  { 0x851e1fff, cam_mode_tbl24 }, /* CAM_SET_CIRCLE3     (定点カメラＤ)   */
  { 0x8c00000d, cam_mode_tbl25 }, /* CAM_SET_PREREND0    (ＰＲカメラＡ)   */
  { 0x8c00000d, cam_mode_tbl26 }, /* CAM_SET_PREREND1    (ＰＲカメラＢ)   */
  { 0x8c000001, cam_mode_tbl27 }, /* CAM_SET_PREREND3    (ＰＲカメラＤ)   */
  { 0xc5000001, cam_mode_tbl28 }, /* CAM_SET_DOOR0       (ドアカメラＡ)   */
  { 0xc5000003, cam_mode_tbl29 }, /* CAM_SET_DOORC       (ドアカメラ梅)   */
  { 0xc5000001, cam_mode_tbl30 }, /* CAM_SET_RAIL3       (レールカメラＤ) */
  { 0xc5000001, cam_mode_tbl31 }, /* CAM_SET_START0      (開始カメラＡ)   */
  { 0xc5000001, cam_mode_tbl32 }, /* CAM_SET_START1      (開始カメラＢ)   */
  { 0x05000001, cam_mode_tbl33 }, /* CAM_SET_FREE0       (自由カメラＡ)   */
  { 0x05000001, cam_mode_tbl34 }, /* CAM_SET_FREE2       (自由カメラＣ)   */
  { 0x85000001, cam_mode_tbl35 }, /* CAM_SET_CIRCLE4     (定点カメラＥ)   */
  { 0x05000003, cam_mode_tbl36 }, /* CAM_SET_CIRCLE5     (定点カメラＦ)   */
  { 0xce000001, cam_mode_tbl37 }, /* CAM_SET_DEMO0       (デモカメラＡ)   */
  { 0x4e000001, cam_mode_tbl38 }, /* CAM_SET_DEMO1       (デモカメラＢ)   */
  { 0x05000009, cam_mode_tbl39 }, /* CAM_SET_MORI1       (森ダンカメラＡ) */
  { 0x45000001, cam_mode_tbl40 }, /* CAM_SET_ITEM0       (お宝カメラＡ)   */
  { 0x45000001, cam_mode_tbl41 }, /* CAM_SET_ITEM1       (お宝カメラＢ)   */
  { 0x45000001, cam_mode_tbl42 }, /* CAM_SET_DEMO3       (デモカメラＤ)   */
  { 0x45000001, cam_mode_tbl43 }, /* CAM_SET_DEMO4       (デモカメラＥ)   */
  { 0x451fffff, cam_mode_tbl44 }, /* CAM_SET_UFOBEAN     (豆ＵＦＯカメラ) */
  { 0x451fffff, cam_mode_tbl45 }, /* CAM_SET_LIFTBEAN    (豆リフトカメラ) */
  { 0xc5000001, cam_mode_tbl46 }, /* CAM_SET_SCENE0      (切替カメラＡ)   */
  { 0x45000001, cam_mode_tbl47 }, /* CAM_SET_SCENE1      (切替カメラＢ)   */
  { 0x05000001, cam_mode_tbl48 }, /* CAM_SET_HIDAN1      (火ダンカメラＡ) */
  { 0x45000001, cam_mode_tbl49 }, /* CAM_SET_HIDAN2      (火ダンカメラＢ) */
  { 0x45000001, cam_mode_tbl50 }, /* CAM_SET_MORI2       (森ダンカメラＢ) */
  { 0x45000001, cam_mode_tbl51 }, /* CAM_SET_MORI3       (森ダンカメラＣ) */
  { 0x451fffff, cam_mode_tbl52 }, /* CAM_SET_TAKO        (大だこカメラ)   */
  { 0x05000033, cam_mode_tbl53 }, /* CAM_SET_SPOT05A     (ＳＰＯＴ０５Ａ) */
  { 0x05000033, cam_mode_tbl54 }, /* CAM_SET_SPOT05B     (ＳＰＯＴ０５Ｂ) */
  { 0x05000033, cam_mode_tbl55 }, /* CAM_SET_HIDAN3      (火ダンカメラＣ) */
  { 0x4a000001, cam_mode_tbl56 }, /* CAM_SET_ITEM2       (お宝カメラＣ)   */
  { 0x05000001, cam_mode_tbl57 }, /* CAM_SET_CIRCLE6     (定点カメラＧ)   */
  { 0x051fffff, cam_mode_tbl58 }, /* CAM_SET_NORMAL2     (通常カメラＣ)   */
  { 0x0501e05f, cam_mode_tbl59 }, /* CAM_SET_FISHING     (釣りカメラ)     */
  { 0x45000001, cam_mode_tbl60 }, /* CAM_SET_DEMOC       (デモカメラ梅)   */
  { 0x051fffff, cam_mode_tbl61 }, /* CAM_SET_UO_FIBER    (魚神経カメラ)   */
  { 0x051fffff, cam_mode_tbl62 }, /* CAM_SET_DUNGEON2    (洞窟カメラＣ)   */
  { 0x051fffff, cam_mode_tbl63 }, /* CAM_SET_TEPPEN      (前見ないカメラ) */
  { 0xc5000ecd, cam_mode_tbl64 }, /* CAM_SET_CIRCLE7     (定点カメラＨ)   */
  { 0x051fffff, cam_mode_tbl65 }, /* CAM_SET_NORMAL4     (通常カメラＥ)   */
};

#endif  /* __CAMERA_C_ */

#endif  /* __CAMERA_PARAM_DATA_H__ */

