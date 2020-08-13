/*
 * $Id: z_std_dma.c,v 1.4 2003/09/11 21:19:03 wheeler Exp $
 *
 * ゼルダ６４ の ＤＭＡ
 *
 * $Log: z_std_dma.c,v $
 * Revision 1.4  2003/09/11 21:19:03  wheeler
 * Fix compiler warnings.
 * Remove debugging code
 * Reduce stacksize.
 *
 * Revision 1.3  2003/09/11 18:46:22  wheeler
 * Additional source from Nintendo (and one from me: fakeprintf.c)
 *
 * Revision 2.2  2001/04/04  07:21:47  zelda
 * ドルフィンエミュレータ用仮ぐみ版 CICと64DD対応部分をはずしたバージョン
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.57  1998/10/13 14:07:33  hayakawa
 * *** empty log message ***
 *
 * Revision 1.56  1998-10-13 09:40:47+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.55  1998-10-08 19:58:34+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.54  1998-10-07 15:57:52+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.53  1998-10-03 16:27:35+09  zelda
 * *** empty log message ***
 *
 * Revision 1.52  1998-09-30 20:04:47+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.51  1998-09-28 23:13:46+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.50  1998-09-28 17:15:01+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.49  1998-09-18 12:05:58+09  zelda
 * 未テスト危険
 *
 * Revision 1.48  1998-09-17 22:47:42+09  zelda
 * *** empty log message ***
 *
 * Revision 1.47  1998-09-17 22:33:44+09  zelda
 * DMA ERROR 時に呼び出し元情報を表示するようにした
 *
 * Revision 1.46  1998-09-17 11:50:48+09  hayakawa
 * ＤＤのメッセージがちゃんとで無かったのを修正
 *
 * Revision 1.45  1998-09-15 21:52:00+09  hayakawa
 * ６４ＤＤ更新
 *
 * Revision 1.44  1998-09-14 22:59:52+09  hayakawa
 * DD Font 転送用 DMA
 *
 * Revision 1.43  1998-09-05 20:21:33+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.42  1998-09-04 16:50:11+09  hayakawa
 * DDを解放すると飛ぶのを修正
 *
 * Revision 1.41  1998-08-26 17:12:24+09  hayakawa
 * メッセージバッファの数を増やした
 *
 * Revision 1.40  1998-08-24 20:14:47+09  hayakawa
 * z_segment.declテスト
 *
 * Revision 1.39  1998-08-20 23:09:37+09  hayakawa
 * slidmaするときにスレッドプライオリティを下げてみた
 *
 * Revision 1.38  1998-08-18 21:28:03+09  hayakawa
 * 分割サイズを変更できるようにした（デバッグ用）
 *
 * Revision 1.37  1998-08-17 21:45:38+09  zelda
 * DMA分割サイズを８Ｋに増加
 *
 * Revision 1.36  1998-08-08 15:55:57+09  hayakawa
 * エラー処理変更
 *
 * Revision 1.35  1998-08-07 13:38:25+09  hayakawa
 * fault_HungUpMsgテスト
 *
 * Revision 1.34  1998-07-24 16:17:35+09  hayakawa
 * percial_DMAが復帰値を返すようにした
 *
 * Revision 1.33  1998-07-17 21:35:13+09  hayakawa
 * dmacopy_fg, dmacopy_bg が復帰値を持つようにした
 *
 * Revision 1.32  1998-07-07 19:49:10+09  hayakawa
 * leoemu対応（実験中）
 *
 * Revision 1.31  1998-06-23 21:31:31+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.30  1998-06-23 21:20:33+09  hayakawa
 * 64DD動作時にサウンドのＤＭＡを実行しないようにした
 *
 * Revision 1.29  1998-06-05 16:56:55+09  hayakawa
 * サウンド用トラップなど
 *
 * Revision 1.28  1998-05-19 16:49:14+09  hayakawa
 * ＤＭＡ分割サイズを２５６→４Ｋに変更（稲垣さんの要請）
 *
 * Revision 1.27  1998-05-15 22:08:30+09  hayakawa
 * DMA_PERFORMACE_TESTで転送時間やレートを計算表示するようにした
 *
 * Revision 1.26  1998-04-21 16:18:34+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1998/03/25 13:17:10  hayakawa
 * Ｃ＋＋用修正
 *
 * Revision 1.24  1998/03/25  10:54:39  hayakawa
 * 型の違いを修正
 *
 * Revision 1.23  1998/03/23  09:49:03  hayakawa
 * osPi→osEPi変更
 *
 * Revision 1.22  1998/03/23  06:26:52  hayakawa
 * 型の不一致修正
 *
 * Revision 1.21  1998/03/13  11:56:19  hayakawa
 * Ｃ＋＋コンパイラでエラーにならないようにした
 *
 * Revision 1.20  1998/03/12  11:28:24  hayakawa
 * やっぱりstrcmpがないと飛ぶので復活
 *
 * Revision 1.19  1998/03/12  05:58:45  hayakawa
 * パーシャルＤＭＡを独立させた
 * ＳＺＰ圧縮処理を削除
 *
 * Revision 1.18  1998/03/06  01:47:11  hayakawa
 * メモリ節約のためにセグメント名テーブルを使わないようにした
 *
 * Revision 1.17  1998/02/23  05:16:35  hayakawa
 * *** empty log message ***
 *
 * Revision 1.16  1998/02/18  08:42:12  hayakawa
 * 仮想ＲＯＭアドレスが３２ＭＢを超えていてもいいようにした
 *
 * Revision 1.15  1998/02/17  09:24:14  hayakawa
 * *** empty log message ***
 *
 * Revision 1.14  1998/01/05  02:39:55  hayakawa
 * dma_rom_adを別ソースに移動
 *
 * Revision 1.13  1997/11/18  12:46:54  hayakawa
 * DMAMGR_STACKSIZEを増やした
 *
 * Revision 1.12  1997/11/17  10:04:20  hayakawa
 * スタックチェックをマクロにした
 *
 * Revision 1.11  1997/11/16  13:37:07  hayakawa
 * stackcheck対応
 *
 * Revision 1.10  1997/11/07  10:37:26  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1997/09/12  13:01:27  hayakawa
 * デバッグ時に置いて、どのセグメントも圧縮していない場合に限り、
 * テーブルに登録していないセグメント領域も転送する
 *
 * Revision 1.8  1997/09/05  14:02:06  hayakawa
 * makeromセグメントサイズを確認するようにした
 *
 * Revision 1.7  1997/08/25  13:56:56  hayakawa
 * セグメント名（デバッグ用）追加
 *
 * Revision 1.6  1997/08/25  09:11:06  hayakawa
 * ROMSIZEを32Mbytesに引き上げた
 *
 * Revision 1.5  1997/08/23  08:37:33  hayakawa
 * *** empty log message ***
 *
 * Revision 1.4  1997/08/22  13:46:53  hayakawa
 * szs対応
 *
 * Revision 1.3  1997/08/22  04:41:48  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1997/08/20  09:22:40  hayakawa
 * ４Ｍラムでの圧縮解凍テスト
 *
 * Revision 1.1  1997/08/18  12:42:47  hayakawa
 * Initial revision
 *
 */

#define  _Z_STD_DMA_C_
#include "z_std_dma.h"
#include "z_std_dma_slid.h"
#include "u64basic.h"
#include "ThreadID.h"
#include "ThreadPriority.h"
#include "debug.h"
#include "stackcheck.h"		/* stackcheck */
#include "system.h"		/* carthandle */
#include "assert64.h"		/* assert */
#if defined(USE_N64DD)
#include "z_n64dd_keep.h"
#endif /* defined(USE_N64DD) */
#include "sleep.h"		/* msleep */
#include "sys_leoemu.h"		/* osEPiStartDma(Emu) */
#include "fault.h"		/* fault_HungUpMsg */
#if defined(USE_N64DD)
#include "z_n64dd_function.h"
#endif /* defined(USE_N64DD) */

#define is_compressed(dma_rom_t) ((dma_rom_t)->rom_e != 0)

#define MAXROMSIZE 0x04000000	/* 64Mbytes */
#define VERBOSE 0
#define DMA_SPLIT_SIZE 0x2000	/* DMA分割サイズ */
#define MSGBUF_SIZE 32
#define DMAMGR_STACKSIZE 0x500	/* 実績 0x204 */

StackCheckDecl(dmamgr);

/*
 * デバッグ用隠しグローバル変数
 */
int _dma_verbose = 0;	/* DMA表示レベル */
				/* 0:一切表示しない */
				/* 1:致命的なエラーのみ */
u32 _dma_split_size = DMA_SPLIT_SIZE;

static int exist_compressed = 0; /* !0:ＤＭＡテーブルに中に１つでも圧縮セグメントが存在する */

static OSMesgQueue 	dmaEntryMsgQ;
static OSMesg 		dmaEntryMsgBufs[MSGBUF_SIZE];
static OSThread		dmamgrThread;
static u64		dmamgrStack[DMAMGR_STACKSIZE / sizeof(u64)];

extern dma_rom_t dma_rom_ad[];
extern char _bootSegmentRomStart[];
extern OSMesgQueue _PiMsgQ;

#ifdef USE_SEGMENT_NAME_TABLE
static unsigned char *dma_rom_ad_name[] = {
    "makerom",
#define _DECL_(name) #name,
#include "z_segment_decl.inc"
#undef _DECL_
};
#endif /* USE_SEGMENT_NAME_TABLE */

/*
 * strcmp と同じです
 */
static int
my_strcmp(const unsigned char *a, const unsigned char *b)
{
    while (*a != 0) {
	if (*a > *b)
	    return 1;
	else if (*a < *b)
	    return -1;
	a++;
	b++;
    }
    if (0 < *b)
	return -1;
    else
	return 0;
}

#if 0				/* EPI Lock Test 未使用 */
extern volatile char _EPI_isAvaliable; /* !0:EPI使用可能(no busy) */
volatile char _EPI_isAvaliable; /* !0:EPI使用可能(no busy) */

/*
 * EPIロック
 */
static int
EPI_LockNoWait(void)
{
    osRecvMesg
    if (!_EPI_isAvaliable) {
	return 0;
    }
    _EPI_isAvaliable = 0;
    
    return 1;
}

/*
 * EPIロック
 * ロックできるまで帰らない
 */
static void
EPI_Lock(void)
{
    while (!EPI_LockNoWait()) {
	COLOR_RED();
	PRINTF("EPIが使用可能ではありません\n");
	COLOR_NORMAL();
	msleep(1);
    }
}

/*
 * EPIアンロック
 */
static void
EPI_Unlock(void)
{
    if (_EPI_isAvaliable) {
	COLOR_RED();
	PRINTF("EPI LockしてないのにUnlockしようとした\n");
	COLOR_NORMAL();
	HungUp();
    }
    _EPI_isAvaliable = 1;
}

/*
 * ディスクロック状態
 */
static int
EPI_isLocked(void)
{
    return !_EPI_isAvaliable;
}
#endif





/*
 *
 *	ＤＭＡ分割	サウンドチームから提供
 *
 */
extern s32
percial_DMA(
    u32 romaddress,
    void *ramaddress,
    u32 size
)
{
    OSIoMesg    dmaIOMsgBuf;
    OSMesgQueue dmaFinishMsgQ;
    OSMesg 	dmaFinishMsgBuf;
    s32 r;
    u32 dma_split_size = _dma_split_size;

    if (dma_split_size == 0) {
	dma_split_size = DMA_SPLIT_SIZE;
    }
    osInvalICache(ramaddress, size);
    osInvalDCache(ramaddress, size);
    osCreateMesgQueue(&dmaFinishMsgQ, &dmaFinishMsgBuf, 1);
    while (size > dma_split_size){
       	SetupDmaIOMsgBuf(&dmaIOMsgBuf, OS_MESG_PRI_NORMAL, romaddress,
			 ramaddress, dma_split_size, &dmaFinishMsgQ);
	if (_dma_verbose == 10) {
	    OSIoMesg *mb = &dmaIOMsgBuf;
	    
	    PRINTF("%10lld ノーマルＤＭＡ %08x %08x %08x (%d)\n",
		   OS_CYCLES_TO_USEC(osGetTime()),
		   mb->dramAddr, mb->devAddr, mb->size, MQ_GET_COUNT(&_PiMsgQ));
	}

       	r = osEPiStartDma(carthandle, &dmaIOMsgBuf, OS_READ);
	if (r != 0) {
	    goto ERROR_EXIT;
	}
	if (_dma_verbose == 10) {
	    PRINTF("%10lld ノーマルＤＭＡ START (%d)\n",
		   OS_CYCLES_TO_USEC(osGetTime()),
		   MQ_GET_COUNT(&_PiMsgQ));
	}
        osRecvMesg(&dmaFinishMsgQ, NULL, OS_MESG_BLOCK);
	if (_dma_verbose == 10) {
	    PRINTF("%10lld ノーマルＤＭＡ END (%d)\n",
		   OS_CYCLES_TO_USEC(osGetTime()),
		   MQ_GET_COUNT(&_PiMsgQ));
	}
	size -= dma_split_size;
	romaddress += dma_split_size;
	ramaddress = (void *)((char *)ramaddress + dma_split_size);
    }
    SetupDmaIOMsgBuf(&dmaIOMsgBuf, OS_MESG_PRI_NORMAL,
		     romaddress, ramaddress, size, &dmaFinishMsgQ);
    if (_dma_verbose == 10) {
	OSIoMesg *mb = &dmaIOMsgBuf;
	    
	PRINTF("%10lld ノーマルＤＭＡ %08x %08x %08x (%d)\n",
	       OS_CYCLES_TO_USEC(osGetTime()),
	       mb->dramAddr, mb->devAddr, mb->size, MQ_GET_COUNT(&_PiMsgQ));
    }
    r = osEPiStartDma(carthandle, &dmaIOMsgBuf, OS_READ);
    if (r != 0) {
	goto ERROR_EXIT;
    }
    osRecvMesg(&dmaFinishMsgQ, NULL, OS_MESG_BLOCK);
    if (_dma_verbose == 10) {
	PRINTF("%10lld ノーマルＤＭＡ END (%d)\n",
	       OS_CYCLES_TO_USEC(osGetTime()),
	       MQ_GET_COUNT(&_PiMsgQ));
    }

ERROR_EXIT:
    osInvalICache(ramaddress, size);
    osInvalDCache(ramaddress, size);
    
    return r;
}


/*
 *
 * サウンドＤＭＡ
 *
 * 返り値(osEPiStartDmaと同じ)
 * -1:PIマネージャが立ち上がっていないかメッセージキューが一杯
 *  0:正常
 */
extern s32
dmaSoundRomHandler(
    OSPiHandle *pihandle,
    OSIoMesg *mb,
    s32 direction
)
{
    s32 r;
    
    assert(pihandle == carthandle);
    assert(direction == OS_READ);
    assert(mb != NULL);

    if (_dma_verbose == 10) {
	PRINTF("%10lld サウンドＤＭＡ %08x %08x %08x (%d)\n",
	       OS_CYCLES_TO_USEC(osGetTime()),
	       mb->dramAddr, mb->devAddr, mb->size, MQ_GET_COUNT(&_PiMsgQ));
    }
#if defined(USE_N64DD)
    if (n64dd_isInitialized()) {
	while (_n64dd_isSoundStopped) {
	    COLOR_ERROR();
	    PRINTF("ディスクが サウンドの DMA を禁止している\n");
	    COLOR_NORMAL();
	    msleep(1000);
	}
    }
#endif /* defined(USE_N64DD) */
    r = osEPiStartDma(pihandle, mb, direction);
    if (r) {
	PRINTF("OOPS!!\n");
    }
    
    return r;
}

/*
 * DISKからの転送
 */
extern void
dmacopy_ddrom_fg(void *dst, u32 src, u32 size)
{
//    int i;
    OSPiHandle *handler;
    OSMesgQueue mq;
    OSMesg m;
    OSIoMesg iom;
    
    handler = osDriveRomInit();
    
    osInvalICache(dst, size);
    osInvalDCache(dst, size);
    
    osCreateMesgQueue(&mq, &m, 1);
    SetupDmaIOMsgBuf(&iom, OS_MESG_PRI_NORMAL, src, dst, size, &mq);
    handler->transferInfo.cmdType = OS_OTHERS;
    osEPiStartDma(handler, &iom, OS_READ);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}

#ifdef DMA_DEBUG_MODE
char        *_dmacopy_file;
unsigned int _dmacopy_line;
static void
dma_fatal(dma_t *dmap, unsigned char *segname,
	  unsigned char *e_msg, unsigned char *j_msg)
{   
    u32 rom = dmap->romadr;
    void *ram = (u8 *)dmap->dstptr;
    u32 size = dmap->dstsiz;
    char s1[80], s2[80];

    BEEP();
    COLOR_RED();
    PRINTF("DMA致命的エラー"
	   "(%s)\n"
	   "ROM:%X RAM:%X SIZE:%X %s\n",
	   j_msg ? j_msg : e_msg ? e_msg : "???",
	   rom, ram, size, segname ? segname : "???");
    if (dmap->_file != NULL) {
	PRINTF("DMA ERROR: %s %d", dmap->_file, dmap->_line);
    } else if (_dmacopy_file != NULL) {
	PRINTF("DMA ERROR: %s %d", _dmacopy_file, _dmacopy_line);
    }
    COLOR_NORMAL();
    
    /*
     * N64画面に表示
     */
    if (dmap->_file != NULL) {
	sprintf(s1, "DMA ERROR: %s %d", dmap->_file, dmap->_line);
    } else if (_dmacopy_file != NULL) {
	sprintf(s1, "DMA ERROR: %s %d", _dmacopy_file, _dmacopy_line);
    } else {
	sprintf(s1, "DMA ERROR: %s", e_msg ? e_msg : "???");
    }
    sprintf(s2, "%07X %08X %X %s", rom, ram, size, segname ? segname : "???");
    fault_HungUpMsg(s1, s2);
}
#else  /* DMA_DEBUG_MODE */
#define dma_fatal(dmap, segname, e_msg, j_msg) HungUp()
#endif /* DMA_DEBUG_MODE */

/*
 * ROMアドレスをセグメント名に変換する
 */
extern unsigned char *
dma_rom2name( u32 rom )
{
#ifndef USE_SEGMENT_NAME_TABLE
    return "??";
#else
    dma_rom_t *p;
    unsigned char **pp;
    
    pp = dma_rom_ad_name;
    for (p = dma_rom_ad; p->rom_b != 0; ++p) {
	if (p->rom_a <= rom && rom < p->rom_b) {
	    return *pp;
	}
	pp ? ++pp : pp;
    }
    return "!?";
#endif /* USE_SEGMENT_NAME_TABLE */
}

/*======================================================================*
 *									*
 *	ＤＭＡ ＲＯＭ テーブル チェック					*
 *									*
 *======================================================================*/
static void
dma_rom_chk(
    dma_t *dmap
)
{
    u32 rom = dmap->romadr;
    void *ram = (u8 *)dmap->dstptr;
    u32 size = dmap->dstsiz;
    u32 realrom;
    u32 realsize;
    char		flg = 0;
    dma_rom_t *p;
    unsigned char **pp;
//    unsigned char *ppp;

#ifdef USE_SEGMENT_NAME_TABLE
    pp = dma_rom_ad_name;
#else
    pp = NULL;
#endif /* USE_SEGMENT_NAME_TABLE */
#define ppp ((pp != NULL) ? *pp : "")
    for (p = dma_rom_ad; p->rom_b != 0; ++p) {

	if (p->rom_a <= rom && rom < p->rom_b) {

	    if (VERBOSE > 2) {
		if (pp == NULL || (my_strcmp(ppp, "kanji") && my_strcmp(ppp, "link_animetion"))) {
		    PRINTF("DMA ROM:%08X RAM:%08X SIZE:%08X %s\n", rom, ram, size, ppp);
		}
	    }
	    
	    if (!is_compressed(p)) { /* 圧縮されていない */

		if (rom + size > p->rom_b) {
		    dma_fatal(dmap, ppp,
			      "Segment Alignment Error",
			      "セグメント境界をまたがって"
			      "ＤＭＡ転送することはできません");
		}
		realrom = p->rom_s + rom - p->rom_a;
		percial_DMA(realrom, ram, size);
		if (VERBOSE > 1) {
		    PRINTF("No Press ROM:%08X RAM:%08X SIZE:%08X\n",
			   realrom, ram, size);
		}
		flg = 1;
		
		break;

	    } else {
		realsize = p->rom_e - p->rom_s;
		realrom = p->rom_s;

		if (p->rom_a != rom) {
		    dma_fatal(dmap, ppp,
			      "Can't Transfer Segment",
			      "圧縮されたセグメントの途中からは"
			      "ＤＭＡ転送することはできません");
		}
		if (size != p->rom_b - p->rom_a) {
		    dma_fatal(dmap, ppp,
			      "Can't Transfer Segment",
			      "圧縮されたセグメントの一部だけを"
			      "ＤＭＡ転送することはできません");
		}
		osSetThreadPri(NULL, PRIORITY_MAIN);
		slidma(realrom, (char *)ram, realsize);
		osSetThreadPri(NULL, PRIORITY_DMAMGR);
		if (VERBOSE > 2) {
		    PRINTF("   Press ROM:%X RAM:%X SIZE:%X\n",
			   realrom, ram, realsize);
		}
		flg = 1;
		break;
	    }
	}
	pp ? ++pp : pp;
    }

    if (flg == 0) {
	if (exist_compressed) {
	    dma_fatal(dmap, NULL,
		      "DATA DON'T EXIST",
		      "該当するデータが存在しません");
	} else {
	    /*
	     * デバッグ時に置いて、どのセグメントも圧縮していない場合に限り、
	     * テーブルに登録していないセグメント領域も転送する
	     */
	    realrom = rom;
	    percial_DMA(realrom, ram, size);
	    if (VERBOSE > 1) {
		PRINTF("No Press ROM:%08X RAM:%08X SIZE:%08X (非公式)\n",
		       realrom, ram, size);
	    }
	}
    }
}

/*
 * ＤＭＡ転送スレッド
 */
static void
dmamgr_proc(void *arg)
{
    OSMesg	osmsg;
    dma_t 	*dmap;
    
    PRINTF("ＤＭＡマネージャスレッド実行開始\n");
    (void)arg;
    
    while (1) {
	/*
	 * ＤＭＡ転送依頼メッセージを待つ
	 */
	(void)osRecvMesg(&dmaEntryMsgQ, &osmsg, OS_MESG_BLOCK);
	if (osmsg == NULL) {
	    break;
	}
	dmap = (dma_t *)osmsg;
	if (VERBOSE > 3) PRINTF("ＤＭＡ登録受付 dmap=%08x\n", dmap);
	dma_rom_chk(dmap);
	/*
	 * メッセージキューが登録されていれば、メッセージを送信する
	 */
	if (dmap->mq != NULL) {
	    if (VERBOSE > 3) {
		PRINTF("osSendMesg: "
		       "dmap=%08x, mq=%08x, m=%08x \n",
		       dmap, dmap->mq, dmap->m);
	    }
	    (void)osSendMesg(dmap->mq, dmap->m, OS_MESG_NOBLOCK);
	}
    }
    
    PRINTF("ＤＭＡマネージャスレッド実行終了\n");
}

/*
 * バックグラウンドで、ＤＭＡ転送する
 * ヘッダ読み込みの登録をする
 *
 * 復帰値
 * -1:パラメータ異常
 * 0:正常受付
 */
extern int
dmacopy_bg(
    dma_t *dmap,
    void *dst,			/* 転送先Ｋ０アドレス（８バイトバウンダリ） */
    u32 src,			/* 転送元ＲＯＭアドレス（２バイトバウンダリ） */
    u32 size,			/* 転送サイズ（２バイトバウンダリ） */
    void *work,			/* 圧縮データ保持用ワーク領域 */
    OSMesgQueue *mq,		/* 完了待ち合わせ用メッセージキュー */
    OSMesg m			/* メッセージ内容 */
)
{
    
    if (VERBOSE > 3) {
	PRINTF("dmacopy_bg(%x, %x, %x, %x, %x, %x, %x)\n",
	       dmap, dst, src, size, work, mq, m);
    }

    (void)work;
    
#if defined(USE_N64DD)
    if (n64dd_function_ok(dmacopy_bg) &&
	n64dd_function_call(dmacopy_bg)(dmap, dst, src, size, work, mq, m)) {
	return 0;
    }
#endif /* defined(USE_N64DD) */
    
#if DEBUG
    if (dst == NULL || (u32)OS_K0_TO_PHYSICAL(dst) + size > osMemSize ||
	src & 1 != 0 || src > MAXROMSIZE || 
	size == 0 || size & 1 != 0) {
	    dma_fatal(dmap, NULL,
		      "ILLIGAL DMA-FUNCTION CALL",
		      "パラメータ異常です");
    }
#endif

    dmap->romadr = src;
    dmap->dstptr = dst;
    dmap->dstsiz = size;
    dmap->pri = OS_MESG_PRI_NORMAL;
    dmap->mq = mq;
    dmap->m = m;

#if DEBUG
    {
	static int flag = 0;

	if (VERBOSE > 0 && flag == 0 && MQ_IS_FULL(&dmaEntryMsgQ)) {
	    flag++;
	    BEEP();
	    COLOR_RED();
	    PRINTF("dmaEntryMsgQが一杯です。キューサイズの再検討をおすすめします。");
	    disp(d, number(dmaEntryMsgBufs));
	    COLOR_NORMAL();
	}
    }
#endif
    (void)osSendMesg(&dmaEntryMsgQ, (OSMesg)dmap, OS_MESG_BLOCK);

    return 0;
}

/*
 * フォアグラウンドで、ＤＭＡ転送する
 */
extern int
dmacopy_fg(void *dst, u32 src, u32 size)
{
    dma_t dma;
    OSMesgQueue mq;
    OSMesg m;
    int r;
    
#ifdef DMA_PERFORMACE_TEST
    OSTime t0, t1;
    float t;
#endif
    
#ifdef DMA_PERFORMACE_TEST
    t0 = osGetTime();
#endif
    
    osCreateMesgQueue(&mq, &m, 1);
    r = dmacopy_bg(&dma, dst, src, size, NULL, &mq, NULL);
    if (r == -1) {
	return r;
    }
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
    
#ifdef DMA_PERFORMACE_TEST
    t1 = osGetTime();
    t = (float)OS_CYCLES_TO_USEC(t1 - t0);
    COLOR_YELLOW();
    PRINTF("DMA:size=%lu bytes  time=%8.3f ms  rate=%8.3f KB/s\n",
	   size, t / 1000.0f, (float)size * 1000.0f * 1000.0f / t / 1024.0f);
    COLOR_NORMAL();
#endif

    return 0;
}

/*
 *  DMAスレッドの作成
 */
extern void
CreateDmaManager( void )
{
    EXTERN_DEFSEG(dmadata);

    /*
     * dmadataの転送
     */
    percial_DMA((u32)_dmadataSegmentRomStart,
		(u8 *)_dmadataSegmentStart,
		_dmadataSegmentRomEnd - _dmadataSegmentRomStart);
    
#if DEBUG
    if (VERBOSE > 0) {
	int i;
	dma_rom_t *p;
	unsigned char **pp;

	PRINTF("dma_rom_ad[]\n");
	p = dma_rom_ad;
#ifdef USE_SEGMENT_NAME_TABLE
	pp = dma_rom_ad_name;
#else
	pp = NULL;
#endif /* USE_SEGMENT_NAME_TABLE */
#define ppp ((pp != NULL) ? *pp : "")
	i = 0;
	exist_compressed = 0;
	while (p->rom_b != 0) {
	    if (is_compressed(p)) {
		exist_compressed = 1;
	    }
	    PRINTF("%3d %08x %08x %08x %08x %08x %c %s\n",
		   i,
		   p->rom_a,
		   p->rom_b,
		   p->rom_s,
		   p->rom_e,
		   p->rom_e ? p->rom_e - p->rom_s : p->rom_b - p->rom_a,
		   (p->rom_e ? p->rom_e - p->rom_s : 0) > 65536 ? '*' : ' ',
		   ppp);
	    i++;
	    p++;
	    pp ? ++pp : pp;
	}
    }
#endif
    
    if ((int)_bootSegmentRomStart != (int)dma_rom_ad[0].rom_b) {
	PRINTF("_bootSegmentRomStart(%08x) != dma_rom_ad[0].rom_b(%08x)\n",
	       _bootSegmentRomStart, dma_rom_ad[0].rom_b);
	HungUp();
    }
    
    osCreateMesgQueue(&dmaEntryMsgQ, dmaEntryMsgBufs, number(dmaEntryMsgBufs));
    StackCheckInit(dmamgr);

    osCreateThread(&dmamgrThread, THREAD_ID_DMAMGR, dmamgr_proc, NULL, dmamgrStack + number(dmamgrStack), PRIORITY_DMAMGR);
    osStartThread(&dmamgrThread);
}

#ifdef DMA_DEBUG_MODE
extern int
__dmacopy_bg( dma_t *dmap, void *dst, u32 src, u32 size, void *work,
	     OSMesgQueue *mq, OSMesg m, char *file, u32 line)
{
    dmap->_file = file;
    dmap->_line = line;
    return dmacopy_bg( dmap, dst, src, size, work, mq, m);
}
extern int
__dmacopy_fg(void *dst, u32 src, u32 size, char *file, u32 line)
{
    dma_t dma, *dmap = &dma;
    OSMesgQueue mq;
    OSMesg m;
    int r;
    
#ifdef DMA_PERFORMACE_TEST
    OSTime t0, t1;
    float t;
#endif
    
    dmap->_file = file;
    dmap->_line = line;

#ifdef DMA_PERFORMACE_TEST
    t0 = osGetTime();
#endif
    
    osCreateMesgQueue(&mq, &m, 1);
    r = dmacopy_bg(&dma, dst, src, size, NULL, &mq, NULL);
    if (r == -1) {
	return r;
    }
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
    
#ifdef DMA_PERFORMACE_TEST
    t1 = osGetTime();
    t = (float)OS_CYCLES_TO_USEC(t1 - t0);
    COLOR_YELLOW();
    PRINTF("DMA:size=%lu bytes  time=%8.3f ms  rate=%8.3f KB/s\n",
	   size, t / 1000.0f, (float)size * 1000.0f * 1000.0f / t / 1024.0f);
    COLOR_NORMAL();
#endif

    return 0;
}
#endif /* DMA_DEBUG_MODE */
