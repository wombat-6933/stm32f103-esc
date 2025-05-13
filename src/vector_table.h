#ifndef VECTOR_TABLE
#define VECTOR_TABLE
#include<stdint.h>

#define END_SRAM 0x2
#define _MSP_VALUE END_SRAM
void default_Handler(void);
void reset_handler(void);
void nmi_handler(void) __attribute__ ((weak, alias("default_Handler")));
uint32_t vector_table[] __attribute__ ((section("._vector_table"))) =
{
(uint32_t)	0x0,
(uint32_t)	reset_handler,
(uint32_t)	nmi_handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
}; 

void default_Handler(void)
{
	while (1);
}
#endif
