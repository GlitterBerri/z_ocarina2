/*
 * $Id: OLDu64macro.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * ６４マクロ
 * 注意
 * 幾つかのマクロでは、グローバル変数に依存しています
 * SegmentBaseAddress:SetSegment*, GetSegment*, SEGMENT_TO_*, *_TO_SEGMENT
 * SegmentRomStart:SEGMENT_TO_ROM
 * IdentityMtx:g*SPPushMatrix,g*SPLoadIdentity
 *
 * $Log: OLDu64macro.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.2  1999-04-07 15:49:45+09  hayakawa
 * gbi関連のマクロをu64newgbi.hに移動
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.38  1998-08-31 20:07:58+09  hayakawa
 * G_RM_ZB_OPA_SURF_FOGのマクロ修正
 *
 * Revision 1.37  1998-08-28 13:33:31+09  hayakawa
 * RM_*_ZO_のマクロを整理整頓
 *
 * Revision 1.36  1998-08-03 22:07:48+09  hayakawa
 * RM_ZU_XLU_SURF追加
 *
 * Revision 1.35  1998-07-22 22:33:46+09  hayakawa
 * レンダーモードを追加
 *
 * Revision 1.34  1998-07-09 17:32:40+09  hayakawa
 * 今後 INTERR はサポートしないようにします
 * フェードアウトマクロはサポートを中止します
 * g[s]DPSetOtherModeがＳＰに反映する機能を利用するようにした→gbiの数が変化
 * g[s]SPSetOtherModeHLのサポートを中止します
 * 単位変換の追加
 * os.hのマクロの一部をインライン関数で置き換え
 *
 * Revision 1.33  1998-06-09 16:39:33+09  hayakawa
 * F3DEX_GBI_2に対応（のはず）
 *
 * Revision 1.32  1998-05-08 15:10:58+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.31  1998-05-08 15:08:41+09  hayakawa
 * RM_AA_ZO_OPA_SURF追加
 *
 * Revision 1.30  1998-04-02 18:06:03+09  hayakawa
 * 実質変わらず
 *
 * Revision 1.29  1998/03/05  08:29:18  hayakawa
 * RM_ZO_CLR_SURF追加
 * IdentityMtx関係を変更
 *
 * Revision 1.28  1997/11/10  13:54:15  hayakawa
 * RM_RA_ZB_OPA_SURF_FOGが間違っていた
 *
 * Revision 1.27  1997/09/27  07:13:23  hayakawa
 * マクロ追加
 *
 * Revision 1.26  1997/09/20  04:45:24  hayakawa
 * 定数追加
 * RM_AA_ZU_XLU_SURF追加
 * RM_AA_ZO_XLU_SURF追加
 * g*SP2Triangles追加
 * g*SP1Quadrangle追加
 * makeVtx*修正
 *
 * Revision 1.25  1997/08/28  10:35:06  hayakawa
 * 過去の過ち（消す）
 *
 * Revision 1.24  1997/06/13  10:55:47  hayakawa
 * xGetSegmentK0のキャストが不適切だった
 *
 * Revision 1.23  1997/06/13  06:30:23  hayakawa
 * コンバインモードレンダーモード補充
 * ターボマイクロコード関係削除
 * makeVtxTC、makeVtxOB定義追加
 *
 * Revision 1.22  1997/04/09  10:06:23  hayakawa
 * RM_[ZB_]XLU_TEX_EDGEのカバレッジが間違っていた
 *
 * Revision 1.21  1997/03/05  05:32:52  hayakawa
 * モードの追加整理
 * ＤＭＡ転送削除
 *
 * Revision 1.20  1997/02/07  10:40:25  hayakawa
 * マクロ追加
 *
 * Revision 1.19  1996/11/26  10:18:37  hayakawa
 * グローバル変数に依存している
 *
 * Revision 1.18  1996/11/21  06:40:41  hayakawa
 * いろいろ変更
 *
 * Revision 1.17  1996/10/29  12:47:18  hayakawa
 * 高速gbiマクロを追加
 *
 * Revision 1.16  1996/10/20  09:18:56  hayakawa
 * DMACOPY変更
 *
 * Revision 1.15  1996/10/14  10:45:23  hayakawa
 * ヘッダ変更
 *
 */

#ifndef __U64MACRO_H_
#define __U64MACRO_H_

#include "ultra64.h"

#include "u64newgbi.h"		/* 以前このヘッダにあった定義 */

/*
 * ウルトラ６４に関係のあるマクロなどの定義
 */

/*
 * プロジェクトのヘッダに持っていった方がいいかも
 */
#define	L_SCREEN_WD	320		/* ローレゾ画面の横サイズ（ドット）  */
#define	L_SCREEN_HT	240		/* ローレゾ画面の縦サイズ（ドット） */
#define	H_SCREEN_WD	640		/* ハイレゾ画面の横サイズ（ドット）  */
#define	H_SCREEN_HT	480		/* ハイレゾ画面の縦サイズ（ドット） */
#ifndef SCREEN_WD
#define	SCREEN_WD	L_SCREEN_WD
#endif
#ifndef SCREEN_HT
#define	SCREEN_HT	L_SCREEN_HT
#endif

#define TMEM_SIZE_FULL 4096	/* TMEMのサイズ（バイト） */
#define TMEM_SIZE_HALF 2048	/* ＣＩ用TMEMのサイズの半分（バイト） */


/*
 * gbi.h に追加するマクロ
 */
/* 32bitカラー作成 */
#define	GRGBA8888(r, g, b, a)	((r) << 24 | (g) << 16 | (b) << 8 | (a))

/*
 * セグメント名からセグメントのサイズを返す
 * 予め、セグメントシンボルの定義をしておく必要がある
 */
#define SEGMENT_ROM_SIZE(name) \
    (u32)(_##name##SegmentRomEnd - _##name##SegmentRomStart)
#define SEGMENT_SIZE(name) \
    (u32)(_##name##SegmentEnd - _##name##SegmentStart)

/*
 * spec file で定義されるセグメントシンボルの定義
 */
				/* コードセグメント用 */
#define EXTERN_DEFSEG_CODE(name) \
    extern char \
    _##name##SegmentStart[], \
    _##name##SegmentTextStart[], \
    _##name##SegmentTextEnd[], \
    _##name##SegmentDataStart[], \
    _##name##SegmentDataEnd[], \
    _##name##SegmentBssStart[], \
    _##name##SegmentBssEnd[], \
    _##name##SegmentEnd[], \
    _##name##SegmentRomStart[], \
    _##name##SegmentRomEnd[]
				/* データセグメント用 */
#define EXTERN_DEFSEG_DATA(name) \
    extern char \
    _##name##SegmentStart[], \
    _##name##SegmentEnd[], \
    _##name##SegmentRomStart[], \
    _##name##SegmentRomEnd[]
				/* ＲＡＷデータ用 */
#define EXTERN_DEFSEG_RAW(name) \
    extern char \
    _##name##SegmentRomStart[], \
    _##name##SegmentRomEnd[]
    
#define EXTERN_DEFSEG(name) EXTERN_DEFSEG_CODE(name)

/*
 * セグメントテーブルバッファを登録する(gsSegmentと同じ形)
 */
/* 内部テーブルにセグメント先頭アドレスをセット */
#define xSetSegment(segtbl, number, base) \
    	((void)((segtbl)[number] = (u32)(base)))
#define SetSegment(number, base) \
    	xSetSegment(SegmentBaseAddress, number, base)
/* 内部テーブルにセグメント先頭アドレスをセット(K0アドレス) */
#define xSetSegmentK0(segtbl, number, base) \
    	xSetSegment(segtbl, number, OS_K0_TO_PHYSICAL(base))
#define SetSegmentK0(number, base) \
    	SetSegment(number, OS_K0_TO_PHYSICAL(base))
/* 内部テーブルからセグメント先頭アドレスをゲット */
#define xGetSegment(segtbl, number) \
    	((u32)((segtbl)[number]))
#define GetSegment(number) \
    	xGetSegment(SegmentBaseAddress, number)
/* 内部テーブルからセグメント先頭アドレスをゲット(K0アドレス) */
#define xGetSegmentK0(segtbl, number) \
    	((void *)OS_PHYSICAL_TO_K0(xGetSegment(segtbl, number)))
#define GetSegmentK0(number) \
    	xGetSegmentK0(SegmentBaseAddress, number)

#if 0
    inline void *PointerConvert(void *type, void *value) { return (void *)value; }
    inline u8 *PointerConvert(u8 *type, void *value) { return (u8 *)value; }
    inline s8 *PointerConvert(s8 *type, void *value) { return (s8 *)value; }
    inline u16 *PointerConvert(u16 *type, void *value) { return (u16 *)value; }
    inline s16 *PointerConvert(s16 *type, void *value) { return (s16 *)value; }
    inline u32 *PointerConvert(u32 *type, void *value) { return (u32 *)value; }
    inline s32 *PointerConvert(s32 *type, void *value) { return (s32 *)value; }
    inline u64 *PointerConvert(u64 *type, void *value) { return (u64 *)value; }
    inline s64 *PointerConvert(s64 *type, void *value) { return (s64 *)value; }
    inline Gfx *PointerConvert(Gfx *type, void *value) { return (Gfx *)value; }
#endif
    
/*
 * セグメントアドレスをROMアドレスに変換する
 */
#define xSEGMENT_TO_ROM(segtbl, addr) \
    	((segtbl)[SEGMENT_NUMBER(addr)] + (unsigned long)SEGMENT_OFFSET(addr))
#define SEGMENT_TO_ROM(addr) \
    	xSEGMENT_TO_ROM(SegmentRomStart, addr)
    
/*
 * セグメントアドレスを物理アドレスに変換する
 */
#define xSEGMENT_TO_PHYSICAL(segtbl, addr) \
    	((segtbl)[SEGMENT_NUMBER(addr)] + (unsigned long)SEGMENT_OFFSET(addr))
#define SEGMENT_TO_PHYSICAL(addr) \
    	xSEGMENT_TO_PHYSICAL(SegmentBaseAddress, addr)
    
/*
 * セグメントアドレスをKSEG0アドレスに変換する
 */
#define xSEGMENT_TO_KSEG0(segtbl, addr) \
     	((void *)OS_PHYSICAL_TO_K0(xSEGMENT_TO_PHYSICAL(segtbl, addr)))
#define SEGMENT_TO_KSEG0(addr) \
    	xSEGMENT_TO_KSEG0(SegmentBaseAddress, addr)
    
/*
 * セグメント番号＋物理アドレスをセグメントアドレスに変換する
 */
#define xPHYSICAL_TO_SEGMENT(segtbl, num, addr) \
	((void *)SEGMENT_ADDR((num), ((addr) - (segtbl)[num])))
#define PHYSICAL_TO_SEGMENT(num, addr) \
    	xPHYSICAL_TO_SEGMENT(SegmentBaseAddress, num, addr)
    
/*
 * セグメント番号＋KSEG0アドレスをセグメントアドレスに変換する
 */
#define xKSEG0_TO_SEGMENT(segtbl, num, addr) \
    	xPHYSICAL_TO_SEGMENT(segtbl, num, OS_K0_TO_PHYSICAL(addr))
#define KSEG0_TO_SEGMENT(num, addr) \
    	xKSEG0_TO_SEGMENT(SegmentBaseAddress, num, addr)

#if 0
/*
 * 仮想アドレスを物理アドレスに変換する
 */
#define VIRTUAL_TO_PHYSICAL(addr) \
    	osVirtualToPhysical(addr)
    
/*
 * 物理アドレスを仮想アドレスに変換する
 */
#define PHYSICAL_TO_VIRTUAL(addr) \
    	osPhysicalToVirtual(addr)
    
/*
 * 仮想アドレスをKSEG0アドレスに変換する
 */
#define VIRTUAL_TO_KSEG0(addr) \
    	OS_PHYSICAL_TO_K0(OS_K0_TO_PHYSICAL(addr))

#endif

/*
 * KSEG0アドレスをKSEG1アドレスに変換する
 */
#if 0
#define KSEG0_TO_KSEG1(addr) \
    	((void *)((unsigned int)(addr) | 0xa0000000))
#else
#define KSEG0_TO_KSEG1(addr) \
    	(void *)(((u32)(addr) + 0x20000000))
#endif
    
/*
 * KSEG1アドレスをKSEG0アドレスに変換する
 */
#define KSEG1_TO_KSEG0(addr) \
    	(void *)(((u32)(addr) - 0x20000000))

/*
 * KSEG0   void *
 * Segment void *
 * Virtual void *
 * Physical unsigned int
 * ROM     unsigned long
 */
    
/*
 * セグメントテーブルバッファ宣言
 */
extern unsigned long SegmentBaseAddress[NUM_SEGMENTS];
extern const unsigned long SegmentRomStart[NUM_SEGMENTS]; /* SEGMENT_TO_ROM */


/* 単位変換の追加 */
#define OS_MSEC_TO_CYCLES(n)	(((u64)(n)*(OS_CPU_COUNTER))/1000LL)
#define OS_CYCLES_TO_MSEC(c)	(((u64)(c)*1000LL)/(OS_CPU_COUNTER))
#define OS_SEC_TO_CYCLES(n)	((u64)(n)*(OS_CPU_COUNTER))
#define OS_CYCLES_TO_SEC(c)	((u64)(c)/(OS_CPU_COUNTER))

/* os.hのマクロの一部をインライン関数で置き換え */
#ifdef _LANGUAGE_C_PLUS_PLUS

#undef OS_K0_TO_PHYSICAL
inline u32 OS_K0_TO_PHYSICAL(void *x)
{
    return (u32)(((char *)(x)-0x80000000));
}

#undef OS_K1_TO_PHYSICAL
inline u32 OS_K1_TO_PHYSICAL(void *x)
{
    return (u32)(((char *)(x)-0xa0000000));
}

#undef OS_PHYSICAL_TO_K0
inline void *OS_PHYSICAL_TO_K0(u32 x)
{
    return (void *)(((u32)(x)+0x80000000));
}

#undef OS_PHYSICAL_TO_K1
inline void *OS_PHYSICAL_TO_K1(u32 x)
{
    return (void *)(((u32)(x)+0xa0000000));
}

#endif /* _LANGUAGE_C_PLUS_PLUS */


#endif /* __U64MACRO_H_ */
