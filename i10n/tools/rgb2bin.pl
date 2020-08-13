#!/usr/bin/perl -w

die "Usage: rgb2bin.pl <input texture image> <format[RGBA|RGB|IA|I]> <bpp[32|16|8|4]>\n" unless $#ARGV==2;

$root = $ENV{ROOT};
$byte_cnt = 0;

$input = shift;
$format = shift;
$bpp = shift;

sub write_int {
    my $val = shift;
    printf OUT_DATA "%c", ($val&0xFF000000) >> 24;
    printf OUT_DATA "%c", ($val&0x00FF0000) >> 16;
    printf OUT_DATA "%c", ($val&0x0000FF00) >> 8;
    printf OUT_DATA "%c", ($val&0x000000FF);
    $byte_cnt += 4;
}

sub write_short {
    my $val = shift;
    printf OUT_DATA "%c", (hex($val)&0xFF00) >> 8;
    printf OUT_DATA "%c", (hex($val)&0x00FF);
    $byte_cnt += 2;
}

sub write_byte {
    my $val = shift;
    printf OUT_DATA "%c", (hex($val)&0xFF);
    $byte_cnt += 1;
}

$name = $input;
$name =~ s/\..*$//;
`chmod u+w $input`;
`./fix_rgb.pl $input`;
`$root/usr/sbin/rgb2c -F -f $format -s $bpp -m texture $input > $name.h`;

open(OUT_DATA,">$name.bin");
binmode(OUT_DATA);

        open(IN_FILE, "<$name.h");
        while (<IN_FILE>) {
            if (/^\s+0x/) {
                @pixel = split /,\s*/;
                foreach $rgba (@pixel) {
                    $rgba =~ s/^\s*//;
                    if ($bpp=~/16/) {
                        write_short ($rgba);
                    } else {
                        write_byte ($rgba);
                    }
                }
            }
        }
        close IN_FILE;
close OUT_DATA;

