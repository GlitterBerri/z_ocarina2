
/*====================================================================
 * os_thread.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_THREAD_H_
#define	_OS_THREAD_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef s32	OSPri;
typedef s32	OSId;
typedef union	{ struct { f32 f_odd; f32 f_even; } f; f64 d; }	__OSfp;

typedef struct {
	u64	at, v0, v1, a0, a1, a2, a3;
	u64	t0, t1, t2, t3, t4, t5, t6, t7;
	u64	s0, s1, s2, s3, s4, s5, s6, s7;
	u64	t8, t9,         gp, sp, s8, ra;
	u64	lo, hi;
	u32	sr, pc, cause, badvaddr, rcp;
	u32	fpcsr;
	__OSfp	 fp0,  fp2,  fp4,  fp6,  fp8, fp10, fp12, fp14;
	__OSfp	fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;

typedef struct {
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;

typedef struct OSThread_s {
	struct OSThread_s	*next;		/* run/mesg queue link */
	OSPri			priority;	/* run/mesg queue priority */
	struct OSThread_s	**queue;	/* queue thread is on */
	struct OSThread_s	*tlnext;	/* all threads queue link */
	u16			state;		/* OS_STATE_* */
	u16			flags;		/* flags for rmon */
	OSId			id;		/* id for debugging */
	int			fp;		/* thread has used fp unit */
	__OSThreadprofile_s     *thprof;        /* workarea for thread profiler */
	__OSThreadContext	context;	/* register/interrupt mask */
} OSThread;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* Thread states */

#define OS_STATE_STOPPED	1
#define OS_STATE_RUNNABLE	2
#define OS_STATE_RUNNING	4
#define OS_STATE_WAITING	8

/* Recommended thread priorities for the system threads */

#define OS_PRIORITY_MAX		255
#define OS_PRIORITY_VIMGR	254
#define OS_PRIORITY_RMON	250
#define OS_PRIORITY_RMONSPIN	200
#define OS_PRIORITY_PIMGR	150
#define OS_PRIORITY_SIMGR	140
#define	OS_PRIORITY_APPMAX	127
#define OS_PRIORITY_IDLE	  0	/* Must be 0 */

/* for thread profiler */
#define THPROF_IDMAX            64
#define THPROF_STACKSIZE        256

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Thread operations */

extern void		osCreateThread(OSThread *, OSId, void (*)(void *),
				       void *, void *, OSPri);
extern void		osDestroyThread(OSThread *);
extern void		osYieldThread(void);
extern void		osStartThread(OSThread *);
extern void		osStopThread(OSThread *);
extern OSId		osGetThreadId(OSThread *);
extern void		osSetThreadPri(OSThread *, OSPri);
extern OSPri		osGetThreadPri(OSThread *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_THREAD_H_ */

/*====================================================================
 * os_message.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_MESSAGE_H_
#define	_OS_MESSAGE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef u32 OSEvent;

/*
 * Structure for message
 */
typedef void *	OSMesg;

/*
 * Structure for message queue
 */
typedef struct OSMesgQueue_s {
	OSThread	*mtqueue;	/* Queue to store threads blocked
					   on empty mailboxes (receive) */
	OSThread	*fullqueue;	/* Queue to store threads blocked
					   on full mailboxes (send) */
	s32		validCount;	/* Contains number of valid message */
	s32		first;		/* Points to first valid message */
	s32		msgCount;	/* Contains total # of messages */
	OSMesg		*msg;		/* Points to message buffer array */
} OSMesgQueue;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* Events */
#ifdef _FINALROM
#define OS_NUM_EVENTS           15
#else
#define OS_NUM_EVENTS           23
#endif

#define OS_EVENT_SW1              0     /* CPU SW1 interrupt */
#define OS_EVENT_SW2              1     /* CPU SW2 interrupt */
#define OS_EVENT_CART             2     /* Cartridge interrupt: used by rmon */
#define OS_EVENT_COUNTER          3     /* Counter int: used by VI/Timer Mgr */
#define OS_EVENT_SP               4     /* SP task done interrupt */
#define OS_EVENT_SI               5     /* SI (controller) interrupt */
#define OS_EVENT_AI               6     /* AI interrupt */
#define OS_EVENT_VI               7     /* VI interrupt: used by VI/Timer Mgr */
#define OS_EVENT_PI               8     /* PI interrupt: used by PI Manager */
#define OS_EVENT_DP               9     /* DP full sync interrupt */
#define OS_EVENT_CPU_BREAK        10    /* CPU breakpoint: used by rmon */
#define OS_EVENT_SP_BREAK         11    /* SP breakpoint:  used by rmon */
#define OS_EVENT_FAULT            12    /* CPU fault event: used by rmon */
#define OS_EVENT_THREADSTATUS     13    /* CPU thread status: used by rmon */
#define OS_EVENT_PRENMI           14    /* Pre NMI interrupt */
#ifndef _FINALROM
#define OS_EVENT_RDB_READ_DONE    15    /* RDB read ok event: used by rmon */
#define OS_EVENT_RDB_LOG_DONE     16    /* read of log data complete */
#define OS_EVENT_RDB_DATA_DONE    17    /* read of hostio data complete */
#define OS_EVENT_RDB_REQ_RAMROM   18    /* host needs ramrom access */
#define OS_EVENT_RDB_FREE_RAMROM  19    /* host is done with ramrom access */
#define OS_EVENT_RDB_DBG_DONE     20
#define OS_EVENT_RDB_FLUSH_PROF   21
#define OS_EVENT_RDB_ACK_PROF     22
#endif

/* Flags to turn blocking on/off when sending/receiving message */

#define	OS_MESG_NOBLOCK		0
#define	OS_MESG_BLOCK		1


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */

/* Get count of valid messages in queue */
#define MQ_GET_COUNT(mq)        ((mq)->validCount)

/* Figure out if message queue is empty or full */
#define MQ_IS_EMPTY(mq)		(MQ_GET_COUNT(mq) == 0)
#define MQ_IS_FULL(mq)		(MQ_GET_COUNT(mq) >= (mq)->msgCount)


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Message operations */

extern void		osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern s32		osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32		osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32		osRecvMesg(OSMesgQueue *, OSMesg *, s32);

/* Event operations */

extern void		osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_MESSAGE_H_ */

/*====================================================================
 * os_exception.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_EXCEPTION_H_
#define	_OS_EXCEPTION_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef u32 OSIntMask;
typedef u32 OSHWIntr;

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* Flags for debugging purpose */

#define	OS_FLAG_CPU_BREAK	1	/* Break exception has occurred */
#define	OS_FLAG_FAULT		2	/* CPU fault has occurred */

/* Interrupt masks */

#define	OS_IM_NONE	0x00000001
#define	OS_IM_SW1	0x00000501
#define	OS_IM_SW2	0x00000601
#define	OS_IM_CART	0x00000c01
#define	OS_IM_PRENMI	0x00001401
#define OS_IM_RDBWRITE	0x00002401
#define OS_IM_RDBREAD	0x00004401
#define	OS_IM_COUNTER	0x00008401
#define	OS_IM_CPU	0x0000ff01
#define	OS_IM_SP	0x00010401
#define	OS_IM_SI	0x00020401
#define	OS_IM_AI	0x00040401
#define	OS_IM_VI	0x00080401
#define	OS_IM_PI	0x00100401
#define	OS_IM_DP	0x00200401
#define	OS_IM_ALL	0x003fff01
#define	RCP_IMASK	0x003f0000
#define	RCP_IMASKSHIFT	16


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Interrupt operations */

extern OSIntMask	osGetIntMask(void);
extern OSIntMask	osSetIntMask(OSIntMask);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_EXCEPTION_H_ */

/*====================================================================
 * os_tlb.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_TLB_H_
#define	_OS_TLB_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef u32 OSPageMask;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Page size argument for TLB routines
 */
#define OS_PM_4K	0x0000000
#define OS_PM_16K	0x0006000
#define OS_PM_64K	0x001e000
#define OS_PM_256K	0x007e000
#define OS_PM_1M	0x01fe000
#define OS_PM_4M	0x07fe000
#define OS_PM_16M	0x1ffe000


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* TLB management routines */

extern void		osMapTLB(s32, OSPageMask, void *, u32, u32, s32);
extern void		osMapTLBRdb(void);
extern void		osUnmapTLB(s32);
extern void		osUnmapTLBAll(void);
extern void		osSetTLBASID(s32);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_TLB_H_ */

/*====================================================================
 * os_pi.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_PI_H_
#define	_OS_PI_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_thread.h"
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for Enhanced PI interface
 */

/*
 * OSTranxInfo is set up for Leo Disk DMA. This info will be maintained
 * by exception handler. This is how the PIMGR and the ISR communicate.
 */

typedef struct {
	u32		errStatus;	/* error status */
        void     	*dramAddr;      /* RDRAM buffer address (DMA) */
	void		*C2Addr;	/* C2 buffer address */
	u32		sectorSize;	/* size of transfering sector */
	u32		C1ErrNum;	/* total # of C1 errors */
	u32		C1ErrSector[4];	/* error sectors */
} __OSBlockInfo;

typedef struct {
	u32     	cmdType;       	/* for disk only */
	u16     	transferMode;   /* Block, Track, or sector?   */
	u16		blockNum;	/* which block is transfering */
	s32     	sectorNum;      /* which sector is transfering */
	u32     	devAddr;        /* Device buffer address */
	u32		bmCtlShadow;	/* asic bm_ctl(510) register shadow ram */
	u32		seqCtlShadow;	/* asic seq_ctl(518) register shadow ram */
	__OSBlockInfo	block[2];	/* bolck transfer info */
} __OSTranxInfo;


typedef struct OSPiHandle_s {
        struct OSPiHandle_s     *next;  /* point to next handle on the table */
        u8                      type;   /* DEVICE_TYPE_BULK for disk */
        u8                      latency;        /* domain latency */
        u8                      pageSize;       /* domain page size */
        u8                      relDuration;    /* domain release duration */
        u8                      pulse;          /* domain pulse width */
	u8			domain;		/* which domain */
        u32                     baseAddress;    /* Domain address */
        u32                     speed;          /* for roms only */
        /* The following are "private" elements" */
        __OSTranxInfo           transferInfo;	/* for disk only */
} OSPiHandle;

typedef struct {
        u8      type;
        u32     address;
} OSPiInfo;

/*
 * Structure for I/O message block
 */
typedef struct {
        u16 		type;		/* Message type */
        u8 		pri;		/* Message priority (High or Normal) */
        u8		status;		/* Return status */
	OSMesgQueue	*retQueue;	/* Return message queue to notify I/O 
					 * completion */
} OSIoMesgHdr;

typedef struct {
	OSIoMesgHdr	hdr;		/* Message header */
	void *		dramAddr;	/* RDRAM buffer address (DMA) */
	u32		devAddr;	/* Device buffer address (DMA) */
	u32 		size;		/* DMA transfer size in bytes */
	OSPiHandle	*piHandle;	/* PI device handle */
} OSIoMesg;

/*
 * Structure for device manager block
 */
typedef struct {
        s32             active;		/* Status flag */
	OSThread	*thread;	/* Calling thread */
        OSMesgQueue  	*cmdQueue;	/* Command queue */
        OSMesgQueue  	*evtQueue;	/* Event queue */
        OSMesgQueue  	*acsQueue;	/* Access queue */
					/* Raw DMA routine */
        s32             (*dma)(s32, u32, void *, u32);
        s32             (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* Flags to indicate direction of data transfer */

#define	OS_READ			0		/* device -> RDRAM */
#define	OS_WRITE		1		/* device <- RDRAM */
#define	OS_OTHERS		2		/* for Leo disk only */

/*
 * I/O message types
 */
#define OS_MESG_TYPE_BASE	(10)
#define OS_MESG_TYPE_LOOPBACK	(OS_MESG_TYPE_BASE+0)
#define OS_MESG_TYPE_DMAREAD	(OS_MESG_TYPE_BASE+1)
#define OS_MESG_TYPE_DMAWRITE	(OS_MESG_TYPE_BASE+2)
#define OS_MESG_TYPE_VRETRACE	(OS_MESG_TYPE_BASE+3)
#define OS_MESG_TYPE_COUNTER	(OS_MESG_TYPE_BASE+4)
#define OS_MESG_TYPE_EDMAREAD	(OS_MESG_TYPE_BASE+5)
#define OS_MESG_TYPE_EDMAWRITE	(OS_MESG_TYPE_BASE+6)

/*
 * I/O message priority
 */
#define OS_MESG_PRI_NORMAL	0
#define OS_MESG_PRI_HIGH	1

/*
 * PI/EPI
 */
#define PI_DOMAIN1      0
#define PI_DOMAIN2      1


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */

extern OSPiHandle      *__osPiTable;    /* The head of OSPiHandle link list */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Peripheral interface (Pi) */
extern u32 		osPiGetStatus(void);
extern s32		osPiGetDeviceType(void);
extern s32		osPiWriteIo(u32, u32);
extern s32		osPiReadIo(u32, u32 *);
extern s32		osPiStartDma(OSIoMesg *, s32, s32, u32, void *, u32,
				     OSMesgQueue *);
extern void		osCreatePiManager(OSPri, OSMesgQueue *, OSMesg *, s32);

/* Enhanced PI interface */

extern OSPiHandle *osCartRomInit(void);
extern OSPiHandle *osLeoDiskInit(void);
extern OSPiHandle *osDriveRomInit(void);

extern s32 osEPiDeviceType(OSPiHandle *, OSPiInfo *);
extern s32 osEPiWriteIo(OSPiHandle *, u32 , u32 );
extern s32 osEPiReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32);
extern s32 osEPiLinkHandle(OSPiHandle *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_PI_H_ */

/*====================================================================
 * os_vi.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_VI_H_
#define	_OS_VI_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_thread.h"
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure to store VI register values that remain the same between 2 fields
 */
typedef struct {
    u32	ctrl;
    u32	width;
    u32	burst;
    u32	vSync;
    u32	hSync;
    u32	leap;
    u32	hStart;
    u32	xScale;
    u32	vCurrent;
} OSViCommonRegs;


/*
 * Structure to store VI register values that change between fields
 */
typedef struct {
    u32	origin;
    u32	yScale;
    u32	vStart;	
    u32	vBurst;
    u32	vIntr;
} OSViFieldRegs;


/*
 * Structure for VI mode
 */
typedef struct {
    u8			type;		/* Mode type */
    OSViCommonRegs	comRegs;	/* Common registers for both fields */
    OSViFieldRegs	fldRegs[2];	/* Registers for Field 1  & 2 */
} OSViMode;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Video Interface (VI) mode type
 */
#define OS_VI_NTSC_LPN1		0	/* NTSC */
#define OS_VI_NTSC_LPF1		1
#define OS_VI_NTSC_LAN1		2
#define OS_VI_NTSC_LAF1		3
#define OS_VI_NTSC_LPN2		4
#define OS_VI_NTSC_LPF2		5
#define OS_VI_NTSC_LAN2		6
#define OS_VI_NTSC_LAF2		7
#define OS_VI_NTSC_HPN1		8
#define OS_VI_NTSC_HPF1		9
#define OS_VI_NTSC_HAN1		10
#define OS_VI_NTSC_HAF1		11
#define OS_VI_NTSC_HPN2		12
#define OS_VI_NTSC_HPF2		13

#define OS_VI_PAL_LPN1		14	/* PAL */
#define OS_VI_PAL_LPF1		15
#define OS_VI_PAL_LAN1		16
#define OS_VI_PAL_LAF1		17
#define OS_VI_PAL_LPN2		18
#define OS_VI_PAL_LPF2		19
#define OS_VI_PAL_LAN2		20
#define OS_VI_PAL_LAF2		21
#define OS_VI_PAL_HPN1		22
#define OS_VI_PAL_HPF1		23
#define OS_VI_PAL_HAN1		24
#define OS_VI_PAL_HAF1		25
#define OS_VI_PAL_HPN2		26
#define OS_VI_PAL_HPF2		27

#define OS_VI_MPAL_LPN1		28	/* MPAL - mainly Brazil */
#define OS_VI_MPAL_LPF1		29
#define OS_VI_MPAL_LAN1		30
#define OS_VI_MPAL_LAF1		31
#define OS_VI_MPAL_LPN2		32
#define OS_VI_MPAL_LPF2		33
#define OS_VI_MPAL_LAN2		34
#define OS_VI_MPAL_LAF2		35
#define OS_VI_MPAL_HPN1		36
#define OS_VI_MPAL_HPF1		37
#define OS_VI_MPAL_HAN1		38
#define OS_VI_MPAL_HAF1		39
#define OS_VI_MPAL_HPN2		40
#define OS_VI_MPAL_HPF2		41

#define OS_VI_FPAL_LPN1         42      /* FPAL - Full screen PAL */
#define OS_VI_FPAL_LPF1         43
#define OS_VI_FPAL_LAN1         44
#define OS_VI_FPAL_LAF1         45
#define OS_VI_FPAL_LPN2         46
#define OS_VI_FPAL_LPF2         47
#define OS_VI_FPAL_LAN2         48
#define OS_VI_FPAL_LAF2         49
#define OS_VI_FPAL_HPN1         50
#define OS_VI_FPAL_HPF1         51
#define OS_VI_FPAL_HAN1         52
#define OS_VI_FPAL_HAF1         53
#define OS_VI_FPAL_HPN2         54
#define OS_VI_FPAL_HPF2         55

/*
 * Video Interface (VI) special features
 */
#define	OS_VI_GAMMA_ON			0x0001
#define	OS_VI_GAMMA_OFF			0x0002
#define	OS_VI_GAMMA_DITHER_ON		0x0004
#define	OS_VI_GAMMA_DITHER_OFF		0x0008
#define	OS_VI_DIVOT_ON			0x0010
#define	OS_VI_DIVOT_OFF			0x0020
#define	OS_VI_DITHER_FILTER_ON		0x0040
#define	OS_VI_DITHER_FILTER_OFF		0x0080

/*
 * Video Interface (VI) mode attribute bit
 */
#define OS_VI_BIT_NONINTERLACE		0x0001          /* lo-res */
#define OS_VI_BIT_INTERLACE		0x0002          /* lo-res */
#define OS_VI_BIT_NORMALINTERLACE	0x0004          /* hi-res */
#define OS_VI_BIT_DEFLICKINTERLACE	0x0008          /* hi-res */
#define OS_VI_BIT_ANTIALIAS		0x0010
#define OS_VI_BIT_POINTSAMPLE		0x0020
#define OS_VI_BIT_16PIXEL		0x0040
#define OS_VI_BIT_32PIXEL		0x0080
#define OS_VI_BIT_LORES			0x0100
#define OS_VI_BIT_HIRES			0x0200
#define OS_VI_BIT_NTSC			0x0400
#define OS_VI_BIT_PAL			0x0800


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */

extern OSViMode	osViModeTable[];	/* Global VI mode table */

extern OSViMode	osViModeNtscLpn1;	/* Individual VI NTSC modes */
extern OSViMode	osViModeNtscLpf1;
extern OSViMode	osViModeNtscLan1;
extern OSViMode	osViModeNtscLaf1;
extern OSViMode	osViModeNtscLpn2;
extern OSViMode	osViModeNtscLpf2;
extern OSViMode	osViModeNtscLan2;
extern OSViMode	osViModeNtscLaf2;
extern OSViMode	osViModeNtscHpn1;
extern OSViMode	osViModeNtscHpf1;
extern OSViMode	osViModeNtscHan1;
extern OSViMode	osViModeNtscHaf1;
extern OSViMode	osViModeNtscHpn2;
extern OSViMode	osViModeNtscHpf2;

extern OSViMode	osViModePalLpn1;	/* Individual VI PAL modes */
extern OSViMode	osViModePalLpf1;
extern OSViMode	osViModePalLan1;
extern OSViMode	osViModePalLaf1;
extern OSViMode	osViModePalLpn2;
extern OSViMode	osViModePalLpf2;
extern OSViMode	osViModePalLan2;
extern OSViMode	osViModePalLaf2;
extern OSViMode	osViModePalHpn1;
extern OSViMode	osViModePalHpf1;
extern OSViMode	osViModePalHan1;
extern OSViMode	osViModePalHaf1;
extern OSViMode	osViModePalHpn2;
extern OSViMode	osViModePalHpf2;

extern OSViMode	osViModeMpalLpn1;	/* Individual VI MPAL modes */
extern OSViMode	osViModeMpalLpf1;
extern OSViMode	osViModeMpalLan1;
extern OSViMode	osViModeMpalLaf1;
extern OSViMode	osViModeMpalLpn2;
extern OSViMode	osViModeMpalLpf2;
extern OSViMode	osViModeMpalLan2;
extern OSViMode	osViModeMpalLaf2;
extern OSViMode	osViModeMpalHpn1;
extern OSViMode	osViModeMpalHpf1;
extern OSViMode	osViModeMpalHan1;
extern OSViMode	osViModeMpalHaf1;
extern OSViMode	osViModeMpalHpn2;
extern OSViMode	osViModeMpalHpf2;

extern OSViMode osViModeFpalLpn1;       /* Individual VI FPAL modes */
extern OSViMode osViModeFpalLpf1;
extern OSViMode osViModeFpalLan1;
extern OSViMode osViModeFpalLaf1;
extern OSViMode osViModeFpalLpn2;
extern OSViMode osViModeFpalLpf2;
extern OSViMode osViModeFpalLan2;
extern OSViMode osViModeFpalLaf2;
extern OSViMode osViModeFpalHpn1;
extern OSViMode osViModeFpalHpf1;
extern OSViMode osViModeFpalHan1;
extern OSViMode osViModeFpalHaf1;
extern OSViMode osViModeFpalHpn2;
extern OSViMode osViModeFpalHpf2;


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Video interface (Vi) */
extern u32		osViGetStatus(void);
extern u32		osViGetCurrentMode(void);
extern u32		osViGetCurrentLine(void);
extern u32		osViGetCurrentField(void);
extern void		*osViGetCurrentFramebuffer(void);
extern void		*osViGetNextFramebuffer(void);
extern void		osViSetXScale(f32);
extern void		osViSetYScale(f32);
extern void		osViExtendVStart(u32);
extern void		osViSetSpecialFeatures(u32);
extern void		osViSetMode(OSViMode *);
extern void		osViSetEvent(OSMesgQueue *, OSMesg, u32);
extern void		osViSwapBuffer(void *);
extern void		osViBlack(u8);
extern void		osViFade(u8, u16);
extern void		osViRepeatLine(u8);
extern void		osCreateViManager(OSPri);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_VI_H_ */

/*====================================================================
 * os_ai.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_AI_H_
#define	_OS_AI_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Audio interface (Ai) */
extern u32 		osAiGetStatus(void);
extern u32 		osAiGetLength(void);
extern s32		osAiSetFrequency(u32);
extern s32		osAiSetNextBuffer(void *, u32);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_AI_H_ */

/*====================================================================
 * os_si.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_SI_H_
#define	_OS_SI_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_SI_H_ */

/*====================================================================
 * os_time.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_TIME_H_
#define	_OS_TIME_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for time value 
 */
typedef u64	OSTime;

/*
 * Structure for interval timer
 */
typedef struct OSTimer_s {
	struct OSTimer_s	*next;	/* point to next timer in list */
	struct OSTimer_s	*prev;	/* point to previous timer in list */
	OSTime			interval;	/* duration set by user */
	OSTime			value;		/* time remaining before */
						/* timer fires           */
	OSMesgQueue		*mq;		/* Message Queue */
	OSMesg			msg;		/* Message to send */
} OSTimer;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Timer interface */

extern OSTime		osGetTime(void);
extern void		osSetTime(OSTime);
extern int		osSetTimer(OSTimer *, OSTime, OSTime,
				   OSMesgQueue *, OSMesg);
extern int		osStopTimer(OSTimer *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_TIME_H_ */

/*====================================================================
 * os_cont.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_CONT_H_
#define	_OS_CONT_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for controllers 
 */

typedef struct {
	u16     type;                   /* Controller Type */
	u8      status;                 /* Controller status */
	u8	errno;
}OSContStatus;

typedef struct {
	u16     button;
	s8      stick_x;		/* -80 <= stick_x <= 80 */
	s8      stick_y;		/* -80 <= stick_y <= 80 */
	u8	errno;
} OSContPad;

typedef struct {
	void    *address;               /* Ram pad Address:  11 bits */
	u8      databuffer[32];         /* address of the data buffer */
        u8      addressCrc;             /* CRC code for address */
	u8      dataCrc;                /* CRC code for data */
	u8	errno;
} OSContRamIo;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 *  Controllers  number
 */

#ifndef _HW_VERSION_1
#define MAXCONTROLLERS  4
#else
#define MAXCONTROLLERS  6
#endif

/* controller errors */
#define CONT_NO_RESPONSE_ERROR          0x8
#define CONT_OVERRUN_ERROR              0x4
#ifdef _HW_VERSION_1
#define CONT_FRAME_ERROR                0x2
#define CONT_COLLISION_ERROR            0x1
#endif 

/* Controller type */

#define CONT_ABSOLUTE           0x0001
#define CONT_RELATIVE           0x0002
#define CONT_JOYPORT            0x0004
#define CONT_EEPROM		0x8000
#define CONT_EEP16K		0x4000
#define	CONT_TYPE_MASK		0x1f07
#define	CONT_TYPE_NORMAL	0x0005
#define	CONT_TYPE_MOUSE		0x0002
#define	CONT_TYPE_VOICE		0x0100

/* Controller status */

#define CONT_CARD_ON            0x01
#define CONT_CARD_PULL          0x02
#define CONT_ADDR_CRC_ER        0x04
#define CONT_EEPROM_BUSY	0x80

/* Buttons */

#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001

/* Nintendo's official button names */

#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D

/* Controller error number */

#define	CONT_ERR_NO_CONTROLLER		PFS_ERR_NOPACK 		/* 1 */
#define	CONT_ERR_CONTRFAIL		CONT_OVERRUN_ERROR	/* 4 */
#define	CONT_ERR_INVALID		PFS_ERR_INVALID		/* 5 */
#define	CONT_ERR_DEVICE			PFS_ERR_DEVICE 		/* 11 */
#define	CONT_ERR_NOT_READY		12
#define	CONT_ERR_VOICE_MEMORY		13
#define	CONT_ERR_VOICE_WORD		14
#define	CONT_ERR_VOICE_NO_RESPONSE	15


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Controller interface */

extern s32		osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32		osContReset(OSMesgQueue *, OSContStatus *);
extern s32		osContStartQuery(OSMesgQueue *);
extern s32		osContStartReadData(OSMesgQueue *);
#ifndef _HW_VERSION_1
extern s32		osContSetCh(u8);
#endif
extern void		osContGetQuery(OSContStatus *);
extern void		osContGetReadData(OSContPad *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_CONT_H_ */

/*====================================================================
 * os_pfs.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_PFS_H_
#define	_OS_PFS_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for file system
 */
typedef struct {
	int		status;
	OSMesgQueue 	*queue;
	int		channel;
	u8		id[32];
	u8		label[32];
	int		version;
	int		dir_size;
	int		inode_table;		/* block location */
	int		minode_table;		/* mirrioring inode_table */
	int		dir_table;		/* block location */
	int		inode_start_page;	/* page # */
	u8		banks;
	u8		activebank;
} OSPfs;

typedef struct {
	u32	file_size;	/* bytes */
  	u32 	game_code;
  	u16 	company_code;
  	char  	ext_name[4];
  	char 	game_name[16];
} OSPfsState;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* File System size */
#define	OS_PFS_VERSION		0x0200
#define	OS_PFS_VERSION_HI	(OS_PFS_VERSION >> 8)
#define	OS_PFS_VERSION_LO	(OS_PFS_VERSION & 255)

#define PFS_FILE_NAME_LEN       16
#define PFS_FILE_EXT_LEN        4
#define BLOCKSIZE		32		/* bytes */
#define PFS_ONE_PAGE            8		/* blocks */
#define PFS_MAX_BANKS		62

/* File System flag */

#define PFS_READ                0
#define PFS_WRITE               1
#define PFS_CREATE              2

/* File System status */
#define PFS_INITIALIZED		0x1
#define PFS_CORRUPTED		0x2		/* File system was corrupted */
#define PFS_ID_BROKEN		0x4
#define PFS_MOTOR_INITIALIZED	0x8
#define	PFS_GBPAK_INITIALIZED	0x10

/* File System error number */

#define PFS_ERR_NOPACK		1	/* no memory card is plugged or   */
#define PFS_ERR_NEW_PACK        2	/* ram pack has been changed to a */
					/* different one 		  */
#define PFS_ERR_INCONSISTENT    3	/* need to run Pfschecker 	  */
#define PFS_ERR_CONTRFAIL	CONT_OVERRUN_ERROR              
#define PFS_ERR_INVALID         5	/* invalid parameter or file not exist*/
#define PFS_ERR_BAD_DATA        6       /* the data read from pack are bad*/
#define PFS_DATA_FULL           7	/* no free pages on ram pack      */
#define PFS_DIR_FULL            8	/* no free directories on ram pack*/
#define PFS_ERR_EXIST		9	/* file exists 			  */
#define PFS_ERR_ID_FATAL	10	/* dead ram pack */
#define PFS_ERR_DEVICE		11	/* wrong device type*/
#define PFS_ERR_NO_GBCART	12 	/* no gb cartridge (64GB-PAK) */
#define PFS_ERR_NEW_GBCART	13 	/* gb cartridge may be changed */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* file system interface */

extern s32 osPfsInitPak(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsRepairId(OSPfs *);
extern s32 osPfsInit(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsReFormat(OSPfs *, OSMesgQueue *, int);
extern s32 osPfsChecker(OSPfs *);
extern s32 osPfsAllocateFile(OSPfs *, u16, u32, u8 *, u8 *, int, s32 *);
extern s32 osPfsFindFile(OSPfs *, u16, u32, u8 *, u8 *, s32 *);
extern s32 osPfsDeleteFile(OSPfs *, u16, u32, u8 *, u8 *);
extern s32 osPfsReadWriteFile(OSPfs *, s32, u8, int, int, u8 *);
extern s32 osPfsFileState(OSPfs *, s32, OSPfsState *);
extern s32 osPfsGetLabel(OSPfs *, u8 *, int *);
extern s32 osPfsSetLabel(OSPfs *, u8 *);
extern s32 osPfsIsPlug(OSMesgQueue *, u8 *);
extern s32 osPfsFreeBlocks(OSPfs *, s32 *);
extern s32 osPfsNumFiles(OSPfs *, s32 *, s32 *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_PFS_H_ */

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_GBPAK_H_
#define	_OS_GBPAK_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"
#include "os_pfs.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef struct {
  u16	fixed1;
  u16	start_address;
  u8	nintendo_chr[0x30];
  u8	game_title[16];
  u16	company_code;
  u8	body_code;
  u8	cart_type;
  u8	rom_size;
  u8	ram_size;
  u8	country_code;
  u8	fixed2;
  u8	version;
  u8	isum;
  u16	sum;
} OSGbpakId;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* definition for 64GB-PAK */

#define OS_GBPAK_POWER          0x01
#define OS_GBPAK_RSTB_DETECTION 0x04
#define OS_GBPAK_RSTB_STATUS    0x08
#define OS_GBPAK_GBCART_PULL    0x40
#define OS_GBPAK_GBCART_ON      0x80

#define	OS_GBPAK_POWER_OFF	0x00 	/* power of 64GB-PAK */
#define	OS_GBPAK_POWER_ON	0x01

#define	OS_GBPAK_ROM_ID_SIZE	0x50	/* ID size of GB cartridge */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* 64GB-PAK */
extern  s32     osGbpakInit(OSMesgQueue *, OSPfs *, int);
extern  s32     osGbpakPower(OSPfs *, s32);
extern  s32     osGbpakGetStatus(OSPfs *, u8 *);
extern  s32     osGbpakReadWrite(OSPfs *, u16, u16, u8 *, u16);
extern  s32     osGbpakReadId(OSPfs *, OSGbpakId *, u8 *);
extern  s32	osGbpakCheckConnector(OSPfs *, u8 *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_GBPAK_H_ */

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_VOICE_H_
#define	_OS_VOICE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

typedef struct {		/* Voice Recognition System */
  OSMesgQueue	*__mq;		/* SI Message Queue */
  int		__channel;	/* Controller Port # */
  s32		__mode;
  u8		cmd_status;	/* Command Status */
} OSVoiceHandle;

typedef struct {		/* Voice Recognition System */
  u16	warning;
  u16	answer_num;		/* 0...5 */
  u16	voice_level;
  u16	voice_sn;
  u16	voice_time;
  u16	answer[5];
  u16	distance[5];
} OSVoiceData;
	

#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* definition for Voice Recognition System */

#define	VOICE_WARN_TOO_SMALL	0x0400
#define	VOICE_WARN_TOO_LARGE	0x0800
#define	VOICE_WARN_NOT_FIT	0x4000
#define	VOICE_WARN_TOO_NOISY	0x8000

#define	VOICE_STATUS_READY	0
#define	VOICE_STATUS_START	1
#define	VOICE_STATUS_CANCEL	3
#define	VOICE_STATUS_BUSY	5
#define	VOICE_STATUS_END	7


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Voice Recognition System */
extern s32 osVoiceInit(OSMesgQueue *, OSVoiceHandle *, int);
extern s32 osVoiceCheckWord(u8 *data);
extern s32 osVoiceClearDictionary(OSVoiceHandle *, u8);
extern s32 osVoiceControlGain(OSVoiceHandle *, s32, s32);
extern s32 osVoiceSetWord(OSVoiceHandle *, u8 *);
extern s32 osVoiceStartReadData(OSVoiceHandle *);
extern s32 osVoiceStopReadData(OSVoiceHandle *);
extern s32 osVoiceGetReadData(OSVoiceHandle *, OSVoiceData *);
extern s32 osVoiceMaskDictionary(OSVoiceHandle *, u8 *, int);
extern void osVoiceCountSyllables(u8 *, u32 *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_VOICE_H_ */

/*====================================================================
 * os_cache.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_CACHE_H_
#define	_OS_CACHE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */

#define	OS_DCACHE_ROUNDUP_ADDR(x)	(void *)(((((u32)(x)+0xf)/0x10)*0x10))
#define	OS_DCACHE_ROUNDUP_SIZE(x)	(u32)(((((u32)(x)+0xf)/0x10)*0x10))


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Cache operations and macros */

extern void		osInvalDCache(void *, s32);
extern void		osInvalICache(void *, s32);
extern void		osWritebackDCache(void *, s32);
extern void		osWritebackDCacheAll(void);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_CACHE_H_ */

/*====================================================================
 * os_debug.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_DEBUG_H_
#define	_OS_DEBUG_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure for Profiler 
 */
typedef struct {
	u16	*histo_base;		/* histogram base */
	u32	histo_size;		/* histogram size */
	u32	*text_start;		/* start of text segment */
	u32	*text_end;		/* end of text segment */
} OSProf;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Profiler constants
 */
#define PROF_MIN_INTERVAL	50	/* microseconds */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Profiler Interface */

extern void		osProfileInit(OSProf *, u32 profcnt);
extern void		osProfileStart(u32);
extern void		osProfileFlush(void);
extern void		osProfileStop(void);

/* Thread Profiler Interface */
extern void             osThreadProfileClear(OSId);
extern void             osThreadProfileInit(void);
extern void             osThreadProfileStart(void);
extern void             osThreadProfileStop(void);
extern u32              osThreadProfileReadCount(OSId);
extern u32              osThreadProfileReadCountTh(OSThread*);
extern OSTime           osThreadProfileReadTime(OSId);
extern OSTime           osThreadProfileReadTimeTh(OSThread*);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_DEBUG_H_ */

/*====================================================================
 * os_error.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_ERROR_H_
#define	_OS_ERROR_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_ERROR_H_ */

/*====================================================================
 * os_gio.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_GIO_H_
#define	_OS_GIO_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_GIO_H_ */

/*====================================================================
 * os_reg.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_REG_H_
#define	_OS_REG_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Miscellaneous operations */

extern u32		osGetCount(void);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_REG_H_ */

/*====================================================================
 * os_system.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_SYSTEM_H_
#define	_OS_SYSTEM_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Values for osTvType 
 */
#define	OS_TV_PAL		0
#define	OS_TV_NTSC		1
#define	OS_TV_MPAL		2

/*
 * Size of buffer the retains contents after NMI
 */
#define OS_APP_NMI_BUFSIZE	64


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */

extern s32 	osRomType;	/* Bulk or cartridge ROM. 0=cartridge 1=bulk */
extern void 	*osRomBase;	/* Rom base address of the game image */
extern s32 	osTvType;	/* 0 = PAL, 1 = NTSC, 2 = MPAL */
extern s32 	osResetType;	/* 0 = cold reset, 1 = NMI */
extern s32 	osCicId;
extern s32 	osVersion;
extern u32	osMemSize;	/* Memory Size */
extern s32	osAppNMIBuffer[];

extern u64	osClockRate;

extern OSIntMask __OSGlobalIntMask;	/* global interrupt mask */


/**************************************************************************
 *
 * Function prototypes
 *
 */

extern void		osInitialize(void);
extern void		osExit(void);
extern u32 		osGetMemSize(void);

/* pre-NMI */
extern s32		osAfterPreNMI(void);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_SYSTEM_H_ */

/*====================================================================
 * os_eeprom.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_EEPROM_H_
#define	_OS_EEPROM_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* EEPROM TYPE */

#define EEPROM_TYPE_4K		0x01
#define EEPROM_TYPE_16K		0x02

/* definition for EEPROM */

#define EEPROM_MAXBLOCKS	64
#define EEP16K_MAXBLOCKS	256
#define EEPROM_BLOCK_SIZE	8


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* EEPROM interface */

extern s32 osEepromProbe(OSMesgQueue *);
extern s32 osEepromRead(OSMesgQueue *, u8, u8 *);
extern s32 osEepromWrite(OSMesgQueue *, u8, u8 *);
extern s32 osEepromLongRead(OSMesgQueue *, u8, u8 *, int);
extern s32 osEepromLongWrite(OSMesgQueue *, u8, u8 *, int);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_EEPROM_H_ */
/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_FLASH_H_
#define	_OS_FLASH_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* 
 * defines for FLASH
 */
#define FLASH_START_ADDR	0x08000000

#define FLASH_SIZE		0x20000
#define FLASH_LATENCY		0x5
#define FLASH_PULSE		0x0c
#define FLASH_PAGE_SIZE		0xf
#define FLASH_REL_DURATION	0x2
#define DEVICE_TYPE_FLASH	8

#define FLASH_VERSION_MX_PROTO_A	0x00c20000
#define FLASH_VERSION_MX_A		0x00c20001
#define FLASH_VERSION_MX_C		0x00c2001e
#define FLASH_VERSION_MX_B_AND_D	0x00c2001d
#define FLASH_VERSION_MEI		0x003200f1

#define OLD_FLASH			0
#define NEW_FLASH			1
/* OLD_FLASH is MX_PROTO_A, MX_A and MX_C */
/* NEW_FLASH is MX_B_AND_D and MATSUSHITA flash */

#define FLASH_STATUS_ERASE_BUSY		2
#define	FLASH_STATUS_ERASE_ERROR	-1
#define FLASH_STATUS_ERASE_OK		0

extern OSPiHandle *osFlashReInit(u8 latency, u8 pulse, 
				 u8 page_size, u8 rel_duration, u32 start);
extern OSPiHandle *osFlashInit(void);
extern void    osFlashReadStatus(u8 *flash_status);
extern void    osFlashReadId(u32 *flash_type, u32 *flash_maker);
extern void    osFlashClearStatus(void);
extern s32     osFlashAllErase(void);
extern s32     osFlashSectorErase(u32 page_num);
extern s32     osFlashWriteBuffer(OSIoMesg *mb, s32 priority, 
				void *dramAddr, OSMesgQueue *mq);
extern s32     osFlashWriteArray(u32 page_num);
extern s32     osFlashReadArray(OSIoMesg *mb, s32 priority, u32 page_num, 
				void *dramAddr, u32 n_pages, OSMesgQueue *mq);
extern void    osFlashChange(u32 flash_num);
extern void    osFlashAllEraseThrough(void);
extern void    osFlashSectorEraseThrough(u32 page_num);
extern s32     osFlashCheckEraseEnd(void);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_FLASH_H_ */

/*====================================================================
 * os_host.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_HOST_H_
#define	_OS_HOST_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */

extern void __osInitialize_common(void);

#if defined(_FINALROM)

#define osInitialize() __osInitialize_common()

#else

/* PARTNER-N64 */
#if defined(PTN64)
extern void __osInitialize_kmc(void);
#define osReadHost osReadHost_pt
#define osWriteHost osWriteHost_pt
#define osInitialize()       \
{                            \
    __osInitialize_common();  \
    __osInitialize_kmc();    \
}

/* MONEGI SMART PACK A */
#elif defined(MWN64)
extern void __osInitialize_msp(void);
#define osReadHost osReadHost_pt
#define osWriteHost osWriteHost_pt
#define osInitialize()       \
{                            \
    __osInitialize_common(); \
    __osInitialize_msp();    \
}

/* IS-Viewer(for Debugger) */
#elif defined(ISV64)
extern void __osInitialize_isv(void);
#define osInitialize()       \
{                            \
    __osInitialize_common(); \
    __osInitialize_isv();    \
}

/* Emulation board for INDY */
#elif defined(EMU64)
extern void __osInitialize_emu(void);
#define osInitialize()       \
{                            \
    __osInitialize_common(); \
    __osInitialize_emu();    \
}

#else
/* Default (auto detect) */
extern void __osInitialize_autodetect(void);
extern void __osInitialize_msp(void);
extern void __osInitialize_kmc(void);
extern void __osInitialize_isv(void);
extern void __osInitialize_emu(void);
#define osInitialize()           \
{                                \
    __osInitialize_common();     \
    __osInitialize_autodetect(); \
}
#endif

#endif  /* _FINAL_ROM */

/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Game <> Host data transfer functions */

extern s32		osTestHost(void);
extern void		osReadHost(void *, u32);
extern void		osWriteHost(void *, u32);
extern void		osAckRamromRead(void);
extern void		osAckRamromWrite(void);

/* RDB port operations */

extern void             osInitRdb(u8 *sendBuf, u32 sendSize);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_HOST_H_ */

/*====================================================================
 * os_convert.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_CONVERT_H_
#define	_OS_CONVERT_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

#define	OS_CLOCK_RATE		62500000LL
#define	OS_CPU_COUNTER		(OS_CLOCK_RATE*3/4)


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */

#define OS_NSEC_TO_CYCLES(n)	(((u64)(n)*(OS_CPU_COUNTER/15625000LL))/(1000000000LL/15625000LL))
#define OS_USEC_TO_CYCLES(n)	(((u64)(n)*(OS_CPU_COUNTER/15625LL))/(1000000LL/15625LL))
#define OS_CYCLES_TO_NSEC(c)	(((u64)(c)*(1000000000LL/15625000LL))/(OS_CPU_COUNTER/15625000LL))
#define OS_CYCLES_TO_USEC(c)	(((u64)(c)*(1000000LL/15625LL))/(OS_CPU_COUNTER/15625LL))

/* OS_K?_TO_PHYSICAL macro bug fix for CodeWarrior */
#ifndef __MWERKS__
#define	OS_K0_TO_PHYSICAL(x)	(u32)(((char *)(x)-0x80000000))
#define	OS_K1_TO_PHYSICAL(x)	(u32)(((char *)(x)-0xa0000000))
#else
#define	OS_K0_TO_PHYSICAL(x)	((char *)(x)-0x80000000)
#define	OS_K1_TO_PHYSICAL(x)	((char *)(x)-0xa0000000)
#endif

#define	OS_PHYSICAL_TO_K0(x)	(void *)(((u32)(x)+0x80000000))
#define	OS_PHYSICAL_TO_K1(x)	(void *)(((u32)(x)+0xa0000000))


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Address translation routines and macros */

extern u32		 osVirtualToPhysical(void *);
extern void *		 osPhysicalToVirtual(u32);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_CONVERT_H_ */

/*====================================================================
 * os_rdp.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_RDP_H_
#define	_OS_RDP_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Display processor interface (Dp) */
extern u32 		osDpGetStatus(void);
extern void		osDpSetStatus(u32);
extern void 		osDpGetCounters(u32 *);
extern s32		osDpSetNextBuffer(void *, u64);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_RDP_H_ */

/*====================================================================
 * os_rsp.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_RSP_H_
#define	_OS_RSP_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_RSP_H_ */

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_MOTOR_H_
#define	_OS_MOTOR_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_message.h"
#include "os_pfs.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Rumble PAK interface */

extern s32 osMotorInit(OSMesgQueue *, OSPfs *, int);
#if	1
#define MOTOR_START		1
#define MOTOR_STOP		0
#define	osMotorStart(x)		__osMotorAccess((x), MOTOR_START)
#define	osMotorStop(x)		__osMotorAccess((x), MOTOR_STOP)
extern s32 __osMotorAccess(OSPfs *, s32);
#else
extern s32 osMotorStop(OSPfs *);
extern s32 osMotorStart(OSPfs *);
#endif


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_MOTOR_H_ */

/*====================================================================
 * os_libc.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_LIBC_H_
#define	_OS_LIBC_H_

#include "os_pfs.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* byte string operations */


extern void     bcopy(const void *, void *, int);
extern int      bcmp(const void *, const void *, int);
extern void     bzero(void *, int);

/* Printf */

extern int		sprintf(char *s, const char *fmt, ...);
extern void		osSyncPrintf(const char *fmt, ...);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_LIBC_H_ */

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo.
        
        $RCSfile: OLDos_others.h,v $
        $Revision: 1.1 $
        $Date: 2003/03/14 03:27:05 $
 *---------------------------------------------------------------------*/

#ifndef _OS_VERSION_H_
#define	_OS_VERSION_H_

#define OS_MAJOR_VERSION	"2.0K"	/* major version */
#define OS_MINOR_VERSION	0	/* patch level */

#endif /* !_OS_VERSION_H_ */
