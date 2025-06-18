#include<stdint.h>

extern uint32_t _stext, _etext;
extern uint32_t _sdata, _edata;
extern uint32_t _sbss, _ebss;
extern uint32_t _s_lma_data, _e_lma_data;
extern uint32_t _s_lma_bss, _e_lma_bss;

void main (void);

#include "vector_table.h"
/* hay que:
 * disable irq
 * hacer vector tabla copiar en flash
 * copiar data de flash a ram
 * inizializar bss a 0 en ram
 * enable global interrupts (?) si no en main cuando sea necesario
 * llamar a main()
 */

int prueba_data = 2;
int prueba_bss;

void _Reset_handler_(void)
{
	uint32_t *dstdata = &_sdata;
	uint32_t *srcdata = &_s_lma_data;

	while (srcdata < &_e_lma_data)
	{
		*dstdata = *srcdata;
		dstdata++; 
		srcdata++;
	}

	uint32_t *dstbss = &_sbss;

	while (dstbss < &_e_lma_bss)
	{
		*dstbss = 0;
		dstbss++; 
	}

	main();
}

void default_Handler(void)
{
	while (1);
}
