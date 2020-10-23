/*****************************************************************************
 * startup.s: Basic startup code to get the STM32 get going & to prepare the 
 * runtime environment to be able to run C programs.
 *****************************************************************************
 * Copyright (C) 2020-2021
 *  
 * Author: DigitallyAmar (@digitallyamar)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/


.thumb_func @This directive tells the assembler that the next symbol will point to a Function written in ARM Thumb Code
.global _start  @Every GNU startup assembler file need to have an _start function

_start:
stacktop: .word 0x20001000    @In case of cortex-m, we need to place IVT at reset address with first word pointing to SP value
.word reset
.word hang

.thumb_func
reset:
    bl notmain
    b hang

.thumb_func
hang:
    b .

.thumb_func
.globl PUT32                @Writes a value to a 32-bit register/address space
PUT32:
    str r1,[r0]
    bx lr

.thumb_func
.globl GET32
GET32:                      @Reads the value from a 32-bit register/address space
    ldr r0,[r0]
    bx lr

.thumb_func
.globl DELAY                @Sleep function that loop subtracts a value to zero. A very crude way of implementing a delay.
DELAY:
1:  sub r0, r0, #1
    cmp r0, #0
    bne 1b
    bx lr
