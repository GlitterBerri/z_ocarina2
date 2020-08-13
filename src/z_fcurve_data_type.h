/* $Id: z_fcurve_data_type.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $ */
/*===========================================================================
 *
 * z_fcurve_data_type.h
 *
 * Program:Kenji Matsutani
 * Date:1998年 1月30日(金曜日) 20時10分55秒 JST
 *
 *$Log: z_fcurve_data_type.h,v $
 *Revision 2.1  1998-10-22 21:17:25+09  zelda
 *ＲＯＭ出しバージョン(NTSC)
 *
 *Revision 1.1  1998/02/09 05:11:19  matutani
 *Initial revision
 *
 *
 *===========================================================================*/

#ifndef INCLUDE_Z_FCURVE_DATA_TYPE_H
#define INCLUDE_Z_FCURVE_DATA_TYPE_H

/*============================================================================
 *
 * Key Data Num Tbl
 *
 * そのファンクションカーブに,幾つのキーが存在するか？のデータ最大255個のキー
 * を持つ。
 *
 * 現在SRT順
 * model:scl.x 1バイト
 *           y
 *           z
 *      :rot.x 1バイト
 *           y 
 *           z 
 *      :trs.x 1バイト
 *           y
 *           z
 *   
 *==========================================================================*/
/*===========================================================================
 *
 * 各キーのデータ
 *
 * メンバ説明
 * unsigned short type:ビット情報(-> sys_hermit_interp_def.h)
 * short frame:キーのフレーム数
 * short lslope, rslope:傾き
 * float value : あるキーの時の値
 *
 *==========================================================================*/
typedef struct key_data {
    unsigned short type;
    short frame;
    short lslope, rslope;
    float value;
} KeyData;

/*---------------------------------------------------------------------------
 *
 * ファンクションカーブ構造体
 *
 * メンバ説明
 * unsigned char *key_num_tbl:ある要素が持つキーデータの個数
 * KeyData *key_data_tbl:キーデータのテーブルへのポインター
 * unsigned short *lock_param:固定値データ（トランスレーションのマイナスに
 * 注意）
 * unsigned short start, end : スタートフレーム,エンドフレーム（ソフト
 * イマージでセットされた。）ただし、この値の範囲を越えたフレームでも計算可能。
 *
 *-------------------------------------------------------------------------*/
typedef struct fcurve_data {
    unsigned char *key_num_tbl;
    KeyData *key_data_tbl;
    unsigned short *lock_param;
    unsigned short start, end;
} FcurveData;

#endif

/*** z_fcurve_data_type.h EOF ***/
