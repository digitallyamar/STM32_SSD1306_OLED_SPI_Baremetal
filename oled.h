#ifndef __OLED_H__
#define __OLED_H__

#define OLED_CS_SELECT                      (0 << 4)
#define OLED_CS_DESELECT                    (1 << 4)

#define OLED_SELECT_CMD                     ~1
#define OLED_SELECT_DATA                    1

#define RESET_PIN_DISABLE                   (1 << 1)
#define RESET_PIN_ENABLE                    ~(1 << 1)

#define OLED_WIDTH                          128
#define OLED_HEIGHT                         64
#define OLED_BUFFER_SIZE                    (OLED_WIDTH * OLED_HEIGHT) / 8

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

#define OLED_HORIZ_SCROLL_RIGHT             0x26
#define OLED_HORIZ_SCROLL_LEFT              0x27
#define OLED_VERT_SCROLL_RIGHT              0x29
#define OLED_VERT_SCROLL_LEFT               0x2A
#define OLED_VERT_SCROLL_OFFSET_1           0x01
#define OLED_VERT_SCROLL_OFFSET_63          0x3F

#define OLED_SCROLL_DEACTIVATE              0x2E
#define OLED_SCROLL_ACTIVATE                0x2F

void oled_dc_select(int selection);
void oled_chip_select(void);
void oled_chip_deselect(void);
void oled_reset(void);
void oled_init(void);
void oled_clear(void);
void oled_draw(unsigned char new_img[]);
void oled_refresh(void);
void oled_flip_up(void);
void oled_flip_down(void);
void oled_scroll_left(void);
void oled_scroll_right(void);
void oled_scroll_up_right(void);
void oled_scroll_up_left(void);
void oled_scroll_down(void);
void oled_scroll_activate(void);
void oled_scroll_deactivate(void);

#endif