#!/usr/freeware/bin/perl -w
# $Id: make_disk_keeptable.pl,v 1.1.1.1 2003/03/10 22:42:45 tong Exp $
#
# z_disk_keeptable_*.dat を作成する
# 使用例:
# make_disk_keeptable.pl < /project/ZELDA1/ROM/zelda_x2.nm2 > z_disk_keeptable_x.dat
#
use strict;

my @SYMBOLS;
my %ADDRESSES;
my %ALPHABETS;

my $SYMBOL_FILENAME = "z_disk_keeptable.decl";

# シンボル取得
open(SYMBOL_FILE, $SYMBOL_FILENAME) or die "$0: can't open $SYMBOL_FILENAME\n";
my $SYMBOL;

my $IN_COMMENT = 0;
my $IDX = 0;
my $REX = " (";
while (<SYMBOL_FILE>) {
#   print $_."\n";
    if ($IN_COMMENT) {
	if (m"\*\/") {
	    s/.*?\*\///g;
	    s/.*?\*\///g;
	    $IN_COMMENT = 0;
	} else {
	    next;
	}
    }
    next if m"^(#|$)";		# 空行と#で始まる行を無視する
    s/\/\*.*\*\// /g;		# /* コメント */ を一個の空白に置換える
##  s/(^ *)|( *$)//g;		# 行頭と行末の空白を削除する
    s/^ *//g; s/ *$//g;		# ↑この形式がxemacsでうまく処理できないので２命令にわけました(;_;)
    next if m"^(#|$)";	 	# 空行と#で始まる行を無視する
    chop;			# '\n'を削除する

    if (m"\/\*") {
	s/\/\*.*$//;
	$IN_COMMENT = 1;
    }
    if (m"^decl2\([^,]*, *([^, ]*) *,.*") {
	$SYMBOL = $1;
	$SYMBOLS[$IDX++] = $SYMBOL;
	$REX .= $SYMBOL . "|";
    }
}
chop $REX;
$REX .= ")\$";
close(SYMBOL_FILE);

#printf(STDERR "REX=%s\n", $REX);

#アドレス取得
my %COUNT;
while (<STDIN>) {
    if (/$REX/) {
	(my $ADDRESS, my $ALPHABET, my $SYMBOL) = split;
	$ADDRESSES{$SYMBOL} = $ADDRESS;
	$ALPHABETS{$SYMBOL} = $ALPHABET;
	$COUNT{$SYMBOL}++;
    }
}

#結果出力
foreach $SYMBOL (@SYMBOLS) {
    printf("decl(%s) /* %s %s %d */\n", $ADDRESSES{$SYMBOL}, $ALPHABETS{$SYMBOL}, $SYMBOL, $COUNT{$SYMBOL});
    
    # シンボル多重定義チェック
    if ($COUNT{$SYMBOL} > 1) {
	printf(STDERR "警告:シンボル `%s' は %d 個あります\n", $SYMBOL, $COUNT{$SYMBOL});
    }
}
