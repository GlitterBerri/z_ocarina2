/*
 * $Id: OLDloadfragment.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * プログラムの動的ロード＆リンク
 *
 * $Log: OLDloadfragment.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.3  2000-09-29 19:59:56+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  2000-09-28 18:38:29+09  hayakawa
 * 大幅変更
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.4  1998-04-01 11:41:15+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.3  1997/09/20  04:46:32  hayakawa
 * LoadFragmentFix3追加
 * LoadFragment3追加
 *
 * Revision 1.2  1997/02/07  10:44:59  hayakawa
 * いろいろ変更
 *
 * Revision 1.1  1996/12/18  01:09:23  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __LOADFRAGMENT_H_
#define __LOADFRAGMENT_H_

typedef char	*MemPtr;
typedef unsigned long	    ulong;

#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

extern ulong  LoadFragmentFix (ulong romStart, ulong romEnd, MemPtr fakebase, MemPtr ramAddr, ulong ramSize);
extern MemPtr LoadFragment    (ulong romStart, ulong romEnd, MemPtr fakebase);
extern ulong  LoadFragmentFix2(ulong romStart, ulong romEnd, MemPtr segStart, MemPtr segEnd, MemPtr ramAddr);
extern MemPtr LoadFragment2   (ulong romStart, ulong romEnd, MemPtr segStart, MemPtr segEnd);
extern ulong  LoadFragmentFix3(ulong romStart, ulong romEnd, MemPtr segStart, MemPtr segEnd, MemPtr ramAddr);
extern MemPtr LoadFragment3   (ulong romStart, ulong romEnd, MemPtr segStart, MemPtr segEnd);
extern ulong  LoadFragmentFix4(ulong romStart, ulong romEnd, ulong relromStart, ulong relromEnd, MemPtr segStart, MemPtr segEnd, MemPtr ramAddr, MemPtr relramAddr);
extern MemPtr LoadFragment4   (ulong romStart, ulong romEnd, ulong relromStart, ulong relromEnd, MemPtr segStart, MemPtr segEnd);

extern int loadfragment_verbose; /* 0:なし 1:致命的 2:エラー 3:情報 */

#if 0
{
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif

#if 0
/* セグメント名でロードするためのマクロ */
#define LOADFRAGMENTFIX(name, ramAddr) 	LoadFragmentFix2((u32)_##name##SegmentRomStart, (u32)_##name##SegmentRomEnd, _##name##SegmentStart, _##name##SegmentEnd, ramAddr)
#define LOADFRAGMENT(name) 		LoadFragment2((u32)_##name##SegmentRomStart, (u32)_##name##SegmentRomEnd, _##name##SegmentStart, _##name##SegmentEnd)
#endif
    
#endif /* __LOADFRAGMENT_H_ */
