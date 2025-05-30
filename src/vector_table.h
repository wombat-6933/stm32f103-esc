#ifndef VECTOR_TABLE
#define VECTOR_TABLE
#include<stdint.h>

#define BASE_SRAM 0x20000000
#define END_SRAM (BASE_SRAM + 56e3 - 1)
#define _MSP_BASE_ END_SRAM

void default_Handler(void);

// ---- exception declaration ---
void _Reset_handler_(void);
void _NMI_(void) __attribute__ ((weak, alias("default_Handler")));
void _HardFault_(void) __attribute__ ((weak, alias("default_Handler")));
void _MemManage_(void) __attribute__ ((weak, alias("default_Handler")));
void _BusFault_(void) __attribute__ ((weak, alias("default_Handler")));
void _UsageFault_(void) __attribute__ ((weak, alias("default_Handler")));
void _SVCall_(void) __attribute__ ((weak, alias("default_Handler")));
void _Debug_Monitor_(void) __attribute__ ((weak, alias("default_Handler")));
void _PendSV_(void) __attribute__ ((weak, alias("default_Handler")));
void _SysTick_(void) __attribute__ ((weak, alias("default_Handler")));

// ----irq declarations ----

uint32_t vector_table[] __attribute__ ((section("._vector_table"))) =
{
// ---- exceptions ------
(uint32_t)	_MSP_BASE_,
(uint32_t)	_Reset_handler_,
(uint32_t)	_NMI_,
(uint32_t)	_HardFault_,
(uint32_t)	_MemManage_,
(uint32_t)	_BusFault_,
(uint32_t)	_UsageFault_,

// --- reserved ---
0, 0, 0, 0,

(uint32_t)	_SVCall_,
(uint32_t)	_Debug_Monitor_,

// ---- reserved ---
0,

(uint32_t)	_PendSV_,
(uint32_t)	_SysTick_,

// ---- las irq normales son 60 a partir de aqui -----
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
(uint32_t)	default_Handler,
}; 

#endif
