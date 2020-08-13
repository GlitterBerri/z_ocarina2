#!/usr/bin/perl
#
#  ＤＤへのマスターデータ書き込みperlの生成
#

{
  while(<>) {
    chop;
    s/leowrite/isvwrite/;
    if ($. != 1) {
	$_ .= " -V -D -n \n";
    } else {
	$_ .= " -V -D \n";
    }
    print $_;
  }
}
