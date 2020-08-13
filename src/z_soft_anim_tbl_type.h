/*  $Id: z_soft_anim_tbl_type.h,v 2.1 1998/10/22 11:51:48 zelda Exp $ */
/*----------------------------------------------------------------------------
 *
 * z_soft_anim_tbl_type.h
 *
 * ソフトイマージ アニメーションテーブル構造体
 *
 * Program:Kenji Matsutani
 *
 * $Log: z_soft_anim_tbl_type.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.7  1997/06/18 04:40:26  matutani
 * SoftAnimTblInfo2をメンバ順序変更
 *
 * Revision 1.6  1997/06/18  01:36:41  matutani
 * SoftAnimTblInfo2追加
 *
 * Revision 1.5  1997/04/26  03:05:30  matutani
 * 構造体の名前がちゃうど！！
 *
 * Revision 1.4  1997/04/22  02:28:17  matutani
 * モデル数shortからunsigned char に変更
 *
 * Revision 1.3  1997/04/15  02:30:26  matutani
 * trsとrot入れ替え
 *
 * Revision 1.2  1997/04/14  01:14:08  matutani
 * ダイレクト対応
 *
 * Revision 1.1  1997/03/25  07:44:46  matutani
 * Initial revision
 *
 *
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_SOFT_ANIM_TBL_TYPE_H
#define INCLUDE_Z_SOFT_ANIM_TBL_TYPE_H


/*
 * type_flag 用チェックマスク
 */
#define TYPE_FLAG_SCL_CUT_MASK (1<<0)
#define TYPE_FLAG_ROT_CUT_MASK (1<<1)
#define TYPE_FLAG_TRS_CUT_MASK (1<<2)
/* 強制的にroot modelのトランスレートデータ追加 */
#define TYPE_FLAG_ADD_ROOT_TRS_MASK (1<<3)
/* ダイレクトデータ */
#define TYPE_FLAG_DIRECT_DATA_MASK (1<<4)
/* rotとtrsの順序を入れ替える */
#define TYPE_FLAG_TR_EXCHANGE_MASK (1<<5)

/*----------------------------------------------------------------------------
 *
 * ソフトイマージ アニメーション構造体:現在スキンのみ
 *
 *--------------------------------------------------------------------------*/
typedef struct soft_anim_tbl_info {
    short mdl_num; /* モデル数 */
   
    unsigned short frame_num; /* 全フレーム数 */
    unsigned char type_flag; /* 各種フラグ  */
    /*
     * フラグ内容
     * 1bit目:スケールカットフラグ
     * 2bit目:ローテートデータカット
     * 3bit目:トランスレートカットフラグ
     * 4bit目:ダイレクトデータ
     * 5bit目:rot,trs入れ替え(直接データのみの対応)
     */
    
    unsigned short *anim_ref_tbl; /* アニメーション参照テーブル */
    
    short *anim_tbl; /* アニメーションデータ */

    /*
     * アニメーションスタートインデックス
     * アニメーションデータテーブルの,このインデックスから後は
     * アニメーションデータを持っている。
     */
    unsigned short anim_start_index; 
  
} SoftAnimTblInfo;

/*--------------------------------------------------------------------------
 *
 * ソフトイマージアニメーション構造体:一般用
 *
 *-------------------------------------------------------------------------*/
typedef struct soft_anim_tbl_info2 {
    unsigned short frame_num; /* 全フレーム数 */
    short *anim_tbl; /* アニメーションデータ */
    unsigned short *anim_ref_tbl; /* アニメーション参照テーブル */
    unsigned short part_index; /* 固定データとアニメーションデータの分かれ目 */
} SoftAnimTblInfo2;

/*----------------------------------------------------------------------------
 *
 * ソフトイマージ アニメーション構造体:リンクROM用
 *
 *---------------------------------------------------------------------------*/
typedef struct soft_anim_tbl_rom_trs_info {
    unsigned short frame_num; /* 全フレーム数 */
    short *anim_tbl; /* アニメーションデータ */
} SoftAnimTblRomTrsInfo;

#endif

/*** z_soft_anim_tbl_type.h end ***/


