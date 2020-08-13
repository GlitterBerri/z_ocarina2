/* $Id: message_change.h,v 1.1 2003/03/14 03:39:08 tong Exp $ */	
/* $Log: message_change.h,v $
/* Revision 1.1  2003/03/14 03:39:08  tong
/* asset files copied from old tree to new tree.
/*
/* Revision 1.1  2003/02/12 19:07:42  tong
/* message_change source.
/*
 * Revision 1.1  1997/01/28  10:53:33  soejima
 * $LogÄÉ²Ã
 * */

/****************************************************************
 *	£Í£Á£Ã¡Î£Å£Ç£×£Ï£Ò£Ä¡ÏÆþÎÏ¥Æ¥­¥¹¥È ¨¡¨¡¡ä £¶£´ÊÑ´¹	*
 *								*
 *	¥¼¥ë¥À£¶£´ ¥á¥Ã¥»¡¼¥¸ÊÑ´¹¥×¥í¥°¥é¥à			*
 *	¡Ú´Á»ú£Ò£Ï£ÍÂÐ±þ¡¦¥Ð¡¼¥¸¥ç¥ó¡Û				*
 *								*
 *					97/01/28¡Ê²Ð¡ËPM 04:20	*
 *  cc message_change.c -o message_change -lX11			*
 ****************************************************************/
/*------------ £Í£Á£Ã¥Ç¡¼¥¿ ------------*/
#define D_HEADER	0x816F	/* ¥Ç¡¼¥¿³«»Ï¡Ê¡Ð¡Ë */
#define D_KUGIRI	0x8146	/* ¥Ç¡¼¥¿¶èÀÚ¤ê¡Ê¡§¡Ë */
#define Z_SYURYOU       0x8170	/* ¥Ç¡¼¥¿£Å£Î£Ä ¡Ê¡Ñ¡Ë*/
#define Z_KEYWAIT       0x81A5	/* ¥­¡¼ÂÔ¤Á ¡Ê¢§¡Ë*/
#define Z_NAME          0x874F	/* ÅÐÏ¿Ì¾Á° ¡Ê¡Ë*/
#define Z_DAMMYS        0x8151	/* Æ¬Â·¤¨¥¹¥Ú¡¼¥¹ ¡Ê¡²¡Ë*/
#define Z_DPITEM	0x819A	/* ¥¢¥¤¥Æ¥à¡Ú£³·å¡Û ¡Ê¡ú¡Ë*/
#define Z_SOUND0	0x81F4	/* ¥µ¥¦¥ó¥É¡Ê£Â£Ç£Í¡Ë¡Ú£²·å¡Û ¡Ê¢ö¡Ë*/
#define Z_SOUND1	0x81F3	/* ¥µ¥¦¥ó¥É¡Ê£Ó£Å¡Ë  ¡Ú£²·å¡Û ¡Ê¢õ¡Ë*/
#define	Z_SENTAKU_2	0x81BC	/* £²Âò ¡Ê¢¾¡Ë*/
#define Z_SENTAKU_3	0x81B8	/* £³Âò ¡Ê¢º¡Ë*/
#define Z_NEXTMSG	0x81CB	/* £Î£Å£Ø£Ô¥á¥Ã¥»¡¼¥¸ÈÖ¹æ¡Ú£´·å¡Û¡Ê¢Í¡Ë */


