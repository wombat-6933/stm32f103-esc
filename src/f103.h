#ifndef F_103XX
#define F_103XX

#include <stdint.h>

#define RCC_REG_BASE 0x40021000
#define RCC_CR (* (uint32_t *) (RCC_REG_BASE + 0x00))
#define RCC_CFGR (* (uint32_t *) (RCC_REG_BASE + 0x04))
#endif
