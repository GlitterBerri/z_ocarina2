#!smake
#
# make clobber のあとや、co spec_ovl のあとに以下の make を実行してください
# make genfiles
#
# $Id: Makefile,v 1.8 2003/07/31 18:23:11 wheeler Exp $
#
# ６４ゼルダ用メイクファイル
#
# 通常 nloadバージョンのメイク：make rom_d
# ＲＯＭ焼きバージョンのメイク：make rom_x
# 最終ＲＯＭバージョンのメイク：make rom_f
# ショウバージョンのメイク：make rom_s
# 
#
# make "VMAKEOPT=" ; コンパイル/makeromオプション追加
# make "VMAKEROMOPT=" ; makeromオプション追加
# make "VMAKEOPTION=" ; makeオプション追加
#
#
#
# make -n ; makeすると実行されるコマンドを表示する
#
#
# RAM8Mバージョン：make "RAM8M="
# malloc用ヒープサイズ変更：make "VMAKEOPT=-DSYS_HEAP_SIZE=0x240000"
# fifoサイズ変更：make "VMAKEOPT=-DSYS_FIFO_SIZE=0x2000"
#
# make clean ; rm -rf *.[ou] a.out core lex.yy.[co] y.tab.[cho] _force ar.tmp.*
# make clobber ; 上記に加えて $(TARGETS) MakeDepend をも消す
# make rmtargets ; $(TARGETS) だけを消す
#
# パートナーＮ６４立ち上げ例
# setenv PTSRC ../:/home/hayakawa/prj/PR/libc64/:/home/hayakawa/prj/PR/libu64/:/home/hayakawa/prj/PR/libbg/:/usr/src/PR/libultra/gu/
# ptnet -host partner2 -fn rk24 -jfn k24 -fg white -bg black -width 80 -height 40 /usr/local/partner-net/n64/nptn64 -EUC
#
# z_actor_h.h を触るとどれだけのファイルが影響を受けるかを調べるには
# grep z_actor_h.h rom_d/Makedepend | cut -d: -f1
#
# $Log: Makefile,v $
# Revision 1.8  2003/07/31 18:23:11  wheeler
# Delete unneeded dependency.
#
# Revision 1.7  2003/05/06 21:42:47  tong
# added z_kanfont.c
#
# Revision 1.6  2003/04/30 18:08:06  tong
# added LOCALE==CHINA
#
# Revision 1.5  2003/03/14 23:19:20  tong
# fix "arg list too long" problem for "make clean_f"
#
# Revision 1.4  2003/03/14 05:22:05  tong
# cleaning up rom_f and "make clean_f"
#
# Revision 1.3  2003/03/14 02:53:56  tong
# more source from Nintendo including cheat obj code.
#
# Revision 1.2  2003/03/13 22:33:15  tong
# using Rob's gzip compression
#
# Revision 1.1.1.1  2003/03/10 22:42:51  tong
# new OBJ tree for ocarina from Nintendo
#
# Revision 2.23  2002-05-31 18:48:30+09  zelda
# *** empty log message ***
#
# Revision 2.22  2002-05-28 13:51:47+09  zelda
# *** empty log message ***
#
# Revision 2.21  2002-03-16 21:27:59+09  zelda
# *** empty log message ***
#
# Revision 2.20  2001-06-01 20:12:42+09  zelda
# makemask6105のスキップをしないようにした
#
# Revision 2.19  2001-05-10 14:02:01+09  zelda
# USE_NEW_DUNGEON対応
#
# Revision 2.18  2001-04-04 17:31:59+09  zelda
# SAM_TOOLディレクトリ変更
#
# Revision 2.17  2001-04-04 16:21:47+09  zelda
# ドルフィンエミュレータ用仮ぐみ版 CICと64DD対応部分をはずしたバージョン
#
# Revision 2.16  2000-06-20 11:53:50+09  hayakawa
# 開発バージョン識別
# ほか
#
# Revision 2.15  1999-12-14 14:47:04+09  zelda
# LDIRT追加できるようにした
#
# Revision 2.14  1999-01-07 17:13:19+09  hayakawa
# *** empty log message ***
#
# Revision 2.13  1999-01-07 16:49:35+09  hayakawa
# *** empty log message ***
#
# Revision 2.12  1999-01-07 16:45:10+09  hayakawa
# *** empty log message ***
#
# Revision 2.11  1999-01-07 16:29:55+09  hayakawa
# *** empty log message ***
#
# Revision 2.10  1999-01-07 16:26:18+09  hayakawa
# *** empty log message ***
#
# Revision 2.9  1999-01-07 13:16:21+09  hayakawa
# ゲートウェイシステム対応
#
# Revision 2.8  1999-01-07 10:02:22+09  soejima
# ＧＡＴＥＷＡＹ仕様
#
# Revision 2.7  1998-10-30 16:15:14+09  hayakawa
# *** empty log message ***
#
# Revision 2.6  1998-10-30 15:59:36+09  hayakawa
# *** empty log message ***
#
# Revision 2.5  1998-10-28 09:57:23+09  zelda
# *** empty log message ***
#
# Revision 2.4  1998-10-27 21:37:27+09  hayakawa
# *** empty log message ***
#
# Revision 2.3  1998-10-27 21:22:44+09  soejima
# ＰＡＬ仕様
#
# Revision 2.2  1998-10-27 10:58:40+09  hayakawa
# PAL_VERSION で イニシャルコード変更
#
# Revision 2.1  1998-10-22 20:41:56+09  zelda
# ＲＯＭ出しバージョン(NTSC)
#
# Revision 1.341  1998/10/17 16:20:44  zelda
# *** empty log message ***
#
# Revision 1.340  1998-10-17 20:20:13+09  zelda
# *** empty log message ***
#
# Revision 1.339  1998-10-17 03:01:35+09  zelda
# *** empty log message ***
#
# Revision 1.338  1998-10-15 21:17:21+09  zelda
# *** empty log message ***
#
# Revision 1.337  1998-10-15 17:27:49+09  zelda
# *** empty log message ***
#
# Revision 1.336  1998-10-13 09:37:23+09  hayakawa
# *** empty log message ***
#
# Revision 1.335  1998-10-09 11:05:19+09  hayakawa
# *** empty log message ***
#
# Revision 1.334  1998-10-06 23:13:27+09  hayakawa
# *** empty log message ***
#
# Revision 1.333  1998-10-06 23:11:26+09  hayakawa
# *** empty log message ***
#
# Revision 1.332  1998-10-06 09:26:16+09  hayakawa
# 販売地域の追加
#
# Revision 1.331  1998-10-02 20:31:37+09  hayakawa
# *** empty log message ***
#
# Revision 1.330  1998-09-28 23:23:26+09  hayakawa
# *** empty log message ***
#
# Revision 1.329  1998-09-28 23:15:07+09  hayakawa
# *** empty log message ***
#
# Revision 1.328  1998-09-26 22:52:07+09  hayakawa
# *** empty log message ***
#
# Revision 1.327  1998-09-26 17:38:44+09  hayakawa
# DD_SYNCHRO外した
#
# Revision 1.326  1998-09-26 16:29:18+09  zelda
# ROM_Dではずるモードをオフにした
#
# Revision 1.325  1998-09-25 16:08:33+09  hayakawa
# versum 殺した
#
# Revision 1.324  1998-09-25 11:57:11+09  zelda
# *** empty log message ***
#
# Revision 1.323  1998-09-22 22:05:55+09  hayakawa
# DISK
#
# Revision 1.322  1998-09-15 22:22:55+09  hayakawa
# __NEWを定義
#
# Revision 1.321  1998-09-15 12:00:45+09  zelda
# null → nullsegment
#
# Revision 1.320  1998-09-14 23:01:17+09  hayakawa
# *** empty log message ***
#
# Revision 1.319  1998-09-14 14:50:27+09  zelda
# null セグメント！？
#
# Revision 1.318  1998-09-11 23:12:18+09  zelda
# 一気に圧縮までなだれ込むぜ！！
#
# Revision 1.317  1998-09-09 22:53:11+09  zelda
# 圧縮オプションを -p2 に変更
#
# Revision 1.316  1998-09-07 23:06:51+09  zelda
# *** empty log message ***
#
# Revision 1.315  1998-09-07 10:03:28+09  zelda
# *** empty log message ***
#
# Revision 1.314  1998-09-05 17:12:52+09  hayakawa
# cpptestエントリを追加
# 使用例
# make -k cpptest TARGET=z_std_dma.o
#
# Revision 1.313  1998-09-04 19:24:51+09  zelda
# ROM_F デバッグ
#
# Revision 1.312  1998-09-04 17:33:27+09  hayakawa
# rom_f から DEBUG_MODE_NOINPUT を外した（暫定）
#
# Revision 1.311  1998-09-04 14:49:56+09  hayakawa
# ドライブ存在確認のオブジェクトをリンク
#
# Revision 1.310  1998-09-03 17:02:57+09  zelda
# MAKEFLAGS
# assert
#
# Revision 1.309  1998-09-02 20:46:48+09  zelda
# HAYAKAWA_TESTks2をデフォルトにした！！
#
# Revision 1.308  1998-08-29 17:07:58+09  zelda
# MAKEOPTIONの整理
#
# Revision 1.307  1998-08-28 09:35:07+09  zelda
# 危険かも
#
# Revision 1.306  1998-08-26 21:20:38+09  zelda
# ２コン挿さっていたらずるモード
#
# Revision 1.305  1998-08-26 13:18:26+09  zelda
# バージョンデータに条件コンパイルが反映されるようにした
#
# Revision 1.304  1998-08-26 11:57:15+09  zelda
# パラレルメイクを修正
# ただし、mapファイルが消されたときに自動生成できなくなった
#
# Revision 1.303  1998-08-25 16:50:37+09  hayakawa
# *** empty log message ***
#
# Revision 1.302  1998-08-25 16:45:55+09  hayakawa
# 緊急対策その１
#
# Revision 1.301  1998-08-25 11:16:38+09  hayakawa
# *** empty log message ***
#
# Revision 1.300  1998-08-25 10:05:10+09  hayakawa
# genfilesでエラーが出る可能性を修正
#
# Revision 1.299  1998-08-24 20:11:10+09  hayakawa
# z_segment.declテスト
#
# Revision 1.298  1998-08-24 20:02:06+09  zelda
# *** empty log message ***
#
# Revision 1.297  1998-08-22 20:54:07+09  zelda
# zelda.nm1も吐くようにした
#
# Revision 1.296  1998-08-21 23:19:20+09  hayakawa
# *** empty log message ***
#
# Revision 1.295  1998-08-21 17:27:53+09  hayakawa
# CIC6105を一時的にオフにした
#
# Revision 1.294  1998-08-21 09:35:16+09  zelda
# touch_z_actor_dlftbls.decl
#
# Revision 1.293  1998-08-19 22:54:27+09  hayakawa
# CIC6105チェックモード
#
# Revision 1.292  1998-08-18 21:55:53+09  hayakawa
# *** empty log message ***
#
# Revision 1.291  1998-08-18 21:23:58+09  hayakawa
# ROM_D ROM_X で USE_COUNT= をデフォルトにしてみた
#
# Revision 1.290  1998-08-17 21:57:43+09  hayakawa
# versum
#
# Revision 1.289  1998-08-13 21:48:33+09  hayakawa
# *** empty log message ***
#
# Revision 1.288  1998-08-13 12:11:17+09  zelda
# spec.i
#
# Revision 1.287  1998-08-12 22:47:12+09  hayakawa
# *** empty log message ***
#
# Revision 1.286  1998-08-11 13:32:36+09  zelda
# 条件コンパイル変更
#
# Revision 1.285  1998-08-07 21:46:24+09  hayakawa
# なんと今だけ！！
#
# Revision 1.284  1998-08-05 21:44:13+09  hayakawa
# *** empty log message ***
#
# Revision 1.283  1998-08-04 11:24:21+09  zelda
# szsキャッシュ
#
# Revision 1.282  1998-08-01 14:54:08+09  zelda
# エラー修正
#
# Revision 1.281  1998-08-01 13:51:04+09  zelda
# *** empty log message ***
#
# Revision 1.280  1998-07-28 20:12:04+09  zelda
# ISVのライブラリを最新を使用するように変更
#
# Revision 1.279  1998-07-23 22:13:26+09  hayakawa
# *** empty log message ***
#
# Revision 1.278  1998-07-23 09:34:31+09  hayakawa
# NOUSE_PRINTF
#
# Revision 1.277  1998-07-21 11:30:27+09  hayakawa
# 古い gfxprint.o をリンクしていた
#
# Revision 1.276  1998-07-17 21:37:27+09  hayakawa
# driverominit.oが２つのライブラリに存在するので削除した
#
# Revision 1.275  1998-07-16 17:05:43+09  hayakawa
# オーディオライブラリが debug_audio.o と audio.o に分離
#
# Revision 1.274  1998-07-15 22:39:28+09  hayakawa
# *** empty log message ***
#
# Revision 1.273  1998-07-15 22:32:16+09  hayakawa
# *** empty log message ***
#
# Revision 1.272  1998-07-10 13:56:55+09  hayakawa
# fullcourse2 のときに 圧縮キャッシュの保存に失敗していたので対処してみた
#
# Revision 1.271  1998-07-07 20:16:26+09  hayakawa
# cleanboot
#
# Revision 1.270  1998-07-07 19:51:05+09  hayakawa
# leoemu対応（実験中）
# makemaskしないように戻した
#
# Revision 1.269  1998-07-07 11:54:59+09  umemiya
# ツール用にSCENE_TOOLとSCENE_TOOL2を追加
#
# Revision 1.268  1998-07-06 21:08:58+09  hayakawa
# makemask を再び自動でやるように変更
#
# Revision 1.267  1998-06-30 22:38:14+09  hayakawa
# MAKEOPTION = USE_CIC6105_NOCHECK= USE_N64DD= HAYAKAWA_TESTdd=
# を設定
#
# Revision 1.266  1998-06-29 14:01:56+09  hayakawa
# *** empty log message ***
#
# Revision 1.265  1998-06-26 21:40:12+09  hayakawa
# HAYAKAWA_TESTdecl,HAYAKAWA_TESTamf,USE_PRERENDER正式採用により削除
#
# Revision 1.264  1998-06-25 22:10:16+09  hayakawa
# MFSは使いそうもないので削除
#
# Revision 1.263  1998-06-24 22:52:09+09  hayakawa
# cleanboot追加
#
# Revision 1.262  1998-06-22 22:16:17+09  hayakawa
# GAME_PLAY追加テスト用
#
# Revision 1.261  1998-06-19 21:19:36+09  hayakawa
# HAYAKAWA_TESTdd
#
# Revision 1.260  1998-06-15 15:28:18+09  hayakawa
# USE_CIC6105_NOCHECK をデフォルトにした
#
# Revision 1.259  1998-06-15 09:24:22+09  hayakawa
# gfxprint.o が個人のディレクトリを指したままだった。御免！
#
# Revision 1.258  1998-06-12 19:33:31+09  zelda
# Revision 1.257  1998-06-12 17:22:13+09  zelda
# F3DZEX2をデフォルトにした
#
# Revision 1.256  1998-06-12 13:29:56+09  zelda
# HAYAKAWA_TESTdecl	ON
#
# Revision 1.255  1998-06-11 22:13:30+09  zelda
# *** empty log message ***
#
# Revision 1.254  1998-06-11 16:11:12+09  hayakawa
# S2DEX 1.07 テスト
#
# Revision 1.253  1998-06-10 19:16:38+09  zelda
# trapuvをはずすのは ROM_F にした
#
# Revision 1.252  1998-06-10 13:41:57+09  hayakawa
# *** empty log message ***
#
# Revision 1.251  1998-06-08 21:38:26+09  hayakawa
# デバッグマロック＆ロケール定義
#
# Revision 1.250  1998-06-05 16:47:00+09  hayakawa
# cleanboot関係更新
#
# Revision 1.249  1998-06-04 22:38:39+09  hayakawa
# 64DD関係
#
# Revision 1.248  1998-05-29 15:27:05+09  hayakawa
# *** empty log message ***
#
# Revision 1.247  1998-05-28 14:23:17+09  zelda
# *** empty log message ***
#
# Revision 1.246  1998-05-27 22:52:00+09  zelda
# WOOOOOOH
#
# Revision 1.245  1998-05-27 15:08:55+09  hayakawa
# 条件コンパイル整理
#
# Revision 1.244  1998-05-27 10:11:22+09  zelda
# 大失敗
#
# Revision 1.243  1998-05-20 22:49:50+09  hayakawa
# 64DD
#
# Revision 1.242  1998-05-19 10:28:57+09  hayakawa
# MAKEMASK6103が勝手に動くのを修正
#
# Revision 1.241  1998-05-18 21:41:14+09  hayakawa
# ディレクトリ間違いを修正
#
# Revision 1.240  1998-05-18 20:16:08+09  hayakawa
# *** empty log message ***
#
# Revision 1.239  1998-05-18 14:35:07+09  hayakawa
# makemaskは手でやってください
#
# Revision 1.238  1998-05-18 13:43:19+09  hayakawa
# *** empty log message ***
#
# Revision 1.237  1998-05-18 13:20:07+09  hayakawa
# 6103用
# make rom_f MAKEOPTION=USE_CIC6103=
#
# Revision 1.236  1998-05-18 09:44:52+09  hayakawa
# ショウバージョン修正
#
# Revision 1.235  1998-05-15 14:28:17+09  hayakawa
# Ｃ＋＋バージョン追加
#
# Revision 1.234  1998-05-14 17:44:27+09  hayakawa
# リンクのコマンドが nld になってなかったのを修正
#
# Revision 1.233  1998-05-14 09:22:29+09  hayakawa
# fullcourse* のときに MAKEOPTION を渡さないようにした
#
# Revision 1.232  1998-05-13 10:16:16+09  hayakawa
# 勘違い
#
# Revision 1.231  1998-05-12 20:16:14+09  zelda
# *** empty log message ***
#
# Revision 1.230  1998-05-12 20:02:17+09  zelda
# *** empty log message ***
#
# Revision 1.229  1998-05-12 19:13:22+09  zelda
# z_actor_dlftbls.decl 統合化
#
# Revision 1.228  1998-05-08 21:36:50+09  hayakawa
# *** empty log message ***
#
# Revision 1.227  1998-05-08 15:36:48+09  hayakawa
# Revision 1.226  1998-05-08 09:52:59+09  hayakawa
# fullcourse3追加
# camera → camera_params
#
# Revision 1.225  1998-05-06 21:38:56+09  hayakawa
# zelda_f.mapエントリ修正
#
# Revision 1.224  1998-05-01 20:00:12+09  zelda
# *** empty log message ***
#
# Revision 1.223  1998-05-01 13:20:29+09  hayakawa
#* if USE_ を ifdef USE_ に変更
# _ODEBUGを取りあえずROM_FでもＯＮにした
#
# Revision 1.222  1998-05-01 11:39:18+09  hayakawa
# ROM_Fバージョン
#
# Revision 1.221  1998-05-01 11:15:03+09  hayakawa
# ROM_D,ROM_Xをマクロに反映
# マップ用エントリ追加
#
# Revision 1.220  1998-04-30 22:53:04+09  hayakawa
# USE_DEBUG_MOJI
#
# Revision 1.219  1998-04-30 21:05:23+09  hayakawa
# ６４ＤＤ用マクロ設定
# zelda.map修正
#
# Revision 1.218  1998-04-28 21:40:45+09  hayakawa
# S2DEX 1.07 対策
#
# Revision 1.217  1998-04-28 21:27:20+09  hayakawa
# 64DD条件コンパイル
# S2DEX 1.07 対策
#
# Revision 1.216  1998-04-27 20:19:42+09  hayakawa
# CICの条件マクロ変更
#
# Revision 1.215  1998-04-24 17:51:43+09  hayakawa
#
# Revision 1.214  1998-04-24 11:48:49+09  hayakawa
# fullcourse2において、圧縮キャッシュの内容を保存するようにした
#
# Revision 1.213  1998-04-23 23:03:07+09  hayakawa
# 64DD関係修正
#
# Revision 1.212  1998-04-22 22:24:32+09  hayakawa
# MFSをデフォルトからはずした
#
# Revision 1.211  1998-04-21 22:45:52+09  hayakawa
# 64DD用変更など
#
# Revision 1.210  1998-04-16 21:02:27+09  hayakawa
# 64DD対応その１
#
# Revision 1.209  1998-04-14 17:35:37+09  hayakawa
# MFS（マルチファイルシステム用コード追加）
#
# Revision 1.208  1998-04-10 11:31:03+09  hayakawa
# じょうけんはずし
# いろいろ
#
# Revision 1.207  1998/03/25  13:24:21  hayakawa
# genfiles:に camera camera_params を追加
# _AUDIO_GAME_PRINT_がついているとおかしくなるのではずした
# make depend のテスト
#
# Revision 1.206  1998/03/23  09:36:30  hayakawa
# *** empty log message ***
#
# Revision 1.205  1998/03/19  09:04:58  hayakawa
# コンパイルできなくなっていたのを修正
#
# Revision 1.204  1998/03/19  07:16:22  hayakawa
# bug fix
#
# Revision 1.203  1998/03/18  08:01:44  hayakawa
# factor5対応
#
# Revision 1.202  1998/03/18  02:37:51  hayakawa
# *** empty log message ***
#
# Revision 1.201  1998/03/16  06:34:11  hayakawa
# PARALLEL= としない限り並列コンパイルしないようにした
# Ｃ＋＋テスト
#
# Revision 1.200  1998/03/13  09:40:12  hayakawa
# *** empty log message ***
#
# Revision 1.199  1998/03/13  07:18:47  hayakawa
# *** empty log message ***
#
# Revision 1.198  1998/03/13  06:09:16  hayakawa
# rom_xで設定が甘い
#
# Revision 1.197  1998/03/12  11:19:45  hayakawa
# オーバーレイの登録を spec_ovl.dat に移した。
# 今後オーバーレイのは spec_ovl.dat に行ってください。
#
# Revision 1.196  1998/03/12  11:13:34  hayakawa
# オーバーレイの登録を spec_ovl.dat に移した。
# 今後オーバーレイのは spec_ovl.dat に行ってください。
#
# Revision 1.195  1998/03/10  12:02:04  hayakawa
# *** empty log message ***
#
# Revision 1.194  1998/03/09  12:31:04  hayakawa
# *** empty log message ***
#
# Revision 1.193  1998/03/06  11:57:40  hayakawa
# MAKEOPTION対応
# RAM8M=をデフォルトにしてみました
#
# Revision 1.192  1998/03/06  10:25:59  hayakawa
# # # メモリ節約に関係ありそうなワーニングを出すようにしました。
# # # みなさん、ワーニングが綺麗になくなるように努力してください。
# # # 近々、あの Warning 827 も復活します。ご期待下さい！
#
# デバッグ
#
# Revision 1.191  1998/03/06  09:55:36  hayakawa
# # メモリ節約に関係ありそうなワーニングを出すようにしました。
# # みなさん、ワーニングが綺麗になくなるように努力してください。
# # 近々、あの Warning 827 も復活します。ご期待下さい！
#
# ROM_Xのときに-O3にした
#
# Revision 1.190  1998/03/06  09:29:35  hayakawa
# メモリ節約に関係ありそうなワーニングを出すようにしました。
# みなさん、ワーニングが綺麗になくなるように努力してください。
# 近々、あの Warning 827 も復活します。ご期待下さい！
#
# Revision 1.189  1998/03/06  08:56:31  hayakawa
# ROM_Xテスト
#
# Revision 1.188  1998/03/06  04:55:24  hayakawa
# カレイドスコープ領域入れ替え第二弾の準備
#
# Revision 1.187  1998/03/06  01:39:57  hayakawa
# 動的ボリュームカリングとポリゴン数カウント関数をはずして１５Ｋバイトほど減らした
# これとは別にライブラリの見直しにより１０Ｋバイトほど減らしている
#
# Revision 1.186  1998/03/05  06:09:10  hayakawa
# 森田さんの希望により zelda_press 終了時に音がなるようにした
#
# Revision 1.185  1998/03/03  04:53:57  hayakawa
# パラレル実験2
#
# Revision 1.184  1998/03/03  04:32:19  hayakawa
# パラレル実験
#
# Revision 1.183  1998/02/26  00:54:58  hayakawa
# *** empty log message ***
#
# Revision 1.182  1998/02/26  00:54:04  hayakawa
# romPP
#
# Revision 1.181  1998/02/25  11:49:38  hayakawa
# make -n ; makeすると実行されるコマンドを表示する
# TARGETS = romPP_d
#
# Revision 1.180  1998/02/23  02:59:49  hayakawa
# *** empty log message ***
#
# Revision 1.179  1998/02/23  02:56:02  hayakawa
# 圧縮をカレントディレクトリで作業するように変更
# make clean のエラー対策？
#
# Revision 1.178  1998/02/20  08:48:56  hayakawa
# zelda_pressタイミング変更
#
# Revision 1.177  1998/02/20  05:18:14  hayakawa
#
# Revision 1.176  1998/02/20  01:44:50  hayakawa
# zelda_pressするタイミングを変更
# make clean で圧縮ファイル関係も削除
#
# Revision 1.175  1998/02/13  09:09:24  hayakawa
# RAM8M変更
# メイクの開始を速くなるようにした
# z_segment_decl.cが自動的に作成されるようにした？つもり
#
# Revision 1.174  1998/01/29  02:22:28  hayakawa
# C64LIB_FULLPATHが間違っていたのを修正
# nus関係を整理統合
# リダイレクトファイルの拡張子を .out から .stdout に変更
#
# Revision 1.173  1998/01/20  00:45:01  hayakawa
# GCC対応テスト（未テスト）
#
# Revision 1.172  1998/01/09  09:17:58  hayakawa
# *** empty log message ***
#
# Revision 1.171  1997/12/12  07:58:20  hayakawa
# stackcheck問題打開のために、libc64 libu64もbootsegmentに組み込めるようにした
#
# Revision 1.170  1997/11/21  08:40:03  hayakawa
# LIBNOS排除
#
# Revision 1.169  1997/11/20  06:49:36  hayakawa
# USE_IRQMGRをデフォルトにした
#
# Revision 1.168  1997/11/19  06:28:48  hayakawa
# SHOW_VERSIONの設定マクロ追加
# cleanbootをSHOW_VERSIONに対応
#
# Revision 1.167  1997/11/19  04:14:52  hayakawa
# *** empty log message ***
#
# Revision 1.166  1997/11/18  09:02:56  hayakawa
# ショウバージョンのメイク：make rom_d NODEFAULT= ROM_ROM= SHOW_VERSION=
#
# Revision 1.165  1997/11/18  08:35:42  hayakawa
# デバッグレジスタを出さない
#
# Revision 1.164  1997/11/15  11:29:35  hayakawa
# ログコメント一部削除
# ソース整理
#
# Revision 1.163  1997/11/05  13:59:19  ogawa
# *** empty log message ***
#
# Revision 1.162  1997/11/05  11:43:02  ogawa
# DRAM8Mのまちがい
#
# Revision 1.161  1997/11/05  11:11:07  ogawa
# ROM8M
#
# Revision 1.160  1997/11/01  06:38:24  hayakawa
# *** empty log message ***
#
# Revision 1.159  1997/10/29  14:00:55  hayakawa
# *** empty log message ***
#
# Revision 1.158  1997/10/27  14:04:11  hayakawa
# 標準関数ライブラリ修正
#
# Revision 1.157  1997/10/23  13:42:16  hayakawa
# 標準関数ライブラリ
#
# Revision 1.156  1997/10/17  14:06:52  hayakawa
# 条件コンパイル変更
#
# Revision 1.155  1997/10/16  12:43:55  umemiya
# *** empty log message ***
#
# Revision 1.154  1997/10/16  11:13:59  hayakawa
# z_segment_decl.cの規則
# その他
#
# Revision 1.153  1997/10/11  02:51:36  hayakawa
# count.oの位置変更
#
# Revision 1.152  1997/10/08  14:19:42  hayakawa
# gload用のファイルをつくらないようにした
#
# Revision 1.151  1997/10/08  10:22:01  soejima
# kanrom.s を kan.s に変更
#
# Revision 1.150  1997/10/03  14:12:37  hayakawa
# zelda_pressオプション変更
#
# Revision 1.149  1997/09/12  07:22:51  hayakawa
# オーディオエラー対策他
#
# Revision 1.148  1997/09/10  11:01:18  hayakawa
# rommap_new導入
#
# Revision 1.147  1997/09/06  06:33:16  hayakawa
# *** empty log message ***
#
# Revision 1.146  1997/09/06  05:42:33  hayakawa
# おろかぶ外した
#
# Revision 1.145  1997/09/05  14:03:35  hayakawa
# coallエントリ追加
# error_playのテスト
#
# Revision 1.144  1997/08/30  05:24:20  hayakawa
# *** empty log message ***
#
# Revision 1.143  1997/08/27  09:27:00  hayakawa
# *** empty log message ***
#
# Revision 1.142  1997/08/27  04:50:40  hayakawa
# 細かく修正
#
# Revision 1.141  1997/08/26  13:03:58  hayakawa
# *** empty log message ***
#
# Revision 1.140  1997/08/26  01:16:03  hayakawa
# ISVIEWERをデフォルトのモードにした
# makerom失敗時にnmxを実行するようにした
#
# Revision 1.139  1997/08/25  13:53:34  hayakawa
# ROM_ROMモード
#
# Revision 1.138  1997/08/23  08:36:53  hayakawa
# *** empty log message ***
#
# Revision 1.137  1997/08/21  02:57:39  hayakawa
# IS-VIEWER用
#
# Revision 1.136  1997/08/20  10:59:04  hayakawa
# オーディオデータが変わったときに makerom するようにした
#
# Revision 1.135  1997/08/19  09:41:23  hayakawa
# Revision 1.134  1997/08/19  01:59:48  hayakawa
# Revision 1.133  1997/08/18  12:47:06  hayakawa
# Revision 1.132  1997/08/12  13:59:26  hayakawa
# *** empty log message ***
#
# Revision 1.131  1997/08/09  08:15:29  hayakawa
# Revision 1.130  1997/08/08  11:10:12  ogawa
# camera.zdb chmod自動化
#
# Revision 1.129  1997/08/08  11:08:50  ogawa
# *** empty log message ***
#
# Revision 1.128  1997/08/07  12:38:43  ogawa
# もうちょっと変更
#
# Revision 1.127  1997/08/07  11:20:32  ogawa
# camera.zdbコピー元ちょい変更
#
# Revision 1.126  1997/08/07  10:56:56  ogawa
# camera.zdb ../data/cameraはやめ
#
# Revision 1.125  1997/08/07  10:07:53  hayakawa
# ../data/cameraの自動生成（仮）
# cleanで.relとか消すようにした
# dma_makeを起動できるようにした
# など
#
# Revision 1.124  1997/08/04  13:30:10  ogawa
# makecamera修正
#
# Revision 1.123  1997/08/04  13:27:24  hayakawa
# makeromでエラーになっていたのを修正
# 分散コンパイルテスト
#
# Revision 1.122  1997/07/31  08:09:49  hayakawa
# playのオーバーレイテスト
#
# Revision 1.121  1997/07/31  02:59:44  hayakawa
# ディレクトリ関係を強化
# 分散コンパイルテスト
#
# Revision 1.120  1997/07/29  10:59:45  hayakawa
# ワーニングテスト
#
# Revision 1.119  1997/07/22  00:00:48  hayakawa
# Revision 1.118  1997/07/17  04:59:19  hayakawa
# CAMPARAMHの依存リストを削除
#
# Revision 1.117  1997/07/16  06:49:12  ogawa
# camera_param_data.hに関する処理
#
# Revision 1.116  1997/07/16  05:35:51  hayakawa
# LMAKEROMOPT,VMAKEROMOPT導入
#
# Revision 1.115  1997/07/15  09:14:18  hayakawa
# LMAKEOPT += "-DUSE_PRERENDER"を追加
#
# Revision 1.114  1997/07/04  04:56:54  ogawa
# camera関連づけ切断
#
# Revision 1.113  1997/07/02  08:23:38  ogawa
# 各ユーザー別の定義マクロ U_${USER}_U を追加
# make scene の追加
#
# Revision 1.112  1997/07/02  05:48:06  ogawa
# camera関係の変更
# データベースを/project以下に移動
#
# Revision 1.111  1997/07/01  12:29:55  ogawa
# *** empty log message ***
#
# Revision 1.110  1997/07/01  06:03:25  ogawa
# *** empty log message ***
#
# Revision 1.109  1997/07/01  05:09:53  ogawa
# カメラデータベース追加
#
# Revision 1.108  1997/07/01  01:36:01  hayakawa
# 吉田君のコンパイル終了時に天才バカボンが動かないようにした
# IRIX6.2のコンパイルに対応
# データのメイクを変更
#
# Revision 1.107  1997/06/19  12:16:11  hayakawa
# HAYAKAWA_LIB時のディレクトリが正しくなかった
#
# Revision 1.106  1997/06/18  11:38:52  hayakawa
# *** empty log message ***
#
# Revision 1.105  1997/06/18  06:39:25  hayakawa
# 終了音補完計画
#
# Revision 1.104  1997/06/18  04:28:03  iwawaki
# *** empty log message ***
#
# Revision 1.103  1997/06/17  12:50:15  iwawaki
# *** empty log message ***
#
# Revision 1.102  1997/06/17  12:44:17  iwawaki
# *** empty log message ***
#
# Revision 1.101  1997/06/17  08:38:06  iwawaki
# *** empty log message ***
#
# Revision 1.100  1997/06/05  07:24:09  hayakawa
# パートナー環境変更
# データ作成時にobj1も呼ぶようにした
#
# Revision 1.99  1997/05/30  01:07:08  hayakawa
#
# Revision 1.98  1997/05/29  08:13:40  soejima
#
# Revision 1.97  1997/05/29  06:57:35  soejima
#
# Revision 1.96  1997/05/29  06:41:44  hayakawa
# コメント修正
#
# Revision 1.95  1997/05/29  01:20:20  hayakawa
# gdisですべてのセグメントを対象にするように変更
#
# Revision 1.94  1997/05/28  06:24:26  hayakawa
# オーディオのディレクトリを正規の場所に変更
# make data に keepの実行を追加
#
# Revision 1.93  1997/05/27  12:13:49  hayakawa
# version.oの生成方法を変更
#
# Revision 1.92  1997/05/26  11:58:11  hayakawa
# make dataからshape_allを外した
# make_versionの方法を修正
#
# Revision 1.91  1997/05/26  10:46:18  hayakawa
# make data を新マップに対応
#
# Revision 1.90  1997/05/24  09:13:47  hayakawa
# version.oの強制自動生成
#
# Revision 1.89  1997/05/22  02:12:52  hayakawa
# 新オーディオ対応
#
# Revision 1.88  1997/05/21  04:54:21  hayakawa
# エラーになったのでSPECFILEとSPEC_INCLUDEを分けた
#
# Revision 1.87  1997/05/21  04:47:24  hayakawa
# spec.audioがsepc.audioになっていた
#
# Revision 1.86  1997/05/21  04:42:33  hayakawa
#
# Revision 1.85  1997/05/14  11:46:07  soejima
# ＩＳ用ｇｄｉｓ セット
#
# Revision 1.84  1997/05/13  09:06:28  hayakawa
# ８ＭＲＡＭ用のコメントを追加
#
# Revision 1.83  1997/05/13  08:29:38  soejima
# is_rom入荷（ＩＳデバッカー用）
#
# Revision 1.82  1997/05/13  05:52:40  hayakawa
# MAKEROMOPTから -d を取った
# IRIX6.2でのldがうまく動かない対策
#
# Revision 1.81  1997/04/16  11:39:31  hayakawa
# clean用エントリ追加
#
# Revision 1.80  1997/04/15  00:14:48  hayakawa
# HAYAKAWA_LIB時のディレクトリ修正
#
# Revision 1.79  1997/04/10  00:56:10  hayakawa
# tmplib.aのパーミッションエラー対策
#
# Revision 1.78  1997/03/29  12:32:32  hayakawa
# makeromオプションに-I$(ZELDA_ROOT)を追加
#
# Revision 1.77  1997/03/27  12:30:55  hayakawa
# USE_PRERENDERはifdefにかえた
# ウルトラライブラリを標準にした
# ultralib2.aの変更
# フォルトライブラリ変更
# あと、いろいろ
#
# Revision 1.76  1997/03/26  04:47:13  hayakawa
# ROM_VERSION用修正
#
# Revision 1.75  1997/03/25  06:04:55  hayakawa
# データファイルが新しくなったときにも反応するようにした
#
# Revision 1.74  1997/03/21  09:16:58  hayakawa
# make fullcourse のときにオプションが渡らなかった
#
# Revision 1.73  1997/03/18  04:53:12  hayakawa
# /usr/bin/ar と /usr/local/bin/ar の挙動が違うのに対策？
#
# Revision 1.72  1997/03/18  01:30:00  hayakawa
# ARの定義をincludeの後ろに持っていった
#
# Revision 1.71  1997/03/18  01:20:44  hayakawa
# /usr/local/bin/arが使われるようにした
#
# Revision 1.70  1997/03/18  01:12:31  hayakawa
# ultralib2.aの中間ファイルの名前を変えた
# cleanallの消すファイルの種類を増やした
#
# Revision 1.69  1997/03/17  12:25:49  hayakawa
# ブートセグメント対応
# libbg関係を削除
# SOUND関係を削除
#
# Revision 1.68  1997/03/17  00:52:31  hayakawa
# bootセグメントの独立用の変更
#
# Revision 1.67  1997/03/13  11:31:13  hayakawa
# コントローラパックメニュー対応
# zelda.gdis無条件実行
#
# Revision 1.66  1997/03/07  08:35:40  hayakawa
# VMAKEOPTが子プロセスのmakeに渡るようにした
#
# Revision 1.65  1997/02/17  05:01:47  hayakawa
# volcull用
#
# Revision 1.64  1997/02/14  01:57:14  hayakawa
# rom_romのときにROM_VERSION=をつけた
#
# Revision 1.63  1997/02/12  07:12:29  hayakawa
# *** empty log message ***
#
# Revision 1.62  1997/02/07  12:18:55  hayakawa
# プリレンダーモードをはずせるようにした
#
# Revision 1.61  1997/02/06  07:20:56  hayakawa
# メイクオプションの渡し型を変更
#
# Revision 1.60  1997/02/05  10:03:31  hayakawa
# ポリゴン数カウント追加
# パートナー用変更
#
# Revision 1.59  1997/01/24  06:14:07  hayakawa
# LCDEFSをLMAKEOPTに変更
# PARTNERの変更
#
# Revision 1.58  1997/01/20  05:19:05  hayakawa
# zelda.gdisの生成方法を修正
#
# Revision 1.57  1997/01/13  11:54:50  hayakawa
# 逆アセンブル修正
# HAYAKAWA_LIBモード追加
#
# Revision 1.56  1997/01/10  07:22:53  hayakawa
# ldでリンクするときにマップを出力するようにした
#
# Revision 1.55  1997/01/09  11:56:26  hayakawa
# ROM用バージョンとデバッグバージョンの並列作成を可能にした
#
# Revision 1.54  1997/01/06  07:42:36  hayakawa
# ＲＯＭバージョンのメイクのしかたを変更
# 共通メイクの導入
#
# Revision 1.53  1996/12/19  02:40:58  hayakawa
# いろいろ変更ROM
#
# Revision 1.52  1996/12/17  04:27:06  hayakawa
# データメイク変更
#
# Revision 1.51  1996/12/05  08:44:34  hayakawa
# とりあえずＲＯＭバージョンができるように
#
# Revision 1.50  1996/12/05  07:31:46  hayakawa
# ROM TEST
#
# Revision 1.49  1996/12/04  05:24:00  hayakawa
# COMMON_DIRを追加
# libC.c++を削除
# -DDEBUG_CAMERAを追加
#  -lu64_d -lc64_dを追加
#
# Revision 1.48  1996/11/19  01:07:16  hayakawa
# 標準ライブラリlibc.aをリンクしないようにした
# タグファイルに/usr/local/srd/PR/*.hを追加した
#
# Revision 1.47  1996/11/16  08:47:08  hayakawa
# デバッグ時のオプティマイズレベルを１にしてみた
# フォックスの音楽データの形式が変わったのでマリオの音楽に戻した
# エントリ gload を追加。コンパイル即実行が可能になった。
# エントリ data を追加。いちいちデータディレクトリに移動したりしなくてよくなった
#
# Revision 1.46  1996/11/07  07:04:28  soejima
# 第１水準フォント アンチエイリアス付 kanrom.o
# 		 アンチエイリアス無 kanrom2.o
#
# Revision 1.45  1996/11/06  11:34:21  soejima
# *** empty log message ***
#
# Revision 1.44  1996/11/06  08:39:03  iwawaki
# *** empty log message ***
#
# Revision 1.43  1996/11/04  10:07:47  hayakawa
# カバレッジ可視化
#
# Revision 1.42  1996/11/01  09:19:30  hayakawa
# システムヒープ領域を外部に設定
# 標準Ｃライブラリをリンク
#
# Revision 1.41  1996/10/30  04:33:56  iwawaki
# z_hilete.cとz_lookat.c追加
#
# Revision 1.40  1996/10/28  09:07:54  hayakawa
# コメント追加
# フォックスサウンドデータが出る
#
# Revision 1.39  1996/10/27  08:53:30  hayakawa
# 条件コンパイルNOUSE_PRINTFの追加
#
# Revision 1.38  1996/10/25  11:58:32  hayakawa
# csleep用にlibbg_d.aをリンク
#
# Revision 1.37  1996/10/24  06:29:56  hayakawa
# 大幅修正
#
# Revision 1.36  1996/10/21  04:48:14  iwawaki
# *** empty log message ***
#
# Revision 1.35  1996/10/21  04:46:28  iwawaki
# *** empty log message ***
#
# Revision 1.34  1996/10/21  02:57:10  iwawaki
# normalize.o追加
#
# Revision 1.33  1996/10/16  05:36:28  hayakawa
# ３部のマイクロコードを使用する
# マップをファイルに吐くようにした
#
# Revision 1.32  1996/10/12  08:08:40  hayakawa
# smakeバージョンに変更した
# CFILESの定義をMakefile.CFILESに移した
# リンクするオブジェクトを増やした
# rom版のメイクができるようにした
# disk(partner)版のメイクができるようにした
# 不要なエントリの削除
# リンクのやり直しやmakeromのやり直しができるようにした
#
# Revision 1.31  1996/10/10  12:55:45  soejima
# z_kscope.c入荷
#
# Revision 1.30  1996/10/10  11:56:43  hayakawa
# ボリュームカリングデータ自動作成ライブラリを追加
#
# Revision 1.29  1996/10/09  06:20:47  soejima
# z_libliblib.c入荷
#
# Revision 1.28  1996/10/08  12:37:17  soejima
# z_parameter.c入荷
#
# Revision 1.27  1996/10/08  07:04:32  sasaki
# ファイルの追加
#
# Revision 1.26  1996/10/08  06:06:27  hayakawa
# オーディオ用のマクロの追加
#
# Revision 1.25  1996/10/07  11:43:19  hayakawa
# 新しいオーディオに対応
#
# Revision 1.24  1996/10/05  09:22:35  hayakawa
# patchディレクトリ対応
#
# Revision 1.23  1996/10/02  06:16:07  soejima
# message入荷
#
# Revision 1.22  1996/09/28  11:13:25  iwawaki
# z_skelanime.c追加
#
# Revision 1.21  1996/09/27  10:55:11  iwawaki
# カメラ用地形チェック追加
#
# Revision 1.20  1996/09/27  05:08:21  soejima
# *** empty log message ***
#
# Revision 1.19  1996/09/27  04:59:50  hayakawa
# 不要なソースをはずした
#
# Revision 1.18  1996/09/25  13:02:35  soejima
# *** empty log message ***
#
# Revision 1.17  1996/09/25  12:31:16  hayakawa
# *** empty log message ***
#
# Revision 1.16  1996/09/24  12:48:38  matutani
# *** empty log message ***
#
# Revision 1.15  1996/09/24  11:25:19  hayakawa
# 速度計に対応
#

#ifndef LOCALE
LOCALE = CHINA
#endif

#ifndef PARALLEL
.NOTPARALLEL:				# 並列動作を禁止
#endif
.PATH: ..				# rom_?ディレクトリからソースを見るため
.SUFFIXES :				# メイク開始までの化時間短縮
##.SUFFIXES : .c .h .s .o .i		# 必要なサフィックス	# HIRATSU Daisuke invalidated this line.
.SUFFIXES : .h .s .o .i						# HIRATSU Daisuke modified this line.

## 標準関数ライブラリ
N64KITDIR    = /usr/local/n64kit
NUSTDINCDIR  = $(N64KITDIR)/nustd/include
NUSTDLIBDIR  = $(N64KITDIR)/nustd/lib


## デバッグレベル(予定)
## 0: 完全製品用 プリント不可
## 1: 製品用     osSyncPrintfのみ
## 2: ショウ用   osSyncPrintfのみ
## 3: 撮影用     PRINTF可
## 4: マリオクラブ初期デバッグ用
## 5: 通常開発用 重要なメッセージのみ表示
## 6: 通常開発用 一般的なメッセージの表示
## 7: テスト開発用  メッセージがちょっとうるさい
## 8: デバッグ調査用  ゲームが引っ掛かるほどメッセージがうるさい
## 9: システムデバッグ用  ゲームが止まるほどメッセージがうるさい
## DEBUG_LEVEL = 6

## cc / makerom のオプション

## DD用につくったデータをロム版に組み込む
## make -k "VMAKEOPTION=USE_NEW_DUNGEON=" rom_d

#ifdef USE_NEW_DUNGEON
LMAKEOPT += -DUSE_NEW_DUNGEON
#endif

## z_player.[ch] の残骸消したら消す
LMAKEOPT += -DHAYAKAWA_TESTks2

## 販売地域
LMAKEOPT += -DFOR_JAPAN -DFOR_USA


##LMAKEOPT += -DGRAPH_OLD_VERSION
##LMAKEOPT += -D_graph=__graph

LMAKEOPT += -DNOUSE_LINE_UCODE		# LineUcodeは使わない
###LMAKEOPT += -DZURUMODE=2		# ２コン挿さっていたらずるモード
LMAKEOPT += -DPLAY_ADJUST		# GAME_PLAY追加テスト用
LMAKEOPT += -DOPTIMIZE_NEXT_DISP	# NEXT_DISPの高速化
LMAKEOPT += -DUSE_DEBUG_MODE
#ifdef USE_N64DD
LMAKEOPT += -DJPN_CASSETTE_BOOT -DOVERLAY_PRG -DMULTICOUNTRY # 64DD対応
###LMAKEOPT += -DDD_SYNCHRO # 同期処理
LMAKEOPT += -DUSE_DD_WRITE  # 一応
#endif
#LMAKEOPT+= -DHAYAKAWA_TEST=1 -DRAM4M -DSYS_FIFO_SIZE=0x8000

## make のオプション

#ifdef ROM_D
LMAKEOPT += -DROM_D
LMAKEOPT += -DZURUMODE=2
LMAKEOPT += "-DU_${USER}_U"
#endif
#ifdef ROM_X
LMAKEOPT += -DROM_X
LMAKEOPT += -DZURUMODE=2
#endif
#ifdef ROM_F
LMAKEOPT += -DROM_F
LMAKEOPT += -DZURUMODE=0
#endif
#ifdef ROM_S
LMAKEOPT += -DROM_S
LMAKEOPT += -DZURUMODE=2
#endif
#ifdef FINAL_ROM
LMAKEOPT += -DFINAL_ROM
#endif

#ifdef ROM_ROM
LMAKEOPT +=	-DROM_ROM=1			# ＲＯＭ焼き用のコードを吐く
#endif
#ifdef EMU_ROM
LMAKEOPT +=	-DEMU_ROM=1			# ボード用のコードを吐く
#endif
#ifdef PARTNER
LMAKEOPT +=	-DPARTNER=1			# パートナー用のコードを吐く
#endif
#ifdef ISVIEWER
LMAKEOPT +=	-DISVIEWER=1			# ISVIEWER用のコードを吐く
#endif

## z_playオーバーレイ化
#ifdef RAM8M
LMAKEOPT += -DRAM8M
#endif

#ifdef USE_CIC6105
LMAKEOPT += -DUSE_CIC6105
#ifdef GATEWAY_VERSION
LMAKEOPT += -DUSE_CIC6105_NOCHECK=
#else
LMAKEOPT += -DUSE_CIC6105_CHECK=
#endif
#endif


#ifdef USE_N64DD
LMAKEOPT += -DUSE_N64DD
#endif
#ifdef USE_LEOEMU
LMAKEOPT += -DUSE_LEOEMU
#endif
#ifdef USE_COUNT
LMAKEOPT += -DUSE_COUNT
#endif

#ifdef USE_LOCALE
LMAKEOPT += -DUSE_LOCALE
#endif
#ifdef USE_DEBUG_MALLOC
LMAKEOPT += -DUSE_DEBUG_MALLOC
#endif
#ifdef SCENE_TOOL
LMAKEOPT += -DSCENE_TOOL
#endif
#ifdef SCENE_TOOL2
#endif
#ifdef DEBUG_CAMERA
LMAKEOPT += -DDEBUG_CAMERA
#endif
#ifdef PAL_VERSION
LMAKEOPT += "-DPAL_VERSION"
#endif
#ifdef GATEWAY_VERSION
LMAKEOPT += -DGATEWAY_VERSION
LMAKEOPT += -DSYS_GATEWAY_N64
#endif

#ifdef VIDEO_AUTO
LMAKEOPT += "-DVIDEO_AUTO"
#else
#ifdef PAL_VERSION
LMAKEOPT += "-DVIDEO_PAL"
#else
LMAKEOPT += "-DVIDEO_NTSC_OR_MPAL"
#endif
#endif


include $(ROOT)/usr/include/make/PRdefs
#ifdef HAYAKAWA_LIB
include /home/hayakawa/prj/PR/COMMON/SRDdefs.mk
#else
include $(ROOT)/usr/local/srd/PR/SRDdefs.mk
#endif
include $(COMMONRULES)
#ifdef __GCC__
include $(ROOT)/usr/include/make/gccdefs
#endif

#
# ディレクトリの設定
#

ZELDA_LIB =	$(ZELDA_ROOT)/lib
ZELDA_TOOL =	$(ZELDA_ROOT)/tool/bin
ZELDA_DATA =	$(ZELDA_ROOT)/data
ZELDA_AUDIO =   $(ZELDA_LIB)/audio

SHELL 		= $(ROOT)/bin/sh
LD 		= $(ROOT)/usr/lib/PR/nld
MAKEMASK 	= $(ROOT)/usr/sbin/makemask
#MAKEMASK6105 	= $(ROOT)/usr/sbin/makemask6105		# HIRATSU Daisuke invalidated this line.
#if defined(USE_CIC6105) && defined(ROM_D)
VERSUM 		= $(ZELDA_LIB)/CIC6105/981001/versum
#endif
NRDC 		= $(ZELDA_LIB)/NRDC/nrdc/nrdc

TARGETS = romPP_d

#if defined(HAYAKAWA_LIB_TEST)
HAYAKAWA_LIB =
#endif

ZELDA_INFO =    zelda_makerom.stdout

#ifdef __GCC__
MKDEPOPT=
LLDOPTS  = 
#else
LLDOPTS  = $(MKDEPOPT)
#endif
#ifdef HAYAKAWA_LIB
PATCH_DIR = /home/hayakawa/prj/PR/COMMON/patch/PR
PATCH_INCDIR = $(PATCH_DIR)
PATCH_LIBDIR = $(PATCH_DIR)
#endif
LCINCS = \
-I$(PATCH_INCDIR) \
-I$(PATCH_INCDIR)/.. \
-I$(ZELDA_LIB)
LLDOPTS += \
-L$(PATCH_LIBDIR)
#ifdef HAYAKAWA_LIB
LCINCS += \
-I/home/hayakawa/prj/PR/libu64 \
-I/home/hayakawa/prj/PR/libc64
LLDOPTS += \
-L/home/hayakawa/prj/PR/libu64 \
-L/home/hayakawa/prj/PR/libc64
#endif
LCINCS += \
-I$(COMMON_INCDIR) \
-I$(ROOT)/usr/include/PR \
-I/usr/include \
-I$(NUSTDINCDIR)
LLDOPTS +=  \
-L$(ZELDA_LIB)/audio \
-L$(COMMON_LIBDIR) \
-L$(ROOT)/usr/lib/PR \
-L$(NUSTDLIBDIR)


### ウルトラライブラリの選択
#if defined(ROM_ROM) || defined(ISVIEWER)
ULTRALIB_BASE = ultra_rom
#elif defined(EMU_ROM) || defined(PARTNER)
ULTRALIB_BASE = ultra
#endif
ULTRALIB = -l$(ULTRALIB_BASE)
## ULTRALIB_FULLPATH = $(PATCH_LIBDIR)/lib$(ULTRALIB_BASE).a
ULTRALIB_FULLPATH = $(ROOT)/usr/lib/lib$(ULTRALIB_BASE).a
ULTRALIB2 = libultra2.a

LEOEMULIBDIR = $(ZELDA_LIB)/ISV/tool/lib
LEOLIBDIR = $(ROOT)/usr/lib

#if defined(ROM_ROM)
U64LIB_BASE = u64_rom
C64LIB_BASE = c64_rom
NUSLIB_BASE = nustd
#else /* EMU_ROM */
U64LIB_BASE = u64_d
C64LIB_BASE = c64_d
NUSLIB_BASE = nustd_d
#endif
LEOLIB_BASE = leo
LEOEMULIB_BASE = leoemu

U64LIB    = -l$(U64LIB_BASE)
C64LIB    = -l$(C64LIB_BASE)
NUSLIB    = -l$(NUSLIB_BASE)
LEOEMULIB = -l$(LEOEMULIB_BASE)
LEOLIB    = -l$(LEOLIB_BASE)

#ifdef HAYAKAWA_LIB
U64LIB_FULLPATH = /home/hayakawa/prj/PR/libu64/lib$(U64LIB_BASE).a
C64LIB_FULLPATH = /home/hayakawa/prj/PR/libc64/lib$(C64LIB_BASE).a
#else
U64LIB_FULLPATH = $(COMMON_LIBDIR)/lib$(U64LIB_BASE).a
C64LIB_FULLPATH = $(COMMON_LIBDIR)/lib$(C64LIB_BASE).a
#endif
NUSLIB_FULLPATH = $(NUSTDLIBDIR)/lib$(NUSLIB_BASE).a
LEOLIB_FULLPATH = $(LEOLIBDIR)/lib$(LEOLIB_BASE).a
LEOEMULIB_FULLPATH = $(LEOEMULIBDIR)/lib$(LEOEMULIB_BASE).a

U64LIB2    = libu642.a
C64LIB2    = libc642.a
NUSLIB2    = libnustd2.a
LEOLIB2    = libleo2.a
LEOEMULIB2 = libleoemu2.a

#
# ファイルの設定
#
include Makefile.CFILES			# CFILES の定義
include Makefile.DISK			# DISK 版の定義

C++FILES =	
COBJECTS        = 	$(CFILES:.c=.o)
COBJECTS_EN     = 	$(CFILES_EN:.c=.o)
COBJECTS_EFF    = 	$(CFILES_EFF:.c=.o)
COBJECTS_Z      = 	$(CFILES_Z:.c=.o)
COBJECTS_SYS    = 	$(CFILES_SYS:.c=.o)
COBJECTS_BOOT   = 	$(CFILES_BOOT:.c=.o)
#ifdef USE_N64DD
COBJECTS_N64DD   = 	$(CFILES_N64DD:.c=.o)
#endif /* USE_N64DD */
C++OBJECTS      = 	$(C++FILES:.c++=.o)
C++OBJECTS_EN   = 	$(C++FILES_EN:.c++=.o)
C++OBJECTS_EFF  = 	$(C++FILES_EFF:.c++=.o)
C++OBJECTS_Z    = 	$(C++FILES_Z:.c++=.o)
C++OBJECTS_SYS  = 	$(C++FILES_SYS:.c++=.o)
C++OBJECTS_BOOT = 	$(C++FILES_BOOT:.c++=.o)
#ifdef USE_N64DD
C++OBJECTS_N64DD = 	$(C++FILES_N64DD:.c++=.o)
#endif /* USE_N64DD */

COBJECT_EN  = cobject_en.o
COBJECT_EFF = cobject_eff.o
COBJECT_Z   = cobject_z.o
COBJECT_SYS = cobject_sys.o
COBJECTS    = $(COBJECTS_EN) $(COBJECTS_EFF) $(COBJECTS_Z) $(COBJECTS_SYS)

CODEOBJECTS = \
	$(COBJECTS) \
	$(C++OBJECTS) \
	$(ZELDA_LIB)/z_fault.o \
	$(ZELDA_LIB)/faultprint.o \
	$(KANJIDATA1)

#ifdef USE_VOLCULL
CODEOBJECTS += $(ZELDA_LIB)/volcull.o
#endif
#ifdef USE_COUNT
CODEOBJECTS += $(ZELDA_LIB)/count.o
#endif

#ifdef PAL_VERSION

#if defined(ROM_D) || defined(ROM_X)
CODEOBJECTS +=	$(ZELDA_LIB)/audio/debug_audio_pal.o 
#else
CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio_pal.o 
#endif

#else /* PAL_VERSION */

#if defined(ROM_D) || defined(ROM_X)
CODEOBJECTS +=	$(ZELDA_LIB)/audio/debug_audio.o 
#else
CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio.o 
#endif

#endif /* PAL_VERSION */

AUDIOOBJECTS =	\
	$(ZELDA_AUDIO)/aspMain.o \
	$(ZELDA_AUDIO)/audio.o \
	$(ZELDA_AUDIO)/audio_hb.o \
	$(ZELDA_AUDIO)/audio_hm.o \
	$(ZELDA_AUDIO)/audio_hs.o \
	$(ZELDA_AUDIO)/audio_hw.o \
	$(ZELDA_AUDIO)/audiotable.o \
	$(ZELDA_AUDIO)/audioheap.o

BOOTOBJECTS = \
	$(COBJECTS_BOOT) \
	$(C++OBJECTS_BOOT)

#ifdef USE_N64DD
N64DDOBJECTS = \
	$(COBJECTS_N64DD) \
	$(C++OBJECTS_N64DD)
#endif /* USE_N64DD */

# KSEG0空間のデータ
DATAFILES = \
	last.c \
	sys_cfb.c \
	sys_dram_stack.c \
	sys_dynamic.c \
	sys_fifo_buffer.c \
	sys_heap.c \
	sys_yield_buffer.c \
	sys_zb.c \
	z_std_dma_data.c

DATAFILES += nullsegment.c

# Segment空間のデータ
DATAFILES += \
	rcp_cfb.c \
	rcp_zb.c \
	z_hilite.c
DATAOBJECTS =	$(DATAFILES:.c=.o)

AUDIOSEGMENT =	audiosegment.o
BOOTSEGMENT =	bootsegment.o
CODESEGMENT =	codesegment.o
#ifdef USE_N64DD
N64DDSEGMENT =	n64ddsegment.o
#endif /* USE_N64DD */
KANJIDATA1 = 	kanread.o
KANJIDATA2 =	kan.o

OBJECTS =	$(BOOTSEGMENT) $(CODESEGMENT)
#ifdef USE_N64DD
OBJECTS +=	$(N64DDSEGMENT)
#endif /* USE_N64DD */
# if defined(PAL_VERSION)
OBJECTS +=	$(DATAOBJECTS)
# else
OBJECTS +=	$(DATAOBJECTS) $(KANJIDATA2)
# endif

##LMAKEOPT = -UUSE_PRERENDER
LMAKEOPT +=	-DF3DEX_GBI 			# 開発３部のマイクロコードを使用する
LMAKEOPT +=	-DF3DEX_GBI_2 			# 開発３部のマイクロコードを使用する
LMAKEOPT +=	-DUSE_VISCVG			# カバレッジの可視表示
#if defined(ROM_S)
LMAKEOPT +=     -DROM_S
LMAKEOPT +=	-DSHOW_VERSION			# ショウバージョン用のコードを吐く
LMAKEOPT +=	-DDEBUG_MODE_NOINPUT		# デバッグレジスタを出さない
LMAKEOPT +=	-DDISABLE_FAULT_DISPLAY		# HungUpを出さない
#endif
#if defined(ROM_F)
LMAKEOPT +=     -DROM_F
LMAKEOPT +=     -DFINAL_ROM
####マリオクラブデバッグ時はHungUpを出すようにする
####LMAKEOPT +=	-DDISABLE_FAULT_DISPLAY		# HungUpを出さない
LMAKEOPT +=	-DDEBUG_MODE_NOINPUT		# デバッグレジスタを出さない
LMAKEOPT +=	-DNOUSE_DEBUG_PAD		# デバッグ用コントローラパッドを使用しない
#endif

#if defined(ROM_F) || defined(ROM_S)
OPTIMIZER = 	-O2 -g3				# 速く・小さく
LMAKEOPT +=	-DROM_VERSION=1			# 実機用ＲＯＭの作成
LMAKEOPT +=	-DNOUSE_PRINTF -DPRINTF_with_Warning_609 # PRINTFを使わない
LMAKEOPT +=	-DDEBUG=0			# put8x8用
LMAKEOPT +=	-DNDEBUG 			# assertを殺す
LMAKEOPT +=	-DUSE_TIMER=0 			# 処理時間を計測しない
LMAKEOPT +=	-D_ODEBUG 			# デバッグモード.とると z_camera.c がエラーになるので取りあえず入れてある（小川さん）
#else
#ifdef ROM_X
OPTIMIZER = 	-O2 -g3				# 速く・小さく
LMAKEOPT +=	-DROM_VERSION=1			# 実機用ＲＯＭの作成
LMAKEOPT +=	-DNOUSE_PRINTF -DPRINTF_with_Warning_609 # PRINTFを使わない
#else
OPTIMIZER = 	-O2 -g3				# 普通にオプティマイズ、デバッガ使う
LMAKEOPT +=	-DROM_VERSION=0			# エミュレータボード用
LMAKEOPT +=	-UNOUSE_PRINTF			# PRINTFを使う
#endif
LMAKEOPT +=	-DDEBUG=1			# lib*_d.aを使用する
LMAKEOPT +=	-DUSE_DEBUG_MOJI		# puts8x8用
LMAKEOPT +=	-DUSE_TIMER=1 			# 処理時間を計測する
LMAKEOPT +=	-D_ODEBUG 			# デバッグモード.とると z_camera.c がエラーになる
#endif
LMAKEOPT +=	-DUSE_FAULT=1 			# 画面にフォルトメッセージが出る
LMAKEOPT +=	-UUSE_RMON			# rmonスレッドを起動しない

#if defined(RAM8M) && defined(ROM_D)
LMAKEOPT +=	-DUSE_SEGMENT_NAME_TABLE
#endif
#if defined(RAM8M) && !defined(ROM_F)
LMAKEOPT +=	-DUSE_ACTOR_NAME_TABLE
#endif


LLDLIBS_CODE += $(U64LIB2) $(C64LIB2)
#if 0
LLDLIBS_CODE += $(ZELDA_LIB)/ucode/us2dexNew.o
#endif
LLDLIBS_CODE += $(ZELDA_LIB)/ucode/libjpg.a
####LLDLIBS_CODE += $(ZELDA_LIB)/audio/libgsmp.a
LLDLIBS_CODE += $(ULTRALIB2) $(NUSLIB2)

LLDLIBS_BOOT += $(ZELDA_LIB)/driverominit.o	## なんてこったい！
LLDLIBS_BOOT += $(ZELDA_LIB)/slidV10.o
LLDLIBS_BOOT += -L$(ROOT)/usr/lib $(U64LIB) $(C64LIB) 
#ifdef USE_N64DD
#ifdef USE_LEOEMU
LLDLIBS_BOOT += $(LEOEMULIB2)
LLDLIBS_BOOT += $(LEOLIB2)
#endif
#endif
#ifdef __GCC__
LLDLIBS_BOOT += -lgultra_d $(NUSLIB) $(GCCDIR)/mipse/lib/libkmc.a
#else
LLDLIBS_BOOT += $(ULTRALIB) $(NUSLIB)
#endif

###LLDLIBS_N64DD = $(ZELDA_LIB)/driveexist/driveexist.o.leo
#ifdef USE_N64DD
#ifndef USE_LEOEMU
LLDLIBS_N64DD += $(LEOLIB2)
#endif
#endif


##cfe: Warning 813:: struct/union/enum '' is used, but not defined
##cfe: Warning 828:: '' may be indistinguishable from '' due to internal name truncation
##cfe: Warning 852:: '' can be const qualified, since it is not set within its lifetime.
##cfe: Warning 814:: static '' unused
##cfe: Warning 819:: function parameter '' is not used in function ''
##cfe: Warning 820:: '' is not used in function ''
##cfe: Warning 821:: '' set but unused in function ''
##cfe: Warning 827:: implicit conversion from '' to ''
##cfe: Warning 828: /usr/include/PR/libaudio.h, line 467: 'AL_MIDI_SongPositionPointer' may be indistinguishable from 'AL_MIDI_SysEx' due to internal name truncation
#WOFF=-woff 1685,515,608,658,799,803,852,1048,1233,1499$(LWOFF)
#ifdef WARNLEVEL1
LWOFF = 	828,852,813
#elifdef WARNLEVEL2
LWOFF = 	813,828,852,814,819,820,821,827
#elifdef WARNLEVEL3
LWOFF = 	1685,515,608,658,799,803,852,1048,1233,1499,813,828,852,814,819,820,821,827
#else
###LWOFF = 	813,828,852,827
LWOFF = 	813,828,852,827,609
#endif
#ifndef __GCC__
WOFF = -woff $(LWOFF)$(VWOFF)
#endif


MAKEOPT = $(GMAKEOPT) $(LMAKEOPT) $(VMAKEOPT)

#LCINCS =
LASINCS =	$(LCINCS)
LCDEFS += $(MAKEOPT)
#ifdef __GCC__
LCOPTS = -Wall -W -G 0
LASOPTS = 	-G 0
#else
LCOPTS = -non_shared -G 0 -mips2 -fullwarn -float -xansi -Xcpluscomm -wlint,-fhp
LASOPTS =	-non_shared -G 0
#endif

LC++DEFS =	$(LCDEFS)
LC++INCS =	$(LCINCS)
LC++OPTS =	-non_shared -G 0 -mips2 -fullwarn -float -xansi +pp -woff 3259,3262,3672,3106
#: warning(3106): nested comment is not allowed
#: warning(3259): expression has no effect
#: warning(3262): variable "p1" was declared but never referenced
#: warning(3672): Mangling of signed character does not match cfront name mangling

: error(3114): identifier "" is undefined
: error(3130): the #endif for this directive is missing
: error(3232): a value of type "" cannot be used to initialize an entity of type ""
: error(3252): argument of type "" is incompatible with parameter of type ""
: error(3611): a value of type "" cannot be assigned to an entity of type ""
: error(3867): expected a member name

## 初期化しないauto変数を 0xffffa5a5にしてしまう
## 全バージョンで外すようにします（全責任者：山本雄一）
##
###if !defined(ROM_F) && !defined(__GCC__)
##LCOPTS   += -trapuv
##LC++OPTS += -trapuv
###endif

## make clean で消えるもの
LDIRT  += rom_d rom_x rom_f rom_s spec_inc_ovl.inc spec_seg_ovl.inc *.rel *.map $(ULTRALIB2) $(U64LIB2) $(C64LIB2) $(NUSLIB2) zelda.gdis eptvr.dat ptn64.dat *.szp *.szs
LDIRT1 = *.d


##LLDOPTS = $(MKDEPOPT) -L$(PATCH_LIBDIR) -L$(COMMON_LIBDIR) -L$(ROOT)/usr/lib/PR
GLDOPTS =				# デフォルトの内容を削除する

#ifdef __GCC__
LDFLAGS_WIDHOUT_LDLIBS = $(LDOPTS) $(ENDIAN)
#else
LDFLAGS_WIDHOUT_LDLIBS	= $(LDOPTS) $(ENDIAN)
#endif

TOOLBIN = ${ZELDA_ROOT}/tool/bin
###CAMDATINSTALLROOT = /home/umemiya/ZELDA/SAM_TOOL
CAMDATINSTALLROOT = /project/ZELDA1/link/tools/umemiya/SAM_TOOL
CAMPARAMH = camera_param_data.h
CAMERAZDB = camera.zdb
CAMDATABASE = ${ZELDA_ROOT}/data/$(CAMERAZDB)



#
# エントリ登録
#
all default:	genfiles $(TARGETS)

help::
	@echo '最新バージョンで、完全に再構築します(rom_d/rom_x/rom_f/rom_s)'
	@echo 'make fullcourse'

# ソース・データ更新
coall::
	coall
	$(MAKE) data

# フルコース2！
# make_midnight 用
# clobber する際に以前の *.szs ファイルを保存しています
fullcourse2::
	@echo このモードは make clobber を使用します
	coall
	-rm -rf szs_x; mkdir szs_x && (cd rom_x && mv [A-Za-n]*.szs ../szs_x/. && mv [o-z]*.szs ../szs_x/.)
	-rm -rf szs_d; mkdir szs_d && (cd rom_d && mv [A-Za-n]*.szs ../szs_d/. && mv [o-z]*.szs ../szs_d/.)
	-rm -rf szs_f; mkdir szs_f && (cd rom_f && mv [A-Za-n]*.szs ../szs_f/. && mv [o-z]*.szs ../szs_f/.)
##	-rm -rf szs_s; mkdir szs_s && (cd rom_s && mv [A-Za-n]*.szs ../szs_s/. && mv [o-z]*.szs ../szs_s/.)
	$(MAKE) clobber
	-mkdir rom_d; (cd szs_d && mv [A-Za-n]*.szs ../rom_d/. && mv [o-z]*.szs ../rom_d/.) && rmdir szs_d
	-mkdir rom_x; (cd szs_x && mv [A-Za-n]*.szs ../rom_x/. && mv [o-z]*.szs ../rom_x/.) && rmdir szs_x
	-mkdir rom_f; (cd szs_f && mv [A-Za-n]*.szs ../rom_f/. && mv [o-z]*.szs ../rom_f/.) && rmdir szs_f
##	-mkdir rom_s; (cd szs_s && mv [A-Za-n]*.szs ../rom_s/. && mv [o-z]*.szs ../rom_s/.) && rmdir szs_s
	$(MAKE) camera_params
	$(MAKE) data
	$(MAKE) genfiles
##	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) rom_d rom_x rom_f

rebuild_d:
	-rm -rf szs_d; mkdir szs_d ; (cd rom_d && mv [A-Za-n]*.szs ../szs_d/. && mv [o-z]*.szs ../szs_d/.)
	-rm -rf rom_d; mkdir rom_d ; (cd szs_d && mv [A-Za-n]*.szs ../rom_d/. && mv [o-z]*.szs ../rom_d/.) && rmdir szs_d
	-$(MAKE) rom_d PARALLEL=
rebuild_x:
	-rm -rf szs_x; mkdir szs_x ; (cd rom_x && mv [A-Za-n]*.szs ../szs_x/. && mv [o-z]*.szs ../szs_x/.)
	-rm -rf rom_x; mkdir rom_x ; (cd szs_x && mv [A-Za-n]*.szs ../rom_x/. && mv [o-z]*.szs ../rom_x/.) && rmdir szs_x
	-$(MAKE) rom_x PARALLEL=
rebuild_f:
	-rm -rf szs_f; mkdir szs_f ; (cd rom_f && mv [A-Za-n]*.szs ../szs_f/. && mv [o-z]*.szs ../szs_f/.)
	-rm -rf rom_f; mkdir rom_f ; (cd szs_f && mv [A-Za-n]*.szs ../rom_f/. && mv [o-z]*.szs ../rom_f/.) && rmdir szs_f
	-$(MAKE) rom_f PARALLEL=
rebuild_s:
	-rm -rf szs_s; mkdir szs_s ; (cd rom_s && mv [A-Za-n]*.szs ../szs_s/. && mv [o-z]*.szs ../szs_s/.)
	-rm -rf rom_s; mkdir rom_s ; (cd szs_s && mv [A-Za-n]*.szs ../rom_s/. && mv [o-z]*.szs ../rom_s/.) && rmdir szs_s
	-$(MAKE) rom_s PARALLEL=
rebuild_c:
	-rm -rf szs_c; mkdir szs_c ; (cd rom_c && mv [A-Za-n]*.szs ../szs_c/. && mv [o-z]*.szs ../szs_c/.)
	-rm -rf rom_c; mkdir rom_c ; (cd szs_c && mv [A-Za-n]*.szs ../rom_c/. && mv [o-z]*.szs ../rom_c/.) && rmdir szs_c
	-$(MAKE) rom_c PARALLEL=
rebuild_all:
	-coall
	-$(MAKE) camera_params
	-$(MAKE) data
	-$(MAKE) genfiles
	-$(MAKE) rebuild_d rebuild_x rebuild_f rebuild_s
	-$(MAKE) romPP_d romPP_x romPP_f PARALLEL=
	-$(MAKE) romPP_d romPP_x romPP_f PARALLEL=
	-$(MAKE) rebuild_s rebuild_c
	-$(MAKE) romPP_s PARALLEL=
	-$(MAKE) romPP_s PARALLEL=

fullcourse3::
	-$(MAKE) cleanboot
##	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) romPP_d || $(MAKE) romPP_d
	-$(MAKE) romPP_x || $(MAKE) romPP_x
	-$(MAKE) romPP_f || $(MAKE) romPP_f
##	-$(MAKE) romPP_s || $(MAKE) romPP_s

# フルコース！
fullcourse::
	coall
	$(MAKE) camera
	$(MAKE) data
	$(MAKE) genfiles
	-$(MAKE) romPP_d || $(MAKE) romPP_d

SPECFILE  = spec
SPEC_INCLUDE  = spec.segment spec.audio
LMAKEROMOPT = -I$(ZELDA_ROOT)

#if ($(LOCALE)=="CHINA")
MAKEROMOPT = $(GMAKEROMOPT) $(LMAKEROMOPT) $(VMAKEROMOPT) -DCHINA 
#else
MAKEROMOPT = $(GMAKEROMOPT) $(LMAKEROMOPT) $(VMAKEROMOPT)
#endif

MAKEROMOBJECTS = $(OBJECTS) $(ZELDA_DATA)/*.o $(OVLOBJECTS) \
	$(ZELDA_AUDIO)/ZeldaAudio_banks.o \
	$(ZELDA_AUDIO)/ZeldaAudio_music.o \
	$(ZELDA_AUDIO)/ZeldaAudio_table.o
MAKEROMFILES = $(SPECFILE) $(SPEC_INCLUDE)  $(OVLRELFILES)


# マップファイルの作成
zelda.map: $(MAKEROMOBJECTS) $(MAKEROMFILES)
	(LANG=C ZELDA_DATA=${ZELDA_DATA} time $(MAKEROM) -m $(MAKEROMOPT) $(MAKEOPT) -r rom ../$(SPECFILE) > zelda.map)


##
## LMAKEOPTIONの定義
##
LMAKEOPTION =
####for GC EMU
###LMAKEOPTION += USE_N64DD=
LMAKEOPTION += USE_LOCALE=

####for GC EMU
###LMAKEOPTION += USE_CIC6105=

#ifdef PARALLEL
LMAKEOPTION += "PARALLEL=$(PARALLEL)"
#endif
#ifdef HAYAKAWA_LIB
LMAKEOPTION += "HAYAKAWA_LIB=$(HAYAKAWA_LIB)"
#endif
#ifdef FORCE_CPP
LMAKEOPTION += "FORCE_CPP=$(FORCE_CPP)"
#endif
#ifdef VMAKEOPT
LMAKEOPTION += "VMAKEOPT=$(VMAKEOPT)"
#endif
#ifdef VMAKEROMOPT
LMAKEOPTION += "VMAKEROMOPT=$(VMAKEROMOPT)"
#endif
#ifdef SCENE_TOOL
LMAKEOPTION += "SCENE_TOOL=$(SCENE_TOOL)"
#endif
#ifdef SCENE_TOOL2
LMAKEOPTION += "SCENE_TOOL2=$(SCENE_TOOL2)"
#endif
MAKEOPTION_D = $(LMAKEOPTION) $(VMAKEOPTION) ROM_D= USE_COUNT= DEBUG_CAMERA= USE_DEBUG_MALLOC= ISVIEWER= RAM8M= VIDEO_AUTO=
MAKEOPTION_X = $(LMAKEOPTION) $(VMAKEOPTION) ROM_X= USE_COUNT= DEBUG_CAMERA= USE_DEBUG_MALLOC= ISVIEWER= RAM8M= VIDEO_AUTO=

MAKEOPTION_F = $(LMAKEOPTION) $(VMAKEOPTION) ROM_F= ROM_ROM= FINAL_ROM=
MAKEOPTION_S = $(LMAKEOPTION) $(VMAKEOPTION) ROM_S= ROM_ROM= SHOW_VERSION=
MAKEOPTION_C = $(MAKEOPTION_D) ROM_C= FORCE_CPP=

LMAKEFLAGS = -f ../$(MAKEFILE)
MAKEFLAGS = $(GMAKEFLAGS) $(LMAKEFLAGS) $(VMAKEFLAGS)

zelda_d.map:
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_D)
	@echo ": Leaving directory \`./rom_d/'"

zelda_x.map:
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_X)
	@echo ": Leaving directory \`./rom_x/'"

zelda_f.map:
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_F)
	@echo ": Leaving directory \`./rom_f/'"

zelda_s.map:
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(VMAKEFLAGS)  zelda.map $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

spec.i:../$(SPECFILE) ../spec.segment ../spec_seg_ovl.inc ../boot.h ../sys_segment.h
	(LANG=C ZELDA_DATA=${ZELDA_DATA} $(CC) -E $(MAKEOPT) ../$(SPECFILE) > spec.i.tmp)
	mv spec.i.tmp spec.i

# ロムヘッダ定義（仮）
MASKROM_VERSION = f		# 開発バージョン識別用（仮）
MASKROM_PGW_INICODE = nzll	# PAL(GATEWAY)
MASKROM_GTW_INICODE = czlg	# GATEWAY
MASKROM_PAL_INICODE = nzlp	# PAL
MASKROM_JPN_INICODE = czlj	# JAPAN
MASKROM_NES_INICODE = czle	# NES
MASKROM_GAME_TITLE = "THE LEGEND OF ZELDA"
#if defined(PAL_VERSION) && defined(GATEWAY_VERSION)
MASKROM_INICODE = $(MASKROM_PGW_INICODE)
#elif !defined(PAL_VERSION) && defined(GATEWAY_VERSION)
MASKROM_INICODE = $(MASKROM_GTW_INICODE)
#elif defined(PAL_VERSION)
MASKROM_INICODE = $(MASKROM_PAL_INICODE)
#else
#MASKROM_INICODE = $(MASKROM_JPN_INICODE)	# HIRATSU Daisuke invalidated this line.
MASKROM_INICODE = $(MASKROM_NES_INICODE)	# HIRATSU Daisuke modified this line.
#endif

rom: $(MAKEROMOBJECTS) $(MAKEROMFILES)
	../make_version.sh $(MAKEOPTION) > version_data.h
	$(CC) $(CFLAGS) -c ../version.c
	(LANG=C ZELDA_DATA=${ZELDA_DATA} time $(MAKEROM) -d $(MAKEROMOPT) $(MAKEOPT) -r rom.tmp ../$(SPECFILE) > $(ZELDA_INFO))
	$(NRDC) -b -i$(MASKROM_INICODE) -t$(MASKROM_GAME_TITLE) -v$(MASKROM_VERSION) rom.tmp
#if defined(USE_CIC6105) && defined(ROM_D) && !defined(GATEWAY_VERSION)
	$(VERSUM) rom.tmp
#endif
	mv -f rom.tmp rom
#	-(nm zelda | sort | tee zelda.nm1 | egrep "^8" > zelda.nm)&
	-(/usr/bin/nm -B zelda | sort | tee zelda.nm2 | egrep "^8" > zelda.nm)&
#if defined(PARTNER)
	n64deb zelda		# パートナー用変換
#endif
# #if defined(PARTNER) || defined(ISVIEWER) || defined(ROM_ROM)
#	@echo "makemaskはスキップされました"
#	@echo "makemaskは手でやってください"
#	@echo "例）makemask rom_d/rom"
	$(MAKEMASK) rom		# ROM焼き用変換 (HIRATSU Daisuke modified this line.)
# #endif
	@-if [ \( ${USER} = "###yoshida" -o ${USER} = "###hayakawa" \) -a -f /home/iwawaki/AIFC_FILES/capture.mv ]; then \
	    audiopanel -nodisplay -nofork -outlevels 2; \
	    movieplayer -l 0 -N -z 0.5 -b q -v /home/iwawaki/AIFC_FILES/capture.mv > /dev/null; \
	else \
	    if [ -x ../bell.sh ]; then \
		    ../bell.sh; \
	    else \
	        if [ -x ./bell.sh ]; then \
		        ./bell.sh; \
	        fi; \
	    fi; \
	fi
	date
#	then playaifc /home/iwawaki/AIFC_FILES/bakabon.aifc > /dev/null; \

## ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(ULTRALIB2): $(ULTRALIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibultra.a
	cp $(ULTRALIB_FULLPATH) tmplibultra.a
	chmod 644 tmplibultra.a
	sed -n -e "s/.*libultra.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > ultra.stdout
	$(AR) d tmplibultra.a `sed -n -e "s/.*libultra.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibultra.a sprintf.o
#if defined(ISVIEWER) || defined(ROM_ROM)
	$(AR) d tmplibultra.a syncprintf.o
#endif
####if !defined(USE_LEOEMU)
###	$(AR) d tmplibultra.a driverominit.o
####endif
	chmod 444 tmplibultra.a
	mv tmplibultra.a $(ULTRALIB2)

## ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(U64LIB2): $(U64LIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibu64.a
	cp $(U64LIB_FULLPATH) tmplibu64.a
	chmod 644 tmplibu64.a
	sed -n -e "s/.*libu64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > u64.stdout
	$(AR) d tmplibu64.a `sed -n -e "s/.*libu64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	chmod 444 tmplibu64.a
	mv tmplibu64.a $(U64LIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(C64LIB2): $(C64LIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibc64.a
	cp $(C64LIB_FULLPATH) tmplibc64.a
	chmod 644 tmplibc64.a
	sed -n -e "s/.*libc64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > c64.stdout
	$(AR) d tmplibc64.a `sed -n -e "s/.*libc64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	-$(AR) d tmplibc64.a assert64.o	# zelda のassertを使用するため
	chmod 444 tmplibc64.a
	mv tmplibc64.a $(C64LIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(NUSLIB2): $(NUSLIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibnus.a
	cp $(NUSLIB_FULLPATH) tmplibnus.a
	chmod 644 tmplibnus.a
	sed -n -e "s/.*lib$(NUSLIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > nus.stdout
	$(AR) d tmplibnus.a `sed -n -e "s/.*'lib$(NUSLIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibnus.a memcpy.o strchr.o strlen.o
	chmod 444 tmplibnus.a
	mv tmplibnus.a $(NUSLIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(LEOLIB2): $(LEOLIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibleo.a
	cp $(LEOLIB_FULLPATH) tmplibleo.a
	chmod 644 tmplibleo.a
	sed -n -e "s/.*lib$(LEOLIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > leo.stdout
#	$(AR) d tmplibleo.a `sed -n -e "s/.*'lib$(LEOLIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibleo.a driverominit.o
	chmod 444 tmplibleo.a
	mv tmplibleo.a $(LEOLIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(LEOEMULIB2): $(LEOEMULIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibleoemu.a
	cp $(LEOEMULIB_FULLPATH) tmplibleoemu.a
	chmod 644 tmplibleoemu.a
	sed -n -e "s/.*lib$(LEOEMULIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > leoemu.stdout
	$(AR) d tmplibleoemu.a `sed -n -e "s/.*'lib$(LEOEMULIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	chmod 444 tmplibleoemu.a
	mv tmplibleoemu.a $(LEOEMULIB2)

#ifdef __GCC__
LDMAPOPT =
#else
LDMAPOPT = -m
#endif

$(AUDIOSEGMENT:.o=.map): $(AUDIOSEGMENT)
$(AUDIOSEGMENT): $(AUDIOOBJECTS)
	$(LD)  -o $(AUDIOSEGMENT) -r $(AUDIOOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_AUDIO) $(LDMAPOPT) > $(AUDIOSEGMENT:.o=.map)

$(BOOTSEGMENT:.o=.map): $(BOOTSEGMENT)
$(BOOTSEGMENT): $(BOOTOBJECTS)
	$(LD)  -o $(BOOTSEGMENT) -r $(BOOTOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_BOOT) $(LDMAPOPT) > $(BOOTSEGMENT:.o=.map)
	echo "$(BOOTSEGMENT:.o=.map) できた"

$(N64DDSEGMENT:.o=.map): $(N64DDSEGMENT)
$(N64DDSEGMENT): $(N64DDOBJECTS) $(LEOLIB2)
	$(LD)  -o $(N64DDSEGMENT) -r $(N64DDOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_N64DD) $(LDMAPOPT) > $(N64DDSEGMENT:.o=.map)

$(CODESEGMENT:.o=.map): $(CODESEGMENT)
$(CODESEGMENT): $(CODEOBJECTS) $(ULTRALIB2) $(NUSLIB2) $(U64LIB2) $(C64LIB2)
	$(LD)  -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_CODE) $(LDMAPOPT) > $(CODESEGMENT:.o=.map)

$(COBJECT_EN) $(COBJECT_EN:.o=.map): $(COBJECTS_EN)
	$(LD)  -o $(COBJECT_EN) -r $(COBJECTS_EN) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_EN:.o=.map)

$(COBJECT_EFF) $(COBJECT_EFF:.o=.map): $(COBJECTS_EFF)
	$(LD)  -o $(COBJECT_EFF) -r $(COBJECTS_EFF) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_EFF:.o=.map)

$(COBJECT_Z) $(COBJECT_Z:.o=.map): $(COBJECTS_Z)
	$(LD)  -o $(COBJECT_Z) -r $(COBJECTS_Z) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_Z:.o=.map)

$(COBJECT_SYS) $(COBJECT_SYS:.o=.map): $(COBJECTS_SYS)
	$(LD)  -o $(COBJECT_SYS) -r $(COBJECTS_SYS) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_SYS:.o=.map)

## 第１水準フォント データ
CC_FLAGS  = -Wab,-r4300_mul -mips2 -O -xansi -signed -fullwarn -prototypes -Xcpluscomm -I/usr/include/PR -non_shared -G 0 -c -Dyj
##LASFLAGS = -Wab,-r4300_mul -mips2 -O2 -xansi -signed -prototypes -Xcpluscomm -I/usr/include/PR -non_shared -G 0 -c -Dyj
kanread.o	: kanread.s	;cc $(CC_FLAGS) -o $(.TARGET) $(.IMPSRC)
kan.o	: kan.s	;cc $(CC_FLAGS) -o $(.TARGET) $(.IMPSRC)

name : zelda
	/usr/bin/nm -x zelda | grep -v ref | sort +2 > $@
name2 : name
	/home/hayakawa/prj/test/namesize name > $@

cfb.o:cfb.c
	$(CC) $(LCOPTS) $(LCINCS) $(MKDEPOPT) $(WOFF) $(LCDEFS) -c cfb.c

##
###


camera: $(CAMDATABASE) $(TOOLBIN)/makecamera
	$(TOOLBIN)/makecamera -l -d$(CAMDATINSTALLROOT) $(CAMDATABASE)

camera_params:  $(CAMPARAMH)

$(CAMPARAMH):  $(CAMDATABASE) $(TOOLBIN)/makecamera
	$(TOOLBIN)/makecamera -td -q $(CAMDATABASE)

../$(CAMPARAMH):  ../../data/$(CAMERAZDB)
	$(TOOLBIN)/makecamera -td -q ../../data/$(CAMERAZDB)
	mv $(CAMPARAMH) ..

../../data/$(CAMERAZDB):
	@if [ ! -l ../../data/camera ]; \
	then \
	    if [ `echo ${HOST} | awk '{print substr($$0, 1, 3)}'` = "srd" ]; \
	    then  ln -s /project/ZELDA/data/camera ../../data; \
	    else  echo "please contact to SRD ..."; \
	    fi; \
	fi
	@if [ ! -r ../../data/$(CAMERAZDB) ]; \
	then \
	    cp ../../data/camera/$(CAMERAZDB) ../../data; \
	fi

$(CAMDATABASE):  ${ZELDA_ROOT}/data/camera/${@F}
	if [ -r $@ ] && [ ! -w $@ ]; \
	then  chmod +w $@; \
	fi
	cp ${ZELDA_ROOT}/data/camera/${@F} $@

###
##

zelda.gdis::				# 逆アセンブルリストの作成
	gdis -S \
$(GDISOPT) \
-I.. \
-I/usr/local/srd/PR/src/libu64 \
-I/usr/local/srd/PR/src/libc64 \
-I/usr/src/PR/libultra/gu zelda > zelda.gdis

# 逆アセンブルリストの作成
zelda_d.gdis::
	cd rom_d; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_x.gdis::
	cd rom_x; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_f.gdis::
	cd rom_f; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_s.gdis::
	cd rom_s; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"

cleanall:
	rm -f rom*/*.o rom*/Makedepend rom*/*.map rom*/*. rom*/*.oo rom*/*.gdis rom*/*.a
cleanboot:				# ptstart()/isPrintfInit()を呼んでいる
	rm -f */boot.o
	rm -f */padmgr.o */main.o
#if defined(CLEAN_ALL) || defined(USE_LEOEMU)
	rm -f */idle.o */is_debug.o	# USE_LEOEMU
	rm -f */cpuprint.o */idle.o */ssSRAMrdwt.o */z_sram.o */z_std_dma.o # sys_leoemu.h
#endif
#if defined(CLEAN_ALL) || defined(RAM8M)
	rm -f */db_camera.o */z_camera.o # 8M/4M
#endif
#if defined(CLEAN_ALL) || defined(HAYAKAWA_TEST)
	rm -f */game.o */graph.o */sys_ucode.o */z_room.o */z_kaleido_manager.o */z_play.o */z_scene_table.o */z_std_dma.o
#endif

#if defined(CLEAN_ALL) || defined(USE_COUNT) || defined(USE_TIMER)
	rm -f */graph.o
#endif
#if defined(CLEAN_ALL) || defined(USE_CIC6105)
	rm -f */boot.o */z_bg_zg.o */z_en_zl2.o */z_fishing.o */sys_ucode.o */audioMgr.o */z_title.o */CIC6105.o */main.o
#endif
#if defined(CLEAN_ALL) || defined(USE_N64DD)
	rm -f */sys_cfb.o */main.o */z_select.o
#endif
#if defined(CLEAN_ALL) || defined(USE_RMON)
	rm -f */main.o */idle.o
#endif
#if defined(CLEAN_ALL) || defined(USE_ACTOR_NAME_TABLE)
	rm -f */z_actor_dlftbls.o */z_std_dma.o
#endif
#if defined(CLEAN_ALL) || defined(USE_VISCVG)
	rm -f */game.o
#endif
#if defined(CLEAN_ALL) || defined(SHOW_VERSION)
	rm -f */main.o 				# DISABLE_FAULT_DISPLAY	
	rm -f */padmgr.o			# SHOW_VERSION
#endif
#if defined(CLEAN_ALL) || defined(DEBUG_MODE_NOINPUT)
	rm -f */game.o */graph.o */z_debug.o */z_demo.o */z_file_choose.o */z_kaleido.o */z_kaleido_scope.o */z_kankyo.o */z_message.o */z_play.o */z_player.o	# DEBUG_MODE_NOINPUT
#endif
#if defined(CLEAN_ALL) || defined(GATEWAY_VERSION)
	rm -f */graph.o */ssSRAMrdwt.o */z_locale.o 
#endif

cleancode:				# リンクだけをやり直す
	rm -f */$(CODESEGMENT)
cleanbootseg:				# リンクだけをやり直す
	rm -f */$(BOOTSEGMENT)
cleanrom:				# makeromだけをやり直す
	rm -f */rom
cleandepend:				# Makedependだけを消す
	rm -f */Makedepend
data:
	cd $(ZELDA_DATA); coall; shape_all

scene:
	cd $(ZELDA_DATA); $(TOOLBIN)/scene_make

keep:
	cd $(ZELDA_DATA); keep

dma_make::
	cd $(ZELDA_DATA); dma_make

# ROM用バージョンの作成
rom_x::
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_X)
	@echo ": Leaving directory \`./rom_x/'"

# デバッグバージョン
rom_d::
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_D)
	@echo ": Leaving directory \`./rom_d/'"

# Ｃ＋＋バージョン
rom_c::
	@echo ": Entering directory \`./rom_c/'"
	mkdirhier rom_c
	cd rom_c; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_C)
	@echo ": Leaving directory \`./rom_c/'"

# Ｃ＋＋バージョン
cpptest:
	@echo ": Entering directory \`./rom_c/'"
	mkdirhier rom_c
	cd rom_c; $(MAKE) $(MAKEFLAGS) $(TARGET) $(MAKEOPTION_C)
	@echo ": Leaving directory \`./rom_c/'"

# 最終ＲＯＭバージョン
rom_f::
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_F)
	@echo ": Leaving directory \`./rom_f/'"

# ショウバージョン
rom_s::
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

romPP_d::
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_D)
	-(cd rom_d; $(MAKEMASK) romPP)		#HIRATSU Daisuke modified this line.
	@echo ": Leaving directory \`./rom_d/'"

romPP_x::
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_X)
	-(cd rom_x; $(MAKEMASK) romPP)		#HIRATSU Daisuke modified this line.
	@echo ": Leaving directory \`./rom_x/'"

romPP_f::
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_F)
	-(cd rom_f; $(MAKEMASK) romPP)		#HIRATSU Daisuke modified this line.
	@echo ": Leaving directory \`./rom_f/'"

romPP_s::
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

romPP:rom
#	../zelda_press -p1
	../zelda_press -p2
	@-if [ \( ${USER} = "###yoshida" -o ${USER} = "###hayakawa" \) -a -f /home/iwawaki/AIFC_FILES/capture.mv ]; then \
	    movieplayer -l 0 -N -z 0.5 -b q -v /home/iwawaki/AIFC_FILES/capture.mv > /dev/null; \
	else \
	    if [ -x ../bell.sh ]; then \
		    ../bell.sh; \
	    else \
	        if [ -x ./bell.sh ]; then \
		        ./bell.sh; \
	        fi; \
	    fi; \
	fi

rom_d/rom::rom_d
rom_x/rom::rom_x
rom_f/rom::rom_f
rom_s/rom::rom_s
rom_d/romPP::romPP_d
rom_x/romPP::romPP_x
rom_f/romPP::romPP_f
rom_s/romPP::romPP_s

install::
	-rm /project/ZELDA/ROM/rom
	cp rom_d/rom /project/ZELDA/ROM/rom_d
	cp rom_x/rom /project/ZELDA/ROM/rom_x
	cp rom_f/rom /project/ZELDA/ROM/rom_f
	cp rom_s/rom /project/ZELDA/ROM/rom_s
	ln /project/ZELDA/ROM/rom_d /project/ZELDA/ROM/rom_d_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_x /project/ZELDA/ROM/rom_x_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_f /project/ZELDA/ROM/rom_f_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_s /project/ZELDA/ROM/rom_s_`date '+%y-%m-%d_%H:%M:%S'`

main.o:sys_heap.h
z_actor_dlftbls.o:z_actor_dlftbls.decl
z_actor_profile.o:z_actor_dlftbls.decl
z_scene.o:z_actor_dlftbls.decl

genfiles:spec_seg_ovl.inc spec_inc_ovl.inc camera_params
z_segment.decl:spec.i
	grep include spec.i | \
grep -v "\." | \
grep -v '"nullsegment"' | \
grep -v '"hilite"' | \
grep -v '"fifobuffer"' | \
grep -v '"yieldbuffer"' | \
grep -v '"SystemDynamic"' | \
grep -v '"dramstackbuffer"' | \
grep -v '"yieldbuffer"' | \
grep -v '"zbuffer"' | \
grep -v '"rcp_cfb"' | \
grep -v '"rcp_zb"' | \
grep -v '"Audioheap"' | \
grep -v '"SystemHeap"' | \
grep -v '"object_go2"' | \
grep -v '"object_stk"' | \
grep -v '"object_gate"' | \
sed -e 's/[ 	]*include[ 	]*"\(.*\)"[ 	]*/_DECL_(\1)/' > z_segment.decl.tmp
	mv z_segment.decl.tmp z_segment.decl

../rom_d/z_segment.decl:z_segment.decl
../rom_x/z_segment.decl:z_segment.decl
../rom_f/z_segment.decl:z_segment.decl
../rom_s/z_segment.decl:z_segment.decl
../rom_c/z_segment.decl:z_segment.decl
spec_seg_ovl.inc:spec_ovl.dat make_spec_seg_ovl.sh
	make_spec_seg_ovl.sh < spec_ovl.dat > spec_seg_ovl.inc~$$$$~ && mv spec_seg_ovl.inc~$$$$~ spec_seg_ovl.inc
spec_inc_ovl.inc:spec_ovl.dat make_spec_inc_ovl.sh
	make_spec_inc_ovl.sh < spec_ovl.dat > spec_inc_ovl.inc~$$$$~ && mv spec_inc_ovl.inc~$$$$~ spec_inc_ovl.inc

z_std_dma.o:z_segment.decl
z_std_dma_data.o:z_segment.decl

# 依存ファイル(depend)をつくる
DEPEND_FILES = $(COBJECTS:.o=.dep)
.SUFFIXES : .dep
.c.dep :
	$(CC) $(CFLAGS) -M $(.IMPSRC) > $(.PREFIX).dep
.cxx.dep .C.dep .c++.dep :
	$(CXX) $(CXXFLAGS) -M $(.IMPSRC) > $(.PREFIX).dep
depend : $(DEPEND_FILES)
test:test.o
	cc -non_shared -o test test.o
touch_z_actor_dlftbls.decl:
	@echo "z_actor_dlftbls.declの順番は大丈夫ですか？"
	touch 01010001 z_actor_dlftbls.decl
	touch 01010000 rom_[dfxs]/z_actor.o rom_[dfxs]/z_actor_dlftbls.o
#ifmake fluff
GCDEFS = $(HW_FLAGS) -F
#endif

## 木村さんにロムを渡す
#z_en_oA2.o:z_en_oA2_inWater.c

ikuiku_d:
	cp rom_d/rom /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/rom_d
ikuiku_f:
	cp rom_f/romPP /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/romPP_f
ikuiku_x:
	cp rom_x/romPP /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/romPP_x



#HIRATSU Daiuske added below lines.
#if ($(LOCALE)=="CHINA")
CFLAGS +=  -DCHINA 
#endif
z_actor.o : z_actor.c
	$(CC) $(CFLAGS) -c ../z_actor.c

z_common_data.o : z_common_data.c
	$(CC) $(CFLAGS) -c ../z_common_data.c

z_construct.o : z_construct.c
	$(CC) $(CFLAGS) -c ../z_construct.c

z_en_mag.o : z_en_mag.c
	$(CC) $(CFLAGS) -c ../z_en_mag.c

z_file_choose.o : z_file_choose.c
	$(CC) $(CFLAGS) -c ../z_file_choose.c

z_file_nameset.o : z_file_nameset.c
	$(CC) $(CFLAGS) -c ../z_file_nameset.c

z_fishing.o : z_fishing.c
	$(CC) $(CFLAGS) -c ../z_fishing.c

z_kaleido_map.o : z_kaleido_map.c
	$(CC) $(CFLAGS) -c ../z_kaleido_map.c

z_kaleido_scope.o : z_kaleido_scope.c
	$(CC) $(CFLAGS) -c ../z_kaleido_scope.c

z_locale.o : z_locale.c
	$(CC) $(CFLAGS) -c ../z_locale.c

z_message.o : z_message.c
	$(CC) $(CFLAGS) -c ../z_message.c

z_parameter.o : z_parameter.c
	$(CC) $(CFLAGS) -c ../z_parameter.c

z_sram.o : z_sram.c
	$(CC) $(CFLAGS) -c ../z_sram.c

z_title.o : z_title.c
	$(CC) $(CFLAGS) -c ../z_title.c

z_opening.o : z_opening.c
	$(CC) $(CFLAGS) -c ../z_opening.c

z_file_copy_del.o : z_file_copy_del.c
	$(CC) $(CFLAGS) -c ../z_file_copy_del.c

z_file_choose_data.o : z_file_choose_data.c
	$(CC) $(CFLAGS) -c ../z_file_choose_data.c

z_std_dma_slid.o : z_std_dma_slid.c
	$(CC) $(CFLAGS) -c ../z_std_dma_slid.c

z_kanfont.o : z_kanfont.c
	$(CC) $(CFLAGS) -c ../z_kanfont.c

clean_f:
	rm -f rom_f/zelda rom_f/rom rom_f/romP rom_f/romPP
	rm -f rom_f/bootsegment.map rom_f/codesegment.map rom_f/dmadata.map rom_f/rom.map rom_f/z_file_choose_segment.map rom_f/z_kaleido_segment.map rom_f/z_vr_box_segment.map
	find rom_f -name \*.rel -print |xargs rm -f 
	find rom_f -name \*.d -print |xargs rm -f 
	find rom_f -name \*.szs -print |xargs rm -f 
#	rm -f rom_f/*.rel 
#	rm -f rom_f/*.d 
#	rm -f rom_f/*.szs
	rm -f rom_f/*.stdout
	rm -f rom_f/version.o rom_f/z_std_dma_slid.o rom_f/z_kaleido_segment.o rom_f/z_vr_box_segment.o rom_f/z_file_choose_segment.o rom_f/bootsegment.o rom_f/codesegment.o rom_f/z_file_choose_data.o rom_f/z_file_copy_del.o rom_f/z_title.o rom_f/z_opening.o rom_f/z_kanfont.o
	rm -f rom_f/version_data.h
