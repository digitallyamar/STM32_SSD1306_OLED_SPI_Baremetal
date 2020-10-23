/*****************************************************************************
 * notmain.c: A simple demo code to get 0.96 inch OLED driven by SSD1306
 * connected to SPI1 of the STM32F407VET blackboard working.
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

#include "stm32f4.h"

void PUT32( unsigned int, unsigned int );
unsigned int GET32( unsigned int );
unsigned int DELAY ( unsigned int );

int notmain(void) {
    
    return 0; 
}