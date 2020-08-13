/*
 * $Id: OLDu64patch.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * ウルトラ６４のＳＧＩのインクルードファイルの不具合に対する修正・追加のパッチ
 * <ultra64.h> のヘッダの不具合（らしきもの）を修正します
 * この内容を、ＳＧＩに報告し、修正してもらうべきでしょう。
 *
 * #include <ultra64.h>
 * #include <u64patch.h>
 * の順に組み込んでください
 *
 * $Log: OLDu64patch.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.18  1999-08-31 15:39:47+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.17  1999-08-31 15:05:24+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.16  1998-07-09 17:24:17+09  hayakawa
 * gSPGeometryModeがultratypes.h に依存しないように
 * gsSPLoadGeometryMode引数の数が間違っている
 *
 * Revision 1.15  1998-04-01 11:36:43+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.14  1998/03/18  02:08:16  hayakawa
 * 2.0iに対応
 *
 * Revision 1.13  1997/12/24  06:55:08  hayakawa
 * fixed v2.0i laterのコメントを付加
 *
 * Revision 1.12  1997/12/24  04:51:50  hayakawa
 * Ｑマイクロコード削除
 * SEGMENT_NUMBERのパッチが正しく当たらないのを修正
 *
 * Revision 1.11  1997/04/09  12:01:57  hayakawa
 * OS_NSEC_TO_CYCLESなどのバグとり（バグが出にくくした）
 * SEGMENT_NUMBERマクロバグ修正
 *
 * Revision 1.10  1997/03/28  00:45:44  hayakawa
 * FTOFRAC8追加
 * SEGMENT_NUMBER高速化
 *
 * Revision 1.9  1997/03/05  10:52:01  hayakawa
 * gSPModifyVertex削除
 * 括弧の位置を修正
 *
 * Revision 1.8  1996/12/03  01:24:30  hayakawa
 * *** empty log message ***
 *
 * Revision 1.7  1996/10/01  05:32:43  hayakawa
 * OS_MSEC_TO_CYCLES,OS_SEC_TO_CYCLESの追加
 * Ｑマイクロコードに対応
 *
 */

#ifndef __U64PATCH_H_
#define __U64PATCH_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif


#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* __U64PATCH_H_ */
