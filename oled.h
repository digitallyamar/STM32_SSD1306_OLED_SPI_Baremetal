#ifndef __OLED_H__
#define __OLED_H__

#define OLED_CS_SELECT                      (0 << 4)
#define OLED_CS_DESELECT                    (1 << 4)

#define OLED_SELECT_CMD                     ~1
#define OLED_SELECT_DATA                    1

#define RESET_PIN_DISABLE                   (1 << 1)
#define RESET_PIN_ENABLE                    ~(1 << 1)



// OLED Init commands
#define OLED_SETCONTRAST                    0x81
#define OLED_DISPLAYALLON_RESUME            0xA4
#define OLED_DISPLAYALLON                   0xA5
#define OLED_NORMALDISPLAY                  0xA6
#define OLED_INVERTDISPLAY                  0xA7
#define OLED_DISPLAYOFF                     0xAE
#define OLED_DISPLAYON                      0xAF
#define OLED_SETDISPLAYOFFSET               0xD3
#define OLED_SETCOMPINS                     0xDA
#define OLED_SETVCOMDETECT                  0xDB
#define OLED_SETDISPLAYCLOCKDIV             0xD5
#define OLED_SETPRECHARGE                   0xD9
#define OLED_SETMULTIPLEX                   0xA8
#define OLED_SETLOWCOLUMN                   0x00
#define OLED_SETHIGHCOLUMN                  0x10
#define OLED_SETSTARTLINE                   0x40
#define OLED_MEMORYMODE                     0x20
#define OLED_COMSCANINC                     0xC0
#define OLED_COMSCANDEC                     0xC8
#define OLED_SEGREMAP                       0xA0
#define OLED_CHARGEPUMP                     0x8D

void oled_dc_select(int selection);
void oled_chip_select(void);
void oled_chip_deselect(void);
void oled_reset(void);
void oled_init(void);

#endif