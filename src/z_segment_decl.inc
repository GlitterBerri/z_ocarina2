#if defined(ROM_F)
#include "rom_f/z_segment.decl"
#elif defined(ROM_X)
#include "rom_x/z_segment.decl"
#elif defined(ROM_D)
#include "rom_d/z_segment.decl"
#elif defined(ROM_S)
#include "rom_s/z_segment.decl"
#else
#error ROM_? が define されていません
#endif
