#include "f103.h"

int main(void)
{
	
	uint32_t rcc_rc, rcc_cfgr, rcc;

	rcc_rc = RCC_CR;
	rcc_cfgr = RCC_CFGR;
	rcc = RCC_AHBENR;

	config_gpio_port_A(GPIO_PIN_2, OUTPUT_10MHZ, IN_ANALOG_OUT_PUSHPULL);

	while (1)
	{
		GPIOA_ODR |= (1 << GPIO_PIN_2);
		for (uint32_t i=0; i<0x01000000; i++);
		GPIOA_ODR &= ~(1 << GPIO_PIN_2);
		for (uint32_t i=0; i<0x01000000; i++);
	}
	while (1);
   return 0;
}
