/*
 * $Id: qrand.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * 高速乱数関数
 *
 * $Log: qrand.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.4  2000-09-28 17:50:07+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.3  1999-10-12 17:56:05+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.2  1999-05-10 17:24:03+09  hayakawa
 * floatの乱数を計算する場合
 * longの乱数の下位23ビットを元に計算していたのを上位23ビットに変更しました。
 * 乱数の下位ビットを利用すると、多くの場合不正確な乱数になってしまいます。
 *
 * 今回はこれに加えて以下の修正をしました
 * ・-0.5 から +0.5 の範囲を返す乱数の追加
 * ・乱数マクロの見直し
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.3  1998-04-01 11:39:43+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1997/11/19  10:26:01  hayakawa
 * sqrand_r、qrand_r、fqrand_r追加
 *
 * Revision 1.1  1997/04/09  10:15:07  hayakawa
 * Initial revision
 *
 */

#ifndef __QRAND_H_
#define __QRAND_H_

#if    (_MIPS_SZLONG != 32)
#error (_MIPS_SZLONG != 32)
#endif

#define QRAND_MAX	ULONG_MAX /* qrandの最大値 */

#define QRAND_MUL	1664525L /* 乱数発生用係数 */
#define QRAND_ADD	1013904223L /* 乱数発生用係数 */

extern unsigned long __qrand_idum; /* 種保存用 */
extern unsigned long __qrand_itemp; /* ワーク用 */

/*
 * マクロバージョン
 */
#define __Qrand()	  (__qrand_idum = QRAND_MUL * __qrand_idum + QRAND_ADD)
#define __Qrand_r(seed_p) (*(seed_p)    = QRAND_MUL * *(seed_p)    + QRAND_ADD)

#define __Sqrand(seed)		 (__qrand_idum = (unsigned long)(seed))
#define __Sqrand_r(seed_p, seed) (*(seed_p)    = (unsigned long)(seed))

#define __Fqrand0(qrand) \
(\
 __qrand_itemp = 0x3f800000 | ((unsigned long)(qrand) >> 9), \
 (*(float *)&__qrand_itemp) \
)
#define __Fqrand01(qrand)	( __Fqrand0(qrand) - 1.0f )
#define __Fqrand02(qrand)	( __Fqrand0(qrand) - 1.5f )
#define __Fqrand()		__Fqrand01(Qrand())
#define __Fqrand2()		__Fqrand02(Qrand())
#define __Fqrand_r(seed_p)	__Fqrand01(Qrand_r(seed_p))
#define __Fqrand2_r(seed_p)	__Fqrand02(Qrand_r(seed_p))

#if !defined(_LANGUAGE_C_PLUS_PLUS)

extern unsigned long qrand(void);
extern void sqrand(unsigned long seed);
extern float fqrand(void);
extern float fqrand2(void);
extern void sqrand_r(unsigned long *seed_p, unsigned long seed);
extern unsigned long qrand_r(unsigned long *seed_p);
extern float fqrand_r(unsigned long *seed_p);
extern float fqrand2_r(unsigned long *seed_p);

#define Qrand()			__Qrand()
#define Qrand_r(seed_p)		__Qrand_r(seed_p)
#define Sqrand(seed)		__Sqrand(seed)
#define Sqrand_r(seed_p, seed)	__Sqrand_r(seed_p, seed)
#define Fqrand()		__Fqrand()
#define Fqrand2()		__Fqrand2()
#define Fqrand_r(seed_p)	__Fqrand_r(seed_p)
#define Fqrand2_r(seed_p)	__Fqrand2_r(seed_p)

#else /* _LANGUAGE_C_PLUS_PLUS */

#define Qrand()			qrand()
#define Qrand_r(seed_p)		qrand_r(seed_p)
#define Sqrand(seed)		sqrand(seed)
#define Sqrand_r(seed_p, seed)	sqrand_r(seed_p, seed)
#define Fqrand()		fqrand()
#define Fqrand2()		fqrand2()
#define Fqrand_r(seed_p)	fqrand_r(seed_p)
#define Fqrand2_r(seed_p)	fqrand2_r(seed_p)

inline unsigned long qrand(void)
{
    return __Qrand();
}

inline void sqrand(unsigned long seed)
{
    __Sqrand(seed);
}

inline float fqrand(void)
{
    return __Fqrand();
}

inline float fqrand2(void)
{
    return __Fqrand2();
}

inline void sqrand_r(unsigned long *seed_p, unsigned long seed)
{
    __Sqrand_r(seed_p, seed);
}

inline unsigned long qrand_r(unsigned long *seed_p)
{
    return __Qrand_r(seed_p);
}

inline float fqrand_r(unsigned long *seed_p)
{
    return __Fqrand_r(seed_p);
}

#endif /* _LANGUAGE_C_PLUS_PLUS */

#endif /* __QRAND_H_ */
