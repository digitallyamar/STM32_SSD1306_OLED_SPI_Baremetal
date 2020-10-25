#include "stm32f4.h"
#include "rcc.h"

void rcc_hsi_clock_on(void) {
    unsigned int rcc_cr_val = GET32(RCC_CR);
    
    // Turn ON the HSI ON bit
    rcc_cr_val |= RCC_HSI_ON;
    PUT32(RCC_CR, rcc_cr_val);

    // Wait for HSI oscillator to be ready
    while (!(GET32(RCC_CR) & RCC_HSI_RDY));    
}

void rcc_hsi_clock_off(void) {
    unsigned int rcc_cr_val = GET32(RCC_CR);
    
    // Turn OFF the HSI ON bit
    rcc_cr_val &= RCC_HSI_OFF;
    PUT32(RCC_CR, rcc_cr_val);

    // Wait for HSI oscillator to be turned off
    while ((GET32(RCC_CR) & RCC_HSI_RDY));    
}

void rcc_hse_clock_on(void) {
    unsigned int rcc_cr_val = GET32(RCC_CR);
    
    // Turn ON the HSE ON bit
    rcc_cr_val |= RCC_HSE_ON;
    PUT32(RCC_CR, rcc_cr_val);

    // Wait for HSE oscillator to be ready
    while (!(GET32(RCC_CR) & RCC_HSE_RDY));    
}

void rcc_pll_clock_on(void) {
    unsigned int rcc_cr_val = GET32(RCC_CR);
    
    // Turn ON the HSE ON bit
    rcc_cr_val |= RCC_PLL_ON;
    PUT32(RCC_CR, rcc_cr_val);

    // Wait for HSE oscillator to be ready
    while (!(GET32(RCC_CR) & RCC_PLL_RDY));    
}

void rcc_css_on(void) {
    unsigned int rcc_cr_val = GET32(RCC_CR);
    
    // Turn ON the CSS ON bit
    rcc_cr_val |= RCC_CSS_ON;
    PUT32(RCC_CR, rcc_cr_val);
}

void rcc_set_sysclk_src(int clk) {
    unsigned int rcc_cfgr_val  = GET32(RCC_CFGR);

    // Switch clock to clk
    rcc_cfgr_val &= SYS_CLK_SW_MASK;
    rcc_cfgr_val |= clk;
    PUT32(RCC_CFGR, rcc_cfgr_val);

    // Wait for new SYS clock cfg. to be ready
    while ((GET32(RCC_CFGR) & (SYS_CLK_SWS_MASK)) != (clk << SYS_CLK_SWS_SHIFT));
}

void rcc_apb1_peri_clk_enable(int peri_clk_enable) {
    unsigned int rcc_apb1enr_val = GET32(RCC_APB1ENR);

    rcc_apb1enr_val |= peri_clk_enable;

    PUT32(RCC_APB1ENR, rcc_apb1enr_val);
}

void rcc_apb2_peri_clk_enable(int peri_clk_enable) {
    unsigned int rcc_apb1enr_val = GET32(RCC_APB2ENR);

    rcc_apb1enr_val |= peri_clk_enable;

    PUT32(RCC_APB2ENR, rcc_apb1enr_val);
}

void rcc_ahb1_peri_clk_enable(int peri_clk_enable) {
    unsigned int rcc_apb1enr_val = GET32(RCC_AHB1ENR);

    rcc_apb1enr_val |= peri_clk_enable;

    PUT32(RCC_AHB1ENR, rcc_apb1enr_val);
}

void rcc_ahb2_peri_clk_enable(int peri_clk_enable) {
    unsigned int rcc_apb2enr_val = GET32(RCC_AHB2ENR);

    rcc_apb2enr_val |= peri_clk_enable;

    PUT32(RCC_AHB2ENR, rcc_apb2enr_val);
}


void rcc_clk_set_pllm(int pllm) {
    unsigned int rcc_pllcfgr_val = GET32(RCC_PLLCFGR);

    // Clear PLLM bit values
    rcc_pllcfgr_val &= RCC_PLLM_CLR_MASK;

    // Set only values between bits[5:0] that belongs to PLLM
    rcc_pllcfgr_val |= ((pllm  << RCC_PLLM_SHIFT) & RCC_PLLM_SET_MASK);

    // Update the new value to the PLLCFGR register
    PUT32(RCC_PLLCFGR, rcc_pllcfgr_val);
}

void rcc_clk_set_plln(int plln) {
    unsigned int rcc_pllcfgr_val = GET32(RCC_PLLCFGR);

    // Clear PLLN bit values
    rcc_pllcfgr_val &= RCC_PLLN_CLR_MASK;

    // Set only values between bits[14:6] that belongs to PLLN
    rcc_pllcfgr_val |= ((plln << RCC_PLLN_SHIFT) & RCC_PLLN_SET_MASK);

    // Update the new value to the PLLCFGR register
    PUT32(RCC_PLLCFGR, rcc_pllcfgr_val);
}

void rcc_clk_set_pllp(int pllp) {
    unsigned int rcc_pllcfgr_val = GET32(RCC_PLLCFGR);

    // Clear PLLP bit values
    rcc_pllcfgr_val &= RCC_PLLP_CLR_MASK;

    // Set only values between bits[17:16] that belongs to PLLP
    rcc_pllcfgr_val |= ((pllp << RCC_PLLP_SHIFT) & RCC_PLLP_SET_MASK);

    // Update the new value to the PLLCFGR register
    PUT32(RCC_PLLCFGR, rcc_pllcfgr_val);
}



void rcc_clk_set_pllq(int pllq) {
    unsigned int rcc_pllcfgr_val = GET32(RCC_PLLCFGR);

    // Clear PLLP bit values
    rcc_pllcfgr_val &= RCC_PLLQ_CLR_MASK;

    // Set only values between bits[27:24] that belongs to PLLQ
    rcc_pllcfgr_val |= ((pllq << RCC_PLLQ_SHIFT) & RCC_PLLQ_SET_MASK);

    // Update the new value to the PLLCFGR register
    PUT32(RCC_PLLCFGR, rcc_pllcfgr_val);
}

void rcc_clk_set_pllsrc(int pllsrc) {
    unsigned int rcc_pllcfgr_val = GET32(RCC_PLLCFGR);

    if (pllsrc == RCC_PLLSRC_HSE) {
        rcc_pllcfgr_val |= RCC_PLLSRC_HSE;
    }
    else {
        rcc_pllcfgr_val &= RCC_PLLSRC_HSI;
    }

    // Update the new value to the PLLCFGR register
    PUT32(RCC_PLLCFGR, rcc_pllcfgr_val);
}

void rcc_clk_set_hpre(int hpre) {
    unsigned int rcc_cfgr_val = GET32(RCC_CFGR);

    // Clear HPRE bit values
    rcc_cfgr_val &= RCC_HPRE_CLR_MASK;

   // Set only values between bits[7:4] that belongs to HPRE
    rcc_cfgr_val |= ((hpre << RCC_HPRE_SHIFT) & RCC_HPRE_SET_MASK);

    // Update the new value to the CFGR register
    PUT32(RCC_CFGR, rcc_cfgr_val);
}

void rcc_clk_set_ppre1(int ppre1) {
    unsigned int rcc_cfgr_val = GET32(RCC_CFGR);

    // Clear HPRE bit values
    rcc_cfgr_val &= RCC_PPRE1_CLR_MASK;

   // Set only values between bits[12:10] that belongs to HPRE
    rcc_cfgr_val |= ((ppre1 << RCC_PPRE1_SHIFT) & RCC_PPRE1_SET_MASK);

    // Update the new value to the CFGR register
    PUT32(RCC_CFGR, rcc_cfgr_val);
}

void rcc_clk_set_ppre2(int ppre2) {
    unsigned int rcc_cfgr_val = GET32(RCC_CFGR);

    // Clear HPRE bit values
    rcc_cfgr_val &= RCC_PPRE2_CLR_MASK;

   // Set only values between bits[15:13] that belongs to HPRE
    rcc_cfgr_val |= ((ppre2 << RCC_PPRE2_SHIFT) & RCC_PPRE2_SET_MASK);

    // Update the new value to the CFGR register
    PUT32(RCC_CFGR, rcc_cfgr_val);
}