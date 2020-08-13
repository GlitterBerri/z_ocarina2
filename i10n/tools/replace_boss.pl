#!/usr/bin/perl -w

open(BOSS_LIST, "<boss.list") || die "Can't open boss.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$texture_path = "$zroot/i10n/assets/zh/";

while (<BOSS_LIST>) {
    /(.*)\/(.*)\.inta\s+(.*)\.o\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\d+)/;
    $dir = $1;
    $name = $2;
    $obj_file = $3;
    $data_offset = $4;
    $loc = $5;
    $size = $6;

    print "./rgb2bin.pl $texture_path$dir/$name.inta IA 8\n";
    `./rgb2bin.pl $texture_path$dir/$name.inta IA 8`;

    `rm -f $zroot/data/$obj_file.zh.o`;
    print "cp $zroot/data/$obj_file.o $zroot/data/$obj_file.zh.o\n";
    `cp $zroot/data/$obj_file.o $zroot/data/$obj_file.zh.o`;
    `chmod u+w $zroot/data/$obj_file.zh.o`;
    $offset = hex($data_offset) + hex($loc);

    print "./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size\n\n";
    `./replace.pl $zroot/data/$obj_file.zh.o $texture_path$dir/$name.bin $offset $size`;

    `rm $texture_path$dir/$name.bin`;
    `rm $texture_path$dir/$name.h`;
}

close BOSS_LIST;
