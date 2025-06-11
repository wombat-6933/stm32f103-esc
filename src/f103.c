#include "f103.h"


void config_gpio_port_A (gpio_pin_t pin, gpio_mode_t mode, gpio_cnf_t cnf)
{
	uint32_t pos_mode;
	uint32_t pos_cnf;
	uint32_t pinh;

	if (pin > GPIO_PIN_7)
	{
		pinh = pin >> 1;
		pos_mode = (pinh * 4);
		pos_cnf = (pinh * 4) + 2;
		GPIOA_CRH |= (mode << pos_mode) | (cnf << pos_cnf);
	}
	else
	{
		pos_mode = (pin * 4);
		pos_cnf = (pin * 4) + 2;
		GPIOA_CRL |= (mode << pos_mode) | (cnf << pos_cnf);
	}
}
