/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (c) 2015, Linaro Limited
 * Copyright (c) 2017, Socionext Inc.
 */

#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#include <mm/generic_ram_layout.h>

/* Make stacks aligned to data cache line length */
#define STACK_ALIGNMENT		64

/* GIC */
#define GIC_BASE		0x5FE00000
#define GICD_OFFSET		0
#define GICC_OFFSET		0x80000

/* UART */
#define UART_CH			0
#define UART_BASE		0x54006800
#define CONSOLE_UART_BASE	(UART_BASE + 0x100 * UART_CH)
#define CONSOLE_BAUDRATE	115200
#define CONSOLE_UART_CLK_IN_HZ	58820000

/*
 *  0xXXXX_XXXX                               -           -
 *    Linux kernel                            |           |
 *  0x9600_0000                               | DRAM#0-#x | Normal memory
 *    Reserved area for Linux drivers         |           |
 *  0x8200_0000                               -           -
 *    TA RAM: 14MiB                           |           |
 *  0x8118_0000                               | TZDRAM    |
 *    TEE RAM: 1 MiB (CFG_TEE_RAM_VA_SIZE)    |           | Secure memory
 *  0x8108_0000 [TZDRAM_BASE, BL32_LOAD_ADDR] -           |
 *    BL31 runtime (defined in ATF code)      |           |
 *  0x8100_0000                               |           -
 *    TEE-REE Shared memory                   | DRAM#0    |
 *  0x80E0_0000                               |           | Normal memory
 *    Reserved area for ucode                 |           |
 *  0x8000_0000 [DRAM0_BASE]                  -           -
 */

#define DRAM0_BASE		0x80000000
#define DRAM0_SIZE		0xC0000000

#define CFG_TEE_LOAD_ADDR	CFG_TZDRAM_START

#endif /* PLATFORM_CONFIG_H */
