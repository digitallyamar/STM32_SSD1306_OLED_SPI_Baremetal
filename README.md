# STM32_SSD1306_OLED_SPI_Baremetal
Baremetal code to drive SSD1306 OLED Driver connected to an STM32F407 Board through SPI.

## To run:

	- On term1, run the command:
		- openocd -f interface/stlink-v2.cfg -f target/stm32f4x.cfg

	- On term2, run the command:
		- telnet localhost 4444
		- reset halt

		- Continue on term2. Enter each of the TCL commands & functions in the script manually.
		- Once done, call the main functions in order:
			- main1
			- main2
			- main3
		- You should now have your 0.96" OLED working!
