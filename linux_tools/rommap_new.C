/************************************************************************
 *									*
 *	デバック情報をもとにロムマップをつくる				*
 *				1997年 9月10日(水曜日) 14時53分27秒 JST	*
 ************************************************************************/

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATA {
    char		name[0x100];
    unsigned int	size;
    unsigned int	adr;
};

/*
 *	データ
 */
DATA	data[0x1000];

/*======================================================================*
 *	データの比較プログラム						*
 *======================================================================*/
int comp(
    const void	*d1,
    const void	*d2
)
{
    DATA	*p1, *p2;

    p1 = (DATA *)d1;
    p2 = (DATA *)d2;

    if(p1->adr < p2->adr) {
	return -1;
    }
    if(p1->adr > p2->adr) {
	return 1;
    }
    return 0;
}

/*======================================================================*
 *	メイン								*
 *======================================================================*/
int main(
    int		argc,
    char	*argv[]
)
{
    FILE	*fp;
    char	com[0x100], not_use[0x100];
    int		number, i;

    ios::sync_with_stdio();

    if(argc != 2) {
	cout << "メモリーマップを指定してください\n";
	exit(1);
    }

    sprintf(com, "egrep Rom %s", argv[1]);

    fp = popen(com, "r");

    strcpy(data[0].name, "makerom"); data[0].adr = 0; data[0].size = 0;
    number = 1;
    while(fscanf(fp, ".globl %s _%s = %x\n",
		 not_use, data[number].name, &data[number].adr)
	  != EOF) {
#if 0
	if (data[number - 1].size != data[number].adr - data[number - 1].adr) {
	    if (number - 1 != 0) {
		fprintf(stderr,
			"%sSegmentRomSize 修正 0x%08x → 0x%08x\n",
			data[number - 1].name,
			data[number - 1].size,
			data[number].adr - data[number - 1].adr);
	    }
	    data[number - 1].size = data[number].adr - data[number - 1].adr;
	}
#endif
	fscanf(fp, ".globl %s _%s = %x\n",
	       not_use, not_use, &data[number].size);
	
	data[number].name[strlen(data[number].name) - 15] = '\0';
	data[number].size = data[number].size - data[number].adr;
	if(data[number].size != 0) {
	    number += 1;
	}
    }
    data[0].size = data[1].adr;

    pclose(fp);

    qsort(data, number, sizeof(DATA), comp);

    for(i = 0; i < number; i += 1) {
	printf("%s.d %x %x\n", data[i].name, data[i].size, data[i].adr);
    }
}
