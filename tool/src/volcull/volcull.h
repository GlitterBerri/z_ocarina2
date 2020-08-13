/*
 * $Id: volcull.h,v 1.1 2003/03/10 23:12:46 tong Exp $
 *
 * 自動ボリュームカリング
 *
 * gSPDisplayList の先のディスプレイリストに含まれる頂点から、
 * カリング用の頂点を抽出し、カリングディスプレイリストを作成、連結する
 *
 *
 * $Log: volcull.h,v $
 * Revision 1.1  2003/03/10 23:12:46  tong
 * Initial revision
 *
 * Revision 1.1  1996/10/11  02:08:27  hayakawa
 * Initial revision
 *
 *
 */
#ifndef __VOLCULL_H_
#define __VOLCULL_H_

#include "ultra64.h"

#if __cplusplus
extern "C" {
#endif

    Gfx *create_volume_culling(Gfx *gfxp);

#if __cplusplus
}
#endif

#endif /* __VOLCULL_H_ */
