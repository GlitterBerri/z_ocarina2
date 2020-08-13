/*  $Id: z_skin_type.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $ */
/*----------------------------------------------------------------------------
 *
 * スキン処理型設定
 *
 * Program:Kenji Matsutani
 *
 * $Log: z_skin_type.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.15  1998/05/18 04:04:05  matutani
 * *** empty log message ***
 *
 * Revision 1.14  1997-10-02 21:56:08+09  matutani
 * 新スキン対応
 *
 * Revision 1.13  1997/09/30  02:37:41  matutani
 * *** empty log message ***
 *
 * Revision 1.12  1997/09/29  12:30:15  matutani
 * *** empty log message ***
 *
 * Revision 1.11  1997/09/27  11:03:03  matutani
 * *** empty log message ***
 *
 * Revision 1.10  1997/09/24  07:29:31  matutani
 * 第２バージョンのための整理
 *
 * Revision 1.9  1997/09/22  04:09:15  matutani
 * *** empty log message ***
 *
 * Revision 1.8  1997/09/16  13:56:17  matutani
 * *** empty log message ***
 *
 * Revision 1.7  1997/09/10  13:40:54  matutani
 * *** empty log message ***
 *
 * Revision 1.6  1997/08/18  00:45:15  matutani
 * 法線処理
 *
 * Revision 1.5  1997/04/24  08:51:53  matutani
 * Skin_Vertexのposition削除
 *
 * Revision 1.4  1997/04/22  02:29:19  matutani
 * モデルのインデックスshortからunsiged char に変更
 *
 * Revision 1.3  1997/04/14  12:29:57  matutani
 * コメント訂正
 *
 * Revision 1.2  1997/03/28  12:13:16  matutani
 * 整理、シェイプ上のグローバル位置計算
 *
 * Revision 1.1  1997/03/25  07:45:17  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/
  
#ifndef INCLUDE_Z_SKIN_TYPE_H
#define INCLUDE_Z_SKIN_TYPE_H
 
#include"z_basic.h"
#include"z_soft_anim_tbl_type.h"
#include"z_skin_type_base.h"
#include"z_skelanime.h"
#include"z_skin_type_h.h"

/*===========================================================================
 *
 * 新バージョン構造体
 *
 *==========================================================================*/
/*-----------------------------------------------------------------------------
 *
 * エンベロープ
 *
 *---------------------------------------------------------------------------*/
/*
 * envelope2
 * 位置計算用データ
 */
typedef struct skin_envelpe2 {
    unsigned char jnt_index; /* 関連づけるジョイントへのインデックス */
    /* 
     * 関連づけたジョイントからの初期位置関係ベクトルに、
     * 初期のglobalのrotマトリックスの逆行列を掛けたベクトル。
     */
    Skin_SPoint init_offset; 
    char cw; /* ウエイト値 */
} Skin_Envelope2;

/*----------------------------------------------------------------------------
 *
 * GameGen Indexテーブル
 *
 *--------------------------------------------------------------------------*/
/*
 * GameGenから出された,Vtxテーブルへのindex,テーブルにして使う。
 * 他の頂点情報設定データ
 */
typedef struct skin_gg_vtx2 {
    unsigned short index; /* GameGenのVtxへのインデックス */

    short tc[2]; /* テクスチャ座標 */
    /*
     * 各頂点の法線ベクトル:
     * 法線ベクトルに、関連づけたジョイントのglobalのrotマトリックスの
     * の逆行列を掛け,自分のジョイントのグローバルマトリックスのrotを掛けた
     * ベクトル。(要熟考)
     */
    signed char nx; /* 法線ベクトルx,y,z */
    signed char ny;
    signed char nz;
    unsigned char a; /* アルファ:Vtxデータそのまま */
} Skin_GG_Vtx2;

/*----------------------------------------------------------------------------
 *
 * Vertex
 *
 *--------------------------------------------------------------------------*/
/*
 * Vertex
 * ツール内ではcsisk_vertexを使う。
 */
typedef struct skin_vertex2 {
    /*
     * GameGen情報
     */
    unsigned short gg_vtx_num; /* GameGenのVtxテーブルへのサイズ */
    unsigned short nb_envdata; /* ジョイント数 */
    unsigned short max_weight_index; /* ウエイト値が最大のindex */
    
    Skin_GG_Vtx2 *gg_vtx_tbl; /* GameGenのVtxテーブルへのポインター */
    Skin_Envelope2 *envdata_tbl; /* エンベロープデータへのポインター */
 
} Skin_Vertex2;

/*-----------------------------------------------------------------------------
 *
 * Skin Mesh
 *
 *---------------------------------------------------------------------------*/
/*
 * スキン用メッシュ情報
 */
typedef struct skin_mesh2 {
    unsigned short nbGfxVertices; /* Vtx頂点テーブルサイズ */
    unsigned short nbVertices; /* 頂点数 */
    Skin_Vertex2 *vertices; /* 頂点への配列 */
    Gfx *gfx; /* gfxへのポインター */
} Skin_Mesh2;

/*----------------------------------------------------------------------------
 *
 * モデルのタイプ
 * DkitのtypeModel.hのDK_ModelTypeとの整合させる 
 *
 *--------------------------------------------------------------------------*/
typedef enum {
    SKIN_MDL_LINK = -1, /* a temporary link for the rendering */
    SKIN_MDL_NILL,      /* a NULL node */
    SKIN_MDL_PTCH,      /* a Patch node */
    SKIN_MDL_FACE,      /* a Face node */
    SKIN_MDL_PMSH,      /* a Pmesh node (no more used) */
    SKIN_MDL_MESH,      /* a Super-mesh node */
    SKIN_MDL_JNT,       /* a Joint node for skeleton animation */
    SKIN_MDL_SPLN,      /* a spline !!!! */
    SKIN_MDL_META,	/* a MetaSystem node */
    SKIN_MDL_BALL,	/* a Metaball node */
    SKIN_MDL_CRV,	/* NURBS curve node */
    SKIN_MDL_SRF,	/* NURBS surface node */
    GFX_MDL_MESH        /* gfx (u64)のテーブルへのポインター */
} Skin_ModelType;

/*---------------------------------------------------------------------------
 *
 * model
 *
 *-------------------------------------------------------------------------*/  
typedef struct skin_model2 {
    Skin_SVector trs; /* ストラクチャートランスレート位置 100倍値 */

    unsigned char child_index; /* 子供のモデル番号 */
    unsigned char sibling_index; /* 兄弟のモデル番号 */
    
    Skin_ModelType type; /* 定義データのポインター先で定義されているタイプ */

    /* 定義データ(形状やディスプレイリストなど):typeを参照してキャスト  */
    Skin_Pointer definition;
} Skin_Model2;

/*---------------------------------------------------------------------------
 *
 * 情報構造体
 *
 *--------------------------------------------------------------------------*/
struct skin_info2 {
    Skin_Model2 **mdl_tbl; /* モデルテーブルへのポインター */
    unsigned char mdl_num; /* モデル数 */
};

/*---------------------------------------------------------------------------
 *
 * Skin Animation Work Vtx Buffer
 *
 *--------------------------------------------------------------------------*/
/*
 * スキン用作業用頂点バッファー
 */
typedef struct skin_animation_vtx_buffer {
    char current; /* 0 or 1 */
    /*
     * 存在無いところはNULL
     */
    Vtx *buf[2];
} Skin_avb;

/*----------------------------------------------------------------------------
 *
 * Skin Animation Work Buffer
 *
 *---------------------------------------------------------------------------*/

/*
 * スキン作業バッファー
 */
typedef struct skin_animation_work_buffer2 {
    Skin_Info2 *pskin_info; /* スキン情報 */
    
    /*
     * アクターデータより。一番大元のスケール（１／１００）,
     * トランスレート,回転込のマトリックス
     */
    Skin_Matrix root_matrix; 
    
    /*
     * 頂点関連
     */
    /*
     * モデル数
     */
    int mdl_num; /* for E3 */
    /*
     * 頂点バッファーのテーブル:game_alloc() 物体数分だけつくり、
     */
    Skin_avb *avb_tbl;
    
    /*
     * スケルトン情報
     * アニメーションデータ処理用
     */
    Skeleton_Info skeleton_info;
    
} Skin_AnimationWorkBuffer2;

/*============================================================================
 *
 * 旧バージョン構造体
 *
 *===========================================================================*/
/*-----------------------------------------------------------------------------
 *
 * エンベロープ
 *
 *---------------------------------------------------------------------------*/
/*
 * envelope
 */
typedef struct skin_envelpe {
    unsigned char jnt_index; /* ジョイントへのインデックス */
    Skin_SPoint init_offset; /* ジョイントからの初期位置(short) */
    char cw; /* ウエイト値 */
} Skin_Envelope;

/*----------------------------------------------------------------------------
 *
 * Vertex
 *
 *--------------------------------------------------------------------------*/

/*
 * Vertex
 * ツール内ではcsisk_vertexを使う。
 */
typedef struct skin_vertex {
#if 0
    Skin_SPoint position; /* 頂点位置(short) */
#endif
    short nb_envdata; /* ジョイント数 */
    /* ウエイト値が最大のエンベロープデータへのポインター */
    short max_weight_index; 
    Skin_Envelope *envdata_tbl; /* エンベロープデータへのポインター */
} Skin_Vertex;

/*----------------------------------------------------------------------------
 *
 * Polygon
 *
 *--------------------------------------------------------------------------*/

/*
 * Polygon
 */
typedef struct skin_polygon {
    short material; /* マテリアルインデックス from model */
    
    short v[3]; /* 頂点インデックス */
    Skin_SVector n[3]; /* 各頂点の法線ベクトル */
    /* st 座標 */
    short sTxt[3];
    short tTxt[3];
   
} Skin_Polygon;

/*-----------------------------------------------------------------------------
 *
 * Mesh
 *
 *---------------------------------------------------------------------------*/

/* エンベロープデータなし */
#define Z_SKIN_TYPE_MESH_SOLID_FLAG (1<<0)

typedef struct skin_mesh {
    short nbVertices;
    Skin_Vertex *vertices; /* 頂点への配列 :newで確保 */
    short nbPolygons;
    Skin_Polygon *polygons; /* ポリゴンへの配列 */

} Skin_Mesh;



/*---------------------------------------------------------------------------
 *
 * model
 *
 *-------------------------------------------------------------------------*/  

typedef struct skin_model {
    Skin_SVector trs; /* 原型トランスレート位置 100倍 */

    unsigned char child_index; /* 子供のモデル番号 */
    unsigned char sibling_index; /* 兄弟のモデル番号 */
    
    Skin_ModelType type; /* 定義データのポインター先で定義されているタイプ */

    /* 定義データ(形状やディスプレイリストなど)  */
    Skin_Pointer definition;
} Skin_Model;

/*-------------------------------------------------------------------------
 *
 * material
 *
 *--------------------------------------------------------------------------*/
typedef struct skin_material {
    /* カラー */
    Skin_Color32 ambient;

    /* テクスチャ─ */
    unsigned int timg; /* ポインタ */
    unsigned char fmt;
    unsigned char size_type;
    unsigned int width, height;
    unsigned int pal;
    unsigned int cms, cmt;
    unsigned int masks, maskt;
    unsigned int shifts, shiftt;
    
} Skin_Material;

/*---------------------------------------------------------------------------
 *
 * 情報構造体
 *
 *---------------------------------------------------------------------------*/
typedef struct skin_info {
    Skin_Model **mdl_tbl; /* モデルテーブルへのポインター */
    unsigned char mdl_num; /* モデル数 */
    unsigned char root_mdl_index; /* ルートモデルのインデックス */

    SoftAnimTblInfo *anm_tbl; /* アニメーション構造体へのポインター */
    
    short material_num; /* マテリアル数 */
    Skin_Material *skin_material_tbl; /* テーブルへのポインター */
} Skin_Info;

/*----------------------------------------------------------------------------
 *
 * 作業バッファー構造体
 *
 *---------------------------------------------------------------------------*/
/*
 * 頂点バッファー要素
 */
typedef struct skin_animation_vertex_buffer_element {
    Skin_SPoint pos; /* 頂点位置 */
} Skin_Animation_Vertex_Buffer_Element;

/*
 * 頂点バッファー
 */
typedef struct skin_animation_vertex_buffer {
    short num; /* 頂点数 */
    /* 頂点テーブル:存在しない場合 NULL */
    Skin_Animation_Vertex_Buffer_Element *pos_tbl; 
} Skin_Animation_Vertex_Buffer;

/*
 * アニメーションバッファー
 */
typedef struct skin_animation_work_buffer {
    Skin_Info *pskin_info; /* スキン情報 */
    
    /*
     * 一番大元のスケール（１／１００）,
     * トランスレート,回転込のマトリックス
     */
    Skin_Matrix root_matrix; 
    
    unsigned char mdl_num; /* 物体数 */
    float current_frame; /* 現在のフレーム */
    
    /* 頂点バッファーのテーブル:game_alloc() 物体数分だけつくる */
    Skin_Animation_Vertex_Buffer *vtx_tbl;
    
} Skin_AnimationWorkBuffer;

typedef enum {
    SKIN_OK,
    SKIN_ERR_MEMORY,
    SKIN_ERR_NO_INV_MATRIX
} Skin_Error;

#endif

/*** z_skin_type.h end ***/
