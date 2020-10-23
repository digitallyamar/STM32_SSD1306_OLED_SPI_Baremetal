/**************************** setup clock ************************************/

/* Enable internal high-speed oscillator. */
proc hsi_on {} {mdw 0x40023800;  mww 0x40023800 0x00007881; mdw 0x40023800;}

/* Select HSI as SYSCLK source. */
proc set_sys_clk_hsi {} {mdw 0x40023808; mww 0x40023808 0x0;}

/* Enable external high-speed oscillator 8MHz. */
proc hse_on {} {mdw 0x40023800; mww 0x40023800 0x00017883; mdw 0x40023800;}

/* Enable/disable high performance mode */
proc pwr_clk_en {} {mdw 0x40023840; mww 0x40023840 0x10000000; mdw 0x40023840;}
proc set_vos {} {mdw 0x40007000; mww 0x40007000 0x00004000;}

/****************************************************************************** 
 ******************* Set prescalers for AHB, ADC, ABP1, ABP2. *****************
 
    pllm = 25, plln = 240, pllp = 2, pllq = 5, pllr = 0, 
    hpre = RCC_CFGR_HPRE_DIV_NONE,
	ppre1 = RCC_CFGR_PPRE_DIV_4,
	ppre2 = RCC_CFGR_PPRE_DIV_2,
	power_save = 1
 
 ******************* Do this before touching the PLL. *************************
******************************************************************************/

proc set_xppre {} {mdw 0x40023808; mww 0x40023808 0x00009400;}

/* Configure PLL */
proc cfg_pll {} {mdw 0x40023804; mww 0x40023804 0x05423C08;}

/* Enable PLL oscillator and wait for it to stabilize. */
proc pll_on {} {mdw 0x40023800; mww 0x40023800 0x01037883;}

/* Select PLL as SYSCLK source. */
/* Wait for PLL clock to be selected. */
proc set_sys_clk_pll {} {mdw 0x40023808; mww 0x40023808 0x00009402;}

/* Disable internal high-speed oscillator. */
proc hsi_off {} {mdw 0x40023800; mww 0x40023800 0x00007882;}

// Enable GPIO clock - A (oled), B(oled), C (buttons)
proc oled_gpio_clk_en {} {mdw 0x40023830; mww 0x40023830 0x00100007;}

// Enable SPI clock
proc spi1_clk_en {} {mdw 0x40023844; mww 0x40023844 0x00001000;}

// Enable CSS (Clock Security System)
proc css_en {} {mdw 0x40023800; mww 0x40023800 0x030B7880;}

// Set GPIO for OLED display
proc oled_gpio_pin_cfg {} {mdw 0x40020000; mww 0x40020000 0xa8000100; mdw 0x40020400; mww 0x40020400 0x00000285;}

// Enable SPI 1 for OLED display
proc spi1_gpio_pin_cfg {} {mdw 0x40020000; mww 0x40020000 0xa8008900; mdw 0x40020020; mww 0x40020020 0x50500000;}

/**************************** Initialize SPI1 ************************************/

//Output Enable - Set CR2 SSOE bit
proc spi1_ssoe_en {} {mdw 0x40013004; mww 0x40013004 0x4;}

/* Reset all bits omitting SPE, CRCEN and CRCNEXT bits. */
/* Configure SPI as master. */
/* Set baud rate, CPOL, CPHA, data & frame format bits. */
proc spi_init_master {} {mdw 0x40013000; mww 0x40013000 0x3054;}

/**************************** Initialize OLED ************************************/
proc oled_init_step1 {} {mdw 0x40020414; mww 0x40020414 0x0; mdw 0x40020014; mww 0x40020014 0x10;}
proc oled_init_step2 {} {mdw 0x40020414; mww 0x40020414 0x2; mdw 0x40020414; mww 0x40020414 0x0; mdw 0x40020414; mww 0x40020414 0x2;}
proc oled_init_step3 {} {mdw 0x40020014; mww 0x40020014 0x0;}


/**************************** Send OLED Init Display Commands ************************************/
proc oled_send_init_cmds_1 {} {mww 0x4001300C 0xAE; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xD5; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0x80; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_2 {} {mww 0x4001300C 0xA8; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0x3F; mdw 0x4001300C; mdw 0x40013008;  mww 0x4001300C 0xD3; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_3 {} {mww 0x4001300C 0x0; mdw 0x4001300C; mdw 0x40013008;  mww 0x4001300C 0x40; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0x8D; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_4 {} {mww 0x4001300C 0x14; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0x20; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0x0; mdw 0x4001300C; mdw 0x40013008;} 
proc oled_send_init_cmds_5 {} {mww 0x4001300C 0xA1; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xC8; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xDA; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_6 {} {mww 0x4001300C 0x12; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0x81; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xCF; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_7 {} {mww 0x4001300C 0xD9; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xF1; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xDB; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_8 {} {mww 0x4001300C 0x40; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xA4; mdw 0x4001300C; mdw 0x40013008; mww 0x4001300C 0xA6; mdw 0x4001300C; mdw 0x40013008;}
proc oled_send_init_cmds_9 {} {mww 0x4001300C 0xAF; mdw 0x4001300C; mdw 0x40013008;}
 

/**************************** Main Routines *********************************************/
/** Call these main routines in order manually and get the OLED 0.96" display working! **/
/****************************************************************************************/

proc main1 {} {hsi_on; set_sys_clk_hsi; hse_on; pwr_clk_en; set_vos; set_xppre; cfg_pll; pll_on; set_sys_clk_pll; hsi_off; oled_gpio_clk_en; spi1_clk_en; css_en; oled_gpio_pin_cfg; spi1_gpio_pin_cfg; spi1_ssoe_en; spi_init_master;}
proc main2 {} { oled_init_step1; oled_init_step2; oled_init_step3;}
proc main3 {} {oled_send_init_cmds_1; oled_send_init_cmds_2; oled_send_init_cmds_3; oled_send_init_cmds_4; oled_send_init_cmds_5; oled_send_init_cmds_6; oled_send_init_cmds_7; oled_send_init_cmds_8; oled_send_init_cmds_9;}
