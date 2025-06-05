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

#endif
