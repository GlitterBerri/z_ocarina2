#ifndef __CAMDEMO_H__
#define __CAMDEMO_H__
#include "z_basic.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#define	CAMDEBUGSW	1	// 0: debug mode OFF

#define	ENDING_VER2	0

#define	CAMPERS		45.0f

#define	CAMPAD	0

#define SPNUM	32
#define CDNUM	10

#define	endWINDOW_CENTER	98
#define	endWINDOW_WIDTH	52.0f
#define	endWINDOW_FRAME	12.0f

#define	resWINDOW_CENTER	(SCREEN_HEIGHT/2)
#define	resWINDOW_WIDTH		(SCREEN_HEIGHT/2)
#define	resWINDOW_FRAME		12.0f

#define	_AX	0
#define	_AY	1
#define	_AZ	2
#define	_E	3
#define	_P	4

#define	CAM_DEMO_VIEWTEST	1
#define	CAM_DEMO_1st		2
#define	CAM_DEMO_2nd		3
#define	CAM_DEMO_3rd		4
#define	CAM_DEMO_4th		5
#define	CAM_DEMO_CREDITS	6

/*      credits color
	  0 : blue
	  1 : green
	  2 : red
	  3 : yellow
	  4 : cycle 1
	  5 : cycle 2
*/


#define	CAM_DEMO_TEST1		128+1
#define	CAM_DEMO_TEST2		128+2
#define	CAM_DEMO_TEST3		128+3
#define	CAM_DEMO_TEST4		128+4


#define	CAM_DEMO_SPTEST		128+5

#define	VE_BOMB	1

#define	ushort	unsigned short
#define	uchar	unsigned char

extern float sint(ushort);
extern float cost(ushort);
extern short atntable[1024];

/*                                  
	 Vector                           
*/                                  

typedef float FVector[3];	/* 3D float vector */
typedef short SVector[3];	/* 3D short vector */
typedef float qFVector[5];	/* 3D float vector */

/*                                  
// camera information record buffer 
*/

typedef struct {

	FVector	lookat;	  /* look at    */
	FVector	position; /* position   */
	float	z;	  /* rotation z */
	float	zoom;	  /* zoom angle */
	uchar	demomode; /* camera mode*/
	
} camDemoBuffer, *camDemoBufferPtr;

/*                     
// controller  
*/                     

typedef struct {

	ushort	trig;
	ushort	offtrig;
	ushort	hold;

	short	x;
	short	y;

} camcont, *camcontPtr;

/*                                  
// spline data                      
*/                                  

typedef struct	{
	signed char	code;	/* Code                    */
	signed char	z;	/* Rotation Z */
	ushort	T;	/* T no sokudo (0<Tvel<1.0)*/
	float	zoom;	/* zoom */
	SVector	pos;
	}SplinedatZ , *SplinedatPtrZ;

/*                                  
// demo sequence data               
*/                                  

typedef struct {
	void 	(*prog)(camDemoBufferPtr camera);
	short	time;
	} DemoData ;




/*                                  
// Data structure for Demo(work)    
*/                                  

typedef struct	{

	FVector		position;
	SVector		angle;

}Demodata;

/*                                  
// Data structure for credit spline    
*/                                  

typedef struct	{
	uchar	code;
	uchar	mapNo;
	SplinedatPtrZ P;
	SplinedatPtrZ L;
	ushort	time;
}creditsp;

/*                                  
// Controller                       
*/                                  

extern	void	DoDemoCamera(camDemoBufferPtr camera);
extern	void	Grou_camdemo_init(void);

extern	void	camdemodraw(void);

extern	creditsp	credittab[];

extern	DemoData DemoHonor[];

extern int	DoDemoRou(void (*prog)(camDemoBufferPtr camera) ,camDemoBufferPtr camera,short StartTime ,short EndTime);

extern int Grou_Dospline(FVector pos,float *z,float *zoom,SplinedatPtrZ ptr,short *pointer,float *T);

extern void	Initspline(void);

extern	short	DemoCameraCounter;	/* Demo no counter */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __CAMDEMO_H__ */
