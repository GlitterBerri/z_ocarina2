#
# $Id: gSRDdefs.mk,v 1.1 2003/03/14 03:27:04 tong Exp $
# 
# FORCE_CPPが定義されている場合は .c のファイルのコンパイルを c++で行う
#
# $Log: gSRDdefs.mk,v $
# Revision 1.1  2003/03/14 03:27:04  tong
# copied SRD dir from old tree to new tree.
#
# Revision 1.1  2003/02/16 08:53:58  blythe
# gnumake version of SRDdefs.mk
#
# Revision 1.8  2000-06-06 11:59:06+09  hayakawa
# *** empty log message ***
#
# Revision 1.7  1998-04-02 11:09:43+09  hayakawa
# .NOTPARALLELをデフォルトにした
# タグの作り方をスマートにした
#
# Revision 1.6  1997/07/08  05:42:00  hayakawa
# makerelのディレクトリ変更
#
# Revision 1.5  1997/05/21  10:26:51  hayakawa
# *** empty log message ***
#
# Revision 1.4  1997/04/09  12:22:55  hayakawa
# Makedependエントリの追加
# タグファイルのファイルを変更
#
# Revision 1.3  1997/03/05  10:38:52  hayakawa
# 大槻さんがgcc用に何か改造したらしい
#
# Revision 1.2  1997/03/05  10:34:18  hayakawa
# TAGSファイルの作り方を変更
#
# Revision 1.1  1997/02/05  11:10:13  hayakawa
# Initial revision
#

ifndef PARALLEL
.NOTPARALLEL:				# 並列動作を禁止
endif

#
# ディレクトリの設定
#
COMMON_DIR = $(ZELDA_ROOT)/srd/PR
COMMON_INCDIR = $(COMMON_DIR)
COMMON_LIBDIR = $(COMMON_DIR)

PATCH_DIR = 	$(ZELDA_ROOT)/srd/PR/patch/PR
PATCH_INCDIR = 	$(PATCH_DIR)
PATCH_LIBDIR = 	$(PATCH_DIR)

#SHELL = /bin/sh
RGB2CFLAGS =
HW_FLAGS = -D_HW_VERSION_2
MAKEREL = $(COMMON_DIR)/makerel
MAKERELOPT =
#if !(defined(GCC) || defined(__GCC__))
ifndef __GCC__
GC++DEFS = $(HW_FLAGS) -Wab,-r4300_mul
endif
#if (defined(GCC) || defined(__GCC__))		
ifdef __GCC__
WOFF=
GC++DEFS =  
CVERSION   = 
#MKDEPOPT = $(MKDEPFILE)
GCDEFS = $(HW_FLAGS) 
endif

### ＲＯＭをつくってすぐ実行 ###
gload:		rom
	gload -s rom
	@echo "'gload -n' で osSyncPrintf が表示されます"

### CFLAGS が長すぎて見辛いので省略してみました ###
ifdef FORCE_CPP
.c.o :
	@echo $(CXX) '$$(CXXFLAGS) -Dthis=_this -c' $<
	@$(CXX) $(CXXFLAGS) -Dthis=_this -c $<
.c.s :
	@echo $(CXX) '$$(CXXFLAGS) -Dthis=_this -S -c' $<
	@$(CXX) $(CXXFLAGS) -Dthis=_this -c -S $<
.c.i :
	$(CXX) $(CXXFLAGS) -Dthis=_this -E $< > $*.i
else
.c.o :
	@echo $(CC) '$$(CFLAGS) -c' $<
	@$(CC) $(CFLAGS) -c $<
.c.s :
	@echo $(CC) '$$(CFLAGS) -S -c' $<
	@$(CC) $(CFLAGS) -S -c $<
.c.i :
	$(CC) $(CFLAGS) -Dthis=_this -E $< > $*.i
endif
.cxx.o .C.o .c++.o :
	@echo $(CXX) '$$(CXXFLAGS) -c' $<
	@$(CXX) $(CXXFLAGS) -c $<
echo_cflags:
	@echo '$$(CFLAGS)= '$(CFLAGS)
	@echo '$$(CXXFLAGS)= '$(CXXFLAGS)

.SUFFIXES : .rel
.o.rel:	$(MAKEREL)
	$(MAKEREL) $(MAKERELOPT) $<

## Makedependから、システム系のヘッダ依存情報を削除することにより
## ライブラリ更新による全コンパイルを防ぐ
## /で始まるファイルを削除、`./'の削除 、複数の空白を１つにまとめる
Makedepend.new:Makedepend
	@sed -e "s| /[^ ]*||g" -e "s| \./| |g" -e "s| +| |g" Makedepend > Makedepend~tmp~
	@mv Makedepend Makedepend~`date '+%y-%m-%d_%H:%M:%S'`~
	@mv Makedepend~tmp~ Makedepend
Makedepend:
	touch Makedepend

TAGS_WORK:;	mkdir $@
###TAGS_WORK/%.h:     /usr/include/PR/%.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/gs2dex.h:     /usr/include/PR/gs2dex.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/gt.h:         /usr/include/PR/gt.h;		sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/gu.h:         /usr/include/PR/gu.h;		sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/leo.h:        /usr/include/PR/leo.h;		sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/leoappli.h:   /usr/include/PR/leoappli.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/libaudio.h:   /usr/include/PR/libaudio.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/n_libaudio.h: /usr/include/PR/n_libaudio.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/os.h:         /usr/include/PR/os.h;		sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/os_internal.h:/usr/include/PR/os_internal.h;	sed -e "s/\(extern .*\)\;/\1{}/" -e 's/extern "C" {/extern "C" \/*{*\//' $? > $@
TAGS_WORK/region.h:     /usr/include/PR/region.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/rmon.h:       /usr/include/PR/rmon.h;		sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/sched.h:      /usr/include/PR/sched.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/sp.h:         /usr/include/PR/sp.h;		sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/sptask.h:     /usr/include/PR/sptask.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAGS_WORK/ultralog.h:   /usr/include/PR/ultralog.h;	sed -e "s/\(extern .*\)\;/\1{}/" $? > $@
TAG:TAGS_WORK TAGS_WORK/gs2dex.h TAGS_WORK/gu.h TAGS_WORK/os.h TAGS_WORK/os_internal.h TAGS_WORK/region.h TAGS_WORK/sp.h TAGS_WORK/sptask.h
	etags --typedefs-and-c++ *.c
	etags --typedefs-and-c++ --append *.h
	etags --typedefs-and-c++ --append \
/usr/local/srd/PR/src/libbg/*.[ch] \
/usr/local/srd/PR/src/libu64/*.[ch] \
/usr/local/srd/PR/src/libc64/*.[ch]
	etags --typedefs-and-c++ --append \
/usr/local/srd/PR/patch/PR/*.h \
/usr/include/PR/*.h \
TAGS_WORK/*.h \
/usr/include/limits.h \
/usr/src/PR/libsrc/libultra/gu/*.c
