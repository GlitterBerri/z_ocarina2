/************************************************************************
 *									*
 *	ファイルサイズをアライメントする				*
 *	code by hayakawa 1997/8/18					*
 ************************************************************************/

/*
 * $Log: romalign.c,v $
 * Revision 1.1  2003/03/14 03:19:08  tong
 * moving linux_tools(nintendo) from old tree to new tree.
 *
 * Revision 1.1  2003/03/11 03:38:48  tong
 * linux make tools from Nintendo
 *
 * Revision 1.1  1997/08/18  11:51:27  hayakawa
 * Initial revision
 *
 */

#include	<stdio.h>
#include	<stdlib.h>

/*======================================================================*
 *	ファイルの長さを調整する					*
 *======================================================================*/
int AlignFileSize(
    char	*fn,
    int		align
)
{
#define GAPSIZE 16
    FILE	*fp;
    long	filelen;
    size_t	fillsize;
    static char gap[GAPSIZE];	/* allzero */

    if ((fp = fopen(fn, "rb")) == NULL) {
	return -1;
    }

    fseek(fp, 0, SEEK_END);
    filelen = ftell(fp);
    
    if (filelen % align == 0) {
	return 0;
    } else {
	if ((fp = freopen(fn, "a+b", fp)) == NULL) {
	    return -2;
	}
	fillsize = align - (filelen % align);
#if 0
	printf("fillsize=%d\n",fillsize);
	printf("align=%d\n",align);
	printf("filelen=%d\n",filelen);
	printf("(filelen %% align)=%d\n",(filelen % align));
	printf("align - (filelen %% align)=%d\n",align - (filelen % align));
#endif
	while (fillsize > GAPSIZE) {
	    if (fwrite(gap, GAPSIZE, 1, fp) != 1) {
		return -3;
	    }
	    fillsize -= GAPSIZE;
	}
	if (fillsize > 0) {
	    if (fwrite(gap, fillsize, 1, fp) != 1) {
		return -3;
	    }
	}
	fclose(fp);
	
	return (int)fillsize;
    }
}

/*======================================================================*
 *	メイン								*
 *======================================================================*/
int main(
    int		argc,
    char	*argv[]
)
{
    int align;
    int er, r;
    char **argvp;
    
    if (argc < 3) {
	fprintf(stderr, "romalign alignsize filename1 ...\n");
	exit(1);
    }
    
    argvp = argv + 1;
    align = atoi(*argvp++);
    er = 0;
    while (*argvp) {
	if ((r = AlignFileSize(*argvp, align)) < 0) {
	    fprintf(stderr, "%s ファイルがオープンできませんでした %d\n", *argvp, r);
	    er = 1;
	}
	argvp++;
    }
    
    return er;
}
