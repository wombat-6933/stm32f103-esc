#ifndef VECTOR_TABLE
#define VECTOR_TABLE
#include<stdint.h>

void default_Handler(void);
void reset_handler(void);
void nmi_handler(void) __attribute__ ((weak, alias("default_Handler")));
uint32_t * vector_table[] __attribute__ ((section("._vector_table"))) =
{
	0x0,
	reset_handler,
	nmi_handler,
	default_Handler,
	default_Handler,
	default_Handler,
	default_Handler,
	default_Handler,
}; 

void default_Handler(void)
{
	while (1);
}
#endif
