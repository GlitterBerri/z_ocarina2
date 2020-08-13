#!smake
#
# make clobber のあとや、co spec_ovl のあとに以下の make を実行してください
# make genfiles
#
# $Id: GNUmakefile,v 1.1 2003/03/20 05:52:06 wheeler Exp $
#
# ６４ゼルダ用メイクファイル
#
# 通常 nloadバージョンのメイク：make rom_d
# ＲＯＭ焼きバージョンのメイク：make rom_x
# 最終ＲＯＭバージョンのメイク：make rom_f
# ショウバージョンのメイク：make rom_s
# 
#
# make "VMAKEOPT=" ; コンパイル/makeromオプション追加
# make "VMAKEROMOPT=" ; makeromオプション追加
# make "VMAKEOPTION=" ; makeオプション追加
#
#
#
# make -n ; makeすると実行されるコマンドを表示する
#
#
# RAM8Mバージョン：make "RAM8M="
# malloc用ヒープサイズ変更：make "VMAKEOPT=-DSYS_HEAP_SIZE=0x240000"
# fifoサイズ変更：make "VMAKEOPT=-DSYS_FIFO_SIZE=0x2000"
#
# make clean ; rm -rf *.[ou] a.out core lex.yy.[co] y.tab.[cho] _force ar.tmp.*
# make clobber ; 上記に加えて $(TARGETS) MakeDepend をも消す
# make rmtargets ; $(TARGETS) だけを消す
#
# パートナーＮ６４立ち上げ例
# setenv PTSRC ../:/home/hayakawa/prj/PR/libc64/:/home/hayakawa/prj/PR/libu64/:/home/hayakawa/prj/PR/libbg/:/usr/src/PR/libultra/gu/
# ptnet -host partner2 -fn rk24 -jfn k24 -fg white -bg black -width 80 -height 40 /usr/local/partner-net/n64/nptn64 -EUC
#
# z_actor_h.h を触るとどれだけのファイルが影響を受けるかを調べるには
# grep z_actor_h.h rom_d/Makedepend | cut -d: -f1
#


ifndef PARALLEL
.NOTPARALLEL:				# 並列動作を禁止
endif
.PATH: ..				# rom_?ディレクトリからソースを見るため
VPATH=..
.SUFFIXES :				# メイク開始までの化時間短縮
.SUFFIXES : .c .h .s .o .i		# 必要なサフィックス

## 標準関数ライブラリ
N64KITDIR    = /usr/local/n64kit
NUSTDINCDIR  = $(N64KITDIR)/nustd/include
#NUSTDLIBDIR  = $(N64KITDIR)/nustd/lib
NUSTDLIBDIR  = $(ROOT)/usr/lib


## デバッグレベル(予定)
## 0: 完全製品用 プリント不可
## 1: 製品用     osSyncPrintfのみ
## 2: ショウ用   osSyncPrintfのみ
## 3: 撮影用     PRINTF可
## 4: マリオクラブ初期デバッグ用
## 5: 通常開発用 重要なメッセージのみ表示
## 6: 通常開発用 一般的なメッセージの表示
## 7: テスト開発用  メッセージがちょっとうるさい
## 8: デバッグ調査用  ゲームが引っ掛かるほどメッセージがうるさい
## 9: システムデバッグ用  ゲームが止まるほどメッセージがうるさい
## DEBUG_LEVEL = 6

## cc / makerom のオプション

## DD用につくったデータをロム版に組み込む
## make -k "VMAKEOPTION=USE_NEW_DUNGEON=" rom_d

ifdef USE_NEW_DUNGEON
LMAKEOPT += -DUSE_NEW_DUNGEON
endif

## z_player.[ch] の残骸消したら消す
LMAKEOPT += -DHAYAKAWA_TESTks2

## 販売地域
LMAKEOPT += -DFOR_JAPAN -DFOR_USA


##LMAKEOPT += -DGRAPH_OLD_VERSION
##LMAKEOPT += -D_graph=__graph

LMAKEOPT += -DNOUSE_LINE_UCODE		# LineUcodeは使わない
###LMAKEOPT += -DZURUMODE=2		# ２コン挿さっていたらずるモード
LMAKEOPT += -DPLAY_ADJUST		# GAME_PLAY追加テスト用
LMAKEOPT += -DOPTIMIZE_NEXT_DISP	# NEXT_DISPの高速化
LMAKEOPT += -DUSE_DEBUG_MODE
ifdef USE_N64DD
LMAKEOPT += -DJPN_CASSETTE_BOOT -DOVERLAY_PRG -DMULTICOUNTRY # 64DD対応
###LMAKEOPT += -DDD_SYNCHRO # 同期処理
LMAKEOPT += -DUSE_DD_WRITE  # 一応
endif
#LMAKEOPT+= -DHAYAKAWA_TEST=1 -DRAM4M -DSYS_FIFO_SIZE=0x8000

## make のオプション

ifdef ROM_D
LMAKEOPT += -DROM_D
LMAKEOPT += -DZURUMODE=2
LMAKEOPT += "-DU_${USER}_U"
endif
ifdef ROM_X
LMAKEOPT += -DROM_X
LMAKEOPT += -DZURUMODE=2
endif
ifdef ROM_F
LMAKEOPT += -DROM_F
LMAKEOPT += -DZURUMODE=0
endif
ifdef ROM_S
LMAKEOPT += -DROM_S
LMAKEOPT += -DZURUMODE=2
endif
ifdef FINAL_ROM
LMAKEOPT += -DFINAL_ROM
endif

ifdef ROM_ROM
LMAKEOPT +=	-DROM_ROM=1			# ＲＯＭ焼き用のコードを吐く
endif
ifdef EMU_ROM
LMAKEOPT +=	-DEMU_ROM=1			# ボード用のコードを吐く
endif
ifdef PARTNER
LMAKEOPT +=	-DPARTNER=1			# パートナー用のコードを吐く
endif
ifdef ISVIEWER
LMAKEOPT +=	-DISVIEWER=1			# ISVIEWER用のコードを吐く
endif

## z_playオーバーレイ化
ifdef RAM8M
LMAKEOPT += -DRAM8M
endif

## HIRATSU Daisuke modified under lines.
LMAKEOPT += -DUSE_CIC6105_NOCHECK=


ifdef USE_N64DD
LMAKEOPT += -DUSE_N64DD
endif
ifdef USE_LEOEMU
LMAKEOPT += -DUSE_LEOEMU
endif
ifdef USE_COUNT
LMAKEOPT += -DUSE_COUNT
endif

ifdef USE_LOCALE
LMAKEOPT += -DUSE_LOCALE
endif
ifdef USE_DEBUG_MALLOC
LMAKEOPT += -DUSE_DEBUG_MALLOC
endif
ifdef SCENE_TOOL
LMAKEOPT += -DSCENE_TOOL
endif
ifdef SCENE_TOOL2
endif
ifdef DEBUG_CAMERA
LMAKEOPT += -DDEBUG_CAMERA
endif
ifdef PAL_VERSION
LMAKEOPT += "-DPAL_VERSION"
endif
ifdef GATEWAY_VERSION
LMAKEOPT += -DGATEWAY_VERSION
LMAKEOPT += -DSYS_GATEWAY_N64
endif

ifdef VIDEO_AUTO
LMAKEOPT += "-DVIDEO_AUTO"
else
ifdef PAL_VERSION
LMAKEOPT += "-DVIDEO_PAL"
else
LMAKEOPT += "-DVIDEO_NTSC_OR_MPAL"
endif
endif


include $(ROOT)/usr/include/make/PRdefs
ifdef HAYAKAWA_LIB
include /home/hayakawa/prj/PR/COMMON/SRDdefs.mk
else
##include $(ROOT)/usr/local/srd/PR/SRDdefs.mk
include $(ZELDA_ROOT)/srd/PR/gSRDdefs.mk
endif
include $(COMMONRULES)
#ifdef __GCC__
#include $(ROOT)/usr/include/make/gccdefs
#endif

#
# ディレクトリの設定
#
ZELDA_LIB =	$(ZELDA_ROOT)/lib
ZELDA_TOOL =	$(ZELDA_ROOT)/tool/bin
ZELDA_DATA =	$(ZELDA_ROOT)/data
ZELDA_AUDIO =   $(ZELDA_LIB)/audio

#SHELL 		= $(ROOT)/bin/sh
#LD 		= $(ROOT)/usr/lib/PR/nld
MAKEMASK 	= $(ROOT)/usr/sbin/makemask
ifdef USE_CIC6105
    ifdef ROM_D
VERSUM 		= $(ZELDA_LIB)/CIC6105/981001/versum
    endif
endif
NRDC 		= $(ZELDA_LIB)/NRDC/nrdc/nrdc

TARGETS = romPP_d

ifdef HAYAKAWA_LIB_TEST
HAYAKAWA_LIB =
endif

ZELDA_INFO =    zelda_makerom.stdout

ifdef __GCC__XXX
MKDEPOPT=
LLDOPTS  = 
else
LLDOPTS  = $(MKDEPOPT)
LLDOPTS  = 
endif
LLDOPTS += --no-warn-mismatch
ifdef HAYAKAWA_LIB
PATCH_DIR = /home/hayakawa/prj/PR/COMMON/patch/PR
PATCH_INCDIR = $(PATCH_DIR)
PATCH_LIBDIR = $(PATCH_DIR)
endif
LCINCS = \
-I$(PATCH_INCDIR) \
-I$(PATCH_INCDIR)/.. \
-I$(ZELDA_LIB)
LLDOPTS += \
-L$(PATCH_LIBDIR)
ifdef HAYAKAWA_LIB
LCINCS += \
-I/home/hayakawa/prj/PR/libu64 \
-I/home/hayakawa/prj/PR/libc64
LLDOPTS += \
-L/home/hayakawa/prj/PR/libu64 \
-L/home/hayakawa/prj/PR/libc64
endif
LCINCS += \
-I$(COMMON_INCDIR) \
-I$(ROOT)/usr/include/PR \
-I$(NUSTDINCDIR)
LLDOPTS +=  \
-L$(ZELDA_LIB)/audio \
-L$(COMMON_LIBDIR) \
-L$(ROOT)/usr/lib/PR \
-L$(NUSTDLIBDIR)


### ウルトラライブラリの選択
ifdef ROM_ROM
ULTRALIB_BASE = ultra_rom
endif
ifdef ISVIEWER
ULTRALIB_BASE = ultra_rom
endif
ifdef EMU_ROM 
ULTRALIB_BASE = ultra
endif
ifdef PARTNER
ULTRALIB_BASE = ultra
endif
ULTRALIB = -l$(ULTRALIB_BASE)
## ULTRALIB_FULLPATH = $(PATCH_LIBDIR)/lib$(ULTRALIB_BASE).a
ULTRALIB_FULLPATH = $(ROOT)/usr/lib/lib$(ULTRALIB_BASE).a
ULTRALIB2 = libultra2.a

LEOEMULIBDIR = $(ZELDA_LIB)/ISV/tool/lib
LEOLIBDIR = $(ROOT)/usr/lib

ifdef ROM_ROM
U64LIB_BASE = u64_rom
C64LIB_BASE = c64_rom
NUSLIB_BASE = nustd
else #/* EMU_ROM */
U64LIB_BASE = u64_d
C64LIB_BASE = c64_d
NUSLIB_BASE = nustd_d
endif
LEOLIB_BASE = leo
LEOEMULIB_BASE = leoemu

U64LIB    = -l$(U64LIB_BASE)
C64LIB    = -l$(C64LIB_BASE)
NUSLIB    = -l$(NUSLIB_BASE)
LEOEMULIB = -l$(LEOEMULIB_BASE)
LEOLIB    = -l$(LEOLIB_BASE)

ifdef HAYAKAWA_LIB
U64LIB_FULLPATH = /home/hayakawa/prj/PR/libu64/lib$(U64LIB_BASE).a
C64LIB_FULLPATH = /home/hayakawa/prj/PR/libc64/lib$(C64LIB_BASE).a
else
U64LIB_FULLPATH = $(COMMON_LIBDIR)/lib$(U64LIB_BASE).a
C64LIB_FULLPATH = $(COMMON_LIBDIR)/lib$(C64LIB_BASE).a
endif
NUSLIB_FULLPATH = $(NUSTDLIBDIR)/lib$(NUSLIB_BASE).a
LEOLIB_FULLPATH = $(LEOLIBDIR)/lib$(LEOLIB_BASE).a
LEOEMULIB_FULLPATH = $(LEOEMULIBDIR)/lib$(LEOEMULIB_BASE).a

U64LIB2    = libu642.a
C64LIB2    = libc642.a
NUSLIB2    = libnustd2.a
LEOLIB2    = libleo2.a
LEOEMULIB2 = libleoemu2.a

#
# ファイルの設定
#
include $(ZELDA_ROOT)/src/GNUmakefile.CFILES			# CFILES の定義
include $(ZELDA_ROOT)/src/GNUmakefile.DISK			# DISK 版の定義

C++FILES =	
COBJECTS        = 	$(CFILES:.c=.o)
COBJECTS_EN     = 	$(CFILES_EN:.c=.o)
COBJECTS_EFF    = 	$(CFILES_EFF:.c=.o)
COBJECTS_Z      = 	$(CFILES_Z:.c=.o)
COBJECTS_SYS    = 	$(CFILES_SYS:.c=.o)
COBJECTS_BOOT   = 	$(CFILES_BOOT:.c=.o)
ifdef USE_N64DD
COBJECTS_N64DD   = 	$(CFILES_N64DD:.c=.o)
endif #/* USE_N64DD */
C++OBJECTS      = 	$(C++FILES:.c++=.o)
C++OBJECTS_EN   = 	$(C++FILES_EN:.c++=.o)
C++OBJECTS_EFF  = 	$(C++FILES_EFF:.c++=.o)
C++OBJECTS_Z    = 	$(C++FILES_Z:.c++=.o)
C++OBJECTS_SYS  = 	$(C++FILES_SYS:.c++=.o)
C++OBJECTS_BOOT = 	$(C++FILES_BOOT:.c++=.o)
ifdef USE_N64DD
C++OBJECTS_N64DD = 	$(C++FILES_N64DD:.c++=.o)
endif #/* USE_N64DD */

COBJECT_EN  = cobject_en.o
COBJECT_EFF = cobject_eff.o
COBJECT_Z   = cobject_z.o
COBJECT_SYS = cobject_sys.o
COBJECTS    = $(COBJECTS_EN) $(COBJECTS_EFF) $(COBJECTS_Z) $(COBJECTS_SYS)

CODEOBJECTS = \
	$(COBJECTS) \
	$(C++OBJECTS) \
	$(ZELDA_LIB)/z_fault.o \
	$(ZELDA_LIB)/faultprint.o \
	$(KANJIDATA1)

ifdef USE_VOLCULL
CODEOBJECTS += $(ZELDA_LIB)/volcull.o
endif
ifdef USE_COUNT
CODEOBJECTS += $(ZELDA_LIB)/count.o
endif

ifdef PAL_VERSION

ifdef ROM_D
    ifdef ROM_X
    CODEOBJECTS +=	$(ZELDA_LIB)/audio/debug_audio_pal.o 
    else
    CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio_pal.o 
    endif
else
CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio_pal.o 
endif

else #/* PAL_VERSION */

ifdef ROM_D
    ifdef ROM_X
    CODEOBJECTS +=	$(ZELDA_LIB)/audio/debug_audio.o 
    else
    CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio.o 
    endif
else
CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio.o 
endif

endif #/* PAL_VERSION */

AUDIOOBJECTS =	\
	$(ZELDA_AUDIO)/aspMain.o \
	$(ZELDA_AUDIO)/audio.o \
	$(ZELDA_AUDIO)/audio_hb.o \
	$(ZELDA_AUDIO)/audio_hm.o \
	$(ZELDA_AUDIO)/audio_hs.o \
	$(ZELDA_AUDIO)/audio_hw.o \
	$(ZELDA_AUDIO)/audiotable.o \
	$(ZELDA_AUDIO)/audioheap.o

BOOTOBJECTS = \
	$(COBJECTS_BOOT) \
	$(C++OBJECTS_BOOT)

ifdef USE_N64DD
N64DDOBJECTS = \
	$(COBJECTS_N64DD) \
	$(C++OBJECTS_N64DD)
endif #/* USE_N64DD */

# KSEG0空間のデータ
DATAFILES = \
	last.c \
	sys_cfb.c \
	sys_dram_stack.c \
	sys_dynamic.c \
	sys_fifo_buffer.c \
	sys_heap.c \
	sys_yield_buffer.c \
	sys_zb.c \
	z_std_dma_data.c

DATAFILES += nullsegment.c

# Segment空間のデータ
DATAFILES += \
	rcp_cfb.c \
	rcp_zb.c \
	z_hilite.c
DATAOBJECTS =	$(DATAFILES:.c=.o)

AUDIOSEGMENT =	audiosegment.o
BOOTSEGMENT =	bootsegment.o
CODESEGMENT =	codesegment.o
ifdef USE_N64DD
N64DDSEGMENT =	n64ddsegment.o
endif #/* USE_N64DD */
KANJIDATA1 = 	kanread.o
KANJIDATA2 =	kan.o

OBJECTS =	$(BOOTSEGMENT) $(CODESEGMENT)
ifdef USE_N64DD
OBJECTS +=	$(N64DDSEGMENT)
endif #/* USE_N64DD */
# if defined(PAL_VERSION)
OBJECTS +=	$(DATAOBJECTS)
# else
OBJECTS +=	$(DATAOBJECTS) $(KANJIDATA2)
# endif

##LMAKEOPT = -UUSE_PRERENDER
LMAKEOPT +=	-DF3DEX_GBI 			# 開発３部のマイクロコードを使用する
LMAKEOPT +=	-DF3DEX_GBI_2 			# 開発３部のマイクロコードを使用する
LMAKEOPT +=	-DUSE_VISCVG			# カバレッジの可視表示
ifdef ROM_S
LMAKEOPT +=     -DROM_S
LMAKEOPT +=	-DSHOW_VERSION			# ショウバージョン用のコードを吐く
LMAKEOPT +=	-DDEBUG_MODE_NOINPUT		# デバッグレジスタを出さない
LMAKEOPT +=	-DDISABLE_FAULT_DISPLAY		# HungUpを出さない
endif
ifdef ROM_F
LMAKEOPT +=     -DROM_F
LMAKEOPT +=     -DFINAL_ROM
####マリオクラブデバッグ時はHungUpを出すようにする
####LMAKEOPT +=	-DDISABLE_FAULT_DISPLAY		# HungUpを出さない
LMAKEOPT +=	-DDEBUG_MODE_NOINPUT		# デバッグレジスタを出さない
LMAKEOPT +=	-DNOUSE_DEBUG_PAD		# デバッグ用コントローラパッドを使用しない
endif

ROM_F_OR_S=0
ifdef ROM_F
ROM_F_OR_S=1
endif
ifdef ROM_S
ROM_F_OR_S=1
endif

ifeq (ROM_F_OR_S, 1)
OPTIMIZER = 	-O2 -g3				# 速く・小さく
LMAKEOPT +=	-DROM_VERSION=1			# 実機用ＲＯＭの作成
LMAKEOPT +=	-DNOUSE_PRINTF -DPRINTF_with_Warning_609 # PRINTFを使わない
LMAKEOPT +=	-DDEBUG=0			# put8x8用
LMAKEOPT +=	-DNDEBUG 			# assertを殺す
LMAKEOPT +=	-DUSE_TIMER=0 			# 処理時間を計測しない
LMAKEOPT +=	-D_ODEBUG 			# デバッグモード.とると z_camera.c がエラーになるので取りあえず入れてある（小川さん）
else
 ifdef ROM_X
OPTIMIZER = 	-O2 -g3				# 速く・小さく
LMAKEOPT +=	-DROM_VERSION=1			# 実機用ＲＯＭの作成
LMAKEOPT +=	-DNOUSE_PRINTF -DPRINTF_with_Warning_609 # PRINTFを使わない
 else
OPTIMIZER = 	-O2 -g3				# 普通にオプティマイズ、デバッガ使う
LMAKEOPT +=	-DROM_VERSION=0			# エミュレータボード用
LMAKEOPT +=	-UNOUSE_PRINTF			# PRINTFを使う
 endif
LMAKEOPT +=	-DDEBUG=1			# lib*_d.aを使用する
LMAKEOPT +=	-DUSE_DEBUG_MOJI		# puts8x8用
LMAKEOPT +=	-DUSE_TIMER=1 			# 処理時間を計測する
LMAKEOPT +=	-D_ODEBUG 			# デバッグモード.とると z_camera.c がエラーになる
endif
LMAKEOPT +=	-DUSE_FAULT=1 			# 画面にフォルトメッセージが出る
LMAKEOPT +=	-UUSE_RMON			# rmonスレッドを起動しない

ifdef RAM8M
    ifdef ROM_D
    LMAKEOPT +=	-DUSE_SEGMENT_NAME_TABLE
    endif
    ifndef ROM_F
    LMAKEOPT +=	-DUSE_ACTOR_NAME_TABLE
    endif
endif


LLDLIBS_CODE += $(U64LIB2) $(C64LIB2)
#if 0
#LLDLIBS_CODE += $(ZELDA_LIB)/ucode/us2dexNew.o
#endif
LLDLIBS_CODE += $(ZELDA_LIB)/ucode/libjpg.a
####LLDLIBS_CODE += $(ZELDA_LIB)/audio/libgsmp.a
LLDLIBS_CODE += $(ULTRALIB2) $(NUSLIB2)

LLDLIBS_BOOT += $(ZELDA_LIB)/driverominit.o	## なんてこったい！
LLDLIBS_BOOT += $(ZELDA_LIB)/slidV10.o
LLDLIBS_BOOT += -L$(ROOT)/usr/lib $(U64LIB) $(C64LIB) 
ifdef USE_N64DD
ifdef USE_LEOEMU
LLDLIBS_BOOT += $(LEOEMULIB2)
LLDLIBS_BOOT += $(LEOLIB2)
endif
endif
ifdef __GCC__XXX
LLDLIBS_BOOT += -lgultra_d $(NUSLIB) $(GCCDIR)/mipse/lib/libkmc.a
else
LLDLIBS_BOOT += $(ULTRALIB) $(NUSLIB)
endif
LLDLIBS_BOOT += -u__umoddi3 -u__udivdi3 -u__divdi3 -lgcc

###LLDLIBS_N64DD = $(ZELDA_LIB)/driveexist/driveexist.o.leo
ifdef USE_N64DD
ifndef USE_LEOEMU
LLDLIBS_N64DD += $(LEOLIB2)
endif
endif


##cfe: Warning 813:: struct/union/enum '' is used, but not defined
##cfe: Warning 828:: '' may be indistinguishable from '' due to internal name truncation
##cfe: Warning 852:: '' can be const qualified, since it is not set within its lifetime.
##cfe: Warning 814:: static '' unused
##cfe: Warning 819:: function parameter '' is not used in function ''
##cfe: Warning 820:: '' is not used in function ''
##cfe: Warning 821:: '' set but unused in function ''
##cfe: Warning 827:: implicit conversion from '' to ''
##cfe: Warning 828: /usr/include/PR/libaudio.h, line 467: 'AL_MIDI_SongPositionPointer' may be indistinguishable from 'AL_MIDI_SysEx' due to internal name truncation
#WOFF=-woff 1685,515,608,658,799,803,852,1048,1233,1499$(LWOFF)
ifdef WARNLEVEL1
LWOFF = 	828,852,813
else
 ifdef WARNLEVEL2
 LWOFF = 	813,828,852,814,819,820,821,827
 else
  ifdef WARNLEVEL3
  LWOFF = 	1685,515,608,658,799,803,852,1048,1233,1499,813,828,852,814,819,820,821,827
  else
###LWOFF = 	813,828,852,827
  LWOFF = 	813,828,852,827,609
  endif
 endif
endif
ifndef __GCC__
WOFF = -woff $(LWOFF)$(VWOFF)
endif


MAKEOPT = $(GMAKEOPT) $(LMAKEOPT) $(VMAKEOPT)

#LCINCS =
LASINCS =	$(LCINCS)
LCDEFS += $(MAKEOPT)
ifdef __GCC__
LCOPTS = -Wall -W -G 0
LASOPTS = 	-G 0
else
LCOPTS = -non_shared -G 0 -mips2 -fullwarn -float -xansi -Xcpluscomm -wlint,-fhp
LASOPTS =	-non_shared -G 0
endif

LC++DEFS =	$(LCDEFS)
LC++INCS =	$(LCINCS)
LC++OPTS =	-non_shared -G 0 -mips2 -fullwarn -float -xansi +pp -woff 3259,3262,3672,3106
#: warning(3106): nested comment is not allowed
#: warning(3259): expression has no effect
#: warning(3262): variable "p1" was declared but never referenced
#: warning(3672): Mangling of signed character does not match cfront name mangling

: error(3114): identifier "" is undefined
: error(3130): the #endif for this directive is missing
: error(3232): a value of type "" cannot be used to initialize an entity of type ""
: error(3252): argument of type "" is incompatible with parameter of type ""
: error(3611): a value of type "" cannot be assigned to an entity of type ""
: error(3867): expected a member name

## 初期化しないauto変数を 0xffffa5a5にしてしまう
## 全バージョンで外すようにします（全責任者：山本雄一）
##
###if !defined(ROM_F) && !defined(__GCC__)
##LCOPTS   += -trapuv
##LC++OPTS += -trapuv
###endif

## make clean で消えるもの
LDIRT  += rom_d rom_x rom_f rom_s spec_inc_ovl.inc spec_seg_ovl.inc *.rel *.map $(ULTRALIB2) $(U64LIB2) $(C64LIB2) $(NUSLIB2) zelda.gdis eptvr.dat ptn64.dat *.szp *.szs
LDIRT1 = *.d


##LLDOPTS = $(MKDEPOPT) -L$(PATCH_LIBDIR) -L$(COMMON_LIBDIR) -L$(ROOT)/usr/lib/PR
GLDOPTS =				# デフォルトの内容を削除する

ifdef __GCC__
LDFLAGS_WIDHOUT_LDLIBS = $(LDOPTS) $(ENDIAN)
else
LDFLAGS_WIDHOUT_LDLIBS	= $(LDOPTS) $(ENDIAN)
endif

TOOLBIN = ${ZELDA_ROOT}/tool/bin
###CAMDATINSTALLROOT = /home/umemiya/ZELDA/SAM_TOOL
CAMDATINSTALLROOT = /project/ZELDA1/link/tools/umemiya/SAM_TOOL
CAMPARAMH = camera_param_data.h
CAMERAZDB = camera.zdb
CAMDATABASE = ${ZELDA_ROOT}/data/$(CAMERAZDB)



#
# エントリ登録
#
all default:	genfiles $(TARGETS)

help::
	@echo '最新バージョンで、完全に再構築します(rom_d/rom_x/rom_f/rom_s)'
	@echo 'make fullcourse'

# ソース・データ更新
coall::
	coall
	$(MAKE) data

# フルコース2！
# make_midnight 用
# clobber する際に以前の *.szs ファイルを保存しています
fullcourse2::
	@echo このモードは make clobber を使用します
	coall
	-rm -rf szs_x; mkdir szs_x && (cd rom_x && mv [A-Za-n]*.szs ../szs_x/. && mv [o-z]*.szs ../szs_x/.)
	-rm -rf szs_d; mkdir szs_d && (cd rom_d && mv [A-Za-n]*.szs ../szs_d/. && mv [o-z]*.szs ../szs_d/.)
	-rm -rf szs_f; mkdir szs_f && (cd rom_f && mv [A-Za-n]*.szs ../szs_f/. && mv [o-z]*.szs ../szs_f/.)
##	-rm -rf szs_s; mkdir szs_s && (cd rom_s && mv [A-Za-n]*.szs ../szs_s/. && mv [o-z]*.szs ../szs_s/.)
	$(MAKE) clobber
	-mkdir rom_d; (cd szs_d && mv [A-Za-n]*.szs ../rom_d/. && mv [o-z]*.szs ../rom_d/.) && rmdir szs_d
	-mkdir rom_x; (cd szs_x && mv [A-Za-n]*.szs ../rom_x/. && mv [o-z]*.szs ../rom_x/.) && rmdir szs_x
	-mkdir rom_f; (cd szs_f && mv [A-Za-n]*.szs ../rom_f/. && mv [o-z]*.szs ../rom_f/.) && rmdir szs_f
##	-mkdir rom_s; (cd szs_s && mv [A-Za-n]*.szs ../rom_s/. && mv [o-z]*.szs ../rom_s/.) && rmdir szs_s
	$(MAKE) camera_params
	$(MAKE) data
	$(MAKE) genfiles
##	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) rom_d rom_x rom_f

rebuild_d:
	-rm -rf szs_d; mkdir szs_d ; (cd rom_d && mv [A-Za-n]*.szs ../szs_d/. && mv [o-z]*.szs ../szs_d/.)
	-rm -rf rom_d; mkdir rom_d ; (cd szs_d && mv [A-Za-n]*.szs ../rom_d/. && mv [o-z]*.szs ../rom_d/.) && rmdir szs_d
	-$(MAKE) rom_d PARALLEL=
rebuild_x:
	-rm -rf szs_x; mkdir szs_x ; (cd rom_x && mv [A-Za-n]*.szs ../szs_x/. && mv [o-z]*.szs ../szs_x/.)
	-rm -rf rom_x; mkdir rom_x ; (cd szs_x && mv [A-Za-n]*.szs ../rom_x/. && mv [o-z]*.szs ../rom_x/.) && rmdir szs_x
	-$(MAKE) rom_x PARALLEL=
rebuild_f:
	-rm -rf szs_f; mkdir szs_f ; (cd rom_f && mv [A-Za-n]*.szs ../szs_f/. && mv [o-z]*.szs ../szs_f/.)
	-rm -rf rom_f; mkdir rom_f ; (cd szs_f && mv [A-Za-n]*.szs ../rom_f/. && mv [o-z]*.szs ../rom_f/.) && rmdir szs_f
	-$(MAKE) rom_f PARALLEL=
rebuild_s:
	-rm -rf szs_s; mkdir szs_s ; (cd rom_s && mv [A-Za-n]*.szs ../szs_s/. && mv [o-z]*.szs ../szs_s/.)
	-rm -rf rom_s; mkdir rom_s ; (cd szs_s && mv [A-Za-n]*.szs ../rom_s/. && mv [o-z]*.szs ../rom_s/.) && rmdir szs_s
	-$(MAKE) rom_s PARALLEL=
rebuild_c:
	-rm -rf szs_c; mkdir szs_c ; (cd rom_c && mv [A-Za-n]*.szs ../szs_c/. && mv [o-z]*.szs ../szs_c/.)
	-rm -rf rom_c; mkdir rom_c ; (cd szs_c && mv [A-Za-n]*.szs ../rom_c/. && mv [o-z]*.szs ../rom_c/.) && rmdir szs_c
	-$(MAKE) rom_c PARALLEL=
rebuild_all:
	-coall
	-$(MAKE) camera_params
	-$(MAKE) data
	-$(MAKE) genfiles
	-$(MAKE) rebuild_d rebuild_x rebuild_f rebuild_s
	-$(MAKE) romPP_d romPP_x romPP_f PARALLEL=
	-$(MAKE) romPP_d romPP_x romPP_f PARALLEL=
	-$(MAKE) rebuild_s rebuild_c
	-$(MAKE) romPP_s PARALLEL=
	-$(MAKE) romPP_s PARALLEL=

fullcourse3::
	-$(MAKE) cleanboot
##	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) romPP_d || $(MAKE) romPP_d
	-$(MAKE) romPP_x || $(MAKE) romPP_x
	-$(MAKE) romPP_f || $(MAKE) romPP_f
##	-$(MAKE) romPP_s || $(MAKE) romPP_s

# フルコース！
fullcourse::
	coall
	$(MAKE) camera
	$(MAKE) data
	$(MAKE) genfiles
	-$(MAKE) romPP_d || $(MAKE) romPP_d

SPECFILE  = spec
SPEC_INCLUDE  = spec.segment spec.audio
LMAKEROMOPT = -I$(ZELDA_ROOT)

MAKEROMOPT = $(GMAKEROMOPT) $(LMAKEROMOPT) $(VMAKEROMOPT)

MAKEROMOBJECTS = $(OBJECTS) $(ZELDA_DATA)/*.o $(OVLOBJECTS) \
	$(ZELDA_AUDIO)/ZeldaAudio_banks.o \
	$(ZELDA_AUDIO)/ZeldaAudio_music.o \
	$(ZELDA_AUDIO)/ZeldaAudio_table.o
MAKEROMFILES = $(SPECFILE) $(SPEC_INCLUDE)  $(OVLRELFILES)


# マップファイルの作成
zelda.map: $(MAKEROMOBJECTS) $(MAKEROMFILES)
	(LANG=C ZELDA_DATA=${ZELDA_DATA} time $(MAKEROM) -m $(MAKEROMOPT) $(MAKEOPT) -r rom ../$(SPECFILE) > zelda.map)


##
## LMAKEOPTIONの定義
##
LMAKEOPTION =
####for GC EMU
###LMAKEOPTION += USE_N64DD=
LMAKEOPTION += USE_LOCALE=1

####for GC EMU
###LMAKEOPTION += USE_CIC6105=

ifdef PARALLEL
LMAKEOPTION += "PARALLEL=$(PARALLEL)"
endif
ifdef HAYAKAWA_LIB
LMAKEOPTION += "HAYAKAWA_LIB=$(HAYAKAWA_LIB)"
endif
ifdef FORCE_CPP
LMAKEOPTION += "FORCE_CPP=$(FORCE_CPP)"
endif
ifdef VMAKEOPT
LMAKEOPTION += "VMAKEOPT=$(VMAKEOPT)"
endif
ifdef VMAKEROMOPT
LMAKEOPTION += "VMAKEROMOPT=$(VMAKEROMOPT)"
endif
ifdef SCENE_TOOL
LMAKEOPTION += "SCENE_TOOL=$(SCENE_TOOL)"
endif
ifdef SCENE_TOOL2
LMAKEOPTION += "SCENE_TOOL2=$(SCENE_TOOL2)"
endif
MAKEOPTION_D = $(LMAKEOPTION) $(VMAKEOPTION) ROM_D= USE_COUNT= DEBUG_CAMERA= USE_DEBUG_MALLOC= ISVIEWER= RAM8M= VIDEO_AUTO=
MAKEOPTION_X = $(LMAKEOPTION) $(VMAKEOPTION) ROM_X= USE_COUNT= DEBUG_CAMERA= USE_DEBUG_MALLOC= ISVIEWER= RAM8M= VIDEO_AUTO=
MAKEOPTION_F = $(LMAKEOPTION) $(VMAKEOPTION) ROM_F=1 ROM_ROM=1 FINAL_ROM=1
MAKEOPTION_S = $(LMAKEOPTION) $(VMAKEOPTION) ROM_S= ROM_ROM= SHOW_VERSION=
MAKEOPTION_C = $(MAKEOPTION_D) ROM_C= FORCE_CPP=

LMAKEFLAGS = -f ../$(MAKEFILE)
MAKEFLAGS = $(GMAKEFLAGS) $(LMAKEFLAGS) $(VMAKEFLAGS)

zelda_d.map:
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_D)
	@echo ": Leaving directory \`./rom_d/'"

zelda_x.map:
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_X)
	@echo ": Leaving directory \`./rom_x/'"

zelda_f.map:
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_F)
	@echo ": Leaving directory \`./rom_f/'"

zelda_s.map:
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(VMAKEFLAGS)  zelda.map $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

spec.i:../$(SPECFILE) ../spec.segment ../spec_seg_ovl.inc ../boot.h ../sys_segment.h
	(LANG=C ZELDA_DATA=${ZELDA_DATA} $(CC) -E $(MAKEOPT) ../$(SPECFILE) > spec.i.tmp)
	mv spec.i.tmp spec.i

# ロムヘッダ定義（仮）
MASKROM_VERSION = f		# 開発バージョン識別用（仮）
MASKROM_PGW_INICODE = nzll	# PAL(GATEWAY)
MASKROM_GTW_INICODE = czlg	# GATEWAY
MASKROM_PAL_INICODE = nzlp	# PAL
MASKROM_JPN_INICODE = czlj	# JAPAN
MASKROM_NES_INICODE = czle	# NES
MASKROM_GAME_TITLE = "THE LEGEND OF ZELDA"
ifdef GATEWAY_VERSION
 ifdef PAL_VERSION
  MASKROM_INICODE = $(MASKROM_PGW_INICODE)
 else
  MASKROM_INICODE = $(MASKROM_GTW_INICODE)
 endif
else
 ifdef PAL_VERSION
  MASKROM_INICODE = $(MASKROM_PAL_INICODE)
 else
 MASKROM_INICODE = $(MASKROM_NES_INICODE)	# HIRATSU Daisuke modified this line.
 endif
endif

rom: $(MAKEROMOBJECTS) $(MAKEROMFILES)
	../make_version.sh $(MAKEOPTION) > version_data.h
	$(CC) $(CFLAGS) -c ../version.c
	(LANG=C ZELDA_DATA=${ZELDA_DATA} time $(MAKEROM) -d $(MAKEROMOPT) $(MAKEOPT) -r rom.tmp ../$(SPECFILE) > $(ZELDA_INFO))
#	$(NRDC) -b -i$(MASKROM_INICODE) -t$(MASKROM_GAME_TITLE) -v$(MASKROM_VERSION) rom.tmp
ifdef USE_CIC6105
 ifdef ROM_D
  ifndef GATEWAY_VERSION
	$(VERSUM) rom.tmp
  endif
 endif
endif
	mv -f rom.tmp rom
#	-(nm zelda | sort | tee zelda.nm1 | egrep "^8" > zelda.nm)&
	-(/usr/bin/nm -B zelda | sort | tee zelda.nm2 | egrep "^8" > zelda.nm)&
ifdef PARTNER
	n64deb zelda		# パートナー用変換
endif
# #if defined(PARTNER) || defined(ISVIEWER) || defined(ROM_ROM)
#	@echo "makemaskはスキップされました"
#	@echo "makemaskは手でやってください"
#	@echo "例）makemask rom_d/rom"
	$(MAKEMASK) rom		# ROM焼き用変換
# #endif
	@-if [ \( ${USER} = "###yoshida" -o ${USER} = "###hayakawa" \) -a -f /home/iwawaki/AIFC_FILES/capture.mv ]; then \
	    audiopanel -nodisplay -nofork -outlevels 2; \
	    movieplayer -l 0 -N -z 0.5 -b q -v /home/iwawaki/AIFC_FILES/capture.mv > /dev/null; \
	else \
	    if [ -x ../bell.sh ]; then \
		    ../bell.sh; \
	    else \
	        if [ -x ./bell.sh ]; then \
		        ./bell.sh; \
	        fi; \
	    fi; \
	fi
	date
#	then playaifc /home/iwawaki/AIFC_FILES/bakabon.aifc > /dev/null; \

## ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(ULTRALIB2): $(ULTRALIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibultra.a
	cp $(ULTRALIB_FULLPATH) tmplibultra.a
	chmod 644 tmplibultra.a
	sed -n -e "s/.*libultra.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > ultra.stdout
	$(AR) d tmplibultra.a `sed -n -e "s/.*libultra.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibultra.a sprintf.o
ifdef ISVIEWER
	$(AR) d tmplibultra.a syncprintf.o
endif
ifdef ROM_ROM
	$(AR) d tmplibultra.a syncprintf.o
endif
####if !defined(USE_LEOEMU)
###	$(AR) d tmplibultra.a driverominit.o
####endif
	chmod 444 tmplibultra.a
	mv tmplibultra.a $(ULTRALIB2)

## ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(U64LIB2): $(U64LIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibu64.a
	cp $(U64LIB_FULLPATH) tmplibu64.a
	chmod 644 tmplibu64.a
	sed -n -e "s/.*libu64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > u64.stdout
	$(AR) d tmplibu64.a `sed -n -e "s/.*libu64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	chmod 444 tmplibu64.a
	mv tmplibu64.a $(U64LIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(C64LIB2): $(C64LIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibc64.a
	cp $(C64LIB_FULLPATH) tmplibc64.a
	chmod 644 tmplibc64.a
	sed -n -e "s/.*libc64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > c64.stdout
	$(AR) d tmplibc64.a `sed -n -e "s/.*libc64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	-$(AR) d tmplibc64.a assert64.o	# zelda のassertを使用するため
	chmod 444 tmplibc64.a
	mv tmplibc64.a $(C64LIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(NUSLIB2): $(NUSLIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibnus.a
	cp $(NUSLIB_FULLPATH) tmplibnus.a
	chmod 644 tmplibnus.a
	sed -n -e "s/.*lib$(NUSLIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > nus.stdout
	$(AR) d tmplibnus.a `sed -n -e "s/.*'lib$(NUSLIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibnus.a memcpy.o strchr.o strlen.o
	chmod 444 tmplibnus.a
	mv tmplibnus.a $(NUSLIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(LEOLIB2): $(LEOLIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibleo.a
	cp $(LEOLIB_FULLPATH) tmplibleo.a
	chmod 644 tmplibleo.a
	sed -n -e "s/.*lib$(LEOLIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > leo.stdout
#	$(AR) d tmplibleo.a `sed -n -e "s/.*'lib$(LEOLIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibleo.a driverominit.o
	chmod 444 tmplibleo.a
	mv tmplibleo.a $(LEOLIB2)

# ブートセグメントで使わなかったオブジェクトでライブラリを再構築する
$(LEOEMULIB2): $(LEOEMULIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibleoemu.a
	cp $(LEOEMULIB_FULLPATH) tmplibleoemu.a
	chmod 644 tmplibleoemu.a
	sed -n -e "s/.*lib$(LEOEMULIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > leoemu.stdout
	$(AR) d tmplibleoemu.a `sed -n -e "s/.*'lib$(LEOEMULIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	chmod 444 tmplibleoemu.a
	mv tmplibleoemu.a $(LEOEMULIB2)

ifdef __GCC__
LDMAPOPT = -M
else
LDMAPOPT = -m
endif

$(AUDIOSEGMENT:.o=.map): $(AUDIOSEGMENT)
$(AUDIOSEGMENT): $(AUDIOOBJECTS)
	$(LD)  -o $(AUDIOSEGMENT) -r $(AUDIOOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_AUDIO) $(LDMAPOPT) > $(AUDIOSEGMENT:.o=.map)

$(BOOTSEGMENT:.o=.map): $(BOOTSEGMENT)
$(BOOTSEGMENT): $(BOOTOBJECTS)
	$(LD)  -o $(BOOTSEGMENT) -r $(BOOTOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_BOOT) $(LDMAPOPT) > $(BOOTSEGMENT:.o=.map)
	echo "$(BOOTSEGMENT:.o=.map) できた"

$(N64DDSEGMENT:.o=.map): $(N64DDSEGMENT)
$(N64DDSEGMENT): $(N64DDOBJECTS) $(LEOLIB2)
	$(LD)  -o $(N64DDSEGMENT) -r $(N64DDOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_N64DD) $(LDMAPOPT) > $(N64DDSEGMENT:.o=.map)

$(CODESEGMENT:.o=.map): $(CODESEGMENT)
$(CODESEGMENT): $(CODEOBJECTS) $(ULTRALIB2) $(NUSLIB2) $(U64LIB2) $(C64LIB2)
	$(LD)  -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_CODE) $(LDMAPOPT) > $(CODESEGMENT:.o=.map)

$(COBJECT_EN) $(COBJECT_EN:.o=.map): $(COBJECTS_EN)
	$(LD)  -o $(COBJECT_EN) -r $(COBJECTS_EN) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_EN:.o=.map)

$(COBJECT_EFF) $(COBJECT_EFF:.o=.map): $(COBJECTS_EFF)
	$(LD)  -o $(COBJECT_EFF) -r $(COBJECTS_EFF) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_EFF:.o=.map)

$(COBJECT_Z) $(COBJECT_Z:.o=.map): $(COBJECTS_Z)
	$(LD)  -o $(COBJECT_Z) -r $(COBJECTS_Z) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_Z:.o=.map)

$(COBJECT_SYS) $(COBJECT_SYS:.o=.map): $(COBJECTS_SYS)
	$(LD)  -o $(COBJECT_SYS) -r $(COBJECTS_SYS) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_SYS:.o=.map)

## 第１水準フォント データ
CC_FLAGS  = -Wab,-r4300_mul -mips2 -O -xansi -signed -fullwarn -prototypes -Xcpluscomm -I/usr/include/PR -non_shared -G 0 -c -Dyj
##LASFLAGS = -Wab,-r4300_mul -mips2 -O2 -xansi -signed -prototypes -Xcpluscomm -I/usr/include/PR -non_shared -G 0 -c -Dyj
kanread.o	: kanread.s	;cc $(CC_FLAGS) -o $(.TARGET) $<
kan.o	: kan.s	;cc $(CC_FLAGS) -o $(.TARGET) $<

name : zelda
	/usr/bin/nm -x zelda | grep -v ref | sort +2 > $@
name2 : name
	/home/hayakawa/prj/test/namesize name > $@

cfb.o:cfb.c
	$(CC) $(LCOPTS) $(LCINCS) $(MKDEPOPT) $(WOFF) $(LCDEFS) -c cfb.c

##
###


#XXX
camera:
#camera: $(CAMDATABASE) $(TOOLBIN)/makecamera
#	$(TOOLBIN)/makecamera -l -d$(CAMDATINSTALLROOT) $(CAMDATABASE)

camera_params:  $(CAMPARAMH)

# XXX
#$(CAMPARAMH):  $(CAMDATABASE) $(TOOLBIN)/makecamera
#	$(TOOLBIN)/makecamera -td -q $(CAMDATABASE)

../$(CAMPARAMH):  ../../data/$(CAMERAZDB)
	$(TOOLBIN)/makecamera -td -q ../../data/$(CAMERAZDB)
	mv $(CAMPARAMH) ..

../../data/$(CAMERAZDB):
	@if [ ! -l ../../data/camera ]; \
	then \
	    if [ `echo ${HOST} | awk '{print substr($$0, 1, 3)}'` = "srd" ]; \
	    then  ln -s /project/ZELDA/data/camera ../../data; \
	    else  echo "please contact to SRD ..."; \
	    fi; \
	fi
	@if [ ! -r ../../data/$(CAMERAZDB) ]; \
	then \
	    cp ../../data/camera/$(CAMERAZDB) ../../data; \
	fi

$(CAMDATABASE):  ${ZELDA_ROOT}/data/camera/${@F}
	if [ -r $@ ] && [ ! -w $@ ]; \
	then  chmod +w $@; \
	fi
	cp ${ZELDA_ROOT}/data/camera/${@F} $@

###
##

zelda.gdis::				# 逆アセンブルリストの作成
	gdis -S \
$(GDISOPT) \
-I.. \
-I/usr/local/srd/PR/src/libu64 \
-I/usr/local/srd/PR/src/libc64 \
-I/usr/src/PR/libultra/gu zelda > zelda.gdis

# 逆アセンブルリストの作成
zelda_d.gdis::
	cd rom_d; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_x.gdis::
	cd rom_x; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_f.gdis::
	cd rom_f; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_s.gdis::
	cd rom_s; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"

cleanall:
	rm -f rom*/*.o rom*/Makedepend rom*/*.map rom*/*. rom*/*.oo rom*/*.gdis rom*/*.a
cleanboot:				# ptstart()/isPrintfInit()を呼んでいる
	rm -f */boot.o
	rm -f */padmgr.o */main.o
ifdef CLEAN_ALL
	rm -f */idle.o */is_debug.o	# USE_LEOEMU
	rm -f */cpuprint.o */idle.o */ssSRAMrdwt.o */z_sram.o */z_std_dma.o # sys_leoemu.h
endif
ifdef USE_LEOEMU
	rm -f */idle.o */is_debug.o	# USE_LEOEMU
	rm -f */cpuprint.o */idle.o */ssSRAMrdwt.o */z_sram.o */z_std_dma.o # sys_leoemu.h
endif
ifdef CLEAN_ALL
	rm -f */db_camera.o */z_camera.o # 8M/4M
endif
ifdef RAM8M
	rm -f */db_camera.o */z_camera.o # 8M/4M
endif
ifdef CLEAN_ALL
	rm -f */game.o */graph.o */sys_ucode.o */z_room.o */z_kaleido_manager.o */z_play.o */z_scene_table.o */z_std_dma.o
endif
ifdef HAYAKAWA_TEST
	rm -f */game.o */graph.o */sys_ucode.o */z_room.o */z_kaleido_manager.o */z_play.o */z_scene_table.o */z_std_dma.o
endif

ifdef CLEAN_ALL
	rm -f */graph.o
endif
ifdef USE_COUNT
	rm -f */graph.o
endif
ifdef USE_TIMER
	rm -f */graph.o
endif
ifdef CLEAN_ALL
	rm -f */boot.o */z_bg_zg.o */z_en_zl2.o */z_fishing.o */sys_ucode.o */audioMgr.o */z_title.o */CIC6105.o */main.o
endif
ifdef USE_CIC6105
	rm -f */boot.o */z_bg_zg.o */z_en_zl2.o */z_fishing.o */sys_ucode.o */audioMgr.o */z_title.o */CIC6105.o */main.o
endif
ifdef CLEAN_ALL
	rm -f */sys_cfb.o */main.o */z_select.o
endif
ifdef USE_N64DD
	rm -f */sys_cfb.o */main.o */z_select.o
endif
ifdef CLEAN_ALL
	rm -f */main.o */idle.o
endif
ifdef USE_RMON
	rm -f */main.o */idle.o
endif
ifdef CLEAN_ALL
	rm -f */z_actor_dlftbls.o */z_std_dma.o
endif
ifdef USE_ACTOR_NAME_TABLE
	rm -f */z_actor_dlftbls.o */z_std_dma.o
endif
ifdef CLEAN_ALL
	rm -f */game.o
endif
ifdef USE_VISCVG
	rm -f */game.o
endif
ifdef CLEAN_ALL
	rm -f */main.o 				# DISABLE_FAULT_DISPLAY	
	rm -f */padmgr.o			# SHOW_VERSION
endif
ifdef SHOW_VERSION
	rm -f */main.o 				# DISABLE_FAULT_DISPLAY	
	rm -f */padmgr.o			# SHOW_VERSION
endif
ifdef CLEAN_ALL
	rm -f */game.o */graph.o */z_debug.o */z_demo.o */z_file_choose.o */z_kaleido.o */z_kaleido_scope.o */z_kankyo.o */z_message.o */z_play.o */z_player.o	# DEBUG_MODE_NOINPUT
endif
ifdef DEBUG_MODE_NOINPUT
	rm -f */game.o */graph.o */z_debug.o */z_demo.o */z_file_choose.o */z_kaleido.o */z_kaleido_scope.o */z_kankyo.o */z_message.o */z_play.o */z_player.o	# DEBUG_MODE_NOINPUT
endif
ifdef CLEAN_ALL
	rm -f */graph.o */ssSRAMrdwt.o */z_locale.o 
endif
ifdef GATEWAY_VERSION
	rm -f */graph.o */ssSRAMrdwt.o */z_locale.o 
endif

cleancode:				# リンクだけをやり直す
	rm -f */$(CODESEGMENT)
cleanbootseg:				# リンクだけをやり直す
	rm -f */$(BOOTSEGMENT)
cleanrom:				# makeromだけをやり直す
	rm -f */rom
cleandepend:				# Makedependだけを消す
	rm -f */Makedepend
data:
	cd $(ZELDA_DATA); coall; shape_all

scene:
	cd $(ZELDA_DATA); $(TOOLBIN)/scene_make

keep:
	cd $(ZELDA_DATA); keep

dma_make::
	cd $(ZELDA_DATA); dma_make

# ROM用バージョンの作成
rom_x::
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_X)
	@echo ": Leaving directory \`./rom_x/'"

# デバッグバージョン
rom_d::
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_D)
	@echo ": Leaving directory \`./rom_d/'"

# Ｃ＋＋バージョン
rom_c::
	@echo ": Entering directory \`./rom_c/'"
	mkdirhier rom_c
	cd rom_c; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_C)
	@echo ": Leaving directory \`./rom_c/'"

# Ｃ＋＋バージョン
cpptest:
	@echo ": Entering directory \`./rom_c/'"
	mkdirhier rom_c
	cd rom_c; $(MAKE) $(MAKEFLAGS) $(TARGET) $(MAKEOPTION_C)
	@echo ": Leaving directory \`./rom_c/'"

# 最終ＲＯＭバージョン
rom_f::
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_F) -f ../GNUmakefile
	@echo ": Leaving directory \`./rom_f/'"

# ショウバージョン
rom_s::
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

romPP_d::
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_D)
	-(cd rom_d; $(MAKEMASK) romPP)
	@echo ": Leaving directory \`./rom_d/'"

romPP_x::
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_X)
	-(cd rom_x; $(MAKEMASK) romPP)
	@echo ": Leaving directory \`./rom_x/'"

romPP_f::
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_F) -f ../GNUmakefile
	-(cd rom_f; $(MAKEMASK) romPP)
	@echo ": Leaving directory \`./rom_f/'"

romPP_s::
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

romPP:rom
#	../zelda_press -p1
	../linux_zelda_press -p2
	@-if [ \( ${USER} = "###yoshida" -o ${USER} = "###hayakawa" \) -a -f /home/iwawaki/AIFC_FILES/capture.mv ]; then \
	    movieplayer -l 0 -N -z 0.5 -b q -v /home/iwawaki/AIFC_FILES/capture.mv > /dev/null; \
	else \
	    if [ -x ../bell.sh ]; then \
		    ../bell.sh; \
	    else \
	        if [ -x ./bell.sh ]; then \
		        ./bell.sh; \
	        fi; \
	    fi; \
	fi

rom_d/rom::rom_d
rom_x/rom::rom_x
rom_f/rom::rom_f
rom_s/rom::rom_s
rom_d/romPP::romPP_d
rom_x/romPP::romPP_x
rom_f/romPP::romPP_f
rom_s/romPP::romPP_s

install::
	-rm /project/ZELDA/ROM/rom
	cp rom_d/rom /project/ZELDA/ROM/rom_d
	cp rom_x/rom /project/ZELDA/ROM/rom_x
	cp rom_f/rom /project/ZELDA/ROM/rom_f
	cp rom_s/rom /project/ZELDA/ROM/rom_s
	ln /project/ZELDA/ROM/rom_d /project/ZELDA/ROM/rom_d_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_x /project/ZELDA/ROM/rom_x_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_f /project/ZELDA/ROM/rom_f_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_s /project/ZELDA/ROM/rom_s_`date '+%y-%m-%d_%H:%M:%S'`

main.o:sys_heap.h
z_actor_dlftbls.o:z_actor_dlftbls.decl
z_actor_profile.o:z_actor_dlftbls.decl
z_scene.o:z_actor_dlftbls.decl

genfiles:spec_seg_ovl.inc spec_inc_ovl.inc camera_params
z_segment.decl:spec.i
	grep include spec.i | \
grep -v "\." | \
grep -v '"nullsegment"' | \
grep -v '"hilite"' | \
grep -v '"fifobuffer"' | \
grep -v '"yieldbuffer"' | \
grep -v '"SystemDynamic"' | \
grep -v '"dramstackbuffer"' | \
grep -v '"yieldbuffer"' | \
grep -v '"zbuffer"' | \
grep -v '"rcp_cfb"' | \
grep -v '"rcp_zb"' | \
grep -v '"Audioheap"' | \
grep -v '"SystemHeap"' | \
grep -v '"object_go2"' | \
grep -v '"object_stk"' | \
grep -v '"object_gate"' | \
sed -e 's/[ 	]*include[ 	]*"\(.*\)"[ 	]*/_DECL_(\1)/' > z_segment.decl.tmp
	mv z_segment.decl.tmp z_segment.decl

../rom_d/z_segment.decl:z_segment.decl
../rom_x/z_segment.decl:z_segment.decl
../rom_f/z_segment.decl:z_segment.decl
../rom_s/z_segment.decl:z_segment.decl
../rom_c/z_segment.decl:z_segment.decl
#spec_seg_ovl.inc:spec_ovl.dat make_spec_seg_ovl.sh XXX
#	make_spec_seg_ovl.sh < spec_ovl.dat > spec_seg_ovl.inc~$$$$~ && mv spec_seg_ovl.inc~$$$$~ spec_seg_ovl.inc
#spec_inc_ovl.inc:spec_ovl.dat make_spec_inc_ovl.sh  XXX
#	make_spec_inc_ovl.sh < spec_ovl.dat > spec_inc_ovl.inc~$$$$~ && mv spec_inc_ovl.inc~$$$$~ spec_inc_ovl.inc

z_std_dma.o:z_segment.decl
z_std_dma_data.o:z_segment.decl

# 依存ファイル(depend)をつくる
DEPEND_FILES = $(COBJECTS:.o=.dep)
.SUFFIXES : .dep
.c.dep :
	$(CC) $(CFLAGS) -M $< > $(.PREFIX).dep
.cxx.dep .C.dep .c++.dep :
	$(CXX) $(CXXFLAGS) -M $< > $(.PREFIX).dep
depend : $(DEPEND_FILES)
test:test.o
	cc -non_shared -o test test.o
touch_z_actor_dlftbls.decl:
	@echo "z_actor_dlftbls.declの順番は大丈夫ですか？"
	touch 01010001 z_actor_dlftbls.decl
	touch 01010000 rom_[dfxs]/z_actor.o rom_[dfxs]/z_actor_dlftbls.o
#ifmake fluff
#GCDEFS = $(HW_FLAGS) -F
#endif

## 木村さんにロムを渡す
z_en_oA2.o:z_en_oA2_inWater.c

ikuiku_d:
	cp rom_d/rom /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/rom_d
ikuiku_f:
	cp rom_f/romPP /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/romPP_f
ikuiku_x:
	cp rom_x/romPP /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/romPP_x
