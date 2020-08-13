/*
 * $Id: z_std_dma.h,v 2.1 1998/10/22 11:51:48 zelda Exp $
 *
 * ゼルダ６４ の ＤＭＡ
 *
 * $Log: z_std_dma.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.15  1998/10/16 13:05:00  hayakawa
 * *** empty log message ***
 *
 * Revision 1.14  1998-10-03 16:27:38+09  zelda
 * *** empty log message ***
 *
 * Revision 1.13  1998-09-28 17:14:52+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.12  1998-09-18 12:06:18+09  zelda
 * 未テスト危険
 *
 * Revision 1.11  1998-09-17 22:31:57+09  zelda
 * DMA ERROR 時に呼び出し元情報を表示するようにした
 *
 * Revision 1.10  1998-08-08 12:05:17+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.9  1998-07-24 16:17:31+09  hayakawa
 * percial_DMAが復帰値を返すようにした
 *
 * Revision 1.8  1998-07-17 21:35:34+09  hayakawa
 * dmacopy_fg, dmacopy_bg が復帰値を持つようにした
 *
 * Revision 1.7  1998-06-05 16:57:31+09  hayakawa
 * サウンドＤＭＡハンドラ
 *
 * Revision 1.6  1998-04-01 11:46:20+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.5  1998/03/19  13:04:16  komatu
 * *** empty log message ***
 *
 * Revision 1.4  1998/03/12  05:57:52  hayakawa
 * コメント追加
 *
 * Revision 1.3  1998/01/05  02:40:50  hayakawa
 * セグメント宣言をヘッダでやらないようにした（遅くなる）
 * dma_rom_adを別ソースに移動
 *
 * Revision 1.2  1997/08/22  13:48:45  hayakawa
 * szs対応
 *
 * Revision 1.1  1997/08/18  12:43:01  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_STD_DMA_H_
#define _Z_STD_DMA_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "os.h"

#if !defined(FINAL_ROM) /* 責任者：山本雄一 */
#define DMA_DEBUG_MODE 1
#endif
    
/*======================================================================*
 *									*
 *	ＤＭＡ ＤＡＴＡ 構造体						*
 *									*
 *======================================================================*/
typedef struct dma_rom_s {
    u32 rom_a;			/* 仮想ＲＯＭStartアドレス 0:データ無効 */
    u32 rom_b;			/* 仮想ＲＯＭEndアドレス */
    u32 rom_s;			/* 実ＲＯＭStartアドレス */
    u32 rom_e;			/* 実ＲＯＭEndアドレス 0:非圧縮 */
} dma_rom_t;

/*======================================================================*
 *									*
 *	ＤＭＡ ＲＯＭ アドレス テーブル ＤＭＡ 処理			*
 *									*
 *======================================================================*/
/*
 * ＤＭＡ管理構造体
 */
typedef struct dma_s {
    u32		romadr;		/* ROMアドレス */
    void	*dstptr;	/* 転送先アドレス */
    u32		dstsiz;		/* データ格納領域サイズ */
#ifdef DMA_DEBUG_MODE
    char        *_file;		/* 呼び出し元ソースファイル名など */
    u32 	_line;		/* 呼び出し元ソース行番号など */
#else  /* DMA_DEBUG_MODE */
    void	*tmpramptr;	/* 圧縮データ時のワーク領域 */
    u32		tmpramsiz;	/* 圧縮データ時のワーク領域サイズ */
#endif /* DMA_DEBUG_MODE */
    s32		pri;		/* 優先度 */
    OSMesgQueue	*mq;		/* DMA転送終了時にメッセージを送信 */
    OSMesg	m;
} dma_t;

/*
 * ＤＭＡマネージャの作成
 * 以下の関数を使用する前に一度だけ呼び出してください。
 */
extern void CreateDmaManager( void );

/*
 * フォアグランドでＤＭＡ転送する
 * 内部で dmacopy_bg を呼出し、待ち合わせを行っています。
 * 0:正常
 * -1:パラメータ異常
 *
 */
extern int dmacopy_fg(void *dst, u32 src, u32 size);

/*
 * バックグランドでＤＭＡ転送する
 * 転送完了時に mq が NULL でなければ mq に m のメッセージを送信します。
 * szs圧縮データに対応。
 * 0:正常
 * -1:パラメータ異常
 */
extern int
dmacopy_bg(
    dma_t *dmap,		/* 管理構造体。転送完了時までは内容を保持してください */
    void *dst,			/* 転送先ＲＡＭアドレス（８バイトバウンダリ） */
    u32 src,			/* 転送元ＲＯＭアドレス（２バイトバウンダリ） */
    u32 size,			/* 転送サイズ（８の倍数） */
    void *work,			/* NULL固定 */
    OSMesgQueue *mq,		/* 転送完了メッセージ用キュー */
    OSMesg m			/* 転送完了メッセージ */
);

/*
 * DISKからの転送
 */
extern void dmacopy_ddrom_fg(void *dst, u32 src, u32 size);

/*
 * *** 通 常 は 使 用 し な い で く だ さ い。***
 * （ツールデータ転送用に公開しています）
 *
 * 分割しながらＤＭＡ転送する
 *
 * スケジューリングや圧縮やセグメントに関係なく転送します。
 */
extern s32 percial_DMA( u32 romaddress, void *ramaddress, u32 size );

/*
 * サウンドＤＭＡハンドラ
 */
extern s32
dmaSoundRomHandler(
    OSPiHandle *pihandle,
    OSIoMesg *mb,
    s32 direction
);

#ifdef DMA_DEBUG_MODE
#ifndef _Z_STD_DMA_C_
extern int
__dmacopy_bg( dma_t *dmap, void *dst, u32 src, u32 size, void *work,
	     OSMesgQueue *mq, OSMesg m, char *file, u32 line);
extern int
__dmacopy_fg(void *dst, u32 src, u32 size, char *file, u32 line);
#define dmacopy_bg( dmap, dst, src, size, work, mq, m ) \
      __dmacopy_bg( dmap, dst, src, size, work, mq, m, __FILE__, __LINE__ )
#define dmacopy_fg( dst, src, size) \
      __dmacopy_fg( dst, src, size, __FILE__, __LINE__ )
#endif /* _Z_STD_DMA_C_ */
#endif /* DMA_DEBUG_MODE */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
