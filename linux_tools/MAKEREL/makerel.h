/********************************************************************************
	makerel.h: NINTENDO64 Relocation table creator header file

	September 18, 1986
 ********************************************************************************/

#ifndef MAKEREL_H
#define	MAKEREL_H

#ifndef __sgi
/* get ulong, uint */
#include <sys/types.h>
#endif


/* boolean */
#define	FALSE	0
#define	TRUE	1

extern char verbose;
extern char showhelp;


#define	Alignment(addr,align)	(((uint)(addr) + ((align)-1)) & ~((align)-1))

extern int
CreateRelocationTable(char *filename, ulong *relocTableData, ulong *relocTableSize);

extern int
WriteELFFile(char *filename, char *data, int nbytes);

#ifndef __sgi
#define ELF_STRTAB	".strtab"
#define ELF_RODATA	".rodata"
#define ELF_SYMTAB	".symtab"
#define ELF_SHSTRTAB	".shstrtab"
#define ELF_TEXT	".text"
#define ELF_DATA	".data"
#define ELF_BSS		".bss"
#define ELF_REL_TEXT	".rel.text"
#define ELF_REL_DATA	".rel.data"
#define ELF_REL_RODATA	".rel.rodata"
#endif


#endif
