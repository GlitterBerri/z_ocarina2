/*
 * $Id: sys_vimgr.h,v 1.1 1998/11/10 06:43:56 zelda Exp $
 *
 * ビデオマネージャ
 *
 * $Log: sys_vimgr.h,v $
 * Revision 1.1  1998/11/10  06:43:56  zelda
 * Initial revision
 *
 */

#ifndef __SYS_VIMGR_H_
#define __SYS_VIMGR_H_

#include "os.h"		/* OSViMode */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    extern OSViMode vimode;
    extern u8 vimode_no;
    extern u8 viextendvstart;
    extern u8 vidirty;
    extern u32 vispecial;
    extern float vixscale;
    extern float viyscale;

    extern void viBlack(int flag);
    extern void viRetrace(void);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __SYS_VIMGR_H_ */
