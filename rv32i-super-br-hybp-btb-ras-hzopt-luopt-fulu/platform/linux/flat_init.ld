ENTRY(_start)
SECTIONS
{
    . = 0;
    .text :
    {
        *(.text.start)
        *(.text*)
        *(.rodata*)
    }
    /DISCARD/ :
    {
        *(.comment)
        *(.note*)
        *(.riscv.attributes)
    }
}
