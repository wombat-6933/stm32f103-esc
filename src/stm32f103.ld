MEMORY
{
	FLASH (RX) : ORIGIN = 0x8000000, LENGTH = 512K
	SRAM (RWX) : ORIGIN = 0x20000000, LENGTH = 96K
}
SECTIONS
{

	.text : 
	ALIGN(4)
	{ 
		_svector_table = . ;
		startup.o(._vector_table) _evector_table = . ;
		_stext = . ;
		*(.text) _etext = . ; 
	} > FLASH

	.data : 
	ALIGN(4)
	{ _sdata = . ; *(.data) _edata = . ; } > SRAM AT > FLASH

	.bss (NOLOAD):
	ALIGN(4)
	{ _sbss = . ; *(.bss) _ebss = . ; } > SRAM

}
	_s_lma_bss = LOADADDR(.bss);
	_e_lma_bss = LOADADDR(.bss) + SIZEOF(.bss);

	_s_lma_data = LOADADDR(.data);
	_e_lma_data = LOADADDR(.data) + SIZEOF(.data);
