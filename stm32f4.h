#ifndef __STM32F4_H__
#define __STM32F4_H__


#define AHB3_BASE               0xA0000000
#define AHB2_BASE               0x50000000
#define AHB1_BASE               0x40020000
#define APB2_BASE               0x40010000
#define APB1_BASE               0x40000000


/************************************************************************/
/*************************** AHB3 Peripherals ***************************/
/************************************************************************/

/* FSMC */
#define FSMC_BASE                (AHB3_BASE)


/************************************************************************/
/*************************** AHB2 Peripherals ***************************/
/************************************************************************/

/* RNG */
#define RNG_BASE                (AHB2_BASE + 0x60800)

/* HASH */
#define HASH_BASE               (AHB2_BASE + 0x60400)

/* CRYP */
#define CRYP_BASE               (AHB2_BASE + 0x60000)

/* DCMI */
#define DCMI_BASE               (AHB2_BASE + 0x50000)

/* USB OTG HS */
#define OTG_FS_BASE             (AHB2_BASE)


/************************************************************************/
/*************************** APB2 Peripherals ***************************/
/************************************************************************/

/* USB OTG HS */
#define OTG_HS_BASE             (AHB1_BASE + 0x20000)

/* DMA2D */
#define DMA2D_BASE              (AHB1_BASE + 0xB000)

/* Ethernet MAC */
#define ETH_BASE                (AHB1_BASE + 0x8000)

/* DMA2 */
#define DMA2_BASE               (AHB1_BASE + 0x4000)

/* DMA1 */
#define DMA1_BASE               (AHB1_BASE + 0x4000)

/* BKPSRAM */
#define BKPSRAM_BASE            (AHB1_BASE + 0x4000)

/* Flash Interface */
#define FLASH_INT_BASE          (AHB1_BASE + 0x3C00)

/* RCC */
#define RCC_BASE                (AHB1_BASE + 0x3800)

/* CRC */
#define CRC_BASE                (AHB1_BASE + 0x3000)

/* GPIOK */
#define GPIOK                   (AHB1_BASE + 0x2800)

/* GPIOJ */
#define GPIOJ                   (AHB1_BASE + 0x2400)

/* GPIOI */
#define GPIOI                   (AHB1_BASE + 0x2000)

/* GPIOH */
#define GPIOH                   (AHB1_BASE + 0x1C00)

/* GPIOG */
#define GPIOG                   (AHB1_BASE + 0x1800)

/* GPIOF */
#define GPIOF                   (AHB1_BASE + 0x1400)

/* GPIOE */
#define GPIOE                   (AHB1_BASE + 0x1000)

/* GPIOD */
#define GPIOD                   (AHB1_BASE + 0x0C00)

/* GPIOC */
#define GPIOC                   (AHB1_BASE + 0x0800)

/* GPIOB */
#define GPIOB                   (AHB1_BASE + 0x0400)

/* GPIOA */
#define GPIOA                   (AHB1_BASE)

/* LCD-TFT */
#define LCD_BASE                (APB2_BASE + 0x6800)

/* SAI1 */
#define SAI1_BASE               (APB2_BASE + 0x5800)

/* SPI6 */
#define SPI6_BASE               (APB2_BASE + 0x5400)

/* SPI5 */
#define SPI5_BASE               (APB2_BASE + 0x5000)

/* TIM11 */
#define TIM11_BASE              (APB2_BASE + 0x4800)

/* TIM10 */
#define TIM10_BASE              (APB2_BASE + 0x4400)

/* TIM9 */
#define TIM9_BASE               (APB2_BASE + 0x4000)

/* EXTI */
#define EXTI_BASE               (APB2_BASE + 0x3C00)

/* SYSCFG */
#define SYSCFG_BASE             (APB2_BASE + 0x3800)

/* SPI4 */
#define SPI4_BASE               (APB2_BASE + 0x3400)

/* SPI1 */
#define SPI1_BASE               (APB2_BASE + 0x3000)

/* SDIO */
#define SDIO_BASE               (APB2_BASE + 0x2C00)

/* ADC */
#define ADC_BASE                (APB2_BASE + 0x2000)

/* USART6 */
#define USART6_BASE             (APB2_BASE + 0x1400)

/* USART1 */
#define USART1_BASE             (APB2_BASE + 0x1000)

/* TIM8 */
#define TIM8_BASE               (APB2_BASE + 0x0400)

/* TIM1 */
#define TIM1_BASE               (APB2_BASE)


/************************************************************************/
/*************************** APB1 Peripherals ***************************/
/************************************************************************/

/* UART7 */
#define UART8_BASE              (APB1_BASE + 0x7C00)

/* UART7 */
#define UART7_BASE              (APB1_BASE + 0x7800)

/* DAC */
#define DAC_BASE                (APB1_BASE + 0x7400)

/* PWR */
#define PWR_BASE                (APB1_BASE + 0x7000)

/* CAN2 */
#define CAN2_BASE               (APB1_BASE + 0x6800)

/* CAN1 */
#define CAN1_BASE               (APB1_BASE + 0x6400)

/* I2C3 */
#define I2C3_BASE               (APB1_BASE + 0x5C00)

/* I2C2 */
#define I2C2_BASE               (APB1_BASE + 0x5800)

/* I2C1 */
#define I2C1_BASE               (APB1_BASE + 0x5400)

/* UART5 */
#define UART5_BASE              (APB1_BASE + 0x5000)

/* UART4 */
#define UART4_BASE              (APB1_BASE + 0x4C00)

/* USART3 */
#define USART3_BASE             (APB1_BASE + 0x4800)

/* USART2 */
#define USART2_BASE             (APB1_BASE + 0x4400)

/* I2S3ext */
#define I2S3Ext_BASE            (APB1_BASE + 0x4000)

/* SPI3 */
#define SPI3_BASE               (APB1_BASE + 0x3C00)

/* SPI2 */
#define SPI2_BASE               (APB1_BASE + 0x3800)

/* I2S2ext */
#define I2S2Ext_BASE            (APB1_BASE + 0x2C00)

/* IWDG */
#define IWDG_BASE               (APB1_BASE + 0x3000)

/* WWDG */
#define WWDG_BASE               (APB1_BASE + 0x2C00)

/* RTC & BKUP */
#define RTC_BASE                (APB1_BASE + 0x2800)

/* Timers */
#define TIM14_BASE              (APB1_BASE + 0x2000)
#define TIM13_BASE              (APB1_BASE + 0x1C00)
#define TIM12_BASE              (APB1_BASE + 0x1800)
#define TIM7_BASE               (APB1_BASE + 0x1400)
#define TIM6_BASE               (APB1_BASE + 0x1000)
#define TIM5_BASE               (APB1_BASE + 0xC00)
#define TIM4_BASE               (APB1_BASE + 0x800)
#define TIM3_BASE               (APB1_BASE + 0x400)
#define TIM2_BASE               (APB1_BASE)


void PUT32( unsigned int dst_reg, unsigned int val);
unsigned int GET32( unsigned int );
unsigned int DELAY ( unsigned int );

#endif      //__STM32F4_H__