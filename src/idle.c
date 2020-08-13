/*
 * $Id: idle.c,v 1.3 2003/09/11 18:46:22 wheeler Exp $
 *
 * アイドルスレッドなど
 *
 * $Log: idle.c,v $
 * Revision 1.3  2003/09/11 18:46:22  wheeler
 * Additional source from Nintendo (and one from me: fakeprintf.c)
 *
 * Revision 2.12  1999/01/07  06:47:27  hayakawa
 * *** empty log message ***
 *
 * Revision 2.11  1998-11-10 15:45:52+09  zelda
 * ブラックアウトのタイミング変更
 *
 * Revision 2.10  1998-11-04 10:38:04+09  hayakawa
 * テスト
 *
 * Revision 2.9  1998-10-30 14:56:46+09  hayakawa
 * viextendvstart
 *
 * Revision 2.8  1998-10-29 15:11:50+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.7  1998-10-28 17:21:23+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.6  1998-10-27 21:38:47+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.5  1998-10-27 21:37:20+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.4  1998-10-27 20:07:50+09  hayakawa
 * スケール対応テスト
 *
 * Revision 2.3  1998-10-23 17:50:15+09  hayakawa
 * FPAL TEST
 *
 * Revision 2.2  1998-10-23 17:34:48+09  hayakawa
 * FPAL TEST
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.40  1998/10/09 08:15:12  hayakawa
 * *** empty log message ***
 *
 * Revision 1.39  1998-10-06 23:14:00+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.38  1998-10-05 23:15:57+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.37  1998-09-22 22:06:52+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.36  1998-09-17 12:06:43+09  zelda
 * *** empty log message ***
 *
 * Revision 1.35  1998-09-07 13:27:36+09  hayakawa
 * BSSのクリアを忘れていた。
 * 一応、大丈夫のはずだが
 *
 * Revision 1.34  1998-08-19 09:41:29+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.33  1998-08-01 15:13:13+09  hayakawa
 * ???
 *
 * Revision 1.32  1998-07-17 21:27:09+09  hayakawa
 * ダミーリンク追加
 *
 * Revision 1.31  1998-07-14 22:13:40+09  zelda
 * ROM_Fのときのundefined symbol対策
 *
 * Revision 1.30  1998-07-07 19:47:51+09  hayakawa
 * leoemu対応（実験中）
 *
 * Revision 1.29  1998-05-01 13:19:48+09  hayakawa
 * if USE_ を ifdef USE_ に変更
 *
 * Revision 1.28  1998-04-30 22:38:21+09  hayakawa
 * ソース整理
 *
 * Revision 1.27  1998-04-30 20:59:44+09  hayakawa
 * 動的アドレスＣＦＢ
 *
 * Revision 1.26  1998-04-24 15:53:58+09  hayakawa
 * codeセグメントロード時間を計測表示
 *
 * Revision 1.25  1998-04-09 21:42:07+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.24  1998-04-09 20:34:54+09  hayakawa
 * ほとんど変わってないと思う
 *
 * Revision 1.23  1998-03-27 15:27:33+09  hayakawa
 * Ｃ＋＋で出るワーニングに対処
 *
 * Revision 1.22  1998/03/25  14:15:43  hayakawa
 * 必要なヘッダをインクルードするようにした
 *
 * Revision 1.21  1998/03/25  12:47:46  hayakawa
 * 外部から参照されない関数を static 宣言した
 *
 * Revision 1.20  1998/03/23  09:45:15  hayakawa
 * osPi→osEPi変更
 *
 * Revision 1.19  1998/03/19  13:01:50  hayakawa
 * PRINT追加
 *
 * Revision 1.18  1998/03/10  04:39:26  hayakawa
 * 修正 CREATER → CREATOR
 *
 * Revision 1.17  1998/03/09  01:20:58  soejima
 * *** empty log message ***
 *
 * Revision 1.16  1998/03/07  12:53:03  soejima
 * Creater→CREATER, Datetime→DATETIMEに変更したよ。
 *
 * Revision 1.15  1998/03/07  07:09:02  sasaki
 * *** empty log message ***
 *
 * Revision 1.14  1998/03/07  05:52:18  sasaki
 * error taisaku
 *
 * Revision 1.13  1998/03/06  11:54:59  hayakawa
 * プリント変更のみ
 *
 * Revision 1.12  1998/03/06  11:33:22  hayakawa
 * プリント変更のみ
 *
 * Revision 1.11  1998/03/06  01:49:51  hayakawa
 * メモリ節約のために osViModeTable を使わないようにした
 * でも、osViModeTableがリンクされてしまうので効果無し
 *
 * Revision 1.10  1997/11/17  10:02:27  hayakawa
 * スタックチェックをマクロにした
 *
 * Revision 1.9  1997/11/16  13:35:15  hayakawa
 * stackcheck調整
 *
 * Revision 1.8  1997/10/28  14:01:25  hayakawa
 * PIメッセージバッファを５０に増やした
 *
 * Revision 1.7  1997/08/20  09:24:23  hayakawa
 * *** empty log message ***
 *
 * Revision 1.6  1997/08/19  09:41:54  hayakawa
 * codesegmentを圧縮するテスト
 *
 * Revision 1.5  1997/08/11  13:54:50  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1997/06/05  06:45:30  hayakawa
 * ldのバグ関連の情報を表示
 *
 * Revision 1.3  1997/05/20  12:41:42  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1997/03/20  12:52:26  hayakawa
 * stackcheck追加
 *
 * Revision 1.1  1997/03/17  12:18:17  hayakawa
 * Initial revision
 *
 */

#include "idle.h"
#include "ultra64.h"
#include "u64macro.h"
#include "sys_segment.h"	/* BOOT_STACK_SIZE */
#include "ThreadID.h"
#include "ThreadPriority.h"
#include "debug.h"		/* PRINTF, disp */
#include "macro.h"		/* number */
#include "main.h"		/* MAIN_STACKSIZE */
#include "stackcheck.h"		/* stackcheck */
#include "z_std_dma.h"		/* dmacopy_fg */
#include "version.h"		/* __Creator__ ... */
#include "system.h"		/* carthandle */
#include "sys_leoemu.h"		/* LeoIdle */
#include "sys_vimgr.h"		/* viBlack, viUpdate */

EXTERN_DEFSEG_CODE(boot);
EXTERN_DEFSEG_CODE(code);

static OSThread	mainThread;
static u64	mainStack[MAIN_STACKSIZE / sizeof(u64)];
StackCheckDecl(main);

#ifdef USE_RMON
static OSThread	rmonThread;
static u64	rmonStack[RMON_STACKSIZE / sizeof(u64)];
StackCheckDecl(rmon);
#endif

/* this number (the depth of the message queue) needs to be equal
 * to the maximum number of possible overlapping PI requests.
 * For this app, 1 or 2 is probably plenty, other apps might
 * require a lot more.
 */
#define NUM_PI_MSGS     50	/* サウンド用に大きくした */

static OSMesg 		PiMsgs[NUM_PI_MSGS];
/*GLOBAL*/ OSMesgQueue _PiMsgQ;

#ifdef USE_RMON
extern int debugflag = 0;
#endif

static void
mainx(void *arg)
{
    extern void mainproc(void *);
    OSTime t;

    PRINTF("mainx 実行開始\n");

    /*
     * DMAマネージャ作成
     */
#ifdef USE_LEOEMU
    {
	extern int _dma_verbose;
	_dma_verbose = 10;
    }
#endif
    CreateDmaManager();
#ifdef USE_LEOEMU
    {
	extern int _dma_verbose;
	_dma_verbose = 0;
    }
#endif
    
    PRINTF("codeセグメントロード中...");
    t = osGetTime();
    dmacopy_fg(_codeSegmentStart, (u32)_codeSegmentRomStart,
	       SEGMENT_ROM_SIZE(code));
    t -= osGetTime();
    PRINTF("\rcodeセグメントロード中...完了\n");
    PRINTF("転送時間 %6.3f\n");
    bzero(_codeSegmentBssStart, (u32)_codeSegmentBssEnd - (u32)_codeSegmentBssStart);
    PRINTF("codeセグメントBSSクリア完了\n");
    mainproc(arg);
    PRINTF("mainx 実行終了\n");
}

/*
 * アイドルスレッド
 */ 
#include "sys_dynamic.h"
#include "sys_fifo_buffer.h"
#include "sys_yield_buffer.h"
#include "sys_zb.h"
#include "rcp.h"		/* IO_READ */
extern void
idleproc(void *arg)
{
    PRINTF("アイドルスレッド(idleproc)実行開始\n");
#if 0
    dump((vu32 *)PHYS_TO_K1(SP_DMEM_START), SP_DMEM_END-SP_DMEM_START+1);
    dump((vu32 *)PHYS_TO_K1(SP_IMEM_START), SP_IMEM_END-SP_IMEM_START+1);
#endif
#if 0
	disp(08x, IO_READ(SP_PC_REG));
	IO_WRITE(SP_PC_REG, 0);
	disp(08x, IO_READ(SP_PC_REG));
	disp(08x, IO_READ(SP_STATUS_REG));
	disp(08x, IO_READ(SP_SEMAPHORE_REG));
	IO_WRITE(SP_SEMAPHORE_REG, 0);
	disp(08x, IO_READ(SP_SEMAPHORE_REG));
#endif
    PRINTF("作製者    : %s\n", __Creator__);
    PRINTF("作成日時  : %s\n", __DateTime__);
    PRINTF("MAKEOPTION: %s\n", __MakeOption__);

    COLOR_GREEN();
    PRINTF("ＲＡＭサイズは %d キロバイトです(osMemSize/osGetMemSize)\n",
	   (int)osMemSize / 1024);
    PRINTF("_bootSegmentEnd(%08x) 以降のＲＡＭ領域はクリアされました(boot)\n",
	   _bootSegmentEnd);
//    PRINTF("フレームバッファのサイズは %d キロバイトです\n",
//	   sizeof(sys_cfb) / 1024);
    PRINTF("Ｚバッファのサイズは %d キロバイトです\n",
	   sizeof(sys_zb) / 1024);
    PRINTF("ダイナミックバッファのサイズは %d キロバイトです\n",
	   sizeof(sys_dynamic) / 1024);
    PRINTF("ＦＩＦＯバッファのサイズは %d キロバイトです\n",
	   sizeof(sys_fifo_buffer) / 1024);
    PRINTF("ＹＩＥＬＤバッファのサイズは %d キロバイトです\n",
	   sizeof(sys_yield_buffer) / 1024);
    {
	extern char _AudioheapSegmentStart[];
	extern char _AudioheapSegmentEnd[];
	
	PRINTF("オーディオヒープのサイズは %d キロバイトです\n",
	       (_AudioheapSegmentEnd - _AudioheapSegmentStart) / 1024);
    }
    //PRINTF("0x802fb1f0 = %08x\n", *(int *)0x802fb1f0);
    COLOR_NORMAL();
    /*
     * ビデオの初期化
     * ・VIマネージャを起動する
     * ・画面モード：ＮＴＳＣ、アンチエリアス,ローレゾ,ハイカラー
     * ・特殊特徴：ガンマオフ,ディザフィルタオフ
     * ・画面を真っ黒にする
     */
    osCreateViManager((OSPri)OS_PRIORITY_VIMGR);
    vispecial = OS_VI_GAMMA_OFF|OS_VI_DITHER_FILTER_ON;
    vixscale = 1.0f;
    viyscale = 1.0f;
#if defined(VIDEO_AUTO) /*defined(FOR_WORLD)*/
    switch (osTvType) {
    case OS_TV_NTSC:
	vimode_no = OS_VI_NTSC_LAN1;
	vimode = osViModeNtscLan1;
	break;
    case OS_TV_MPAL:
	vimode_no = OS_VI_MPAL_LAN1;
	vimode = osViModeMpalLan1;
	break;
    case OS_TV_PAL:
#if 01				/* FPAL */
	vimode_no = OS_VI_FPAL_LAN1;
	vimode = osViModeFpalLan1;
	viyscale = 0.833f;
#else
	vimode_no = OS_VI_PAL_LAN1;
	vimode = osViModePalLan1;
	viextendvstart = 0;
#endif
	break;
    }
#elif defined(VIDEO_PAL) /*defined(PAL_VERSION)*/	/* FOR_Eヨーロッパ */
    switch (osTvType) {
    case OS_TV_NTSC:
    case OS_TV_PAL:
    case OS_TV_MPAL:
#if 01				/* FPAL */
	vimode_no = OS_VI_FPAL_LAN1;
	vimode = osViModeFpalLan1;
	viyscale = 0.833f;
#else
	vimode_no = OS_VI_PAL_LAN1;
	vimode = osViModePalLan1;
	viextendvstart = 0;
#endif
	break;
    }
#elif defined(VIDEO_NTSC_OR_MPAL) /*defined(FOR_JAPAN) || defined(FOR_USA)*/
    switch (osTvType) {
    case OS_TV_NTSC:
    case OS_TV_PAL:		/* PALはNTSCとして扱う */
	vimode_no = OS_VI_NTSC_LAN1;
	vimode = osViModeNtscLan1;
	break;
    case OS_TV_MPAL:
	vimode_no = OS_VI_MPAL_LAN1;
	vimode = osViModeMpalLan1;
	break;
    }
#else
#error "VIDEO_??? が定義されていません"
    vimode_no = OS_VI_NTSC_LAN1;
    vimode = osViModeNtscLan1;
#endif
    vidirty = 1;
    
    osViSetMode( &vimode );
    viBlack(1);
    osViBlack(1);
    osViSwapBuffer(0x803da80);

    /*
     * PIマネージャを起動する(カートリッジアクセス用)
     */
    osCreatePiManager((OSPri)OS_PRIORITY_PIMGR,
		      &_PiMsgQ, PiMsgs, number(PiMsgs));
    
#ifdef USE_RMON
    /*
     * デバッギングとデータ変換用にRMONを起動する
     * (先にPIマネージャの起動を確かめよ)
     */
    StackCheckInit(rmon);
    osCreateThread(&rmonThread, (OSId)THREAD_ID_RMON, rmonMain, NULL,
		   (void *)(rmonStack + number(rmonStack)), 
		   (OSPri)OS_PRIORITY_RMON);
    osStartThread(&rmonThread);
#endif /* USE_RMON */
    
    /*
     * メインスレッドの作成
     */
    StackCheckInitN(main, 1024);
    osCreateThread(&mainThread, THREAD_ID_MAIN, mainx, arg,
		   mainStack + number(mainStack),
		   (OSPri)PRIORITY_MAIN);

    /*
     * gload -a "-d" で立ち上げた時はデバッグモード
     * スレッドの開始はデバッガで行なう
     */
#ifdef USE_RMON
    if (!debugflag) {
#endif
	/*
	 * 各アプリケーションスレッドの起動
	 */
    osStartThread(&mainThread);
#ifdef USE_RMON
    } else {
	PRINTF("ゲームショップデバッグモード\n");
	PRINTF("dbgif &\n");
	PRINTF("gvd zelda\n");
    }
#endif
    
    /*
     * idleスレッドは何もしないスレッドになる
     */
    osSetThreadPri(NULL, (OSPri)OS_PRIORITY_IDLE);

#ifdef USE_LEOEMU
    {
	extern u32 leoComuBuffAdd;

	PRINTF("leoComuBuffAdd=%08x\n", leoComuBuffAdd);
	PRINTF("*** call LeoIdle() ***\n");
	LeoIdle();
    }
#endif
    for (;;) {
#ifdef USE_LEOEMU
	    //PRINTF("*** call LeoIdle() ***\n");
	    LeoIdle();
#endif
    }
    /*PRINTF("アイドルスレッド(idleproc)実行終了\n");*/
}

#include "os_internal.h"	/* __osSetHWIntrRoutine */
static void *_dummy[] = {
    osStopThread,
    __osSetHWIntrRoutine,
#ifdef USE_LEOEMU
    osPiWriteIo,
    osPiReadIo,
    osPiStartDma,
    LeoGetKAdr,
    LeoGetAAdr2,
#endif /* USE_LEOEMU */
#if defined(USE_N64DD)
    osEPiWriteIo,
    osEPiReadIo,
#endif
    __osSetFpcCsr,
    __osGetFpcCsr,
    __osGetHWIntrRoutine,
    __osSetHWIntrRoutine,
    osViGetNextFramebuffer,
    bcmp,
};
