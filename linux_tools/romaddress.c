/************************************************************************
 *									*
 *	ＲＯＭマップをもとにアドレスを計算する				*
 *									*
 ************************************************************************/
/*
 * $Log: romaddress.c,v $
 * Revision 1.1  2003/03/14 03:19:08  tong
 * moving linux_tools(nintendo) from old tree to new tree.
 *
 * Revision 1.1  2003/03/11 03:38:48  tong
 * linux make tools from Nintendo
 *
 * Revision 1.8  1998-10-22 20:50:45+09  zelda
 * *** empty log message ***
 *
 * Revision 1.7  1998-04-15 21:00:03+09  hayakawa
 * バグとり
 *
 * Revision 1.6  1998-04-15 20:27:08+09  hayakawa
 * ワーニングをとった
 *
 * Revision 1.5  1998-04-15 19:00:19+09  hayakawa
 * 条件コンパイル消去
 *
 * Revision 1.4  1998-04-15 18:13:28+09  hayakawa
 * セグメントが1024を超えても動くようにした(2048まで)
 *
 * Revision 1.3  1997-08-28 14:07:46+09  hayakawa
 * ゼルダ用修正
 *
 * Revision 1.2  1997/08/22  13:45:44  hayakawa
 * szs対応
 *
 * Revision 1.1  1997/08/18  11:51:57  hayakawa
 * Initial revision
 *
 */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#define		MAX_FIL		0x00000800
#define		MAX_STR		0x00000400 /* 最大ファイル名長 */

typedef struct dma_rom_s {
    char                *rom_a;
    char                *rom_b;
    char                *rom_s;
    char                *rom_e;
} dma_rom_t;

typedef struct rom_data_s {
    struct rom_data_s	*next;
    unsigned long	sz;
    unsigned long	ad;
    char		fn[1];
} rom_data_t;

static dma_rom_t	dma_rom_tbl[MAX_FIL];
static size_t		dma_rom_number;
static rom_data_t	*rom_data_top = NULL;
static rom_data_t	*rom_data_num = 0;

/*======================================================================*
 *	ＤＭＡ アドレスデータを書く					*
 *======================================================================*/
static void dma_data_write(
    char	*const wfn
)
{
    FILE	*wfp;

    if ((wfp = fopen(wfn, "w")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", wfn);
	exit(1);
    }

    if (fwrite(dma_rom_tbl, sizeof(dma_rom_t), dma_rom_number, wfp) != dma_rom_number) {
	fprintf(stderr, "%s ファイルがライトできませんでした\n", wfn);
	exit(1);
    }

    fclose(wfp);
}

/*======================================================================*
 *	ＤＭＡ アドレスデータを読む(数を調べる)				*
 *======================================================================*/
static void dma_data_read(
    char	*const rfn
)
{
    FILE	*rfp;
    dma_rom_t *dma_rom;

    if ((rfp = fopen(rfn, "r")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", rfn);
	exit(1);
    }

    dma_rom_number = 0;
    dma_rom = dma_rom_tbl;
    while (fread(dma_rom, sizeof(dma_rom_t), 1, rfp) == 1) {
	dma_rom++;
	dma_rom_number++;
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
 *	ＲＯＭアドレス計算						*
 *======================================================================*/
static void dma_addr_set(void)
{
    int			i, j;
    char		*rnm, nm[MAX_STR], nm_szs[MAX_STR];
    FILE		*rfp;
    unsigned long	ad;
    int			flg;	/* !0:圧縮されている */
    rom_data_t  *rom_data;
    dma_rom_t *dma_rom;
    
    i = 0;
    ad = 0;
    dma_rom = dma_rom_tbl;
    rom_data = rom_data_top;
    while (rom_data != NULL) {
	strcpy(nm, rom_data->fn);
	j = (int)strlen(nm);
	nm[j - 1] = 's';
	nm[j    ] = 'z';
	nm[j + 1] = 'p';
	nm[j + 2] = '\0';
	
	strcpy(nm_szs, nm);
	j = (int)strlen(nm_szs);
	nm_szs[j - 1] = 's';

	if ((rfp = fopen(nm_szs, "r")) != NULL) {
	    flg = 1;
	    rnm = nm_szs;
	} else if ((rfp = fopen(nm, "r")) != NULL) {
	    flg = 1;
	    rnm = nm;
	} else if ((rfp = fopen(rom_data->fn, "r")) != NULL) {
	    flg = 0;
	    rnm = rom_data->fn;
	} else {
	    fprintf(stderr, "%s(.szs|.szp) ファイルがオープンできませんでした\n",
		    rom_data->fn);
	    exit(1);
	}

	dma_rom->rom_a = (char *)rom_data->ad;
	dma_rom->rom_b = (char *)rom_data->ad + rom_data->sz;
	dma_rom->rom_s = (char *)ad;

	fseek(rfp, 0, SEEK_END);
	ad += (unsigned long)ftell(rfp);
	fseek(rfp, 0, SEEK_SET);

	dma_rom->rom_e = (char *)((flg == 0) ? 0 : ad);

	fclose(rfp);

	printf("%3d:%08x %08x %08x %08x %8d ",i+1,
	       dma_rom->rom_a, dma_rom->rom_b,
	       dma_rom->rom_s, dma_rom->rom_e,
	       dma_rom->rom_b - dma_rom->rom_a);
	if (dma_rom->rom_e != 0) {
	    printf("%7d %6.2f%% ",
		   dma_rom->rom_e - dma_rom->rom_s,
		   (float)(dma_rom->rom_e - dma_rom->rom_s) /
		   (float)(dma_rom->rom_b - dma_rom->rom_a) * 100.0f);
	} else {
	    printf("******* ******* ");
	}
	printf("%s\n", rnm);

	++i;
	++dma_rom;
	rom_data = rom_data->next;
    }

    if (i + 1 >= (int)dma_rom_number) {
	fprintf(stderr, "dmadata.dがセグメント数に対して小さすぎます\n");
	fprintf(stderr, "あと %d 個以上のエントリを増やしてください(%d %d)\n",
		i - (int)dma_rom_number, i, (int)dma_rom_number);
	exit(1);
    }

    for (; i < (int)dma_rom_number; ++i) {
	dma_rom->rom_a = 0;
	dma_rom->rom_s = 0;
	dma_rom->rom_e = 0;
	dma_rom->rom_b = 0;
    }
}

/*======================================================================*
 *	メイン								*
 *======================================================================*/
extern int main(
    const int	argc,
    char	*argv[]
)
{
    if (argc != 3) {
	fprintf(stderr, "ＲＯＭマップとアドレステーブルを指定してください\n");
	exit(1);
    }

    rom_map_read(argv[1]);
    dma_data_read(argv[2]);
    dma_addr_set();
    dma_data_write(argv[2]);

    return 0;
}
