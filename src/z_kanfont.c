/* $Id: z_kanfont.c,v 1.3 2003/05/13 03:08:28 tong Exp $
 *
 * 漢字フォント
 *
 * $Log: z_kanfont.c,v $
 * Revision 1.3  2003/05/13 03:08:28  tong
 * kanfont_get_zh: mapping between character and its font glyph index.
 *
 * Revision 1.2  2003/05/06 21:41:59  tong
 * font DMA code.
 *
 * Revision 2.6  1998-11-06 13:36:11+09  soejima
 * コメント
 *
 * Revision 2.5  1998-10-29 18:18:51+09  soejima
 * ＰＡＬ変更
 *
 * Revision 2.4  1998-10-28 19:10:48+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.3  1998-10-28 18:36:26+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.2  1998-10-27 21:26:07+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.37  1998/08/26 06:11:54  soejima
 * *** empty log message ***
 *
 * Revision 1.36  1998-08-12 14:47:04+09  soejima
 * *** empty log message ***
 *
 * Revision 1.35  1998-06-26 20:42:50+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1996/11/07  10:53:55  soejima
 * Initial revision
 * $Log追加
 * */


/************************************************************************
 *									*
 *	漢字フォント							*
 *				1996年11月07日(木曜日) 18時20分00秒 JST *
 ************************************************************************/
#include "z_basic.h"

#include "z_kanfont.h"
#include "z_message_tbl.h"


#if defined(PAL_VERSION)
EXTERN_DEFSEG_DATA(nes_message_data_static);
#else
/* 文字フォント */
EXTERN_DEFSEG_DATA(kanji);
/* メッセージデータ */
EXTERN_DEFSEG_DATA(message_data_static);
#endif
EXTERN_DEFSEG_DATA(nes_font_static);
EXTERN_DEFSEG_DATA(message_static);




/************************************************************************
 *									*
 *	漢字フォント バッファ セット					*
 *									*
 ************************************************************************/
/* フォントＤＡＴＡ */
extern void
kanfont_get( Kanfont *kanfont, unshort code, unshort kanadr )
{
#if defined(PAL_VERSION)
    kanfont;
    code;
    kanadr;
#else
    int		m;

    m = getkadr((int)code);
    dmacopy_fg( &kanfont->kbuffer[kanadr], (u32)_kanjiSegmentRomStart+(u32)m, 128 );
#endif
}
/* ＮＥＳ版フォントＤＡＴＡ */
extern void
kanfont_get_NES( Kanfont *kanfont, unchar code, unshort kanadr )
{
    int		m;
    m = code * 128;
    dmacopy_fg( &kanfont->kbuffer[kanadr], (u32)_nes_font_staticSegmentRomStart+(u32)m, 128 );
}

#ifdef CHINA
extern void
kanfont_get_ZH( Kanfont *kanfont, unshort code, unshort kanadr )
{
    int		m;
    m = code * 128;
    dmacopy_fg( &kanfont->kbuffer[kanadr], (u32)_nes_font_staticSegmentRomStart+(u32)m, 128 );
}
#endif

/* 終了／改行マーク ＤＡＴＡ */
extern void
kanfont_get2( Kanfont *kanfont, unshort code )
{
    dmacopy_fg( &kanfont->kbuffer2[0], (u32)_message_staticSegmentRomStart+(((128*64)/2)*4)+(((16*16)/2)*code), (16*16)/2 );
}



/************************************************************************
 *	カレイド・スコープ用フォント読み込み				*
 ************************************************************************/
extern void
kscope_kanfont_get( Kanfont *kanfont )
{
    int		i, j, jj, m;
    unchar	*msg_data1, *msg_data2, *msg_data3;
    unshort *mb;
    
#if defined(PAL_VERSION)
    msg_data2 = (unchar *)zel0000_0001;
    msg_data1 = (unchar *)end_FFFC;
    msg_data3 = (unchar *)end_FFFD;
    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
    
    jj = (u32)kanfont->msg_data0;
    dmacopy_fg( &kanfont->mbuff.nes_mes_buf[0], (u32)_nes_message_data_staticSegmentRomStart+(u32)kanfont->msg_data, (u32)kanfont->msg_data0 );
    PRINTF("msg_data=%x,  msg_data0=%x   jj=%x\n",kanfont->msg_data, kanfont->msg_data0, jj );
    i = j = 0;
    /* 文字読み込み */
    while ( kanfont->mbuff.nes_mes_buf[i] != ND_SYURYOU ) {
	if ( i > jj ) {
	    PRINTF("ＥＲＲＯＲ！！  エラー！！！  error───！！！！\n");
	    break;
	}
	if ( kanfont->mbuff.nes_mes_buf[i] != NKAIGYO ) {
	    PRINTF("nes_mes_buf[%d]=%d\n",i,kanfont->mbuff.nes_mes_buf[i]);
	    m = ((int)kanfont->mbuff.nes_mes_buf[i] - 0x20) * 128;
	    dmacopy_fg( &kanfont->kbuffer4[j], (u32)_nes_font_staticSegmentRomStart+(u32)m, 128 );
	    j += Buf_Ct;
	}
	i++;
    }
#else
/*    get_msg_add_get( kanfont, 0xfffc ); */
    msg_data2 = (unchar *)ALL_0_0001;
    msg_data1 = (unchar *)END_TXT_FFFC;
    msg_data3 = (unchar *)END_TXT_FFFD;
    kanfont->msg_data = (unchar *)(msg_data1 - msg_data2);
    kanfont->msg_data0 = (unchar *)(msg_data3 - msg_data1);
    
    jj = (u32)kanfont->msg_data0/2;
    dmacopy_fg( &kanfont->mbuff.message_buf[0], (u32)_message_data_staticSegmentRomStart+(u32)kanfont->msg_data, (u32)kanfont->msg_data0 );
    PRINTF("msg_data=%x,  msg_data0=%x   jj=%x\n",kanfont->msg_data, kanfont->msg_data0, jj );
    i = j = 0;
    /* 文字読み込み */
    mb = kanfont->mbuff.message_buf;
    while ( mb[i] != D_SYURYOU ) {
	if ( i > jj ) {
	    PRINTF("ＥＲＲＯＲ！！  エラー！！！  error───！！！！\n");
	    break;
	}
	if ( mb[i] != 0x0A ) {
	    m = getkadr((int)mb[i]);
	    dmacopy_fg( &kanfont->kbuffer4[j], (u32)_kanjiSegmentRomStart+(u32)m, 128 );
	    j += Buf_Ct;
	}
	i++;
    }
#endif
}

