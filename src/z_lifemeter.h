/************************************************************************
 *
 * $Id: z_lifemeter.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 ************************************************************************/

#ifndef INCLUDE_Z_LIFEMETER_H
#define INCLUDE_Z_LIFEMETER_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


/*----------------------------------------------------------------------*/
/*	インクルードファイル						*/
/*----------------------------------------------------------------------*/
#include "z_play.h"
#include "z_save_area_h.h"

/*----------------------------------------------------------------------*/
/*	マクロ								*/
/*----------------------------------------------------------------------*/
enum {
    LIFE_MD_NORMAL, LIFE_MD_WATER, LIFE_MD_FIAR, LIFE_MD_MAX
};

enum {
    LIFE_BASE_FRAME = 10,
    LIFE_BASE_ZOOM_FRAME = LIFE_BASE_FRAME,
    LIFE_TIME0 = 20*LIFE_CT		/* ライフを減らすときの時間【１６秒】 */
};

enum {
    LIFE_MARK_SIZE = 16,
    LIFE_MARK_SIZE_R = LIFE_MARK_SIZE / 2,
    LIFE_MARK_STEP = 10,
    LIFE_MARK_XPOS = 22 + LIFE_MARK_SIZE_R,
    LIFE_MARK_YPOS = 18 + LIFE_MARK_SIZE_R
};

enum {
    LIFE_BASE_pR  = 255,
    LIFE_BASE_pG  =  70,
    LIFE_BASE_pB  =  50,
    LIFE_BASE_eR  =  50,
    LIFE_BASE_eG  =  40,
    LIFE_BASE_eB  =  60,
    LIFE_BASE_WpR = 100,
    LIFE_BASE_WpG = 100,
    LIFE_BASE_WpB = 255,
    LIFE_BASE_WeR =   0,
    LIFE_BASE_WeG =   0,
    LIFE_BASE_WeB = 255,
    LIFE_BASE_FpR = 255,
    LIFE_BASE_FpG = 190,
    LIFE_BASE_FpB =   0,
    LIFE_BASE_FeR = 255,
    LIFE_BASE_FeG =   0,
    LIFE_BASE_FeB =   0,
#if 0
    LIFE2_BASE_pR = 200,
    LIFE2_BASE_pG =   0,
    LIFE2_BASE_pB =   0,
    LIFE2_BASE_eR = 255,
    LIFE2_BASE_eG = 255,
    LIFE2_BASE_eB = 255
#else
    LIFE2_BASE_pR = 255,
    LIFE2_BASE_pG = 255,
    LIFE2_BASE_pB = 255,
    LIFE2_BASE_eR = 200,
    LIFE2_BASE_eG =   0,
    LIFE2_BASE_eB =   0
#endif
};

#define	LIFE_ZOOM_POINT			( 0.68f )
#define	LIFE_ZOOM_POINT_MAX_STEP	( 1.0f - LIFE_ZOOM_POINT )
#define	LIFE_ZOOM_POINT_MAX_STEP2	( 1.0f / LIFE_ZOOM_POINT - 1.0f )
#define	LIFE_MARK_BASE_X		( ( -130.0f ) - ( float )LIFE_MARK_XPOS )
#define	LIFE_MARK_BASE_Y		( 94.5f - ( float )LIFE_MARK_YPOS )


#define	LIFE_PRIM_WR_MAXSTEP		( LIFE_BASE_WpR - LIFE_BASE_pR )
#define	LIFE_PRIM_WG_MAXSTEP		( LIFE_BASE_WpG - LIFE_BASE_pG )
#define	LIFE_PRIM_WB_MAXSTEP		( LIFE_BASE_WpB - LIFE_BASE_pB )
#define	LIFE_ENV_WR_MAXSTEP		( LIFE_BASE_WeR - LIFE_BASE_eR )
#define	LIFE_ENV_WG_MAXSTEP		( LIFE_BASE_WeG - LIFE_BASE_eG )
#define	LIFE_ENV_WB_MAXSTEP		( LIFE_BASE_WeB - LIFE_BASE_eB )
#define	LIFE_PRIM_FR_MAXSTEP		( LIFE_BASE_FpR - LIFE_BASE_pR )
#define	LIFE_PRIM_FG_MAXSTEP		( LIFE_BASE_FpG - LIFE_BASE_pG )
#define	LIFE_PRIM_FB_MAXSTEP		( LIFE_BASE_FpB - LIFE_BASE_pB )
#define	LIFE_ENV_FR_MAXSTEP		( LIFE_BASE_FeR - LIFE_BASE_eR )
#define	LIFE_ENV_FG_MAXSTEP		( LIFE_BASE_FeG - LIFE_BASE_eG )
#define	LIFE_ENV_FB_MAXSTEP		( LIFE_BASE_FeB - LIFE_BASE_eB )

#define	LIFE2_PRIM_WR_MAXSTEP		( LIFE_BASE_WpR - LIFE2_BASE_pR )
#define	LIFE2_PRIM_WG_MAXSTEP		( LIFE_BASE_WpG - LIFE2_BASE_pG )
#define	LIFE2_PRIM_WB_MAXSTEP		( LIFE_BASE_WpB - LIFE2_BASE_pB )
#define	LIFE2_ENV_WR_MAXSTEP		( LIFE_BASE_WeR - LIFE2_BASE_eR )
#define	LIFE2_ENV_WG_MAXSTEP		( LIFE_BASE_WeG - LIFE2_BASE_eG )
#define	LIFE2_ENV_WB_MAXSTEP		( LIFE_BASE_WeB - LIFE2_BASE_eB )
#define	LIFE2_PRIM_FR_MAXSTEP		( LIFE_BASE_FpR - LIFE2_BASE_pR )
#define	LIFE2_PRIM_FG_MAXSTEP		( LIFE_BASE_FpG - LIFE2_BASE_pG )
#define	LIFE2_PRIM_FB_MAXSTEP		( LIFE_BASE_FpB - LIFE2_BASE_pB )
#define	LIFE2_ENV_FR_MAXSTEP		( LIFE_BASE_FeR - LIFE2_BASE_eR )
#define	LIFE2_ENV_FG_MAXSTEP		( LIFE_BASE_FeG - LIFE2_BASE_eG )
#define	LIFE2_ENV_FB_MAXSTEP		( LIFE_BASE_FeB - LIFE2_BASE_eB )

#define	LIFE_MT_COL_RATE(p)		( (p).dokidoki_meter )
#define	LIFE_MT_COL_MODE(p)		( (p).now_mode )
#define	LIFE_MT_pRR(p)			( (p).dokidoki_prim[0] )
#define	LIFE_MT_pGG(p)			( (p).dokidoki_prim[1] )
#define	LIFE_MT_pBB(p)			( (p).dokidoki_prim[2] )
#define	LIFE_MT_eRR(p)			( (p).dokidoki_env[0] )
#define	LIFE_MT_eGG(p)			( (p).dokidoki_env[1] )
#define	LIFE_MT_eBB(p)			( (p).dokidoki_env[2] )

#define	Set_LIFE_MT_PRIM_R(p,f,d)	( (p).doki_prim_r[ (f) ] = (d) )
#define	Set_LIFE_MT_PRIM_G(p,f,d)	( (p).doki_prim_g[ (f) ] = (d) )
#define	Set_LIFE_MT_PRIM_B(p,f,d)	( (p).doki_prim_b[ (f) ] = (d) )
#define	Set_LIFE_MT_ENV_R(p,f,d)	( (p).doki_env_r[ (f) ] = (d) )
#define	Set_LIFE_MT_ENV_G(p,f,d)	( (p).doki_env_g[ (f) ] = (d) )
#define	Set_LIFE_MT_ENV_B(p,f,d)	( (p).doki_env_b[ (f) ] = (d) )
#define	Get_LIFE_MT_PRIM_R(p,f)		( (p).doki_prim_r[ (f) ] )
#define	Get_LIFE_MT_PRIM_G(p,f)		( (p).doki_prim_g[ (f) ] )
#define	Get_LIFE_MT_PRIM_B(p,f)		( (p).doki_prim_b[ (f) ] )
#define	Get_LIFE_MT_ENV_R(p,f)		( (p).doki_env_r[ (f) ] )
#define	Get_LIFE_MT_ENV_G(p,f)		( (p).doki_env_g[ (f) ] )
#define	Get_LIFE_MT_ENV_B(p,f)		( (p).doki_env_b[ (f) ] )

#define	LIFE_MT_RESTLIFE(p)		( (p).dokidoki_max )
#define	LIFE_MT_RESTTIME(p)		( (p).active_heart_timer )

#define	LIFE_MT_ZOOM_RATE(p)		( (p).dokidoki_wait )
#define	LIFE_MT_ZOOM_MODE(p)		( (p).dokidoki_flag )

/*----------------------------------------------------------------------*/
/*									*/
/*----------------------------------------------------------------------*/
extern void initial_LifeMeterColorAnimation( Game_play * );
extern void LifeMeterColorAnimation( Game_play * );
extern int initial_LifeRestChange_Damage( Game_play * );
extern int initial_LifeRestChange( Game_play * );
extern int LifeRestChange( Game_play * );
extern void DrawLifeMeter( Game_play * );
extern void LifeMeterZoom( Game_play * );
extern int Life_Caution_Check( void );



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif	/* INCLUDE_Z_LIFEMETER_H */
