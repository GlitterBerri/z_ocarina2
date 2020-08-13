/*
 * $Id: z_std_dma_slid.h,v 2.1 1998/10/22 11:51:48 zelda Exp $
 *
 * ゼルダ６４ の 展開しながらＤＭＡ
 *
 * $Log: z_std_dma_slid.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.3  1998/04/01 02:46:19  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1998/03/19  13:04:23  komatu
 * *** empty log message ***
 *
 * Revision 1.1  1997/08/22  13:47:07  hayakawa
 * Initial revision
 *
 *
 */

#ifndef _Z_STD_DMA_SLID_H_
#define _Z_STD_DMA_SLID_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

void slidma(unsigned long dmasrc, char *dst, unsigned long dmasiz);

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* _Z_STD_DMA_SLID_H_ */
