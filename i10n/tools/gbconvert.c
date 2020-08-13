#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{	
	FILE *fptr1, *fptr2; 
	unsigned char line[4096];
	int i=0;
	unsigned char header[]="{\\rtf1\\ansi\\ansicpg936\\uc2\\deff1\\stshfdbch13\\stshfloch0\\stshfhich0\\stshfbi0\\deflang1033\\deflangfe2052{\\fonttbl{\\f0\\froman\\fcharset0\\fprq2{\\*\\panose 02020603050405020304}Times New Roman;}{\\f1\\fswiss\\fcharset0\\fprq2{\\*\\panose 020b0604020202020204}Arial;} {\\f13\\fnil\\fcharset134\\fprq2{\\*\\panose 02010600030101010101}\\'cb\\'ce\\'cc\\'e5{\\*\\falt SimSun};}{\\f36\\fnil\\fcharset134\\fprq2{\\*\\panose 00000000000000000000}@\\'cb\\'ce\\'cc\\'e5;}{\\f38\\froman\\fcharset238\\fprq2 Times New Roman CE;}}";

	if (argc!=3) {
		printf("Usage: gbconvert <input rtf file> <output rtf file>\n");
		exit(0);
	}

	fptr2 = fopen (argv[2], "w");
	fprintf(fptr2, "%s\n", header);

	fptr1 = fopen (argv[1], "rb");
	fgets(line, 4095, fptr1);
	fgets(line, 4095, fptr1);
	fprintf(fptr2, "%s\n", line);
	fgets(line, 4095, fptr1);
	while (fgets(line, 4095, fptr1)) {
		for (i=0; i<strlen(line); i++) {
			if (line[i]>0xA0) {
				fprintf(fptr2, "\\\'%x\\\'%x", line[i], line[i+1]);
				i++;
			} else if (line[i+1]>0xA0) {
				fprintf(fptr2, "%c", line[i]);
				fprintf(fptr2, "\\fs32\\loch\\af13\\insrsid6489931 \\loch\\af13\\hich\\af1\\dbch\\f13");
			} else {
				fprintf(fptr2, "%c", line[i]);
			}
		}
	}

	fclose(fptr1);
	fclose(fptr2);
}



