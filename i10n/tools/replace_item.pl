#!/usr/bin/perl -w

open(ITEM_LIST, "<item.list") || die "Can't open item.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$texture_path = "$zroot/i10n/assets/zh/";
$data_offset = "0x23b0";
$obj_file = "item_name";
`rm -f $zroot/data/$obj_file.zh.o`;
`cp $zroot/data/$obj_file.o $zroot/data/$obj_file.zh.o`;
`chmod u+w $zroot/data/$obj_file.zh.o`;

while (<ITEM_LIST>) {
    /(.*items)\/(.*)\.inta\s+(0x[0-9a-fA-F]+)\s+(\d+)/;
    $dir = $1;
    $name = $2;
    $loc = $3;
    $size = $4;

    print "./rgb2bin.pl $texture_path$dir/$name.inta IA 4\n";
    `./rgb2bin.pl $texture_path$dir/$name.inta IA 4`;

    $offset = hex($data_offset) + hex($loc);
    print "./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size\n\n";
    `./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size`;

    `rm $texture_path$dir/$name.bin`;
    `rm $texture_path$dir/$name.h`;
}

close ITEM_LIST;
