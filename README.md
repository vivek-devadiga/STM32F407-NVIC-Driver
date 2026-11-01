# STM32F407 NVIC Driver

## Project Overview

This project focuses on understanding and implementing the Nested Vectored Interrupt Controller (NVIC) of the STM32F407VG microcontroller.

I developed this driver using Embedded C and direct register access without using HAL or CMSIS libraries.

The main objective was to understand how interrupts are enabled, disabled, prioritized and managed at the processor level.

## Hardware and Software

* **Microcontroller:** STM32F407VG
* **IDE:** STM32CubeIDE
* **Language:** Embedded C
* **Programming approach:** Bare-metal programming
* **Debugging:** STM32CubeIDE Debugger

## Project Structure

```text
NVIC_CONFIGURATION/
│
├── Inc/
│   └── nvic.h
│
├── Src/
│   ├── main.c
│   └── nvic.c
│
├── Startup/
├── document/
│   └── STM32F407_NVIC_Driver_Test_Report.docx
│
├── STM32F407VGTX_FLASH.ld
├── STM32F407VGTX_RAM.ld
└── README.md
```

## Implemented Functions

| Function               | Description                           |
| ---------------------- | ------------------------------------- |
| NVIC_EnableIRQ()       | Enables the selected interrupt        |
| NVIC_DisableIRQ()      | Disables the selected interrupt       |
| NVIC_SetPendingIRQ()   | Sets an interrupt as pending          |
| NVIC_ClearPendingIRQ() | Clears the pending status             |
| NVIC_GetActive()       | Checks whether an interrupt is active |
| NVIC_SetPriority()     | Configures interrupt priority         |

## Registers Used

| Register | Purpose                          |
| -------- | -------------------------------- |
| ISER     | Interrupt Set-Enable Register    |
| ICER     | Interrupt Clear-Enable Register  |
| ISPR     | Interrupt Set-Pending Register   |
| ICPR     | Interrupt Clear-Pending Register |
| IABR     | Interrupt Active Bit Register    |
| IPR      | Interrupt Priority Register      |

## Important Concepts Learned

* NVIC architecture and interrupt handling.
* IRQ number and register mapping.
* Bit-position calculation using division and modulo.
* Memory-mapped register access using pointers.
* Interrupt pending and active status.
* Interrupt priority configuration.
* Volatile pointers for hardware register access.

## Testing

The driver was built and tested using STM32CubeIDE.

Register values were inspected through the debugger's Memory view.

USART2 (IRQ38) was used as an example for testing interrupt configuration.

The priority configuration was verified by setting priority 3 and observing `0x30` at address `0xE000E426`.

Additional testing details are available in the `document` folder.

## Learning Outcome

Through this project, I gained practical experience working with Cortex-M4 interrupt management and writing a basic NVIC driver using direct register access.

This project also provides a foundation for learning EXTI and handling GPIO interrupts.

## Repository

GitHub: STM32F407-NVIC-Driver

---

**Project:** STM32F407 NVIC Driver
**Programming:** Embedded C | Bare-Metal
