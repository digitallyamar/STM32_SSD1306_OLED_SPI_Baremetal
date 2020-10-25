#include "stm32f4.h"
#include "spi.h"

// Set SSOE bit for the reg. value passed as argument
void spi_ssoe_set(unsigned int spi_num) {
    unsigned int spi_cr2_val = GET32(SPI_CR2(spi_num));

    spi_cr2_val |= SPI_SSOE_SET;
    PUT32(SPI_CR2(spi_num), spi_cr2_val);
}

// Clear SSOE bit for the reg. value passed as argument
void spi_ssoe_clear(unsigned int spi_num) {
    unsigned int spi_cr2_val = GET32(SPI_CR2(spi_num));

    spi_cr2_val &= SPI_SSOE_CLR;
    PUT32(SPI_CR2(spi_num), spi_cr2_val);    
}

// Enable CRC - Set CRCEN Enable bit (CRC)
void spi_crc_set(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val |= SPI_CR1_CRCEN_SET;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Disable CRC - Clear CRCEN Enable bit
void spi_crc_clr(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_CRCEN_CLR;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);        
}

// Next txfr is CRC - Set CRCNEXT Enable bit
void spi_crcnext_set(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val |= SPI_CR1_CRCNEXT_SET;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);
}

// Next txfr is Data phase - Clear CRCNEXT Enable bit
void spi_crcnext_clr(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_CRCNEXT_CLR;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}


// Enable SPI - Set SPI Enable bit (SPE)
void spi_spe_set(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val |= SPI_CR1_SPE_SET;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Disable SPI - Clear SPI Enable bit (SPE)
void spi_spe_clr(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_SPE_CLR;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set baud rate
void spi_baud_rate_set(unsigned int spi_num, unsigned int spi_br_div) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_SET_BAUD_RATE_DIV_MASK;
    spi_cr1_val |= spi_br_div;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set as master
void spi_master_set(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val |= SPI_CR1_MSTR_SET;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set as slave
void spi_master_clr(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_MSTR_CLR;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set clock phase
void spi_cpha_set(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val |= SPI_CR1_CPHA_SET;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set clock phase
void spi_cpha_clr(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_CPHA_CLR;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set clock polarity
void spi_cpol_set(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val |= SPI_CR1_CPOL_SET;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

// Set clock polarity
void spi_cpol_clr(unsigned int spi_num) {
    unsigned int spi_cr1_val = GET32(SPI_CR1(spi_num));

    spi_cr1_val &= SPI_CR1_CPOL_CLR;
    PUT32(SPI_CR1(spi_num), spi_cr1_val);    
}

void spi_master_init(unsigned int spi_num) {
    // (i): Enable Output (set SSOE in CR2)
    spi_ssoe_set(spi_num);
    // (ii): Set baud rate
    spi_baud_rate_set(spi_num, SPI_SET_BAUD_RATE_DIV8);
    // (iii): Set as master
    spi_master_set(spi_num);
    // (iv): Set clock polarity to 0 when idle 
    spi_cpol_clr(spi_num);
    // (v): Set 1st clock transition as the 1st data capture edge
    spi_cpha_clr(spi_num);
    // (vi): Enable CRC
    spi_crc_set(spi_num);
    // (vi): Next transfer is CRC
    spi_crcnext_set(spi_num);
    // (vii): Finally, enable SPI
    spi_spe_set(spi_num);
}

int spi_master_send_half_duplex(unsigned int spi_num, unsigned int data) {
    //Just read out DR initially and ignore it!
    GET32(SPI_DR(spi_num));

    unsigned int spi_sr_val = GET32(SPI_SR(spi_num));

    // Send data only when TXE is set and no errors
    if (spi_sr_val == SPI_SR_TXE_SET_MASK) {
        PUT32(SPI_DR(spi_num), data);
        DELAY(10);
    }
    else {
        return -1;
    }

    // Read back received byte and ignore it
    // Need to do this to clear RXNE bit in SR reg.
    GET32(SPI_DR(spi_num));

    spi_sr_val = GET32(SPI_SR(spi_num));

    if (spi_sr_val == SPI_SR_TXE_SET_MASK) {
        return 0;
    }   
    else {
        return -1;
    }
}