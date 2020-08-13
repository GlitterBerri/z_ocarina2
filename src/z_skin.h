/*  $Id: z_skin.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $ */
/*---------------------------------------------------------------------------
 *
 * スキン処理
 *
 * Program:Kenji Matsutani
 *
 * $Log: z_skin.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.11  1998/06/29 13:08:31  matutani
 * ドッペルモード対応
 *
 * Revision 1.10  1998-06-18 21:23:40+09  matutani
 * 簡易表示モード
 *
 * Revision 1.9  1998-04-08 11:59:39+09  matutani
 * あるジョイントのディスプレイリストを非表示にして、その代りのディスプレイリストを表示。
 *
 * Revision 1.8  1998/03/19  13:03:21  komatu
 * *** empty log message ***
 *
 * Revision 1.7  1998/02/13  14:01:00  matutani
 * *** empty log message ***
 *
 * Revision 1.6  1997/10/06  10:39:07  matutani
 * *** empty log message ***
 *
 * Revision 1.5  1997/10/02  12:54:55  matutani
 * *** empty log message ***
 *
 * Revision 1.4  1997/08/18  00:46:03  matutani
 * 法線処理
 *
 * Revision 1.3  1997/08/07  07:02:00  matutani
 * from:スケール100倍位置 コメント
 *
 * Revision 1.2  1997/03/28  12:14:07  matutani
 * スキンのシェイプ上のグローバル位置を計算
 *
 * Revision 1.1  1997/03/25  07:46:06  matutani
 * Initial revision
 *
 *
 *-------------------------------------------------------------------------*/

#ifndef INCLUDE_Z_SKIN_H
#define INCLUDE_Z_SKIN_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include"z_skin_type.h"
#include"z_skin_awb.h"

/*============================================================================
 *
 * 処理マスク
 *
 *==========================================================================*/
/* デフォルト */
#define SKIN_DISP_DEFAULT 0
/* マトリックス計算／頂点計算をし直さない */
#define SKIN_DISP_NO_CALC (1 << 0)
/* rootマトリックスをロードしない */
#define SKIN_DISP_NO_ROOT_MTX (1 << 1)

/*=============================================================================
 *
 * 新バージョン
 *
 *===========================================================================*/

/*---------------------------------------------------------------------------
 *
 * gfxのディスプレイリスト表示
 *
 *--------------------------------------------------------------------------*/
extern void Skin_gfx_mesh2_disp(
    Graph *graph,
    Skin_AnimationWorkBuffer2 *pskin_awb,
    int index_mdl,
    Gfx *change_gfx,
    unsigned int proc_mask);
    
    
/*-----------------------------------------------------------------------------
 * 
 * skinデータからディスプレイリストに変換
 *
 * 引数:
 * Actor *thisx : アクターポインター
 * Game *pgame : ゲームポインター
 * Skin_AnimationWorkBuffer2 *pskin_awb : スキン作業バッファー
 * void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *) : 計算処理
 * int root_trs_flag : ルートのトランスレーションデータを使用するか？
 *
 * メモ：
 * pos_func == NULLの場合実行しない
 *
 *---------------------------------------------------------------------------*/
extern void Skin_disp2( 
    Actor *thisx,
    Game *pgame, 
    Skin_AnimationWorkBuffer2 *pskin_awb,
    void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *),
    int root_trs_flag);

/*-----------------------------------------------------------------------------
 * 
 * skinデータからディスプレイリストに変換
 *
 * 引数:
 * Actor *thisx : アクターポインター
 * Game *pgame : ゲームポインター
 * Skin_AnimationWorkBuffer2 *pskin_awb : スキン作業バッファー
 * void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *) : 計算処理
 * int (*joint_func)(Actor *, Game *, int, Skin_AnimationWorkBuffer2 *):
 *   各ジョイント表示前処理
 * 返り値がFALSEの時はそのジョイントを表示しない。
 * int root_trs_flag : ルートのトランスレーションデータを使用するか？
 *
 * メモ：
 * pos_func == NULLの場合実行しない
 *
 *---------------------------------------------------------------------------*/
extern void Skin_disp3( 
    Actor *thisx,
    Game *pgame, 
    Skin_AnimationWorkBuffer2 *pskin_awb,
    void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *),
    int (*joint_func)(Actor *, Game *, int, Skin_AnimationWorkBuffer2 *),
    int root_trs_flag);

/*---------------------------------------------------------------------------
 *
 * あるグローバルマトリックス（ルートマトリックス含む)により、
 * 変換された位置を計算する。
 * スキンデータではない
 * gfx用（skinでも使えるが)
 * from:スケール100倍位置
 *
 *---------------------------------------------------------------------------*/
extern void Skin_MatrixPosition2_gfx(
    Skin_AnimationWorkBuffer2 *pskin_awb2,
    int jyoint, xyz_t *from, xyz_t *to);

/*==========================================================================
 *
 * 旧バージョン
 *
 *========================================================================*/

/*---------------------------------------------------------------------------
 *
 * meshのデータからディスプレイリストに変換
 *
 *--------------------------------------------------------------------------*/
extern void Skin_Mesh_disp(
    Graph *graph,
    Skin_AnimationWorkBuffer *pskin_awb,
    int index_mdl);

/*---------------------------------------------------------------------------
 *
 * あるグローバルマトリックス（ルートマトリックス含む)により、
 * 変換された位置を計算する。
 * スキンデータではない
 * gfx用（skinでも使えるが)
 * from:スケール100倍位置
 *
 *---------------------------------------------------------------------------*/
extern void Skin_MatrixPosition_gfx(
    Skin_AnimationWorkBuffer *pskin_awb,
    int jyoint, xyz_t *from, xyz_t *to);

/*----------------------------------------------------------------------------
 *
 * スキン処理のモデルの頂点のグローバル位置を得ることができる。
 * skinモデル専用
 *
 *--------------------------------------------------------------------------*/
extern void Skin_MatrixPosition_skin(
      Skin_AnimationWorkBuffer *pskin_awb,
      int jyoint, int vtx_index, xyz_t *to);

/*-----------------------------------------------------------------------------
 * 
 * skinデータからディスプレイリストに変換
 *
 *---------------------------------------------------------------------------*/
extern void Skin_disp(
    Actor *thisx,
    Game *game, 
    Skin_AnimationWorkBuffer *pskin_awb,
    void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer *),
    int root_trs_flag);

/*-----------------------------------------------------------------------------
 * 
 * skinデータからディスプレイリストに変換
 *
 * 引数:
 * Actor *thisx : アクターポインター
 * Game *pgame : ゲームポインター
 * Skin_AnimationWorkBuffer2 *pskin_awb : スキン作業バッファー
 * void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *) : 計算処理
 * int (*joint_func)(Actor *, Game *, int, Skin_AnimationWorkBuffer2 *):
 *   各ジョイント表示前処理
 * 返り値がFALSEの時はそのジョイントを表示しない。
 * int root_trs_flag : ルートのトランスレーションデータを使用するか？
 * int simple_flag:簡易表示をするかどうか？
 * 
 * メモ：
 * pos_func == NULLの場合実行しない
 *
 *---------------------------------------------------------------------------*/
extern void Skin_disp4( 
    Actor *thisx,
    Game *pgame, 
    Skin_AnimationWorkBuffer2 *pskin_awb,
    void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *),
    int (*joint_func)(Actor *, Game *, int, Skin_AnimationWorkBuffer2 *),
    int root_trs_flag,
    int simple_flag);

/*-----------------------------------------------------------------------------
 * 
 * skinデータからディスプレイリストに変換
 *
 * 引数:
 * Actor *thisx : アクターポインター
 * Game *pgame : ゲームポインター
 * Skin_AnimationWorkBuffer2 *pskin_awb : スキン作業バッファー
 * void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *) : 計算処理
 * int (*joint_func)(Actor *, Game *, int, Skin_AnimationWorkBuffer2 *):
 *   各ジョイント表示前処理
 * 返り値がFALSEの時はそのジョイントを表示しない。
 * int root_trs_flag : ルートのトランスレーションデータを使用するか？
 * int simple_flag:簡易表示をするかどうか？
 * 
 * メモ：
 * pos_func == NULLの場合実行しない
 *
 *---------------------------------------------------------------------------*/
extern void Skin_disp5( 
    Actor *thisx,
    Game *pgame, 
    Skin_AnimationWorkBuffer2 *pskin_awb,
    void (*pos_func)(Actor *, Game *, Skin_AnimationWorkBuffer2 *),
    int (*joint_func)(Actor *, Game *, int, Skin_AnimationWorkBuffer2 *),
    int root_trs_flag,
    int simple_flag,
    unsigned int proc_mask);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_skin.h ***/

