#!/usr/bin/perl -w

#$GBCODE_BYTE_OFFSET = 0xa1;
#$GBCODE_UNIT_LEN = 94;

$in_txt = shift;
$out_txt = shift;

$cnt = 0;
$glyph_idx_base = 0xA08C;
$glyph_idx_hi = 0;
$glyph_idx_lo = 0;

open(IN_TXT, "<$in_txt") or die "Can't open $in_txt: $!";
open(OUT_TXT, ">$out_txt") or die "Can't open $out_txt: $!";
open(OUT_ZH, ">$out_txt.zh") or die "Can't open $out_txt.zh: $!";
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
                            $cnt ++;
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
