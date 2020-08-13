/* $Id: z_kaleido_moji.h,v 1.1.1.1 2003/03/10 22:42:46 tong Exp $ */	
/* $Log: z_kaleido_moji.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:46  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.2  1998-10-28 18:36:00+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.10  1998/06/29 13:19:54  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/03/25  06:08:32  soejima
 * Initial revision
 * $Log追加
 * */


#ifndef INCLUDE_Z_KAKEIDO_MOJI_H
#define INCLUDE_Z_KAKEIDO_MOJI_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif



/************************************************************************
 *									*
 *	カレイド・スコープ 使用文字					*
 *				1997年02月06日(木曜日) 09時00分00秒 JST *
 ************************************************************************/
#if defined(PAL_VERSION)
/* 文字ポインタ */
enum {
    SS0,	/* 数字 */
    SS1,
    SS2,
    SS3,
    SS4,
    SS5,
    SS6,
    SS7,
    SS8,
    SS9,
    AAA,	/* アルファベット */
    AAB,
    AAC,
    AAD,
    AAE,
    AAF,
    AAG,
    AAH,
    AAI,
    AAJ,
    AAK,
    AAL,
    AAM,
    AAN,
    AAO,
    AAP,
    AAQ,
    AAR,
    AAS,
    AAT,
    AAU,
    AAV,
    AAW,
    AAX,
    AAY,
    AAZ,
    AXA,
    AXB,
    AXC,
    AXD,
    AXE,
    AXF,
    AXG,
    AXH,
    AXI,
    AXJ,
    AXK,
    AXL,
    AXM,
    AXN,
    AXO,
    AXP,
    AXQ,
    AXR,
    AXS,
    AXT,
    AXU,
    AXV,
    AXW,
    AXX,
    AXY,
    AXZ,
    SSS,	/* スペース */
    SPD,	/* ─ */
    SPO,	/* ． */
    Moji_Point
};
#else
/* 文字ポインタ */
enum {
    SS0,	/* 数字 */
    SS1,
    SS2,
    SS3,
    SS4,
    SS5,
    SS6,
    SS7,
    SS8,
    SS9,
    HAA,	/* ひらがな */
    HII,
    HUU,
    HEE,
    HOO,
    HKA,
    HKI,
    HKU,
    HKE,
    HKO,
    HSA,
    HSI,
    HSU,
    HSE,
    HSO,
    HTA,
    HTI,
    HTU,
    HTE,
    HTO,
    HNA,
    HNI,
    HNU,
    HNE,
    HNO,
    HHA,
    HHI,
    HHU,
    HHE,
    HHO,
    HMA,
    HMI,
    HMU,
    HME,
    HMO,
    HYA,
    HYU,
    HYO,
    HRA,
    HRI,
    HRU,
    HRE,
    HRO,
    HWA,
    HWO,
    HNN,
    HXA,
    HXI,
    HXU,
    HXE,
    HXO,
    HXTU,
    HXYA,
    HXYU,
    HXYO,
    HGA,
    HGI,
    HGU,
    HGE,
    HGO,
    HZA,
    HZI,
    HZU,
    HZE,
    HZO,
    HDA,
    HDI,
    HDU,
    HDE,
    HDO,
    HBA,
    HBI,
    HBU,
    HBE,
    HBO,
    HPA,
    HPI,
    HPU,
    HPE,
    HPO,
    KAA,	/* カタカナ */
    KII,
    KUU,
    KEE,
    KOO,
    KKA,
    KKI,
    KKU,
    KKE,
    KKO,
    KSA,
    KSI,
    KSU,
    KSE,
    KSO,
    KTA,
    KTI,
    KTU,
    KTE,
    KTO,
    KNA,
    KNI,
    KNU,
    KNE,
    KNO,
    KHA,
    KHI,
    KHU,
    KHE,
    KHO,
    KMA,
    KMI,
    KMU,
    KME,
    KMO,
    KYA,
    KYU,
    KYO,
    KRA,
    KRI,
    KRU,
    KRE,
    KRO,
    KWA,
    KWO,
    KNN,
    KXA,
    KXI,
    KXU,
    KXE,
    KXO,
    KXTU,
    KXYA,
    KXYU,
    KXYO,
    KGA,
    KGI,
    KGU,
    KGE,
    KGO,
    KZA,
    KZI,
    KZU,
    KZE,
    KZO,
    KDA,
    KDI,
    KDU,
    KDE,
    KDO,
    KBA,
    KBI,
    KBU,
    KBE,
    KBO,
    KPA,
    KPI,
    KPU,
    KPE,
    KPO,
    KVI,
    AAA,	/* アルファベット */
    AAB,
    AAC,
    AAD,
    AAE,
    AAF,
    AAG,
    AAH,
    AAI,
    AAJ,
    AAK,
    AAL,
    AAM,
    AAN,
    AAO,
    AAP,
    AAQ,
    AAR,
    AAS,
    AAT,
    AAU,
    AAV,
    AAW,
    AAX,
    AAY,
    AAZ,
    AXA,
    AXB,
    AXC,
    AXD,
    AXE,
    AXF,
    AXG,
    AXH,
    AXI,
    AXJ,
    AXK,
    AXL,
    AXM,
    AXN,
    AXO,
    AXP,
    AXQ,
    AXR,
    AXS,
    AXT,
    AXU,
    AXV,
    AXW,
    AXX,
    AXY,
    AXZ,
    SSS,	/* スペース */
    ARR,	/* → */
    SPA,	/* ？ */
    SPB,	/* ！ */
    SPC,	/* ： */
    SPD,	/* ─ */
    SPF,	/* （ */
    SPG,	/* ） */
    SPJ,	/* ゛ */
    SPK,	/* ゜ */
    SPN,	/* ， */
    SPO,	/* ． */
    SPV,	/* ／ */
    G00,	/* 英 */
    G01,	/* 数 */
    G02,	/* 戻 */
    G03,	/* 決 */
    G04,	/* 定 */
    Moji_Point
};
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_kakeido_moji.h end ***/
