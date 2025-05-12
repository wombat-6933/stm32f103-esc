#include<stdint.h>
#define SRAM_DIR (uint32_t*) 0x20000000
extern uint32_t* _etext, _edata, _ebss;

#include"vector_table.h"
/* hay que:
 * hacer vector tabla copiar en flash
 * copiar data de flash a ram
 * llamar a main()
 */

void reset_handler (void)
{
	uint32_t *dstdata = SRAM_DIR;

	uint32_t *srcdata = _etext;

	while (srcdata < _edata)
	{
		*dstdata = *srcdata;
		dstdata++; 
		srcdata++;
	}

	main();
}
