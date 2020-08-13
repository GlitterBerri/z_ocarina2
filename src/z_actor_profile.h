/*
 * $Id: z_actor_profile.h,v 2.1 1998/10/22 11:45:49 zelda Exp $
 *
 *
 *
 * $Log: z_actor_profile.h,v $
 * Revision 2.1  1998/10/22  11:45:49  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.151  1998/06/26 13:01:07  hayakawa
 * HAYAKAWA_TESTdecl正式採用により削除
 *
 * Revision 1.150  1998-06-15 19:23:34+09  hayakawa
 * HAYAKAWA_TESTdeclの処理だけにしてテスト
 *
 * Revision 1.149  1998-06-11 16:10:36+09  hayakawa
 * decl5追加
 *
 * Revision 1.148  1998-05-27 09:44:29+09  hayakawa
 * decl0の処理がまずかった
 *
 * Revision 1.147  1998-05-14 10:28:39+09  zelda
 * *** empty log message ***
 *
 * Revision 1.146  1998-05-13 10:04:00+09  hayakawa
 * decl0の定義が抜けていた
 *
 * Revision 1.145  1998-04-24 09:58:03+09  hayakawa
 * ワーニング対策
 *
 * Revision 1.144  1998-04-21 22:41:58+09  hayakawa
 * z_actor_dlftbls.declにz_actor_list.hを統合準備
 *
 * Revision 1.143  1998-04-14 17:30:13+09  hayakawa
 * 魔法入れ替えテスト
 *
 * Revision 1.142  1998-03-31 21:40:42+09  hayakawa
 * z_actor_dlftbls.decに一本化
 *
 * Revision 1.141  1998/03/31  11:55:33  yoshida
 * マロン大人追加
 *
 * Revision 1.140  1998/03/30  08:05:11  sumiyosi
 * ＮＰＣ３追加しました。
 *
 * Revision 1.139  1998/03/25  13:59:48  umemiya
 * 氷の洞窟、SPOT06オブジェクトなど追加
 *
 * Revision 1.138  1998/03/25  11:46:43  sumiyosi
 * デクの樹Ｊｒ．追加。
 *
 * Revision 1.137  1998/03/25  03:02:54  komatu
 * *** empty log message ***
 *
 * Revision 1.136  1998/03/23  09:28:39  sakakibara
 * *** empty log message ***
 *
 * Revision 1.135  1998/03/21  09:08:59  sumiyosi
 * 村人しぇあーどばーてっくす版追加。
 *
 * Revision 1.134  1998/03/19  10:31:23  sakakibara
 * *** empty log message ***
 *
 * Revision 1.133  1998/03/19  05:36:01  nisiwaki
 * 双子の老婆
 *
 * Revision 1.132  1998/03/18  13:49:40  yoshida
 * インゴー追加
 *
 * Revision 1.131  1998/03/17  06:19:11  komatu
 * *** empty log message ***
 *
 * Revision 1.130  1998/03/13  04:08:23  umemiya
 * ダイオクタ、カレババ、巨大魚オブジェクト追加
 *
 * Revision 1.129  1998/03/11  11:19:26  takahata
 * *** empty log message ***
 *
 * Revision 1.128  1998/03/10  12:56:26  morita
 * Boss_Mo
 *
 * Revision 1.127  1998/03/10  04:59:06  komatu
 * ナボール追加
 *
 * Revision 1.126  1998/03/09  09:18:16  takahata
 * *** empty log message ***
 *
 * Revision 1.125  1998/03/09  06:40:40  kuzuhara
 * 射的場関連
 *
 * Revision 1.124  1998/03/09  06:16:08  sakakibara
 * ｓｐｏｔ１７  噴煙 追加
 *
 * Revision 1.123  1998/03/09  04:10:50  umemiya
 * 墓下ダンジョン・オブジェクト追加
 *
 * Revision 1.122  1998/03/06  06:33:18  tarukado
 * *** empty log message ***
 *
 * Revision 1.121  1998/03/04  09:35:39  sakakibara
 * *** empty log message ***
 *
 * Revision 1.120  1998/03/04  02:04:08  nisiwaki
 * ミラーシールド効果
 *
 * Revision 1.119  1998/03/03  13:41:14  umemiya
 * ブロッブ追加
 *
 * Revision 1.118  1998/03/03  04:43:44  kuzuhara
 * 兵士２
 * 火山弾発生エンカウント
 * 火山弾
 * 				の作成
 *
 * Revision 1.117  1998/03/02  04:39:45  umemiya
 * 墓下ダンジョン・オブジェクト追加
 *
 * Revision 1.116  1998/02/27  13:54:51  morita
 * *** empty log message ***
 *
 * Revision 1.115  1998/02/27  09:25:49  morita
 * *** empty log message ***
 *
 * Revision 1.114  1998/02/26  13:10:19  sumiyosi
 * フレイムウォーカー追加しました。
 *
 * Revision 1.113  1998/02/25  13:40:04  matutani
 * 宝箱の光
 *
 * Revision 1.112  1998/02/25  09:19:52  komatu
 * *** empty log message ***
 *
 * Revision 1.111  1998/02/24  07:53:32  kuzuhara
 * 敵エンカウントテストの作成
 *
 * Revision 1.110  1998/02/24  04:24:51  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.109  1998/02/23  07:40:22  tarukado
 * デッドハンド＆デッドアーム追加
 *
 * Revision 1.108  1998/02/21  10:51:09  sumiyosi
 * フレイムダンサーの攻撃用炎追加。
 *
 * Revision 1.107  1998/02/21  07:54:29  morita
 * Boss_Fd2
 *
 * Revision 1.106  1998/02/20  10:05:55  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.105  1998/02/20  07:51:22  matutani
 * 魔法（炎、風、氷）
 *
 * Revision 1.104  1998/02/20  04:09:30  umemiya
 * スポット０２オブジェクト、墓追加
 *
 * Revision 1.103  1998/02/19  13:54:13  iwawaki
 * ,
 *
 * Revision 1.102  1998/02/18  02:44:33  matutani
 * 子馬追加
 *
 * Revision 1.101  1998/02/16  09:04:46  sumiyosi
 * フレイムダンサーを追加。
 *
 * Revision 1.100  1998/02/13  03:03:23  nisiwaki
 * En_Duを追加
 *
 * Revision 1.99  1998/02/11  14:04:08  iwawaki
 * *** empty log message ***
 *
 * Revision 1.98  1998/02/10  05:45:16  morita
 * Boss_Fd 追加
 *
 * Revision 1.97  1998/02/09  13:56:56  sumiyosi
 * スタルウォール追加。
 *
 * Revision 1.96  1998/02/09  08:33:13  sakakibara
 * *** empty log message ***
 *
 * Revision 1.95  1998/02/05  12:25:39  umemiya
 * ポウ姉妹イベント用オブジェ追加
 *
 * Revision 1.94  1998/01/31  12:21:45  iwawaki
 * *** empty log message ***
 *
 * Revision 1.93  1998/01/30  03:01:20  umemiya
 * ポウ四姉妹追加
 *
 * Revision 1.92  1998/01/29  11:40:03  tarukado
 * *** empty log message ***
 *
 * Revision 1.91  1998/01/29  02:10:35  kuzuhara
 * 城兵士１をつくりました！
 *
 * Revision 1.90  1998/01/23  04:07:01  umemiya
 * フロアマスター、炎の神殿・炎の壁大追加
 *
 * Revision 1.89  1998/01/22  13:43:53  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.88  1998/01/20  13:11:29  tarukado
 * *** empty log message ***
 *
 * Revision 1.87  1998/01/20  10:27:58  sakakibara
 * *** empty log message ***
 *
 * Revision 1.86  1998/01/20  07:57:11  sumiyosi
 * 墓守・タロン・シークを追加。
 *
 * Revision 1.85  1998/01/19  09:22:11  sakakibara
 * 炎の神殿オブジェクト【ポンプフライヤ】追加
 *
 * Revision 1.84  1998/01/19  05:32:33  tarukado
 * *** empty log message ***
 *
 * Revision 1.83  1998/01/14  05:47:25  tarukado
 * *** empty log message ***
 *
 * Revision 1.82  1998/01/12  09:57:51  sakakibara
 * 炎の神殿・ハンマーステップ追加
 *
 * Revision 1.81  1998/01/09  13:37:15  iwawaki
 * *** empty log message ***
 *
 * Revision 1.80  1998/01/07  02:20:35  sakakibara
 * 炎の神殿・格子追加
 *
 * Revision 1.79  1998/01/05  12:13:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.78  1997/12/24  08:59:01  morita
 * En_Fhg_Fire
 *
 * Revision 1.77  1997/12/24  06:38:50  sumiyosi
 * 大ゼルダ追加
 *
 * Revision 1.76  1997/12/24  05:08:07  umemiya
 * トラップ床ビュン、時の間・マスターソード追加
 *
 * Revision 1.75  1997/12/18  08:25:04  umemiya
 * 時の間・オブジェ追加
 *
 * Revision 1.74  1997/12/17  08:57:46  tarukado
 * *** empty log message ***
 *
 * Revision 1.73  1997/12/17  04:58:51  umemiya
 * 森の神殿・ひねり回廊部屋追加
 *
 * Revision 1.72  1997/12/16  08:33:44  takahata
 * *** empty log message ***
 *
 * Revision 1.71  1997/12/15  10:04:33  matutani
 * ファントムガノン馬
 *
 * Revision 1.70  1997/12/11  09:50:00  iwawaki
 * *** empty log message ***
 *
 * Revision 1.69  1997/12/05  05:25:05  umemiya
 * 水の神殿・動く水面追加
 *
 * Revision 1.68  1997/12/04  09:40:31  umemiya
 * 水の神殿・MOVEBGオブジェ追加
 *
 * Revision 1.67  1997/11/26  07:34:29  umemiya
 * バリ追加
 *
 * Revision 1.66  1997/11/12  08:24:45  umemiya
 * 面クリダンジョンオブジェクト追加
 *
 * Revision 1.65  1997/11/08  08:35:36  umemiya
 * デクナッツ追加
 *
 * Revision 1.64  1997/11/05  14:40:28  iwawaki
 * *** empty log message ***
 *
 * Revision 1.63  1997/10/27  13:46:31  tarukado
 * *** empty log message ***
 *
 * Revision 1.62  1997/10/21  09:11:21  matutani
 * ゼルダ馬
 *
 * Revision 1.61  1997/10/19  12:31:23  iwawaki
 * *** empty log message ***
 *
 * Revision 1.60  1997/10/16  13:54:52  umemiya
 * ドドンゴダンジョン・せりあがり追加
 *
 * Revision 1.59  1997/10/16  08:43:21  sumiyosi
 * En_GirlB→子ゼルダに変更。
 *
 * Revision 1.58  1997/10/04  14:45:38  iwawaki
 * *** empty log message ***
 *
 * Revision 1.57  1997/10/02  13:52:24  umemiya
 * デクババ追加
 *
 * Revision 1.56  1997/10/02  10:18:22  tarukado
 * *** empty log message ***
 *
 * Revision 1.55  1997/10/02  07:56:17  sumiyosi
 * ＮＰＣ追加
 *
 * Revision 1.54  1997/10/01  02:41:52  umemiya
 * *** empty log message ***
 *
 * Revision 1.53  1997/09/30  05:52:51  morita
 * *** empty log message ***
 *
 * Revision 1.52  1997/09/29  13:27:56  umemiya
 * 妖精ダンジョンオブジェクト追加
 *
 * Revision 1.51  1997/09/29  10:56:23  sumiyosi
 * コキリ族の女の子追加
 *
 * Revision 1.50  1997/09/27  14:00:33  umemiya
 * 炎の神殿・フックショット付きリフト追加
 *
 * Revision 1.49  1997/09/26  04:36:23  sumiyosi
 * コキリ族（子供その１）
 *
 * Revision 1.48  1997/09/24  13:45:22  umemiya
 * ザコ兵を一つに統一、炎の神殿・宝箱を守る炎を追加
 *
 * Revision 1.47  1997/09/20  12:41:23  tarukado
 * *** empty log message ***
 *
 * Revision 1.46  1997/09/19  10:34:55  tarukado
 * *** empty log message ***
 *
 * Revision 1.45  1997/09/17  13:54:07  umemiya
 * 跳ね橋、炎のカーテン、追加
 *
 * Revision 1.44  1997/09/17  04:42:19  sumiyosi
 * シーカー族追加
 *
 * Revision 1.43  1997/09/16  08:43:29  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.42  1997/09/12  13:47:20  umemiya
 * 火の神殿オブジェを分割
 *
 * Revision 1.41  1997/09/12  12:30:21  matutani
 * ガノン馬追加
 *
 * Revision 1.40  1997/09/11  07:00:27  umemiya
 * 火の神殿オブジェ追加
 *
 * Revision 1.39  1997/09/10  14:37:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.38  1997/09/06  14:28:17  iwawaki
 * *** empty log message ***
 *
 * Revision 1.37  1997/09/05  09:16:52  sumiyosi
 * デブ（その１）追加
 *
 * Revision 1.36  1997/09/05  08:02:03  matutani
 * 汎用馬
 *
 * Revision 1.35  1997/09/02  12:03:45  umemiya
 * 川音追加
 *
 * Revision 1.34  1997/09/02  06:04:31  umemiya
 * エイヤー追加
 *
 * Revision 1.33  1997/09/01  07:30:21  tarukado
 * *** empty log message ***
 *
 * Revision 1.32  1997/08/30  13:11:18  tarukado
 * *** empty log message ***
 *
 * Revision 1.31  1997/08/26  13:02:57  hayakawa
 * *** empty log message ***
 *
 * Revision 1.30  1997/08/26  04:22:57  hayakawa
 * *** empty log message ***
 *
 * Revision 1.29  1997/08/26  01:09:57  sumiyosi
 * スタルチュラ追加。
 *
 * Revision 1.28  1997/08/25  02:25:47  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.27  1997/08/19  10:48:19  tarukado
 * *** empty log message ***
 *
 * Revision 1.26  1997/08/19  07:30:20  umemiya
 * En_Bili 追加
 *
 * Revision 1.25  1997/08/06  03:23:01  iwawaki
 * *** empty log message ***
 *
 * Revision 1.24  1997/08/04  01:34:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.23  1997/08/01  07:26:49  morita
 * *** empty log message ***
 *
 * Revision 1.22  1997/07/30  01:15:03  tarukado
 * *** empty log message ***
 *
 * Revision 1.21  1997/07/28  14:04:47  iwawaki
 * *** empty log message ***
 *
 * Revision 1.20  1997/07/22  05:52:01  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.19  1997/07/22  00:14:58  iwawaki
 * *** empty log message ***
 *
 * Revision 1.18  1997/07/17  06:57:13  morita
 * *** empty log message ***
 *
 * Revision 1.17  1997/07/09  09:29:39  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.16  1997/07/09  09:25:56  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.15  1997/07/08  01:40:57  iwawaki
 * *** empty log message ***
 *
 * Revision 1.14  1997/07/02  01:51:56  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.13  1997/06/27  09:12:04  tarukado
 * *** empty log message ***
 *
 * Revision 1.12  1997/06/12  00:27:51  iwawaki
 * *** empty log message ***
 *
 * Revision 1.11  1997/06/06  00:48:48  iwawaki
 * *** empty log message ***
 *
 * Revision 1.10  1997/06/05  04:26:24  tarukado
 * *** empty log message ***
 *
 * Revision 1.9  1997/06/04  07:52:46  morita
 * *** empty log message ***
 *
 * Revision 1.8  1997/06/04  07:18:13  tarukado
 * *** empty log message ***
 *
 * Revision 1.7  1997/06/03  05:32:27  tarukado
 * *** empty log message ***
 *
 * Revision 1.6  1997/05/31  13:12:21  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1997/05/24  07:17:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.4  1997/05/22  05:50:12  tarukado
 * *** empty log message ***
 *
 * Revision 1.3  1997/05/20  12:12:12  iwawaki
 * *** empty log message ***
 *
 * Revision 1.2  1997/05/06  07:42:39  iwawaki
 * new
 *
 */

#ifndef INCLUDE_Z_ACTOR_PROFILE_H
#define INCLUDE_Z_ACTOR_PROFILE_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_actor.h"

/************************************************************************
 *
 *	プロフィールＮｏ
 *
 ************************************************************************/
enum profile_e {
#define decl(name) name, 
#define decl0(name1, name2) _filler_ ## name1 ## _filler_,
#define decl1(name1, name2) decl(name1)
#define decl2(name1, name2) decl(name1)
#define decl3(name1, name2) decl(name1)
#define decl4(name1, name2) decl(name1)
#define decl5(name1, name2) decl(name1)
#include "z_actor_dlftbls.decl"
    MaxProfile
#undef decl
#undef decl0
#undef decl1
#undef decl2
#undef decl3
#undef decl4
#undef decl5
};

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
/*** z_actor_profile.h end ***/
