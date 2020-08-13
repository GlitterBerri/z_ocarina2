/********************************************************************************
					  NINTENDO64 Relocation table creator

								ELF output module

			 Copyright 1996 Nintendo co., ltd.  All rights reserved

								September 18, 1996
 ********************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libelf.h>
#include "makerel.h"


/****************************************
	Writes the following ELF file:

	ELFHeader
	Section 0	NULL
	Section 1	SYMTAB		.symtab
	Section 2	STRTAB		.shstrtab
	Section 3	STRTAB		.strtab
	Section 4	PROGBITS	.rodata
 ****************************************/


static int stringLength;				/* length of written string				*/

static long symbolTableOffset;			/* offset to the symbol table			*/
static long symbolTableSize;			/* size of the symbol table				*/

static long shnameTableOffset;			/* offset to the section name table		*/
static long shnameTableSize;			/* size of the section name table		*/

static long stringTableOffset;			/* offset to the string table			*/
static long stringTableSize;			/* size of the string table				*/

static long rodataSectionOffset;		/* offset to the rodata section			*/
static long rodataSectionSize;			/* size of the rodata section			*/

static long	sectionTableOffset;			/* offset to the section table			*/


static short nameSymtab;				/* index to the symtab section name		*/
static short nameShstrtab;				/* index to the shstrtab section name 	*/
static short nameStrtab;				/* index to the strtab table name		*/
static short nameRodata;				/* index to the rodata section name		*/


/********************************************************************************/
/*																				*/
/*	Store a string into the string buffer.										*/
/*																				*/
/********************************************************************************/
static int
WriteString(char *string, FILE *file)
{
	int code;
	int top = stringLength;

	stringLength += (strlen(string) + 1);

	while (code = *string++) {
		fputc(code, file);
	}
	fputc(code, file);
	return(top);
}
/********************************************************************************/
/*																				*/
/*	Create section name list.													*/
/*																				*/
/********************************************************************************/
static int
WriteSymbolTable(FILE *file, int size)
{
	Elf32_Sym symbol;


	symbolTableOffset = ftell(file);
	symbolTableSize	  = sizeof(Elf32_Sym) * 2;

	symbol.st_name	= 0;
	symbol.st_value	= 0;
	symbol.st_size	= 0;
	symbol.st_info	= ELF32_ST_INFO(STB_LOCAL, STT_NOTYPE);
	symbol.st_other	= 0;
	symbol.st_shndx	= SHN_UNDEF;
	fwrite((char *)&symbol, sizeof(Elf32_Sym), 1, file);

	symbol.st_name	= 1;
	symbol.st_value	= 0;
	symbol.st_size	= size;
	symbol.st_info	= ELF32_ST_INFO(STB_LOCAL, STT_SECTION);
	symbol.st_other	= 0;
	symbol.st_shndx	= 1;
	fwrite((char *)&symbol, sizeof(Elf32_Sym), 1, file);
}
/********************************************************************************/
/*																				*/
/*	Write symbol name.															*/
/*																				*/
/********************************************************************************/
static int
WriteSymbolName(FILE *file)
{
	stringTableOffset = ftell(file);
	stringLength	  = 0;

	WriteString("", file);
	WriteString(ELF_RODATA, file);

	stringTableSize = stringLength;
}
/********************************************************************************/
/*																				*/
/*	Create section name.														*/
/*																				*/
/********************************************************************************/
static int
WriteSectionName(FILE *file)
{
	shnameTableOffset = ftell(file);
	stringLength	  = 0;

	WriteString("", file);
	nameSymtab	 = WriteString(ELF_SYMTAB  , file);
	nameShstrtab = WriteString(ELF_SHSTRTAB, file);
	nameStrtab	 = WriteString(ELF_STRTAB  , file);
	nameRodata	 = WriteString(ELF_RODATA  , file);

	shnameTableSize = stringLength;
}
/********************************************************************************/
/*																				*/
/*	Create section name.														*/
/*																				*/
/********************************************************************************/
static void
WriteSectionHeader(FILE *file)
{
	Elf32_Shdr	header;


	sectionTableOffset = ftell(file);


	/* section 0 */

	header.sh_name		= 0;
	header.sh_type		= SHT_NULL;
	header.sh_flags		= 0;
	header.sh_addr		= 0;
	header.sh_offset	= 0;
	header.sh_size		= 0;
	header.sh_link		= SHN_UNDEF;
	header.sh_info		= 0;
	header.sh_addralign	= 0;
	header.sh_entsize	= 0;
	fwrite((char *)&header, sizeof(Elf32_Shdr), 1, file);


	/* symbol table section */

	header.sh_name		= nameSymtab;
	header.sh_type		= SHT_SYMTAB;
	header.sh_flags		= 0;
	header.sh_addr		= 0;
	header.sh_offset	= symbolTableOffset;
	header.sh_size		= symbolTableSize;
	header.sh_link		= 3;
	header.sh_info		= 2;
	header.sh_addralign = 4;
	header.sh_entsize	= sizeof(Elf32_Sym);
	fwrite((char *)&header, sizeof(Elf32_Shdr), 1, file);


	/* section header string table section */

	header.sh_name		= nameShstrtab;
	header.sh_type		= SHT_STRTAB;
	header.sh_flags		= 0;
	header.sh_addr		= 0;
	header.sh_offset	= shnameTableOffset;
	header.sh_size		= shnameTableSize;
	header.sh_link		= SHN_UNDEF;
	header.sh_info		= 0;
	header.sh_addralign = 1;
	header.sh_entsize	= 1;
	fwrite((char *)&header, sizeof(Elf32_Shdr), 1, file);


	/* string table section */

	header.sh_name		= nameStrtab;
	header.sh_type		= SHT_STRTAB;
	header.sh_flags		= 0;
	header.sh_addr		= 0;
	header.sh_offset	= stringTableOffset;
	header.sh_size		= stringTableSize;
	header.sh_link		= SHN_UNDEF;
	header.sh_info		= 0;
	header.sh_addralign = 1;
	header.sh_entsize	= 1;
	fwrite((char *)&header, sizeof(Elf32_Shdr), 1, file);


	/* data section */

	header.sh_name		= nameRodata;
	header.sh_type		= SHT_PROGBITS;
	header.sh_flags		= SHF_ALLOC;
	header.sh_addr		=  0;
	header.sh_offset	= rodataSectionOffset;
	header.sh_size		= rodataSectionSize;
	header.sh_link		= SHN_UNDEF;
	header.sh_info		= 0;
	header.sh_addralign = 16;
	header.sh_entsize	= 1;
	fwrite((char *)&header, sizeof(Elf32_Shdr), 1, file);
}
/********************************************************************************/
/*																				*/
/*	Write ELF header.															*/
/*																				*/
/********************************************************************************/
static void
WriteELFHeader(FILE *file)
{
	int			cnt;
	Elf32_Ehdr	header;

	for (cnt = 7; cnt < 16; cnt++) {
		header.e_ident[cnt] = 0;
	}
	header.e_ident[0]	= 0x7f;
	header.e_ident[1]	= 'E';
	header.e_ident[2]	= 'L';
	header.e_ident[3]	= 'F';
	header.e_ident[4]	= 1;			/* 32 bit	*/
	header.e_ident[5]	= 2;			/* MS bit	*/
	header.e_ident[6]	= 1;			/* version	*/

	header.e_phoff		= 0;
	header.e_type		= ET_REL;
	header.e_phnum		= 0;
	header.e_phentsize	= 0;
	header.e_shnum		= 5;
	header.e_machine	= EM_MIPS;
	header.e_version	= EV_CURRENT;
	header.e_entry		= 0;
	header.e_shoff		= 0;						/* fix up later		*/
	header.e_flags		= 0x10000000;				/* MIPS-2			*/
	header.e_ehsize		= sizeof(Elf32_Ehdr);
	header.e_shentsize	= sizeof(Elf32_Shdr);
	header.e_shstrndx	= 2;
	fwrite((char *)&header, sizeof(Elf32_Ehdr), 1, file);
}
/********************************************************************************/
/*																				*/
/*	Write data.																	*/
/*																				*/
/********************************************************************************/
static void
WriteData(FILE *file, char *data, int nbytes)
{
	ulong alignOffset;

	rodataSectionOffset = ftell(file);
	rodataSectionSize	= nbytes;
	alignOffset			= Alignment(rodataSectionOffset, 16);

	while (rodataSectionOffset < alignOffset) {
		fputc(0xff, file);
		rodataSectionOffset++;
	}
	fwrite(data, sizeof(char), nbytes, file);
}
/********************************************************************************/
/*																				*/
/*	Make a ELF file.															*/
/*																				*/
/********************************************************************************/
extern int
WriteELFFile(char *filename, char *data, int nbytes)
{
	FILE *file;

	if ((file = fopen(filename, "w")) == NULL) {
		perror(filename);
		return(FALSE);
	}
	WriteELFHeader(file);
	WriteSymbolTable(file, nbytes);
	WriteSectionName(file);
	WriteSymbolName(file);
	WriteData(file, data, nbytes);
	WriteSectionHeader(file);

	fseek(file, 32L, SEEK_SET);
	fwrite((char *)&sectionTableOffset, sizeof(ulong), 1, file);

	fclose(file);
	return(TRUE);
}
