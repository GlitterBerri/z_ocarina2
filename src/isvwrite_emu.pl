#!/usr/bin/perl
#
#  ＤＤイメージへのデータ書き込みperlの生成
#
{
  while(<>) {
    chop;
    s/leowrite/isvwrite/;
    if ($. != 1) {
	$_ .= " -V -n \n";
    } else {
	$_ .= " -V \n";
    }
    print $_;
  }
}
