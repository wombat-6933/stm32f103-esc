#ifndef VECTOR_TABLE
#define VECTOR_TABLE
#include<stdint.h>

void reset_handler(void);
void nmi_handler(void) __attribute__ ((weak, alias("default_Handler")));
uint32_t * vector_table[] __attribute__ ((section("._vector_table"))) =
{
	reset_handler,
	nmi_handler,

}; 

void default_Handler(void)
{
	while (1);
}
#endif
