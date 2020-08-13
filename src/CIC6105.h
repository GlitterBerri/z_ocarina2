/*
 * $Id: CIC6105.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 * 
 * CIC6105対応rspbootの宣言
 *
 * $Log: CIC6105.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.5  1998/10/14 08:44:29  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1998-10-02 21:19:15+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1998-06-17 15:35:11+09  hayakawa
 * rspbootマイクロコードのシンボルを作り出すマクロを作った
 *
 */
#ifndef __CIC6105_H_
#define __CIC6105_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "gfxprint.h"		/* gfxprint_t */

/*
 * CICに対応したrspbootマイクロコードのシンボルを作り出す
 */
#if   defined(USE_CIC6105_NOCHECK)
#define RSPBOOT(x)	rspboot0_nocheck##x
#elif defined(USE_CIC6105_CHECK)
#define RSPBOOT(x)	rspboot0##x
#else
#define RSPBOOT(x)	rspboot##x
#endif

extern long long int	RSPBOOT(TextStart)[], RSPBOOT(TextEnd)[];

/* call by z_title.c */
extern void cic6105_title_draw(gfxprint_t *gfxprint);
extern void cic6105_title_cleanup(void);
/* call by audioMgr.c */
extern void cic6105_amInit(void);
/* call by main.c */
extern void cic6105_init(void);
extern void cic6105_cleanup(void);
extern void cic6105_test(void);

#include "z_std_dma.h"		/* dmacopy_fg */
#define	CIC6105_DMA_START_ADDR		0xfc0
#define	CIC6105_DMA_TEST_DATA1		0x8bc43b5d
#define	CIC6105_DMA_TEST_DATA2		0xbb3518a2
#define	CIC6105_DMA_START_ADDR2		0xf98
#define	CIC6105_DMA_TEST_DATA3		0xb2f779f7
#define	CIC6105_DMA_TEST_DATA4		0x6057fc3b

#define CIC6105_CART_ADDR1		0xb0000340
#define CIC6105_CART_DATA1		0x0330c820
#define CIC6105_CART_ADDR2		0xb0000d24
#define CIC6105_CART_DATA2		0x98cce31a

#define	CIC6105_RDRAM_TEST_ADDR2	0xa00002e8
#define	CIC6105_RDRAM_TEST_DATA2	0xc86e2000

#define CIC6105_BOOT_RDRAM_TEST_ADDR1	0xa02fb1f4
#define CIC6105_BOOT_RDRAM_TEST_DATA1	0xad090010
#define CIC6105_BOOT_RDRAM_TEST_ADDR2	0xa02fe1c0
#define CIC6105_BOOT_RDRAM_TEST_DATA2	0xad170014



#define CIC6105_CartDmaTest1(databuf_p) \
	dmacopy_fg((void *)(databuf_p), CIC6105_DMA_START_ADDR, 16)
#define CIC6105_CartDmaTest1_is_OK(databuf_p) ( \
	((*(databuf_p))[0] == CIC6105_DMA_TEST_DATA1) && \
	((*(databuf_p))[1] == CIC6105_DMA_TEST_DATA2))
#define CIC6105_CartDmaTest2(databuf_p) \
    	dmacopy_fg((void *)(databuf_p), CIC6105_DMA_START_ADDR2, 16)
#define CIC6105_CartDmaTest2_is_OK(databuf_p) ( \
	((*(databuf_p))[0] == CIC6105_DMA_TEST_DATA3) && \
	((*(databuf_p))[1] == CIC6105_DMA_TEST_DATA4))
    
#define CIC6105_CartTest1(data_p) \
    	osPiReadIo(CIC6105_CART_ADDR1, data_p)
#define CIC6105_CartTest1_is_OK(data_p) (*(data_p) == CIC6105_CART_DATA1)
#define CIC6105_CartTest2(data_p) \
    	osPiReadIo(CIC6105_CART_ADDR2, data_p)
#define CIC6105_CartTest2_is_OK(data_p) (*(data_p) == CIC6105_CART_DATA2)

#define CIC6105_RamTest1_is_OK() (osCicId == 6105)
#define CIC6105_RamTest2_is_OK() (*(u32 *)CIC6105_RDRAM_TEST_ADDR2 == CIC6105_RDRAM_TEST_DATA2)
    
#define CIC6105_BootRamTest1(data_p) \
    	(*(data_p) = *(u32 *)CIC6105_BOOT_RDRAM_TEST_ADDR1)
#define CIC6105_BootRamTest1_is_OK(data_p) \
    	(*(data_p) == CIC6105_BOOT_RDRAM_TEST_DATA1)
#define CIC6105_BootRamTest2(data_p) \
    	(*(data_p) = *(u32 *)CIC6105_BOOT_RDRAM_TEST_ADDR2)
#define CIC6105_BootRamTest2_is_OK(data_p) \
    	(*(data_p) == CIC6105_BOOT_RDRAM_TEST_DATA2)

    extern void cic6105_boot(void);
    extern u32 cic6105_cputest(void);
    extern u32 cic6105_BootRamTestData1;
    extern u32 cic6105_BootRamTestData2;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __CIC6105_H_ */
