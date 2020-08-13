#!/usr/bin/perl -w

die "Usage: replace.pl <input object file> <replacing file> <offset> <size>\n" unless $#ARGV==3;
($in, $data, $offset, $size) = @ARGV;
open(IFH, "+<$in") || die "Can't open $in: $!";
open(OFH, "<$data") || die "Can't open $data: $!";
binmode(IFH);
binmode(OFH);

$bytes="";
read(IFH, $bytes, $offset+$size);
seek(IFH, -$size, 1);
read(OFH, $bytes, $size) == $size || die "can't read $size bytes from $data: $!";
print IFH $bytes; 
close IFH; 
close OFH; 

