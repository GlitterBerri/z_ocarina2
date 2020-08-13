/*
 * $Id: z_message_tbl.h,v 2.2 1998-10-27 21:26:31+09 soejima Exp $
 */	



#ifndef INCLUDE_Z_MESSAGE_TBL_H
#define INCLUDE_Z_MESSAGE_TBL_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


/************************************************************************
 *									*
 *	£Í£Å£Ó£Ó£Á£Ç£Å							*
 *				1997Ç¯02·î26Æü(¿åÍËÆü) 14»þ30Ê¬00ÉÃ JST *
 ************************************************************************/
# if defined(PAL_VERSION)
#include "../data/pal_nes_a"
#include "../data/pal_ger_a"
#include "../data/pal_fra_a"
#include "../data/pal_staff_a"
# else
#include "../data/msg.h"
#include "../data/nes_a"
#include "../data/staff_a"
# endif






#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_message_tbl.h end ***/
