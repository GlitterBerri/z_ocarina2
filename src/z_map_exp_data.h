/*
 * $Id: z_map_exp_data.h,v 2.1 1998-10-22 21:17:25+09 zelda Exp $
 *
 * マップマークデータ
 *
 * $Log: z_map_exp_data.h,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.4  1998/10/18 05:25:27  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1998-10-09 11:56:57+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.2  1998-09-19 23:06:30+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1998-09-19 14:39:01+09  hayakawa
 * Initial revision
 *
 */

#ifndef _Z_MAP_EXP_DATA_H_
#define _Z_MAP_EXP_DATA_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_types.h"

#define NONSTATIC_MAP_EXP_DATA 1
#if NONSTATIC_MAP_EXP_DATA
#define MAP_EXP_DATA_TBL(name) (*map_exp_data_tbl_p->name)
#else
#define MAP_EXP_DATA_TBL(name) (name)
#endif

#define BOSS_NUM 		8	/* ダンジョンボスマップの数 */
#define DUNGEON_NUM 		10	/* ダンジョンマップの数 */
#define GROUND_NUM		24	/* 地上マップの数 */
#define CHECK_DUNGEON_NUM	20
#define dct			51

#define decl(type, name, proto) type (*(name)) proto ;
typedef struct {
#include "z_map_exp_data.decl"
} map_exp_data_tbl_t;
#undef decl

extern map_exp_data_tbl_t rom_map_exp_data_tbl;

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif	/* _Z_MAP_EXP_DATA_H_ */
