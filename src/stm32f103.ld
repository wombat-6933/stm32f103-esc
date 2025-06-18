__STACK_SIZE = 0x00000C00;
__HEAP_SIZE  = 0x00000A00;

OUTPUT_ARCH(arm)

MEMORY
{
	FLASH (RX) : ORIGIN = 0x8000000, LENGTH = 128K
	SRAM (RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}
SECTIONS
{

	.text : 
	ALIGN(4)
	{ 
		_svector_table = . ;
		KEEP(startup.o(._vector_table)) _evector_table = . ;
		_stext = . ;
		*(.text) 
		_etext = . ; 
	} > FLASH

	.data : 
	ALIGN(4)
	{ 
		_sdata = . ; 
		*(.data) 
		*(.data.*)
		_edata = . ; 
	} > SRAM AT > FLASH

	.bss (NOLOAD):
	ALIGN(4)
	{ 
		_sbss = . ; 
		*(.bss) 
		*(.bss.*)
		*(COMMON)
		_ebss = . ; 
	} > SRAM

	.heap (NOLOAD) :
	{
		. = ALIGN(8);
		__END_HEAP = .;
		. = __HEAP_SIZE;
		__START_HEAP = .;
	} > SRAM

	.stack (NOLOAD) :
	{
		. = ALIGN(8);
		__END_STACK = .;
		. = __STACK_SIZE;
		__START_STACK = .;
	} > SRAM

}
	_s_lma_bss = LOADADDR(.bss);
	_e_lma_bss = LOADADDR(.bss) + SIZEOF(.bss);

	_s_lma_data = LOADADDR(.data);
	_e_lma_data = LOADADDR(.data) + SIZEOF(.data);
