/*
 * $Id: count.h,v 1.1.1.1 2003/03/10 22:42:25 tong Exp $
 *
 * シェイプ中のポリゴン数を数える
 *
 * $Log: count.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:25  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 1.5  1998-08-20 22:11:16+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-08-06 22:51:00+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1998-08-03 11:02:00+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1997/10/10  08:29:36  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1997/01/28  08:42:01  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __COUNT_H_
#define __COUNT_H_

#include "ultra64.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    typedef struct ucode_info_s {
	int ucode_type;		/* 1:f3dex 2:l3dex 3:s2dex */
	void *textstart;
    } ucode_info_t;
    typedef struct count_s {
	u32 segment_base[16];
	Gfx *dl_stack[18];
	int dl_depth;		/* ディスプレイリストの段数 */
	int dl_cnt;		/* ディスプレイリストの数 */
	int vtx_cnt;		/* 頂点の数 */
	int spvtx_cnt;		/* SPVetrexの数 */
	int tri1_cnt;		/* SP1Triangleの数 */
	int tri2_cnt;		/* SP2Trianglesの数 */
	int quad_cnt;		/* SP1Quadrangleの数 */
	int line_cnt;		/* SP1Lineの数 */
	int loaducode_cnt;	/* gsSPLoadUcodeの数 */
	int need_pipesync;
	int need_tilesync;
	int need_loadsync;
	int sync_err;
	int verbose;
	int current_ucode_type;	/* マイクロコード種別  */
				/* 0:不明  */
				/* 1:F3DEX系 */
				/* 2:L3DEX系 */
				/* 3:S2DEX系 */
	int ucode_info_max;
	ucode_info_t *ucode_info_tbl;
	u32 state_othermode_h;
	u32 state_othermode_l;
	u32 state_geometory_mode;
    } count_t;

    extern void count_init(count_t *);
    extern void count_cleanup(count_t *);
    extern void count_check(count_t *, Gfx *gfxp);
    extern void count_set_ucode_info(count_t *, int ucode_info_max, ucode_info_t *ucode_info_tbl);
    extern void count_set_first_ucode(count_t *, void *textstart);

#if STANDALONE
    extern void do_count(Gfx *gfxp);
#endif

#define count_gDPNoOpTag3(pkt, b, w, h) gDma1p(pkt, G_NOOP, w, h, b)
#define count_gDPNoOpHere(pkt) 	count_gDPNoOpTag3(pkt, 1, __FILE__, __LINE__)
#define count_gDPNoOpString(pkt, s, n) 	count_gDPNoOpTag3(pkt, 2, s, n)
#define count_gDPNoOpWord(pkt, w, n) 	count_gDPNoOpTag3(pkt, 3, w, n)
#define count_gDPNoOpFloat(pkt, f, n) 	count_gDPNoOpTag3(pkt, 4, *(u32*)&(f), n)
#define count_gDPNoOpVerbose(pkt) 	count_gDPNoOpTag3(pkt, 5, 0, 1)
#define count_gDPNoOpQuiet(pkt) 	count_gDPNoOpTag3(pkt, 5, 0, 0)
#define count_gDPNoOpCallBack(pkt, func, n) count_gDPNoOpTag3(pkt, 6, func, n)
#define count_gDPNoOpOpenDisp2(pkt, file, line) \
    	count_gDPNoOpTag3(pkt, 7, file, line)
#define count_gDPNoOpOpenDisp(pkt) \
	count_gDPNoOpOpenDisp2(pkt, __FILE__, __LINE__)
#define count_gDPNoOpCloseDisp2(pkt, file, line) \
	count_gDPNoOpTag3(pkt, 8, file, line)
#define count_gDPNoOpCloseDisp(pkt) \
	count_gDPNoOpCloseDisp2(pkt, __FILE__, __LINE__)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __COUNT_H_ */
