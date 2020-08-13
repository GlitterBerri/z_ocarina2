/* $Id: z_collision_type.h,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $ */
/* $Log: z_collision_type.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.37  1998/09/05 14:00:12  matutani
 * *** empty log message ***
 *
 * Revision 1.36  1998-09-04 00:01:43+09  matutani
 * *** empty log message ***
 *
 * Revision 1.35  1998-08-25 20:51:00+09  matutani
 * 変更待ち特に変更点無し
 *
 * Revision 1.34  1998-07-14 21:36:03+09  matutani
 * Shield_Info削除
 *
 * Revision 1.33  1998-05-08 22:06:26+09  matutani
 * 順序整理
 *
 * Revision 1.32  1998-05-08 21:35:29+09  matutani
 * *** empty log message ***
 *
 * Revision 1.31  1998-04-30 19:31:43+09  matutani
 * 一部構造体変更
 * これ取ると全コンパイルしないと動きません。
 *
 * Revision 1.30  1998-04-29 15:14:05+09  matutani
 * コメント追加
 *
 * Revision 1.29  1998-03-18 12:00:44+09  ogawa
 * *** empty log message ***
 *
 * Revision 1.28  1998/03/17  07:31:37  kuzuhara
 * MAX_CLCH_AC_NUM 60に変更
 *
 * Revision 1.27  1998/03/09  13:37:13  matutani
 * ＯＣチェックの変更
 *
 * Revision 1.26  1998/02/26  02:40:49  matutani
 * *** empty log message ***
 *
 * Revision 1.25  1998/02/25  13:40:24  matutani
 * statusにoffset追加
 *
 * Revision 1.24  1998/02/11  11:58:44  matutani
 * *** empty log message ***
 *
 * Revision 1.23  1997/11/17  06:57:56  matutani
 * ヒット時位置補正準備
 *
 * Revision 1.22  1997/11/13  05:51:31  matutani
 * 追加／クリア停止処理
 *
 * Revision 1.21  1997/11/12  14:02:29  matutani
 * ヒット時のバック処理
 *
 * Revision 1.20  1997/11/10  06:39:35  matutani
 * 盾処理（ビット／簡易距離計算）／バトルデータ処理
 * 
 * Revision 1.19  1997/11/05  02:47:34  matutani
 * コリジョンデータ構造体
 *
 * Revision 1.18  1997/11/05  01:19:07  matutani
 * *** empty log message ***
 *
 * Revision 1.17  1997/11/04  12:53:58  matutanib_heart_2_modelT
 * ヒットマーク処理
 *
 * Revision 1.16  1997/10/31  03:06:21  matutani
 * ステータス／デバッグ表示
 *
 * Revision 1.15  1997/10/30  14:13:41  matutani
 * Status 構造体追加
 * Damage構造体さようなら。（予定）
 *
 * Revision 1.14  1997/10/30  08:00:46  matutani
 * *** empty log message ***
 *
 * Revision 1.13  1997/10/30  02:35:54  matutani
 * *** empty log message ***
 *
 * Revision 1.12  1997/10/29  13:57:44  matutani
 * 新版コリジョンチェックスタートバージョン
 *
 * Revision 1.11  1997/10/18  14:09:32  matutani
 * デバッグ開始
 *
 * Revision 1.10  1997/10/14  06:01:26  matutani
 * 打ち込み終了
 *
 * Revision 1.9  1997/10/13  05:03:22  matutani
 * *** empty log message ***
 *
 * Revision 1.8  1997/10/10  12:59:20  matutani
 * NewCollisionCheck 制作中
 *
 * Revision 1.7  1997/10/08  02:45:03  matutani
 * *** empty log message ***
 *
 * Revision 1.6  1997/10/08  01:38:13  matutani
 * CollisionCheck構造体
 *
 * Revision 1.5  1997/08/28  02:36:06  matutani
 * 攻撃タイプラベル追加
 *
 * Revision 1.4  1997/08/18  00:49:58  matutani
 * 法線処理
 *
 * Revision 1.3  1996/09/25  01:40:36  matutani
 * *** empty log message ***
 *
 * Revision 1.2  1996/09/24  13:02:41  matutani
 * *** empty log message ***
 *
 * Revision 1.1  1996/09/24  12:10:34  matutani
 * Initial revision
 *
 */
/*----------------------------------------------------------------------------
 *
 * z_collision_type.h
 * COLLISIONの構造体宣言
 * このヘッダーをインクルードする前にsys_math3d.hをインクルードしてください。
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_COLLISION_TYPE_H
#define INCLUDE_Z_COLLISION_TYPE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/*==========================================================================
 *
 * 新構造体Version3 (Version2は頓挫)
 *
 * 動作内容
 * 攻撃判定（剣など）                  AT 
 * 攻撃に対する当り判定(体など）       AC (Attack Collision)
 * OBJ同士のチェック（コリジョン）     OC (Object Collision)
 *
 *==========================================================================*/
/*===========================================================================
 *
 * 攻撃タイプ
 *
 *===========================================================================*/
/*----------------------------------------------------------------------------
 *
 * 攻撃タイプラベル(旧データ）
 *
 *---------------------------------------------------------------------------*/
typedef enum {
    CL_AT_LBL_NONE, /* なし */
    CL_AT_LBL_SWORD, /* 剣 */
    CL_AT_LBL_ARROW, /* 矢 */
    CL_AT_LBL_BOMB, /* 爆弾 */
    CL_AT_LBL_OTHERS, /* その他もろもろ */
    
    CL_AT_LBL_LAST_INDEX
} CL_AT_LBL;
/*===========================================================================
 *
 * 各当りの基本構造体
 * メモ：当たりを処理するときの１つのタイプにつき１つ持つ。
 *
 *=========================================================================*/
/*--------------------------------------------------------------------------
 *
 * DATAタイプ
 * z_collision_check.cのcollection_functionと対応しているので注意
 *
 *-------------------------------------------------------------------------*/
typedef enum cl_data_lbl {
    CL_DATA_LBL_JNT_SPH, /* 関節球 */
    CL_DATA_LBL_PIPE, /* パイプ１つ */
    CL_DATA_LBL_TRIS, /* 三角形数枚 */
    CL_DATA_LBL_SWRD, /* 剣データ */
    CL_DATA_LBL_LAST_INDEX
} CL_DATA_LBL;

#if 0
/* dead */
/*==========================================================================
 *
 * シールド情報
 *
 *==========================================================================*/
typedef struct shield_info {
    /* 有効範囲 */
    Math3D_pipe pipe; /* 円筒サイズ */
    short start_angle; /* 範囲角度:スタート位置 */
    short diff_angle; /* start_angleからの角度,正負両方OK */
} Shield_Info;
#endif

/*---------------------------------------------------------------------------
 *
 * ClObj情報構造体
 *
 * Actor *self : 自分のポインター
 * Actor *at_ac_actor : 命中先
 * Actor *ac_at_actor : 攻撃元
 * Acotr *oc_actor : コリジョンで補正した／されたアクターポインター
 *
 * unsigned char at_bit,ac_bit,oc_bit,oc_bit2 :
 *                                      情報ビットはz_collision_param.h参照
 * メモ:
 * *at_bit:攻撃関係
 * チェック,ヒット時ビット,ヒット対象グループ,その他
 * *ac_bit:攻撃対象関係
 * チェック,ヒット時ビット,盾ビット,ヒット対象グループ,その他
 * *oc_bit:キャラ同士の位置補正
 * チェック,ヒット時ビット,対象グループ,その他
 * *oc_bit2:キャラ同士の位置補正拡張
 * プレイヤーとのヒット,自己グループ
 *
 * unsigned char hit_mark_type: ヒットマーク デフォルトはCL_HM_HM1 
 *
 * unsigned char data_type :データ型
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj {
    /*
     * メモ
     * Actorと無関係な場合はNULLにしておく
     */
    Actor *self; /* 自分:OCの場合は補正対象 */
    Actor *at_ac_actor; /* 命中先 */
    Actor *ac_at_actor; /* 攻撃元 */
    Actor *oc_actor; /* 接触するアクター */
    
    /* 情報ビット */
    unsigned char at_bit;
    unsigned char ac_bit;
    unsigned char oc_bit;
    unsigned char oc_bit2;
    
    unsigned char hit_mark_type; /* ヒットマークパラメータ */
    unsigned char data_type; /* CL_DATA_LBL の内容を代入 */
} ClObj;

/*
 * 情報構x造体セット用データ構造体
 */
typedef struct cl_obj_data {
    Actor *self; /* 自分:OCの場合は補正対象 */

    /* 情報ビット */
    unsigned char at_bit;
    unsigned char ac_bit;
    unsigned char oc_bit;

    unsigned char data_type; /* CL_DATA_LBL の内容を代入 */
} ClObjData;

/*
 * 情報構造体セットデータ構造体:ヒットマーク追加
 * Version 3
 */
typedef struct cl_obj_datat3 {
    /* ヒットマーク */
    unsigned char hit_mark_type;

    /* 情報ビット */
    unsigned char at_bit;
    unsigned char ac_bit;
    unsigned char oc_bit;

    unsigned char data_type; /* CL_DATA_LBLの内容を代入 */
} ClObjData3;

/*
 * 情報構造体セットデータ構造体:oc_bit2追加
 * Version 4
 */
typedef struct cl_obj_data4 {
    /* ヒットマーク */
    unsigned char hit_mark_type;

    /* 情報ビット */
    unsigned char at_bit;
    unsigned char ac_bit;
    unsigned char oc_bit;
    unsigned char oc_bit2; /* 自己OC種別追加 */

    unsigned char data_type; /* CL_DATA_LBLの内容を代入 */
} ClObjData4;

/*---------------------------------------------------------------------------
 *
 * バトルデータ関連情報
 *
 *--------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------
 *
 * ATバトル情報
 *
 * unsigned long at_type : 攻撃タイプビット情報 z_collision_param.h 参照
 * 
 * unsigned char at_special : ヒット時特殊データ z_collision_param.h 参照
 * このデータは攻撃がヒットした相手に渡される。
 * unsigned char atp : 攻撃力 ダメージ値に加算
 *
 *--------------------------------------------------------------------------*/
typedef struct cle_at_btl_info {
    /* 入力 */
    unsigned long at_type; /* 攻撃タイプビット情報 */
    
    unsigned char at_special; /* ヒット時特殊データ:CLE_AT_SPECIAL_TYPE */
    unsigned char atp; /* 攻撃力 */
} CleAtBtlInfo;

/*--------------------------------------------------------------------------
 *
 * ATバトル情報データ部分
 *
 * 同上
 *
 *--------------------------------------------------------------------------*/
typedef struct cle_at_btl_info_data {
    unsigned long at_type;  /* 攻撃タイプビット情報 */
    unsigned char at_special; /* ヒット時特殊データ:CLE_AT_SPECIAL_TYPE  */
    unsigned char atp; /* 攻撃力 */
} CleAtBtlInfoData;

/*----------------------------------------------------------------------------
 *
 * ACバトル情報
 *
 * unsigned long at_type_mask : 攻撃ビット情報マスク
 *
 * unsigned char ac_special : 攻撃ヒット時特殊データ
 * このデータは攻撃した相手に渡される。
 *
 * unsigned char ac : 防御力 ダメージ値から引く
 *
 *--------------------------------------------------------------------------*/
typedef struct cle_ac_btl_info {
    unsigned long ac_type_mask; /* 攻撃ビットヒット情報マスク */
    unsigned char ac_special; /* 攻撃ヒット時特殊データ:CLE_AC_SPECIAL_TYPE */
    unsigned char ac; /* 防御力 */
    s_xyz cross; /* 交差位置 */
} CleAcBtlInfo;

/*----------------------------------------------------------------------------
 *
 * ACバトル情報データ部分
 *
 * 同上
 *
 *---------------------------------------------------------------------------*/
typedef struct cle_ac_btl_info_data {
    unsigned long ac_type_mask; /* 攻撃ビットヒット情報マスク */
    unsigned char ac_special; /* 攻撃ヒット時特殊データ:CLE_AC_SPECIAL_TYPE*/
    unsigned char ac; /* 防御力 */
} CleAcBtlInfoData;

/*-----------------------------------------------------------------------------
 *
 * 情報構造体
 * 注意:ClObjとは異なり,基底構造体？としては使わない。
 * メモ
 * CleAtBtlInfo at_btl_info : 攻撃側データ関連
 * CleAcBtlInfo ac_btl_info : 攻撃対象側データ関連
 *
 * unsinged char at_bit,ac_bit,oc_bit : 情報ビット z_collision_param.h参照
 *
 *---------------------------------------------------------------------------*/
typedef struct cl_obj_elem {
    
    /* 戦闘データ関連 */
    CleAtBtlInfo at_btl_info; 
    CleAcBtlInfo ac_btl_info;
    
    /* 材質データ */
    unsigned char material;
    
    /* 情報ビット */
    unsigned char at_bit; 
    unsigned char ac_bit;
    unsigned char oc_bit;
    
    ClObj *at_hit_obj; /* 当ったClObjへのポインター (for at) */
    ClObj *ac_hit_obj; /* 攻撃ClObjへのポインター (for ac) */
    struct cl_obj_elem *at_hit_elem;/*当ったエレメントへのポインター (for at)*/
    struct cl_obj_elem *ac_hit_elem;/* 攻撃エレメントへのポインター (for ac) */
    
} ClObjElem;

/*---------------------------------------------------------------------------
 *
 * 情報セット用構造体
 *
 * 同上
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj_elem_data {
    /* 材質データ */
    unsigned char material;
    
    CleAtBtlInfoData at_btl_info_data; /* 攻撃データ */
    CleAcBtlInfoData ac_btl_info_data; /* 防御データ */

    /* 情報ビット */
    unsigned char at_bit; 
    unsigned char ac_bit;
    unsigned char oc_bit;
    
} ClObjElemData;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 *
 * 関節球情報
 *
 *::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

/*--------------------------------------------------------------------------
 *
 * 関節球要素データ属性
 *
 * メモ：
 * char sph_index_tbl;は各球に対応するジョイントインデックスを指し示す。
 * Math3D_sphere local_sph;マトリックスで変換前の球データ。対応するジョ
 * イントに対するローカルデータが入っている。
 * Math3D_sphereのs_xyzの中心位置のみトランスレートする。
 * Math3D_sphere global_sph;マトリックスで変換後のデータ これで判定を行う
 * float scl_r; rに対するスケール値 
 *
 *---------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_elem_attr {
    Math3D_sphere local_sph; /* ローカル関節球データ  */
    Math3D_sphere global_sph; /* グローバル関節球データ */
    float scl_r; /* rに対するスケール値:100倍値でない。 */
    unsigned char sph_index; /* 関節インデックステーブルへのインデックス */
} ClObjJntSphElemAttr;

/*-------------------------------------------------------------------------
 *
 * 関節球要素セット用データ
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_elem_attr_data {
    unsigned char sph_index;
    Math3D_sphere local_sph;
    short scl_r100; /* rに対するスケール値 */
} ClObjJntSphElemAttrData;

/*-------------------------------------------------------------------------
 *
 * 関節球要素データ
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_elem {
    ClObjElem cl_elem; /* 各当たり要素用データ */
    ClObjJntSphElemAttr attr; /* 各当たり属性値 */
} ClObjJntSphElem;


/*-------------------------------------------------------------------------
 *
 * 関節球要素データセット用構造体
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_elem_data {
    ClObjElemData cl_elem_data; /* 各当たり要素用データ */
    ClObjJntSphElemAttrData attr_data; /* 各当たり属性値 */
} ClObjJntSphElemData;

/*---------------------------------------------------------------------------
 *
 * 関節球
 * 
 *---------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph {
    ClObj cl_obj; /* 基底情報 */
    int num; /* 関節数:以下この関節数分だけデータが存在する。 */
    ClObjJntSphElem *elem_tbl; /* 関節球要素テーブル */
} ClObjJntSph;

/*----------------------------------------------------------------------------
 *
 * 関節球データセット用構造体
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_data {
    ClObjData cl_obj_data; /* 基底情報データ */
    int num;
    ClObjJntSphElemData *elem_data_tbl;
} ClObjJntSphData;

/*--------------------------------------------------------------------------
 *
 * 関節球データセット用構造体
 * Version3
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_data3 {
    ClObjData3 cl_obj_data;
    int num;
    ClObjJntSphElemData *elem_data_tbl;
} ClObjJntSphData3;

/*----------------------------------------------------------------------------
 *
 * 関節球データセット用構造体(ClObjData4がversion up!!)
 * Version5
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj_jnt_sph_data5 {
    ClObjData4 cl_obj_data;
    int num;
    ClObjJntSphElemData *elem_data_tbl;
} ClObjJntSphData5;

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 *
 * 当たりパイプ構造体情報
 *
 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*----------------------------------------------------------------------------
 *
 * 属性情報
 *
 *---------------------------------------------------------------------------*/
typedef struct cl_obj_pipe_attr {
    Math3D_pipe pipe; /* 円筒形状 */
} ClObjPipeAttr;

/*---------------------------------------------------------------------------
 *
 * 属性情報セット構造体
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj_pipe_attr_data {
    Math3D_pipe pipe;
} ClObjPipeAttrData;

/*----------------------------------------------------------------------------
 *
 * パイプ
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_pipe {
    ClObj cl_obj; /* 基底情報 */
    ClObjElem cl_elem; /* 当たりデータ要素 */
    ClObjPipeAttr attr; /* 属性情報 */
} ClObjPipe;

/*--------------------------------------------------------------------------
 *
 * パイプ情報セット構造体
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_pipe_data {
    ClObjData cl_obj_data;  /* 基底情報データ */
    ClObjElemData cl_elem_data; /* 当たりデータ要素 */
    ClObjPipeAttrData attr_data; /* 属性情報 */
} ClObjPipeData;

/*---------------------------------------------------------------------------
 *
 * パイプ情報セット構造体
 * Version3
 *
 *---------------------------------------------------------------------------*/
typedef struct cl_obj_pipe_data3 {
    ClObjData3 cl_obj_data; /* 基底情報データ */
    ClObjElemData cl_elem_data; /* 当たりデータ要素 */
    ClObjPipeAttrData attr_data; /* 属性情報 */
} ClObjPipeData3;

/*---------------------------------------------------------------------------
 *
 * パイプ情報セット構造体(ClObjData4がVersion up!!)
 * Version5
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_pipe_data5 {
    ClObjData4 cl_obj_data; /* 基底情報データ */
    ClObjElemData cl_elem_data; /* 当りデータ要素 */
    ClObjPipeAttrData attr_data; /* 属性情報 */
} ClObjPipeData5;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 *
 * 当たり三角形構造体情報
 *
 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*--------------------------------------------------------------------------
 *
 * 属性情報
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_tris_elem_attr {
    Math3D_triangle tri; /* 三角形形状情報 */
} ClObjTrisElemAttr;
 
/*-------------------------------------------------------------------------
 *
 * 属性情報設定データ
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_tris_elem_attr_set {
    xyz_t pos[3]; /* 三角形形状情報 */
} ClObjTrisElemAttrData;
 
/*--------------------------------------------------------------------------
 *
 * 当たり三角形データ要素
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_tris_elem {
    ClObjElem cl_elem; /* 当たりデータ要素 */
    ClObjTrisElemAttr attr; /* 属性情報 */
} ClObjTrisElem;

/*-------------------------------------------------------------------------
 *
 * 当り三角形データ要素データセット
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_tris_elem_data {
    ClObjElemData cl_elem_data; /* 当りデータ要素設定構造体 */
    ClObjTrisElemAttrData attr_data; /* 属性情報 */
} ClObjTrisElemData;

/*-------------------------------------------------------------------------
 *
 * 三角形 数枚
 *
 *-------------------------------------------------------------------------*/
typedef struct cl_obj_tris {
    ClObj cl_obj; /* 基底情報 */
    int num; /* 要素数 */
    ClObjTrisElem *elem_tbl; /* 三角形要素テーブル */
} ClObjTris;

/*--------------------------------------------------------------------------
 *
 * 三角形数枚
 *
 *---------------------------------------------------------------------------*/
typedef struct cl_obj_tris_data {
     ClObjData cl_obj_data; /* 基底情報データ */
     int num; /* 要素数 */
     ClObjTrisElemData *elem_data_tbl; /* データテーブル先 */
 } ClObjTrisData;

/*----------------------------------------------------------------------------
 *
 * 三角形数枚
 * Version3
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj_tris_data3 {
    ClObjData3 cl_obj_data; /*   基底情報データ */
     int num; /* 要素数 */
     ClObjTrisElemData *elem_data_tbl; /* データテーブル先 */
 } ClObjTrisData3;
 
/*----------------------------------------------------------------------------
 *
 * 三角形数枚
 * Version5
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_obj_tris_data5 {
    ClObjData4 cl_obj_data; /* 基底情報データ */
    int num; /* 要素数 */
    ClObjTrisElemData *elem_data_tbl; /* データテーブル先 */
} ClObjTrisData5;

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 *
 * 剣軌道データ
 *
 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*------------------------------------------------------------------------
 *
 * 剣軌道データアトリビュート
 * xyz_t new_root, new_top, prev_root, prev_top: 剣形状データ
 * s_xyz start, end : 剣情報方向性データ ClObjSwrdAttr_set()で計算し直し
 *
 *-----------------------------------------------------------------------*/
typedef struct cl_obj_swrd_attr {
    xyz_t new_root;
    xyz_t new_top;
    xyz_t prev_root;
    xyz_t prev_top;
    
    s_xyz start;
    s_xyz end;
    
    /*
     * 現在の攻撃距離:endからヒット位置までの距離
     * メモ:攻撃元は攻撃タイプにより変化する場合があり、状況によっては
     * そぐわない場合があるかも知れない。
     * 値は２乗値
     */
    float hit_length;

} ClObjSwrdAttr;

/*------------------------------------------------------------------------
 *
 * 剣軌道データアトリビュート設定データ
 *
 *-----------------------------------------------------------------------*/
typedef struct cl_obj_swrd_attr_data {
    xyz_t new_root;
    xyz_t new_top;
    xyz_t prev_root;
    xyz_t prev_top;
} ClObjSwrdAttrData;

/*-------------------------------------------------------------------------
 *
 * 剣軌道
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_swrd {
    ClObj cl_obj; /* 基底情報 */
    ClObjElem cl_elem; /* 当たりデータ要素 */
    ClObjSwrdAttr attr; /* 属性データ */
} ClObjSwrd;

/*-----------------------------------------------------------------------
 *
 * 剣軌道設定データ
 *
 *--------------------------------------------------------------------*/
typedef struct cl_obj_swrd_data {
    ClObjData cl_obj_data; /* 基底情報データ */
    ClObjElemData cl_elem_data; /* 当りデータ要素設定データ */
    ClObjSwrdAttrData attr_data; /* 属性設定データ */
} ClObjSwrdData;

/*-----------------------------------------------------------------------
 *
 * 剣軌道設定データ
 * Version3
 *
 *--------------------------------------------------------------------*/
typedef struct cl_obj_swrd_data3 {
    ClObjData3 cl_obj_data; /* 基底情報データ */
    ClObjElemData cl_elem_data; /* 当りデータ要素設定データ */
    ClObjSwrdAttrData attr_data; /* 属性設定データ */
} ClObjSwrdData3;

/*--------------------------------------------------------------------------
 *
 * 剣軌道設定データ(ClObjData4にVersion up!!)
 * Version5
 *
 *------------------------------------------------------------------------*/
typedef struct cl_obj_swrd_data5 {
    ClObjData4 cl_obj_data;  /* 基底情報データ */
    ClObjElemData cl_elem_data; /* 当りデータ要素設定データ */
    ClObjSwrdAttrData attr_data; /* 属性設定データ */
} ClObjSwrdData5;

/*=========================================================================
 *
 * OC専用 ラインチェック
 *
 *========================================================================*/
/*-------------------------------------------------------------------------
 *
 * 各チェック要素
 *
 *------------------------------------------------------------------------*/
typedef struct cl_oc_line {
    
    /* 始点、終点 */
    Math3D_lineSegment ls;
    
    /* 処理ビット */
    unsigned short status;
} ClOCLine;

/*---------------------------------------------------------------------------
 *
 * セット用データ型
 *
 *--------------------------------------------------------------------------*/
typedef struct cl_oc_line_data {
    
    /* 始点終点 */
    Math3D_lineSegment ls;
    
    /* 処理ビット */
    unsigned short status;
    
} ClOCLineData;
    

/*=========================================================================
 *
 * コリジョンチェック処理構造体
 *
 *========================================================================*/
#define MAX_CLCH_AT_NUM 50
#define MAX_CLCH_AC_NUM 60
#define MAX_CLCH_OC_NUM 50
#define MAX_CLCH_OC_LINE_NUM 3
typedef struct collision_check {
    /* コリジョンデータテーブル */

    /* AT */
    short at_num;
    unsigned short status;
    ClObj *at_tbl[MAX_CLCH_AT_NUM];
    /* AC */
    int ac_num;
    ClObj *ac_tbl[MAX_CLCH_AC_NUM];
    /* OC */
    int oc_num;
    ClObj *oc_tbl[MAX_CLCH_OC_NUM];
    
    /* OC Line */
    int oc_line_num;
    ClOCLine *oc_line_tbl[MAX_CLCH_OC_LINE_NUM];
    
} CollisionCheck;

/*===========================================================================
 *
 * Damage構造体
 *
 * int hp: 現在の体力
 * int damage: ダメージ(これだけ体力減少）
 * Actor *pactor: 攻撃者へのポインター
 *
 *==========================================================================*/
typedef struct damage_s {
    int hp; /* HP */
    int damage; /* ダメージ量 */
    /* 特殊データ */
    unsigned char at_special;
    unsigned char ac_special;
    unsigned char weight; /* weight */
    
    
    /* お蔵入り */
    CL_AT_LBL type; /* ダメージタイプ */
    Actor *pactor; /* 攻撃者 */
    CL_AT_LBL at_lbl; /* 攻撃ラベル */

    xyz_t attacker_pos; /* 攻撃者位置 */
    int set_damage; /* ダメージフラッグ */
} DAMAGE_S;

/*==========================================================================
 *
 * 敵反応データ
 * unsigned char reaction[32]: 反応データ
 *
 *=========================================================================*/
typedef struct btl_data {
    /* 敵反応ラベル:z_collision_param.h CL_BTD_TYPE */
    unsigned char reaction[32];
} BtlData;

/*===========================================================================
 *
 * Status 構造体
 *
 *===========================================================================*/
typedef struct status_s {
    /* 敵反応データ */
    BtlData *btl_data;
    /* ある１フレーム内の補正ベクトル */
    xyz_t coll_vec;
    
    /* 半径 */
    short r;
    /* 高さ */
    short h;
    /* オフセット */
    short offset;
    /* weight */ 
    unsigned char weight;
    
    unsigned char hp; /* HP */
    unsigned char damage; /* damage */
    unsigned char hit_reaction; /* 攻撃を受けたときのリアクション */
    
    /* 特殊データ */
    unsigned char at_special;
    unsigned char ac_special;
    
} Status;

/*---------------------------------------------------------------------------
 *
 * ステータスデータ
 *
 *--------------------------------------------------------------------------*/
typedef struct status_data_s {
    unsigned char hp; /* HP */
    unsigned char hit_mark_type; /* ヒットマークパラメータ */
    
    /* 半径 */
    short r;
    /* 高さ */
    short h;
    /* weight */
    unsigned char weight;
} Status_Data;

/*--------------------------------------------------------------------------
 *
 * ステータスデータ
 * Version2
 *
 *-------------------------------------------------------------------------*/
typedef struct status_data_s2 {
    unsigned char hp; /* HP */

    /* 半径 */
    short r;
    /* 高さ */
    short h;
    /* weight */
    unsigned char weight;
} Status_Data2;

/*--------------------------------------------------------------------------
 *
 * ステータスデータ(オフセット指定が必要なときのみ使用）
 * Version3
 *
 *-------------------------------------------------------------------------*/
typedef struct status_data_s3 {
    unsigned char hp; /* HP */

    /* 半径 */
    short r;
    /* 高さ */
    short h;
    /* オフセット */
    short offset;
    /* weight */
    unsigned char weight;
} Status_Data3;

/*============================================================================
 *
 * 旧型構造体
 *
 *==========================================================================*/

/*
 * 三角形形状構造体
 */
typedef struct collision_triangle_s {
    xyz_t pos[3]; /* 三角形の頂点データ */
    float a, b, c, d;
} COLLISION_TRIANGLE_S;

/*
 * 円筒形状構造体
 */
typedef struct collision_pipe_s {
    float r; /* 半径 */
    float h; /* 高さ */
    float offset; /* オフセット */
} COLLISION_PIPE_S;


/*
 * 剣攻撃 結果パラメータ
 */
typedef enum sword_attack_result_e {
    ACTOR_SW_AT_RSLT_MISS, /* すか */
    ACTOR_SW_AT_RSLT_SUCCESS, /* 命中 */
    ACTOR_SW_AT_RSLT_DEFENCE /* 防がれた（剣を戻すか,ロックするか？） */
} ATTACK_RESULT_E;

 /* 剣の位置データ */
typedef struct sword_pos_s {
    int prev_data_on_flag; /* 一つ前の位置データが入っている */
    xyz_t prev_top_pos;
    xyz_t prev_root_pos;
} SWORD_POS_S;

  /* 盾の位置データ */
typedef struct shield_pos_s {
    COLLISION_TRIANGLE_S tri[2];
    COLLISION_TRIANGLE_S current_tri[2];
} SHIELD_POS_S;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_collision_type.h end ***/
