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


unsigned char _oledbuffer[OLED_BUFFER_SIZE];

void oled_flip_up(void) {
    int scroll_step_count = 0x0;

    oled_dc_select(OLED_SELECT_CMD);

    while(scroll_step_count <= 0x3F) {
        scroll_step_count++;
        spi_master_send_half_duplex(SPI1, OLED_SETSTARTLINE + scroll_step_count);

        DELAY(9999);
    }
}

void oled_flip_down(void) {
    int scroll_step_count = 0x3F;

    oled_dc_select(OLED_SELECT_CMD);

    while(scroll_step_count) {
        spi_master_send_half_duplex(SPI1, OLED_SETSTARTLINE + scroll_step_count);
        scroll_step_count--;

        DELAY(9999);
    }
}

void oled_scroll_right(void) {

    oled_dc_select(OLED_SELECT_CMD);
    
    //TODO: We are adding delays here as frequencies might
    // not have been configured correctly. TBD later!

    spi_master_send_half_duplex(SPI1, OLED_HORIZ_SCROLL_RIGHT);
    DELAY(1000);
    // Send Dummy Byte 0x00
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);
    // Set start page address as PAGE 0
    spi_master_send_half_duplex(SPI1, 0x0);    
    DELAY(1000);
    // Set time interal between each scroll step as 5 frames
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);
    // Set end page address as PAGE 7
    spi_master_send_half_duplex(SPI1, 0x7);
    DELAY(1000);

    // Dummy Byte
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);

    // Dummy Byte
    spi_master_send_half_duplex(SPI1, 0xFF);
    DELAY(1000);
}


void oled_scroll_left(void) {

    oled_dc_select(OLED_SELECT_CMD);
    
    //TODO: We are adding delays here as frequencies might
    // not have been configured correctly. TBD later!

    spi_master_send_half_duplex(SPI1, OLED_HORIZ_SCROLL_LEFT);
    DELAY(1000);
    // Send Dummy Byte 0x00
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);
    // Set start page address as PAGE 0
    spi_master_send_half_duplex(SPI1, 0x0);    
    DELAY(1000);
    // Set time interal between each scroll step as 5 frames
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);
    // Set end page address as PAGE 7
    spi_master_send_half_duplex(SPI1, 0x7);
    DELAY(1000);

    // Dummy Byte
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);

    // Dummy Byte
    spi_master_send_half_duplex(SPI1, 0xFF);
    DELAY(1000);
}

void oled_scroll_up_right(void) {

    oled_dc_select(OLED_SELECT_CMD);
    
    //TODO: We are adding delays here as frequencies might
    // not have been configured correctly. TBD later!

    spi_master_send_half_duplex(SPI1, OLED_VERT_SCROLL_RIGHT);
    DELAY(1000);
    // Send Dummy Byte 0x00
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);
    // Set start page address as PAGE 0
    spi_master_send_half_duplex(SPI1, 0x0);    
    DELAY(1000);
    // Set time interal between each scroll step as 5 frames
    spi_master_send_half_duplex(SPI1, 0x7);
    DELAY(1000);
    // Set end page address as PAGE 7
    spi_master_send_half_duplex(SPI1, 0x7);
    DELAY(1000);

    // Set vertical scrolling effect
    spi_master_send_half_duplex(SPI1, OLED_VERT_SCROLL_OFFSET_63);
    DELAY(1000);
}

void oled_scroll_up_left(void) {

    oled_dc_select(OLED_SELECT_CMD);
    
    //TODO: We are adding delays here as frequencies might
    // not have been configured correctly. TBD later!

    spi_master_send_half_duplex(SPI1, OLED_VERT_SCROLL_LEFT);
    DELAY(1000);
    // Send Dummy Byte 0x00
    spi_master_send_half_duplex(SPI1, 0x0);
    DELAY(1000);
    // Set start page address as PAGE 0
    spi_master_send_half_duplex(SPI1, 0x0);    
    DELAY(1000);
    // Set time interal between each scroll step as 5 frames
    spi_master_send_half_duplex(SPI1, 0x7);
    DELAY(1000);
    // Set end page address as PAGE 7
    spi_master_send_half_duplex(SPI1, 0x7);
    DELAY(1000);

    // Set vertical scrolling effect
    spi_master_send_half_duplex(SPI1, OLED_VERT_SCROLL_OFFSET_63);
    DELAY(1000);
}

void oled_scroll_down(void) {
    oled_scroll_up_right();
    oled_scroll_up_left();
}

void oled_scroll_activate(void) {
    oled_dc_select(OLED_SELECT_CMD);
    // Activate scrolling
    spi_master_send_half_duplex(SPI1, OLED_SCROLL_ACTIVATE);
    DELAY(1000);
}

void oled_scroll_deactivate(void) {
    oled_dc_select(OLED_SELECT_CMD);
    // De-Activate scrolling
    spi_master_send_half_duplex(SPI1, OLED_SCROLL_DEACTIVATE);
    DELAY(1000);
}

void oled_clear(void) {
    oled_dc_select(OLED_SELECT_DATA);

    for (int i=0; i < OLED_BUFFER_SIZE; i++) {
        _oledbuffer[i] = 0x0;
        spi_master_send_half_duplex(SPI1, _oledbuffer[i]);
    }
}

void oled_draw(unsigned char new_img[]) {
    oled_dc_select(OLED_SELECT_DATA);

    for (int i=0; i < OLED_BUFFER_SIZE; i++) {
        _oledbuffer[i] = new_img[i];
    }
}

void oled_refresh(void) {
    oled_dc_select(OLED_SELECT_DATA);

    for (int i=0; i < OLED_BUFFER_SIZE; i++) {
        spi_master_send_half_duplex(SPI1, _oledbuffer[i]);
    }
}

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
        gpiob_odr_val |= OLED_SELECT_DATA;         
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