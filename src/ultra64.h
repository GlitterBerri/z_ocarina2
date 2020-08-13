/*
 * $Id: ultra64.h,v 2.1 1998/10/22 11:41:56 zelda Exp $
 *
 * 必要なものを厳選
 *
 * $Log: ultra64.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1998/03/17 12:34:00  hayakawa
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.1  1998/03/17  12:30:45  hayakawa
 * Initial revision
 *
 */

#ifndef _ULTRA64_H_
#define _ULTRA64_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
/* libaudio.h のワーニング抑制 */
#ifndef __PATCH_LIBAUDIO_H_
#define __PATCH_LIBAUDIO_H_
struct PVoice_s {int v;};
struct ALParam_s {int v;};
struct ALMainBus_s {int v;};
struct ALAuxBus_s {int v;};
struct ALFilter_s {int v;};
#endif /* __PATCH_LIBAUDIO_H_ */

#include <PR/ultratypes.h>	/* u8,u16,...,size_t, TRUE,FALSE,NULL */
#include <PR/os.h>		/* ultratypes, OSContPad,A_BUTTON,osGetTime,osMotorStart,bcopy,osSyncPrintf */
#include <PR/mbi.h>		/* gbi+abi, SEGMENT_OFFSET */
#include <PR/gu.h>		/* ultratypes+mbi+sptask, gu*, sin */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" { */
#endif

#include "u64patch.h"

#endif
