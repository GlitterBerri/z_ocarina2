/*
 * $Id: ultra64.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * /usr/include/PR/ultra64.h の代わりにインクルードする
 *
 * $Log: ultra64.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.5  1999-05-11 15:38:25+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1997-03-05 19:52:34+09  hayakawa
 * libaudio.h のワーニング抑制
 *
 * Revision 1.3  1996/10/04  05:48:23  hayakawa
 * パッチの強制インクルード
 *
 * Revision 1.2  1996/10/04  05:27:28  hayakawa
 * ディレクトリの変更
 *
 */

/**************************************************************************
 *                                                                        *
 *               Copyright (C) 1994, Silicon Graphics, Inc.               *
 *                                                                        *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright  law.  They  may not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *                                                                        *
 *************************************************************************/

#ifndef _ULTRA64_H_
#define _ULTRA64_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
    
#if 0
/* libaudio.h のワーニング抑制 */
#ifndef __PATCH_LIBAUDIO_H_
#define __PATCH_LIBAUDIO_H_
struct PVoice_s {int v;};
struct ALParam_s {int v;};
struct ALMainBus_s {int v;};
struct ALAuxBus_s {int v;};
struct ALFilter_s {int v;};
#endif /* __PATCH_LIBAUDIO_H_ */
#endif

#include <PR/ultratypes.h>
#include <PR/rcp.h>
#include <PR/os.h>
#include <PR/region.h>
#include <PR/rmon.h>
#include <PR/sptask.h>
#include <PR/mbi.h>
#include <PR/libaudio.h>
#include <PR/gu.h>
#include <PR/ramrom.h>
#include <PR/sp.h>
#include <PR/ucode.h>
#include <PR/ultraerror.h>
#include <PR/ultralog.h>

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#include "u64patch.h"

#endif
