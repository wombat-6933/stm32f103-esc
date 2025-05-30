#include<stdint.h>

extern uint32_t* _etext, _edata, _ebss;
void main (void);

#include "vector_table.h"
/* hay que:
 * disable irq
 * hacer vector tabla copiar en flash
 * copiar data de flash a ram
 * llamar a main()
 */

void _Reset_handler_(void)
{
	uint32_t *dstdata = BASE_SRAM;

	uint32_t *srcdata = _etext;

	while (srcdata < _edata)
	{
		*dstdata = *srcdata;
		dstdata++; 
		srcdata++;
	}

	main();
}

void default_Handler(void)
{
	while (1);
}
