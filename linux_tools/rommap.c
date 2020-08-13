/************************************************************************
 *									*
 *	ウルトラ６４のメモリーマップからＲＯＭマップをつくる		*
 *									*
 ************************************************************************/
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#define		MAX_FIL		0x00000800
#define		MAX_STR		0x00000400 /* 最大ファイル名長 */

typedef struct rom_data_s {
    char		fn[MAX_STR];
    unsigned long	ad;
    unsigned long	sz;
} rom_data_t;

char		m_map_tbl[MAX_FIL][MAX_STR];
rom_data_t	r_map_tbl[MAX_FIL];
rom_data_t	r_map_tbl_w[MAX_FIL];
unsigned long	makerom_s;
int		hex_flg;

/*======================================================================*
 *      ＲＯＭマップを表示                                              *
 *======================================================================*/
#define MAX_ROMSIZE              0x00FFFFFF
void r_map_write_d(void)
{
    int         i;
    int         total = 0;

    i = 0;
    fprintf(stdout, "address : filename (size)\n");
    fprintf(stdout, "--------+---------------------------------------\n");
    while (r_map_tbl[i].fn[0] != '\0') {
        fprintf(stdout, "%06Xh : %s  (%d byte)\n",
                r_map_tbl[i].ad, r_map_tbl[i].fn, r_map_tbl[i].sz);
        total += (int)r_map_tbl[i].sz;
        i += 1;
    }
    fprintf(stdout, "\ntotal = %d byte (%d byte  used %f %%)",
            total, total - MAX_ROMSIZE,
            (float)total / (float)MAX_ROMSIZE * 100.0F);
    if (total > MAX_ROMSIZE)
        fprintf(stdout, "          ### Memory Over !! ###");
    fprintf(stdout, "\n");
}

/*======================================================================*
 *	ＲＯＭマップを表示						*
 *======================================================================*/
void r_map_write(void)
{
    int		i;

    i = 0;
    while (r_map_tbl[i].fn[0] != '\0') {
	fprintf(stdout, "%s %X %X\n",
		r_map_tbl[i].fn, r_map_tbl[i].sz, r_map_tbl[i].ad);
	i += 1;
    }
}

/*======================================================================*
 *	メモリーマップをＲＯＭマップに変換				*
 *======================================================================*/
void m_r_map(void)
{
    int			i, j, k;
    int			flg;
    unsigned long	rom_ad = 0;

    i = 0;
    j = 0;
    strcpy(r_map_tbl_w[j].fn, "makerom.data");
    r_map_tbl_w[j].ad = 0x80000000;
    r_map_tbl_w[j].sz = makerom_s;
    j += 1;
    while (m_map_tbl[i][0] != '\0') {
	sscanf(m_map_tbl[i], ".%s %x %x\n",
	       r_map_tbl_w[j].fn, &r_map_tbl_w[j].ad, &r_map_tbl_w[j].sz);
	flg = 1;
	for(k = 0; k < j; k += 1) {
	    if (!strcmp(r_map_tbl_w[k].fn, r_map_tbl_w[j].fn)) {
		flg = 0;
		break;
	    }
	}
	j += flg;
	i += 1;
    }
    r_map_tbl_w[j].fn[0] = '\0';

    i = 0;
    j = 0;
    while (r_map_tbl_w[i].fn[0] != '\0') {
	strcpy(r_map_tbl[j].fn, r_map_tbl_w[i].fn);
	for(k = 0; k < MAX_STR && r_map_tbl_w[i].fn[k] != '\0'; k += 1) {
	    if (r_map_tbl_w[i].fn[k] == '.') {
		r_map_tbl[j].fn[k + 1] = 'd';
		r_map_tbl[j].fn[k + 2] = '\0';
		if (!strncmp(&r_map_tbl_w[i].fn[k], ".text", strlen(".text"))) {
		    r_map_tbl_w[i + 1].sz += r_map_tbl_w[i].sz;
		    i += 1;
		}
		r_map_tbl[j].sz = r_map_tbl_w[i].sz;
		r_map_tbl[j].ad = rom_ad;
		rom_ad += r_map_tbl[j].sz;
	    }
	}
	i += 1;
	j += 1;
    }
}

/*======================================================================*
 *	メモリーマップを読む						*
 *======================================================================*/
int chk_m_map(
    char	*const p
)
{
    int		i, j, k;
    char	f_name[MAX_STR];

    if (p[0] != '.') return 0;

    for(i = 1; i < MAX_STR && p[i] != '\0'; i += 1) {
	if (p[i] == '.') {
	    if (!strncmp(&p[i], ".data", strlen(".data"))) {
		sscanf(p, "%s %x %x\n", f_name, &j, &k);
		if (k != 0) {
		    return 1;
		} else {
		    return 0;
		}
	    }
	    if (!strncmp(&p[i], ".text", strlen(".text"))) {
		sscanf(p, "%s %x %x\n", f_name, &j, &k);
		if (k != 0) {
		    return 1;
		} else {
		    return 0;
		}
	    }
	    if (!strncmp(&p[i], ".sdata", strlen(".sdata"))) {
		sscanf(p, "%s %x %x\n", f_name, &j, &k);
		if (k != 0) {
		    fprintf(stderr, "%s のサイズが０ではありません\n", f_name);
		    exit(1);
		}
	    }
	}
    }

    return 0;
}

void m_map_read(
    char	*const rfn
)
{
    FILE	*rfp;
    int		i;

    if ((rfp = fopen(rfn, "r")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", rfn);
	exit(1);
    }

    i = 0;
    while (i < MAX_FIL) {
	if (fgets(m_map_tbl[i], MAX_STR - 1, rfp) == NULL) break;
	i += chk_m_map(m_map_tbl[i]);
    }
    m_map_tbl[i][0] = '\0';

    fclose(rfp);
}

/*======================================================================*
 *	メイン								*
 *======================================================================*/
int main(
    const int	argc,
    char	*argv[]
)
{
    switch(argc) {
    case 2:
	makerom_s = 0x00001050;
	hex_flg = 1;
	break;
    case 3:
	sscanf(argv[2], "%X", &makerom_s);
	hex_flg = 1;
	break;
    case 4:
	sscanf(argv[2], "%X", &makerom_s);
	sscanf(argv[3], "%X", &hex_flg);
	break;
    default:
	fprintf(
	    stderr,
	    "メモリーマップ ヘッダーサイズ ヘキサフラグ を 指定してください\n"
	);
	exit(1);
	break;
    }

    m_map_read(argv[1]);
    m_r_map();
    if (hex_flg == 1) {
	r_map_write();
    } else {
	r_map_write_d();
    }

    return 0;
}
