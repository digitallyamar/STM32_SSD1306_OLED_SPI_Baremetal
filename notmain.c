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
#include "rcc.h"
#include "gpio.h"
#include "spi.h"
#include "oled.h"

int notmain(void) {
    /********************************************************************** 
     * Step 1: We will use HSI as the initial clock src until PPL is ready. 
    **********************************************************************/
    
    // Enable HSI clock
    rcc_hsi_clock_on();

    // Set HSI as the initial clock src
    rcc_set_sysclk_src(SYS_CLK_SW_HSI);


    /********************************************************************** 
     * Step 2: Now, let us start configuring for PLL
    **********************************************************************/

    // (i): Enable HSE clock
    rcc_hse_clock_on();

    // (ii): Enable clock for PWR so that we can configure PWR module
    rcc_apb1_peri_clk_enable(PWR_CLK_ENABLE);
    // ** TODO **: Set VOS to scale 1. [power_save = 1]
    // Since this is the default value anyways, we can skip this for now!



    rcc_clk_set_hpre(RCC_CFGR_HPRE_DIV_NONE);
    rcc_clk_set_ppre1(RCC_CFGR_PPRE_DIV_4);
    rcc_clk_set_ppre2(RCC_CFGR_PPRE_DIV_2);


    // (iii): Set prescalers for AHB, ADC, ABP1, ABP2.
    //          pllm = 8, plln = 240, pllp = 2, pllq = 5, pllr = 0,
    //          hpre = RCC_CFGR_HPRE_DIV_NONE,
	//          ppre1 = RCC_CFGR_PPRE_DIV_4,
	//          ppre2 = RCC_CFGR_PPRE_DIV_2
    rcc_clk_set_pllm(8);
    rcc_clk_set_plln(240);
    rcc_clk_set_pllp(2);
    rcc_clk_set_pllq(5);


    rcc_clk_set_pllsrc(RCC_PLLSRC_HSE);

    // (iv): Enable PLL Clock
    rcc_pll_clock_on();

    // (v): Select PPL as the new sys clock source
    rcc_set_sysclk_src(SYS_CLK_SW_PLL);

    // (vi): Finally, disable HSI clock
    rcc_hsi_clock_off();

    /********************************************************************** 
     * Step 3: Configure GPIO pins for SPI
    **********************************************************************/

   // (i): Enable clocks for GPIO A & B
    rcc_ahb1_peri_clk_enable(GPIOA_CLK_ENABLE | GPIOB_CLK_ENABLE);

   // (ii): Enable clock for SPI1
    rcc_apb2_peri_clk_enable(SPI1_CLK_ENABLE);

 
    // (iii): Enable CSS
    rcc_css_on();

    // (iv): Set GPIOA pin PA4 to output mode
    gpio_set_mode(GPIOA, GPIO_PIN_4, GPIO_MODE_OUTPUT);

    // (iv): Set GPIOB pins PB1 & PB0 to output mode
    gpio_set_mode(GPIOB, GPIO_PIN_1, GPIO_MODE_OUTPUT);
    gpio_set_mode(GPIOB, GPIO_PIN_0, GPIO_MODE_OUTPUT);

    // (v): Set GPIOA pins PA7 & PA5 to AF mode for SPI1
    gpio_set_mode(GPIOA, GPIO_PIN_7, GPIO_MODE_ALTFUN);
    gpio_set_mode(GPIOA, GPIO_PIN_5, GPIO_MODE_ALTFUN);

    // (vi): Set GPIOA AF pins PA7 & PA5 to AF5
    gpio_set_af_mode(GPIOA, GPIO_PIN_7, GPIO_AFMODE_AF5);
    gpio_set_af_mode(GPIOA, GPIO_PIN_5, GPIO_AFMODE_AF5);

    spi_master_init(SPI1);

    // OLED operations starts from here!
 
    oled_dc_select(OLED_SELECT_CMD);
    oled_chip_deselect();
    oled_reset();

    oled_chip_select();

    // Start sending OLED Initialization commands
    oled_init();

   return 0; 
}