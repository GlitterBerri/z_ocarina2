/*
 * $Id: romfill.C,v 1.1 2003/03/14 03:19:08 tong Exp $
 *
 * ＲＯＭの残りを０ｘＦＦで埋める
 *
 * $Log: romfill.C,v $
 * Revision 1.1  2003/03/14 03:19:08  tong
 * moving linux_tools(nintendo) from old tree to new tree.
 *
 * Revision 1.1  2003/03/11 03:38:48  tong
 * linux make tools from Nintendo
 *
 * Revision 1.1  1998-10-22 20:48:54+09  hayakawa
 * Initial revision
 *
 */
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

#define		MAX_MEM		0x100000
#define         MIN(a, b)       ((a) >= (b) ? (b) : (a))

char	buffer[MAX_MEM];

/*======================================================================*
 *									*
 *	メイン								*
 *									*
 *======================================================================*/
int main(
    int		argc,
    char	*argv[]
)
{
    FILE	*rfp, *wfp;
    int		r_flg, r_size, rom_size, w_size, size;
    int		i;

    ios::sync_with_stdio();

    if(argc != 4) {
	fprintf(stderr,
		"ＲＯＭ ＩＮ と ＲＯＭ ＯＵＴ と サイズを指定してください\n");
	exit(1);
    }

    if((rfp = fopen(argv[1], "r")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", argv[1]);
	exit(1);
    }

    if((wfp = fopen(argv[2], "w")) == NULL) {
	fprintf(stderr, "%s ファイルがオープンできませんでした\n", argv[2]);
	exit(1);
    }

    if((r_size = fread(&buffer, sizeof(char), MAX_MEM, rfp)) != MAX_MEM) {
	for(i = r_size; i < MAX_MEM; i += 1) {
	    buffer[i] = (char)i;
	}
	r_flg = 0;
    } else {
	r_flg = 1;
    }
    w_size = size = atol(argv[3]);
    rom_size = r_size;

    while(fwrite(&buffer, sizeof(char), MIN(MAX_MEM, w_size), wfp)
	  == MIN(MAX_MEM, w_size)) {
	if(w_size > MAX_MEM) {
	    w_size -= MAX_MEM;
	} else {
	    break;
	}
	if(r_flg) {
	    if((r_size = fread(&buffer, sizeof(char), MAX_MEM, rfp))
	       != MAX_MEM) {
		for(i = r_size; i < MAX_MEM; i += 1) {
		    buffer[i] = (char)i;
		}
		r_flg = 0;
	    }
	    rom_size += r_size;
	} else if(r_size != 0) {
	    r_size = 0;
	    for(i = r_size; i < MAX_MEM; i += 1) {
		buffer[i] = (char)i;
	    }
	}
    }

    if(r_flg) {
	while((r_size = fread(&buffer, sizeof(char), MAX_MEM, rfp))
	      == MAX_MEM) {
	    rom_size += r_size;
	}
	rom_size += r_size;
    }
    if(rom_size > size) {
	fprintf(stderr, "ＲＯＭ サイズ オーバー %d\n", rom_size - size);
    } else {
	fprintf(stderr, "ＲＯＭ サイズ %d ---> %d\n", rom_size, size);
	fprintf(stderr, "残り %d\n", size - rom_size);
    }

    fclose(wfp);
    fclose(rfp);

    return 0;
}
