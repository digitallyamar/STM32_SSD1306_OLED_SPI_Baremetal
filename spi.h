#ifndef __SPI_H__
#define __SPI_H__

#define SPI1                            SPI1_BASE
#define SPI2                            SPI2_BASE
#define SPI3                            SPI3_BASE

#define SPI_CR1(spi_num)                (spi_num + 0x00)
#define SPI_CR2(spi_num)                (spi_num + 0x04)
#define SPI_SR(spi_num)                 (spi_num + 0x08)
#define SPI_DR(spi_num)                 (spi_num + 0x0C)
#define SPI_CRCPR(spi_num)              (spi_num + 0x010)
#define SPI_RXCRCR(spi_num)             (spi_num + 0x014)
#define SPI_TXCRCR(spi_num)             (spi_num + 0x018)
#define SPI_I2SCFGR(spi_num)            (spi_num + 0x01C)
#define SPI_I2SPR(spi_num)              (spi_num + 0x020)

//CR1 Reg bits
#define SPI_CR1_CPHA_SET                (1 << 0)
#define SPI_CR1_CPHA_CLR                ~(1 << 0)
#define SPI_CR1_CPOL_SET                (1 << 1)
#define SPI_CR1_CPOL_CLR                ~(1 << 1)
#define SPI_CR1_MSTR_SET                (1 << 2)
#define SPI_CR1_MSTR_CLR                ~(1 << 2)
#define SPI_CR1_SPE_SET                 (1 << 6)
#define SPI_CR1_SPE_CLR                 ~(1 << 6)
#define SPI_CR1_LSBFIRST                (1 << 7)
#define SPI_CR1_MSBFIRST                ~(1 << 7)
#define SPI_CR1_CRCNEXT_SET             (1 << 12)
#define SPI_CR1_CRCNEXT_CLR             ~(1 << 12)
#define SPI_CR1_CRCEN_SET               (1 << 13)
#define SPI_CR1_CRCEN_CLR               ~(1 << 13)


#define SPI_CR1_SET_BAUD_RATE_DIV_MASK  0xFFC7

#define SPI_CR1_BAUD_RATE_DIV(x)        (x << 3)

// CR2 Reg bits
#define SPI_SSOE_SET                    (1 << 2)
#define SPI_SSOE_CLR                    ~(1 << 2)

#define SPI_SR_TXE_SET_MASK             0x2

#define SPI_SET_BAUD_RATE_DIV2          SPI_CR1_BAUD_RATE_DIV(0)
#define SPI_SET_BAUD_RATE_DIV4          SPI_CR1_BAUD_RATE_DIV(1)
#define SPI_SET_BAUD_RATE_DIV8          SPI_CR1_BAUD_RATE_DIV(2)
#define SPI_SET_BAUD_RATE_DIV16         SPI_CR1_BAUD_RATE_DIV(3)
#define SPI_SET_BAUD_RATE_DIV32         SPI_CR1_BAUD_RATE_DIV(4)
#define SPI_SET_BAUD_RATE_DIV64         SPI_CR1_BAUD_RATE_DIV(5)
#define SPI_SET_BAUD_RATE_DIV128        SPI_CR1_BAUD_RATE_DIV(6)
#define SPI_SET_BAUD_RATE_DIV256        SPI_CR1_BAUD_RATE_DIV(7)

void spi_master_init(unsigned int spi_num);
int spi_master_send_half_duplex(unsigned int spi_num, unsigned int data);

#endif