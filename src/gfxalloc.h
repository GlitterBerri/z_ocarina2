/*
 * $Id: gfxalloc.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 * ÆÈÎ©·¿GfxÎÎ°è¼ÚÍÑ´Ø¿ô
 *
 * »ÈÍÑÎã¡Ë
 * {
 *     Gfx *glistp_new, *my_shape;
 *
 *     mtx = gfxalloc(&glistp, sizeof(Mtx));
 *     gSPMatrix(glistp++, mtx);
 *     my_shape = gfxopen(glistp, 0);
 *     glistp_new = make_my_shape(my_shape);
 *     glistp = graph_gfxclose(glistp, glistp_new);
 *     {
 *         gDPSetPrimColor(glistp++, 0, 0, 255, 255, 50, 255);
 *         gSPDisplayList(glistp++, my_shape);
 *         gDPSetPrimColor(glistp++, 0, 0, 200, 255, 150, 255);
 *         gSPDisplayList(glistp++, my_shape);
 *     }
 * }
 *
 * $Log: gfxalloc.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.2  1998/08/28 05:18:17  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1998-08-27 16:55:24+09  hayakawa
 * Initial revision
 *
 */

#ifndef __GFXALLOC_H_
#define __GFXALLOC_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
#include "gbi.h"

extern Gfx *gfxopen(Gfx *glistp);
extern Gfx *gfxclose(Gfx *glistp, Gfx *glistp_new);
extern void *gfxalloc(Gfx **glistpp, size_t size);

#define GfxOpen(glistp) 	((glistp) + 1)
#define GfxClose(glistp, child) (gSPBranchList(glistp, child), child)
#define GfxAlloc(glistp, size) 	gfxalloc(&(glistp), size)


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __GFXALLOC_H_ */
