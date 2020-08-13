/*
 * $Id: z_rcp.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 * $Log: z_rcp.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.77  1998/09/23 09:07:19  hayakawa
 * gfx_softsprite_z_prim_xlu追加というか変更
 *
 * Revision 1.76  1998-09-11 21:38:58+09  hayakawa
 * 『何もしない』ディスプレイリスト
 *
 * Revision 1.75  1998-09-10 21:04:44+09  hayakawa
 * gfx_set_fog_nosync
 * gfx_set_fog_sync
 * 追加
 *
 * Revision 1.74  1998-08-31 20:11:10+09  hayakawa
 * gfx_softsprite_z_fog追加
 *
 * Revision 1.73  1998-08-31 11:16:57+09  hayakawa
 * gfx_softsprite_prim_xlu追加
 *
 * Revision 1.72  1998-08-24 14:44:59+09  hayakawa
 * アニメモデル作成関数 anime_envcolor を追加
 *
 * Revision 1.71  1998-08-07 22:37:38+09  hayakawa
 * gfx_softsprite追加
 *
 * Revision 1.70  1998-07-24 21:22:30+09  zelda
 * gfx_rect_moji
 *
 * Revision 1.69  1998-07-17 16:59:08+09  soejima
 * *** empty log message ***
 *
 * Revision 1.68  1998-06-12 21:41:31+09  yoshida
 * *** empty log message ***
 *
 * Revision 1.67  1998-05-25 18:46:12+09  komatu
 * gfx_polygon_z_light_fog_prim
 * gp_overlay_polygon_z_light_fog_prim
 * の追加
 *
 * Revision 1.66  1998-05-25 15:29:45+09  komatu
 * gfx_polygon_z_light_fog_prim
 * gp_overlay_polygon_z_light_fog_prim
 * gp_overlay_rcp_mode_set
 * の定義
 *
 * Revision 1.65  1998-05-13 17:08:30+09  hayakawa
 * static_DisplayList_initialize
 *
 * Revision 1.64  1998-04-27 21:50:03+09  hayakawa
 * two_tex_scroll2登録
 *
 * Revision 1.63  1998-04-22 19:06:42+09  hayakawa
 * gfx_tex_scroll2 gfx_tex_scroll追加
 *
 * Revision 1.62  1998-03-30 21:27:49+09  hayakawa
 * 命名修正
 *
 * Revision 1.61  1998/03/30  05:23:31  nisiwaki
 * gfx_xlu_rectangle_2c
 *
 * Revision 1.60  1998/03/30  04:49:47  hayakawa
 * Gfx版の関数は gfx_ で始まるようにするつもり
 *
 * Revision 1.59  1998/03/18  04:23:02  komatu
 * _LANGUAGE_C_PLUS_PLUSの追加
 *
 * Revision 1.58  1998/01/09  08:04:48  hayakawa
 * _texture_decal_shadow追加
 *
 * Revision 1.57  1998/01/09  06:42:09  hayakawa
 * _texture_z_light_fog_prim2追加
 *
 * Revision 1.56  1997/11/07  11:05:01  hayakawa
 * Game_playでエラー
 *
 * Revision 1.55  1997/11/04  13:22:36  soejima
 * *** empty log message ***
 *
 * Revision 1.54  1997/11/04  00:47:25  yoshida
 * *** empty log message ***
 *
 * Revision 1.53  1997/10/20  14:17:59  hayakawa
 * フォグ関係
 *
 * Revision 1.52  1997/10/17  14:16:10  hayakawa
 * デバッグ
 *
 * Revision 1.51  1997/10/17  14:12:32  hayakawa
 * set_fog追加
 *
 * Revision 1.50  1997/09/24  14:32:54  iwawaki
 * *** empty log message ***
 *
 * Revision 1.49  1997/09/01  13:45:14  iwawaki
 * *** empty log message ***
 *
 * Revision 1.48  1997/07/28  10:45:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.47  1997/07/24  04:05:48  tarukado
 * *** empty log message ***
 *
 * Revision 1.46  1997/07/23  08:35:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.45  1997/07/23  04:14:49  matutani
 * void texture_z_cld_poly_xlu_nd(Graph *graph)を追加
 *
 * Revision 1.44  1997/07/19  04:52:34  matutani
 * void texture_z_cld_poly_xlu(Graph *graph);
 * を追加
 *
 * Revision 1.43  1997/07/17  05:18:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.42  1997/07/16  12:31:38  tarukado
 * *** empty log message ***
 *
 * Revision 1.41  1997/07/10  10:18:23  soejima
 * texture_hilight_reflect
 *
 * Revision 1.40  1997/06/10  07:24:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.39  1997/06/06  00:48:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.38  1997/05/27  12:16:40  soejima
 * ＯＶＥＲＬＡＹ用
 *
 * Revision 1.37  1997/05/21  12:38:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.36  1997/05/12  07:01:42  iwawaki
 * *** empty log message ***
 *
 * Revision 1.35  1997/05/01  02:18:13  soejima
 * fox_gsCPSetModeSとrgba32texture入荷
 *
 * Revision 1.34  1997/04/16  04:48:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.33  1997/04/16  04:47:25  iwawaki
 * *** empty log message ***
 *
 * Revision 1.32  1997/04/15  02:07:53  iwawaki
 * *** empty log message ***
 *
 * Revision 1.31  1997/04/04  09:04:38  soejima
 * NEXT_POLY_XLU_DISP版 rectangle_a_prim削除
 *
 * Revision 1.30  1997/04/04  08:41:24  soejima
 * NEXT_POLY_XLU_DISP版 rectangle_a_prim作成
 *
 * Revision 1.29  1997/03/26  13:44:43  matutani
 * NEXT_POLYGON_XLU_DISP版 texture_z_light_prm_xlu_disp
 *
 * Revision 1.28  1997/03/25  01:21:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.27  1997/03/19  12:48:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.26  1997/02/25  13:17:19  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1997/02/21  07:44:28  soejima
 * fukidasi_polygon 追加
 *
 * Revision 1.24  1997/02/06  04:43:54  soejima
 * kscope_primをkaleido_scope_primに変更
 *
 * Revision 1.23  1997/01/14  07:28:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1996/12/25  05:26:56  iwawaki
 * *** empty log message ***
 *
 * Revision 1.21  1996/12/24  02:00:21  iwawaki
 * softsprite_prim追加
 *
 * Revision 1.20  1996/12/02  01:40:36  soejima
 * message_moji_polygon追加
 *
 * Revision 1.19  1996/11/19  01:18:36  hayakawa
 * このファイルをインクルードしてもエラーにならないようにした。
 *
 * Revision 1.18  1996/11/16  08:58:17  hayakawa
 * プロトタイプの追加 texture_decal_shadow
 *
 * Revision 1.17  1996/11/11  06:28:17  soejima
 * message_moji設定
 *
 * Revision 1.16  1996/11/01  01:40:22  soejima
 * rect_moji2 設定
 *
 * Revision 1.15  1996/10/22  02:33:40  soejima
 * kscope_prim追加
 *
 * Revision 1.14  1996/10/21  00:19:35  iwawaki
 * softsprite追加
 *
 * Revision 1.13  1996/10/18  08:34:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1996/10/15  01:22:57  soejima
 * vr_box_polygon追加
 *
 * Revision 1.11  1996/10/09  08:33:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1996/10/09  08:27:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.9  1996/10/09  08:18:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.8  1996/10/09  08:12:19  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1996/10/08  11:51:02  soejima
 * void rectangle_a_prim( Graph *graph )を追加
 *
 * Revision 1.6  1996/09/26  11:27:13  soejima
 * void polygon_z_light(Graph *graph); 追加
 *
 * Revision 1.5  1996/09/21  05:57:19  matutani
 * polygon_z_light_fog_prim()追加
 *
 * Revision 1.4  1996/09/20  02:48:02  matutani
 * extern void vertex_color_xlu_polygon(Graph *graph);追加
 *
 * Revision 1.3  1996/09/18  09:39:17  iwawaki
 * $Log追加
 * */


#ifndef INCLUDE_Z_RCP_H
#define INCLUDE_Z_RCP_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "graph.h"		/* Graph */
#include "z_play_h.h"		/* Game_play */

/*
 *
 * 拡張フォグ設定
 * 0 <= near <= 998:通常フォグ
 * near==999:もっとも遠いフォグを設定
 * near>1000:フォグなしと同じ効果を得られる
 * near < 0 :常にフォグカラーで表示される(特定の色で染めることができる)
 *
 * gfx_set_fog_nosync 同期命令無し
 * gfx_set_fog_sync   同期命令あり
 */
extern Gfx *
gfx_set_fog_nosync(
    Gfx *gp, 
    unsigned  int r, 
    unsigned  int g, 
    unsigned  int b, 
    unsigned  int a, 
    int n, 
    int f
);
extern Gfx *
gfx_set_fog_sync(
    Gfx *gp, 
    unsigned  int r, 
    unsigned  int g, 
    unsigned  int b, 
    unsigned  int a, 
    int n, 
    int f
);
extern Gfx *
set_fog(
    Gfx *gp,
    unsigned  int r,
    unsigned  int g,
    unsigned  int b,
    unsigned  int a,
    int n,
    int f
);

/*======================================================================*
 *						
 *	汎用
 *						
 *======================================================================*/
extern Gfx *rcp_mode_set(Gfx *next_disp, int type);
extern void gp_overlay_rcp_mode_set(Gfx **glistp, int type);

/*======================================================================*
 *						
 *	フィルレクタングルプリムカラー（ポインタ指定可）		
 *						
 *======================================================================*/
extern Gfx *fill_rectangle_prim_free(Gfx *next_disp); /* もうすぐ消す */
extern Gfx *gfx_fill_rectangle_prim(Gfx *gp);

/*======================================================================*
 *					
 *	透明テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern Gfx *gfx_texture_cullback_xlu(Gfx *gp);

/*======================================================================*
 *					
 *	ポリゴンプリムカラー	
 *					
 *======================================================================*/
extern void polygon_prim(Graph *graph);

/*======================================================================*
 *									*
 *	フィルレクタングルプリムカラー					*
 *									*
 *======================================================================*/
extern void fill_rectangle_prim(Graph *graph);

/*======================================================================*
 *								
 *	テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern void texture_cullback(Graph *graph);

/*======================================================================*
 *								
 *	透明テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern void xlu_texture_cullback(Graph *graph);

/*======================================================================*
 *					
 *	透明テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern void texture_cullback_xlu(Graph *graph);

/*======================================================================*
 *								
 *	補間テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern void morf_texture_cullback(Graph *graph);

/*======================================================================*
 *								
 *	（透明）補間テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern void xlu_morf_texture_cullback(Graph *graph);

/*======================================================================*
 *					
 *	透明補間テクスチャー，Ｚバッファ無し，シェーディング無し，表面表示のみ
 *								
 *======================================================================*/
extern void morf_texture_cullback_xlu(Graph *graph);

/*======================================================================*
 *									*
 *	プリミティブ ライト テクスチャ Ｚ				*
 *									*
 *======================================================================*/
extern void texture_z_light_prim(Graph *graph);

/*======================================================================*
 *									
 *	プリミティブ ライト テクスチャ Ｚ
 *
 * NEXT_POLYGON_XLU_DISP版 (by Matsutani)
 *									
 *======================================================================*/
extern void texture_z_light_prim_xlu_disp(Graph *graph);

/*======================================================================*
 *									*
 *	プリミティブ ライト テクスチャ Ｚフォグ（カラーディザ変更）	*
 *									*
 *======================================================================*/
extern void _texture_z_light_fog_prim2(Game_play *game_play);

/*======================================================================*
 *									*
 *	プリミティブ ライト テクスチャ Ｚ	フォグ			*
 *									*
 *======================================================================*/
extern void _texture_z_light_fog_prim(Graph *graph);
#define gfx_texture_z_light_fog_prim(gp)	rcp_mode_set((gp), 25)
#define gp_overlay_texture_z_light_fog_prim(glistp)	\
		gp_overlay_rcp_mode_set((glistp), 25)


/*======================================================================*
 *									*
 *	プリミティブ ライト テクスチャ Ｚ	フォグ（アルファ用）	*
 *									*
 *======================================================================*/
extern void _texture_z_light_fog_prim_xlu(Graph *graph);

/*======================================================================*
 *									*
 *	スぺキュラハイライト テクスチャ Ｚ				*
 *									*
 *======================================================================*/
extern void texture_z_hilight(Graph *graph);

/*======================================================================*
 *									*
 *	反射マッピング テクスチャ Ｚ					*
 *									*
 *======================================================================*/
extern void texture_z_reflect(Graph *graph);

/*======================================================================*
 *									*
 *	反射マッピング スぺキュラハイライト テクスチャ Ｚ		*
 *									*
 *======================================================================*/
extern void texture_z_hilight_reflect(Graph *graph);

/*======================================================================*
 *									*
 *	テクスチャレクタングル						*
 *									*
 *======================================================================*/
extern Gfx *gfx_xlu_rectangle_2c(Gfx *gp);
extern Gfx *gfx_rectangle(Gfx *gp);
extern void rectangle(Graph *graph);

/*======================================================================*
 *									*
 *	デカルテクスチャ						*
 *									*
 *======================================================================*/
extern void texture_decal(Graph *graph);
extern void _texture_decal_shadow(
    Graph    *graph
);

/*======================================================================*
 *									*
 *	フィルレクタングル						*
 *									*
 *======================================================================*/
extern void fill_rectangle(Graph *graph);

/*======================================================================*
 *									*
 *	テキスト文字                                                    *
 *									*
 *======================================================================*/
extern Gfx *gfx_rect_moji(Gfx *gp);

extern void rect_moji(Graph *graph);

extern void rect_moji2(Graph *graph);

extern void message_moji(Graph *graph);

extern void message_moji_polygon(Graph *graph);

/*--------------------------------------------------------------------------
 *
 * 頂点カラー（透過）
 * テクスチャ─無し
 *
 *------------------------------------------------------------------------*/
extern void vertex_color_xlu_polygon( Graph *graph );
 
/*======================================================================*
 *									*
 *	ライト ポリゴン Ｚ プリミティブ					*
 *									*
 *======================================================================*/
extern void polygon_z_light_prim(Graph *graph);

/*======================================================================*
 *									*
 *	ライト ポリゴン Ｚ プリミティブ ＦＯＧ				*
 *									*
 *======================================================================*/
extern void _polygon_z_light_fog_prim(Graph *graph);
#define gfx_polygon_z_light_fog_prim(gp)	rcp_mode_set((gp), 37)
#define gp_overlay_polygon_z_light_fog_prim(glistp)	\
		gp_overlay_rcp_mode_set((glistp), 37)

/*======================================================================*
 *									*
 *	ライト ポリゴン Ｚ						*
 *									*
 *======================================================================*/
extern void polygon_z_light( Graph *graph );

/*======================================================================*
 *									*
 *	レクタングルＡプリム						*
 *									*
 *======================================================================*/
extern Gfx *gfx_rectangle_a_prim(Gfx *gp);
extern void rectangle_a_prim( Graph *graph );
/* ＯＶＥＲＬＡＹ用 */
extern void overlay_rectangle_a_prim( Graph *graph );
extern void gp_overlay_rectangle_a_prim(Gfx **glistp);

/*======================================================================*
 *									*
 *	ヴァ─チャル・ボックス ポリゴン					*
 *									*
 *======================================================================*/
extern void vr_box_polygon( Graph *graph );

/*======================================================================*
 *									*
 *	ソフトスプライト						*
 *									*
 *======================================================================*/
extern void softsprite(Graph *graph);

/*======================================================================*
 *									*
 *	ソフトスプライト（プリミティブカラーセット）			*
 *									*
 *======================================================================*/
extern void softsprite_prim(Graph *graph);

/*
 * ソフトスプライト新規格
 */
extern Gfx *gfx_softsprite_prim_xlu(Gfx *gp);   /* 半透明プリムカラー */
extern Gfx *gfx_softsprite_z(Gfx *gp); 		/* Ｚ不透明 */
extern Gfx *gfx_softsprite_z_fog(Gfx *gp);      /* Ｚ不透明フォグ */
extern Gfx *gfx_softsprite_z_prim(Gfx *gp); 	/* Ｚ不透明プリムカラー */
extern Gfx *gfx_softsprite_z_prim_cld(Gfx *gp); /* Ｚ半透明プリムカラー */
extern Gfx *gfx_softsprite_z_prim_xlu(Gfx *gp); /* Ｚ半透明プリムカラー */
extern Gfx *gfx_softsprite_z_xlu(Gfx *gp); 	/* Ｚ半透明 */

/*======================================================================*
 *									*
 *	カレイド・スコープ						*
 *									*
 *======================================================================*/
extern void kaleido_scope_prim(Graph *graph);
/* ＯＶＥＲＬＡＹ用 */
extern void overlay_kaleido_scope_prim(Graph *graph);
#if 0
extern void kaleido_scope_prim_glistp( Gfx **glistpp );	/* 未使用？ */
#endif



/*======================================================================*
 *									*
 *	吹き出し ポリゴン						*
 *									*
 *======================================================================*/
extern void fukidasi_polygon(Graph *graph);

/*======================================================================*
 *									*
 *	ライト ポリゴン プリミティブ					*
 *									*
 *======================================================================*/
extern void polygon_light_prim(Graph *graph);

/*======================================================================*
 *									*
 *	テクスチャ Ｚ							*
 *									*
 *======================================================================*/
extern void texture_z(Graph *graph);

/*======================================================================*
 *									*
 *	テクスチャ Ｚ CLD_SRF/NEXT_POLY_XLU_DISPを使用			*
 *									*
 *======================================================================*/
extern void texture_z_cld_poly_xlu(Graph *graph);

/*======================================================================*
 *									*
 *	テクスチャ Ｚ CLD_SRF/NEXT_POLY_XLU_DISPを使用			*
 * ディザなくしバージョン                                               *
 *									*
 *======================================================================*/
extern void texture_z_cld_poly_xlu_nd(Graph *graph);

/*======================================================================*
 *									*
 *	ＲＧＢＡ３２テクスチャ						*
 *									*
 *======================================================================*/
extern void rgba32texture(Graph *graph);
/* 仮ＯＶＥＲＬＡＹ用 */
extern void gp_overlay_rgba32texture( Gfx **glistp );

/*======================================================================*
 *									*
 *	反射マッピング スぺキュラハイライト テクスチャ 			*
 *									*
 *======================================================================*/
extern void texture_hilight_reflect(Graph *graph);

/*======================================================================*
 *									*
 *	テクスチャスクロール			 			*
 *									*
 *======================================================================*/

/*
 * アニメモデル作成関数
 * テクスチャスクロールの設定
 */
extern Gfx *gfx_tex_scroll2(
    Gfx		**gpp,
    int	tex_x_pos,
    int tex_y_pos,
    int tex_x_size,
    int tex_y_size
);

/*
 * アニメモデル作成関数
 * テクスチャスクロールの設定
 */
extern Gfx *gfx_tex_scroll(
    Gfx		**gpp,
    int	tex_x_pos,
    int tex_y_pos
);

/*
 * アニメモデル作成関数
 * テクスチャスクロールの設定
 */
extern Gfx *tex_scroll(
    Graph *graph,
    int tex_x_pos,
    int tex_y_pos
);

/*
 * アニメモデル作成関数
 * テクスチャスクロールの設定
 */
extern Gfx *tex_scroll2(
    Graph *graph,
    int tex_x_pos,
    int tex_y_pos,
    int tex_x_size,
    int tex_y_size
);

/*
 * アニメモデル作成関数
 * ２枚テクスチャスクロールの設定
 */
extern Gfx *two_tex_scroll(
    Graph	*graph,
    int tex1_tileno,
    int tex1_x_pos,
    int tex1_y_pos,
    int tex1_x_size,
    int tex1_y_size,
    int tex2_tileno,
    int tex2_x_pos,
    int tex2_y_pos,
    int tex2_x_size,
    int tex2_y_size
);

/*
 * アニメモデル作成関数
 * ２枚テクスチャスクロールの設定
 * 環境カラーの設定
 */
extern Gfx *two_tex_scroll_env(
    Graph *graph,
    int tex1_tileno,
    int tex1_x_pos,
    int tex1_y_pos,
    int	tex1_x_size,
    int tex1_y_size,
    int tex2_tileno,
    int tex2_x_pos,
    int tex2_y_pos,
    int tex2_x_size,
    int tex2_y_size,
    int red,
    int green,
    int blue,
    int alpha
);

/*
 * アニメモデル作成関数
 * 環境カラーの設定のみ
 */
extern Gfx *anime_envcolor(
    Graph *graph,
    int red,
    int green,
    int blue,
    int alpha
    );

/*
 * 『何もしない』ディスプレイリスト
 */
extern Gfx dl_noop[];

/*-----------------------------------------------------------------------
 *
 *	ディスプレイリスト初期設定
 *
 *----------------------------------------------------------------------*/
extern void DisplayList_initialize(
    Graph         *this,
    unsigned char r,
    unsigned char g,
    unsigned char b
);
extern void static_DisplayList_initialize(Graph *graph);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_rcp.h end ***/
