/********************************************************************************
	makerel.h: NINTENDO64 Relocation table creator header file

	September 18, 1986
 ********************************************************************************/

#ifndef MAKEREL_H
#define	MAKEREL_H


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


#endif
