/*
 * $Id: z_shrink_window.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 *
 * 画角縮小
 *
 * $Log: z_shrink_window.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.5  1998/03/19 13:03:00  komatu
 * *** empty log message ***
 *
 * Revision 1.4  1997/11/12  07:57:36  hayakawa
 * 以下のファイルを同時にチェックアウトしてください（今回だけ）
 * z_play.c
 * z_player.h
 * z_shrink_window.c
 * z_shrink_window.h
 *
 * shrink_window_move変更
 *
 * Revision 1.3  1997/11/12  05:16:33  hayakawa
 * shrink_window_setnowval追加
 * shrink_window_getnowval追加
 *
 * Revision 1.2  1997/11/12  04:51:12  hayakawa
 * shrink_window_init追加
 * shrink_window_cleanup追加
 * shrink_window_getval追加
 *
 * Revision 1.1  1997/11/11  12:22:09  hayakawa
 * Initial revision
 *
 */

#ifndef __Z_SHRINK_WINDOW_H_
#define __Z_SHRINK_WINDOW_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

				/* 初期化 */
void shrink_window_init(void);
				/* 後始末 */
void shrink_window_cleanup(void);
				/* ゲームフレーム動作 */
void shrink_window_move(int frame);
				/* 目標の縮小量の設定 */
void shrink_window_setval(int val);
				/* 目標の縮小量の取得 */
int  shrink_window_getval(void);
				/* 現在の縮小量の設定 */
void shrink_window_setnowval(int val);
				/* 現在の縮小量の取得 */
int  shrink_window_getnowval(void);
				/* 音を鳴らす設定 */
void shrink_window_ring(int val);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __Z_SHRINK_WINDOW_H_ */
