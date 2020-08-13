#!smake
SHELL=/bin/sh

.NOTPARALLEL:
.SUFFIXES: .c .o .rgba .inta .int
.rgba.c:
	txtcnv RGBA 32 $<
.inta.c:
	txtcnv IA 8 $<
.int.c:
	txtcnv I 4 $<
.c.o:
	$(CC) -c $(COPT) $<

VF3DEXOPT='-DF3DEX_GBI_2'
PATCH_DIR=/usr/local/srd/PR/patch/PR
LIBC64_DIR=/usr/local/srd/PR
COPT=-G 0 -fullwarn -xansi -Xcpluscomm -non_shared -mips2 -o32 -nostdinc -I$(PATCH_DIR) -I$(PATCH_DIR)/.. -I$(LIBC64_DIR) -I$(ZELDA_ROOT)/src -I/usr/local/srd/PR -I/usr/include/PR -I/usr/include -DF3DEX_GBI $(VF3DEXOPT)
LD=/usr/lib/PR/nld
CC=/usr/bin/cc

#rm -f *.o $out:t.oo $out:t.map

COMMON_OBJECTS = \
g_dd.o \
g_title_efc_1.o \
g_title_efc_2.o \
g_title_efc_3.o \
g_title_efc_4.o \
g_title_efc_5.o \
g_title_efc_6.o \
g_title_efc_7.o \
g_title_efc_8.o \
g_title_efc_9.o \
g_title_mable.o \
g_title_sub_1.o \
g_title_sub_2.o \
g_title_sub_j.o

default::zelda_mag.o zelda_mag_ura.o

zelda_mag.o:g_title.o g_title_cpr.o $(COMMON_OBJECTS)
	$(LD) -wall -r $(.ALLSRC) -o $(.TARGET) -m > $(.TARGET:.o=.map)

zelda_mag_ura.o:g_title_ura.o g_title_cpr_ura.o $(COMMON_OBJECTS)
	$(LD) -wall -r $(.ALLSRC) -o $(.TARGET) -m > $(.TARGET:.o=.map)

clean::clean_objects clean_sources
	rm -f *.c~
	rm -f *.map

clean_objects::
	rm -f g_dd.o g_title*.o *.oo

clean_sources::
	rm -f g_dd.c g_title*.c

g_title_mable.c:g_title_mable.int
	txtcnv I 8 $*.int

g_title_sub_1.c:g_title_sub_1.int
	txtcnv I 8 $*.int

g_title_sub_2.c:g_title_sub_2.int
	txtcnv I 8 $*.int

g_title_sub_j.c:g_title_sub_j.int
	txtcnv I 8 $*.int
