/* $Id: z_bezier.h,v 2.1 1998/10/22 11:45:49 zelda Exp $
   $Log: z_bezier.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
   Revision 1.10  1998/04/06 04:22:29  ogawa
   *** empty log message ***

 * Revision 1.9  1998/04/06  04:18:54  ogawa
 * *** empty log message ***
 *
 * Revision 1.8  1998/03/19  10:32:09  sakakibara
 * *** empty log message ***
 * */
#ifndef __Z_BEZIER_H__
#define __Z_BEZIER_H__

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#define BEZIER_QUARITY   (8)     /* */
#define BEZIER_QMASK     (7)     /* BEZIER_QUARITY - 1 */
#define BEZIER_QSHIFT    (3)     /* BEZIER_QUARITYの２のｎ乗のｎ */
#define BEZIER_DIVIDE   (90)     /* (BEZIER_QUARITY + 1) x 3 以上 */

typedef struct zelda_bezier_curve_struct Bezier;

struct zelda_bezier_curve_struct {   
    xyz_t        *controls;                    /* 制御点の配列         */
    short        ncontrols;                    /* 制御点の数           */
    short        nsections;                    /* セクションの数       */
    xyz_t        *keyvec;
    float        *keyval;
    xyz_t        position;
    short        current;                      /* 今の場所             */
    short        section;                      /* 今のセクション       */
    short        direction;                    /* 今の向き             */
    s_xyz        angle;
    float        curr;
    Game         *game;
};

extern Bezier  *createBezier4AutoDemo(s_xyz *, short, short, Game *);
extern int     playAutoDemoBezier(Bezier *, short, xyz_t *);
extern Bezier  *createBezier4InteractiveRail(s_xyz *, short, short, Game *);
extern float   nearestPointOnBezier(Bezier *, xyz_t *, xyz_t *);
extern int     destroyBezier(Bezier *);
extern void    calcQuadraticBezier2D(xy_t pnt[3], float tc, xy_t *ret);
extern void    calcCublicBezier3D(xyz_t pnt[4], float tc, xyz_t *ret);

extern float   bz_curve(float, float);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
