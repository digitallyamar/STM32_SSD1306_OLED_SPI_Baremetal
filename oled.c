#include "stm32f4.h"
#include "spi.h"
#include "gpio.h"
#include "oled.h"

/************************************************************************
** OLED Pin Cnxns:
                        -------------
                        | GPIO|OLED |
                        -------------
                        | PA4 |  CS |
                        | PB0 |  DC |
                        | PB1 | RES |
                        | PA7 | SDA |
                        | PA5 | SCK |
                        -------------
************************************************************************/

void oled_chip_select(void) {
    // We neeed to pull PA4 low
    unsigned int gpioa_odr_val = GET32(GPIO_0DR(GPIOA));
    gpioa_odr_val &= OLED_CS_SELECT;

    PUT32(GPIO_0DR(GPIOA), gpioa_odr_val);
}

void oled_chip_deselect(void) {
    // We neeed to pull PA4 high
    unsigned int gpioa_odr_val = GET32(GPIO_0DR(GPIOA));
    gpioa_odr_val |= OLED_CS_DESELECT;

    PUT32(GPIO_0DR(GPIOA), gpioa_odr_val);
}

void oled_dc_select(int selection) {
    unsigned int gpiob_odr_val = GET32(GPIO_0DR(GPIOB));
    if (selection == OLED_SELECT_CMD) {
        // We need to pull PB0 low
        gpiob_odr_val &= OLED_SELECT_CMD;
    } else {
        // We need to pull PB0 high
        gpiob_odr_val &= OLED_SELECT_DATA;         
    }

    PUT32(GPIO_0DR(GPIOB), gpiob_odr_val);
}

void oled_reset(void) {
    //We will first pull PB1 HIGH, then LOW & back to HIGH again
    unsigned int gpiob_odr_val = GET32(GPIO_0DR(GPIOB));
    
    gpiob_odr_val |= RESET_PIN_DISABLE;
    PUT32(GPIO_0DR(GPIOB), gpiob_odr_val);
    DELAY(1000);

    gpiob_odr_val &= RESET_PIN_ENABLE;
    PUT32(GPIO_0DR(GPIOB), gpiob_odr_val);
    DELAY(1000);

    gpiob_odr_val |= RESET_PIN_DISABLE;
    PUT32(GPIO_0DR(GPIOB), gpiob_odr_val);
}

void oled_init(void) {
    // To initialize OLED, we need to send 25 OLED commands
    // We will store these commands in an array
    // We then write them to the SPI one by one


    static const char oled_initcmds[25] = {
        OLED_DISPLAYOFF,
        OLED_SETDISPLAYCLOCKDIV,
        0x80,
        OLED_SETMULTIPLEX,
        0x3F, // 128x64
        OLED_SETDISPLAYOFFSET,
        0x00,
        OLED_SETSTARTLINE | 0x00,
        OLED_CHARGEPUMP,
        0x14,
        OLED_MEMORYMODE,
        0x00,
        OLED_SEGREMAP | 0x01,
        OLED_COMSCANDEC,
        OLED_SETCOMPINS,
        0x12, // 128x64
        OLED_SETCONTRAST,
        0xCF,
        OLED_SETPRECHARGE,
        0xF1,
        OLED_SETVCOMDETECT,
        0x40,
        OLED_DISPLAYALLON_RESUME,
        OLED_NORMALDISPLAY,
        OLED_DISPLAYON
    };

    for (int i = 0; i < sizeof(oled_initcmds); i++) {
        spi_master_send_half_duplex(SPI1, oled_initcmds[i]);
    }

}