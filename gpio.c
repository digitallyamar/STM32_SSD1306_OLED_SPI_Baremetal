#include "stm32f4.h"
#include "gpio.h"

void gpio_set_mode(int port, int pin, int mode) {
    unsigned int gpio_mode_val = GET32(GPIO_MODER(port));
    
    gpio_mode_val &= (~((GPIO_MODE_MASK) << (pin * GPIO_MODE_BITS_SIZE)));
    gpio_mode_val |= (mode << (pin * GPIO_MODE_BITS_SIZE));

    PUT32(GPIO_MODER(port), gpio_mode_val);
}

void gpio_set_af_mode(int port, int pin, int af_mode) {
    unsigned int gpio_af_mode_val;
    
    if (pin < 8) {
        gpio_af_mode_val = GET32(GPIO_AFRL(port));
    }
    else {
        gpio_af_mode_val = GET32(GPIO_AFRH(port));
    }

    gpio_af_mode_val &= (~((GPIO_AFMODE_MASK) << (pin * GPIO_AFMODE_BITS_SIZE)));
    gpio_af_mode_val |= (af_mode << (pin * GPIO_AFMODE_BITS_SIZE));

    if (pin < 8) {
        PUT32(GPIO_AFRL(port), gpio_af_mode_val);
    }
    else {
        PUT32(GPIO_AFRH(port), gpio_af_mode_val);
    }

}