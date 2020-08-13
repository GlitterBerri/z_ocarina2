/*
 * $Id: z_locale.h,v 2.2 1998-10-27 19:35:04+09 hayakawa Exp $
 *
 * ロケールクラス
 *
 * $Log: z_locale.h,v $
 * Revision 2.2  1998-10-27 19:35:04+09  hayakawa
 * 一応PALモードの追加
 *
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.3  1998/10/03 07:04:33  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1998-07-02 21:57:34+09  hayakawa
 * デバッグ時は関数の方が良さげ
 *
 * Revision 1.1  1998-06-08 20:57:48+09  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_LOCALE_H_
#define __Z_LOCALE_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

    typedef enum z_locale_mode_e {
	Z_LOCALE_MODE_UNKNOWN = 0,
	Z_LOCALE_MODE_JAPAN = 1,
	Z_LOCALE_MODE_USA = 2,
	Z_LOCALE_MODE_PAL = 3,
	Z_LOCALE_MODE_MAX
    } z_locale_mode_e;
    
    extern z_locale_mode_e z_locale_mode;
    extern void z_locale_init(void);
    extern void z_locale_cleanup(void);
#ifndef ROM_F
    extern int z_locale_IsJapan(void);
    extern int z_locale_IsUSA(void);
    extern int z_locale_IsPAL(void);
#else
#define z_locale_IsJapan()   (z_locale_mode == Z_LOCALE_MODE_JAPAN)
#define z_locale_IsUSA()     (z_locale_mode == Z_LOCALE_MODE_USA)
#define z_locale_IsPAL()     (z_locale_mode == Z_LOCALE_MODE_PAL)
#define z_locale_IsUnknown() (z_locale_mode <= 0)
#endif
   
#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_LOCALE_H_ */
