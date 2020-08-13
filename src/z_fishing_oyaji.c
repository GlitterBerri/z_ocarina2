/* $Id: z_fishing_oyaji.c,v 2.1 1998-10-22 21:17:25+09 zelda Exp $ */
/*
 * $Log: z_fishing_oyaji.c,v $
 * Revision 2.1  1998-10-22 21:17:25+09  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.37  1998/10/01 08:35:59  morita
 * *** empty log message ***
 *
 * Revision 1.36  1998-10-01 17:21:52+09  morita
 * *** empty log message ***
 *
 * Revision 1.35  1998-09-30 23:49:49+09  morita
 * *** empty log message ***
 *
 * Revision 1.34  1998-09-30 16:06:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.33  1998-09-26 22:35:50+09  morita
 * *** empty log message ***
 *
 * Revision 1.32  1998-09-23 16:18:29+09  morita
 * *** empty log message ***
 *
 * Revision 1.31  1998-09-22 22:58:37+09  morita
 * *** empty log message ***
 *
 * Revision 1.30  1998-09-18 00:21:40+09  morita
 * *** empty log message ***
 *
 * Revision 1.29  1998-09-17 23:22:03+09  morita
 * *** empty log message ***
 *
 * Revision 1.28  1998-09-12 22:38:23+09  morita
 * *** empty log message ***
 *
 * Revision 1.27  1998-09-12 15:38:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.26  1998-09-12 14:10:48+09  morita
 * *** empty log message ***
 *
 * Revision 1.25  1998-09-09 16:46:34+09  morita
 *  戻る原
 *
 * Revision 1.24  1998-09-09 11:08:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.23  1998-09-08 23:24:04+09  morita
 * *** empty log message ***
 *
 * Revision 1.22  1998-09-03 23:59:57+09  morita
 * *** empty log message ***
 *
 * Revision 1.21  1998-09-02 22:10:31+09  morita
 * *** empty log message ***
 *
 * Revision 1.20  1998-09-02 22:04:19+09  morita
 * *** empty log message ***
 *
 * Revision 1.19  1998-08-31 22:19:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.18  1998-08-29 17:49:19+09  morita
 * *** empty log message ***
 *
 * Revision 1.17  1998-08-27 20:43:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.16  1998-08-27 19:26:21+09  morita
 * *** empty log message ***
 *
 * Revision 1.15  1998-08-27 18:17:12+09  morita
 * *** empty log message ***
 *
 * Revision 1.14  1998-08-26 22:21:37+09  kuzuhara
 * あれれ？
 *
 * Revision 1.13  1998-08-26 21:43:17+09  kuzuhara
 * やーす！金のウロコ
 * ＧＥＴ！！！！！
 *
 * Revision 1.12  1998-08-26 21:05:35+09  morita
 * *** empty log message ***
 *
 * Revision 1.11  1998-08-26 17:53:42+09  morita
 * *** empty log message ***
 *
 * Revision 1.10  1998-08-25 22:56:24+09  morita
 * *** empty log message ***
 *
 * Revision 1.9  1998-08-25 20:49:25+09  morita
 * *** empty log message ***
 *
 * Revision 1.8  1998-08-24 20:31:57+09  morita
 * *** empty log message ***
 *
 * Revision 1.7  1998-08-24 11:19:56+09  kuzuhara
 * どうです？
 *
 * Revision 1.6  1998-08-22 21:06:25+09  kuzuhara
 * するでー
 * ブルブル
 *
 * Revision 1.5  1998-08-22 18:24:17+09  morita
 * *** empty log message ***
 *
 * Revision 1.4  1998-08-21 00:09:32+09  morita
 * *** empty log message ***
 *
 * Revision 1.3  1998-08-05 16:39:43+09  kuzuhara
 * ふぃー
 *
 * Revision 1.2  1998-08-05 15:04:05+09  morita
 * *** empty log message ***
 *
 * Revision 1.1  1998-08-05 14:49:42+09  morita
 * Initial revision
 *
 **/


/* bm 専用 ->work[?] */
#define BM_MES_MODE 0
#define BM_MES_WAIT 1
#define BM_EYE_NO   2
#define BM_EYE_TIME 3
#define BM_KUBI_YA  4


/* 店の親父 */
/*=======================================================================
 *	会話処理
 *======================================================================*/
static void bm_message_check(Fishing_actor *this, Game_play *game_play)
{
/*    Player_actor *pla = (Player_actor *)get_player_actor(game_play);*/
    
    /* メッセージ原処理でっせ！ */
    
#if 0
    if ( kREG(32) ) {			/* start + B */
	PRINTF( "\033[35m ☆☆☆☆☆ うひゃあ   ☆☆☆☆☆ %d\n\033[m", message_check( &( game_play->message )) );
	PRINTF( "\033[36m ☆☆☆☆☆ とひょーん ☆☆☆☆☆ %d\n\033[m", this->work[ BM_MES_MODE ] );
	PRINTF( "\n\n"  );
	kREG(32) = OFF;
    }
#endif
    switch( this->work[ BM_MES_MODE ] ) {

    case 0:		/* イニシャルメッセージセット処理原 */
	if ( fishing_game_mode == 0 ) {					/* GAME 中でない？ */
	    if(AGE != 1 /* || KAZ(8) */) { /* 17歳 */
		if((HI_SCORE(HS_FISH) & SAVE_CHILD_PLAY) &&
		   !(HI_SCORE(HS_FISH) & SAVE_ADULT_PLAY)) { /* 子供やってから大人で初めて？ */
		    this->actor.talk_message = 0x4093;		/* Ｍ：おお しばらく！(開始) */
		} else {
		    this->actor.talk_message = 0x407b;		/* Ｍ：２０ルピーでする？(開始) */
		}
	    } else {
		this->actor.talk_message = 0x407b;		/* Ｍ：２０ルピーでする？(開始) */
	    }
	}
	else {		/* ゲーム中のメッセージ */
	    if(lure_with_head == 0) {
		this->actor.talk_message = 0x4084;/* なんかよう？ */
	    } else { /* ボウシとられた後？ */
		this->actor.talk_message = 0x4097;/* あかんゆうてるやろ！！ */
//		this->actor.talk_message = 0x408a;/* あかんゆうてるやろ！！ */
	    }
	}
	
	if( Actor_talk_check((Actor *)this, game_play) ) {	/* チェンジ会話モード原 */
	    if ( fishing_game_mode == 0 ) {				/* GAME 中でない？ */
		this->work[ BM_MES_MODE ] = 1;		/* 選択チェック原 */
		
		if(AGE != 1 /* || KAZ(8) */) { /* 17歳 */
		    HI_SCORE(HS_FISH) |= SAVE_ADULT_PLAY; /* １回でも話した */
		} else {
		    HI_SCORE(HS_FISH) |= SAVE_CHILD_PLAY; /* １回でも話した */
		}
	    }
	    else {
		this->work[ BM_MES_MODE ] = 10;  /*3;*/		/* 敵制御クリア原 */
	    }
	    break;
	}
	Actor_talk_request2((Actor *)this, game_play, 100.0f /* + (float)BREG(16) */ );	/* 会話できる範囲原 */
	break;
	
    case 1:		/* 選択メッセージチェック処理原 */
	if ( message_check( &( game_play->message ) ) == 4 ) {	/* 原選択待ち？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
		
		switch ( game_play->message.sel_pnt ) {		/* ええねん？あかんねん？  */
		case 0:				/* ええねん */
		    if ( S_Private.lupy_count >= 20 ) { /* お金ある？ */
 			lupy_increase( -20 ); 

			if ( !z_vibctl2_RumblePackIsConnected() )	/* 振動パックささってるか？の有無 */
			    this->actor.talk_message = 0x0407c;			/* Ｍ：振動パックないがな */
			else
			    this->actor.talk_message = 0x0407d;			/* Ｍ：振動パックあるやんけ */
			
			message_set2( game_play, this->actor.talk_message );	/* 強制メッセージセット */
			this->work[ BM_MES_MODE ] = 2;
		    }
		    else { /* 金ない */
			message_set2( game_play, 0x0407e );	/* 強制メッセージセット */
			this->work[ BM_MES_MODE ] = 3;
		    }
		    break;
		    
		case 1:				/* あかんねん */
		    message_set2( game_play, 0x002d );	/* 強制メッセージセット */
		    this->work[ BM_MES_MODE ] = 3;
		    break;
		}
	    }
	}
	break;

    case 2:		/* ぶるぶるパックメッセージ終了待ち */
	if ( message_check( &( game_play->message ) ) == 5 ) {	/* 敵制御メッセージ終了原待ち？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
			
		message_set2( game_play, 0x0407f );	/* 強制メッセージセット */
		this->work[ BM_MES_MODE ] = 4;
	    }
	}
	break;
	
    case 3:		/* 条件メッセージチェック処理原 */
	if ( message_check( &( game_play->message ) ) == 5 ) {	/* 敵制御メッセージ終了原待ち？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
		this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
#if 0
		if(AGE != 1) { /* 17歳 */
		    bm_head_no = 1; /* ハゲ ＋ 帽子 */
		    lure_with_head = 0;
		}
		
		head_check = 20;  /* 親父ぼうし判定なし時間 */
#endif		
	    }
	}

	if ( message_check( &( game_play->message ) ) == 6 ) {	/* 自動終了メッセージ待ち？ */
	    this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
	}
	
	break;

	
    case 4:		/* 条件メッセージチェック処理原(GAME 開始) */
	if ( message_check( &( game_play->message ) ) == 4 ) {	/* 原選択待ち？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
		
		switch ( game_play->message.sel_pnt ) {		/* ええねん？あかんねん？ */
		case 0:				/* ええねん */
		    FishRangeForMessage = (u16)fish_record;
		    message_set2( game_play, 0x04080 );	/* 強制メッセージセット */
		    this->work[ BM_MES_MODE ] = 5;			/* 戻る原 */
		    break;

		case 1:				/* あかんねん(一生ループ) */
		    message_set2( game_play, 0x0407f );	/* 強制メッセージセット */
		    break;
		}
	    }
	}
	break;

    case 5:		/* 最終メッセージ待ち */
	if ( message_check( &( game_play->message ) ) == 5 ) {	/* 原選択待ち？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */

		/* ゲームスタート */
		ON_HOLD_ROD( game_play );

/* 		if(KAZ(66) == 0) */
		    to_fishing_set(game_play); /* 構えセット */
		
		fishing_game_mode = 1;     /* 竿セット */
		
		head_check = 20;  /* 親父ぼうし判定なし時間 */
		
		this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
#if 0		
		lupy_increase( -20 ); /* 毎度どうも */
#endif
		/* プレイ回数セーブ */
		if((HI_SCORE(HS_FISH) & 0x00ff0000) < 0x00ff0000) { /* 255回未満 */
		    HI_SCORE(HS_FISH) += SAVE_PLAY_COUNT;
		}
	    }
	}
	break;




/* 追加 */
	
    case 10:		/* なんかよう？ */
	if(lure_with_head) { /* ボウシとられたあと？ */
	    if ( message_check( &( game_play->message ) ) == 4 ) {	/* 原選択待ち？ */
		if ( pad_on_check(game_play) ) {
		    message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */

		    switch ( game_play->message.sel_pnt ) {		/* 返して？ */
		    case 0:	/* 返す */
			message_set2( game_play, 0x40b2 );	/* おっ！すなおやん */
			bm_head_no = 1; /* ボウシ戻す */
			lure_with_head = 0;
			this->work[ BM_MES_MODE ] = 20;
			break;
		    case 1:	/* いやだ */
			this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
			break;
		    }
		}
	    }

#if 0
	    
	    if ( message_check( &( game_play->message ) ) == 0 ) {	/* 原選択待ち？ */
		bm_head_no = 1; /* ボウシ戻す */
		lure_with_head = 0;
		this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
	    }
#endif	    
	} else {
	    if ( message_check( &( game_play->message ) ) == 4 ) {	/* 原選択待ち？ */
		if ( pad_on_check(game_play) ) {
		    message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */

/* 		    if(KAZ(88)) { */
/* 			game_play->message.sel_pnt = 2; */
/* 		    } */
		    switch ( game_play->message.sel_pnt ) {		/* ？ */
		    case 0:	/* さかな見て */
			if(my_record == 0.0f) {
			    this->actor.talk_message = 0x408c; /* 魚ないで */
			    this->work[ BM_MES_MODE ] = 20;			/*  */
			} else {
			    if(my_fish_kind == FISH_KIND_BASS) {
				FishRangeForMessage = (u16)my_record;
				
				if((short)fish_record < (short)my_record) {
				    if(use_lure == LURE_TYPE_WORM) {
					this->actor.talk_message = 0x40b0; /* わーむで記録更新 */
				    } else {
					this->actor.talk_message = 0x4086; /* 記録更新！ */
				    }
				    this->work[ BM_MES_MODE ] = 11;			/*  */
				} else  {
				    this->actor.talk_message = 0x408b; /* 小さいで */
				    this->work[ BM_MES_MODE ] = 20;			/*  */
				}
			    } else { /* SNAKE_HEAD */
				this->actor.talk_message = 0x409b; /* これはめずらしい！ */
				this->work[ BM_MES_MODE ] = 11;			/*  */
			    }
			}
			message_set2( game_play, this->actor.talk_message );	/* 強制メッセージセット */
			break;
			
		    case 1:	/* なんかしゃべって */
			if(fishing_time > 36000 /* || KAZ(76) */) { /* 約３０分経過 */
/* 			    KAZ(76) = 0; */
			    fishing_time = 36000 - 6000; /* 後, ５分おきに言う */
			    message_set2( game_play, 0x04088 );	/* 強制メッセージセット */
			} else { /* 世間話 */
			    static u16 seken_mes_no[] = {
				0x4096, /* 濁ってるとき用 */
				
				0x408d,
				0x408e,
				0x408f,
				
 			     /* 大人用 */
				0x4094,
				0x4095,
				
			    };
			    
			    if(mad_water == 0) { /*にごってない日？ */
				if(seken_mes_ct == 0) { /* No.0 はなし */
				    seken_mes_ct ++;
				}
			    }

			    if(lure_type == LURE_TYPE_WORM &&
			       seken_mes_no[seken_mes_ct] == 0x408d) { /* ワ─ム持ってる？ */
				message_set2( game_play, 0x40af );	/* 強制メッセージセット */
			    } else {
				message_set2( game_play, seken_mes_no[seken_mes_ct] );	/* 強制メッセージセット */
			    }
			    
			    seken_mes_ct ++;
			    
			    if(AGE != 1 ) { /* 17才？ */
				if(seken_mes_ct > 5)
				    seken_mes_ct = 0;
			    } else {
				if(seken_mes_ct > 3)
				    seken_mes_ct = 0;
			    }
			}
			
			this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
			break;
			
		    case 2:  /* もうやめる */
			if(fish_catch_count == 0) { /* ぼうず？ */
			    message_set2( game_play, 0x4085 );	/* 強制メッセージセット */
			} else {
			    if(AGE == 1) { /* 5歳 */
				message_set2( game_play, 0x4092 );	/* 強制メッセージセット */
			    }
			}
			this->work[ BM_MES_MODE ] = 22;
			break;
		    }
		}
	    }
	}
	break;

    case 11:  /* 景品もらう */
	if ( message_check( &( game_play->message ) ) == 5 ||
	     message_check( &( game_play->message ) ) == 0
/*||
	     message_check( &( game_play->message ) ) == 6  */  ) {	/* メッセージ終り？ */
	    if ( pad_on_check(game_play) ) {
		int gi;
		
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */

		if(my_fish_kind == FISH_KIND_BASS) {
		    fish_record = my_record; /* 記録更新 */
		    my_record = 0.0f;
		    
		    if(AGE == 1) { /* 5歳 */
			float record;
			
			HI_SCORE(HS_FISH) &= 0xffffff00;
			HI_SCORE(HS_FISH) |= ((long)fish_record & 0x0000007f);

			record = (float)((HI_SCORE(HS_FISH) & 0x7f000000) >> 24); /* 大人の記録 */
			
			if(fish_record > record) { /* 大人の記録も更新 */
			    HI_SCORE(HS_FISH) &= 0x00ffffff;
			    HI_SCORE(HS_FISH) |= (((long)fish_record & 0x007f) << 24);
			    
			    if(use_lure ==  LURE_TYPE_WORM) { /* ワ─ムでつってしもうた。 */
				HI_SCORE(HS_FISH) |= SAVE_USE_WORM_A;
			    }
			}
			
			if(use_lure ==  LURE_TYPE_WORM) { /* ワ─ムでつってしもうた。 */
			    HI_SCORE(HS_FISH) |= SAVE_USE_WORM_C;
			    this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
			    break;  /* 景品なし */
			}
		    } else { /* 大人 */
			HI_SCORE(HS_FISH) &= 0x00ffffff;
			HI_SCORE(HS_FISH) |= (((long)fish_record & 0x007f) << 24);
			if(use_lure ==  LURE_TYPE_WORM) { /* ワ─ムでつってしもうた。 */
			    HI_SCORE(HS_FISH) |= SAVE_USE_WORM_A;
			    this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
			    break;  /* 景品なし */
			}
		    }
		    
		    /* 基本もらえる景品セット */
		    if(fish_record >= 60.0f) { /* 60オーバー？ */
			gi = GET_ITEM_BIG_RUPPE;
		    } else if(fish_record >= 50.0f) { /* 50オーバー？ */
			gi = GET_ITEM_RUPPE_RED;
		    } else if(fish_record >= 40.0f) { /* 40オーバー？ */
			gi = GET_ITEM_RUPPE_BLUE;
		    } else {                          /* 30オーバー？ */
			gi = GET_ITEM_20RUPPE;
		    }

		    /* 特別もらえる景品セット */
		    if(AGE == 1) { /* 5歳 */
			if(fish_record >= 50.0f) { /* 50オーバー？ */
			    if(!(HI_SCORE(HS_FISH) & SAVE_HEART_GET)) { /* ハートもらってない？ */
				HI_SCORE(HS_FISH) |= SAVE_HEART_GET; /* もらおう */
				
 				gi = GET_ITEM_HEART_PARTS; 
/* 				gi = GET_ITEM_BIN_NUL; */
				/* ワ─ムどっかに落そう */
				worm_set_P = 1 + (u8)rnd_f(3.999f); /* 1 ~ 3 */
			    }
			}
		    } else {                        /* 17才 */
			if(fish_record >= 60.0f) { /* 60オーバー？ */
			    if(!(HI_SCORE(HS_FISH) & SAVE_UROKO_GET)) { /* ウロコもらってない？ */
				HI_SCORE(HS_FISH) |= SAVE_UROKO_GET; /* もらおう */
				
				gi = GET_ITEM_GOLD_SCALE;
				/* ワ─ムどっかに落そう */
				worm_set_P = 1 + (u8)rnd_f(3.999f); /* 1 ~ 3 */
			    }
			}
		    }
		} else {  /* 外道用景品 */
		    my_record = 0.0f;
		    gi = GET_ITEM_BIG_RUPPE;
		}

		/* 景品もらおう */
		this->actor.mother = NULL;		/* 持ち上げまえに親いらね */
		
		Actor_carry_request_set2( &this->actor, game_play,
					  gi,			/* 金のウロコ */
					  2000.0f,		/* この範囲はメッセージ受諾範囲より大 */
					  1000.0f );
		
		this->work[ BM_MES_MODE ] = 23;			/* 持ち上げ要求チェック原 */
	    }
	}
	break;
	
    case 20: /* まだやんの？ */
	if ( message_check( &( game_play->message ) ) == 5 /* ||
	     message_check( &( game_play->message ) ) == 6 */) {	/* メッセージ終り？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
#if 0	    
		message_set2( game_play, 0x408a );	/* 強制メッセージセット */
		this->work[ BM_MES_MODE ] = 21;			/* 戻る原 */
#endif		
		this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
	    }
	}
	break;
	
    case 21:
	if ( message_check( &( game_play->message ) ) == 4 ) {	/* 原選択待ち？ */
	    if ( pad_on_check(game_play) ) {
		message_close(game_play);			/* メッセージウィンドウ閉じ原、る？  */
		
		switch ( game_play->message.sel_pnt ) {		/* ？ */
		case 0:	/* まだやる */
		    this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
		    break;

		case 1:	/* もうやめる */
		    if(fish_catch_count == 0) { /* ぼうず？ */
			message_set2( game_play, 0x4085 );	/* 強制メッセージセット */
		    } else {
			if(AGE == 1) { /* 5歳 */
			    message_set2( game_play, 0x4092 );	/* 強制メッセージセット */
			}
		    }
		    this->work[ BM_MES_MODE ] = 22;
		    break;
		}
	    }
	}
	break;
	
    case 22:
	if ( message_check( &( game_play->message ) ) == 0 ) {	/* メッセージ終り？ */
	    this->work[ BM_MES_MODE ] = 0;
#if 0		    
	    if(AGE != 1) { /* 17歳 */
		bm_head_no = 1; /* ボウシ戻す */
		lure_with_head = 0;
	    }
#endif
	    
#if 01
	    if(lure_with_head) {
		bm_head_no = 1; /* ボウシ戻す */
		lure_with_head = 0;
	    }
	    fishing_game_mode = 0; /* 終り */
	    OFF_HOLD_ROD( game_play );
/*	    pla->fishing_mode = 0;*/
#endif	    
	}
	break;

    case 23:			/* 持ち上げ要求チェック原 */
	rod_disp = 0; /* 竿 ＆ ルアー表示無し */
	
	if ( Actor_carry_check( &this->actor, game_play ) ) {
	    this->work[ BM_MES_MODE ] = 24;			/* 終了待ち */
	}
	else {
	    Actor_carry_request_set2( &this->actor, game_play,
				      GET_ITEM_GOLD_SCALE,		/* 金の鱗 */
				      2000.0f,		/* この範囲はメッセージ受諾範囲より大 */
				      1000.0f );
	}
	break;

    case 24:			/* 終了待ち */
	rod_disp = 0; /* 竿 ＆ ルアー表示無し */
	
	if ( message_check( &( game_play->message ) ) == 6 ) {
	    if ( pad_on_check(game_play) ) {
//		message_set2( game_play, 0x408a );	/* 強制メッセージセット */
		
/* 		PRINTF( "\033[32m☆☆☆☆☆ 正常終了 ☆☆☆☆☆ \n\033[m" ); */

		if(my_fish_kind == FISH_KIND_BASS) {
#if 0		    
		    message_set( game_play, 0x408a, NULL );	/* 強制メッセージセット */
		    this->work[ BM_MES_MODE ] = 21;			/* 戻る原 */
#endif		    
		    this->work[ BM_MES_MODE ] = 0;			/* 戻る原 */
		} else {
		    message_set( game_play, 0x409c, NULL );	/* 逃がすで */
		    this->work[ BM_MES_MODE ] = 20;			/* 戻る原 */
		}
	    }
	}
	break;
	
    }
}

/************************************************************************
 *	メッセージ 終了チェック		message_check(z_message.c)	*
 *									*
 *	Ｒｅｔｒｕｎ値	０：Ｎｏｔｈｉｎｇメッセージ			*
 *			１：次のメッセージ有り				*
 *			２：メッセージ終了				*
 *			３：メッセージ出力中				*
 *			４：選択					*
 *			５：敵側制御					*
 *			６：メッセージ出力終了				*
 *			７：オカリナ自動演奏終了			*
 *			８：オカリナ演奏正解				*
 *			９：オカリナ演奏誤り				*
 *		      １０：改行待ち					*
 ************************************************************************/
