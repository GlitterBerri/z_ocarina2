/* $Id: message_change.c,v 1.1 2003/03/14 03:39:08 tong Exp $ */	
/* $Log: message_change.c,v $
/* Revision 1.1  2003/03/14 03:39:08  tong
/* asset files copied from old tree to new tree.
/*
/* Revision 1.1  2003/02/12 19:07:42  tong
/* message_change source.
/*
 * Revision 1.3  1997/08/29  05:00:15  soejima
 * 大変更（半角スペース使用可）
 * Revision 1.2  1997/04/09  04:37:39  soejima
 * EGWORD Version-UP(Version 7.0)
 * Revision 1.1  1997/01/28  10:53:33  soejima
 * $Log追加
 * */

/****************************************************************
 *	ＭＡＣ［ＥＧＷＯＲＤ］入力テキスト ──＞ ６４変換	*
 *								*
 *	ゼルダ６４ メッセージ変換プログラム			*
 *	【漢字ＲＯＭ対応・バージョン】				*
 *								*
 *					97/01/28（火）PM 04:20	*
 *  cc message_change.c -o message_change			*
 ****************************************************************/
#include <stdio.h>
#include <time.h>


/*======================================*
 *	文字変換用 変数			*
 *======================================*/
#define	unshort		unsigned short
#define	unchar		unsigned char

#define TO_SJIS(x)  ( (x) < (0x000A) ? (x + 0x824F) : (x - 0x000A + 0x8260) ) 
#define TO_ASCII(x) ( (x) < (0x8260) ? (x - 0x824F) : (x - 0x824F - 0x0007) )


char	File_Table[]="message.tbl";			/* 読み込みファイルＴＡＢＬＥ */
char	Write_File[]="zld64_msg_data.c";		/* データ書き込みファイル */
char	Table_File[]="zld64_msg_data.tbl";		/* テーブルデータ書き込みファイル */
char	Header_File[]="zld64_msg_data.h";		/* ＨＥＡＤＥＲ書き込みファイル */

FILE 	*rfp;			/* データ読み込み ポインタ */
FILE 	*rfpi;			/* 情報読み込み ポインタ */
FILE 	*wfp;			/* データ書き込み ポインタ */
FILE 	*wfpt;			/* ｘｘｘ.ｔｂｌ 書き込み ポインタ */
FILE 	*wfph;			/* ｘｘｘ.ｈ     書き込み ポインタ */

char 	file_name[200][1000];	/* テーブル登録Ｆｉｌｅ */
unshort	file_su;		/* テーブル登録Ｆｉｌｅ数 */
unshort	file_no;		/* テーブル登録Ｆｉｌｅポインタ */
unshort dt_ct;			/* Ｆｉｌｅ内テキスト カウンタ */
char	lf;			/* 改行制御 */

int	text_count;		/* テキスト数 */

int	inf_data_adr;		/* メッセージ情報先頭アドレス */
int	inf_data_ct;		/* メッセージ情報数 */

unshort	temp1_buf[200][1000];	/* 情報１ */
unshort	temp2_buf[2000];	/* 情報２ */
unshort	msdt_buf[0x200];	/* 複数データ読み込みバッファ（ｓｈｏｒｔ型） */
unchar 	msg_no[8];		/* メッセージＮｏ読み込みバッファ（ｃｈａｒ型） */

unshort	tp1, tp2;

unshort	euc[4];			/* ＳＪＩＳ→ＥＵＣ変換バッファ */

char 	*dlt;


/********************************************************************************/
/*------------ ＭＡＣデータ ------------*/
#define D_HEADER	0x816F	/* データ開始            （｛）          */
#define D_SYURYOU       0x8170	/* データＥＮＤ          （｝）          */
#define D_KUGIRI	0x8146	/* データ区切り          （：）          */
#define Z_KEYWAIT       0x81A5	/* キー待ち :改ページ    （▼）          */
#define Z_BLANK		0x86C7	/* 空き                  （→【２桁】）  */
#define Z_NEXTMSG	0x81CB	/* ＮＥＸＴメッセージ番号（⇒【４桁】）  */
#define Z_START         0x8189	/* 一括表示開始          （♂）          */
#define Z_STOP          0x818A	/* 一括表示終了          （♀）          */
#define Z_DISPSTOP      0x86C8	/* 表示停止              （←）          */
#define Z_ENEMY         0x819F	/* 敵側制御コード        （◆）          */
#define Z_TIMER         0x81A3	/* ＴＩＭＥＲ 		 （▲【２桁】）  */
#define Z_PAUSE         0x81A4	/* キー待ち              （▽）          */
#define Z_TIMER_END     0x819E	/* タイマー付終了コード  （◇）          */
#define Z_NAME          0x874F	/* プレイヤー登録名前    （名）          */
#define Z_OCARINA       0x81F0	/* オカリナ              （Ａ）          */
#define Z_BGM	        0x81F4	/* サウンド（ＢＧＭ）    （♪【４桁】）  */
#define Z_SE            0x81F3	/* サウンド（ＳＥ）      （♭【４桁】）  */
#define Z_DPITEM	0x819A	/* アイテム              （★【３桁】）  */
#define Z_SPEED         0x86C9	/* 文字表示スピード      （↑【２桁】）  */
#define Z_TEXTURE       0x86B3	/* １枚テクスチャ        （.Ｔ.【６桁】）*/
#define Z_EVENT_0	0x8791	/* ＥＶＥＮＴタイマー大  （大）          */
#define Z_EVENT_1	0x8792	/* ＥＶＥＮＴタイマー小  （小）          */
#define Z_NONONO	0x8199	/* 早送り禁止            （☆）          */
#define	Z_SENTAKU_2	0x81BC	/* ２択                  （⊂）          */
#define Z_SENTAKU_3	0x81B8	/* ３択                  （∈）          */
#define KAIGYO          0x0A	/* 改行 */
#define CHANGE          0x0B	/* 文字色切替 */
#define SPACE           0x8140	/* スペース */

/********************************************************************************/
/*=======================================================
  =	ＳＪＩＳ →（ＪＩＳ）→ ＥＵＣ 変換		=
  =	（＋１２８を外すとＪＩＳ変換になる）		=
  =======================================================*/
static void
sjis2euc( unchar c1, unchar c2 )
{
    int		adjust = c2 < 159;
    int		rowOffset = c1 < 160 ? 112 : 176;
    int		cellOffset = adjust ? ( c2 > 127 ? 32 : 31 ) : 126;

    euc[0] =  (((( c1 - rowOffset ) << 1) - adjust) + 128) << 8;
    euc[0] |= (c2 - cellOffset) + 128;
    euc[1] =  NULL;
}

/*---------------------------------------
  -	メッセージＮｏ．ＧＥＴ		-
  ---------------------------------------*/
static void
message_number_get( void )
{
    if ( msdt_buf[5] != D_KUGIRI /*（：）*/ ) {
	/* メッセージＮＯ．エラー */
	printf("'%s' Message_No. ERROR\n", file_name[file_no]);
	exit(1);
    }

    /* キャスト演算 */
    msg_no[0] = 0x30/* 0 */;
    msg_no[1] = 0x78/* x */;
    msg_no[2] = (char)( msdt_buf[1] > 0x825F ? ( msdt_buf[1] > 0x8280 ? (msdt_buf[1]-0x8281)+0x61 : (msdt_buf[1]-0x8260)+0x41 ) : (msdt_buf[1]-0x824F)+0x30 );
    msg_no[3] = (char)( msdt_buf[2] > 0x825F ? ( msdt_buf[2] > 0x8280 ? (msdt_buf[2]-0x8281)+0x61 : (msdt_buf[2]-0x8260)+0x41 ) : (msdt_buf[2]-0x824F)+0x30 );
    msg_no[4] = (char)( msdt_buf[3] > 0x825F ? ( msdt_buf[3] > 0x8280 ? (msdt_buf[3]-0x8281)+0x61 : (msdt_buf[3]-0x8260)+0x41 ) : (msdt_buf[3]-0x824F)+0x30 );
    msg_no[5] = (char)( msdt_buf[4] > 0x825F ? ( msdt_buf[4] > 0x8280 ? (msdt_buf[4]-0x8281)+0x61 : (msdt_buf[4]-0x8260)+0x41 ) : (msdt_buf[4]-0x824F)+0x30 );
    msg_no[6] = 0x2c/* , */;
    msg_no[7] = 0x20/*   */;

    /* メッセージＮＯ．書き込み */
    fprintf(wfpt,"\t{ ");
    if( (fwrite(&msg_no, sizeof(char), 0x8, wfpt)) != 0x8 ){
	printf("[zld64_msg_data.tbl]  Message_No. Write ERROR!!\n");
	exit(1);
    }
    printf("Message_No.=%c%c%c%c  :  ",msg_no[2],msg_no[3],msg_no[4],msg_no[5]);
}

/*---------------------------------------
  -	Ｔｙｐｅ データ ＧＥＴ		-
  ---------------------------------------*/
static void
message_type_get( void )
{
    unchar 	msg_buf[10];		/* データ読み込みバッファ（ｃｈａｒ型） */


    if ( msdt_buf[8] != D_KUGIRI /*（：）*/ ) {
	printf("'%s' HEADER DATA ERROR\n", file_name[file_no]);
	exit(1);
    }

    /* キャスト演算 */
    msg_buf[0] = 0x30/* 0 */;
    msg_buf[1] = 0x78/* x */;
    msg_buf[2] = (char)( msdt_buf[6] > 0x825F ? ( msdt_buf[6] > 0x8280 ? (msdt_buf[6]-0x8281)+0x61 : (msdt_buf[6]-0x8260)+0x41 ) : (msdt_buf[6]-0x824F)+0x30 );
    msg_buf[3] = (char)( msdt_buf[7] > 0x825F ? ( msdt_buf[7] > 0x8280 ? (msdt_buf[7]-0x8281)+0x61 : (msdt_buf[7]-0x8260)+0x41 ) : (msdt_buf[7]-0x824F)+0x30 );
    msg_buf[4] = 0x2c/* , */;
    msg_buf[5] = 0x20/*   */;


    /* ファイル 書き込み */
    if( (fwrite(&msg_buf, sizeof(char), 0x6, wfpt)) != 0x6 ) {
	printf("zld64_msg_data.tbl HEADER Write Error\n");
	exit(1);
    }
    printf("Type=%c%c\n",msg_buf[0], msg_buf[1] );
}

/*---------------------------------------
  -	改行チェック			-
  ---------------------------------------*/
static void
return_code_check( void )
{
    if ( lf != 0 ) {
	fprintf(wfp, "\n\t");
	lf = 0;
    }
}
/*---------------------------------------
  -	改行チェック			-
  ---------------------------------------*/
static void
return_code_check1( void )
{
    if ( lf != 0 ) {
	fprintf(wfp, "\n");
	lf = 0;
    }
}


/****************************************************************
 *	Ｆｉｌｅ Ｏｐｅｎ処理					*
 ****************************************************************/
static void
file_open( void )
{
    /*
     * 読み込みＴＡＢＬＥ ＯＰＥＮ
     */
    printf( "********************************************************\n");
    printf( "*******    S T A R T  :  %s",dlt);
    printf( "********************************************************\n");
    if ( ( rfp = fopen( File_Table, "r" ) ) == NULL ) {
	printf( "[%s] File_Table Open Error!!!\n", File_Table );
	exit(1);
    }
    /* テーブル内のファイル数を求める */
    file_su = 0;
    while ( fscanf( rfp, "%s\n", &file_name[file_su] ) != EOF ) file_su++;
    if ( !file_su ) {
	/* ファイル無し！！ ──＞ 終了 */
	printf( "%s TABLE_File Nothing!!!\n", File_Table );
	exit(1);
    } else /* ファイル数表示 */
	printf( "*** OPEN File_Table = %s,   FILE COUNT = %d\n", File_Table, file_su );
    fclose( rfp );
    
    /*
     * データ書き込みファイル Ｏｐｅｎ
     */
    if( ( wfp = fopen( Write_File, "w" ) ) == NULL ) {
	printf( "[%s] Write_File OPEN ERROR!!\n", Write_File );
	exit(1);
    }
    fprintf( wfp, "/*\n * 作成日 : %s */\n", dlt );
    fprintf( wfp, "/*------------ ＣＯＤＥ ＤＡＴＡ ------------*/\n" );
    fprintf( wfp, "#define D_SYURYOU            0x8170	/* データＥＮＤ （｝）*/\n" );
    fprintf( wfp, "#define Z_KEYWAIT            0x81A5	/* キー待ち （▼）*/\n" );
    fprintf( wfp, "#define Z_BLANK              0x86C7	/* 空き（→【２桁】）*/\n" );
    fprintf( wfp, "#define Z_NEXTMSG            0x81CB	/* ＮＥＸＴメッセージ番号（⇒【４桁】）*/\n" );
    fprintf( wfp, "#define Z_START              0x8189	/* 一括表示開始 （♂）*/\n" );
    fprintf( wfp, "#define Z_STOP               0x818A	/* 一括表示終了 （♀）*/\n" );
    fprintf( wfp, "#define Z_DISPSTOP           0x86C8	/* 表示停止 （←）*/\n" );
    fprintf( wfp, "#define Z_ENEMY              0x819F	/* 敵側制御コード （◆）*/\n" );
    fprintf( wfp, "#define Z_TIMER              0x81A3	/* ＴＩＭＥＲ（▲【２桁】）*/\n" );
    fprintf( wfp, "#define Z_PAUSE              0x81A4	/* キー待ち （▽）*/\n" );
    fprintf( wfp, "#define Z_TIMER_END          0x819E	/* タイマー付終了コード  （◇）*/\n" );
    fprintf( wfp, "#define Z_NAME               0x874F	/* プレイヤー登録名前 （）*/\n" );
    fprintf( wfp, "#define Z_OCARINA            0x81F0	/* オカリナ （Ａ）*/\n" );
    fprintf( wfp, "#define Z_BGM                0x81F4	/* サウンド（ＢＧＭ）（♪【４桁】*/\n" );
    fprintf( wfp, "#define Z_SE                 0x81F3	/* サウンド（ＳＥ）（♭【４桁】）*/\n" );
    fprintf( wfp, "#define Z_DPITEM             0x819A	/* アイテム（★【３桁】）*/\n" );
    fprintf( wfp, "#define Z_SPEED              0x86C9	/* 文字表示スピード（↑【２桁】）*/\n" );
    fprintf( wfp, "#define Z_TEXTURE            0x86B3	/* １枚テクスチャ（.Ｔ.【６桁】）*/\n" );
    fprintf( wfp, "#define Z_EVENT_0		0x8791	/* ＥＶＥＮＴタイマー大  （大）*/\n" );
    fprintf( wfp, "#define Z_EVENT_1		0x8792	/* ＥＶＥＮＴタイマー小  （小）*/\n" );
    fprintf( wfp, "#define Z_NONONO	        0x8199	/* 早送り禁止            （☆）*/\n" );
    fprintf( wfp, "#define Z_SENTAKU_2          0x81BC	/* ２択 */\n" );
    fprintf( wfp, "#define Z_SENTAKU_3          0x81B8	/* ３択 */\n" );
    fprintf( wfp, "#define KAIGYO               0x0A	/* 改行 */\n" );
    fprintf( wfp, "#define CHANGE               0x0B	/* 文字色切替 */\n" );
    fprintf( wfp, "#define SPACE                0x8140	/* スペース */\n\n" );

    /*
     * テーブルデータ書き込みファイル Ｏｐｅｎ
     */
    if( ( wfpt = fopen( Table_File, "w" ) ) == NULL ) {
	printf( "[%s]  Write_Table OPEN ERROR!!\n", Table_File );
	exit(1);
    }
    fprintf( wfpt, "/*\n * 作成日 : %s */\nstatic\nMSG_T message_tbl[] = {\n", dlt );

    /*
     * ＨＥＡＤＥＲ書き込みファイル Ｏｐｅｎ
     */
    if( ( wfph = fopen( Header_File, "w" ) ) == NULL ) {
	printf( "[%s] Write_HEADER_FILE OPEN ERROR!!\n", Header_File );
	exit(1);
    }
    fprintf( wfph, "  ==    作成日 : %s ", dlt );
    fprintf( wfph, " ===============================================================*/\n");
    fprintf( wfph, "/*------------ ＣＯＤＥ ＤＡＴＡ ------------*/\n" );
    fprintf( wfph, "#define D_SYURYOU            0x8170	/* データＥＮＤ （｝）*/\n" );
    fprintf( wfph, "#define Z_KEYWAIT            0x81A5	/* キー待ち （▼）*/\n" );
    fprintf( wfph, "#define Z_BLANK              0x86C7	/* 空き（→【２桁】）*/\n" );
    fprintf( wfph, "#define Z_NEXTMSG            0x81CB	/* ＮＥＸＴメッセージ番号（⇒【４桁】）*/\n" );
    fprintf( wfph, "#define Z_START              0x8189	/* 一括表示開始 （♂）*/\n" );
    fprintf( wfph, "#define Z_STOP               0x818A	/* 一括表示終了 （♀）*/\n" );
    fprintf( wfph, "#define Z_DISPSTOP           0x86C8	/* 表示停止 （←）*/\n" );
    fprintf( wfph, "#define Z_ENEMY              0x819F	/* 敵側制御コード （◆）*/\n" );
    fprintf( wfph, "#define Z_TIMER              0x81A3	/* ＴＩＭＥＲ（▲【２桁】）*/\n" );
    fprintf( wfph, "#define Z_PAUSE              0x81A4	/* キー待ち （▽）*/\n" );
    fprintf( wfph, "#define Z_TIMER_END          0x819E	/* タイマー付終了コード  （◇）*/\n" );
    fprintf( wfph, "#define Z_NAME               0x874F	/* プレイヤー登録名前 （）*/\n" );
    fprintf( wfph, "#define Z_OCARINA            0x81F0	/* オカリナ （Ａ）*/\n" );
    fprintf( wfph, "#define Z_BGM                0x81F4	/* サウンド（ＢＧＭ）（♪【４桁】*/\n" );
    fprintf( wfph, "#define Z_SE                 0x81F3	/* サウンド（ＳＥ）（♭【４桁】）*/\n" );
    fprintf( wfph, "#define Z_DPITEM             0x819A	/* アイテム（★【３桁】）*/\n" );
    fprintf( wfph, "#define Z_SPEED              0x86C9	/* 文字表示スピード（↑【２桁】）*/\n" );
    fprintf( wfph, "#define Z_TEXTURE            0x86B3	/* １枚テクスチャ（.Ｔ.【６桁】）*/\n" );
    fprintf( wfph, "#define Z_EVENT_0		 0x8791	/* ＥＶＥＮＴタイマー大  （大）*/\n" );
    fprintf( wfph, "#define Z_EVENT_1		 0x8792	/* ＥＶＥＮＴタイマー小  （小）*/\n" );
    fprintf( wfph, "#define Z_NONONO	         0x8199	/* 早送り禁止            （☆）*/\n" );
    fprintf( wfph, "#define Z_SENTAKU_2          0x81BC	/* ２択 */\n" );
    fprintf( wfph, "#define Z_SENTAKU_3          0x81B8	/* ３択 */\n" );
    fprintf( wfph, "#define KAIGYO               0x0A	/* 改行 */\n" );
    fprintf( wfph, "#define CHANGE               0x0B	/* 文字色切替 */\n" );
    fprintf( wfph, "#define SPACE                0x8140	/* スペース */\n\n" );
}


/****************************************************************
 *	基本データ読み込み処理					*
 ****************************************************************/
static void
basic_data_read( void )
{
    int		text_start_adr;		/* メッセージＤＡＴＡ先頭アドレス */
    int		text_total_ct;		/* メッセージ総文字数 */
    unchar 	title_buf[100];		/* データ読み込みバッファ（ｃｈａｒ型） */
    short	i, cfg;


    /*
     * ＲＥＡＤ Ｆｉｌｅ Ｏｐｅｎ
     */
    if( (rfp = fopen(file_name[file_no],"r")) == NULL ) {
	printf("%s 999 Read File Open Error!!\n", file_name[file_no]);
	exit(1);
    }
    if( (rfpi = fopen(file_name[file_no],"r")) == NULL ) {
	printf("%s 999 Read File Open Error!!\n", file_name[file_no]);
	exit(1);
    }
    
    tp1 = 0;
    /*
     * タイトル位置検索
     */
    if ( (fread(&title_buf, sizeof(unchar), 0x70, rfp)) != 0x70 ) {
	printf("'%s' READ OPEN ERROR1111!!\n", file_name);
	exit(1);
    }


    /* メッセージ総文字数Ｇｅｔ【text_total_ct】 */
    cfg = 1;
    i = -1;
    while ( cfg ) {
	if ( title_buf[++i] == 0x54/* T */ ) {
	    if ( title_buf[++i] == 0x45/* E */ ) {
		if ( title_buf[++i] == 0x58/* X */ ) {
		    if ( title_buf[++i] == 0x54/* T */ ) {
			/* メッセージＤＡＴＡ先頭アドレス */
			text_start_adr = ((int)title_buf[i+1]<<24 | (int)title_buf[i+2]<<16 | (int)title_buf[i+3]<<8 | (int)title_buf[i+4]);
			/* メッセージ総文字数 */
			text_total_ct = ((int)title_buf[i+5]<<24 | (int)title_buf[i+6]<<16 | (int)title_buf[i+7]<<8 | (int)title_buf[i+8]);
			cfg = 0;
		    }
		}
	    }
	}
    }
    printf("text_total_ct=%d(%x : %2x,%2x,%2x,%2x) text_start_adr=%x\n",text_total_ct, i+5, title_buf[i+5], title_buf[i+6], title_buf[i+7], title_buf[i+8], text_start_adr );


    /* メッセージ情報数Ｇｅｔ【inf_data_adr, inf_data_ct】 */
    cfg = 1;
    while ( cfg ) {
	if ( title_buf[++i] == 0x41/* A */ ) {
	    if ( title_buf[++i] == 0x54/* T */ ) {
		if ( title_buf[++i] == 0x52/* R */ ) {
		    if ( title_buf[++i] == 0x42/* B */ ) {
			/* メッセージ情報先頭アドレス */
			inf_data_adr = ((int)title_buf[i+1]<<24 | (int)title_buf[i+2]<<16 | (int)title_buf[i+3]<<8 | (int)title_buf[i+4]);
			/* メッセージ情報数 */
			inf_data_ct = ((int)title_buf[i+5]<<24 | (int)title_buf[i+6]<<16 | (int)title_buf[i+7]<<8 | (int)title_buf[i+8]);
			cfg = 0;
		    }
		}
	    }
	}
    }
    printf("inf_data_ct=%d(%x : %2x,%2x,%2x,%2x)\n",inf_data_ct, i+5, title_buf[i+5], title_buf[i+6], title_buf[i+7], title_buf[i+8] );


    /* メッセージＤＡＴＡ先頭位置へ移動 */
    fseek(rfp, text_start_adr, SEEK_SET);

    /* 情報先頭移動 */
    fseek(rfpi, inf_data_adr, SEEK_SET);
}


/****************************************************************
 *	データＨＥＡＤＥＲ処理					*
 ****************************************************************/
static void
header_proc( void )
{
    int		i, r_ct;


    /* データＨＥＡＤＥＲ数読み込み */
    if ( (i=fread(&r_ct, sizeof(int), 0x1, rfp)) != 0x1 ) {
	printf("-'%s'- (%x)READ ERROR!!!!\n", file_name[file_no],i);
	exit(1);
    }
    /* データＨＥＡＤＥＲ読み込み（データＨＥＡＤＥＲ数分） */
    if ( (i=fread(&msdt_buf, sizeof(unshort), (r_ct/2), rfp)) != (r_ct/2) ) {
	printf("--'%s'-- [%x]READ ERROR!!!!\n", file_name[file_no],i);
	exit(1);
    }
    printf("msdt_buf[%2x]=",r_ct);
    for ( i = 0; i < (r_ct/2); i++ ) {
	/* ＳＪＩＳ → ＥＵＣ */
	sjis2euc( msdt_buf[i] >> 8, msdt_buf[i] & 0x00ff );
	printf("%s ", euc);
    }
    printf("\n");

    if ( msdt_buf[0] == D_HEADER /*（｛）*/) {
	/* メッセージＮｏ．読み込み */
	message_number_get();

	/* メッセージＴＹＰＥ 読み込み */
	message_type_get();

	/* "ｘｘｘ.ｔｂｌ" メッセージＮｏ．書き込み */
	fprintf(wfpt, "%s_%c%c%c%c },\t\t/* %6d */\n", file_name[file_no], msg_no[2], msg_no[3], msg_no[4], msg_no[5], text_count );
	/* "ｘｘｘ.ｈ" メッセージＮｏ．書き込み */
	fprintf(wfph, "extern unsigned short %s_%c%c%c%c[];\n",file_name[file_no], msg_no[2], msg_no[3], msg_no[4], msg_no[5] );
    } else {
	printf("DATA HEADER ERROR 123!! :::  msdt_buf[0] = %x \n", msdt_buf[0]);
	exit(1);
    }
}


/****************************************************************
 *	メッセージ データ（仮書き込みバッファ１にセット）	*
 *	┏━┯━┳━┯━┯━━━━━━━━━┯━┯━┓		*
 *	┃ 個数 ┃       データ（偶数バイト）       ┃		*
 *	┗━┷━┻━┷━┷━━━━━━━━━┷━┷━┛		*
 * 	  ※半角スペースＯＫ！！（必ず偶数個）			*
 ****************************************************************/
static void
msg_data_get( void )
{
    int		i, j, r_ct;
    unshort	low, high;


    while ( 1 ) {
	if ( (fread(&r_ct, sizeof(int), 0x1, rfp)) != 0x1 ) {
	    printf( "'%s' READ ERROR!!  r_ct=%x\n", file_name[file_no], r_ct );
	    exit(1);
	}
	fseek( rfp, -2, SEEK_CUR );
	printf("r_ct=%x  ",r_ct);
	/* メッセージ データ読み込み（メッセージ データ数分） */
	if ( (i=fread(&msdt_buf, sizeof(unshort), (r_ct/2)+1, rfp)) != (r_ct/2)+1 ) {
	    printf("'%s' (%x)READ ERROR!!!!\n", file_name[file_no],i);
	    exit(1);
	}
	if ( msdt_buf[1] == D_HEADER /*（｛）*/ ) {
	    printf("\n");
	    temp1_buf[dt_ct][0] = 0;
	    i = r_ct + 4;
	    fseek( rfp, -i, SEEK_CUR );
	    break;
	} else {
	    printf("temp1_buf[%x] = ",dt_ct);
	    for ( i = j = 0; i < (r_ct/2)+1; i++ ) {
		temp1_buf[dt_ct][j] = msdt_buf[i];
		if ( msdt_buf[i] > 0x8000 ) {
		    /* ＳＪＩＳ → ＥＵＣ */
		    sjis2euc( temp1_buf[dt_ct][j] >> 8, temp1_buf[dt_ct][j] & 0x00ff );
		    printf("%s ", euc);
		} else {
		    if ( !j ) printf("[%04x] ",msdt_buf[i]);
		    else      printf("<%04x> ",msdt_buf[i]);
		}
		j++;
		if ( j > 1000 ) {
		    printf("--temp1_buf-- SIZE OVER!!!\n");
		    exit(1);
		}
	    }
	    printf("\n");
	    dt_ct++;
	    temp1_buf[dt_ct][0] = 0;
	    if ( msdt_buf[i-1] == D_SYURYOU ) break;
	}
    }
}


/************************************************************************
 *	出力文字情報（仮書き込みバッファ２にセット）			*
 *┏━┯━┳━┯━┳━┯━┳━┯━┳━┯━┳━┯━┳━┯━┳━┯━┓	*
 *┃ 個数 ┃      ┃      ┃サイズ┃      ┃      ┃  色  ┃      ┃	*
 *┗━┷━┻━┷━┻━┷━┻━┷━┻━┷━┻━┷━┻━┷━┻━┷━┛	*
 *		 	    ↓      ↓      ↓				*
 *			┏━┯━┳━┯━┳━┯━┓			*
 *			┃ 個数 ┃サイズ┃  色  ┃			*
 *			┗━┷━┻━┷━┻━┷━┛			*
 * サイズ（１６進表示：基本１２ドット）					*
 * 色（０：黒, １：赤, ２：緑, ３：水色, ４：青, ５：ピンク, ６：黄色） *
 ************************************************************************/
static void
msg_inf_get( void )
{
    int 	r_ct, data_ct, ct;
    unshort	i;
    
    
    data_ct = tp1 = tp2 = 0;
    while ( 1 ) {
	if ( (fread(&r_ct, sizeof(int), 0x1, rfpi)) != 0x1 ) {
	    printf("'%s' INFORMATION COUNT ERROR!!\n", file_name[file_no]);
	    exit(1);
	}
	printf("r_ct=%x\n",r_ct);
	if ( (fread(&msdt_buf, sizeof(unshort), (r_ct/2), rfpi)) != (r_ct/2) ) {
	    printf("'%s' INFORMATION DATA ERROR!!\n", file_name[file_no]);
	    exit(1);
	}
	for ( i = ct = 0; i < (r_ct/2); i += 0x8 ) ct += msdt_buf[0+i];
	if ( !ct ) break;
	printf("ct=%x, temp1_buf=%x\n",ct, temp1_buf[tp1][0] );
	if ( ct == temp1_buf[tp1][0] ) {
	    for ( i = 0; i < (r_ct/2); ) {
		printf("[%02x]=%04x, ",i, msdt_buf[i]);
		i++;
		if ( !(i & 0x0007) ) printf("\n");
	    }
	    for ( i = 0; i < (r_ct/2); i += 0x8 ) {
		/* 個数 */
		temp2_buf[tp2] = msdt_buf[0+i];
		/* 文字サイズ */
		temp2_buf[tp2+2] = TO_SJIS( (msdt_buf[3+i] >> 8) );
		/* 文字カラー */
		temp2_buf[tp2+4] = (msdt_buf[6+i] + 0x824F);
		printf("temp2_buf[%02x]=%04x,%04x,%04x(%04x,%04x,%04x)\n",
		       tp2,
		       temp2_buf[tp2],temp2_buf[tp2+2],temp2_buf[tp2+4],
		       msdt_buf[0+i], msdt_buf[3+i],   msdt_buf[6+i]);
		tp2 += 6;
		temp2_buf[tp2] = 0;
		if ( tp2 > 2000 ) {
		    printf("--temp2_buf-- SIZE OVER!!!\n");
		    exit(1);
		}
	    }
	    tp1++;
	} else {
	    if ( !temp1_buf[tp1][0] ) break;
	}
	data_ct += (r_ct + 4);
	printf("inf_data_ct=%x  data_ct=%x\n",inf_data_ct,data_ct);
	if ( inf_data_ct == data_ct ) break;
    }
}


/****************************************************************
 *	メッセージデータ ＆ 出力文字情報 結合			*
 ****************************************************************/
static void
msg_data_link( void )
{
    unshort	x, read_ct;
    int		i, j, ct, mct;
    unshort	comment_buf[1000];	/* コメント用 */
    unshort 	inf_buf[3];	        /* 文字情報バッファ */

    
    dt_ct = tp2 = 0;
    /* メッセージＮｏ。書き込み */
    fprintf(wfp, "unsigned short %s_%c%c%c%c[] = {\n", file_name[file_no], msg_no[2], msg_no[3], msg_no[4], msg_no[5] );
    
    /* 初期設定 */
    inf_buf[1] = 0x8262;
    inf_buf[2] = 0x824F;

    /* データ 書き込み */
    while ( 1 ) {
	tp1 = 1;
	return_code_check1();		/* 改行チェック */
	fprintf(wfp, "\t/*  ");   	/* メッセージ コメント */
	ct = temp1_buf[dt_ct][0];
	printf("dt_ct=%x ct=%x-->(",dt_ct, ct);
	for ( i = j = 0; i < (ct/2); i++ ) {
	    printf("(%x)",temp1_buf[dt_ct][i+1]);
	    if ( temp1_buf[dt_ct][i+1] != 0x2020 ) {
		comment_buf[j] = temp1_buf[dt_ct][i+1];
		printf("%x, ",comment_buf[j]);
		j++;
	    }
	    comment_buf[j] = NULL;
	}
	printf(")i=%x j=%x   ct=%x\n",i, j, ct);
	if( (fwrite(&comment_buf, sizeof(unshort), j, wfp)) != j ){
	    printf("zld64_msg_data.c COMMENT Write Error\n");
	    exit(1);
	}
	fprintf(wfp, "  */\n");
	
	/* 出力文字情報 */
	fprintf(wfp, "\t");
	mct = 0;
	while ( 1 ) {
	    if ( inf_buf[1] != temp2_buf[tp2+2] || inf_buf[2] != temp2_buf[tp2+4] ) {
		x = (( TO_ASCII(temp2_buf[tp2+2]) ) << 8) | TO_ASCII(temp2_buf[tp2+4]);
		return_code_check();	/* 改行チェック */
		fprintf( wfp, "CHANGE,0x%04x,\n\t", x );
		inf_buf[1] = temp2_buf[tp2+2];
		inf_buf[2] = temp2_buf[tp2+4];
	    }
	    
	    /* メッセージ */
	    for ( i = 0; i < (temp2_buf[tp2]/2); i++ ) {
		printf("msg_no=%x %x %x %x\n",msg_no[2], msg_no[3], msg_no[4], msg_no[5]);
		if ( msg_no[2] == 0x46 && msg_no[3] == 0x46 && msg_no[4] == 0x46 && msg_no[5] == 0x43 ) {
		    /* kscope_moji_FFFC[] */
		    /* カレイド・スコープ用フォントデータ */
		    read_ct = (temp2_buf[tp2] >> 1) + tp1;
		    for (; tp1 < read_ct; tp1++) {
			if ( temp1_buf[dt_ct][tp1] != D_SYURYOU ) {
			    fprintf(wfp, "0x%04x,",temp1_buf[dt_ct][tp1]);
			} else {
			    fprintf( wfp, "\n\tD_SYURYOU,  /* ---> 終了 */\n\t" );
			    break;
			}
		    }
		    lf = 1;
		    break;
		} else {
/*		    printf("<%02x> ",temp1_buf[dt_ct][tp1]);*/
		    switch( temp1_buf[dt_ct][tp1] ) {
		    case D_SYURYOU:
			/* 終了 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "D_SYURYOU,  /* ---> 終了 */\n\t" );
			break;

		    case Z_KEYWAIT:
			/* キー待ち */
			fprintf( wfp, "\n\tZ_KEYWAIT,  /* キー待ち */\n" );
			lf = 99;
			break;
			    
		    case Z_BLANK:
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_BLANK, %x,  /* 空きＤｏｔ数 */\n\t", x );
			tp1+=2;
			i+=2;
			break;
			    
		    case Z_NEXTMSG:
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+4] );
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_NEXTMSG, 0x%x,  /* ---> ＮＥＸＴメッセージ番号 */\n\t", x );
			tp1+=4;
			i+=4;
			break;

		    case Z_START:
			/* 一括表示開始 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_START, /* 一括表示開始 */ " );
			lf = 1;
			break;

		    case Z_STOP:
			/* 一括表示終了 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_STOP, /* 一括表示終了 */ " );
			lf = 1;
			break;

		    case Z_TIMER:
			/* ＴＩＭＥＲ */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_TIMER, %x,  /* ＴＩＭＥＲ */\n\t", x );
			tp1+=2;
			i+=2;
			lf = 99;
			break;

		    case Z_PAUSE:
			/* キー待ち */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_PAUSE, /* キー待ち */ " );
			lf = 1;
			break;

		    case Z_TIMER_END:
			/* ＴＩＭＥＲ */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_TIMER_END, %x,  /* タイマー付終了コード */\n\t", x );
			tp1+=2;
			i+=2;
			lf = 99;
			break;

		    case Z_NAME:
			/* プレイヤー登録名前 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_NAME, /* プレイヤー登録名前 */ " );
			lf = 1;
			break;

		    case Z_OCARINA:
			/* オカリナ */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_OCARINA, /* オカリナ */ " );
			lf = 1;
			break;

		    case Z_BGM:
			/* サウンド（ＢＧＭ）*/
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+4] );
			return_code_check();	/* 改行チェック */
			fprintf(wfp, "Z_BGM, 0x%x,\n\t", x );
			tp1+=4;
			break;

		    case Z_SE:
			/* サウンド（ＳＥ）*/
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+4] );
			return_code_check();	/* 改行チェック */
			fprintf(wfp, "Z_SE, 0x%x,\n\t", x );
			tp1+=4;
			break;
			    
		    case Z_DPITEM:
			/* アイテム */
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+3] );
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_DPITEM,%x,\n\t", x );
			tp1+=3;
			i+=3;
			break;
			    
		    case Z_SPEED:
			/* 文字表示スピード */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_SPEED, %x,  /* 文字表示スピード */\n\t", x );
			tp1+=2;
			i+=2;
			break;
			    
		    case Z_TEXTURE:
			return_code_check();	/* 改行チェック */
			/* １枚テクスチャ */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			fprintf( wfp, "Z_TEXTURE, 0x%02x,", x );
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+4] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+5] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+6] );
			fprintf( wfp, " 0x%04x,  /* １枚テクスチャ */\n\t", x );
			tp1+=6;
			i+=6;
			break;

		    case Z_EVENT_0:
			/* ＥＶＥＮＴタイマー大 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_EVENT_0, /* ＥＶＥＮＴタイマー大 */ " );
			lf = 1;
			break;

		    case Z_EVENT_1:
			/* ＥＶＥＮＴタイマー小 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_EVENT_1, /* ＥＶＥＮＴタイマー小 */ " );
			lf = 1;
			break;

		    case Z_NONONO:
			/* 早送り禁止 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_NONONO, /* 早送り禁止 */\n\t" );
			lf = 1;
			break;

		    case Z_SENTAKU_2:
			/* ２択 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_SENTAKU_2,\n\t" );
			break;

		    case Z_SENTAKU_3:
			/* ３択 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_SENTAKU_3,\n\t" );
			break;

		    case 0x2020:
			/* データ無視（頭揃えスペース）*/
			break;

		    case Z_DISPSTOP:
			/* 表示停止 */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_DISPSTOP, /* 表示停止 */ " );
			lf = 1;
			break;

		    case Z_ENEMY:
			/* 敵側制御コード */
			return_code_check();	/* 改行チェック */
			fprintf( wfp, "Z_ENEMY, /* 表示停止 */ " );
			lf = 99;
			break;
			
		    default:   /* その他 */
/*			printf("- WRITE\n");*/
			fprintf(wfp, "0x%04X,",temp1_buf[dt_ct][tp1]);
			lf = 1;
			break;
		    }
		    tp1++;
		}
	    }
	    mct += temp2_buf[tp2];
	    tp2 += 6;
	    printf("mct=%x   temp2_buf[%x]=%02x\n",mct, tp2, temp2_buf[tp2] );
	    if ( mct == temp1_buf[dt_ct][0] ) break;
	}
	if ( !temp2_buf[tp2] ) break;
	/* 改行 */
	if ( lf != 99 ) fprintf(wfp, "KAIGYO,\n");
	lf = 0;
	dt_ct++;
    }
    /* メッセージ 終了 */
    fprintf(wfp, "};\n\n");
}



/********************************************************************************	
 *	ＭＡＩＮ								*
 ********************************************************************************/
main( int argc, char *argv[] )
{
    int 		r_ct;

    typedef long 	time_t;
    time_t 		jikoku;
    struct tm 		*lt;

    /* 開始時刻表示 */
    time(&jikoku);		/* 暦時間の取得 */
    lt = localtime(&jikoku); 	/* 暦時間を構造体型の時間に変換 */
    dlt = asctime(lt);		/* 構造体型の時間を表示可能文字列に変換 */
    
    
    /*
     * Ｆｉｌｅ Ｏｐｅｎ処理
     */
    file_open();

    /*
     * テキストファイル 読み込み
     */
    for ( file_no = text_count = 0; file_no < file_su; file_no++ ) {
	printf("-------------------------------------------------------------------\n");
	printf( "file_no = %d,  file_name = %s\n", file_no, file_name[file_no] );
	/*
	 * 基本データ読み込み処理
	 */
	basic_data_read();
	printf( "Basic_data READ END\n" );

	/*
	 * ファイル内テキスト検索
	 */
	while ( 1 ) {
	    printf("-------------------------------------------------------------------\n");
	    dt_ct = 0;

	    /* データＨＥＡＤＥＲ処理 */
	    header_proc();
	    printf("----------- out-of-head_data (message-no. type) END!! ----------\n");
	    
	    /*
	     * メッセージ データ（仮書き込みバッファ１にセット）
	     */
	    msg_data_get();
	    printf("--------------- out-of-text_data (temp1_buf) END!! -------------\n");

	    /*
	     * 出力文字情報（仮書き込みバッファ２にセット）
	     */
	    msg_inf_get();
	    printf("------------- out-of-information (temp2_buf) END!! -------------\n");
	    
	    /*
	     * メッセージ データ ＆ 出力文字情報 結合
	     */
	    msg_data_link();
	    printf("=========================  LINK - END  ============================\n");

	    text_count++;

	    if ( (fread(&r_ct, sizeof(int), 0x1, rfp)) != 0x1 ) {
		printf( "'%s' READ ERROR!!  r_ct=%x\n", file_name[file_no], r_ct );
		exit(1);
	    }
	    if ( !r_ct ) break;
	    else	 fseek( rfp, -4, SEEK_CUR );
	}
	
	/*
	 * Ｆｉｌｅ Ｃｌｏｓｅ
	 */
	fclose(rfp);
	fclose(rfpi);
    }
    /* 終了 */
    fprintf(wfpt, "\t{ 0xFFFF,  0x00, NULL }\n};\n\n\n");

    
    /*
     * Ｆｉｌｅ Ｃｌｏｓｅ
     */
    fclose(wfp);
    fclose(wfpt);
    fclose(wfph);
    

    /* 終了時刻表示 */
    time(&jikoku);		/* 暦時間の取得 */
    lt = localtime(&jikoku); 	/* 暦時間を構造体型の時間に変換 */
    dlt = asctime(lt);		/* 構造体型の時間を表示可能文字列に変換 */
    printf("     END!!  END!!  END!!  :  %s",dlt);
}

