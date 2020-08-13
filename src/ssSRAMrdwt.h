/*
 ******************************************************************************
 *              
 *     ドメインへのアクセス管理処理のヘッダー
 *              
 * $Id: ssSRAMrdwt.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 * $Log: ssSRAMrdwt.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.2  1998/05/01 04:14:57  otsuki
 * FOR_SRAM_ACCESSをDEBUG以外でも有効にした。
 *
 * Revision 1.1  1998/04/03 06:14:27  soejima
 * Initial revision
 *
 *              
 ******************************************************************************
 */
#if      !defined(__SRAM_MANAGERh)
#define  __SRAM_MANAGERh
#include <os_internal.h>
#include <rcp.h>
#include "main.h"

#define FOR_SRAM_ACCESS       1

/* ドメインクラス */
typedef struct class_sram {
    OSPiHandle   handle;
    OSIoMesg     dmaIoMesgBuf;
    OSMesgQueue  dmaMessageQ;
} ssDMNClass;

enum domain_access_type {DOMAIN_READ = OS_READ, DOMAIN_WRITE = OS_WRITE};
void ssDMNReadWrite(void *, size_t, int);
void ssDMNInitial(void *, u8, u8, u8, u8, u8, u8, u32);

#ifdef FOR_SRAM_ACCESS
/* ＳＲＡＭアクセスのための定数 */
#define SRAM_START_ADDR       (void *)0x08000000   /* 開始アドレス */
#define SRAM_SIZE             0x8000 	           /* 容量 */
#define SRAM_LATENCY          0x5 
#define SRAM_PULSE            0x0c 
#define SRAM_PAGE_SIZE        0xd 
#define SRAM_REL_DURATION     0x2

/* ＳＲＡＭのアクセス */
#define ssSRAMRead(p,s,sz)    ssSRAMReadWrite(s,p,sz,DOMAIN_READ)
#define ssSRAMWrite(s,p,sz)   ssSRAMReadWrite(s,p,sz,DOMAIN_WRITE)
void ssSRAMReadWrite(void *, void *, size_t, int);

#if DEBUG
void SRAMAccessTest(void);
#endif
#endif //FOR_SRAM_ACCESS

#ifdef SYS_GATEWAY_N64
/* ゲートウェイＮ６４ポートアクセスのための定数 */
#define GWYN64_PORT               ((void *)0x0ff70000)
#define GWYN64_PORT_SIZE          0x8000 	           /* 容量 */
#define GWYN64_PORT_LATENCY       0x5 
#define GWYN64_PORT_PULSE         0x0c 
#define GWYN64_PORT_PAGE_SIZE     0xd 
#define GWYN64_PORT_REL_DURATION  0x2

#define ssGWYPRead(p)         ssGWYPReadWrite(GWYN64_PORT,p,DOMAIN_READ)
#define ssGWYPWrite(p)        ssGWYPReadWrite(GWYN64_PORT,p,DOMAIN_WRITE)
void ssGWYPReadWrite(void *, void *, int);
#endif

#endif
