/*
 * $Id: sys_leoemu.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 * leoemuヘッダ
 *
 * $Log: sys_leoemu.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.1  1998/07/07 10:47:11  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __SYS_LEOEMU_H__
#define __SYS_LEOEMU_H__

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <leo.h>
    
#ifdef USE_LEOEMU

    /* IPL情報の開始アドレス／長さブロックを取得します。 */
    extern s32 LeoExGetIPLInfo(u32* iplAdrs, u32* iplLength);

    /* osEPiStartDma関数のエミュレーションです */
    extern s32 osEPiStartDmaEmu(OSPiHandle *pHandle , OSIoMesg *pMesg, s32 nMode);
#define osEPiStartDma(a, b, c) osEPiStartDmaEmu(a, b, c)

/*
  この関数は、必ず一番低い優先順位のスレッドで、呼び続けられなければいけません。
  void idle(void *arg)
  {
     ...
     while(1) {
       LeoIdle();
     }
  }
*/

extern void LeoIdle(void);

#else  /* USE_LEOEMU */

#define LeoIdle() (void)0

#endif /* USE_LEOEMU */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __SYS_LEOEMU_H__ */
