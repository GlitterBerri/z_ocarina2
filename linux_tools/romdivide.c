/************************************************************************
 *									*
 *	ＲＯＭマップをもとにＲＯＭを分割する				*
 *									*
 ************************************************************************/
/*
 * $Id: romdivide.c,v 1.1 2003/03/14 03:19:08 tong Exp $
 * $Log: romdivide.c,v $
 * Revision 1.1  2003/03/14 03:19:08  tong
 * moving linux_tools(nintendo) from old tree to new tree.
 *
 * Revision 1.1  2003/03/11 03:38:48  tong
 * linux make tools from Nintendo
 *
 * Revision 1.8  1998-10-22 20:47:43+09  hayakawa
 * *** empty log message ***
 *
 * Revision 1.7  1998-06-23 11:29:08+09  zelda
 * ポインタの初期化を忘れていた
 *
 */
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#define		MAX_STR		0x00000400 /* 最大ファイル名長 */
#define		ROMBUF		0x00010000 /* 転送バッファサイズ */

typedef struct rom_data_s {
    struct rom_data_s	*next;
    unsigned long	sz;
    unsigned long	ad;
    char		fn[1];
} rom_data_t;

static rom_data_t	*rom_data_top = NULL;
static int		rom_data_num = 0;
static char		rombuf[ROMBUF];
static int		vflag = 0;

/*======================================================================*
 *	ＲＯＭをわける							*
 *======================================================================*/
static void rom_div(
    char	*const r_name
)
{
    FILE	*rfp, *wfp;
    int		i;
    size_t leftsize;
    char	*w_name;
    rom_data_t  *rom_data;

    if ((rfp = fopen(r_name, "r")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", r_name);
	exit(1);
    }

    i = 0;
    if (vflag) {
	fprintf(stderr, "rom_data_num = %d\n", rom_data_num);
    }
    for (rom_data = rom_data_top; rom_data != NULL; rom_data = rom_data->next) {

	w_name = rom_data->fn;
	
	if (vflag) {
	    fprintf(stderr, "%d:%s %d %d\n",
		    i, w_name, rom_data->ad, rom_data->sz);
	}
	
	if ((wfp = fopen(w_name, "w")) == NULL) {
	    fprintf(stderr, "%s ファイルがオープンできませんでした\n",
		    w_name);
	    exit(1);
	}

	if (fseek(rfp, (long)rom_data->ad, SEEK_SET)) {
	    fprintf(stderr, "%s ファイルがシークできませんでした\n",
		    r_name);
	    exit(1);
	}
	leftsize = (size_t)rom_data->sz;
	while (leftsize > ROMBUF) {
	    if (fread(rombuf, sizeof(char), ROMBUF, rfp) != ROMBUF) {
		fprintf(stderr, "%s ファイルがリードできませんでした\n", r_name);
		exit(1);
	    }
	    if (fwrite(rombuf, sizeof(char), ROMBUF, wfp) != ROMBUF) {
		fprintf(stderr, "%s ファイルがライトできませんでした\n", w_name);
		exit(1);
	    }
	    leftsize -= ROMBUF;
	}
	if (fread(rombuf, sizeof(char), leftsize, rfp) != leftsize) {
	    fprintf(stderr, "%s ファイルがリードできませんでした\n", r_name);
	    exit(1);
	}
	if (fwrite(rombuf, sizeof(char), leftsize, wfp) != leftsize) {
	    fprintf(stderr, "%s ファイルがライトできませんでした\n", w_name);
	    exit(1);
	}
	fclose(wfp);
	++i;
    }

    i = 0;
    while (fread(rombuf, sizeof(char), 1, rfp) == 1) {
	fprintf(stderr, "%s ファイルが余っています : %X %X\n",
		r_name, i, rombuf[0]);
	i += 1;
    }
    
    fclose(rfp);
}

/*======================================================================*
 *	ＲＯＭマップを読む						*
 *======================================================================*/
static void rom_map_read(
    char	*const rfn
)
{
    FILE	*rfp;
    rom_data_t  *rom_data;
    unsigned long	temp_sz;
    unsigned long	temp_ad;
    char		temp_fn[MAX_STR+1];
    size_t size;

    if ((rfp = fopen(rfn, "r")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", rfn);
	exit(1);
    }

    rom_data_top == NULL;
    rom_data_num = 0;
    while (1) {
	if (fscanf( rfp, "%s %x %x\n", temp_fn, &temp_sz, &temp_ad) == EOF) {
	    break;
	}
	size = sizeof(rom_data_t) + strlen(temp_fn);
	if (rom_data_top == NULL) {
	    rom_data_top = (rom_data_t *)malloc(size);
	    rom_data = rom_data_top;
	} else {
	    rom_data->next = (rom_data_t *)malloc(size);
	    rom_data = rom_data->next;
	}
	if (rom_data == NULL) {
	    fprintf(stderr, "メモリアロケーションエラー\n");
	    exit(1);
	}
	rom_data->sz = temp_sz;
	rom_data->ad = temp_ad;
	rom_data->next = NULL;
	strcpy(rom_data->fn, temp_fn);
	rom_data_num++;
    }

    fclose(rfp);
}

/*======================================================================*
 *	メイン								*
 *======================================================================*/
extern int main(
    int		argc,
    char	*argv[]
)
{
    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'v' && argv[1][2] == '\0') {
	vflag = 1;
	argv++;
	argc--;
    }
    if (argc != 3) {
	fprintf(stderr, "ＲＯＭマップとＲＯＭを指定してください\n");
	exit(1);
    }

    rom_map_read(argv[1]);
    rom_div(argv[2]);

    return 0;
}
