#!/usr/bin/perl -w

open(MAG_LIST, "<mag.list") || die "Can't open mag.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$texture_path = "$zroot/i10n/assets/zh/";
$data_offset = "0x7c";
$obj_file = "mag";
`rm -f $zroot/data/$obj_file.zh.o`;
`cp $zroot/data/$obj_file.o $zroot/data/$obj_file.zh.o`;
`chmod u+w $zroot/data/$obj_file.zh.o`;

while (<MAG_LIST>) {
    /zelda_mag\/(.*)\.(inta|rgba)\s+(0x[0-9a-fA-F]+)\s+(\d+)/;
    $dir = "zelda_mag";
    $name = $1;
    $suffix = $2;
    $loc = $3;
    $size = $4;

    if ($suffix eq "rgba") {
        print "./rgb2bin.pl $texture_path$dir/$name.rgba RGBA 32\n";
        `./rgb2bin.pl $texture_path$dir/$name.rgba RGBA 32`;
    } else {
        print "./rgb2bin.pl $texture_path$dir/$name.inta IA 8\n";
        `./rgb2bin.pl $texture_path$dir/$name.inta IA 8`;
    }

    $offset = hex($data_offset) + hex($loc);
    print "./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size\n\n";
    `./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size`;

    `rm $texture_path$dir/$name.bin`;
    `rm $texture_path$dir/$name.h`;
}

close MAG_LIST;
