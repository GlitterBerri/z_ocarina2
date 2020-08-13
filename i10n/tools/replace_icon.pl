#!/usr/bin/perl -w

open(ICON_LIST, "<icon.list") || die "Can't open icon.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$texture_path = "$zroot/i10n/assets/zh/";
$data_offset = "0x4a0";
$obj_file = "icon_item_nes";
`rm -f $zroot/data/$obj_file.zh.o`;
`cp $zroot/data/$obj_file.o $zroot/data/$obj_file.zh.o`;
`chmod u+w $zroot/data/$obj_file.zh.o`;

while (<ICON_LIST>) {
    /(.*(others_nes|h_dt|save|i4|sf))\/(.*)\.(.*)\s+(0x[0-9a-fA-F]+)\s+(\d+)/;
    $dir = $1;
    $name = $3;
    $ext = $4;
    $loc = $5;
    $size = $6;

    if ($ext =~/a/) {
        print "./rgb2bin.pl $texture_path$dir/$name.$ext IA 8\n";
        `./rgb2bin.pl $texture_path$dir/$name.$ext IA 8`;
    } else {
        print "./rgb2bin.pl $texture_path$dir/$name.$ext I 4\n";
        `./rgb2bin.pl $texture_path$dir/$name.$ext I 4`;
    }
    $offset = hex($data_offset) + hex($loc);
    print "./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size\n\n";
    `./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size`;

    `rm $texture_path$dir/$name.bin`;
    `rm $texture_path$dir/$name.h`;
}

close ICON_LIST;
