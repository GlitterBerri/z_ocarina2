/* $Id: z_kanfont.h,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $ */	
/* $Log: z_kanfont.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:45  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.22  1998/09/19 09:28:42  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/11/07  10:53:46  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_KANFONT_H
#define INCLUDE_Z_KANFONT_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif



/************************************************************************
 *									*
 *	漢字フォント							*
 *				1996年11月07日(木曜日) 18時20分00秒 JST *
 ************************************************************************/
#define BUF_CT   	128
#define BUF_TOTAL	BUF_CT*30*4
#define Buf_Ct   	(128/8)

/* 文字展開バッファ */
typedef struct zelda_kanfont_struct {
    unsigned char	*msg_data, *msg_data0;


    unsigned char	kbuffer[BUF_TOTAL];
    
    unsigned char	kbuffer2[BUF_CT];

    long long	kbuffer4[Buf_Ct*16*20];	/* 文字展開バッファ */


    union	buff {
	unsigned short	message_buf[16*40];		/* メッセージ展開バッファ */
#ifdef CHINA
	unsigned char	nes_mes_buf[16*40*2];		/* メッセージ展開バッファ */
#else
	unsigned char	nes_mes_buf[16*40];		/* メッセージ展開バッファ */
#endif
    } mbuff;
} Kanfont;



extern int
getkadr(int);

extern void
kanfont_get( Kanfont *kanfont, unshort code, unshort kanadr );

extern void
kanfont_get_NES( Kanfont *kanfont, unchar code, unshort kanadr );

#ifdef CHINA
extern void
kanfont_get_ZH( Kanfont *kanfont, unshort code, unshort kanadr );
#endif

extern void
kanfont_get2( Kanfont *kanfont, unshort code );

extern void
kscope_kanfont_get( Kanfont *kanfont );



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_kanfont.h end ***/
