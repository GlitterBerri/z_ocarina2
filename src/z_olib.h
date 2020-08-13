/*#### 	$Id: z_olib.h,v 2.1 1998/10/22 11:51:48 zelda Exp $
 |###   --- 補足ライブラリ集 ---
 |##
 |#         CameraやView等で使用
 |
 * $Log: z_olib.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.22  1998/09/21 14:23:37  ogawa
 * *** empty log message ***
 *
 * Revision 1.21  1998-09-21 23:12:42+09  hayakawa
 * Memsetをmemsetにdefineしているのをコメントアウトした
 * のでよろしく
 *
 * Revision 1.20  1998-06-26 19:58:05+09  ogawa
 * *** empty log message ***
 *
 * Revision 1.19  1998-06-26 16:20:54+09  ogawa
 * *** empty log message ***
 *
 * Revision 1.18  1998-06-10 19:43:44+09  ogawa
 * gamealloc_malloc()の廃止
 *
 * Revision 1.17  1998-04-01 11:46:25+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.16  1998/03/25  11:50:29  yoshida
 * Ｃ＋＋からのインクルードに対応
 *
 * Revision 1.15  1998/02/26  04:32:31  ogawa
 * *** empty log message ***
 *
 * Revision 1.14  1998/01/30  12:29:02  ogawa
 * *** empty log message ***
 *
 * Revision 1.13  1997/11/28  04:44:55  ogawa
 * *** empty log message ***
 *
 * Revision 1.12  1997/11/28  01:31:34  ogawa
 * *** empty log message ***
 *
 * Revision 1.11  1997/08/25  05:22:21  ogawa
 * *** empty log message ***
 *
 * Revision 1.10  1997/05/15  01:07:02  ogawa
 * *** empty log message ***
 *
 * Revision 1.9  1997/05/15  01:00:40  ogawa
 * *** empty log message ***
 *
 * Revision 1.8  1997/03/14  00:35:47  hayakawa
 * 基本ヘッダu64basic.hから、math64.hを削除したので、その対処
 * DEG2RAD、RAD2DEGを利用するようにした
 *
 * Revision 1.7  1996/10/02  10:24:21  ogawa
 * 極座標 地球儀座標系 追加
 *
 * Revision 1.6  1996/09/24  01:31:49  ogawa
 * バグ修正 （単位ベクトル）
 *
 * Revision 1.5  1996/09/21  13:17:15  ogawa
 * *** empty log message ***
 *
 * Revision 1.4  1996/09/21  07:56:44  ogawa
 * "types.h" をインクルード
 *
 * Revision 1.3  1996/09/21  07:30:11  ogawa
 * ２つのポジションから角度を求める関数追加
 *
 * Revision 1.2  1996/09/20  05:35:41  ogawa
 * RCSヘッダー作成
 *
 */

#ifndef __OLIB_H_
#define __OLIB_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "string.h"
#include "z_types.h"
#include "math64.h"		/* 浮動小数演算関係 */

/*###
 |##  メモリー操作
 |#
 */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
#define new(type)   (type *)malloc(sizeof(type))
#define delete(obj) free(obj)
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#define g_new(g, type)   (type *)zelda_malloc(sizeof(type))
#define g_new_allay(g, type, n)   (type *)zelda_malloc(sizeof(type) * (n))
#define g_delete(g, obj)  zelda_free(obj)

/*#define memset(a, b, c) Memset(a, b, c)*/

/*###
 |##  コントロール
 |#
 */

#define checkButton(btn)  (Key_T[0].button & (btn))

/*###
 |##  タイプ
 |#
 */

typedef struct rectangle_type_0 {
    int top, bottom, left, right;
} irect;

typedef short  sangle_t;

typedef struct r_and_two_sangle {
    float  r;
    sangle_t v;      /* vartical angle */
    sangle_t h;      /* horizontal angle */
} rsvsh_t;

typedef rsvsh_t  spolar_t;
typedef rsvsh_t  sglobe_t;

/*###
 |##  数学系
 |#
 */

#define fabs(ff)        fabsf(ff)
#define sabs(ss)        ((ss) >= 0 ? (ss) : -(ss))

#define ROOT2  (1.4142135f)
#define ROOT3  (1.7320508f)

#define SANGLE1D     (182.041667f)              /* =(65535 / 360) */
#define DIVSANGLE1D  (.00549325f)               /* =1 / (65535 / 360) */
#define degree2sangle(dd)  ((short)((dd) * SANGLE1D + 0.5f))
#define sangle2degree(ss)  ((float)(ss) * DIVSANGLE1D)
//#define degree2radian(dd)  ((dd) * F_PI / 180.0f)
#define degree2radian(dd)  DEG2RAD(dd)
//#define radian2degree(rr)  ((rr) * 180.0f / F_PI)
#define radian2degree(rr)  RAD2DEG(rr)
#define sangle2radian(ss)  degree2radian(sangle2degree(ss))
#define radian2sangle(rr)  degree2sangle(radian2degree(rr))

#define ssin(ss)  sin_s(ss)
#define scos(ss)  cos_s(ss)
/*#define ssin(ss)  sinf(sangle2radian(ss))*/
/*#define scos(ss)  cosf(sangle2radian(ss))*/

#define cos2sin(cc)  (sqrtf(1.0f - (cc) * (cc)))
/*###
 |##  関数宣言
 |#
 */
#ifdef __OLIB_C_
#define _GLOBAL
#else
#define _GLOBAL extern
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#define _GLOBAL
#endif
_GLOBAL float  distance_between(xyz_t *, xyz_t *);
_GLOBAL float  distance_between2(xyz_t *, xyz_t *, xyz_t *);
_GLOBAL float  distance_2d(xyz_t *, xyz_t *);
_GLOBAL float  never_zero(float, float);
_GLOBAL float  limiter(float, float);
_GLOBAL xyz_t  unitvector_by_2pos(xyz_t *, xyz_t *);
_GLOBAL xyz_t  spolar2world(spolar_t *);
_GLOBAL xyz_t  sglobe2world(sglobe_t *);
_GLOBAL spolar_t  world2spolar(xyz_t *);
_GLOBAL sglobe_t  world2sglobe(xyz_t *);
_GLOBAL spolar_t  spolar_by_2pos(xyz_t *, xyz_t *);
_GLOBAL sglobe_t  sglobe_by_2pos(xyz_t *, xyz_t *);
_GLOBAL xyz_t  radianxy_by_2pos(xyz_t *, xyz_t *);
_GLOBAL xyz_t  degreexy_by_2pos(xyz_t *, xyz_t *);
_GLOBAL s_xyz  sanglexy_by_2pos(xyz_t *, xyz_t *);
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#undef _GLOBAL

#define pr_sangle_t(aho)  PRINTF("%s(%d): sangle_t: %s %d (%f)\n", \
                          __FILE__, __LINE__, #aho, (short)(aho),     \
			  sangle2degree(aho)) 
#define pr_xyz_t(aho)     PRINTF("%s(%d): xyz_t: %s (%f %f %f)\n", \
                          __FILE__, __LINE__, #aho, (aho)->x,      \
		          (aho)->y, (aho)->z) 
#define pr_s_xyz(aho)     PRINTF("%s(%d): s_xyz: %s (%d %d %d)\n", \
                          __FILE__, __LINE__, #aho, (aho)->sx,      \
		          (aho)->sy, (aho)->sz) 
#define pr_sglobe_t(aho)  PRINTF("%s(%d): sglobe_t: %s (%f %f %f)\n", \
                          __FILE__, __LINE__, #aho, (aho)->r,         \
		          sangle2degree((aho)->v),sangle2degree((aho)->h)) 
#define pass()  PRINTF("-----  pass %d in %s\n", __LINE__, __FILE__)

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __OLIB_H_ */
