#ifndef F_103XX
#define F_103XX

#include <stdint.h>

#define RCC_REG_BASE 0x40021000
#define RCC_CR (* (uint32_t *) (RCC_REG_BASE + 0x00))
#define RCC_CFGR (* (uint32_t *) (RCC_REG_BASE + 0x04))
#define RCC_CIR (* (uint32_t *) (RCC_REG_BASE + 0x08))
#define RCC_APB2RSTR (* (uint32_t *) (RCC_REG_BASE + 0x0C))
#define RCC_APB1RSTR (* (uint32_t *) (RCC_REG_BASE + 0x10))
#define RCC_AHBENR (* (uint32_t *) (RCC_REG_BASE + 0x14))
#define RCC_APB2ENR (* (uint32_t *) (RCC_REG_BASE + 0x18))
#define RCC_APB1ENR (* (uint32_t *) (RCC_REG_BASE + 0x1C))
#define RCC_BDCR (* (uint32_t *) (RCC_REG_BASE + 0x20))
#define RCC_CFGR2 (* (uint32_t *) (RCC_REG_BASE + 0x2C))

#define GPIOA_REG_BASE 0x40010800
#define GPIOA_CRL (* (uint32_t *) (GPIOA_REG_BASE + 0x00)) 
#define GPIOA_CRH (* (uint32_t *) (GPIOA_REG_BASE + 0x04)) 
#define GPIOA_IDR (* (uint32_t *) (GPIOA_REG_BASE + 0x08)) 
#define GPIOA_ODR (* (uint32_t *) (GPIOA_REG_BASE + 0x0C)) 
#define GPIOA_BSRR (* (uint32_t *) (GPIOA_REG_BASE + 0x10)) 
#define GPIOA_BRR (* (uint32_t *) (GPIOA_REG_BASE + 0x14)) 
#define GPIOA_LCKR (* (uint32_t *) (GPIOA_REG_BASE + 0x18)) 

#define GPIOB_REG_BASE 0x40010C00
#define GPIOC_REG_BASE 0x40011000
#define GPIOD_REG_BASE 0x40011400
#define GPIOE_REG_BASE 0x40011800
#define GPIOF_REG_BASE 0x40011C00
#define GPIOG_REG_BASE 0x40012000

typedef enum 
{
	INPUT = 0b00,
	OUTPUT_10MHZ = 0b01,
	OUTPUT_2MHZ = 0b10,
	OUTPUT_50MHZ = 0b11
}gpio_mode_t;

typedef enum 
{
	IN_ANALOG_OUT_PUSHPULL = 0b00,
	IN_FLOAT_OUT_OPENDRAIN = 0b01,
	IN_PULLUPDOWN_AF_PUSHPULL = 0b10,
	AF_OPENDRAIN = 0b11
}gpio_cnf_t;

typedef enum 
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
}gpio_pin_t;

void config_gpio_port_A (gpio_pin_t pin, gpio_mode_t mode, gpio_cnf_t cnf);

#endif
