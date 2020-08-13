/*
 * $Id: graph.h,v 2.2 1998/10/27 11:07:23 hayakawa Exp $
 *
 * グラフィックスレッドクラス
 *
 * $Log: graph.h,v $
 * Revision 2.2  1998/10/27  11:07:23  hayakawa
 * スケール対応テスト
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.43  1998/09/07 05:47:36  zelda
 * *** empty log message ***
 *
 * Revision 1.42  1998-09-05 20:09:58+09  zelda
 * *** empty log message ***
 *
 * Revision 1.41  1998-09-05 17:52:09+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.40  1998-08-28 13:51:08+09  zelda
 * *** empty log message ***
 *
 * Revision 1.39  1998-08-28 10:30:49+09  zelda
 * ROM_Dでないときのgraph_alloc16の定義を間違えていた
 *
 * Revision 1.38  1998-08-27 22:48:09+09  hayakawa
 * gfxalloc独立化
 * graph_alloc 更新
 *
 * Revision 1.37  1998-08-21 20:38:48+09  hayakawa
 * graph_newオプティマイズ
 * graph_alloc関連を16バイトバウンダリに変更
 *
 * Revision 1.36  1998-08-10 11:07:59+09  hayakawa
 * ROM_Dの時だけDLにデバッグ情報を入れるようにしてみた
 *
 * Revision 1.35  1998-08-07 22:25:52+09  zelda
 * くそー
 *
 * Revision 1.34  1998-08-07 20:20:44+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.33  1998-08-07 17:34:07+09  hayakawa
 * _graph を __graph に変更
 * OPEN_DISP, CLOSE_DISP改造
 *
 * Revision 1.32  1998-08-07 16:05:24+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.31  1998-08-06 22:45:32+09  hayakawa
 * OPEN_DISP, CLOSE_DISPに細工
 *
 * Revision 1.30  1998-07-24 22:00:29+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.29  1998-07-24 21:49:36+09  hayakawa
 * Graph_newa graph_newa追加
 *
 * Revision 1.28  1998-04-02 17:55:28+09  hayakawa
 * WORK追加
 *
 * Revision 1.27  1998/04/01  02:47:12  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.26  1998/03/31  13:38:28  hayakawa
 * ワーク用ディスプレイリスト領域追加
 * いろいろ
 *
 * Revision 1.25  1998/03/18  08:03:12  hayakawa
 * Ｃ＋＋対応
 *
 * Revision 1.24  1997/12/18  04:24:49  hayakawa
 * TaskEndCallBackの追加
 *
 * Revision 1.23  1997/11/17  06:11:49  morita
 * GRAPH_STACKSIZEを増やした
 *
 * Revision 1.22  1997/11/16  13:38:42  hayakawa
 * STACKSIZE調整
 *
 * Revision 1.21  1997/10/03  14:19:31  hayakawa
 * EnableNextSwapFrame／IsDisableNextSwapFrameなど
 *
 * Revision 1.20  1997/07/22  11:10:47  hayakawa
 * 独立型Gfx領域借用関数追加
 *
 * Revision 1.19  1997/04/16  11:42:52  hayakawa
 * ダイナミックバッファとフレームバッファの独立化のためにcfb_bankを新設
 *
 * Revision 1.18  1997/03/26  04:26:27  hayakawa
 * スタックを512バイト増やした
 *
 * Revision 1.17  1997/03/20  12:51:57  hayakawa
 * GRAPH_STACKSIZE追加
 *
 * Revision 1.16  1997/03/13  11:42:45  hayakawa
 * フレームバッファ情報対応
 * 構造体のメンバをソートした
 *
 * Revision 1.15  1997/02/14  07:49:57  hayakawa
 * OVERLAY用のマクロ追加
 *
 * Revision 1.14  1997/02/06  07:21:58  hayakawa
 * Ｃ＋＋でコンパイルできるように変更
 *
 * Revision 1.13  1997/02/05  11:45:37  hayakawa
 * 構造体メンバ追加
 * graph_gfxopen/graph_gfxclose新設
 *
 * Revision 1.12  1997/01/13  11:52:28  hayakawa
 * 条件コンパイルをはずした
 *
 * Revision 1.11  1997/01/06  07:40:50  hayakawa
 * ラインと半透明に対応
 *
 * Revision 1.10  1996/10/09  05:31:47  hayakawa
 * Gfxポインタの設定ができるように SET_NOW_DISP 関数を追加した
 *
 * Revision 1.9  1996/10/02  06:41:26  hayakawa
 * とりあえずなにもしないFLUSH_DISP／REOPEN_DISPを追加
 *
 * Revision 1.8  1996/10/01  10:39:46  hayakawa
 * 不要なメンバの削除
 *
 */

#ifndef __GRAPH_H_
#define __GRAPH_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "u64basic.h"
#include "u64types.h"
#include "THA_GA.h"
#include "sched.h"

#if 0
#define GRAPH_STACKSIZE (6144+512)	/* もう少し余裕が必要 */
#else
#define GRAPH_STACKSIZE 0x1800	/* 実績 0x1200以上 */
#endif

typedef union {    
    struct {
        short     type;
    } gen;
    struct {
        short     type;
    } done;
    OSScMsg       app;
} GraphMsg;

/*
 * グラフィックステートとディスプレイリスト
 * この構造体をグラフのディスプレイリストを生成するすべての関数の第1引数にする
 * ただし、非独立型に限る
 * 関数の先頭と末尾で、OPEN_DISP/CLOSE_DISPを呼び出す
 * 
 */
#define MAX_MESGS               8
typedef struct graph_s {
    Gfx		*Gfx_list00P_top;
    Gfx		*Gfx_list01P_top;
#ifndef NOUSE_LINE_UCODE
    Gfx		*Gfx_list02P_top;
    Gfx		*Gfx_list03P_top;
#else
    Gfx		*_Gfx_list02P_top;
    Gfx		*_Gfx_list03P_top;
#endif /* NOUSE_LINE_UCODE */
    Gfx		*Gfx_list04P_top;
    Gfx		*gfxsave;
    GraphMsg 	msg;            /* completion message */
    OSMesg 	graphReplyMsgBuf[MAX_MESGS];
    OSMesgQueue *sched_cmdQ;
    OSMesgQueue graphReplyMsgQ;
    OSScTask	ossctask00p;
#if 01
    OSScTask	ossctask01p;	/* 4+4+4+4+64+4+4+8+8=104 */
    OSScTask	ossctask02p;
    Gfx		*Gfx_list05P_top; /* 描画前の作業用エリア */
    THA_GA 	work_thaga;
    char        _ossctask03p[104 - sizeof(Gfx *) - sizeof(THA_GA)];
    char        _ossctask04p[4+4+4+4+64+4+4+8+8];
#endif
    OSSched 	*sc;
    OSViMode	*vimode;	/* !NULL:osViSetMode(vimode) */
#ifndef NOUSE_LINE_UCODE
    THA_GA 	line_opa_thaga;
    THA_GA 	line_xlu_thaga;
#else
    THA_GA 	_line_opa_thaga;
    THA_GA 	_line_xlu_thaga;
#endif /* NOUSE_LINE_UCODE */
    THA_GA 	overlay_thaga;
    THA_GA 	poly_opa_thaga;
    THA_GA 	poly_xlu_thaga;
    int 	frame_counter;	/* グラフィックフレームカウンタ */
    u16		*FrameBufferP;	/* 描画対象フレームバッファ */
    u16		*RenderBufferP;	/* 作業用フレームバッファ */
    u32 	vispecial;	/* osViSetSpecialFeatures */
    int 	cfb_bank;	/* フレームバッファバンク */
    void	(*TaskEndCallBack)(struct graph_s *, void *);
    void	*TaskEndClientData;
    float	vixscale, viyscale; /* スケール */
} graph_t;
typedef graph_t Graph;

/*
 * タスク終了時のコールバック関数の登録マクロ
 * 注意）手抜きなので関数は一つしか登録できません
 */
#define graph_AddTaskEndCallBack(graph, callback, client_data) \
do { \
     (graph)->TaskEndCallBack = (callback); \
     (graph)->TaskEndClientData = (client_data); \
} while (0)
#define graph_RemoveTaskEndCallBack(graph, callback, client_data) \
do { \
    if ((graph)->TaskEndCallBack   == (callback) && \
	(graph)->TaskEndClientData == (client_data)) { \
        (graph)->TaskEndCallBack   = NULL; \
        (graph)->TaskEndClientData = NULL; \
    }\
} while (0)
    
    /*
     * OPEN_DISP/CLOSE_DISP
     *
     * ちょっとトリッキーです。気をつけてください。
     *
     */
#ifndef ROM_D
#define OPEN_DISP(graph) 			\
{ 						\
    Graph *__graph = (graph); 			\
    int __poly_gfx_opened = 0; 			\
    (void)0			/* rquire `;'  */

#define CLOSE_DISP(graph) 			\
    do { 					\
	(void)&(graph)->Gfx_list00P_top; 	\
	(void)__poly_gfx_opened; 		\
    } while (0); 				\
}   (void)0			/* rquire `;'  */
#else
typedef struct {
    Gfx *tmp_poly_opa;
    Gfx *tmp_poly_xlu;
    Gfx *tmp_overlay;
} __GraphCheck;
extern void __graphcheck_opendisp(__GraphCheck *this, Graph *graph, char *file, int line);
extern void __graphcheck_closedisp(__GraphCheck *this, Graph *graph, char *file, int line);
#define OPEN_DISP(graph) 			\
{ 						\
    Graph *__graph = (graph); 			\
    int __poly_gfx_opened = 0; 			\
    __GraphCheck __graphcheck; 			\
    __graphcheck_opendisp(&__graphcheck, graph, __FILE__, __LINE__); \
    (void)0			/* rquire `;'  */

#define CLOSE_DISP(graph) 			\
    do { 					\
	__graphcheck_closedisp(&__graphcheck, graph, __FILE__, __LINE__); \
       	(void)__poly_gfx_opened; 		\
    } while (0); 				\
}   (void)0			/* rquire `;'  */
#endif

#define NEXT_POLY_OPA_DISP 	THA_GA_NEXT_DISP(&__graph->poly_opa_thaga)
#define NEXT_POLY_XLU_DISP 	THA_GA_NEXT_DISP(&__graph->poly_xlu_thaga)
#ifndef NOUSE_LINE_UCODE
#define NEXT_LINE_OPA_DISP 	THA_GA_NEXT_DISP(&__graph->line_opa_thaga)
#define NEXT_LINE_XLU_DISP 	THA_GA_NEXT_DISP(&__graph->line_xlu_thaga)
#endif /* NOUSE_LINE_UCODE */
#define NEXT_OVERLAY_DISP 	THA_GA_NEXT_DISP(&__graph->overlay_thaga)
#define NEXT_WORK_DISP 		THA_GA_NEXT_DISP(&__graph->work_thaga)
#define NEXT_DISP 		NEXT_POLY_OPA_DISP
#define NOW_POLY_OPA_DISP 	(Gfx *)THA_GA_getHeadPtr(&__graph->poly_opa_thaga)
#define NOW_POLY_XLU_DISP 	(Gfx *)THA_GA_getHeadPtr(&__graph->poly_xlu_thaga)
#ifndef NOUSE_LINE_UCODE
#define NOW_LINE_OPA_DISP 	(Gfx *)THA_GA_getHeadPtr(&__graph->line_opa_thaga)
#define NOW_LINE_XLU_DISP 	(Gfx *)THA_GA_getHeadPtr(&__graph->line_xlu_thaga)
#endif /* NOUSE_LINE_UCODE */
#define NOW_OVERLAY_DISP 	(Gfx *)THA_GA_getHeadPtr(&__graph->overlay_thaga)
#define NOW_WORK_DISP 		(Gfx *)THA_GA_getHeadPtr(&__graph->work_thaga)
#define NOW_DISP 		NOW_POLY_OPA_DISP
#define SET_NOW_POLY_OPA_DISP(ptr) THA_GA_setHeadPtr(&__graph->poly_opa_thaga, ptr)
#define SET_NOW_POLY_XLU_DISP(ptr) THA_GA_setHeadPtr(&__graph->poly_xlu_thaga, ptr)
#ifndef NOUSE_LINE_UCODE
#define SET_NOW_LINE_OPA_DISP(ptr) THA_GA_setHeadPtr(&__graph->line_opa_thaga, ptr)
#define SET_NOW_LINE_XLU_DISP(ptr) THA_GA_setHeadPtr(&__graph->line_xlu_thaga, ptr)
#endif /* NOUSE_LINE_UCODE */
#define SET_NOW_OVERLAY_DISP(ptr) THA_GA_setHeadPtr(&__graph->overlay_thaga, ptr)
#define SET_NOW_WORK_DISP(ptr) 	THA_GA_setHeadPtr(&__graph->work_thaga, ptr)
#define SET_NOW_DISP(ptr) 	SET_NOW_POLY_OPA_DISP(ptr)
    
extern void graph_proc(void *arg);
extern void graph_ct(Graph *);
extern void graph_dt(Graph *);

/*
 * graph_alloc   : おすすめ
 * graph_alloc15 : 汎用
 * graph_alloc16 : size が 16 の倍数の時専用
 * サイズで確保
 */

#ifdef ROM_D
extern void *_graph_alloc(Graph *, size_t);	/* １フレーム後に解放するmalloc */
#define graph_alloc16(graph, size) 	_graph_alloc(graph, size)
#define graph_alloc15(graph, size) 	_graph_alloc(graph, size)
#define graph_alloc(graph, size) 	_graph_alloc(graph, size)
#else
#define graph_alloc16(graph, size) 	((void *)((graph)->poly_opa_thaga.tha.tail_p = (char *)((int)(graph)->poly_opa_thaga.tha.tail_p - (size))))
#define graph_alloc15(graph, size) 	graph_alloc16(graph, (((size) + 15) & ~15))
#define graph_alloc(graph, size) 	graph_alloc15(graph, size)
#endif

/*
 * graph_new   : おすすめ
 * graph_new15 : 汎用
 * graph_new16 : sizeof(type) が 16 の倍数の時専用
 * graph_newa  : 配列用
 * 型で確保
 */
#define graph_new16(graph, type) (type *)graph_alloc16(graph, sizeof(type))
#define graph_new15(graph, type) (type *)graph_alloc15(graph, sizeof(type))
#define graph_new(graph, type) (((sizeof(type) & 15) == 0) ? graph_new16(graph, type) : graph_new15(graph, type))

#define graph_newa(graph, type, count) ((type *)graph_alloc(graph, sizeof(type) * (count)))

#define Graph_alloc(size) 	graph_alloc(graph, size)
#define Graph_new(type) 	graph_new(graph, type)
#define Graph_newa(type, count) graph_newa(graph, type, count)


/*
 * 表示フレームバッファのスワップ制御用マクロ
 */
#define DisableNextSwapFrame() 	(SREG(33) |= 1)
#define IsDisableNextSwapFrame() ((SREG(33) & 1) != 0)
#define EnableNextSwapFrame() 	(SREG(33) &= ~1)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __GRAPH_H_ */
