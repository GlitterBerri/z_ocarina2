/*---------------------------------------------------------------------*
	Copyright (C) 1998, Nintendo.
	
	File		ucode_z.h
	Coded    by	Yoshitaka Yasumoto.	Mar 30, 1998.
	
	$Id: ucode_z1.h,v 1.1 2003/03/10 22:42:44 tong Exp $
 *---------------------------------------------------------------------*/
#ifndef _UCODE_Z1_H_
#define	_UCODE_Z1_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)
/*========== F3DZEX/L3DZEX ==========*/
/* FIFO version */
extern long long int gspF3DZEX_fifoTextStart[],
                     gspF3DZEX_fifoTextEnd[];
extern long long int gspF3DZEX_fifoDataStart[],
                     gspF3DZEX_fifoDataEnd[];
extern long long int gspF3DZEX_NoN_fifoTextStart[],
                     gspF3DZEX_NoN_fifoTextEnd[];
extern long long int gspF3DZEX_NoN_fifoDataStart[],
                     gspF3DZEX_NoN_fifoDataEnd[];
extern long long int gspF3DZLX_fifoTextStart[],
                     gspF3DZLX_fifoTextEnd[];
extern long long int gspF3DZLX_fifoDataStart[],
                     gspF3DZLX_fifoDataEnd[];
extern long long int gspF3DZLX_NoN_fifoTextStart[],
                     gspF3DZLX_NoN_fifoTextEnd[];
extern long long int gspF3DZLX_NoN_fifoDataStart[],
                     gspF3DZLX_NoN_fifoDataEnd[];
extern long long int gspF3DZLX_Rej_fifoTextStart[],
                     gspF3DZLX_Rej_fifoTextEnd[];
extern long long int gspF3DZLX_Rej_fifoDataStart[],
                     gspF3DZLX_Rej_fifoDataEnd[];
extern long long int gspF3DZLP_Rej_fifoTextStart[],
                     gspF3DZLP_Rej_fifoTextEnd[];
extern long long int gspF3DZLP_Rej_fifoDataStart[],
                     gspF3DZLP_Rej_fifoDataEnd[];
extern long long int gspL3DZEX_fifoTextStart[],
                     gspL3DZEX_fifoTextEnd[];
extern long long int gspL3DZEX_fifoDataStart[],
                     gspL3DZEX_fifoDataEnd[];
#endif /* _LANGUAGE_C */
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#endif /* !_UCODE_Z_H */

/*======== End of ucode_z.h ========*/
