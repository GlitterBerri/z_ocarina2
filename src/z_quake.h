#ifndef __QUAKE_H_
#define __QUAKE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_olib.h"
#include "z_camera.h"

/*
-- quake object -- */
struct zelda_quake_struct;
typedef struct zelda_quake_struct   Quake;
struct zelda_quake_scale_struct;
typedef struct zelda_quake_scale_struct   QuakeScale;

/*
** algorithmn types */
enum quake_type {
    QUAKE_TYPE_DUMMY,
    QUAKE_TYPE_REGULAR,
    QUAKE_TYPE_RANDAM,
    QUAKE_TYPE_GODOWN,
    QUAKE_TYPE_RANDOWN,
    QUAKE_TYPE_SOFT,
    QUAKE_TYPE_ENDLESS,
    QUAKE_TYPE_MAX
};

struct zelda_quake_scale_struct {
    xyz_t           center, eye;
    short           supva, supho, sfovy;
    float           level;
};    

struct zelda_quake_struct {
    short           id;       /* randam value - seed */
    short           time;
    Camera          *camera;
    enum quake_type type;
    struct  {
	short       va;       /* vartical */
	short       ho;       /* holizontal */
	short       fo;       /* fovy */
	short       up;       /* up of lookat */
    }               scale;
    s_xyz           rotate;
    short           speed;    /* short angle - use sin curve */
    short           usecamang;
    short           count;
    short           cam_no;
};


/*
** parameter type */
#define QUAKE_PARAM_SPEED      (0x0001)
#define QUAKE_PARAM_VSCALE     (0x0002)
#define QUAKE_PARAM_HSCALE     (0x0004)
#define QUAKE_PARAM_FOVYSCALE  (0x0008)
#define QUAKE_PARAM_UPSCALE    (0x0010)
#define QUAKE_PARAM_ROTATEX    (0x0020)
#define QUAKE_PARAM_ROTATEY    (0x0040)
#define QUAKE_PARAM_ROTATEZ    (0x0080)
#define QUAKE_PARAM_TIME       (0x0100)
#define QUAKE_PARAM_CAMANGLE   (0x0200)

/*
** global routinedefinitions */
    
extern void   initQuakeControl(void);
extern short  startQuake(Camera *, enum quake_type);
extern short  stopQuake(short);
extern short  cameraQuakeControl(Camera *, QuakeScale *);
extern short  setQuake(short, short, short);
extern short  setSpeedQuake(short, short);
extern short  setTimerQuake(short, short);
extern short  getTimerQuake(short);
extern short  setScaleQuake(short, short, short, short, short);
extern short  setRotateQuake(short, short, s_xyz);


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __QUAKE_H_ **/

