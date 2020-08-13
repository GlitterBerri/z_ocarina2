/*
 * $Id: math64_gcc.h,v 1.1 2003/03/14 03:27:05 tong Exp $
 *
 * gcc専用math
 *
 * $Log: math64_gcc.h,v $
 * Revision 1.1  2003/03/14 03:27:05  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:07:07  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998-10-22 20:18:25+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.1  1997-04-09 19:14:17+09  hayakawa
 * Initial revision
 *
 */

#ifndef __GNUC__
#error このプログラムは gcc でコンパイルしてください
#endif

				/* ベースアセンブラ命令 */
#define ___asm_t1_t2(opcode, x, type1, type2)       \
	({ type1 __value; type2 __arg = (x);   \
           asm (#opcode " %0,%1": "=f" (__value): "f" (__arg));  \
           __value; })
#define ___asm_t(opcode, x, type) ___asm_t1_t2(opcode, x, type, type)
#define ___asm_s(opcode, x)   ___asm_t(opcode, x, float)
#define ___asm_d(opcode, x)   ___asm_t(opcode, x, double)
#define ___asm_w_s(opcode, x) ___asm_t1_t2(opcode, x, float, float)
#define ___asm_w_d(opcode, x) ___asm_t1_t2(opcode, x, float, double)
#define ___asm_s_w(opcode, x) ___asm_t1_t2(opcode, x, float, float)
#define ___asm_d_w(opcode, x) ___asm_t1_t2(opcode, x, double, float)
#define ___asm_i_s(opcode, x)       \
	({ int __value; float __arg = (x);   \
           asm (#opcode" %0, %1": "=r" (__value): "f" (__arg));  \
           __value; })

				/* 単独アセンブラ命令 */
#define ___abs_s(x)     ___asm_s(abs.s, x)
#define ___abs_d(x)     ___asm_d(abs.d, x)
#define ___sqrt_s(x)    ___asm_s(sqrt.s, x)
#define ___sqrt_d(x)    ___asm_d(sqrt.d, x)
#define ___floor_w_s(x) ___asm_w_s(floor.w.s, x)
#define ___floor_w_d(x) ___asm_w_d(floor.w.d, x)
#define ___ceil_w_s(x)  ___asm_w_s(ceil.w.s, x)
#define ___ceil_w_d(x)  ___asm_w_d(ceil.w.d, x)
#define ___trunc_w_s(x) ___asm_w_s(trunc.w.s, x)
#define ___trunc_w_d(x) ___asm_w_d(trunc.w.d, x)
#define ___round_w_s(x) ___asm_w_s(round.w.s, x)
#define ___round_w_d(x) ___asm_w_d(round.w.d, x)
#define ___cvt_s_w(x) 	___asm_s_w(cvt.s.w, x)
#define ___cvt_d_w(x) 	___asm_d_w(cvt.d.w, x)
#define ___mfc1(x) 	___asm_i_s(mfc1, x)

				/* 絶対値 */
#define ___ffabs(x) 	___abs_s(x)
#define ___fabs(x) 	___abs_d(x)

				/* 平方根 */
#define ___fsqrt(x) 	___sqrt_s(x)
#define ___sqrt(x) 	___sqrt_d(x)

				/* −∞方向に丸める */
#define ___ffloor(x) 	___cvt_s_w(___floor_w_s(x))
#define ___floor(x) 	___cvt_d_w(___floor_w_d(x))
#define ___iffloor(x) 	___mfc1(___floor_w_s(x))
#define ___ifloor(x) 	___mfc1(___floor_w_d(x))

				/* ＋∞方向に丸める */
#define ___fceil(x) 	___cvt_s_w(___ceil_w_s(x))
#define ___ceil(x) 	___cvt_d_w(___ceil_w_d(x))
#define ___ifceil(x) 	___mfc1(___ceil_w_s(x))
#define ___iceil(x) 	___mfc1(___ceil_w_d(x))

				/* ０方向へ丸める */
#define ___ftrunc(x) 	___cvt_s_w(___trunc_w_s(x))
#define ___trunc(x) 	___cvt_d_w(___trunc_w_d(x))
#define ___iftrunc(x) 	___mfc1(___trunc_w_s(x))
#define ___itrunc(x) 	___mfc1(___trunc_w_d(x))

				/* 近い整数に丸める */
#define ___fround(x) 	___cvt_s_w(___round_w_s(x))
#define ___round(x) 	___cvt_d_w(___round_w_d(x))
#define ___ifround(x) 	___mfc1(___round_w_s(x))
#define ___iround(x) 	___mfc1(___round_w_d(x))

				/* 小数部分取り出し */
#define ___fdecimal(x) 	({float  __xarg = (x); __xarg - ___ftrunc(__xarg);})
#define ___decimal(x) 	({double __xarg = (x); __xarg -  ___trunc(__xarg);})

				/* 否定的論理和 */
#define ___nor(x1, x2) \
	({ int __value; int __rs = (x1); int __rt = (x2);   \
           asm ("nor %0,%1,%2": "=r" (__value): "r" (__rs), "r" (__rt));  \
           __value; })
