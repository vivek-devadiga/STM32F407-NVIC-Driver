/*

* ============================================================
* File Name    : nvic.h
* Project      : STM32F407 NVIC Driver
* Hardware     : STM32F407VG
* Language     : Embedded C (Bare Metal)
*
* Description:
* This header file contains NVIC register base addresses
* and function declarations.
*
* ============================================================
  */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>

/* NVIC Register Base Addresses */

#define NVIC_ISER_BASE    0xE000E100U
#define NVIC_ICER_BASE    0xE000E180U
#define NVIC_ISPR_BASE    0xE000E200U
#define NVIC_ICPR_BASE    0xE000E280U
#define NVIC_IABR_BASE    0xE000E300U
#define NVIC_IPR_BASE 0xE000E400U

/* NVIC Driver Function Declarations */

void NVIC_EnableIRQ(uint8_t IRQNumber);
void NVIC_DisableIRQ(uint8_t IRQNumber);

void NVIC_SetPendingIRQ(uint8_t IRQNumber);
void NVIC_ClearPendingIRQ(uint8_t IRQNumber);

uint8_t NVIC_GetActive(uint8_t IRQNumber);

void NVIC_SetPriority(uint8_t IRQNumber, uint8_t Priority);

#endif /* NVIC_H_ */
