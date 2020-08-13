/* $Id: z_common.c,v 2.1 1998-10-22 20:45:49+09 zelda Exp $ */
/* $Log: z_common.c,v $
 * Revision 2.1  1998-10-22 20:45:49+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.37  1998/10/20 14:02:02  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.36  1998-06-20 22:53:37+09  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.35  1998-06-06 18:45:25+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.34  1998-06-06 18:35:16+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.33  1998-06-05 23:20:55+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.32  1998-06-04 17:20:21+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.31  1998-06-03 22:23:27+10  sumiyosi
 * インゴーのセリフ関係いじりました。
 *
 * Revision 1.30  1998-05-20 23:37:23+10  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.29  1998/05/19 01:40:44  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.28  1998/05/18 13:45:00  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.27  1998/05/15 13:42:04  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.26  1998/05/15 07:40:18  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.25  1998/05/15 01:13:51  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.24  1998/05/08 14:03:24  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.23  1998/05/06 13:55:16  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.22  1998/05/05 13:32:39  sumiyosi
 * 会話関連ちと、改造
 *
 * Revision 1.21  1998/05/01 08:35:37  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.20  1998/04/28 00:32:48  sumiyosi
 * 城兵士メッセージ変更
 *
 * Revision 1.19  1998/04/14 11:26:32  sumiyosi
 * マロン、インゴーメッセージ追加
 *
 * Revision 1.18  1998/04/13 12:23:50  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.17  1998/04/09 08:28:03  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.16  1998/04/08  07:27:57  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.15  1998/04/07  14:51:16  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.14  1998/04/07  02:30:31  sumiyosi
 * ハイラル城メッセージせっと。
 *
 * Revision 1.13  1998/04/06  06:15:02  soejima
 * Inf_Tableマクロ修正
 *
 * Revision 1.12  1998/04/06  06:04:08  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.11  1998/04/03  14:14:34  sumiyosi
 * 何、変更したか忘れた…
 *
 * Revision 1.10  1998/03/26  05:54:20  sumiyosi
 * 一回あげます
 *
 * Revision 1.9  1998/03/25  08:21:52  sumiyosi
 * ゴロン関連のメッセージを入れました。
 *
 * Revision 1.8  1998/03/24  13:48:18  sumiyosi
 * とりあえず、コキリの森・マーケット・マーケットアレイのメッセージ
 * 入れときました…。
 *
 * Revision 1.7  1998/03/18  13:59:20  sumiyosi
 * *** empty log message ***
 *
 * Revision 1.6  1998/03/09  05:07:49  iwawaki
 * *** empty log message ***
 *
 * Revision 1.5  1998/02/13  11:15:40  sumiyosi
 * ご迷惑をおかけしました…
 *
 * Revision 1.4  1998/02/13  07:37:11  sumiyosi
 * ゴロン族のメッセージ追加
 *
 * Revision 1.3  1998/02/10  10:16:50  sumiyosi
 * タロンのメッセージ修正
 *
 * Revision 1.2  1998/02/10  08:39:54  sumiyosi
 * メッセージ修正
 *
 * Revision 1.1  1998/02/09  14:01:40  sumiyosi
 * Initial revision
 *
 *
 *
 * */
/*-----------------------------------------------------------------------
 *
 * z_common.c
 * 
 * Program:N.Sumiyosi
 * 1998/02/05
 *
 *----------------------------------------------------------------------*/
#include"z_save_area_h.h"
#include"z_common_data.h"
#include"z_in_race.h"
#include"z_parameter_h.h"
extern int debug_camera_sw;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃								      ┃
  ┃	メッセージ設定					     	      ┃
  ┃								      ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
extern void message_set3(
    Game_play *game_play,
    Actor *thisx,
    unsigned short mesno
){
    message_set2(game_play, mesno);
    thisx->talk_message=mesno;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃								      ┃
  ┃	謎フラグに関すること					      ┃
  ┃								      ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
/*┌─────────────────────────────────┐
  │	イベントフラグのゲット					      │
  └─────────────────────────────────┘*/
extern int event_check(
    int no
){
    int check_bit, data_idx;

    check_bit=1<<(no&0x000F);	/* チェックするビット	*/
    data_idx=no>>4;		/* データインデックス	*/
    return (Event_Chk_Inf(data_idx)&check_bit);
}

/*┌─────────────────────────────────┐
  │	イベントフラグのセット					      │
  └─────────────────────────────────┘*/
extern void event_set(
    int no
){
    int check_bit, data_idx;

    check_bit=1<<(no&0x000F);	/* チェックするビット	*/
    data_idx=no>>4;		/* データインデックス	*/
    Event_Chk_Inf(data_idx)|=check_bit;
}

/*┌─────────────────────────────────┐
  │	メッセージチェックフラグのゲット			      │
  └─────────────────────────────────┘*/
extern int nazo_check(
    int no
){
    int check_bit, data_idx;

    check_bit=1<<(no&0x000F);	/* チェックするビット	*/
    data_idx=no>>4;		/* データインデックス	*/
    return (Inf_Table(data_idx)&check_bit);
}

/*┌─────────────────────────────────┐
  │	メッセージチェックフラグのセット			      │
  └─────────────────────────────────┘*/
extern void nazo_set(
    int no
){
    int check_bit, data_idx;

    check_bit=1<<(no&0x000F);	/* チェックするビット	*/
    data_idx=no>>4;		/* データインデックス	*/
    Inf_Table(data_idx)|=check_bit;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃								      ┃
  ┃	会話に関すること					      ┃
  ┃								      ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
/************************************************************************
 *
 *	メッセージセット
 *			
 ************************************************************************/
static int npc_mes_set(
    Game_play *game_play,
    short chrno
){
    unsigned short mesno=0x0000;
    unsigned short time;
    Player_actor *pl=(Player_actor *)get_player_actor(game_play);

    switch(chrno)
    {
	
    case KOKIRI_SARIA:	/*** サリア	****/
	
	/* 森の精霊石入手？	*/
	if(event_check(EVNT_009)) {
	    if(nazo_check(NAZO_005)) mesno=0x1048;
	    else mesno=0x1047;
	    break;
	}
	
	/* ミド通せんぼ？	*/
	if(event_check(EVNT_002)) {
	    if(nazo_check(NAZO_003)) mesno=0x1032;
	    else mesno=0x1031;
	    break;
	}
	
	/* サリア冒頭？		*/
	if(nazo_check(NAZO_000)) {
	    if(nazo_check(NAZO_001)) mesno=0x1003;
	    else mesno=0x1002;
	}
	else mesno=0x1001;
	break;
	
    case KOKIRI_MIDO:	/*** ミド	****/
	
	if(ZCommonGet(link_age)) { /* リンク子供	*/

	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) {
		if(nazo_check(NAZO_010)) mesno=0x1046;
		else mesno=0x1045;
		break;
	    }
	    
	    /* サリア怒り？	*/
	    if(event_check(EVNT_003)) {
		if(nazo_check(NAZO_00E)) mesno=0x1034;
		else mesno=0x1033;
		break;
	    }
	    
	    if(nazo_check(NAZO_00C)) mesno=0x1030;
	    else mesno=0x102F;
	    break;
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) {
		if(nazo_check(NAZO_019)) mesno=0x1071;
		else mesno=0x1070;
		break;
	    }
	    
	    /* デクの樹Ｊｒ．の情報？	*/
	    if(event_check(EVNT_00B)) {
		if(nazo_check(NAZO_017)) mesno=0x1068;
		else mesno=0x1067;
		break;
	    }
	    
	    if(nazo_check(NAZO_015)) mesno=0x1061;
	    else mesno=0x1060;
	    break;
	}
	break;
	
    case KOKIRI_A:	/*** コキリＡ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1042;
	    else mesno=0x1004;
	}
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手	*/
	    if(event_check(EVNT_05C)) {
		mesno=0x1072;
	    }
	    else {
		if(nazo_check(NAZO_041)) mesno=0x1055;
		else mesno=0x1056;
	    }
	}
	break;
	
    case KOKIRI_B:	/*** コキリＢ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1043;
	    else {
		if(nazo_check(NAZO_01E)) mesno=0x1006;
		else mesno=0x1005;
	    }
	}
	
	else { /* リンク大人	*/
	    
	    /* 風のメダル入手	*/
	    if(event_check(EVNT_05C)) mesno=0x1073;
	    else mesno=0x105A;
	}
	break;
	
    case KOKIRI_C:	/*** コキリＣ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1042;
	    else mesno=0x1007;
	}
	
	else { /* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1072;
	    else {
		
		if(nazo_check(NAZO_047)) mesno=0x105E;
		else mesno=0x105D;
	    }
	}
	break;
	
    case KOKIRI_D:	/*** コキリＤ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1044;
	    else {
		if(nazo_check(NAZO_022)) mesno=0x1009;
		else mesno=0x1008;
	    }
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1075;
	    else mesno=0x105B;
	}
	break;
	
    case KOKIRI_E:	/*** コキリＥ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1042;
	    else {
		if(nazo_check(NAZO_024)) mesno=0x100B;
		else mesno=0x100A;
	    }
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1056;
	    else mesno=0x105F;
	    
	}
	break;

    case KOKIRI_F:	/*** コキリＦ	****/

	if(ZCommonGet(link_age)) {	/* リンク子供	*/

	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1043;
	    else {
		if(nazo_check(NAZO_026)) mesno=0x100D;
		else mesno=0x100C;
	    }
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1057;
	    else mesno=0x1057;
	    
	}
	break;

    case KOKIRI_G:	/*** コキリＧ	****/

	if(ZCommonGet(link_age)) {	/* リンク子供	*/

	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1043;
	    else {
		if(nazo_check(NAZO_028)) mesno=0x1019;
		else mesno=0x100E;
	    }
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1077;
	    else {
		if(nazo_check(NAZO_051)) mesno=0x1058;
		else mesno=0x1059;
	    }
	}
	break;
	
    case KOKIRI_H:	/*** コキリＨ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x1049;
	    else mesno=0x1035;
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1079;
	    else mesno=0x104e;
	}
	break;
	
    case KOKIRI_I:	/*** コキリＩ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x104A;
	    else mesno=0x1038;
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x1079;
	    else {
		if(nazo_check(NAZO_059)) mesno=0x1050;
		else mesno=0x104F;
	    }
	}
	break;
	
    case KOKIRI_J:	/*** コキリＪ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x104B;
	    else mesno=0x103C;
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x107B;
	    else mesno=0x1051;
	}
	break;
	
    case KOKIRI_K:	/*** コキリＫ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
	    /* 森の精霊石入手？	*/
	    if(event_check(EVNT_009)) mesno=0x104C;
	    else mesno=0x103D;
	}
	
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x107C;
	    else mesno=0x1052;
	}
	break;
	
    case KOKIRI_L:	/*** コキリＬ	****/
	
	if(ZCommonGet(link_age)) {	/* リンク子供	*/
	    
		/* 森の精霊石入手？	*/
		if(event_check(EVNT_009)) mesno=0x104D;
		else mesno=0x103E;
	    }
	    
	else {	/* リンク大人	*/
	    
	    /* 風のメダル入手？	*/
	    if(event_check(EVNT_05C)) mesno=0x106E;
	    else {
		if(nazo_check(NAZO_061)) mesno=0x1053;
		else mesno=0x1054;
	    }
	}
	break;
	
    case DEKU_JR:	/*** デクの樹Ｊｒ	****/
	
	/* 風のメダル入手？	*/
	if(event_check(EVNT_05C)) mesno=0x1078;
	else {
	    if(nazo_check(NAZO_066)) mesno=0x1066;
	    else mesno=0x1062;
	}
	break;
	
    case HEI_A:	/*** 城門の兵士	****/

	if(game_play->scene_data_ID==SPOT15) {	/* 特別…	*/
	    mesno=0x7002;
	    break;
	}
	
	if(nazo_check(NAZO_06A)) mesno=0x7004;
	else {
	    time=ZCommonGet(zelda_time);
	    if((time>=0x4000)&&(time<0xc556)) mesno=0x7002;
	    else mesno=0x7003;
	}
	break;
	
    case HEI_B:	/*** 路地裏倒れ兵士	****/
	
	/* ３つの精霊石そろった？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    if(nazo_check(NAZO_06C)) mesno=0x7008;
	    else mesno=0x7007;
	}
	break;
	
    case HEI_C:	/*** 見回り兵士	****/

	mesno=0x702D;
	break;

    case MONBAN_A:	/*** 凱旋門の門番	****/

	/* ３つの精霊石そろった？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
	){
	    mesno=0x7006;
	    break;
	}
	
	/* タロン探索願い？	*/
	if(event_check(EVNT_012)) {
	    if(nazo_check(NAZO_071)) mesno=0x7072;
	    else mesno=0x7071;
	}
	else {
	    mesno=0x7029;
	}
	break;
	
    case MONBAN_B:	/*** カカリコ村門番	****/
    case MONBAN_C:	/*** ゾーラ川門番	****/
	
	/* どちらかが道をあけてくれた？	*/
	if(event_check(EVNT_042)) {
	    mesno=0x2012;
	    break;
	}
	
	/* 門番にゼルダ姫の手紙をみせた？	*/
	if(event_check(EVNT_041)) {
	    if(nazo_check(NAZO_076)) mesno=0x2011;
	    else mesno=0x2010;
	    break;
	}
	
	/* ゼルダ姫から手紙もらった？	*/
	if(event_check(EVNT_040)) mesno=0x200F;
	else mesno=0x200E;
	break;
	
    case HYLIA_A:	/*** ハイリアＡ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))) mesno=0x7044;
	else mesno=0x7015;
	break;
	
    case HYLIA_B:	/*** ハイリアＢ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
	){
	    mesno=0x7045;
	}
	else {
	    if(nazo_check(NAZO_122)) mesno=0x7017;
	    mesno=0x7016;
	}
	break;

    case HYLIA_C:	/*** ハイリアＣ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x7046;
	}
	else {
	    if(nazo_check(NAZO_122)) mesno=0x7019;
	    mesno=0x7018;
	}
	break;

    case HYLIA_D:	/*** ハイリアＤ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x7047;
	    break;
	}
	    
	/* タロン帰宅？	*/
	if(event_check(EVNT_014))
	{
	    mesno=0x701A;
	    break;
	}

	/* インゴーからタロンの居場所？	*/
	if(event_check(EVNT_011)) {
	    if(nazo_check(NAZO_126)) mesno=0x701C;
	    else mesno=0x701B;
	}
	else mesno=0x701A;
	break;

    case HYLIA_E:	/*** ハイリアＥ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x7048;
	}
	else {
	    if(nazo_check(NAZO_12A)) mesno=0x701E;
	    mesno=0x701D;
	}
	break;
	    
    case HYLIA_F:	/*** ハイリアＦ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x7049;
	}
	else {
	    if(nazo_check(NAZO_12C)) mesno=0x7020;
	    mesno=0x701F;
	}
	break;
	    
    case HYLIA_G:	/*** ハイリアＧ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x704A;
	}
	else {
	    if(nazo_check(NAZO_12E)) mesno=0x7022;
	    mesno=0x7021;
	}
	break;
	
    case HYLIA_H:	/*** ハイリアＨ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x704B;
	}
	else {
	    if(nazo_check(NAZO_130)) mesno=0x7024;
	    mesno=0x7023;
	}
	break;
	    
    case HYLIA_I:	/*** ハイリアＩ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x704C;
	}
	else {
	    if(nazo_check(NAZO_132)) mesno=0x7026;
	    mesno=0x7025;
	}
	break;
	    
    case HYLIA_J:	/*** ハイリアＪ	****/
	
	/* ３つの精霊石そろう？	*/
	if((event_check(EVNT_009))&&
	   (event_check(EVNT_025))&&
	   (event_check(EVNT_037))
        ){
	    mesno=0x704D;
	}
	else {
	    if(nazo_check(NAZO_134)) mesno=0x7028;
	    mesno=0x7027;
	}
	break;
	    
    case LAKE_JIJI:	/*** 湖のじいさん	****/
	
	if(nazo_check(NAZO_136)) mesno=0x403D;
	mesno=0x403C;
	break;

    case DANPEI:	/*** 墓守ダンペイ	****/

	if(nazo_check(NAZO_138)) mesno=0x5029;
	else mesno=0x5028;
	break;

    case DANPEI_DIALY:	/*** ダンペイの日記	****/

	mesno=0x5002;
	break;

    case GORON_A:	/*** ゴロンＡ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/
	    
	    /* 炎の精霊石入手？	*/
	    if(event_check(EVNT_025)) {
		mesno=0x3027;
		break;
	    }
	    
	    /* 大岩爆破？	*/
	    if(event_check(EVNT_023)) mesno=0x3021;
	    else {
		if(nazo_check(NAZO_140)) mesno=0x302A;
		else mesno=0x3008;
	    }
	}
	else {	/* リンク大人	*/
	    
	    if(event_check(EVNT_020)) mesno=0x4043;
	    else mesno=0x302A;
	}
	break;

    case GORON_B:	/*** ゴロンＢ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/
	    
	    /* 炎の精霊石入手？	*/
	    if(event_check(EVNT_025)) {
		mesno=0x3027;
		break;
	    }
	    
	    /* 大岩爆破？	*/
	    if(event_check(EVNT_023)) mesno=0x3026;
	    else mesno=0x3009;
	}
	else {	/* リンク大人	*/
	    
	    if(event_check(EVNT_02A)) mesno=0x4043;
	    else mesno=0x302A;
	}
	break;

    case GORON_C:	/*** ゴロンＣ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/
	    
	    /* 炎の精霊石入手？	*/
	    if(event_check(EVNT_025)) {
		mesno=0x3027;
		break;
	    }
	    
	    /* 大岩爆破？	*/
	    if(event_check(EVNT_023)) {
		mesno=0x3026;
		break;
	    }

	    /* ２回目		*/
	    if(nazo_check(NAZO_14B)) mesno=0x302B;
	    else mesno=0x300A;
	}
	else {	/* リンク大人	*/
	    
	    if(event_check(EVNT_02B)) mesno=0x4043;
	    else mesno=0x302A;
	}
	break;

    case GORON_D:	/*** ゴロンＤ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/
	    
	    /* 炎の精霊石入手？	*/
	    if(event_check(EVNT_025)) {
		mesno=0x3027;
		break;
	    }
	    if(nazo_check(NAZO_150)) mesno=0x3015;
	    else mesno=0x3014;
	}
	else {	/* リンク大人	*/
	    
	    if(event_check(EVNT_02C)) mesno=0x4043;
	    else mesno=0x302A;
	}
	break;
	
    case GORON_E:	/*** ゴロンＥ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/
	    
	    /* 炎の精霊石入手？	*/
	    if(event_check(EVNT_025)) {
		mesno=0x3027;
		break;
	    }
	    if(nazo_check(NAZO_154)) mesno=0x3017;
	    else mesno=0x3016;
	}
	else { /* リンク大人	*/
	    
	    if(event_check(EVNT_02C)) mesno=0x4043;
	    else mesno=0x302A;
	}
	break;
	    
    case GORON_F:	/*** ゴロンＦ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/
	    
	    /* 炎の精霊石入手？	*/
	    if(event_check(EVNT_025)) {
		mesno=0x3027;
		break;
	    }
	    if(nazo_check(NAZO_158)) mesno=0x3019;
	    else mesno=0x3018;
	}
	else { /* リンク大人	*/
	    
	    if(event_check(EVNT_02D)) mesno=0x4043;
	    else mesno=0x302A;
	}
	break;
	
    case DARUNIA:	/*** ダルニア	****/

	/* 炎の精霊石入手？	*/
	if(event_check(EVNT_025)) {
	    mesno=0x3029;
	    break;
	}

	/* ゴロンＦと会話・ゴロン店主の依頼？	*/
	if((event_check(EVNT_020))&&
	   (event_check(EVNT_021))) mesno=0x301B;
	else mesno=0x301A;
	break;
	
    case ZORA_A:	/*** ゾーラＡ	****/

	/* 水の精霊石入手？	*/
	if(event_check(EVNT_037)) {
	    mesno=0x402D;
	    break;
	}

	/* ゾーラ族と会話？	*/
	if(event_check(EVNT_030)) mesno=0x4007;
	else mesno=0x4006;
	break;
	
    case ZORA_B:	/*** ゾーラＢ	****/

	/* 水の精霊石入手？	*/
	if(event_check(EVNT_037)) {
	    mesno=0x402E;
	    break;
	}

	/* ゾーラ族と会話？	*/
	if(event_check(EVNT_030)) {
	    if(nazo_check(NAZO_184)) mesno=0x4009;
	    else mesno=0x4008;
	}
	else mesno=0x4006;
	break;

    case ZORA_C:	/*** ゾーラＣ	****/

	/* 水の精霊石入手？	*/
	if(event_check(EVNT_037)) {
	    mesno=0x402D;
	    break;
	}

	/* ゾーラの里で空きびん→ゾーラＣと会話？	*/
	if(event_check(EVNT_031))
	{
	    if(nazo_check(NAZO_18A)) mesno=0x400B;
	    else mesno=0x402F;
	    break;
	}
	
	/* ゾーラ族と会話？	*/
	if(event_check(EVNT_030)) mesno=0x400A;
	else mesno=0x4006;
	break;

    case ZORA_D:	/*** ゾーラＤ	****/

	/* 水の精霊石入手？	*/
	if(event_check(EVNT_037)) {
	    mesno=0x402E;
	    break;
	}

	/* ゾーラ族と会話？	*/
	if(event_check(EVNT_030)) mesno=0x400C;
	else mesno=0x4006;
	break;
	
    case ZORA_E:	/*** ゾーラＥ	****/

	/* 水の精霊石入手？	*/
	if(event_check(EVNT_037)) {
	    mesno=0x402D;
	    break;
	}

	/* キングゾーラ許可？	*/
	if(event_check(EVNT_033)) {
	    mesno=0x4010;
	    break;
	}

	/* ゾーラ族と会話？	*/
	if(event_check(EVNT_030)) mesno=0x400F;
	else mesno=0x4006;
	break;
	
    case ZORA_F:	/*** ゾーラＦ	****/

	/* 水の精霊石入手？	*/
	if(event_check(EVNT_037)) {
	    mesno=0x402E;
	    break;
	}

	/* ゾーラ族と会話？	*/
	if(event_check(EVNT_030)) mesno=0x4011;
	else mesno=0x4006;
	break;
	
    case KING_ZORA:	/*** キングゾーラ	****/

	if(ZCommonGet(link_age)) { /* リンク子供	*/

	    /* 水の精霊石入手？	*/
	    if(event_check(EVNT_037)) {
		mesno=0x402B;
		break;
	    }

	    /* 空ビンを手にいれた？	*/
	    if(event_check(EVNT_031)) {
		if(nazo_check(NAZO_198)) mesno=0x401C;
		else mesno=0x401B;
	    }
	    else mesno=0x401A;
	}
	break;

    case KAKARICO_A:	/*** カカリコ村人Ａ	****/
	    
	mesno=0x500F;
	break;

    case KAKARICO_B:	/*** カカリコ村人Ｂ	****/

	mesno=0x5010;
	break;

    case KAKARICO_C:	/*** カカリコ村人Ｃ	****/

	mesno=0x5012;
	break;
	
    case KAKARICO_D:	/*** カカリコ村人Ｄ	****/

	if(nazo_check(NAZO_226)) mesno=0x5001;
	else mesno=0x5000;
	break;

    case KAKARICO_E:	/*** カカリコ村人Ｅ	****/

	mesno=0x5012;
	break;
	
    case KAKARICO_F:	/*** カカリコ村人Ｆ	****/

	if(nazo_check(NAZO_22A)) mesno=0x5001;
	else mesno=0x5000;
	break;

    case MARON:		/*** マロン	****/

	/* マロンの説明？	*/
	if(event_check(EVNT_016)) {
	    mesno=0x2049;
	    break;
	}

	/* エポナ逃げる？	*/
	if(event_check(EVNT_015)) {
	    mesno=0x2048;
	    break;
	}

	/* タロン帰宅？		*/
	if(event_check(EVNT_014)) {
	    mesno=0x2047;
	    break;
	}

	/* "探索願い"が出てて、"帰宅"してない？	*/
	if(( event_check(EVNT_012))&&
	   (!event_check(EVNT_014))) {
	    mesno=0x2044;
	    break;
	}

	/* マロンと話した？	*/
	if(event_check(EVNT_010)) {

	    /* インゴーと話した？	*/
	    if(event_check(EVNT_011)) mesno=0x2043;
	    else mesno=0x2042;
	}
	else mesno=0x2041;
	break;

    case INGO:		/*** インゴー	****/

	if(ZCommonGet(link_age)) {	/* 子供時代	*/

	    /* タロン帰宅？		*/
	    if(event_check(EVNT_014)) {
		mesno=0x2040;
		break;
	    }
	    
	    if(nazo_check(NAZO_094)) mesno=0x2040;
	    else mesno=0x203F;
	}
	else {	/* 大人時代	*/

	    /* エポナ入手？	*/
	    if(event_check(EVNT_018)) {
		break;
	    }

	    if(ZCommonGet(asahiru_fg)) {
		mesno=0x204E;
		break;
	    }
#if 0
	    /* インゴーの勝ち	*/
	    if(INGORaceGetScene==SCENE_1_WIN1) {
		if(INGORaceGetFlags(INGO_COND2)) {
		    mesno=0x203E;
		    break;
		}
		mesno=0x203D;
		break;
	    }

	    /* インゴーの負け( 1回目)	*/
	    if(INGORaceGetScene==SCENE_1_LOS1) {
		mesno=0x203A;
		break;
	    }

	    /* インゴーの負け( 2回目)	*/
	    if(INGORaceGetScene==SCENE_1_LOS2) {
		mesno=0x203B;
		break;
	    }
	    
	    /* 乗馬体験中？	*/
	    if(INGORaceGetScene==SCENE_2) {
		if(pl->action&P_ACTION_RIDE_HORSE) {
		    if(INGORaceGetFlags(INGO_COND1))	mesno=0x2038;
		    else mesno=0x2037;
		}
		else mesno=0x2036;
		break;
	    }
#endif
	    if(nazo_check(NAZO_09A)) mesno=0x2031;
	    else mesno=0x2030;
	    break;
	}
	break;

    }

    if(!mesno) mesno=0x0001;
    return mesno;
}

/************************************************************************
 *
 *	メッセージ後の、フラグセット
 *			
 ************************************************************************/
static void info_set(
    unsigned short mesno,
    short chrno
){
    switch(chrno)
    {
	
    case KOKIRI_SARIA:	/*** サリア	****/

	switch(mesno)
	{
	case 0x1001: nazo_set(NAZO_000); break;
	case 0x1002: nazo_set(NAZO_001); break;

	case 0x1031:
	    event_set(EVNT_003);	/* 《サリア怒り》	*/
	    nazo_set(NAZO_003);
	    break;
	    
	case 0x1047: nazo_set(NAZO_005); break;
	}
	break;

    case KOKIRI_MIDO:	/*** ミド	****/

	switch(mesno)
	{
	case 0x102F:
	    event_set(NAZO_002);	/* 《ミド通せんぼ》	*/
	    nazo_set(NAZO_00C);
	    break;
	    
	case 0x1033:

	    /*
	     * ♪ＳＥセット[どいたときの謎解き正解音]
	     */
	    Na_StartSystemSe(
		NA_SE_SY_CORRECT_CHIME
		);
	    
	    event_set(EVNT_004);	/* 《デクの樹への道開けた》	*/
	    nazo_set(NAZO_00E);
	    break;
	    
	case 0x1045: nazo_set(NAZO_010); break;
	case 0x1060: nazo_set(NAZO_015); break;

	case 0x1067:
	    event_set(EVNT_00A);	/* 《迷いの森への道開けた》	*/
	    nazo_set(NAZO_017);
	    break;

	case 0x1070: nazo_set(NAZO_019); break;
	}
	break;

    case KOKIRI_A:	/*** コキリＡ	****/

	if(mesno==0x1056) nazo_set(NAZO_041);
	break;
	
    case KOKIRI_B:	/*** コキリＢ	****/

	if(mesno==0x1005) nazo_set(NAZO_01E);
	break;

    case KOKIRI_C:	/*** コキリＣ	****/

	if(mesno==0x105D) nazo_set(NAZO_047);
	break;

    case KOKIRI_D:	/*** コキリＤ	****/	

	if(mesno==0x1008) nazo_set(NAZO_022);
	break;

    case KOKIRI_E:	/*** コキリＥ	****/

	if(mesno==0x100A) nazo_set(NAZO_024);
	break;

    case KOKIRI_F:	/*** コキリＦ	****/

	if(mesno==0x100C) nazo_set(NAZO_026);
	break;

    case KOKIRI_G:	/*** コキリＧ	****/

	if(mesno==0x100E) nazo_set(NAZO_028);
	if(mesno==0x1059) nazo_set(NAZO_051);
	break;
	
    case KOKIRI_I:	/*** コキリＩ	****/

	if(mesno==0x104F) nazo_set(NAZO_059);
	break;
	
    case KOKIRI_L:	/*** コキリＬ	****/

	if(mesno==0x1054) nazo_set(NAZO_061);
	break;
	
    case DEKU_JR:	/*** デクの樹Ｊｒ	****/

	if(mesno==0x1062) nazo_set(NAZO_066);
	break;
	
    case HEI_A:		/*** 城門の兵士	****/

	if(mesno==0x7002) nazo_set(NAZO_06A);
	if(mesno==0x7003) nazo_set(NAZO_06A);
	break;

    case HEI_B:		/*** 路地裏倒れ兵士	****/

	if(mesno==0x7007) nazo_set(NAZO_06C);
	break;
	
    case MONBAN_A:	/*** 凱旋門の門番	****/

	if(mesno==0x7071) nazo_set(NAZO_071);
	break;
	
    case MONBAN_B:	/*** ゾーラ川門番	****/
    case MONBAN_C:	/*** カカリコ村門番	****/

	if(mesno==0x2010) nazo_set(NAZO_076);
	break;

    case HYLIA_B:	/*** ハイリアＢ	****/

	if(mesno==0x7016) nazo_set(NAZO_122);
	break;

    case HYLIA_C:	/*** ハイリアＣ	****/

	if(mesno==0x7018) nazo_set(NAZO_124);
	break;

    case HYLIA_E:	/*** ハイリアＥ	****/

	if(mesno==0x701D) nazo_set(NAZO_12A);
	break;

    case HYLIA_F:	/*** ハイリアＦ	****/

	if(mesno==0x701F) nazo_set(NAZO_12C);
	break;
	
    case HYLIA_G:	/*** ハイリアＧ	****/

	if(mesno==0x7021) nazo_set(NAZO_12E);
	break;

    case HYLIA_H:	/*** ハイリアＨ	****/

	if(mesno==0x7023) nazo_set(NAZO_130);
	break;

    case HYLIA_I:	/*** ハイリアＩ	****/

	if(mesno==0x7025) nazo_set(NAZO_132);
	break;

    case HYLIA_J:	/*** ハイリアＪ	****/

	if(mesno==0x7027) nazo_set(NAZO_134);
	break;

    case LAKE_JIJI:	/*** 湖のじいさん	****/

	if(mesno==0x403C) nazo_set(NAZO_136);
	break;

    case DANPEI:	/*** 墓守ダンペイ	****/

	if(mesno==0x5028) nazo_set(NAZO_138);
	break;

    case GORON_A:	/*** ゴロンＡ	****/

	if(mesno==0x3008) nazo_set(NAZO_140);
	break;

    case GORON_C:	/*** ゴロンＣ	****/

	if(mesno==0x300B) nazo_set(NAZO_14B);
	break;

    case GORON_D:	/*** ゴロンＤ	****/

	if(mesno==0x3014) nazo_set(NAZO_150);
	break;

    case GORON_E:	/*** ゴロンＥ	****/

	if(mesno==0x3016) nazo_set(NAZO_154);
	break;

    case GORON_F:	/*** ゴロンＦ	****/

	if(mesno==0x3018) {
	    event_set(EVNT_020);
	    nazo_set(NAZO_158);
	}
	break;

    case DARUNIA:	/*** ダルニア	****/
	
	if(mesno==0x3020) {
	    event_set(EVNT_022);
	    nazo_set(NAZO_173);
	}
	break;

    case ZORA_A:	/*** ゾーラＡ	****/
    case ZORA_D:	/*** ゾーラＤ	****/
    case ZORA_E:	/*** ゾーラＥ	****/
    case ZORA_F:	/*** ゾーラＦ	****/

	if(mesno==0x4006) event_set(EVNT_030);
	break;
	
    case ZORA_B:	/*** ゾーラＢ	****/

	if(mesno==0x4006) event_set(EVNT_030);
	if(mesno==0x4008) nazo_set(NAZO_184);
	break;

    case ZORA_C:	/*** ゾーラＣ	****/

	if(mesno==0x4006) event_set(EVNT_030);
	if(mesno==0x400A) event_set(EVNT_032);
	if(mesno==0x402F) nazo_set(NAZO_18A);
	break;

    case KING_ZORA:	/*** キングゾーラ	****/

	if(mesno==0x401B) {
	    event_set(EVNT_033);
	    nazo_set(NAZO_198);
	}
	break;

    case KAKARICO_D:	/*** カカリコ村人Ｄ	****/

	if(mesno==0x5000) nazo_set(NAZO_226);
	break;

    case KAKARICO_F:	/*** カカリコ村人Ｆ	****/

	if(mesno==0x5013) nazo_set(NAZO_22A);
	break;

    case MARON:	/*** マロン	****/

	if(mesno==0x2041) event_set(EVNT_010);
	if(mesno==0x2044) event_set(EVNT_012);
	if(mesno==0x2047) event_set(EVNT_015);
	if(mesno==0x2048) event_set(EVNT_016);
	break;

    case INGO:	/*** インゴー	****/
#if 0
	if(mesno==0x203F) {
	    event_set(EVNT_011);
	    nazo_set(NAZO_094);
	}

	/* 競馬に勝った	1回目	*/
	if(mesno==0x203D) {
	    INGORaceSetFlags(INGO_COND2);
	    INGORaceSetScene(SCENE_1);	/* 始めにもどる	*/
	}
	
	/* 競馬に負けた 1回目	*/
	if(mesno==0x203A) {
	    INGORaceSetFlags(INGO_COND3);
	    INGORaceSetScene(SCENE_3);	/* もっかい競馬	*/
	}
	
	/* 競馬に負けた 2回目	*/
	if(mesno==0x203B) {
	    INGORaceSetScene(SCENE_4);	/* 錯乱モードへ	*/
	}
	
	/* 体験乗馬ヤメ	*/
	if(mesno==0x2035) {
	    INGORaceSetScene(SCENE_1);
	}
#endif	
	break;
	
    }
}

/************************************************************************
 *
 *	選択メッセージ
 *			
 ************************************************************************/
static int select_mes(
    Game_play *game_play,
    Actor *thisx,
    unsigned short mesno
){
    Message *mes=(Message *)&game_play->message;
    int ret=TRUE;

    switch(mesno)
    {
	
    case 0x1035:

	/* 黄色のアイコン？	*/
	if(mes->sel_pnt==0) {
	    if(nazo_check(NAZO_02A)) message_set3(game_play, thisx, 0x1036);
	    else message_set3(game_play, thisx, 0x1041);
	}

	/* モノの持ち替え？	*/
	if(mes->sel_pnt==1) {
	    if(nazo_check(NAZO_02B)) message_set3(game_play, thisx, 0x1037);
	    else message_set3(game_play, thisx, 0x1041);
	}
	ret=FALSE;
	break;

    case 0x1038:
	
	/* ＭＡＰ？	*/
	if(mes->sel_pnt==0) {
	    if(nazo_check(NAZO_02E)) message_set3(game_play, thisx, 0x1039);
	    else message_set3(game_play, thisx, 0x1041);
	}

	/* 装備？	*/
	if(mes->sel_pnt==1) {
	    if(nazo_check(NAZO_02F)) message_set3(game_play, thisx, 0x103A);
	    else message_set3(game_play, thisx, 0x1041);
	}

	/* コレクト？	*/
	if(mes->sel_pnt==2) {
	    if(nazo_check(NAZO_030)) message_set3(game_play, thisx, 0x103B);
	    else message_set3(game_play, thisx, 0x1041);
	}
	ret=FALSE;
	break;

    case 0x103E:

	/* 盾あり？	*/
	if(mes->sel_pnt==0) message_set3(game_play, thisx, 0x103F);

	/* 盾なし？	*/
	if(mes->sel_pnt==1) message_set3(game_play, thisx, 0x1040);
	ret=FALSE;
	break;

    case 0x1041:

	if(mes->sel_msgno==0x1035) {
	    if(mes->sel_pnt==0) {
		message_set3(game_play, thisx, 0x1036);
		nazo_set(NAZO_02A);
	    }
	    if(mes->sel_pnt==1) {
		message_set3(game_play, thisx, 0x1037);
		nazo_set(NAZO_02B);
	    }
	}
	
	if(mes->sel_msgno==0x1038) {
	    if(mes->sel_pnt==0) {
		message_set3(game_play, thisx, 0x1039);
		nazo_set(NAZO_02E);
	    }
	    if(mes->sel_pnt==1) {
		message_set3(game_play, thisx, 0x103A);
		nazo_set(NAZO_02F);
	    }
	    if(mes->sel_pnt==2) {
		message_set3(game_play, thisx, 0x103B);
		nazo_set(NAZO_030);
	    }
	}
	ret=FALSE;
	break;

    case 0x1062:

	/* うん	*/
	if(mes->sel_pnt==0) message_set3(game_play, thisx, 0x1063);

	/* やだ	*/
	if(mes->sel_pnt==1) message_set3(game_play, thisx, 0x1064);
	ret=FALSE;
	break;

    case 0x2030:
    case 0x2031:
	
	/* うん	*/
	if(mes->sel_pnt==0) {
	    if(S_Private.lupy_count>=10) {
		message_set3(game_play, thisx, 0x2034);
		lupy_increase(-10);
	    }
	    else {
		message_set3(game_play, thisx, 0x2032);
	    }
	}

	/* やだ	*/
	if(mes->sel_pnt==1) message_set3(game_play, thisx, 0x2032);
	
	nazo_set(NAZO_09A);
	ret=FALSE;
	break;

    case 0x2037:
#if 0	
	INGORaceSetFlags(INGO_COND1);
#endif	
	
    case 0x2036:
	
	/* つづける	*/
	if(mes->sel_pnt==0) message_set3(game_play, thisx, 0x201F);

	/* やめる	*/
	if(mes->sel_pnt==1) message_set3(game_play, thisx, 0x205A);
	ret=FALSE;
	break;

    case 0x2038:

	/* やる		*/
	if(mes->sel_pnt==0) {
#if 0	    
	    INGORaceSetScene(SCENE_3);
	    mes->wct=0;
#endif	    
	    break;
	}
	
	/* やめる	*/
	if(mes->sel_pnt==1) message_set3(game_play, thisx, 0x205A);
	ret=FALSE;
	break;

    case 0x2034:
	
	/* 説明きく	*/
	if(mes->sel_pnt==0) {
	    message_set3(game_play, thisx, 0x2035);
	    ret=FALSE;
	    break;
	}

    case 0x2035:
#if 0
	INGORaceSetScene(SCENE_2);
	mes->wct=0;
#endif	
	break;
	
    case 0x2043:

	/* タロン探索願い出した？	*/
	if(!event_check(EVNT_012)) {
	    message_set3(game_play, thisx, 0x2044);
	    ret=FALSE;
	}
	break;

    case 0x205A:
#if 0	
	INGORaceSetScene(SCENE_1);
	mes->wct=0;
#endif	
	break;

    case 0x300A:

	/* うん		*/
	if(mes->sel_pnt==0) {
	    if(event_check(EVNT_022)) message_set3(game_play, thisx, 0x300B);
	    else message_set3(game_play, thisx, 0x300C);
	}
		
	/* ううん	*/
	if(mes->sel_pnt==1) message_set3(game_play, thisx, 0x300D);
	ret=FALSE;
	break;

    case 0x301B:

	/* 炎の精霊石ほしい	*/
	if(mes->sel_pnt==0) message_set3(game_play, thisx, 0x301D);

	/* バクダン品切でこまる	*/
	if(mes->sel_pnt==1) {
	    if(nazo_check(NAZO_173)) message_set3(game_play, thisx, 0x301F);
	    else message_set3(game_play, thisx, 0x301E);
	}
	ret=FALSE;
	break;

    case 0x301E:

	message_set3(game_play, thisx, 0x3020);
	ret=FALSE;
	break;

    case 0x400C:

	/* うん		*/
	if(mes->sel_pnt==0) {
	    message_set3(game_play, thisx, 0x400D);
	}
		
	/* ううん	*/
	if(mes->sel_pnt==1) {
	    message_set3(game_play, thisx, 0x400E);
	}
	ret=FALSE;
	break;
	    
    case 0x7007:

	message_set3(game_play, thisx, 0x703E);
	ret=FALSE;
	break;

    case 0x703E:
	
	message_set3(game_play, thisx, 0x703F);
	ret=FALSE;
	break;
	
    case 0x703F:
	
	message_set3(game_play, thisx, 0x7042);
	ret=FALSE;
	break;

    }
    return ret;
}

/*┌─────────────────────────────────┐
  │	メッセージセレクト					      │
  └─────────────────────────────────┘*/
extern unsigned short set_talk_message(
    Game_play *game_play,
    short chrno
){
    ( void )game_play;
    return (unsigned short)npc_mes_set(game_play, chrno);
}

/*┌─────────────────────────────────┐
  │	謎フラグ、次のメッセージセット				      │
  └─────────────────────────────────┘*/
static int set_nazo_and_next_message(
    Game_play *game_play,
    short chrno,
    unsigned short mesno
){
    ( void )game_play;
    info_set(mesno, chrno);
    return FALSE;
}

/*┌─────────────────────────────────┐
  │	敵制御で終わるメッセージの場合…処理			      │
  └─────────────────────────────────┘*/
static int special_talk(
    Game_play *game_play,
    Actor *thisx,
    short chrno
){
    ( void )chrno;
    return select_mes(game_play, thisx, thisx->talk_message);
}

/*┌─────────────────────────────────┐
  │	メッセージ終了						      │
  └─────────────────────────────────┘*/
static int message_end_check(
    Game_play *game_play,
    Actor *thisx,
    short chrno
){
    Message *mes=(Message *)&game_play->message;
    int ret=FALSE;
    
    switch(message_check(&game_play->message))
    {
    case 2:	/* メッセージ終了？	*/

	set_nazo_and_next_message(game_play, chrno, thisx->talk_message);
	ret=TRUE;
	break;

    case 4:	/* 選択			*/
    case 5:	/* 敵側制御？		*/

	if(!pad_on_check(game_play)) break;
	if(special_talk(game_play, thisx, chrno)) {
	    Na_StartSystemSe(NA_SE_SY_CANCEL);
	    mes->msg_mode=M_CLOSE;
	    ret=TRUE;
	}
	break;
    }
    return ret;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃								      ┃
  ┃	会話処理						      ┃
  ┃								      ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
extern int talk_to_player(
    Game_play *game_play,
    Actor *thisx,
    int chrno,
    int *talking
){
    short distance_angle_y;
    short display_x;
    short display_y;

    if(Actor_talk_check(thisx, game_play)) {
	*talking=ON;
	return TRUE;
    }

    /*
     * すでに会話中か？
     */
    if(*talking==ON)
    {
	if(message_end_check(game_play, thisx, chrno)) *talking=OFF;
	return FALSE;
    }

    /*
     * 会話対象の画面内チェック
     */
    Actor_display_position_set(
	game_play,
	thisx,
	&display_x,
	&display_y
    );
    
    if((display_x<  0)||
       (display_x>320)||
       (display_y<  0)||
       (display_y>240))	return FALSE;

    /*
     * 向きチェック
     */
    distance_angle_y=
	ABS(distance_angle(thisx->player_angle_y,
			   thisx->shape.angle.sy
	));
    if(distance_angle_y>=0x4300)
	return FALSE;
    
    /*
     * 会話リクエストをだす
     */
/*    if((thisx->player_range > anchor_status_data[ANCHOR_RANGE_A].range)&&
 */

    /* かりに 80.0f ということにします…(^^;;	*/
    if((thisx->player_range > (160.0f*160.0f))&&
       (!thisx->anchor_flag)) return FALSE;

    if(thisx->player_range<=(80.0f*80.0f)) {
	if(Actor_talk_request2(thisx, game_play, 80.0f))
	    thisx->talk_message=set_talk_message(game_play, chrno);
    }
    else {
	if(Actor_talk_request(thisx, game_play))
	    thisx->talk_message=set_talk_message(game_play, chrno);
    }
    return FALSE;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
  ┃								      ┃
  ┃	視点移動						      ┃
  ┃								      ┃
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
/*┌─────────────────────────────────┐
  │	チェイン角度もどす					      │
  └─────────────────────────────────┘*/
extern int chain_angle_reset(
    s_xyz *neck_angle,
    s_xyz *body_angle
){
    /* 首アングルもどす	*/
    add_calc_short_angle(
	&neck_angle->sy,
	0,
	6,
	6200,
	100
    );
    add_calc_short_angle(
	&neck_angle->sx,
	0,
	6,
	6200,
	100
    );
    
    /* 体アングルもどす	*/
    add_calc_short_angle(
	&body_angle->sy,
	0,
	6,
	6200,
	100
    );
    add_calc_short_angle(
	&body_angle->sx,
	0,
	6,
	6200,
	100
    );
    return TRUE;
}

/*┌─────────────────────────────────┐
  │	チェイン角度を目標に向ける				      │
  └─────────────────────────────────┘*/
static int chain_angle_set(
    Actor *thisx,
    xyz_t *target_pos,
    s_xyz *neck_angle,
    s_xyz *body_angle
){
    short aim_look_angle_x;
    short aim_look_angle_y;
    short offset_angle;
    short func_result;

    /*
     * 注目点との角度を求める
     */
    aim_look_angle_x=search_position_angleX(
	&thisx->eye.position,
	target_pos
    );
    aim_look_angle_y=search_position_angleY(
	&thisx->eye.position,
	target_pos
    ) -thisx->world.angle.sy;

    /*
     * 首縦ふり
     */
    offset_angle=aim_look_angle_x;
    add_calc_short_angle(
	&neck_angle->sx, offset_angle,
	6,
	2000,	/* 6200,	*/
	1	/* 100		*/
    );
    neck_angle->sx=(short)min_max_limit(
	neck_angle->sx,
	6000*-1,
	6000
    );
    
    /*
     * 首まわす
     */
    offset_angle=aim_look_angle_y;
    func_result=add_calc_short_angle(
	&neck_angle->sy, offset_angle,
	6,
	2000,	/* 6200,	*/
	1	/* 1000		*/
    );
    neck_angle->sy=(short)min_max_limit(
	neck_angle->sy,
	8000*-1,
	8000
    );
    
    if((func_result)&&(ABS(neck_angle->sy)<8000))
	return FALSE;
    
    /*
     * 体まわす
     */
    offset_angle=(short)(aim_look_angle_y-neck_angle->sy);
    add_calc_short_angle(
	&body_angle->sy, offset_angle,
	4,
	2000,	/* 6200,	*/
	1	/* 10		*/
    );

    body_angle->sy=(short)min_max_limit(
	body_angle->sy,
	12000*-1,
	12000
    );

    return TRUE;
}

/*┌─────────────────────────────────┐
  │	メイン							      │
  └─────────────────────────────────┘*/
extern short eye_move(
    Game_play *game_play,
    Actor *thisx,
    s_xyz *neck_angle,
    s_xyz *body_angle,
    float eye_posint,
    int talking
){
    Actor *pl=get_player_actor(game_play);
    short distance_angle_y;
    xyz_t target_position;

    talking;
    
    /*
     * 目の位置セット
     */
    thisx->eye.position=thisx->world.position;
    thisx->eye.position.y+=eye_posint;

    /*
     * 向きチェック
     */
    
    /* デモ用条件追加	*/
    if(((!game_play->demo_play.mode)&&(!debug_camera_sw))||
       (ZCommonGet(scene_no)!=SPOT04_0)
    ){
	distance_angle_y=
	    ABS(distance_angle(thisx->player_angle_y,
			       thisx->shape.angle.sy
		));
	if(distance_angle_y>=0x4300)
	{
	    chain_angle_reset(neck_angle, body_angle);
	    return FALSE;
	}
    }

    /*
     * 注目点を見る
     */
    
    /* デモ用条件追加	*/
    if(((game_play->demo_play.mode)||(debug_camera_sw))&&
       (ZCommonGet(scene_no)==SPOT04_0)
    ){
	target_position=game_play->view.eye;
    }
    else {
	target_position=pl->eye.position;
    }

    chain_angle_set(
	thisx,
	&target_position,
	neck_angle,
	body_angle
    );
    return TRUE;
}

/*┌─────────────────────────────────┐
  │	メイン							      │
  └─────────────────────────────────┘*/
extern short eye_move2(
    Game_play *game_play,
    Actor *thisx,
    s_xyz *neck_angle,
    s_xyz *body_angle,
    xyz_t eye_pos
){
    Actor *pl=get_player_actor(game_play);
    short distance_angle_y;
    xyz_t target_position;

    /*
     * 目の位置セット
     */
    thisx->eye.position=eye_pos;

    /*
     * 向きチェック
     */
    
    /* デモ用条件追加	*/
    if(((!game_play->demo_play.mode)&&(!debug_camera_sw))||
       (ZCommonGet(scene_no)!=SPOT04_0)
    ){
	distance_angle_y=
	    ABS(distance_angle(thisx->player_angle_y,
			       thisx->shape.angle.sy
		));
	if(distance_angle_y>=0x4300)
	{
	    chain_angle_reset(neck_angle, body_angle);
	    return FALSE;
	}
    }

    /*
     * 注目点を見る
     */
    
    /* デモ用条件追加	*/
    if(((game_play->demo_play.mode)||(debug_camera_sw))&&
       (ZCommonGet(scene_no)==SPOT04_0)
    ){
	target_position=game_play->view.eye;
    }
    else {
	target_position=pl->eye.position;
    }

    chain_angle_set(
	thisx,
	&target_position,
	neck_angle,
	body_angle
    );
    return TRUE;
}
