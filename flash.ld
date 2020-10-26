MEMORY
{
	flash :	ORIGIN = 0x08000000, LENGTH = 0x10000
	ram :	ORIGIN = 0x20000000, LENGTH = 0x1000
}

SECTIONS
{
	.text	:	{	*(.text*)	} > flash
	.rodata	:	{	*(.rodata*) } > flash
	.bss	:	{	*(.bss*)	} > ram
}
