/* $Id: z_player.h,v 1.1.1.1 2003/03/10 22:42:55 tong Exp $ */	
/* $Log: z_player.h,v $
 * Revision 1.1.1.1  2003/03/10 22:42:55  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.210  1998/10/20 10:46:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.209  1998-10-17 02:33:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.208  1998-10-15 17:20:16+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.207  1998-10-13 21:19:04+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.206  1998-10-13 15:26:51+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.205  1998-10-09 21:25:47+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.204  1998-10-08 13:35:05+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.203  1998-10-07 22:57:27+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.202  1998-10-04 01:25:05+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.201  1998-09-30 20:00:31+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.200  1998-09-26 01:15:58+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.199  1998-09-20 02:06:10+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.198  1998-09-19 18:32:29+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.197  1998-09-12 23:48:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.196  1998-09-09 00:43:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.195  1998-09-07 14:03:36+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.194  1998-09-05 23:24:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.193  1998-09-05 00:12:43+09  goron
 * *** empty log message ***
 *
 * Revision 1.192  1998-09-03 23:59:15+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.191  1998-09-03 00:26:33+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.190  1998-09-02 00:31:22+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.189  1998-09-01 00:31:13+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.188  1998-08-29 00:20:40+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.187  1998-08-27 00:25:28+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.186  1998-08-22 18:38:16+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.185  1998-08-20 18:22:53+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.184  1998-08-14 16:48:19+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.183  1998-08-14 00:11:46+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.182  1998-08-13 00:49:23+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.181  1998-08-12 00:34:51+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.180  1998-08-06 00:58:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.179  1998-08-04 21:34:10+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.178  1998-08-04 17:08:16+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.177  1998-07-30 23:23:10+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.176  1998-07-29 22:57:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.175  1998-07-25 22:56:34+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.174  1998-07-24 20:52:21+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.173  1998-07-24 19:05:02+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.172  1998-07-23 23:14:46+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.171  1998-07-22 23:02:44+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.170  1998-07-20 22:41:40+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.169  1998-07-20 17:40:11+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.168  1998-07-16 20:01:49+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.167  1998-07-13 22:53:33+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.166  1998-07-10 23:08:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.165  1998-07-09 23:06:11+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.164  1998-07-06 22:57:17+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.163  1998-07-04 22:31:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.162  1998-06-29 22:28:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.161  1998-06-24 22:57:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.160  1998-06-23 22:59:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.159  1998-06-20 22:55:34+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.158  1998-06-19 22:41:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.157  1998-06-18 19:28:31+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.156  1998-06-17 23:01:34+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.155  1998-06-16 23:06:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.154  1998-06-15 22:57:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.153  1998-06-12 23:25:21+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.152  1998-06-11 23:08:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.151  1998-06-08 22:57:47+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.150  1998-06-06 22:55:45+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.149  1998-06-05 16:50:59+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.148  1998-06-04 19:29:33+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.147  1998-06-04 17:52:57+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.146  1998-06-01 22:34:52+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.145  1998-05-30 22:51:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.144  1998-05-29 20:11:24+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.143  1998-05-26 14:10:45+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.142  1998-05-26 12:07:32+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.141  1998-05-19 18:51:12+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.140  1998/05/18 07:10:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.139  1998/05/16 11:11:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.138  1998/05/15 14:01:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.137  1998/05/14 11:35:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.136  1998/05/12 14:25:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.135  1998/05/11 14:06:36  iwawaki
 * *** empty log message ***
 *
 * Revision 1.134  1998/05/08 06:32:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.133  1998/05/07 14:20:36  iwawaki
 * *** empty log message ***
 *
 * Revision 1.132  1998/04/29 07:07:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.131  1998/04/28 13:28:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.130  1998/04/27 14:18:54  iwawaki
 * *** empty log message ***
 *
 * Revision 1.129  1998/04/25 11:44:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.128  1998/04/24 05:16:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.127  1998/04/23 10:42:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.126  1998/04/22 14:24:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.125  1998/04/21 14:07:27  iwawaki
 * *** empty log message ***
 *
 * Revision 1.124  1998/04/20 14:20:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.123  1998/04/18 14:43:34  iwawaki
 * *** empty log message ***
 *
 * Revision 1.122  1998/04/16 11:24:03  iwawaki
 * *** empty log message ***
 *
 * Revision 1.121  1998/04/08 14:17:40  iwawaki
 * *** empty log message ***
 *
 * Revision 1.120  1998/04/07  14:12:03  iwawaki
 * *** empty log message ***
 *
 * Revision 1.119  1998/04/03  14:06:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.118  1998/04/02  10:38:30  iwawaki
 * *** empty log message ***
 *
 * Revision 1.117  1998/04/01  02:31:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.116  1998/03/30  13:30:30  iwawaki
 * *** empty log message ***
 *
 * Revision 1.115  1998/03/27  14:03:05  iwawaki
 * *** empty log message ***
 *
 * Revision 1.114  1998/03/26  10:37:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.113  1998/03/23  14:01:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.112  1998/03/21  14:22:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.111  1998/03/20  14:28:42  iwawaki
 * *** empty log message ***
 *
 * Revision 1.110  1998/03/18  14:02:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.109  1998/03/18  02:45:05  iwawaki
 * *** empty log message ***
 *
 * Revision 1.108  1998/03/17  13:53:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.107  1998/03/16  04:21:41  iwawaki
 * *** empty log message ***
 *
 * Revision 1.106  1998/03/12  13:52:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.105  1998/03/10  11:24:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.104  1998/03/07  14:24:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.103  1998/03/05  14:17:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.102  1998/03/05  03:01:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.101  1998/03/05  02:40:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.100  1998/03/03  14:04:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.99  1998/02/27  13:20:29  iwawaki
 * *** empty log message ***
 *
 * Revision 1.98  1998/02/26  08:38:05  iwawaki
 * *** empty log message ***
 *
 * Revision 1.97  1998/02/25  03:02:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.96  1998/02/24  13:55:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.95  1998/02/23  14:08:52  iwawaki
 * *** empty log message ***
 *
 * Revision 1.94  1998/02/21  13:24:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.93  1998/02/20  13:40:37  iwawaki
 * *** empty log message ***
 *
 * Revision 1.92  1998/02/19  13:54:13  iwawaki
 * ,
 *
 * Revision 1.91  1998/02/18  05:35:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.90  1998/02/18  04:37:35  iwawaki
 * *** empty log message ***
 *
 * Revision 1.89  1998/02/17  05:39:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.88  1998/02/14  13:43:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.87  1998/02/12  13:46:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.86  1998/02/11  14:04:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.85  1998/02/10  13:55:18  iwawaki
 * ..
 *
 * Revision 1.84  1998/02/07  13:24:45  iwawaki
 * *** empty log message ***
 *
 * Revision 1.83  1998/02/05  02:42:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.82  1998/02/03  13:35:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.81  1998/01/30  13:21:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.80  1998/01/29  13:33:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.79  1998/01/28  14:38:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.78  1998/01/27  13:18:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.77  1998/01/27  10:35:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.76  1998/01/16  13:40:09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.75  1998/01/09  13:37:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.74  1998/01/06  10:11:53  soejima
 * 引数変更
 * z_save_area.h削除
 *
 * Revision 1.73  1997/12/25  09:10:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.72  1997/12/11  09:50:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.71  1997/12/01  12:05:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.70  1997/12/01  09:04:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.69  1997/11/19  07:07:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.68  1997/11/15  12:07:40  iwawaki
 * *** empty log message ***
 *
 * Revision 1.67  1997/11/15  10:16:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.66  1997/11/13  17:07:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.65  1997/11/13  12:01:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.64  1997/11/12  07:56:20  hayakawa
 * 以下のファイルを同時にチェックアウトしてください（今回だけ）
 * z_play.c
 * z_player.h
 * z_shrink_window.c
 * z_shrink_window.h
 *
 * 不要なプロトタイプをはずした
 *
 * Revision 1.63  1997/11/11  15:15:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.62  1997/11/10  12:00:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.61  1997/11/07  14:27:18  iwawaki
 * *** empty log message ***
 *
 * Revision 1.60  1997/11/05  14:40:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.59  1997/11/04  02:39:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.58  1997/11/03  07:30:19  iwawaki
 * *** empty log message ***
 *
 * Revision 1.57  1997/11/01  14:58:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.56  1997/10/31  05:09:25  ogawa
 * *** empty log message ***
 *
 * Revision 1.55  1997/10/31  05:05:33  ogawa
 * *** empty log message ***
 *
 * Revision 1.54  1997/10/30  10:48:27  iwawaki
 * *** empty log message ***
 *
 * Revision 1.53  1997/10/29  13:48:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.52  1997/10/28  13:26:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.51  1997/10/27  10:39:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.50  1997/10/27  03:13:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.49  1997/10/24  14:26:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.48  1997/10/23  14:43:32  iwawaki
 * *** empty log message ***
 *
 * Revision 1.47  1997/10/18  06:56:52  iwawaki
 * *** empty log message ***
 *
 * Revision 1.46  1997/10/13  14:38:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.45  1997/10/10  14:54:14  iwawaki
 * *** empty log message ***
 *
 * Revision 1.44  1997/10/07  14:22:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.43  1997/10/02  04:19:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.42  1997/09/24  14:32:54  iwawaki
 * *** empty log message ***
 *
 * Revision 1.41  1997/09/17  08:37:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.40  1997/09/14  14:16:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.39  1997/09/10  14:37:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.38  1997/09/06  14:28:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.37  1997/09/01  13:45:14  iwawaki
 * *** empty log message ***
 *
 * Revision 1.36  1997/08/29  11:14:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.35  1997/08/29  04:38:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.34  1997/08/27  01:46:55  iwawaki
 * *** empty log message ***
 *
 * Revision 1.33  1997/08/25  13:58:23  hayakawa
 * Z_PLAYER_Hを移動
 *
 * Revision 1.32  1997/08/21  11:07:19  hayakawa
 * *** empty log message ***
 *
 * Revision 1.31  1997/08/21  08:32:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.30  1997/08/09  05:01:19  iwawaki
 * *** empty log message ***
 *
 * Revision 1.29  1997/08/06  03:23:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.28  1997/08/04  01:34:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.27  1997/07/31  07:46:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.26  1997/07/31  03:18:34  iwawaki
 * *** empty log message ***
 *
 * Revision 1.25  1997/07/31  01:59:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.24  1997/07/28  01:25:26  iwawaki
 * *** empty log message ***
 *
 * Revision 1.23  1997/07/24  08:02:42  iwawaki
 * *** empty log message ***
 *
 * Revision 1.22  1997/07/22  00:14:58  iwawaki
 * *** empty log message ***
 *
 * Revision 1.21  1997/07/11  07:52:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1997/07/09  04:40:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.19  1997/07/08  11:48:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/07/05  12:39:45  iwawaki
 * *** empty log message ***
 *
 * Revision 1.17  1997/07/04  05:55:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.16  1997/07/02  04:44:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.15  1997/07/02  00:33:58  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1997/06/27  03:19:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.13  1997/06/26  05:16:52  iwawaki
 * *** empty log message ***
 *
 * Revision 1.12  1997/06/20  06:21:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1997/06/18  13:05:50  iwawaki
 * *** empty log message ***
 * new
 * */


#ifndef INCLUDE_Z_PLAYER_H
#define INCLUDE_Z_PLAYER_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/************************************************************************
 *
 *	プレイヤー
 *
 ************************************************************************/
#include "z_basic.h"
#include "z_play_h.h"
#include "z_actor_h.h"
#include "z_player_h.h"
#include "z_collision_check.h"
#include "z_eff_blure.h"
#include "z_parameter.h"

/*-----------------------------------------------------------------------
 *
 *	プレイヤーマクロ
 *
 *----------------------------------------------------------------------*/
/*
 * 年齢タイプ
 */
enum {
    P_AGE_17,
    P_AGE_6,
    P_AGE_MAX
};
    
/*
 * 設定データ
 */
#define	P_MAX_JOINT			(21+1)		/* スケルトン数 */

#define P_SHAPE_OFFSET_Y		0.0f
#define	P_ANCHOR_OFFSET_Y		500.0f
#define	P_SCALE				(1.0f/100.0f)
#define	P_CHILD_SCALE			(110.0f/170.0f)
#define	P_GRAVITY			((float)REG(68)/100.0f)
#define	P_RUN_MAX_SPEEDF		(((float)REG(45))/100.0f)

/*
 * 状態フラグ
 */
#define	P_ACTION_NORMAL			(0)	/* ＮＯクリアーフラグ */
#define	P_ACTION_SCENE_CHANGE_DEMO	(1)	/* シーン切り替えデモ中フラグ */
//#define	P_ACTION_TURN			(1<<1)	/* ターン中フラグ */
#define	P_ACTION_BOTTLE_ATTACK		(1<<1)	/* 空ビン攻撃フラグ */
//#define	P_ACTION_FIGHT			(1<<2)	/* 戦闘モードフラグ */
#define	P_ACTION_HOOK_FLY_END		(1<<2)	/* フックショット飛行終了フラグ */
#define	P_ACTION_BOW			(1<<3)	/* 弓矢モードフラグ */
#define	P_ACTION_ANCHOR_FIGHT		(1<<4)	/* 注目戦闘フラグ */
#define	P_ACTION_NO_KEY_MODE		(1<<5)	/* キー無視モードフラグ */
#define	P_ACTION_TALK			(1<<6)	/* 会話中フラグ */
#define	P_ACTION_DOWN			(1<<7)	/* ダウンフラグ */
#define	P_ACTION_AUTO_FIGHT		(1<<8)	/* 自動で戦闘モードになるフラグ */
#define	P_ACTION_ARROW_CATCH		(1<<9)	/* 弓矢セットフラグ */
#define	P_ACTION_GET_ITEM		(1<<10)	/* ゲットアイテムフラグ */
#define	P_ACTION_CARRY			(1<<11)	/* 持ち上げフラグ */
#define	P_ACTION_POWER_KIRU		(1<<12)	/* 溜め斬りフラグ */
#define	P_ACTION_FALL			(1<<13)	/* ぶら下がりフラグ */
#define	P_ACTION_JUMP_CLIMB		(1<<14)	/* ジャンプぶら下がりフラグ */
#define	P_ACTION_ANCHOR			(1<<15)	/* 注目フラグ */
#define	P_ACTION_KEEPON			(1<<16)	/* 注目モードフラグ */
#define	P_ACTION_PARALLEL		(1<<17)	/* 平行モードフラグ */
#define	P_ACTION_JUMP			(1<<18)	/* ジャンプモードフラグ */
#define	P_ACTION_FREEFALL		(1<<19)	/* 落下モードフラグ */
#define	P_ACTION_SUBJECT		(1<<20)	/* 主観モードフラグ */
#define	P_ACTION_LADDER			(1<<21)	/* 梯子モードフラグ */
#define	P_ACTION_DEFENSE		(1<<22)	/* 防御モードフラグ */
#define	P_ACTION_RIDE_HORSE		(1<<23)	/* 乗馬モードフラグ */
#define	P_ACTION_BOOM			(1<<24)	/* ブーメランモードフラグ */
#define	P_ACTION_BOOM_THROW		(1<<25)	/* ブーメラン投げモードフラグ */
#define	P_ACTION_DAMAGE			(1<<26)	/* ダメージモードフラグ */
#define	P_ACTION_SWIM			(1<<27)	/* 泳ぎモードフラグ */
#define	P_ACTION_ALL_STOP_DEMO		(1<<28)	/* 完全停止デモモードフラグ */
#define	P_ACTION_DEMO			(1<<29)	/* デモモードフラグ */
#define	P_ACTION_PARALLEL_CAMERA	(1<<30)	/* 注目解除後の平行カメラフラグ */
#define	P_ACTION_WARP_FALL		(1<<31)	/* ワープ穴フラグ */

#define	P_ACTION_DONT_CARRY		(P_ACTION_DOWN | P_ACTION_POWER_KIRU | P_ACTION_FALL | \
					 P_ACTION_JUMP_CLIMB | P_ACTION_JUMP | P_ACTION_FREEFALL | P_ACTION_SUBJECT | \
					 P_ACTION_LADDER) 	
#define	P_ACTION_DONT_RIDE		(P_ACTION_DONT_CARRY | P_ACTION_CARRY)
#define	P_ACTION_DONT_COMPAS		(P_ACTION_ANCHOR_FIGHT | P_ACTION_POWER_KIRU | P_ACTION_FALL | P_ACTION_JUMP_CLIMB | \
					 P_ACTION_SUBJECT) 	

/*
 * 状態フラグ２
 */
#define	P_ACTION2_PUSH_PULL_OK		(1)		/* 押し，引きモード可能フラグ */
#define	P_ACTION2_TALK_OK		(1<<1)		/* 会話可能フラグ */
#define	P_ACTION2_STEPUP_OK		(1<<2)		/* 段登り可能フラグ */
#define	P_ACTION2_BIG_SE_SET		(1<<3)		/* 大きいＳＥセットフラグ */
#define	P_ACTION2_PUSH_PULL		(1<<4)		/* 押し，引き中フラグ */
#define	P_ACTION2_NO_ANCHOR_ANGLE	(1<<5)		/* シェイプ方向を注目から解除するフラグ */
#define	P_ACTION2_NO_SHAPE_ANGLE	(1<<6)		/* シェイプ方向を固定するフラグ */
#define	P_ACTION2_RE_DEAD_ATTACK	(1<<7)		/* リーデッド捕まりフラグ */
#define	P_ACTION2_PUSH_PULL_CATCH	(1<<8)		/* 押し，引き状態フラグ */
#define	P_ACTION2_SAND_SOUND_SET	(1<<9)		/* 砂地サウンドコードセットフラグ */
#define	P_ACTION2_SWIM_DEEP		(1<<10)		/* 潜り中フラグ */
#define	P_ACTION2_SWIM_DEEP_CAMERA	(1<<11)		/* 潜り用カメラフラグ */
#define	P_ACTION2_CLIMB_STOP		(1<<12)		/* 梯子ｏｒ壁登り中で停止フラグ */
#define	P_ACTION2_ANCHOR_ROCK		(1<<13)		/* 注目ロックフラグ */
#define	P_ACTION2_ICE_DOWN		(1<<14)		/* 氷ダメージフラグ */
#define	P_ACTION2_STOP_FLAG		(1<<15)		/* 停止フラグ */
#define	P_ACTION2_TUNNEL_OK		(1<<16)		/* 横穴モード可能フラグ */
#define	P_ACTION2_POWER_KIRU_SHOT	(1<<17)		/* 溜め斬りショットフラグ */
#define	P_ACTION2_TUNNEL		(1<<18)		/* 横穴モードフラグ */
#define	P_ACTION2_DEMO_JUMP		(1<<19)		/* デモジャンプフラグ */
#define	P_ACTION2_ELF_ACTION		(1<<20)		/* ゲットアイテムフラグ */
#define	P_ACTION2_ELF_MAIL_OK		(1<<21)		/* 妖精へのメール可能フラグ */
#define	P_ACTION2_RIDE_HORSE_END_OK	(1<<22)		/* 降馬ＯＫフラグ */
#define	P_ACTION2_OKARINA_REQUEST	(1<<23)		/* オカリナスペシャル演奏要求フラグ */
#define	P_ACTION2_OKARINA_REQUEST_OK	(1<<24)		/* オカリナスペシャル演奏可能フラグ */
#define	P_ACTION2_OKARINA_ACTOR_OK	(1<<25)		/* オカリナスペシャル演奏Ａｃｔｏｒ指定可能フラグ */
#define	P_ACTION2_MIRROR_DISPLAY	(1<<26)		/* 写り込むモードフラグ */
#define	P_ACTION2_OKARINA_MODE		(1<<27)		/* オカリナモードフラグ */
#define	P_ACTION2_WAIT			(1<<28)		/* 待機モードフラグ */
#define	P_ACTION2_NO_DISPLAY		(1<<29)		/* 表示ＯＦＦフラグ */
#define	P_ACTION2_KIRU_TRANSLATE	(1<<30)		/* 剣斬り移動フラグ */
#define	P_ACTION2_WATER_FALL		(1<<31)		/* 水中落下フラグ */

/*
 * 状態フラグ３
 */
#define	P_ACTION3_GROUND_NO_CHECK	(1)	/* 床チェック無しフラグ */
#define	P_ACTION3_SKY			(1<<1)	/* 空中フラグ */
#define	P_ACTION3_MOVE_STOP		(1<<2)	/* 動作停止フラグ */
#define	P_ACTION3_KIRU_END		(1<<3)	/* 剣斬り後フラグ */
#define	P_ACTION3_GROUND_CHECKED	(1<<4)	/* 床ＢＧチェックしたフラグ */
#define	P_ACTION3_TO_OKARINA		(1<<5)	/* 強制オカリナモードへフラグ */
#define	P_ACTION3_SHIELD_REMAKE		(1<<6)	/* シールド魔法再セットフラグ */
#define	P_ACTION3_HOOK_FLY		(1<<7)	/* フックショット引っ張られ中フラグ */
	 
/*-----------------------------------------------------------------------
 *
 *	スタートモードセット
 *
 *----------------------------------------------------------------------*/
enum {
    P_START_MODE_NON,			/*  0  出演しない */
    P_START_MODE_M_SWORD_END,		/*  1  マスターソードデモ出現デモ */
    P_START_MODE_FROM_WARP,		/*  2  時の間ワープ出現デモ */
    P_START_MODE_DOOR_START,		/*  3 ドア出現デモ */
    P_START_MODE_JUMP_START,		/*  4  ジャンプで登場 */
    P_START_MODE_FROM_OKARINA_WARP,	/*  5  オカリナワープ出現デモ */
    P_START_MODE_FROM_MAGIC_WARP,	/*  6  風の魔法出現デモ */
    P_START_MODE_DAMAGE_START,		/*  7  やられで登場 */
    P_START_MODE_DUMMY_8,
    P_START_MODE_DUMMY_9,
    P_START_MODE_DUMMY_10,
    P_START_MODE_DUMMY_11,
    P_START_MODE_DUMMY_12,
    P_START_MODE_DEMO_WAIT,		/* 13  待機で登場 */
    P_START_MODE_DEMO_RUN,		/* 14  走って登場 */
    P_START_MODE_RUN_START		/* 15  走って登場 */
};

#define	PLAYER_START_MODE_JUMP_START		((P_START_MODE_JUMP_START<<8) | 0xff)
#define	PLAYER_START_MODE_DEMO_WAIT		((P_START_MODE_DEMO_WAIT<<8) | 0xff)
#define	PLAYER_START_MODE_DEMO_RUN		((P_START_MODE_DEMO_RUN<<8) | 0xff)
#define	PLAYER_START_MODE_FROM_OKARINA_WARP	((P_START_MODE_FROM_OKARINA_WARP<<8) | 0xff)
#define	PLAYER_START_MODE_FROM_MAGIC_WARP	((P_START_MODE_FROM_MAGIC_WARP<<8) | 0xff)

/*-----------------------------------------------------------------------
 *
 *	デモ再生情報クラス
 *
 *----------------------------------------------------------------------*/
enum {
    P_DEMO_PLAY_NON,			
    P_DEMO_PLAY_ANCHOR_STOP,		/* 注目停止 */
    P_DEMO_PLAY_GOMA_FURIMUKI,		/* ゴーマ部屋振り向き */
    P_DEMO_PLAY_RUN_START,		/* 走り開始 */
    P_DEMO_PLAY_RUN_END,		/* 走り終了 */
    P_DEMO_PLAY_BIKKURI,		/* ビックリ */
    P_DEMO_PLAY_TOOL_PLAY,		/* ツールデモ再生 */
    P_DEMO_PLAY_END,			/* 終了 */
    P_DEMO_PLAY_WAIT,			/* 待機 */
    P_DEMO_PLAY_FURIMUKI,		/* 振り向き */
    P_DEMO_PLAY_WARP_OUT,		/* ワープアウト */
    P_DEMO_PLAY_WARP_UP,		/* ワープ上昇 */
    P_DEMO_PLAY_FIGHTER_WAIT,		/* 戦闘体制 */
    P_DEMO_PLAY_CARRY_WAIT_STONE_1,	/* 精霊石１持ち上げ待機 */
    P_DEMO_PLAY_CARRY_STONE_1,		/* 精霊石１持ち上げ */
    P_DEMO_PLAY_CARRY_END_STONE_1,	/* 精霊石１持ち上げ終了 */
    P_DEMO_PLAY_STANDUP,		/* 立ち上がる */
    P_DEMO_PLAY_SITDOWN,		/* 座る */
    P_DEMO_PLAY_M_SWORD_START,		/* 時の間マスターソードデモ */
    P_DEMO_PLAY_LOOK_DOWN,		/* 下を向く */
    P_DEMO_PLAY_LOOK_DOWN_END,		/* 下向きから基本へ */
    P_DEMO_PLAY_FROM_WARP,		/* ワープから出現 */
    P_DEMO_PLAY_KENJYA_START,		/* 賢者の間の出現 */
    P_DEMO_PLAY_LOOK_ME,		/* 自分を見る */
    P_DEMO_PLAY_BIG_DOWN,		/* 吹っ飛ばされ */
    P_DEMO_PLAY_WAKE_UP,		/* 起き上がり */
    P_DEMO_PLAY_OKARINA,		/* オカリナ演奏 */
    P_DEMO_PLAY_OKARINA_END,		/* オカリナ演奏終了 */
    P_DEMO_PLAY_GET_ITEM,		/* ゲットアイテム */
    P_DEMO_PLAY_GET_ITEM_END,		/* ゲットアイテム終了 */
    P_DEMO_PLAY_SWORD_STANDBY,		/* 剣抜き */
    P_DEMO_PLAY_EYE_CLOSE,		/* 目を閉じる */
    P_DEMO_PLAY_EYE_OPEN,		/* 目を開ける */
    P_DEMO_PLAY_ATOZUSARI,		/* 後退さり */
    P_DEMO_PLAY_SWIM_WAIT,		/* 立ち泳ぎ */
    P_DEMO_PLAY_WATER_GET_ITEM,		/* 水中ゲットアイテム */
    P_DEMO_PLAY_BASHI,			/* バシッ */
    P_DEMO_PLAY_HANG_UP_DOWN,		/* つり下げられ */
    P_DEMO_PLAY_OP3_WAIT1,		/* 寝て待機 */
    P_DEMO_PLAY_OP3_NEGAERI,		/* 寝返り */
    P_DEMO_PLAY_OP3_OKIAGARI,		/* ベッドで起き上がり */
    P_DEMO_PLAY_OP3_TATIAGARI,		/* ベッドから立ち上がり */
    P_DEMO_PLAY_FUTTOBI,		/* ガノンドロフの魔法で吹っ飛び */
    P_DEMO_PLAY_MIOKURI,		/* 走り去るガノンドロフを見送り，立ち上がる */
    P_DEMO_PLAY_WAIT2,			/* 待機２ */
    P_DEMO_PLAY_CLEAR,			/* 消える */
    P_DEMO_PLAY_DISPLAY,		/* 現れる */
    P_DEMO_PLAY_NOZOKI,			/* のぞき */
    P_DEMO_PLAY_KOUTAI,			/* 後退 */
    P_DEMO_PLAY_TOOL_DEMO_WAIT,		/* ツールデモ待機 */
    P_DEMO_PLAY_KOUTAI_KENNUKI,		/* 後退剣抜き */
    P_DEMO_PLAY_KAKEYORI,		/* 駆け寄り */
    P_DEMO_PLAY_KAKEYORI_MIMAWASI,	/* 見回し */
    P_DEMO_PLAY_KAKEYORI_MIOKURIRI,	/* 見上げ */
    P_DEMO_PLAY_FURIMUKI2,		/* 振り向き２ */
    P_DEMO_PLAY_KAOAGE,			/* 顔上げ */
    P_DEMO_PLAY_KAOAGE_WAIT,		/* 顔上げ待機 */
    P_DEMO_PLAY_MIMAWASI,		/* 見回し */
    P_DEMO_PLAY_NOZOKIKOMI,		/* のぞき込み */
    P_DEMO_PLAY_ODOROKI,		/* 驚き */
    P_DEMO_PLAY_SHAGAMU,		/* しゃがむ */
    P_DEMO_PLAY_KIZETSU,		/* 気絶 */
    P_DEMO_PLAY_OKIRU,			/* 気絶＞起き上がる */
    P_DEMO_PLAY_POWER_KIRU_SATRT,	/* 溜め斬りへ */
    P_DEMO_PLAY_NWAIT,			/* 別れシーン待機 */
    P_DEMO_PLAY_TEWATASHI,		/* 別れシーン手渡し */
    P_DEMO_PLAY_OROSUU,			/* 別れシーンおろす */
    P_DEMO_PLAY_OROORO,			/* 右上方を見回す */
    P_DEMO_PLAY_IMANODARE,		/* 右上方から戻る */
    P_DEMO_PLAY_HATTO,			/* ハッとなる */
    P_DEMO_PLAY_AFTER_OKARINA,		/* オカリナの直後 */
    P_DEMO_PLAY_AFTER_OKARINA_END,	/* オカリナから戻る */
    P_DEMO_PLAY_AFTER_OKARINA_CHILD,	/* オカリナの直後（少年用） */
    P_DEMO_PLAY_AFTER_OKARINA_END_CHILD,/* オカリナから戻る（少年用） */
    P_DEMO_PLAY_GURAD,			/* ガードする */
    P_DEMO_PLAY_LOOK_HAND,		/* 手を見る */
    P_DEMO_PLAY_SITA,			/* 下を見る（ガ） */
    P_DEMO_PLAY_UE,			/* 上を見る（ガ） */
    P_DEMO_PLAY_MUKU,			/* ゼルダに向く（ガ） */
    P_DEMO_PLAY_MIAGERU,		/* 上を向く（ガ） */
    P_DEMO_PLAY_HA,			/* ハッと見る（ガ） */
    P_DEMO_PLAY_1KYORO,			/* 炎バリア振り向く */
    P_DEMO_PLAY_2KYORO,			/* ガノン復活向き直り */
    P_DEMO_PLAY_SAGARU,			/* 空中のガノンを見る */
    P_DEMO_PLAY_BOUZEN,			/* 呆然をガノンを見る */
    P_DEMO_PLAY_KAMAERU,		/* 慌てて構える */
    P_DEMO_PLAY_HAJIKARERU,		/* 剣を弾かれる */
    P_DEMO_PLAY_KEN_MIRU,		/* 刺さった剣を見る */
    P_DEMO_PLAY_MUKINAORU,		/* ガノンに向き直る */
    P_DEMO_PLAY_POWER_KIRU_WAIT,	/* 回転斬り溜め */
    P_DEMO_PLAY_POWER_KIRU_SHOOT,	/* 回転斬り発動 */
    P_DEMO_PLAY_SWORD_CHECK,		/* 剣試し */
    P_DEMO_PLAY_DOWN_TO_STAND,		/* 吹っ飛んで立つ */
    P_DEMO_PLAY_HEAT,			/* 暑っつー */
    P_DEMO_PLAY_M_SWORD_END,		/* 時の間剣抜き登場 */
    P_DEMO_PLAY_KOUSAN,			/* 兵士に捕まった */
    P_DEMO_PLAY_M_SWORD_CATCH,		/* マスターソード取る */
    P_DEMO_PLAY_GANON_LAST_1,		/* ガノン最後の一撃１ */
    P_DEMO_PLAY_GANON_LAST_2,		/* ガノン最後の一撃２ */
    P_DEMO_PLAY_GANON_ZELDA_MIRU,	/* ゼルダ見る */
    P_DEMO_PLAY_GANON_KEN_MIRU_1,	/* 剣見る１ */
    P_DEMO_PLAY_GANON_KEN_MIRU_2,	/* 剣見る２ */
    P_DEMO_PLAY_GANON_KEN_MIRU_MODORU,	/* 剣見る終了 */
    P_DEMO_PLAY_MAX
};

typedef struct {
    unsigned char	mode;		/* モード */
    unsigned char	old_mode;	/* 前フレームモード */
    unsigned char	tool_mode;	/* ツールデモ用動作モード */
    unsigned char	counter;	/* カウンター */
    Actor		*anchor_actor;	/* 注目Ａｃｔｏｒポインタ */
    short		start_frame;	/* 開始フレーム */
    short		end_frame;	/* 終了フレーム */
    xyz_t		start_pos;	/* 開始座標 */
    xyz_t		end_pos;	/* 終了座標 */
    unsigned short	timer;		/* タイマー */
    signed short	work;		/* 汎用フラグ */
} Demo_Play_Status;

/*-----------------------------------------------------------------------
 *
 *	ドア情報クラス
 *
 *----------------------------------------------------------------------*/
enum {
    DOOR_OPEN_FLAG_OFF,
    DOOR_OPEN_FLAG_NORMAL,
    DOOR_OPEN_FLAG_SHUTTER,
    DOOR_OPEN_FLAG_KILLER
};

typedef struct {
    signed char	flag;
    signed char	direction;
    short	timer;
    Actor	*actor;
} Door_Status;

/*-----------------------------------------------------------------------
 *
 *	持ち上げ情報クラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
    signed char		flag;			/* 持ち上げ物フラグ */
    unsigned short	distance_angle_y;	/* 持ち上げ物との方向 */
    Actor		*actor;			/* 持ち上げ物Ａcｔｏｒポインタ */
} Carry_Status;

/*-----------------------------------------------------------------------
 *
 *	乗り物情報クラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
    signed char		direction;		/* 方向フラグ */
    Actor		*actor;			/* 乗り物Ａcｔｏｒポインタ */
} Ride_Status;

/*-----------------------------------------------------------------------
 *
 *	持ち物クラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
//    unsigned char	flag;
    Actor		*actor;
    Position_Angle	world;
} Catch;

/*-----------------------------------------------------------------------
 *
 *	プレイヤー性能クラス
 *
 *----------------------------------------------------------------------*/
enum {				/* 服タイプ */
    PLAYER_ABILITY_SUIT_GREEN,
    PLAYER_ABILITY_SUIT_RED,
    PLAYER_ABILITY_SUIT_BLUE
};
enum {				/* 盾タイプ */
    PLAYER_ABILITY_SHIELD_NON,
    PLAYER_ABILITY_SHIELD_WOOD,
    PLAYER_ABILITY_SHIELD_HYRAL,
    PLAYER_ABILITY_SHIELD_MIRROR
};
enum {				/* Ａボタンアイテム */
    PLAYER_ABILITY_A_ITEM_NON,
    PLAYER_ABILITY_A_ITEM_M_SWORD_DEMO,

    PLAYER_ABILITY_A_ITEM_FISHING_ROD,
    PLAYER_ABILITY_A_ITEM_SWORD,
    PLAYER_ABILITY_A_ITEM_MINISWORD,
    PLAYER_ABILITY_A_ITEM_LONGSWORD,
    PLAYER_ABILITY_A_ITEM_STICK,
    PLAYER_ABILITY_A_ITEM_HAMMER,
    PLAYER_ABILITY_A_ITEM_BOW,
    PLAYER_ABILITY_A_ITEM_FIRE_BOW,
    PLAYER_ABILITY_A_ITEM_ICE_BOW,
    PLAYER_ABILITY_A_ITEM_LIGHT_BOW,
    PLAYER_ABILITY_A_ITEM_DARK_BOW,
    PLAYER_ABILITY_A_ITEM_TWISTAR_BOW,
    PLAYER_ABILITY_A_ITEM_SOUL_BOW,
    PLAYER_ABILITY_A_ITEM_PACHI,
    PLAYER_ABILITY_A_ITEM_HOOK,
    PLAYER_ABILITY_A_ITEM_HOOK2,
    PLAYER_ABILITY_A_ITEM_BOMB,
    PLAYER_ABILITY_A_ITEM_BOMCHU,
    PLAYER_ABILITY_A_ITEM_BOOM,

    PLAYER_ABILITY_A_ITEM_ICE_MEDAL,
    PLAYER_ABILITY_A_ITEM_LIGHT_MEDAL,
    PLAYER_ABILITY_A_ITEM_DARK_MEDAL,
    PLAYER_ABILITY_A_ITEM_TWISTAR_MEDAL,
    PLAYER_ABILITY_A_ITEM_SOUL_MEDAL,
    PLAYER_ABILITY_A_ITEM_FIRE_MEDAL,
    PLAYER_ABILITY_A_ITEM_MAGIC_NATSU,
    
    PLAYER_ABILITY_A_ITEM_ELF_OKARINA,
    PLAYER_ABILITY_A_ITEM_OKARINA,

    PLAYER_ABILITY_A_ITEM_BOTTLE,
    PLAYER_ABILITY_A_ITEM_BOTTLE_FISH,
    PLAYER_ABILITY_A_ITEM_BOTTLE_FIRE,
    PLAYER_ABILITY_A_ITEM_BOTTLE_BUG,
    PLAYER_ABILITY_A_ITEM_BOTTLE_POH,
    PLAYER_ABILITY_A_ITEM_BOTTLE_BIGPOH,
    PLAYER_ABILITY_A_ITEM_BOTTLE_MAIL,

    PLAYER_ABILITY_A_ITEM_BOTTLE_RED,
    PLAYER_ABILITY_A_ITEM_BOTTLE_BLUE,
    PLAYER_ABILITY_A_ITEM_BOTTLE_GREEN,
    PLAYER_ABILITY_A_ITEM_BOTTLE_MILK,
    PLAYER_ABILITY_A_ITEM_BOTTLE_HALF_MILK,
    PLAYER_ABILITY_A_ITEM_BOTTLE_ELF,

    PLAYER_ABILITY_A_ITEM_LETTER,
    PLAYER_ABILITY_A_ITEM_EGG,
    PLAYER_ABILITY_A_ITEM_NIWATORI,
    PLAYER_ABILITY_A_ITEM_BEAN,
    PLAYER_ABILITY_A_ITEM_POCKET_EGG,
    PLAYER_ABILITY_A_ITEM_HANDY_COCK,
    PLAYER_ABILITY_A_ITEM_KOJIRO,
    PLAYER_ABILITY_A_ITEM_AYASHII_KINOKO,
    PLAYER_ABILITY_A_ITEM_AYASHII_DRUG,
    PLAYER_ABILITY_A_ITEM_NOKOGIRI,
    PLAYER_ABILITY_A_ITEM_BREAKE_GORON_SWORD,
    PLAYER_ABILITY_A_ITEM_SPECIAL_DRUG,
    PLAYER_ABILITY_A_ITEM_MEDAMA_FROG,
    PLAYER_ABILITY_A_ITEM_EYES_DRUG,
    PLAYER_ABILITY_A_ITEM_GORON_SWORD_CARD,

    PLAYER_ABILITY_A_ITEM_MASK_KI_TAN,
    PLAYER_ABILITY_A_ITEM_MASK_SKJ,
    PLAYER_ABILITY_A_ITEM_MASK_REDEAD,
    PLAYER_ABILITY_A_ITEM_MASK_RABIT,
    PLAYER_ABILITY_A_ITEM_MASK_GOLON,
    PLAYER_ABILITY_A_ITEM_MASK_ZOLA,
    PLAYER_ABILITY_A_ITEM_MASK_GELD,
    PLAYER_ABILITY_A_ITEM_MASK_TRUTH,

    PLAYER_ABILITY_A_ITEM_MAGIC_GRASS,
    PLAYER_ABILITY_A_ITEM_MAX
};
enum {
    PERFO_NORMAL_BOOTS,
    PERFO_HEAVY_BOOTS,
    PERFO_HOBA_BOOTS,
    PERFO_ROOM,
//    PERFO_DASH_BOOTS,
    PERFO_WATER_HEVY_BOOTS,
    PERFO_MAX
};
#define	PLAYER_ABILITY_A_ITEM_CHANGE_SUIT	(1)
#define	PLAYER_ABILITY_A_ITEM_CHANGE_SHIELD	(1<<1)
#define	PLAYER_ABILITY_A_ITEM_CHANGE_BOOTS	(1<<2)
#define	PLAYER_ABILITY_A_ITEM_CHANGE_SWORD	(1<<3)

typedef struct {
    signed char		suit;		/* 服 		    */
    signed char		sword;		/* 剣		    */
    signed char		shield;		/* 盾		    */
    signed char		boots;		/* ブーツ	    */
    signed char		item_ID;	/* アイテムＩＤＮｏ */
    signed char		A_item;		/* Ａボタンアイテム */
    unsigned char	next_item;	/* 次のアイテム     */
    signed char		old_boots;	/* 前フレームブーツ */
    signed char		now_A_item;	/* Ａボタンアイテム */

    unsigned char	change_flag;	/* アイテム変更フラグ */
} Player_Ability;

/*-----------------------------------------------------------------------
 *
 *	プレイヤーマスターソード装備チェック
 *
 *----------------------------------------------------------------------*/
#define	player_m_sword_check(game_play)	\
	(((Player_actor *)get_player_actor((game_play)))->player_ability.A_item == PLAYER_ABILITY_A_ITEM_SWORD)
    
/*-----------------------------------------------------------------------
 *
 *	プレイヤーヘビーブーツタイプチェック
 *
 *----------------------------------------------------------------------*/
#define	player_heavy_boots_check(game_play)	\
	(((Player_actor *)get_player_actor((game_play)))->player_ability.boots == PERFO_HEAVY_BOOTS)
    
/*-----------------------------------------------------------------------
 *
 *	フィッシングモードチェック
 *
 *----------------------------------------------------------------------*/
#define	player_fishing_mode_check(game_play)	\
	(((Player_actor *)get_player_actor((game_play)))->player_ability.A_item == PLAYER_ABILITY_A_ITEM_FISHING_ROD)
	    
/*-----------------------------------------------------------------------
 *
 *	プレイヤー入れ替えシェイプクラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	type;
    unsigned char	next_type;
    signed char		item_change_type;
    unsigned char	anime_type;
    unsigned char	L_hand;
    unsigned char	R_hand;
    unsigned char	carry;
    unsigned char	mask;
    Gfx			**R_hand_model;
    Gfx			**L_hand_model;
    Gfx			**carry_model;
    Gfx			**waist_model;
} Player_Shape;

enum {
    PLAYER_MASK_NON,
    PLAYER_MASK_KI_TAN,		/* キータンのお面 */
    PLAYER_MASK_SKJ,		/* ドクロのお面 */
    PLAYER_MASK_REDEAD,		/* こわそおなお面 */
    PLAYER_MASK_RABIT,		/* ウサギずきん */
    PLAYER_MASK_GOLON,		/* ゴロンのお面 */
    PLAYER_MASK_ZOLA,		/* ゾ─ラのお面 */
    PLAYER_MASK_GELD,		/* ゲルドのお面 */
    PLAYER_MASK_TRUTH,		/* まことの仮面 */
    PLAYER_MASK_MAX
};

/*-----------------------------------------------------------------------
 *
 *	ゲットアイテム入れ替えシェイプクラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
    unsigned char	flag;
    dma_t		dma;
    OSMesgQueue		mq;
    OSMesg		m;
    char		*Segment;
} Get_Item_Shape;

/*-----------------------------------------------------------------------
 *
 *	帽子アクションクラス
 *
 *----------------------------------------------------------------------*/
#define	HAT_JOINT_MAX	3

typedef struct {
    xyz_t	pos;
    short	angle_x;
    short	angle_y;
    float	speed_y;
} Hat_Status;
typedef struct {
    Hat_Status	status[HAT_JOINT_MAX+1];
} Hat_Info;

/*-----------------------------------------------------------------------
 *
 *	サブカメラクラス
 *
 *----------------------------------------------------------------------*/
typedef struct {
    short	ID;		/* サブカメラＩＤ */
    xyz_t	center;		/* 注目点 */
    xyz_t	eye;		/* 視点 */
    xyz_t	up;		/* ＵＰ */
    float	fovy;		/* 画角 */
} Sub_Camera;

/*-----------------------------------------------------------------------
 *
 *	年齢別データ
 *
 *----------------------------------------------------------------------*/
typedef struct {
    float			roof_bgcheck_offset_y;
    float			shape_shadow_size;
    float			anime_move_scale;
    float			stepup_max_high;
    float			stepup_swim_high;
    float			stepup_250_high;
    float			stepup_150_high;
    float			stepup_100_high;
    float			stepup_50_high;
    float			water_out_surface_y;
    float			water_surface_offset_y;
    float			water_dive_surface_y;
    float			deep_end_water_surface_offset_y;
    float			fall_ok_to_ground_high;
    float			Fclimb_init_to_wall_r;
    float			climb_to_wall_r;
    float			climb_end_check_y;
    
    s_xyz			climb_endAR_base_translate;
    s_xyz			climb_up_base_translate[4];
    s_xyz			climb_down_base_translate[4];
    s_xyz			climb_side_base_translate[4];
    
    u16				sound_voice_age_offset_data;
    u16				sound_SE_age_offset_data;
    
    SoftAnimTblRomTrsInfo	*demo_Tbox_open_anm;
    SoftAnimTblRomTrsInfo	*m_sword_start_anm;
    SoftAnimTblRomTrsInfo	*m_sword_end_anm;
    SoftAnimTblRomTrsInfo	*climb_startA_anm;
    SoftAnimTblRomTrsInfo	*climb_startB_anm;
    SoftAnimTblRomTrsInfo	*climb_up_anm[4];
    SoftAnimTblRomTrsInfo	*Fclimb_side_anm[2];
    SoftAnimTblRomTrsInfo	*climb_endA_anm[2];
    SoftAnimTblRomTrsInfo	*climb_endB_anm[2];
} Link_Age_Status;    
    
/*-----------------------------------------------------------------------
 *
 *	プレイヤークラス
 *
 *----------------------------------------------------------------------*/
enum {
    LINK_PARTS_WAIST,
    LINK_PARTS_R_LEG_A,
    LINK_PARTS_R_LEG_B,
    LINK_PARTS_R_FOOT,
    LINK_PARTS_L_LEG_A,
    LINK_PARTS_L_LEG_B,
    LINK_PARTS_L_FOOT,
    LINK_PARTS_HEAD,
    LINK_PARTS_HAT,
    LINK_PARTS_COLLAR,
    LINK_PARTS_L_ARM_A,
    LINK_PARTS_L_ARM_B,
    LINK_PARTS_L_HAND,
    LINK_PARTS_R_ARM_A,
    LINK_PARTS_R_ARM_B,
    LINK_PARTS_R_HAND,
    LINK_PARTS_CARRY,
    LINK_PARTS_CHEST1,
    LINK_PARTS_MAX
};

enum {
    POWER_DAMAGE_TYPE_NON,
    POWER_DAMAGE_TYPE_JUMP,
    POWER_DAMAGE_TYPE_BIG,
    POWER_DAMAGE_TYPE_ELEC,
    POWER_DAMAGE_TYPE_MAX
};
    
/*
 * 汎用変数宣言（弓矢）
 */
#define	bow_gen_scale		f_work[0]
#define	bow_gen_speed		f_work[1]
#define	bow_type		s_work

/*
 * 汎用変数宣言（剣，デクの棒）
 */
#define	sword_power		f_work[0]
#define	sword_stick_length	f_work[1]
#define	sword_stick_timer	s_work

/*
 * 汎用変数宣言（ロングソード）
 */
#define	sword_HP		f_work[1]

/*
 * 汎用変数宣言（フィッシングロッド）
 */
enum {
    FISHING_MODE_NON,
    FISHING_MODE_THROW,
    FISHING_MODE_FIGHT,
    FISHING_MODE_CATCH
};
#define	fishing_powerX		f_work[0]
#define	fishing_powerY		f_work[1]
#define	fishing_mode		s_work

//#define	JOINT_BUFF_SIZE	(((P_MAX_JOINT * sizeof(s_xyz)) + 2) + 15)
#define	JOINT_BUFF_SIZE	(((((P_MAX_JOINT * sizeof(s_xyz)) + 2) + 15)/16) * 16)

struct PLAYER_ACTOR {
    Actor		actor;				/* 基底クラス */
    
    Player_Ability	player_ability;			/* 性能クラス */
    Player_Shape	player_shape;			/* 入れ替えシェイプクラス */
    Get_Item_Shape	get_item_shape;			/* ゲットアイテムシェイプクラス */
    Skeleton_Info	skeleton;			/* スケルトンシェイプクラス */
    char		now_joint[JOINT_BUFF_SIZE]; 	/* アニメーションデータバッファ */
    char		morf_joint[JOINT_BUFF_SIZE]; 	/* アニメーションデータバッファ */
    char		work_joint[JOINT_BUFF_SIZE]; 	/* アニメーションデータバッファ */
    Eye_Anime		eye_anime;			/* 目アニメーションクラス */
    Catch		l_hand;				/* 左手持ち物クラス */
    Catch		r_hand;				/* 右手持ち物クラス */
    Hat_Info		hat;				/* 帽子アクションクラス */
    
    Door_Status		door;				/* ドア情報クラス */
    Carry_Status	carry;				/* 持ち上げ情報クラス */
    Ride_Status		ride;				/* 乗り物情報クラス */
    Demo_Play_Status	demo_play;			/* デモ再生情報クラス */
    Sub_Camera		sub_camera;			/* サブカメラクラス */
    
    ClObjPipe 		acoc_info;			/* コリジョン情報 Obj Collision */
    ClObjSwrd		at_info[2]; 			/* 		  AT Collision */
    ClObjSwrd		shield_info; 			/* 		  Shield Collision */

    Camera_Parameter	camera_parameter;		/* カメラへの情報 */
    int 		blure_effect_index;	 	/* エフェクトの剣ブラ─のインデックス */
    
    void		(*process)(			/* 処理関数ポインタ */
	Player_actor *,
	Game_play *
    );

    Link_Age_Status	*link_age_status;		/* 年齢別データポインタ */
    unsigned int	action;				/* 状態フラグ */
    unsigned int	action2;			/* 状態フラグ２ */

    Actor		*anchor_request_actor;		/* 注目要求Ａｃｔｏｒポインタ */
    Actor		*boom_actor;			/* ブーメランＡｃｔｏｒポインタ */

    Actor		*elf_actor;			/* 妖精Ａｃｔｏｒポインタ */
    signed short	elf_message;			/* 妖精のメッセージＮｏ */
    
//    unsigned char	parallel_timer;			/* 平行カメラタイマー */
    unsigned char	action3;			/* 状態フラグ３ */

    signed char		put_item;			/* 欲しいアイテム */
    Actor		*talk_actor;			/* 会話相手のＡｃｔｏｒポインタ */
    float		talk_distance;			/* 会話相手との距離 */

    Actor		*dowsing_actor;			/* ダウジンクのＡｃｔｏｒポインタ */
    float		dowsing_counter;		/* ダウジングカウンター */
    float		dowsing_distance;		/* ダウジングとの距離 */

    Actor		*okarina_actor;			/* オカリナモード要求Ａｃｔｏｒポインタ */
    
    signed char		inter_anime_couter;		/* インターバルアニメーションカウンター */
    unsigned char	look_mode;			/* 主観モードフラグ */
    
    unsigned short	anime_angle_status;		/* 目線，首，胴体方向制御フラグ */
//    s_xyz		eye_speed;			/* 目線移動スピード */
    short		body_offset_angle_y;
    short		pad1;
    short		pad2;
    s_xyz		neck_angle;			/* 首方向 */
    s_xyz		body_angle;			/* 胴体方向 */
    short		global_angle_x;			/* グローバルＸ方向 */
    float		display_offset_y;		/* 表示補正オフセットＹ */
    
    Skeleton_Info	uperbody_skeleton;		/* 上半身スケルトンシェイプクラス */
    char		uperbody_now_joint[JOINT_BUFF_SIZE]; /* アニメーションデータバッファ */
    char		uperbody_morf_joint[JOINT_BUFF_SIZE]; /* アニメーションデータバッファ */
    int			(*uperbody_process)(		/* 上半身処理関数ポインタ */
	Player_actor *,
	Game_play *
    );
    float		uperbody_add_ratio;		/* 上半身アニメーション合成補間率 */
    short		uperbody_counter;		/* 上半身処理汎用カウンタ */
    signed char		uperbody_flag;			/* 上半身処理汎用フラグ */
    
    unsigned char	to_free_timer;			/* 装備解除タイマー */
    float		action_speedF;			/* アクションスピード */
    short		action_angle_y;			/*           Ｙ方向 */

    short		parallel_angle_y;		/* 平行カメラモード注目方向 */

    unsigned short	swim_deep_time;			/* 潜水時間 */

    signed char		kiru_type;			/* 剣攻撃タイプ */
    signed char		sword_attack;			/* 剣攻撃フラグ */
    signed char		combo_key;			/* 剣攻撃キー入力フラグ */
    unsigned char	combo_counter;			/* 剣攻撃カウンター */
    unsigned char	command_counter;		/* コマンド技用カウンター */
    signed char		command_stick_dir[4];		/* コマンド技用キーバッファ */
    signed char		command_stick_camera_dir[4];	/* コマンド技用キーバッファ */

    signed char		flag;				/* 汎用フラグ */
    short		counter;			/* 汎用カウンター */
    float		ripple_set_counter;		/* 波紋セット用カウンター */
    float		f_work[2];			/* 汎用変数 */
    short		s_work;				/*    ”    */
    
    signed char		get_item_no;			/* タイプＡゲットアイテムシェイプＮｏ */
    unsigned char	get_item_counter;		/*               ”              表示用カウンター */
    
    float		run_anime_morf;			/* 走りアニメーションフラグ */ 
    float		run_anime_frame;		/* 走りアニメーションフレームカウンター */
    float		normal_anchor_ratio;		/* ノーマル，注目モードアニメーション補間値 */
    float		anchor_LR_ratio;		/* 注目モード停止アニメーション補間値 */
    float		anchor_LR_aim_ratio;		/*                                  */
    float		horse_offset_y;			/* 乗馬オフセットＹ値 */
    short		anchor_angle_speed;		/* 注目ターンスピード */
    short		turn_angle_speed;		/* ターンスピード */
    
    float		max_speedF;			/* 最大移動速度 */
    float		wall_high;			/* 壁高さ */
    float		to_wall_r;			/* 壁距離 */
    unsigned char	wall_high_type;			/* 壁高さタイプ(0:no hit 1:51-100 2:101-150 3:151-250)  */
    unsigned char	wall_hit_counter;		/* 壁当り継続カウンター */
    unsigned char	talk_end_timer;			/* 会話終了後タイマー */
    unsigned char	fog_set_counter;		/* フォグセットカウンター */
    
    unsigned char	mini_damage_timer;		/* 小ダメージタイマー */
    unsigned char	electric_timer;			/* 電撃ビリビリタイマー */
    unsigned char	work_buffer;			/* 汎用バッファ */
    unsigned char	landing_timer;			/* 落下タイマー */
    
    short		landing_top_y;			/* 落下開始Ｙ座標 */
    short		landing_high;			/* 落下高さ */
    short		ground_angle_x;			/* 地面のＸ傾斜角度 */
    short		ground_angle_z;			/*       Ｚ傾斜角度 */
    short		walk_ground_angle_x;		/* 歩きアニメーション用地面の傾斜角度 */
    u16			sound_ground_code;		/* 地面サウンド用コード */
    
    unsigned char	power_damage;			/* 外力ダメージ値 */
    unsigned char	power_flag;			/* 外力フラグ */
    short		power_angle_y;			/* 外力Ｙ方向 */
    float		power_speedF;			/* 外力ＸＺ平面速度 */
    float		power_speed_y;			/* 外力Ｙ方向速度 */

    float		environment_power_speedF;	/* 環境パワースピード */
    short		environment_power_angle_y;	/* 環境パワー方向 */

    short		swim_deep_counter;		/* 潜水カウンター */

    SWORD_POS_S		sword_pos[3];			/* 剣の位置データ保持 */
    xyz_t		parts_pos[LINK_PARTS_MAX];	/* パーツ座標 */
    MtxF		sword_matrix;			/* 剣のモデル行列 */
    MtxF		shield_matrix;			/* 盾のモデル行列 */

    unsigned char	fire_set_flag;			/* 炎ダメージエフェクトセットフラグ */
    unsigned char	fire_timer[LINK_PARTS_MAX];	/* 炎ダメージタイマー */

    unsigned char	shoot_timer;			/* 飛び道具発射タイマー */
    
    void		(*demo_init_proc)(		/* デモ初期設定関数ポインタ */
	Game_play *,
	Player_actor *
    );

    signed char		no_damage_timer;		/* ノーダメージタイマー */
    unsigned char	ground_attribute_counter;	/* 同一床コードチェックフレーム */

    unsigned char	old_ground_auto_jump_type;	/* 前フレーム地面オートジャンプコード */
    unsigned char	old_ground_attribute;		/* 前フレーム床コード */

    float		old_stick_length;		/* 前フレームスティック入力長さ */
    short		old_stick_angle;		/* 前フレームスティック入力絶対角度 */

    u16			old_sound_ground_code;		/* 前フレーム地面サウンド用コード */
    short		scene_change_landing_top_y;	/* シーン切り替え用落下開始Ｙ座標 */
    signed char		down_restart_counter;		/* ダウン再スタートチェックカウンター */
    unsigned char	elf_restart_timer;		/* 妖精復活再スタートタイマー */
    xyz_t		old_waist_pos;			/* 前フレーム腰座標 */
};

/*-----------------------------------------------------------------------
 *
 *	 プレイヤー外部参照宣言
 *
 *----------------------------------------------------------------------*/
extern void Player_actor_ct(Actor *thisx, Game *game);
extern void Player_actor_dt(Actor *thisx, Game *game);
extern void Player_actor_move(Actor *thisx, Game *game);
extern void Player_actor_draw(Actor *thisx, Game *game);

/*-----------------------------------------------------------------------
 *
 *	プレイヤー魚逃がしチェック
 *
 *----------------------------------------------------------------------*/
#define	player_fish_out_check(game_play)	\
	Ovl_Proc_Info_Call((game_play), Player_fish_out_check)((game_play))
//extern int player_fish_out_check(
//    Game_play *game_play
//);

/*-----------------------------------------------------------------------
 *
 *	フィッシングモード初期設定
 *
 *----------------------------------------------------------------------*/
#define	to_fishing_set(game_play)	\
	Ovl_Proc_Info_Call((game_play), Player_to_fishing_set)((game_play))
//extern int to_fishing_set(
//    Game_play *game_play
//);

/*-----------------------------------------------------------------------
 *
 *	リーデッド捕まれ初期設定
 *
 *----------------------------------------------------------------------*/
#define	to_re_dead_attack_set(game_play, this)	\
	Ovl_Proc_Info_Call((game_play), Player_to_re_dead_attack_set)((game_play), (this))
//extern int to_re_dead_attack_set(
//    Game_play    *game_play,
//    Player_actor *this
//);

/*-----------------------------------------------------------------------
 *
 *	プレイヤーデモセット
 *
 *----------------------------------------------------------------------*/
#define	player_demo_set(game_play, target_actor, mode)	\
	Ovl_Proc_Info_Call((game_play), Player_demo_set)((game_play), (target_actor), (mode))
//extern int player_demo_set(
//     Game_play *game_play,
//    Actor     *target_actor,
//    int       mode
//);

/*-----------------------------------------------------------------------
 *
 *	停止中処理初期設定
 *
 *----------------------------------------------------------------------*/
#define	to_wait_set(this, game_play)	\
	Ovl_Proc_Info_Call((game_play), Player_to_wait_set)((this), (game_play))
//extern void to_wait_set(
//    Player_actor *this,
//    Game_play    *game_play
//);

/*-----------------------------------------------------------------------
 *
 *	ダメージセット
 *
 *----------------------------------------------------------------------*/
#define	to_damage_set(game_play, damage_point)	\
	Ovl_Proc_Info_Call((game_play), Player_to_damage_set)((game_play), (damage_point))
//extern int to_damage_set(
//    Game_play *game_play,
//    int       damage_point
//);

/*-----------------------------------------------------------------------
 *
 *	会話モードへ
 *
 *----------------------------------------------------------------------*/
#define	player_to_talk_set(game_play, talk_actor)	\
	Ovl_Proc_Info_Call((game_play), Player_to_talk_set)((game_play), (talk_actor))
//extern void player_to_talk_set(
//    Game_play *game_play,
//    Actor     *talk_actor
//);

/************************************************************************
 *
 *	プレイヤークラス 初期設定
 *
 ************************************************************************/
#define Player_actor_init(this, game_play, skeleton)	\
	Ovl_Proc_Info_Call((game_play), Player_init)((this), (game_play), (skeleton))
//extern void Player_actor_init(
//    Player_actor   *this,
//    Game_play      *game_play,
//    Rigid_Mdl_Info *skeleton
//);

/************************************************************************
 *
 *	プレイヤー動作処理
 *
 ************************************************************************/
#define	Player_actor_proc(this, game_play, pad)	\
	Ovl_Proc_Info_Call((game_play), Player_proc)((this), (game_play), (pad))
//extern void Player_actor_proc(
//    Player_actor *this,
//    Game_play    *game_play,
//    pad_t        *pad
//);



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_player.h end ***/
