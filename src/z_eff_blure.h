/* $Id: z_eff_blure.h,v 2.1 1998/10/22 12:13:45 zelda Exp $ */
/* $Log: z_eff_blure.h,v $
 * Revision 2.1  1998/10/22  12:13:45  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.18  1998/09/07 12:35:17  matutani
 * *** empty log message ***
 *
 * Revision 1.17  1998-09-04 22:45:02+09  matutani
 * *** empty log message ***
 *
 * Revision 1.16  1998-08-26 21:51:51+09  matutani
 * *** empty log message ***
 *
 * Revision 1.15  1998-08-25 20:49:41+09  matutani
 * *** empty log message ***
 *
 * Revision 1.14  1998-07-15 22:25:42+09  matutani
 * *** empty log message ***
 *
 * Revision 1.13  1998-03-18 19:57:01+09  sumiyosi
 * 修正依頼おわりました。
 *
 * Revision 1.12  1998/03/07  11:34:42  matutani
 * 捻テスト
 *
 * Revision 1.11  1998/03/03  13:35:14  matutani
 * *** empty log message ***
 *
 * Revision 1.10  1998/03/03  10:42:42  matutani
 * ブラ─テクスチャ（テスト）
 *
 * Revision 1.9  1997/03/14  00:33:29  hayakawa
 * ヘッダ追加
 *
 * Revision 1.8  1996/11/26  13:01:58  matutani
 * もう必要のないコード削除
 *
 * Revision 1.7  1996/11/15  08:35:11  matutani
 * 変更なし
 *
 * Revision 1.6  1996/10/31  02:05:37  matutani
 * *** empty log message ***
 *
 * Revision 1.5  1996/10/22  10:09:06  matutani
 * ブラ─リスト処理中止
 *
 * Revision 1.4  1996/09/20  05:18:13  matutani
 * 頂点バッファー／フラグを構造体から削除
 *
 * Revision 1.3  1996/09/20  04:15:24  matutani
 * *** empty log message ***
 *
 * Revision 1.2  1996/09/20  01:00:21  matutani
 * 最新のファイルを上書き
 *
 */

/*----------------------------------------------------------------------------
 *
 * z_eff_blure.h
 * ブラー処理
 * Program:Kenji Matsutani
 * 1996/09/04
 *---------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_EFF_BLURE_H
#define INCLUDE_Z_EFF_BLURE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif    

#include<ultra64.h>
#include<u64types.h>
#include"z_basic.h"
#include"z_effect.h"
#include"graph.h"		/* Graph */

/* 表示する頂点の最大数 */
/* ２で割れる数 */
#define EFFECT_BLURE_MAX_DISP_VERTEX 32
#define EFFECT_BLURE_MAX_EDGE_NUM (32 /2)

/*
 * ブラ─のタイプ
 */
typedef enum {
    EFFECT_BLURE_TYPE_SPACE, /* 空白 */
    EFFECT_BLURE_TYPE_EDGE, /* エッジ */
    EFFECT_BLURE_TYPE_NO_USE, /* 未使用 */
    EFFECT_BLURE_TYPE_LAST_INDEX
} EFFECT_BLURE_TYPE;

/*
 * Blure_procの終了タイプ
 */
typedef enum effect_blure_proc_type {
    EFFECT_BLURE_PROC_NO_DATA, /* リストにデータが存在しない */
    EFFECT_BLURE_PROC_USE_DATA /* リストにデータが存在する */
} EFFECT_BLURE_PROC_TYPE;

/*
 * エッジステータスビット情報
 *
 * 5432109876543210
 *               +-- エッジ状態
 *
 */
/* エッジ状態 */
/* 補間無し */
#define EBE_STTS_NO_INTERP 0
/* 補間 */
#define EBE_STTS_HERMITE_INTERP 1
/* 端 */
#define EBE_STTS_EDGE 2

#define EBE_STTS_DEFAULT EBE_STTS_NO_INTERP

/* エッジ状態取得 */
#define EBE_STTS_Get(pedge) ((pedge)->status & 0x3)
/* エッジ状態セット */
#define EBE_STTS_Set(pedge, type) \
{(pedge)->status &= ~0x3; (pedge)->status |= type;}

/*
 * ブラー用のデータ構造体
 */
typedef struct effect_blure_edge {
    /* タイプ */
    EFFECT_BLURE_TYPE type;
    
    /* 現在のフレーム数 */
    int now_frame;

    /* 位置データ─ */
    /* 剣先データ */
    s_xyz tpos; 
    /* 根元データ */
    s_xyz rpos;

    /* 状態ビット */
    unsigned short status;
    
} EFFECT_BLURE_EDGE;


/*----------------------------------------------------------------------------
 *
 * ブラ─情報構造体
 *
 *---------------------------------------------------------------------------*/

/*
 * blure form type
 */
typedef enum effect_blure_form_type {
    EFFECT_BLURE_FORM_DEC_NONE, /* 形状減衰無し */
    EFFECT_BLURE_FORM_DEC_TOP, /* 先の方が減っていく */
    EFFECT_BLURE_FORM_DEC_ROOT, /* 根元の方が減っていく */
    EFFECT_BLURE_FORM_DEC_BOTH, /* 先／根元両方減っていく */
    EFFECT_BLURE_FORM_SPREAD, /* 広がっていく */
    EFFECT_BLURE_FORM_LAST_INDEX
} EFFECT_BLURE_FORM_TYPE;

/*
 * blure diplay buffer
 */
typedef enum effect_blure_display_buffer {
    EFFECT_BLURE_DISPLAY_BUFFER_0,
    EFFECT_BLURE_DISPLAY_BUFFER_1
} EFFECT_BLURE_DISPLAY_BUFFER_TYPE;

/* ステータスビット:デフォルトを０にする */
/*
 * スパイラル(ねじれ）:弓矢用
 */
#define Z_EFF_BLURE_SPR_ON (1<<1)
/*
 * 十字:弓矢用
 */
#define Z_EFF_BLURE_CROSS_ON (1<<2)
/*
 * 新処理
 */
#define Z_EFF_BLURE_NEW (1<<3)
/*
 * SHADE_OFF
 * 常に２５５
 */
#define Z_EFF_BLURE_SHADE_OFF (1<<4)

/*
 * モード設定
 */
enum {
    EFF_BLURE_MODE_NORMAL,
    EFF_BLURE_MODE_ARROW_TXT,
    EFF_BLURE_MODE_HERMITE_INTER,
    EFF_BLURE_MODE_LAST_INDEX
};

/*-----------------------------------------------------------------------------
 *
 * 旧構造体（テクスチャ無し）
 * 現在はデータセット時のみ使用
 * 変更するなら使用している敵総てコンパイル掛け直しましょう。
 *
 *---------------------------------------------------------------------------*/
typedef struct effect_blure_info {
    /* エッジ数 */
    int now_edge_num;

    /* エッジデータ */
    EFFECT_BLURE_EDGE edge[EFFECT_BLURE_MAX_EDGE_NUM];
    
    /* スタートカラー */
    unsigned char start_top[4]; /* r, g, b, a */
    unsigned char start_root[4]; /* r, g, b, a */

    /* エンドカラー */
    unsigned char end_top[4]; /* r, g, b, a */ 
    unsigned char end_root[4]; /* r, g, b, a */
    
    /* 消失フレーム数 */
    int remove_frame;

    /* ステップフラグ */
    int step_flag;

    /* 形状タイプ */
    EFFECT_BLURE_FORM_TYPE form_type;
    
} EFFECT_BLURE_INFO;

/*---------------------------------------------------------------------------
 *
 * 新構造体
 * データセット用構造体
 * Version1:1998年 2月27日(金曜日) 16時32分45秒 JST
 *
 *--------------------------------------------------------------------------*/
typedef struct effect_blure_info_data1 {
    /* 形状タイプ */
    EFFECT_BLURE_FORM_TYPE form_type;
    
    /* ステータスビット:デフォルトを０にする。 */
    /*
     * statusが０であると旧処理で,動作します。
     */
    unsigned short status;

    /* 回転スピード */
    short rot_speed;
    
    /* スタートカラー */
    unsigned char start_top[4]; /* r, g, b, a */
    unsigned char start_root[4]; /* r, g, b, a */

    /* エンドカラー */
    unsigned char end_top[4]; /* r, g, b, a */ 
    unsigned char end_root[4]; /* r, g, b, a */

    /* 消失フレーム数 */
    unsigned char remove_frame;

    /* ステップフラグ */
    unsigned char step_flag;

    /* モードインデックス */
    /*
     * 0.今までと同様,デフォルト
     * 1.Arrowテクスチャ─(status != 0でないと働きません。)
     * 2.Hermite補間
     */
    unsigned char mode;

    /* 
     * 広がりパラメーター
     */
    unsigned char spread_param;

    /* texture work */
    rgba_t prim;
    rgba_t env;
    
} Effect_Blure_Info_Data1;

/*---------------------------------------------------------------------------
 *
 * 新構造体
 * テクスチャ対応
 *
 *--------------------------------------------------------------------------*/
typedef struct effect_blure_info2 {
    
    /* エッジデータ */
    EFFECT_BLURE_EDGE edge[EFFECT_BLURE_MAX_EDGE_NUM];
    
    /* 形状タイプ */
    EFFECT_BLURE_FORM_TYPE form_type;
    /* 広がりサイズ */
    float spread_size;
    
    /* ステータスビット:デフォルトを０にする。 */
    unsigned short status;
    
    /* 回転スピード */
    short rot_speed;
    short rot;

    /* スタートカラー */
    unsigned char start_top[4]; /* r, g, b, a */
    unsigned char start_root[4]; /* r, g, b, a */
    
    /* エンドカラー */
    unsigned char end_top[4]; /* r, g, b, a */ 
    unsigned char end_root[4]; /* r, g, b, a */
    
    /* エッジ数 */
    unsigned char now_edge_num;
    
    /* 消失フレーム数 */
    unsigned char remove_frame;
    
    /* ステップフラグ */
    unsigned char step_flag;
    
    /* 処理モード */
    unsigned char mode;

    /* texture_work */
    rgba_t prim;
    rgba_t env;
    
} EFFECT_BLURE_INFO2;


/*----------------------------------------------------------------------------
 *
 * ブラー処理関数(旧関数)
 *
 *---------------------------------------------------------------------------*/

/*
 * 頂点追加
 */
extern void EffectBlure_edge_add(
    EFFECT_BLURE_INFO *pbl_info,
    xyz_t *ptpos,
    xyz_t *prpos);


/*
 * 空白追加
 */
extern void EffectBlure_space_add(EFFECT_BLURE_INFO *pbl_info);


#if 0


/*
 * コンストラクター
 */
extern void EffectBlure_ct(
    EFFECT_BLURE_INFO *pbl_info,
    unsigned char *start_top, /* size 4の配列:スタートの剣先の方のカラー */
    unsigned char *start_root, /* size 4の配列:スタートの根元の方のカラー */
    unsigned char *end_top, /* size 4の配列:消失時の剣先のカラー */
    unsigned char *end_root, /* size 4の配列:消失時の根元のカラー */
    int remove_frame, /* 消失フレーム数 */
    int step_flag, /* ステップのON, OFF （TRUEまたはFALSE) */
    EFFECT_BLURE_FORM_TYPE form_type); /* 形状 */

/*
 * デストラクター
 */
extern void EffectBlure_dt(EFFECT_BLURE_INFO *pbl_info);


/*
 * リスト解放
 */
extern void EffectBlure_edge_free(EFFECT_BLURE_INFO *pbl_info);


/*
 * 時間経過
 */
extern EFFECT_BLURE_PROC_TYPE EffectBlure_proc(EFFECT_BLURE_INFO *pbl_info);

   
/*
 * 表示
 */
extern void EffectBlure_disp(EFFECT_BLURE_INFO *pbl_info, Graph *graph);
#endif
/*----------------------------------------------------------------------------
 *
 * エフェクトシステム用ブラー処理
 *
 *---------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 *
 * EFFECT_BLURE_INFO初期化
 *
 *--------------------------------------------------------------------------*/
extern void EffectBlureInfo_ct(void *this, void *init);

/*---------------------------------------------------------------------------
 *
 * 新データセット構造体用セット関数 (for Version 1)
 * メモ；initは実はEffect_Blure_Info_Data1へのポインター
 *
 *------------------------------------------------------------------------*/
extern void EffectBlureInfo_v1_ct(
    void *this,
    void *init);

/*----------------------------------------------------------------------------
 *
 * EFFECT_BLURE_INFOデストラクター
 *
 *--------------------------------------------------------------------------*/
extern void EffectBlureInfo_dt(void *this);


/*----------------------------------------------------------------------------
 *
 * EFFECT_BLURE_INFO動作処理
 *
 *---------------------------------------------------------------------------*/
extern Effect_Proc_Func EffectBlureInfo_proc(void *this);

 
/*----------------------------------------------------------------------------
 *
 * EffectBlureInfo表示処理
 *
 *---------------------------------------------------------------------------*/
extern void EffectBlureInfo_disp(void *this, Graph *graph);

#ifdef _LANGUAGE_C_PLUS_PLUS
}	/* extern "C"	*/
#endif

#endif

/*** eff_blure.h ***/

