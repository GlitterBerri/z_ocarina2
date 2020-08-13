/*
 * $Id: system.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 * £Î£¶£´¥·¥¹¥Æ¥àÄêµÁ
 *
 * $Log: system.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.1  1998/03/23 10:30:40  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "os.h"			/* OSPiHandle */

#define SetupDmaIOMsgBuf(mb, priority, dAddr, vAddr, nbytes, mq) do {\
		(mb)->hdr.pri = priority;\
		(mb)->hdr.retQueue = mq;\
		(mb)->devAddr = dAddr;\
		(mb)->dramAddr = vAddr;\
		(mb)->size = nbytes;\
	} while (0)

extern OSPiHandle *carthandle;

#endif /* __SYSTEM_H_ */
