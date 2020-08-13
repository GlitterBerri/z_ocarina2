/*
 * $Id: OLDdebug.h,v 1.1 2003/03/14 03:27:04 tong Exp $
 *
 * デバッグ用
 *
 * $Log: OLDdebug.h,v $
 * Revision 1.1  2003/03/14 03:27:04  tong
 * copied SRD dir from old tree to new tree.
 *
 * Revision 1.1.1.1  2003/01/17 21:06:42  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.15  2001-02-07 17:05:34+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.14  2000-08-03 13:43:35+09  hayakawa
 * マクロ修正
 *
 * Revision 2.13  2000-08-03 10:50:43+09  hayakawa
 * C++のワーニングに対応
 *
 * Revision 2.12  2000-06-07 11:29:31+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.11  2000-06-07 10:59:21+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.10  2000-06-07 10:50:09+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.9  2000-06-07 10:22:50+09  hayakawa
 * C++用訂正
 *
 * Revision 2.8  2000-04-24 09:55:51+09  hayakawa
 * PRINTF数字マクロ
 *
 * Revision 2.7  2000-04-13 11:43:14+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.6  1999-05-13 12:02:13+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.5  1999-05-13 12:00:12+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.4  1999-05-13 11:54:57+09  hayakawa
 * *** empty log message ***
 *
 * Revision 2.3  1999-05-13 10:18:12+09  hayakawa
 * 無効なPRINTFでワーニングが出ないようにした
 *
 * Revision 2.2  1999-04-07 15:50:45+09  hayakawa
 * PRINTFマクロをgccでエラーにならないように変更
 * ただし、引数に副作用を持つ式を書いた場合の動作は保証されない
 *
 * Revision 2.1  1998-10-22 20:19:27+09  hayakawa
 * ＲＯＭ出しバージョン
 *
 * Revision 1.35  1998-10-18 21:46:02+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.34  1998-09-10 13:18:53+09  hayakawa
 * DBG_ARRAY追加
 *
 * Revision 1.33  1998-08-03 22:09:18+09  hayakawa
 * dbg_here,DBG_HERE,DBG_DISP追加
 *
 * Revision 1.32  1998-07-23 11:30:24+09  hayakawa
 * NOUSE_PRINTFの判定を間違えた
 *
 * Revision 1.31  1998-07-22 22:04:06+09  hayakawa
 * NOUSE_PRINTFが無視されていた
 * DBG_RANGE_I追加
 * その他いろいろ
 *
 * Revision 1.30  1998-07-20 17:09:36+09  hayakawa
 * カッコの対応がおかしかった
 *
 * Revision 1.29  1998-07-20 11:53:16+09  hayakawa
 * constつけた
 *
 * Revision 1.28  1998-07-20 11:44:07+09  hayakawa
 * 新形式へ
 *
 * Revision 1.27  1998-07-09 22:08:22+09  hayakawa
 * コンパイルエラー修正
 *
 * Revision 1.26  1998-07-09 15:21:40+09  hayakawa
 * マクロをif 文で使えるようにした
 *
 * Revision 1.25  1998-04-23 09:33:07+09  hayakawa
 * T() なんてふざけた名前の define を消し去った
 *
 * Revision 1.24  1998-04-01 11:42:19+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.23  1997/11/19  09:40:08  hayakawa
 * COLORマクロ追加
 *
 * Revision 1.22  1997/09/20  03:08:21  hayakawa
 * DBG_BOUND追加
 *
 * Revision 1.21  1997/04/09  10:02:39  hayakawa
 * ROM_VERSIONを見るようにした
 * DBG_PTRのチェックにosMemSizeを使うようにした
 *
 * Revision 1.20  1997/02/07  10:55:55  hayakawa
 * BATCH
 *
 * Revision 1.19  1996/12/18  01:00:51  hayakawa
 * 移植性のためにコントローラのヘッダ読み込みを廃止した
 *
 * Revision 1.18  1996/12/02  05:35:23  hayakawa
 * HungUp_func、Reset関数の追加
 *
 * Revision 1.17  1996/11/26  10:14:08  hayakawa
 * コントローラで、デバッグコントロールできるようにした
 * ハングアップ用の対応
 *
 * Revision 1.16  1996/11/21  06:21:32  hayakawa
 * XPRINTF、xdispの追加
 *
 * Revision 1.15  1996/10/29  12:45:35  hayakawa
 * DEBUG モードと NOUSE_PRINTF をわけた
 * ワーニング抑止
 *
 * Revision 1.14  1996/10/20  09:10:06  hayakawa
 * _LANGUAGE_C_PLUS_PLUS を __cplusplus に変更
 *
 * Revision 1.13  1996/10/01  05:26:47  hayakawa
 * ポインタがＫ０セグメント中に存在するかどうかのマクロを修正
 *
 */

#ifndef __DEBUG_H_
#define __DEBUG_H_

#include "u64types.h"		/* size_t */

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#define __DBG_NOP()		((void)0) /* 何もしないマクロ */

/* __DBG_NOP_PRINTF(...) 何もしないprintf */
#if defined(_LANGUAGE_C_PLUS_PLUS)
    extern "C++" {
//	inline void __dbg_nop_prtintf_cpp() { return; }
	inline void __dbg_nop_prtintf_cpp(char * ...) { return; }
    }
#define __DBG_NOP_PRINTF	__dbg_nop_prtintf_cpp
#elif defined(__GNUC__) || !defined(PRINTF_with_Warning_609)
#define __DBG_NOP_PRINTF	while (0) osSyncPrintf
#else  /* defined(__GNUC__) || !defined(PRINTF_with_Warning_609) */
#define __DBG_NOP_PRINTF(x) __DBG_NOP()	/* 引数が２つ以上あると Warning 609 が出てしまう */
#endif /* defined(__GNUC__) || !defined(PRINTF_with_Warning_609) */
    
#define __DBG_NOP_PRINTF0(x)						__DBG_NOP()
#define __DBG_NOP_PRINTF1(x, a1)					(void)(a1)
#define __DBG_NOP_PRINTF2(x, a1, a2)					(void)((void)(a1), (a2))
#define __DBG_NOP_PRINTF3(x, a1, a2, a3)				(void)((void)((void)(a1), (a2)), (a3))
#define __DBG_NOP_PRINTF4(x, a1, a2, a3, a4)				(void)((void)((void)((void)(a1), (a2)), (a3)), (a4))
#define __DBG_NOP_PRINTF5(x, a1, a2, a3, a4, a5)			(void)((void)((void)((void)((void)(a1), (a2)), (a3)), (a4)), (a5))
#define __DBG_NOP_PRINTF6(x, a1, a2, a3, a4, a5, a6)			(void)((void)((void)((void)((void)((void)(a1), (a2)), (a3)), (a4)), (a5)), (a6))
#define __DBG_NOP_PRINTF7(x, a1, a2, a3, a4, a5, a6, a7)		(void)((void)((void)((void)((void)((void)((void)(a1), (a2)), (a3)), (a4)), (a5)), (a6)), (a7))
#define __DBG_NOP_PRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)		(void)((void)((void)((void)((void)((void)((void)((void)(a1), (a2)), (a3)), (a4)), (a5)), (a6)), (a7)), (a8))
#define __DBG_NOP_PRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)	(void)((void)((void)((void)((void)((void)((void)((void)((void)(a1), (a2)), (a3)), (a4)), (a5)), (a6)), (a7)), (a8)), (a9))

extern void Reset( void );		/* リセット */

#ifndef Defined_fault_HungUp
/* ハングアップ */
extern void _dbg_hungup( const char *const file, const int line );
#define HungUp() 	_dbg_hungup(__FILE__, __LINE__)
#endif /* Defined_fault_HungUp */

    
#if !NOUSE_PRINTF

#define PRINTF		osSyncPrintf
#define ZPRINTF(args)				\
do {						\
    OSPri mythread_pri = osGetThreadPri(NULL);	\
    osSetThreadPri(NULL, OS_PRIORITY_APPMAX);	\
    PRINTF args;				\
    osSetThreadPri(NULL, mythread_pri);		\
} while (0)
    
#define PRINTF0(x)                                    	PRINTF(x)                                    
#define PRINTF1(x, a1)                                	PRINTF(x, a1)                                
#define PRINTF2(x, a1, a2)                            	PRINTF(x, a1, a2)                            
#define PRINTF3(x, a1, a2, a3)                        	PRINTF(x, a1, a2, a3)                        
#define PRINTF4(x, a1, a2, a3, a4)                    	PRINTF(x, a1, a2, a3, a4)                    
#define PRINTF5(x, a1, a2, a3, a4, a5)                	PRINTF(x, a1, a2, a3, a4, a5)                
#define PRINTF6(x, a1, a2, a3, a4, a5, a6)            	PRINTF(x, a1, a2, a3, a4, a5, a6)            
#define PRINTF7(x, a1, a2, a3, a4, a5, a6, a7)        	PRINTF(x, a1, a2, a3, a4, a5, a6, a7)        
#define PRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)    	PRINTF(x, a1, a2, a3, a4, a5, a6, a7, a8)    
#define PRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)	PRINTF(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)
#define ZPRINTF0(x)                                    	ZPRINTF(x)                                    
#define ZPRINTF1(x, a1)                                	ZPRINTF(x, a1)                                
#define ZPRINTF2(x, a1, a2)                            	ZPRINTF(x, a1, a2)                            
#define ZPRINTF3(x, a1, a2, a3)                        	ZPRINTF(x, a1, a2, a3)                        
#define ZPRINTF4(x, a1, a2, a3, a4)                    	ZPRINTF(x, a1, a2, a3, a4)                    
#define ZPRINTF5(x, a1, a2, a3, a4, a5)                	ZPRINTF(x, a1, a2, a3, a4, a5)                
#define ZPRINTF6(x, a1, a2, a3, a4, a5, a6)            	ZPRINTF(x, a1, a2, a3, a4, a5, a6)            
#define ZPRINTF7(x, a1, a2, a3, a4, a5, a6, a7)        	ZPRINTF(x, a1, a2, a3, a4, a5, a6, a7)        
#define ZPRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)    	ZPRINTF(x, a1, a2, a3, a4, a5, a6, a7, a8)    
#define ZPRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)	ZPRINTF(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)

#else  /* !NOUSE_PRINTF */
    
#define PRINTF						__DBG_NOP_PRINTF
#define ZPRINTF						__DBG_NOP_PRINTF

#define PRINTF0(x)                                    	__DBG_NOP_PRINTF0(x)                                    
#define PRINTF1(x, a1)                                	__DBG_NOP_PRINTF1(x, a1)                                
#define PRINTF2(x, a1, a2)                            	__DBG_NOP_PRINTF2(x, a1, a2)                            
#define PRINTF3(x, a1, a2, a3)                        	__DBG_NOP_PRINTF3(x, a1, a2, a3)                        
#define PRINTF4(x, a1, a2, a3, a4)                    	__DBG_NOP_PRINTF4(x, a1, a2, a3, a4)                    
#define PRINTF5(x, a1, a2, a3, a4, a5)                	__DBG_NOP_PRINTF5(x, a1, a2, a3, a4, a5)                
#define PRINTF6(x, a1, a2, a3, a4, a5, a6)            	__DBG_NOP_PRINTF6(x, a1, a2, a3, a4, a5, a6)            
#define PRINTF7(x, a1, a2, a3, a4, a5, a6, a7)        	__DBG_NOP_PRINTF7(x, a1, a2, a3, a4, a5, a6, a7)        
#define PRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)    	__DBG_NOP_PRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)    
#define PRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)	__DBG_NOP_PRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)
#define ZPRINTF0(x)                                    	__DBG_NOP_PRINTF0(x)                                    
#define ZPRINTF1(x, a1)                                	__DBG_NOP_PRINTF1(x, a1)                                
#define ZPRINTF2(x, a1, a2)                            	__DBG_NOP_PRINTF2(x, a1, a2)                            
#define ZPRINTF3(x, a1, a2, a3)                        	__DBG_NOP_PRINTF3(x, a1, a2, a3)                        
#define ZPRINTF4(x, a1, a2, a3, a4)                    	__DBG_NOP_PRINTF4(x, a1, a2, a3, a4)                    
#define ZPRINTF5(x, a1, a2, a3, a4, a5)                	__DBG_NOP_PRINTF5(x, a1, a2, a3, a4, a5)                
#define ZPRINTF6(x, a1, a2, a3, a4, a5, a6)            	__DBG_NOP_PRINTF6(x, a1, a2, a3, a4, a5, a6)            
#define ZPRINTF7(x, a1, a2, a3, a4, a5, a6, a7)        	__DBG_NOP_PRINTF7(x, a1, a2, a3, a4, a5, a6, a7)        
#define ZPRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)    	__DBG_NOP_PRINTF8(x, a1, a2, a3, a4, a5, a6, a7, a8)    
#define ZPRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)	__DBG_NOP_PRINTF9(x, a1, a2, a3, a4, a5, a6, a7, a8, a9)

#endif /* !NOUSE_PRINTF */

    
#if DEBUG && !NOUSE_PRINTF
extern void _dbg_dump(const void *const ptr, const size_t siz);
#define dump(ptr, siz) 		_dbg_dump(ptr, siz)
#else
#define dump(ptr, siz)		__DBG_NOP()
#endif

#if DEBUG
#define DBG_ARRAY(a,i) \
*(((unsigned int)(i) < number(a)) ? &(a)[i] : \
  (_dbg_array_error(i, number(a), a, #a,  __FILE__, __LINE__), &(a)[0]))
extern void
_dbg_array_error(
    unsigned int array_idx,
    unsigned int array_num,
    const void *array_ptr,
    const char *array_name,
    const char *file,
    unsigned int line);
#else
#define DBG_ARRAY(a,i) ((a)[i])
#endif

#if DEBUG && !NOUSE_PRINTF
extern void
       _dbg_bound(const char *const varname, const void *const var, const int bound, const char *const file, const int line);
#define DBG_BOUND(var, bound) _dbg_bound(#var, (const void *)(var), bound, __FILE__, __LINE__)

extern void
       _dbg_null(const char *const varname, const void *const var, const char *const file, const int line);
#define DBG_NULL(var) _dbg_null(#var, (const void *)(var), __FILE__, __LINE__)

extern void
       _dbg_ptr(const char *const varname, const void *const var, const char *const file, const int line);
#define DBG_PTR(var) _dbg_ptr(#var, (const void *)(var), __FILE__, __LINE__)

extern float f_debug_range_f(
    const char *file,
    const int line,
    const char *varstr,
    const float var,
    const char *minstr,
    const float min,
    const char *maxstr,
    const float max
);

#define DBG_RANGE_F(var, min, max) \
f_debug_range_f(__FILE__, __LINE__, #var, var, #min, min, #max, max)

extern int
_dbg_range(
    const char *file,
    const int line,
    const char *varstr,
    const int var,
    const char *minstr,
    const int min,
    const char *maxstr,
    const int max
);
#define DBG_RANGE_I(var, min, max) _dbg_range(__FILE__, __LINE__, #var, var, #min, min, #max, max) 
#define DBG_RANGE(var, max) DBG_RANGE_I(var, 0, max)

extern void _dbg_here(char *file, int line);
#define DBG_HERE() _dbg_here(__FILE__, __LINE__)
#define DBG_DISP(fmt, var) \
do { \
	DBG_HERE(); \
	PRINTF(#var " = %" #fmt "\n", var); \
} while (0)
#define disp(fmt, var) DBG_DISP(fmt, var)

#define zdisp(fmt, var) \
ZPRINTF(("%d %s %d:%s = %" #fmt "\n", osGetThreadId(NULL), __FILE__, __LINE__, #var, (var)))

/*
 * ViewPort内容表示
 */
#define DispViewport(vv) \
    PRINTF("%s %d: [%s] = {\n%d %d %d %d\n%d %d %d %d\n}\n", \
	   __FILE__, __LINE__, #vv, \
	   (vv)->vp.vscale[0], (vv)->vp.vscale[1], \
	   (vv)->vp.vscale[2], (vv)->vp.vscale[3], \
	   (vv)->vp.vtrans[0], (vv)->vp.vtrans[1], \
	   (vv)->vp.vtrans[2], (vv)->vp.vtrans[3])
/*
 * 行列の内容表示(long)
 */
#define DispMatrix(m) \
do { \
    Mtx2u_t *u = &((Mtx2 *)(m))->m2u; \
    PRINTF( "%s %d: [%s] =\n" \
	    "/ %04x.%04x %04x.%04x %04x.%04x %.04x.%04x \\\n" \
	    "| %04x.%04x %04x.%04x %04x.%04x %.04x.%04x |\n" \
	    "| %04x.%04x %04x.%04x %04x.%04x %.04x.%04x |\n" \
	    "\\ %04x.%04x %04x.%04x %04x.%04x %.04x.%04x /\n", \
	    __FILE__, __LINE__, #m, \
	    u->i[0][0], u->f[0][0], u->i[1][0], u->f[1][0], u->i[2][0], u->f[2][0], u->i[3][0], u->f[3][0], \
	    u->i[0][1], u->f[0][1], u->i[1][1], u->f[1][1], u->i[2][1], u->f[2][1], u->i[3][1], u->f[3][1], \
	    u->i[0][2], u->f[0][2], u->i[1][2], u->f[1][2], u->i[2][2], u->f[2][2], u->i[3][2], u->f[3][2], \
	    u->i[0][3], u->f[0][3], u->i[1][3], u->f[1][3], u->i[2][3], u->f[2][3], u->i[3][3], u->f[3][3]); \
} while (0)

/*
 * 行列の内容表示(float)
 */
#define DispMatrixf(m) \
PRINTF( "%s %d: [%s] =\n"\
	"/ %12.6f %12.6f %12.6f %12.6f \\\n" \
	"| %12.6f %12.6f %12.6f %12.6f |\n" \
	"| %12.6f %12.6f %12.6f %12.6f |\n" \
	"\\ %12.6f %12.6f %12.6f %12.6f /\n", \
	__FILE__, __LINE__, #m, \
	(m)->mf[0][0], (m)->mf[1][0], (m)->mf[2][0], (m)->mf[3][0], \
	(m)->mf[0][1], (m)->mf[1][1], (m)->mf[2][1], (m)->mf[3][1], \
	(m)->mf[0][2], (m)->mf[1][2], (m)->mf[2][2], (m)->mf[3][2], \
	(m)->mf[0][3], (m)->mf[1][3], (m)->mf[2][3], (m)->mf[3][3])
    

#else  /* DEBUG && !NOUSE_PRINTF */
#define DBG_BOUND(var, bound) 	((void)(var), (void)(bound))
#define DBG_NULL(var) 		((void)(var))
#define DBG_PTR(ptr) 		((void)(ptr))
#define DBG_RANGE(var, max) 	((void)(var), (void)(max))
#define DBG_RANGE_F(var, min, max) ((void)(var), (void)(min), (void)(max))
#define DBG_HERE()              __DBG_NOP()
#define DBG_DISP(fmt, var)      ((void)(var))

#define disp(fmt, var)		((void)(var))
#define zdisp(fmt, var)		((void)(var))
#define DispMatrix(m)		((void)(m))
#define DispMatrixf(m)		((void)(m))
#define DispViewport(vv) 	((void)(vv))

#endif /* DEBUG  && !NOUSE_PRINTF */

//#define xdisp(fmt, var)		__DBG_NOP_PRINTF(#fmt, var)
//#define XPRINTF 		__DBG_NOP_PRINTF

#if DEBUG  && !NOUSE_PRINTF
#define C_BELL 			7
#define ESC_RED			"\033[31m"
#define ESC_GREEN		"\033[32m"
#define ESC_YELLOW		"\033[33m"
#define ESC_BLUE		"\033[34m"
#define ESC_MAZENTA		"\033[35m"
#define ESC_CYAN		"\033[36m"
#define ESC_WHITE		"\033[37m"
#define ESC_BLACK		"\033[30m"
#define ESC_NORMAL		"\033[m"
#define ESC_WARNING		"\033[43;30m"
#define ESC_ERROR		"\033[41;37m"
#define BEEP() 			PRINTF("%c", C_BELL) /* ピーと鳴る */
#define COLOR_RED()		PRINTF(ESC_RED)
#define COLOR_GREEN() 		PRINTF(ESC_GREEN)
#define COLOR_YELLOW() 		PRINTF(ESC_YELLOW)
#define COLOR_BLUE() 		PRINTF(ESC_BLUE)
#define COLOR_MAZENTA()		PRINTF(ESC_MAZENTA)
#define COLOR_CYAN() 		PRINTF(ESC_CYAN)
#define COLOR_WHITE() 		PRINTF(ESC_WHITE)
#define COLOR_BLACK() 		PRINTF(ESC_BLACK)
#define COLOR_NORMAL() 		PRINTF(ESC_NORMAL)
#define COLOR_WARNING() 	PRINTF(ESC_WARNING)
#define COLOR_ERROR() 		PRINTF(ESC_ERROR)
//#undef  COLOR_RED
//#define COLOR_RED()		COLOR_ERROR()
#else  /* DEBUG  && !NOUSE_PRINTF */
#define ESC_RED			""
#define ESC_GREEN		""
#define ESC_YELLOW		""
#define ESC_BLUE		""
#define ESC_MAZENTA		""
#define ESC_CYAN		""
#define ESC_WHITE		""
#define ESC_BLACK		""
#define ESC_NORMAL		""
#define ESC_WARNING		""
#define ESC_ERROR		""
#define BEEP() 			__DBG_NOP()
#define COLOR_RED()		__DBG_NOP()
#define COLOR_GREEN() 		__DBG_NOP()
#define COLOR_YELLOW() 		__DBG_NOP()
#define COLOR_BLUE() 		__DBG_NOP()
#define COLOR_MAZENTA()		__DBG_NOP()
#define COLOR_CYAN() 		__DBG_NOP()
#define COLOR_WHITE() 		__DBG_NOP()
#define COLOR_BLACK() 		__DBG_NOP()
#define COLOR_NORMAL() 		__DBG_NOP()
#define COLOR_WARNING() 	__DBG_NOP()
#define COLOR_ERROR() 		__DBG_NOP()
#endif /* DEBUG  && !NOUSE_PRINTF */

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __DEBUG_H_ */
