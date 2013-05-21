.entry my_kernel
{
    .lmem 0
    .smem 24
    .reg 2
    .bar 0
    add.u32 $r11, $r11, $r11
    sub.u32 $r11, c1[0x0000], $r11
}
