/*
 * $Id: header.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 * バカチョンヘッダ
 * これを使わずに個別にインクルードすべき
 * $Log: header.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.13  1996/11/26  05:52:48  hayakawa
 * インクルードされるとワーニングを発生するようにした
 *
 * Revision 1.12  1996/11/21  06:28:32  hayakawa
 * いつまでもバカチョンヘッダをインクルードするでないと出せるようにしてみた
 *
 */

#ifndef __HEADER_H_
#define __HEADER_H_


#ifndef __cplusplus
#error  いつまでもバカチョンヘッダをインクルードするでない
#endif

#include "stdlib64.h"
#include "math64.h"
#include "ultra64.h"
#include "ramrom.h"

#include "macro.h"
#include "u64patch.h"
#include "u64macro.h"
#include "u64types.h"

#include "controller.h"
#include "uty.h"
#include "bg.h"
#include "bgthread.h"
#include "mtxuty.h"
#include "bguty.h"

#include "bg_msgmgr.h"
#include "dynamic.h"
#include "nameentry.h"
#include "debug.h"

#endif /* __HEADER_H_ */
