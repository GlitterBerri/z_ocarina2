/*
 * $Id: audio.h,v 2.1 1998-10-22 20:41:56+09 zelda Exp $
 *
 * $Log: audio.h,v $
 * Revision 2.1  1998-10-22 20:41:56+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.6  1998/06/26 12:50:45  hayakawa
 * audio_StopAllSoundEffect追加
 *
 * Revision 1.5  1998-04-01 11:45:45+09  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.4  1997/12/03  02:16:21  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1997/12/03  02:15:25  hayakawa
 * /projectを直接みないようにした
 *
 * Revision 1.2  1997/05/28  06:17:06  hayakawa
 * HAYAKAWA_TESTaを標準にして外した
 *
 * Revision 1.1  1997/05/22  02:16:16  hayakawa
 * Initial revision
 *
 * Revision 1.8  1997/04/09  09:35:11  hayakawa
 * NOUSE_AUDIO削除
 *
 * Revision 1.7  1996/11/21  05:08:17  hayakawa
 * インクルードするべきファイルをインクルードしていなかった
 *
 * Revision 1.6  1996/10/29  12:35:17  hayakawa
 * NOUSE_AUDIO条件コンパイル
 * NEW_AUDIO削除
 *
 * Revision 1.5  1996/10/20  08:51:53  hayakawa
 * _LANGUAGE_C_PLUS_PLUS を __cplusplus に変更
 *
 */
#ifndef __AUDIO_H_
#define __AUDIO_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "../lib/audio/audio_game.h"
    
extern void audio_StopAllSoundEffect(void);

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif
