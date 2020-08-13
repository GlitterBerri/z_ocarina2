#!/usr/bin/perl -w

open(TITLE_LIST, "<title.list") || die "Can't open title.list: $!";

$zroot = $ENV{ZELDA_ROOT};
$title_o = "$zroot/data/title.o";
$title_zh_o = "$zroot/data/title.zh.o";
$texture_path = "$zroot/i10n/assets/zh/TEXTURE/TITLE/file_name/";
$data_offset = 0xf70;
`rm -f $title_zh_o`;
`cp $title_o $title_zh_o`;
`chmod u+w $title_zh_o`;

while (<TITLE_LIST>) {
    /(ia|i|rgba|rgb)(\d+)(\/)(.*)(\.)(ia|i|rgba|rgb)/;
    $format = $1;
    $bpp = $2;
    $name = $4;
    $ext = $6;

    print "./rgb2bin.pl $texture_path$format$bpp/$name.$ext $format $bpp\n";
    `./rgb2bin.pl $texture_path$format$bpp/$name.$ext $format $bpp`;

    print "mips-linux-readelf -a $title_o |grep $name\_txt\n";
    $out = `mips-linux-readelf -a $title_o |grep "$name"_txt`;
    $out =~ /(:\s*)([0-9a-fA-F]+)(\s+)(\d+)/;
    $offset = hex($2) + $data_offset;
    $size = $4;

    print "./replace.pl $title_zh_o $texture_path$format$bpp/$name.bin $offset $size\n\n";
    `./replace.pl $title_zh_o $texture_path$format$bpp/$name.bin $offset $size`;

    `rm $texture_path$format$bpp/$name.bin`;
    `rm $texture_path$format$bpp/$name.h`;
}

close TITLE_LIST;
