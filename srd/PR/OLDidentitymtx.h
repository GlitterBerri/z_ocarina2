/*
 * $Id: OLDidentitymtx.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * 単位行列の定義
 *
 * $Log: OLDidentitymtx.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.2  1998-04-01 11:42:16+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.1  1998/03/05  08:06:48  hayakawa
 * Initial revision
 *
 */

#ifndef __IDENTITYMTX_H_
#define __IDENTITYMTX_H_

#include "u64types.h"		/* Mtx2 */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

extern Mtx2 IdentityMtx;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __IDENTITYMTX_H_ */
