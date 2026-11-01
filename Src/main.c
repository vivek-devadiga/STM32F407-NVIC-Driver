
/*
 * ============================================================
 * File Name    : main.c
 * Project      : STM32F407 NVIC Driver
 * Hardware     : STM32F407VG
 * Language     : Embedded C (Bare Metal)
 *
 * Description:
 * This file is used to test the NVIC driver functions.
 *
 * Test:
 * Enable USART2 interrupt through the NVIC.
 *
 * USART2 IRQ Number : 38
 * NVIC Register    : ISER1
 * Bit Position     : 6
 *
 * ============================================================
 */

#include "nvic.h"

int main(void)
{
	NVIC_EnableIRQ(38); // Enable USART2 interrupt (IRQ number 38)
	NVIC_DisableIRQ(38); // Disable USART2 interrupt (IRQ number 38)

	NVIC_SetPendingIRQ(38); //SetPending USART2 interrupt (IRQ number 38)
	NVIC_ClearPendingIRQ(38); //ClearPending USART2 interrupt (IRQ number 38)

	NVIC_GetActive(38); // GetActive USART2 interrupt (IRQ number 38)

	NVIC_SetPriority(38U , 3U); //SetPriority
	while(1)
	{

	}
}
