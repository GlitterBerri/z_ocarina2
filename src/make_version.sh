#!/bin/sh
# $Log: make_version.sh,v $
# Revision 1.1  2003/03/10 22:42:53  tong
# Initial revision
#
# Revision 2.1  1998-10-22 20:41:56+09  zelda
# ＲＯＭ出しバージョン(NTSC)
#
# Revision 1.4  1998/03/10 04:38:08  hayakawa
# 修正 CREATER → CREATOR
#
# Revision 1.3  1998/03/06  11:56:20  hayakawa
# MAKEOPTION対応
#
# Revision 1.2  1998/03/06  11:35:25  hayakawa
# __MAKEOPTION__追加
#
# Revision 1.1  1997/05/26  12:41:05  hayakawa
# Initial revision
#

echo "#define __CREATOR__  \"`whoami`@`hostname`\""
echo "#define __DATETIME__ \"`date '+%y-%m-%d %H:%M:%S'`\""
echo '#define __MAKEOPTION__ "'$*'"'
