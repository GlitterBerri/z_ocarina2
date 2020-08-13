#!/usr/bin/perl -w

open(GAMEOVER_LIST, "<gameover.list") || die "Can't open gameover.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$texture_path = "$zroot/i10n/assets/zh/";
`rm -f $zroot/data/icon_item_gameover.zh.o`;
`cp $zroot/data/icon_item_gameover.o $zroot/data/icon_item_gameover.zh.o`;
`chmod u+w $zroot/data/icon_item_gameover.zh.o`;

while (<GAMEOVER_LIST>) {
    /(.*(gameover|save))\/(.*)(\.)(.*)\s+(.*)\.o\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\d+)/;
    $dir = $1;
    $name = $3;
    $ext = $5;
    $obj_file = $6;
    $data_offset = $7;
    $loc = $8;
    $size = $9;

    print "./rgb2bin.pl $texture_path$dir/$name.$ext IA 8\n";
    `./rgb2bin.pl $texture_path$dir/$name.$ext IA 8`;

    $offset = hex($data_offset) + hex($loc);
    print "./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size\n\n";
    `./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size`;

    `rm $texture_path$dir/$name.bin`;
    `rm $texture_path$dir/$name.h`;
}

close GAMEOVER_LIST;
