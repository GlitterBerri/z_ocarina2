#!/usr/bin/perl -w
#fix the sgi image problem from iQue: change dimension from 4-D to 3-D

die "Usage: fix_rgb.pl <input sgi file> \n" unless $#ARGV==0;
$in = shift;
open(FH, "+<$in") || die "Can't open $in: $!";
binmode(FH);

$bytes="";
read(FH, $bytes, 6);
seek(FH, -1, 1);
printf FH "%c", 0x03;
close FH; 

