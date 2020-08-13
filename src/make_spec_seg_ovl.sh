#!/usr/local/bin/bash
# $Id: make_spec_seg_ovl.sh,v 1.1 2003/03/10 22:42:53 tong Exp $

read after || exit 0

echo '/*'
echo $0 'による自動生成ファイルです。'
echo '編集およびレジストは禁止されています。'
echo '*/'

while true
do
  read segname objbase || exit 0
  echo ''
  echo 'beginseg'
  echo '	name "'$segname'"'
  echo '	flags OBJECT'
  echo '	after "'$after'"'
  echo '	include "'$objbase'.o"'
  echo '	include "'$objbase'.rel"'
  echo 'endseg'
  after=$segname
done
