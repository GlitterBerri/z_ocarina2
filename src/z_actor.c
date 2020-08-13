/*
 * $Id: z_actor.c,v 1.1.1.1 2003/03/10 22:42:46 tong Exp $
 * 
 * $Log: z_actor.c,v $
 * Revision 1.1.1.1  2003/03/10 22:42:46  tong
 * new OBJ tree for ocarina from Nintendo
 *
 * Revision 2.8  2001/04/04  07:21:47  zelda
 * ドルフィンエミュレータ用仮ぐみ版 CICと64DD対応部分をはずしたバージョン
 *
 * Revision 2.7  1999-03-08 21:58:06+09  morita
 * *** empty log message ***
 *
 * Revision 2.6  1998-11-09 17:44:15+09  tarukado
 * *** empty log message ***
 *
 * Revision 2.5  1998-10-28 16:08:30+09  okajima
 * *** empty log message ***
 *
 * Revision 2.4  1998/10/28 06:17:39  okajima
 * *** empty log message ***
 *
 * Revision 2.3  1998/10/28 05:00:17  okajima
 * *** empty log message ***
 *
 * Revision 2.2  1998/10/28 04:58:34  okajima
 * ちめいテロップ、ボスめいひょうじ PAL たいおう
 *
 * Revision 2.1  1998/10/22 11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.723  1998/10/20 10:16:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.722  1998-10-19 19:52:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.721  1998-10-17 23:36:48+09  zelda
 * *** empty log message ***
 *
 * Revision 1.720  1998-10-16 18:43:00+09  hayakawa
 * 条件コンパイルを変更
 *
 * Revision 1.719  1998-10-16 18:17:30+09  umemiya
 * ドアをデモ中止めないよう変更
 *
 * Revision 1.718  1998-10-16 17:12:35+09  hayakawa
 * TRAP_ACTOR
 * count_gDPNoOp
 *
 * Revision 1.717  1998-10-16 13:42:32+09  matutani
 * デバッグモードをROM_Dにした。
 *
 * Revision 1.716  1998-10-16 02:28:01+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.715  1998-10-15 17:20:26+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.714  1998-10-15 13:31:45+09  matutani
 * *** empty log message ***
 *
 * Revision 1.713  1998-10-15 03:06:53+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.712  1998-10-14 17:02:03+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.711  1998-10-14 01:46:53+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.710  1998-10-14 00:29:46+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.709  1998-10-13 18:02:57+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.708  1998-10-13 11:27:48+09  matutani
 * DREG外しました。
 *
 * Revision 1.707  1998-10-13 01:06:12+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.706  1998-10-12 16:29:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.705  1998-10-10 14:35:22+09  zelda
 * *** empty log message ***
 *
 * Revision 1.704  1998-10-09 17:13:12+09  goron
 * *** empty log message ***
 *
 * Revision 1.703  1998-10-09 15:05:38+09  goron
 * *** empty log message ***
 *
 * Revision 1.702  1998-10-09 15:04:28+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.701  1998-10-09 01:26:10+09  goron
 * *** empty log message ***
 *
 * Revision 1.700  1998-10-08 13:57:23+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.699  1998-10-07 23:55:12+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.698  1998-10-07 13:22:15+09  sakakibara
 * *** empty log message ***
 *
 * Revision 1.697  1998-10-07 10:03:11+09  morita
 * *** empty log message ***
 *
 * Revision 1.696  1998-10-07 00:56:39+09  matutani
 * *** empty log message ***
 *
 * Revision 1.695  1998-10-06 15:16:21+09  matutani
 * *** empty log message ***
 *
 * Revision 1.694  1998-10-06 00:59:32+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.693  1998-10-04 21:29:35+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.692  1998-10-04 01:01:30+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.691  1998-10-04 00:44:42+09  goron
 * *** empty log message ***
 *
 * Revision 1.690  1998-10-03 22:45:17+09  umemiya
 * スイッチ関連の旧関数を削除
 *
 * Revision 1.689  1998-10-03 22:42:52+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.688  1998-10-03 01:49:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.687  1998-10-02 01:36:07+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.686  1998-10-01 20:38:13+09  komatu
 * *** empty log message ***
 *
 * Revision 1.685  1998-10-01 16:57:43+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.684  1998-10-01 16:34:36+09  komatu
 * *** empty log message ***
 *
 * Revision 1.683  1998-10-01 00:45:19+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.682  1998-10-01 00:35:44+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.681  1998-09-30 19:58:30+09  okajima
 * *** empty log message ***
 *
 * Revision 1.680  1998-09-30 19:58:05+09  okajima
 * *** empty log message ***
 *
 * Revision 1.679  1998-09-30 19:55:38+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.678  1998-09-30 01:00:06+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.677  1998-09-29 00:19:36+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.676  1998-09-27 20:31:25+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.675  1998-09-27 01:27:19+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.674  1998-09-26 16:02:46+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.673  1998-09-26 12:11:20+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.672  1998-09-26 01:14:50+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.671  1998-09-25 01:49:01+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.670  1998-09-24 23:16:49+09  okajima
 * 燃える”ガノン”の字、ボツになる。
 *
 * Revision 1.669  1998-09-24 22:42:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.668  1998-09-24 10:34:41+09  soejima
 * *** empty log message ***
 *
 * Revision 1.667  1998-09-24 00:41:52+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.666  1998-09-23 16:46:58+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.665  1998-09-23 15:49:52+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.664  1998-09-23 11:10:47+09  hayakawa
 * メッセージが出すぎるのを抑制
 * ヤバイメッセージに色つけた
 *
 * Revision 1.663  1998-09-23 00:06:52+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.662  1998-09-23 00:04:24+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.661  1998-09-22 14:02:53+09  morita
 * ActorQuakeRumbleSet追加
 *
 * Revision 1.660  1998-09-22 13:23:48+09  matutani
 * *** empty log message ***
 *
 * Revision 1.659  1998-09-22 12:00:30+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.658  1998-09-22 01:11:26+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.657  1998-09-22 00:38:27+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.656  1998-09-20 02:22:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.655  1998-09-19 14:59:18+09  umemiya
 * 眼鏡オブジェの部屋切替時の部屋チェック
 *
 * Revision 1.654  1998-09-19 00:55:55+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.653  1998-09-18 00:46:45+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.652  1998-09-16 22:45:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.651  1998-09-16 11:44:55+09  umemiya
 * Actor_timer_level_SE_set追加
 *
 * Revision 1.650  1998-09-16 00:57:30+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.649  1998-09-15 00:06:04+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.648  1998-09-14 23:00:36+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.647  1998-09-12 19:10:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.646  1998-09-12 13:33:56+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.645  1998-09-12 13:26:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.644  1998-09-12 13:20:23+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.643  1998-09-12 00:19:56+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.642  1998-09-11 00:38:53+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.641  1998-09-10 14:57:26+09  goron
 * *** empty log message ***
 *
 * Revision 1.640  1998-09-10 14:56:26+09  goron
 * *** empty log message ***
 *
 * Revision 1.639  1998-09-10 11:48:45+09  morita
 * *** empty log message ***
 *
 * Revision 1.638  1998-09-10 11:42:13+09  goron
 * *** empty log message ***
 *
 * Revision 1.637  1998-09-10 11:19:52+09  goron
 * *** empty log message ***
 *
 * Revision 1.636  1998-09-10 00:26:53+09  goron
 * *** empty log message ***
 *
 * Revision 1.635  1998-09-09 00:45:47+09  goron
 * *** empty log message ***
 *
 * Revision 1.634  1998-09-08 00:18:34+09  goron
 * *** empty log message ***
 *
 * Revision 1.633  1998-09-07 20:34:56+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.632  1998-09-07 19:30:14+09  goron
 * *** empty log message ***
 *
 * Revision 1.631  1998-09-07 17:25:27+09  goron
 * *** empty log message ***
 *
 * Revision 1.630  1998-09-07 12:21:44+09  okajima
 * *** empty log message ***
 *
 * Revision 1.629  1998-09-07 11:53:33+09  goron
 * *** empty log message ***
 *
 * Revision 1.628  1998-09-05 23:17:54+09  goron
 * *** empty log message ***
 *
 * Revision 1.627  1998-09-05 00:10:44+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.626  1998-09-04 19:04:24+09  goron
 * *** empty log message ***
 *
 * Revision 1.625  1998-09-04 13:47:06+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.624  1998-09-04 10:32:13+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.623  1998-09-04 10:26:23+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.622  1998-09-04 10:20:09+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.621  1998-09-03 23:58:10+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.620  1998-09-03 00:22:12+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.619  1998-09-02 00:18:23+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.618  1998-09-01 09:29:20+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.617  1998-09-01 00:30:00+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.616  1998-08-29 00:19:24+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.615  1998-08-28 20:07:28+09  hayakawa
 * メガネ表示修正＆整理
 *
 * Revision 1.614  1998-08-28 00:35:49+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.613  1998-08-27 21:27:50+09  matutani
 * *** empty log message ***
 *
 * Revision 1.612  1998-08-27 21:21:09+09  matutani
 * *** empty log message ***
 *
 * Revision 1.611  1998-08-27 18:40:11+09  matutani
 * *** empty log message ***
 *
 * Revision 1.610  1998-08-27 18:36:29+09  matutani
 * *** empty log message ***
 *
 * Revision 1.609  1998-08-27 16:22:31+09  matutani
 * BGCheckCollection_setRideStatus()の引数変更
 *
 * Revision 1.608  1998-08-27 16:01:32+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.607  1998-08-27 00:24:52+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.606  1998-08-25 17:55:39+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.605  1998-08-25 00:28:26+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.604  1998-08-24 21:02:24+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.603  1998-08-22 19:31:47+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.602  1998-08-22 18:45:10+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.601  1998-08-22 18:31:49+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.600  1998-08-20 19:31:17+09  hayakawa
 * actor_dlftbls_init, actor_dlftbls_initを呼ぶ
 *
 * Revision 1.599  1998-08-20 18:22:36+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.598  1998-08-20 13:10:01+09  matutani
 * *** empty log message ***
 *
 * Revision 1.597  1998-08-20 10:36:55+09  matutani
 * *** empty log message ***
 *
 * Revision 1.596  1998-08-20 00:48:27+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.595  1998-08-19 22:23:43+09  umemiya
 * 影の表示関数を少し変更（問題発生するかも？）
 *
 * Revision 1.594  1998-08-17 21:58:52+09  hayakawa
 * テスト＆ソース整理
 *
 * Revision 1.593  1998-08-17 15:33:24+09  matutani
 * 壁チェック新バージョン
 *
 * Revision 1.592  1998-08-14 17:02:04+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.591  1998-08-13 17:51:40+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.590  1998-08-13 00:46:37+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.589  1998-08-11 10:17:42+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.588  1998-08-11 00:55:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.587  1998-08-08 23:55:59+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.586  1998-08-08 21:37:50+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.585  1998-08-08 19:29:00+09  hayakawa
 * CLOSE_DISP問題解決
 *
 * Revision 1.584  1998-08-08 00:27:59+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.583  1998-08-06 22:47:04+09  hayakawa
 * countチェック
 * eyeチェック
 *
 * Revision 1.582  1998-08-04 15:25:25+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.581  1998-08-03 22:48:26+09  soejima
 * *** empty log message ***
 *
 * Revision 1.580  1998-08-01 16:54:19+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.579  1998-07-31 22:50:18+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.578  1998-07-31 21:01:37+09  hayakawa
 * 未使用マクロを削除
 *
 * Revision 1.577  1998-07-30 23:17:54+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.576  1998-07-30 09:35:49+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.575  1998-07-25 22:55:55+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.574  1998-07-25 18:24:32+09  matutani
 * Dustのプロトタイプ宣言を直した。
 *
 * Revision 1.573  1998-07-24 22:57:12+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.572  1998-07-23 23:13:27+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.571  1998-07-22 13:41:43+09  hayakawa
 * 魔法の眼鏡（青）
 *
 * Revision 1.570  1998-07-20 22:39:28+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.569  1998-07-20 17:37:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.568  1998-07-17 22:55:28+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.567  1998-07-16 19:56:14+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.566  1998-07-16 11:47:39+09  umemiya
 * 鍵表示関数バグ修正
 *
 * Revision 1.565  1998-07-15 22:56:31+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.564  1998-07-14 23:10:15+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.563  1998-07-13 22:56:33+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.562  1998-07-13 22:51:31+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.561  1998-07-10 23:12:05+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.560  1998-07-10 22:47:41+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.559  1998-07-10 11:02:43+09  umemiya
 * 鍵表示に邪神像用追加
 *
 * Revision 1.558  1998-07-09 23:08:05+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.557  1998-07-08 17:45:40+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.556  1998-07-08 16:49:35+09  morita
 * *** empty log message ***
 *
 * Revision 1.555  1998-07-08 16:31:33+09  sumiyosi
 * ＮＰＣ共通ルーチン追加。
 *
 * Revision 1.554  1998-07-07 22:56:12+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.553  1998-07-06 22:54:38+09  sumiyosi
 * npc_talk の戻り値変更。
 *
 * Revision 1.552  1998-07-04 23:54:18+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.551  1998-07-02 23:39:13+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.550  1998-07-02 20:15:04+10  okajima
 * *** empty log message ***
 *
 * Revision 1.549  1998-07-02 11:58:07+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.548  1998-07-01 21:11:20+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.547  1998-07-01 22:03:34+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.546  1998-07-01 15:37:33+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.545  1998-06-30 16:21:05+10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.544  1998-06-29 20:57:51+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.543  1998-06-29 20:10:58+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.542  1998-06-29 17:08:14+10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.541  1998-06-26 21:40:07+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.540  1998-06-25 21:52:50+10  zelda
 * メモリの使用状況を分かりやすくした
 *
 * Revision 1.539  1998-06-25 16:45:36+09  matutani
 * CollisionCheck_Status_Clear()を削除
 * status_infoを使っています。
 *
 * Revision 1.538  1998-06-25 16:40:36+09  matutani
 * CollisionCheck_Damage_ct()削除
 * status_infoを使っています。
 *
 * Revision 1.537  1998-06-25 16:38:13+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.536  1998-06-25 15:39:27+09  matutani
 * actor->collision関連掃除
 *
 * Revision 1.535  1998-06-25 14:57:09+09  matutani
 * Actor_talk_request()のsize_rセットをstatus_info.rに変更
 *
 * Revision 1.534  1998-06-24 22:39:22+09  okajima
 * 地名テロップ、ボス名の日本語、英語切り替え処理追加
 *
 * Revision 1.533  1998-06-23 22:57:31+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.532  1998-06-20 22:54:07+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.531  1998-06-19 20:18:38+09  ogawa
 * Actor_world_to_eye()アングルもコピーするようにした。
 * 苦情は岩脇まで
 *
 * Revision 1.530  1998-06-19 10:01:27+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.529  1998-06-18 19:25:56+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.528  1998-06-16 16:59:28+09  kuzuhara
 * デバッグ作業
 * まつたに
 *
 * Revision 1.527  1998-06-15 22:54:42+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.526  1998-06-12 23:22:44+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.525  1998-06-11 17:03:06+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.524  1998-06-11 16:11:57+09  hayakawa
 * 非開放型アクターをメモリブロックの後ろから割り当てるようにした
 *
 * Revision 1.523  1998-06-11 10:42:46+09  umemiya
 * EN_DOOR_KEY_TIMEを.hに移動
 *
 * Revision 1.522  1998-06-10 22:57:57+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.521  1998-06-10 10:48:51+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.520  1998-06-09 23:20:07+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.519  1998-06-09 22:44:02+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.518  1998-06-08 10:38:26+09  nisiwaki
 * Setpos_HiliteReflect_xlu_init
 *
 * Revision 1.517  1998-06-05 10:32:01+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.516  1998-06-03 22:58:13+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.515  1998-06-03 09:49:00+09  hayakawa
 * オーバーレイ解放禁止のフラグを逆転（元に戻した）
 *
 * Revision 1.514  1998-06-02 22:55:08+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.513  1998-06-01 22:33:24+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.512  1998-05-30 22:49:46+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.511  1998-05-29 13:51:01+09  hayakawa
 * draw_statusメンバに対応
 * アクター解放テストのデフォルトを『解放しない』にした
 *
 * Revision 1.510  1998-05-28 21:11:49+09  hayakawa
 * アクタープログラム解放処理もろもろ
 * （まだテスト中）
 *
 * Revision 1.509  1998-05-27 16:29:18+09  hayakawa
 * 条件コンパイル整理
 *
 * Revision 1.508  1998-05-27 14:18:03+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.507  1998-05-26 18:19:22+09  matutani
 * 変更中止
 *
 * Revision 1.506  1998-05-26 12:07:49+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.505  1998-05-25 22:04:00+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.504  1998/05/25 06:36:42  iwawaki
 * *** empty log message ***
 *
 * Revision 1.503  1998/05/25 02:11:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.502  1998/05/21 11:28:02  iwawaki
 * *** empty log message ***
 *
 * Revision 1.501  1998/05/21 11:00:14  tarukado
 * *** empty log message ***
 *
 * Revision 1.500  1998/05/21 06:40:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.499  1998/05/20 13:44:51  hayakawa
 * 自分だけの変更
 *
 * Revision 1.498  1998-05-20 20:42:37+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.497  1998/05/19 14:36:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.496  1998/05/19 10:08:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.495  1998/05/18 06:34:52  umemiya
 * 注目照準表示処理を一部変更
 *
 * Revision 1.494  1998-05-18 10:03:53+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.493  1998/05/16 11:09:53  iwawaki
 * *** empty log message ***
 *
 * Revision 1.492  1998/05/15 14:00:30  iwawaki
 * *** empty log message ***
 *
 * Revision 1.491  1998/05/14 11:33:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.490  1998/05/13 13:56:26  iwawaki
 * *** empty log message ***
 *
 * Revision 1.489  1998/05/13 08:18:28  tarukado
 * *** empty log message ***
 *
 * Revision 1.488  1998/05/13 07:45:41  iwawaki
 * *** empty log message ***
 *
 * Revision 1.487  1998/05/13 03:14:51  matutani
 * *** empty log message ***
 *
 * Revision 1.486  1998-05-11 22:36:59+09  matutani
 * *** empty log message ***
 *
 * Revision 1.485  1998-05-11 22:25:31+09  matutani
 * moveBG改良？
 *
 * Revision 1.484  1998-05-11 11:42:47+09  matutani
 * DEBUG_P変更
 *
 * Revision 1.483  1998-05-09 22:09:39+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.482  1998/05/08 13:59:18  iwawaki
 * *** empty log message ***
 *
 * Revision 1.481  1998/05/07 13:56:10  matutani
 * *** empty log message ***
 *
 * Revision 1.480  1998-05-07 16:02:36+09  hayakawa
 * アクターのロード用のメモリがない場合にハングアップせずに NULL で復帰するようにした
 *
 * Revision 1.479  1998-05-07 12:00:41+09  matutani
 * DEBUG_P追加 draw終了
 *
 * Revision 1.478  1998-05-06 23:28:39+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.477  1998/05/06 04:09:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.476  1998/05/05 08:20:31  tarukado
 * *** empty log message ***
 *
 * Revision 1.475  1998/05/02 08:40:52  matutani
 * 変更無し（デバッグ DEBUG_P用処理(printf)追加)
 *
 * Revision 1.474  1998-05-01 17:08:36+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.473  1998/05/01 05:51:14  umemiya
 * *** empty log message ***
 *
 * Revision 1.472  1998-04-30 22:06:16+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.471  1998/04/30 06:43:48  matutani
 * *** empty log message ***
 *
 * Revision 1.470  1998-04-29 23:00:23+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.469  1998/04/29 12:03:05  iwawaki 
 * *** empty log message ***
 *
 * Revision 1.468  1998/04/29 10:12:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.467  1998/04/29 07:13:44  tarukado
 * *** empty log message ***
 *
 * Revision 1.466  1998/04/29 07:06:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.465  1998/04/28 05:15:49  tarukado
 * *** empty log message ***
 *
 * Revision 1.464  1998/04/27 14:17:26  iwawaki
 * *** empty log message ***
 *
 * Revision 1.463  1998/04/27 06:16:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.462  1998/04/27 02:58:36  hayakawa
 * gamealloc_malloc, gamealloc_freeの残骸抹消
 * データバンク無し！の情報追加
 *
 * Revision 1.461  1998-04-24 13:51:30+09  matutani
 * PRINTFを追加(DEBUG_P)
 *
 * Revision 1.460  1998-04-23 22:13:52+09  hayakawa
 * PRINTF消した
 *
 * Revision 1.459  1998-04-22 21:04:48+09  okajima
 * *** empty log message ***
 *
 * Revision 1.458  1998/04/22 10:41:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.457  1998/04/22 01:23:28  hayakawa
 * コンストラクタで、絶対魔法領域をNULLにしていなかったため、
 * デストラクタで、Free使用として落ちていた。
 *
 * Revision 1.456  1998-04-21 22:38:11+09  hayakawa
 * C++エラー対策
 *
 * Revision 1.455  1998-04-21 18:58:49+09  matutani
 * moveBG情報クリア位置変更(move後すぐ）
 *
 * Revision 1.454  1998-04-21 18:29:11+09  matutani
 * *** empty log message ***
 *
 * Revision 1.453  1998-04-21 16:42:40+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.452  1998/04/21 02:07:43  hayakawa
 * Ａｃｔｏｒクラス デストラクトがなくてもとりあえずとおるようにした
 *
 * Revision 1.451  1998-04-18 23:42:48+09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.450  1998/04/17 07:11:39  okajima
 * *** empty log message ***
 *
 * Revision 1.449  1998/04/17 05:55:50  okajima
 * *** empty log message ***
 *
 * Revision 1.448  1998/04/17 02:04:25  soejima
 * メッセージＮｏ．上位修正
 *
 * Revision 1.447  1998-04-16 21:23:02+10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.446  1998/04/15 04:40:36  iwawaki
 * *** empty log message ***
 *
 * Revision 1.445  1998/04/14 14:20:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.444  1998/04/14 13:34:44  hayakawa
 * 絶対魔法領域を必要になったときにとるようにした
 *
 * Revision 1.443  1998-04-14 20:20:07+09  hayakawa
 * Actor_info に 絶対魔法領域を追加準備
 *
 * Revision 1.442  1998-04-14 17:36:30+09  hayakawa
 * 魔法入れ替えテスト
 *
 * Revision 1.441  1998-04-13 11:38:35+09  umemiya
 * *** empty log message ***
 *
 * Revision 1.440  1998-04-11 00:17:13+10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.439  1998/04/10  01:18:20  hayakawa
 * プロトタイプのヘッダを追加
 * Ｃ＋＋のエラーを取った
 *
 * Revision 1.438  1998-04-10 09:51:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.437  1998/04/09  14:38:06  morita
 * *** empty log message ***
 *
 * Revision 1.436  1998/04/09  09:35:21  hayakawa
 * SREG(21)をshrink_window_getnowval()に変更（直接みないように）
 *
 * Revision 1.435  1998/04/06  10:17:13  morita
 * *** empty log message ***
 *
 * Revision 1.434  1998/04/04  14:03:09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.433  1998/04/03  01:44:57  soejima
 * メッセージ 設定 テスト
 *
 * Revision 1.432  1998/04/03  01:19:44  okajima
 * *** empty log message ***
 *
 * Revision 1.431  1998/04/02  10:37:02  iwawaki
 * *** empty log message ***
 *
 * Revision 1.430  1998/03/31  13:23:45  hayakawa
 * Profile_Max → MaxProfile
 *
 * Revision 1.429  1998/03/30  13:06:33  matutani
 * *** empty log message ***
 *
 * Revision 1.428  1998/03/30  05:49:38  hayakawa
 * z_rcpの命名規則の変更に伴う変更
 *
 * Revision 1.427  1998/03/27  09:37:41  matutani
 * DEBUG_Pを増やした
 *
 * Revision 1.426  1998/03/26  10:35:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.425  1998/03/25  13:03:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.424  1998/03/25  08:50:07  matutani
 * *** empty log message ***
 *
 * Revision 1.423  1998/03/25  06:09:08  okajima
 * *** empty log message ***
 *
 * Revision 1.422  1998/03/23  13:57:09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.421  1998/03/21  12:37:38  matutani
 * *** empty log message ***
 *
 *
 * 住吉トラップ対策をいれました。（早川）
 *
 * Revision 1.420  1998/03/16  14:18:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.419  1998/03/16  06:36:38  matutani
 * *** empty log message ***
 *
 * Revision 1.418  1998/03/16  01:27:00  hayakawa
 * texture_decal_shadow → _texture_decal_shadow
 *
 * Revision 1.417  1998/03/13  13:34:31  matutani
 * *** empty log message ***
 *
 * Revision 1.416  1998/03/12  10:04:13  matutani
 * *** empty log message ***
 *
 * Revision 1.415  1998/03/11  10:32:04  matutani
 * 空中にいるときに補正を受けなくした。
 * 
 * Revision 1.414  1998/03/10  13:36:24  matutani
 * *** empty log message ***
 *
 * Revision 1.413  1998/03/10  06:49:38  matutani
 * 馬暫定設置
 * 
 * Revision 1.412  1998/03/09  08:10:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.411  1998/03/09  06:21:19  iwawaki
 * *** empty log message ***
 *
 * Revision 1.410  1998/03/07  14:24:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.409  1998/03/06  10:30:22  morita
 * *** empty log message ***
 *
 * Revision 1.408  1998/03/06  04:51:29  hayakawa
 * メモリ節約のためにセグメント名テーブルを使わないようにした
 *
 * Revision 1.407  1998/03/05  14:17:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.406  1998/03/05  01:26:41  iwawaki
 * *** empty log message ***
 *
 * Revision 1.405  1998/03/04  13:41:27  iwawaki
 * *** empty log message ***
 *
 * Revision 1.404  1998/03/04  00:56:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.403  1998/03/03  13:56:28  morita
 * *** empty log message ***
 *
 * Revision 1.402  1998/03/02  09:45:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.401  1998/03/02  01:31:27  umemiya
 * ボス用鍵扉表示追加
 *
 * Revision 1.400  1998/02/27  11:26:07  sakakibara
 * *** empty log message ***
 *
 * Revision 1.399  1998/02/27  08:41:04  iwawaki
 * *** empty log message ***
 *
 * Revision 1.398  1998/02/20  08:49:54  hayakawa
 * print追加のみ
 *
 * Revision 1.397  1998/02/19  12:41:34  matutani
 * デバッグ表示訂正
 *
 * Revision 1.396  1998/02/19  10:31:16  matutani
 * デバッグ表示 -DDEBUG_P
 *
 * Revision 1.395  1998/02/19  08:33:37  matutani
 * *** empty log message ***
 *
 * Revision 1.394  1998/02/19  06:52:20  iwawaki
 * *** empty log message ***
 *
 * Revision 1.393  1998/02/17  13:06:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.392  1998/02/16  13:49:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.391  1998/02/14  13:43:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.390  1998/02/11  12:00:28  matutani
 * *** empty log message ***
 *
 * Revision 1.389  1998/02/11  05:33:33  matutani
 * ShotVsMyCheck()のCollisionCheckPipeVsLine()から
 * CollisionCheckPipeVsLine2()に変更。
 * パラメーターとしてcollisionからstatusに変更のため。
 * ただし、statusにはoffsetが未対応のため0.0fとして処理
 * statusのoffsetについては対応予定
 * 以上
 *
 * Revision 1.388  1998/02/10  06:38:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.387  1998/02/10  06:31:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.386  1998/02/10  06:15:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.385  1998/02/09  13:56:18  sumiyosi
 * ＮＰＣ関連のルーチン集追加。
 *
 * Revision 1.384  1998/02/07  13:24:45  iwawaki
 * *** empty log message ***
 *
 * Revision 1.383  1998/02/06  02:39:08  tarukado
 * *** empty log message ***
 *
 * Revision 1.382  1998/02/05  00:19:28  sumiyosi
 * すんません。エラー出したんで直しました。
 *
 * Revision 1.381  1998/02/04  13:57:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.380  1998/02/04  00:08:17  sumiyosi
 * anchor_status_data を使いたかったので、外に出しました。
 *
 * Revision 1.379  1998/01/30  13:21:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.378  1998/01/29  13:33:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.377  1998/01/29  11:38:59  tarukado
 * *** empty log message ***
 *
 * Revision 1.376  1998/01/28  08:04:37  morita
 * *** empty log message ***
 *
 * Revision 1.375  1998/01/27  07:54:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.374  1998/01/22  09:22:53  umemiya
 * Actor_search_position_project_distanceXZの内容変更
 *
 * Revision 1.373  1998/01/22  07:47:01  tarukado
 * 汎用 影表示ルーチン追加
 *
 * Revision 1.372  1998/01/21  12:42:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.371  1998/01/21  06:18:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.370  1998/01/21  04:06:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.369  1998/01/20  14:28:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.368  1998/01/20  07:55:26  sumiyosi
 * 村人関連の関数抹殺‥
 *
 * Revision 1.367  1998/01/16  13:40:09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.366  1998/01/14  05:47:31  tarukado
 * *** empty log message ***
 *
 * Revision 1.365  1998/01/13  14:38:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.364  1998/01/13  07:30:28  morita
 * *** empty log message ***
 *
 * Revision 1.363  1998/01/12  14:22:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.362  1998/01/12  02:49:01  hayakawa
 * *** empty log message ***
 *
 * Revision 1.361  1998/01/12  02:45:09  hayakawa
 * *_z_light_fog_prim*を_*_z_light_fog_prim*に変更
 *
 * Revision 1.360  1998/01/09  08:26:34  tarukado
 * *** empty log message ***
 *
 * Revision 1.359  1998/01/07  08:58:16  tarukado
 * *** empty log message ***
 *
 * Revision 1.358  1998/01/05  07:20:18  tarukado
 * *** empty log message ***
 *
 * Revision 1.357  1997/12/26  02:42:08  okajima
 * *** empty log message ***
 *
 * Revision 1.356  1997/12/15  09:44:50  iwawaki
 * *** empty log message ***
 *
 * Revision 1.355  1997/12/12  08:01:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.354  1997/12/11  12:07:53  iwawaki
 * *** empty log message ***
 *
 * Revision 1.353  1997/12/09  10:48:54  iwawaki
 * *** empty log message ***
 *
 * Revision 1.352  1997/12/09  05:22:27  iwawaki
 * *** empty log message ***
 *
 * Revision 1.351  1997/12/05  12:28:04  iwawaki
 * *** empty log message ***
 *
 * Revision 1.350  1997/12/04  08:58:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.349  1997/12/03  09:13:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.348  1997/12/02  05:56:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.347  1997/12/02  01:17:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.346  1997/12/02  00:55:09  iwawaki
 * *** empty log message ***
 *
 * Revision 1.345  1997/12/02  00:50:02  iwawaki
 * *** empty log message ***
 *
 * Revision 1.344  1997/11/19  05:31:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.343  1997/11/19  03:24:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.342  1997/11/19  01:13:38  iwawaki
 * *** empty log message ***
 *
 * Revision 1.341  1997/11/18  20:23:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.340  1997/11/18  15:22:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.339  1997/11/18  12:43:37  soejima
 * *** empty log message ***
 *
 * Revision 1.338  1997/11/18  12:15:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.337  1997/11/18  09:40:28  matutani
 * 馬位置
 *
 * Revision 1.336  1997/11/18  08:59:45  soejima
 * *** empty log message ***
 *
 * Revision 1.335  1997/11/18  08:46:46  soejima
 * *** empty log message ***
 *
 * Revision 1.334  1997/11/18  08:10:32  morita
 * *** empty log message ***
 *
 * Revision 1.333  1997/11/18  04:59:10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.332  1997/11/18  03:05:28  okajima
 * *** empty log message ***
 *
 * Revision 1.331  1997/11/18  01:50:46  matutani
 * *** empty log message ***
 *
 * Revision 1.330  1997/11/17  15:10:34  iwawaki
 * *** empty log message ***
 *
 * Revision 1.329  1997/11/17  13:20:45  soejima
 * *** empty log message ***
 *
 * Revision 1.328  1997/11/17  12:09:37  matutani
 * moveBG変更中止
 *
 * Revision 1.327  1997/11/17  08:38:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.326  1997/11/17  04:42:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.325  1997/11/17  03:12:06  matutani
 * coll_vecコリジョンチェックからの補正量
 *
 * Revision 1.324  1997/11/17  02:50:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.323  1997/11/16  12:42:33  iwawaki
 * *** empty log message ***
 *
 * Revision 1.322  1997/11/16  11:48:13  sumiyosi
 * ゴロン族のメッセージの上位を0x09に
 *
 * Revision 1.321  1997/11/16  11:01:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.320  1997/11/16  09:14:13  iwawaki
 * *** empty log message ***
 *
 * Revision 1.319  1997/11/15  17:34:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.318  1997/11/15  12:58:30  hayakawa
 * include.hayakawaの内容を反映した
 *
 * Revision 1.317  1997/11/15  12:48:56  iwawaki
 * *** empty log message ***
 *
 * Revision 1.316  1997/11/15  10:16:24  iwawaki
 * *** empty log message ***
 *
 * Revision 1.315  1997/11/14  13:58:00  morita
 * *** empty log message ***
 *
 * Revision 1.314  1997/11/14  13:20:57  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.313  1997/11/14  12:07:00  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.312  1997/11/14  11:53:31  tarukado
 * *** empty log message ***
 *
 * Revision 1.311  1997/11/14  07:51:22  iwawaki
 * *** empty log message ***
 *
 * Revision 1.310  1997/11/14  03:17:44  iwawaki
 * *** empty log message ***
 *
 * Revision 1.309  1997/11/14  02:54:25  morita
 *          真の向上とは単純化に在る
 *
 * Revision 1.308  1997/11/14  02:27:27  morita
 * *** empty log message ***
 *
 * Revision 1.307  1997/11/13  17:07:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.306  1997/11/12  16:49:43  iwawaki
 * *** empty log message ***
 *
 * Revision 1.305  1997/11/12  15:36:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.304  1997/11/12  11:49:31  iwawaki
 * *** empty log message ***
 *
 * Revision 1.303  1997/11/10  17:17:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.302  1997/11/07  10:00:37  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.301  1997/11/07  09:20:32  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.300  1997/11/05  12:51:38  iwawaki
 * *** empty log message ***
 *
 * Revision 1.299  1997/11/05  01:11:06  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.298  1997/11/04  14:20:06  iwawaki
 * *** empty log message ***
 *
 * Revision 1.297  1997/11/03  13:36:38  tarukado
 * *** empty log message ***
 *
 * Revision 1.296  1997/11/03  12:07:18  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.295  1997/11/01  14:58:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.294  1997/11/01  07:23:16  iwawaki
 * *** empty log message ***
 *
 * Revision 1.293  1997/11/01  07:05:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.292  1997/10/31  06:47:11  sumiyosi
 * エラー直したつもり...
 *
 * Revision 1.291  1997/10/31  05:04:14  iwawaki
 * *** empty log message ***
 *
 * Revision 1.290  1997/10/31  05:00:52  iwawaki
 * *** empty log message ***
 *
 * Revision 1.289  1997/10/31  03:04:13  matutani
 * ステータス／デバッグ表示
 *
 * Revision 1.288  1997/10/30  23:58:51  umemiya
 * *** empty log message ***
 *
 * Revision 1.287  1997/10/30  13:30:38  tarukado
 * 自分が注目戦闘の対象かチェック
 * 注目戦闘中 自分が はみご かチェック  追加
 *
 * Revision 1.286  1997/10/30  10:48:39  iwawaki
 * *** empty log message ***
 *
 * Revision 1.285  1997/10/29  11:10:08  tarukado
 * *** empty log message ***
 *
 * Revision 1.284  1997/10/29  07:06:11  iwawaki
 * *** empty log message ***
 *
 * Revision 1.283  1997/10/29  01:22:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.282  1997/10/28  02:14:25  tarukado
 * 爆風当り判定修正
 *
 * Revision 1.281  1997/10/27  14:50:04  iwawaki
 * *** empty log message ***
 *
 * Revision 1.280  1997/10/23  14:09:08  sumiyosi
 * 会話終了チェック改造。
 * （戻り値が２のときのみＴＲＵＥ）
 *
 * Revision 1.279  1997/10/23  14:00:10  iwawaki
 * *** empty log message ***
 *
 * Revision 1.278  1997/10/23  10:04:45  iwawaki
 * *** empty log message ***
 *
 * Revision 1.277  1997/10/23  07:39:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.276  1997/10/23  01:18:07  iwawaki
 * *** empty log message ***
 *
 * Revision 1.275  1997/10/22  14:45:46  iwawaki
 * *** empty log message ***
 *
 * Revision 1.274  1997/10/20  02:52:15  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.273  1997/10/19  12:31:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.272  1997/10/18  14:12:57  matutani
 * コリジョンチェック（ダメージ関係）
 *
 * $Log追加
 */

/************************************************************************
 *
 *	Ａｃｔｏｒ
 *
 ************************************************************************/
#include "sys_segment.h"
#include "z_basic.h"
#include "z_play.h"
#include "z_player.h"
#include "z_player_lib.h"
#include "z_player_shape.h"
#include "z_player_macro.h"
#include "z_player_item.h"
#include "z_effect.h"
#include "z_hilite.h"
#include "z_actor_files.h"
#include "z_effect.h"
#include "z_effect_soft_sprite.h"
#include "z_en_part.h"
#include "z_en_horse.h"
#include "z_skin_matrix.h"
#include "z_bgcheck_collection.h"
#include "z_eff_ss_g_ripple.h"
#include "z_eff_ss_g_splash.h"
#include "z_eff_ss_dead.h"
#include "z_eff_ss_dust.h"
#include "z_bgcheck_movebg.h"
#include "z_scene_table.h"
#include "camera_param_data.h"
// #include "z_people.h"		/* 村人専用	*/
#include "z_actor_dlftbls.h"	/* DLFTBL_ACTOR */
#include "loadfragment.h"	/* LoadFragmentFix2 */
#include "assert64.h"		/* assert */
#include "z_message_h.h"
#include "z_collision_param.h"
#include "z_common_data.h"
#include "z_quake.h"
#include "z_en_item00.h"
#include "z_en_bom.h"
#include "z_malloc.h"
#include "z_eff_spark_flash.h"
#include "z_arms_hook.h"
#include "z_horse.h"
#include "z_shrink_window.h"
#include "z_save_area_h.h"
#include "z_bgcheck_poly_param.h"
#include "z_parameter_h.h"
#include "mathdef.h"
#ifdef ROM_D
#include "count.h"		/* count_gDPNoOpHere */
#endif

/* 日本語 英語切り替え用*/
#include "padmgr.h"

#if defined(ROM_D)
#define AM_FIELD_SIZE 10144	/* 08/17 */
#elif defined(ROM_X)
#define AM_FIELD_SIZE 9712	/* 08/17 */
#elif defined(ROM_F)
#define AM_FIELD_SIZE 9440	/* 08/17 */
#else
#define AM_FIELD_SIZE 10240	/* 今は適当に１０Ｋバイト */
#endif

#define	DEBUG_PRINT_PROC()								\
{											\
}

/************************************************************************
 *
 *	シェイプ情報クラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	シェイプ情報クラス 初期化
 *
 *----------------------------------------------------------------------*/
extern void Shape_Info_init(
    Shape_Info *this,
    float	offset_y,
    void 	(*shadow_proc)(Actor *, LightsN *, Game_play *),
    float	shadow_size
)
{
    this->offset_y = offset_y;

    this->shadow_proc  = shadow_proc;
    this->shadow_size  = shadow_size;
    this->shadow_alpha = 255;
}

/*-----------------------------------------------------------------------
 *
 *	シェイプ指定影表示
 *
 *----------------------------------------------------------------------*/
extern Gfx shadow_model[];
extern Gfx shadow_h_model[];

static void Actor_shadow_draw(
    Actor     *this,
    LightsN   *lightN,
    Game_play *game_play,
    Gfx	      *shape,
    rgba_t    *color
)
{
    lightN;
    
    if ( this->ground_polygon_info != NULL ) {		/* 影表示ＯＫ？ */
	
	float	to_ground_y = this->world.position.y - this->ground_y;
	
	if ( -50.0f <= to_ground_y &&
	     to_ground_y < 500.0f ) {	/* 影表示ＯＫ？ */
	    
	    float	shadow_scale;
	    MtxF	ground_matrix;
	    
	    /*
	     * 影表示
	     */
	    OPEN_DISP(game_play->g.graph);
	
//	    _texture_decal_shadow(game_play->g.graph);
	    SET_NOW_DISP(rcp_mode_set(NOW_DISP, 44));
	    
	    gDPSetCombineLERP(
		NEXT_DISP,
		0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0,
		0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

	    to_ground_y = min_max_limit(to_ground_y, 0.0f, 150.0f);
	    shadow_scale = 1.0f - (to_ground_y * (1.0f/(150.0f + 200.0f)));		/* アルファセット */
	    if(color) {
		gDPSetPrimColor(NEXT_DISP,0,0,
				color->r,color->g,color->b,
				(unsigned char)((float)this->shape.shadow_alpha*shadow_scale));
	    } else {
		gDPSetPrimColor(NEXT_DISP, 0,0, 0,0,0,
				(unsigned char)((float)this->shape.shadow_alpha*shadow_scale));
	    }

	    T_Polygon_Ground_Matrix(this->ground_polygon_info,
				    this->world.position.x,
				    this->ground_y,
				    this->world.position.z,
				    ground_matrix);
	    Matrix_put(&ground_matrix);
	    if ( shape != shadow_model )
		Matrix_rotateY((float)this->shape.angle.sy * (F_PI/32768.0f), MULT_MTX);
	    
	    shadow_scale  = 1.0f - (to_ground_y * (1.0f/(150.0f + 200.0f)));	/* スケールセット */
	    shadow_scale *= this->shape.shadow_size;
	    Matrix_scale(shadow_scale * this->scale.x,
			 1.0f,
			 shadow_scale * this->scale.z, MULT_MTX);
	    gSPMatrix(NEXT_DISP,
		      Matrix_to_Mtx_new(game_play->g.graph),
		      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	    
	    gSPDisplayList(NEXT_DISP, shape);
	
	    CLOSE_DISP(game_play->g.graph);
	}
    }
}

/*-----------------------------------------------------------------------
 *
 *	丸影表示
 *
 *----------------------------------------------------------------------*/
extern void Actor_shadow_circle(
    Actor     *this,
    LightsN   *lightN,
    Game_play *game_play
)
{
    Actor_shadow_draw(this, lightN, game_play, shadow_model,NULL);
}
/*-----------------------------------------------------------------------
 *
 *	光影表示
 *
 *----------------------------------------------------------------------*/
extern void Actor_shadow_white_circle(
    Actor     *this,
    LightsN   *lightN,
    Game_play *game_play
)
{
    static rgba_t color = {255,255,255,255};
    Actor_shadow_draw(this, lightN, game_play, shadow_model,&color);
}

/*-----------------------------------------------------------------------
 *
 *	馬影表示
 *
 *----------------------------------------------------------------------*/
extern void Actor_shadow_horse(
    Actor     *this,
    LightsN   *lightN,
    Game_play *game_play
)
{
    Actor_shadow_draw(this, lightN, game_play, shadow_h_model,NULL);
}

/*-----------------------------------------------------------------------
 *
 *	２足影表示用影設定，表示
 *
 *----------------------------------------------------------------------*/
extern Gfx foot_shadow_model[];

static void shadow_foot_draw(
    Game_play *game_play,
    Light     *lightp,
    MtxF      *ground_matrix,
    int	      light_power,
    float     shadow_alpha,
    float     shadow_scale_x,
    float     shadow_scale_z
)
{
    float	shadow_data, shadow_angle_y;
    float	dx, dz;

    OPEN_DISP(game_play->g.graph);
    
    shadow_data = (float)light_power * 0.00005f;
//    gDPSetPrimColor(NEXT_POLY_XLU_DISP,
//		    0,0, 0,0,0,
//		    (unsigned char)(shadow_alpha * max_limit(shadow_data, 1.0f)));
    gDPSetPrimColor(NEXT_DISP,
		    0,0, 0,0,0,
		    (unsigned char)(shadow_alpha * max_limit(shadow_data, 1.0f)));
    
    dx = (float)lightp->l.dir[XYZ_X];	/* 方向セット */
    dz = (float)lightp->l.dir[XYZ_Z];
    shadow_angle_y = fatan2(dx, dz);

    shadow_scale_z *= 4.5f - ((float)(lightp->l.dir[XYZ_Y]) * 0.035f);	/* 長さセット */
    if ( shadow_scale_z < 1.0f )
	shadow_scale_z = 1.0f;
    
    Matrix_put((MtxF *)ground_matrix);						/* 表示セット */
    Matrix_rotateY(shadow_angle_y, MULT_MTX);
    Matrix_scale(shadow_scale_x,
		 1.0f,
		 shadow_scale_x * shadow_scale_z, MULT_MTX);
//    gSPMatrix(NEXT_POLY_XLU_DISP,
//	      Matrix_to_Mtx_new(game_play->g.graph),
//	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(NEXT_DISP,
	      Matrix_to_Mtx_new(game_play->g.graph),
	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
//    gSPDisplayList(NEXT_POLY_XLU_DISP, foot_shadow_model);
    gSPDisplayList(NEXT_DISP, foot_shadow_model);

    CLOSE_DISP(game_play->g.graph);
}

/*-----------------------------------------------------------------------
 *
 *	２足影表示
 *
 *----------------------------------------------------------------------*/
extern void Actor_shadow_foot(
    Actor     *this,
    LightsN   *lightN,
    Game_play *game_play
)
{
    float	to_ground_y = this->world.position.y - this->ground_y;
    
    if ( to_ground_y > 20.0f )	{	/* 水中丸影へ？ */
	 
	float		save_shadow_size  = this->shape.shadow_size;
	unsigned char	save_shadow_alpha = this->shape.shadow_alpha;
	float		shadow_alpha_ratio;
	
	this->shape.shadow_size *= 0.3f;
	shadow_alpha_ratio 	 = (to_ground_y - 20.0f) * 0.02f;
	this->shape.shadow_alpha  = (float)this->shape.shadow_alpha * (shadow_alpha_ratio > 1.0f ? 1.0f : shadow_alpha_ratio);
	Actor_shadow_circle(this, lightN, game_play);
	this->shape.shadow_size  = save_shadow_size;
	this->shape.shadow_alpha = save_shadow_alpha;
    }

    if ( to_ground_y < 200.0f ) {	/* 足影表示？ */

	MtxF	ground_matrix;
    
	float	ground_y[2], to_ground_y, shadow_alpha, shadow_scale_x, shadow_scale_z;
    
	Light	*lightp;
	int	light_power, max_light_power;
	int	i, j;
	
	int	light_num     = lightN->diffuse_num - 2;
	Light	*start_lightp = &lightN->lights.l[0];
	xyz_t	*foot_posp    = this->shape.foot_pos;
	float	*ground_yp    = ground_y;
    
	/*
	 * 影表示
	 */
	OPEN_DISP(game_play->g.graph);
    
//	_texture_decal_shadow(game_play->g.graph);
	SET_NOW_DISP(rcp_mode_set(NOW_DISP, 44));
	
	this->shape.foot_hit_flag = 0;
	for (i=0; i<2; i++) {
	    
	    foot_posp->y += GROUND_BGCHECK_OFFSET_Y;
	    *ground_yp = Game_play_ground_matrix(game_play, ground_matrix, foot_posp);
	    foot_posp->y -= GROUND_BGCHECK_OFFSET_Y;
	    
	    this->shape.foot_hit_flag <<= 1;
	
	    to_ground_y = foot_posp->y - *ground_yp;
	    if ( -1.0f <= to_ground_y &&
		 to_ground_y < 500.0f ) {	/* 影表示ＯＫ？（0.0f->-1.0fにしてガクガク修正）*/

    		if ( to_ground_y <= 0.0f )
		    this->shape.foot_hit_flag++;

		if ( to_ground_y > 30.0f )
		    to_ground_y = 30.0f;
	        shadow_alpha = (float)this->shape.shadow_alpha * (1.0f - (to_ground_y * (1.0f/30.0f)));	/* アルファセット */
		if ( to_ground_y > 30.0f )
		    to_ground_y = 30.0f;
		shadow_scale_z = 1.0f - (to_ground_y * (1.0f/(30.0f + 40.0f)));				/* スケールセット */
		shadow_scale_x = shadow_scale_z * this->shape.shadow_size * this->scale.x;

		max_light_power = 0;
		lightp          = start_lightp;
		for (j=0; j<light_num; j++) {	/* 演出ライト */

		    if ( lightp->l.dir[XYZ_Y] > 0 ) {	/* ライト方向ＯＫ？ */
		    
			light_power =
			    (lightp->l.col[RGB_R] + lightp->l.col[RGB_G] + lightp->l.col[RGB_B]) * ABS(lightp->l.dir[XYZ_Y]);
			if ( light_power > 0 ) {
			    
			    max_light_power += light_power;
			    shadow_foot_draw(game_play,
					     lightp,
					     &ground_matrix,
					     light_power,
					     shadow_alpha,
					     shadow_scale_x,
					     shadow_scale_z);
			}
		    }
		    
		    lightp++;
		}
		for (j=0; j<2; j++) {	/* 環境ライト */

		    if ( lightp->l.dir[XYZ_Y] > 0 ) {	/* ライト方向ＯＫ？ */
			
			light_power = ((lightp->l.col[RGB_R] + lightp->l.col[RGB_G] + lightp->l.col[RGB_B]) *
				       ABS(lightp->l.dir[XYZ_Y])) - (max_light_power * 8);
			if ( light_power > 0 ) {
			    
			    shadow_foot_draw(game_play,
					     lightp,
					     &ground_matrix,
					     light_power,
					     shadow_alpha,
					     shadow_scale_x,
					     shadow_scale_z);
			}
		    }
		
		    lightp++;
		}
	    }

	    foot_posp++;
	    ground_yp++;
	}
	
	if ( !bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND) ) {	/* 現在落下中？ */
	 
	    this->shape.foot_hit_flag = 0;
	}
	else if ( this->shape.foot_hit_flag == 3 ) {	/* 両足接地？ */
	    
	    float foot_distance_y = this->shape.foot_pos[0].y - this->shape.foot_pos[1].y;
	    
	    if ( (ground_y[0] + foot_distance_y) < (ground_y[1] - foot_distance_y) ) this->shape.foot_hit_flag = 2;
	    else								     this->shape.foot_hit_flag = 1;
	}
	
	CLOSE_DISP(game_play->g.graph);
    }
}

/*-----------------------------------------------------------------------
 *
 *	２足影座標チェック
 *
 *----------------------------------------------------------------------*/
extern void Actor_foot_shadow_pos_set(
    Actor     *this,
    int       jyoint_no,
    int	      L_foot_jyoint,
    xyz_t     *L_foot_offset,
    int	      R_foot_jyoint,
    xyz_t     *R_foot_offset
)
{
    if ( jyoint_no == L_foot_jyoint ) {		/* 左足？ */
	Matrix_Position(L_foot_offset, &this->shape.foot_pos[0]);
    } else if ( jyoint_no == R_foot_jyoint ) {	/* 右足？ */
	Matrix_Position(R_foot_offset, &this->shape.foot_pos[1]);
    }
}

/*-----------------------------------------------------------------------
 *
 *	透視変換座標セット
 *
 *----------------------------------------------------------------------*/
extern void projection_pos_set(
    Game_play *game_play,
    xyz_t     *target_pos,
    xyz_t     *display_pos,
    float     *w
)
{
    Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
			     (Skin_Vector *)target_pos,
			     (Skin_Vector *)display_pos,
			     w);
    if ( *w < 1.0f )
	*w = 1.0f;
    else
	*w = 1.0f / *w;
}

/************************************************************************
 *
 *	注目マーカークラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	照準ブラー用データセット
 *
 *----------------------------------------------------------------------*/
static void Anchor_Marker_target_data_set(
    Anchor_Marker *this,
    int		  target_ID,
    float	  x,
    float	  y,
    float	  z
)
{
    Anchor_Target_Data	*target_data = &this->target.data[target_ID];

    target_data->position.x = x;
    target_data->position.y = y;
    target_data->position.z = z;
    target_data->r	    = this->target_r;
}

/*-----------------------------------------------------------------------
 *
 *	役柄別注目カラーデータ
 *
 *----------------------------------------------------------------------*/
static Color	status_color[ACTOR_PART_MAX+1][2] = {
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_SWITCH */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_FRIEND */
    {{255,255,255,255}, {  0,  0,255,0}},	/* ACTOR_PART_PLAYER */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_BOM */
    {{150,150,255,255}, {150,150,255,0}},	/* ACTOR_PART_PEOPLE */
    {{255,255,  0,255}, {200,155,  0,0}},	/* ACTOR_PART_ENEMY  */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_OBJ    */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_EFFECT */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_ITEM   */
    {{255,255,  0,255}, {200,155,  0,0}},	/* ACTOR_PART_BOSS  */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_DOOR   */
    {{  0,255,  0,255}, {  0,255,  0,0}},	/* ACTOR_PART_TREASURE */
    {{  0,255,  0,255}, {  0,255,  0,0}}	/* ACTOR_PART_MAX（自動注目）*/
};

/*-----------------------------------------------------------------------
 *
 *	照準ブラー用データ初期化
 *
 *----------------------------------------------------------------------*/
#define TARGET_SCALE_X			0.15f
#define START_TARGET_R			500.0f
#define END_TARGET_R			80.0f
#define TARGET_SCALE_X_CHANGE_R		120.0f

static void Anchor_Marker_target_init(
    Anchor_Marker *this,
    int		  target_part,
    Game_play	  *game_play
)
{
    Anchor_Target_Data	*target_data;
    Color		*status_colorp = &status_color[target_part][0];
    int			i;

    
    xyz_t_move(&this->target_position, view_get_eye(&game_play->view));
    this->target_r     = START_TARGET_R;
    this->target_timer = 256;

    target_data = this->target.data;
    for (i=0; i<TARGET_BLURE_MAX; i++) {

	Anchor_Marker_target_data_set(this, i, 0.0f, 0.0f, 0.0f);
	target_data->color.r = status_colorp->r;
	target_data->color.g = status_colorp->g;
	target_data->color.b = status_colorp->b;

	target_data++;
    }
}

/*-----------------------------------------------------------------------
 *
 *	注目マーカーデータ初期化
 *
 *----------------------------------------------------------------------*/
static void Anchor_Marker_data_set(
    Anchor_Marker *this,
    Actor	  *target_actor,
    int		  target_part,
    Game_play	  *game_play
)
{
    game_play;
    
    this->position.x = target_actor->eye.position.x;
    this->position.y = target_actor->eye.position.y + (target_actor->anchor_offset_y * target_actor->scale.y);
    this->position.z = target_actor->eye.position.z;

    this->center_color.fr = (float)status_color[target_part][0].r;
    this->center_color.fg = (float)status_color[target_part][0].g;
    this->center_color.fb = (float)status_color[target_part][0].b;
    this->center_color.fa = (float)status_color[target_part][0].a;
    this->side_color.fr   = (float)status_color[target_part][1].r;
    this->side_color.fg   = (float)status_color[target_part][1].g;
    this->side_color.fb   = (float)status_color[target_part][1].b;
    this->side_color.fa   = (float)status_color[target_part][1].a;
}

/*-----------------------------------------------------------------------
 *
 *	注目マーカークラス 初期化
 *
 *----------------------------------------------------------------------*/
static void Anchor_Marker_init(
    Anchor_Marker *this,
    Actor	  *base_actor,
    Game_play	  *game_play
)
{
    this->anchor_actor	       =
    this->target_actor	       =
    this->anchor_request_actor =
    this->enemyBGM_actor       = NULL;
    this->rock_on              = 0;
    this->move_ratio           = 0.0f;
    this->target.count         = 0; 
    Anchor_Marker_data_set(this, base_actor, (int)base_actor->part, game_play);
    Anchor_Marker_target_init(this, (int)base_actor->part, game_play);
}

/*-----------------------------------------------------------------------
 *
 *	注目照準表示処理
 *
 *----------------------------------------------------------------------*/
extern Gfx	target_model[];
extern Gfx 	tetra_model[];
extern Gfx 	mark_model[];

extern void Anchor_Marker_target_draw(
    Anchor_Marker *this,
    Game_play	  *game_play
)
{
    Actor	*target_actor = this->target_actor;
    
    OPEN_DISP(game_play->g.graph);
	
    if ( this->target_timer ) {		/* 表示？ */
	
	Player_actor		*player_actor = (Player_actor *)get_player_actor(game_play);
	float			move_ratio    = 1.0f;
	short			alpha         = 255;
	Anchor_Target_Data	*target_data;
	xyz_t			display_position;
	int			blure_max;
	float			w;
	int			i, j;
	
	/*
	 * ターゲット座標セット（２Ｄ）
	 */
	if ( this->rock_on )
	    blure_max = 1;			/* ターゲット固定？ */
	else
	    blure_max = TARGET_BLURE_MAX;
	
	if ( target_actor != NULL ) {
	    
	    xyz_t_move(&this->target_position, &target_actor->eye.position);
	    move_ratio = (START_TARGET_R - this->target_r) / (START_TARGET_R - END_TARGET_R);
	} else {							/* 消去 */

	    if ( (this->target_timer -= 120) < 0 )
		this->target_timer = 0;
	    alpha = this->target_timer;
	}

	projection_pos_set(game_play, &this->target_position, &display_position, &w);
	display_position.x  = (display_position.x * w) * (float)(SCREEN_WD/2) * move_ratio;
	display_position.x  = min_max_limit(display_position.x, (float)(-SCREEN_WD), (float)SCREEN_WD); 
	display_position.y  = (display_position.y * w) * (float)(SCREEN_HT/2) * move_ratio;
	display_position.y  = min_max_limit(display_position.y, (float)(-SCREEN_HT), (float)SCREEN_HT);
	display_position.z *= move_ratio;
	
	/*
	 * 照準ブラー用データセット
	 */
	if ( --(this->target.count) < 0 )
	    this->target.count = TARGET_BLURE_MAX-1;
	Anchor_Marker_target_data_set(this,
				      (int)this->target.count,
				      display_position.x,
				      display_position.y,
				      display_position.z);

	
	if ( !bitcheck(player_actor->action, P_ACTION_TALK) ||
	     player_actor->camera_parameter.primary_actor != target_actor ) {	/* 一時消去？ */
	    
	    /*
	     * ターゲット表示
	     */
	    SET_NOW_OVERLAY_DISP(rcp_mode_set(NOW_OVERLAY_DISP, 57));
	    
	    for (i=0, j=(int)this->target.count; i<blure_max; i++, j=(j+1)%TARGET_BLURE_MAX) {
		
		target_data = &this->target.data[j];
		
		if ( target_data->r < START_TARGET_R ) {	/* 照準表示ＯＫ？ */
		    
		    float target_scale_x = target_data->r <= TARGET_SCALE_X_CHANGE_R ? TARGET_SCALE_X : (TARGET_SCALE_X + ((target_data->r - TARGET_SCALE_X_CHANGE_R) * 0.001f));
		    int	k;
		    
		    /*
		     * 照準表示
		     */
		    Matrix_translate(target_data->position.x, target_data->position.y, 0.0f, SET_MTX);   
		    Matrix_scale(target_scale_x, TARGET_SCALE_X, 1.0f, MULT_MTX);
		    gDPSetPrimColor(NEXT_OVERLAY_DISP, 0,0,
				    target_data->color.r,
				    target_data->color.g,
				    target_data->color.b,
				    (unsigned char)alpha);
		    
		    Matrix_rotateZ((float)(this->rock_on & 0x7f) * ((360.0f/128.0f) * (F_PI/180.0f)), MULT_MTX);
		    for (k=0; k<4; k++) {
			
			Matrix_rotateZ(90.0f*(F_PI/180.0f), MULT_MTX);
			
			Matrix_push();
			
			Matrix_translate(target_data->r, target_data->r, 0.0f, MULT_MTX);
			gSPMatrix(NEXT_OVERLAY_DISP,
				  Matrix_to_Mtx_new(game_play->g.graph),
				  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
			gSPDisplayList(NEXT_OVERLAY_DISP, target_model);
			
			Matrix_pull();
		    }
		}
	
		if ( (alpha -= 255/TARGET_BLURE_MAX) < 0 ) alpha = 0;
	    }
	}
    }

    /*
     * 次候補マーカー表示
     */
    if ( (target_actor = this->secondary_actor) != NULL && /* 次候補あり？ */
	 !Actor_bitcheck_status(target_actor, ACTOR_STATUS_ANCHOR_NO_ROCK) ) {	/* ロック可能？ */
	 
	Color		*status_colorp = &status_color[target_actor->part][0];
	
	SET_NOW_POLY_XLU_DISP(rcp_mode_set(NOW_POLY_XLU_DISP, 7)); /* texture_a_prim */
	
	Matrix_translate(target_actor->eye.position.x,
			 target_actor->eye.position.y + (target_actor->anchor_offset_y * target_actor->scale.y) + 17.0f,
			 target_actor->eye.position.z,
			 SET_MTX);
	Matrix_rotateY(((game_play->game_frame_counter * 3000) & 0xffff) * (F_PI/32768.0f), MULT_MTX);
//	Matrix_scale(0.035f, 0.06f, 0.05f, MULT_MTX);
	Matrix_scale((float)(35+TREG(27))/1000.0f,
		     (float)(60+TREG(28))/1000.0f,
		     (float)(50+TREG(29))/1000.0f, MULT_MTX);

	gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0,0,
			status_colorp->r, status_colorp->g, status_colorp->b,
			255);
	gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game_play->g.graph),
		  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	gSPDisplayList(NEXT_POLY_XLU_DISP, mark_model);
    }
	
    CLOSE_DISP(game_play->g.graph);
}

/*-----------------------------------------------------------------------
 *
 *	注目マーカー処理
 *
 *----------------------------------------------------------------------*/
#define	MOVE_FRAME	4
#define	MOVE_RATIO_ADD	(1.0f/(float)MOVE_FRAME)

extern void Anchor_Marker_process(
    Anchor_Marker *this,
    Actor	  *player_actor,
    Actor	  *target_actor,
    Game_play	  *game_play
)
{
    Player_actor	*player 	  = (Player_actor *)player_actor;
    Actor		*elf_target_actor = NULL;
    int			target_part;
    xyz_t		camera_position;
    float		camera_w;
    
    /*
     * 戦闘モードＢＧＭ用チェック
     */
    if ( player->camera_parameter.primary_actor != NULL &&
	 player->command_stick_camera_dir[player->command_counter] == 2 ) {

	this->secondary_actor = NULL;
    } else {
	
	Actor_info_anchor_search(game_play,
				 &game_play->actor_info,
				 &elf_target_actor,
				 player_actor);
	this->secondary_actor = elf_target_actor; /* 次候補Ａｃｔｏｒポインタ */
    }
    
    /*
     * 注目マーカー処理
     */
    if ( this->anchor_request_actor != NULL ) {		/* 注目要求あり？ */

	elf_target_actor           = this->anchor_request_actor;
	this->anchor_request_actor = NULL;
    } else if ( target_actor != NULL ) {		/* 注目対象あり？ */
	
	elf_target_actor = target_actor;
    }
    
    if ( elf_target_actor != NULL )
	target_part = (int)elf_target_actor->part;
    else
	target_part = (int)player_actor->part;
    
    if ( elf_target_actor != this->anchor_actor ||	
	 target_part != this->anchor_actor_part ) {	/* 注目対象変更？ */
	
	this->anchor_actor      = elf_target_actor;
	this->anchor_actor_part = (unsigned char)target_part;
	this->move_ratio        = 1.0f;
    }
    
    if ( elf_target_actor == NULL ) elf_target_actor = player_actor;	/* 注目Ａｃｔｏｒ無し？ */
    
    if ( !chase_f(&this->move_ratio, 0.0f, MOVE_RATIO_ADD) ) {	/* マーカー移動中？ */
	
	float	move_ratio = MOVE_RATIO_ADD / this->move_ratio;
	float	dx, dy, dz;
	
	/*
	 * 妖精注目座標移動
	 */
	dx = elf_target_actor->world.position.x - this->position.x;
	dy = (elf_target_actor->world.position.y +
	      (elf_target_actor->anchor_offset_y *
	       elf_target_actor->scale.y)) - this->position.y;
	dz = elf_target_actor->world.position.z - this->position.z;
	this->position.x += dx * move_ratio;
	this->position.y += dy * move_ratio;
	this->position.z += dz * move_ratio;
    } else {
	Anchor_Marker_data_set(this, elf_target_actor, target_part, game_play);
    }

    /*
     * 照準注目座標移動
     */
    if ( target_actor != NULL &&	/* 注目中？ */
	 !this->rock_on ) {		/* ロックオン？ */
	    
	projection_pos_set(game_play, &target_actor->eye.position, &camera_position, &camera_w);
	if ( camera_position.z <= 0.0f ||
	     fabsf(camera_position.x * camera_w) >= 1.0f ||
	     fabsf(camera_position.y * camera_w) >= 1.0f ) {	/* 表示中でない？ */
	    
	    target_actor = NULL;
	}
    }

    if ( target_actor != NULL ) {	/* 注目中？ */
	
	if ( target_actor != this->target_actor ) {
	    
	    Anchor_Marker_target_init(this, target_actor->part, game_play);
	    this->target_actor = target_actor;
	    if ( target_actor->name == ACTOR_NAME_EN_BOOM )
		this->target_timer = 0;	/* ブーメラン？ */
	    
	    /*
	     * ロックオンＳＥセット
	     */
	    Na_StartSystemSe_F((Actor_check_status(target_actor, ACTOR_STATUS_FIGHT) ?
				NA_SE_SY_LOCK_ON_ENEMY : NA_SE_SY_LOCK_ON_HUMAN));	/* <SE> */
	}
	
	this->target_position.x = target_actor->world.position.x;
	this->target_position.y = target_actor->world.position.y - (target_actor->shape.offset_y * target_actor->scale.y);
	this->target_position.z = target_actor->world.position.z;
	
//	if ( shrink_window_getnowval() >= 27 ) { /* ビスタサイズ？ */
	    
	    if ( !this->rock_on ) {	/* ロックオンへ？ */
		
		float	accel = (START_TARGET_R - this->target_r) * 3.0f;
		
		accel = min_max_limit(accel, 30.0f, 100.0f);
		if ( chase_f(&this->target_r, END_TARGET_R, accel) ) {	/* 照準枠サイズ設定 */
		    
		    this->rock_on++;	/* ロックオン */

#if 0		    
		    /*
		     * ロックオンＳＥセット
		     */
		    Na_StartSystemSe_F((target_actor->part == ACTOR_PART_ENEMY ?
					NA_SE_SY_LOCK_ON_ENEMY : NA_SE_SY_LOCK_ON_HUMAN));	/* <SE> */
#endif
		}
	    } else {
		
		this->rock_on  = (this->rock_on + 3) | 0x80;
		this->target_r = TARGET_SCALE_X_CHANGE_R;		/* 照準枠サイズ設定 */
	    }
//	}
    } else {
	
	this->target_actor = NULL;
	
	chase_f(&this->target_r, START_TARGET_R, 80.0f);	/* 照準枠サイズ設定 */
    }
}

/************************************************************************
 *
 *	Ａｃｔｏｒ環境クラス
 *
 ************************************************************************/

#if 0
/*-----------------------------------------------------------------------
 *
 *	スイッチビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_sw_check(Actor_Environment *this, int sw_no)
{
    if ( sw_no < 32 ) return bitcheck((this)->sw1, (1<<(sw_no)));
    else	      return bitcheck((this)->sw2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	スイッチビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_on(Actor_Environment *this, int sw_no)
{
    if ( sw_no < 32 ) bitset((this)->sw1, (1<<(sw_no)));
    else	      bitset((this)->sw2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	スイッチビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_off(Actor_Environment *this, int sw_no)
{
    if ( sw_no < 32 ) bitclr((this)->sw1, (1<<(sw_no)));
    else	      bitclr((this)->sw2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	チェック用スイッチビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_sw_c_check(Actor_Environment *this, int sw_no)
{
    if ( sw_no < 32 ) return bitcheck((this)->sw_c1, (1<<(sw_no)));
    else	      return bitcheck((this)->sw_c2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	チェック用スイッチビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_c_on(Actor_Environment *this, int sw_no)
{
    if ( sw_no < 32 ) bitset((this)->sw_c1, (1<<(sw_no)));
    else	      bitset((this)->sw_c2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	チェック用スイッチビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_c_off(Actor_Environment *this, int sw_no)
{
    if ( sw_no < 32 ) bitclr((this)->sw_c1, (1<<(sw_no)));
    else	      bitclr((this)->sw_c2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	宝箱ゲットビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_Tbox_check(Actor_Environment *this, int Tbox_no)
{
    return bitcheck((this)->Tbox, (1<<(Tbox_no)));
}

/*-----------------------------------------------------------------------
 *
 *	宝箱ゲットビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_Tbox_on(Actor_Environment *this, int Tbox_no)
{
    bitset((this)->Tbox, (1<<(Tbox_no)));
}

/*-----------------------------------------------------------------------
 *
 *	部屋全滅ビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_room_clear_check(Actor_Environment *this, int room_no)
{
    return bitcheck((this)->room_clear, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	部屋全滅ビットビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_room_clear_on(Actor_Environment *this, int room_no)
{
    bitset((this)->room_clear, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	部屋全滅ビットビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_room_clear_off(Actor_Environment *this, int room_no)
{
    bitclr((this)->room_clear, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	敵存在無しビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_no_enemy_check(Actor_Environment *this, int room_no)
{
    return bitcheck((this)->no_enemy, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	敵存在無しビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_no_enemy_on(Actor_Environment *this, int room_no)
{
    bitset((this)->no_enemy, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	敵存在無しビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_no_enemy_off(Actor_Environment *this, int room_no)
{
    bitclr((this)->no_enemy, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	アイテムゲットビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_item_check(Actor_Environment *this, int item_no)
{
    if ( item_no < 32 ) return bitcheck((this)->item1, (1<<(item_no)));
    else	        return bitcheck((this)->item2, (1<<((item_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	アイテムゲットビットＯＮ
 *	０は無視
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_item_on(Actor_Environment *this, int item_no)
{
    if (!item_no)
	return;

    if ( item_no < 32 ) bitset((this)->item1, (1<<(item_no)));
    else	        bitset((this)->item2, (1<<((item_no) - 32)));
}
#endif

/*-----------------------------------------------------------------------
 *
 *	スイッチビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_sw_Check(Game_play *game_play, int sw_no)
{
    if ( sw_no < 32 ) return bitcheck(game_play->actor_info.environment.sw1, (1<<(sw_no)));
    else	      return bitcheck(game_play->actor_info.environment.sw2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	スイッチビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_On(Game_play *game_play, int sw_no)
{
    if ( sw_no < 32 ) bitset(game_play->actor_info.environment.sw1, (1<<(sw_no)));
    else	      bitset(game_play->actor_info.environment.sw2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	スイッチビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_Off(Game_play *game_play, int sw_no)
{
    if ( sw_no < 32 ) bitclr(game_play->actor_info.environment.sw1, (1<<(sw_no)));
    else	      bitclr(game_play->actor_info.environment.sw2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	チェック用スイッチビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_sw_c_Check(Game_play *game_play, int sw_no)
{
    if ( sw_no < 32 ) return bitcheck(game_play->actor_info.environment.sw_c1, (1<<(sw_no)));
    else	      return bitcheck(game_play->actor_info.environment.sw_c2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	チェック用スイッチビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_c_On(Game_play *game_play, int sw_no)
{
    if ( sw_no < 32 ) bitset(game_play->actor_info.environment.sw_c1, (1<<(sw_no)));
    else	      bitset(game_play->actor_info.environment.sw_c2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	チェック用スイッチビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_sw_c_Off(Game_play *game_play, int sw_no)
{
    if ( sw_no < 32 ) bitclr(game_play->actor_info.environment.sw_c1, (1<<(sw_no)));
    else	      bitclr(game_play->actor_info.environment.sw_c2, (1<<((sw_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	宝箱ゲットビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_Tbox_Check(Game_play *game_play, int Tbox_no)
{
    return bitcheck(game_play->actor_info.environment.Tbox, (1<<(Tbox_no)));
}

/*-----------------------------------------------------------------------
 *
 *	宝箱ゲットビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_Tbox_On(Game_play *game_play, int Tbox_no)
{
    bitset(game_play->actor_info.environment.Tbox, (1<<(Tbox_no)));
}

/*-----------------------------------------------------------------------
 *
 *	部屋全滅ビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_room_clear_Check(Game_play *game_play, int room_no)
{
    return bitcheck(game_play->actor_info.environment.room_clear, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	部屋全滅ビットビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_room_clear_On(Game_play *game_play, int room_no)
{
    bitset(game_play->actor_info.environment.room_clear, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	部屋全滅ビットビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_room_clear_Off(Game_play *game_play, int room_no)
{
    bitclr(game_play->actor_info.environment.room_clear, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	敵存在無しビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_no_enemy_Check(Game_play *game_play, int room_no)
{
    return bitcheck(game_play->actor_info.environment.no_enemy, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	敵存在無しビットＯＮ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_no_enemy_On(Game_play *game_play, int room_no)
{
    bitset(game_play->actor_info.environment.no_enemy, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	敵存在無しビットＯＦＦ
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_no_enemy_Off(Game_play *game_play, int room_no)
{
    bitclr(game_play->actor_info.environment.no_enemy, (1<<(room_no)));
}

/*-----------------------------------------------------------------------
 *
 *	アイテムゲットビットチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_Environment_item_Check(Game_play *game_play, int item_no)
{
    if ( item_no < 32 ) return bitcheck(game_play->actor_info.environment.item1, (1<<(item_no)));
    else	        return bitcheck(game_play->actor_info.environment.item2, (1<<((item_no) - 32)));
}

/*-----------------------------------------------------------------------
 *
 *	アイテムゲットビットＯＮ
 *	０は無視
 *
 *----------------------------------------------------------------------*/
extern void Actor_Environment_item_On(Game_play *game_play, int item_no)
{
    if (!item_no)
	return;

    if ( item_no < 32 ) bitset(game_play->actor_info.environment.item1, (1<<(item_no)));
    else	        bitset(game_play->actor_info.environment.item2, (1<<((item_no) - 32)));
}

/************************************************************************
 *
 *	Ａｃｔｏｒ名前表示 クラス
 *
 ************************************************************************/
/* 日本語 英語切り替え用*/
extern padmgr_t padmgr;

/*-----------------------------------------------------------------------
 *
 *	名前表示コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Actor_Name_Disp_ct(
    Game_play	    *game_play,
    Actor_Name_Disp *this
)
{
    game_play;
    
    this->timer      =
    this->wait_timer =
    this->color      =
    this->alpha      = 0;
}

/*-----------------------------------------------------------------------
 *
 *	名前表示セット
 *
 *----------------------------------------------------------------------*/
#if 0
#define	Actor_Name_Disp_Set(						\
    game_play,								\
    this,								\
    texture,								\
    x,									\
    y,									\
    w,									\
    h									\
)
    Actor_Name_Disp_Set2(game_play, this, texture, x, y, w, h, 0)
#endif
    
extern void Actor_Name_Disp_Set(
    Game_play	    *game_play,
    Actor_Name_Disp *this,
    unsigned char   *texture,
    short	    x,
    short	    y,
    unsigned char   w,
    unsigned char   h
)
{
    game_play;
    
    this->texture = texture;
    this->x       = x;
    this->y       = y;
    this->w       = w;
    this->h       = h;
    this->timer   = 80;
    this->wait_timer = 0;
}

extern void Actor_Name_Disp_Set2(
    Game_play	    *game_play,
    Actor_Name_Disp *this,
    unsigned char   *texture,
    int		    x,
    int		    y,
    int		    w,
    int		    h,
    int		    start_wait_timer
)
{
    Scene_Data_Status	*scene_data_statusp = (Scene_Data_Status *)game_play->scene_data_statusp;
    u32			scene_name_size;
    
    scene_name_size = (u32)scene_data_statusp->txt_rom_address.end - (u32)scene_data_statusp->txt_rom_address.start;
    if ( scene_name_size &&
#ifndef PAL_VERSION	/* 日本 ＆ ＮＥＳ */
	 scene_name_size <= (1024*8) ) {
#else			/* ＰＡＬ */
	 scene_name_size <= (1024*12) ) {
#endif
	
	/*
	 * シーン名テクスチャー読み込み
	 */
	dmacopy_fg(texture,
		   scene_data_statusp->txt_rom_address.start,
		   scene_name_size);
    }
    
    this->texture    = texture;
    this->x          = x;
    this->y          = y;
    this->w          = w;
    this->h          = h;
    this->timer      = 80;
    this->wait_timer = start_wait_timer;
}

/*-----------------------------------------------------------------------
 *
 *	名前表示処理
 *
 *----------------------------------------------------------------------*/
extern void Actor_Name_Disp_Move(
    Game_play	    *game_play,
    Actor_Name_Disp *this
)
{
    game_play;

    if ( !timer_check_dec(&this->wait_timer) ) {
	if ( !timer_check_dec(&this->timer) ) {
	    chase_s(&this->alpha, 0, 30);
	    chase_s(&this->color, 0, 70);
//	    PRINTF( "tm:%d c:%d a:%d\n",this->timer,this->color,this->alpha );
	} else {
	    chase_s(&this->alpha, 255, 10);
	    chase_s(&this->color, 255, 20);
	}
    }
}



/*-----------------------------------------------------------------------
 *
 *	名前表示
 *
 *----------------------------------------------------------------------*/
extern void Actor_Name_Disp_Draw(
    Game_play	    *game_play,
    Actor_Name_Disp *this
)
{
    if ( this->alpha ) {

	int	w  = this->w;
	int	h  = this->h;
	int	w2 = w << 1;
	int	x1 = (this->x << 2) - w2;
	int	x2 = x1 + (w2 << 1) - 4;
	int	y1 = (this->y << 2) - (h << 1);
	int	y2;
	int	txt_offset;

	OPEN_DISP(game_play->g.graph);

#if defined(PAL_VERSION)
	txt_offset = (w*h) * (J_N);
#else
	if ( !(J_N) ) {
	    /* 日本語 */
	    txt_offset = 0;
	} else {
	    /* 英語 */
	    txt_offset = w*h;
	}
#endif

	if ( (w * h) > (4*1024) ) h = (4*1024) / w;	/* テクスチャーメモリオーバー？ */
	y2 = y1 + (h << 2);
	
	SET_NOW_OVERLAY_DISP(gfx_texture_cullback_xlu(NOW_OVERLAY_DISP));

	gDPSetPrimColor(NEXT_OVERLAY_DISP, 0,0,
			(unsigned char)this->color,
			(unsigned char)this->color,
			(unsigned char)this->color,
			(unsigned char)this->alpha);
	
	gDPLoadTextureBlock(NEXT_OVERLAY_DISP, this->texture + txt_offset, G_IM_FMT_IA, G_IM_SIZ_8b, w, h, 0,
			    G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

	gSPTextureRectangle(NEXT_OVERLAY_DISP, x1, y1, x2, (y2 - 1),
			    G_TX_RENDERTILE,
			    0<<5, 0<<5,
			    1<<10,  1<<10);


	if ( (h = this->h - h) > 0 ) {
	    gDPLoadTextureBlock(NEXT_OVERLAY_DISP, this->texture + (4*1024) + txt_offset, G_IM_FMT_IA, G_IM_SIZ_8b, w, h, 0,
			      G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			      G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	    gSPTextureRectangle(NEXT_OVERLAY_DISP, x1, y2, x2, (y2 + (h << 2) - 1),
				G_TX_RENDERTILE,
				0<<5, 0<<5,
				1<<10,  1<<10);
	}
    
    
#if 0	
    gDPLoadTextureBlock(NEXT_OVERLAY_DISP, this->texture, G_IM_FMT_IA, G_IM_SIZ_8b, this->w, this->h, 0,
			    G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSPTextureRectangle(NEXT_OVERLAY_DISP, (x4 - w2), (y4 - h2), (x4 + w2 - 4), (y4 + h2 - 4),
			    G_TX_RENDERTILE,
			    0<<5, 0<<5,
			    1<<10, 1<<10);
#endif
	
	CLOSE_DISP(game_play->g.graph);
    }
}


#if 0
/*-----------------------------------------------------------------------
 *
 *	名前表示
 *
 *----------------------------------------------------------------------*/
extern unsigned char g_mable_s1_txt[];

extern void Actor_Name_Disp_Draw(
    Game_play	    *game_play,
    Actor_Name_Disp *this
)
{
    if ( this->alpha ) {

	int	w  = this->w;
	int	h  = this->h;
	int	w2 = w << 1;
	int	x1 = (this->x << 2) - w2;
	int	x2 = x1 + (w2 << 1) - 4;
	int	y1 = (this->y << 2) - (h << 1);
	int	y2;
	int	txt_offset;
	int     wk,wkh;
	int     size;

	OPEN_DISP(game_play->g.graph);

	wk = game_play->game_frame_counter;

	if ( (padmgr_GetPadPattern(&padmgr) & 0x4) ) {
	    /* 日本語 */
	    txt_offset = 0;
	} else {
	    /* 英語 */
	    txt_offset = w*h;
	}
	
	size = (4*1024);
	if( game_play->scene_data_ID == GANON_DEMO ) {
	    /** ２タイル用に1024使うので **/
	    size = (3*1024);
	}
	if ( (w * h) > size ) h = size / w;	/* テクスチャーメモリオーバー？ */
	wkh = h;
	y2 = y1 + (h << 2);
	
	SET_NOW_OVERLAY_DISP(gfx_texture_cullback_xlu(NOW_OVERLAY_DISP));

	if( game_play->scene_data_ID == GANON_DEMO ) {
#define G_CC_INT550	TEXEL1, PRIMITIVE, ENV_ALPHA, TEXEL0, TEXEL1, 1, ENVIRONMENT, TEXEL0
#define G_CC_INT551	PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, PRIMITIVE, 0
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetCycleType( NEXT_OVERLAY_DISP, G_CYC_2CYCLE );
	    gDPSetAlphaCompare( NEXT_OVERLAY_DISP, G_AC_THRESHOLD );
	    gDPSetRenderMode( NEXT_OVERLAY_DISP, G_RM_PASS, G_RM_CLD_SURF2 );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT550, G_CC_INT551 );
	    
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 170, (unsigned char)this->alpha );
	    gDPSetEnvColor( NEXT_OVERLAY_DISP, 170, 100, 0, 128 );

	    gDPLoadMultiBlock( NEXT_OVERLAY_DISP,
			       g_mable_s1_txt, 256+128, G_TX_RENDERTILE+1, G_IM_FMT_I, G_IM_SIZ_8b, 32, 32, 0,
			       G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			       5, 5, 1, 1 );
	} else {
	    gDPSetPrimColor(NEXT_OVERLAY_DISP, 0,0,
			    (unsigned char)this->color,
			    (unsigned char)this->color,
			    (unsigned char)this->color,
			    (unsigned char)this->alpha);
	}
	
	gDPLoadMultiBlock(NEXT_OVERLAY_DISP, this->texture + txt_offset, 0, G_TX_RENDERTILE, G_IM_FMT_IA, G_IM_SIZ_8b, w, h, 0,
			    G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	if( game_play->scene_data_ID == GANON_DEMO ) {
	    gDPSetTileSize( NEXT_OVERLAY_DISP, G_TX_RENDERTILE+1,
			    0,
			    0x7f - ((wk<<1) & 0x7f),
			    0, 0 );
	}
	gSPTextureRectangle(NEXT_OVERLAY_DISP, x1, y1, x2, (y2 - 1),
			    G_TX_RENDERTILE,
			    0<<5, 0<<5,
			    1<<10,  1<<10);


	if ( (h = this->h - h) > 0 ) {
	    gDPLoadMultiBlock(NEXT_OVERLAY_DISP, this->texture + size + txt_offset,
			      0, G_TX_RENDERTILE, G_IM_FMT_IA, G_IM_SIZ_8b, w, h, 0,
			      G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			      G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	    
	    if( game_play->scene_data_ID == GANON_DEMO ) {
		gDPSetTileSize( NEXT_OVERLAY_DISP, G_TX_RENDERTILE+1,
				0,
				(0x7f - ((wk<<1) & 0x7f)) - ((wkh>>1) << 2),
				0, 0 );
	    }
	    
	    gSPTextureRectangle(NEXT_OVERLAY_DISP, x1, y2, x2, (y2 + (h << 2) - 1),
				G_TX_RENDERTILE,
				0<<5, 0<<5,
				1<<10,  1<<10);
	}
    
    
#if 0	
    gDPLoadTextureBlock(NEXT_OVERLAY_DISP, this->texture, G_IM_FMT_IA, G_IM_SIZ_8b, this->w, this->h, 0,
			    G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR,
			    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
	gSPTextureRectangle(NEXT_OVERLAY_DISP, (x4 - w2), (y4 - h2), (x4 + w2 - 4), (y4 + h2 - 4),
			    G_TX_RENDERTILE,
			    0<<5, 0<<5,
			    1<<10, 1<<10);
#endif
	
	CLOSE_DISP(game_play->g.graph);
    }
}
#endif


/*-----------------------------------------------------------------------
 *
 *	シーン名表示キャンセル
 *
 *----------------------------------------------------------------------*/
extern int Actor_Name_Disp_Cancel(Game_play *game_play, Actor_Name_Disp *this)
{
    if ( Name_Disp_Check2(game_play) ) {	/* シーン名表示中？ */
	
	this->wait_timer =
	this->timer      = 0;
	
	return FALSE;
    }
    
    return TRUE;
}

/************************************************************************
 *
 *	Ａｃｔｏｒクラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒクラス削除設定
 *
 *----------------------------------------------------------------------*/
extern void Actor_delete(
    Actor      *this
) 
{
    this->move_proc =
    this->draw_proc = NULL;
    
    Actor_clear_status(this, ACTOR_STATUS_ANCHOR);	/* 注目無しセット */
}

/*-----------------------------------------------------------------------
 *
 *	セット座標，方向を現在座標，方向へ
 *
 *----------------------------------------------------------------------*/
extern void Actor_home_to_world(
    Actor *this
)
{
    this->world = this->home;
}

/*-----------------------------------------------------------------------
 *
 *	現在座標を視点座標へ
 *
 *----------------------------------------------------------------------*/
extern void Actor_world_to_eye(
    Actor *this,
    float offset_y
)
{
    this->eye.position.x = this->world.position.x;
    this->eye.position.y = this->world.position.y + offset_y;
    this->eye.position.z = this->world.position.z;

    this->eye.angle.sx = this->world.angle.sx;
    this->eye.angle.sy = this->world.angle.sy;
    this->eye.angle.sz = this->world.angle.sz;
}

/*-----------------------------------------------------------------------
 *
 *	シェイプ方向を現在方向へ
 *
 *----------------------------------------------------------------------*/
extern void Actor_shape_to_world(
    Actor *this
)
{
    this->world.angle = this->shape.angle;
}

/*-----------------------------------------------------------------------
 *
 *	現在方向をシェイプ方向へ
 *
 *----------------------------------------------------------------------*/
extern void Actor_world_to_shape(
    Actor *this
)
{
    this->shape.angle = this->world.angle;
}

/*-----------------------------------------------------------------------
 *
 *	スケールセット	
 *
 *----------------------------------------------------------------------*/
extern void Actor_set_scale(
    Actor *this,
    float scale
)
{
    this->scale.x = 
    this->scale.y = 
    this->scale.z = scale; 
}

/*-----------------------------------------------------------------------
 *
 *	データセグメント設定
 *
 *----------------------------------------------------------------------*/
extern void Actor_set_segment(
    Game_play *game_play,
    Actor     *this
)
{
    SetSegmentK0(GAMEPLAY_OBJECT_EXCHANGE_SEGMENT, game_play->object_exchange.status[this->bank_ID].Segment);
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒクラス コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Actor_ct(
    Actor *this,
    Game  *game
)
{
    Game_play	*game_play = (Game_play *)game;
    
    Actor_home_to_world(this);					/* セット座標，方向を現在座標，方向へ */
    Actor_world_to_shape(this);					/* 現在方向をシェイプ方向へ */
    Actor_world_to_eye(this, 0.0f);				/* 現在座標を視点座標へ */	
    xyz_t_move(&this->old_position, &this->world.position);	/* 前フレーム座標セット */
    Actor_set_scale(this, 1.0f/100.0f);				/* スケールセット */

    this->anchor_range = ANCHOR_RANGE_D;		/* 注目可能距離タイプセット */
	
    this->max_speed_y  = -20.0f;			/* 最大落下速度セット */
    this->player_range = FLT_MAX;			/* 第一回目は注目無しセット */

    this->cull_z = 1000.0f;		                /* カリング距離セット */
    this->cull_r = 350.0f;		                /* カリング半径セット */
    this->cull_y = 700.0f;		                /* カリング高さセット */

    this->profile_message = 0xff;			/* プロフィールメッセージ番号リセット */
    
    
    /*
     * ステータスクリア
     */
    CollisionCheck_Status_ct(&this->status_info);
    
    this->ground_bg_actor_index = DYNA_ACTOR_NUM; /* デフォルト値 */
    
    Shape_Info_init(&this->shape,			/* シェイプ情報クラス コンストラクト */
		    0.0f,
		    NULL,
		    0.0f);

    if ( Object_Exchange_bank_dma_check(&game_play->object_exchange, (int)this->bank_ID) ) {	/* データ転送済み？ */

	/*
	 * データセグメント設定
	 */
	Actor_set_segment(game_play, this);

	this->constract_proc(this, game);	/* Ａｃｔｏｒ別コンストラクト */
	this->constract_proc = NULL;		/* コンストラクト呼び出し終了設定 */
    }
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒクラス デストラクト
 *
 *----------------------------------------------------------------------*/
extern void Actor_dt(
    Actor *this,
    Game  *game
)
{
    actor_name_show(this,"Actor_dt",0);
    if (this->destruct_proc != NULL) {
	
#ifdef DEBUG_P
	PRINTF("Ａｃｔｏｒクラス デストラクト 開始 %d %08x\n",
	       this->name, this->destruct_proc);
#endif
	
	this->destruct_proc(this, game);	/* Ａｃｔｏｒ別デストラクト */

#ifdef DEBUG_P
	PRINTF("Ａｃｔｏｒクラス デストラクト 終了 %d %08x\n",
	       this->name, this->destruct_proc);
#endif

	this->destruct_proc = NULL;

    } else {
#if DEBUG
	DLFTBL_ACTOR	*actor_dlftbl;
	char *actor_name;

	actor_dlftbl = (DLFTBL_ACTOR *)this->dlftbl;
	actor_name = actor_dlftbl_GetSegName(actor_dlftbl);
	
	PRINTF(    /* ESC_WARNING */
	       "Ａｃｔｏｒクラス デストラクトがありません [%s]\n"
	       ESC_NORMAL,
	       actor_name);
#endif	
    }
}

/*-----------------------------------------------------------------------
 *
 *	移動計算
 *
 *----------------------------------------------------------------------*/
extern void Actor_position_move(
    Actor *this
)
{
    float	frame_speed = (float)GetGameFrame()/2.0f;
    
#if 0
//    this->world.position.x += this->position_speed.x;
    this->world.position.x += this->position_speed.x * frame_speed;
//    this->world.position.y += this->position_speed.y;
    this->world.position.y += this->position_speed.y * frame_speed;
//    this->world.position.z += this->position_speed.z;
    this->world.position.z += this->position_speed.z * frame_speed;
#endif
    /* メモ：by matutani
     * coll_vecコリジョンチェックからの補正量
     */
    this->world.position.x += this->position_speed.x * frame_speed +
	this->status_info.coll_vec.x;
    this->world.position.y += this->position_speed.y * frame_speed +
	this->status_info.coll_vec.y;
    this->world.position.z += this->position_speed.z * frame_speed +
	this->status_info.coll_vec.z;
}

/*-----------------------------------------------------------------------
 *
 *	移動速度セット
 *
 *----------------------------------------------------------------------*/
extern void Actor_position_speed_set(
    Actor *this
)
{
    this->position_speed.x = this->speedF * sin_s(this->world.angle.sy);
    this->position_speed.z = this->speedF * cos_s(this->world.angle.sy);
    if ( (this->position_speed.y += this->gravity) < this->max_speed_y ) this->position_speed.y = this->max_speed_y;
}

/*-----------------------------------------------------------------------
 *
 *	移動速度セット＋移動計算
 *
 *----------------------------------------------------------------------*/
extern void Actor_position_moveF(
    Actor *this
)
{
    Actor_position_speed_set(this);
    Actor_position_move(this);
}

/*-----------------------------------------------------------------------
 *
 *	移動速度セット（＋Ｘ方向）
 *
 *----------------------------------------------------------------------*/
extern void Actor_position_speed_set_XY(
    Actor *this
)
{
    float	speedXY = this->speedF * cos_s(this->world.angle.sx);

    this->position_speed.x = speedXY * sin_s(this->world.angle.sy);
    this->position_speed.y = this->speedF * sin_s(this->world.angle.sx);
    this->position_speed.z = speedXY * cos_s(this->world.angle.sy);
}

/*-----------------------------------------------------------------------
 *
 *	移動速度セット＋移動計算（＋Ｘ方向）
 *
 *----------------------------------------------------------------------*/
extern void Actor_position_moveF_XY(
    Actor *this
)
{
    Actor_position_speed_set_XY(this);
    Actor_position_move(this);
}

/*-----------------------------------------------------------------------
 *
 *	３Ｄ移動速度セット
 *
 *----------------------------------------------------------------------*/
extern void Actor_vector_to_position_speed(
    Actor *this,
    float vector_speed
)
{
    this->speedF           = vector_speed * cos_s(this->world.angle.sx);
    this->position_speed.y = vector_speed * -(sin_s(this->world.angle.sx));
}

/*-----------------------------------------------------------------------
 *
 *	アニメーショントランスレート移動計算
 *
 *----------------------------------------------------------------------*/
extern void Actor_position_move_anime(
    Actor         *this,
    Skeleton_Info *skeleton
)
{
    xyz_t	anime_trans;
    
    Skeleton_Info_translate_set(skeleton, &anime_trans, this->shape.angle.sy);

    this->world.position.x += anime_trans.x * this->scale.x;
    this->world.position.y += anime_trans.y * this->scale.y;
    this->world.position.z += anime_trans.z * this->scale.z;
}

/*-----------------------------------------------------------------------
 *
 *	サーチＡｃｔｏｒＸＺ平面方向計算
 *
 *----------------------------------------------------------------------*/
extern short Actor_search_actor_angleY(
    Actor *this,
    Actor *target_actor
)
{
    return search_position_angleY(&this->world.position, &target_actor->world.position);
}

/*-----------------------------------------------------------------------
 *
 *	目線からのサーチＡｃｔｏｒＸＺ平面方向計算
 *
 *----------------------------------------------------------------------*/
extern short Actor_eye_search_actor_angleY(
    Actor *this,
    Actor *target_actor
)
{
    return search_position_angleY(&this->eye.position, &target_actor->eye.position);
}

/*-----------------------------------------------------------------------
 *
 *	サーチ座標ＸＺ平面方向計算
 *
 *----------------------------------------------------------------------*/
extern short Actor_search_position_angleY(
    Actor *this,
    xyz_t *target_position
)
{
    return search_position_angleY(&this->world.position, target_position);
}

/*-----------------------------------------------------------------------
 *
 *	サーチＡｃｔｏｒＹＺ平面方向計算
 *
 *----------------------------------------------------------------------*/
extern short Actor_search_actor_angleX(
    Actor *this,
    Actor *target_actor
)
{
    return search_position_angleX(&this->world.position, &target_actor->world.position);
}

/*-----------------------------------------------------------------------
 *
 *	目線からのサーチＡｃｔｏｒＹＺ平面方向計算
 *
 *----------------------------------------------------------------------*/
extern short Actor_eye_search_actor_angleX(
    Actor *this,
    Actor *target_actor
)
{
    return search_position_angleX(&this->eye.position, &target_actor->eye.position);
}
 
/*-----------------------------------------------------------------------
 *
 *	サーチ座標ＹＺ平面方向計算
 *
 *----------------------------------------------------------------------*/
extern short Actor_search_position_angleX(
    Actor *this,
    xyz_t *target_position
)
{
    return search_position_angleX(&this->world.position, target_position);
}

/*-----------------------------------------------------------------------
 *
 *	サーチＡｃｔｏｒ３Ｄ距離計算
 *
 *----------------------------------------------------------------------*/
extern float Actor_search_actor_distance(
    Actor *this,
    Actor *target_actor
)
{
    return search_position_distance(&this->world.position, &target_actor->world.position);
}

/*-----------------------------------------------------------------------
 *
 *	サーチ座標３Ｄ距離計算
 *
 *----------------------------------------------------------------------*/
extern float Actor_search_position_distance(
    Actor *this,
    xyz_t *target_position
)
{
    return search_position_distance(&this->world.position, target_position); 
}

/*-----------------------------------------------------------------------
 *
 *	サーチＡｃｔｏｒＸＺ平面距離計算
 *
 *----------------------------------------------------------------------*/
extern float Actor_search_actor_distanceXZ(
    Actor *this,
    Actor *target_actor
)
{
    return search_position_distanceXZ(&this->world.position, &target_actor->world.position);
}

/*-----------------------------------------------------------------------
 *
 *	サーチ座標ＸＺ平面距離計算
 *
 *----------------------------------------------------------------------*/
extern float Actor_search_position_distanceXZ(
    Actor *this,
    xyz_t *target_position
)
{
    return search_position_distanceXZ(&this->world.position, target_position);
}

/*-----------------------------------------------------------------------
 *
 *	サーチ座標ＸＺ平面投影距離計算
 *
 *----------------------------------------------------------------------*/
extern void Actor_search_position_project_distanceXZ(
    Actor *this,
    xyz_t *distance,
    xyz_t *target_position
)
{
    float	cos_data = cos_s(this->shape.angle.sy);
    float	sin_data = sin_s(this->shape.angle.sy);
    float	sx = target_position->x - this->world.position.x;
    float	sz = target_position->z - this->world.position.z;
    
    distance->x = -(sz * sin_data) + sx * cos_data;
    distance->z = sx * sin_data + sz * cos_data;
    distance->y = target_position->y - this->world.position.y;
}

/*-----------------------------------------------------------------------
 *
 *	サーチＡｃｔｏｒＹ距離計算
 *
 *----------------------------------------------------------------------*/
extern float Actor_search_actor_high(
    Actor *this,
    Actor *target_actor
)
{
    return target_actor->world.position.y - this->world.position.y;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー身長セット
 *
 *----------------------------------------------------------------------*/
extern float player_get_tall(
    Actor *thisx
)
{
    Player_actor	*player = (Player_actor *)thisx;
    float		tall_size = (bitcheck(player->action, P_ACTION_RIDE_HORSE) ? 32.0f : 0.0f);

    if ( !ZCommonGet(link_age) ) return (tall_size + (170.0f * (68.0f/170.0f)));
    else		         return (tall_size + (110.0f * (68.0f/170.0f)));
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー最大スピードセット
 *
 *----------------------------------------------------------------------*/
extern float player_get_max_speed(
    Actor *thisx
)
{
    Player_actor	*player = (Player_actor *)thisx;
    
    if ( bitcheck(player->action, P_ACTION_RIDE_HORSE) ) return En_Horse_get_max_speed();	/* 乗馬中？ */
    else if ( bitcheck(player->action, P_ACTION_SWIM) )  return ((float)REG(45)/100.0f) * 0.6f;	/* 泳ぎ？ */
    else					         return ((float)REG(45)/100.0f);
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー弓矢モードチェック
 *
 *----------------------------------------------------------------------*/
extern int player_bow_check(
    Actor *thisx
)
{
    Player_actor	*player = (Player_actor *)thisx;

    return (int)bitcheck(player->action, P_ACTION_BOW);
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー弓矢構えチェック
 *
 *----------------------------------------------------------------------*/
extern int player_bow_ready_check(
    Actor *thisx
)
{
    Player_actor	*player = (Player_actor *)thisx;

    return (player_bow_check(thisx) && player->uperbody_counter);
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー戦闘モードチェック
 *
 *----------------------------------------------------------------------*/
extern int player_fight_check(
    Game_play *game_play
)
{
    Player_actor	*player = (Player_actor *)get_player_actor(game_play);
    
    return (bitcheck(player->action, P_ACTION_CARRY) ||
	    player_bow_ready_check((Actor *)player));
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤーオーバーアクションチェック
 *
 *----------------------------------------------------------------------*/
extern int player_big_SE_action_check(
    Game_play *game_play
)
{
    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    return (bitcheck(player->action2, P_ACTION2_BIG_SE_SET));
}    

/*-----------------------------------------------------------------------
 *
 *	プレイヤー梯子ｏｒ壁登り中で停止フラグチェック
 *
 *----------------------------------------------------------------------*/
extern int player_climb_stop_check(
    Game_play *game_play
)
{
    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    return (bitcheck(player->action2, P_ACTION2_CLIMB_STOP));
}    

/*-----------------------------------------------------------------------
 *
 *	プレイヤーフックショット引っ張られ入れ替え
 *
 *----------------------------------------------------------------------*/
extern void player_hook_carry_change(
    Game_play *game_play,
    Actor     *carry_actor,
    Actor     *change_actor
)
{
    Arms_Hook_actor	*hook_shot = (Arms_Hook_actor *)Actor_info_name_search(&game_play->actor_info,
									       ACTOR_NAME_ARMS_HOOK,
									       ACTOR_PART_EFFECT);
    
    hook_shot->carry_actor    = change_actor;
    hook_shot->carry_offset.x =
    hook_shot->carry_offset.y =
    hook_shot->carry_offset.z = 0.0f;
    Actor_set_status(change_actor, ACTOR_STATUS_HOOK_CARRY_NOW);	/* フックショット引っ張られ中フラグセット */
    
    Actor_clear_status(carry_actor, ACTOR_STATUS_HOOK_CARRY_NOW);	/* フックショット引っ張られ中フラグリセット */
}    

/*-----------------------------------------------------------------------
 *
 *	乗馬サブカメラセット
 *
 *----------------------------------------------------------------------*/
extern void player_make_horse_camera(
    Game_play *game_play,
    Actor     *thisx
)
{
    if ( game_play->room_info.now.type != ROOM_TYPE_TOWN &&	/* ROOMで無いとき */
	 Game_play_change_camera_check(game_play) ) {		/* カメラ切り替えＯＫ？ */
	 
	/*
	 * カメラセット
	 */
	changeCameraSet(NOW_CAMERA, CAM_SET_HORSE0);
    }
}

/*-----------------------------------------------------------------------
 *
 *	乗馬初期設定
 *
 *----------------------------------------------------------------------*/
extern void player_ride_horse_init(
    Game_play *game_play,
    Actor     *thisx,
    Actor     *horse_actor
)
{
    Player_actor	*player = (Player_actor *)thisx;

    game_play;
    
    bitset(player->action, P_ACTION_RIDE_HORSE);	/* 乗馬フラグセット */
    player->ride.actor = horse_actor;
    
    /*
     * 馬へ連絡
     */
    horse_actor->child = thisx;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤーＡｃｔｏｒデモ状態チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_player_demo_check(
    Actor *player_actor
)
{
    return (bitcheck(((Player_actor *)player_actor)->action, (P_ACTION_DOWN | P_ACTION_DEMO)) ||	/* デモ中？ */
	    ((Player_actor *)player_actor)->demo_play.mode);
}

/*-----------------------------------------------------------------------
 *
 *	馬セットチェック
 *
 *----------------------------------------------------------------------*/
extern void Actor_Horse_Set_Check(
    Game_play *game_play,
    Actor     *thisx
)
{
    Horse_Set_Check(game_play, thisx);
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー停止デモセット
 *
 *----------------------------------------------------------------------*/
extern int player_demo_mode_set2(
    Game_play     *game_play,
    Actor         *this,
    unsigned char mode
)
{
    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

//    if ( !bitcheck(player->action, P_ACTION_SWIM) ) {
	
    player->demo_play.mode         = mode;
    player->demo_play.anchor_actor = this;
    player->demo_play.work         = OFF;
//    }
    
    return TRUE; 
}

extern int player_demo_mode_set(
    Game_play     *game_play,
    Actor         *this,
    unsigned char mode
)
{
    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    player_demo_mode_set2(game_play,
			  this,
			  mode);

    player->demo_play.work = ON;	/* デモフラグＯＮセット */
    
    return TRUE; 
}

/*-----------------------------------------------------------------------
 *
 *	ダイナミックＢＧパワークリアー
 *
 *----------------------------------------------------------------------*/
extern void MoveBG_Actor_power_clear(
    MoveBG_Actor *this
)
{
    this->powerF =
    this->powerY = 0.0f;
}

/*-----------------------------------------------------------------------
 *
 *	ダイナミックＢＧパワーセット
 *
 *----------------------------------------------------------------------*/
extern void MoveBG_Actor_powerF_set(
    MoveBG_Actor *this,
    float	 powerF,
    short	 power_angle_y
)
{
    this->powerF       += powerF;
    this->power_angle_y = power_angle_y;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤーがこっちを向いているか？チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_player_look_direction_check(
    Actor     *this,
    short     angle,
    Game_play *game_play
)
{
    Player_actor	*player_actor    = (Player_actor *)get_player_actor(game_play);
    short		distance_angle_y = distance_angle((short)(this->player_angle_y + 0x8000),
							  player_actor->actor.shape.angle.sy); 

    if ( ABS(distance_angle_y) < angle ) return TRUE;

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	相手Ａｃｔｏｒがこっちを向いているか？チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_look_direction_check(
    Actor *this,
    Actor *target_actor,
    short angle
)
{
    short	search_angle_y   = Actor_search_actor_angleY(this, target_actor);
    short	distance_angle_y = distance_angle((short)(search_angle_y + 0x8000),
						  target_actor->shape.angle.sy); 

    if ( ABS(distance_angle_y) < angle ) return TRUE;

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤーのいる方向チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_player_direction_check(
    Actor *this,
    short angle
)
{
    short	distance_angle_y = distance_angle(this->player_angle_y, this->shape.angle.sy); 
    
    if ( ABS(distance_angle_y) < angle ) return TRUE;

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒのいる方向チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_actor_direction_check(
    Actor *this,
    Actor *target_actor,
    short angle
)
{
    short	search_angle_y   = Actor_search_actor_angleY(this, target_actor);
    short	distance_angle_y = distance_angle(search_angle_y, this->shape.angle.sy); 

    if ( ABS(distance_angle_y) < angle ) return TRUE;

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤーのいる距離と方向チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_player_distance_direction_check(
    Actor *this,
    float distance,
    short angle
)
{
    short	distance_angle_y = distance_angle(this->player_angle_y, this->shape.angle.sy); 
    
    if ( ABS(distance_angle_y) < angle ) {
	
	float	player_distance = sqrtf((this->player_distance * this->player_distance) +
					(this->player_high * this->player_high));
	
	if ( player_distance < distance ) return TRUE;
    }
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒのいる距離と方向チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_actor_distance_direction_check(
    Actor *this,
    Actor *target_actor,
    float distance,
    short angle
)
{
    if ( Actor_search_actor_distance(this, target_actor) < distance ) {

	short	distance_angle_y = distance_angle(Actor_search_actor_angleY(this, target_actor), this->shape.angle.sy); 
	
	if ( ABS(distance_angle_y) < angle ) return TRUE;
    }
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	ＢＧチェック							*
 *
 *----------------------------------------------------------------------*/
static T_Polygon	*roof_polygon_info;
static int		roof_pbg_actor_index;

#define	GROUND_NO_HIT_OK_OFFSET_Y	-11.0f

extern int ground_no_hit_set(
    Actor *this,
    float ground_offset_y,
    int	  flag
)
{
    if ( bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND) &&	/* 現在着地中？ */
	 ground_offset_y < GROUND_NO_HIT_OK_OFFSET_Y ) {
	
	bitclr(this->environment_info, ENVIRONMENT_INFO_GROUND);	/* 着地中リセット */
	bitset(this->environment_info, ENVIRONMENT_INFO_GROUND_LEAVE);	/* 空中への瞬間セット */
	
	if ( this->position_speed.y < 0.0f &&
	     bitcheck(flag, BGCHECK_GROUND_LEAVE_SP_CLR) ) this->position_speed.y = 0.0f;

	return FALSE;
    }

    return TRUE;
}

/*-----------------------------------------------------------------------
 *
 *	足ＢＧチェック
 *
 *----------------------------------------------------------------------*/
static int Actor_foot_bgcheck(
    Game_play *game_play,
    Actor     *this,
    xyz_t     *foot_pos,
    int	      flag
)
{
    float	offset_y;
    int		pbg_actor_index;
    
    foot_pos->y += GROUND_BGCHECK_OFFSET_Y;
    
    this->ground_y = T_BGCheck_ObjGroundCheck_aiac2(
	game_play,
	&game_play->BGCheck,
	&this->ground_polygon_info,
	&pbg_actor_index,
	this,
	foot_pos);
    
    bitclr(this->environment_info, (ENVIRONMENT_INFO_LANDING |
				    ENVIRONMENT_INFO_GROUND_LEAVE |
				    ENVIRONMENT_INFO_GROUND_HIT));	/* 情報フラグリセット */

    if ( this->ground_y <= -BGCHECK_OVER_Y ) {	/* エリアオーバー？ */
	
	return ground_no_hit_set(this, -BGCHECK_OVER_Y, flag);
    }
    else {

	this->ground_bg_actor_index = (unsigned char)pbg_actor_index;	/* ダイナミック用アクターインデックスセット */
	
	offset_y = this->ground_y - this->world.position.y;

//	if ( 0.0f <= offset_y &&
//	     offset_y < (move_speed_y + GROUND_HIT_OFFSET_Y) ) {	/* 着地？ */
	if ( 0.0f <= offset_y ) {	/* 着地？ */
	    
	    bitset(this->environment_info, ENVIRONMENT_INFO_GROUND_HIT);	/* 床衝突 */

	    if ( bitcheck(this->environment_info, ENVIRONMENT_INFO_ROOF) ) {	/* 天井衝突？ */

		if ( roof_pbg_actor_index != pbg_actor_index ) {	/* 天井と床に挟まれ？ */

		    if ( offset_y > 15.0f ) bitset(this->environment_info, ENVIRONMENT_INFO_SANDWICH);
		}
		else {							/* 挟まれ補正 */

		    this->world.position.x = this->old_position.x;
		    this->world.position.z = this->old_position.z;
		}
	    }
	    this->world.position.y = this->ground_y;
	    
	    if ( this->position_speed.y <= 0.0f ) {	/* 下降中？ */
		
		if ( !bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND) ) {	/* 着地の瞬間？ */
		    
		    bitset(this->environment_info, ENVIRONMENT_INFO_LANDING);	/* 着地の瞬間セット */
		}
		else if ( bitcheck(flag, BGCHECK_GROUND_DOWN_SP_SET) &&
			  this->gravity < 0.0f ) {
		    
		    this->position_speed.y = GROUND_HIT_SET_SPEED_Y;	/* （仮）下り坂で落下にならない様に */
		}
		else {

		    this->position_speed.y = 0.0f;
		}
		bitset(this->environment_info, ENVIRONMENT_INFO_GROUND);	/* 着地中セット */

#ifdef DYNA_POLY_TEST
		/* 注意:着地中のみ動作したい */
		BGCheckCollection_setRideStatus(
		    &game_play->BGCheck, this, this->ground_bg_actor_index);
#endif
	    }
	}
	else {		/* 空中 */

	    if ( bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND) &&
		 offset_y >= GROUND_NO_HIT_OK_OFFSET_Y ) {

		BGCheckCollection_setRideStatus(
		    &game_play->BGCheck, this, this->ground_bg_actor_index);
	    }
	    
	    return ground_no_hit_set(this, offset_y, flag);
	}
    }

    return TRUE;
}

/*-----------------------------------------------------------------------
 *
 *	（新）ＢＧチェック
 *
 *----------------------------------------------------------------------*/
extern void Actor_BGcheck2(
    Game_play *game_play,
    Actor     *this,
    float     wall_check_h,
    float     wall_check_r,
    float     roof_check_h,
    int	      flag
)
{
    float 	move_speed_y 	    = this->world.position.y - this->old_position.y;
    int 	old_pbg_actor_index = this->ground_bg_actor_index;
    xyz_t 	tmp_pos;
    
    /*
     * moveBG
     */
    if (old_pbg_actor_index != DYNA_ACTOR_NUM &&
	bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND)) {
	BGCheckCollection_proc(&game_play->BGCheck, old_pbg_actor_index,
			       this);
    }

    /*
     * 壁チェック
     */
    if ( bitcheck(flag, BGCHECK_WALL) ) {	/* 壁チェック？ */

	int	pbg_actor_index;
	if ((!bitcheck(flag, BGCHECK_WALL_LINE_CHECK_OFF) &&
	     T_BGCheck_ObjWallCheck2_aiac(
		 &game_play->BGCheck,
		 &tmp_pos,
		 &this->world.position,
		 &this->old_position,
		 wall_check_r,
		 &this->wall_polygon_info,
		 &pbg_actor_index,
		 this,
		 wall_check_h)) ||
	    (bitcheck(flag, BGCHECK_WALL_LINE_CHECK_OFF) &&
	     T_BGCheck_ObjWallCheck2_aiac_nl(
		 &game_play->BGCheck,
		 &tmp_pos,
		 &this->world.position,
		 &this->old_position,
		 wall_check_r,
		 &this->wall_polygon_info,
		 &pbg_actor_index,
		 this,
		 wall_check_h))
	    ) { /* 衝突？ */
	    /*
	     * 壁衝突
	     */
	    T_Polygon	*wall_polygon_info = this->wall_polygon_info;

	    xyz_t_move(&this->world.position, &tmp_pos); /* 補正されたのでコピー */

#if 0	    
	    if ( bitcheck(flag, BGCHECK_WALL_HIT_CONTINUE) ) {	/* 壁衝突継続？ */
		
		float	dx = tmp_pos.x - this->world.position.x;
		float	dz = tmp_pos.z - this->world.position.z;
		float	dr = sqrtf((dx * dx) + (dz * dz));
		
		if ( dr != 0.0f ) {
		    
		    dr = 1.0f / dr;
		    this->world.position.x += dx * dr;
		    this->world.position.z += dz * dr;
		}
	    }
#endif
	    
	    this->wall_angle_y = atans_table((float)wall_polygon_info->c, (float)wall_polygon_info->a); /* 壁角度 */
	    
	    bitset(this->environment_info, ENVIRONMENT_INFO_WALL);	/* 壁衝突セット */
	    this->wall_bg_actor_index = (unsigned char)pbg_actor_index;	/* ダイナミック用アクターインデックスセット */
	}
	else {
	    
	    bitclr(this->environment_info, ENVIRONMENT_INFO_WALL);	/* 壁衝突リセット */
	}
    }
    
    /*
     * 天井チェック
     */
    tmp_pos.x = this->world.position.x;
    tmp_pos.z = this->world.position.z;   
    if ( bitcheck(flag, BGCHECK_ROOF) ) {	/* 天井チェック？ */

	float	check_result_y;
	
	tmp_pos.y = this->old_position.y + 10.0f;
	if ( T_BGCheck_ObjRoofCheck_aiac(&game_play->BGCheck,
					 &check_result_y,
					 &tmp_pos,
					 roof_check_h + move_speed_y - 10.0f,
					 &roof_polygon_info,
					 &roof_pbg_actor_index,
					 this) ) {			/* 衝突？ */

	    bitset(this->environment_info, ENVIRONMENT_INFO_ROOF);	/* 天井衝突セット */

	    this->world.position.y = check_result_y + move_speed_y - 10.0f; 
	}
	else {
	    
	    bitclr(this->environment_info, ENVIRONMENT_INFO_ROOF);	/* 天井衝突リセット */
	}
    }

    /* 床チェック */
    if ( bitcheck(flag, BGCHECK_GROUND) ) {	/* 床チェック？ */

	Water_Info	*water_info;
	float		water_surface_pos_y;

	/*
	 * 足元チェック
	 */
//	tmp_pos.y = this->world.position.y - move_speed_y;
	tmp_pos.y = this->old_position.y;
	Actor_foot_bgcheck(game_play, this, &tmp_pos, flag);

	/*
	 * 水面チェック
	 */
	water_surface_pos_y = this->world.position.y;
	if ( T_BGCheck_WaterSurfaceCheck3(game_play,
					  &game_play->BGCheck,
					  this->world.position.x,
					  this->world.position.z,
					  &water_surface_pos_y,
					  &water_info) ) {	/* 水面の上？ */
	    
	    this->water_surface_y = water_surface_pos_y - this->world.position.y;	/* 水面Ｙ距離セット */
	    if ( this->water_surface_y < 0.0f ) {	/* 水中でない？ */
		
		bitclr(this->environment_info, (ENVIRONMENT_INFO_WATER | ENVIRONMENT_INFO_WATER_DIVE));
	    }
	    else {					/* 水中 */
		
		if ( !bitcheck(this->environment_info, ENVIRONMENT_INFO_WATER) ) {	/* 水中への瞬間？ */
		    
		    xyz_t	effect_pos;
		    
		    bitset(this->environment_info, ENVIRONMENT_INFO_WATER_DIVE);	/* 水中への瞬間フラグセット */
		    
#if 0		
		    /*
		     * 水しぶきセット
		     */
		    effect_pos.x = this->world.position.x;
		    effect_pos.y = water_surface_pos_y;
		    effect_pos.z = this->world.position.z;
		    Effect_SS_G_Splash_ct((Game *)game_play, &effect_pos,
					  (this->position_speed.y > -8.0f ? EFF_G_SPLASH_1 : EFF_G_SPLASH_2));
#endif
		    /* 波紋セットチェック */
		    if ( !bitcheck(flag, BGCHECK_RIPPLE_NOSET) ) {	/* 床チェック？ */
			/*
			 * 波紋セット
			 */
			effect_pos.x = this->world.position.x;
			effect_pos.y = water_surface_pos_y;
			effect_pos.z = this->world.position.z;
			Effect_SS_G_Ripple_ct((Game *)game_play, &effect_pos, 100.0f, 0);
			Effect_SS_G_Ripple_ct((Game *)game_play, &effect_pos, 100.0f, 4);
			Effect_SS_G_Ripple_ct((Game *)game_play, &effect_pos, 100.0f, 8);
		    }      
		}

		bitset(this->environment_info, ENVIRONMENT_INFO_WATER);	/* 水中フラグセット */
	    }
	}
	else {

	    this->water_surface_y = -BGCHECK_OVER_Y;	/* 水面Ｙ距離セット */
	    
	    bitclr(this->environment_info, (ENVIRONMENT_INFO_WATER | ENVIRONMENT_INFO_WATER_DIVE));
	}
    }
}

/*-----------------------------------------------------------------------
 *
 *	ハイライト環境マッピング登録
 *
 *----------------------------------------------------------------------*/
extern Gfx *HiliteReflect_new(
    xyz_t  *object,
    xyz_t  *eye,
    xyz_t  *light_direction,
    Graph  *graph,
    Gfx	   *gfxp,
    Hilite **hilitep
)
{
    static Mtx	work_view_matrix;

//    Hilite	*hilitep = graph_new(graph, Hilite);
    LookAt	*lookatp = graph_new(graph, LookAt);
    float       eye_x = (eye->x == object->x && eye->z == object->z
			 ? eye->x + .001f : eye->x);
    /* Ｙ軸上に２点が並ぶと落ちるバグへの対策 */

    *hilitep = graph_new(graph, Hilite);

    /*
     * ハイライト設定
     */
#ifndef DEBUG_MODE_NOINPUT    
    if (HREG(80) == 6) {
	PRINTF("z_actor.c 3529 "
	       "eye=[%f(%f) %f %f] object=[%f %f %f] light_direction=[%f %f %f]\n",
	       eye_x, eye->x, eye->y, eye->z,
	       object->x, object->y, object->z, 
	       light_direction->x, light_direction->y, light_direction->z );
    }
#endif	/* DEBUG_MODE_NOINPUT */
    
    debug_eyecheck(eye_x, eye->y, eye->z);
    guLookAtHilite(&work_view_matrix,
		   lookatp,
//		   hilitep,
		   *hilitep,
		   eye_x, eye->y, eye->z,
		   object->x, object->y, object->z, 
		   0.0f, 1.0f, 0.0f,
		   light_direction->x,
		   light_direction->y,
		   light_direction->z,
		   light_direction->x,
		   light_direction->y,
		   light_direction->z,
		   16, 16);

    /*
     * ハイライト設定ディスプレイリストセット
     */
    gSPLookAt(gfxp++, lookatp);
//    gDPSetHilite1Tile(gfxp++, G_TX_RENDERTILE+1, hilitep, 16, 16);
    gDPSetHilite1Tile(gfxp++, G_TX_RENDERTILE+1, *hilitep, 16, 16);

//    /*
//     * ハイライトデータセグメントアドレス設定
//     */
//    gSPSegment(gfxp++, HILITE_SEGMENT, hilitep);
    
    return gfxp;
}

/*-----------------------------------------------------------------------
 *
 *	ハイライト環境マッピング初期設定
 *
 *----------------------------------------------------------------------*/
static Gfx	dummy_hilite_data[] = {
    gsSPEndDisplayList()
};

extern Hilite *HiliteReflect_init(
    xyz_t *object,
    xyz_t *eye,
    xyz_t *light_direction,
    Graph *graph
)
{
    Hilite	*hilitep;
    
    OPEN_DISP(graph);

    /*
     * ハイライト環境マッピング登録
     */
    SET_NOW_POLY_OPA_DISP(HiliteReflect_new(object, eye, light_direction, graph, NOW_POLY_OPA_DISP, &hilitep));

    CLOSE_DISP(graph);

    return hilitep;
}

/*-----------------------------------------------------------------------
 *
 *	ハイライト環境マッピング初期設定（半透明）
 *
 *----------------------------------------------------------------------*/
extern Hilite *HiliteReflect_xlu_init(
    xyz_t *object,
    xyz_t *eye,
    xyz_t *light_direction,
    Graph *graph
)
{
    Hilite	*hilitep;
    
    OPEN_DISP(graph);

    /*
     * ハイライト環境マッピング登録
     */
    SET_NOW_POLY_XLU_DISP(HiliteReflect_new(object, eye, light_direction, graph, NOW_POLY_XLU_DISP, &hilitep));

    CLOSE_DISP(graph);

    return hilitep;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒハイライト環境マッピング設定データセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_HiliteReflect_set_init(
    Actor     *this,
    Game_play *game_play,
    int	      flag
)
{
    Hilite	*hilitep;
    xyz_t	light_direction;

    light_direction.x = (float)game_play->kankyo.sun_light.status.diffuse.dx;
    light_direction.y = (float)game_play->kankyo.sun_light.status.diffuse.dy;
    light_direction.z = (float)game_play->kankyo.sun_light.status.diffuse.dz;

    /*
     * ハイライト環境マッピング初期設定
     */
#ifndef DEBUG_MODE_NOINPUT    
    if (HREG(80) == 6) {
	PRINTF("z_actor.c 3637 "
	       "game_play->view.eye=[%f(%f) %f %f]\n",
	       game_play->view.eye.x,
	       game_play->view.eye.y,
	       game_play->view.eye.z);
    }
#endif	/* DEBUG_MODE_NOINPUT */
    hilitep = HiliteReflect_init(&this->world.position,
				 &game_play->view.eye,
				 &light_direction,
				 game_play->g.graph);

    if ( flag ) {
    
	Gfx 	*gfxp  = (Gfx *)graph_alloc(game_play->g.graph, (2 * sizeof(Gfx)));
	Gfx	*gfxp2 = gfxp;
	
	OPEN_DISP(game_play->g.graph);
	
	/*
	 * ハイライトデータセグメントアドレス設定
	 */
	gDPSetHilite1Tile(gfxp++, G_TX_RENDERTILE+1, hilitep, 16, 16);
	gSPEndDisplayList(gfxp);
	
	gSPSegment(NEXT_DISP, HILITE_SEGMENT, gfxp2);

	CLOSE_DISP(game_play->g.graph);
    }
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒハイライト環境マッピング設定データセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_HiliteReflect_xlu_set_init(
    Actor     *this,
    Game_play *game_play,
    int	      flag
)
{
    Hilite	*hilitep;
    xyz_t	light_direction;

    light_direction.x = (float)game_play->kankyo.sun_light.status.diffuse.dx;
    light_direction.y = (float)game_play->kankyo.sun_light.status.diffuse.dy;
    light_direction.z = (float)game_play->kankyo.sun_light.status.diffuse.dz;

    /*
     * ハイライト環境マッピング初期設定
     */
    hilitep = HiliteReflect_xlu_init(&this->world.position,
				     &game_play->view.eye,
				     &light_direction,
				     game_play->g.graph);
    
    if ( flag ) {
    
	Gfx 	*gfxp  = (Gfx *)graph_alloc(game_play->g.graph, (2 * sizeof(Gfx)));
	Gfx	*gfxp2 = gfxp;
	
	OPEN_DISP(game_play->g.graph);
	
	/*
	 * ハイライトデータセグメントアドレス設定
	 */
	gDPSetHilite1Tile(gfxp++, G_TX_RENDERTILE+1, hilitep, 16, 16);
	gSPEndDisplayList(gfxp);
	
	gSPSegment(NEXT_POLY_XLU_DISP, HILITE_SEGMENT, gfxp2);

	CLOSE_DISP(game_play->g.graph);
    }
}

/*-----------------------------------------------------------------------
 *
 *	視点座標，方向読み込み
 *
 *----------------------------------------------------------------------*/
extern Position_Angle Actor_get_eye(
    Actor *this
)
{
    return this->eye;
}

/*-----------------------------------------------------------------------
 *
 *	ワールド座標，方向読み込み
 *
 *----------------------------------------------------------------------*/
extern Position_Angle Actor_get_world(
    Actor *this
)
{
    return this->world;
}

/*-----------------------------------------------------------------------
 *
 *	シェイプ座標，方向読み込み
 *
 *----------------------------------------------------------------------*/
extern Position_Angle Actor_get_shape(
    Actor *this
)
{
    Position_Angle	shape;

    xyz_t_move(&shape.position, &this->world.position);
    shape.angle = this->shape.angle;
    
    return shape;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ注目度計算
 *
 *----------------------------------------------------------------------*/
static float Actor_anchor_ratio(
    Actor     *this,
    Actor     *player,
    short     target_angle_y
)
{
    Player_actor	*player_actor    = (Player_actor *)player;
    short		distance_angle_y = (short)ABS(distance_angle((short)(this->player_angle_y - 0x8000), target_angle_y));

#if 0
    if ( player_actor->camera_parameter.primary_actor == NULL &&
	 distance_angle_y > 0x2aaa ) return FLT_MAX;
#else
    if ( player_actor->camera_parameter.primary_actor != NULL ) {	/* 現在注目中？ */

	float	search_range;
	
	if ( distance_angle_y > 0x4000 ||
	     Actor_bitcheck_status(this, ACTOR_STATUS_ANCHOR_NO_ROCK) ) return FLT_MAX;
	
	search_range = this->player_range -
	    ((this->player_range * 0.8f) * ((float)(0x4000 - distance_angle_y) * (1.0f/32768.0f)));
	
	return search_range;
    }
    else {
	
	if ( distance_angle_y > 0x2aaa ) return FLT_MAX;
    }
#endif
    
    return this->player_range;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ注目度チェック
 *
 *----------------------------------------------------------------------*/
#if 0
typedef struct {
    float	range;
    float	cancel_ratio;
} Anchor_Status;
#endif

extern Anchor_Status	anchor_status_data[ANCHOR_RANGE_MAX] = {
    {(70.0f*70.0f),     (1.0f / 2.0f)},		/* ANCHOR_RANGE_A */
    {(170.0f*170.0f),   (1.0f / 1.5f)},		/* ANCHOR_RANGE_B */
    {(280.0f*280.0f),   (1.0f / 20.0f)},	/* ANCHOR_RANGE_C */
    {(350.0f*350.0f),   (1.0f / 1.5f)},		/* ANCHOR_RANGE_D */
    {(700.0f*700.0f),   (1.0f / 1.5f)},		/* ANCHOR_RANGE_E */
    {(1000.0f*1000.0f), (1.0f / 1.5f)},		/* ANCHOR_RANGE_F */

    /* 人間注目専用	*/
    {(100.0f*100.0f),	(95.0f / 100.1f)},	/* ANCHOR_RANGE_G */
    {(140.0f*140.0f),	(120.0f / 140.0f)},	/* ANCHOR_RANGE_H */
    {(240.0f*240.0f),	(100.0f / 240.0f)},	/* ANCHOR_RANGE_I */

    {(280.0f*280.0f),	(1.0f / 1000.0f)},	/* ANCHOR_RANGE_P */
};

static int Actor_anchor_ratio_check(
    Actor     *this,
    float     ratio
)
{
    return (ratio < anchor_status_data[this->anchor_range].range);
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ注目度チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_anchor_check(
    Actor *this,
    Actor *player,
    int	  flag
)
{
    if ( this->move_proc == NULL ||					/* 消去？ */
	 !Actor_bitcheck_status(this, ACTOR_STATUS_ANCHOR_KEEP) ) {	/* 注目対象外？ */
	
	return TRUE;
    }
    else if ( !flag ) {

#if 0	
	float	ratio = Actor_anchor_ratio(this,
					   player,
					   player->shape.angle.sy);
#else	
	short	distance_angle_y = (short)ABS(distance_angle((short)(this->player_angle_y - 0x8000), player->shape.angle.sy));
	float	ratio 		 = ((((Player_actor *)player)->camera_parameter.primary_actor == NULL &&
				     distance_angle_y > 0x2aaa) ? FLT_MAX : this->player_range);
#endif
	
	return !Actor_anchor_ratio_check(this,
					 (ratio * anchor_status_data[this->anchor_range].cancel_ratio)); /* 逃げた？ */
    }
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	会話チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_talk_check(
    Actor     *this,
    Game_play *game_play
)
{
    game_play;
    
    if ( Actor_bitcheck_status(this, ACTOR_STATUS_TALKING_NOW) ) {	/* 会話相手は私？ */

	Actor_clear_status(this, ACTOR_STATUS_TALKING_NOW);
	
	return TRUE;
    }
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	会話意思セット
 *
 *----------------------------------------------------------------------*/
extern int Actor_talk_request_get_item_set(
    Actor     *this,
    Game_play *game_play,
    float     size_r,
    float     size_h,
    int	      get_item
)
{
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);

    if ( Actor_bitcheck_status((Actor *)player_actor, ACTOR_STATUS_TALKING_NOW) ||	/* プレイヤー会話中？ */
	 (get_item &&
	  player_demo_check(game_play)) ||
	 (!this->anchor_flag &&								/* 注目されてない？ */
	  (fabsf(this->player_high) > size_h ||						/* 会話距離ＯＫ？ */
	   this->player_distance > player_actor->talk_distance ||
	   this->player_distance > size_r)) ) {
	
	return FALSE;
    }
    player_actor->talk_actor    = this;
    player_actor->talk_distance = this->player_distance;
    player_actor->put_item 	= get_item;
    
    return TRUE;
}

extern int Actor_talk_request_get_item(
    Actor     *this,
    Game_play *game_play,
    float     size_r,
    int	      get_item
)
{
    return Actor_talk_request_get_item_set(this, game_play, size_r, size_r, get_item);
}

extern int Actor_talk_request2(
    Actor     *this,
    Game_play *game_play,
    float     size_r
)
{
    return Actor_talk_request_get_item(this, game_play, size_r, 0);
}

extern int Actor_talk_request(
    Actor     *this,
    Game_play *game_play
)
{
    float	size = this->status_info.r + 50.0f;
    
    return Actor_talk_request2(this, game_play, size);
}

/*-----------------------------------------------------------------------
 *
 *	会話終了チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_talk_end_check(
    Actor     *this,
    Game_play *game_play
) 
{
    this;
    
    if ( message_check(&game_play->message) == 2 ) return TRUE;	/* 会話終了？ */

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤーからのゲットアイテムチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_get_item_check(
    Game_play *game_play
)
{
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);

    return player_actor->put_item;
}

/*-----------------------------------------------------------------------
 *
 *	表示座標計算
 *
 *----------------------------------------------------------------------*/
extern void Actor_display_position_set(
    Game_play *game_play,
    Actor     *this,
    short     *display_x,
    short     *display_y
)
{
    xyz_t	display_position;
    float	w;
    
    projection_pos_set(game_play, &this->eye.position, &display_position, &w);
    *display_x = (short)(((display_position.x * w) * (float)(SCREEN_WD/2)) + (float)(SCREEN_WD/2));
    *display_y = (short)(((display_position.y * w) * (float)(-SCREEN_HT/2)) + (float)(SCREEN_HT/2));
}

/*-----------------------------------------------------------------------
 *
 *	持ち上げられチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_carry_check(
    Actor     *this,
    Game_play *game_play
)
{
    game_play;
    
    if ( this->mother != NULL ) return TRUE;	/* 持ち上げられた？ */
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	アイテム指定持ち上げられ意思セット
 *
 *----------------------------------------------------------------------*/
extern int Actor_carry_request_set2(
    Actor     *this,
    Game_play *game_play,
    int	      flag,
    float     size_r,
    float     size_h
)
{
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);

    if ( !bitcheck(player_actor->action, P_ACTION_DONT_CARRY) &&
	 bom_check(player_actor) < 0 &&
	 (((player_actor->l_hand.actor != NULL ||
	    player_actor->talk_actor == this) &&
	   0 < flag &&
	   flag < GET_ITEM_CATCH) ||
	  !bitcheck(player_actor->action, (P_ACTION_DEMO | P_ACTION_CARRY))) &&	/* プレイヤー持てる状態？ */
	 this->player_distance < size_r &&					/* ＸＺ平面距離ＯＫ？ */
	 fabsf(this->player_high) < size_h ) {					/* 高さＯＫ？ */
	
	short	distance_angle_y     = distance_angle(this->player_angle_y, player_actor->actor.shape.angle.sy);
	int	abs_distance_angle_y = ABS(distance_angle_y);

	if ( flag ||
	     abs_distance_angle_y > player_actor->carry.distance_angle_y ) {	/* プレイヤー方向近い？ */

	    /*
	     * プレイヤーへ持ち上げＯＫ連絡
	     */		    
	    player_actor->carry.flag	         = flag;
	    player_actor->carry.actor	         = this;
	    player_actor->carry.distance_angle_y = (unsigned short)abs_distance_angle_y;	/* プレイヤーとの方向セット */
	    
	    return TRUE;
	}
    }
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	アイテム指定持ち上げられ意思セット
 *
 *----------------------------------------------------------------------*/
extern int Actor_carry_request_set(
    Actor     *this,
    Game_play *game_play,
    int	      flag
)
{
    return Actor_carry_request_set2(this, game_play, flag, 50.0f, 10.0f);
}

/*-----------------------------------------------------------------------
 *
 *	持ち上げられ意思セット
 *
 *----------------------------------------------------------------------*/
extern int Actor_carry_request(
    Actor     *this,
    Game_play *game_play
)
{
    return Actor_carry_request_set(this, game_play, 0);
}

/*-----------------------------------------------------------------------
 *
 *	持ち上げられ終了チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_carry_end_check(
    Actor     *this,
    Game_play *game_play
) 
{
    game_play;
    
    if ( this->mother == NULL ) return TRUE;	/* 離された？ */

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	持ち上げられ入れ替え
 *
 *----------------------------------------------------------------------*/
extern void Actor_carry_change(
    Actor     *this,
    Actor     *change_actor,
    Game_play *game_play
)
{
    Actor	*mother = this->mother;
    game_play;
    
    if ( mother->name == ACTOR_NAME_PLAYER ) {	/* 親はプレイヤー？ */

	Player_actor	*player = (Player_actor *)mother;

	player->carry.actor  =
	player->l_hand.actor = change_actor;
    }

    mother->child        = change_actor;
    change_actor->mother = mother;
    this->mother	 = NULL;
}

/*-----------------------------------------------------------------------
 *
 *	ダウジング意思要求
 *
 *----------------------------------------------------------------------*/
extern void Actor_dowsing_request(
    Actor     *this,
    Game_play *game_play
)
{
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);

    if ( this->player_range < player_actor->dowsing_distance ) {	/* ダウジング距離更新？ */
	
//	player_actor->dowsing_actor    = this;
	player_actor->dowsing_distance = this->player_range;
    }
}

/*-----------------------------------------------------------------------
 *
 *	乗られチェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_ride_check(
    Game_play *game_play,
    Actor     *this
)
{
    game_play;
    
    if ( this->child != NULL ) return TRUE;	/* 乗られた？ */
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	乗られ意思セット
 *
 *----------------------------------------------------------------------*/
extern int Actor_ride_request(
    Game_play *game_play,
    Actor     *this,
    int	      direction
)
{
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);
	
    if ( !bitcheck(player_actor->action, P_ACTION_DONT_RIDE) ) {	/* プレイヤー乗れる状態？ */
	
	/*
	 * プレイヤーへ乗れるＯＫ連絡
	 */		    
	player_actor->ride.actor     = this;
	player_actor->ride.direction = (signed char)direction;	/* 方向フラグセット */
	
	return TRUE;
    }
    
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	乗られ終了チェック
 *
 *----------------------------------------------------------------------*/
extern int Actor_ride_end_check(
    Game_play *game_play,
    Actor     *this
)
{
    game_play;
    
    if ( this->child == NULL ) return TRUE;	/* 降りられた？ */

    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤー吹っ飛ばしセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_player_power_damage_set_init(
    Game_play	*game_play,
    Actor	*this,
    float	speedF,
    short	angle_y,
    float	speed_y,
    int		type,
    int		damage
)
{
    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    this;

    player->power_damage  = damage;
    player->power_flag    = type;
    player->power_speedF  = speedF;
    player->power_angle_y = angle_y;
    player->power_speed_y = speed_y;
}
extern void Actor_player_power_damage_AT_set(
    Game_play *game_play,
    Actor     *this,
    float     speedF,
    short     angle_y,
    float     speed_y,
    int	      damage
)
{
    Actor_player_power_damage_set_init(game_play,
				       this,
				       speedF,
				       angle_y,
				       speed_y,
				       POWER_DAMAGE_TYPE_BIG,
				       damage);
}
extern void Actor_player_power_damage_set(
    Game_play *game_play,
    Actor     *this,
    float     speedF,
    short     angle_y,
    float     speed_y
)
{
    Actor_player_power_damage_AT_set(game_play,
				     this,
				     speedF,
				     angle_y,
				     speed_y,
				     0);
}
extern void Actor_player_power_damage_AT_set2(
    Game_play *game_play,
    Actor     *this,
    float     speedF,
    short     angle_y,
    float     speed_y,
    int	      damage
)
{
    Actor_player_power_damage_set_init(game_play,
				       this,
				       speedF,
				       angle_y,
				       speed_y,
				       POWER_DAMAGE_TYPE_JUMP,
				       damage);
}
extern void Actor_player_power_damage_set2(
    Game_play *game_play,
    Actor     *this,
    float     speedF,
    short     angle_y,
    float     speed_y
)
{
    Actor_player_power_damage_AT_set2(game_play,
				      this,
				      speedF,
				      angle_y,
				      speed_y,
				      0);
}
/*----------------------------------------------------------------------------
 *
 *	プレイヤー用ＳＥセット
 *
 *---------------------------------------------------------------------------*/
extern void player_SE_set(
    Actor *this,
    u16   SE_flag
)
{
    Na_StartPlayerSe((f32 *)&this->camera_position, SE_flag);	/* <SE> */
}

/*-----------------------------------------------------------------------
 *
 *	ＳＥセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_SE_set(
    Actor *this,
    u16   SE_flag
)
{
    
#ifdef DEBUG_P
    PRINTF("Actor_SE_set():pos %f %f %f\n",
	   this->camera_position.x,
	   this->camera_position.y,
	   this->camera_position.z);
#endif
	   
    Na_StartObjectSe_F((f32 *)&this->camera_position, SE_flag);	/* <SE> */
}
    
/*-----------------------------------------------------------------------
 *
 *	着地ＳＥセット（床のＢＧチェック要！！）
 *
 *----------------------------------------------------------------------*/
extern void Actor_bound_SE_set(
    Game_play *game_play,
    Actor     *this
)
{
    int		ground_code;
    
    if ( bitcheck(this->environment_info, ENVIRONMENT_INFO_WATER) ) {		/* 水中？ */

	if ( this->water_surface_y < 20.0f ) ground_code = NA_CODE_WATER0;
	else				     ground_code = NA_CODE_WATER1;
    }
    else {
	
	ground_code = T_BGCheck_getSoundGroundLabel(&game_play->BGCheck,
						    this->ground_polygon_info,
						    (int)this->ground_bg_actor_index);
    }

    Na_StartObjectSe_F((f32 *)&this->camera_position, NA_SE_EV_OBJECT_BOUND);		/* <SE> */
    Na_StartObjectSe_F((f32 *)&this->camera_position, (NA_SE_EV_PUT + ground_code));	/* <SE> */
}

/*-----------------------------------------------------------------------
 *
 *	プレイヤータイプレベルＳＥフラグセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_player_level_SE_set(Actor *this, u16 flag)
{
    Actor_set_status(this, ACTOR_STATUS_LEVEL_SE_PLAYER);
    Actor_clear_status(this, (ACTOR_STATUS_LEVEL_SE_SYSTEM | ACTOR_STATUS_LEVEL_SE_FIX | ACTOR_STATUS_LEVEL_SE_TIMER));
    this->level_SE_flag = flag;
}

/*-----------------------------------------------------------------------
 *
 *	システムタイプレベルＳＥフラグセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_system_level_SE_set(Actor *this, u16 flag)
{
    Actor_set_status(this, ACTOR_STATUS_LEVEL_SE_SYSTEM);
    Actor_clear_status(this, (ACTOR_STATUS_LEVEL_SE_PLAYER | ACTOR_STATUS_LEVEL_SE_FIX | ACTOR_STATUS_LEVEL_SE_TIMER));
    this->level_SE_flag = flag;
}

/*-----------------------------------------------------------------------
 *
 *	固定タイプレベルＳＥフラグセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_fix_level_SE_set(Actor *this, u16 flag)
{
    Actor_set_status(this, ACTOR_STATUS_LEVEL_SE_FIX);
    Actor_clear_status(this, (ACTOR_STATUS_LEVEL_SE_PLAYER | ACTOR_STATUS_LEVEL_SE_SYSTEM | ACTOR_STATUS_LEVEL_SE_TIMER));
    this->level_SE_flag = flag;
}

/*-----------------------------------------------------------------------
 *
 *	オブジェクトタイプレベルＳＥフラグセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_level_SE_set(Actor *this, u16 flag)
{
    Actor_clear_status(this, (ACTOR_STATUS_LEVEL_SE_PLAYER | ACTOR_STATUS_LEVEL_SE_SYSTEM | ACTOR_STATUS_LEVEL_SE_FIX | ACTOR_STATUS_LEVEL_SE_TIMER));
    this->level_SE_flag = flag;
}

/*-----------------------------------------------------------------------
 *
 *	タイマーレベルＳＥフラグセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_timer_level_SE_set(Actor *this, int timer)
{
    Actor_set_status(this, ACTOR_STATUS_LEVEL_SE_TIMER);
    Actor_clear_status(this, (ACTOR_STATUS_LEVEL_SE_PLAYER | ACTOR_STATUS_LEVEL_SE_SYSTEM | ACTOR_STATUS_LEVEL_SE_FIX));

    if (timer < NA_TIMER_TERM_WARNING)
	this->level_SE_flag = (NA_TIMER_COUNT_HIGH + 1);
    else if (timer < NA_TIMER_TERM_CAUTION)
	this->level_SE_flag = (NA_TIMER_COUNT_MIDDLE + 1);
    else
	this->level_SE_flag = (NA_TIMER_COUNT_LOW + 1);
}

/*-----------------------------------------------------------------------
 *
 *	ジャブジャブ様内臓破りチェック
 *
 *----------------------------------------------------------------------*/
extern int jyabujyabu_kiru_check(
    Game_play *game_play,
    Actor     *this,
    T_Polygon *polygon_info,
    int	      bg_actor_index,
    xyz_t     *hit_pos
)
{
    if ( T_BGCheck_getAttributeCode_ai(&game_play->BGCheck,
				       polygon_info,
				       bg_actor_index) == BG_POLY_ATR_IN_FISH ) {	/* ジャブジャブ？ */
	/*
	 * ブヨブヨセット
	 */
	game_play->room_info.work[0] = 1;

	/*
	 * エフェクトセット
	 */
	CollisionCheck_setBlueBlood((Game *)game_play, NULL, hit_pos);
	
	/*
	 * 巨大魚ダンジョンの壁の剣突きはね返り音ＳＥセット
	 */
	Actor_SE_set((Actor *)this, NA_SE_IT_WALL_HIT_BUYO);	/* <SE> */

	return TRUE;
    }

    return FALSE;
}

/************************************************************************
 *
 *	Ａｃｔｏｒデータクラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	風の魔法ポインターコンストラクト
 *
 *----------------------------------------------------------------------*/
#define	WARP_POINT_SCALE_MAX	40

static Light_data	magic_window_light_data;	/* ライトデータ */
static Light_list	*magic_window_light_list;	/* ライトデータリストポインタ */
static int		pointer_move_wait;		/* ポインター移動待ちタイマー */
static float		pointer_move_counter;		/* ポインター移動カウンター */

static void magic_window_pointer_ct(Game_play *game_play)
{
    if ( Get_WM_WORK(0) ) {	/* 風の魔法ポイント設定中？ */

	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].work, WARP_POINT_SCALE_MAX);
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos.x, (float)Get_WM_P_POSX(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos.y, (float)Get_WM_P_POSY(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos.z, (float)Get_WM_P_POSZ(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_angle_y, (short)Get_WM_P_ANGLEY(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_mode, (short)Get_WM_P_MODE(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].scene, (Scene_No)Get_WM_SCENE(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].room_ID, (unsigned char)Get_WM_R_ID(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].sw2, (unsigned long)Get_WM_SW2(0));
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].item2, (unsigned long)Get_WM_ITEM2(0));
    }
    else {

	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].work, 0);
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos.x, 0.0f);
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos.y, 0.0f);
	ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos.z, 0.0f);
    }
    
    /*
     * ライトデータリスト追加
     */
    Light_point_ct(&magic_window_light_data,
		   (short)ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.x),
		   (short)ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.y + 80.0f),
		   (short)ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.z),
		   255, 255, 255,
		   -1);
    magic_window_light_list = Global_light_list_new((Game *)game_play,
						    &game_play->global_light,
						    &magic_window_light_data);

    pointer_move_wait    = 0;
    pointer_move_counter = 0.0f;
}

/*-----------------------------------------------------------------------
 *
 *	風の魔法ポインター表示処理
 *
 *----------------------------------------------------------------------*/
extern Gfx	efc_flash_modelT[];

extern void magic_window_pointer_draw(Game_play *game_play)
{
    int		light_power = -1;
    int		warp_flag;
    
    OPEN_DISP(game_play->g.graph);

    if ( (warp_flag = ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].work)) ) {	/* 風の魔法ポインターセット中？ */
	
	float	display_offset_y = (!ZCommonGet(link_age) ? 80.0f : 60.0f);
	float	ratio 		 = 1.0f;
	int	alpha 		 = 255;
	int	max_over;

	if ( (max_over = warp_flag - WARP_POINT_SCALE_MAX) < 0 ) {	/* ポインター表示，消去初期セット */
	    
	    ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].work, ++warp_flag);
	    
	    ratio = (float)(ABS(warp_flag)) * (1.0f/(float)WARP_POINT_SCALE_MAX);

	    pointer_move_wait    = 60;		/* ポインター移動用待ちタイマーセット */
	    pointer_move_counter = 1.0f;	/* ポインター移動用カウンターリセット */
	}
	else if ( pointer_move_wait ) {

	    pointer_move_wait--;
	}
	else if ( pointer_move_counter > 0.0f ) {
	    
	    static xyz_t	kirakira_vec  = {0.0f, -0.05f, 0.0f};
	    static xyz_t	kirakira_acc  = {0.0f, -0.025f, 0.0f};
	    static rgba_t	kirakira_prim = {255, 255, 255};
	    static rgba_t	kirakira_env  = {100, 200,   0};
	    
	    xyz_t	*now_pos = ZCommonGetP(game_info.restart_data[RESTART_MODE_WARP].player_pos);
	    xyz_t	*new_pos = ZCommonGetP(game_info.restart_data[RESTART_MODE_DOWN].player_pos);
	    float	now_pointer_move_counter = pointer_move_counter;
	    xyz_t	dis;
	    float	dr;
	    
	    xyz_t	kirakira_pos;
	    
	    float	unit, len, dx;
	    float	pointer_move_speed;
	    
	    dr = search_position_distance2(new_pos, now_pos, &dis);
	    if ( dr < 20.0f ) {

		pointer_move_counter = 0.0f;
		xyz_t_move(now_pos, new_pos);
	    }
	    else {
		
		len = dr * (1.0f / pointer_move_counter);
		pointer_move_speed = 20.0f / len;
		if ( pointer_move_speed < 0.05f ) pointer_move_speed = 0.05f;
		chase_f(&pointer_move_counter, 0.0f, pointer_move_speed);
		
		unit = (dr * (pointer_move_counter / now_pointer_move_counter)) / dr;
		now_pos->x = new_pos->x + (dis.x * unit);
		now_pos->y = new_pos->y + (dis.y * unit);
		now_pos->z = new_pos->z + (dis.z * unit);
		
		len *= 0.5f;
		dx   = dr - len; 
		display_offset_y += sqrtf((len * len) - (dx * dx)) * 0.2f;

		PRINTF("-------- DISPLAY Y=%f\n", display_offset_y);
	    }
	    
	    /*
	     * キラキラエフェクトセット
	     */
	    kirakira_pos.x = now_pos->x + rnd_fx(6.0F);
	    kirakira_pos.y = now_pos->y + 80.0f + (6.0F * rnd());
	    kirakira_pos.z = now_pos->z + rnd_fx(6.0F);
	    Effect_SS_KiraKira_sc_ct_ct((Game *)game_play,
					&kirakira_pos,
					&kirakira_vec,
					&kirakira_acc,
					&kirakira_prim,
					&kirakira_env,
					1000,
					16);

	    if ( pointer_move_counter == 0.0f ) {	/* 終了？ */
		
		ZCommonSet(game_info.restart_data[RESTART_MODE_WARP], ZCommonGet(game_info.restart_data[RESTART_MODE_DOWN]));
		ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_mode, PLAYER_START_MODE_FROM_MAGIC_WARP);
		ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].work, WARP_POINT_SCALE_MAX);
	    }
	    ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos, *now_pos);
	}
	else if ( max_over > 0 ) {
	    
	    xyz_t	*now_pos  = ZCommonGetP(game_info.restart_data[RESTART_MODE_WARP].player_pos);
	    float	new_ratio = 1.0f - ((float)max_over * 0.1f);
	    float	now_ratio = 1.0f - ((float)(max_over - 1) * 0.1f);
	    xyz_t	eye, dis;
	    float	dr;
	    
	    if ( new_ratio > 0.0f ) {
		
		eye.x = game_play->view.eye.x;
		eye.y = game_play->view.eye.y - display_offset_y;
		eye.z = game_play->view.eye.z;
		dr = search_position_distance2(&eye, now_pos, &dis);
		dr = (dr * (new_ratio / now_ratio)) / dr;
	    
		now_pos->x = eye.x + (dis.x * dr);
		now_pos->y = eye.y + (dis.y * dr);
		now_pos->z = eye.z + (dis.z * dr);
		ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].player_pos, *now_pos);
	    }

	    if ( (alpha = 255 - (max_over * 30)) < 0 ) {	/* 消えた？ */
		
		Set_WM_WORK(OFF);
		ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].work, 0);
		
		alpha = 0;
	    }
	    else {
		
		ZCommonSet(game_info.restart_data[RESTART_MODE_WARP].work, ++warp_flag);
	    }
	    ratio = 1.0f + ((float)max_over * 0.2);
	}

	light_power = (int)(500.0f * ratio);
	
	if ( !game_play->demo_play.mode &&
	     ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].scene) == ZCommonGet(scene_no) &&
	     ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].room_ID) == game_play->room_info.now.ID ) {
	    
	    float	scale = 0.025f * ratio;
	    
	    /*
	     * レンダリングモード設定
	     */
	    SET_NOW_POLY_XLU_DISP(rcp_mode_set(NOW_POLY_XLU_DISP, 25));
	    
	    Matrix_translate(ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.x),
			     ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.y) + display_offset_y,
			     ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.z),
			     SET_MTX);
	    Matrix_scale(scale, scale, scale, MULT_MTX);
	    Matrix_mult(&(game_play->softsprite_matrix), MULT_MTX);
	    Matrix_push();
	    
	    gDPPipeSync(NEXT_POLY_XLU_DISP);
	    gDPSetPrimColor(NEXT_POLY_XLU_DISP, 128,128, 255,255,200,alpha);
	    gDPSetEnvColor(NEXT_POLY_XLU_DISP, 100,200,0,255);
	    
	    Matrix_rotateZ((float)((game_play->game_frame_counter * 1500) & 0xffff) * F_PI/32768.0f, MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	    gSPDisplayList(NEXT_POLY_XLU_DISP, efc_flash_modelT);
	    
	    Matrix_pull();
	    Matrix_rotateZ((float)(~((game_play->game_frame_counter * 1200) & 0xffff)) * F_PI/32768.0f, MULT_MTX);
	    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
	    gSPDisplayList(NEXT_POLY_XLU_DISP, efc_flash_modelT);
	}
	
	Light_point_ct(&magic_window_light_data,
		       (short)ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.x),
		       (short)(ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.y) + display_offset_y),
		       (short)ZCommonGet(game_info.restart_data[RESTART_MODE_WARP].player_pos.z),
		       255, 255, 255,
		       light_power);

	CLOSE_DISP(game_play->g.graph);
    }
}

/*-----------------------------------------------------------------------
 *
 *	風の魔法ポインターデストラクト
 *
 *----------------------------------------------------------------------*/
static void magic_window_pointer_dt(Game_play *game_play)
{
    /*
     * ライトデータリスト削除
     */
    Global_light_list_delete((Game *)game_play, &game_play->global_light, magic_window_light_list);
}

/*-----------------------------------------------------------------------
 *
 *	魔法のメガネキャンセル
 *
 *----------------------------------------------------------------------*/
extern void magic_grass_cancel(Game_play *game_play)
{
    if ( game_play->actor_info.magic_grass ) {	/* 魔法のメガネ使用中？ */
	
	game_play->actor_info.magic_grass = 0;
	MAGIC_CANCEL( game_play );
    }
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒデータクラス コンストラクト
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_ct(
    Game       *game,
    Actor_info *this,
    Actor_data *player_data
) 
{
    Game_play		*game_play = (Game_play *)game;
    
    long		*room_infp = &(Room_Inf[game_play->scene_data_ID][0]);
    DLFTBL_ACTOR	*actor_dlftbl;
    int			i;

    /*
     * ゼロクリア（初期化はこれにおまかせ）
     */
    bzero(this, sizeof(Actor_info));
    
    actor_dlftbls_init();
    
    /*
     * 表示行列初期化
     */
    Matrix_copy_MtxF(&game_play->softsprite_matrix, &MtxF_clear);
    Matrix_copy_MtxF(&game_play->projection_matrix, &MtxF_clear);

     /*
     * オーバーレイ用データ初期化
     */
    actor_dlftbl = actor_dlftbls;
    assert(MaxProfile == ACTOR_DLF_MAX);
    for (i=0; i < ACTOR_DLF_MAX; i++) {
	actor_dlftbl->allocp = NULL;
	actor_dlftbl->clients = 0;
	actor_dlftbl++;
    }

    /*
     * Ａｃｔｏｒ環境クラスコンストラクト
     */
    this->environment.Tbox       = room_infp[Inf_Box];
    this->environment.sw1 	 = room_infp[Inf_Switch];
    this->environment.room_clear = room_infp[Inf_Enemy];
    this->environment.item1      = room_infp[Inf_Item0];
//    this->environment.item2      = room_infp[Inf_Item1];

    /*
     * 名前表示コンストラクト
     */
    Actor_Name_Disp_ct((Game_play *)game, &this->name_disp); 

    /*
     * 絶対魔法領域
     */
    this->absolute_magic_field = NULL;

    /*
     * プレイヤー登録
     */
    Actor_info_new(this, player_data, game);

    /*
     * 注目マーカークラス コンストラクト
     */
    Anchor_Marker_init(&this->anchor_marker, this->actor_list[ACTOR_PART_PLAYER].actor, (Game_play *)game);

    /*
     * 風の魔法ポインターコンストラクト
     */
    magic_window_pointer_ct(game_play);

#if 0    
    /*
     * コンパスデータ（デバック用）
     */
    IREG(75) = 100;
    IREG(76) = 100;
    IREG(77) = 255;
    IREG(78) = 255;
    IREG(79) =  70;

    IREG(80) = -25;

    IREG(85) = 255;
    IREG(86) = 255;
    IREG(87) = 255;
    IREG(88) = 255;
    IREG(89) = 40;

    IREG(90) = 0;
    IREG(91) = -40;
#endif
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ呼び出し
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_call_actor(
    Game_play  *game_play,
    Actor_info *this
)
{
    static unsigned long	move_stop_flag[ACTOR_PART_MAX] = {
	(P_ACTION_DOWN | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK),			/* ACTOR_PART_SWITCH */
	(P_ACTION_DOWN | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK),			/* ACTOR_PART_FRIEND */
	0,										/* ACTOR_PART_PLAYER */
	(P_ACTION_DOWN | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK | P_ACTION_GET_ITEM),	/* ACTOR_PART_BOM    */
	(P_ACTION_DOWN),								/* ACTOR_PART_PEOPLE */
	(P_ACTION_DOWN | P_ACTION_DEMO | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK),	/* ACTOR_PART_ENEMY  */
	(P_ACTION_DOWN | P_ACTION_ALL_STOP_DEMO),					/* ACTOR_PART_OBJ    */
	0,										/* ACTOR_PART_EFFECT */
	(P_ACTION_DOWN | P_ACTION_DEMO | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK),	/* ACTOR_PART_ITEM   */
	(P_ACTION_DOWN | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK | P_ACTION_GET_ITEM),	/* ACTOR_PART_BOSS  */
	0,										/* ACTOR_PART_DOOR   */
	(P_ACTION_DOWN | P_ACTION_ALL_STOP_DEMO | P_ACTION_TALK),			/* ACTOR_PART_TREASURE */
    };
    
    Actor		*actor;
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);

    int 		okarina_no_stop_flag = 0;
    unsigned long	*move_stop_flagp;
    int			move_part_stop_flag, i;
    Actor		*talk_actor = NULL;
    
    /*
     * Ａｃｔｏｒセットチェック
     */
    if ( game_play->actor_set_num ) {	/* Ａｃｔｏｒセット？ */
	
	Actor_data	*actor_data = game_play->actor_data;
	
	for (i=0; i<game_play->actor_set_num; i++) Actor_info_new(&game_play->actor_info, actor_data++, (Game *)game_play);
	
	game_play->actor_set_num = 0;	/* Ａｃｔｏｒセット終了 */
    }
    
    /*
     * ダメージ地震タイマー計算
     */
    if ( this->quake_damage ) this->quake_damage--;
	
    /* 
     * Ａｃｔｏｒ呼び出し
     */

#ifndef DEBUG_MODE_NOINPUT    
    if(KAZ(0) == -100) { /* はずれ宝箱テスト */
	Player_actor    *pla = (Player_actor *)get_player_actor(game_play);
	
	KAZ(0) = 0;
	/* 秘密セット */
	Actor_info_make_actor(&game_play->actor_info,
			      (Game *)game_play,
			      En_Clear_Tag,
			      pla->actor.world.position.x,
			      pla->actor.world.position.y + 100.0f,
			      pla->actor.world.position.z,
			      0,
			      0,
			      0,
			      1);
    }
#endif    

#ifdef DEBUG_P
    PRINTF("ACTOR START !!\n");
    DEBUG_PRINT_PROC();
#endif

    /*
     * デモストップチェック
     */
    move_stop_flagp = move_stop_flag;
    if ( bitcheck(player_actor->action2, P_ACTION2_OKARINA_MODE) ) okarina_no_stop_flag = ACTOR_STATUS_OKARINA_NO_STOP;
    if ( bitcheck(player_actor->action, P_ACTION_TALK) &&
	 ((player_actor->actor.talk_message & 0xff00) != 0x0600) ) talk_actor = player_actor->talk_actor;
    
    for (i=0; i<ACTOR_PART_MAX; i++, move_stop_flagp++) {	/* 役柄順 */

	move_part_stop_flag = bitcheck(player_actor->action, *move_stop_flagp);		/* デモチェックフラグセット */
	
	actor = this->actor_list[i].actor;
	while ( actor != NULL ) {

	    if ( actor->world.position.y < -25000.0f ) actor->world.position.y = -25000.0f;
	    
	    actor->level_SE_flag = 0;	/* レベルＳＥフラグリセット */

#ifdef DEBUG_P
	    PRINTF("ACTOR NAME=%d STATUS=%x MOVE_PROC=%x arg_data=0x%x\n",
		   actor->name, actor->status, actor->move_proc,
		   actor->arg_data);
	    DEBUG_PRINT_PROC();
#endif
		
	    if ( actor->constract_proc != NULL ) {	/* データ転送待ち？ */
		
		if ( Object_Exchange_bank_dma_check(&game_play->object_exchange,
						    (int)actor->bank_ID) ) {	/* データ転送終了？ */
		    
		    /*
		     * データセグメント設定
		     */
		    Actor_set_segment(game_play, actor);
		    
		    actor->constract_proc(actor, (Game *)game_play);	/* Ａｃｔｏｒ別コンストラクト */
		    actor->constract_proc = NULL;				/* コンストラクト呼び出し終了設定 */
		}

		actor = actor->next;
	    }
	    else if ( !Object_Exchange_bank_dma_check(&game_play->object_exchange,
						      (int)actor->bank_ID) ) {	/* データ無し？ */
		
		/*
		 * Ａｃｔｏｒ消去
		 */
		Actor_delete(actor);

		actor = actor->next;
	    }
#if 1	    
	    else if ( (okarina_no_stop_flag &&					/* オカリナ演奏中でない？ */
		       !Actor_bitcheck_status(actor, okarina_no_stop_flag)) ||	/* オカリナストップ？ */
		      (!okarina_no_stop_flag &&
		       move_part_stop_flag &&					/* 停止？ */
		       talk_actor != actor &&					/* 会話相手でない？ */
		       player_actor->elf_actor != actor &&			/* ナヴィでない？ */
		       player_actor->l_hand.actor != actor &&			/* 持ってる物でない？ */
		       actor->mother != (Actor *)player_actor) ) { 		/* プレイヤーと関係中でない？ */
#else
	    else if ( (move_part_stop_flag &&					/* 停止？ */
		       talk_actor != actor &&					/* 会話相手でない？ */
		       player_actor->elf_actor != actor &&			/* ナヴィでない？ */
		       player_actor->l_hand.actor != actor &&			/* 持ってる物でない？ */
		       actor->mother != (Actor *)player_actor) &&		/* プレイヤーと関係中でない？ */
		      !Actor_bitcheck_status(actor, okarina_no_stop_flag) ) {	/* オカリナ演奏中停止？ */
#endif
		
		/*
		 * ステータス情報クリア
		 */
		CollisionCheck_Status_Clear(&actor->status_info);
		
		actor = actor->next;
	    }
 	    else {
		
		if ( actor->move_proc == NULL ) {	/* Ａｃｔｏｒクラス削除？ */
		    
		    if ( !Actor_isDraw(actor) ) {
			
			actor = Actor_info_delete(&game_play->actor_info, actor, (Game *)game_play);
		    }
		    else {
			
			Actor_dt(actor, (Game *)game_play);
			actor = actor->next; 			/* 今回は見逃しといたる */
		    }
		}
		else {
		    
		    /*
		     * 前フレーム座標セット
		     */
		    xyz_t_move(&actor->old_position, &actor->world.position);
		    
		    /*
		     * プレイヤーとの距離，方向セット
		     */
		    actor->player_distance = Actor_search_actor_distanceXZ(actor, (Actor *)player_actor);
		    actor->player_high     = Actor_search_actor_high(actor, (Actor *)player_actor);
		    actor->player_range    =
			(actor->player_distance * actor->player_distance) + (actor->player_high * actor->player_high);
		    actor->player_angle_y  = Actor_search_actor_angleY(actor, (Actor *)player_actor);

		    /*
		     * ステータス情報クリアー
		     */
		    Actor_clear_status(actor, (ACTOR_STATUS_BODY_HIT));
		    
		    if ( !timer_check_dec(&(actor->stop_timer)) &&			/* 停止でない？ */
			 Actor_bitcheck_status(actor, (ACTOR_STATUS_NO_CULL_MOVE |
						       ACTOR_STATUS_NO_CULL_FLAG)) ) {	/* カリング？ */
			
			/*
			 * 注目フラグセット
			 */
			if ( actor == player_actor->camera_parameter.primary_actor ) actor->anchor_flag = ON;
			else						 	     actor->anchor_flag = OFF;
			
			/*
			 * 注目待ちタイマー計算
			 */
			if ( actor->anchor_wait ) {

			    if ( player_actor->camera_parameter.primary_actor == NULL ) actor->anchor_wait = 0;
//			    else							actor->anchor_wait--;
			}
			
			/*
			 * データセグメント設定
			 */
			Actor_set_segment(game_play, actor);

			/*
			 * フォグタイマーカウントダウン
			 */
			if(actor->fog_timer)
			    --actor->fog_timer;
			
			/*
			 * 処理呼び出し
			 */

#ifdef DEBUG_P
			PRINTF("move動作前:actor_p:%x proc:%x\n",
			       actor, actor->move_proc);
			DEBUG_PRINT_PROC();
#endif

			actor->move_proc(actor, (Game *)game_play);

#ifdef DEBUG_P
			PRINTF("move動作完了\n");
			DEBUG_PRINT_PROC();
#endif
			
			/*
			 * moveBG:status情報クリア
			 * 4/21追加
			 */
			DynaPolyInfo_statusClear(
			    (Game *)game_play,
				&((game_play)->BGCheck.dyna_poly_info),
				actor);

#if 0
			/*
			 * ダメージ情報クリア
			 */
			CollisionCheck_Damage_Clear(&actor->damage);
#endif
		    }

		    /*
		     * ステータス情報クリア
		     */
		    CollisionCheck_Status_Clear(&actor->status_info);
		    
		    actor = actor->next;
		}
	    }
	    }

#ifdef DYNA_POLY_TEST
	/*
	 * ダイナミックポリゴンセットアップ
	 * ACTOR_PART_FRIEND の時の最後に行う
	 */
	if (i ==  ACTOR_PART_FRIEND) {
	    DynaPolyInfo_setup(
		(Game *)game_play, 
		&((game_play)->BGCheck.dyna_poly_info));
	}
#endif	
	}
    
#ifdef DEBUG_P
	PRINTF("ACTOR END !!\n");
	DEBUG_PRINT_PROC();
#endif

    /*
     * 注目マーカー処理
     */
    if ( (actor = player_actor->camera_parameter.primary_actor) != NULL &&
	 actor->move_proc == NULL ) {						/* 注目対象消去モード？ */
	
	actor = NULL;
	anchor_cancel(player_actor);
    }
    if ( actor == NULL ||
	 player_actor->camera_parameter.anchor_change_wait < ANCHOR_CHANGE_WAIT_TIME ) {	/* 注目解除？ */
	
	if ( this->anchor_marker.rock_on ) {	/* ロックオフへ？ */
	    
	    this->anchor_marker.rock_on = 0;
	    
	    /*
	     * ロックオフＳＥセット
	     */
	    Na_StartSystemSe_F(NA_SE_SY_LOCK_OFF);	/* <SE> */
	}
	actor = NULL;
    }
    Anchor_Marker_process(&this->anchor_marker,
			  (Actor *)player_actor,
			  actor,
			  game_play);

    /*
     * 名前表示処理
     */
    Actor_Name_Disp_Move(game_play, &this->name_disp);

    /*
     * ダイナミックポリゴン情報クリア
     */
    DynaPolyInfo_cleanUp(
	(Game *)game_play, 
	&((game_play)->BGCheck.dyna_poly_info));
}

#if 0
/*-----------------------------------------------------------------------
 *
 *	コンパス表示
 *
 *----------------------------------------------------------------------*/
#define G_CC_PRIM_LIGHT 	PRIMITIVE, 0, SHADE, 0, PRIMITIVE, 0, SHADE, 0

extern Gfx compas_model[];
extern Gfx compass_modelT[];
extern Gfx tetra_model[];

static void compas_draw(
    Game_play 	  *game_play,
    xyz_t	  *center,
    float	  scale,
    float     	  offset_r,
    float     	  offset_h,
    short     	  rx,
    short     	  ry,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a,
    Gfx		  *shape
)
{
    OPEN_DISP(game_play->g.graph);
    
    gDPSetPrimColor(NEXT_DISP, 0, 1,
		    r,
		    g,
		    b,
		    a);
    Matrix_translate(center->x,
		     center->y + offset_h,
		     center->z,
		     SET_MTX);
    Matrix_rotateY(((float)ry * ((2.0f * F_PI)/65536.0f)), MULT_MTX);
    Matrix_rotateX(((float)rx * ((2.0f * F_PI)/65536.0f)), MULT_MTX);
    Matrix_translate(0.0f,
		     0.0f,
		     offset_r,
		     MULT_MTX);
    Matrix_scale(scale, scale, scale, MULT_MTX);
    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(NEXT_DISP, shape);
    
    CLOSE_DISP(game_play->g.graph);
}
#endif

#define TRAP_ACTOR		/* defineすると型変換エラー時に情報表示 */

#ifdef TRAP_ACTOR
#include <fault.h>		/* fault_client_t */
#include <faultprint.h>		/* faultprint */
#endif

#ifdef TRAP_ACTOR
static void
display_actor(Actor *actor, void *comment)
{
    DLFTBL_ACTOR	*actor_dlftbl;
    char *actor_name;

    if (actor == NULL || actor->dlftbl == NULL) {
	faultprint_Locate(6*8, 3*8);
	faultprint_Printf("ACTOR NAME is NULL");
    }
    
    actor_dlftbl = (DLFTBL_ACTOR *)actor->dlftbl;
    actor_name = actor_dlftbl_GetSegName(actor_dlftbl);
    
    PRINTF("アクターの名前(%08x:%s)\n", actor, actor_name);
    
    if (comment != NULL) {
	PRINTF("コメント:%s\n", comment);
    }
    
    faultprint_Locate(6*8, 3*8);
    faultprint_Printf("ACTOR NAME %08x:%s", actor, actor_name);
    
}
#endif

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ個別表示
 *
 *----------------------------------------------------------------------*/
static void Actor_draw(
    Game_play  *game_play,
    Actor      *this
)
{
#ifdef TRAP_ACTOR
    fault_client_t fault_client;
#endif
    LightsN	*lightsN;
    
#ifdef TRAP_ACTOR
    fault_AddClient(&fault_client,
		    (void (*)(void *, void *))display_actor,
		    this,
		    "Actor_draw");
#endif
    OPEN_DISP(game_play->g.graph);

    /*
     * ライト設定
     */
    lightsN = Global_light_read(&game_play->global_light, game_play->g.graph);
    LightsN_list_check(lightsN,
		       game_play->global_light.list,
		       (Actor_bitcheck_status(this, ACTOR_STATUS_MAP_LIGHT_MODE) ? NULL : &this->world.position));
    LightsN_disp(lightsN, game_play->g.graph);

    
    /*
     * オブジェクト表示
     */
    if ( Actor_bitcheck_status(this, ACTOR_STATUS_NO_QUAKE) ) {		/* 地震影響無し？ */
	
	Matrix_softcv3_load(this->world.position.x + game_play->camera.gap.x,
			    this->world.position.y + (this->shape.offset_y * this->scale.y + game_play->camera.gap.y),
			    this->world.position.z + game_play->camera.gap.z,
			    &this->shape.angle);
    }
    else {

	Matrix_softcv3_load(this->world.position.x,
			    this->world.position.y + (this->shape.offset_y * this->scale.y),
			    this->world.position.z,
			    &this->shape.angle);
    }
	
    Matrix_scale(this->scale.x, this->scale.y, this->scale.z, MULT_MTX);
    
    /*
     * データセグメント設定
     */
    Actor_set_segment(game_play, this);
    
    /*
     * データセグメント設定
     */
    {
        Object_Exchange_Status *s = game_play->object_exchange.status;
        gSPSegment(NEXT_DISP,
                   GAMEPLAY_OBJECT_EXCHANGE_SEGMENT, s[this->bank_ID].Segment);
        gSPSegment(NEXT_POLY_XLU_DISP,
                   GAMEPLAY_OBJECT_EXCHANGE_SEGMENT, s[this->bank_ID].Segment);
    }

    if(this->fog_timer){ /* フォグ かける？ */
	rgba_t 	fog_color = {0,0,0,255};
	if(this->fog_data & FOG_TYPE_H){
	    /* 白フォグ */
	    fog_color.r =
	    fog_color.g =
	    fog_color.b = ((this->fog_data & 0x1f00) >> 5) | 7;
	}else if(this->fog_data & FOG_TYPE_R){
	    /* 赤フォグ */
	    fog_color.r = ((this->fog_data & 0x1f00) >> 5) | 7;
	}else{
	    /* 青フォグ */
	    fog_color.b = ((this->fog_data & 0x1f00) >> 5) | 7;
	}
	if(this->fog_data & FOG_POLY_X){
	    Eff_Set_Fog3_xlu((Game *)game_play, &fog_color,
			     (short)this->fog_timer,(this->fog_data & 0x00ff));
	}else{
	    Eff_Set_Fog3((Game *)game_play, &fog_color,
			 (short)this->fog_timer,(this->fog_data & 0x00ff));
	}
    }
    
    this->draw_proc(this, (Game *)game_play);
    
    if(this->fog_timer){
	if(this->fog_data & FOG_POLY_X){
	    Eff_Off_Fog_xlu((Game *)game_play);
	}else{
	    Eff_Off_Fog((Game *)game_play);
	}
//	if(!this->stop_timer)
//	    --this->fog_timer;
    }
    
    /*
     * 影表示
     */
    if ( this->shape.shadow_proc != NULL ) this->shape.shadow_proc(this, lightsN, game_play);

    CLOSE_DISP(game_play->g.graph);

#ifdef TRAP_ACTOR
    fault_RemoveClient(&fault_client);
#endif
}

/*-----------------------------------------------------------------------
 *
 *	レベルＳＥセット
 *
 *----------------------------------------------------------------------*/
static void level_SE_set(Actor *this)
{
    if ( Actor_bitcheck_status(this, ACTOR_STATUS_LEVEL_SE_PLAYER) )		/* プレイヤータイプ？ */
	Na_StartPlayerSe((f32 *)&this->camera_position, this->level_SE_flag);	/* <SE> */
    else if ( Actor_bitcheck_status(this, ACTOR_STATUS_LEVEL_SE_SYSTEM) )	/* システム？ */
	Na_StartSystemSe_F(this->level_SE_flag);	/* <SE> */
    else if ( Actor_bitcheck_status(this, ACTOR_STATUS_LEVEL_SE_FIX) )		/* 固定？ */
	Na_StartFixSe_F(this->level_SE_flag);	/* <SE> */
    else if ( Actor_bitcheck_status(this, ACTOR_STATUS_LEVEL_SE_TIMER) )	/* タイマー？ */
	Na_SetTimerSe((s8)(this->level_SE_flag - 1));
    else
	Na_StartObjectSe_F((f32 *)&this->camera_position, this->level_SE_flag);	/* <SE> */
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ表示(actor.h not access "Game_play" !!)
 *
 *----------------------------------------------------------------------*/
#define	G_CC_MAGIC_GLASS_IN	TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
#define	G_CC_MAGIC_GLASS_OUT	PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, 0, PRIMITIVE, TEXEL0, PRIM_LOD_FRAC, 0
#define	INVISIBLE_ACTOR_MAX	20
/*
 * 魔法の眼鏡のテクスチャのロードと表示
 */
static void
Actor_info_draw_actor_glass_txt_draw(Graph *graph)
{
    extern unsigned char	g_grass_txt[];
    
    OPEN_DISP(graph);
    
    gDPLoadTextureBlock(NEXT_POLY_XLU_DISP, g_grass_txt,
			G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0,
			G_TX_CLAMP | G_TX_MIRROR, G_TX_CLAMP | G_TX_MIRROR,
			6, 6, G_TX_NOLOD, G_TX_NOLOD);
    /* フレームバッファ(320x240)の中央に再配置 */
    gDPSetTileSize(NEXT_POLY_XLU_DISP, G_TX_RENDERTILE,
		   (320 / 2 - 128 / 2    ) << 2,
		   (240 / 2 - 128 / 2    ) << 2,
		   (320 / 2 + 128 / 2 - 1) << 2,
		   (240 / 2 + 128 / 2 - 1) << 2);
//    gSPTextureRectangle(NEXT_POLY_XLU_DISP, 0<<2, 0<<2, 320<<2, 240<<2,
//			G_TX_RENDERTILE, (0<<5), (0<<5), 1<<10, 1<<10);
    gSPTextureRectangle(NEXT_POLY_XLU_DISP, 0<<2, 0<<2, 320<<2, 240<<2,
			G_TX_RENDERTILE,
			(70<<5),
			(50<<5),
			(int)(((float)(320-(70*2))/320.0f)*1024.0f),
			(int)(((float)(240-(50*2))/240.0f)*1024.0f));
gDPPipeSync(NEXT_POLY_XLU_DISP);
    
    CLOSE_DISP(graph);
}

static void
Actor_info_draw_actor_glass_draw(
    Game_play *game_play,
    int invisible_actor_counter,
    Actor *invisible_actor[INVISIBLE_ACTOR_MAX]
    )
{
    Graph *graph = game_play->g.graph;
    Actor		**actorP;
    int i;

    OPEN_DISP(graph);
    
#ifdef ROM_D
    count_gDPNoOpString(NEXT_POLY_OPA_DISP, "魔法のメガネ START", 0);
#endif

    /*
     * メガネ表示
     */
    gDPPipeSync(NEXT_POLY_XLU_DISP);
    if ( !game_play->room_info.now.glass_mode ) {	/* 内側？ */
	/*
	 * 赤い眼鏡
	 * 丸の内側のＺ値は保存する。色は保存する。つまり何も書かない。
	 * 丸の外側は赤の半透明で描画する。Ｚ値を０にする。
	 */

	gDPSetOtherModeHL(NEXT_POLY_XLU_DISP,
			  G_CYC_1CYCLE|G_TF_BILERP|G_TC_FILT|G_CD_MAGICSQ|G_AD_DISABLE,
			  G_AC_THRESHOLD|G_ZS_PRIM|G_RM_ZO_CLD_SURF|G_RM_ZO_CLD_SURF2);
	gDPSetCombineMode(NEXT_POLY_XLU_DISP, G_CC_MAGIC_GLASS_IN, G_CC_MAGIC_GLASS_IN);
	gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0, 255, 0, 0, 255); /* 赤 */
    } else {						/* 外側 */
	/*
	 * 青い眼鏡（赤に変更）
	 * 丸の内側のＺ値を０にする。色は保存する。
	 * 丸の外側のＺ値は保存する。色は保存する。つまり何も書かない。
	 * (見えないアクター表示後に丸の外側を青の半透明で描画する)
	 */

	gDPSetOtherModeHL(NEXT_POLY_XLU_DISP,
			  G_CYC_1CYCLE|G_TF_BILERP|G_TC_FILT|G_CD_MAGICSQ|G_AD_DISABLE,
			  G_AC_THRESHOLD|G_ZS_PRIM|G_RM_ZO_CLR_SURF|G_RM_ZO_CLR_SURF2);
	gDPSetCombineMode(NEXT_POLY_XLU_DISP, G_CC_MAGIC_GLASS_OUT, G_CC_MAGIC_GLASS_OUT);
	gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 255, 74, 74, 74, 74); /* テクスチャの I の最大値 */
    }
    gDPSetPrimDepth(NEXT_POLY_XLU_DISP, 0, 0);
    /* メガネテクスチャ表示 */
    Actor_info_draw_actor_glass_txt_draw(graph);

    /*
     * 見えないＡcｔｏｒ表示
     * 魔法の眼鏡の効果でＺ値が０になっている部分には描画されない
     */
#ifdef ROM_D
    count_gDPNoOpString(NEXT_POLY_OPA_DISP,
			"魔法のメガネ 見えないＡcｔｏｒ表示 START",
			invisible_actor_counter);
#endif
    actorP = invisible_actor;
    for (i = 0; i < invisible_actor_counter; i++) {
#ifdef ROM_D
	count_gDPNoOpString(NEXT_POLY_OPA_DISP, "魔法のメガネ 見えないＡcｔｏｒ表示", i);
#endif
	Actor_draw(game_play, *actorP++);
    }
#ifdef ROM_D
    count_gDPNoOpString(NEXT_POLY_OPA_DISP,
			"魔法のメガネ 見えないＡcｔｏｒ表示 END",
			invisible_actor_counter);
#endif

    
    if ( game_play->room_info.now.glass_mode ) {	/* 外側？ */
#ifdef ROM_D
	count_gDPNoOpString(NEXT_POLY_OPA_DISP, "青い眼鏡(外側)", 0);
#endif
	/*
	 * 青い眼鏡
	 * 丸の外側は青の半透明で描画する。Ｚ値は保存する。ただの半透明。
	 */
	gDPPipeSync(NEXT_POLY_XLU_DISP);
	gDPSetOtherModeHL(NEXT_POLY_XLU_DISP,
			  G_CYC_1CYCLE|G_TF_BILERP|G_TC_FILT|G_CD_MAGICSQ|G_AD_DISABLE,
			  G_AC_THRESHOLD|G_ZS_PRIM|G_RM_CLD_SURF|G_RM_CLD_SURF2);
	gDPSetCombineMode(NEXT_POLY_XLU_DISP, G_CC_MAGIC_GLASS_IN, G_CC_MAGIC_GLASS_IN);
	gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0, 0, 255, 0, 0, 255);
	Actor_info_draw_actor_glass_txt_draw(graph);
#ifdef ROM_D
	count_gDPNoOpString(NEXT_POLY_OPA_DISP, "青い眼鏡(外側)", 1);
#endif
    }

#ifdef ROM_D
    count_gDPNoOpString(NEXT_POLY_OPA_DISP, "魔法のメガネ END", 0);
#endif

    CLOSE_DISP(graph);
}


/* 表示カリングチェック */
extern int Actor_draw_actor_no_culling_check(
    Game_play *game_play,
    Actor *actor)
{
    return Actor_draw_actor_no_culling_check2(
	game_play, actor, &(actor->camera_position), actor->camera_w);
}

/* 表示カリングチェック:引数分離版 */
extern int Actor_draw_actor_no_culling_check2(
    Game_play *game_play,
    Actor *actor,
    xyz_t *camera_position,
    float camera_w)
{
    float tmp_w;
    
    if ( -actor->cull_r < camera_position->z &&
	 camera_position->z < (actor->cull_z + actor->cull_r) &&
	 ((tmp_w = (camera_w < 1.0f ? 1.0f : (1.0f / camera_w))),
	  ((fabsf(camera_position->x) - actor->cull_r) * tmp_w) < 1.0f &&
	  ((camera_position->y + actor->cull_y) * tmp_w) > -1.0f &&
	  ((camera_position->y - actor->cull_r) * tmp_w) < 1.0f)) {
	return TRUE;
    }
    return FALSE;
    
}

extern void Actor_info_draw_actor(
    Game_play  *game_play,
    Actor_info *this
)
{
    int			invisible_actor_counter = 0;
    Actor		*invisible_actor[INVISIBLE_ACTOR_MAX];

    Actor_list		*actor_listP;
    Actor		*actor;
#if 0
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);
    float		sx, sy, sz, sr;
#endif
    int			i;

    OPEN_DISP(game_play->g.graph);

#if 0    
    /*
     * コンパス表示
     */
    if ( game_play->room_info.now.type != ROOM_TYPE_FIELD &&	/* 固定コンパス（Ｎ）表示？ */
	 bitcheck(player_actor->actor.environment_info, ENVIRONMENT_INFO_GROUND) &&
	 !bitcheck(player_actor->action, P_ACTION_DONT_COMPAS) ) {	/* コンパス表示ＯＫ？ */
	
	polygon_prim(game_play->g.graph);
	gDPSetCombineMode(NEXT_DISP, G_CC_SHADE_PRIM, G_CC_SHADE_PRIM);
	gDPSetRenderMode(NEXT_DISP, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
	
	sx = player_actor->actor.home.position.x - player_actor->actor.world.position.x;
	sy = player_actor->actor.home.position.y - player_actor->actor.world.position.y;
	sz = player_actor->actor.home.position.z - player_actor->actor.world.position.z;
	sr = sqrtf((sx * sx) + (sz * sz));

	compas_draw(game_play,					/* 注目コンパス */
		    &player_actor->actor.world.position,
		    (float)IREG(89)/100.0f,
		    (float)IREG(91),
		    0.0f,
		    atans_table(sr, -sy), atans_table(sz, sx),
		    (unsigned char)IREG(85),
		    (unsigned char)IREG(86),
		    (unsigned char)IREG(87),
		    (unsigned char)IREG(88),
		    tetra_model);

#if 0	
	if ( game_play->room_info.now.type == ROOM_TYPE_FIELD ) {	/* 固定コンパス（Ｎ）表示？ */

	    compas_draw(game_play,					/* 固定コンパス（Ｎ） */
			&player_actor->actor.world.position,
			(float)IREG(79)/100.0f,
			(float)IREG(80),
			0.0f,
			0, 0,
			(unsigned char)IREG(75),
			(unsigned char)IREG(76),
			(unsigned char)IREG(77),
			(unsigned char)IREG(78),
			compass_modelT);
	}
#endif
    }
#endif
    
#ifdef DEBUG_P
    PRINTF("ACTOR DRAW START !!\n");
    DEBUG_PRINT_PROC();
#endif

    /*
     * Ａcｔｏｒ表示
     */
    actor_listP = this->actor_list;
    for (i=0; i<ACTOR_PART_MAX; i++, actor_listP++) { /* 役柄順 */
	
	actor = actor_listP->actor;

	while ( actor != NULL ) {

#ifdef DEBUG_P
	    PRINTF("ACTOR DRAW NAME=%d arg_data=0x%x start\n",
		   actor->name, actor->arg_data);
	    DEBUG_PRINT_PROC();
#endif
	    
#ifdef ROM_D
	    {
		DLFTBL_ACTOR	*actor_dlftbl;
		char *actor_name;
		
		actor_dlftbl = (DLFTBL_ACTOR *)actor->dlftbl;
		actor_name = actor_dlftbl_GetSegName(actor_dlftbl);
		count_gDPNoOpString(NEXT_POLY_OPA_DISP, actor_name, i);
		count_gDPNoOpString(NEXT_POLY_XLU_DISP, actor_name, i);
	    }
#endif
#define HREG2(n) (HREG(64) == 1 && (HREG(65) == -1 || HREG(65) == HREG(66)) && HREG(67+(n)))
	    SETHREG(66, i);
	    if (!HREG2(1)) {
	    /*
	     * カメラポジションセット（前フレーム）
	     */
	    Skin_Matrix_PrjMulVector((Skin_Matrix *)game_play->projection_matrix,
				     (Skin_Vector *)&actor->world.position,
				     (Skin_Vector *)&actor->camera_position,
				     &actor->camera_w);
	    }
			
	    if (!HREG2(2)) {
	    /*
	     * レベルＳＥセットチェック
	     */
	    if ( actor->level_SE_flag ) level_SE_set(actor);
	    }
		
	    if (!HREG2(3)) {
	    /*
	     * カリングチェック
	     */
		if (Actor_draw_actor_no_culling_check(game_play, actor)) {
		    /* カリングしない？ */
		    Actor_set_status(actor, ACTOR_STATUS_NO_CULL_FLAG);
		} else {
		    Actor_clear_status(actor, ACTOR_STATUS_NO_CULL_FLAG);
		}
	    }

	    /*
	     * 表示
	     */
	    Actor_resetDraw(actor);
	    if (!HREG2(4)) {
	    if ( actor->constract_proc == NULL &&	/* データ転送待ち？ */
		 actor->draw_proc != NULL &&		/* 消去中？ */
		 Actor_bitcheck_status(actor,
				       (ACTOR_STATUS_NO_CULL_DRAW | ACTOR_STATUS_NO_CULL_FLAG)) ) { /* カリングしない？ */

		if ( Actor_bitcheck_status(actor, ACTOR_STATUS_INVISIBLE) &&
		     (!game_play->room_info.now.glass_mode ||
		      Actor_player_glass_check(game_play) ||
		      (actor->room_ID != game_play->room_info.now.ID))) {	/* 見えない？ */

		    assert(invisible_actor_counter < INVISIBLE_ACTOR_MAX);	/* 最大値チェック！！ */
		    invisible_actor[invisible_actor_counter] = actor;
		    invisible_actor_counter++;
		}
		else {
		    
		    if (!HREG2(5)) {
			actor_name_show(actor,"Actor_draw",0);
		    Actor_draw(game_play, actor);
		    Actor_setDraw(actor);
		    }
		}

#ifdef DEBUG_P
		PRINTF("ACTOR DRAW NAME=%d end\n", actor->name);
		DEBUG_PRINT_PROC();
#endif
		
	    }
	    }

	    actor = actor->next;
	} /* while */
    } /* for */
    
    /*
     * エフェクト表示
     */
    if (!(HREG(64) == 1 && HREG(73) == 0)) {
    EffectDisp(game_play->g.graph); /* 表示 */
    }
    
    /*
     * エフェクトソフトスプライト表示
     */
    if (!(HREG(64) == 1 && HREG(74) == 0)) {
	EffectSoftSprite_disp(&game_play->g);
    }
    
    /******************************
     * 魔法のメガネ
     */
    if (!(HREG(64) == 1 && HREG(72) == 0)) {
	if ( Actor_player_glass_check(game_play) ) {	/* 使用中？ */

	    Actor_info_draw_actor_glass_draw(game_play, invisible_actor_counter, invisible_actor);

	    if ( game_play->demo_play.mode ||
		 player_demo_check(game_play) ) {
		
		/*
		 * 魔法のメガネキャンセル
		 */
		magic_grass_cancel(game_play);
	    }
	}
    }

    /*
     * 風の魔法ポインター表示
     */
    magic_window_pointer_draw(game_play);
    
    /*
     * ポイントライト表示
     */
    if ( !IREG(32) ) Light_list_point_draw(game_play);
    
    /*
     * 名前表示処理
     */
#ifdef DEBUG_P
    PRINTF("Actor_Name_Disp_Draw();start\n");
#endif
    
    if (!(HREG(64) == 1 && HREG(75) == 0)) {
    Actor_Name_Disp_Draw(game_play, &this->name_disp);
    }
    
#ifdef DEBUG_P
    PRINTF("Actor_Name_Disp_Draw();end\n");
#endif
    
    /*
     * コリジョンデバッグ表示
     */
#ifdef ROM_D
    if (!(HREG(64) == 1 && HREG(76) == 0)) {
	CollisionCheck_DebugDispATACOC((Game *)game_play,
				       &game_play->collision_check);
    }
#endif

 
#ifdef DEBUG_P
    PRINTF("ACTOR DRAW END !!\n");
    DEBUG_PRINT_PROC();
#endif

    CLOSE_DISP(game_play->g.graph);
}

/*-----------------------------------------------------------------------
 *
 *	ＡｃｔｏｒデータバンクＡｃｔｏｒチェック
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_bank_actor_check(
    Game_play  *game_play,
    Actor_info *this
) 
{
    Actor	*actor;
    int		i;

    /*
     * Ａcｔｏｒ消去チェック
     */
    for (i=0; i<ACTOR_PART_MAX; i++) {

	actor = this->actor_list[i].actor;
	while ( actor != NULL ) {

	    if ( !Object_Exchange_bank_dma_check(&game_play->object_exchange,
						 (int)actor->bank_ID) ) {	/* データ無し？ */

		/*
		 * Ａｃｔｏｒ消去
		 */
		Actor_delete(actor);
	    }
	    
	    actor = actor->next;
	}
    }
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ停止タイマーセット
 *
 *----------------------------------------------------------------------*/
#define	STOP_TIMER_SET_PART_MAX	2

extern void Actor_info_stop_timer_set(
    Game_play  *game_play,
    Actor_info *this,
    int	       timer
) 
{
    static unsigned char	stop_timer_set_part[STOP_TIMER_SET_PART_MAX] = {
	ACTOR_PART_ENEMY,
	ACTOR_PART_BOSS,
    };
    
    Actor	*actor;
    int		i;

    game_play;
    
    /*
     * Ａｃｔｏｒ停止タイマーセット
     */
    for (i=0; i<STOP_TIMER_SET_PART_MAX; i++) {
	
	actor = this->actor_list[stop_timer_set_part[i]].actor;
	while ( actor != NULL ) {
	    
	    actor->stop_timer = timer;	/* 停止タイマーセット */
	    
	    actor = actor->next;
	}
    }
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒデータ部屋Ａｃｔｏｒチェック
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_room_actor_check(
    Game_play  *game_play,
    Actor_info *this
) 
{
    Actor		*actor;
    int			i;
    
    /*
     * Ａcｔｏｒ消去チェック
     */
    for (i=0; i<ACTOR_PART_MAX; i++) {

	actor = this->actor_list[i].actor;
	while ( actor != NULL ) {

	    if ( actor->room_ID >= 0 &&
		 actor->room_ID != game_play->room_info.now.ID &&
		 actor->room_ID != game_play->room_info.old.ID ) {/* 消去？ */

#ifdef DEBUG_P
		PRINTF("Actor_info_room_actor_check():\n");
		PRINTF("消去:actor %x, name %d, arg_data 0x%x\n",
		       actor, actor->name, actor->arg_data);
		DEBUG_PRINT_PROC();
#endif

		if (!Actor_isDraw(actor)) {
		    actor = Actor_info_delete(this, actor, (Game *)game_play);
		} else {
		    Actor_delete(actor); /* 死の宣告 */
		    Actor_dt(actor, (Game *)game_play);
		    actor = actor->next; /* 今回は見逃しといたる */
		}
	    } else {
		actor = actor->next;
	    }
	}
    }
    
    /* コリジョンテーブルクリア */
    CollisionCheck_clear((Game *)game_play, &game_play->collision_check);

    /*
     * 敵存在無しビットクリア
     */
    this->environment.no_enemy = 0;

    /*
     * スイッチビットクリア
     */
    this->environment.sw2 &= 0x00ffffff;	/* ５６ー６３ビットクリア */

    /*
     *  ”太陽の歌”フラグＯＦＦ
     */
    game_play->message.sun_song = 0;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒデータクラス デストラクト
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_dt(
    Actor_info *this,
    Game       *game
) 
{
    Actor	*actor;
    int		i;
    
    for (i=0; i<ACTOR_PART_MAX; i++) {		/* 役柄順 */
	
	while( (actor = this->actor_list[i].actor) != NULL ) {
	    
	    Actor_info_delete(this, actor, game);
	}
    }
    
    /*
     * 絶対魔法領域解放
     */
    if (HREG(20))
	PRINTF("絶対魔法領域解放\n");
    if (this->absolute_magic_field != NULL) {
	zelda_free(this->absolute_magic_field);
	this->absolute_magic_field = NULL;
    }

    /*
     * 情報ビットセット
     */
    Game_play_room_inf_set((Game_play *)game);

    /*
     * 風の魔法ポインターデストラクト
     */
    magic_window_pointer_dt((Game_play *)game);
    
    actor_dlftbls_cleanup();
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ役柄別リスト登録
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_part_new(
    Actor_info 	  *this,
    Actor      	  *actor,
    unsigned char part
) 
{
    Actor	*now_actor;

    actor->part = part;		/* 役柄セット */
    
    this->num++;					/* 総合Ａｃｔｏｒセット数加算 */
    this->actor_list[part].num++;			/* 役柄別Ａｃｔｏｒセット数加算 */
    now_actor = this->actor_list[part].actor;		/* 役柄別Ａｃｔｏｒリスト先頭ポインタ */
    if ( now_actor != NULL ) now_actor->pre = actor;	/* 次Ａｃｔｏｒの前Ａｃｔｏｒポインタ設定 */
    this->actor_list[part].actor = actor;		/* 役柄別Ａｃｔｏｒリスト先頭ポインタ更新 */
    actor->next		      	 = now_actor;		/* 次Ａｃｔｏｒポインタ設定 */
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ役柄別リスト削除
 *
 *----------------------------------------------------------------------*/
extern Actor *Actor_info_part_delete(
    Game_play  *game_play,
    Actor_info *this,
    Actor      *actor
)
{
    Actor	*next_actor;
    
    this->num--;					/* 総合Ａｃｔｏｒセット数減算 */
    this->actor_list[actor->part].num--;		/* 役柄別Ａｃｔｏｒセット数減算 */
    if ( actor->pre != NULL ) actor->pre->next = actor->next;
    else		      this->actor_list[actor->part].actor = actor->next;
    if ( (next_actor = actor->next) != NULL ) next_actor->pre = actor->pre;

    actor->pre  = 
    actor->next = NULL;

    if ( actor->room_ID == game_play->room_info.now.ID &&
	 actor->part == ACTOR_PART_ENEMY &&
	 !this->actor_list[ACTOR_PART_ENEMY].num ) {	/* 敵全滅？ */
	
	/*
	 * 部屋全滅ビットチェック
	 */
	Actor_Environment_no_enemy_On(game_play, game_play->room_info.now.ID);
    }
    
    return next_actor;
}

/*
 * アクタークライアントがなくなったらメモリ解放する
 */
static void
actor_free_check(DLFTBL_ACTOR *actor_dlftbl)
{
    COLOR_CYAN();
    if (actor_dlftbl->clients == 0) {
	if (HREG(20))
	    PRINTF("アクタークライアントが０になりました\n");
	if (actor_dlftbl->allocp != NULL) {
	    if (actor_dlftbl->flags & 2) {
		if (HREG(20))
		    PRINTF("オーバーレイ解放しません\n");
	    } else if (actor_dlftbl->flags & 1) {
		if (HREG(20))
		    PRINTF("絶対魔法領域確保なので解放しません\n");
		actor_dlftbl->allocp = NULL;
	    } else {
		if (HREG(20))
		    PRINTF("オーバーレイ解放します\n");
		zelda_free(actor_dlftbl->allocp);
		actor_dlftbl->allocp = NULL;
	    }
	}
    } else {
	if (HREG(20))
	    PRINTF("アクタークライアントはあと %d 残っています\n", actor_dlftbl->clients);
    }
    COLOR_NORMAL();
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒクラス追加
 *
 *----------------------------------------------------------------------*/
extern Actor *Actor_info_make_actor(
    Actor_info     *this,
    Game           *game,
    short	   profile,
    float          x,
    float          y,
    float          z,
    short          sx,
    short          sy,
    short          sz,
    short 	   arg_data
) 
{
    Game_play	*game_play = (Game_play *)game;
    Actor	*actor;	/* クラス宣言 */
    Actor_profile	*profilep;
    int		bank_ID;
    u32		save_segment;
    DLFTBL_ACTOR *actor_dlftbl;
    char *actor_name;
    size_t actor_segsize;

    
#ifdef DEBUG_P
    PRINTF("Actor_info_make_actor():\n");
    PRINTF("引数:%d; %f,%f,%f; %d,%d,%d; %d;\n",
	   profile, x, y, z, sx, sy, sz, arg_data);
#endif
	
    assert(profile < ACTOR_DLF_MAX);
	    
    actor_dlftbl = &actor_dlftbls[profile];
    actor_name = actor_dlftbl_GetSegName(actor_dlftbl);
    actor_segsize = actor_dlftbl->SegmentEnd - actor_dlftbl->SegmentStart;

    if (HREG(20))
	PRINTF("アクタークラス追加 [%d:%s]\n", profile, actor_name);

    /*
     * Ａｃｔｏｒセット数オーバーチェック
     */
    if ( this->num > ACTOR_MAX ) {
	PRINTF(ESC_WARNING "Ａｃｔｏｒセット数オーバー\n" ESC_NORMAL);
	
	return (Actor *)NULL;
    }
 
#if 0
    PRINTF("actor_dlftbl:%08x %08x %08x %08x %08x %08x %s\n",
	   actor_dlftbl->SegmentRomStart,
	   actor_dlftbl->SegmentRomEnd,
	   actor_dlftbl->SegmentStart,
	   actor_dlftbl->SegmentEnd,
	   actor_dlftbl->allocp,
	   actor_dlftbl->profile,
	   actor_name
	);
#endif

    /*
     * アクターオーバーレイ処理
     */
    if (actor_dlftbl->SegmentStart == NULL) {
	/*
	 * 常駐アクター
	 */
	if (HREG(20))
	    PRINTF("オーバーレイではありません\n");
	profilep = actor_dlftbl->profile;
    } else {
	/*
	 * 非常駐アクター
	 */
	if (actor_dlftbl->allocp != NULL) {
	    if (HREG(20))
		PRINTF("既にロードされています\n");
	} else {
	    if (actor_dlftbl->flags & 1) {
		/* 絶対魔法領域 */
		assert(actor_segsize <= AM_FIELD_SIZE);
		if (this->absolute_magic_field == NULL) {
		    this->absolute_magic_field = zelda_malloc_r_DEBUG(
			AM_FIELD_SIZE, "AMF:絶対魔法領域", 0);
		    if (HREG(20))
			PRINTF("絶対魔法領域確保 %d バイト確保\n", AM_FIELD_SIZE);
		}
		actor_dlftbl->allocp = (char *)this->absolute_magic_field;
	    } else if (actor_dlftbl->flags & 2) {
		actor_dlftbl->allocp = (char *)zelda_malloc_r_DEBUG(
		    actor_segsize, actor_name, 0);
	    } else {
		actor_dlftbl->allocp = (char *)zelda_malloc_DEBUG(
		    actor_segsize, actor_name, 0);
	    }

	    if (!actor_dlftbl->allocp) {
		PRINTF(ESC_ERROR
		       "Ａｃｔｏｒプログラムメモリが確保できません\n"
		       ESC_NORMAL);
		
		return (Actor *)NULL;
	    }
	    /* オーバーレイのロード */
	    LoadFragmentFix2(
		actor_dlftbl->SegmentRomStart,
		actor_dlftbl->SegmentRomEnd,
		actor_dlftbl->SegmentStart,
		actor_dlftbl->SegmentEnd,
		actor_dlftbl->allocp);
	    COLOR_GREEN();
	    PRINTF("OVL(a):Seg:%08x-%08x Ram:%08x-%08x Off:%08x %s\n",
		   actor_dlftbl->SegmentStart,
		   actor_dlftbl->SegmentEnd,
		   actor_dlftbl->allocp,
		   (int)actor_dlftbl->allocp +
		   (int)actor_dlftbl->SegmentEnd -
		   (int)actor_dlftbl->SegmentStart,
		   (int)actor_dlftbl->SegmentStart -
		   (int)actor_dlftbl->allocp,
		   actor_name
		);
	    COLOR_NORMAL();
	    actor_dlftbl->clients = 0;
	}
#define newp(this, ptr) ((void *)((ptr) ? (char *)(ptr) - ((char *)this->SegmentStart - (char *)this->allocp) : NULL))
	profilep = (Actor_profile *)newp(actor_dlftbl, actor_dlftbl->profile);
#undef newp
    }
      
    
    /*
     * データバンクチェック
     */
    bank_ID = Object_Exchange_bank_check(
	&game_play->object_exchange, profilep->bank);
    if ( bank_ID < 0 ||
	 (profilep->part == ACTOR_PART_ENEMY &&
	  Actor_Environment_room_clear_Check(
	      game_play, game_play->room_info.now.ID)) ) { /* データバンク無し？ */
	
	PRINTF(ESC_ERROR
	       "データバンク無し！！<データバンク＝%d>(profilep->bank=%d)\n"
	       ESC_NORMAL,
	       bank_ID, profilep->bank);
	
	actor_free_check(actor_dlftbl);
	
	return (Actor *)NULL;
    }
    
    /*
     * アクタークラス確保
     */
    actor = (Actor *)zelda_malloc_DEBUG(profilep->class_size, actor_name, 1);

    if ( actor == NULL ) {
		
	PRINTF(ESC_ERROR
	       "Ａｃｔｏｒクラス確保できません！ %s <サイズ＝%dバイト>\n",
	       ESC_NORMAL,
	       actor_name,
	       profilep->class_size);
		
	actor_free_check(actor_dlftbl);
	return NULL;
    }
    
    assert(actor_dlftbl->clients < 255);
    ++actor_dlftbl->clients;
    if (HREG(20))
	PRINTF("アクタークライアントは %d 個目です\n", actor_dlftbl->clients);
	    
    /*
     * アクタークラス初期化
     */
    mem_clear((unsigned char *)actor, profilep->class_size, 0); /* Ａｃｔｏｒクラス初期クリアー */

    actor->dlftbl = (void *)actor_dlftbl;

    actor->name   = profilep->name;	/* 名前 */

#ifdef DEBUG_P
    PRINTF("ACTOR NAME %d\n", actor->name);
    DEBUG_PRINT_PROC();
#endif
	    
    actor->status = profilep->status; /* 情報 */
	
    /* データバンクテーブルＮｏ */
    if ( profilep->name == ACTOR_NAME_EN_PART ) {
	actor->bank_ID = (signed char)sz;
	sz             = 0;
    } else {
	actor->bank_ID = (signed char)bank_ID;
    }
    actor->constract_proc = profilep->construct_proc; /* コンストラクト関数 */
    actor->destruct_proc  = profilep->destruct_proc; /* デストラクト関数 */
    actor->move_proc      = profilep->move_proc; /* 処理関数 */
    actor->draw_proc      = profilep->draw_func; /* 表示関数 */
    
    actor->room_ID	   = game_play->room_info.now.ID; /* 部屋Ｎｏ */
    actor->home.position.x = x;	/* 現在座標 */
    actor->home.position.y = y;
    actor->home.position.z = z;
    actor->home.angle.sx   = sx; /* 現在方向 */
    actor->home.angle.sy   = sy;
    actor->home.angle.sz   = sz;
    
    actor->arg_data = arg_data;	/* 引数データ */
    
    Actor_info_part_new(this, actor, profilep->part); /* 役柄別リスト登録 */
    
    save_segment = GetSegment(GAMEPLAY_OBJECT_EXCHANGE_SEGMENT);
    Actor_ct(actor, game);		/* Ａｃｔｏｒクラス コンストラクト */
    SetSegment(GAMEPLAY_OBJECT_EXCHANGE_SEGMENT, save_segment);
    
    return actor;
}

/*-----------------------------------------------------------------------
 *
 *	子Ａｃｔｏｒクラス追加
 *
 *----------------------------------------------------------------------*/
extern Actor *Actor_info_make_child_actor(
    Actor_info     *this,
    Actor	   *mother_actor,
    Game           *game,
    short	   profile,
    float          x,
    float          y,
    float          z,
    short          sx,
    short          sy,
    short          sz,
    short	   arg_data
)
{
    Actor	*child_actor = Actor_info_make_actor(this, game, profile, x,y,z, sx,sy,sz, arg_data);

#ifdef DEBUG_P
    PRINTF("Actor_info_make_child_actor():\n");
    PRINTF("引数: %x; %d; %f,%f,%f; %d,%d,%d; %d;\n",
	   mother_actor, profile, x, y, z, sx, sy, sz, arg_data);
#endif
    
    if ( child_actor == NULL ) return NULL;
    
    mother_actor->child  = child_actor;
    child_actor->mother  = mother_actor;
    if ( child_actor->room_ID >= 0 ) child_actor->room_ID = mother_actor->room_ID;
    
    return child_actor;
}

/*-----------------------------------------------------------------------
 *
 *	ドアＡｃｔｏｒ追加
 * 		arg_data : 0000000000000000
 *			   +----++--++----+
 *			     |    |   |
 *			     |    |   +- ビットＮｏ
 *		   	     |    +----- タイプ
 *			     +---------- ドアＮｏ 
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_make_door_actor(
    Game_play  *game_play,
    Actor_info *this
)
{
    Door_data	*door_data;
    int		i;
    
    door_data = (Door_data *)game_play->door_info.data;
    for (i=0; i<game_play->door_info.num; i++) {

	if ( door_data->profile >= 0 &&								/* 登録されてない？ */
	     ((door_data->status[0].room_status_ID >= 0 &&
	       (door_data->status[0].room_status_ID == game_play->room_info.now.ID ||
		door_data->status[0].room_status_ID == game_play->room_info.old.ID)) ||
	      (door_data->status[1].room_status_ID >= 0 &&
	       (door_data->status[1].room_status_ID == game_play->room_info.now.ID ||
		door_data->status[1].room_status_ID == game_play->room_info.old.ID))) ) {
	    
	    Actor_info_make_actor(this,
				  (Game *)game_play,
				  (door_data->profile & 0x1fff),
				  (float)door_data->position.sx,
				  (float)door_data->position.sy,
				  (float)door_data->position.sz,
				  0,
				  door_data->angle_y,
				  0,
				  (short)((i << (4+6)) + door_data->arg_data));
	    
	    door_data->profile = (short)(-(door_data->profile));
	}
	
	door_data++;
    }   
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒクラス登録
 *
 *----------------------------------------------------------------------*/
extern Actor *Actor_info_new(
    Actor_info *this,
    Actor_data *actor_data,
    Game       *game
) 
{
    return Actor_info_make_actor(this,	
				 game,
				 actor_data->profile,
				 (float)actor_data->position.sx,
				 (float)actor_data->position.sy,
				 (float)actor_data->position.sz,
				 actor_data->angle.sx,
				 actor_data->angle.sy,
				 actor_data->angle.sz,
				 actor_data->arg_data);
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒクラス削除
 *
 *----------------------------------------------------------------------*/
extern Actor *Actor_info_delete(
    Actor_info *this,
    Actor      *actor,
    Game       *game 
) 
{
    Game_play		*game_play    = (Game_play *)game;
    Player_actor	*player_actor = (Player_actor *)get_player_actor(game_play);
    Actor		*next_actor;
    DLFTBL_ACTOR	*actor_dlftbl;
    char *actor_name;

    actor_dlftbl = (DLFTBL_ACTOR *)actor->dlftbl;
    actor_name = actor_dlftbl_GetSegName(actor_dlftbl);
    
    if (HREG(20))
	PRINTF("アクタークラス削除 [%s]\n", actor_name);

#ifdef DEBUG_P
    PRINTF("Actor_info_delete():start name=%d\n", actor->name);
#endif

    if (player_actor != NULL &&
	player_actor->camera_parameter.primary_actor == actor ) {

	anchor_cancel(player_actor);
	
	Camera_change(Gama_play_get_camera(
	    game_play, Gama_play_active_camera(game_play)), CAM_MODE_NORMAL);
    }
    if (this->anchor_marker.anchor_actor == actor)
	this->anchor_marker.anchor_actor = NULL;
    if (this->anchor_marker.anchor_request_actor == actor)
	this->anchor_marker.anchor_request_actor = NULL;
    if (this->anchor_marker.enemyBGM_actor == actor)
	this->anchor_marker.enemyBGM_actor = NULL;
    
    /*
     * ＳＥリセット
     */
    Na_StopAllObjSe((f32 *)&actor->camera_position);	/* <SE> */
    
    Actor_dt(actor, game);	/* Ａｃｔｏｒクラス デストラクト */

    next_actor = Actor_info_part_delete(game_play, this, actor); /* Ａｃｔｏｒ役柄別リスト削除 */

    actor_name_show(actor,"Actor_info_delete",0);
    zelda_free(actor);

    /*
     * オーバーレイ解放
     */
    if (actor_dlftbl->SegmentStart == NULL) {
	if (HREG(20))
	    PRINTF("オーバーレイではありません\n");
    } else {
	assert(actor_dlftbl->allocp != NULL);
	assert(actor_dlftbl->clients > 0);
	--actor_dlftbl->clients;
	actor_free_check(actor_dlftbl);
    }
    
#ifdef DEBUG_P
    PRINTF("Actor_info_delete():end\n");
#endif
    
    return next_actor;
}

/*-----------------------------------------------------------------------
 *
 *	注目Ａｃｔｏｒ画面座標チェック
 *
 *----------------------------------------------------------------------*/
static int anchor_search_display_check(
    Game_play  *game_play,
    Actor      *target_actor
)
{
    short	display_x, display_y;
    
    Actor_display_position_set(game_play, target_actor, &display_x, &display_y);
		
    return (-20 < display_x && display_x < (SCREEN_WD+20) &&
	    -160 < display_y && display_y < (SCREEN_HT+160));
}

/*-----------------------------------------------------------------------
 *
 *	注目Ａｃｔｏｒサーチ
 *
 *----------------------------------------------------------------------*/
static Actor	*primary_actor, *wait_primary_actor;
static float	primary_ratio, enemyBGM_ratio;
static int	primary_wait;
static short	target_angle_y;

extern void anchor_search_check(
    Game_play  *game_play,
    Actor_info *this,
    Actor      *player_actor,
    int	       part
) 
{
    float	ratio;
    
    Actor	*actor 	          = this->actor_list[part].actor;
    Actor	*now_anchor_actor = ((Player_actor *)player_actor)->camera_parameter.primary_actor;

    while( actor != NULL ) {
	
	if ( actor->move_proc != NULL &&
	     actor != player_actor &&
	     Actor_check_status(actor, ACTOR_STATUS_ANCHOR) ) {
	    
	    if ( part == ACTOR_PART_ENEMY &&
		 Actor_check_status(actor, ACTOR_STATUS_FIGHT) &&		/* 戦闘モードＢＧＭ用距離チェック */
		 actor->player_range < (NA_ENM_BGM_DIST_MAX * NA_ENM_BGM_DIST_MAX) &&
		 actor->player_range < enemyBGM_ratio ) {
		
		this->anchor_marker.enemyBGM_actor = actor;
		enemyBGM_ratio             	   = actor->player_range;
	    }
	    
	    if ( actor != now_anchor_actor ) {
		
		ratio = Actor_anchor_ratio(actor,
					   player_actor,
					   target_angle_y);

		if ( ratio < primary_ratio &&
		     Actor_anchor_ratio_check(actor, ratio) &&
		     anchor_search_display_check(game_play, actor) ) {	/* 第一注目Ａｃｔｏｒ変更？ */
		    
		    T_Polygon	*polygon_info;
		    int		bg_actor_index;
		    xyz_t	hit_pos;

		    
		    if ( !T_BGCheck_CameraLineCheck_poly_chgrp_ai(&game_play->BGCheck,
								  &player_actor->eye.position,
								  &actor->eye.position,
								  &hit_pos,
								  &polygon_info,
								  ON,
								  ON,
								  ON,
								  ON,
								  &bg_actor_index) ||
			 T_BGCheck_CheckArrowNoHit(&game_play->BGCheck,
						   polygon_info,
						   bg_actor_index) ) {		/* 壁で遮られてない？ */
			
		    
			if ( actor->anchor_wait ) {		/* 待ち？ */
			    
			    if ( actor->anchor_wait < primary_wait ) {	/* 待ちＡｃｔｏｒ登録？ */
				
				wait_primary_actor   = actor;
				primary_wait         = (int)actor->anchor_wait;
			    }
			}
			else {				/* 第一注目Ａｃｔｏｒ登録 */
			    
			    primary_actor = actor;
			    primary_ratio = ratio;
			}
		    }
		}
	    }
	}
	
	actor = actor->next;
    }
}

extern Actor *Actor_info_anchor_search(
    Game_play  *game_play,
    Actor_info *this,
    Actor      **primary_actorp,
    Actor      *player_actor
) 
{
    primary_actor      =
    wait_primary_actor = NULL;
    primary_ratio      =
    enemyBGM_ratio     = FLT_MAX;
    primary_wait       = INT_MAX;
	
    if ( !player_demo_check(game_play) ) {	/* デモ中でない？ */

	static unsigned char	anchor_part[ACTOR_PART_MAX] = {
	    ACTOR_PART_BOSS,
	    ACTOR_PART_ENEMY,
	    ACTOR_PART_FRIEND,

	    ACTOR_PART_BOM,
	    ACTOR_PART_PEOPLE,
	    ACTOR_PART_EFFECT,
	    ACTOR_PART_TREASURE,
	    ACTOR_PART_SWITCH,
	    ACTOR_PART_OBJ,
	    ACTOR_PART_ITEM,
	    ACTOR_PART_DOOR,
	};

	unsigned char	*anchor_partp = anchor_part;
	int		i;
	
	this->anchor_marker.enemyBGM_actor = NULL;
	
	target_angle_y = player_actor->shape.angle.sy;

	/*
	 * 敵注目チェック
	 */
	for (i=0; i<3; i++, anchor_partp++) anchor_search_check(game_play,
								this,
								player_actor,
								*anchor_partp);

	if ( primary_actor == NULL ) {	/* 敵を注目中？ */
	    
	    /*
	     * 敵以外注目チェック
	     */
	    for (;i<ACTOR_PART_MAX; i++, anchor_partp++) anchor_search_check(game_play,
									     this,
									     player_actor,
									     *anchor_partp);
	}
    }
    
    if ( primary_actor == NULL ) *primary_actorp = wait_primary_actor;	/* 注目Ａｃｔｏｒ無し？ */
    else 			 *primary_actorp = primary_actor;	/* 第一注目Ａｃｔｏｒ有り */
    
    return *primary_actorp;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ検索
 *
 *----------------------------------------------------------------------*/
extern Actor *Actor_info_name_search(
    Actor_info *this,
    int        name,
    int        part
) 
{
    Actor	*actor = this->actor_list[part].actor;
    
    while( actor != NULL ) {
	
	if ( actor->name == name ) return actor;
	
	actor = actor->next;
    }

    return NULL;
}

/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒフィニッシュセット
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_finish(
    Game_play *game_play,
    Actor     *this
)
{
    game_play->actor_info.finish = ACT_FINISH_TIMER;

    Effect_SE_Info_new(game_play, &this->world.position, 20, NA_SE_EN_LAST_DAMAGE);	/* <SE> */
}

/************************************************************************
 *
 *	目アニメーションクラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	目アニメーションセット
 *
 *----------------------------------------------------------------------*/
extern short Eye_Anime_pattern_set(
    Eye_Anime *this,
    short     min_timer,
    short     random_timer,
    short     close_timer
)
{
    int		close;
    
    if ( !timer_check_dec(&this->timer) ) this->timer = (short)get_random_timer(min_timer, random_timer);
    
    if ( (close = this->timer - close_timer) > 0 ) this->pattern = 0;
    else if ( close >= -1 || this->timer <= 1 )    this->pattern = 1;
    else					   this->pattern = 2;

    return this->pattern;
}

/************************************************************************
 *
 *	口アニメーションクラス
 *
 ************************************************************************/

/*-----------------------------------------------------------------------
 *
 *	口アニメーションセット
 *
 *----------------------------------------------------------------------*/
extern short Mouth_Anime_pattern_set(
    Mouth_Anime *this,
    short       min_timer,
    short       random_timer,
    short       mouth_type
)
{
    if ( !timer_check_dec(&this->timer) ) {
	
	this->timer = (short)get_random_timer(min_timer, random_timer);
	
	if ( !((++this->pattern) % 3) ) this->pattern = (short)((int)(rnd() * (float)mouth_type) * 3); 
    }

    return this->pattern;
}

/*-----------------------------------------------------------------------------
 *
 * Part_Break_init():シェイプ分解イニシャル
 *
 *---------------------------------------------------------------------------*/

extern void Part_Break_init(Break_work *this,int joint_max,Game *game)
{
    game;
    
    /* バッファ確保 */
    if((NULL != (this->part_base=(MtxF *)zelda_malloc((sizeof(MtxF))*((unsigned int)joint_max+1))))
       &&
       (NULL!=(this->shape_base=(unsigned int *)zelda_malloc
	       ((sizeof(unsigned int))*((unsigned int)joint_max+1))))
	&&
       (NULL!=(this->b_id=(short *)zelda_malloc
	       ((sizeof(short))*((unsigned int)joint_max+1))))
    )
    {
	mem_clear((unsigned char *)this->part_base,
		  ((sizeof(MtxF))*((unsigned int)joint_max+1)), 0);
	mem_clear((unsigned char *)this->shape_base,
		  ((sizeof(unsigned int))*((unsigned int)joint_max+1)), 0);
	mem_clear((unsigned char *)this->b_id,
		  ((sizeof(short))*((unsigned int)joint_max+1)), 0);
	this->mtxfget_flg = 1;
    }else{
	if(this->part_base != NULL){
	    zelda_free(this->part_base);
	}
	if(this->shape_base != NULL){
	    zelda_free(this->shape_base);
	}
	if(this->b_id != NULL){
	    zelda_free(this->b_id);
	}

    }
}

/*-----------------------------------------------------------------------------
 *
 * Part_Break_get():シェイプ分解パーツ確保
 *
 *---------------------------------------------------------------------------*/

extern void Part_Break_Get(Break_work *this,
			   int now_joint,
			   int start_joint,
			   int end_joint,
			   int joint_max,
			   Gfx **shape,
			   short Bank_ID)
{
    Game_play *game_play = (Game_play *)Effect_GetGamePointer();
    
    /* パーツ作成？ */
    if(!game_play->actor_info.finish && this->mtxfget_flg > 0){

	if(now_joint >= start_joint && now_joint <= end_joint){
	    /* シェイプデータ確認 */
	    if ( *shape != NULL  ){
		*(this->shape_base+(this->mtxfget_flg)) = (unsigned int)*shape;

		/* 座標獲得 */
//		Matrix_get((MtxF *)(*(this->part_base+(this->mtxfget_flg))));
		Matrix_get(this->part_base+(this->mtxfget_flg));

		*(this->b_id+(this->mtxfget_flg)) = (short)Bank_ID;

		++this->mtxfget_flg;
	    }
	}

	/* 最終パーツチェック */
	if(this->old_joint_no != now_joint)
	    ++this->part_count;

	if ( this->part_count >= (unsigned int)joint_max){
	    this->part_count  = (this->mtxfget_flg-1);
	    this->mtxfget_flg = -1;
	}
    }
    this->old_joint_no = now_joint;
}

/*-----------------------------------------------------------------------------
 *
 *  Part_Break():分解してアクター登録
 *
 *---------------------------------------------------------------------------*/

extern int Part_break(Actor *thisx, Break_work *this,Game_play *pgame_play,
		      short idx)
{
    En_Part_Actor	*now_actor;
    Actor		*actor;
    short 		id;
    Game		*game;
    game	= (Game *)pgame_play;
    
//    if((this->mtxfget_flg!=0)||(this->part_count<=0))
    if(this->mtxfget_flg != -1){
	return(NULL);
    }

    while(this->part_count > 0){
	Matrix_put(this->part_base+(this->part_count));

	Matrix_scale(1.0f/thisx->scale.x,
		     1.0f/thisx->scale.y,
		     1.0f/thisx->scale.z, MULT_MTX);

	Matrix_get(this->part_base+(this->part_count));

	if(*(this->b_id+(this->part_count)) >= 0){
	    id = *(this->b_id+(this->part_count));
	}else{
	    id = thisx->bank_ID;
	}
	
	actor = 
	    Actor_info_make_child_actor(&pgame_play->actor_info,thisx,game,
				  En_Part,
				  (*(this->part_base+(this->part_count)))[3][0]
				  ,(*(this->part_base+(this->part_count)))[3][1]
				  ,(*(this->part_base+(this->part_count)))[3][2]
				  ,0,0,id,
				  idx);

	if(actor!=NULL){
	    now_actor = (En_Part_Actor *)actor;
	    Matrix_to_rotate_new(this->part_base+(this->part_count),
				  &actor->shape.angle, 0);
#if 0	    
	    Matrix_get(&(now_actor->part_base));
	    now_actor->part_base[3][0] =
	    now_actor->part_base[3][1] =
	    now_actor->part_base[3][2] = 0.0f;
#endif
	    now_actor->shape_part =
	    *(this->shape_base+(this->part_count));
	    actor->scale = thisx->scale;

	}
	--this->part_count;
    }
    this->mtxfget_flg = 0;
    zelda_free(this->part_base);
    zelda_free(this->shape_base);
    zelda_free(this->b_id);
    return(TRUE);
}


/*----------------------------------------------------------------------------
 *
 * 地面円形煙発生サブルーチン
 *
 *   ポジションＹは actor.ground_y に自動でなります。
 *
 *   sizeは ポジションを 中心とした半径です。
 *
 *   countは 一度に設定する煙効果の数です。
 *
 *   acc_baseは 煙の飛ぶ速度のベーススピードです。（Ｘ，Ｚ軸のみです）
 *
 *----------------------------------------------------------------------*/
extern void _dust_ground_set(
    Game_play *pgame_play,
    Actor *this,
    xyz_t *pos,
    float size,
    int count,
    float acc_base,
    short scale_100,
    short scale_diff,
    u8    light
)
{
    xyz_t pos_w;
    xyz_t vec_w = {0.0f, 0.0f, 0.0f};
    xyz_t acc_w = {0.0f, 0.3f, 0.0f};
    int i;
    float ang_w;
    
    Game *game = (Game *)pgame_play;
    
    ang_w = (rnd() - 0.5f) * 6.28f;
//    ang_w = (float)(game->frame_counter * 10);

    pos_w.y = this->ground_y; 

    acc_w.y += ((rnd()-0.5f) *  0.2f);

//    for( i = count; i >= 0; --i, ang_w += 10.0f)
    for( i = count; i >= 0; --i, ang_w += (6.28f/((float)count + 1.0f)))
    {
	pos_w.x = pos->x + (sinf_table(ang_w) * size);
	pos_w.z = pos->z + (cosf_table(ang_w) * size);
/* 	pos_w.y = this->ground_y + rnd_f(5.0f) + 5.0f; */

	acc_w.x  = ((rnd()-0.5f) * acc_base);
	acc_w.z  = ((rnd()-0.5f) * acc_base);

	if(scale_100 == 0)
	    Effect_SS_Dust_ct_direct(game, &pos_w, &vec_w, &acc_w);
	else
	    if(light) {
		Effect_SS_Dust_sc_li_ct(game,
					&pos_w,
					&vec_w,
					&acc_w,
					scale_100,
					scale_diff
		    );
	    } else {
		Effect_SS_Dust_sc_ct(game,
				     &pos_w,
				     &vec_w,
				     &acc_w,
				     scale_100,
				     scale_diff
		    );
	    }
    }
}


/*----------------------------------------------------------------------------
 *
 *   適当に煙を出すサブルーチン
 *
 *   countは 一度に設定する煙効果の数です。
 *
 *----------------------------------------------------------------------*/
extern void  dust_fly_set2(
    Game_play *pgame_play,
    xyz_t *pos,
    float size,
    int count,
    short scale_100,
    short scale_diff,
    u8 light)
{
    xyz_t pos_w;
    xyz_t vec_w = {0.0f, 0.0f, 0.0f};
    xyz_t acc_w = {0.0f, 0.3f, 0.0f};
    int i;
    short scale_100_w;
    
    Game *game = (Game *)pgame_play;
    
    for( i = count; i >= 0; --i ) {
	pos_w.x = pos->x + (rnd() - 0.5f) * size;
	pos_w.y = pos->y + (rnd() - 0.5f) * size;
	pos_w.z = pos->z + (rnd() - 0.5f) * size;

	scale_100_w = scale_100 + (short)((float)scale_100 * rnd() * 0.2f);
	
	if (light) {
	    Effect_SS_Dust_sc_li_ct(game,
				    &pos_w,
				    &vec_w,
				    &acc_w,
				    scale_100_w,
				    scale_diff
		);
	} else {
	    Effect_SS_Dust_sc_ct(game,
				 &pos_w,
				 &vec_w,
				 &acc_w,
				 scale_100_w,
				 scale_diff);
	}
    }
}
/*-----------------------------------------------------------------------
 * 自分と爆風の当り判定
 *-----------------------------------------------------------------------*/

extern Actor *BlastVsMyCheck( Game *game, ClObj *thisx)
{
    game;
    
//    ClObj  *thisx = (ClObj  *)this;
//    PRINTF("actor    %x\n",this);
//    PRINTF("cl       %x\n",thisx);

    
    if ((thisx->ac_bit & CL_AC_BIT_HIT)) {
//	PRINTF("bit chk ok    %x\n",thisx->ac_bit);
//	PRINTF("ac       p    %x\n",thisx->ac_at_actor);
//	PRINTF("at       p    %x\n",thisx->at_ac_actor);
//	PRINTF("oc       p    %x\n",thisx->oc_actor);
	if(thisx->ac_at_actor->part == ACTOR_PART_BOM){
//	    PRINTF("part chk ok\n");
	    bitclr(thisx->ac_bit, CL_AC_BIT_HIT);
//	    PRINTF("bit clr ok\n");
	    return thisx->ac_at_actor;
	}
    }
    return NULL;
}
extern Actor *BlastVsMyCheck_c( Game *game, Actor *thisx)
{
    Actor *check_actor;
    float dist;

    check_actor =
	((Game_play *)game)->actor_info.actor_list[ACTOR_PART_BOM].actor;
    
    while (check_actor != NULL) {
	
	if (check_actor == thisx || check_actor->arg_data != 1) {
	    check_actor = check_actor->next;
	    continue;
	}

//	if(check_actor->move_proc == NULL)
//	    continue;

	dist = Actor_search_actor_distance(thisx, check_actor);
/*
	if((float)(((En_Bom_actor *)check_actor)->bomb_sph.elem_tbl[0].attr.global_sph.r) >= dist)
	*/
	if(((float)(check_actor->shape.angle.sz * 10) + 80.0f) >= dist)
	    return check_actor;
	
	check_actor = check_actor->next;
    }
    return NULL;
}
/*-----------------------------------------------------------------------
 *
 *	Ａｃｔｏｒ役柄変更
 *
 *----------------------------------------------------------------------*/
extern void Actor_info_part_chg(
    Game_play     *game_play,
    Actor_info 	  *this,
    Actor      	  *actor,
    unsigned char part
) 
{
    Actor_info_part_delete(game_play, this, actor);
    Actor_info_part_new(this, actor, part); 
}
/*-----------------------------------------------------------------------
 * 飛び道具先読み当り判定
 *-----------------------------------------------------------------------*/
extern Actor *ShotVsMyCheck( Game_play *game_play, Actor *this, float reng)
{

    Actor *check_actor;
    xyz_t pos_w,p_spd,posd1,posd2;
    
    check_actor = game_play->actor_info.actor_list[ACTOR_PART_EFFECT].actor;
    
    while (check_actor != NULL) {
	if((check_actor->name != ACTOR_NAME_ARMS_HOOK &&
	    check_actor->name != ACTOR_NAME_EN_ARROW) || check_actor == this){
	    check_actor = check_actor->next;
	    continue;
	}
	if(search_position_distance(&this->world.position,
				      &check_actor->world.position) > reng ||
	     !((Arms_Hook_actor *)check_actor)->timer){
	    check_actor = check_actor->next;
	    continue;
	}
	p_spd.x=(check_actor->speedF*10.0f)*sin_s(check_actor->world.angle.sy);
        p_spd.y= check_actor->position_speed.y + (check_actor->gravity*10.0f);
        p_spd.z=(check_actor->speedF*10.0f)*cos_s(check_actor->world.angle.sy);

	pos_w.x = check_actor->world.position.x + p_spd.x;
	pos_w.y = check_actor->world.position.y + p_spd.y;
	pos_w.z = check_actor->world.position.z + p_spd.z;
	
	if (CollisionCheckPipeVsLine2(
	    /* 円筒情報(offset未対応:statusにoffsetがないため） */
	    this->status_info.r, this->status_info.h, 0.0f,
	    &this->world.position,
	    &check_actor->world.position, &pos_w, /* ライン情報 */
	    &posd1,&posd2) != NULL){ /* 交点（pcross1優先) */
	    return check_actor;
	}
	
	check_actor = check_actor->next;
    }

    return NULL;
}
/************************************************************************/
/*    メッセージ 設定 テスト						*/
/************************************************************************/
extern void mes_set(Game_play *game_play, Actor *thisx, short mes_no)
{
    short mes_b;
    switch(game_play->scene_data_ID){
    case SPOT04:
    case SPOT05:
    case SPOT10:
    case YDAN:
    case YDAN_BOSS:
    case MORIBOSS:
    case LINK_HOME:
    case KOKIRI_HOME:
    case KOKIRI_HOME2:
    case KOKIRI_HOME3:
    case KOKIRI_HOME4:
    case KOKIRI_HOME5:
    case KOKIRI_SHOP:
	mes_b = 0x1000;
	break;

    case SPOT00:
    case SPOT20:
    case LONRON:
////////    case TARON_SHOP:
	mes_b = 0x2000;
	break;

    case SPOT16:
    case SPOT17:
    case SPOT18:
////////    case SPOT19:
    case DDAN_BOSS:
    case HIDAN:
    case FIRE_BOSS:
	mes_b = 0x3000;
	break;
	
    case SPOT03:
    case SPOT07:
    case SPOT08:
    case BDAN:
    case BDAN_BOSS:
	mes_b = 0x4000;
	break;
	
    case SPOT01:
    case SPOT02:
    case IMPA_HOME:
    case KAKARIKO:
//    case KAKARIKO_HOME2:
    case KAKARIKO_HOME3:
//    case KAKARIKO_SHOP:
    case HAKAMORI_HOUSE:
    case HAKASITARELAY:
    case HAKAANA:
    case HAKADAN:
    case HAKADAN_BOSS:
	mes_b = 0x5000;
	break;
	
    case SPOT06:
    case SPOT09:
    case SPOT11:
    case LABO:
    case TENTO:
    case JYASINZOU:
    case JYASINZOU_BOSS:
	mes_b = 0x6000;
	break;
	
    case SPOT15:
    case ENTRA:
    case MARKET_DAY:
    case MARKET_NIGHT:
    case MARKET_RUINS:
    case MARKET_ALLEY:
    case MARKET_ALLEY_N:
////////    case MARKET_ALLEY_R:
	mes_b = 0x7000;
	break;
	
    default:
	mes_b=0x0000;
	break;
    }
    thisx->talk_message = mes_b | mes_no;
}


/****************************************************************/
/*		ＢＧポイント床チェック				*/
/****************************************************************/
extern short BG_point_check(Actor *this,Game_play *game_p,float reng,short ang)
{
    short a,env_b;
    float speed_x, speed_z;
    xyz_t pos_back;

    xyz_t_move(&pos_back, &this->world.position);
    env_b = this->environment_info;

    speed_x = reng * sin_s(ang);
    speed_z = reng * cos_s(ang);

    this->world.position.x += speed_x;
    this->world.position.z += speed_z;

    Actor_BGcheck2(game_p,
		   this,
		   0.0f,0.0f,0.0f,
		   BGCHECK_GROUND);	/* チェック情報 */

    xyz_t_move(&this->world.position, &pos_back);

    a = bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND);
    this->environment_info = env_b;
    return a;
}

/****************************************************************/
/*		自分が注目戦闘の対象かチェック			*/
/****************************************************************/
extern short Anc_Fight_My_Check(Game_play *game_play,Actor *this){
    Actor *pplayer = get_player_actor(game_play);
    Player_actor	*player_actor = (Player_actor *)pplayer;

    if((bitcheck(player_actor->action, P_ACTION_ANCHOR_FIGHT))&&
	this->anchor_flag){
	return 1;
    }else{
	return 0;
    }
}
/****************************************************************/
/*	注目戦闘中 自分が はみご かチェック			*/
/****************************************************************/
extern short Anc_Fight_ham_Check(Game_play *game_play,Actor *this){
    Actor *pplayer = get_player_actor(game_play);
    Player_actor	*player_actor = (Player_actor *)pplayer;

    if((bitcheck(player_actor->action, P_ACTION_ANCHOR_FIGHT))&&
	!this->anchor_flag){
	return 1;
    }else{
	return 0;
    }
}

/*
 *
 * 座標追跡汎用ルーチン
 *
 */
extern float chase_pos(
    xyz_t *target, xyz_t *chaser,
    float speed_s, float speed_m,float area_max, float area_min)
{
    float r = 0.0f;
    
    if(search_position_distance(target, chaser) >= area_max){
	r = add_calc(&chaser->x, target->x, speed_s, speed_m, 0.0f);
	r += add_calc(&chaser->y, target->y, speed_s, speed_m, 0.0f);
	r += add_calc(&chaser->z, target->z, speed_s, speed_m, 0.0f);
    }else{
	if(search_position_distance(target, chaser) > area_min){
	    r = add_calc(&chaser->x, target->x, speed_s, speed_m, 0.0f);
	    r += add_calc(&chaser->y, target->y, speed_s, speed_m, 0.0f);
	    r += add_calc(&chaser->z, target->z, speed_s, speed_m, 0.0f);
	}
    }
    return r;
}

/*
 *
 * 汎用 影表示ルーチン
 *
 */
extern void Shadow_draw(
    xyz_t	  *pos,
    xyz_t	  *shadow_scale,
    unsigned char shadow_a,
    Game_play     *game_play
)
{
    MtxF	ground_matrix;
    float	pos_y;
    xyz_t	chk_pos;
    T_Polygon	*ground_polygon_info;
    
    /*
     * 影表示
     */
    OPEN_DISP(game_play->g.graph);

//    _texture_decal_shadow(game_play->g.graph);
    SET_NOW_DISP(rcp_mode_set(NOW_DISP, 44));

//    gDPSetPrimColor(NEXT_POLY_XLU_DISP, 0,0, 0,0,0,shadow_a);
    gDPSetPrimColor(NEXT_DISP, 0,0, 0,0,0,shadow_a);

    chk_pos.x = pos->x;
    chk_pos.y = pos->y+1.0f; 
    chk_pos.z = pos->z;
    
    pos_y = T_BGCheck_ObjGroundCheck2(
	game_play,
	&game_play->BGCheck,
	&ground_polygon_info,
	&chk_pos);
    if(ground_polygon_info != NULL){
	T_Polygon_Ground_Matrix(ground_polygon_info,
				pos->x, pos_y, pos->z,
				ground_matrix);

	Matrix_put(&ground_matrix);
    }else{
	Matrix_translate(pos->x, pos->y, pos->z, SET_MTX);
    }
	    
    Matrix_scale(shadow_scale->x, 1.0f, shadow_scale->z, MULT_MTX);
//    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game_play->g.graph),
    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game_play->g.graph),
	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    
//    gSPDisplayList(NEXT_POLY_XLU_DISP, shadow_model);
    gSPDisplayList(NEXT_DISP, shadow_model);
	
    CLOSE_DISP(game_play->g.graph);

}

/*-----------------------------------------------------------------------
 *	おそらくこのパターンさえあれば
 *	たいがい使えるであろう地震（自信）関数	
 *----------------------------------------------------------------------*/
extern void set_jisin(Game_play *game_play, short yad, short time)
{
    short id;
    
    id = startQuake(&game_play->camera, QUAKE_TYPE_GODOWN);
    
    setSpeedQuake(id,
		  20000);
    setScaleQuake(id,
		  yad,
		  0,
		  0,
		  0);
    setTimerQuake(id,
		  time);
}
extern void set_jisin_2(Game_play *game_play, short yad, short time, short spd)
{
    short id;
    
    id = startQuake(&game_play->camera, QUAKE_TYPE_GODOWN);
    
    setSpeedQuake(id,
		  spd);
    setScaleQuake(id,
		  yad,
		  0,
		  0,
		  0);
    setTimerQuake(id,
		  time);
}

extern void ActorQuakeRumbleSet(Actor *this, Game_play *game_play, short yad, short time)
{
    if(yad >= 5) {
	RUMBLE_ENTRY2_TYPE_A(this->player_range);
    } else {
	RUMBLE_ENTRY2_TYPE_B(this->player_range);
    }
    set_jisin(game_play, yad, time);
}

/*
 *  任意範囲の乱数
 */
extern float rnd_f(float r)
{
    return rnd()*r;
}
/*
 *  正負均等の乱数
 */
extern float rnd_fx(float r)
{
    return (rnd()-0.5f)*r;
}

/*-----------------------------------------------------------------------
 *
 *	鍵表示用関数
 *	key_timer:10	->	鍵閉じた状態
 *	key_timer:10-1	->	鍵開き中
 *	key_timer:0	->	鍵開き後（鍵表示なし）
 *
 *----------------------------------------------------------------------*/
extern Gfx	doorkagi_model[];
extern Gfx	doorkusari_model[];
extern Gfx	doorkagiboss_model[];
extern Gfx	doorkusariboss_model[];


/*
 *  鍵用
 */
#define EN_DOOR_KUSARI_KATAMUKI		0.54f
#define EN_DOOR_KUSARI_BOSS_KATAMUKI	0.644f

typedef struct {
    float	kusari_katamuki;
    float	sin_cos_ratio;
    float	offset_y;
    float	scale;
    float	init_z;
    Gfx		*kusari_model;
    Gfx		*kagi_model;
} Door_Key_Status;

extern void key_draw(Game *game, int key_timer, int type)
{
    static Door_Key_Status	door_key_status_data[] = {
	{EN_DOOR_KUSARI_KATAMUKI, 	6000.0f, 5000.0f, 1.0f,  0.0f, doorkusari_model,     doorkagi_model},
	{EN_DOOR_KUSARI_BOSS_KATAMUKI, 12000.0f, 8000.0f, 1.0f,  0.0f, doorkusariboss_model, doorkagiboss_model},
	{EN_DOOR_KUSARI_KATAMUKI+0.1f,  8500.0f, 8000.0f, 1.75f, 0.1f, doorkusari_model,     doorkagi_model},
    };
    
    Door_Key_Status	*door_key_status = door_key_status_data + type;
    int 		i;
    MtxF		mtx;
    float 		scale, sin_value, cos_value;
    float		rot_angle_z = door_key_status->init_z;
    
    OPEN_DISP(game->graph);

    /* ドアの向きによって追加してください */
    /*    Matrix_rotateY(F_PI, MULT_MTX);*/
    
    /* ドアからのオフセット */
    Matrix_translate(0.0f,
		     door_key_status->offset_y,
		     500.0f,
		     MULT_MTX);

    Matrix_get(&mtx);

    /* 鎖移動量計算 */
    sin_value = (-(EN_DOOR_KEY_TIME - key_timer) *
		 sinf(door_key_status->kusari_katamuki-rot_angle_z) *
		 (1.0f / (float)EN_DOOR_KEY_TIME)) * door_key_status->sin_cos_ratio;
    cos_value = ((EN_DOOR_KEY_TIME - key_timer) *
		 cosf(door_key_status->kusari_katamuki-rot_angle_z) *
		 (1.0f / (float)EN_DOOR_KEY_TIME)) * door_key_status->sin_cos_ratio;

    for (i = 0; i < 4; i++) {

	Matrix_put(&mtx);
	Matrix_rotateZ(rot_angle_z, MULT_MTX);
	Matrix_translate(sin_value,
			 cos_value,
			 0.0f,
			 MULT_MTX);
	if (door_key_status->scale != 1.0f)
	    Matrix_scale(door_key_status->scale,
			 door_key_status->scale,
			 door_key_status->scale,
			 MULT_MTX);
	gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph),
		  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

	gSPDisplayList(NEXT_DISP, door_key_status->kusari_model);

	rot_angle_z +=
	    (i % 2)? door_key_status->kusari_katamuki * 2.0f: F_PI - door_key_status->kusari_katamuki * 2.0f;
    }

    scale = (float)key_timer * (1.0f / (float)EN_DOOR_KEY_TIME);

    Matrix_put(&mtx);

    Matrix_scale(scale, scale, scale, MULT_MTX);

    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph),
	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

    gSPDisplayList(NEXT_DISP, door_key_status->kagi_model);

    CLOSE_DISP(game->graph);
}

/*---------------------------------------------------------------------------
 *
 * 閃光セット
 *
 *-------------------------------------------------------------------------*/
extern void SetSparkFlash(Game *game, xyz_t *pset_pos)
{
    /*
     * 閃光セット
     */
    CollisionCheckSetSparkFlashBlue(game, pset_pos);
}

/*---------------------------------------------------------------------------
 * 共通フォグ設定ルーチン
 *
 * 	fog_type = 赤 青 白 指定	ラベル
 *					FOG_TYPE_B	 青 指定 
 *					FOG_TYPE_R	 赤 指定
 *					FOG_TYPE_H	 白 指定
 *
 *	fog_color = 色の濃さ ０ ー ２５５
 *			（内部で ７とＯＲを かけるので実際には、７ー２５５）
 *
 *	poly_type = 半透明 か 不透明 の指定	ラベル
 *						FOG_POLY_N	不透明 指定
 *						FOG_POLY_X	半透明 指定
 *
 *	timer  =   フォグを かけてる時間 ０ ー ２５５
 *
 *
 *-------------------------------------------------------------------------*/
extern void Set_Fog(Actor *this, short fog_type, short fog_color,
		    short poly_type, short timer)
{
    if(fog_type == FOG_TYPE_H && !(fog_color & 0x8000))
	Actor_SE_set(this, NA_SE_EN_LIGHT_ARROW_HIT);	/* <SE> */
    
    this->fog_data = fog_type|poly_type|((fog_color & 0x00f8) << 5) | timer;

    this->fog_timer = timer;
}

/*---------------------------------------------------------------------------
 * 環境マッピング 光源の方向セット
 *-------------------------------------------------------------------------*/
extern void Setpos_HiliteReflect_init(
    xyz_t	*pos,
    Game_play 	*game_play
)
{
    xyz_t	light_direction;	/* 環境マッピングのため */

    light_direction.x = (float)game_play->kankyo.sun_light.status.diffuse.dx;
    light_direction.y = (float)game_play->kankyo.sun_light.status.diffuse.dy;
    light_direction.z = (float)game_play->kankyo.sun_light.status.diffuse.dz;

    HiliteReflect_init(pos,
		       &game_play->view.eye,
		       &light_direction,
		       game_play->g.graph);
}

/*---------------------------------------------------------------------------
 * 環境マッピング 光源の方向セット
 *-------------------------------------------------------------------------*/
extern void Setpos_HiliteReflect_xlu_init(
    xyz_t	*pos,
    Game_play 	*game_play
)
{
    xyz_t	light_direction;	/* 環境マッピングのため */

    light_direction.x = (float)game_play->kankyo.sun_light.status.diffuse.dx;
    light_direction.y = (float)game_play->kankyo.sun_light.status.diffuse.dy;
    light_direction.z = (float)game_play->kankyo.sun_light.status.diffuse.dz;

    HiliteReflect_xlu_init(pos,
			   &game_play->view.eye,
			   &light_direction,
			   game_play->g.graph);
}

/************************************************************************
 *
 * ＮＰＣ関連
 *
 ************************************************************************/
/*-----------------------------------------------------------------------
 *
 * 設定データ
 *
 *----------------------------------------------------------------------*/

/*
 * 目線データ
 */
static EyeMoveInf eye_move_info[13]={

    {	/* 子供マロン、大人マロン	*/
	/*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
	{ 60*182,-20*182, 35*182, 30*182,  0*182,  0*182,  ON},
	 170.0f, 90*182,	/* 距離, 範囲	*/
    },
    
    {	/* インゴー	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 60*182,-30*182, 30*182, 30*182,-10*182, 20*182,  ON},
	 170.0f, 90*182,	/* 距離, 範囲	*/
    },
    
    {	/* サリア、コキリ族（女）	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 70*182,-40*182, 20*182, 20*182,-20*182, 10*182,  ON},
	 170.0f, 90*182,	/* 距離, 範囲	*/
    },
    
    {	/* ダルニア	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 30*182,-20*182,  0*182, 10*182,-10*182,  0*182,  ON},
	 170.0f, 90*182,	/* 距離, 範囲	*/
    },
    
    {	/* ゴロン族	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 60*182,-10*182, 10*182, 20*182,-60*182, 60*182,  ON},
	 170.0f, 90*182,	/* 距離, 範囲	*/
    },
    
    {	/* コキリ族（男）	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        {  0*182,-40*182, 60*182, 90*182,-20*182, 20*182,  ON},
	 170.0f, 90*182,	/* 距離, 範囲	*/
    },
    
    {	/* 犬おばさん・赤おばば・いったりさん  等 */
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 60*182,-20*182, 20*182, 20*182,  0*182,  0*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
    
    {	/* ヒゲ・木箱前おっさん	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 60*182,-20*182,  0*182, 20*182,  0*182, 40*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
    
    {	/* ゴザ売り	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 60*182,-20*182,-20*182,  0*182,  0*182,  0*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
    
    {	/* ババア・ソカシ	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 10*182,-20*182, 20*182, 40*182,  0*182,  0*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
    
    {	/* アレイじいさん	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 20*182,-20*182,  0*182, 40*182,  0*182, 20*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
    
    {	/* ゾーラ	*/
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 60*182,-40*182, 40*182, 20*182,-20*182, 20*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
    
    {	/* シーク・インパ・ナボール・子ルト・大ゼルダ */
        /*   首Y, 首minX, 首maxX,    腰Y, 腰minX, 腰maxX, 体まわす	*/
        { 35*182,-20*182, 20*182, 20*182,  0*182,  0*182,  ON},
	   0.0f,  0*182,	/* 距離, 範囲	*/
    },
};

/*
 * その他
 */
#define add_calc_short_angleN(m, n)	add_calc_short_angle(m, n, 6, 2000, 1)
#define KEEP_TIME (short)get_random_timer(30, 30)
#define CIRA_TIME (short)get_random_timer(10, 10)

/*-----------------------------------------------------------------------
 *
 * 標準会話るーちん
 * 
 *----------------------------------------------------------------------*/
extern int npc_talk(
    Game_play *game_play,
    Actor *thisx,
    NpcBasicAct *basic,
    float range,
    unsigned short (*set_mes_process)(Game_play *, Actor *),
    short (*end_mes_process)(Game_play *, Actor *)
){
    short display_x, display_y;

    /*
     * 会話ＯＫ？
     */
    if(Actor_talk_check(thisx, game_play)) {
	basic->talk_stat=NOW_TALK;
	return TRUE;
    }

    /*
     * 現在、会話中‥
     */
    if(basic->talk_stat!=END_TALK) {
	basic->talk_stat=end_mes_process(game_play, thisx);
	return FALSE;
    }

    /*
     * 画面に入ってる？
     */
    Actor_display_position_set(game_play, thisx, &display_x, &display_y);
    if((display_x<  0)||(display_x>320)||
       (display_y<  0)||(display_y>240)) return FALSE;

    /*
     * 会話リクエスト
     */
    if(Actor_talk_request2(thisx, game_play, range)==0) return FALSE;

    /*
     * メッセージ選択
     */
    thisx->talk_message=set_mes_process(game_play, thisx);
    return FALSE;
}

/*-----------------------------------------------------------------------
 *
 * 目線移動さぶるーちん
 * 
 *----------------------------------------------------------------------*/
static void eye_moveS(
    Actor *thisx,
    NpcBasicAct *basic,
    short neck_limit_y,
    short neck_max_x,
    short neck_min_x,
    short kosi_limit_y,
    short kosi_max_x,
    short kosi_min_x,
    unsigned char turn
){
    short ray_angle_x, ray_angle_y;
    short aim_angle_x, aim_angle_y;
    short offset;
    xyz_t eye;

    /*
     * 自分と対象とのアングルを求める
     */
    eye.x=thisx->world.position.x;
    eye.y=thisx->world.position.y+basic->my_eye_offset;
    eye.z=thisx->world.position.z;
    ray_angle_x =search_position_angleX(&eye, &basic->attention);
    ray_angle_y =search_position_angleY(&eye, &basic->attention);

    /*
     * Ｙアングル
     */
    aim_angle_y=search_position_angleY(
	&thisx->world.position, &basic->attention
	);
    aim_angle_y-=thisx->shape.angle.sy;
    offset=min_max_limit(aim_angle_y,-neck_limit_y,neck_limit_y);
    add_calc_short_angleN(&basic->neck.sy, offset);
    offset=( ABS(aim_angle_y)>=32768 ? 0 : ABS(aim_angle_y) );
    basic->neck.sy=min_max_limit(basic->neck.sy,-offset, offset);
    aim_angle_y-=basic->neck.sy;
    offset=min_max_limit(aim_angle_y,-kosi_limit_y,kosi_limit_y);
    add_calc_short_angleN(&basic->kosi.sy, offset);
    offset=( ABS(aim_angle_y)>=32768 ? 0 : ABS(aim_angle_y) );
    
    basic->kosi.sy=min_max_limit(basic->kosi.sy,-offset, offset);

    if(turn) {	/* 体もまわす	*/
	add_calc_short_angleN(
	    &thisx->shape.angle.sy, ray_angle_y
	    );
    }

    /*
     * Ｘアングル
     */
    
    /* 首	*/
    aim_angle_x =ray_angle_x;
    offset=min_max_limit(aim_angle_x, neck_min_x, neck_max_x);
    add_calc_short_angleN(&basic->neck.sx, offset);
    
    /* 腰	*/
    aim_angle_x-=basic->neck.sx;
    offset=min_max_limit(aim_angle_x, kosi_min_x, kosi_max_x);
    add_calc_short_angleN(&basic->kosi.sx, offset);
}

/*-----------------------------------------------------------------------
 *
 * 見える範囲
 *
 *----------------------------------------------------------------------*/
extern short get_search_angle(
    short no
){
    return eye_move_info[no].search_angle;
}

/*-----------------------------------------------------------------------
 *
 * 振り向き
 * 
 *----------------------------------------------------------------------*/
static short check_behind(
    Actor *thisx,
    NpcBasicAct *basic,
    float distance,
    short angle,
    short compulsion
){
    short angle_y;
    float dist;
    
    /*
     * 強制モード指定あり？
     */
    if(compulsion!=CND_DUMY) {
	return compulsion;
    }
    
    /*
     * 会話中？
     */
    if(basic->talk_stat!=END_TALK) {
	return TRN_ARND;
    }
    
    /*
     * 距離はなれすぎ？
     */
    dist=search_position_distance(
	&thisx->world.position, &basic->attention
	);
    
    if(dist >distance) {
	basic->see_timer=0;
	basic->see_count=0;
	return NON_ACTN;
    }

    /*
     * 視界に入ってる？
     */
    angle_y=search_position_angleY(&thisx->world.position, &basic->attention);
    angle_y=ABS((short)((float)angle_y-(float)thisx->shape.angle.sy));

    if(angle_y<=angle) {
	basic->see_timer=0;
	basic->see_count=0;
	return NRM_LOOK;
    }

    /*
     * そのまま？
     */
    if(timer_check_dec(&basic->see_timer)) {
	return basic->see_condition;
    }

    /*
     * 振り向く
     */
    switch(basic->see_count) {

    case 0:	/* 始めに‥	*/
    case 2:

	basic->see_timer=KEEP_TIME;
	basic->see_count++;
	return NON_ACTN;

    case 1:	/* 首だけ‥	*/

	basic->see_timer=CIRA_TIME;
	basic->see_count++;
	return NCK_MOVE;
    }	return TRN_ARND;	/* それ以外は、これ	*/
}    

/*-----------------------------------------------------------------------
 *
 * 目線移動
 *
 *----------------------------------------------------------------------*/
extern void eye_moveM(
    Actor *thisx,
    NpcBasicAct *basic,
    short no,
    short compulsion	/* 強制モード	*/
){
    AngleLimit limdat;

    /*
     * 振り向き
     */
    basic->see_condition=check_behind(
	thisx,
	basic,
	eye_move_info[no].search_range,
	eye_move_info[no].search_angle,
	compulsion
	);

    /*
     * データセット
     */
    limdat=eye_move_info[no].lim_dat;
    switch(basic->see_condition) {
	
    case NON_ACTN:	/* 無反応	*/

	limdat.neck_limit_y=0;
	limdat.neck_max_x=0;
	limdat.neck_min_x=0;

    case NCK_MOVE:	/* 首だけでみる	*/

	limdat.kosi_limit_y=0;
	limdat.kosi_max_x=0;
	limdat.kosi_min_x=0;
	
    case NRM_LOOK:	/* 上半身でみる	*/	
	
	limdat.turn=0;
	
    default:		/* その他	*/
	break;
	    
    }
    
    /*
     * 目線移動
     */
    eye_moveS(
	thisx,
	basic,
	limdat.neck_limit_y,
	limdat.neck_max_x,
	limdat.neck_min_x,
	limdat.kosi_limit_y,
	limdat.kosi_max_x,
	limdat.kosi_min_x,
	limdat.turn
	);
}

/*-----------------------------------------------------------------------
 *
 * なにもしない
 *			
 *----------------------------------------------------------------------*/
static Gfx *npc_nothing(
    Graph *graph
){
    Gfx *gfxp_ret;
    Gfx *gfxp=(Gfx *)graph_alloc(graph, sizeof(Gfx));

    gfxp_ret=gfxp;
    gSPEndDisplayList(gfxp++);
    return(gfxp_ret);
}

/*-----------------------------------------------------------------------
 *
 * レンダモードの変更
 *			
 *----------------------------------------------------------------------*/
static Gfx *change_render_mode(
    Graph *graph
){
    Gfx *gfxp_ret;
    Gfx *gfxp=(Gfx *)graph_alloc(graph, sizeof(Gfx)*2);

    gfxp_ret=gfxp;
    gDPSetRenderMode(gfxp++, G_RM_FOG_SHADE_A, G_RM_AA_ZU_XLU_SURF2);
    gSPEndDisplayList(gfxp++);
    return(gfxp_ret);
}

/*-----------------------------------------------------------------------
 *
 * 不透明キャラの表示
 *			
 *----------------------------------------------------------------------*/
extern void no_clarity(
    Game *game,
    Skeleton_Info *skel,
    int  (*before)(Game *, int, Gfx **, xyz_t *, s_xyz *, void *, Gfx **),
    void (*after)(Game *, int, Gfx **, s_xyz *, void *, Gfx **),
    void *p,
    short alpha
){
    OPEN_DISP(game->graph);
    _texture_z_light_fog_prim(game->graph);
	
    gDPPipeSync(NEXT_DISP);
    gDPSetEnvColor(
	NEXT_DISP,
	0,
	0,
	0,
	alpha
    );

    gDPPipeSync(NEXT_DISP);
    gSPSegment(NEXT_DISP, ANIME_MODEL_5_SEGMENT,
	npc_nothing(game->graph)
    );
    
    SET_NOW_POLY_OPA_DISP(
	Si2_draw2_SV(
	    game,
	    (Rigid_ModelPointer *)skel->list,
	    skel->now_joint,
	    skel->model_num,
	    before, after,
	    p,
	    NOW_POLY_OPA_DISP
	    )
    );
    
    CLOSE_DISP(game->graph);
}

/*-----------------------------------------------------------------------
 *
 * 半透明キャラの表示
 *			
 *----------------------------------------------------------------------*/
extern void clarity(
    Game *game,
    Skeleton_Info *skel,
    int  (*before)(Game *, int, Gfx **, xyz_t *, s_xyz *, void *, Gfx **),
    void (*after)(Game *, int, Gfx **, s_xyz *, void *, Gfx **),
    void *p,
    short alpha
){
    OPEN_DISP(game->graph);
    _texture_z_light_fog_prim_xlu(game->graph);
    
    gDPPipeSync(NEXT_POLY_XLU_DISP);
    gDPSetEnvColor(
	NEXT_POLY_XLU_DISP,
	0,
	0,
	0,
	alpha
    );

    gSPSegment(
	NEXT_POLY_XLU_DISP,
	ANIME_MODEL_5_SEGMENT,
	change_render_mode(game->graph)
    );
	
    SET_NOW_POLY_XLU_DISP(
	Si2_draw2_SV(
	    game,
	    (Rigid_ModelPointer *)skel->list,
	    skel->now_joint,
	    skel->model_num,
	    before, after,
	    p,
	    NOW_POLY_XLU_DISP)
    );
    CLOSE_DISP(game->graph);
}

/*-----------------------------------------------------------------------
 *
 * コキリ族・アルファ値セット
 *
 *----------------------------------------------------------------------*/
extern int debug_camera_sw;
extern short kokiri_alpha_set(
    Actor *thisx,
    Game_play *game_play,
    short alpha,
    float range
){
    Actor *pl=(Actor *)get_player_actor(game_play);
    float wrange;
    
    /*
     * デモカメラ作動中？
     */
    if((game_play->demo_play.mode)||(debug_camera_sw)) {
	wrange=search_position_distance(
	    &thisx->world.position, &game_play->view.eye
	    );
	wrange/=4.0f;	/* デモ中は、倍の距離で出現 */
    }
    else {
	wrange=search_position_distance(
	    &thisx->world.position,  &pl->world.position
	    );
    }

    /*
     * 接近？
     */
    if(wrange>range) {	/* 消える	*/
	Actor_clear_status(thisx,ACTOR_STATUS_ANCHOR);
	add_calc_short_angle(&alpha,   0, 6, 20, 1);
    }
    else {	/* 出現	*/
	Actor_set_status(thisx, ACTOR_STATUS_ANCHOR);
	add_calc_short_angle(&alpha, 255, 6, 20, 1);
    }
    return alpha;
}

/*-----------------------------------------------------------------------
 *
 * アニメーション切り替え
 *
 *----------------------------------------------------------------------*/
extern void npc_anime_ct(
    Skeleton_Info *sk,
    AnimeCtInfo *dt,
    int no
){
    float anime_max_frame;	/* 終了フレーム	*/

    /*
     ** 指定データ ****/
    dt+=no;

    /*
     ** 終了フレーム決定 ****/
    if(dt->end_frame>0.0f)	anime_max_frame= dt->end_frame;
    else anime_max_frame=(float)Si2_anime_end_frame(dt->anime);

    /*
     ** コンストラクト ****/
    Skeleton_Info2_init(
	sk,
	dt->anime,
	dt->anime_speed,
	dt->start_frame,
	anime_max_frame,
	dt->flag,
	dt->morfcount
	);
}

/*-----------------------------------------------------------------------
 *
 * プログラム・ウェイト
 *
 *----------------------------------------------------------------------*/
extern void program_wait(
    Game_play *game_play,
    short *y,
    short *z,
    int max_count
){
    unsigned long fcount=0;
    int i;

    /*
     * プログラム・ウェイト基数セット
     */
    fcount=game_play->game_frame_counter;
    for(i=0;i<max_count;i++) {
	*(y+i)=fcount*(0x300+1300+i*50);
	*(z+i)=fcount*(0x300+1600+i*50);
    }
}

/*====	ＮＰＣ関連おわり	========================================*/


#include "z_cheap_proc.c"
#include "z_common.c"		/* ＮＰＣなどで使用するルーチン集	*/


#if !defined(ROM_F) && 0
extern void actor_name_show(Actor *actor, char *comment, int data)
{
    DLFTBL_ACTOR	*actor_dlftbl;
    char *actor_name;
    
    actor_dlftbl = (DLFTBL_ACTOR *)actor->dlftbl;
    actor_name = actor_dlftbl_GetSegName(actor_dlftbl);
    if (SREG(5))
    osSyncPrintf("%s:%08x:actor=%08x[%d:%s]\n", comment, data, actor, actor->name, actor_name);
}
#endif

