ENTRY(_start)

SECTIONS
{

	.text 0x8000000 : 
	{ *(.text) _etext = . ; }

	.data : 
	ALIGN(4)
	{ *(.data) _edata = . ; }

	.bss : 
	ALIGN(4)
	{ *(.bss) _ebss = . ; }

}
