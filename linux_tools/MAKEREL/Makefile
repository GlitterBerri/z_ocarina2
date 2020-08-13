#!smake
#################################################################################
#																				#
#	Makefile for NINTENDO64 Relocation table creator							#
#																				#
#																				#
#################################################################################
MKDEPOPT  = -MDupdate $(MKDEPFILE)
MKDEPFILE = Makedepend

CCFLAGS   = $(MKDEPOPT)  -O -mips2 -xansi -signed -fullwarn -prototypes -Xcpluscomm -c
LDFLAGS   = $(MKDEPOPT)  -lelf


#################################################################################
#																				#
#	Code files																	#
#																				#
#################################################################################

SOUFILES = \
main.c \
readrel.c \
writeelf.c


#################################################################################
#																				#
#	Make default (gamesys.out)													#
#																				#
#################################################################################

APPFILE = makerel

default: $(APPFILE)


sinclude $(MKDEPFILE)

.SUFFIXES: .o .c

.c.o:
	cc $(CCFLAGS) $<

OBJFILES = $(SOUFILES:.c=.o)


$(APPFILE):	$(OBJFILES)
		cc -o $(APPFILE) $(OBJFILES) $(LDFLAGS)


#################################################################################
#																				#
#	Make cleanall																#
#																				#
#################################################################################

clean:
	rm $(OBJFILES) $(APPFILE)

# 通常ユーザがリンクできる場所にコピーする
#ifdef INSTALL_HOST
INSTALL_DIR = /auto/$(INSTALL_HOST)/usr/local/srd/PR
# 通常ユーザがリンクできる場所にコピーする
install:
	cp $(APPFILE) $(INSTALL_DIR)/.
#else
install:	$(HEADERS) $(TARGETS)
	make install INSTALL_HOST=srd99
	make install INSTALL_HOST=srd61
	make install INSTALL_HOST=srd65
	make install INSTALL_HOST=srd86
#endif
