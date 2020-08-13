/********************************************************************************
					  NINTENDO64 Relocation table creator

								  main module

			 Copyright 1996 Nintendo co., ltd.  All rights reserved

								September 18, 1996
 ********************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libelf.h>
#include "makerel.h"


static int majorVersion = 1;			/* mejor version number					*/
static int minorVersion = 0;			/* minor version number					*/

static ulong relocTableData[0x4000];	/* relocation table buffer				*/
static ulong relocTableSize;			/* relocation table size				*/

char verbose  = FALSE;
char showhelp = FALSE;

static char *objFname = NULL;
static char *relFname = NULL;

/********************************************************************************/
/*																				*/
/*	Print help.																	*/
/*																				*/
/********************************************************************************/
static void
PrintHelp(void)
{
	fprintf(stderr, "NINTENDO64 Relocation table creator  version %d.%02d\n", majorVersion, minorVersion);
	fprintf(stderr, "Usage: makerel [-h] [-v] [-o filename] objectfile\n");
	fprintf(stderr, "   -h: show this help\n");
	fprintf(stderr, "   -v: set verbose mode\n");
	fprintf(stderr, "   -o: set output file name\n\n");
}
/********************************************************************************/
/*																				*/
/*	Create file name.															*/
/*																				*/
/********************************************************************************/
static void
CreateFileName(char *newname, char *orgname, char *extend)
{
	char *extendp;

	strcpy(newname, orgname);
	extendp = strrchr(newname, '.');

	if (extendp == NULL)  strcat(newname, extend);
					else  strcpy(extendp, extend);
}
/********************************************************************************/
/*																				*/
/*	Create file name.															*/
/*																				*/
/********************************************************************************/
static int
CheckOption(int argc, char **argv)
{
	while (--argc > 0) {
		if (**++argv == '-') {
			switch ((*argv)[1]) {
				case 'v': verbose  = TRUE;						break;
				case 'h': showhelp = TRUE;						break;
				case 'o': if (--argc > 0)  relFname = *++argv;	break;
				default : showhelp = TRUE;						break;
			}
		}
		else if (objFname == NULL) {
			objFname = *argv;
		}
	}
	if (objFname == NULL || showhelp)  PrintHelp();

	return(objFname != NULL);
}
/********************************************************************************/
/*																				*/
/*	Main.																		*/
/*																				*/
/********************************************************************************/
extern int
main(int argc, char **argv)
{
	char filename[256];

	if (!CheckOption(argc, argv)) {
		exit(1);
	}
	if (elf_version(EV_CURRENT) == EV_NONE) {
		fprintf(stderr, "makerel: ELF library out of date.\n");
		exit(1);
	}
	if (!CreateRelocationTable(objFname, relocTableData, &relocTableSize)) {
		fprintf(stderr, "makerel: cannot read ELF file \"%s\"\n", *argv);
		exit(1);
	}
	if (relFname == NULL) {
		CreateFileName(filename, objFname, ".rel");
		relFname = filename;
	}
	if (!WriteELFFile(relFname, (char *)relocTableData, relocTableSize*sizeof(ulong))) {
		fprintf(stderr, "makerel: cannot write ELF file \"%s\"\n", filename);
		exit(1);
	}
	exit(0);
}
