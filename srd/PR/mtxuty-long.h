/*
 * $Id: mtxuty-long.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * $Log: mtxuty-long.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.7  1998-04-01 11:38:54+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 * IdentityMtx削除
 *
 * Revision 1.6  1996/11/21  06:34:28  hayakawa
 * インクルードするべきファイルをインクルードしていなかった
 *
 * Revision 1.5  1996/10/20  09:15:30  hayakawa
 * _LANGUAGE_C_PLUS_PLUS を __cplusplus に変更
 *
 */

/*
 * 行列演算支援関数 (long)
 */

#ifndef __MTXUTY_LONG_H_
#define __MTXUTY_LONG_H_

#include "u64types.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

void
guLoadIdentityi(
    Mtx *const m1
);
void
guLoadMatrixi(
    Mtx *const m1,
    const Mtx *const m2
);
void
guMultMatrixi(
    Mtx *const m1,
    const Mtx *const m2
);
void
guRotatei(
    Mtx *const m1,
    const float angle,		/* 回転角度 */  
    const float x,
    const float y,
    const float z
);
void
guScale3i(
    Mtx *const m1,
    const float x,
    const float y,
    const float z
);
void
guScale2i(
    Mtx *const m1,
    const float x,
    const float y
);
void
guRotateZi(
    Mtx *const m1,
    const float angle		/* 回転角度 */  
);
void
guRotateYi(
    Mtx *const m1,
    const float angle		/* 回転角度 */  
);
void
guRotateXi(
    Mtx *const m1,
    const float angle		/* 回転角度 */  
);
void
guTranslate2i(
    Mtx *const m1,
    const float x,
    const float y
);
void
guTranslate3i(
    Mtx *const m1,
    const float x,
    const float y,
    const float z
);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __MTXUTY_LONG_H_ */
