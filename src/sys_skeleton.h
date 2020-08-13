/* $Id: sys_skeleton.h,v 2.1 1998/10/22 11:41:56 zelda Exp $ */	
/* $Log: sys_skeleton.h,v $
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.6  1996/11/13 04:34:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1996/11/13  04:30:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1996/10/18  08:15:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.3  1996/10/18  08:13:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1996/09/18  09:01:07  iwawaki
 * $Log追加
 * */

#ifndef INCLUDE_SYS_SKEKETON_H
#define INCLUDE_SYS_SKELETON_H

typedef struct SKELETON {
    Gfx		*shape;		/* pointer to the shape structure */
    float	ofsx;		/* offset x from the parent skeleton */
    float	ofsy;		/* offset y from the parent skeleton */
    float	ofsz;		/* offset z from the parent skeleton */
    short	angx;		/* angle X */
    short	angy;		/* angle Y */ 
    short	angz;		/* angle Z */ 
    struct SKELETON	*brother;   /* pointer to the brother skeleton */
    struct SKELETON	*child;	    /* pointer to the child skeleton */
} SkeletonRecord, *SkeletonPtr;

typedef struct SKELETONLOD2 {
    Gfx		*shape[2];	/* pointer to the shape structure */
    float	ofsx;		/* offset x from the parent skeleton */
    float	ofsy;		/* offset y from the parent skeleton */
    float	ofsz;		/* offset z from the parent skeleton */
    short	angx;		/* angle X */
    short	angy;		/* angle Y */ 
    short	angz;		/* angle Z */ 
    struct SKELETONLOD2	*brother;   /* pointer to the brother skeleton */
    struct SKELETONLOD2	*child;	    /* pointer to the child skeleton */
} SkeletonLod2Record, *SkeletonLod2Ptr;

typedef struct {
    SkeletonPtr	*slist;
}ObjectRecord, *ObjectPtr;

typedef struct{
    short frame;
    short joint;
    short *anime_param;
    short *anime_table;
}AnimeRecord;

#endif

/*** sys_skeleton.h end ***/
