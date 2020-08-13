/*
 * $Id: faultprint.h,v 1.1 2003/03/10 22:42:25 tong Exp $
 *
 *
 * $Log: faultprint.h,v $
 * Revision 1.1  2003/03/10 22:42:25  tong
 * Initial revision
 *
 * Revision 1.3  2001-02-05 21:52:34+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  2000-10-12 11:43:25+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.1  1999-10-20 17:38:22+09  hayakawa
 * Initial revision
 *
 */

#ifndef FAULTPRINT_H
#define FAULTPRINT_H

#include <ultratypes.h>
#include <stdarg.h>

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif
#if 0
}
#endif

typedef struct {
    /*private:*/
    u16 *	frame_bufferP;			/* pointer to the frame buffer	*/
    u16		screen_width;				/* screen width			*/
    u16		screen_height;				/* screen height		*/
    u16		scissor_top;
    u16		scissor_bottom;
    u16		scissor_left;
    u16		scissor_right;
    u16		foreground_color;
    u16		background_color;
    u16		current_pos_x;
    u16		current_pos_y;
    const void	*font_imageP;	/* 8x8フォント */
    u8		font_width;	/* フォント有効横幅 */
    u8		font_height;	/* フォント有効高さ */
    s8		font_wmargin;	/* フォント横マージン 0:密着 */
    s8		font_hmargin;	/* フォント縦マージン 0:密着 */
    u16		color_palette_table[10];
    u8		setfg_mode;
    u8		syncprint_mode;	/* !0:同時にosSyncPrintfする */
    void	(*NextPageCallback)(void); /* ページの切り替えにコールバックする */
} FaultPrint_t;
extern void faultprint_SyncPrintMode(int x);
extern void faultprint_FillRectangle(int ulx, int uly, int lrx, int lry, u16 pcol);
extern void faultprint_Color(u16 color);
extern void faultprint_SetForegroundColor(u16 color);
extern void faultprint_SetBackgroundColor(u16 color);
extern void faultprint_SetMargin(s8 wmargin, s8 hmargin);
extern void faultprint_Locate(int posx, int posy);
extern void faultprint_ClearScreen(void);
extern void faultprint_Vprintf(const char *format, va_list vparam);
extern void faultprint_Printf(const char *format, ...);
extern void faultprint_PosPrintf(int posx, int posy, const char *format, ...);
extern void faultprint_Initial(void);
extern void faultprint_SetFrameBuffer(u16 *framebuf, u16 width, u16 height);
extern void faultprint_SetNextPageCallback(void (*cb)(void));
extern void faultprint_Flush(void);

#define FAULTPRINT_C_SETFG	'\032'
#define FAULTPRINT_S_SETFG	"\032"
    
#if 0
{
#endif
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* FAULTPRINT_H */
