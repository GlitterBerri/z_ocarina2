/* $Id: z_save_area_h.h,v 2.1 1998-10-22 20:51:48+09 zelda Exp $
 * $Log: z_save_area_h.h,v $
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * £Ò£Ï£Í½Ð¤·¥Ð¡¼¥¸¥ç¥ó(NTSC)
 *
 * Revision 1.100  1998/10/17 08:55:48  soejima
 * *** empty log message ***
 *
 * Revision 1.99  1998-10-17 14:59:35+09  soejima
 * *** empty log message ***
 *
 * Revision 1.98  1998-10-09 16:27:39+09  soejima
 * *** empty log message ***
 *
 * Revision 1.97  1998-10-07 23:06:12+09  soejima
 * *** empty log message ***
 *
 * Revision 1.96  1998-09-30 16:13:55+09  soejima
 * *** empty log message ***
 *
 * Revision 1.95  1998-09-30 16:11:44+09  soejima
 * *** empty log message ***
 *
 * Revision 1.94  1998-09-29 10:42:08+09  soejima
 * *** empty log message ***
 *
 * Revision 1.93  1998-09-23 19:15:52+09  nisiwaki
 * *** empty log message ***
 *
 * Revision 1.92  1998-09-21 22:48:04+09  soejima
 * *** empty log message ***
 *
 * Revision 1.91  1998-09-18 20:39:56+09  soejima
 * *** empty log message ***
 *
 * Revision 1.90  1998-09-18 18:20:15+09  soejima
 * *** empty log message ***
 *
 * Revision 1.89  1998-09-18 14:26:57+09  soejima
 * *** empty log message ***
 *
 * Revision 1.88  1998-09-17 16:55:26+09  soejima
 * *** empty log message ***
 *
 * Revision 1.87  1998-09-15 23:05:39+09  soejima
 * *** empty log message ***
 *
 * Revision 1.86  1998-09-10 22:58:59+09  soejima
 * *** empty log message ***
 *
 * Revision 1.1  1997/09/27  04:43:22  soejima
 * Initial revision
 * $LogÄÉ²Ã
 * */


#ifndef INCLUDE_Z_SAVE_AREA_H_H
#define INCLUDE_Z_SAVE_AREA_H_H

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include "z_common_data.h"

/************************************************************************
 *									*
 *	¥»¡¼¥Ö¡¦¥¨¥ê¥¢							*
 *				1997Ç¯09·î25Æü(ÌÚÍËÆü) 11»þ00Ê¬00ÉÃ JST *
 ************************************************************************/
/*======================================================================*/
/*======================================================================*/
/* £Â£É£Ô ¥Æ¡¼¥Ö¥ë */
extern long
check_bit[];

/* £Â£é£ô¥Á¥§¥Ã¥¯¡¦¥Ç¡¼¥¿ */
extern unshort
bit_check_data[];
extern unshort
bit_and_data[];
extern long
non_equip_bit[];
/* £Â£é£ô¥·¥Õ¥È¡¦¥Ç¡¼¥¿ */
extern unchar
bit_shift_data[];
extern unchar
non_equip_shift[];
/* ¥¢¥¤¥Æ¥à£Í£Á£ØÃÍ¥Ç¡¼¥¿ */
extern unshort
item_max_data[][4];

/* ¶â¥¹¥¿¥ë¥Á¥å¥é¡¦¥Ç¡¼¥¿ */
extern unsigned long
bit_check_kinsta[];
extern unsigned long
bit_shift_kinsta[];

/* ¥¢¥¤¥Æ¥à¡¦¥Ç¡¼¥¿ ¥Æ¡¼¥Ö¥ë */
extern unchar
*item_data[];

extern unchar number_pt[];


/* ÁõÈ÷¥¢¥¤¥Æ¥àÅÐÏ¿ */
extern void
SetEquip_Item( short no, unshort pt );
/* ÁõÈ÷¥¢¥¤¥Æ¥àËõ¾Ã */
extern char
ClearEquip_Item( Game_play *game_play, short no );
/* ÈóÁõÈ÷¥¢¥¤¥Æ¥àÅÐÏ¿ */
extern void
Set_Non_Equip_Register( short no, short pt );





/*======================================================================*/
/*======================================================================*/
#define	S_Private		z_common_data.memory.privatef
#define	S_Used			z_common_data.memory.used
#define	S_Table			z_common_data.memory.table
#define	S_Save			z_common_data.memory.save
#define	S_Information		z_common_data.memory.information

/*
 * £Ð£ò£é£ö£á£ô£å
 */
#define Save_Ct			S_Private.savect
#define Player_Name		S_Private.player_name
#define F_64DD			S_Private.f_64dd
#define LIFE_CHECK		(S_Private.max_life == S_Private.now_life)
#define MAGIC_MAX		S_Private.magic_max
#define MAGIC_NOW		S_Private.magic_now
#define MAGIC_CHECK		( MAGIC_NOW == Z_MAGIC_NOW_MAX )
#define LONG_SWORD_HP		S_Private.long_sword_hp
#define NAVI_TIMER		S_Private.navi_timer
#define MAGIC_MODE		S_Private.magic_mode
#define SWORD_ABILITY		S_Private.sword_ability
#define MAGIC_ABILITY		S_Private.magic_ability
#define LIFE_ABILITY		S_Private.life_ability
#define LAST_SWORD		S_Private.last_sword
#define OCARINA_ROUND		S_Private.ocarina_round
/* »Ò¶¡»þÁõÈ÷ */
#define Child_Register_Item( no )	S_Private.child_register_item[no]
#define Child_Register_Item_Pt( no )	S_Private.child_register_item_pt[no-1]
#define Child_Equip_Item		S_Private.child_equip_item
/* Âç¿Í»þÁõÈ÷ */
#define Adult_Register_Item( no )	S_Private.adult_register_item[no]
#define Adult_Register_Item_Pt( no )	S_Private.adult_register_item_pt[no-1]
#define Adult_Equip_Item		S_Private.adult_equip_item
/* £×£Á£Ò£Ð */
#define WARP_Pos_X			S_Private.position.x
#define WARP_Pos_Y			S_Private.position.y
#define WARP_Pos_Z			S_Private.position.z
#define WARP_Angle			S_Private.angle_y
#define WARP_Scene_No			S_Private.scene
#define WARP_room_ID			S_Private.room_ID
#define WARP_FLAG			S_Private.flag
/* ¥·¡¼¥ó¥Ç¡¼¥¿£Î£ï */
#define SCENE_DATA_ID			S_Private.scene_data_ID


/*
 * £Õ£ó£å£ä
 */
#define Register_Item( no )	S_Used.register_item[no]
#define Register_Item_Pt( no )	S_Used.register_item_pt[no-1]
#define Equip_Item		S_Used.equip_item
/* £Á¥Ü¥¿¥ó¥¢¥¤¥Æ¥à */
#define	A_BUTTON_ITEM		( (Z_BTN_ITEM(0) == 0xff) ? (0xff) : ((Register_Item(0) == H_sword_3) ? H_sword_2 : S_Used.register_item[0]) )
/* £Ã¥Ü¥¿¥ó¥¢¥¤¥Æ¥à */
////////#define	C_BUTTON_ITEM( no )	S_Used.register_item[no]
////////#define	C_BUTTON_ITEM( no )	( (Register_Item(0) == H_bow || Z_BTN_ITEM(0) == 0xff) ? (0xff) : (S_Used.register_item[no]) )
////#define	C_BUTTON_ITEM( no )	( (C_ALPHA( no ) == 0xff ) ? (S_Used.register_item[no]) : 0xff )
#define	C_BUTTON_ITEM( no )	( (Z_BTN_ITEM(no) != 0xff ) ? (S_Used.register_item[no]) : 0xff )
/* ÁõÈ÷¥¢¥¤¥Æ¥à */
#define	EQUIPMENT_ITEM( no )	( (Equip_Item & bit_check_data[no]) >> bit_shift_data[no] )

/*
 * £Ô£á£â£ì£å
 */
#define Item_Register(no)	S_Table.item_register[no]
#define Item_Register_Set(item)	(S_Table.item_register[number_pt[item]] = item)
#define Get_Item_Register(item)	(S_Table.item_register[number_pt[item]])
#define Item_Count(no)		S_Table.item_count[number_pt[no]]

#define Equip_Register  	S_Table.equip_register
#define Equip_Sword_CK(item_no)  (S_Table.equip_register & ( check_bit[item_no-H_sword_0] << bit_shift_data[E_Sword]))		/* ÁõÈ÷·Ï·õ */
#define Equip_Shield_CK(item_no)  (S_Table.equip_register & ( check_bit[item_no-H_shield_1] << bit_shift_data[E_Shield]))	/* ÁõÈ÷·Ï½â */
#define Equip_Clothes_CK(item_no)  (S_Table.equip_register & ( check_bit[item_no-H_clothes_1] << bit_shift_data[E_Clothes]))	/* ÁõÈ÷·ÏÉþ */
#define Equip_Boots_CK(item_no)  (S_Table.equip_register & ( check_bit[item_no-H_boots_1] << bit_shift_data[E_Boots]))		/* ÁõÈ÷·Ï·¤ */
#define SetEquip_Register(no, pt)  	(Equip_Register |= (pt << bit_shift_data[no]))
#define EorEquip_Register(no, pt)  	(Equip_Register ^= (pt << bit_shift_data[no]))
#define GetEquip_Register(no)  		((Equip_Register & bit_check_data[no]) >> bit_shift_data[no])
#define CKEquip_Register(no)  		(S_Table.equip_register & check_bit[no])

#define NON_EQUIP_REGISTER		(S_Table.non_equip_register)
#define Non_Equip_Register(no)	((NON_EQUIP_REGISTER & non_equip_bit[no]) >> non_equip_shift[no])
#define Equip_Bow		(Non_Equip_Register(NE_Bow))		/* ÌðÎ©¤Æ */
#define Equip_Bomb		(Non_Equip_Register(NE_Bomb)) 		/* ÇúÃÆÂÞ */
#define Equip_Grove		(Non_Equip_Register(NE_Grove)) 		/* ¥°¥í¡¼¥Ö */
#define Equip_Scale		(Non_Equip_Register(NE_Scale)) 		/* ¥¦¥í¥³ */
#define Equip_Purse		(Non_Equip_Register(NE_Purse)) 		/* ºâÉÛ */
#define Equip_Pachinko		(Non_Equip_Register(NE_Pachinko)) 	/* ¥Ñ¥Á¥ó¥³ */
#define Equip_Stick		(Non_Equip_Register(NE_Stick)) 		/* ¥Ç¥¯¤ÎËÀ */
#define Equip_Deck_Nut		(Non_Equip_Register(NE_Deck_Nut)) 	/* ¥Ç¥¯¤Î¼Â */

#define Item_MaxGet(no)		(item_max_data[no][Non_Equip_Register(no)])

#define Collect_Register(no)	(S_Table.collect_register & check_bit[no])
#define HeartCt			0x10000000
#define HeartPt			0xF0000000
#define HeartMax		0x40000000
#define Collect_Heart		(S_Table.collect_register & HeartPt)
#define GetCollect_Heart	((Collect_Heart & HeartPt) >> 28)
#define SetCollect_SEAL(no)	(S_Table.collect_register |= check_bit[no - H_seal_medal_1])
#define GetCollect_SEAL(no)	(S_Table.collect_register & check_bit[no - H_seal_medal_1])
#define SetCollect_MELODY(no)	(S_Table.collect_register |= check_bit[C_SEAL + (no - H_melody_1)])
#define GetCollect_MELODY(no)	(S_Table.collect_register & check_bit[C_SEAL + (no - H_melody_1)])
#define SetCollect_HOLY(no)	(S_Table.collect_register |= check_bit[C_SEAL + C_MELODY + (no - H_holystone_1)])
#define GetCollect_HOLY(no)	(S_Table.collect_register & check_bit[C_SEAL + C_MELODY + (no - H_holystone_1)])
#define SetCollect_ITEM(no)	(S_Table.collect_register |= check_bit[C_SEAL + C_MELODY + C_HOLY + (no - H_shake_stone)])
#define GetCollect_ITEM(no)	(S_Table.collect_register & check_bit[C_SEAL + C_MELODY + C_HOLY + (no - H_shake_stone)])

#define SetKeyCompassMap(i0,i1)	(S_Table.key_compass_map[i0] |= check_bit[i1-H_boss_key])
#define GetKeyCompassMap(i0,i1)	(S_Table.key_compass_map[i0] & check_bit[i1-H_boss_key])
#define RSetKeyCompassMap(i0,i1) (S_Table.key_compass_map[i0] ^= check_bit[i1-H_boss_key])
#define EorKeyCompassMap(dj, pt) (S_Table.key_compass_map[dj] ^= pt)

#define Key_Reg( id ) 		S_Table.key_register[ id ]

#define	Heart_Status		S_Table.key_register[19]	/* ¥Ï¡¼¥ÈÀ©¸æ */

#define N_COIN_TOTAL		S_Table.n_coin_total

/*
 * £É£î£æ£ï£ò£í£á£ô£é£ï£î
 */
#define Room_Inf		S_Information.room_inf
#define Inf_Box			0
#define Inf_Switch		1
#define Inf_Enemy		2
#define Inf_Item0		3
#define Inf_Item1		4
#define Inf_Room		5
#define Inf_Floor		6


/* É÷¼Ù¤ÎËâË¡¡Ê£±£²£´¡¢£±£²£µ¡Ë*/
#define Get_WM_P_POSX( data )		(Room_Inf[124][0])
#define Get_WM_P_POSY( data )		(Room_Inf[124][1])
#define Get_WM_P_POSZ( data )		(Room_Inf[124][2])
#define Get_WM_P_ANGLEY( data )		(Room_Inf[124][3])
#define Get_WM_P_MODE( data )		(Room_Inf[124][4])
#define Get_WM_SCENE( data )		(Room_Inf[124][5])
#define Get_WM_R_ID( data )		(Room_Inf[124][6])
#define Get_WM_WORK( data )		(Room_Inf[125][0])
#define Get_WM_SW2( data )		(Room_Inf[125][1])
#define Get_WM_ITEM2( data )		(Room_Inf[125][2])

#define Set_WM_P_POSX( data )		(Room_Inf[124][0] = data)
#define Set_WM_P_POSY( data )		(Room_Inf[124][1] = data)
#define Set_WM_P_POSZ( data )		(Room_Inf[124][2] = data)
#define Set_WM_P_ANGLEY( data )		(Room_Inf[124][3] = data)
#define Set_WM_P_MODE( data )		(Room_Inf[124][4] = data)
#define Set_WM_SCENE( data )		(Room_Inf[124][5] = data)
#define Set_WM_R_ID( data )		(Room_Inf[124][6] = data)
#define Set_WM_WORK( data )		(Room_Inf[125][0] = data)
#define Set_WM_SW2( data )		(Room_Inf[125][1] = data)
#define Set_WM_ITEM2( data )		(Room_Inf[125][2] = data)

/* ¶â¥¹¥¿¥ë¥Á¥å¥é¡Ê£±£²£¶¡Ë*/
#define Get_KIN_STA( no ) 		(((unsigned long)Room_Inf[126][no>>2] & bit_check_kinsta[no&0x3]) >> bit_shift_kinsta[no&0x3])
#define Set_KIN_STA( no, data ) 	(Room_Inf[126][no>>2] |= ((long)data << bit_shift_kinsta[no&0x3]))


/* ¥Ï¥¤¥¹¥³¥¢¡Ê£±£²£·¡Ë*/
/* ¢­¢­¢­¢­¢­ point ¢­¢­¢­¢­¢­ */
#define HS_YABU			0	/* Î®Å­ÇÏ */
#define HS_POW			1	/* ¥Ý¨¡ */
#define HS_FISH			2	/* ¤Ä¤ê */
#define HS_EPONA		3	/* ¥¨¥Ý¥Ê¥ì¡¼¥¹ */
#define HS_MARASON		4	/* ¥Þ¥é¥½¥ó¥Þ¥ó */
#define HS_DANPI		6	/* ¥À¥ó¥Ú¥¤¥ì¡¼¥¹ */
/* ¢¬¢¬¢¬¢¬¢¬ point ¢¬¢¬¢¬¢¬¢¬ */
#define HI_SCORE( point )	Room_Inf[127][point]




/* £Å£Ö£Å£Î£Ô¥Á¥§¥Ã¥¯£Â£é£ô¾ðÊó */
#define Event_Chk_Inf( no )		(S_Information.event_chk_inf[no])
#define Get_Event_Chk_Inf( no, data ) (Event_Chk_Inf( no ) & data)
#define Set_Event_Chk_Inf( no, data ) (Event_Chk_Inf( no ) |= data)
/* ¥¢¥¤¥Æ¥à¼èÆÀ¾ðÊó */
#define Item_Get_Inf( no )		(S_Information.item_get_inf[no])
#define Get_Item_Get_Inf( no, data ) 	(Item_Get_Inf( no ) & data)
#define Set_Item_Get_Inf( no, data ) 	(Item_Get_Inf( no ) |= data)
/* ¥á¥Ã¥»¡¼¥¸¥Á¥§¥Ã¥¯£Â£é£ô¾ðÊó */
#define Inf_Table( no ) 		(S_Information.inf_table[no])
#define Get_Inf_Table( no, data ) 	(Inf_Table( no ) & data)
#define Set_Inf_Table( no, data ) 	(Inf_Table( no ) |= data)
#define Set_Dungeon_Bit( scene_id ) 	(Inf_Table( 26 ) |= check_bit[scene_id])
#define HOLD_SWORD			Inf_Table( 29 )

/* ¥ª¥«¥ê¥ÊÏ¿²»¥Õ¥é¥° */
#define	OCA_REC_FLAG			S_Information.oca_rec_flag
/* °Æ»³»Ò£¸²»Ï¿²»¥Õ¥é¥° */
#define	OCA_REC_FLAG8			S_Information.oca_rec_flag8

/*
 * £Ó£á£ö£å
 */
#define Check_Sum		S_Save.check_sum
    

/*  */
#define EVENT_FG		z_common_data.event_fg
#define EVENT_TM		z_common_data.event_tm
#define TOTAL_EVENT_FG		z_common_data.total_event_fg
#define TOTAL_EVENT_TM		z_common_data.total_event_tm
/*  */
#define Z_BTN_ITEM(button)	z_common_data.button_item[button]	
#define Z_CK_FG			z_common_data.ck_fg
#define Z_ALPHA_TYPE		z_common_data.alpha_type
#define Z_PREV_ALPHA_TYPE	z_common_data.prev_alpha_type
#define LAST_TIME_TYPE		z_common_data.last_time_type
#define Z_ALPHA_COUNT		z_common_data.alpha_count
#define Z_MAGIC_NOW_MAX		z_common_data.magic_now_max
#define Z_MAGIC_NOW_NOW		z_common_data.magic_now_now
#define Z_MAGIC_USED		z_common_data.magic_used
/*  */
#define EVENT_INF(no)		z_common_data.event_inf[no]
#define G_EVENT_INF(no, data)	(EVENT_INF(no) & data)
#define S_EVENT_INF(no, data)	(EVENT_INF(no) |= data)

#define Scene_ID		z_common_data.scene_ID

#define Yabusame_Mode		z_common_data.yabusame_mode
#define Yabusame_Total		z_common_data.yabusame_total

/* £°¡§£Ê£Á£Ð£Á£Î ¡¿ £±¡§£Î£Å£Ó */
#define	J_N			z_common_data.j_n
/* £Ó£Ï£Õ£Î£Ä ¥¹¥Æ¥ì¥ª¡¿¥â¥Î¥é¥ë¡¿¥Ø¥Ã¥É¥Û¥ó¡¿£³£Ä */
#define	S_SOUND			z_common_data.s_sound
/* ¸À¸ì */
#define	LANGUAGE		z_common_data.language
/* £ÚÃíÌÜÊýË¡ £°¡§¥¹¥¤¥Ã¥Á¡¿£±¡§¥Û¡¼¥ë¥É */
#define	Z_ATTENTION		z_common_data.z_attention

/*  */
#define No_Save			z_common_data.no_save

/*  */
/*  */



/* £È£ï£ò£ó£å */
#define	H_Spot_No		z_common_data.memory.horse.spot_no
#define	H_Horse_X		z_common_data.memory.horse.horse_x
#define	H_Horse_Y		z_common_data.memory.horse.horse_y
#define	H_Horse_Z		z_common_data.memory.horse.horse_z
#define	H_Horse_A		z_common_data.memory.horse.horse_a


/*======================================================================*/
#define	NO_CONTROLLER		(z_common_data.file_no == 0xFEDC)
/*======================================================================*/
#define 	LIFE_CT		16	/* ¥Ï¡¼¥È£±¸Ä¤ÎÍÆÎÌ */
#define		Nuts_Max	10	/* ¥Ç¥¯¤Î¼Â¤Î£Í£Á£ØÃÍ */



#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif

/*** z_save_area_h.h end ***/
