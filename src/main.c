#include "f103.h"

int main(void)
{
	
	uint32_t rcc_rc, rcc_cfgr, rcc;

	rcc_rc = RCC_CR;
	rcc_cfgr = RCC_CFGR;
	rcc = RCC_AHBENR;
	while (1);
   return 0;
}
