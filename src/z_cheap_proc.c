/*
 * $Id: z_cheap_proc.c,v 2.1 1998-10-22 20:45:49+09 zelda Exp $
 *
 * $Log: z_cheap_proc.c,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.30  1998/10/03 15:06:26  tarukado
 * *** empty log message ***
 *
 * Revision 1.29  1998-09-25 22:37:27+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.28  1998-09-19 18:09:56+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.27  1998-09-07 20:42:44+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.26  1998-08-27 15:57:41+09  umemiya
 * 安上がり 表示処理（半透明） 追加
 *
 * Revision 1.25  1998-08-27 11:43:13+09  umemiya
 * レンダモードの変更にアルファコンペア追加
 *
 * Revision 1.24  1998-08-26 20:22:46+09  umemiya
 * *** empty log message ***
 *
 * Revision 1.23  1998-08-13 16:26:15+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.22  1998-08-10 23:37:28+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.21  1998-08-05 23:49:30+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.20  1998-08-03 23:24:04+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.19  1998-06-25 22:14:53+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.18  1998-06-24 22:50:24+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.17  1998-06-16 13:31:39+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.16  1998-06-15 23:01:27+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.15  1998-06-09 22:43:05+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.14  1998-06-08 21:24:16+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.13  1998-06-05 22:22:49+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.12  1998-06-04 23:05:42+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.11  1998-05-07 17:22:44+09  umemiya
 * 特殊処理用ディスプレイリスト追加
 *
 * Revision 1.10  1998-05-07 15:39:27+09  tarukado
 * *** empty log message ***
 *
 * Revision 1.9  1998/05/02 13:55:46  tarukado
 * *** empty log message ***
 *
 * Revision 1.8  1998/03/09 05:07:59  iwawaki
 * *** empty log message ***
 *
 * Revision 1.7  1998/03/05  14:11:26  tarukado
 * *** empty log message ***
 *
 * Revision 1.6  1998/02/16  09:57:39  tarukado
 * *** empty log message ***
 *
 * Revision 1.5  1998/02/06  05:03:25  tarukado
 * *** empty log message ***
 *
 * Revision 1.4  1998/02/06  02:36:20  tarukado
 * *** empty log message ***
 *
 * Revision 1.3  1998/02/05  02:12:50  tarukado
 * *** empty log message ***
 *
 * Revision 1.2  1998/01/29  04:51:42  tarukado
 * *** empty log message ***
 *
 * Revision 1.1  1998/01/14  05:47:08  tarukado
 * Initial revision
 *
 *
 *
 * */

/*-----------------------------------------------------------------------------
 *
 * z_cheap_proc.c
 * 
 * Program: Tarukado
 * 1998/01/13
 *
 *---------------------------------------------------------------------------*/
#include"z_basic.h"
#include"z_play.h"
#include"z_player.h"
#include"z_player_macro.h"
#include"z_cheap_proc.h"
#include"z_en_part.h"
#include"z_collision_check.h"
#include"z_collision_param.h"
#include"z_eff_ss_kirakira.h"
#include"z_skelanime.h"
#include"z_actor_files.h"

#define DEGREE_TO_SHORT(x) ((short)(65536.0f/360.0f*(float)x))

extern float add_calc(float *a, float b, float p, float max, float min);
extern float add_calc_a(float *a, float b, float p, float max, float min);
extern int chase_s3(short *my, short aim, short step);
extern short add_calc_short_angle(short *a, short b, short p, short max, short min);

#define DEBUG_Z_CHEAP_PROC

/*---------------------------------------------------------------------------
 *
 * 各動作処理
 *
 *--------------------------------------------------------------------------*/
/*
 * CHEAP_NON_MOVE
 */
extern void Cheap_non_move( Actor *this, Game *game)
{
    this;
    game;
}
/*-----------------------------------------------------------------------------
 *
 * CHEAP_MODE_WAIT
 *
 *---------------------------------------------------------------------------*/
/*
 * 安上がり 持ち上げ オブジェモード
 */
extern int Cheap_mode_wait( Actor *this, Game_play *game_play)
{
    int ans = 0;
    
    switch(this->arg_data){
    case 0:
	/*
	 * 持ち上げチェック
	 */
	if(Actor_carry_check(this, game_play)){
	    /* 持ち上げられた？ */
	    this->arg_data = 1;
	}else{
	    /*
	     * 着地チェック
	     */
	    if(!bitcheck(this->environment_info, ENVIRONMENT_INFO_GROUND)){
		/*
		 * 座標移動計算
		 */
		Actor_position_moveF(this);
	    
		/* 空気抵抗 */
		add_calc(&this->speedF, 0.0f, 1.0f, 0.1f, 0.0f);
	    }else{
		/* 着地の瞬間？ */
		if(bitcheck(this->environment_info,
			    ENVIRONMENT_INFO_LANDING) &&
		   this->position_speed.y < -4.0f ){
		    ++ans;
		}else{
		    this->shape.angle.sx = 
			this->shape.angle.sz = 0;
		    /* 持ち上げられ意思セット */
		    Actor_carry_request(this, game_play);
		}
	    }
	}
	break;
    case 1:
	/* 投げられた？ */
	if(Actor_carry_end_check(this, game_play)){
	    this->arg_data = 0;
	}
    }	
    Actor_BGcheck2(game_play,
		   this,
		   this->status_info.h,
		   this->status_info.r,
		   this->status_info.r,
		   (BGCHECK_WALL | BGCHECK_GROUND |/* チェック情報 */
		    BGCHECK_GROUND_DOWN_SP_SET |
		    BGCHECK_GROUND_LEAVE_SP_CLR));
    return(ans);
}
/************************************************************************
 *									*
 *	安上がり 表示処理			 			*
 *									*
 ************************************************************************/
extern void Cheap_gfx_display(Game *game, Gfx *gfx)
{
    OPEN_DISP(game->graph);
    _texture_z_light_fog_prim(game->graph);
    gSPMatrix(NEXT_DISP, Matrix_to_Mtx_new(game->graph),
	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(NEXT_DISP, gfx);
    CLOSE_DISP(game->graph);
}
/************************************************************************
 *									*
 *	安上がり 表示処理（半透明）		 			*
 *									*
 ************************************************************************/
extern void Cheap_gfx_display_xlu(Game *game, Gfx *gfx)
{
    OPEN_DISP(game->graph);
    _texture_z_light_fog_prim_xlu(game->graph);
    gSPMatrix(NEXT_POLY_XLU_DISP, Matrix_to_Mtx_new(game->graph),
	      G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(NEXT_POLY_XLU_DISP, gfx);
    CLOSE_DISP(game->graph);
}
/************************************************************************
 *									*
 *	プレイヤー コンボ ゲット		 			*
 *									*
 ************************************************************************/
extern int pl_comb_get(Game_play *game_play)
{
    Player_actor *player_actor = (Player_actor *)get_player_actor(game_play);

    return(player_actor->combo_counter);

}
/*-----------------------------------------------------------------------
 * 自分の近くに目的のアクターがいるか？
 *-----------------------------------------------------------------------*/
extern Actor *ActorSearch( Game_play *game_play, Actor *this,
			  short name, unsigned char part, float size )
{
    Actor *check_actor;
    
    check_actor =
	game_play->actor_info.actor_list[part].actor;
    
    while (check_actor != NULL) {

	if (check_actor == this || (name != -1 && check_actor->name != name)){
	    check_actor = check_actor->next;
	    continue;
	}
	
	if(Actor_search_actor_distance( this, check_actor) <= size)
	    return check_actor;
	else
	    check_actor = check_actor->next;
    }
    return NULL;
}
/*-----------------------------------------------------------------------
 * 自分の近くでプレイヤーこっちに 剣振ってるか？
 *-----------------------------------------------------------------------*/
extern int PlayerSwingCheck( Game_play *game_play, Actor *this, float dist,
			     short dead_angle, short angle, short base_angle)
{
    /* プレイヤー */
    Actor *pplayer_actor = get_player_actor(game_play);
    Player_actor	*player_actor = (Player_actor *)pplayer_actor;
    short	distance_angle_y = distance_angle(
				(short)(this->player_angle_y + 0x8000),
				pplayer_actor->shape.angle.sy); 
    short	distance_angle_y2 = distance_angle(this->player_angle_y,
						   base_angle); 
    
    if((this->player_distance <= dist) && (player_actor->sword_attack)&&
       (ABS(distance_angle_y)<=angle)&&(ABS(distance_angle_y2)<=dead_angle)){
	return TRUE;
    }
    return FALSE;
}

/*-----------------------------------------------------------------------
 * 砂セット
 *-----------------------------------------------------------------------*/
extern void suna_set0(Game *game, xyz_t *t_pos, xyz_t *vec, xyz_t *acc)
{
    rgba_t		kirakira_prim, kirakira_env;
    
    /*
     * キラキラエフェクトセット
     */
    kirakira_prim.r = 200;
    kirakira_prim.g = 160;
    kirakira_prim.b = 120;
    kirakira_env.r  = 130;
    kirakira_env.g  = 90;
    kirakira_env.b  = 50;
    Effect_SS_KiraKira_ct(game, t_pos, vec, acc,
			      &kirakira_prim, &kirakira_env);
}
extern void suna_set(Game *game, xyz_t *t_pos){
    static xyz_t	kirakira_vec = {0.0f, -1.5f, 0.0f};
    static xyz_t	kirakira_acc = {0.0f, -0.2f, 0.0f};

    suna_set0(game, t_pos,&kirakira_vec, &kirakira_acc);
}

/*-----------------------------------------------------------------------
 *
 *	特殊処理用ディスプレイリスト
 *
 *----------------------------------------------------------------------*/
extern Gfx Actor_change_render_mode[] = {
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZU_XLU_SURF2),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsSPEndDisplayList(),
};

/*-----------------------------------------------------------------------
 * ハンマーで上から叩かれた？
 *-----------------------------------------------------------------------*/
extern int HammerSwingCheck( Game_play *game_play, ClObj *thisx)
{
    /* プレイヤー */
    Actor *pplayer_actor = get_player_actor(game_play);
    Player_actor	*player_actor = (Player_actor *)pplayer_actor;

    if((thisx->ac_bit & CL_AC_BIT_GRP_PLAYER) && player_actor->sword_attack &&
       player_actor->kiru_type == HAMMER_HIT)
	return TRUE;

    return NULL;
}


/*-----------------------------------------------------------------------
 * ヒットポイントからダメージ引くよ(status_info 内の値)
 *-----------------------------------------------------------------------*/
extern int hp_down( Actor *thisx)
{
    if(thisx->status_info.hp <= thisx->status_info.damage){
	thisx->status_info.hp = 0;
    }else{
	thisx->status_info.hp -= thisx->status_info.damage;
    }
    return ((int)thisx->status_info.hp);
}
/*-----------------------------------------------------------------------
 * 特定の攻撃に対するアイテム強制セット用ルーチン
 *-----------------------------------------------------------------------*/
extern void Hit_bit_set( Actor *a, ClObjElem *thisx, int flg)
{
    ClObjElem *hit_elem;
    hit_elem = thisx->ac_hit_elem;
    if(hit_elem == NULL){
	a->item_bit = 0;

    }else if(flg &&
	     hit_elem->at_btl_info.at_type & (CLE_ATC_BIT_FIRE_MAGIC|
				CLE_ATC_BIT_ICE_MAGIC|CLE_ATC_BIT_DARK_MAGIC)){
	a->stop_timer = hit_elem->at_btl_info.atp;
	a->item_bit = 0;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_FIRE_ARROW){
	a->item_bit = BIT_FIRE_ARROW;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_ICE_ARROW){
	a->item_bit = BIT_ICE_ARROW;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_WIND_ARROW){
	a->item_bit = BIT_WIND_ARROW;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_SOUL_ARROW){
	a->item_bit = BIT_SOUL_ARROW;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_DARK_ARROW){
	a->item_bit = BIT_DARK_ARROW;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_LIGHT_ARROW){
	a->item_bit = BIT_LIGHT_ARROW;
    }else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_LIGHT_MAGIC){
	if(flg){
	    a->stop_timer = hit_elem->at_btl_info.atp;
	}
	a->item_bit = BIT_LIGHT_MAGIC;
    }else{
	a->item_bit = 0;
    }
}
extern void Hit_bit_set_sph( Actor *a, ClObjJntSph *thisx, int flg)
{
    int i;
    unsigned int item_bit;
    ClObjElem *elem;
    ClObjElem *hit_elem;

    a->item_bit = 0;
    for(i = thisx->num-1; i >= 0 ; --i){
	elem = &thisx->elem_tbl[i].cl_elem;
	hit_elem = elem->ac_hit_elem;

	if(hit_elem == NULL){
	    item_bit = 0;
	}else if(flg &&
		 hit_elem->at_btl_info.at_type & (CLE_ATC_BIT_FIRE_MAGIC|
				CLE_ATC_BIT_ICE_MAGIC|CLE_ATC_BIT_DARK_MAGIC)){
	    a->stop_timer = hit_elem->at_btl_info.atp;
	    item_bit = 0;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_FIRE_ARROW){
	    item_bit = BIT_FIRE_ARROW;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_ICE_ARROW){
	    item_bit = BIT_ICE_ARROW;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_WIND_ARROW){
	    item_bit = BIT_WIND_ARROW;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_SOUL_ARROW){
	    item_bit = BIT_SOUL_ARROW;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_DARK_ARROW){
	    item_bit = BIT_DARK_ARROW;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_LIGHT_ARROW){
	    item_bit = BIT_LIGHT_ARROW;
	}else if(hit_elem->at_btl_info.at_type & CLE_ATC_BIT_LIGHT_MAGIC){
	    if(flg){
		a->stop_timer = hit_elem->at_btl_info.atp;
	    }
	    item_bit = BIT_LIGHT_MAGIC;
	}else{
	    item_bit = 0;
	}
	a->item_bit |= item_bit;
    }

}
/*-----------------------------------------------------------------------
 *
 *	サーチ座標Ｘang ＆ Ｙang平面方向計算
 *
 *	flg == 0	my.y     - target.y
 *	flg == 1	target.y - my.y
 *
 *
 *----------------------------------------------------------------------*/
extern void search_position_angleXY(
    xyz_t *my_position,
    xyz_t *target_position,
    s_xyz *a_angle,
    int	  flg
)
{
    float	x = target_position->x - my_position->x;
    float	z = target_position->z - my_position->z;
    float	y;
    float	rg;
    if(flg){
	y = target_position->y - my_position->y;
    }else{
	y = my_position->y - target_position->y;
    }
    a_angle->sy = atans_table(z,x);
    rg = sqrtf(x*x + z*z);
    a_angle->sx = atans_table(rg,y);

}

/* 汎用 弾セット */
extern Actor *shot_set(Actor *thisx, xyz_t *pos, s_xyz *ang, xyz_t *spd_c,
		       int time, s_xyz *pipe_d, Game_play *pgame_play,
		       short idx, Gfx *shape)
{
    En_Part_Actor	*now_actor;
    Actor		*actor;
    
    actor =  Actor_info_make_child_actor(&pgame_play->actor_info,thisx,
					 (Game *)pgame_play,
					 En_Part,
				  	 pos->x, pos->y, pos->z,
					 ang->sx, ang->sy, thisx->bank_ID,idx);

    if(actor != NULL){

	now_actor = (En_Part_Actor *)actor;
	
	actor->scale = thisx->scale;
	actor->speedF = spd_c->x;
	
	now_actor->shape_part = (unsigned int)shape;
	now_actor->mode = EN_PART_SHOT_INIT;
	now_actor->mode_timer = time;
	now_actor->angle = spd_c->y;
	now_actor->angle_add = spd_c->z;
	return actor;
    }
    return NULL;
}

/* 斜面角度計算 */
extern void grnd_ang(Actor *thisx, short y_ang, s_xyz *ret_ang)
{
    if(thisx->ground_polygon_info != NULL){
	float	aa, p_bb, cc;
	float	x, y, z,x2,y2,z2;
	T_Polygon	*ground_polygon_info;
	short  h_p = rad_to_angle(3.14f*0.5f);
	ground_polygon_info = thisx->ground_polygon_info;
	
	aa   = T_POLYGON_ABC_CONV(ground_polygon_info->a);
	p_bb = T_POLYGON_ABC_CONV(ground_polygon_info->b);
	cc   = T_POLYGON_ABC_CONV(ground_polygon_info->c);
	
	x = sin_s(y_ang);
	z = cos_s(y_ang);
	y = (-(aa * x) - (cc * z)) * p_bb;
	ret_ang->sx = -rad_to_angle(fatan2(y, 1.0f));
	
	x2 = sin_s(y_ang - h_p);
	z2 = cos_s(y_ang - h_p);
	y2 = (-(aa * x2) - (cc * z2)) * p_bb;
	ret_ang->sz = -rad_to_angle(fatan2(y2, 1.0f));
    }
}


