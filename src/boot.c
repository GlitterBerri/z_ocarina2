/*
 * $Id: boot.c,v 1.3 2003/09/11 18:46:22 wheeler Exp $
 *
 * ブート処理
 *
 * $Log: boot.c,v $
 * Revision 1.3  2003/09/11 18:46:22  wheeler
 * Additional source from Nintendo (and one from me: fakeprintf.c)
 *
 * Revision 2.3  2001/04/04  07:21:47  zelda
 * ドルフィンエミュレータ用仮ぐみ版 CICと64DD対応部分をはずしたバージョン
 *
 * Revision 2.2  1998-11-09 11:56:22+09  hayakawa
 * ソースコメント追加
 *
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.27  1998/10/14 08:43:32  hayakawa
 * *** empty log message ***
 *
 * Revision 1.26  1998-09-07 21:07:36+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.25  1998-09-07 13:32:00+09  hayakawa
 * osMemSize = osGetMemSize() するようにした
 *
 * Revision 1.24  1998-08-13 21:49:31+09  hayakawa
 * osDriveRomInit うーん
 *
 * Revision 1.23  1998-07-17 21:24:58+09  hayakawa
 * osAiSetFrequency(376000)が980708patch で不要
 *
 * Revision 1.22  1998-06-25 22:11:44+09  hayakawa
 * osSyncPrintfをtrapprintf.cに移動
 *
 * Revision 1.21  1998-06-18 22:38:27+09  hayakawa
 * プチノイズ対策を入れてみた。
 *
 * Revision 1.20  1998-06-08 22:03:54+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.19  1998-06-08 22:02:33+09  hayakawa
 * ロケール定義
 *
 * Revision 1.18  1998-05-29 17:35:47+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.17  1998-05-01 13:19:28+09  hayakawa
 * if USE_ を ifdef USE_ に変更
 *
 * Revision 1.16  1998-04-30 22:38:32+09  hayakawa
 * ソース整理
 *
 * Revision 1.15  1998-04-15 15:37:00+09  hayakawa
 * ROM_ROMのときにisPrintfInitを呼ばないようにした
 *
 * Revision 1.14  1998-03-23 18:41:29+09  hayakawa
 * osPi→osEPi変更
 *
 * Revision 1.13  1998/03/12  11:26:51  hayakawa
 * pt.hをインクルードしないようにした
 *
 * Revision 1.12  1997/12/25  09:05:46  hayakawa
 * StackCheckInit→StackCheckInitBoot
 *
 * Revision 1.11  1997/11/18  12:45:12  hayakawa
 * stackcheck対応
 * ClearRDRAMのタイミングを変更
 *
 * Revision 1.10  1997/11/17  10:02:03  hayakawa
 * スタックチェックをマクロにした
 *
 * Revision 1.9  1997/11/16  13:37:57  hayakawa
 * stackcheck対応
 *
 * Revision 1.8  1997/08/21  02:58:58  hayakawa
 * IS-VIEWER用
 *
 * Revision 1.7  1997/05/21  09:42:27  hayakawa
 * ワーニング対策
 *
 * Revision 1.6  1997/05/15  12:39:33  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1997/05/13  05:42:57  soejima
 * ＩＳーＤｅｂｇｅｒ用 isPrintfInit() 入荷
 *
 * Revision 1.4  1997/03/27  12:42:16  hayakawa
 * パートナー用修正
 * osSyncPrintf用トラップ
 *
 * Revision 1.3  1997/03/20  12:50:52  hayakawa
 * ラムクリアのサイズが間違っていた
 *
 * Revision 1.2  1997/03/17  12:15:56  hayakawa
 * アイドル関係の処理をidle.cに移した
 *
 * Revision 1.1  1997/03/17  00:56:51  hayakawa
 * Initial revision
 *
 */

#include "boot.h"
#include "ultra64.h"
#include "u64macro.h"
#include "sys_segment.h"	/* BOOT_STACK_SIZE */
#include "ThreadID.h"
#include "ThreadPriority.h"
#include "debug.h"		/* PRINTF, disp */
#include "macro.h"		/* number */
#include "is_debug.h"		/* ｉｓ-Ｄｅｂｕｇｅｒ */
#include "stackcheck.h"		/* stackcheck */
#include "system.h"		/* carthandle */
#ifdef USE_LOCALE
#include "z_locale.h"		/* z_locale_init */
#endif

#include "idle.h"
#if defined(USE_CIC6105)
#include "CIC6105.h"		/* cic6105_boot */
#endif /* defined(USE_CIC6105) */

EXTERN_DEFSEG_CODE(boot);

/*
 * bootはスレッドではない
 * bootStackはbootstack.cで定義している
 */
extern u64 bootStack[BOOT_STACKSIZE / sizeof(u64)];
StackCheckDecl(boot);

static OSThread	idleThread;
static u64	idleStack[IDLE_STACKSIZE / sizeof(u64)];
StackCheckDecl(idle);

#ifdef USE_RMON
/*
 * 引数の取得
 * gload -a の引数を argc, argv[]の形に変換する
 */
static void
get_args(int *argcp, char ***argvp)
{
    static u32 argbuf[16];
    char	*arglist[32];	/* max 32 args */
    char	*ptr;
    u32 *argp;
    int i;
    int argc;
    char **argv;
    
    argp = (u32 *)RAMROM_APP_WRITE_ADDR;
    for (i = 0; i < (int)number(argbuf); i++, argp++) {
	osEPiReadIo(carthandle, (u32)argp, &argbuf[i]); /* Assume no DMA */
    }
    
    /* re-organize argstring to be like main(argv,argc) */
    argc = 1;
    argv = arglist;
    ptr = (char *)argbuf;
    while (*ptr != '\0') {
	while (*ptr != '\0' && (*ptr == ' ')) {
	    *ptr = '\0';
	    ptr++;
	}
	if (*ptr != '\0') {
	    argv[argc++] = ptr;
	}
	while (*ptr != '\0' && (*ptr != ' ')) {
	    ptr++;
	}
    }
    *argcp = argc;
    *argvp = argv;
}
#endif /* DEBUG && USE_RMON */

#ifdef USE_RMON
/*
 * 引数の評価
 */
static void
parse_args(int argc, char **argv)
{
    /* process the arguments: */
    while (argc > 1) {
	if (argv[1][0] == '-') {
	    switch(argv[1][1]) {
	    case 'd':
		debugflag   = 1;
		break;
		
	    case 'b':
		break;
		
	    case 'v':
		break;
		
	    case 'P':
//		profile     = 1;
		break;
	    default:
		PRINTF("不明な引数 [%s]\n", argv[1]);
		break;
	    }
	}
	argc--;
	argv++;
    }
}
#endif /* DEBUG && USE_RMON */

/*
 * ブートセグメント以降のすべてのＲＡＭをクリアする
 */
static void
ClearRDRAM(void)
{
    bzero(_bootSegmentEnd, (size_t)osMemSize - (size_t)OS_K0_TO_PHYSICAL(_bootSegmentEnd));
}

extern void
boot(void)
{
    StackCheckInitBoot(boot);

    osMemSize = osGetMemSize();
#if defined(USE_CIC6105)
    cic6105_boot();
#endif /* defined(USE_CIC6105) */
    
    ClearRDRAM();		/* ブートセグメント以降のRAMをクリア */
    
    osInitialize();		/* ６４ＯＳ初期化 */
    carthandle = osCartRomInit(); /* EPi関数用ハンドル取得 */
    osDriveRomInit();		/* やっちゃていいのか？？ */
#if !defined(ROM_ROM)
#if defined(ISVIEWER)
    isPrintfInit();		/* ＩＳＶＩＥＷＲ初期化 */
#elif defined(PARTNER)
    {
	void ptstart(void);

	ptstart();			/* パートナーＮ６４初期化 */
    }
#endif
#endif /* !defined(ROM_ROM) */

    
#ifdef USE_RMON
    {
	int argc;
	char **argv;

	get_args(&argc, &argv);	/* オプション取得 */
	parse_args(argc, argv);	/* オプション解析 */
    }
#endif /* USE_RMON */
    
#ifdef USE_LOCALE
    z_locale_init();
#endif
    
    /* アイドルスレッドの設定と起動 */
    StackCheckInit(idle);
    osCreateThread(&idleThread, THREAD_ID_IDLE, idleproc, NULL,
		   idleStack + number(idleStack),
		   (OSPri)PRIORITY_MAIN);
    osStartThread(&idleThread);

    /* never reached (決して到達しない) */
}
