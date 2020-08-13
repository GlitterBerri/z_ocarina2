#!/usr/bin/perl -w

open(MAP_LIST, "<map.list") || die "Can't open map.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$texture_path = "$zroot/i10n/assets/zh/";
$data_offset = "0xa70";
$obj_file = "map_name";
`rm -f $zroot/data/$obj_file.zh.o`;
`cp $zroot/data/$obj_file.o $zroot/data/$obj_file.zh.o`;
`chmod u+w $zroot/data/$obj_file.zh.o`;

while (<MAP_LIST>) {
    /(.*dungeons|.*place)\/(.*)\.inta\s+(0x[0-9a-fA-F]+)\s+(\d+)/;
    $dir = $1;
    $name = $2;
    $loc = $3;
    $size = $4;

    if ($dir =~ /dungeons/) {
        print "./rgb2bin.pl $texture_path$dir/$name.inta IA 4\n";
        `./rgb2bin.pl $texture_path$dir/$name.inta IA 4`;
    } elsif ($dir =~ /place/) {
        print "./rgb2bin.pl $texture_path$dir/$name.inta IA 8\n";
        `./rgb2bin.pl $texture_path$dir/$name.inta IA 8`;
    }

    $offset = hex($data_offset) + hex($loc);
    print "./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size\n\n";
    `./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size`;

    `rm $texture_path$dir/$name.bin`;
    `rm $texture_path$dir/$name.h`;
}

close MAP_LIST;
