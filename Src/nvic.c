
/*
 * ============================================================
 * File Name    : nvic.c
 * Project Name : NVIC_CONFIGURATION
 * Project      : STM32F407 NVIC Driver
 * Language     : Embedded C
 * Programming  : Bare-Metal Register Access
 *
 * Description:
 * This source file contains NVIC driver functions.
 * It provides interrupt enable, disable, pending,
 * pending clear and active status operations using
 * direct memory-mapped register access.
 *
 * Functions:
 * 1. NVIC_EnableIRQ()       - Enable peripheral interrupt.
 * 2. NVIC_DisableIRQ()      - Disable peripheral interrupt.
 * 3. NVIC_SetPendingIRQ()   - Set interrupt pending.
 * 4. NVIC_ClearPendingIRQ() - Clear interrupt pending.
 * 5. NVIC_GetActive()       - Check interrupt active status.
 * 6. NVIC_SetPriority()     - Configure interrupt priority.
 *
 * ============================================================
 */

#include "nvic.h"

/*
 * Function: NVIC_EnableIRQ
 *
 * Purpose:
 * Enable a particular peripheral interrupt in the NVIC.
 *
 * IRQNumber:
 * Interrupt number assigned to the peripheral by ST.
 */

void NVIC_EnableIRQ( uint8_t IRQNumber)
{
	uint8_t register_number;
	uint8_t bit_position;

    if (IRQNumber > 81U)
    {
        return;
    }

    /*
     * STEP 1:
     * Identify which ISER register is required.
     *
     * Each ISER register contains 32 interrupt enable bits.
     *
     * IRQ 0-31  -> ISER0
     * IRQ 32-63 -> ISER1
     * IRQ 64-95 -> ISER2
     *
     * Example:
     * IRQNumber = 38
     * register_number = 38 / 32 = 1 (ISER1)
     */
	register_number = IRQNumber / 32U;

	    /*
	     * STEP 2:
	     * Identify the bit position inside the selected ISER register.
	     *
	     * Example:
	     * IRQNumber = 38
	     * bit_position = 38 % 32 = 6
	     */
	bit_position = IRQNumber % 32U;

    /*
     * STEP 3:
     * Create a pointer to the NVIC ISER registers.
     *
     * NVIC_ISER_BASE = 0xE000E100
     * ISER[0] -> ISER0
     * ISER[1] -> ISER1
     * ISER[2] -> ISER2
     *
     * Volatile ensures hardware register accesses
     * are performed as requested.
     */

	volatile uint32_t *ISER = (volatile uint32_t *)NVIC_ISER_BASE;

    /*
     * STEP 4:
     * Enable the required interrupt by writing 1
     * to the selected register's bit position.
     *
     * Example:
     * ISER[1] = (1U << 6);
     *
     * This enables USART2 interrupt (IRQ 38).
     */

	ISER[register_number] = (1U << bit_position);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * ============================================================
 * Function Name : NVIC_DisableIRQ()
 *
 * Purpose:
 * Disable the selected peripheral interrupt in the NVIC.
 *
 * Parameter:
 * IRQNumber - Interrupt number assigned to the peripheral.
 *
 * Valid IRQ Range:
 * STM32F407 supports external IRQ numbers from 0 to 81.
 *
 * Register Used:
 * ICER - Interrupt Clear-Enable Register.
 *
 * Register Base Address:
 * 0xE000E180
 *
 * Working:
 * 1. Check whether the IRQ number is valid.
 * 2. Calculate the ICER register number using IRQNumber / 32.
 * 3. Calculate the bit position using IRQNumber % 32.
 * 4. Access the ICER register using its base address.
 * 5. Write 1 to the selected bit to disable the interrupt.
 *
 * Example:
 * USART2 IRQ Number = 38
 * Selected Register = ICER1
 * Bit Position      = 6
 *
 * ============================================================
 */

void NVIC_DisableIRQ( uint8_t IRQNumber)
{
	uint8_t register_number;
	uint8_t bit_position;

    if (IRQNumber > 81U)
    {
        return;
    }


	register_number = IRQNumber / 32U;
	bit_position = IRQNumber % 32U;

	volatile uint32_t *ICER = (volatile uint32_t*)NVIC_ICER_BASE;

	ICER[register_number] = (1U << bit_position);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*

* ============================================================
* Function Name : NVIC_SetPendingIRQ()
*
* Purpose:
* Set the pending status of the selected interrupt in NVIC.
*
* Parameter:
* IRQNumber - Interrupt number assigned to the peripheral.
*
* Valid IRQ Range:
* STM32F407 supports external IRQ numbers from 0 to 81.
*
* Register Used:
* ISPR - Interrupt Set-Pending Register.
*
* Register Base Address:
* 0xE000E200
*
* Working:
* 1. Check whether the IRQ number is valid.
* 2. Calculate the ISPR register number using IRQNumber / 32.
* 3. Calculate the bit position using IRQNumber % 32.
* 4. Access the ISPR register using its base address.
* 5. Write 1 to the selected bit to set the interrupt pending.
*
* Example:
* USART2 IRQ Number = 38
* Selected Register = ISPR1
* Bit Position      = 6
*
* ============================================================
  */


void NVIC_SetPendingIRQ(uint8_t IRQNumber)
{
	uint8_t register_number;
	uint8_t bit_position;

    if (IRQNumber > 81U)
    {
        return;
    }

	register_number = IRQNumber / 32U;
	bit_position = IRQNumber % 32U;

	volatile uint32_t *ISPR = (volatile uint32_t*)NVIC_ISPR_BASE;

	ISPR[register_number] = (1U << bit_position);

}

////////////////////////////////////////////////////////////////////////////////////////////////

/*

* ============================================================
* Function Name : NVIC_ClearPendingIRQ()
*
* Purpose:
* Clear the pending status of the selected interrupt in NVIC.
*
* Parameter:
* IRQNumber - Interrupt number assigned to the peripheral.
*
* Valid IRQ Range:
* STM32F407 supports external IRQ numbers from 0 to 81.
*
* Register Used:
* ICPR - Interrupt Clear-Pending Register.
*
* Register Base Address:
* 0xE000E280
*
* Working:
* 1. Check whether the IRQ number is valid.
* 2. Calculate the ICPR register number using IRQNumber / 32.
* 3. Calculate the bit position using IRQNumber % 32.
* 4. Access the ICPR register using its base address.
* 5. Write 1 to the selected bit to clear the interrupt pending.
*
* Example:
* USART2 IRQ Number = 38
* Selected Register = ICPR1
* Bit Position      = 6
*
* ============================================================
  */



void NVIC_ClearPendingIRQ(uint8_t IRQNumber)
{
	uint8_t register_number;
	uint8_t bit_position;

    if (IRQNumber > 81U)
    {
        return;
    }

	register_number = IRQNumber / 32U;
	bit_position = IRQNumber % 32U;

	volatile uint32_t *ICPR = (volatile uint32_t*)NVIC_ICPR_BASE;

	ICPR[register_number] = (1U << bit_position);

}

//////////////////////////////////////////////////////////////////////////////////////////////


/*

* ============================================================
* Function Name : NVIC_GetActive()
*
* Purpose:
* Check whether the selected interrupt is currently active
* in the NVIC.
*
* Parameter:
* IRQNumber - Interrupt number assigned to the peripheral.
*
* Valid IRQ Range:
* STM32F407 supports external IRQ numbers from 0 to 81.
*
* Register Used:
* IABR - Interrupt Active Bit Register.
*
* Register Base Address:
* 0xE000E300
*
* Return Value:
* 1 - Interrupt is currently active.
* 0 - Interrupt is not active or IRQ number is invalid.
*
* Working:
* 1. Check whether the IRQ number is valid.
* 2. Calculate the IABR register number using IRQNumber / 32.
* 3. Calculate the bit position using IRQNumber % 32.
* 4. Read the selected IABR register.
* 5. Extract the required bit.
* 6. Return the active status (0 or 1).
*
* Example:
* USART2 IRQ Number = 38
* Selected Register = IABR1
* Bit Position      = 6
*
* ============================================================
  */

uint8_t NVIC_GetActive(uint8_t IRQNumber)
{
    uint8_t register_number;
    uint8_t bit_position;

    if (IRQNumber > 81U)
    {
        return 0U;
    }

    register_number = IRQNumber / 32U;

    bit_position = IRQNumber % 32U;

    volatile uint32_t *IABR = (volatile uint32_t *)NVIC_IABR_BASE;

    return (uint8_t)((IABR[register_number] >> bit_position) & 1U);
}

/*
 * ============================================================
 * Function Name : NVIC_SetPriority()
 *
 * Purpose:
 * Configure the priority of the selected interrupt.
 *
 * Parameters:
 * IRQNumber - Interrupt number (0 to 81).
 * Priority  - Priority value (0 to 15).
 *
 * Register Used:
 * IPR - Interrupt Priority Register.
 *
 * Register Base Address:
 * 0xE000E400
 *
 * Working:
 * 1. Check whether IRQNumber is valid.
 * 2. Check whether Priority is between 0 and 15.
 * 3. Create a pointer to the IPR registers.
 * 4. Shift the priority value left by 4 bits.
 * 5. Write the priority into the selected interrupt field.
 *
 * Example:
 * USART2 IRQ Number = 38
 * Priority          = 3
 *
 * ============================================================
 */

void NVIC_SetPriority(uint8_t IRQNumber, uint8_t Priority)
{
    volatile uint8_t *IPR = (volatile uint8_t *)NVIC_IPR_BASE;

    if (IRQNumber > 81U)
    {
        return;
    }

    if (Priority > 15U)
    {
        return;
    }

    IPR[IRQNumber] = (uint8_t)(Priority << 4U);
}
