#ifndef _GBI_H_

#if 1/*defined(__GNUC__)*/
#include "gbi__.h"		/* 括弧の修正済(g/gs) */
#else  /* defined(__GNUC__) */
#include "/usr/include/PR/gbi.h"
#endif /* defined(__GNUC__) */

/*
 * gSPLookAtとgDPLoad{Texture,Multi}{Block,Tile}*
 * 系は最後のセミコロンが抜けている
 */

/* (s32),(s16)キャスト抜け */
#undef gSPScisTextureRectangle
/* like gSPTextureRectangle but accepts negative position arguments */
#define gSPScisTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy) \
do {                                                                         \
    Gfx *_g = (Gfx *)(pkt);                                                  \
                                                                             \
    _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) |                              \
                    _SHIFTL(MAX((s16)(xh),0), 12, 12) |                      \
                    _SHIFTL(MAX((s16)(yh),0), 0, 12));                       \
    _g->words.w1 = (_SHIFTL((tile), 24, 3) |                                 \
                    _SHIFTL(MAX((s16)(xl),0), 12, 12) |                      \
                    _SHIFTL(MAX((s16)(yl),0), 0, 12));                       \
    gImmp1(pkt, G_RDPHALF_1,                                                 \
                (_SHIFTL(((s32)(s) -                                         \
                          (((s16)(xl) < 0) ?                                 \
                           (((s16)(dsdx) < 0) ?                              \
                            ((s32)MAX((((s16)(xl)*(s16)(dsdx))>>7),0)) :     \
			    ((s32)MIN((((s16)(xl)*(s16)(dsdx))>>7),0))) : 0)), \
			 16, 16) |                                           \
                 _SHIFTL(((s32)(t) -                                         \
                          (((s16)(yl) < 0) ?                                 \
                           (((s16)(dtdy) < 0) ?                              \
                            ((s32)MAX((((s16)(yl)*(s16)(dtdy))>>7),0)) :     \
                            ((s32)MIN((((s16)(yl)*(s16)(dtdy))>>7),0))) : 0)), \
			 0, 16)));                                           \
    gImmp1(pkt, G_RDPHALF_2, (_SHIFTL((dsdx), 16, 16) |                      \
                              _SHIFTL((dtdy), 0, 16)));                      \
} while (0)

#define	_GBI_H_

#endif /* _GBI_H_ */
