/* $Id: camera.h,v 2.1 1998/10/22 11:41:56 zelda Exp $ */
/*
 * カメラクラス
 */

#ifndef __CAMERA_H_
#define __CAMERA_H_

#include "u64basic.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

typedef struct camera_s {
    xyz_t		eye;		/* 視点 */
    xyz_t		center;		/* 中心 */
    xyz_t		up;		/* 上方向 */
} camera_t;
typedef camera_t Camera;

void camera_init(Camera *);
void camera_set_camera(Camera *);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __CAMERA_H_ */
