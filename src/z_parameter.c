/* $Id: z_parameter.c,v 2.12 1999/01/12 05:33:05 soejima Exp $
 *
 * パラメーター
 *
 * $Log: z_parameter.c,v $
 * Revision 2.12  1999/01/12  05:33:05  soejima
 * ＰＡＬ版 ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.11  1999-01-07 17:36:36+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.10  1999-01-07 13:27:12+09  soejima
 * ＧＡＴＥＷＡＹ仕様
 *
 * Revision 2.9  1998-11-12 17:51:35+09  soejima
 * *** empty log message ***
 *
 * Revision 2.8  1998-11-09 17:12:35+09  soejima
 * *** empty log message ***
 *
 * Revision 2.7  1998-11-06 13:54:55+09  soejima
 * コメント
 *
 * Revision 2.6  1998-11-05 19:51:57+09  sasaki
 * 砂漠で太陽の歌BGM イニシャル設定
 *
 * Revision 2.5  1998-11-05 18:44:33+09  soejima
 * サウンド
 *
 * Revision 2.4  1998-10-29 18:19:01+09  soejima
 * ＰＡＬ変更
 *
 * Revision 2.3  1998-10-27 21:26:46+09  soejima
 * ＰＡＬ仕様
 *
 * Revision 2.2  1998-10-23 20:15:39+09  soejima
 * わらしべＴＩＭＥ・ＵＰで、住吉インゴーフラグクリアー
 *  EVENT_INF( 0 ) = G_EVENT_INF( 0, 0x7F80 );
 *
 * Revision 2.1  1998-10-22 20:51:48+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.536  1998/10/20 03:12:30  soejima
 * *** empty log message ***
 *
 * Revision 1.535  1998-10-19 15:08:06+09  soejima
 * *** empty log message ***
 *
 * Revision 1.534  1998-10-18 18:24:39+09  sasaki
 * 魔法メーター音 デモ面時 カット
 *
 * Revision 1.533  1998-10-17 16:03:59+09  soejima
 * *** empty log message ***
 *
 * Revision 1.521  1998-10-13 11:12:33+09  soejima
 * デクの種 １０→５個へ by山田(洋)
 *
 * Revision 1.1  1996/10/08  12:35:48  soejima
 * Initial revision
 * $Log追加
 * */

#define SOEJIMA_PRINT	( 0 )

/************************************************************************
 *									*
 *	ゼルダ64 パラメーター						*
 *				1996年10月 8日(火曜日) 17時00分00秒 JST *
 *									*
 ************************************************************************/
#include "z_basic.h"
#include "z_play.h"
#include "z_player.h"
#include "z_player_lib.h"
#include "z_define1.h"
#include "z_actor.h"
#include "audio.h"
#include "assert64.h"		/* assert */
#include "padmgr.h"
#include "z_wipe.h"
#include "z_common_data.h"

#include "z_horse.h"
#include "z_parameterd.h"
#include "z_parameter_h.h"
#include "z_map_exp.h"
#include "z_scene_table.h"
#include "z_kaleido_scope_h.h"
#include "z_map_mark.h"
#include "z_opening.h"
#include "z_message_h.h"
#include"z_en_in.h"

#include "yama.c"

#if 1 /* 1998 10/6 komatu */
#include "z_en_zl3_dousa.h"
#endif


#define PR_KAREIDOSCOPE_MODE 	SREG(94) /* カレイドスコープモード */

EXTERN_DEFSEG_DATA(do_action_static);
EXTERN_DEFSEG_DATA(icon_item_static);


extern padmgr_t padmgr;

extern unsigned short h_yabusame_txt[];



extern void LifeMeterColorAnimation( Game_play * );
////////extern int initial_LifeRestChange_Damage( Game_play * );
////////extern void initial_LifeRestChange( Game_play * );
////////extern int  LifeRestChange( Game_play * );
extern void DrawLifeMeter( Game_play * );
extern void LifeMeterZoom( Game_play * );

#if 0
extern void EnemyPosConvert( Game_play *, float, float, short *, short * );
#endif

extern int player_condition_check(Game_play *game_play);

extern void flg_set(Game_play  *this);


extern unchar number_pt[];


static short	yabu_sound = 0;
/*static short	yabu_frame = 0;
static unshort	yabu_ten[3] = {
    0, 0, 0,
};*/
static unshort	yabu_total[4] = {
    0, 0, 0, 0,
};
enum {
    Yabu_Null,
    Yabu_Score,
    Yabu_Fdin,
    Yabu_Disp,
    Yabu_Fdout,
    Yabu_point
};


static unshort	navi_pt = 0;
static unshort	navi_ct = 0;

extern short 	Warashibe_item[] = {
    H_reserve_23,		/* あやしいキノコ */
    H_reserve_28,		/* メダマガエル */
    H_reserve_29,		/* 特製本生目薬 */
};
extern short 	Warashibe_before_item[] = {
    H_reserve_22,		/* コジロー */
    H_reserve_27,		/* 処方せん */
    H_reserve_27,		/* 処方せん */
};

static short	mgr = FULL_ALPHA, mgg = FULL_ALPHA, mgb = FULL_ALPHA;


static short	shift_item_no[] = {
    H_stick, H_stick,			/* H0_stick H1_stick */
    H_deku_nut, H_deku_nut,		/* H0_deku_nut H1_deku_nut */
    H_bomb_1, H_bomb_1, H_bomb_1, H_bomb_1,		/* H0_bomb_1 H1_bomb_1 H2_bomb_1 H3_bomb_1 */
    H_bow, H_bow, H_bow,		/* H0_arrow H1_arrow H2_arrow */
    H_deku_seed,			/* H0_deku_seed */
    H_bomb_2, H_bomb_2,			/* H0_bomb_2 H1_bomb_2 */
    H_stick, H_stick,			/* H0_stick H1_stick */
    H_deku_nut, H_deku_nut,		/* H0_deku_nut H1_deku_nut */
};

#define	KEY_XDP		 26	/* 鍵表示Ｘ */
#define	KEY_YDP		190	/* 鍵表示Ｙ */

static short	player_condition = 0;
static short	player_diving = 0;

/*  */
static Gfx fbdemo_fade_gfx_init[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH |
			  G_FOG | G_LIGHTING | G_TEXTURE_GEN |
			  G_TEXTURE_GEN_LINEAR | G_LOD | G_ZBUFFER),
    gsDPSetOtherModeHL(G_PM_1PRIMITIVE|G_CYC_1CYCLE|G_TP_NONE|G_TD_CLAMP|
		       G_TL_TILE|G_TT_NONE|G_TF_BILERP|G_TC_FILT|G_CK_NONE|
		       G_CD_MAGICSQ|G_AD_DISABLE,
		       G_AC_NONE|G_ZS_PIXEL|G_RM_CLD_SURF|G_RM_CLD_SURF2),
    gsDPSetCombineMode( G_CC_PRIMITIVE, G_CC_PRIMITIVE ),
    gsSPEndDisplayList(),
};



/*===============================================================
  =								=
  ===============================================================*/
extern void
alpha_change( unshort type )
{
    if ( type != Z_PREV_ALPHA_TYPE ) {
////////	LAST_TIME_TYPE = Z_PREV_ALPHA_TYPE; 	/* 前回ＴＹＰＥ */
	PRINTF("ＡＬＰＨＡーＴＹＰＥ＝%d  LAST_TIME_TYPE=%d\n",type,LAST_TIME_TYPE);
	Z_PREV_ALPHA_TYPE = Z_ALPHA_TYPE = type;
	Z_ALPHA_COUNT = 1;
    }
}

/*===============================================================
  =	   アルファ値セッテング					=
  ===============================================================*/
static void
c_alpha_set_1( Game_play *game_play, short alpha1 )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    if ( Z_BTN_ITEM(0) == 0xff ) {
	if ( parameter->b_alpha != CLEAR_ALPHA ) parameter->b_alpha = CLEAR_ALPHA;
    } else {
	if ( parameter->b_alpha != FULL_ALPHA ) parameter->b_alpha = alpha1;
    }
    if ( Z_BTN_ITEM(1) == 0xff ) {
	if ( parameter->c_alpha != CLEAR_ALPHA ) parameter->c_alpha = CLEAR_ALPHA;
    } else {
	if ( parameter->c_alpha != FULL_ALPHA ) parameter->c_alpha = alpha1;
    }
    if ( Z_BTN_ITEM(2) == 0xff ) {
	if ( parameter->c_alpha1 != CLEAR_ALPHA ) parameter->c_alpha1 = CLEAR_ALPHA;
    } else {
	if ( parameter->c_alpha1 != FULL_ALPHA ) parameter->c_alpha1 = alpha1;
    }
    if ( Z_BTN_ITEM(3) == 0xff ) {
	if ( parameter->c_alpha2 != CLEAR_ALPHA ) parameter->c_alpha2 = CLEAR_ALPHA;
    } else {
	if ( parameter->c_alpha2 != FULL_ALPHA ) parameter->c_alpha2 = alpha1;
    }
    if ( Z_BTN_ITEM(4) == 0xff ) {
	if ( parameter->a_alpha != CLEAR_ALPHA ) parameter->a_alpha = CLEAR_ALPHA;
    } else {
	if ( parameter->a_alpha != FULL_ALPHA ) parameter->a_alpha = alpha1;
    }
}
/*===============================================================
  =	   アルファ値セッテング					=
  ===============================================================*/
static void
c_alpha_set_0( Game_play *game_play, short alpha, short alpha1 )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    if ( Z_CK_FG ) {
	c_alpha_set_1( game_play, alpha1 );
    } else {
	if ( parameter->b_alpha ) {
	    if ( parameter->b_alpha > alpha ) parameter->b_alpha = alpha;
	}
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
    }
}

/*===============================================================
  =	   アルファ値セッテング					=
  ===============================================================*/
static void
alpha_setting0( Game_play *game_play, short alpha  )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    short	alpha1 = FULL_ALPHA - alpha;

    switch ( Z_ALPHA_TYPE ) {
    case 1:
    case 2:
    case 8:
	PRINTF("a_alpha=%d, c_alpha=%d   →   ",parameter->a_alpha, parameter->c_alpha);
	if ( Z_ALPHA_TYPE == 8 ) {
	    if ( parameter->b_alpha != FULL_ALPHA )     parameter->b_alpha = alpha1;
	} else {
	    if ( parameter->b_alpha ) {
		if ( parameter->b_alpha > alpha ) parameter->b_alpha = alpha;
	    }
	}
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
	if ( parameter->heart_alpha ) {
	    if ( parameter->heart_alpha > alpha ) parameter->heart_alpha = alpha;
	}
	if ( parameter->meter_alpha ) {
	    if ( parameter->meter_alpha > alpha ) parameter->meter_alpha = alpha;
	}
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	PRINTF("a_alpha=%d, c_alpha=%d\n",parameter->a_alpha, parameter->c_alpha);
	break;
	    
    case 3:
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	c_alpha_set_0( game_play, alpha, alpha1 );
	if ( parameter->meter_alpha ) {
	    if ( parameter->meter_alpha > alpha ) parameter->meter_alpha = alpha;
	}
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	break;
	
    case 4:
	if ( parameter->b_alpha ) {
	    if ( parameter->b_alpha > alpha ) parameter->b_alpha = alpha;
	}
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
	if ( parameter->heart_alpha ) {
	    if ( parameter->heart_alpha > alpha ) parameter->heart_alpha = alpha;
	}
	if ( parameter->meter_alpha ) {
	    if ( parameter->meter_alpha > alpha ) parameter->meter_alpha = alpha;
	}
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->a_alpha != FULL_ALPHA ) parameter->a_alpha = alpha1;
	break;
	
    case 5:
	c_alpha_set_0( game_play, alpha, alpha1 );
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->a_alpha != FULL_ALPHA )     parameter->a_alpha = alpha1;
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	if ( parameter->meter_alpha != FULL_ALPHA ) parameter->meter_alpha = alpha1;
	break;

    case 6:
	c_alpha_set_0( game_play, alpha, alpha1 );
	if ( parameter->a_alpha != FULL_ALPHA )     parameter->a_alpha = alpha1;
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	if ( parameter->meter_alpha != FULL_ALPHA ) parameter->meter_alpha = alpha1;
	switch ( game_play->scene_data_ID ) {
	case SPOT00:
	case SPOT01:
	case SPOT02:
	case SPOT03:
	case SPOT04:
	case SPOT05:
	case SPOT06:
	case SPOT07:
	case SPOT08:
	case SPOT09:
	case SPOT10:
	case SPOT11:
	case SPOT12:
	case SPOT13:
	case SPOT15:
	case SPOT16:
	case SPOT17:
	case SPOT18:
	case SPOT20:
	case GANONTOU:
#define MAP_ALPHA_VALUE	170
	    if ( parameter->map_alpha < MAP_ALPHA_VALUE ) parameter->map_alpha = alpha1;
	    else                                          parameter->map_alpha = MAP_ALPHA_VALUE;
	    break;
	    
	default:
	    if ( parameter->map_alpha != FULL_ALPHA ) parameter->map_alpha = alpha1;
	    break;
	}
	break;

    case 7:
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	c_alpha_set_1( game_play, alpha1 );
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	if ( parameter->meter_alpha != FULL_ALPHA ) parameter->meter_alpha = alpha1;
    default:
	break;
	    
    case 9:
	if ( parameter->b_alpha ) {
	    if ( parameter->b_alpha > alpha ) parameter->b_alpha = alpha;
	}
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	if ( parameter->meter_alpha != FULL_ALPHA ) parameter->meter_alpha = alpha1;
	break;

    case 10:
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
	if ( parameter->heart_alpha ) {
	    if ( parameter->heart_alpha > alpha ) parameter->heart_alpha = alpha;
	}
	if ( parameter->meter_alpha ) {
	    if ( parameter->meter_alpha > alpha ) parameter->meter_alpha = alpha;
	}
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->b_alpha != FULL_ALPHA ) parameter->b_alpha = alpha1;
	break;

    case 11:
	if ( parameter->b_alpha ) {
	    if ( parameter->b_alpha > alpha ) parameter->b_alpha = alpha;
	}
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->meter_alpha ) {
	    if ( parameter->meter_alpha > alpha ) parameter->meter_alpha = alpha;
	}
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	break;

    case 12:
	if ( parameter->a_alpha != FULL_ALPHA ) parameter->a_alpha = alpha1;
	if ( parameter->b_alpha != FULL_ALPHA ) parameter->b_alpha = alpha1;
	if ( parameter->map_alpha != FULL_ALPHA ) parameter->map_alpha = alpha1;
	if ( parameter->c_alpha ) {
	    if ( parameter->c_alpha > alpha ) parameter->c_alpha = alpha;
	}
	if ( parameter->c_alpha1 ) {
	    if ( parameter->c_alpha1 > alpha ) parameter->c_alpha1 = alpha;
	}
	if ( parameter->c_alpha2 ) {
	    if ( parameter->c_alpha2 > alpha ) parameter->c_alpha2 = alpha;
	}
/*	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}*/
	if ( parameter->meter_alpha ) {
	    if ( parameter->meter_alpha > alpha ) parameter->meter_alpha = alpha;
	}
	if ( parameter->heart_alpha ) {
	    if ( parameter->heart_alpha > alpha ) parameter->heart_alpha = alpha;
	}
	break;
	
    case 13:
	c_alpha_set_0( game_play, alpha, alpha1 );
	if ( parameter->map_alpha ) {
	    if ( parameter->map_alpha > alpha ) parameter->map_alpha = alpha;
	}
	if ( parameter->a_alpha ) {
	    if ( parameter->a_alpha > alpha ) parameter->a_alpha = alpha;
	}
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	if ( parameter->meter_alpha != FULL_ALPHA ) parameter->meter_alpha = alpha1;
	break;
    }
    
    if ( game_play->room_info.now.type == ROOM_TYPE_DANGEON && parameter->map_alpha >= MAP_ALPHA )
	parameter->map_alpha = MAP_ALPHA;
}
/*===============================================================
  =	   Ａボタン表示変更ＤＭＡ				=
 ===============================================================*/
static void
parameter_check( Game_play *game_play  )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    Message		*message = (Message *)&game_play->message;

    short		i, henkou;

    /*
     *  ＰＡＲＡＭＥＴＲ管理
     */
    henkou = 0;
    if ( ZCommonGet( day_time ) < 0xfff0 ||
	(game_play->scene_data_ID == SPOT20 && ZCommonGet(day_time) == 0xfff0) ) {
	Z_CK_FG = 0;
	if ( player->action & P_ACTION_RIDE_HORSE ||
	     game_play->bow_game_flag >= 2 ||
/*	     game_play->bomchu_game_flag > 0 ||
	     ((short)game_play->bomchu_game_flag == -1 && game_play->actor_info.actor_list[ ACTOR_PART_BOM ].num) ) {*/
	     (game_play->scene_data_ID == BOWLING && Actor_Environment_sw_Check( game_play, 56 )) ) {
	    if ( Register_Item(0) != 0xff ) {
		Z_CK_FG = 1;
		if ( Z_BTN_ITEM(0) == 0xff ) {
		    Z_BTN_ITEM(0) = 
			Z_BTN_ITEM(1) =
			Z_BTN_ITEM(2) =
			Z_BTN_ITEM(3) = 0;
		}
		if ( !(Register_Item(0) == H_pachinko ||
		       Register_Item(0) == H_bow ||
		       Register_Item(0) == H_bomb_2 ||
		       Register_Item(0) == 0xff) ) {
		    Z_BTN_ITEM(0) = Register_Item(0);
/*		    if ( game_play->bomchu_game_flag > 0 ||
			 ((short)game_play->bomchu_game_flag == -1 && game_play->actor_info.actor_list[ ACTOR_PART_BOM ].num) ) {*/
		    if ( game_play->scene_data_ID == BOWLING && Actor_Environment_sw_Check( game_play, 56 ) ) {
			/* ボムチュウ・ボウリング場 */
			Register_Item(0) = H_bomb_2;
			item_textuer_dma( game_play, 0 );
		    } else {
			Register_Item(0) = H_bow;
			if ( game_play->bow_game_flag >= 2 ) {
			    /* 射的場 */
			    if ( ZCommon_LinkAgeIsChild() ) {
				Register_Item(0) = H_pachinko;
			    }
			    item_textuer_dma( game_play, 0 );
			} else if ( Item_Register(H_bow) == 0xff ) {
			    /* その他 */
			    Register_Item(0) = 0xff;
			} else {
			    item_textuer_dma( game_play, 0 );
			}
		    }
		    Z_BTN_ITEM(1) =
			Z_BTN_ITEM(2) =
			Z_BTN_ITEM(3) = 0xff;
		    alpha_change( 6 );
////////		    alpha_change( 8 );
		}
		if ( game_play->fbdemo_wipe_mode ) {
		    alpha_change( 1 );
		} else {
		    if ( Yabusame_Mode == Yabu_START ) alpha_change( 8 );
		    else if ( game_play->bow_game_flag >= 2 ) alpha_change( 8 );
/*		    else if ( game_play->bomchu_game_flag > 0 ||
			      ((short)game_play->bomchu_game_flag == -1 && game_play->actor_info.actor_list[ ACTOR_PART_BOM ].num) ) alpha_change( 8 );*/
		    else if ( game_play->scene_data_ID == BOWLING && Actor_Environment_sw_Check( game_play, 56 ) ) alpha_change( 8 );
		    else if ( player->action & P_ACTION_RIDE_HORSE ) alpha_change( 12 );
		}
	    } else {
		if ( player->action & P_ACTION_RIDE_HORSE ) alpha_change( 12 );
	    }
	} else if ( game_play->scene_data_ID == KENJYANOMA ) {
	    alpha_change( 1 );
	} else if ( game_play->scene_data_ID == TURIBORI ) {
	    Z_CK_FG = 2;
	    if ( CHK_HOLD_ROD( game_play ) ) {
		if ( Register_Item(0) != H_rod ) {
		    /* つり中 */
		    Z_BTN_ITEM(0) = Register_Item(0);
		    Register_Item(0) = H_rod;
		    Z_PREV_ALPHA_TYPE = 0;
		    item_textuer_dma( game_play, 0 );
////////		    DO_ACTION_POINT_SET( game_play, DO_Maku );
		    alpha_change( 12 );
		}
		if ( Z_PREV_ALPHA_TYPE != 12 ) alpha_change( 12 );
	    } else if ( Register_Item(0) == H_rod ) {
		Register_Item(0) = Z_BTN_ITEM(0);
		Z_PREV_ALPHA_TYPE = 0;
		if ( Register_Item(0) != 0xff ) {
		    item_textuer_dma( game_play, 0 );
		}
		Z_BTN_ITEM(0) =
		    Z_BTN_ITEM(1) =
		    Z_BTN_ITEM(2) =
		    Z_BTN_ITEM(3) = 0xff;
		alpha_change( 50 );
	    } else {
		if ( !Z_BTN_ITEM(0) ) Z_PREV_ALPHA_TYPE = 0;
		Z_BTN_ITEM(0) =
		    Z_BTN_ITEM(1) =
		    Z_BTN_ITEM(2) =
		    Z_BTN_ITEM(3) = 0xff;
		alpha_change( 50 );
	    }
	} else {
	    if ( !message->msg_mode ) {
		if ( player_condition_check( game_play ) >= 2 && player_condition_check( game_play ) <= 4 ) {	/* プレイヤー水中 */
		    if ( Z_BTN_ITEM(0) != 0xff ) henkou = 1;
		    Z_BTN_ITEM(0) = 0xff;
		    for( i = 1; i < 4; i++ ) {
			if ( player_condition_check( game_play ) == 2 ) {
			    if ( !(Register_Item(i) == H_S_hookshot || Register_Item(i) == H_L_hookshot) ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
			    } else {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			} else {
			    if ( !Z_BTN_ITEM(i) ) henkou = 1;
			    Z_BTN_ITEM(i) = 0xff;
			}
		    }
		    if ( henkou ) Z_PREV_ALPHA_TYPE = 0;
		    alpha_change( 50 );
		} else if ( bitcheck( player->action, (P_ACTION_LADDER) ) ||	/* つかまり／ぶら下がり中？ */
			    bitcheck( player->action2, (P_ACTION2_TUNNEL) ) 		/* 横穴モード？ */
		    ) {	
		    if ( Z_BTN_ITEM(0) != 0xff ) {
			Z_BTN_ITEM(0) = 0xff;
			Z_BTN_ITEM(1) = 0xff;
			Z_BTN_ITEM(2) = 0xff;
			Z_BTN_ITEM(3) = 0xff;
			Z_PREV_ALPHA_TYPE = 0;
			alpha_change( 50 );
		    }
		} else if ( InRaceSeq == SCENE_2 ) {		/* 体験乗馬中？ */
		    if ( player->action & P_ACTION_RIDE_HORSE ) {
			if ( !(Register_Item(0) == 0xff || Register_Item(0) == H_bow) ) {
			    if ( Item_Register(H_bow) == 0xff ) Register_Item(0) = 0xff;
			    else {
				Register_Item(0) = H_bow;
				henkou = 1;
			    }
			}
		    } else {
			if ( Register_Item(0) == 0xff || Register_Item(0) == H_bow ) {
			    if ( !(Register_Item(0) == H_sword_0 ||		/* ナイフ */
				   Register_Item(0) == H_sword_1 ||		/* マスターソード */
				   Register_Item(0) == H_sword_2 ||		/* 巨人のナイフ */
				   Register_Item(0) == H_sword_3) ) { 	/* 折れた巨人のナイフ */
				Register_Item(0) = Z_BTN_ITEM(0);
			    } else {
				Z_BTN_ITEM(0) = Register_Item(0);
			    }
			}
			henkou = 1;
		    }
		    if ( henkou ) {
			item_textuer_dma( game_play, 0 );
			henkou = 0;
		    }
		    for( i = 1; i < 4; i++ ) {
			if ( !(Register_Item(i) == H_ocarina_1 || Register_Item(i) == H_ocarina_2) ) {
			    if ( !Z_BTN_ITEM(i) ) henkou = 1;
			    Z_BTN_ITEM(i) = 0xff;
			} else {
			    if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
			    Z_BTN_ITEM(i) = 0;
			}
		    }
		    if ( henkou ) Z_PREV_ALPHA_TYPE = 0;
		    alpha_change( 50 );
		} else {
#if SOEJIMA_PRINT
		    PRINTF("  ~~b_button=%d(%d)~~  ",parameter->b_button,henkou);
#endif
		    if ( !parameter->b_button ) {
			if ( Register_Item(0) == H_pachinko ||
			     Register_Item(0) == H_bow ||
			     Register_Item(0) == H_bomb_2 ||
			     Register_Item(0) == 0xff ) {
			    if ( !(Register_Item(0) == 0xff && HOLD_SWORD) ) {
				henkou = 1;
				Register_Item(0) = Z_BTN_ITEM(0);
				if ( Register_Item(0) != 0xff ) {
				    item_textuer_dma( game_play, 0 );
				}
			    }
			} else if ( Z_BTN_ITEM(0) == 0xff ) {
			    henkou = 1;
			    if ( Z_BTN_ITEM(0) == 0xff || !Z_BTN_ITEM(0) ) Z_BTN_ITEM(0) = 0;
			    else                                           Register_Item(0) = Z_BTN_ITEM(0);
			}
		    } else if ( parameter->b_button == 1 ) {
			if ( Register_Item(0) == H_pachinko ||
			     Register_Item(0) == H_bow ||
			     Register_Item(0) == H_bomb_2 ||
			     Register_Item(0) == 0xff ) {
			    if ( !(Register_Item(0) == 0xff && HOLD_SWORD) ) {
				henkou = 1;
				Register_Item(0) = Z_BTN_ITEM(0);
				if ( Register_Item(0) != 0xff ) {
				    item_textuer_dma( game_play, 0 );
				}
			    }
			} else {
			    if ( Z_BTN_ITEM(0) == 0 ) henkou = 1;
			    Z_BTN_ITEM(0) = 0xff;
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~c_bottle=%d(%d)~~  ",parameter->c_bottle,henkou);
#endif
		    if ( parameter->c_bottle ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) >= H_bottle && Register_Item(i) <= H_bottle_12 ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
			    }
			}
		    } else if ( !parameter->c_bottle ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) >= H_bottle && Register_Item(i) <= H_bottle_12 ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~c_warasibe=%d(%d)~~  ",parameter->c_warasibe,henkou);
#endif
		    if ( parameter->c_warasibe ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) >= H_reserve_00 && Register_Item(i) <= H_reserve_30 ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
			    }
			}
		    } else if ( !parameter->c_warasibe ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) >= H_reserve_00 && Register_Item(i) <= H_reserve_30 ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~c_hook=%d(%d)~~  ",parameter->c_hook,henkou);
#endif
		    if ( parameter->c_hook ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_S_hookshot || Register_Item(i) == H_L_hookshot ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
			    }
			}
		    } else if ( !parameter->c_hook ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_S_hookshot || Register_Item(i) == H_L_hookshot ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~c_ocarina=%d(%d)~~  ",parameter->c_ocarina,henkou);
#endif
		    if ( parameter->c_ocarina ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_ocarina_1 ||  Register_Item(i) == H_ocarina_2 ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
			    }
			}
		    } else if ( !parameter->c_ocarina ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_ocarina_1 ||  Register_Item(i) == H_ocarina_2 ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~m_wind=%d(%d)~~  ",parameter->m_wind,henkou);
#endif
		    if ( parameter->m_wind ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_goddess_2 ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
				PRINTF("***(i=%d)***  ",i);
			    }
			}
		    } else if ( !parameter->m_wind ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_goddess_2 ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~m_magic=%d(%d)~~  ",parameter->m_magic,henkou);
#endif
		    if ( parameter->m_magic ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_goddess_1 || Register_Item(i) == H_goddess_3 ) {
				if ( !Z_BTN_ITEM(i) ) henkou = 1;
				Z_BTN_ITEM(i) = 0xff;
			    }
			}
		    } else if ( !parameter->m_magic ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( Register_Item(i) == H_goddess_1 || Register_Item(i) == H_goddess_3 ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~another=%d(%d)~~  ",parameter->another,henkou);
#endif
		    if ( parameter->another ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( !(Register_Item(i) == H_ocarina_1 ||  Register_Item(i) == H_ocarina_2 ||  (Register_Item(i) >= H_bottle && Register_Item(i) <= H_bottle_12) ||  (Register_Item(i) >= H_reserve_00 && Register_Item(i) <= H_reserve_30)) ) {
				if ( !(game_play->scene_data_ID == TAKARAYA && Register_Item(i) == H_magicglass) ) {
				    if ( !Z_BTN_ITEM(i) ) henkou = 1;
				    Z_BTN_ITEM(i) = 0xff;
				} else {
				    if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				    Z_BTN_ITEM(i) = 0;
				}
			    }
			}
		    } else if ( !parameter->another ) {
			for ( i = 1; i < 4; i++ ) {
			    if ( !(Register_Item(i) == H_goddess_1 || Register_Item(i) == H_S_hookshot || Register_Item(i) == H_L_hookshot || Register_Item(i) == H_goddess_2 || Register_Item(i) == H_goddess_3 || Register_Item(i) == H_ocarina_1 ||  Register_Item(i) == H_ocarina_2 ||  (Register_Item(i) >= H_bottle && Register_Item(i) <= H_bottle_12) ||  (Register_Item(i) >= H_reserve_00 && Register_Item(i) <= H_reserve_30)) ) {
				if ( Z_BTN_ITEM(i) == 0xff ) henkou = 1;
				Z_BTN_ITEM(i) = 0;
			    }
			}
		    }
#if SOEJIMA_PRINT
		    PRINTF("  ~~終了(%d)~~\n",henkou);
#endif
		}
	    }
	}
    }
    if ( henkou ) {
	Z_PREV_ALPHA_TYPE = 0;
	if ( !(game_play->fade_direction || game_play->fbdemo_wipe_mode) ) {
	    alpha_change( 50 );
	    PRINTF("????????  alpha_change( 50 );  ?????\n");
	} else {
	    PRINTF("game_play->fade_direction || game_play->fbdemo_wipe_mode\m");
	}
    }
}
/************************************************************************
 *									*
 *	ボタン表示関係データ設定					*
 *									*
 ************************************************************************/
extern void
button_status_set( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    short	jjj;


    /*
     *  ボタン表示関係データ設定
     */
    parameter->h_gage    =
	parameter->b_button  =
	parameter->a_button  =
	parameter->c_bottle  =
	parameter->c_warasibe =
	parameter->c_hook    =
	parameter->c_ocarina =
	parameter->c_warp    =
	parameter->c_sunmoon =
	parameter->m_wind    =
	parameter->m_magic   =
	parameter->another   =
	jjj = 0;
    PRINTF("ボタン表示関係データ設定 scene_data_ID=%d\n",game_play->scene_data_ID);
    do {
	if ( button_data[jjj][0] == (unchar)game_play->scene_data_ID ) {
	    parameter->h_gage    = (button_data[jjj][1] & 0xc0) >> 6;
	    parameter->b_button  = (button_data[jjj][1] & 0x30) >> 4;
	    parameter->a_button  = (button_data[jjj][1] & 0x0c) >> 2;
	    parameter->c_bottle  = (button_data[jjj][1] & 0x03);
	    parameter->c_warasibe = (button_data[jjj][2] & 0xc0) >> 6;
	    parameter->c_hook    = (button_data[jjj][2] & 0x30) >> 4;
	    parameter->c_ocarina = (button_data[jjj][2] & 0x0c) >> 2;
	    parameter->c_warp    = (button_data[jjj][2] & 0x03);
	    parameter->c_sunmoon = (button_data[jjj][3] & 0xc0) >> 6;
	    parameter->m_wind    = (button_data[jjj][3] & 0x30) >> 4;
	    parameter->m_magic   = (button_data[jjj][3] & 0x0c) >> 2;
	    parameter->another   = (button_data[jjj][3] & 0x03);
	    COLOR_YELLOW();
	    PRINTF("parameter->button_status = %x,%x,%x\n",button_data[jjj][1],button_data[jjj][2],button_data[jjj][3]);
	    PRINTF("h_gage=%d, b_button=%d, a_button=%d, c_bottle=%d\n",parameter->h_gage,parameter->b_button,parameter->a_button,parameter->c_bottle);
	    PRINTF("c_warasibe=%d, c_hook=%d, c_ocarina=%d, c_warp=%d\n",parameter->c_warasibe,parameter->c_hook,parameter->c_ocarina,parameter->c_warp);
	    PRINTF("c_sunmoon=%d, m_wind=%d, m_magic=%d, another=%d\n",parameter->c_sunmoon,parameter->m_wind,parameter->m_magic,parameter->another);
////////	    parameter_check( game_play );
	    COLOR_NORMAL();
	    break;
	}
	jjj++;
    } while ( button_data[jjj][0] != 0xff );
}




/*===============================================================
  =	（ＩＡ／８）Ｔｅｃｔｕｒｅ＿Ｒｅｃｔａｎｇｌｅ		=
  ===============================================================*/
static Gfx
*texture_rectangleIA8( Gfx *gp, void *timg,
		       short width, short height,
		       short xpos,  short ypos,
		       short xsize, short ysize,
		       unshort xscale, unshort yscale )
{
    gDPLoadTextureBlock( gp++,
			 timg, G_IM_FMT_IA, G_IM_SIZ_8b,
			 width, height, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD );
    gSPTextureRectangle( gp++,
			 ((xpos) * 0x4), ((ypos) * 0x4),
			 ((xpos + xsize) * 0x4), ((ypos + ysize) * 0x4),
			 G_TX_RENDERTILE, 0, 0, xscale, yscale );
    return gp;
}


/*===============================================================
  =	（Ｉ／８）Ｔｅｃｔｕｒｅ＿Ｒｅｃｔａｎｇｌｅ		=
  ===============================================================*/
static Gfx
*texture_rectangleI8( Gfx *gp, void *timg,
		       short width, short height,
		       short xpos,  short ypos,
		       short xsize, short ysize,
		       unshort xscale, unshort yscale )
{
    gDPLoadTextureBlock( gp++,
			 timg, G_IM_FMT_I, G_IM_SIZ_8b,
			 width, height, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD );
    gSPTextureRectangle( gp++,
			 ((xpos) * 0x4), ((ypos) * 0x4),
			 ((xpos + xsize) * 0x4), ((ypos + ysize) * 0x4),
			 G_TX_RENDERTILE, 0, 0, xscale, yscale );
    return gp;
}












/*===============================================================
  =	   装備デフォルト設定処理				=
  ===============================================================*/
extern void
equip_default_set( void )
{
////////    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    short	i;
    unshort	zzz;

    if ( ZCommon_LinkAgeIsChild() ) {
	/* 子供 → 大人 */
	for ( i = 0; i < 4; i++ ) {
	    if ( i ) Child_Register_Item( i ) = Register_Item( i );
	    else     Child_Register_Item( i ) = H_sword_0;	/* 必ず『コキリの剣』*/
	    if ( i ) Child_Register_Item_Pt( i ) = Register_Item_Pt( i );
	}
	Child_Equip_Item = Equip_Item;
	if ( Adult_Register_Item(0) == 0xff ) {
	    Register_Item( 0 ) = H_sword_1;
	    if ( Item_Register( H_deku_nut ) != 0xff ) {
		Register_Item( 1 ) = H_deku_nut;
		Register_Item_Pt( 1 ) = 1;
	    } else {
		Register_Item( 1 ) = 
		    Register_Item_Pt( 1 ) = 0xff;
	    }
	    Register_Item( 2 ) = H_bomb_1;
	    Register_Item( 3 ) = Item_Register( H_ocarina_1 );
	    Register_Item_Pt( 2 ) = 2;
	    Register_Item_Pt( 3 ) = 7;
	    Equip_Item = 0x1122;
	} else {
	    for ( i = 0; i < 4; i++ ) {
		Register_Item( i ) = Adult_Register_Item( i );
		if ( i ) Register_Item_Pt( i ) = Adult_Register_Item_Pt( i );
		if ( (Register_Item( i ) >= H_bottle && Register_Item( i ) <= H_bottle_12) ||
		     (Register_Item( i ) >= H_reserve_00 && Register_Item( i ) <= H_reserve_30)) {
		    /* ボトル類やわらしべ類は、持ち物チェック */
		    PRINTF("Register_Item_Pt(%d)=%d\n",i,Register_Item_Pt(i));
		    Register_Item( i ) = Item_Register( Register_Item_Pt( i ) );
		}
	    }
	    Equip_Item = Adult_Equip_Item;
	}
    } else {
	/* 大人 → 子供 */
	for ( i = 0; i < 4; i++ ) {
	    Adult_Register_Item( i ) = Register_Item( i );
	    if ( i ) Adult_Register_Item_Pt( i ) = Register_Item_Pt( i );
	}
	Adult_Equip_Item = Equip_Item;
	if ( Child_Register_Item(0) == 0xff ) {
	} else {
	    for ( i = 0; i < 4; i++ ) {
		Register_Item( i ) = Child_Register_Item( i );
		if ( i ) Register_Item_Pt( i ) = Child_Register_Item_Pt( i );
		if ( (Register_Item( i ) >= H_bottle && Register_Item( i ) <= H_bottle_12) ||
		     (Register_Item( i ) >= H_reserve_00 && Register_Item( i ) <= H_reserve_30)) {
		    /* ボトル類やわらしべ類は、持ち物チェック */
		    PRINTF("Register_Item_Pt(%d)=%d\n",i,Register_Item_Pt(i));
		    Register_Item( i ) = Item_Register( Register_Item_Pt( i ) );
		}
	    }
	    Equip_Item = Child_Equip_Item;
	    Equip_Item &= 0xfff0;
	    Equip_Item |= 0x0001;
	}
    }
    if ( (zzz = Equip_Item & bit_check_data[E_Shield]) ) {
	zzz >>= bit_shift_data[E_Shield];
	if ( !CKEquip_Register(E_sword_z+zzz) ) Equip_Item &= bit_and_data[E_Shield];
    }
    
    /* プレイヤー性能初期設定 */
////////    player_ability_init( game_play, player );
}



/*===============================================================
  =	   流鏑馬ＧＡＭＥ ＳＴＡＲＴ     			=
  ===============================================================*/
extern void
yabusame_game_start( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    Yabusame_Mode = Yabu_START;
    Yabusame_Total =
	yabu_sound =
	parameter->yabusame_score =
	parameter->yabu_mode =
	parameter->yabu_score = 0;
/*	yabu_alpha =
	yabu_alpha1 = 0;*/
    parameter->yabusame_arrow = 20;
}



/*===============================================================
  =	   巨人のナイフ処理ＤＭＡ				=
  ===============================================================*/
extern void
sword_system_dma( Game_play *game_play )
{
    SetEquip_Register( E_Sword, check_bit[H_sword_2-H_sword_0] );
    EorEquip_Register( 0, 8 );
    if ( Equip_Register & check_bit[3] ) {
	Register_Item(0) = H_sword_3;
    } else {
	Register_Item(0) = H_sword_2;
    }
    item_textuer_dma( game_play, 0 );
}

/*===============================================================
  =	   アイテム テクスチャＤＭＡ				=
  ===============================================================*/
extern void
item_textuer_dma( Game_play *game_play, unshort item_no  )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    /* アイテム テクスチャＤＭＡ */
    osCreateMesgQueue( &parameter->mq, &parameter->m, 1 );
    dmacopy_bg( &parameter->dma,
		parameter->icon_itemSegment + (I_IT_PT * item_no),
		(u32)(_icon_item_staticSegmentRomStart + ((Register_Item(item_no))*I_IT_PT)),
		I_IT_PT,
		NULL,
		&parameter->mq,
		NULL );
    osRecvMesg( &parameter->mq, NULL, OS_MESG_BLOCK );
}


/*===============================================================
  =	   アイテム テクスチャＤＭＡ				=
  ===============================================================*/
extern void
item_textuer_dma1( Game_play *game_play, unshort item_no )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    /* アイテム テクスチャＤＭＡ */
    osCreateMesgQueue( &parameter->mq, &parameter->m, 1 );
    dmacopy_bg( &parameter->dma1,
		parameter->icon_itemSegment + (I_IT_PT * item_no),
		(u32)(_icon_item_staticSegmentRomStart + ((Register_Item(item_no))*I_IT_PT)),
		I_IT_PT,
		NULL,
		&parameter->mq,
		NULL );
    osRecvMesg( &parameter->mq, NULL, OS_MESG_BLOCK );
}

# if 0
/*===============================================================
  =	   Ａボタン表示変更ＤＭＡ				=
 ===============================================================*/
extern void
a_item_dma( Game_play *game_play, unshort type  )
{
    game_play;
////////    Parameter		*parameter = (Parameter *)&game_play->parameter;

////////    if ( !type ) {
////////	Z_BTN_ITEM(0) = Register_Item(0);
////////	Register_Item(0) = H_bow;
////////	alpha_change( 6 );
////////    } else {
	Register_Item(0) = Z_BTN_ITEM(0);
	Z_BTN_ITEM(0) = 
	    Z_BTN_ITEM(1) =
	    Z_BTN_ITEM(2) =
	    Z_BTN_ITEM(3) = 0;
	alpha_change( 7 );
////////    }
    /* アイテム テクスチャＤＭＡ */
    item_textuer_dma( game_play, 0 );
}
# endif
/*===============================================================
  =	   Ａボタン表示切替ＤＭＡ				=
 ===============================================================*/
extern void
a_item_dma_change( Game_play *game_play, unshort type  )
{
# if 1
    if ( type ) {
	if ( Register_Item(0) == H_pachinko ||
	     Register_Item(0) == H_bow ||
	     Register_Item(0) == H_bomb_2 ||
	     Register_Item(0) == H_rod ||
	     Z_BTN_ITEM(0) == 0xff ) {
	    if ( Register_Item(0) == H_pachinko ||
		 Register_Item(0) == H_bow ||
		 Register_Item(0) == H_bomb_2 ||
		 Register_Item(0) == H_rod ) {
		Register_Item(0) = Z_BTN_ITEM(0);
		item_textuer_dma( game_play, 0 );
	    }
	} else if ( Register_Item(0) == 0xff ) {
	    if ( !(Register_Item(0) == 0xff && HOLD_SWORD) ) {
		Register_Item(0) = Z_BTN_ITEM(0);
		item_textuer_dma( game_play, 0 );
	    }
	}
	Z_BTN_ITEM(0) =
	    Z_BTN_ITEM(1) =
	    Z_BTN_ITEM(2) =
	    Z_BTN_ITEM(3) = 0;
	alpha_change( 7 );
/*	yabu_alpha1 = yabu_alpha;*/
    } else {
	Z_BTN_ITEM(0) =
	    Z_BTN_ITEM(1) =
	    Z_BTN_ITEM(2) =
	    Z_BTN_ITEM(3) = 0;
	parameter_check( game_play );
    }
# endif
# if 0
    if ( !type ) {
	if ( Z_CK_FG ) {
	    Z_BTN_ITEM(0) = Register_Item(0);
	    if ( ZCommon_LinkAgeIsChild() ) {
		Register_Item(0) = H_pachinko;
	    } else {
		Register_Item(0) = H_bow;
	    }
	    alpha_change( 6 );
	    Z_CK_FG = 0;
	}
    } else {
	if ( Register_Item(0) == H_pachinko || Register_Item(0) == H_bow ) {
	    Register_Item(0) = Z_BTN_ITEM(0);
	    Z_CK_FG = 1;
	} else Z_CK_FG = 0;
    }
    /* アイテム テクスチャＤＭＡ */
    osCreateMesgQueue( &parameter->mq, &parameter->m, 1 );
    dmacopy_bg( &parameter->dma,
		parameter->icon_itemSegment,
		(u32)(_icon_item_staticSegmentRomStart + ((Register_Item(0))*I_IT_PT)),
		I_IT_PT,
		NULL,
		&parameter->mq,
		NULL );
    osRecvMesg( &parameter->mq, NULL, OS_MESG_BLOCK );
# endif
}



/*===============================================================
  =	   アイテム取得セッテング				=
  =	ＲＥＴＵＲＮ値 ＝ ０ｘＦＦ:新規アイテム			=
  ===============================================================*/
extern unchar
item_get_setting( Game_play *game_play, unchar item_no )
{
    static short	BS_count[] = {
	5, 10, 20, 30,
    };
    static short	arrow_count[] = {
	 5, 10, 30,
    };
    static short	bomchuw_count[] = {
	5, 20,
    };
    static short	rupy_ctdt[] = {
	  1,		/*128『ルピー緑（１ルピー）』 */
	  5,		/*129『ルピー青（５ルピー）』 */
	 20,		/*130『ルピー赤（２０ルピー）』 */
	 50,		/*131『大ルピー（５０ルピー）』 */
	200,		/*132『特大ルピー（２００ルピー）』 */
	 10,		/*133『銀のルピー（１０ルピー）』 */
    };

    short	i, pt, z;


    pt = number_pt[item_no];
    if ( item_no >= H0_stick ) {
	pt = number_pt[shift_item_no[item_no-H0_stick]];
    }
    COLOR_YELLOW();
    PRINTF("item_get_setting=%d  pt=%d  z=%x\n",item_no, pt, Item_Register(pt) );
    COLOR_NORMAL();


    if ( item_no >= H_seal_medal_1 && item_no <= H_seal_medal_6) {
	/* 封印 */
	SetCollect_SEAL( item_no );
	COLOR_YELLOW();
	PRINTF("封印 = %x\n",S_Table.collect_register );
	COLOR_NORMAL();
	if ( item_no == H_seal_medal_3 ) {	/* 104『ルトの封印』 */
	    Horse_escape_Spot06Water( game_play );
	}
	return( 0xff );
    } else if ( item_no >= H_melody_1 && item_no <= H_melody_12 ) {
	/* 楽譜 */
	SetCollect_MELODY( item_no );
	COLOR_YELLOW();
	PRINTF("楽譜 = %x\n",S_Table.collect_register );
	PRINTF("楽譜 = %x (%x) (%x)\n",S_Table.collect_register,check_bit[(item_no-H_melody_1)+C_SEAL], check_bit[C_SEAL + C_MELODY + (item_no - H_holystone_1)] );
	COLOR_NORMAL();
	return( 0xff );
    } else if ( item_no >= H_holystone_1 && item_no <= H_holystone_3 ) {
	/* 精霊石 */
	SetCollect_HOLY( item_no );
	COLOR_YELLOW();
	PRINTF("精霊石 = %x\n",S_Table.collect_register );
	COLOR_NORMAL();
	return( 0xff );
    } else if ( item_no == H_shake_stone || item_no == H_gerudoC ) {
	/* アイテム */
	SetCollect_ITEM( item_no );
	COLOR_YELLOW();
	PRINTF("アイテム = %x\n",S_Table.collect_register );
	COLOR_NORMAL();
	return( 0xff );
    } else if ( item_no == H_N_coin ) {
	/* Ｎコイン */
	SetCollect_ITEM( item_no );
	N_COIN_TOTAL++;
	COLOR_YELLOW();
	PRINTF("Ｎコイン = %x(%d)\n",S_Table.collect_register, N_COIN_TOTAL );
	COLOR_NORMAL();
	return( 0xff );
    } else if ( item_no >= H_sword_0 && item_no <= H_sword_2 ) {
	/* 剣 */
	SetEquip_Register( E_Sword, check_bit[item_no-H_sword_0] );
	if ( item_no == H_sword_2 ) {
	    /* 巨人のナイフ */
	    LONG_SWORD_HP = 8;
	    if ( GetEquip_Register( E_Sword ) == 0xf ) {
		/* 折れた巨人のナイフ修復 */
		EorEquip_Register( 0, 8 );
		if ( Register_Item(0) == H_sword_3 ) {
		    Register_Item(0) = H_sword_2;
		    item_textuer_dma( game_play, 0 );
		}
	    }
	} else if ( item_no == H_sword_1 ) {
	    /* マスターソード */
	    Register_Item( 0 ) = H_sword_1;
	    Equip_Item &= 0xfff0;
	    Equip_Item |= 0x0002;
	    item_textuer_dma( game_play, 0 );
	}
	return( 0xff );
    } else if ( item_no >= H_shield_1 && item_no <= H_shield_3 ) {
	/* 盾 */
	SetEquip_Register( E_Shield, check_bit[item_no-H_shield_1] );
	return( 0xff );
    } else if ( item_no >= H_clothes_1 && item_no <= H_clothes_3 ) {
	/* 服 */
	SetEquip_Register( E_Clothes, check_bit[item_no-H_clothes_1] );
	return( 0xff );
    } else if ( item_no >= H_boots_1 && item_no <= H_boots_3 ) {
	/* ブーツ */
	SetEquip_Register( E_Boots, check_bit[item_no-H_boots_1] );
	return( 0xff );
    } else if ( item_no == H_boss_key || item_no == H_compass || item_no == H_map ) {
	/* ＭＡＰアイテム */
	SetKeyCompassMap(Scene_ID, item_no);
	return( 0xff );
    } else if ( item_no == H_key ) {
	/* ダンジョンの鍵 */
	if ( S_Table.key_register[ Scene_ID ] < 0 ) {
	    S_Table.key_register[ Scene_ID ] = 1;
	    return( 0xff );
	} else {
	    S_Table.key_register[ Scene_ID ]++;
	    return( 0xff );
	}
    } else if ( item_no == H_arrowcase_1 || item_no == H_bow ) {
	/* 小さな矢立て（３０）＆ 妖精の弓 */
	if ( !Non_Equip_Register( NE_Bow ) ) {
	    Set_Non_Equip_Register( NE_Bow, 1 );
	    Item_Register_Set(H_bow);
	    Item_Count(H_bow) = item_max_data[NE_Bow][1];
	    return( 0xff );
	} else {
	    Item_Count(H_bow) += 1;
	    if ( Item_Count(H_bow) > Item_MaxGet( NE_Bow ) ) Item_Count(H_bow) = Item_MaxGet( NE_Bow );
	}
    } else if ( item_no == H_arrowcase_2 ) {
	/* 大きな矢立て（５０）*/
	Set_Non_Equip_Register( NE_Bow, 2 );
	Item_Count(H_bow) = item_max_data[NE_Bow][2];
	return( 0xff );
    } else if ( item_no == H_arrowcase_3 ) {
	/* もっと大きな矢立て（９０）*/
	Set_Non_Equip_Register( NE_Bow, 3 );
	Item_Count(H_bow) = item_max_data[NE_Bow][3];
	return( 0xff );
    } else if ( item_no == H_dekupouch_2 ) {
	/* デグのタネ袋（４０）*/
	Set_Non_Equip_Register( NE_Pachinko, 2 );
	Item_Count(H_pachinko) = item_max_data[NE_Pachinko][2];
	return( 0xff );
    } else if ( item_no == H_dekupouch_3 ) {
	/* デグのタネ袋（５０）*/
	Set_Non_Equip_Register( NE_Pachinko, 3 );
	Item_Count(H_pachinko) = item_max_data[NE_Pachinko][3];
	return( 0xff );
    } else if ( item_no == H_bombpouch_1/* || item_no == H_bomb_1*/ ) {
	/* 小さな袋（２０）＆ 爆弾 */
	if ( !Non_Equip_Register( NE_Bomb ) ) {
	    Set_Non_Equip_Register( NE_Bomb, 1 );
	    Item_Register_Set(H_bomb_1);
	    Item_Count(H_bomb_1) = item_max_data[NE_Bomb][1];
	    return( 0xff );
	} else {
	    Item_Count(H_bomb_1) += 1;
	    if ( Item_Count(H_bomb_1) > Item_MaxGet( NE_Bomb ) ) Item_Count(H_bomb_1) = Item_MaxGet( NE_Bomb );
	}
    } else if ( item_no == H_bombpouch_2 ) {
	/* 大きな袋（３０）*/
	Set_Non_Equip_Register( NE_Bomb, 2 );
	Item_Count(H_bomb_1) = item_max_data[NE_Bomb][2];
	return( 0xff );
    } else if ( item_no == H_bombpouch_3 ) {
	/* もっと大きな袋（５０）*/
	Set_Non_Equip_Register( NE_Bomb, 3 );
	Item_Count(H_bomb_1) = item_max_data[NE_Bomb][3];
	return( 0xff );
    } else if ( item_no == H_bracelet ) {
	/* 銅のブレスレット */
	Set_Non_Equip_Register( NE_Grove, 1 );
	return( 0xff );
    } else if ( item_no == H_gloves_1 ) {
	/* 銀のグローブ */
	Set_Non_Equip_Register( NE_Grove, 2 );
	return( 0xff );
    } else if ( item_no == H_gloves_2 ) {
	/* 金のグローブ */
	Set_Non_Equip_Register( NE_Grove, 3 );
	return( 0xff );
    } else if ( item_no == H_scale_1 ) {
	/* 銀のウロコ */
	Set_Non_Equip_Register( NE_Scale, 1 );
	return( 0xff );
    } else if ( item_no == H_scale_2 ) {
	/* 金のウロコ */
	Set_Non_Equip_Register( NE_Scale, 2 );
	return( 0xff );
    } else if ( item_no == H_purse_2 ) {
	/* 大人のがま口 */
	Set_Non_Equip_Register( NE_Purse, 1 );
	return( 0xff );
    } else if ( item_no == H_purse_3 ) {
	/* 大金持ちがま口 */
	Set_Non_Equip_Register( NE_Purse, 2 );
	return( 0xff );
    } else if ( item_no == H0_stick_bag ) {
	/*『デクの棒』２０本袋 */
	if ( Item_Register(pt) == 0xff ) Item_Register_Set(H_stick);
	Set_Non_Equip_Register( NE_Stick, 2 );
	Item_Count(H_stick) = item_max_data[NE_Stick][2];
	return( 0xff );
    } else if ( item_no == H1_stick_bag ) {
	/*『デクの棒』３０本袋 */
	if ( Item_Register(pt) == 0xff ) Item_Register_Set(H_stick);
	Set_Non_Equip_Register( NE_Stick, 3 );
	Item_Count(H_stick) = item_max_data[NE_Stick][3];
	return( 0xff );
    } else if ( item_no == H0_deku_nut_bag ) {
	/*『デクの実』３０個袋 */
	if ( Item_Register(pt) == 0xff ) Item_Register_Set(H_deku_nut);
	Set_Non_Equip_Register( NE_Deck_Nut, 2 );
	Item_Count(H_deku_nut) = item_max_data[NE_Deck_Nut][2];
	return( 0xff );
    } else if ( item_no == H1_deku_nut_bag ) {
	/*『デクの実』４０個袋 */
	if ( Item_Register(pt) == 0xff ) Item_Register_Set(H_deku_nut);
	Set_Non_Equip_Register( NE_Deck_Nut, 3 );
	Item_Count(H_deku_nut) = item_max_data[NE_Deck_Nut][3];
	return( 0xff );
    } else if ( item_no == H_L_hookshot ) {
	/* ロング・フックショット */
	Item_Register_Set(item_no);
	for ( i = 1; i < 4; i++ ) {
	    if ( Register_Item(i) == H_S_hookshot ) {
		Register_Item(i) = H_L_hookshot;
		item_textuer_dma( game_play, i );
	    }
	}
	return( 0xff );
    } else if ( item_no == H_stick ) {
	/* デクの棒 */
	if ( Item_Register(pt) == 0xff ) {
	    Set_Non_Equip_Register( NE_Stick, 1 );
	    Item_Count(H_stick) = 1;
	} else {
	    Item_Count(H_stick)++;
	    if ( Item_Count(H_stick) > Item_MaxGet( NE_Stick ) ) Item_Count(H_stick) = Item_MaxGet( NE_Stick );
	}
    } else if ( item_no == H0_stick || item_no == H1_stick ) {
	/* デクの棒（５本／１０本）*/
	if ( Item_Register(pt) == 0xff ) {
	    Set_Non_Equip_Register( NE_Stick, 1 );
	    Item_Count(H_stick) = BS_count[item_no - H0_stick];
	} else {
	    Item_Count(H_stick) += BS_count[item_no - H0_stick];
	    if ( Item_Count(H_stick) > Item_MaxGet( NE_Stick ) ) Item_Count(H_stick) = Item_MaxGet( NE_Stick );
	}
	item_no = H_stick;
    } else if ( item_no == H_deku_nut ) {
	/* デクの実 */
	if ( Item_Register(pt) == 0xff ) {
	    Set_Non_Equip_Register( NE_Deck_Nut, 1 );
	    Item_Count(H_deku_nut) = 1;
	} else {
	    Item_Count(H_deku_nut)++;
	    if ( Item_Count(H_deku_nut) > Item_MaxGet( NE_Deck_Nut ) ) Item_Count(H_deku_nut) = Item_MaxGet( NE_Deck_Nut );
	}
    } else if ( item_no == H0_deku_nut || item_no == H1_deku_nut ) {
	/* デクの実（５個／１０個）*/
	if ( Item_Register(pt) == 0xff ) {
	    Set_Non_Equip_Register( NE_Deck_Nut, 1 );
	    Item_Count(H_deku_nut) += BS_count[item_no - H0_deku_nut];
	    PRINTF("デクの実 %d(%d)=%d  BS_count=%d\n",item_no,H0_deku_nut,item_no - H0_deku_nut,BS_count[item_no - H0_deku_nut]);
	} else {
	    Item_Count(H_deku_nut) += BS_count[item_no - H0_deku_nut];
	    if ( Item_Count(H_deku_nut) > Item_MaxGet( NE_Deck_Nut ) ) Item_Count(H_deku_nut) = Item_MaxGet( NE_Deck_Nut );
	}
	item_no = H_deku_nut;
    } else if ( item_no == H_bomb_1 ) {
	/* 爆弾 */
	PRINTF(" 爆弾  爆弾  爆弾  爆弾 爆弾   爆弾 爆弾 \n"); 
	if ( (Item_Count(H_bomb_1) += 1) > Item_MaxGet( NE_Bomb ) ) Item_Count(H_bomb_1) = Item_MaxGet( NE_Bomb );
	return( 0xff );
    } else if ( item_no >= H0_bomb_1 && item_no <= H3_bomb_1 ) {
	/* 爆弾（５個／１０個） */
	if ( (Item_Count(H_bomb_1) += BS_count[item_no - H0_bomb_1]) > Item_MaxGet( NE_Bomb ) ) Item_Count(H_bomb_1) = Item_MaxGet( NE_Bomb );
	return( 0xff );
    } else if ( item_no == H_bomb_2 ) {
	/* ボムチュウ */
	if ( Item_Register(pt) == 0xff ) {
	    Item_Register_Set(H_bomb_2);
	    Item_Count(H_bomb_2) = 10;
	    return( 0xff );
	}
	if ( (Item_Count(H_bomb_2) += 10) > 50 ) Item_Count(H_bomb_2) = 50;
	return( 0xff );
    } else if ( item_no == H0_bomb_2 || item_no == H1_bomb_2 ) {
	/* ボムチュウ（５個／２０個 ）*/
	if ( Item_Register(pt) == 0xff ) {
	    Item_Register_Set(H_bomb_2);
	    Item_Count(H_bomb_2) += bomchuw_count[item_no - H0_bomb_2];
	    return( 0xff );
	}
	if ( (Item_Count(H_bomb_2) += bomchuw_count[item_no - H0_bomb_2]) > 50 ) Item_Count(H_bomb_2) = 50;
	return( 0xff );
    } else if ( item_no >= H0_arrow && item_no <= H2_arrow ) {
	/* 弓（１０本／３０本／５０本）*/
	Item_Count(H_bow) += arrow_count[item_no - H0_arrow];
	if ( Item_Count(H_bow) >= Item_MaxGet( NE_Bow ) || Item_Count(H_bow) < 0 ) Item_Count(H_bow) = Item_MaxGet( NE_Bow );
	PRINTF("%d本  Item_MaxGet=%d\n",Item_Count(H_bow),Item_MaxGet( NE_Bow ));
	return( H_bow );
    } else if ( item_no == H_pachinko ) {
	/* パチンコ */
	Set_Non_Equip_Register( NE_Pachinko, 1 );
	Item_Register_Set(H_pachinko);
	Item_Count(H_pachinko) = 30;
	return( 0xff );
    } else if ( item_no == H_deku_seed ) {
	/* デクのタネ */
	Item_Count(H_pachinko) += 5;
	if ( Item_Count(H_pachinko) >= Item_MaxGet( NE_Pachinko ) ) Item_Count(H_pachinko) = Item_MaxGet( NE_Pachinko );
	if ( !Get_Item_Get_Inf( 1, 0x0008 ) ) {
	    Set_Item_Get_Inf( 1, 0x0008 );
	    return( 0xff );
	}
	return( H_deku_seed );
    } else if ( item_no == H0_deku_seed ) {
	/* デクのタネ */
	Item_Count(H_pachinko) += 30;
	if ( Item_Count(H_pachinko) >= Item_MaxGet( NE_Pachinko ) ) Item_Count(H_pachinko) = Item_MaxGet( NE_Pachinko );
	if ( !Get_Item_Get_Inf( 1, 0x0008 ) ) {
	    Set_Item_Get_Inf( 1, 0x0008 );
	    return( 0xff );
	}
	return( H_deku_seed );
    } else if ( item_no == H_ocarina_1 ) {
	/* 妖精のオカリナ */
	Item_Register_Set(H_ocarina_1);
////////	SetCollect_MELODY( H_melody_7 );
	return( 0xff );
    } else if ( item_no == H_ocarina_2 ) {
	/* 時のオカリナ */
	Item_Register_Set(H_ocarina_2);
	for ( i = 1; i < 4; i++ ) {
	    if ( Register_Item(i) == H_ocarina_1 ) {
		Register_Item(i) = H_ocarina_2;
		item_textuer_dma( game_play, i );
	    }
	}
	return( 0xff );
    } else if ( item_no == H_bean ) {
	/* 魔法のマメ */
	if ( Item_Register(pt) == 0xff ) {
	    Item_Register_Set(item_no);
	    Item_Count(H_bean) = 1;
	    Item_Count(BEAN_COUNT) = 1;
	} else {
	    Item_Count(H_bean)++;
	    Item_Count(BEAN_COUNT)++;
	}
	return( 0xff );
    } else if ( item_no == H_heart_1 || item_no == H_heartpiece ) {
	/* ハートの欠片 */
	S_Table.collect_register += HeartCt;
	return( 0xff );
    } else if ( item_no == H_heart ) {
	/* ハートの器 */
	S_Private.max_life += LIFE_CT;
	S_Private.now_life += LIFE_CT;
	return( 0xff );
    } else if ( item_no == H_life ) {
	/* 回復ハート */
	PRINTF("回復ハート回復ハート回復ハート\n");
	life_meter_play( game_play, LIFE_CT*1 );
	return( item_no );
    } else if ( item_no == H_magic_pot_0 ) {
	/* 魔法の壷（小）*/
	if ( MAGIC_FLAG != Magic_Recovery ) { 		/* ＭＰ回復中 */
	    magic_mode_check( game_play );
	}
	MAGIC_CHARGE( game_play, 12, MAGIC_RECOVERY );
	if ( !Get_Inf_Table( 25, 0x0100) ) {
	    Set_Inf_Table( 25, 0x0100);
	    return( 0xff );
	} else return( item_no );
////////	return( H_magic_pot_0 );
    } else if ( item_no == H_magic_pot_1 ) {
	/* 魔法の壷（大）*/
	if ( MAGIC_FLAG != Magic_Recovery ) { 		/* ＭＰ回復中 */
	     magic_mode_check( game_play );
	}
	MAGIC_CHARGE( game_play, 24, MAGIC_RECOVERY );
	if ( !Get_Inf_Table( 25, 0x0100) ) {
	    Set_Inf_Table( 25, 0x0100);
	    return( 0xff );
	} else return( item_no );
////////	return( H_magic_pot_1 );
    } else if ( item_no >= H_rupy00 && item_no <= H_rupy05 ) {
	/* ルピ（１,５,１０,５０,５００,１０ルピー） */
	lupy_increase( rupy_ctdt[item_no - H_rupy00] );
	return( 0xff );
    } else if ( item_no == H_bottle ) {
	/* 空瓶 */
	z = number_pt[item_no];
	for ( i = 0; i < 4; i++ ) {
	    if ( Item_Register(z+i) == 0xff ) {
		Item_Register(z+i) = item_no;
		return( 0xff );
	    }
	}
    } else if ( (item_no >= H_bottle_1 && item_no <= H_bottle_12) || item_no == H_lonron_milk ) {
	/* 各種瓶 */
	z = number_pt[item_no];
	if ( !(item_no == H_bottle_6 || item_no == H_bottle_7) ) {
////////	    if ( (item_no >= H_bottle_1 && item_no <= H_bottle_12)  || item_no == H_lonron_milk ) {
	    if ( item_no == H_lonron_milk ) {
		item_no = H_bottle_6;
		z = number_pt[item_no];
	    }
	    for ( i = 0; i < 4; i++ ) {
		if ( Item_Register(z+i) == H_bottle ) {
		    PRINTF("Item_Pt(1)=%d Item_Pt(2)=%d Item_Pt(3)=%d   空瓶=%d   中味=%d\n",Register_Item_Pt(1),Register_Item_Pt(2),Register_Item_Pt(3), z+i, item_no);
		    if ( Register_Item_Pt(1) == (z+i) ) {
			Register_Item(1) = item_no;
			item_textuer_dma1( game_play, 1 );
			Z_BTN_ITEM(1) = 0;
		    } else if ( Register_Item_Pt(2) == (z+i) ) {
			Register_Item(2) = item_no;
			item_textuer_dma1( game_play, 2 );
			Z_BTN_ITEM(2) = 0;
		    } else if ( Register_Item_Pt(3) == (z+i) ) {
			Register_Item(3) = item_no;
			item_textuer_dma( game_play, 3 );
			Z_BTN_ITEM(3) = 0;
		    }
		    Item_Register(z+i) = item_no;
////////		    return( item_no );
		    return( 0xff );
		}
	    }
	} else {
	    for ( i = 0; i < 4; i++ ) {
		if ( Item_Register(z+i) == 0xff ) {
		    Item_Register(z+i) = item_no;
		    return( 0xff );
		}
	    }
	}
////////	return( item_no );
    } else if ( item_no >= H_reserve_00 && item_no <= H_reserve_30 ) {
	/* わらしべアイテム */
	/* 名人のノコギリ */
	if ( item_no == H_reserve_25 ) Item_Get_Inf(01) |= 0x8000;
	z = Item_Register(number_pt[item_no]);
	Item_Register_Set(item_no);
	if ( z != 0xff ) {
	    for ( i = 1; i < 4; i++ ) {
		if ( Register_Item(i) == z ) {
		    if ( item_no != H_reserve_11 ) {
			Register_Item(i) = item_no;
			item_textuer_dma( game_play, i );
		    } else Register_Item(i) = 0xff;
		    return( 0xff );
		}
	    }
	}
	return( 0xff );
    }

    z = Item_Register(pt);
    PRINTF("Item_Register(%d)=%d  %d\n",pt, item_no, z );
////////    Item_Register(pt) = item_no;
    Item_Register_Set(item_no);

    return( z );
}
/*===============================================================
  =	   アイテム取得セッテング				=
  =	ＲＥＴＵＲＮ値 ＝ ０ｘＦＦ:新規アイテム			=
  ===============================================================*/
extern unchar
item_get_non_setting( unchar item_no )
{
    short	i, pt, z;


    pt = number_pt[item_no];
    if ( item_no >= H0_stick ) {
	pt = number_pt[shift_item_no[item_no-H0_stick]];
    }
    COLOR_GREEN();
    PRINTF("item_get_non_setting=%d  pt=%d  z=%x\n",item_no, pt, Item_Register(pt) );
    COLOR_NORMAL();


    if ( item_no >= H_seal_medal_1 && item_no <= H_seal_medal_6) {
	/* 封印 */
	return( 0xff );
    } else if ( item_no >= H_holystone_1 && item_no <= H_N_coin ) {
	/* 精霊石・楽譜・アイテム */
	return( 0xff );
# if 0
    } else if ( item_no >= H_sword_0 && item_no <= H_sword_2 ) {
	/* 剣 */
	return( 0xff );
    } else if ( item_no >= H_shield_1 && item_no <= H_shield_3 ) {
	/* 盾 */
	return( 0xff );
    } else if ( item_no >= H_clothes_1 && item_no <= H_clothes_3 ) {
	/* 服 */
	return( 0xff );
    } else if ( item_no >= H_boots_1 && item_no <= H_boots_3 ) {
	/* ブーツ */
	return( 0xff );
# endif
    } else if ( item_no >= H_sword_0 && item_no <= H_sword_2 ) {
	/* 剣 */
	if ( item_no == H_sword_2 ) return( 0xff );
	if ( Equip_Sword_CK(item_no) ) return( item_no );
	else                           return( 0xff );
    } else if ( item_no >= H_shield_1 && item_no <= H_shield_3 ) {
	/* 盾 */
	if ( Equip_Shield_CK(item_no) ) return( item_no );
	else                            return( 0xff );
     } else if ( item_no >= H_clothes_1 && item_no <= H_clothes_3 ) {
	/* 服 */
	if ( Equip_Clothes_CK(item_no) ) return( item_no );
	else                             return( 0xff );
    } else if ( item_no >= H_boots_1 && item_no <= H_boots_3 ) {
	/* ブーツ */
	if ( Equip_Boots_CK(item_no) ) return( item_no );
	else                           return( 0xff );
   } else if ( item_no == H_boss_key || item_no == H_compass || item_no == H_map ) {
	/* ＭＡＰアイテム */
	return( 0xff );
    } else if ( item_no == H_key ) {
	/* ダンジョンの鍵 */
/*	if ( S_Table.key_register[ Scene_ID ] < 0 ) return( 0xff );
	else                                        return( 0 );*/
	return( 0xff );
    } else if ( item_no >= H_pachinko && item_no <= H_bomb_2 ) {
	/* パチンコ,妖精のオカリナ,時のオカリナ, ボムチュウ*/
	return( 0xff );
    } else if ( item_no == H0_bomb_2 || item_no == H1_bomb_2 ) {
	/* ボムチュウ（５個／２０個 ）*/
	return( 0xff );
    } else if ( item_no == H_arrowcase_1 || item_no == H_bow ) {
	/* 小さな矢立て（２０）＆ 妖精の弓 */
	if ( !Non_Equip_Register( NE_Bow ) ) {
	    return( 0xff );
	} else return( 0 );
    } else if ( item_no == H_arrowcase_2 || item_no == H_arrowcase_3 ) {
	/* 大きな矢立て（４０）もっと大きな矢立て（５０）*/
	return( 0xff );
    } else if ( item_no == H_dekupouch_2 || item_no == H_dekupouch_3 ) {
	/* デグのタネ袋（４０）デグのタネ袋（５０）*/
	return( 0xff );
    } else if ( item_no == H_bombpouch_1 || item_no == H_bomb_1 ) {
	/* 小さな袋（１０）＆ 爆弾 */
	if ( !Non_Equip_Register( NE_Bomb ) ) {
	    return( 0xff );
	} else return( 0 );
    } else if ( item_no >= H0_stick_bag && item_no <= H1_deku_nut_bag ) {
	/* デクの棒袋 ＆ デクの実袋 */
	return( 0xff );
# if 0
    } else if ( item_no == H_bombpouch_2 ) {
	/* 大きな袋（２０）*/
	return( 0xff );
    } else if ( item_no == H_bombpouch_3 ) {
	/* もっと大きな袋（５０）*/
	return( 0xff );
    } else if ( item_no == H_bracelet ) {
	/* 銅のブレスレット */
	return( 0xff );
    } else if ( item_no == H_gloves_1 ) {
	/* 銀のグローブ */
	return( 0xff );
    } else if ( item_no == H_gloves_2 ) {
	/* 金のグローブ */
	return( 0xff );
    } else if ( item_no == H_scale_1 ) {
	/* 銀のウロコ */
	return( 0xff );
    } else if ( item_no == H_scale_2 ) {
	/* 金のウロコ */
	return( 0xff );
    } else if ( item_no == H_purse_2 ) {
	/* 大人のがま口 */
	return( 0xff );
    } else if ( item_no == H_purse_3 ) {
	/* 大金持ちがま口 */
	return( 0xff );
# endif
    } else if ( item_no >= H_bombpouch_2 && item_no <= H_purse_3 ) {
	/* 大きな袋（２０）,もっと大きな袋（５０）,銅のブレスレット,銀のグローブ,金のグローブ,銀のウロコ,金のウロコ,大人のがま口,大金持ちがま口 */
	return( 0xff );
    } else if ( item_no == H_L_hookshot ) {
	/* ロング・フックショット */
	return( 0xff );
    } else if ( item_no == H_deku_seed || item_no == H0_deku_seed ) {
	/* デクのタネ */
	if ( !Get_Item_Get_Inf( 1, 0x0008 ) )
	    return( 0xff );
	else
	    return( H_deku_seed );
    } else if ( item_no == H_bean ) {
	/* 魔法のマメ */
	return( 0xff );
    } else if ( item_no == H_heart_1 ||item_no == H_heartpiece ) {
	/* ハートの欠片 */
	return( 0xff );
    } else if ( item_no == H_heart ) {
	/* ハートの器 */
	return( 0xff );
    } else if ( item_no == H_life ) {
	/* 回復ハート */
	return( H_life );
    } else if ( item_no == H_magic_pot_0 || item_no == H_magic_pot_1 ) {
	/* 魔法の壷（小）（大）*/
	PRINTF("魔法の壷 Get_Inf_Table( 25, 0x0100)=%d\n",Get_Inf_Table( 25, 0x0100));
	if ( !Get_Inf_Table( 25, 0x0100) ) return( 0xff );
	else                               return( item_no );
    } else if ( item_no >= H_rupy00 && item_no <= H_rupy05 ) {
	/* ルピ（１,５,１０,５０,５００,１０ルピー） */
	return( 0xff );
    } else if ( item_no == H_bottle ) {
	/* 空き瓶 */
	return( 0xff );
    } else if ( (item_no >= H_bottle_1 && item_no <= H_bottle_12) || item_no == H_lonron_milk ) {
	/* 各種瓶 */
	z = number_pt[item_no];
	if ( !(item_no == H_bottle_6 || item_no == H_bottle_7) ) {
////////	if ( (item_no >= H_bottle_1 && item_no <= H_bottle_12) || item_no == H_lonron_milk ) {
	    if ( item_no == H_lonron_milk ) {
		item_no = H_bottle_6;
		z = number_pt[item_no];
	    }
	    for ( i = 0; i < 4; i++ ) {
		if ( Item_Register(z+i) == H_bottle ) {
////////		    return( item_no );
		    return( 0xff );
		}
	    }
	} else {
	    for ( i = 0; i < 4; i++ ) {
		if ( Item_Register(z+i) == 0xff ) {
		    return( 0xff );
		}
	    }
	}
    } else if ( item_no >= H_reserve_00 && item_no <= H_reserve_30 ) {
	/* わらしべアイテム */
	/* 名人のノコギリ */
	return( 0xff );
    }

    return( Item_Register(pt) );
}




/*===============================================================
  =	   アイテム消去セッテング				=
  ===============================================================*/
extern void
item_clear_setting( unshort item, unshort pt )
{
    short	i;

    if ( item == H_bean ) Item_Count(BEAN_COUNT) = 0;
    Item_Register(pt) = 0xff;
    PRINTF("\nItem_Register(%d)\n", pt, Item_Register(pt) );
    for ( i = 1; i < 4; i++ ) {
	if ( Register_Item(i) == item ) {
	    Register_Item(i) = 0xff;
	    Register_Item_Pt(i) = 0xff;
	}
    }
}
/*===============================================================
  =	   アイテム切替セッテング				=
  ===============================================================*/
extern char
item_change_setting( Game_play *game_play, unshort item0, unshort item1 )
{
    short	i;

    for ( i = 0; i < 24; i++ ) {
	if ( Item_Register(i) == item0 ) {
	    Item_Register(i) = item1;
	    PRINTF("アイテム消去(%d)\n",i);
	    for ( i = 1; i < 4; i++ ) {
		if ( Register_Item(i) == item0 ) {
		    Register_Item(i) = item1;
		    item_textuer_dma( game_play, i );
		    return( 1 );
		}
	    }
	    return( 1 );
	}
    }
    return( 0 );
# if 0
    short	i, k;

    for ( i = k = 0; i < 24; i++ ) {
	if ( Item_Register(i) == item0 ) {
	    Item_Register(i) = item1;
	    PRINTF("アイテム消去(%d)\n",i);
	    k = 1;
	    for ( i = 1; i < 4; i++ ) {
		if ( Register_Item(i) == item0 ) {
		    Register_Item(i) = item1;
		    item_textuer_dma( game_play, i );
		}
	    }
	}
    }
    return( k );
# endif
}
/*======================================================================*/
/*	買えるかどうかのチェック処理					*/
/*======================================================================*/
/*----- 空瓶あるかチェック -----*/
extern int findEmptyBottle( void )
{
    register int	i;

    i = 18;
    while ( i < 22 ) {
	if ( Item_Register(i) == H_bottle ) return TRUE;
	i ++;
    }
    return FALSE;
}
/*===============================================================
  =	   ＢＯＴＴＬＥ（中身）チェック				=
  ===============================================================*/
extern int bottle_interior_check( unchar item_no )
{
    register int	i;

    i = 18;
    while ( i < 22 ) {
	if ( Item_Register(i) == item_no ) return TRUE;
	i ++;
    }
    return FALSE;
}
/*===============================================================
  =	   ＢＯＴＴＬＥ（中身）取得処理				=
  ===============================================================*/
extern void
bottle_getting( Game_play *game_play, unchar item_no, unchar c_no )
{
    PRINTF("item_no=%x,  c_no=%x,  Pt=%x  Item_Register=%x\n",item_no, c_no, Register_Item_Pt(c_no), Item_Register(Register_Item_Pt(c_no)) );
    if ( Item_Register(Register_Item_Pt(c_no)) == H_bottle_6 && item_no == H_bottle ) {
	item_no = H_bottle_11;
    }
    Item_Register(Register_Item_Pt(c_no)) = item_no;
    Register_Item(c_no) = item_no;
    item_textuer_dma( game_play, c_no );
    game_play->kscope.select_name[0] = item_no;
    Z_BTN_ITEM( c_no ) = 0;
}
/*===============================================================
  =	   ＢＯＴＴＬＥ（妖精使用チェック）			=
  ===============================================================*/
extern char
bottle_fairy_use( Game_play *game_play )
{
    short	z, i, j;
    z = number_pt[H_bottle_4];
    for ( i = 0; i < 4; i++ ) {
	if ( Item_Register(z+i) == H_bottle_4 ) {
	    for ( j = 1; j < 4; j++ ) {
		if ( Register_Item(j) == H_bottle_4 ) {
		    Register_Item(j) = H_bottle;
		    item_textuer_dma( game_play, j );
		    z = Register_Item_Pt(j);
		    i = 0;
		    break;
		}
	    }
	    PRINTF("妖精使用＝%d\n",z);
	    Item_Register(z+i) = H_bottle;
	    return( 1 );
	}
    }
    return ( 0 );
}





/*===============================================================
  =	テクスチャ白黒変換					=
 ===============================================================*/
static void
nuki_set( unsigned int  *image, unshort size )
{
    unshort 	j;
    
    for ( j = 0; j < (size); j++ ) {
	image[j] = 0x0;
    }
}
/*===============================================================
  =	   ＤＯアクション ＮＥＸＴテクスチャＤＭＡ		=
 ===============================================================*/
#if defined(PAL_VERSION)
extern unsigned char g_ba_nes_atakku_txt[];
extern unsigned char g_ba_nes_chekku_txt[];
#else
extern unsigned char g_ba_atakku_txt[];
extern unsigned char g_ba_chekku_txt[];
#endif
static void
////////next_do_action_textuer_dma( Parameter *parameter, unshort action, size_t adr )
next_do_action_textuer_dma( Parameter *parameter, unshort action, short adr )
{
#if defined(PAL_VERSION)
    static unchar *do_index[] = {
	g_ba_nes_atakku_txt, g_ba_nes_chekku_txt,
    };
#else
    static unchar *do_index[] = {
	g_ba_atakku_txt, g_ba_chekku_txt,
    };
#endif
    
    /* ＤＯアクション ＮＥＸＴテクスチャＤＭＡ */
    if ( action >= DO_F_Navi ) action = DO_Navi;

    if ( J_N ) action += DO_F_Navi;
    if ( J_N == 2 ) action += DO_F_Navi;

    if ( !(action == DO_Navi || action == DO_Navi+DO_F_Navi || action == DO_Navi+DO_F_Navi+DO_F_Navi) ) {
	osCreateMesgQueue( &parameter->mq, &parameter->m, 1 );
	dmacopy_bg( &parameter->dma,
		    parameter->do_actionSegment + (G_B_PT*adr),
		    (u32)(_do_action_staticSegmentRomStart + (G_B_PT * action) ),
		    G_B_PT,
		    NULL,
		    &parameter->mq,
		    NULL );
	osRecvMesg( &parameter->mq, NULL, OS_MESG_BLOCK );
    } else {
	SetSegmentK0( PARAMETER0_SEGMENT, parameter->do_actionSegment );
	nuki_set( (unsigned int *)SEGMENT_TO_KSEG0(do_index[adr]), ((48/2)*16)/4 );
    }
}






/********************************************************
 *	ＤＯアクション ポイント セット			*
 ********************************************************/
extern void
do_action_point_set( Game_play *game_play, unshort action )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Kscope		*kscope = (Kscope *)&game_play->kscope;

    if ( parameter->do_action_old != action ) {
	/* Ｎｅｗアクション セット */
	parameter->do_action_old = action;
	parameter->do_action_flg = 1;
	parameter->do_action_rotate = 0.0f;

	/* ＤＯアクション ＮＥＸＴテクスチャＤＭＡ */
/*	if ( action == DO_F_Navi ) {
	    action = DO_Navi;
	    if ( !navi_sound ) {
		Na_StartSystemSe( NA_SE_VO_NAVY_CALL );
		navi_sound = 2400;
	    }
	}*/
////////	next_do_action_textuer_dma( parameter, action, G_B_PT*1 );
	next_do_action_textuer_dma( parameter, action, 1 );
	if ( kscope->pause ) parameter->do_action_flg = 3;
    }
}
/********************************************************
 *	ＤＯアクション ポイント セット			*
 ********************************************************/
extern void
do_action_navi_set( Game_play *game_play, unshort action )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    if ( (action == DO_F_Navi || action == DO_P_Navi) && !parameter->navi_flag && !game_play->demo_play.mode ) {
	if ( action == DO_P_Navi ) Na_StartSystemSe( NA_SE_VO_NAVY_CALL );
	if ( action == DO_F_Navi ) Na_StartNavyVoiceSingle( NA_SE_VO_NA_HELLO_2 );
	parameter->navi_flag = 1;
	navi_pt = 0;
	navi_ct = 10;
    } else if ( action == DO_E_Navi && parameter->navi_flag ) {
	parameter->navi_flag = 0;
    }
}
/********************************************************
 *	スペシャル【Ｂ】アクション ポイント セット	*
 ********************************************************/
extern void
sp_action_set( Game_play *game_play, unshort action )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;



    if ( J_N ) action += DO_F_Navi;
    if ( J_N == 2 ) action += DO_F_Navi;

    parameter->sp_action = action;

    osCreateMesgQueue( &parameter->mq, &parameter->m, 1 );
    dmacopy_bg( &parameter->dma,
		parameter->do_actionSegment + (G_B_PT*1),
		(u32)(_do_action_staticSegmentRomStart + (G_B_PT * action) ),
		G_B_PT,
		NULL,
		&parameter->mq,
		NULL );
    osRecvMesg( &parameter->mq, NULL, OS_MESG_BLOCK );
    
    parameter->sp_action_flag = 1;
}












/********************************************************
 *	ライフメーター 増減処理				*
 ********************************************************/
extern char
life_meter_play( Game_play *game_play, short count )
{
    unshort	i, j;
    game_play;


    PRINTF("＊＊＊＊＊  増減=%d (now=%d, max=%d)  ＊＊＊",count,S_Private.now_life,S_Private.max_life);
    if ( count > 0 ) Na_StartSystemSe( NA_SE_SY_HP_RECOVER );
    else {
	if ( LIFE_ABILITY && count < 0 ) {
	    count >>= 1;
	    PRINTF("ハート減少半分！！＝%d\n",count);
	}
    }
    S_Private.now_life += count;
    if ( S_Private.now_life > S_Private.max_life )
	S_Private.now_life = S_Private.max_life;
    /* ドキドキハートテクスチャＤＭＡ */
    i = j = (unshort)(S_Private.now_life % LIFE_CT);
    if ( j != 0 ) {
	if ( j >= 11 ) i = 3;
	else {
	    if ( j >= 6 ) i =2;
	    else i = 1;
	}
    }
    PRINTF("  ライフ=%d  ＊＊＊  %d  ＊＊＊＊＊＊\n",S_Private.now_life, i );

////////    if ( count >= 0 ) {
////////	initial_LifeRestChange( game_play );
////////    } else {
////////	if ( player_condition == 1 || player_condition == 2 ) {
////////	    initial_LifeRestChange_Damage( game_play );
////////	}
////////    }

    if ( S_Private.now_life <= 0 ) {
	S_Private.now_life = 0;
	return(0);	/* プレイヤー死亡 */
    } else return(1);	/* プレイヤー健在 */
}
/********************************************************
 *	ライフメーター MAX値増減処理			*
 ********************************************************/
extern void
life_meter_max( short count )
{
    S_Private.max_life += LIFE_CT*count;
}



/********************************************************
 *	ルピー数 増減処理				*
 ********************************************************/
extern void
lupy_increase( short count )
{
    z_common_data.lupy_udct += count;
}
# if 0
/********************************************************
 *	デクの棒回数処理				*
 ********************************************************/
extern void
deku_stick_count( short count )
{
    PRINTF("デクの棒=%d\n",Item_Count( H_stick ));
    Item_Count(H_stick) += count;
    if ( Item_Count(H_stick) > 50 ) Item_Count(H_stick) = 50;
    else if ( Item_Count(H_stick) < 0 ) Item_Count(H_stick) = 0;
}
# endif
/********************************************************
 *	 各アイテム回数処理				*
 ********************************************************/
extern void
item_count_vary( short kind, short count )
{
    PRINTF("アイテム = (%d)    数 = (%d + %d)  ",kind,Item_Count(kind),count);
    if ( kind == H_stick ) {
	Item_Count(H_stick) += count;
	if ( Item_Count(H_stick) >= Item_MaxGet( NE_Stick ) ) Item_Count(H_stick) = Item_MaxGet( NE_Stick );
	else if ( Item_Count(H_stick) < 0 ) Item_Count(H_stick) = 0;
    } else if ( kind == H_deku_nut ) {
	/* デクの実 */
	Item_Count(H_deku_nut) += count;
	if ( Item_Count(H_deku_nut) >= Item_MaxGet( NE_Deck_Nut ) ) Item_Count(H_deku_nut) = Item_MaxGet( NE_Deck_Nut );
	else if ( Item_Count(H_deku_nut) < 0 ) Item_Count(H_deku_nut) = 0;
    } else if ( kind == H_bomb_2 ) {
	/* ボムチュウ */
	Item_Count(H_bomb_2) += count;
	if ( Item_Count(H_bomb_2) >= 50 ) Item_Count(H_bomb_2) = 50;
	else if ( Item_Count(H_bomb_2) < 0 ) Item_Count(H_bomb_2) = 0;
    } else if ( kind == H_bow ) {
	/* 妖精の弓 */
	Item_Count(H_bow) += count;
	if ( Item_Count(H_bow) >= Item_MaxGet( NE_Bow ) ) Item_Count(H_bow) = Item_MaxGet( NE_Bow );
	else if ( Item_Count(H_bow) < 0 ) Item_Count(H_bow) = 0;
    } else if ( kind == H_pachinko || kind == H_deku_seed ) {
	/* パチンコ / デクのタネ */
	Item_Count(H_pachinko) += count;
	if ( Item_Count(H_pachinko) >= Item_MaxGet( NE_Pachinko ) ) Item_Count(H_pachinko) = Item_MaxGet( NE_Pachinko );
	else if ( Item_Count(H_pachinko) < 0 ) Item_Count(H_pachinko) = 0;
    } else if ( kind == H_bomb_1 ) {
	/* 爆弾 */
	Item_Count(H_bomb_1) += count;
	if ( Item_Count(H_bomb_1) >= Item_MaxGet( NE_Bomb ) ) Item_Count(H_bomb_1) = Item_MaxGet( NE_Bomb );
	else if ( Item_Count(H_bomb_1) < 0 ) Item_Count(H_bomb_1) = 0;
    } else if ( kind == H_bean ) {
	/* 魔法のマメ */
	Item_Count(H_bean) += count;
    }
    PRINTF("合計 = (%d)\n",Item_Count(kind));
}






/********************************************************
 *	魔法メーター状態チェック			*
 ********************************************************/
extern void
magic_mode_check( Game_play *game_play )
{
    game_play;

    if ( MAGIC_MODE ) {
	ZCommonSet( keep_magic_flag, MAGIC_FLAG );
	Z_MAGIC_NOW_NOW = MAGIC_VALUE*(MAGIC_ABILITY + 1); /*Z_MAGIC_NOW_MAX;*/
	Set_MAGIC_FLAG( Magic_Charge );
    }
}
/********************************************************
 *	魔法メーターキャンセルチェック			*
 ********************************************************/
extern void
magic_cancel_check( Game_play *game_play )
{
    game_play;

    if ( !(MAGIC_FLAG == Magic_Start || MAGIC_FLAG == Magic_Charge ) ) { /* 魔法メーター初期化中 */
	if ( MAGIC_FLAG == Magic_Recovery ) { 		/* ＭＰ回復中 */
	    ZCommonSet( keep_magic_flag, MAGIC_FLAG );
	}
	Set_MAGIC_FLAG( Magic_End );
    }
}
/********************************************************
 *	魔法メーター容量チェック			*
 ********************************************************/
extern short
magic_meter_check( Game_play *game_play, short mp, short magic_type )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    if ( !MAGIC_MODE ) return(0); /* 使用不可 */
    
    if ( magic_type != MAGIC_RECOVERY && ((MAGIC_NOW - mp) < 0) ) {
	if ( Z_MAGIC_NOW_MAX ) {
	    Na_StartSystemSe(NA_SE_SY_ERROR);
	}
	return(0); /* 使用不可 */
    }
    switch( magic_type ) {
    case MAGIC_ATTACK:
    case MAGIC_ARROW:
	if ( !MAGIC_FLAG || MAGIC_FLAG == Magic_Glass  ) {
	    /* 攻撃魔法 ＆ 魔法の弓 */
	    if ( MAGIC_FLAG == Magic_Glass ) game_play->actor_info.magic_grass = 0;
	    Z_MAGIC_USED = MAGIC_NOW - mp;
	    Set_MAGIC_FLAG( Magic_Attack );
	    return(1); /* 使用ＯＫ！ */
	} else {
	    Na_StartSystemSe(NA_SE_SY_ERROR);
	    return(0); /* 使用不可 */
	}
	
    case MAGIC_DEFENCE:
	if ( !MAGIC_FLAG || MAGIC_FLAG == Magic_Glass  ) {
	    /* 補助魔法 */
	    if ( MAGIC_FLAG == Magic_Glass ) game_play->actor_info.magic_grass = 0;
	    Z_MAGIC_USED = MAGIC_NOW - mp;
	    Set_MAGIC_FLAG( Magic_Defence );
	    return(1); /* 使用ＯＫ！ */
	} else {
	    Na_StartSystemSe(NA_SE_SY_ERROR);
	    return(0); /* 使用不可 */
	}
	
    case MAGIC_GLASS:
	/* まことの虫眼鏡 */
	if ( !MAGIC_FLAG ) {
	    if ( MAGIC_NOW ) {
		parameter->magic_frame = 80;
		Set_MAGIC_FLAG( Magic_Glass );
		return(1); /* 使用ＯＫ！ */
	    } else return(0); /* 使用不可 */
	} else {
	    if ( MAGIC_FLAG == Magic_Glass ) return(1); /* 使用ＯＫ！ */
	    else return(0); /* 使用不可 */
	}
	
    case MAGIC_SAVE:
	if ( !MAGIC_FLAG || MAGIC_FLAG == Magic_Glass  ) {
	    /* 魔法充電 */
	    if ( MAGIC_FLAG == Magic_Glass ) game_play->actor_info.magic_grass = 0;
	    Z_MAGIC_USED = MAGIC_NOW - mp;
	    Set_MAGIC_FLAG( Magic_Save );
	    return(1); /* 使用ＯＫ！ */
	} else {
	    Na_StartSystemSe(NA_SE_SY_ERROR);
	    return(0); /* 使用不可 */
	}
	
    case MAGIC_RECOVERY:
	/* ＭＰ回復 */
	if ( MAGIC_NOW <= Z_MAGIC_NOW_MAX ) {
	    Z_MAGIC_USED = MAGIC_NOW + mp;
	    if ( Z_MAGIC_USED >= Z_MAGIC_NOW_MAX )
		Z_MAGIC_USED = Z_MAGIC_NOW_MAX;
	    Set_MAGIC_FLAG( Magic_Recovery );
	    return(1); /* 使用ＯＫ！ */
	}
	break;
    }
    return(0); /* 使用不可 */
}


/********************************************************
 *	魔法メーター処理				*
 ********************************************************/
static void
magic_meter_move( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Message		*message = (Message *)&game_play->message;


    static short m_gage_color[][3] = {
	{255, 255, 255, },
    	{150, 150, 150, },
    };
    static short magic_color[][3] = {
	{255, 255, 150, },
	{255, 255,  50, },
    };
    static short magic_pt[] = {
	0, 1, 1, 0,
    };
    static short	mc = 2, mcpt = 1;
    short		rc, gc, bc, k;


    switch ( MAGIC_FLAG ) {
    case Magic_Start:
	 /* 魔法メーターＯＮ */
	k = (short)(MAGIC_VALUE*MAGIC_MAX);
	if ( k != Z_MAGIC_NOW_MAX ) {
	    if ( k > Z_MAGIC_NOW_MAX ) {
		if ( (Z_MAGIC_NOW_MAX += 8) > k ) Z_MAGIC_NOW_MAX = k;
	    } else if ( (Z_MAGIC_NOW_MAX -= 8) <= k ) Z_MAGIC_NOW_MAX = k;
	} else 	Set_MAGIC_FLAG( Magic_Charge );
	break;
	
    case Magic_Charge:
	/* 蓄電 */
	MAGIC_NOW+=4;
	if ( z_common_data.game_info.mode == GAME_INFO_GAME &&
	     ZCommonGet( game_info.counter < 4 ) )
	    Na_StartSystemSe( NA_SE_SY_GAUGE_UP );
	PRINTF("蓄電  MAGIC_NOW=%d (%d)\n",MAGIC_NOW,Z_MAGIC_NOW_NOW);
	if ( MAGIC_NOW >= Z_MAGIC_NOW_NOW ) {
	    MAGIC_NOW = Z_MAGIC_NOW_NOW;
	    Set_MAGIC_FLAG( ZCommonGet( keep_magic_flag ) );
	    ZCommonSet( keep_magic_flag, Magic_Null );
	}
	break;

    case Magic_Attack:
	/* Ｆｉｒｅ １ */
	mc = 2;
	Set_MAGIC_FLAG( Magic_Hit );
	break;
	
    case Magic_Hit:
	/* ＦＩＲＥ */
	MAGIC_NOW -= 2;
	if ( MAGIC_NOW <= 0 ) {
	    MAGIC_NOW = 0;
	    Set_MAGIC_FLAG( Magic_Wait );
	    mgr = mgg = mgb = 255;
	} else if ( MAGIC_NOW == Z_MAGIC_USED ) {
	    Set_MAGIC_FLAG( Magic_Wait );
	    mgr = mgg = mgb = 255;
	}
    case Magic_Save:
    case Magic_Wait:
    case Magic_Defence:
	/* Ｆｉｒｅ ２ */
	k = magic_pt[mcpt];
	/* 魔法ゲージ */
	rc = (ABS(mgr - m_gage_color[k][0] )) / mc;
	gc = (ABS(mgg - m_gage_color[k][1] )) / mc;
	bc = (ABS(mgb - m_gage_color[k][2] )) / mc;
	if ( mgr >= m_gage_color[k][0] ) mgr -= rc;
	else				 mgr += rc;
	if ( mgg >= m_gage_color[k][1] ) mgg -= gc;
	else				 mgg += gc;
	if ( mgb >= m_gage_color[k][2] ) mgb -= bc;
	else				 mgb += bc;

	if ( !(--mc) ) {
	    mgr = m_gage_color[k][0];
	    mgg = m_gage_color[k][1];
	    mgb = m_gage_color[k][2];
	    mc = YREG(40 + mcpt);
	    if ( ++mcpt >= 4 ) mcpt = 0;
	}
	break;
	
    case Magic_End:
	mgr = mgg = mgb = 255;
	Set_MAGIC_FLAG( Magic_Null );
	break;
	
    case Magic_Glass:
	if ( !(KALEIDO_SCOPE_Pause_on_off( game_play )) &&
	     !message->msg_mode &&
	     !game_play->gover.gover_mode &&
	     !game_play->fade_direction &&
	     !game_play->fbdemo_wipe_mode &&
	     !Game_play_demo_mode_check( game_play ) ) {
	    /* まことの虫眼鏡 */
	    if ( !MAGIC_NOW || (player_condition_check( game_play ) >= 2 && player_condition_check( game_play ) <= 4) || (Register_Item(1) != H_magicglass && Register_Item(2) != H_magicglass &&  Register_Item(3) != H_magicglass) || !game_play->actor_info.magic_grass ) {
		    /* 虫眼鏡ＯＦＦ */
		    game_play->actor_info.magic_grass = 0;
		    Na_StartSystemSe( NA_SE_SY_GLASSMODE_OFF );
		    Set_MAGIC_FLAG( Magic_Null );
		    mgr = mgg = mgb = 255;
		    break;
	    }
	    if ( !--parameter->magic_frame ) {
		MAGIC_NOW--;
		parameter->magic_frame = 80;
	    }
	}
	k = magic_pt[mcpt];
	/* 魔法ゲージ */
	rc = (ABS(mgr - m_gage_color[k][0] )) / mc;
	gc = (ABS(mgg - m_gage_color[k][1] )) / mc;
	bc = (ABS(mgb - m_gage_color[k][2] )) / mc;
	if ( mgr >= m_gage_color[k][0] ) mgr -= rc;
	else				 mgr += rc;
	if ( mgg >= m_gage_color[k][1] ) mgg -= gc;
	else				 mgg += gc;
	if ( mgb >= m_gage_color[k][2] ) mgb -= bc;
	else				 mgb += bc;

	if ( !(--mc) ) {
	    mgr = m_gage_color[k][0];
	    mgg = m_gage_color[k][1];
	    mgb = m_gage_color[k][2];
	    mc = YREG(40 + mcpt);
	    if ( ++mcpt >= 4 ) mcpt = 0;
	}
	break;

	
    case Magic_Recovery:
	/* ＭＰ回復 */
	MAGIC_NOW+=4;
	Na_StartSystemSe( NA_SE_SY_GAUGE_UP );
	if ( MAGIC_NOW >= Z_MAGIC_USED ) {
	    MAGIC_NOW = Z_MAGIC_USED;
	    Set_MAGIC_FLAG( ZCommonGet( keep_magic_flag ) );
	    ZCommonSet( keep_magic_flag, Magic_Null );
	}
	break;

    default:
	Set_MAGIC_FLAG( Magic_Null );
	break;
    }
}
/********************************************************
 *	魔法メーター処理				*
 ********************************************************/
static void
magic_meter_draw( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    short	i;


    OPEN_DISP( game_play->g.graph );

    if ( MAGIC_MAX ) {
	/* メーター １,２ */
	if ( S_Private.max_life > LIFE_CT*10 ) i = XREG(50);
	else				       i = XREG(48);
	overlay_rectangle_a_prim(game_play->g.graph);
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, mgr, mgg, mgb, parameter->meter_alpha );
	gDPSetEnvColor( NEXT_OVERLAY_DISP, 100, 50, 50, 255 );
	SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, g_m_meter1_txt,
						    8, 16,
						    XREG(49), i,
						    8, 16,
						    1 << 10, 1 << 10 )
			      );
/*	gDPLoadTextureBlock( NEXT_OVERLAY_DISP, 
			     g_m_meter1_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_OVERLAY_DISP,
			     XREG(49) << 2, i << 2,
			     (XREG(49)+8) << 2, (i+16) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );*/
	SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, g_m_meter2_txt,
						    24, 16,
						    XREG(49)+8, i,
						    Z_MAGIC_NOW_MAX, 16,
						    1 << 10, 1 << 10 )
			      );
/*	gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			     g_m_meter2_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 24, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_OVERLAY_DISP,
			     (XREG(49)+8) << 2, i << 2,
			     ((XREG(49)+8)+Z_MAGIC_NOW_MAX) << 2, (i+16) << 2,
			     G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );*/
	gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			     g_m_meter1_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 8, 16, 0,
			     G_TX_MIRROR, G_TX_NOMIRROR,
			     3, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	gSPTextureRectangle( NEXT_OVERLAY_DISP,
			     ((XREG(49)+8)+Z_MAGIC_NOW_MAX) << 2, i << 2,
			     ((XREG(49)+8)+Z_MAGIC_NOW_MAX)+8 << 2, (i+16) << 2,
			     G_TX_RENDERTILE, 32 << 3, 0, 1 << 10, 1 << 10 );

	/* 充電用メーター ３ */
	gDPPipeSync( NEXT_OVERLAY_DISP );
#define  G_CC_INT8      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, PRIMITIVE
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT8, G_CC_INT8 );
	gDPSetEnvColor( NEXT_OVERLAY_DISP, 0, 0, 0, 255 );
	if ( MAGIC_FLAG == Magic_Save ) {
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 250, 250,   0, parameter->meter_alpha );
	    gDPLoadTextureBlock_4b( NEXT_OVERLAY_DISP,
				    g_m_meter3_txt, G_IM_FMT_I, 16, 16, 0,
				    G_TX_NOMIRROR, G_TX_NOMIRROR,
				    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 XREG(51) << 2, (i+MAGIC_YPD) << 2,
				 (XREG(51)+MAGIC_NOW) << 2, (i+MAGIC_YSZ) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    /* メーター ３ */
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(0), ZREG(1), ZREG(2), parameter->meter_alpha );
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 XREG(51) << 2, (i+MAGIC_YPD) << 2,
				 (XREG(51)+Z_MAGIC_USED) << 2, (i+MAGIC_YSZ) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	} else {
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(0), ZREG(1), ZREG(2), parameter->meter_alpha );
	    gDPLoadTextureBlock_4b( NEXT_OVERLAY_DISP,
				    g_m_meter3_txt, G_IM_FMT_I, 16, 16, 0,
				    G_TX_NOMIRROR, G_TX_NOMIRROR,
				    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 XREG(51) << 2, (i+MAGIC_YPD) << 2,
				 (XREG(51)+MAGIC_NOW) << 2, (i+MAGIC_YSZ) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	}
    }

    CLOSE_DISP( game_play->g.graph );
}




/********************************************************
 *	ＴＯＴＡＬ─ＥｖｅｎｔＴｉｍｅｒ開始		*
 ********************************************************/
extern void
total_event_timer_set( short total_event_time )
{
    /* タイマー開始 */
    ZCommonSet( event_xp[1], 140 );	/* タイマー表示Ｘ位置 */
    ZCommonSet( event_yp[1],  80 );	/* タイマー表示Ｙ位置 */
    
    player_diving = 0;

    TOTAL_EVENT_TM = total_event_time;
    if ( total_event_time ) 
	TOTAL_EVENT_FG = TEvent_MD1;	/* 減算 */
    else
	TOTAL_EVENT_FG = TEvent_MD11;	/* 加算 */
}
/********************************************************
 *	ＴＯＴＡＬ─ＥｖｅｎｔＴｉｍｅｒ強制終了	*
 ********************************************************/
extern void
total_event_timer_end( Game_play *game_play )
{
    game_play;
    if ( TOTAL_EVENT_FG ) {
	if ( G_EVENT_INF( 1, 0x0001 ) )
	    TOTAL_EVENT_TM = 4*60-1;
	else
	    TOTAL_EVENT_TM = 1;
    }
}
/********************************************************
 *	ＥｖｅｎｔＴｉｍｅｒ開始			*
 ********************************************************/
extern void
event_timer_set( short event_time )
{
    /* タイマー開始 */
    ZCommonSet( event_xp[0], 140 );	/* タイマー表示Ｘ位置 */
    ZCommonSet( event_yp[0],  80 );	/* タイマー表示Ｙ位置 */

    player_diving = 0;

    EVENT_TM = event_time;
    if ( event_time ) 
	EVENT_FG = Event_MD5;		/* 減算 */
    else
	EVENT_FG = Event_MD30;		/* 加算 */
}


# if 0
/*===============================================================
  =	   I4・ルピー数表示					=
 ===============================================================*/
extern void
texture_I8( Graph *graph, short no, int xpos, int ypos )
{
    OPEN_DISP( graph );

    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			 rupy_num0_txt + (8*16)*no, G_IM_FMT_I, G_IM_SIZ_8b, 8, 16, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 xpos << 2, ypos << 2,
			 xpos + 8 << 2, ypos + 16 << 2,
			 G_TX_RENDERTILE, 0, 0, 1 <<10, 1 << 10 );

    CLOSE_DISP( graph );
}
# endif




/*===============================================================
  =	   ＢボタンＤＯメッセージ表示				=
 ===============================================================*/
static void
do_message_display( Graph *graph, void *timg )
{
    OPEN_DISP( graph );


    gDPLoadTextureBlock_4b ( NEXT_OVERLAY_DISP,
			     timg, G_IM_FMT_IA, 48, 16, 0,
			     G_TX_NOMIRROR, G_TX_NOMIRROR,
			     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
    gSP1Quadrangle( NEXT_OVERLAY_DISP, 0, 2, 3, 1, 0 );

    CLOSE_DISP( graph );
}







# if 0
/*===============================================================
  =	ボタン背景表示						=
  ===============================================================*/
static void
button_background_rectangle( Game_play *game_play, short no, short pt, short alpha )
{
    OPEN_DISP( game_play->g.graph );

    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), alpha );
    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
    SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, item_back_txt + ((32*32)*pt),
						32, 32,
						ZREG(70+no), ZREG(74+no),
						VREG(80+no), VREG(80+no),
						ZREG(78+no) << 1, ZREG(78+no) << 1 )
			  );
/*    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			 item_back_txt + ((32*32)*pt),
			 G_IM_FMT_IA, G_IM_SIZ_8b,
			 32, 32, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD);
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 ZREG(70+no) << 2, ZREG(74+no) << 2,
			 (ZREG(70+no)+VREG(80+no)) << 2, (ZREG(74+no)+VREG(80+no)) << 2,
			 G_TX_RENDERTILE, 0, 0, ZREG(78+no) << 1, ZREG(78+no) << 1 );*/

    CLOSE_DISP( game_play->g.graph );
}
# endif
/*===============================================================
  =	基本全ボタン背景表示					=
  ===============================================================*/
static void
button_background_rectangle_all( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    Kscope		*kscope = (Kscope *)&game_play->kscope;

#if defined(PAL_VERSION)
    static unchar	*navi_txt[] = {
	h_navi_nes_txt, h_navi_nes_txt, h_navi_nes_txt
    };
#else
    static unchar	*navi_txt[] = {
	h_navi_txt, h_navi_nes_txt,
    };
#endif
    static short	start_xpos[] = {
	132, 130, 130,
    };
    
    short 		pt;
#if defined(PAL_VERSION)
    short	scale, xsize, ysize;
#endif

    OPEN_DISP( game_play->g.graph );

    /* Ｂボタン */
    gDPPipeSync( NEXT_OVERLAY_DISP );
//////////    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT3, G_CC_INT3 );
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(43), ZREG(44), ZREG(45), parameter->b_alpha );
    gDPSetEnvColor( NEXT_OVERLAY_DISP, 0, 0, 0, 255 );
////////    gDPSetEnvColor( NEXT_OVERLAY_DISP, ZREG(36), ZREG(37), ZREG(38), 255 );
    SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, item_back_txt,
						32, 32,
						ZREG(70+0), ZREG(74+0),
						VREG(80+0), VREG(80+0),
						ZREG(78+0) << 1, ZREG(78+0) << 1 )
			  );
/*    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			 item_back_txt, G_IM_FMT_IA, G_IM_SIZ_8b,
			 32, 32, 0,
			 G_TX_NOMIRROR, G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD);
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 ZREG(70+0) << 2, ZREG(74+0) << 2,
			 (ZREG(70+0)+VREG(80+0)) << 2, (ZREG(74+0)+VREG(80+0)) << 2,
			 G_TX_RENDERTILE, 0, 0, ZREG(78+0) << 1, ZREG(78+0) << 1 );*/

    /* Ｃボタン */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), parameter->c_alpha );
    /* 左 */
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 ZREG(70+1) << 2, ZREG(74+1) << 2,
			 (ZREG(70+1)+VREG(80+1)) << 2, (ZREG(74+1)+VREG(80+1)) << 2,
			 G_TX_RENDERTILE, 0, 0, ZREG(78+1) << 1, ZREG(78+1) << 1 );
    /* 下 */
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), parameter->c_alpha1 );
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 ZREG(70+2) << 2, ZREG(74+2) << 2,
			 (ZREG(70+2)+VREG(80+2)) << 2, (ZREG(74+2)+VREG(80+2)) << 2,
			 G_TX_RENDERTILE, 0, 0, ZREG(78+2) << 1, ZREG(78+2) << 1 );
    /* 右 */
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), parameter->c_alpha2 );
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 ZREG(70+3) << 2, ZREG(74+3) << 2,
			 (ZREG(70+3)+VREG(80+3)) << 2, (ZREG(74+3)+VREG(80+3)) << 2,
			 G_TX_RENDERTILE, 0, 0, ZREG(78+3) << 1, ZREG(78+3) << 1 );


    /* カレイド・スコープ中（赤丸＆『もどる』）表示 */
    if ( !(kscope->pause >= Pause_Gameover_C && kscope->pause <= Pause_Gameover_E) ) {
	if ( KALEIDO_SCOPE_Pause_on_off( game_play ) ) {
#define SB_SIZE	 	((int)(32.0f * (70.0f/100.0f)))
#define SB_SCALE	((int)(1024.0f / (70.0f/100.0f)))
#define	SB_XSIZE	((int)(48.0f * (80.0f/100.0f)))
#define	SB_YSIZE	((int)(16.0f * (80.0f/100.0f)))
#define	SB_MSCALE	((int)(1024.0f / (80.0f/100.0f)))
#define	Zreg_68	132
#define	Zreg_69	 17
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 200, 0, 0, parameter->start_alpha );
#if defined(PAL_VERSION)
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 start_xpos[J_N] << 2, Zreg_69 << 2,
				 (start_xpos[J_N]+SB_SIZE) << 2, (Zreg_69+SB_SIZE) << 2,
				 G_TX_RENDERTILE, 0, 0, SB_SCALE, SB_SCALE );
#else
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 Zreg_68 << 2, Zreg_69 << 2,
				 (Zreg_68+SB_SIZE) << 2, (Zreg_69+SB_SIZE) << 2,
				 G_TX_RENDERTILE, 0, 0, SB_SCALE, SB_SCALE );
#endif
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->start_alpha );
	    gDPSetEnvColor( NEXT_OVERLAY_DISP,  0, 0, 0, 0 );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
	    gDPLoadTextureBlock_4b ( NEXT_OVERLAY_DISP,
				     parameter->do_actionSegment+G_B_PT*2, G_IM_FMT_IA, 48, 16, 0,
				     G_TX_NOMIRROR, G_TX_NOMIRROR,
				     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
#if defined(PAL_VERSION)
	    scale = ((int)(1024.0f / ((float)ZREG(48+J_N)/100.0f)));
	    xsize = ((int)(48.0f / ((float)ZREG(48+J_N)/100.0f)));
	    ysize = ((int)(16.0f / ((float)ZREG(48+J_N)/100.0f)));
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 ZREG(54+J_N) << 2, ZREG(51+J_N) << 2,
/*				 (ZREG(66)+SB_XSIZE) << 2, (ZREG(65)+SB_YSIZE) << 2,*/
				 (ZREG(54+J_N)+xsize) << 2, (ZREG(51+J_N)+ysize) << 2,
/*				 G_TX_RENDERTILE, 0, 0, SB_MSCALE, SB_MSCALE );*/
				 G_TX_RENDERTILE, 0, 0, scale, scale );
#else
	    ZREG(48) = ((int)(1024.0f / ((float)ZREG(49+J_N)/100.0f)));
	    ZREG(51) = ((int)(48.0f / ((float)ZREG(49+J_N)/100.0f)));
	    ZREG(52) = ((int)(16.0f / ((float)ZREG(49+J_N)/100.0f)));
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 ZREG(55+J_N) << 2, ZREG(53+J_N) << 2,
/*				 (ZREG(66)+SB_XSIZE) << 2, (ZREG(65)+SB_YSIZE) << 2,*/
				 (ZREG(55+J_N)+ZREG(51)) << 2, (ZREG(53+J_N)+ZREG(52)) << 2,
/*				 G_TX_RENDERTILE, 0, 0, SB_MSCALE, SB_MSCALE );*/
				 G_TX_RENDERTILE, 0, 0, ZREG(48), ZREG(48) );
#endif
	}
    }

    /* ナヴィボタン（黄丸＆『ナヴィ』）表示 */
    if ( parameter->navi_flag && !KALEIDO_SCOPE_Pause_on_off( game_play ) && !game_play->demo_play.mode ) {
#define NB_SIZE	 	((int)(32.0f * (50.0f/100.0f)))
#define NB_SCALE	((int)(1024.0f / (50.0f/100.0f)))
	if ( !navi_pt ) {
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    if ( Z_PREV_ALPHA_TYPE == 1 || Z_PREV_ALPHA_TYPE == 2 || Z_PREV_ALPHA_TYPE == 5 ) pt = 0;
	    else {
		if ( bitcheck( player->action, (P_ACTION_LADDER) ) ||	/* つかまり／ぶら下がり中？ */
		     player_condition_check( game_play ) == 4 ||	/* 浮上中？ */
		     bitcheck(player->action2, (P_ACTION2_TUNNEL) ) 	/* 横穴モード？ */
		    ) pt = CLEAR_ALPHA;
		else pt = parameter->heart_alpha;
	    }
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), pt );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT3, G_CC_INT3 );
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 ZREG(62) << 2, ZREG(63) << 2,
				 (ZREG(62)+NB_SIZE) << 2, (ZREG(63)+NB_SIZE) << 2,
				 G_TX_RENDERTILE, 0, 0, NB_SCALE, NB_SCALE );
	    gDPPipeSync( NEXT_OVERLAY_DISP );
/*	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->heart_alpha );*/
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, pt );
	    gDPSetEnvColor( NEXT_OVERLAY_DISP,  0, 0, 0, 0 );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
	    gDPLoadTextureBlock_4b ( NEXT_OVERLAY_DISP,
				     navi_txt[J_N], G_IM_FMT_IA, 32, 8, 0,
				     G_TX_NOMIRROR, G_TX_NOMIRROR,
				     G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 YREG(88) << 2, YREG(89) << 2,
				 (YREG(88)+32) << 2, (YREG(89)+8) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	}
	if ( !(--navi_ct) ) {
	    navi_pt ^= 1;
	    navi_ct = 10;
/*	    if ( !navi_pt ) {
		Na_StartSystemSe( NA_SE_SY_NAVY_CALL );
	    }*/
	}
    }

    gDPPipeSync( NEXT_OVERLAY_DISP );
    for ( pt = 1; pt < 4; pt++ ) {
	if ( Register_Item(pt) > 0xf0 ) {	/* Ｃボタンアイテム無しマーク */
	    if ( pt == 1 ) {
		gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), parameter->c_alpha );
	    } else if ( pt == 2 ) {
		gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), parameter->c_alpha1 );
	    } else
		gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, ZREG(39), ZREG(40), ZREG(41), parameter->c_alpha2 );
	    SET_NOW_OVERLAY_DISP(
		texture_rectangleIA8( NOW_OVERLAY_DISP, item_back_txt + ((32*32)*(pt+1)),
				      32, 32,
				      ZREG(70+pt), ZREG(74+pt),
				      VREG(80+pt), VREG(80+pt),
				      ZREG(78+pt) << 1, ZREG(78+pt) << 1 )
		);
	}
    }


    CLOSE_DISP( game_play->g.graph );
}
/*===============================================================
  =	ボタンアイテム表示					=
  ===============================================================*/
static void
button_item_rectangle( Game_play *game_play, void *data, short no )
{
    OPEN_DISP( game_play->g.graph );

    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			 data,
			 G_IM_FMT_RGBA, G_IM_SIZ_32b,
			 32, 32, 0,
			 G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK,   G_TX_NOMASK,
			 G_TX_NOLOD,    G_TX_NOLOD );
    gSPTextureRectangle( NEXT_OVERLAY_DISP,
			 ZREG(82+no) << 2, ZREG(86+no) << 2,
			 (ZREG(82+no)+VREG(76+no)) << 2, (ZREG(86+no)+VREG(76+no)) << 2,
			 G_TX_RENDERTILE, 0, 0, ZREG(90+no) << 1, ZREG(90+no) << 1 );

    CLOSE_DISP( game_play->g.graph );
}
/*===============================================================
  =	   アイテム数表示					=
 ===============================================================*/
static void
count_display_rectangle( Game_play *game_play, short no, short alpha )
{
    short	s0, s1;


    OPEN_DISP( game_play->g.graph );

    s0 = Register_Item(no);
//  PRINTF("no=%d  Register_Item=%d  種類＝%d   数＝%d\n",no, Register_Item(no), s0, S_Table.item_count[number_pt[s0]]);
    if ( s0 == H_stick || s0 == H_deku_nut || s0 == H_bomb_1 || s0 == H_bow || (s0 >= H_m_bow_1 && s0 <= H_m_bow_3) || s0 == H_pachinko || s0 == H_bomb_2 || s0 == H_bean ) {
	if ( (s0 >= H_m_bow_1 && s0 <= H_m_bow_3) ) s0 = H_bow;
	s1 = (short)Item_Count(s0);
	gDPPipeSync( NEXT_OVERLAY_DISP );
	if ( !no && Yabusame_Mode == Yabu_START ) {
	    s1 = game_play->parameter.yabusame_arrow;	/* 流鏑馬 */
	} else if ( !no && game_play->bow_game_flag >= 2 ) {
	    s1 = game_play->bow_game_flag - 1;		/* 射的場 */
	} else if ( !no &&
/*		    (game_play->bomchu_game_flag > 0 ||
		     ((short)game_play->bomchu_game_flag == -1 && game_play->actor_info.actor_list[ ACTOR_PART_BOM ].num)) ) {*/
		    (game_play->scene_data_ID == BOWLING && Actor_Environment_sw_Check( game_play, 56 )) ) {
	    s1 = game_play->bomchu_game_flag;		/* ボムチュウボーリング */
	    if ( s1 < 0 ) s1 = 0;
	} else {
	    if ( (s0 == H_bow && (Item_Count(s0) == Item_MaxGet(NE_Bow))) ||
		 (s0 == H_bomb_1 && (Item_Count(s0) == Item_MaxGet(NE_Bomb))) ||
		 (s0 == H_pachinko && (Item_Count(s0) == Item_MaxGet(NE_Pachinko))) ||
		 (s0 == H_stick && (Item_Count(s0) == Item_MaxGet(NE_Stick))) ||
		 (s0 == H_deku_nut && (Item_Count(s0) == Item_MaxGet(NE_Deck_Nut))) ||
		 (s0 == H_bomb_2 && s1 == 50) ||
		 (s0 == H_bean && s1 == 15) ) {
		gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 120, 255,   0, alpha );
	    }
	}
	if ( !s1 ) {
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 100, 100, 100, alpha );
	}
	s0 = 0;
	while ( s1 >= 10 ) {
	    s0++;
	    s1 -= 10;
	}
	if ( s0 ) {
	    SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, num_s0_txt + (8*8)*s0,
							8, 8,
							VREG(64+no), VREG(68+no),
							8, 8,
							1 << 10, 1 << 10 )
				  );
	}
	SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, num_s0_txt + (8*8)*s1,
						    8, 8,
						    VREG(64+no)+6, VREG(68+no),
						    8, 8,
						    1 << 10, 1 << 10 )
				  );
    }

    CLOSE_DISP( game_play->g.graph );
}



/*===============================================================
  =	ボタン背景表示						=
  ===============================================================*/
static void
button_background_set( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    OPEN_DISP( game_play->g.graph );

    Matrix_translate( 0.0f, 0.0f, (float)XREG(18)/10.0f, SET_MTX );
    Matrix_scale( 1.0f, 1.0f, 1.0f, MULT_MTX );
    Matrix_rotateX( parameter->do_action_rotate/10000.0f, MULT_MTX );
    gSPMatrix( NEXT_OVERLAY_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
    gSPVertex( NEXT_OVERLAY_DISP, &(parameter->parameter_frame_vtx[0]), 4, 0 );
    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
			 item_back_txt, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
			 G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_WRAP | G_TX_NOMIRROR,
			 G_TX_NOMASK, G_TX_NOMASK,
			 G_TX_NOLOD, G_TX_NOLOD);
    gSP1Quadrangle( NEXT_OVERLAY_DISP, 0, 2, 3, 1, 0 );

    CLOSE_DISP( game_play->g.graph );
}





/*===============================================================
  =	Ｖｔｘ設定						=
  ===============================================================*/
static void
vtx_data_initial( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    short 	i;


    /* アイテム背景 */
    parameter->parameter_frame_vtx = (Vtx_t *)graph_alloc(game_play->g.graph, sizeof(Vtx_t) * ((1+1)*4) );
    parameter->parameter_frame_vtx[0].ob[0]  = parameter->parameter_frame_vtx[2].ob[0]  = (short)-(AB_BUTTON_SIZE/2);
    parameter->parameter_frame_vtx[1].ob[0]  = parameter->parameter_frame_vtx[3].ob[0]  = (short)(parameter->parameter_frame_vtx[0].ob[0] + AB_BUTTON_SIZE);
    parameter->parameter_frame_vtx[0].ob[1]  = parameter->parameter_frame_vtx[1].ob[1]  = (short)(AB_BUTTON_SIZE/2);
    parameter->parameter_frame_vtx[2].ob[1]  = parameter->parameter_frame_vtx[3].ob[1]  = (short)(parameter->parameter_frame_vtx[0].ob[1] - AB_BUTTON_SIZE);
    parameter->parameter_frame_vtx[4].ob[0] = parameter->parameter_frame_vtx[6].ob[0] = (short)-(XREG(21)/2);
    parameter->parameter_frame_vtx[5].ob[0] = parameter->parameter_frame_vtx[7].ob[0] = (short)(parameter->parameter_frame_vtx[4].ob[0] + XREG(21));
    parameter->parameter_frame_vtx[4].ob[1] = parameter->parameter_frame_vtx[5].ob[1] = (short)(XREG(28)/2);
    parameter->parameter_frame_vtx[6].ob[1] = parameter->parameter_frame_vtx[7].ob[1] = (short)(parameter->parameter_frame_vtx[4].ob[1] - XREG(28));
    for ( i=0; i<(1+1)*4; i+=4 ) {
	parameter->parameter_frame_vtx[i+0].ob[2] = parameter->parameter_frame_vtx[i+1].ob[2] = 
	    parameter->parameter_frame_vtx[i+2].ob[2] = parameter->parameter_frame_vtx[i+3].ob[2] = 0;
	parameter->parameter_frame_vtx[i+0].flag = parameter->parameter_frame_vtx[i+1].flag = 
	    parameter->parameter_frame_vtx[i+2].flag = parameter->parameter_frame_vtx[i+3].flag = 0;
	parameter->parameter_frame_vtx[i+0].tc[0] = parameter->parameter_frame_vtx[i+0].tc[1] = 
	    parameter->parameter_frame_vtx[i+1].tc[1] = parameter->parameter_frame_vtx[i+2].tc[0] = 0;
	parameter->parameter_frame_vtx[i+1].tc[0] = parameter->parameter_frame_vtx[i+2].tc[1] = 
	    parameter->parameter_frame_vtx[i+3].tc[0] = parameter->parameter_frame_vtx[i+3].tc[1] = BUTTON_SIZE << 5;
	parameter->parameter_frame_vtx[i+0].cn[0] = parameter->parameter_frame_vtx[i+1].cn[0] = 
	    parameter->parameter_frame_vtx[i+2].cn[0] = parameter->parameter_frame_vtx[i+3].cn[0] =
	    parameter->parameter_frame_vtx[i+0].cn[1] = parameter->parameter_frame_vtx[i+1].cn[1] = 
	    parameter->parameter_frame_vtx[i+2].cn[1] = parameter->parameter_frame_vtx[i+3].cn[1] =
	    parameter->parameter_frame_vtx[i+0].cn[2] = parameter->parameter_frame_vtx[i+1].cn[2] = 
	    parameter->parameter_frame_vtx[i+2].cn[2] = parameter->parameter_frame_vtx[i+3].cn[2] = 255;
	parameter->parameter_frame_vtx[i+0].cn[3] = parameter->parameter_frame_vtx[i+1].cn[3] = 
	    parameter->parameter_frame_vtx[i+2].cn[3] = parameter->parameter_frame_vtx[i+3].cn[3] = 255;
    }
    parameter->parameter_frame_vtx[4+1].tc[0] = parameter->parameter_frame_vtx[4+3].tc[0] = 48 << 5;
    parameter->parameter_frame_vtx[4+2].tc[1] = parameter->parameter_frame_vtx[4+3].tc[1] = 16 << 5;

    /* 点滅ハートVtx */
///////    parameter->heartVtx = (Vtx_t *)graph_alloc(game_play->g.graph, sizeof(Vtx_t) * (2 * 4) );
    parameter->heartVtx = (Vtx_t *)graph_alloc(game_play->g.graph, sizeof(Vtx_t) * 4 );
    parameter->heartVtx[0].ob[0] = parameter->heartVtx[2].ob[0] = -8;
    parameter->heartVtx[1].ob[0] = parameter->heartVtx[3].ob[0] =  8;
    parameter->heartVtx[0].ob[1] = parameter->heartVtx[1].ob[1] =  8;
    parameter->heartVtx[2].ob[1] = parameter->heartVtx[3].ob[1] = -8;
	parameter->heartVtx[0].ob[2] = parameter->heartVtx[1].ob[2] =
	parameter->heartVtx[2].ob[2] = parameter->heartVtx[3].ob[2] = 0;
    parameter->heartVtx[0].flag = parameter->heartVtx[1].flag = 
	parameter->heartVtx[2].flag = parameter->heartVtx[3].flag = 0;
    parameter->heartVtx[0].tc[0] = parameter->heartVtx[0].tc[1] = 
	parameter->heartVtx[1].tc[1] = parameter->heartVtx[2].tc[0] = 0;
    parameter->heartVtx[1].tc[0] = parameter->heartVtx[2].tc[1] = 
	parameter->heartVtx[3].tc[0] = parameter->heartVtx[3].tc[1] = 16 << 5;
    parameter->heartVtx[0].cn[0] = parameter->heartVtx[1].cn[0] = 
	parameter->heartVtx[2].cn[0] = parameter->heartVtx[3].cn[0] =
	parameter->heartVtx[0].cn[1] = parameter->heartVtx[1].cn[1] = 
	parameter->heartVtx[2].cn[1] = parameter->heartVtx[3].cn[1] =
	parameter->heartVtx[0].cn[2] = parameter->heartVtx[1].cn[2] = 
	parameter->heartVtx[2].cn[2] = parameter->heartVtx[3].cn[2] =
	parameter->heartVtx[0].cn[3] = parameter->heartVtx[1].cn[3] = 
	parameter->heartVtx[2].cn[3] = parameter->heartVtx[3].cn[3] = 255;
# if 0
    /* ＭＡＰ点（プレイヤー位置）*/
    parameter->heartVtx[4].ob[2] = parameter->heartVtx[5].ob[2] =
	parameter->heartVtx[6].ob[2] = parameter->heartVtx[7].ob[2] = 0;
    parameter->heartVtx[4].flag = parameter->heartVtx[5].flag = 
	parameter->heartVtx[6].flag = parameter->heartVtx[7].flag = 0;
    parameter->heartVtx[4].tc[0] = parameter->heartVtx[4].tc[1] = 
	parameter->heartVtx[5].tc[1] = parameter->heartVtx[6].tc[0] = 0;
    parameter->heartVtx[5].tc[0] = parameter->heartVtx[6].tc[1] = 
	parameter->heartVtx[7].tc[0] = parameter->heartVtx[7].tc[1] = BUTTON_SIZE << 5;
    parameter->heartVtx[4].cn[0] = parameter->heartVtx[5].cn[0] = 
	parameter->heartVtx[6].cn[0] = parameter->heartVtx[7].cn[0] =
	parameter->heartVtx[4].cn[1] = parameter->heartVtx[5].cn[1] = 
	parameter->heartVtx[6].cn[1] = parameter->heartVtx[7].cn[1] =
	parameter->heartVtx[4].cn[2] = parameter->heartVtx[5].cn[2] = 
	parameter->heartVtx[6].cn[2] = parameter->heartVtx[7].cn[2] =
	parameter->heartVtx[4].cn[3] = parameter->heartVtx[5].cn[3] = 
	parameter->heartVtx[6].cn[3] = parameter->heartVtx[7].cn[3] = 255;
# endif
}



/*===============================================================
  =	パラメーター表示 透視射影ビュー設定			=
 ===============================================================*/
static void
parameter_perspective_view( Game_play *game_play, int top, int bottom, int left, int right )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;


    xyz_t	eye, center, up;


    /*
     * ビュー設定
     */
    eye.x = eye.y = eye.z = 0.0f;
    center.x = center.y = 0.0f;
    center.z = -1.0f;
    up.x = up.z = 0.0f;
    up.y = 1.0f;

    setLookAtView( &parameter->view, &eye, &center, &up );

    parameter->vw.top    = top;
    parameter->vw.bottom = bottom;
    parameter->vw.left   = left;
    parameter->vw.right  = right;
    setScissorView( &parameter->view, &parameter->vw );

    setPerspectiveView( &parameter->view, 60, 10, 60 );

    showPerspectiveOverLayView( &parameter->view );
}



/*===============================================================
  =	パラメーター表示 正射影ビュー設定			=
 ===============================================================*/
static void
parameter_view( Parameter *parameter )
{
    view_set_ScissorBox( &parameter->view, 0, 0, SCREEN_WD, SCREEN_HT );

    showOverLayView( &parameter->view );
}







/************************************************************************
 *									*
 *	パラメーターＤＲＡＷ						*
 *									*
 ************************************************************************/
extern void
parameter_draw( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Kscope		*kscope = (Kscope *)&game_play->kscope;

    Message		*message = (Message *)&game_play->message;

    Player_actor	*player = (Player_actor *)get_player_actor(game_play);


    static short	power_r[] = {
	255, 100, 255,
    };
    static short	power_g[] = {
	  0, 100, 255,
    };
    static short	power_b[] = {
	  0, 255, 100,
    };
    
    static short tm_xp[] = {
	16, 16+9, 16+9+9, 16+9+9+8, 16+9+9+8+9,
    };
    static short tm_xsz[] = {
	 9,    9,      8,        9,          9,
    };
    
    short	i, j, l0, l3, ht_xp;
    static short	display_tm, frame_tm;
    static short	total_display_tm, total_frame_tm;
    static short navi_flush_color[][3] = {
    	{   0, 150,   0 },
	{ 100, 255,   0 },
    };
    static short navi_flush[][3] = {
    	{ 255, 255, 255 },
	{   0,   0,   0 },
    	{ 255, 255, 255 },
    };
    static short	etm[5];

    static short	purse_pt0[] = {
	1, 0, 0,
    };
    static short	purse_pt1[] = {
	2, 3, 3,
    };

    static short 	Next_scene[] = {
	SPOT10_2,
	SPOT07_3,
	SPOT07_3,
    };
    static float	a_scale[] = {
	-40.0f, -35.0f,
    };
    static short	b_scale[] = {
	((short)(1024.0f / 11.2f)),
	((short)(1024.0f / 11.2f)),
    };
#define	SetScissor	45	 /* シザ─サイズ */
    short	event_pt;

    OPEN_DISP( game_play->g.graph );


    /*
     * Ｓｅｇｍｅｎｔ設定
     */
    gSPSegment ( NEXT_OVERLAY_DISP, DYNAMIC_SEGMENT,    parameter->parameterSegment );
    gSPSegment ( NEXT_OVERLAY_DISP, PARAMETER0_SEGMENT, parameter->do_actionSegment );
    gSPSegment ( NEXT_OVERLAY_DISP, ICON_ITEM_SEGMENT,  parameter->icon_itemSegment );
    gSPSegment ( NEXT_OVERLAY_DISP, MAP_SEGMENT,        parameter->mapSegment );


    if ( !kscope->debug ) {
    /*
     * Ｖｔｘ設定
     */
    vtx_data_initial( game_play );

    /*
     * ビュー設定
     */
    parameter_view( parameter );

    /*
     * Ｌｉｆｅ Ｍｅｔｅｒ
     */
    DrawLifeMeter( game_play );
    
    /*
     * ルピー ＆ ダンジョン鍵
     */
    overlay_rectangle_a_prim(game_play->g.graph);
    /* ルピー表示 */
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 200, 255, 100, parameter->meter_alpha );
    gDPSetEnvColor( NEXT_OVERLAY_DISP, 0, 80, 0, 255 );
    SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, rupy_txt,
						16, 16,
						26, 206,
						16, 16,
						1 << 10, 1 << 10 )
			  );
    
    switch ( game_play->scene_data_ID ) {
////////    case YDAN:		/* 妖精の木のダンジョン		*/
////////    case DDAN:		/* ドドンゴダンジョン		*/
////////    case BDAN:		/* 魚ダンジョン			*/
    case MORI1:		/* 森の神殿			*/
    case HIDAN:		/* 炎の神殿			*/
    case MIZUSIN:	/* 水の神殿			*/
    case JYASINZOU:	/* 巨大邪神像ダンジョン         */
    case HAKADAN:	/* 墓下ダンジョン       	*/
    case HAKADAN_CH:	/* 墓下ダンジョン こども      	*/
    case ICE_DOUKUTU:	/* 氷の洞窟                     */
    case GANON:		/* ガノンの塔			*/
    case MEN:		/* 面クリダンジョン		*/
    case GERUDOWAY:	/* ゲルド通路			*/
    case GANONTIKA:	/* ガノン地下		        */
    case GANON_SONOGO:	/* ガノンの塔その後		*/
    case GANONTIKA_SONOGO:/* ガノン地下その後		*/
    case TAKARAYA:	/* 宝箱屋			*/
	if ( S_Table.key_register[Scene_ID] >= 0 ) {
	    /* ダンジョン鍵表示 */
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 200, 230, 255, parameter->meter_alpha );
	    gDPSetEnvColor( NEXT_OVERLAY_DISP,  0,  0, 20, 255 );
	    SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, g_key_txt,
							16, 16,
							KEY_XDP, KEY_YDP,
							16, 16,
							1 << 10, 1 << 10 )
		);
	    
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->meter_alpha );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT4, G_CC_INT4 );
	    parameter->rpc[2] = 0;
	    parameter->rpc[3] = S_Table.key_register[Scene_ID];
	    while ( parameter->rpc[3] >= 10 ) {
		parameter->rpc[2]++;
		parameter->rpc[3] -=10;
	    }
	    l0 = KEY_XDP+16;
	    if ( parameter->rpc[2] ) {
		SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + ((8*16)*parameter->rpc[2]),
							    8, 16,
							    l0, KEY_YDP,
							    8, 16,
							    1 << 10, 1 << 10 )
				      );
		l0 += 8;
	    }
	    SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + ((8*16)*parameter->rpc[3]),
						       8, 16,
						       l0, KEY_YDP,
						       8, 16,
						       1 << 10, 1 << 10 )
				  );
	}
	break;
    default:
	break;
    }
    
    /* ルピー数表示 */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    if ( S_Private.lupy_count == Item_MaxGet( NE_Purse ) ) {
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 120, 255,   0, parameter->meter_alpha );
    } else if ( S_Private.lupy_count ) {
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->meter_alpha );
    } else {
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0,100, 100, 100, parameter->meter_alpha );
    }
    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT4, G_CC_INT4 );
    parameter->rpc[0] = parameter->rpc[1] = 0;
    parameter->rpc[2] = S_Private.lupy_count;
    if ( parameter->rpc[2] > 9999 || parameter->rpc[2] < 0 ) parameter->rpc[2] = (short)(parameter->rpc[2] & 0xddd);
    while ( parameter->rpc[2] >= 100 ) {
	parameter->rpc[0]++;
	parameter->rpc[2] -= 100;
    }
    while ( parameter->rpc[2] >= 10 ) {
	parameter->rpc[1]++;
	parameter->rpc[2] -=10;
    }
    j = purse_pt0[Non_Equip_Register( NE_Purse )];
    l3 = purse_pt1[Non_Equip_Register( NE_Purse )];
    for ( i = 0, l0 = 26+16; i < l3; i++, j++, l0+=8 ) {
	SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + ((8*16)*parameter->rpc[j]),
						   8, 16,
						   l0, 206,
						   8, 16,
						   1 << 10, 1 << 10 )
			      );
    }

    /*
     * 魔法メーター
     */
    magic_meter_draw( game_play );
    
    /*
     * ＭＡＰ
     */
    map_exp_draw( game_play );
    
    /*
     * 岩脇注目カーソル
     */
    if ( PR_KAREIDOSCOPE_MODE !=2 && PR_KAREIDOSCOPE_MODE !=3 ) {
	Anchor_Marker_target_draw( &game_play->actor_info.anchor_marker, game_play );
    }
    
    /*
     * ボタン背景
     */
    overlay_rectangle_a_prim(game_play->g.graph);
    /* 基本全ボタン背景表示 */
    button_background_rectangle_all( game_play );
    /* Ｂボタン ： アイテム */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->b_alpha );
    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
    if ( !parameter->sp_action_flag ) {
	if ( Register_Item(0) != 0xff ) {
	    button_item_rectangle( game_play, parameter->icon_itemSegment+I_IT_PT*0, 0 );
/*	    if ( Register_Item(0) == H_pachinko ||
		 Register_Item(0) == H_bow ||
		 Register_Item(0) == H_bomb_2 ) {*/
		if ( player->action & P_ACTION_RIDE_HORSE ||
		     game_play->bow_game_flag >= 2 ||
		     (game_play->scene_data_ID == BOWLING && Actor_Environment_sw_Check( game_play, 56 )) ) {
		/* アイテム数 */
		gDPPipeSync( NEXT_OVERLAY_DISP );
		gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
//		if ( !(game_play->bow_game_flag >= 2 || game_play->bomchu_game_flag > 0) ) {
		    count_display_rectangle( game_play, 0, parameter->b_alpha );
//		}
	    }
	}
    } else {
	gDPPipeSync( NEXT_OVERLAY_DISP );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->b_alpha );
	gDPLoadTextureBlock_4b ( NEXT_OVERLAY_DISP,
				 parameter->do_actionSegment+G_B_PT, G_IM_FMT_IA, 48, 16, 0,
				 G_TX_NOMIRROR, G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD );
#if defined(PAL_VERSION)
#if defined(GATEWAY_VERSION)
	if ( !(parameter->sp_action == DO_Save ||
	       parameter->sp_action == DO_Save+DO_F_Navi ||
	       parameter->sp_action == DO_Save+DO_F_Navi+DO_F_Navi) ) {
	    WREG(0) = ((int)(1024.0f / ((float)WREG(37+J_N)/100.0f)));
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
/*			     152 << 2, 24 << 2,
			     (152+48) << 2, (24+16) << 2,*/
				 WREG(40+J_N) << 2, WREG(43+J_N) << 2,
				 (WREG(40+J_N)+48) << 2, (WREG(43+J_N)+16) << 2,
				 G_TX_RENDERTILE, 0, 0, WREG(0), WREG(0) );
/*			     G_TX_RENDERTILE, 0, 0, ZREG(90) << 1, ZREG(90) << 1 );*/
/*			     G_TX_RENDERTILE, 0, 0, b_scale[J_N] << 1, b_scale[J_N] << 1 );*/
	}
#else
	WREG(0) = ((int)(1024.0f / ((float)WREG(37+J_N)/100.0f)));
	gSPTextureRectangle( NEXT_OVERLAY_DISP,
/*			     152 << 2, 24 << 2,
			     (152+48) << 2, (24+16) << 2,*/
			     WREG(40+J_N) << 2, WREG(43+J_N) << 2,
			     (WREG(40+J_N)+48) << 2, (WREG(43+J_N)+16) << 2,
			     G_TX_RENDERTILE, 0, 0, WREG(0), WREG(0) );
/*			     G_TX_RENDERTILE, 0, 0, ZREG(90) << 1, ZREG(90) << 1 );*/
/*			     G_TX_RENDERTILE, 0, 0, b_scale[J_N] << 1, b_scale[J_N] << 1 );*/
#endif	/* GATEWAY_VERSION */
#else
#if defined(GATEWAY_VERSION)
	if ( !(parameter->sp_action == DO_Save || parameter->sp_action == DO_Save+DO_F_Navi) ) {
	    WREG(0) = ((int)(1024.0f / ((float)WREG(8+J_N)/100.0f)));
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
/*			     152 << 2, 24 << 2,
			     (152+48) << 2, (24+16) << 2,*/
				 WREG(10+J_N) << 2, WREG(12+J_N) << 2,
				 (WREG(10+J_N)+48) << 2, (WREG(12+J_N)+16) << 2,
				 G_TX_RENDERTILE, 0, 0, WREG(0), WREG(0) );
/*			     G_TX_RENDERTILE, 0, 0, ZREG(90) << 1, ZREG(90) << 1 );*/
/*			     G_TX_RENDERTILE, 0, 0, b_scale[J_N] << 1, b_scale[J_N] << 1 );*/
	}
#else
	WREG(0) = ((int)(1024.0f / ((float)WREG(8+J_N)/100.0f)));
	gSPTextureRectangle( NEXT_OVERLAY_DISP,
/*			     152 << 2, 24 << 2,
			     (152+48) << 2, (24+16) << 2,*/
			     WREG(10+J_N) << 2, WREG(12+J_N) << 2,
			     (WREG(10+J_N)+48) << 2, (WREG(12+J_N)+16) << 2,
			     G_TX_RENDERTILE, 0, 0, WREG(0), WREG(0) );
/*			     G_TX_RENDERTILE, 0, 0, ZREG(90) << 1, ZREG(90) << 1 );*/
/*			     G_TX_RENDERTILE, 0, 0, b_scale[J_N] << 1, b_scale[J_N] << 1 );*/
#endif	/* GATEWAY_VERSION */
#endif	/* PAL_VERSION */
    }
    /* Ｃボタン左 ： アイテム */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    if ( Register_Item(1) < 0xf0 ) {
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->c_alpha );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	button_item_rectangle( game_play, parameter->icon_itemSegment+I_IT_PT*1, 1 );
	/* アイテム数 */
	gDPPipeSync( NEXT_OVERLAY_DISP );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
	count_display_rectangle( game_play, 1, parameter->c_alpha );
    }
    /* Ｃボタン下 ： アイテム */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    if ( Register_Item(2) < 0xf0 ) {
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->c_alpha1 );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	button_item_rectangle( game_play, parameter->icon_itemSegment+I_IT_PT*2, 2 );
	/* アイテム数 */
	gDPPipeSync( NEXT_OVERLAY_DISP );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
	count_display_rectangle( game_play, 2, parameter->c_alpha1 );
    }
    /* Ｃボタン右 ： アイテム */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    if ( Register_Item(3) < 0xf0 ) {
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->c_alpha2 );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	button_item_rectangle( game_play, parameter->icon_itemSegment+I_IT_PT*3, 3 );
	/* アイテム数 */
	gDPPipeSync( NEXT_OVERLAY_DISP );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );
	count_display_rectangle( game_play, 3, parameter->c_alpha2 );
    }
    /* Ａボタン ： 背景 */
    overlay_kaleido_scope_prim( game_play->g.graph );
    parameter_perspective_view( game_play, XREG(16), XREG(16)+SetScissor, XREG(17), XREG(17)+SetScissor );
    gSPClearGeometryMode( NEXT_OVERLAY_DISP, G_CULL_BOTH );
    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT3, G_CC_INT3 );
    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, XREG(22), XREG(23), XREG(24), parameter->a_alpha );
    button_background_set( game_play );
    
    /* アイテム */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    parameter_perspective_view( game_play, XREG(19), XREG(19)+SetScissor, XREG(20), XREG(20)+SetScissor );
    gSPSetGeometryMode( NEXT_OVERLAY_DISP, G_CULL_BACK );
    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT9, G_CC_INT9 );

    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->a_alpha );
    gDPSetEnvColor( NEXT_OVERLAY_DISP,  0, 0, 0, 0 );
#if defined(PAL_VERSION)
    Matrix_translate( 0.0f, 0.0f, (float)WREG(46+J_N)/10.0f, SET_MTX );
#else
    Matrix_translate( 0.0f, 0.0f, (float)WREG(14+J_N)/10.0f, SET_MTX );
#endif
/*    Matrix_translate( 0.0f, 0.0f, a_scale[J_N], SET_MTX );*/
    Matrix_scale( 1.0f, 1.0f, 1.0f, MULT_MTX );
    Matrix_rotateX( parameter->do_action_rotate/10000.0f, MULT_MTX );
    gSPMatrix( NEXT_OVERLAY_DISP, Matrix_to_Mtx_new(game_play->g.graph), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH );
    gSPVertex( NEXT_OVERLAY_DISP, &(parameter->parameter_frame_vtx[4]), 4, 0 );
    if ( parameter->do_action_flg  < 2 || parameter->do_action_flg == 3 ) {
	do_message_display( game_play->g.graph, parameter->do_actionSegment );
    } else {
	do_message_display( game_play->g.graph, parameter->do_actionSegment+G_B_PT );
    }

    
    /*
     * カレイド・スコープ移動アイテム
     */
    gDPPipeSync( NEXT_OVERLAY_DISP );
    parameter_view( parameter );
    if ( kscope->pause == Pause_Play && kscope->kscp_status == 0x03 ) {
	gSPSegment ( NEXT_OVERLAY_DISP, ICON_ITEM_SEGMENT,  kscope->icon_itemSegment );
	overlay_kaleido_scope_prim( game_play->g.graph );
	gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	GspLoadIdentity(NEXT_OVERLAY_DISP);
	kscope->cursolVtx[16].ob[0] = kscope->cursolVtx[18].ob[0] = (short)kscope->sl_xpos/10;
	kscope->cursolVtx[17].ob[0] = kscope->cursolVtx[19].ob[0] = (short)(kscope->cursolVtx[16].ob[0] + WREG(90) / 10);
	kscope->cursolVtx[16].ob[1] = kscope->cursolVtx[17].ob[1] = (short)kscope->sl_ypos/10;
	kscope->cursolVtx[18].ob[1] = kscope->cursolVtx[19].ob[1] = (short)(kscope->cursolVtx[16].ob[1] - WREG(90) / 10);
	if ( kscope->sl_item_no < H_power_1 ) {
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, kscope->sl_alpha );
	    gSPVertex( NEXT_OVERLAY_DISP, &(kscope->cursolVtx[16]), 4, 0);
	    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
				 item_data[kscope->sl_item_no],
				 G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD);
	} else {
	    i = kscope->sl_item_no - H_power_1;
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, power_r[i], power_g[i], power_b[i], kscope->sl_alpha );
	    if ( kscope->sl_alpha >= 1 && kscope->sl_alpha < 255 ) {
		i = (kscope->sl_alpha / 8) / 2;
		kscope->cursolVtx[16].ob[0] = kscope->cursolVtx[18].ob[0] = (short)(kscope->cursolVtx[16].ob[0] - i);
		kscope->cursolVtx[17].ob[0] = kscope->cursolVtx[19].ob[0] = (short)(kscope->cursolVtx[16].ob[0] + 32 + (i*2));
		kscope->cursolVtx[16].ob[1] = kscope->cursolVtx[17].ob[1] = (short)(kscope->cursolVtx[16].ob[1] + i);
		kscope->cursolVtx[18].ob[1] = kscope->cursolVtx[19].ob[1] = (short)(kscope->cursolVtx[16].ob[1] - 32 - (i*2));
	    }
	    gSPVertex( NEXT_OVERLAY_DISP, &(kscope->cursolVtx[16]), 4, 0);
	    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
				 h_32_power_0_txt,
				 G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD);
	}
	gSP1Quadrangle( NEXT_OVERLAY_DISP, 0, 2, 3, 1, 0 );
    }
    
    /*
     * 鞭メーター表示
     */
    overlay_rectangle_a_prim( game_play->g.graph );
    if ( !KALEIDO_SCOPE_Pause_on_off( game_play ) ) {
	if ( Yabusame_Mode != Yabu_START ) {
	    if ( parameter->do_action == DO_Lash ) {
		gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
				     g_muti_txt, G_IM_FMT_RGBA, G_IM_SIZ_32b, 16, 16, 0,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_WRAP | G_TX_NOMIRROR,
				     G_TX_NOMASK, G_TX_NOMASK,
				     G_TX_NOLOD, G_TX_NOLOD);
		for ( i = 1, ht_xp = ZREG(14); i < 7; i++, ht_xp += 16 ) {
		    if ( !parameter->lash_ct || i > parameter->lash_ct ) {
			gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0,   0, 150, 255, parameter->a_alpha );
		    } else {
			gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->a_alpha );
		    }
		    gSPTextureRectangle( NEXT_OVERLAY_DISP,
					 ht_xp << 2, ZREG(15) << 2,
					 (ht_xp+16) << 2, (ZREG(15)+16) << 2,
					 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
		}
	    }
	} else {
	    ht_xp = WREG(32);
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->b_alpha );
	    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
				 h_yabusame_txt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD );
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 (ht_xp+(9*3)+1) << 2, ZREG(15) << 2,
				 ((ht_xp+(9*3)+1)+24) << 2, (ZREG(15)+16) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT4, G_CC_INT4 );
	    ht_xp = (WREG(32)+(9*3+1)+(24+2));
	    for ( i = j = 0; i < 4; i++ ) {
		if ( !(!yabu_total[i] && !j && i < 3) ) {
		    SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + (8*16)*yabu_total[i],
							       8, 16,
							       ht_xp, (ZREG(15)-2),
							       tm_xsz[0], VREG(42),
							       VREG(43) << 1, VREG(43) << 1 )
			);
		    ht_xp+=9;
		    j++;
		}
	    }
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_MODULATERGBA_PRIM, G_CC_MODULATERGBA_PRIM );
	}
    }

# if 0
    /*
     * 射的場の矢メーター表示
     */
    if ( !(KALEIDO_SCOPE_Pause_on_off( game_play )) &&
	 !message->msg_mode &&
	 !game_play->fade_direction &&
	 !game_play->fbdemo_wipe_mode &&
	 !Game_play_demo_mode_check( game_play ) ) {
	if ( (game_play->bow_game_flag >= 2 || game_play->bomchu_game_flag > 0) && !EVENT_FG ) {
	    if ( game_play->bow_game_flag >= 2 ) {
		j = game_play->bow_game_flag - 1;
	    } else if ( game_play->bomchu_game_flag > 0 ) {
		j = game_play->bomchu_game_flag;
	    }
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, parameter->b_alpha );
	    gDPLoadTextureBlock( NEXT_OVERLAY_DISP,
				 parameter->icon_itemSegment, G_IM_FMT_RGBA, G_IM_SIZ_32b, 32, 32, 0,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_WRAP | G_TX_NOMIRROR,
				 G_TX_NOMASK, G_TX_NOMASK,
				 G_TX_NOLOD, G_TX_NOLOD);
	    gSPTextureRectangle( NEXT_OVERLAY_DISP,
				 YREG(32) << 2, YREG(33) << 2,
				 (YREG(32)+32) << 2, (YREG(33)+32) << 2,
				 G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10 );
	    parameter->rpc[2] = 0;
	    parameter->rpc[3] = j;
	    while ( parameter->rpc[3] >= 10 ) {
		parameter->rpc[2]++;
		parameter->rpc[3] -=10;
	    }
	    YREG(34) = YREG(32) + 20;
	    if ( parameter->rpc[2] ) {
		SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + ((8*16)*parameter->rpc[2]),
							   8, 16,
							   YREG(34), YREG(33)+18,
							   8, 16,
							   1 << 10, 1 << 10 )
		    );
		YREG(34) += 8;
	    }
	    SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + ((8*16)*parameter->rpc[3]),
						       8, 16,
						       YREG(34), YREG(33)+18,
						       8, 16,
						       1 << 10, 1 << 10 )
		);
	}
    }
# endif    
    /*
     * カウント・ダウンタイマー表示
     */
    if ( TOTAL_EVENT_FG == TEvent_MD5 ) {
	if ( message_check( &game_play->message ) == 5 ) {
	    /* 終了 */
	    total_frame_tm = 40;
	    ZCommonSet( day_time, 0x0000 );
	    game_play->fade_direction = GAME_PLAY_FADE_OUT;
	    WIPE_SET(3);
	    TOTAL_EVENT_FG = TEvent_MD0;
	    /* プレイヤーＢボタン【剣】チェック */
	    if ( !(Register_Item(0) == H_sword_0 ||	/* ナイフ */
		   Register_Item(0) == H_sword_1 ||	/* マスターソード */
		   Register_Item(0) == H_sword_2 ||	/* 巨人のナイフ */
		   Register_Item(0) == H_sword_3) ) { 	/* 折れた巨人のナイフ */
		if ( Z_BTN_ITEM(0) ) Register_Item(0) = Z_BTN_ITEM(0);
		else                 Register_Item(0) = 0xff;
	    }
	    /* タイムアップチェック */
	    for ( i = 0; i < 3; i++ ) {
		if ( Get_Item_Register(H_reserve_20) == Warashibe_item[i] ) {
		    EVENT_INF( 0 ) = G_EVENT_INF( 0, 0x7F80 );
		    PRINTF("EVENT_INF=%x\n",EVENT_INF( 0 ));
		    game_play->next_scene = Next_scene[i];
		    Item_Register_Set( Warashibe_before_item[i] );
		    for ( j = 1; j < 4; j++ ) {
			if ( Register_Item(j) == Warashibe_item[i] ) {
			    Register_Item(j) = Warashibe_before_item[i];
			    item_textuer_dma( game_play, j );
			}
		    }
		}
	    }
	}
    }
//    PRINTF("msg_mode=%d, bitcheck=%d, fade_direction=%d, fbdemo_wipe_mode=%d, player_demo_check=%d\n",message->msg_mode, bitcheck( player->action, P_ACTION2_OKARINA_REQUEST_OK ),game_play->fade_direction,game_play->fbdemo_wipe_mode,player_demo_check( game_play ) );
    if ( !(KALEIDO_SCOPE_Pause_on_off( game_play )) &&
	 !game_play->gover.gover_mode &&
	 !message->msg_mode &&
	 !bitcheck( player->action2, P_ACTION2_OKARINA_REQUEST_OK ) &&
	 !game_play->fade_direction &&
	 !game_play->fbdemo_wipe_mode &&
	 !Game_play_demo_mode_check( game_play ) &&
	 Yabusame_Mode != Yabu_START &&
	 !(game_play->bow_game_flag >= 2 ||
/*	   game_play->bomchu_game_flag > 0 ||
	   (short)game_play->bomchu_game_flag == -1 && game_play->actor_info.actor_list[ ACTOR_PART_BOM ].num)   ) {*/
	   (game_play->scene_data_ID == BOWLING && Actor_Environment_sw_Check( game_play, 56 )) ) ) {
	event_pt = 0;
	switch( EVENT_FG ) {
	case Event_MD1:
	    frame_tm = 20;
	    display_tm = 20;
	    EVENT_TM = S_Private.now_life>>1; /*parameter->dokidoki_max;*/
	    EVENT_FG = Event_MD2;
	    break;
	case Event_MD2:
	    if ( !(--frame_tm) ) {
		frame_tm = 20;
		EVENT_FG = Event_MD3;
	    }
	    break;
	case Event_MD5:
	case Event_MD30:
	    frame_tm = 20;
	    display_tm = 20;
	    if ( EVENT_FG == Event_MD5 ) EVENT_FG = Event_MD6;
	    else                         EVENT_FG = Event_MD31;
	    break;
	case Event_MD6:
	case Event_MD31:
	    if ( !(--frame_tm) ) {
		frame_tm = 20;
		if ( EVENT_FG == Event_MD6 ) EVENT_FG = Event_MD7;
		else                         EVENT_FG = Event_MD32;
	    }
	    break;
	case Event_MD3:
	case Event_MD7:
	    /* 表示位置移動 */
	    i = (ZCommonGet(event_xp[0]) - 26)/frame_tm;
	    ZCommonSet( event_xp[0], ZCommonGet(event_xp[0]) - i );
	    if ( S_Private.max_life > LIFE_CT*10 ) {
		i = (ZCommonGet(event_yp[0]) - 54)/frame_tm;
	    } else {
		i = (ZCommonGet(event_yp[0]) - 46)/frame_tm;
	    }
	    ZCommonSet( event_yp[0], ZCommonGet(event_yp[0]) - i );
	    if ( !(--frame_tm) ) {
		frame_tm = 20;
		ZCommonSet( event_xp[0], 26 );	/* タイマー表示Ｘ位置 */
		if ( S_Private.max_life > LIFE_CT*10 )  ZCommonSet( event_yp[0],  54);
		else                                    ZCommonSet( event_yp[0],  46);
		if ( EVENT_FG == Event_MD3 ) EVENT_FG = Event_MD4;
		else                         EVENT_FG = Event_MD20;
	    }
	case Event_MD4:
	case Event_MD20:
	    if ( EVENT_FG == Event_MD4 || EVENT_FG == Event_MD20 ) {
		if ( S_Private.max_life > LIFE_CT*10 ) {
		    ZCommonSet( event_yp[0], 54 );
		} else {
		    ZCommonSet( event_yp[0], 46 );
		}
	    }
	    if ( EVENT_FG >= Event_MD3 ) {
		if ( !message->msg_data ) {
		    if ( !(--display_tm) ) {
			if ( EVENT_TM ) EVENT_TM--;
			display_tm = 20;
			if ( !EVENT_TM ) {
			    /* 終了 */
			    EVENT_FG = Event_End;
			    if ( player_diving ) {
				S_Private.now_life = 0;
				to_damage_set( game_play, -( S_Private.now_life + 2 ) );
			    }
			    player_diving = 0;
			} else if ( EVENT_TM > 60 ){
			    if ( etm[4] == 1 ) Na_StartSystemSe( NA_SE_SY_MESSAGE_WOMAN );
			} else if ( EVENT_TM > 10 ){
			    /* １０秒前 */
			    if ( (etm[4] & 1) ) {
				Na_StartSystemSe( NA_SE_SY_WARNING_COUNT_N );
			    }
			} else {
			    /* １０秒以内 */
			    Na_StartSystemSe( NA_SE_SY_WARNING_COUNT_E );
			}
		    }
		}
	    }
	    break;
	    
	case Event_MD32:
	    i = (ZCommonGet(event_xp[0]) - 26)/frame_tm;
	    ZCommonSet( event_xp[0], ZCommonGet(event_xp[0]) - i );
	    if ( S_Private.max_life > LIFE_CT*10 ) {
		i = (ZCommonGet(event_yp[0]) - 54)/frame_tm;
	    } else {
		i = (ZCommonGet(event_yp[0]) - 46)/frame_tm;
	    }
	    ZCommonSet( event_yp[0], ZCommonGet(event_yp[0]) - i );
	    if ( !(--frame_tm) ) {
		frame_tm = 20;
		ZCommonSet( event_xp[0], 26 );	/* タイマー表示Ｘ位置 */
		if ( S_Private.max_life > LIFE_CT*10 )  ZCommonSet( event_yp[0],  54);
		else                                    ZCommonSet( event_yp[0],  46);
		EVENT_FG = Event_MD33;
	    }
	case Event_MD33:
	    if ( EVENT_FG == Event_MD33 ) {
		if ( S_Private.max_life > LIFE_CT*10 ) {
		    ZCommonSet( event_yp[0], 54 );
		} else {
		    ZCommonSet( event_yp[0], 46 );
		}
	    }
	    if ( EVENT_FG >= Event_MD3 ) {
		if ( !(--display_tm) ) {
		    EVENT_TM++;
		    display_tm = 20;
		    if ( EVENT_TM == 3599 ) {
			/* 終了 */
			frame_tm = 40;
			EVENT_FG = Event_MD34;
		    } else {
			Na_StartSystemSe( NA_SE_SY_WARNING_COUNT_N );
		    }
		}
	    }
	    break;


	case Event_End:
	    if ( TOTAL_EVENT_FG ) {
		total_frame_tm = 20;
		total_display_tm = 20;
		ZCommonSet( event_xp[1], 140 );	/* タイマー表示Ｘ位置 */
		ZCommonSet( event_yp[1],  80 );	/* タイマー表示Ｙ位置 */
		if ( TOTAL_EVENT_FG <= TEvent_Wait )
		    TOTAL_EVENT_FG = TEvent_MD2;
		else
		    TOTAL_EVENT_FG = TEvent_MD12;
		EVENT_FG = Event_MD0;
	    } else {
		EVENT_FG = Event_MD0;
	    }
	case Event_MD34:
	    break;

	default:
	    /*
	     * ＴＯＡＬカウントタイマー表示
	     */
	    event_pt = 1;
	    switch( TOTAL_EVENT_FG ) {
	    case TEvent_MD1:
	    case TEvent_MD11:
		total_frame_tm = 20;
		total_display_tm = 20;
		ZCommonSet( event_xp[1], 140 );	/* タイマー表示Ｘ位置 */
		ZCommonSet( event_yp[1],  80 );	/* タイマー表示Ｙ位置 */
		if ( TOTAL_EVENT_FG == TEvent_MD1 ) TOTAL_EVENT_FG = TEvent_MD2;
		else                                TOTAL_EVENT_FG = TEvent_MD12;
		break;
	    case TEvent_MD2:
	    case TEvent_MD12:
		if ( !(--total_frame_tm) ) {
		    total_frame_tm = 20;
		    if ( TOTAL_EVENT_FG == TEvent_MD2 ) TOTAL_EVENT_FG = TEvent_MD3;
		    else                                TOTAL_EVENT_FG = TEvent_MD13;
		}
		break;
	    case TEvent_MD3:
	    case TEvent_MD13:
		PRINTF("event_xp[1]=%d,  event_yp[1]=%d  TOTAL_EVENT_TM=%d\n",ZCommonGet(event_xp[1]), ZCommonGet(event_yp[1]), TOTAL_EVENT_TM );
		i = (ZCommonGet(event_xp[1]) - 26)/total_frame_tm;
		ZCommonSet( event_xp[1], ZCommonGet(event_xp[1]) - i );
		if ( S_Private.max_life > LIFE_CT*10 ) {
		    i = (ZCommonGet(event_yp[1]) - 54)/total_frame_tm;
		} else {
		    i = (ZCommonGet(event_yp[1]) - 46)/total_frame_tm;
		}
		ZCommonSet( event_yp[1], ZCommonGet(event_yp[1]) - i );
		if ( !(--total_frame_tm) ) {
		    total_frame_tm = 20;
		    ZCommonSet( event_xp[1], 26 );	/* タイマー表示Ｘ位置 */
		    if ( S_Private.max_life > LIFE_CT*10 )  ZCommonSet( event_yp[1],  54);
		    else                                    ZCommonSet( event_yp[1],  46);
		    if ( TOTAL_EVENT_FG == TEvent_MD3 ) TOTAL_EVENT_FG = TEvent_MD4;
		    else                                TOTAL_EVENT_FG = TEvent_MD14;
		}
	    case TEvent_MD4:	/* イベントタイマー */
	    case TEvent_MD14:	/* イベントタイマー */
		if ( TOTAL_EVENT_FG == TEvent_MD4 || TOTAL_EVENT_FG == TEvent_MD14 ) {
		    if ( S_Private.max_life > LIFE_CT*10 ) {
			ZCommonSet( event_yp[1], 54 );
		    } else {
			ZCommonSet( event_yp[1], 46 );
		    }
		}
		if ( TOTAL_EVENT_FG >= TEvent_MD3 ) {
		    if ( !(--total_display_tm) ) {
			total_display_tm = 20;
			if ( TOTAL_EVENT_FG == TEvent_MD4 ) {
			    TOTAL_EVENT_TM--;
			    PRINTF("TOTAL_EVENT_TM=%d\n",TOTAL_EVENT_TM);
			    if ( TOTAL_EVENT_TM <= 0 ) {
				/* 終了 */
#if 0	/* 1998 10/6 komatu */			
///				if ( !Get_Event_Chk_Inf(9, 0x0800) ) {
#else
				if (!GET_ESCAPE_EVENT_STATE_IN_ZL3(game_play)) {
#endif					
				    total_frame_tm = 40;
				    TOTAL_EVENT_FG = TEvent_MD5;
				    ZCommonSet( day_time, 0x0000 );
				    message_set( game_play, 0x71B0, 0 );
				    player_demo_mode_set(game_play, NULL, P_DEMO_PLAY_WAIT); /* プレイヤー停止 */
				} else {
				    total_frame_tm = 40;
				    TOTAL_EVENT_FG = TEvent_Wait;
				}
			    } else if ( TOTAL_EVENT_TM > 60 ){
				if ( etm[4] == 1 ) Na_StartSystemSe( NA_SE_SY_MESSAGE_WOMAN );
			    } else if ( TOTAL_EVENT_TM > 10 ){
				/* １０秒前 */
				if ( (etm[4] & 1) ) {
				    Na_StartSystemSe( NA_SE_SY_WARNING_COUNT_N );
				}
			    } else {
				    /* １０秒以内 */
				Na_StartSystemSe( NA_SE_SY_WARNING_COUNT_E );
			    }
			} else {
			    TOTAL_EVENT_TM++;
			    if ( G_EVENT_INF( 1, 0x0001 ) ) {
				if ( TOTAL_EVENT_TM == 4*60 ) {
				    message_set( game_play, 0x6083, 0 );
				    EVENT_INF( 1 ) = G_EVENT_INF( 1, 0xfffe );
				    TOTAL_EVENT_FG = TEvent_MD0;
				}
			    }
			}
			if ( !(TOTAL_EVENT_TM % 60) ) {
			    Na_StartSystemSe( NA_SE_SY_WARNING_COUNT_N );
			}
		    }
		}
		break;
# if 0
	    case TEvent_MD5:	/* イベントタイマー */
		if ( message_check( &game_play->message ) == 5 ) {
		    /* 終了 */
		    total_frame_tm = 40;
		    TOTAL_EVENT_FG = TEvent_Wait;
		    ZCommonSet( day_time, 0x0000 );
		    game_play->fade_direction = GAME_PLAY_FADE_OUT;
		    WIPE_SET(3);
		    TOTAL_EVENT_FG = TEvent_MD0;
		    /* タイムアップチェック */
		    for ( i = 0; i < 3; i++ ) {
			if ( Get_Item_Register(H_reserve_20) == Warashibe_item[i] ) {
			    game_play->next_scene = Next_scene[i];
			    Item_Register_Set( Warashibe_before_item[i] );
			    for ( j = 1; j < 4; j++ ) {
				if ( Register_Item(j) == Warashibe_item[i] ) {
				    Register_Item(j) = Warashibe_before_item[i];
				    item_textuer_dma( game_play, j );
				}
			    }
			}
		    }
		}
		break;
# endif		
	    case TEvent_Wait:
		if ( !(--total_frame_tm) ) {
		    TOTAL_EVENT_FG = TEvent_MD0;
		}
		break;
	    }
	    break;
	}

	if ( (EVENT_FG && EVENT_FG != Event_End) || TOTAL_EVENT_FG ) {
	    etm[0] = etm[1] = etm[3] = 0;
	    etm[2] = 10;
	    if ( EVENT_FG ) {
		etm[4] = EVENT_TM;
	    } else {
		etm[4] = TOTAL_EVENT_TM;
	    }
	    while ( etm[4] >= 60 ) {
		etm[1]++;
		if ( etm[1] >= 10 ) {
		    etm[0]++;
		    etm[1] -= 10;
		}
		etm[4] -= 60;
	    }
	    while ( etm[4] >= 10 ) {
		etm[3]++;
		etm[4] -=10;
	    }
	    /* ＥＶＥＮＴ中 */
	    gDPPipeSync( NEXT_OVERLAY_DISP );
/*	    if ( parameter->map_alpha >= MAP_ALPHA_VALUE ) {
		gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, 255 );
	    } else {
		gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255,   0 );
	    }*/
	    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, 255 );
	    gDPSetEnvColor( NEXT_OVERLAY_DISP, 0, 0, 0, 0 );
	    SET_NOW_OVERLAY_DISP( texture_rectangleIA8( NOW_OVERLAY_DISP, h_timer_txt,
							16, 16,
							ZCommonGet(event_xp[event_pt]),
							ZCommonGet(event_yp[event_pt])+2,
							16, 16,
							1 << 10, 1 << 10 )
		);
	    gDPPipeSync( NEXT_OVERLAY_DISP );
	    gDPSetCombineMode( NEXT_OVERLAY_DISP, G_CC_INT4, G_CC_INT4 );
/*	    if ( parameter->map_alpha >= MAP_ALPHA_VALUE ) event_alpha = 255;
	    else                                           event_alpha = 0;*/
	    if ( EVENT_FG ) {
		if ( (EVENT_TM < 10 && EVENT_FG < Event_MD30) ){
		    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255,  50,   0, 255 );
		} else {
		    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255, 255, 255 );
		}
	    } else {
		if ( (TOTAL_EVENT_TM < 10 && TOTAL_EVENT_FG < TEvent_Wait) ){
		    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255,  50,   0, 255 );
		} else {
		    gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 255, 255,   0, 255 );
		}
	    }
	    for ( i = 0; i < 5; i++ ) {
		SET_NOW_OVERLAY_DISP( texture_rectangleI8( NOW_OVERLAY_DISP, rupy_num0_txt + (8*16)*etm[i],
							   8, 16,
							   ZCommonGet(event_xp[event_pt])+tm_xp[i],
							   ZCommonGet(event_yp[event_pt]),
							   tm_xsz[i], VREG(42),
							   VREG(43) << 1, VREG(43) << 1 )
		    );
	    }
	}
	}
    }
#if !defined(ROM_F)
    if ( kscope->debug == 3 ) flg_set( game_play );
#endif
    if ( parameter->fill_alpha ) {
	gDPPipeSync( NEXT_OVERLAY_DISP );
	gSPDisplayList( NEXT_OVERLAY_DISP, fbdemo_fade_gfx_init );
	gDPSetPrimColor( NEXT_OVERLAY_DISP, 0, 0, 0, 0, 0, parameter->fill_alpha );
	gDPFillRectangle( NEXT_OVERLAY_DISP, 0, 0, ScreenWidth-1, ScreenHeight-1 );
    }
    
    CLOSE_DISP( game_play->g.graph );
    
}




/************************************************************************
 *									*
 *	パラメーターＭＯＶＥ						*
 *									*
 ************************************************************************/
extern void
parameter_move( Game_play *game_play )
{
    Parameter		*parameter = (Parameter *)&game_play->parameter;

    Message		*message = (Message *)&game_play->message;

    Player_actor	*player = (Player_actor *)get_player_actor(game_play);

    
    short	alpha, alpha1;
    unshort	action;
    static unchar	zelda_time = 0;
    static short	keep_zelda_time = 0;

    if ( !(KALEIDO_SCOPE_Pause_on_off( game_play )) &&
	 (Yabusame_Mode == Yabu_START ||
	  ZCommonGet( game_info.counter ) < 4 ||
	  (game_play->scene_data_ID == SPOT20 && ZCommonGet( game_info.counter ) == 4) ) &&
	 (!message->msg_mode ||
	  (message->msg_mode && game_play->scene_data_ID == BOWLING)) &&
	 !game_play->gover.gover_mode ) {
# if 0
	 !game_play->gover.gover_mode &&
	 !game_play->fade_direction &&
	 !game_play->fbdemo_wipe_mode &&
	 !Game_play_demo_mode_check( game_play ) ) {
# endif
	parameter_check( game_play );
    }
	
	
    /*
     * ＡＬＰＨＡ値操作
     */
    switch ( Z_ALPHA_TYPE ) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
	alpha = FULL_ALPHA - (ALPHA * Z_ALPHA_COUNT);
	if ( alpha < 0 ) alpha = 0;
	alpha_setting0( game_play, alpha );
	Z_ALPHA_COUNT++;
	if ( !alpha ) Z_ALPHA_TYPE = 0;
	break;

    case 50:
	alpha = FULL_ALPHA - (ALPHA * Z_ALPHA_COUNT);
	if ( alpha < 0 ) alpha = 0;
	alpha1 = FULL_ALPHA - alpha;
	if ( alpha1 >= FULL_ALPHA ) alpha1 = FULL_ALPHA;
	PRINTF("case 50 : alpha=%d  alpha1=%d\n",alpha,alpha1);
	c_alpha_set_1( game_play, alpha1 );
	if ( parameter->heart_alpha != FULL_ALPHA ) parameter->heart_alpha = alpha1;
	if ( parameter->meter_alpha != FULL_ALPHA ) parameter->meter_alpha = alpha1;
	switch ( game_play->scene_data_ID ) {
	case SPOT00:
	case SPOT01:
	case SPOT02:
	case SPOT03:
	case SPOT04:
	case SPOT05:
	case SPOT06:
	case SPOT07:
	case SPOT08:
	case SPOT09:
	case SPOT10:
	case SPOT11:
	case SPOT12:
	case SPOT13:
	case SPOT15:
	case SPOT16:
	case SPOT17:
	case SPOT18:
	case SPOT20:
	case GANONTOU:
	    if ( parameter->map_alpha < MAP_ALPHA_VALUE ) parameter->map_alpha = alpha1;
	    else                                          parameter->map_alpha = MAP_ALPHA_VALUE;
	    break;
	    
	default:
	    if ( parameter->map_alpha != FULL_ALPHA ) parameter->map_alpha = alpha1;
	    break;
	}
	Z_ALPHA_COUNT++;
	if ( alpha1 == FULL_ALPHA ) Z_ALPHA_TYPE = 0;
	break;

    case 52:
	Z_ALPHA_TYPE = 1;
	alpha_setting0( game_play, 0 );
	Z_ALPHA_TYPE = 0;
    default:
	break;
    }
    
    /*
     * ＭＡＰ
     */
    map_exp_move( game_play );

    /*
     * Ｌｉｆｅ Ｍｅｔｅｒ
     */
    if ( LIFE_MODE ) {
	ZCommonSet( life_mode, (LIFE_MODE - 4 ) );
	S_Private.now_life+=4;
	if ( (S_Private.now_life & 0xf) < 4 ) Na_StartSystemSe(NA_SE_SY_HP_RECOVER);
	PRINTF("now_life=%d  max_life=%d\n",S_Private.now_life,S_Private.max_life);
	if ( S_Private.now_life >= S_Private.max_life ) {
	    S_Private.now_life = S_Private.max_life;
	    PRINTF("S_Private.now_life=%d  S_Private.max_life=%d\n",S_Private.now_life,S_Private.max_life);
	    ZCommonSet( life_mode, 0 );
	}
    }
    LifeMeterZoom( game_play );

    /* プレイヤー水中判定 : [！＝ ０] の時水中 */
    player_condition = player_condition_check( game_play );
    if ( player_condition == 1 ) {
	/* 炎（ゴロンの服）チェック */
	if ( EQUIPMENT_ITEM( E_Clothes ) == 2 ) player_condition = 0;
    } else if ( player_condition_check( game_play ) >= 2 && player_condition_check( game_play ) <= 4 ) {	/* プレイヤー水中 */
	/* 水（ゾ─ラの服）チェック */
	if ( EQUIPMENT_ITEM( E_Clothes ) == 3 ) player_condition = 0;
    }
    LifeMeterColorAnimation( game_play );
////////    if ( player_condition == 1 || player_condition == 2 ) {
	if ( EVENT_FG >= Event_MD3 ) {
	    if ( !(KALEIDO_SCOPE_Pause_on_off( game_play )) &&
		 !message->msg_mode &&
		 !bitcheck( player->action2, P_ACTION2_OKARINA_REQUEST_OK ) &&
		 !game_play->fade_direction &&
		 !game_play->fbdemo_wipe_mode &&
		 !Game_play_demo_mode_check( game_play ) ) {
////////		LifeRestChange( game_play );
	    }
	}
////////    } else {
////////	initial_LifeRestChange( game_play );
////////    }


    /*
     * ルピー数
     */
    if ( z_common_data.lupy_udct ) {
	/* ルピー数増減 */
	if ( z_common_data.lupy_udct > 0 ) {
	    /* ルピー数（＋） */
	    if ( S_Private.lupy_count < Item_MaxGet( NE_Purse ) ) {
		z_common_data.lupy_udct--;
		S_Private.lupy_count++;
		Na_StartSystemSe( NA_SE_SY_RUPY_COUNT );
	    } else {
		PRINTF("ルピー数ＭＡＸ = %d\n",Item_MaxGet( NE_Purse ));
		S_Private.lupy_count = Item_MaxGet( NE_Purse );
		z_common_data.lupy_udct = 0;
	    }
	} else {
	    /* ルピー数（─） */
	    if ( S_Private.lupy_count ) {
		if ( z_common_data.lupy_udct < -49 ) {
		    z_common_data.lupy_udct += 10;
		    S_Private.lupy_count -= 10;
		    if ( S_Private.lupy_count < 0 ) S_Private.lupy_count = 0;
		    Na_StartSystemSe( NA_SE_SY_RUPY_COUNT );
		} else {
		    z_common_data.lupy_udct++;
		    S_Private.lupy_count--;
		    Na_StartSystemSe( NA_SE_SY_RUPY_COUNT );
		}
	    } else {
		z_common_data.lupy_udct = 0;
	    }
	}
    }




    /* ＤＯアクション チェック */
    switch ( parameter->do_action_flg ) {
    case 0x1:
	if ( (parameter->do_action_rotate += (31400.0f/(float)WREG(5))) >= 15700.0f ) {
	    parameter->do_action_rotate = -15700.0f;
	    parameter->do_action_flg = 2;
	}
	break;

    case 0x2:
	if ( (parameter->do_action_rotate += (31400.0f/(float)WREG(5))) >= 0.0f ) {
	    parameter->do_action_rotate = 0.0f;
	    parameter->do_action_flg = 0;
	    parameter->do_action = parameter->do_action_old;
		
	    /* ＤＯアクション ＮＥＸＴテクスチャＤＭＡ */
	    action = parameter->do_action;
	    if ( action == DO_F_Navi || action == DO_P_Navi ) action = DO_Navi;
	    next_do_action_textuer_dma( parameter, action, 0 );
	}
	break;

    case 0x3:
	if ( (parameter->do_action_rotate += (31400.0f/(float)WREG(5))) >= 15700.0f ) {
	    parameter->do_action_rotate = -15700.0f;
	    parameter->do_action_flg = 2;
	}
	break;

    case 0x4:
	if ( (parameter->do_action_rotate += (31400.0f/(float)WREG(5))) >= 0.0f ) {
	    parameter->do_action_rotate = 0.0f;
	    parameter->do_action_flg = 0;
	    parameter->do_action = parameter->do_action_old;
		
	    /* ＤＯアクション ＮＥＸＴテクスチャＤＭＡ */
	    action = parameter->do_action;
	    if ( action == DO_F_Navi || action == DO_P_Navi ) action = DO_Navi;
	    next_do_action_textuer_dma( parameter, action, 0 );
	}
	break;
	
    default:
	break;
    }
    WREG(7) = parameter->do_action_rotate;


    /* 魔法メーター処理 */
    if ( !(KALEIDO_SCOPE_Pause_on_off( game_play )) &&
	 !message->msg_mode &&
	 !game_play->fade_direction &&
	 !game_play->gover.gover_mode &&
	 !game_play->fbdemo_wipe_mode &&
	 !(game_play->demo_play.mode && player_demo_check( game_play )) ) {
/*	 ZCommonGet( day_time ) < 0xfff0 ) {*/
	if ( MAGIC_MODE ) {
	    if ( !MAGIC_MAX ) {
		MAGIC_MAX = MAGIC_ABILITY + 1;
		Set_MAGIC_FLAG( Magic_Start );
		COLOR_YELLOW();
		PRINTF("魔法スター─────ト！！！！！！！！！\n");
		PRINTF("MAGIC_MAX=%d\n",MAGIC_MAX);
		PRINTF("MAGIC_NOW=%d\n",MAGIC_NOW);
		PRINTF("Z_MAGIC_NOW_NOW=%d\n",Z_MAGIC_NOW_NOW);
		PRINTF("Z_MAGIC_NOW_MAX=%d\n",Z_MAGIC_NOW_MAX);
		COLOR_NORMAL();
	    }
	}
	magic_meter_move( game_play );
    }



    if ( !EVENT_FG ) {
	if ( player_condition == 1 || player_condition == 2 || player_condition == 4 ) {
	    /* タイマー開始 */
	    if ( (S_Private.now_life >> 1) ) {
		EVENT_FG = Event_MD1;
		ZCommonSet( event_xp[0], 140 );	/* タイマー表示Ｘ位置 */
		ZCommonSet( event_yp[0],  80 );	/* タイマー表示Ｙ位置 */
		player_diving = 1;
	    }
	}
    } else if ( !player_condition || player_condition == 3 ) {
	if ( EVENT_FG <= Event_MD4 ) { 
	    /* タイマー停止 */
	    EVENT_FG = Event_MD0;
	}
    }
    if ( Yabusame_Mode == Yabu_START ) {
	/*
	 * 流鏑馬
	 */
	Yabusame_Total += parameter->yabusame_score;
	parameter->yabusame_score = 0;
	if ( !yabu_sound) {
	    if ( Yabusame_Total >= 1000 ) {
//////////		Na_StartBgm( NA_BGM_HORSE_GOAL );
		yabu_sound++;
	    }
	} else if ( yabu_sound == 1 ) {
	    if ( Yabusame_Total >= 1500 ) {
//////////		Na_StartBgm( NA_BGM_HORSE_GOAL );
		yabu_sound++;
	    }
	}
	yabu_total[0] =
	    yabu_total[1] = 0;
	    yabu_total[2] = 0;
	yabu_total[3] = Yabusame_Total;
	while ( yabu_total[3] >= 1000 ) {
	    yabu_total[0]++;
	    yabu_total[3] -= 1000;
	}
	while ( yabu_total[3] >= 100 ) {
	    yabu_total[1]++;
	    yabu_total[3] -= 100;
	}
	while ( yabu_total[3] >= 10 ) {
	    yabu_total[2]++;
	    yabu_total[3] -= 10;
	}
    }

    /* 『太陽の歌』→ 昼夜入替 */
    if ( ZCommonGet( sunmoon_flag ) ) {
	if ( message->ocarina_no != Ocarina_FrogFrog && ZCommonGet( sunmoon_flag ) == 1 ) {
	    OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
	}
	if ( game_play->kankyo.day_time_plus ) {
	    if ( ZCommonGet( sunmoon_flag ) != 2 ) {
		zelda_time = 0;
		if ( ZCommonGet(zelda_time) >= MORNING_TIME && ZCommonGet(zelda_time) <= NIGHT_TIME )
		    zelda_time  = 1;
		ZCommonSet( sunmoon_flag, 2 );
		keep_zelda_time = TIME_SPEED;
		TIME_SPEED = 400;
	    } else {
		if ( !zelda_time ) {
		    if ( ZCommonGet(zelda_time) >= MORNING_TIME && ZCommonGet(zelda_time) <= NIGHT_TIME ) {
			ZCommonSet( sunmoon_flag, 0 );
			TIME_SPEED = keep_zelda_time;
			OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		    }
		} else {
		    if ( ZCommonGet(zelda_time) > NIGHT_TIME ) {
			ZCommonSet( sunmoon_flag, 0 );
			TIME_SPEED = keep_zelda_time;
			OCARINA_MODE( game_play ) = Oca_Stop;	/* オカリナ終了 */
		    }
		}
	    } 
	} else if ( game_play->room_info.now.type != ROOM_TYPE_DANGEON && parameter->c_sunmoon != 3 ) {
	    if ( ZCommonGet(zelda_time) >= MORNING_TIME && ZCommonGet(zelda_time) < NIGHT_TIME ) {
		ZCommonSet( next_zelda_time, TIME_00/*NIGHT_TIME*/ );	/* ジャスト   ０時（深夜） */
		WIPE_SET(4);					/* white		*/
		ZCommonSet( next_wipe, 2 );
		game_play->actor_stop_flag = 1;
	    } else {
		ZCommonSet( next_zelda_time, TIME_12/*MORNING_TIME*/ );	/* ジャスト １２時（お昼） */
		WIPE_SET(5);					/* white		*/
		ZCommonSet( next_wipe, 3 );
		game_play->actor_stop_flag = 1;
# if 0
		/* めざましタマゴは、目覚ましどりに		*/
		if( item_change_setting( game_play, H_reserve_00, H_reserve_01 ) ||
		    /* ポケットタマゴは、てのりコッコに		*/
		    item_change_setting( game_play, H_reserve_20, H_reserve_21 )   )
		{
		    Na_StartSystemSe(NA_SE_EV_CHICKEN_CRY_M);
		}
# endif
	    }
	    if ( game_play->scene_data_ID == SPOT13 ) {
		WIPE_SET(14);					/* ＳＰＯＴ１３専用 */
		ZCommonSet( next_wipe, 14 );
	    }

/*	    Game_play_restart_set(game_play,
				  RESTART_MODE_RETURN,
				  PLAYER_START_MODE_DEMO_WAIT);*/
// iw	    ZCommonSet(game_info.restart_data[RESTART_MODE_RETURN], ZCommonGet(game_info.restart_data[RESTART_MODE_DOWN]));
// iw	    ZCommonSet(game_info.restart_flag, (RESTART_MODE_RETURN + 1));
	    ZCommonSet(game_info.restart_flag, -2);
	    game_play->next_scene = ZCommonGet( scene_no );
	    game_play->fade_direction = GAME_PLAY_FADE_OUT;	/* フェードアウトセット */
	    ZCommonSet( sunmoon_flag, 0 );

	    Na_StopAllSound(30);
	    ZCommonSet(old_bgm, 255);
	    ZCommonSet(old_env, 255);
	} else {
	    ZCommonSet( sunmoon_flag, 3 );
	}
    }
}
