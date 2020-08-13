/********************************************************************************
		      NINTENDO64 Relocation table creator

			relocation table creation module

	     Copyright 1996 Nintendo co., ltd.	All rights reserved

				September 24, 1996
 ********************************************************************************/

/*
 * $Log: readrel.c,v $
 * Revision 1.2  2003/05/24 04:20:34  blythe
 * mips-linux cross port
 *
 * Revision 1.1  2003/03/14 03:19:08  tong
 * moving linux_tools(nintendo) from old tree to new tree.
 *
 * Revision 1.1  2003/03/11 03:38:48  tong
 * linux make tools from Nintendo
 *
 * Revision 1.4  1997/05/21  10:32:52  hayakawa
 * *** empty log message ***
 *
 * Revision 1.3  1996/12/17  01:13:00  hayakawa
 * タブを８桁に変更
 *
 * Revision 1.2	 1996/12/17  01:07:21  hayakawa
 * dara->data
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libelf.h>
#include <fcntl.h>
#include <unistd.h>
#include "makerel.h"


#define SECTION_TEXT	    0x40000000
#define SECTION_DATA	    0x80000000
#define SECTION_RODATA	    0xC0000000


static short	secNameIndex;		/* section name section index			*/
static short	symNameIndex;		/* symbol name section index			*/


static int	    numSymbols;		/* number of symbols				*/
static Elf32_Sym *  symbolList;		/* pointer to the symbol list			*/


static int	    numTexts	= 0;	/* number of .text section relocations		*/
static int	    numDatas	= 0;	/* number of .data section relocations		*/
static int	    numRodatas	= 0;	/* number of .rodata section relocations	*/

static Elf32_Rel *  relocText;		/* pointer to the .text section relocation	*/
static Elf32_Rel *  relocData;		/* pointer to the .data section relocation	*/
static Elf32_Rel *  relocRodata;	/* pointer to the .rodata section relocation	*/

static ulong	    textSize	= 0;	/* size of text section				*/
static ulong	    dataSize	= 0;	/* size of data section				*/
static ulong	    rodataSize	= 0;	/* size of rodata section			*/
static ulong	    bssSize	= 0;	/* size of bss section				*/

/********************************************************************************/
/*										*/
/*  Data type name table.							*/
/*										*/
/********************************************************************************/

static char *dataTypeName[] = {
    "MIPS_NONE         ",   /*	0 */
    "MIPS_16           ",   /*	1 */
    "MIPS_32           ",   /*	2 */
    "MIPS_REL          ",   /*	3 */
    "MIPS_26           ",   /*	4 */
    "MIPS_HI16         ",   /*	5 */
    "MIPS_LO16         ",   /*	6 */
    "MIPS_GPREL        ",   /*	7 */
    "MIPS_LITERAL      ",   /*	8 */
    "MIPS_GOT          ",   /*	9 */
    "MIPS_PC16         ",   /* 10 */
    "MIPS_CALL         ",   /* 11 */
    "MIPS_GPREL32      ",   /* 12 */
    "MIPS_UNKNOWN      ",   /* 13 */
    "MIPS_UNKNOWN      ",   /* 14 */
    "MIPS_UNKNOWN      ",   /* 15 */
    "MIPS_SHIFT5       ",   /* 16 */
    "MIPS_SHIFT6       ",   /* 17 */
    "MIPS_64           ",   /* 18 */
    "MIPS_GOT_DISP     ",   /* 19 */
    "MIPS_GOT_PAGE     ",   /* 20 */
    "MIPS_GOT_OFST     ",   /* 21 */
    "MIPS_GOT_HI16     ",   /* 22 */
    "MIPS_GOT_LO16     ",   /* 23 */
    "MIPS_SUB          ",   /* 24 */
    "MIPS_INSERT_A     ",   /* 25 */
    "MIPS_INSERT_B     ",   /* 26 */
    "MIPS_DELETE       ",   /* 27 */
    "MIPS_HIGHER       ",   /* 28 */
    "MIPS_HIGHEST      ",   /* 29 */
    "MIPS_CALL_HI16    ",   /* 30 */
    "MIPS_CALL_LO16    ",   /* 31 */
    "MIPS_SCN_DISP     ",   /* 32 */
    "MIPS_REL16        ",   /* 33 */
    "MIPS_ADD_IMMEDIATE",   /* 34 */
    "MIPS_UNKNOWN      "    /* 35 */
};

/********************************************************************************/
/*										*/
/*  Store section size into the relocation table.				*/
/*										*/
/********************************************************************************/
static int
StoreSectionSize(ulong **dataHandle)
{
    ulong *dataPointer = *dataHandle;

    *dataPointer++ =   textSize;
    *dataPointer++ =   dataSize;
    *dataPointer++ = rodataSize;
    *dataPointer++ =	bssSize;
    *dataPointer++ = 0;			/* number of relocation datas	*/

    if (verbose) {
	printf("\nrelocation table\n\n");
	printf("size of .text   section = %08lx\n",   textSize);
	printf("size of .data   section = %08lx\n",   dataSize);
	printf("size of .rodata section = %08lx\n", rodataSize);
	printf("size of .bss    section = %08lx\n",    bssSize);
    }
    *dataHandle = dataPointer;
    return(5);
}

/********************************************************************************/
/*										*/
/*  Read relocate table.							*/
/*										*/
/********************************************************************************/
static int
StoreRelocationData(ulong **dataHandle, ulong section, char *secname, Elf *elf, Elf32_Rel *relocp, ulong ndatas)
{
    int	   counter     = 0;
    ulong *dataPointer = *dataHandle;


    while (ndatas-- > 0) {
	int sym	 = ELF32_R_SYM (relocp->r_info);
	int type = ELF32_R_TYPE(relocp->r_info);

	if (symbolList[sym].st_shndx != SHN_UNDEF) {
	    ulong   reldata  = (relocp->r_offset & 0x00ffffff) | ((type & 0x3f) << 24) | section;
	    char *  typename = dataTypeName[(type <= 34) ? type : 35];
	    char *  symname  = elf_strptr(elf, symNameIndex, symbolList[sym].st_name);

	    *dataPointer++ = reldata;
	    counter++;

	    if (verbose) {
		printf("%s: 0x%02lx  0x%08lx    %s  %s\n", 
		    secname, reldata>>24, reldata&0x00ffffff, typename, symname
		);
	    }
	}
	relocp++;
    }
    *dataHandle = dataPointer;
    return(counter);
}

/********************************************************************************/
/*										*/
/*  Store relocation table footer.						*/
/*										*/
/********************************************************************************/
static int
StoreTableFooter(ulong **dataHandle, int nheaders, int nrelocs)
{
    ulong * dataPointer = *dataHandle;
    ulong   totalsize	= nheaders + nrelocs + 1;
    ulong   alignsize	= Alignment(totalsize, 4);


    while (totalsize < alignsize) {
	*dataPointer++ = 0x00000000;
	totalsize++;
    }
    *dataPointer++ = totalsize * 4;
    *dataHandle	   = dataPointer;

    if (verbose) {
	putchar('\n');
	printf("number of relocation datas = %d\n", nrelocs   );
	printf("size of relocation table   = %ld\n", totalsize*4);
	putchar('\n');
    }
    return(totalsize);
}

/********************************************************************************/
/*										*/
/*  Write relocation table.							*/
/*										*/
/********************************************************************************/
static void
WriteRelocFile(Elf *elf, ulong *relocTableData, ulong *relocTableSize)
{
    int	    nheaders, nrelocs;
    ulong * nrelocsp;

    nheaders = StoreSectionSize(&relocTableData);
    nrelocsp = relocTableData - 1;

    if (verbose)  printf("\nsection: flag    offset        data type         symbol\n");

    nrelocs  = StoreRelocationData(&relocTableData, SECTION_TEXT  , ".text  ", elf, relocText  , numTexts  );
    nrelocs += StoreRelocationData(&relocTableData, SECTION_DATA  , ".data  ", elf, relocData  , numDatas  );
    nrelocs += StoreRelocationData(&relocTableData, SECTION_RODATA, ".rodata", elf, relocRodata, numRodatas);

    *nrelocsp	    = nrelocs;
    *relocTableSize = StoreTableFooter(&relocTableData, nheaders, nrelocs);
}














/********************************************************************************/
/*										*/
/*  Get symbol table.								*/
/*										*/
/********************************************************************************/
static void
GetSymbolTable(Elf *elf, Elf32_Shdr *secHeader, Elf_Scn *section)
{
    char *secname = elf_strptr(elf, secNameIndex, secHeader->sh_name);

    if (!strcmp(secname, ELF_SYMTAB)) {
	Elf_Data *secdata = elf_getdata(section, NULL);

	if ((secdata != NULL) && (secdata->d_type == ELF_T_SYM)) {
	    numSymbols = secdata->d_size / sizeof(Elf32_Sym);
	    symbolList = (Elf32_Sym *)secdata->d_buf;
	}
    }
}

/********************************************************************************/
/*										*/
/*  Get relocate table.								*/
/*										*/
/********************************************************************************/
static void
GetRelocateTable(Elf *elf, Elf32_Shdr *secHeader, Elf_Scn *section)
{
    Elf_Data *secdata = elf_getdata(section, NULL);

    if ((secdata != NULL) && (secdata->d_type == ELF_T_REL)) {
	char *secname = elf_strptr(elf, secNameIndex, secHeader->sh_name);

	//printf("secname=[%s]\n", secname);
	if (!strcmp(secname, ELF_REL_TEXT)) {
	    numTexts  = secdata->d_size / sizeof(Elf32_Rel);
	    relocText = (Elf32_Rel *)secdata->d_buf;
	}
	else if (!strcmp(secname, ELF_REL_DATA)) {
	    numDatas  = secdata->d_size / sizeof(Elf32_Rel);
	    relocData = (Elf32_Rel *)secdata->d_buf;
	}
	else if (!strcmp(secname, ELF_REL_RODATA)) {
	    numRodatas	= secdata->d_size / sizeof(Elf32_Rel);
	    relocRodata = (Elf32_Rel *)secdata->d_buf;
	}
    }
}

/********************************************************************************/
/*										*/
/*  Get section size.								*/
/*										*/
/********************************************************************************/
static void
SetSectionSize(Elf *elf, Elf32_Shdr *secHeader)
{
    char *secname = elf_strptr(elf, secNameIndex, secHeader->sh_name);

    if	    (!strcmp(secname, ELF_TEXT	))  textSize   = secHeader->sh_size;
    else if (!strcmp(secname, ELF_DATA	))  dataSize   = secHeader->sh_size;
    else if (!strcmp(secname, ELF_RODATA))  rodataSize = secHeader->sh_size;
    else if (!strcmp(secname, ELF_BSS	))  bssSize    = secHeader->sh_size;
}

/********************************************************************************/
/*										*/
/*  Get string section.								*/
/*										*/
/********************************************************************************/
static void
SetStringIndex(Elf *elf, Elf32_Shdr *secHeader, short index)
{
    char *secname = elf_strptr(elf, secNameIndex, secHeader->sh_name);

    if (!strcmp(secname, ELF_STRTAB))  symNameIndex = index;
}

/********************************************************************************/
/*										*/
/*  Open ELF.									*/
/*										*/
/********************************************************************************/
extern int
CreateRelocationTable(char *filename, ulong *relocTableData, ulong *relocTableSize)
{
    int file;
    int result = FALSE;


    if ((file = open(filename, O_RDONLY)) != -1) {
	Elf *elfArc = elf_begin(file, ELF_C_READ, NULL);

	if (elf_kind(elfArc) == ELF_K_ELF) {
	    Elf *elfFile = elf_begin(file, ELF_C_READ, elfArc);

	    if (elfFile != NULL) {
		Elf32_Ehdr *elfHeader = elf32_getehdr(elfFile);

		if (elfHeader != NULL) {
		    Elf_Scn *section = NULL;
		    short    index   = 1;

		    secNameIndex = elfHeader->e_shstrndx;
		    while ((section = elf_nextscn(elfFile, section)) != NULL) {
			Elf32_Shdr *secHeader = elf32_getshdr(section);

			switch (secHeader->sh_type) {
			    case SHT_SYMTAB  : GetSymbolTable  (elfFile, secHeader, section);	break;
			    case SHT_REL     : GetRelocateTable(elfFile, secHeader, section);	break;
			    case SHT_PROGBITS: SetSectionSize  (elfFile, secHeader	   );	break;
			    case SHT_NOBITS  : SetSectionSize  (elfFile, secHeader	   );	break;
			    case SHT_STRTAB  : SetStringIndex  (elfFile, secHeader, index  );	break;
			    default:
				//printf("secHeader->sh_type=[%lx]\n", (long)secHeader->sh_type);
				break;
			}
			index += 1;
		    }
		}
		WriteRelocFile(elfFile, relocTableData, relocTableSize);
		elf_end(elfFile);
		result	= TRUE;
	    }
	}
	elf_end(elfArc);
	close(file);
    }
    return(result);
}
