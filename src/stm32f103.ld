ENTRY(_start)

MEMORY
{
	FLASH: ORIGIN = 0x8000000 , LENGTH = 512K
	SRAM: ORIGIN = 0x20000000 , LENGTH = 96K
}
SECTIONS
{

	.text : 
	{ *(.text) _etext = . ; } > FLASH

	.data : 
	{ *(.data) _edata = . ; }

}
