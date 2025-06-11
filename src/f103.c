#include "f103.h"

enum gpio_mode
{
	INPUT = 0b00,
	OUTPUT_10MHZ = 0b01,
	OUTPUT_2MHZ = 0b10,
	OUTPUT_50MHZ = 0b11
};

enum gpio_cnf
{
	IN_ANALOG_OUT_PUSHPULL = 0b00,
	IN_FLOAT_OUT_OPENDRAIN = 0b01,
	IN_PULLUPDOWN_AF_PUSHPULL = 0b10,
	AF_OPENDRAIN = 0b11
};

enum gpio_pin
{
	GPIO_PIN_0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15
};

void config_gpio_port_A (GPIO_PIN_T pin, GPIO_MODE_T mode, GPIO_CNF_T cnf)
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
