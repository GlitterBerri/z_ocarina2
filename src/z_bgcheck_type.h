/* $Id: z_bgcheck_type.h,v 2.1 1998/10/22 11:45:49 zelda Exp $ */
/* $Log: z_bgcheck_type.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.55  1998/06/29 13:31:55  matutani
 * Dyna_Poly_Actorのmin_y, max_y追加
 *
 * Revision 1.54  1998-06-25 21:45:24+09  matutani
 * Bounding Box構造体に整理
 *
 * Revision 1.53  1998-06-24 22:27:31+09  matutani
 * BoundingBox XYZ
 *
 * Revision 1.52  1998-06-23 22:04:29+09  matutani
 * *** empty log message ***
 *
 * Revision 1.51  1998-06-16 17:46:18+09  matutani
 * *** empty log message ***
 *
 * Revision 1.50  1998-05-30 16:52:54+09  matutani
 * コメント（Water_Info）
 *
 * Revision 1.49  1998-05-14 13:56:16+09  matutani
 * DYNA_ACTOR_NUMを５０にした。
 *
 * Revision 1.48  1998-05-14 12:16:09+09  matutani
 * DYNA_ACTOR_NUMを５０にした。
 *
 * Revision 1.47  1998-05-13 22:33:20+09  matutani
 * DYNA_ACTOR_NUMを４０に増やしました。
 *
 * Revision 1.46  1998-04-15 15:20:01+09  matutani
 * *** empty log message ***
 *
 * Revision 1.45  1998-03-18 10:32:04+09  takahata
 * *** empty log message ***
 *
 * Revision 1.44  1998/03/06  11:29:06  matutani
 * 変更点１
 * お店、ＶＲ─ＢＯＸ＋ＰＲ、ＶＲ─ＢＯＸの時、BGチェックのバッファーを
 * １５ＫＢしか取らなくしました。
 *
 * 変更点２
 * マップにポリゴンが少ないときにチェックで使うメッシュの個数を２x２x２に
 * する、処理追加。（場所によって処理が増えているところがあるかも知れませ
 * ん。注意してください）
 *
 * Revision 1.43  1998/02/24  02:57:21  matutani
 * *** empty log message ***
 *
 * Revision 1.42  1998/02/13  12:00:40  matutani
 * *** empty log message ***
 *
 * Revision 1.41  1998/02/13  06:06:22  matutani
 * 砂嵐
 *
 * Revision 1.40  1998/01/29  12:00:03  matutani
 * 矢系当らないフラグ
 *
 * Revision 1.39  1998/01/21  01:31:51  matutani
 * コメント訂正
 *
 * Revision 1.38  1998/01/12  11:42:46  matutani
 *  フックショット刺さるコード
 *
 * Revision 1.37  1997/12/25  09:39:43  matutani
 * *** empty log message ***
 *
 * Revision 1.36  1997/12/24  09:59:30  matutani
 * 横穴
 *
 * Revision 1.35  1997/12/03  08:29:54  matutani
 * 水情報／ビット増やした
 *
 * Revision 1.34  1997/11/16  14:09:02  matutani
 * moveBG処理減らし
 *
 * Revision 1.33  1997/11/13  06:05:57  matutani
 * 馬侵入禁止追加
 *
 * Revision 1.32  1997/11/07  00:33:49  matutani
 * *** empty log message ***
 *
 * Revision 1.31  1997/11/06  07:02:26  matutani
 * *** empty log message ***
 *
 * Revision 1.30  1997/11/04  05:45:12  matutani
 * *** empty log message ***
 *
 * Revision 1.29  1997/10/18  14:26:02  matutani
 * *** empty log message ***
 *
 * Revision 1.28  1997/10/11  06:54:38  matutani
 * Water_Info:bit[ 5]: 8-12 環境
 *
 * Revision 1.27  1997/10/11  06:47:58  matutani
 * Water_Info: bit[ 4]: 8-11 環境
 *
 * Revision 1.26  1997/09/30  07:48:47  matutani
 * *** empty log message ***
 *
 * Revision 1.25  1997/09/26  06:37:52  matutani
 * Water_Info訂正
 *
 * Revision 1.24  1997/09/03  04:13:53  matutani
 * サウンドコード
 *
 * Revision 1.23  1997/08/18  00:51:56  matutani
 * 法線処理
 *
 * Revision 1.22  1997/08/04  08:34:37  matutani
 * 環境追加後
 *
 * Revision 1.21  1997/07/29  09:53:50  matutani
 * ダイナミックポリゴンテスト
 *
 * Revision 1.20  1997/07/25  06:23:02  matutani
 * 整理
 *
 * Revision 1.19  1997/07/23  12:39:01  matutani
 * *** empty log message ***
 *
 * Revision 1.18  1997/07/23  05:57:39  matutani
 * *** empty log message ***
 *
 * Revision 1.17  1997/07/19  10:42:19  matutani
 * ダイナミック当り
 *
 * Revision 1.16  1997/07/07  06:02:22  matutani
 * エラー
 *
 * Revision 1.15  1997/07/03  04:41:47  matutani
 * *** empty log message ***
 *
 * Revision 1.14  1997/07/03  04:39:58  matutani
 * *** empty log message ***
 *
 * Revision 1.13  1997/07/01  12:12:11  matutani
 * 天井チェックでポリゴンが返るようにする準備
 *
 * Revision 1.12  1997/06/30  13:26:42  matutani
 * 梯子UP追加
 *
 * Revision 1.11  1997/06/27  05:21:41  matutani
 * ダイナミックポリゴン／カメラ取得関数index版
 *
 * Revision 1.10  1997/06/26  00:37:16  matutani
 * 新規ポリゴンデータ
 *
 * Revision 1.9  1997/06/19  08:21:13  matutani
 * まだ未使用部分をはずした
 *
 * Revision 1.8  1997/06/18  13:09:35  matutani
 * *** empty log message ***
 *
 * Revision 1.7  1997/05/30  07:10:15  matutani
 * *** empty log message ***
 *
 * Revision 1.6  1997/05/30  02:49:01  matutani
 * *** empty log message ***
 *
 * Revision 1.5  1997/05/30  00:40:48  matutani
 * *** empty log message ***
 *
 * Revision 1.4  1997/05/26  04:28:43  matutani
 * ポリゴンカウンター
 *
 * Revision 1.3  1997/05/19  09:45:58  matutani
 * 床抜け禁止
 *
 * Revision 1.2  1996/11/11  08:33:24  matutani
 * BGチェック調整
 *
 * Revision 1.1  1996/10/28  10:25:16  matutani
 * Initial revision
 * */


/*----------------------------------------------------------------------------
 *
 * z_bgcheck_types.h
 *
 * Program:Kenji Matsutani
 * 1996/10/28
 *--------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_BGCHECK_TYPE_H
#define INCLUDE_Z_BGCHECK_TYPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_basic.h"

#include"z_bgcheck_short_slist.h"
#include"z_bgcheck_param.h"

/* ダイナミックポリゴンテスト */
#define DYNA_POLY_TEST

/* デバッグBSP */
#undef DEBUG_BSP_BGCHECK


/*==========================================================================
 *
 * BSP処理
 *
 *=========================================================================*/

/*----------------------------------------------------------------------------
 *
 * BGチェック用Vertex構造体
 *
 *---------------------------------------------------------------------------*/

typedef struct t_vertex {
    s_xyz pos; /* 位置情報 */
} T_Vertex;

/*----------------------------------------------------------------------------
 *
 * BGチェック用Polygon構造体 
 *
 *---------------------------------------------------------------------------*/

/* チェック対象 */
typedef unsigned short Check_Mask;

typedef struct t_polygon {
    
    unsigned short info; /* ポリゴン情報へのインデックス */
    
    unsigned short v[3]; /* 頂点テーブルへのインデックス */
    /*
     * 頂点インデックスの上位3ビットをチェックのON/OFFフラグにする。
     * v[0]
     *  サイズ:領域
     * bit[13]: 0-12 頂点インデックス
     * bit[ 1]:13    カメラ当たらない
     * bit[ 1]:14    Obj当たらない
     * bit[ 1]:15    Arrow系当らない
     *
     * v[1]
     *  サイズ:領域
     * bit[13]: 0-12 頂点インデックス
     * bit[ 1]:13    ベルトコンベアか？（これが立っていると水流でなくて、
     *               ベルトと判断する。 **new!!**
     * bit[2]:14-15  未定
     * 
     * v[2] 未定
     */
    
    /* 平面方程式のパラメーター */
    /* (a,b,c:-１から１を-32767から32767に展開 注意:-32768は使わない) */
    /* ax+by+cz+d = 0 */
    short a;
    short b;
    short c;

    short d; /* a, b, cとは異なり即値 */
  
} T_Polygon;


/*-------------------------------------------------------------------------
 *
 * ポリゴン情報テーブル
 *
 *------------------------------------------------------------------------*/
typedef struct polygon_info {
    unsigned int info[2];
    /*
     * 内容
     * info[0]
     *  サイズ: 領域
     * bit[ 8]: 0- 7 カメラ セット
     * bit[ 5]: 8-12 シーン切り替えコード
     * bit[ 5]:13-17 属性
     * bit[ 3]:18-20 天井
     * bit[ 5]:21-25 壁
     * bit[ 4]:26-29 床
     *         26-29:オートジャンプ(値:0-4) *** 拡張 ***
     * bit[ 1]:30    底上げ
     * bit[ 1]:31    馬侵入禁止
     *
     * info[1]
     * bit[ 4]: 0- 3 サウンド
     * bit[ 2]: 4- 5 摩擦 **空き**
     * bit[ 5]: 6-10 環境
     * bit[ 6]:11-16 エコー
     * bit[ 1]:17    フックショット刺さるコード
     * bit[ 3]:18-20 水流/ベルト パワーインデックス 
     *               インデックスが０の時は,水流/ベルトでない。
     *               インデックスが０でないときは,水流かベルトかを確認して,
     *               処理する。
     * bit[ 6]:21-26 角度（上のビットが０の時は空き？）
     * bit[ 1]:27    ダメージポリゴン *** new!! ***
     */
} Polygon_Info;




/*---------------------------------------------------------------------------
 *
 * BGチェック用Mesh構造体
 *
 *--------------------------------------------------------------------------*/
typedef struct t_mesh {
    short_SLIST ground;
    short_SLIST wall;
    short_SLIST roof;
} T_Mesh;

/*----------------------------------------------------------------------------
 *
 * カメラデータテーブル
 *
 *--------------------------------------------------------------------------*/
typedef struct camera_data {
    unsigned short type; /* タイプ */
    unsigned short num; /* データ数 */
    s_xyz *tbl; /* テーブルへのポインター */
} Camera_Data;

/*---------------------------------------------------------------------------
 *
 * 水情報
 *
 *--------------------------------------------------------------------------*/
typedef struct water_info {
    /* 最小位置 */
    s_xyz min_pos;
    /* xzサイズ */
    short size_x;
    short size_z;
    unsigned int info; /* 情報ビット */
    /*
     * info
     * bit[ 8]: 0- 7 カメラセット
     * bit[ 5]: 8-12 環境
     * bit[ 6]:13-18 部屋番号
     * bit[ 1]:19    環境ビットか？
     * bit[  ]:20-31 余り
     */
} Water_Info; 


/*----------------------------------------------------------------------------
 *
 *  BGチェック用BGDataInfo構造体
 * DynaPolyUty_inBgdi_SG2KSG()との対応をとっておく
 *
 *---------------------------------------------------------------------------*/
typedef struct t_bgdatainfo {
    
    /* 頂点の最大最小 */
    short vtx_min[3]; 
    short vtx_max[3]; 
    
    /* 頂点の個数 */
    unsigned short vtx_num;
    
    /* 頂点テーブルへのポインター */
    T_Vertex *vtx_tbl;

    /* 面の個数 */
    unsigned short poly_num;
    
    /* ポリゴンテーブルへのポインター */
    T_Polygon *poly_tbl;

    /* ポリゴン情報テーブル */
    Polygon_Info *poly_info_tbl;

    /* カメラデータテーブル */
    Camera_Data *camera_data_tbl;

    /* 水情報ポリゴン数 */
    unsigned short water_info_num;
    
    /* 水情報テーブル */
    Water_Info *water_info_tbl;

} T_BGDataInfo;

/*--------------------------------------------------------------------------
 *
 * BG チェックバッファー
 *
 *------------------------------------------------------------------------*/

typedef struct bgcheck_alloc {
    
    unsigned short short_slist_node_size;
    unsigned short short_slist_node_last_index; /* ダイナミック処理用 */
    short_SLIST_NODE *short_slist_node_tbl;
    
    /* チェックバッファー:一枚のポリゴンについて１つのテーブル */
    char *polygon_check;
    
} BGCheckAlloc;

/*============================================================================
 *
 * ダイナミックポリゴン処理
 *
 *==========================================================================*/

/*---------------------------------------------------------------------------
 *
 * ダイナミックポリゴン:アクター/データ登録テーブル
 *
 *-------------------------------------------------------------------------*/
/*
 * vertex index 情報
 */
typedef struct dyna_vert_index_info {
    unsigned short start_index;
} Dyna_Vert_Index_Info;

/*
 * polygon index情報
 */
typedef struct dyna_poly_index_info {
    unsigned short start_index;
    short_SLIST roof;
    short_SLIST wall;
    short_SLIST ground;
} Dyna_Poly_Index_Info;

/*
 * shape情報
 */
typedef struct t_shape_srt {
    xyz_t scale;
    s_xyz rot;
    xyz_t trs;
} T_Shape_SRT;


typedef struct dyna_poly_actor {
    
    Actor *pactor; /* アクター */
    T_BGDataInfo *pbgdata; /* チェック形状 */

    /*
     * テーブルになるので,ポリゴンテーブルの場合,アクターテーブルの
     * index=0の時,０からdyna_poly_indexまで使用,
     * index=1の時,dyna_poly_inde(index = 0) - 1からdyna_poly_index(index = 1)
     * まで使用
     */
    Dyna_Poly_Index_Info poly; /* ポリゴンインデックス */
    Dyna_Vert_Index_Info vert; /* 頂点インデックス */
    T_Shape_SRT old_srt; /* 前の状態 */
    T_Shape_SRT now_srt;

    Math3D_sphere bounding_sph; /* 包む球 */
    float min_y, max_y; /* 高さ最大最小 */
} Dyna_Poly_Actor; 

/*----------------------------------------------------------------------------
 *
 * ポリゴンテーブル管理構造体
 *
 *--------------------------------------------------------------------------*/
typedef struct dyna_poly_tbl {
    T_Polygon *pbuf; /* ポリゴンバッファー:game_allocを使用 */ 
} Dyna_Poly_Tbl;

/*--------------------------------------------------------------------------
 *
 * 頂点テーブル管理構造体
 *
 *-------------------------------------------------------------------------*/
typedef struct dyna_vert_tbl {
    T_Vertex *pbuf; /* 頂点バッファー:game_allocを使用 */
} Dyna_Vert_Tbl;

/*--------------------------------------------------------------------------
 *
 * bit_info 作業ビット情報内容
 *
 *------------------------------------------------------------------------*/
/*
 * デフォルト値
 */
#define BG_DPI_BIT_INFO_DEFAULT (BG_DPI_BIT_INFO_DATA_RECONSTRUCT)

/*
 * アクターの削除などによる頂点／ポリゴンテーブルの再セットが必要になった。
 * 場合に立てる。
 * expand内でこのビットが立っていると展開処理を省略しない。
 * expnad後にこのビットはクリアされる。
 */
#define BG_DPI_BIT_INFO_DATA_RECONSTRUCT (1<<0)
/*--------------------------------------------------------------------------
 *
 * ダイナミックポリゴン管理構造体
 *
 *-------------------------------------------------------------------------*/
    
/* ダイナミックポリゴンアクター:個数 増やすとclobberした方がいいでしょう。 */
#define DYNA_ACTOR_NUM (50)
    
/*
 * 構造体
 */
typedef struct dyna_poly_info {
    unsigned char bit_info; /* 作業ビット情報 */
    Dyna_Poly_Actor tbl[DYNA_ACTOR_NUM]; /* アクターテーブル */
    unsigned short mask_tbl[DYNA_ACTOR_NUM]; /* チェック用マスク */

    Dyna_Poly_Tbl poly_tbl; /* ポリゴンテーブル */
    Dyna_Vert_Tbl vert_tbl; /* 頂点テーブル */
    
    short_SLIST_TBL short_slist; /* short slist テーブル */

    /* メモリ確保サイズ */
    int sst_size;
    int poly_num;
    int vert_num;
    
} Dyna_Poly_Info;

/*--------------------------------------------------------------------------
 *
 * ポリゴンデータブロック構造体
 *
 *--------------------------------------------------------------------------*/
typedef struct poly_data_block {
    int actor_index;
    T_Polygon *poly;
} PolyDataBlock;

/*---------------------------------------------------------------------------
 *
 * キャッシュデータブロック構造体
 *
 * メモ：
 * countにはデータが入っていないとき-1が入っている。
 *
 *--------------------------------------------------------------------------*/
typedef struct cache_data_block {
    PolyDataBlock pdb;
    int count;
} CacheDataBlock;

#define LINE_CACHE_SIZE 10
/*---------------------------------------------------------------------------
 *
 * BGチェックテストキャッシュ
 *
 *--------------------------------------------------------------------------*/
typedef struct t_bgcheck_cache {
    CacheDataBlock line[LINE_CACHE_SIZE]; /* ラインキャッシュ */
} T_BGCheck_Cache;

/*---------------------------------------------------------------------------
 *
 * BGチェック用BGCheckInfo
 *
 *--------------------------------------------------------------------------*/

typedef struct t_bgcheck {
    T_BGDataInfo *pbgdata; /* BGのデータ情報 */

    /* メッシュエリア最大最小位置 */
    xyz_t mesh_min_pos;
    xyz_t mesh_max_pos;

    /* メッシュ数 */
    int mesh_x_num;
    int mesh_y_num;
    int mesh_z_num;
    
    /* メッシュサイズ */
    float mesh_size_x;
    float mesh_size_y;
    float mesh_size_z;

    /* メッシュサイズ逆数 */
    float mesh_size_x_reciprocal;
    float mesh_size_y_reciprocal;
    float mesh_size_z_reciprocal;

    /* メッシュのテーブルへのポインター:分割数可変 */
    T_Mesh *mesh_tbl;
    
    /* BGチェックメモリバッファー */
    BGCheckAlloc bgcheck_alloc;

    /* ダイナミックポリゴンデータ情報 */
    Dyna_Poly_Info dyna_poly_info;


    /* For BGCheck Memory Size */
    unsigned long max_memory_size;
    
} T_BGCheck;  

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_bgcheck_type.h end ***/
