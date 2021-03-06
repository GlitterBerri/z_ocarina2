/* $Id: message_change.c,v 1.1 2003/03/14 03:39:08 tong Exp $ */	
/* $Log: message_change.c,v $
/* Revision 1.1  2003/03/14 03:39:08  tong
/* asset files copied from old tree to new tree.
/*
/* Revision 1.1  2003/02/12 19:07:42  tong
/* message_change source.
/*
 * Revision 1.3  1997/08/29  05:00:15  soejima
 * åÏXi¼pXy[XgpÂj
 * Revision 1.2  1997/04/09  04:37:39  soejima
 * EGWORD Version-UP(Version 7.0)
 * Revision 1.1  1997/01/28  10:53:33  soejima
 * $LogÇÁ
 * */

/****************************************************************
 *	l`bmdfvnqcnüÍeLXg  USÏ·	*
 *								*
 *	[_US bZ[WÏ·vO			*
 *	y¿qnlÎEo[Wz				*
 *								*
 *					97/01/28iÎjPM 04:20	*
 *  cc message_change.c -o message_change			*
 ****************************************************************/
#include <stdio.h>
#include <time.h>


/*======================================*
 *	¶Ï·p Ï			*
 *======================================*/
#define	unshort		unsigned short
#define	unchar		unsigned char

#define TO_SJIS(x)  ( (x) < (0x000A) ? (x + 0x824F) : (x - 0x000A + 0x8260) ) 
#define TO_ASCII(x) ( (x) < (0x8260) ? (x - 0x824F) : (x - 0x824F - 0x0007) )


char	File_Table[]="message.tbl";			/* ÇÝÝt@Cs`akd */
char	Write_File[]="zld64_msg_data.c";		/* f[^«Ýt@C */
char	Table_File[]="zld64_msg_data.tbl";		/* e[uf[^«Ýt@C */
char	Header_File[]="zld64_msg_data.h";		/* gd`cdq«Ýt@C */

FILE 	*rfp;			/* f[^ÇÝÝ |C^ */
FILE 	*rfpi;			/* îñÇÝÝ |C^ */
FILE 	*wfp;			/* f[^«Ý |C^ */
FILE 	*wfpt;			/* . «Ý |C^ */
FILE 	*wfph;			/* .     «Ý |C^ */

char 	file_name[200][1000];	/* e[uo^e */
unshort	file_su;		/* e[uo^e */
unshort	file_no;		/* e[uo^e|C^ */
unshort dt_ct;			/* eàeLXg JE^ */
char	lf;			/* üs§ä */

int	text_count;		/* eLXg */

int	inf_data_adr;		/* bZ[WîñæªAhX */
int	inf_data_ct;		/* bZ[Wîñ */

unshort	temp1_buf[200][1000];	/* îñP */
unshort	temp2_buf[2000];	/* îñQ */
unshort	msdt_buf[0x200];	/* ¡f[^ÇÝÝobt@i^j */
unchar 	msg_no[8];		/* bZ[WmÇÝÝobt@i^j */

unshort	tp1, tp2;

unshort	euc[4];			/* rihr¨dtbÏ·obt@ */

char 	*dlt;


/********************************************************************************/
/*------------ l`bf[^ ------------*/
#define D_HEADER	0x816F	/* f[^Jn            ioj          */
#define D_SYURYOU       0x8170	/* f[^dmc          ipj          */
#define D_KUGIRI	0x8146	/* f[^æØè          iFj          */
#define Z_KEYWAIT       0x81A5	/* L[Ò¿ :üy[W    i¥j          */
#define Z_BLANK		0x86C7	/* ó«                  i¨yQzj  */
#define Z_NEXTMSG	0x81CB	/* mdwsbZ[WÔiËySzj  */
#define Z_START         0x8189	/* ê\¦Jn          ij          */
#define Z_STOP          0x818A	/* ê\¦I¹          ij          */
#define Z_DISPSTOP      0x86C8	/* \¦â~              i©j          */
#define Z_ENEMY         0x819F	/* G¤§äR[h        ij          */
#define Z_TIMER         0x81A3	/* shldq 		 i£yQzj  */
#define Z_PAUSE         0x81A4	/* L[Ò¿              i¤j          */
#define Z_TIMER_END     0x819E	/* ^C}[tI¹R[h  ij          */
#define Z_NAME          0x874F	/* vC[o^¼O    i¼j          */
#define Z_OCARINA       0x81F0	/* IJi              i`j          */
#define Z_BGM	        0x81F4	/* TEhiaflj    iôySzj  */
#define Z_SE            0x81F3	/* TEhirdj      ióySzj  */
#define Z_DPITEM	0x819A	/* ACe              iyRzj  */
#define Z_SPEED         0x86C9	/* ¶\¦Xs[h      iªyQzj  */
#define Z_TEXTURE       0x86B3	/* PeNX`        i.s.yUzj*/
#define Z_EVENT_0	0x8791	/* dudms^C}[å  iåj          */
#define Z_EVENT_1	0x8792	/* dudms^C}[¬  i¬j          */
#define Z_NONONO	0x8199	/* èÖ~            ij          */
#define	Z_SENTAKU_2	0x81BC	/* Qð                  i¼j          */
#define Z_SENTAKU_3	0x81B8	/* Rð                  i¸j          */
#define KAIGYO          0x0A	/* üs */
#define CHANGE          0x0B	/* ¶FØÖ */
#define SPACE           0x8140	/* Xy[X */

/********************************************************************************/
/*=======================================================
  =	rihr ¨iihrj¨ dtb Ï·		=
  =	i{PQWðO·ÆihrÏ·ÉÈéj		=
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
  -	bZ[WmDfds		-
  ---------------------------------------*/
static void
message_number_get( void )
{
    if ( msdt_buf[5] != D_KUGIRI /*iFj*/ ) {
	/* bZ[WmnDG[ */
	printf("'%s' Message_No. ERROR\n", file_name[file_no]);
	exit(1);
    }

    /* LXgZ */
    msg_no[0] = 0x30/* 0 */;
    msg_no[1] = 0x78/* x */;
    msg_no[2] = (char)( msdt_buf[1] > 0x825F ? ( msdt_buf[1] > 0x8280 ? (msdt_buf[1]-0x8281)+0x61 : (msdt_buf[1]-0x8260)+0x41 ) : (msdt_buf[1]-0x824F)+0x30 );
    msg_no[3] = (char)( msdt_buf[2] > 0x825F ? ( msdt_buf[2] > 0x8280 ? (msdt_buf[2]-0x8281)+0x61 : (msdt_buf[2]-0x8260)+0x41 ) : (msdt_buf[2]-0x824F)+0x30 );
    msg_no[4] = (char)( msdt_buf[3] > 0x825F ? ( msdt_buf[3] > 0x8280 ? (msdt_buf[3]-0x8281)+0x61 : (msdt_buf[3]-0x8260)+0x41 ) : (msdt_buf[3]-0x824F)+0x30 );
    msg_no[5] = (char)( msdt_buf[4] > 0x825F ? ( msdt_buf[4] > 0x8280 ? (msdt_buf[4]-0x8281)+0x61 : (msdt_buf[4]-0x8260)+0x41 ) : (msdt_buf[4]-0x824F)+0x30 );
    msg_no[6] = 0x2c/* , */;
    msg_no[7] = 0x20/*   */;

    /* bZ[WmnD«Ý */
    fprintf(wfpt,"\t{ ");
    if( (fwrite(&msg_no, sizeof(char), 0x8, wfpt)) != 0x8 ){
	printf("[zld64_msg_data.tbl]  Message_No. Write ERROR!!\n");
	exit(1);
    }
    printf("Message_No.=%c%c%c%c  :  ",msg_no[2],msg_no[3],msg_no[4],msg_no[5]);
}

/*---------------------------------------
  -	s f[^ fds		-
  ---------------------------------------*/
static void
message_type_get( void )
{
    unchar 	msg_buf[10];		/* f[^ÇÝÝobt@i^j */


    if ( msdt_buf[8] != D_KUGIRI /*iFj*/ ) {
	printf("'%s' HEADER DATA ERROR\n", file_name[file_no]);
	exit(1);
    }

    /* LXgZ */
    msg_buf[0] = 0x30/* 0 */;
    msg_buf[1] = 0x78/* x */;
    msg_buf[2] = (char)( msdt_buf[6] > 0x825F ? ( msdt_buf[6] > 0x8280 ? (msdt_buf[6]-0x8281)+0x61 : (msdt_buf[6]-0x8260)+0x41 ) : (msdt_buf[6]-0x824F)+0x30 );
    msg_buf[3] = (char)( msdt_buf[7] > 0x825F ? ( msdt_buf[7] > 0x8280 ? (msdt_buf[7]-0x8281)+0x61 : (msdt_buf[7]-0x8260)+0x41 ) : (msdt_buf[7]-0x824F)+0x30 );
    msg_buf[4] = 0x2c/* , */;
    msg_buf[5] = 0x20/*   */;


    /* t@C «Ý */
    if( (fwrite(&msg_buf, sizeof(char), 0x6, wfpt)) != 0x6 ) {
	printf("zld64_msg_data.tbl HEADER Write Error\n");
	exit(1);
    }
    printf("Type=%c%c\n",msg_buf[0], msg_buf[1] );
}

/*---------------------------------------
  -	üs`FbN			-
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
  -	üs`FbN			-
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
 *	e n					*
 ****************************************************************/
static void
file_open( void )
{
    /*
     * ÇÝÝs`akd nodm
     */
    printf( "********************************************************\n");
    printf( "*******    S T A R T  :  %s",dlt);
    printf( "********************************************************\n");
    if ( ( rfp = fopen( File_Table, "r" ) ) == NULL ) {
	printf( "[%s] File_Table Open Error!!!\n", File_Table );
	exit(1);
    }
    /* e[uàÌt@Cðßé */
    file_su = 0;
    while ( fscanf( rfp, "%s\n", &file_name[file_su] ) != EOF ) file_su++;
    if ( !file_su ) {
	/* t@C³µII  I¹ */
	printf( "%s TABLE_File Nothing!!!\n", File_Table );
	exit(1);
    } else /* t@C\¦ */
	printf( "*** OPEN File_Table = %s,   FILE COUNT = %d\n", File_Table, file_su );
    fclose( rfp );
    
    /*
     * f[^«Ýt@C n
     */
    if( ( wfp = fopen( Write_File, "w" ) ) == NULL ) {
	printf( "[%s] Write_File OPEN ERROR!!\n", Write_File );
	exit(1);
    }
    fprintf( wfp, "/*\n * ì¬ú : %s */\n", dlt );
    fprintf( wfp, "/*------------ bncd c`s` ------------*/\n" );
    fprintf( wfp, "#define D_SYURYOU            0x8170	/* f[^dmc ipj*/\n" );
    fprintf( wfp, "#define Z_KEYWAIT            0x81A5	/* L[Ò¿ i¥j*/\n" );
    fprintf( wfp, "#define Z_BLANK              0x86C7	/* ó«i¨yQzj*/\n" );
    fprintf( wfp, "#define Z_NEXTMSG            0x81CB	/* mdwsbZ[WÔiËySzj*/\n" );
    fprintf( wfp, "#define Z_START              0x8189	/* ê\¦Jn ij*/\n" );
    fprintf( wfp, "#define Z_STOP               0x818A	/* ê\¦I¹ ij*/\n" );
    fprintf( wfp, "#define Z_DISPSTOP           0x86C8	/* \¦â~ i©j*/\n" );
    fprintf( wfp, "#define Z_ENEMY              0x819F	/* G¤§äR[h ij*/\n" );
    fprintf( wfp, "#define Z_TIMER              0x81A3	/* shldqi£yQzj*/\n" );
    fprintf( wfp, "#define Z_PAUSE              0x81A4	/* L[Ò¿ i¤j*/\n" );
    fprintf( wfp, "#define Z_TIMER_END          0x819E	/* ^C}[tI¹R[h  ij*/\n" );
    fprintf( wfp, "#define Z_NAME               0x874F	/* vC[o^¼O ij*/\n" );
    fprintf( wfp, "#define Z_OCARINA            0x81F0	/* IJi i`j*/\n" );
    fprintf( wfp, "#define Z_BGM                0x81F4	/* TEhiafljiôySz*/\n" );
    fprintf( wfp, "#define Z_SE                 0x81F3	/* TEhirdjióySzj*/\n" );
    fprintf( wfp, "#define Z_DPITEM             0x819A	/* ACeiyRzj*/\n" );
    fprintf( wfp, "#define Z_SPEED              0x86C9	/* ¶\¦Xs[hiªyQzj*/\n" );
    fprintf( wfp, "#define Z_TEXTURE            0x86B3	/* PeNX`i.s.yUzj*/\n" );
    fprintf( wfp, "#define Z_EVENT_0		0x8791	/* dudms^C}[å  iåj*/\n" );
    fprintf( wfp, "#define Z_EVENT_1		0x8792	/* dudms^C}[¬  i¬j*/\n" );
    fprintf( wfp, "#define Z_NONONO	        0x8199	/* èÖ~            ij*/\n" );
    fprintf( wfp, "#define Z_SENTAKU_2          0x81BC	/* Qð */\n" );
    fprintf( wfp, "#define Z_SENTAKU_3          0x81B8	/* Rð */\n" );
    fprintf( wfp, "#define KAIGYO               0x0A	/* üs */\n" );
    fprintf( wfp, "#define CHANGE               0x0B	/* ¶FØÖ */\n" );
    fprintf( wfp, "#define SPACE                0x8140	/* Xy[X */\n\n" );

    /*
     * e[uf[^«Ýt@C n
     */
    if( ( wfpt = fopen( Table_File, "w" ) ) == NULL ) {
	printf( "[%s]  Write_Table OPEN ERROR!!\n", Table_File );
	exit(1);
    }
    fprintf( wfpt, "/*\n * ì¬ú : %s */\nstatic\nMSG_T message_tbl[] = {\n", dlt );

    /*
     * gd`cdq«Ýt@C n
     */
    if( ( wfph = fopen( Header_File, "w" ) ) == NULL ) {
	printf( "[%s] Write_HEADER_FILE OPEN ERROR!!\n", Header_File );
	exit(1);
    }
    fprintf( wfph, "  ==    ì¬ú : %s ", dlt );
    fprintf( wfph, " ===============================================================*/\n");
    fprintf( wfph, "/*------------ bncd c`s` ------------*/\n" );
    fprintf( wfph, "#define D_SYURYOU            0x8170	/* f[^dmc ipj*/\n" );
    fprintf( wfph, "#define Z_KEYWAIT            0x81A5	/* L[Ò¿ i¥j*/\n" );
    fprintf( wfph, "#define Z_BLANK              0x86C7	/* ó«i¨yQzj*/\n" );
    fprintf( wfph, "#define Z_NEXTMSG            0x81CB	/* mdwsbZ[WÔiËySzj*/\n" );
    fprintf( wfph, "#define Z_START              0x8189	/* ê\¦Jn ij*/\n" );
    fprintf( wfph, "#define Z_STOP               0x818A	/* ê\¦I¹ ij*/\n" );
    fprintf( wfph, "#define Z_DISPSTOP           0x86C8	/* \¦â~ i©j*/\n" );
    fprintf( wfph, "#define Z_ENEMY              0x819F	/* G¤§äR[h ij*/\n" );
    fprintf( wfph, "#define Z_TIMER              0x81A3	/* shldqi£yQzj*/\n" );
    fprintf( wfph, "#define Z_PAUSE              0x81A4	/* L[Ò¿ i¤j*/\n" );
    fprintf( wfph, "#define Z_TIMER_END          0x819E	/* ^C}[tI¹R[h  ij*/\n" );
    fprintf( wfph, "#define Z_NAME               0x874F	/* vC[o^¼O ij*/\n" );
    fprintf( wfph, "#define Z_OCARINA            0x81F0	/* IJi i`j*/\n" );
    fprintf( wfph, "#define Z_BGM                0x81F4	/* TEhiafljiôySz*/\n" );
    fprintf( wfph, "#define Z_SE                 0x81F3	/* TEhirdjióySzj*/\n" );
    fprintf( wfph, "#define Z_DPITEM             0x819A	/* ACeiyRzj*/\n" );
    fprintf( wfph, "#define Z_SPEED              0x86C9	/* ¶\¦Xs[hiªyQzj*/\n" );
    fprintf( wfph, "#define Z_TEXTURE            0x86B3	/* PeNX`i.s.yUzj*/\n" );
    fprintf( wfph, "#define Z_EVENT_0		 0x8791	/* dudms^C}[å  iåj*/\n" );
    fprintf( wfph, "#define Z_EVENT_1		 0x8792	/* dudms^C}[¬  i¬j*/\n" );
    fprintf( wfph, "#define Z_NONONO	         0x8199	/* èÖ~            ij*/\n" );
    fprintf( wfph, "#define Z_SENTAKU_2          0x81BC	/* Qð */\n" );
    fprintf( wfph, "#define Z_SENTAKU_3          0x81B8	/* Rð */\n" );
    fprintf( wfph, "#define KAIGYO               0x0A	/* üs */\n" );
    fprintf( wfph, "#define CHANGE               0x0B	/* ¶FØÖ */\n" );
    fprintf( wfph, "#define SPACE                0x8140	/* Xy[X */\n\n" );
}


/****************************************************************
 *	î{f[^ÇÝÝ					*
 ****************************************************************/
static void
basic_data_read( void )
{
    int		text_start_adr;		/* bZ[Wc`s`æªAhX */
    int		text_total_ct;		/* bZ[W¶ */
    unchar 	title_buf[100];		/* f[^ÇÝÝobt@i^j */
    short	i, cfg;


    /*
     * qd`c e n
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
     * ^CgÊuõ
     */
    if ( (fread(&title_buf, sizeof(unchar), 0x70, rfp)) != 0x70 ) {
	printf("'%s' READ OPEN ERROR1111!!\n", file_name);
	exit(1);
    }


    /* bZ[W¶fytext_total_ctz */
    cfg = 1;
    i = -1;
    while ( cfg ) {
	if ( title_buf[++i] == 0x54/* T */ ) {
	    if ( title_buf[++i] == 0x45/* E */ ) {
		if ( title_buf[++i] == 0x58/* X */ ) {
		    if ( title_buf[++i] == 0x54/* T */ ) {
			/* bZ[Wc`s`æªAhX */
			text_start_adr = ((int)title_buf[i+1]<<24 | (int)title_buf[i+2]<<16 | (int)title_buf[i+3]<<8 | (int)title_buf[i+4]);
			/* bZ[W¶ */
			text_total_ct = ((int)title_buf[i+5]<<24 | (int)title_buf[i+6]<<16 | (int)title_buf[i+7]<<8 | (int)title_buf[i+8]);
			cfg = 0;
		    }
		}
	    }
	}
    }
    printf("text_total_ct=%d(%x : %2x,%2x,%2x,%2x) text_start_adr=%x\n",text_total_ct, i+5, title_buf[i+5], title_buf[i+6], title_buf[i+7], title_buf[i+8], text_start_adr );


    /* bZ[Wîñfyinf_data_adr, inf_data_ctz */
    cfg = 1;
    while ( cfg ) {
	if ( title_buf[++i] == 0x41/* A */ ) {
	    if ( title_buf[++i] == 0x54/* T */ ) {
		if ( title_buf[++i] == 0x52/* R */ ) {
		    if ( title_buf[++i] == 0x42/* B */ ) {
			/* bZ[WîñæªAhX */
			inf_data_adr = ((int)title_buf[i+1]<<24 | (int)title_buf[i+2]<<16 | (int)title_buf[i+3]<<8 | (int)title_buf[i+4]);
			/* bZ[Wîñ */
			inf_data_ct = ((int)title_buf[i+5]<<24 | (int)title_buf[i+6]<<16 | (int)title_buf[i+7]<<8 | (int)title_buf[i+8]);
			cfg = 0;
		    }
		}
	    }
	}
    }
    printf("inf_data_ct=%d(%x : %2x,%2x,%2x,%2x)\n",inf_data_ct, i+5, title_buf[i+5], title_buf[i+6], title_buf[i+7], title_buf[i+8] );


    /* bZ[Wc`s`æªÊuÖÚ® */
    fseek(rfp, text_start_adr, SEEK_SET);

    /* îñæªÚ® */
    fseek(rfpi, inf_data_adr, SEEK_SET);
}


/****************************************************************
 *	f[^gd`cdq					*
 ****************************************************************/
static void
header_proc( void )
{
    int		i, r_ct;


    /* f[^gd`cdqÇÝÝ */
    if ( (i=fread(&r_ct, sizeof(int), 0x1, rfp)) != 0x1 ) {
	printf("-'%s'- (%x)READ ERROR!!!!\n", file_name[file_no],i);
	exit(1);
    }
    /* f[^gd`cdqÇÝÝif[^gd`cdqªj */
    if ( (i=fread(&msdt_buf, sizeof(unshort), (r_ct/2), rfp)) != (r_ct/2) ) {
	printf("--'%s'-- [%x]READ ERROR!!!!\n", file_name[file_no],i);
	exit(1);
    }
    printf("msdt_buf[%2x]=",r_ct);
    for ( i = 0; i < (r_ct/2); i++ ) {
	/* rihr ¨ dtb */
	sjis2euc( msdt_buf[i] >> 8, msdt_buf[i] & 0x00ff );
	printf("%s ", euc);
    }
    printf("\n");

    if ( msdt_buf[0] == D_HEADER /*ioj*/) {
	/* bZ[WmDÇÝÝ */
	message_number_get();

	/* bZ[Wsxod ÇÝÝ */
	message_type_get();

	/* "." bZ[WmD«Ý */
	fprintf(wfpt, "%s_%c%c%c%c },\t\t/* %6d */\n", file_name[file_no], msg_no[2], msg_no[3], msg_no[4], msg_no[5], text_count );
	/* "." bZ[WmD«Ý */
	fprintf(wfph, "extern unsigned short %s_%c%c%c%c[];\n",file_name[file_no], msg_no[2], msg_no[3], msg_no[4], msg_no[5] );
    } else {
	printf("DATA HEADER ERROR 123!! :::  msdt_buf[0] = %x \n", msdt_buf[0]);
	exit(1);
    }
}


/****************************************************************
 *	bZ[W f[^i¼«Ýobt@PÉZbgj	*
 *	¬ª¶ª±ª¶ª¶ªªªªªªªªª¶ª¶ª­		*
 *	« Â «       f[^iôoCgj       «		*
 *	¯ª¸ª³ª¸ª¸ªªªªªªªªª¸ª¸ª®		*
 * 	  ¦¼pXy[XnjIIiK¸ôÂj			*
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
	/* bZ[W f[^ÇÝÝibZ[W f[^ªj */
	if ( (i=fread(&msdt_buf, sizeof(unshort), (r_ct/2)+1, rfp)) != (r_ct/2)+1 ) {
	    printf("'%s' (%x)READ ERROR!!!!\n", file_name[file_no],i);
	    exit(1);
	}
	if ( msdt_buf[1] == D_HEADER /*ioj*/ ) {
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
		    /* rihr ¨ dtb */
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
 *	oÍ¶îñi¼«Ýobt@QÉZbgj			*
 *¬ª¶ª±ª¶ª±ª¶ª±ª¶ª±ª¶ª±ª¶ª±ª¶ª±ª¶ª­	*
 *« Â «      «      «TCY«      «      «  F  «      «	*
 *¯ª¸ª³ª¸ª³ª¸ª³ª¸ª³ª¸ª³ª¸ª³ª¸ª³ª¸ª®	*
 *		 	    «      «      «				*
 *			¬ª¶ª±ª¶ª±ª¶ª­			*
 *			« Â «TCY«  F  «			*
 *			¯ª¸ª³ª¸ª³ª¸ª®			*
 * TCYiPUi\¦Fî{PQhbgj					*
 * FiOF, PFÔ, QFÎ, RFF, SFÂ, TFsN, UF©Fj *
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
		/* Â */
		temp2_buf[tp2] = msdt_buf[0+i];
		/* ¶TCY */
		temp2_buf[tp2+2] = TO_SJIS( (msdt_buf[3+i] >> 8) );
		/* ¶J[ */
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
 *	bZ[Wf[^  oÍ¶îñ 			*
 ****************************************************************/
static void
msg_data_link( void )
{
    unshort	x, read_ct;
    int		i, j, ct, mct;
    unshort	comment_buf[1000];	/* Rgp */
    unshort 	inf_buf[3];	        /* ¶îñobt@ */

    
    dt_ct = tp2 = 0;
    /* bZ[WmB«Ý */
    fprintf(wfp, "unsigned short %s_%c%c%c%c[] = {\n", file_name[file_no], msg_no[2], msg_no[3], msg_no[4], msg_no[5] );
    
    /* úÝè */
    inf_buf[1] = 0x8262;
    inf_buf[2] = 0x824F;

    /* f[^ «Ý */
    while ( 1 ) {
	tp1 = 1;
	return_code_check1();		/* üs`FbN */
	fprintf(wfp, "\t/*  ");   	/* bZ[W Rg */
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
	
	/* oÍ¶îñ */
	fprintf(wfp, "\t");
	mct = 0;
	while ( 1 ) {
	    if ( inf_buf[1] != temp2_buf[tp2+2] || inf_buf[2] != temp2_buf[tp2+4] ) {
		x = (( TO_ASCII(temp2_buf[tp2+2]) ) << 8) | TO_ASCII(temp2_buf[tp2+4]);
		return_code_check();	/* üs`FbN */
		fprintf( wfp, "CHANGE,0x%04x,\n\t", x );
		inf_buf[1] = temp2_buf[tp2+2];
		inf_buf[2] = temp2_buf[tp2+4];
	    }
	    
	    /* bZ[W */
	    for ( i = 0; i < (temp2_buf[tp2]/2); i++ ) {
		printf("msg_no=%x %x %x %x\n",msg_no[2], msg_no[3], msg_no[4], msg_no[5]);
		if ( msg_no[2] == 0x46 && msg_no[3] == 0x46 && msg_no[4] == 0x46 && msg_no[5] == 0x43 ) {
		    /* kscope_moji_FFFC[] */
		    /* JChEXR[vptHgf[^ */
		    read_ct = (temp2_buf[tp2] >> 1) + tp1;
		    for (; tp1 < read_ct; tp1++) {
			if ( temp1_buf[dt_ct][tp1] != D_SYURYOU ) {
			    fprintf(wfp, "0x%04x,",temp1_buf[dt_ct][tp1]);
			} else {
			    fprintf( wfp, "\n\tD_SYURYOU,  /* ---> I¹ */\n\t" );
			    break;
			}
		    }
		    lf = 1;
		    break;
		} else {
/*		    printf("<%02x> ",temp1_buf[dt_ct][tp1]);*/
		    switch( temp1_buf[dt_ct][tp1] ) {
		    case D_SYURYOU:
			/* I¹ */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "D_SYURYOU,  /* ---> I¹ */\n\t" );
			break;

		    case Z_KEYWAIT:
			/* L[Ò¿ */
			fprintf( wfp, "\n\tZ_KEYWAIT,  /* L[Ò¿ */\n" );
			lf = 99;
			break;
			    
		    case Z_BLANK:
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_BLANK, %x,  /* ó«c */\n\t", x );
			tp1+=2;
			i+=2;
			break;
			    
		    case Z_NEXTMSG:
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+4] );
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_NEXTMSG, 0x%x,  /* ---> mdwsbZ[WÔ */\n\t", x );
			tp1+=4;
			i+=4;
			break;

		    case Z_START:
			/* ê\¦Jn */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_START, /* ê\¦Jn */ " );
			lf = 1;
			break;

		    case Z_STOP:
			/* ê\¦I¹ */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_STOP, /* ê\¦I¹ */ " );
			lf = 1;
			break;

		    case Z_TIMER:
			/* shldq */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_TIMER, %x,  /* shldq */\n\t", x );
			tp1+=2;
			i+=2;
			lf = 99;
			break;

		    case Z_PAUSE:
			/* L[Ò¿ */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_PAUSE, /* L[Ò¿ */ " );
			lf = 1;
			break;

		    case Z_TIMER_END:
			/* shldq */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_TIMER_END, %x,  /* ^C}[tI¹R[h */\n\t", x );
			tp1+=2;
			i+=2;
			lf = 99;
			break;

		    case Z_NAME:
			/* vC[o^¼O */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_NAME, /* vC[o^¼O */ " );
			lf = 1;
			break;

		    case Z_OCARINA:
			/* IJi */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_OCARINA, /* IJi */ " );
			lf = 1;
			break;

		    case Z_BGM:
			/* TEhiaflj*/
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+4] );
			return_code_check();	/* üs`FbN */
			fprintf(wfp, "Z_BGM, 0x%x,\n\t", x );
			tp1+=4;
			break;

		    case Z_SE:
			/* TEhirdj*/
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+4] );
			return_code_check();	/* üs`FbN */
			fprintf(wfp, "Z_SE, 0x%x,\n\t", x );
			tp1+=4;
			break;
			    
		    case Z_DPITEM:
			/* ACe */
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+2] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+3] );
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_DPITEM,%x,\n\t", x );
			tp1+=3;
			i+=3;
			break;
			    
		    case Z_SPEED:
			/* ¶\¦Xs[h */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_SPEED, %x,  /* ¶\¦Xs[h */\n\t", x );
			tp1+=2;
			i+=2;
			break;
			    
		    case Z_TEXTURE:
			return_code_check();	/* üs`FbN */
			/* PeNX` */
			x = ( TO_ASCII( temp1_buf[dt_ct][tp1+1] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+2] );
			fprintf( wfp, "Z_TEXTURE, 0x%02x,", x );
			x =  ( TO_ASCII( temp1_buf[dt_ct][tp1+3] ) ) << 12;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+4] ) ) << 8;
			x |= ( TO_ASCII( temp1_buf[dt_ct][tp1+5] ) ) << 4;
			x |= TO_ASCII( temp1_buf[dt_ct][tp1+6] );
			fprintf( wfp, " 0x%04x,  /* PeNX` */\n\t", x );
			tp1+=6;
			i+=6;
			break;

		    case Z_EVENT_0:
			/* dudms^C}[å */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_EVENT_0, /* dudms^C}[å */ " );
			lf = 1;
			break;

		    case Z_EVENT_1:
			/* dudms^C}[¬ */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_EVENT_1, /* dudms^C}[¬ */ " );
			lf = 1;
			break;

		    case Z_NONONO:
			/* èÖ~ */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_NONONO, /* èÖ~ */\n\t" );
			lf = 1;
			break;

		    case Z_SENTAKU_2:
			/* Qð */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_SENTAKU_2,\n\t" );
			break;

		    case Z_SENTAKU_3:
			/* Rð */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_SENTAKU_3,\n\t" );
			break;

		    case 0x2020:
			/* f[^³iªµ¦Xy[Xj*/
			break;

		    case Z_DISPSTOP:
			/* \¦â~ */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_DISPSTOP, /* \¦â~ */ " );
			lf = 1;
			break;

		    case Z_ENEMY:
			/* G¤§äR[h */
			return_code_check();	/* üs`FbN */
			fprintf( wfp, "Z_ENEMY, /* \¦â~ */ " );
			lf = 99;
			break;
			
		    default:   /* »Ì¼ */
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
	/* üs */
	if ( lf != 99 ) fprintf(wfp, "KAIGYO,\n");
	lf = 0;
	dt_ct++;
    }
    /* bZ[W I¹ */
    fprintf(wfp, "};\n\n");
}



/********************************************************************************	
 *	l`hm								*
 ********************************************************************************/
main( int argc, char *argv[] )
{
    int 		r_ct;

    typedef long 	time_t;
    time_t 		jikoku;
    struct tm 		*lt;

    /* Jn\¦ */
    time(&jikoku);		/* ïÔÌæ¾ */
    lt = localtime(&jikoku); 	/* ïÔð\¢Ì^ÌÔÉÏ· */
    dlt = asctime(lt);		/* \¢Ì^ÌÔð\¦Â\¶ñÉÏ· */
    
    
    /*
     * e n
     */
    file_open();

    /*
     * eLXgt@C ÇÝÝ
     */
    for ( file_no = text_count = 0; file_no < file_su; file_no++ ) {
	printf("-------------------------------------------------------------------\n");
	printf( "file_no = %d,  file_name = %s\n", file_no, file_name[file_no] );
	/*
	 * î{f[^ÇÝÝ
	 */
	basic_data_read();
	printf( "Basic_data READ END\n" );

	/*
	 * t@CàeLXgõ
	 */
	while ( 1 ) {
	    printf("-------------------------------------------------------------------\n");
	    dt_ct = 0;

	    /* f[^gd`cdq */
	    header_proc();
	    printf("----------- out-of-head_data (message-no. type) END!! ----------\n");
	    
	    /*
	     * bZ[W f[^i¼«Ýobt@PÉZbgj
	     */
	    msg_data_get();
	    printf("--------------- out-of-text_data (temp1_buf) END!! -------------\n");

	    /*
	     * oÍ¶îñi¼«Ýobt@QÉZbgj
	     */
	    msg_inf_get();
	    printf("------------- out-of-information (temp2_buf) END!! -------------\n");
	    
	    /*
	     * bZ[W f[^  oÍ¶îñ 
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
	 * e b
	 */
	fclose(rfp);
	fclose(rfpi);
    }
    /* I¹ */
    fprintf(wfpt, "\t{ 0xFFFF,  0x00, NULL }\n};\n\n\n");

    
    /*
     * e b
     */
    fclose(wfp);
    fclose(wfpt);
    fclose(wfph);
    

    /* I¹\¦ */
    time(&jikoku);		/* ïÔÌæ¾ */
    lt = localtime(&jikoku); 	/* ïÔð\¢Ì^ÌÔÉÏ· */
    dlt = asctime(lt);		/* \¢Ì^ÌÔð\¦Â\¶ñÉÏ· */
    printf("     END!!  END!!  END!!  :  %s",dlt);
}

