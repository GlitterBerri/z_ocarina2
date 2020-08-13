#!/usr/bin/perl -w

sub expand {
    my $val = shift;
    for ($j=0; $j<8; $j++) {
        $high = ($val & (0x80>>$j))==0 ? 0 : 0xf0;
        $j++;
        $low = ($val & (0x80>>$j))==0 ? 0 : 0x0f;
        printf FONT_ZH "0x%02x, ", ($high|$low);
    }
}

sub gen_font_12x12_4bpp {
    my $b1 = shift;
    my $b2 = shift;
  
    open(FONT_ZH, ">$out_dir/$hb1$hb2.c") or die "Can't open $hb1$hb2.c: $!";
    printf FONT_ZH "unsigned char font_zh_$hb1$hb2\_txt[] = {\n";
    #the first 2 lines of space filler to fill up the glyph to 16x16
    for ($j=0; $j<16; $j++) {
        printf FONT_ZH "0x%02x, ", 0x00;
        if (($j+1)%8==0) { printf FONT_ZH "\n";}
    }

    my $idx = ($b1-$GBCODE_BYTE_OFFSET)*$GBCODE_UNIT_LEN + ($b2-$GBCODE_BYTE_OFFSET);
    my $start = $idx*13;
    my $i = 1, $last = 0x00;

    for ($i=1; $i<13; $i++) {
        $line = $lines[$start+$i-1];
        if ($i%2==1) {                       # odd lines in the glyph
            $line =~ /^\s*(0x[0-9a-fA-F]+),\s*(0x[0-9a-fA-F]+)/;
            expand(hex($1)&0xFF);            # 1st byte on odd lines
            expand(hex($2)&0xF0);            #  1st half of the 2nd byte on odd lines
            $last = $2;
        } elsif ($i%2==0) {                  # even lines in the glyph
            $line =~ /^\s*(0x[0-9a-fA-F]+),/;
            expand(hex($1)&0xFF);            # 1st byte on even lines
            expand((hex($last)<<4)&0x00F0);  # 2nd half of the 2nd byte on odd lines
        }
        printf FONT_ZH "\n";
    }

    #the last 2 lines of space filler to fill up the glyph to 16x16
    for ($j=0; $j<16; $j++) {
        printf FONT_ZH "0x%02x, ", 0x00;
        if (($j+1)%8==0) { printf FONT_ZH "\n";}
    }
    printf FONT_ZH "};";
    close FONT_ZH;
}

die "Usage: process_kanji.pl <msg data file> <GBFONT_12x12.data> <font glyph header file>\n" unless $#ARGV==2;
($in_txt, $font_in, $font_h) = @ARGV;
$in_txt =~ /(.*).c$/;
$out_txt = $1; 
`mkdir font_zh`;
$out_dir = "font_zh";


open(IN_TXT, "<$in_txt") or die "Can't open $in_txt: $!";
open(FONT_C, "+<$font_h") || die "Can't open $font_h: $!";
@tmp = <FONT_C>;
seek(FONT_C, -1, -1);

open(OUT_TXT, ">$out_txt\_zh.c") or die "Can't open $out_txt\_zh.c: $!";
open(OUT_ZH, ">$out_txt\_zh.zh") or die "Can't open $out_txt\_zh.zh: $!";

open(FONT_IN, "<$font_in") or die "Can't open $font_in: $!";
@lines = <FONT_IN>;
close FONT_IN;

$GBCODE_BYTE_OFFSET = 0xa1; # each block stars at 0xA1
$GBCODE_UNIT_LEN = 94;   # each block has 94 characters from 0xA1 to 0xFE
$glyph_idx_base = 0xA08C; # Zelda already had 138 font glyphs, 
                          # Chinese glyph starts at 140 (0x8C)
                          # 0xA0 is used to inidate it's Chinese glyph
$cnt = 0;
$glyph_idx_hi = 0;
$glyph_idx_lo = 0;
$hb1 = 0;
$hb2 = 0;

while (<IN_TXT>) {
    if (/^\#define/ || /^unsigned char/) {
        printf OUT_TXT "%s", $_;
    } else {
        @bytes = split / +/;
        for ($i=0; $i<=$#bytes; $i++) {
            $byte = $bytes[$i];
            if ($byte =~/^(0x[0-9a-fA-F]+)(,)/) {
                $b1 = hex($1);
                if ($b1>=0xA0 && $b1<0xFF) {  # double byte characters
                    $b2 = $bytes[++$i];
                    $b2 =~/^(0x[0-9a-fA-F]+)(,)/; 
                    $b2 = hex($1);
                    
                    if ($b1>=0xAA && $b1<0xB0) {  # non-chinese characters
                        printf OUT_TXT " 0x%2X, 0x%2X,", $b1, $b2;
                    } else {
                        my $key = $b1<<8 | $b2;
                        my $val; 
                        if ($glyphs{$key}) {
                            $val = $glyphs{$key};
                        } else {
                            $val = $glyph_idx_base + $cnt;
                            $glyphs{$key} = $val;
                            printf OUT_ZH "%c%c", $b1, $b2;
                            $hb1 = sprintf("%02x", $b1);
                            $hb2 = sprintf("%02x", $b2);
                            gen_font_12x12_4bpp($b1, $b2);
                            printf FONT_C "#include \"$out_dir\/$hb1$hb2.c\"\n";
                            $cnt ++;
                            printf STDOUT "font glyph $cnt generated: %02x, %02x\n", $b1, $b2;
                        }
                        $glyph_idx_hi = ($val & 0xFF00) >> 8;
                        $glyph_idx_lo = ($val & 0x00FF);
                        printf OUT_TXT " 0x%02x, 0x%02x,", $glyph_idx_hi, $glyph_idx_lo;
                    }
                } else {
                    printf OUT_TXT " %s", $byte;
                }
            } elsif ($byte=~/NZ_NEXTMSG,|NZ_BGM,|NZ_SE,/) {
                printf OUT_TXT " %s %s %s", $byte, $bytes[++$i], $bytes[++$i];
            } else {
                printf OUT_TXT " %s", $byte;
            }
        }
    }
}

print "Total Chinese Characters Used: $cnt\n";
close IN_TXT;
close OUT_TXT;
close OUT_ZH;
close FONT_C;
