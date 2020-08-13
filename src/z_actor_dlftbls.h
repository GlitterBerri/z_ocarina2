/*
 * $Id: z_actor_dlftbls.h,v 2.1 1998-10-22 20:45:49+09 zelda Exp $
 *
 * $Log: z_actor_dlftbls.h,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.16  1998/08/28 09:59:14  hayakawa
 * warning対策
 *
 * Revision 1.15  1998-08-20 17:51:51+09  hayakawa
 * actor_dlftbls_show_info
 * actor_dlftbls_init
 * actor_dlftbls_cleanup
 * actor_dlftbls_num
 *
 * Revision 1.14  1998-06-26 21:53:39+09  hayakawa
 * HAYAKAWA_TESTdecl正式採用により削除
 *
 * Revision 1.13  1998-06-15 19:23:48+09  hayakawa
 * HAYAKAWA_TESTdeclの処理だけにしてテスト
 *
 * Revision 1.12  1998-06-11 16:10:46+09  hayakawa
 * decl5追加
 *
 * Revision 1.11  1998-05-28 11:02:13+09  hayakawa
 * 構造体メンバ変更
 * マクロ追加
 *
 * Revision 1.10  1998-05-14 10:29:02+09  zelda
 * マクロエラー対策
 *
 * Revision 1.9  1998-04-22 13:30:37+09  hayakawa
 * 条件コンパイルによってワーニングやエラーが出ていたのを修正
 *
 * Revision 1.8  1998-04-21 18:51:29+09  hayakawa
 * z_actor_dlftbls.declにz_actor_list.hを統合準備
 *
 * Revision 1.7  1998-04-14 17:29:15+09  hayakawa
 * Actor_profile_dlftblのメンバを追加しました
 * actor_dlftbl_GetSegNameマクロを追加
 * 魔法入れ替えテスト
 *
 * Revision 1.6  1998-03-27 15:27:16+09  hayakawa
 * Actor_profile_dlftblのメンバのconstをはずした
 *
 * Revision 1.5  1998/03/19  10:32:18  sakakibara
 * *** empty log message ***
 *
 * Revision 1.4  1998/03/10  04:42:07  hayakawa
 * 条件コンパイルで構造体のサイズが変わらないようにした
 *
 * Revision 1.3  1998/03/06  04:51:50  hayakawa
 * メモリ節約のためにセグメント名テーブルを使わないようにした
 *
 * Revision 1.2  1997/08/25  13:53:06  hayakawa
 * セグメント名（デバッグ用）追加
 * player対応
 *
 * Revision 1.1  1997/08/25  07:02:46  hayakawa
 * Initial revision
 *
 */

#ifndef Z_ACTOR_DLFTBLS_H
#define Z_ACTOR_DLFTBLS_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_actor.h"		/* Actor_profile */

/*
 * アクタープロファイルクラス定義
 */
typedef struct {
    u32 SegmentRomStart;	/* _nameSegmentRomStart */
    u32 SegmentRomEnd;		/* _nameSegmentRomEnd */
    char *SegmentStart;		/* _nameSegmentStart */
    char *SegmentEnd;		/* _nameSegmentEnd */
    char *allocp;		/* セグメントを配置した実際のアドレス */
    Actor_profile *profile;	/* profileの仮想アドレス */
#ifdef USE_ACTOR_NAME_TABLE
    char *segname;		/* セグメント名（デバッグ用） */
#else
    char *__segname;		/* 構造体のサイズが変わらないように */
#endif /* USE_ACTOR_NAME_TABLE */
    u16 flags;			/* bit0:解放可能 */
    s8  clients;		/* クライアント数 */
    u8  status;			/* bit0:ロード中 bit1:常駐 */
} Actor_profile_dlftbl;
typedef Actor_profile_dlftbl DLFTBL_ACTOR;

/*
 * セグメント名取得
 */
#ifdef USE_ACTOR_NAME_TABLE
#define actor_dlftbl_GetSegName(t) ((t)->segname ? (t)->segname : "")
#else
#define actor_dlftbl_GetSegName(t) ((void)(t), "")
#endif

typedef enum {
#define decl(name) ACTOR_DLF_##name,
#define decl0(name1, name2) _filler_ACTOR_DLF_ ## name1 ## _filler_,
#define decl1(name1, name2) decl(name1)
#define decl2(name1, name2) decl(name1)
#define decl3(name1, name2) decl(name1)
#define decl4(name1, name2) decl(name1)
#define decl5(name1, name2) decl(name1)
#include "z_actor_dlftbls.decl"
#undef decl
#undef decl0
#undef decl1
#undef decl2
#undef decl3
#undef decl4
#undef decl5
    ACTOR_DLF_MAX
} actor_dlftbls_e;

/*
 * アクタープロファイルのポインタを取得
 */
#define actor_dlftbl_profile(actor_dlftbl) \
(((actor_dlftbl)->allocp == NULL) ? ((actor_dlftbl)->profile) : \
 ((actor_dlftbl)->profile) - ((actor_dlftbl)->SegmentStart) + ((actor_dlftbl)->allocp))

/*
 * グローバル変数宣言
 */
extern unsigned int actor_dlftbls_num; /* actor_dlftblsの要素数 */
extern DLFTBL_ACTOR actor_dlftbls[];

/*
 * グローバル関数宣言
 */
/*
 * テーブル情報表示
 * （デバッグ用）
 */
extern void
actor_dlftbls_show_info(void);
/*
 * 初期化
 */
extern void
actor_dlftbls_init(void);
/*
 * 後始末
 */
extern void
actor_dlftbls_cleanup(void);


#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* Z_ACTOR_DLFTBLS_H */
