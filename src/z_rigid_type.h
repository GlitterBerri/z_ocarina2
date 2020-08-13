/*  $Id: z_rigid_type.h,v 2.1 1998/10/22 11:51:48 zelda Exp $ */
/*-----------------------------------------------------------------------------
 *
 *  リッジドモデル構造体
 *
 * Program:Kenji Matsutani
 *
 *$Log: z_rigid_type.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.9  1998/03/18 04:25:26  komatu
 *_LANGUAGE_C_PLUS_PLUSの追加
 *
 * Revision 1.8  1998/01/08  09:50:58  matutani
 * Rigid_Mdl_Info_SV追加
 *
 * Revision 1.7  1997/06/18  06:14:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.6  1997/06/18  02:48:39  matutani
 * Rigid_Mdl_Infoを追加
 *
 * Revision 1.5  1997/06/18  01:36:29  matutani
 * モデル情報追加
 *
 * Revision 1.4  1997/05/06  11:28:49  matutani
 * gfxの配列をgfxのポインターの配列に訂正
 *
 * Revision 1.3  1997/05/06  10:53:05  matutani
 * gfxを配列にしました。
 *
 * Revision 1.2  1997/04/30  00:50:22  iwawaki
 * 私が修正
 *
 * Revision 1.1  1997/04/25  07:29:13  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_RIGID_TYPE_H
#define INCLUDE_Z_RIGID_TYPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "u64basic.h"
#include"z_types.h"
#include"z_soft_anim_tbl_type.h"
#include"z_skin_type_base.h"

typedef enum {
    NORMAL, /* ノーマルディスプレイリスト */
    NORMAL_T, /* ノーマル＋透明 */
    LOD, /* ノーマル ＋ LOD */
    LOD_T /* (ノーマル＋透明) + (LOD + 透明) */
} Gfx_Type;

/*----------------------------------------------------------------------------
 *
 * model
 *
 *---------------------------------------------------------------------------*/
/*
 * 構造体
 */
typedef struct rigid_model {
    s_xyz trs; /* 原型トランスレート:内容１００倍値 */
    unsigned char child_index; /* 子供のモデル番号 */
    unsigned char sibling_index; /* 兄弟のモデル番号 */
} Rigid_Model;

/*
 * モデルテーブル用ポインター型宣言 
 */
typedef void * Rigid_ModelPointer;

/*---------------------------------------------------------------------------
 *
 * ノーマルディスプレイリスト
 *
 *-------------------------------------------------------------------------*/
typedef struct rigid_model_NORMAL {
    Rigid_Model mdl;

    Gfx *gfx[1]; /* ノーマル */
} Rigid_Model_NORMAL;

/*--------------------------------------------------------------------------
 *
 * （ノーマル＋透明）ディスプレイリスト
 *
 *--------------------------------------------------------------------------*/
typedef struct rigid_mode_NORMAL_T {
    Rigid_Model mdl;

    Gfx *gfx[2]; /* ノーマル、透明 */
} Rigid_Model_NORMAL_T;

/*----------------------------------------------------------------------------
 *
 * （ノーマル＋ＬＯＤ）ディスプレイリスト
 *
 *--------------------------------------------------------------------------*/
typedef struct rigid_model_LOD {
    Rigid_Model mdl;

    Gfx *gfx[2]; /* ノーマル,ＬＯＤ */
} Rigid_Model_LOD;

/*---------------------------------------------------------------------------
 *
 * (ノーマル＋透明) + (LOD + 透明)
 *
 *--------------------------------------------------------------------------*/
typedef struct rigid_model_LOD_T {
    Rigid_Model mdl;

    Gfx *gfx[4]; /* ノーマル、透明、ＬＯＤ,透明 */
} Rigid_Model_LOD_T;

/*---------------------------------------------------------------------------
 *
 * モデル情報
 *
 *--------------------------------------------------------------------------*/
typedef struct rigid_mdl_info {
    Rigid_ModelPointer *mdl_tbl; /* モデルテーブルへのポインター */
    unsigned char mdl_num; /* モデル数 */
} Rigid_Mdl_Info;

/*---------------------------------------------------------------------------
 *
 * shared vertex用モデル情報
 *
 *--------------------------------------------------------------------------*/
typedef struct rigid_mdl_info_sv {
    Rigid_Mdl_Info mdl_info; /* モデル情報 */
    unsigned char shape_num; /* シェイプ数 */
} Rigid_Mdl_Info_SV;

/*---------------------------------------------------------------------------
 *
 * 情報構造体
 *
 *---------------------------------------------------------------------------*/
typedef struct Rigid_Info {
    Rigid_Model **mdl_tbl; /* モデルテーブルへのポインター */
    Gfx_Type gfx_type_mask; /* モデル構造ディスプレイリストタイプ */
    unsigned char mdl_num; /* モデル数 */
    
    unsigned char root_mdl_index; /* ルートモデルのインデックス */

    SoftAnimTblInfo *anm_tbl; /* アニメーション構造体へのポイタ─ */
} Rigid_Info;
    
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_rigid_type.h end ***/
