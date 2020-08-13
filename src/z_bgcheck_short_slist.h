/* $Id: z_bgcheck_short_slist.h,v 2.1 1998/10/22 11:45:49 zelda Exp $ */
/*============================================================================
 *
 * z_bgcheck_slist.h
 *
 * Program:Kenji Matsutani
 * 1997年 6月 5日(木曜日) 16時04分35秒 JST
 *
 *===========================================================================*/

#ifndef INCLUDE_Z_BGCHECK_SLIST_H
#define INCLUDE_Z_BGCHECK_SLIST_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#define SS_NULL 65535

/*==========================================================================
 *
 * short slist タイプ
 *
 *========================================================================*/

/*----------------------------------------------------------------------------
 *
 * shortノード構造体
 *
 *--------------------------------------------------------------------------*/
typedef struct short_slist_node {
    short data; /* 内容データ */
    unsigned short next; /* 次のノードへのインデックス */
} short_SLIST_NODE;

/*----------------------------------------------------------------------------
 *
 * short単方向リスト情報構造体
 *
 *---------------------------------------------------------------------------*/
typedef struct short_slist {
    unsigned short head; /* 先頭のノードへのインデックス */
} short_SLIST;

/*===========================================================================
 *
 * short slist テーブル構造体
 *
 *===========================================================================*/
typedef struct dyna_short_slist_tbl {
    short_SLIST_NODE *tbl; /* メモリーへのポインター */
    int last_index; /* 現在の最終インデックス */
    int tbl_size; /* テーブルのサイズ */
} short_SLIST_TBL;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_bgcheck_slist.h ***/


