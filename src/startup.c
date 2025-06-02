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
	uint32_t *dstdata = (uint32_t*) BASE_SRAM;

	uint32_t *srcdata = (uint32_t*) _etext;

	while ((uint32_t)srcdata < (uint32_t)_edata)
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
