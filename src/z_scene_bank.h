/*
 * $Id: z_scene_bank.h,v 2.1 1998/10/22 11:51:48 zelda Exp $
 *
 *   バンクデータ定義
 *
 * $Log: z_scene_bank.h,v $
 * Revision 2.1  1998/10/22  11:51:48  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.154  1998/08/20 02:51:48  hayakawa
 * object_exchange_bank_max に Object_Bank_MAX の値が入るようにした
 *
 * Revision 1.153  1998-06-04 22:05:14+09  hayakawa
 * もういいでしょう
 * enum タグ追加
 *
 * Revision 1.152  1998-06-02 09:52:52+09  zelda
 * *** empty log message ***
 *
 * Revision 1.151  1998-06-02 09:47:13+09  zelda
 * decl00にダミーを割り当てるのを忘れてた。
 *
 * Revision 1.1  1997/05/31  06:32:39  iwawaki
 * Initial revision
 *
 */

#ifndef INCLUDE_Z_SCENE_BANK_H
#define INCLUDE_Z_SCENE_BANK_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_scene_h.h"		/* Object_Bank */
#include "z_play_h.h"		/* Rom_Address */

/************************************************************************
 *
 *	入れ替えオブジェクトシェイプバンク
 *
 ************************************************************************/
enum Object_Bank_e {
    Object_Bank_Non,	 	/* 無し */
    
#define decl(ename, sname) 	Object_Bank_##ename,
#define decl0(ename, sname)	__dummy__##Object_Bank_##ename,
#include "z_scene_bank.decl"
#undef decl
#undef decl0
    
    Object_Bank_MAX		/* 最後に置いて下さい */
};

/************************************************************************
 *
 *	プレイヤーバンクデータ
 *
 ************************************************************************/
extern Object_Bank object_exchange_player_bank[2];

/************************************************************************
 *
 *	オブジェクト入れ替えバンクデータテーブル
 *
 ************************************************************************/
extern unsigned int object_exchange_bank_max;
extern Rom_Address object_exchange_rom_address[];

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif
/*** z_scene_bank.h end ***/
