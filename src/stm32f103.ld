MEMORY
{
	FLASH (RX) : ORIGIN = 0x8000000, LENGTH = 512K
	SRAM (RWX) : ORIGIN = 0x20000000, LENGTH = 96K
}
SECTIONS
{

	.text : 
	/*ALIGN(4)*/
	{ 
		startup.o(._vector_table) _evector_table = . ;
		*(.text) _etext = . ; 
	} > FLASH

	.data : 
	/*ALIGN(4)*/
	{ *(.data) _edata = . ; } > SRAM AT > FLASH

}
