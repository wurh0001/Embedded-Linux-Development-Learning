/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 02:43:05
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 21:22:46
 * @FilePath: /projects/p14_lcd/imx6ull/MCIMX6Y2.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __MCIMX6Y2_H__
#define __MCIMX6Y2_H__

#include "cc.h"

/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 160                /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  Software0_IRQn               = 0,                /**< Cortex-A7 Software Generated Interrupt 0 */
  Software1_IRQn               = 1,                /**< Cortex-A7 Software Generated Interrupt 1 */
  Software2_IRQn               = 2,                /**< Cortex-A7 Software Generated Interrupt 2 */
  Software3_IRQn               = 3,                /**< Cortex-A7 Software Generated Interrupt 3 */
  Software4_IRQn               = 4,                /**< Cortex-A7 Software Generated Interrupt 4 */
  Software5_IRQn               = 5,                /**< Cortex-A7 Software Generated Interrupt 5 */
  Software6_IRQn               = 6,                /**< Cortex-A7 Software Generated Interrupt 6 */
  Software7_IRQn               = 7,                /**< Cortex-A7 Software Generated Interrupt 7 */
  Software8_IRQn               = 8,                /**< Cortex-A7 Software Generated Interrupt 8 */
  Software9_IRQn               = 9,                /**< Cortex-A7 Software Generated Interrupt 9 */
  Software10_IRQn              = 10,               /**< Cortex-A7 Software Generated Interrupt 10 */
  Software11_IRQn              = 11,               /**< Cortex-A7 Software Generated Interrupt 11 */
  Software12_IRQn              = 12,               /**< Cortex-A7 Software Generated Interrupt 12 */
  Software13_IRQn              = 13,               /**< Cortex-A7 Software Generated Interrupt 13 */
  Software14_IRQn              = 14,               /**< Cortex-A7 Software Generated Interrupt 14 */
  Software15_IRQn              = 15,               /**< Cortex-A7 Software Generated Interrupt 15 */
  VirtualMaintenance_IRQn      = 25,               /**< Cortex-A7 Virtual Maintenance Interrupt */
  HypervisorTimer_IRQn         = 26,               /**< Cortex-A7 Hypervisor Timer Interrupt */
  VirtualTimer_IRQn            = 27,               /**< Cortex-A7 Virtual Timer Interrupt */
  LegacyFastInt_IRQn           = 28,               /**< Cortex-A7 Legacy nFIQ signal Interrupt */
  SecurePhyTimer_IRQn          = 29,               /**< Cortex-A7 Secure Physical Timer Interrupt */
  NonSecurePhyTimer_IRQn       = 30,               /**< Cortex-A7 Non-secure Physical Timer Interrupt */
  LegacyIRQ_IRQn               = 31,               /**< Cortex-A7 Legacy nIRQ Interrupt */

  /* Device specific interrupts */
  IOMUXC_IRQn                  = 32,               /**< General Purpose Register 1 from IOMUXC. Used to notify cores on exception condition while boot. */
  DAP_IRQn                     = 33,               /**< Debug Access Port interrupt request. */
  SDMA_IRQn                    = 34,               /**< SDMA interrupt request from all channels. */
  TSC_IRQn                     = 35,               /**< TSC interrupt. */
  SNVS_IRQn                    = 36,               /**< Logic OR of SNVS_LP and SNVS_HP interrupts. */
  LCDIF_IRQn                   = 37,               /**< LCDIF sync interrupt. */
  RNGB_IRQn                    = 38,               /**< RNGB interrupt. */
  CSI_IRQn                     = 39,               /**< CMOS Sensor Interface interrupt request. */
  PXP_IRQ0_IRQn                = 40,               /**< PXP interrupt pxp_irq_0. */
  SCTR_IRQ0_IRQn               = 41,               /**< SCTR compare interrupt ipi_int[0]. */
  SCTR_IRQ1_IRQn               = 42,               /**< SCTR compare interrupt ipi_int[1]. */
  WDOG3_IRQn                   = 43,               /**< WDOG3 timer reset interrupt request. */
  Reserved44_IRQn              = 44,               /**< Reserved */
  APBH_IRQn                    = 45,               /**< DMA Logical OR of APBH DMA channels 0-3 completion and error interrupts. */
  WEIM_IRQn                    = 46,               /**< WEIM interrupt request. */
  RAWNAND_BCH_IRQn             = 47,               /**< BCH operation complete interrupt. */
  RAWNAND_GPMI_IRQn            = 48,               /**< GPMI operation timeout error interrupt. */
  UART6_IRQn                   = 49,               /**< UART6 interrupt request. */
  PXP_IRQ1_IRQn                = 50,               /**< PXP interrupt pxp_irq_1. */
  SNVS_Consolidated_IRQn       = 51,               /**< SNVS consolidated interrupt. */
  SNVS_Security_IRQn           = 52,               /**< SNVS security interrupt. */
  CSU_IRQn                     = 53,               /**< CSU interrupt request 1. Indicates to the processor that one or more alarm inputs were asserted. */
  USDHC1_IRQn                  = 54,               /**< USDHC1 (Enhanced SDHC) interrupt request. */
  USDHC2_IRQn                  = 55,               /**< USDHC2 (Enhanced SDHC) interrupt request. */
  SAI3_RX_IRQn                 = 56,               /**< SAI3 interrupt ipi_int_sai_rx. */
  SAI3_TX_IRQn                 = 57,               /**< SAI3 interrupt ipi_int_sai_tx. */
  UART1_IRQn                   = 58,               /**< UART1 interrupt request. */
  UART2_IRQn                   = 59,               /**< UART2 interrupt request. */
  UART3_IRQn                   = 60,               /**< UART3 interrupt request. */
  UART4_IRQn                   = 61,               /**< UART4 interrupt request. */
  UART5_IRQn                   = 62,               /**< UART5 interrupt request. */
  eCSPI1_IRQn                  = 63,               /**< eCSPI1 interrupt request. */
  eCSPI2_IRQn                  = 64,               /**< eCSPI2 interrupt request. */
  eCSPI3_IRQn                  = 65,               /**< eCSPI3 interrupt request. */
  eCSPI4_IRQn                  = 66,               /**< eCSPI4 interrupt request. */
  I2C4_IRQn                    = 67,               /**< I2C4 interrupt request. */
  I2C1_IRQn                    = 68,               /**< I2C1 interrupt request. */
  I2C2_IRQn                    = 69,               /**< I2C2 interrupt request. */
  I2C3_IRQn                    = 70,               /**< I2C3 interrupt request. */
  UART7_IRQn                   = 71,               /**< UART-7 ORed interrupt. */
  UART8_IRQn                   = 72,               /**< UART-8 ORed interrupt. */
  Reserved73_IRQn              = 73,               /**< Reserved */
  USB_OTG2_IRQn                = 74,               /**< USBO2 USB OTG2 */
  USB_OTG1_IRQn                = 75,               /**< USBO2 USB OTG1 */
  USB_PHY1_IRQn                = 76,               /**< UTMI0 interrupt request. */
  USB_PHY2_IRQn                = 77,               /**< UTMI1 interrupt request. */
  DCP_IRQ_IRQn                 = 78,               /**< DCP interrupt request dcp_irq. */
  DCP_VMI_IRQ_IRQn             = 79,               /**< DCP interrupt request dcp_vmi_irq. */
  DCP_SEC_IRQ_IRQn             = 80,               /**< DCP interrupt request secure_irq. */
  TEMPMON_IRQn                 = 81,               /**< Temperature Monitor Temperature Sensor (temperature greater than threshold) interrupt request. */
  ASRC_IRQn                    = 82,               /**< ASRC interrupt request. */
  ESAI_IRQn                    = 83,               /**< ESAI interrupt request. */
  SPDIF_IRQn                   = 84,               /**< SPDIF interrupt. */
  Reserved85_IRQn              = 85,               /**< Reserved */
  PMU_IRQ1_IRQn                = 86,               /**< Brown-out event on either the 1.1, 2.5 or 3.0 regulators. */
  GPT1_IRQn                    = 87,               /**< Logical OR of GPT1 rollover interrupt line, input capture 1 and 2 lines, output compare 1, 2, and 3 interrupt lines. */
  EPIT1_IRQn                   = 88,               /**< EPIT1 output compare interrupt. */
  EPIT2_IRQn                   = 89,               /**< EPIT2 output compare interrupt. */
  GPIO1_INT7_IRQn              = 90,               /**< INT7 interrupt request. */
  GPIO1_INT6_IRQn              = 91,               /**< INT6 interrupt request. */
  GPIO1_INT5_IRQn              = 92,               /**< INT5 interrupt request. */
  GPIO1_INT4_IRQn              = 93,               /**< INT4 interrupt request. */
  GPIO1_INT3_IRQn              = 94,               /**< INT3 interrupt request. */
  GPIO1_INT2_IRQn              = 95,               /**< INT2 interrupt request. */
  GPIO1_INT1_IRQn              = 96,               /**< INT1 interrupt request. */
  GPIO1_INT0_IRQn              = 97,               /**< INT0 interrupt request. */
  GPIO1_Combined_0_15_IRQn     = 98,               /**< Combined interrupt indication for GPIO1 signals 0 - 15. */
  GPIO1_Combined_16_31_IRQn    = 99,               /**< Combined interrupt indication for GPIO1 signals 16 - 31. */
  GPIO2_Combined_0_15_IRQn     = 100,              /**< Combined interrupt indication for GPIO2 signals 0 - 15. */
  GPIO2_Combined_16_31_IRQn    = 101,              /**< Combined interrupt indication for GPIO2 signals 16 - 31. */
  GPIO3_Combined_0_15_IRQn     = 102,              /**< Combined interrupt indication for GPIO3 signals 0 - 15. */
  GPIO3_Combined_16_31_IRQn    = 103,              /**< Combined interrupt indication for GPIO3 signals 16 - 31. */
  GPIO4_Combined_0_15_IRQn     = 104,              /**< Combined interrupt indication for GPIO4 signals 0 - 15. */
  GPIO4_Combined_16_31_IRQn    = 105,              /**< Combined interrupt indication for GPIO4 signals 16 - 31. */
  GPIO5_Combined_0_15_IRQn     = 106,              /**< Combined interrupt indication for GPIO5 signals 0 - 15. */
  GPIO5_Combined_16_31_IRQn    = 107,              /**< Combined interrupt indication for GPIO5 signals 16 - 31. */
  Reserved108_IRQn             = 108,              /**< Reserved */
  Reserved109_IRQn             = 109,              /**< Reserved */
  Reserved110_IRQn             = 110,              /**< Reserved */
  Reserved111_IRQn             = 111,              /**< Reserved */
  WDOG1_IRQn                   = 112,              /**< WDOG1 timer reset interrupt request. */
  WDOG2_IRQn                   = 113,              /**< WDOG2 timer reset interrupt request. */
  KPP_IRQn                     = 114,              /**< Key Pad interrupt request. */
  PWM1_IRQn                    = 115,              /**< hasRegInstance(`PWM1`)?`Cumulative interrupt line for PWM1. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  PWM2_IRQn                    = 116,              /**< hasRegInstance(`PWM2`)?`Cumulative interrupt line for PWM2. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  PWM3_IRQn                    = 117,              /**< hasRegInstance(`PWM3`)?`Cumulative interrupt line for PWM3. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  PWM4_IRQn                    = 118,              /**< hasRegInstance(`PWM4`)?`Cumulative interrupt line for PWM4. Logical OR of rollover, compare, and FIFO waterlevel crossing interrupts.`:`Reserved`) */
  CCM_IRQ1_IRQn                = 119,              /**< CCM interrupt request ipi_int_1. */
  CCM_IRQ2_IRQn                = 120,              /**< CCM interrupt request ipi_int_2. */
  GPC_IRQn                     = 121,              /**< GPC interrupt request 1. */
  Reserved122_IRQn             = 122,              /**< Reserved */
  SRC_IRQn                     = 123,              /**< SRC interrupt request src_ipi_int_1. */
  Reserved124_IRQn             = 124,              /**< Reserved */
  Reserved125_IRQn             = 125,              /**< Reserved */
  CPU_PerformanceUnit_IRQn     = 126,              /**< Performance Unit interrupt ~ipi_pmu_irq_b. */
  CPU_CTI_Trigger_IRQn         = 127,              /**< CTI trigger outputs interrupt ~ipi_cti_irq_b. */
  SRC_Combined_IRQn            = 128,              /**< Combined CPU wdog interrupts (4x) out of SRC. */
  SAI1_IRQn                    = 129,              /**< SAI1 interrupt request. */
  SAI2_IRQn                    = 130,              /**< SAI2 interrupt request. */
  Reserved131_IRQn             = 131,              /**< Reserved */
  ADC1_IRQn                    = 132,              /**< ADC1 interrupt request. */
  ADC_5HC_IRQn                 = 133,              /**< ADC_5HC interrupt request. */
  Reserved134_IRQn             = 134,              /**< Reserved */
  Reserved135_IRQn             = 135,              /**< Reserved */
  SJC_IRQn                     = 136,              /**< SJC interrupt from General Purpose register. */
  CAAM_Job_Ring0_IRQn          = 137,              /**< CAAM job ring 0 interrupt ipi_caam_irq0. */
  CAAM_Job_Ring1_IRQn          = 138,              /**< CAAM job ring 1 interrupt ipi_caam_irq1. */
  QSPI_IRQn                    = 139,              /**< QSPI1 interrupt request ipi_int_ored. */
  TZASC_IRQn                   = 140,              /**< TZASC (PL380) interrupt request. */
  GPT2_IRQn                    = 141,              /**< Logical OR of GPT2 rollover interrupt line, input capture 1 and 2 lines, output compare 1, 2 and 3 interrupt lines. */
  CAN1_IRQn                    = 142,              /**< Combined interrupt of ini_int_busoff,ini_int_error,ipi_int_mbor,ipi_int_txwarning and ipi_int_waken */
  CAN2_IRQn                    = 143,              /**< Combined interrupt of ini_int_busoff,ini_int_error,ipi_int_mbor,ipi_int_txwarning and ipi_int_waken */
  Reserved144_IRQn             = 144,              /**< Reserved */
  Reserved145_IRQn             = 145,              /**< Reserved */
  PWM5_IRQn                    = 146,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  PWM6_IRQn                    = 147,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  PWM7_IRQn                    = 148,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  PWM8_IRQn                    = 149,              /**< Cumulative interrupt line. OR of Rollover Interrupt line, Compare Interrupt line and FIFO Waterlevel crossing interrupt line */
  ENET1_IRQn                   = 150,              /**< ENET1 interrupt */
  ENET1_1588_IRQn              = 151,              /**< ENET1 1588 Timer interrupt [synchronous] request. */
  ENET2_IRQn                   = 152,              /**< ENET2 interrupt */
  ENET2_1588_IRQn              = 153,              /**< MAC 0 1588 Timer interrupt [synchronous] request. */
  Reserved154_IRQn             = 154,              /**< Reserved */
  Reserved155_IRQn             = 155,              /**< Reserved */
  Reserved156_IRQn             = 156,              /**< Reserved */
  Reserved157_IRQn             = 157,              /**< Reserved */
  Reserved158_IRQn             = 158,              /**< Reserved */
  PMU_IRQ2_IRQn                = 159               /**< Brown-out event on either core, gpu or soc regulators. */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */



/* ----------------------------------------------------------------------------
   -- Configuration of the Cortex-A7 Processor and Core Peripherals
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Configuration of the Cortex-A7 Processor and Core Peripherals
 * @{
 */

#define __CA7_REV                      0x0005    /**< Core revision r0p5 */
#define __GIC_PRIO_BITS                5         /**< Number of Bits used for Priority Levels */
#define __FPU_PRESENT                  1         /**< FPU present or not */


/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */



/** CCM寄存器 */
typedef struct
{
    __IO uint32_t CCR;     /**< CCM Control Register, offset: 0x0 */
    __IO uint32_t CCDR;    /**< CCM Control Divider Register, offset: 0x4 */
    __I uint32_t CSR;      /**< CCM Status Register, offset: 0x8 */
    __IO uint32_t CCSR;    /**< CCM Clock Switcher Register, offset: 0xC */
    __IO uint32_t CACRR;   /**< CCM Arm Clock Root Register, offset: 0x10 */
    __IO uint32_t CBCDR;   /**< CCM Bus Clock Divider Register, offset: 0x14 */
    __IO uint32_t CBCMR;   /**< CCM Bus Clock Multiplexer Register, offset: 0x18 */
    __IO uint32_t CSCMR1;  /**< CCM Serial Clock Multiplexer Register 1, offset: 0x1C */
    __IO uint32_t CSCMR2;  /**< CCM Serial Clock Multiplexer Register 2, offset: 0x20 */
    __IO uint32_t CSCDR1;  /**< CCM Serial Clock Divider Register 1, offset: 0x24 */
    __IO uint32_t CS1CDR;  /**< CCM SAI1 Clock Divider Register, offset: 0x28 */
    __IO uint32_t CS2CDR;  /**< CCM SAI2 Clock Divider Register, offset: 0x2C */
    __IO uint32_t CDCDR;   /**< CCM D1 Clock Divider Register, offset: 0x30 */
    __IO uint32_t CHSCCDR; /**< CCM HSC Clock Divider Register, offset: 0x34 */
    __IO uint32_t CSCDR2;  /**< CCM Serial Clock Divider Register 2, offset: 0x38 */
    __IO uint32_t CSCDR3;  /**< CCM Serial Clock Divider Register 3, offset: 0x3C */
    uint8_t RESERVED_0[8];
    __I uint32_t CDHIPR; /**< CCM Divider Handshake In-Process Register, offset: 0x48 */
    uint8_t RESERVED_1[8];
    __IO uint32_t CLPCR; /**< CCM Low Power Control Register, offset: 0x54 */
    __IO uint32_t CISR;  /**< CCM Interrupt Status Register, offset: 0x58 */
    __IO uint32_t CIMR;  /**< CCM Interrupt Mask Register, offset: 0x5C */
    __IO uint32_t CCOSR; /**< CCM Clock Output Source Register, offset: 0x60 */
    __IO uint32_t CGPR;  /**< CCM General Purpose Register, offset: 0x64 */
    __IO uint32_t CCGR0; /**< CCM Clock Gating Register 0, offset: 0x68 */
    __IO uint32_t CCGR1; /**< CCM Clock Gating Register 1, offset: 0x6C */
    __IO uint32_t CCGR2; /**< CCM Clock Gating Register 2, offset: 0x70 */
    __IO uint32_t CCGR3; /**< CCM Clock Gating Register 3, offset: 0x74 */
    __IO uint32_t CCGR4; /**< CCM Clock Gating Register 4, offset: 0x78 */
    __IO uint32_t CCGR5; /**< CCM Clock Gating Register 5, offset: 0x7C */
    __IO uint32_t CCGR6; /**< CCM Clock Gating Register 6, offset: 0x80 */
    uint8_t RESERVED_2[4];
    __IO uint32_t CMEOR;
} CCM_Type;

#define CCM_BASE (0x20C4000u)
#define CCM ((CCM_Type *)CCM_BASE)

/** CCM_ANALOG - Register Layout Typedef */
typedef struct {
    __IO uint32_t PLL_ARM;                           /**< Analog ARM PLL control Register, offset: 0x0 */
    __IO uint32_t PLL_ARM_SET;                       /**< Analog ARM PLL control Register, offset: 0x4 */
    __IO uint32_t PLL_ARM_CLR;                       /**< Analog ARM PLL control Register, offset: 0x8 */
    __IO uint32_t PLL_ARM_TOG;                       /**< Analog ARM PLL control Register, offset: 0xC */
    __IO uint32_t PLL_USB1;                          /**< Analog USB1 480MHz PLL Control Register, offset: 0x10 */
    __IO uint32_t PLL_USB1_SET;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x14 */
    __IO uint32_t PLL_USB1_CLR;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x18 */
    __IO uint32_t PLL_USB1_TOG;                      /**< Analog USB1 480MHz PLL Control Register, offset: 0x1C */
    __IO uint32_t PLL_USB2;                          /**< Analog USB2 480MHz PLL Control Register, offset: 0x20 */
    __IO uint32_t PLL_USB2_SET;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x24 */
    __IO uint32_t PLL_USB2_CLR;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x28 */
    __IO uint32_t PLL_USB2_TOG;                      /**< Analog USB2 480MHz PLL Control Register, offset: 0x2C */
    __IO uint32_t PLL_SYS;                           /**< Analog System PLL Control Register, offset: 0x30 */
    __IO uint32_t PLL_SYS_SET;                       /**< Analog System PLL Control Register, offset: 0x34 */
    __IO uint32_t PLL_SYS_CLR;                       /**< Analog System PLL Control Register, offset: 0x38 */
    __IO uint32_t PLL_SYS_TOG;                       /**< Analog System PLL Control Register, offset: 0x3C */
    __IO uint32_t PLL_SYS_SS;                        /**< 528MHz System PLL Spread Spectrum Register, offset: 0x40 */
    uint8_t RESERVED_0[12];
    __IO uint32_t PLL_SYS_NUM;                       /**< Numerator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x50 */
    uint8_t RESERVED_1[12];
    __IO uint32_t PLL_SYS_DENOM;                     /**< Denominator of 528MHz System PLL Fractional Loop Divider Register, offset: 0x60 */
    uint8_t RESERVED_2[12];
    __IO uint32_t PLL_AUDIO;                         /**< Analog Audio PLL control Register, offset: 0x70 */
    __IO uint32_t PLL_AUDIO_SET;                     /**< Analog Audio PLL control Register, offset: 0x74 */
    __IO uint32_t PLL_AUDIO_CLR;                     /**< Analog Audio PLL control Register, offset: 0x78 */
    __IO uint32_t PLL_AUDIO_TOG;                     /**< Analog Audio PLL control Register, offset: 0x7C */
    __IO uint32_t PLL_AUDIO_NUM;                     /**< Numerator of Audio PLL Fractional Loop Divider Register, offset: 0x80 */
    uint8_t RESERVED_3[12];
    __IO uint32_t PLL_AUDIO_DENOM;                   /**< Denominator of Audio PLL Fractional Loop Divider Register, offset: 0x90 */
    uint8_t RESERVED_4[12];
    __IO uint32_t PLL_VIDEO;                         /**< Analog Video PLL control Register, offset: 0xA0 */
    __IO uint32_t PLL_VIDEO_SET;                     /**< Analog Video PLL control Register, offset: 0xA4 */
    __IO uint32_t PLL_VIDEO_CLR;                     /**< Analog Video PLL control Register, offset: 0xA8 */
    __IO uint32_t PLL_VIDEO_TOG;                     /**< Analog Video PLL control Register, offset: 0xAC */
    __IO uint32_t PLL_VIDEO_NUM;                     /**< Numerator of Video PLL Fractional Loop Divider Register, offset: 0xB0 */
    uint8_t RESERVED_5[12];
    __IO uint32_t PLL_VIDEO_DENOM;                   /**< Denominator of Video PLL Fractional Loop Divider Register, offset: 0xC0 */
    uint8_t RESERVED_6[28];
    __IO uint32_t PLL_ENET;                          /**< Analog ENET PLL Control Register, offset: 0xE0 */
    __IO uint32_t PLL_ENET_SET;                      /**< Analog ENET PLL Control Register, offset: 0xE4 */
    __IO uint32_t PLL_ENET_CLR;                      /**< Analog ENET PLL Control Register, offset: 0xE8 */
    __IO uint32_t PLL_ENET_TOG;                      /**< Analog ENET PLL Control Register, offset: 0xEC */
    __IO uint32_t PFD_480;                           /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF0 */
    __IO uint32_t PFD_480_SET;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF4 */
    __IO uint32_t PFD_480_CLR;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xF8 */
    __IO uint32_t PFD_480_TOG;                       /**< 480MHz Clock (PLL3) Phase Fractional Divider Control Register, offset: 0xFC */
    __IO uint32_t PFD_528;                           /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x100 */
    __IO uint32_t PFD_528_SET;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x104 */
    __IO uint32_t PFD_528_CLR;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x108 */
    __IO uint32_t PFD_528_TOG;                       /**< 528MHz Clock (PLL2) Phase Fractional Divider Control Register, offset: 0x10C */
    uint8_t RESERVED_7[64];
    __IO uint32_t MISC0;                             /**< Miscellaneous Register 0, offset: 0x150 */
    __IO uint32_t MISC0_SET;                         /**< Miscellaneous Register 0, offset: 0x154 */
    __IO uint32_t MISC0_CLR;                         /**< Miscellaneous Register 0, offset: 0x158 */
    __IO uint32_t MISC0_TOG;                         /**< Miscellaneous Register 0, offset: 0x15C */
    __IO uint32_t MISC1;                             /**< Miscellaneous Register 1, offset: 0x160 */
    __IO uint32_t MISC1_SET;                         /**< Miscellaneous Register 1, offset: 0x164 */
    __IO uint32_t MISC1_CLR;                         /**< Miscellaneous Register 1, offset: 0x168 */
    __IO uint32_t MISC1_TOG;                         /**< Miscellaneous Register 1, offset: 0x16C */
    __IO uint32_t MISC2;                             /**< Miscellaneous Register 2, offset: 0x170 */
    __IO uint32_t MISC2_SET;                         /**< Miscellaneous Register 2, offset: 0x174 */
    __IO uint32_t MISC2_CLR;                         /**< Miscellaneous Register 2, offset: 0x178 */
    __IO uint32_t MISC2_TOG;                         /**< Miscellaneous Register 2, offset: 0x17C */
} CCM_ANALOG_Type;

/* CCM_ANALOG - Peripheral instance base addresses */
/** Peripheral CCM_ANALOG base address */
#define CCM_ANALOG_BASE                          (0x20C8000u)
/** Peripheral CCM_ANALOG base pointer */
#define CCM_ANALOG                               ((CCM_ANALOG_Type *)CCM_ANALOG_BASE)
/** Array initializer of CCM_ANALOG peripheral base addresses */
#define CCM_ANALOG_BASE_ADDRS                    { CCM_ANALOG_BASE }
/** Array initializer of CCM_ANALOG peripheral base pointers */
#define CCM_ANALOG_BASE_PTRS                     { CCM_ANALOG }


/* ----------------------------------------------------------------------------
   -- GPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPT_Peripheral_Access_Layer GPT Peripheral Access Layer
 * @{
 */

/** GPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< GPT Control Register, offset: 0x0 */
  __IO uint32_t PR;                                /**< GPT Prescaler Register, offset: 0x4 */
  __IO uint32_t SR;                                /**< GPT Status Register, offset: 0x8 */
  __IO uint32_t IR;                                /**< GPT Interrupt Register, offset: 0xC */
  __IO uint32_t OCR[3];                            /**< GPT Output Compare Register 1..GPT Output Compare Register 3, array offset: 0x10, array step: 0x4 */
  __I  uint32_t ICR[2];                            /**< GPT Input Capture Register 1..GPT Input Capture Register 2, array offset: 0x1C, array step: 0x4 */
  __I  uint32_t CNT;                               /**< GPT Counter Register, offset: 0x24 */
} GPT_Type;

/* ----------------------------------------------------------------------------
   -- GPT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPT_Register_Masks GPT Register Masks
 * @{
 */

/*! @name CR - GPT Control Register */
#define GPT_CR_EN_MASK                           (0x1U)
#define GPT_CR_EN_SHIFT                          (0U)
#define GPT_CR_EN(x)                             (((uint32_t)(((uint32_t)(x)) << GPT_CR_EN_SHIFT)) & GPT_CR_EN_MASK)
#define GPT_CR_ENMOD_MASK                        (0x2U)
#define GPT_CR_ENMOD_SHIFT                       (1U)
#define GPT_CR_ENMOD(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_CR_ENMOD_SHIFT)) & GPT_CR_ENMOD_MASK)
#define GPT_CR_DBGEN_MASK                        (0x4U)
#define GPT_CR_DBGEN_SHIFT                       (2U)
#define GPT_CR_DBGEN(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_CR_DBGEN_SHIFT)) & GPT_CR_DBGEN_MASK)
#define GPT_CR_WAITEN_MASK                       (0x8U)
#define GPT_CR_WAITEN_SHIFT                      (3U)
#define GPT_CR_WAITEN(x)                         (((uint32_t)(((uint32_t)(x)) << GPT_CR_WAITEN_SHIFT)) & GPT_CR_WAITEN_MASK)
#define GPT_CR_DOZEEN_MASK                       (0x10U)
#define GPT_CR_DOZEEN_SHIFT                      (4U)
#define GPT_CR_DOZEEN(x)                         (((uint32_t)(((uint32_t)(x)) << GPT_CR_DOZEEN_SHIFT)) & GPT_CR_DOZEEN_MASK)
#define GPT_CR_STOPEN_MASK                       (0x20U)
#define GPT_CR_STOPEN_SHIFT                      (5U)
#define GPT_CR_STOPEN(x)                         (((uint32_t)(((uint32_t)(x)) << GPT_CR_STOPEN_SHIFT)) & GPT_CR_STOPEN_MASK)
#define GPT_CR_CLKSRC_MASK                       (0x1C0U)
#define GPT_CR_CLKSRC_SHIFT                      (6U)
#define GPT_CR_CLKSRC(x)                         (((uint32_t)(((uint32_t)(x)) << GPT_CR_CLKSRC_SHIFT)) & GPT_CR_CLKSRC_MASK)
#define GPT_CR_FRR_MASK                          (0x200U)
#define GPT_CR_FRR_SHIFT                         (9U)
#define GPT_CR_FRR(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_FRR_SHIFT)) & GPT_CR_FRR_MASK)
#define GPT_CR_EN_24M_MASK                       (0x400U)
#define GPT_CR_EN_24M_SHIFT                      (10U)
#define GPT_CR_EN_24M(x)                         (((uint32_t)(((uint32_t)(x)) << GPT_CR_EN_24M_SHIFT)) & GPT_CR_EN_24M_MASK)
#define GPT_CR_SWR_MASK                          (0x8000U)
#define GPT_CR_SWR_SHIFT                         (15U)
#define GPT_CR_SWR(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_SWR_SHIFT)) & GPT_CR_SWR_MASK)
#define GPT_CR_IM1_MASK                          (0x30000U)
#define GPT_CR_IM1_SHIFT                         (16U)
#define GPT_CR_IM1(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_IM1_SHIFT)) & GPT_CR_IM1_MASK)
#define GPT_CR_IM2_MASK                          (0xC0000U)
#define GPT_CR_IM2_SHIFT                         (18U)
#define GPT_CR_IM2(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_IM2_SHIFT)) & GPT_CR_IM2_MASK)
#define GPT_CR_OM1_MASK                          (0x700000U)
#define GPT_CR_OM1_SHIFT                         (20U)
#define GPT_CR_OM1(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_OM1_SHIFT)) & GPT_CR_OM1_MASK)
#define GPT_CR_OM2_MASK                          (0x3800000U)
#define GPT_CR_OM2_SHIFT                         (23U)
#define GPT_CR_OM2(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_OM2_SHIFT)) & GPT_CR_OM2_MASK)
#define GPT_CR_OM3_MASK                          (0x1C000000U)
#define GPT_CR_OM3_SHIFT                         (26U)
#define GPT_CR_OM3(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_OM3_SHIFT)) & GPT_CR_OM3_MASK)
#define GPT_CR_FO1_MASK                          (0x20000000U)
#define GPT_CR_FO1_SHIFT                         (29U)
#define GPT_CR_FO1(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_FO1_SHIFT)) & GPT_CR_FO1_MASK)
#define GPT_CR_FO2_MASK                          (0x40000000U)
#define GPT_CR_FO2_SHIFT                         (30U)
#define GPT_CR_FO2(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_FO2_SHIFT)) & GPT_CR_FO2_MASK)
#define GPT_CR_FO3_MASK                          (0x80000000U)
#define GPT_CR_FO3_SHIFT                         (31U)
#define GPT_CR_FO3(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_CR_FO3_SHIFT)) & GPT_CR_FO3_MASK)

/*! @name PR - GPT Prescaler Register */
#define GPT_PR_PRESCALER_MASK                    (0xFFFU)
#define GPT_PR_PRESCALER_SHIFT                   (0U)
#define GPT_PR_PRESCALER(x)                      (((uint32_t)(((uint32_t)(x)) << GPT_PR_PRESCALER_SHIFT)) & GPT_PR_PRESCALER_MASK)
#define GPT_PR_PRESCALER24M_MASK                 (0xF000U)
#define GPT_PR_PRESCALER24M_SHIFT                (12U)
#define GPT_PR_PRESCALER24M(x)                   (((uint32_t)(((uint32_t)(x)) << GPT_PR_PRESCALER24M_SHIFT)) & GPT_PR_PRESCALER24M_MASK)

/*! @name SR - GPT Status Register */
#define GPT_SR_OF1_MASK                          (0x1U)
#define GPT_SR_OF1_SHIFT                         (0U)
#define GPT_SR_OF1(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_SR_OF1_SHIFT)) & GPT_SR_OF1_MASK)
#define GPT_SR_OF2_MASK                          (0x2U)
#define GPT_SR_OF2_SHIFT                         (1U)
#define GPT_SR_OF2(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_SR_OF2_SHIFT)) & GPT_SR_OF2_MASK)
#define GPT_SR_OF3_MASK                          (0x4U)
#define GPT_SR_OF3_SHIFT                         (2U)
#define GPT_SR_OF3(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_SR_OF3_SHIFT)) & GPT_SR_OF3_MASK)
#define GPT_SR_IF1_MASK                          (0x8U)
#define GPT_SR_IF1_SHIFT                         (3U)
#define GPT_SR_IF1(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_SR_IF1_SHIFT)) & GPT_SR_IF1_MASK)
#define GPT_SR_IF2_MASK                          (0x10U)
#define GPT_SR_IF2_SHIFT                         (4U)
#define GPT_SR_IF2(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_SR_IF2_SHIFT)) & GPT_SR_IF2_MASK)
#define GPT_SR_ROV_MASK                          (0x20U)
#define GPT_SR_ROV_SHIFT                         (5U)
#define GPT_SR_ROV(x)                            (((uint32_t)(((uint32_t)(x)) << GPT_SR_ROV_SHIFT)) & GPT_SR_ROV_MASK)

/*! @name IR - GPT Interrupt Register */
#define GPT_IR_OF1IE_MASK                        (0x1U)
#define GPT_IR_OF1IE_SHIFT                       (0U)
#define GPT_IR_OF1IE(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_IR_OF1IE_SHIFT)) & GPT_IR_OF1IE_MASK)
#define GPT_IR_OF2IE_MASK                        (0x2U)
#define GPT_IR_OF2IE_SHIFT                       (1U)
#define GPT_IR_OF2IE(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_IR_OF2IE_SHIFT)) & GPT_IR_OF2IE_MASK)
#define GPT_IR_OF3IE_MASK                        (0x4U)
#define GPT_IR_OF3IE_SHIFT                       (2U)
#define GPT_IR_OF3IE(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_IR_OF3IE_SHIFT)) & GPT_IR_OF3IE_MASK)
#define GPT_IR_IF1IE_MASK                        (0x8U)
#define GPT_IR_IF1IE_SHIFT                       (3U)
#define GPT_IR_IF1IE(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_IR_IF1IE_SHIFT)) & GPT_IR_IF1IE_MASK)
#define GPT_IR_IF2IE_MASK                        (0x10U)
#define GPT_IR_IF2IE_SHIFT                       (4U)
#define GPT_IR_IF2IE(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_IR_IF2IE_SHIFT)) & GPT_IR_IF2IE_MASK)
#define GPT_IR_ROVIE_MASK                        (0x20U)
#define GPT_IR_ROVIE_SHIFT                       (5U)
#define GPT_IR_ROVIE(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_IR_ROVIE_SHIFT)) & GPT_IR_ROVIE_MASK)

/*! @name OCR - GPT Output Compare Register 1..GPT Output Compare Register 3 */
#define GPT_OCR_COMP_MASK                        (0xFFFFFFFFU)
#define GPT_OCR_COMP_SHIFT                       (0U)
#define GPT_OCR_COMP(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_OCR_COMP_SHIFT)) & GPT_OCR_COMP_MASK)

/* The count of GPT_OCR */
#define GPT_OCR_COUNT                            (3U)

/*! @name ICR - GPT Input Capture Register 1..GPT Input Capture Register 2 */
#define GPT_ICR_CAPT_MASK                        (0xFFFFFFFFU)
#define GPT_ICR_CAPT_SHIFT                       (0U)
#define GPT_ICR_CAPT(x)                          (((uint32_t)(((uint32_t)(x)) << GPT_ICR_CAPT_SHIFT)) & GPT_ICR_CAPT_MASK)

/* The count of GPT_ICR */
#define GPT_ICR_COUNT                            (2U)

/*! @name CNT - GPT Counter Register */
#define GPT_CNT_COUNT_MASK                       (0xFFFFFFFFU)
#define GPT_CNT_COUNT_SHIFT                      (0U)
#define GPT_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x)) << GPT_CNT_COUNT_SHIFT)) & GPT_CNT_COUNT_MASK)


/*!
 * @}
 */ /* end of group GPT_Register_Masks */


/* GPT - Peripheral instance base addresses */
/** Peripheral GPT1 base address */
#define GPT1_BASE                                (0x2098000u)
/** Peripheral GPT1 base pointer */
#define GPT1                                     ((GPT_Type *)GPT1_BASE)
/** Peripheral GPT2 base address */
#define GPT2_BASE                                (0x20E8000u)
/** Peripheral GPT2 base pointer */
#define GPT2                                     ((GPT_Type *)GPT2_BASE)
/** Array initializer of GPT peripheral base addresses */
#define GPT_BASE_ADDRS                           { 0u, GPT1_BASE, GPT2_BASE }
/** Array initializer of GPT peripheral base pointers */
#define GPT_BASE_PTRS                            { (GPT_Type *)0u, GPT1, GPT2 }
/** Interrupt vectors for the GPT peripheral type */
#define GPT_IRQS                                 { NotAvail_IRQn, GPT1_IRQn, GPT2_IRQn }

/*!
 * @}
 */ /* end of group GPT_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- EPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPIT_Peripheral_Access_Layer EPIT Peripheral Access Layer
 * @{
 */

/** EPIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control register, offset: 0x0 */
  __IO uint32_t SR;                                /**< Status register, offset: 0x4 */
  __IO uint32_t LR;                                /**< Load register, offset: 0x8 */
  __IO uint32_t CMPR;                              /**< Compare register, offset: 0xC */
  __I  uint32_t CNR;                               /**< Counter register, offset: 0x10 */
} EPIT_Type;

/* ----------------------------------------------------------------------------
   -- EPIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPIT_Register_Masks EPIT Register Masks
 * @{
 */

/*! @name CR - Control register */
#define EPIT_CR_EN_MASK                          (0x1U)
#define EPIT_CR_EN_SHIFT                         (0U)
#define EPIT_CR_EN(x)                            (((uint32_t)(((uint32_t)(x)) << EPIT_CR_EN_SHIFT)) & EPIT_CR_EN_MASK)
#define EPIT_CR_ENMOD_MASK                       (0x2U)
#define EPIT_CR_ENMOD_SHIFT                      (1U)
#define EPIT_CR_ENMOD(x)                         (((uint32_t)(((uint32_t)(x)) << EPIT_CR_ENMOD_SHIFT)) & EPIT_CR_ENMOD_MASK)
#define EPIT_CR_OCIEN_MASK                       (0x4U)
#define EPIT_CR_OCIEN_SHIFT                      (2U)
#define EPIT_CR_OCIEN(x)                         (((uint32_t)(((uint32_t)(x)) << EPIT_CR_OCIEN_SHIFT)) & EPIT_CR_OCIEN_MASK)
#define EPIT_CR_RLD_MASK                         (0x8U)
#define EPIT_CR_RLD_SHIFT                        (3U)
#define EPIT_CR_RLD(x)                           (((uint32_t)(((uint32_t)(x)) << EPIT_CR_RLD_SHIFT)) & EPIT_CR_RLD_MASK)
#define EPIT_CR_PRESCALAR_MASK                   (0xFFF0U)
#define EPIT_CR_PRESCALAR_SHIFT                  (4U)
#define EPIT_CR_PRESCALAR(x)                     (((uint32_t)(((uint32_t)(x)) << EPIT_CR_PRESCALAR_SHIFT)) & EPIT_CR_PRESCALAR_MASK)
#define EPIT_CR_SWR_MASK                         (0x10000U)
#define EPIT_CR_SWR_SHIFT                        (16U)
#define EPIT_CR_SWR(x)                           (((uint32_t)(((uint32_t)(x)) << EPIT_CR_SWR_SHIFT)) & EPIT_CR_SWR_MASK)
#define EPIT_CR_IOVW_MASK                        (0x20000U)
#define EPIT_CR_IOVW_SHIFT                       (17U)
#define EPIT_CR_IOVW(x)                          (((uint32_t)(((uint32_t)(x)) << EPIT_CR_IOVW_SHIFT)) & EPIT_CR_IOVW_MASK)
#define EPIT_CR_DBGEN_MASK                       (0x40000U)
#define EPIT_CR_DBGEN_SHIFT                      (18U)
#define EPIT_CR_DBGEN(x)                         (((uint32_t)(((uint32_t)(x)) << EPIT_CR_DBGEN_SHIFT)) & EPIT_CR_DBGEN_MASK)
#define EPIT_CR_WAITEN_MASK                      (0x80000U)
#define EPIT_CR_WAITEN_SHIFT                     (19U)
#define EPIT_CR_WAITEN(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CR_WAITEN_SHIFT)) & EPIT_CR_WAITEN_MASK)
#define EPIT_CR_STOPEN_MASK                      (0x200000U)
#define EPIT_CR_STOPEN_SHIFT                     (21U)
#define EPIT_CR_STOPEN(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CR_STOPEN_SHIFT)) & EPIT_CR_STOPEN_MASK)
#define EPIT_CR_OM_MASK                          (0xC00000U)
#define EPIT_CR_OM_SHIFT                         (22U)
#define EPIT_CR_OM(x)                            (((uint32_t)(((uint32_t)(x)) << EPIT_CR_OM_SHIFT)) & EPIT_CR_OM_MASK)
#define EPIT_CR_CLKSRC_MASK                      (0x3000000U)
#define EPIT_CR_CLKSRC_SHIFT                     (24U)
#define EPIT_CR_CLKSRC(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CR_CLKSRC_SHIFT)) & EPIT_CR_CLKSRC_MASK)

/*! @name SR - Status register */
#define EPIT_SR_OCIF_MASK                        (0x1U)
#define EPIT_SR_OCIF_SHIFT                       (0U)
#define EPIT_SR_OCIF(x)                          (((uint32_t)(((uint32_t)(x)) << EPIT_SR_OCIF_SHIFT)) & EPIT_SR_OCIF_MASK)

/*! @name LR - Load register */
#define EPIT_LR_LOAD_MASK                        (0xFFFFFFFFU)
#define EPIT_LR_LOAD_SHIFT                       (0U)
#define EPIT_LR_LOAD(x)                          (((uint32_t)(((uint32_t)(x)) << EPIT_LR_LOAD_SHIFT)) & EPIT_LR_LOAD_MASK)

/*! @name CMPR - Compare register */
#define EPIT_CMPR_COMPARE_MASK                   (0xFFFFFFFFU)
#define EPIT_CMPR_COMPARE_SHIFT                  (0U)
#define EPIT_CMPR_COMPARE(x)                     (((uint32_t)(((uint32_t)(x)) << EPIT_CMPR_COMPARE_SHIFT)) & EPIT_CMPR_COMPARE_MASK)

/*! @name CNR - Counter register */
#define EPIT_CNR_COUNT_MASK                      (0xFFFFFFFFU)
#define EPIT_CNR_COUNT_SHIFT                     (0U)
#define EPIT_CNR_COUNT(x)                        (((uint32_t)(((uint32_t)(x)) << EPIT_CNR_COUNT_SHIFT)) & EPIT_CNR_COUNT_MASK)


/*!
 * @}
 */ /* end of group EPIT_Register_Masks */


/* EPIT - Peripheral instance base addresses */
/** Peripheral EPIT1 base address */
#define EPIT1_BASE                               (0x20D0000u)
/** Peripheral EPIT1 base pointer */
#define EPIT1                                    ((EPIT_Type *)EPIT1_BASE)
/** Peripheral EPIT2 base address */
#define EPIT2_BASE                               (0x20D4000u)
/** Peripheral EPIT2 base pointer */
#define EPIT2                                    ((EPIT_Type *)EPIT2_BASE)
/** Array initializer of EPIT peripheral base addresses */
#define EPIT_BASE_ADDRS                          { 0u, EPIT1_BASE, EPIT2_BASE }
/** Array initializer of EPIT peripheral base pointers */
#define EPIT_BASE_PTRS                           { (EPIT_Type *)0u, EPIT1, EPIT2 }
/** Interrupt vectors for the EPIT peripheral type */
#define EPIT_IRQS                                { NotAvail_IRQn, EPIT1_IRQn, EPIT2_IRQn }

/*!
 * @}
 */ /* end of group EPIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LCDIF Peripheral Access Layer LCD接口层
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Peripheral_Access_Layer LCDIF Peripheral Access Layer
 * @{
 */

/** LCDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< eLCDIF General Control Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< eLCDIF General Control Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< eLCDIF General Control Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< eLCDIF General Control Register, offset: 0xC */
  __IO uint32_t CTRL1;                             /**< eLCDIF General Control1 Register, offset: 0x10 */
  __IO uint32_t CTRL1_SET;                         /**< eLCDIF General Control1 Register, offset: 0x14 */
  __IO uint32_t CTRL1_CLR;                         /**< eLCDIF General Control1 Register, offset: 0x18 */
  __IO uint32_t CTRL1_TOG;                         /**< eLCDIF General Control1 Register, offset: 0x1C */
  __IO uint32_t CTRL2;                             /**< eLCDIF General Control2 Register, offset: 0x20 */
  __IO uint32_t CTRL2_SET;                         /**< eLCDIF General Control2 Register, offset: 0x24 */
  __IO uint32_t CTRL2_CLR;                         /**< eLCDIF General Control2 Register, offset: 0x28 */
  __IO uint32_t CTRL2_TOG;                         /**< eLCDIF General Control2 Register, offset: 0x2C */
  __IO uint32_t TRANSFER_COUNT;                    /**< eLCDIF Horizontal and Vertical Valid Data Count Register, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CUR_BUF;                           /**< LCD Interface Current Buffer Address Register, offset: 0x40 */
       uint8_t RESERVED_1[12];
  __IO uint32_t NEXT_BUF;                          /**< LCD Interface Next Buffer Address Register, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t TIMING;                            /**< LCD Interface Timing Register, offset: 0x60 */
       uint8_t RESERVED_3[12];
  __IO uint32_t VDCTRL0;                           /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x70 */
  __IO uint32_t VDCTRL0_SET;                       /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x74 */
  __IO uint32_t VDCTRL0_CLR;                       /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x78 */
  __IO uint32_t VDCTRL0_TOG;                       /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x7C */
  __IO uint32_t VDCTRL1;                           /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register1, offset: 0x80 */
       uint8_t RESERVED_4[12];
  __IO uint32_t VDCTRL2;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register2, offset: 0x90 */
       uint8_t RESERVED_5[12];
  __IO uint32_t VDCTRL3;                           /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register3, offset: 0xA0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t VDCTRL4;                           /**< eLCDIF VSYNC Mode and Dotclk Mode Control Register4, offset: 0xB0 */
       uint8_t RESERVED_7[12];
  __IO uint32_t DVICTRL0;                          /**< Digital Video Interface Control0 Register, offset: 0xC0 */
       uint8_t RESERVED_8[12];
  __IO uint32_t DVICTRL1;                          /**< Digital Video Interface Control1 Register, offset: 0xD0 */
       uint8_t RESERVED_9[12];
  __IO uint32_t DVICTRL2;                          /**< Digital Video Interface Control2 Register, offset: 0xE0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t DVICTRL3;                          /**< Digital Video Interface Control3 Register, offset: 0xF0 */
       uint8_t RESERVED_11[12];
  __IO uint32_t DVICTRL4;                          /**< Digital Video Interface Control4 Register, offset: 0x100 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CSC_COEFF0;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient0 Register, offset: 0x110 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CSC_COEFF1;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient1 Register, offset: 0x120 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CSC_COEFF2;                        /**< RGB to YCbCr 4:2:2 CSC Coefficent2 Register, offset: 0x130 */
       uint8_t RESERVED_15[12];
  __IO uint32_t CSC_COEFF3;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient3 Register, offset: 0x140 */
       uint8_t RESERVED_16[12];
  __IO uint32_t CSC_COEFF4;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient4 Register, offset: 0x150 */
       uint8_t RESERVED_17[12];
  __IO uint32_t CSC_OFFSET;                        /**< RGB to YCbCr 4:2:2 CSC Offset Register, offset: 0x160 */
       uint8_t RESERVED_18[12];
  __IO uint32_t CSC_LIMIT;                         /**< RGB to YCbCr 4:2:2 CSC Limit Register, offset: 0x170 */
       uint8_t RESERVED_19[12];
  __IO uint32_t DATA;                              /**< LCD Interface Data Register, offset: 0x180 */
       uint8_t RESERVED_20[12];
  __IO uint32_t BM_ERROR_STAT;                     /**< Bus Master Error Status Register, offset: 0x190 */
       uint8_t RESERVED_21[12];
  __IO uint32_t CRC_STAT;                          /**< CRC Status Register, offset: 0x1A0 */
       uint8_t RESERVED_22[12];
  __I  uint32_t STAT;                              /**< LCD Interface Status Register, offset: 0x1B0 */
       uint8_t RESERVED_23[76];
  __IO uint32_t THRES;                             /**< eLCDIF Threshold Register, offset: 0x200 */
       uint8_t RESERVED_24[12];
  __IO uint32_t AS_CTRL;                           /**< eLCDIF AS Buffer Control Register, offset: 0x210 */
       uint8_t RESERVED_25[12];
  __IO uint32_t AS_BUF;                            /**< Alpha Surface Buffer Pointer, offset: 0x220 */
       uint8_t RESERVED_26[12];
  __IO uint32_t AS_NEXT_BUF;                       /**< , offset: 0x230 */
       uint8_t RESERVED_27[12];
  __IO uint32_t AS_CLRKEYLOW;                      /**< eLCDIF Overlay Color Key Low, offset: 0x240 */
       uint8_t RESERVED_28[12];
  __IO uint32_t AS_CLRKEYHIGH;                     /**< eLCDIF Overlay Color Key High, offset: 0x250 */
       uint8_t RESERVED_29[12];
  __IO uint32_t SYNC_DELAY;                        /**< LCD working insync mode with CSI for VSYNC delay, offset: 0x260 */
} LCDIF_Type;

/* ----------------------------------------------------------------------------
   -- LCDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Register_Masks LCDIF Register Masks
 * @{
 */

/*! @name CTRL - eLCDIF General Control Register */
#define LCDIF_CTRL_RUN_MASK                      (0x1U)
#define LCDIF_CTRL_RUN_SHIFT                     (0U)
#define LCDIF_CTRL_RUN(x)                        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_RUN_SHIFT)) & LCDIF_CTRL_RUN_MASK)
#define LCDIF_CTRL_DATA_FORMAT_24_BIT_MASK       (0x2U)
#define LCDIF_CTRL_DATA_FORMAT_24_BIT_SHIFT      (1U)
#define LCDIF_CTRL_DATA_FORMAT_24_BIT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_DATA_FORMAT_24_BIT_MASK)
#define LCDIF_CTRL_DATA_FORMAT_18_BIT_MASK       (0x4U)
#define LCDIF_CTRL_DATA_FORMAT_18_BIT_SHIFT      (2U)
#define LCDIF_CTRL_DATA_FORMAT_18_BIT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_DATA_FORMAT_18_BIT_MASK)
#define LCDIF_CTRL_DATA_FORMAT_16_BIT_MASK       (0x8U)
#define LCDIF_CTRL_DATA_FORMAT_16_BIT_SHIFT      (3U)
#define LCDIF_CTRL_DATA_FORMAT_16_BIT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_DATA_FORMAT_16_BIT_MASK)
#define LCDIF_CTRL_RSRVD0_MASK                   (0x10U)
#define LCDIF_CTRL_RSRVD0_SHIFT                  (4U)
#define LCDIF_CTRL_RSRVD0(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_RSRVD0_SHIFT)) & LCDIF_CTRL_RSRVD0_MASK)
#define LCDIF_CTRL_MASTER_MASK                   (0x20U)
#define LCDIF_CTRL_MASTER_SHIFT                  (5U)
#define LCDIF_CTRL_MASTER(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_MASTER_SHIFT)) & LCDIF_CTRL_MASTER_MASK)
#define LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_MASK     (0x40U)
#define LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_SHIFT    (6U)
#define LCDIF_CTRL_ENABLE_PXP_HANDSHAKE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_MASK)
#define LCDIF_CTRL_RGB_TO_YCBCR422_CSC_MASK      (0x80U)
#define LCDIF_CTRL_RGB_TO_YCBCR422_CSC_SHIFT     (7U)
#define LCDIF_CTRL_RGB_TO_YCBCR422_CSC(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_RGB_TO_YCBCR422_CSC_MASK)
#define LCDIF_CTRL_WORD_LENGTH_MASK              (0x300U)
#define LCDIF_CTRL_WORD_LENGTH_SHIFT             (8U)
#define LCDIF_CTRL_WORD_LENGTH(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_WORD_LENGTH_MASK)
#define LCDIF_CTRL_LCD_DATABUS_WIDTH_MASK        (0xC00U)
#define LCDIF_CTRL_LCD_DATABUS_WIDTH_SHIFT       (10U)
#define LCDIF_CTRL_LCD_DATABUS_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_LCD_DATABUS_WIDTH_MASK)
#define LCDIF_CTRL_CSC_DATA_SWIZZLE_MASK         (0x3000U)
#define LCDIF_CTRL_CSC_DATA_SWIZZLE_SHIFT        (12U)
#define LCDIF_CTRL_CSC_DATA_SWIZZLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_CSC_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_INPUT_DATA_SWIZZLE_MASK       (0xC000U)
#define LCDIF_CTRL_INPUT_DATA_SWIZZLE_SHIFT      (14U)
#define LCDIF_CTRL_INPUT_DATA_SWIZZLE(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_INPUT_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_DATA_SELECT_MASK              (0x10000U)
#define LCDIF_CTRL_DATA_SELECT_SHIFT             (16U)
#define LCDIF_CTRL_DATA_SELECT(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_SELECT_SHIFT)) & LCDIF_CTRL_DATA_SELECT_MASK)
#define LCDIF_CTRL_DOTCLK_MODE_MASK              (0x20000U)
#define LCDIF_CTRL_DOTCLK_MODE_SHIFT             (17U)
#define LCDIF_CTRL_DOTCLK_MODE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_DOTCLK_MODE_MASK)
#define LCDIF_CTRL_VSYNC_MODE_MASK               (0x40000U)
#define LCDIF_CTRL_VSYNC_MODE_SHIFT              (18U)
#define LCDIF_CTRL_VSYNC_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_VSYNC_MODE_MASK)
#define LCDIF_CTRL_BYPASS_COUNT_MASK             (0x80000U)
#define LCDIF_CTRL_BYPASS_COUNT_SHIFT            (19U)
#define LCDIF_CTRL_BYPASS_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_BYPASS_COUNT_MASK)
#define LCDIF_CTRL_DVI_MODE_MASK                 (0x100000U)
#define LCDIF_CTRL_DVI_MODE_SHIFT                (20U)
#define LCDIF_CTRL_DVI_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DVI_MODE_SHIFT)) & LCDIF_CTRL_DVI_MODE_MASK)
#define LCDIF_CTRL_SHIFT_NUM_BITS_MASK           (0x3E00000U)
#define LCDIF_CTRL_SHIFT_NUM_BITS_SHIFT          (21U)
#define LCDIF_CTRL_SHIFT_NUM_BITS(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_SHIFT_NUM_BITS_MASK)
#define LCDIF_CTRL_DATA_SHIFT_DIR_MASK           (0x4000000U)
#define LCDIF_CTRL_DATA_SHIFT_DIR_SHIFT          (26U)
#define LCDIF_CTRL_DATA_SHIFT_DIR(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_DATA_SHIFT_DIR_MASK)
#define LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_MASK      (0x8000000U)
#define LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_SHIFT     (27U)
#define LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_MASK)
#define LCDIF_CTRL_READ_WRITEB_MASK              (0x10000000U)
#define LCDIF_CTRL_READ_WRITEB_SHIFT             (28U)
#define LCDIF_CTRL_READ_WRITEB(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_READ_WRITEB_SHIFT)) & LCDIF_CTRL_READ_WRITEB_MASK)
#define LCDIF_CTRL_YCBCR422_INPUT_MASK           (0x20000000U)
#define LCDIF_CTRL_YCBCR422_INPUT_SHIFT          (29U)
#define LCDIF_CTRL_YCBCR422_INPUT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_YCBCR422_INPUT_MASK)
#define LCDIF_CTRL_CLKGATE_MASK                  (0x40000000U)
#define LCDIF_CTRL_CLKGATE_SHIFT                 (30U)
#define LCDIF_CTRL_CLKGATE(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLKGATE_SHIFT)) & LCDIF_CTRL_CLKGATE_MASK)
#define LCDIF_CTRL_SFTRST_MASK                   (0x80000000U)
#define LCDIF_CTRL_SFTRST_SHIFT                  (31U)
#define LCDIF_CTRL_SFTRST(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SFTRST_SHIFT)) & LCDIF_CTRL_SFTRST_MASK)

/*! @name CTRL_SET - eLCDIF General Control Register */
#define LCDIF_CTRL_SET_RUN_MASK                  (0x1U)
#define LCDIF_CTRL_SET_RUN_SHIFT                 (0U)
#define LCDIF_CTRL_SET_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_RUN_SHIFT)) & LCDIF_CTRL_SET_RUN_MASK)
#define LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_MASK   (0x2U)
#define LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_SHIFT  (1U)
#define LCDIF_CTRL_SET_DATA_FORMAT_24_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_MASK)
#define LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_MASK   (0x4U)
#define LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_SHIFT  (2U)
#define LCDIF_CTRL_SET_DATA_FORMAT_18_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_MASK)
#define LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_MASK   (0x8U)
#define LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_SHIFT  (3U)
#define LCDIF_CTRL_SET_DATA_FORMAT_16_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_MASK)
#define LCDIF_CTRL_SET_RSRVD0_MASK               (0x10U)
#define LCDIF_CTRL_SET_RSRVD0_SHIFT              (4U)
#define LCDIF_CTRL_SET_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_RSRVD0_SHIFT)) & LCDIF_CTRL_SET_RSRVD0_MASK)
#define LCDIF_CTRL_SET_MASTER_MASK               (0x20U)
#define LCDIF_CTRL_SET_MASTER_SHIFT              (5U)
#define LCDIF_CTRL_SET_MASTER(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_MASTER_SHIFT)) & LCDIF_CTRL_SET_MASTER_MASK)
#define LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_MASK (0x40U)
#define LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_SHIFT (6U)
#define LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_MASK)
#define LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_MASK  (0x80U)
#define LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_SHIFT (7U)
#define LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_MASK)
#define LCDIF_CTRL_SET_WORD_LENGTH_MASK          (0x300U)
#define LCDIF_CTRL_SET_WORD_LENGTH_SHIFT         (8U)
#define LCDIF_CTRL_SET_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_SET_WORD_LENGTH_MASK)
#define LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_MASK    (0xC00U)
#define LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_SHIFT   (10U)
#define LCDIF_CTRL_SET_LCD_DATABUS_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_MASK)
#define LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_MASK     (0x3000U)
#define LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_SHIFT    (12U)
#define LCDIF_CTRL_SET_CSC_DATA_SWIZZLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_MASK   (0xC000U)
#define LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_SHIFT  (14U)
#define LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_SET_DATA_SELECT_MASK          (0x10000U)
#define LCDIF_CTRL_SET_DATA_SELECT_SHIFT         (16U)
#define LCDIF_CTRL_SET_DATA_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_SELECT_SHIFT)) & LCDIF_CTRL_SET_DATA_SELECT_MASK)
#define LCDIF_CTRL_SET_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_SET_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_SET_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_SET_DOTCLK_MODE_MASK)
#define LCDIF_CTRL_SET_VSYNC_MODE_MASK           (0x40000U)
#define LCDIF_CTRL_SET_VSYNC_MODE_SHIFT          (18U)
#define LCDIF_CTRL_SET_VSYNC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_SET_VSYNC_MODE_MASK)
#define LCDIF_CTRL_SET_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_SET_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_SET_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_SET_BYPASS_COUNT_MASK)
#define LCDIF_CTRL_SET_DVI_MODE_MASK             (0x100000U)
#define LCDIF_CTRL_SET_DVI_MODE_SHIFT            (20U)
#define LCDIF_CTRL_SET_DVI_MODE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DVI_MODE_SHIFT)) & LCDIF_CTRL_SET_DVI_MODE_MASK)
#define LCDIF_CTRL_SET_SHIFT_NUM_BITS_MASK       (0x3E00000U)
#define LCDIF_CTRL_SET_SHIFT_NUM_BITS_SHIFT      (21U)
#define LCDIF_CTRL_SET_SHIFT_NUM_BITS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_SET_SHIFT_NUM_BITS_MASK)
#define LCDIF_CTRL_SET_DATA_SHIFT_DIR_MASK       (0x4000000U)
#define LCDIF_CTRL_SET_DATA_SHIFT_DIR_SHIFT      (26U)
#define LCDIF_CTRL_SET_DATA_SHIFT_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_SET_DATA_SHIFT_DIR_MASK)
#define LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_MASK  (0x8000000U)
#define LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_SHIFT (27U)
#define LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_MASK)
#define LCDIF_CTRL_SET_READ_WRITEB_MASK          (0x10000000U)
#define LCDIF_CTRL_SET_READ_WRITEB_SHIFT         (28U)
#define LCDIF_CTRL_SET_READ_WRITEB(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_READ_WRITEB_SHIFT)) & LCDIF_CTRL_SET_READ_WRITEB_MASK)
#define LCDIF_CTRL_SET_YCBCR422_INPUT_MASK       (0x20000000U)
#define LCDIF_CTRL_SET_YCBCR422_INPUT_SHIFT      (29U)
#define LCDIF_CTRL_SET_YCBCR422_INPUT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_SET_YCBCR422_INPUT_MASK)
#define LCDIF_CTRL_SET_CLKGATE_MASK              (0x40000000U)
#define LCDIF_CTRL_SET_CLKGATE_SHIFT             (30U)
#define LCDIF_CTRL_SET_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_CLKGATE_SHIFT)) & LCDIF_CTRL_SET_CLKGATE_MASK)
#define LCDIF_CTRL_SET_SFTRST_MASK               (0x80000000U)
#define LCDIF_CTRL_SET_SFTRST_SHIFT              (31U)
#define LCDIF_CTRL_SET_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_SFTRST_SHIFT)) & LCDIF_CTRL_SET_SFTRST_MASK)

/*! @name CTRL_CLR - eLCDIF General Control Register */
#define LCDIF_CTRL_CLR_RUN_MASK                  (0x1U)
#define LCDIF_CTRL_CLR_RUN_SHIFT                 (0U)
#define LCDIF_CTRL_CLR_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_RUN_SHIFT)) & LCDIF_CTRL_CLR_RUN_MASK)
#define LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_MASK   (0x2U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_SHIFT  (1U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_MASK)
#define LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_MASK   (0x4U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_SHIFT  (2U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_MASK)
#define LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_MASK   (0x8U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_SHIFT  (3U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_MASK)
#define LCDIF_CTRL_CLR_RSRVD0_MASK               (0x10U)
#define LCDIF_CTRL_CLR_RSRVD0_SHIFT              (4U)
#define LCDIF_CTRL_CLR_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL_CLR_RSRVD0_MASK)
#define LCDIF_CTRL_CLR_MASTER_MASK               (0x20U)
#define LCDIF_CTRL_CLR_MASTER_SHIFT              (5U)
#define LCDIF_CTRL_CLR_MASTER(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_MASTER_SHIFT)) & LCDIF_CTRL_CLR_MASTER_MASK)
#define LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_MASK (0x40U)
#define LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_SHIFT (6U)
#define LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_MASK)
#define LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_MASK  (0x80U)
#define LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_SHIFT (7U)
#define LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_MASK)
#define LCDIF_CTRL_CLR_WORD_LENGTH_MASK          (0x300U)
#define LCDIF_CTRL_CLR_WORD_LENGTH_SHIFT         (8U)
#define LCDIF_CTRL_CLR_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_CLR_WORD_LENGTH_MASK)
#define LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_MASK    (0xC00U)
#define LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_SHIFT   (10U)
#define LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_MASK)
#define LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_MASK     (0x3000U)
#define LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_SHIFT    (12U)
#define LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_MASK   (0xC000U)
#define LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_SHIFT  (14U)
#define LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_CLR_DATA_SELECT_MASK          (0x10000U)
#define LCDIF_CTRL_CLR_DATA_SELECT_SHIFT         (16U)
#define LCDIF_CTRL_CLR_DATA_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_SELECT_SHIFT)) & LCDIF_CTRL_CLR_DATA_SELECT_MASK)
#define LCDIF_CTRL_CLR_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_CLR_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_CLR_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_CLR_DOTCLK_MODE_MASK)
#define LCDIF_CTRL_CLR_VSYNC_MODE_MASK           (0x40000U)
#define LCDIF_CTRL_CLR_VSYNC_MODE_SHIFT          (18U)
#define LCDIF_CTRL_CLR_VSYNC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_CLR_VSYNC_MODE_MASK)
#define LCDIF_CTRL_CLR_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_CLR_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_CLR_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_CLR_BYPASS_COUNT_MASK)
#define LCDIF_CTRL_CLR_DVI_MODE_MASK             (0x100000U)
#define LCDIF_CTRL_CLR_DVI_MODE_SHIFT            (20U)
#define LCDIF_CTRL_CLR_DVI_MODE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DVI_MODE_SHIFT)) & LCDIF_CTRL_CLR_DVI_MODE_MASK)
#define LCDIF_CTRL_CLR_SHIFT_NUM_BITS_MASK       (0x3E00000U)
#define LCDIF_CTRL_CLR_SHIFT_NUM_BITS_SHIFT      (21U)
#define LCDIF_CTRL_CLR_SHIFT_NUM_BITS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_CLR_SHIFT_NUM_BITS_MASK)
#define LCDIF_CTRL_CLR_DATA_SHIFT_DIR_MASK       (0x4000000U)
#define LCDIF_CTRL_CLR_DATA_SHIFT_DIR_SHIFT      (26U)
#define LCDIF_CTRL_CLR_DATA_SHIFT_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_CLR_DATA_SHIFT_DIR_MASK)
#define LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_MASK  (0x8000000U)
#define LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_SHIFT (27U)
#define LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_MASK)
#define LCDIF_CTRL_CLR_READ_WRITEB_MASK          (0x10000000U)
#define LCDIF_CTRL_CLR_READ_WRITEB_SHIFT         (28U)
#define LCDIF_CTRL_CLR_READ_WRITEB(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_READ_WRITEB_SHIFT)) & LCDIF_CTRL_CLR_READ_WRITEB_MASK)
#define LCDIF_CTRL_CLR_YCBCR422_INPUT_MASK       (0x20000000U)
#define LCDIF_CTRL_CLR_YCBCR422_INPUT_SHIFT      (29U)
#define LCDIF_CTRL_CLR_YCBCR422_INPUT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_CLR_YCBCR422_INPUT_MASK)
#define LCDIF_CTRL_CLR_CLKGATE_MASK              (0x40000000U)
#define LCDIF_CTRL_CLR_CLKGATE_SHIFT             (30U)
#define LCDIF_CTRL_CLR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_CLKGATE_SHIFT)) & LCDIF_CTRL_CLR_CLKGATE_MASK)
#define LCDIF_CTRL_CLR_SFTRST_MASK               (0x80000000U)
#define LCDIF_CTRL_CLR_SFTRST_SHIFT              (31U)
#define LCDIF_CTRL_CLR_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_SFTRST_SHIFT)) & LCDIF_CTRL_CLR_SFTRST_MASK)

/*! @name CTRL_TOG - eLCDIF General Control Register */
#define LCDIF_CTRL_TOG_RUN_MASK                  (0x1U)
#define LCDIF_CTRL_TOG_RUN_SHIFT                 (0U)
#define LCDIF_CTRL_TOG_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_RUN_SHIFT)) & LCDIF_CTRL_TOG_RUN_MASK)
#define LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_MASK   (0x2U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_SHIFT  (1U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_MASK)
#define LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_MASK   (0x4U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_SHIFT  (2U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_MASK)
#define LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_MASK   (0x8U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_SHIFT  (3U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_MASK)
#define LCDIF_CTRL_TOG_RSRVD0_MASK               (0x10U)
#define LCDIF_CTRL_TOG_RSRVD0_SHIFT              (4U)
#define LCDIF_CTRL_TOG_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL_TOG_RSRVD0_MASK)
#define LCDIF_CTRL_TOG_MASTER_MASK               (0x20U)
#define LCDIF_CTRL_TOG_MASTER_SHIFT              (5U)
#define LCDIF_CTRL_TOG_MASTER(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_MASTER_SHIFT)) & LCDIF_CTRL_TOG_MASTER_MASK)
#define LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_MASK (0x40U)
#define LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_SHIFT (6U)
#define LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_MASK)
#define LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_MASK  (0x80U)
#define LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_SHIFT (7U)
#define LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_MASK)
#define LCDIF_CTRL_TOG_WORD_LENGTH_MASK          (0x300U)
#define LCDIF_CTRL_TOG_WORD_LENGTH_SHIFT         (8U)
#define LCDIF_CTRL_TOG_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_TOG_WORD_LENGTH_MASK)
#define LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_MASK    (0xC00U)
#define LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_SHIFT   (10U)
#define LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_MASK)
#define LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_MASK     (0x3000U)
#define LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_SHIFT    (12U)
#define LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_MASK   (0xC000U)
#define LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_SHIFT  (14U)
#define LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_MASK)
#define LCDIF_CTRL_TOG_DATA_SELECT_MASK          (0x10000U)
#define LCDIF_CTRL_TOG_DATA_SELECT_SHIFT         (16U)
#define LCDIF_CTRL_TOG_DATA_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_SELECT_SHIFT)) & LCDIF_CTRL_TOG_DATA_SELECT_MASK)
#define LCDIF_CTRL_TOG_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_TOG_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_TOG_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_TOG_DOTCLK_MODE_MASK)
#define LCDIF_CTRL_TOG_VSYNC_MODE_MASK           (0x40000U)
#define LCDIF_CTRL_TOG_VSYNC_MODE_SHIFT          (18U)
#define LCDIF_CTRL_TOG_VSYNC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_TOG_VSYNC_MODE_MASK)
#define LCDIF_CTRL_TOG_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_TOG_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_TOG_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_TOG_BYPASS_COUNT_MASK)
#define LCDIF_CTRL_TOG_DVI_MODE_MASK             (0x100000U)
#define LCDIF_CTRL_TOG_DVI_MODE_SHIFT            (20U)
#define LCDIF_CTRL_TOG_DVI_MODE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DVI_MODE_SHIFT)) & LCDIF_CTRL_TOG_DVI_MODE_MASK)
#define LCDIF_CTRL_TOG_SHIFT_NUM_BITS_MASK       (0x3E00000U)
#define LCDIF_CTRL_TOG_SHIFT_NUM_BITS_SHIFT      (21U)
#define LCDIF_CTRL_TOG_SHIFT_NUM_BITS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_TOG_SHIFT_NUM_BITS_MASK)
#define LCDIF_CTRL_TOG_DATA_SHIFT_DIR_MASK       (0x4000000U)
#define LCDIF_CTRL_TOG_DATA_SHIFT_DIR_SHIFT      (26U)
#define LCDIF_CTRL_TOG_DATA_SHIFT_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_TOG_DATA_SHIFT_DIR_MASK)
#define LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_MASK  (0x8000000U)
#define LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_SHIFT (27U)
#define LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_MASK)
#define LCDIF_CTRL_TOG_READ_WRITEB_MASK          (0x10000000U)
#define LCDIF_CTRL_TOG_READ_WRITEB_SHIFT         (28U)
#define LCDIF_CTRL_TOG_READ_WRITEB(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_READ_WRITEB_SHIFT)) & LCDIF_CTRL_TOG_READ_WRITEB_MASK)
#define LCDIF_CTRL_TOG_YCBCR422_INPUT_MASK       (0x20000000U)
#define LCDIF_CTRL_TOG_YCBCR422_INPUT_SHIFT      (29U)
#define LCDIF_CTRL_TOG_YCBCR422_INPUT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_TOG_YCBCR422_INPUT_MASK)
#define LCDIF_CTRL_TOG_CLKGATE_MASK              (0x40000000U)
#define LCDIF_CTRL_TOG_CLKGATE_SHIFT             (30U)
#define LCDIF_CTRL_TOG_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_CLKGATE_SHIFT)) & LCDIF_CTRL_TOG_CLKGATE_MASK)
#define LCDIF_CTRL_TOG_SFTRST_MASK               (0x80000000U)
#define LCDIF_CTRL_TOG_SFTRST_SHIFT              (31U)
#define LCDIF_CTRL_TOG_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_SFTRST_SHIFT)) & LCDIF_CTRL_TOG_SFTRST_MASK)

/*! @name CTRL1 - eLCDIF General Control1 Register */
#define LCDIF_CTRL1_RESET_MASK                   (0x1U)
#define LCDIF_CTRL1_RESET_SHIFT                  (0U)
#define LCDIF_CTRL1_RESET(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RESET_SHIFT)) & LCDIF_CTRL1_RESET_MASK)
#define LCDIF_CTRL1_MODE86_MASK                  (0x2U)
#define LCDIF_CTRL1_MODE86_SHIFT                 (1U)
#define LCDIF_CTRL1_MODE86(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_MODE86_SHIFT)) & LCDIF_CTRL1_MODE86_MASK)
#define LCDIF_CTRL1_BUSY_ENABLE_MASK             (0x4U)
#define LCDIF_CTRL1_BUSY_ENABLE_SHIFT            (2U)
#define LCDIF_CTRL1_BUSY_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_BUSY_ENABLE_MASK)
#define LCDIF_CTRL1_RSRVD0_MASK                  (0xF8U)
#define LCDIF_CTRL1_RSRVD0_SHIFT                 (3U)
#define LCDIF_CTRL1_RSRVD0(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RSRVD0_SHIFT)) & LCDIF_CTRL1_RSRVD0_MASK)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_MASK          (0x100U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_SHIFT         (8U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_VSYNC_EDGE_IRQ_MASK)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_MASK      (0x200U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_SHIFT     (9U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_MASK)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_MASK           (0x400U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_SHIFT          (10U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_UNDERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_OVERFLOW_IRQ_MASK            (0x800U)
#define LCDIF_CTRL1_OVERFLOW_IRQ_SHIFT           (11U)
#define LCDIF_CTRL1_OVERFLOW_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_OVERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_MASK       (0x1000U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_SHIFT      (12U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_MASK)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_MASK   (0x2000U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_SHIFT  (13U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_MASK)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_EN_MASK        (0x4000U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_EN_SHIFT       (14U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_EN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_UNDERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_OVERFLOW_IRQ_EN_MASK         (0x8000U)
#define LCDIF_CTRL1_OVERFLOW_IRQ_EN_SHIFT        (15U)
#define LCDIF_CTRL1_OVERFLOW_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_OVERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_BYTE_PACKING_FORMAT_MASK     (0xF0000U)
#define LCDIF_CTRL1_BYTE_PACKING_FORMAT_SHIFT    (16U)
#define LCDIF_CTRL1_BYTE_PACKING_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_BYTE_PACKING_FORMAT_MASK)
#define LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_MASK)
#define LCDIF_CTRL1_FIFO_CLEAR_MASK              (0x200000U)
#define LCDIF_CTRL1_FIFO_CLEAR_SHIFT             (21U)
#define LCDIF_CTRL1_FIFO_CLEAR(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_FIFO_CLEAR_MASK)
#define LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_MASK)
#define LCDIF_CTRL1_INTERLACE_FIELDS_MASK        (0x800000U)
#define LCDIF_CTRL1_INTERLACE_FIELDS_SHIFT       (23U)
#define LCDIF_CTRL1_INTERLACE_FIELDS(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_INTERLACE_FIELDS_MASK)
#define LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_MASK    (0x1000000U)
#define LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_SHIFT   (24U)
#define LCDIF_CTRL1_RECOVER_ON_UNDERFLOW(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_MASK)
#define LCDIF_CTRL1_BM_ERROR_IRQ_MASK            (0x2000000U)
#define LCDIF_CTRL1_BM_ERROR_IRQ_SHIFT           (25U)
#define LCDIF_CTRL1_BM_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_BM_ERROR_IRQ_MASK)
#define LCDIF_CTRL1_BM_ERROR_IRQ_EN_MASK         (0x4000000U)
#define LCDIF_CTRL1_BM_ERROR_IRQ_EN_SHIFT        (26U)
#define LCDIF_CTRL1_BM_ERROR_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_BM_ERROR_IRQ_EN_MASK)
#define LCDIF_CTRL1_COMBINE_MPU_WR_STRB_MASK     (0x8000000U)
#define LCDIF_CTRL1_COMBINE_MPU_WR_STRB_SHIFT    (27U)
#define LCDIF_CTRL1_COMBINE_MPU_WR_STRB(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_COMBINE_MPU_WR_STRB_MASK)
#define LCDIF_CTRL1_RSRVD1_MASK                  (0xF0000000U)
#define LCDIF_CTRL1_RSRVD1_SHIFT                 (28U)
#define LCDIF_CTRL1_RSRVD1(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RSRVD1_SHIFT)) & LCDIF_CTRL1_RSRVD1_MASK)

/*! @name CTRL1_SET - eLCDIF General Control1 Register */
#define LCDIF_CTRL1_SET_RESET_MASK               (0x1U)
#define LCDIF_CTRL1_SET_RESET_SHIFT              (0U)
#define LCDIF_CTRL1_SET_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RESET_SHIFT)) & LCDIF_CTRL1_SET_RESET_MASK)
#define LCDIF_CTRL1_SET_MODE86_MASK              (0x2U)
#define LCDIF_CTRL1_SET_MODE86_SHIFT             (1U)
#define LCDIF_CTRL1_SET_MODE86(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_MODE86_SHIFT)) & LCDIF_CTRL1_SET_MODE86_MASK)
#define LCDIF_CTRL1_SET_BUSY_ENABLE_MASK         (0x4U)
#define LCDIF_CTRL1_SET_BUSY_ENABLE_SHIFT        (2U)
#define LCDIF_CTRL1_SET_BUSY_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_SET_BUSY_ENABLE_MASK)
#define LCDIF_CTRL1_SET_RSRVD0_MASK              (0xF8U)
#define LCDIF_CTRL1_SET_RSRVD0_SHIFT             (3U)
#define LCDIF_CTRL1_SET_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RSRVD0_SHIFT)) & LCDIF_CTRL1_SET_RSRVD0_MASK)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_MASK      (0x100U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_SHIFT     (8U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_MASK)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_MASK  (0x200U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_SHIFT (9U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_MASK)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_MASK       (0x400U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_SHIFT      (10U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_SET_UNDERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_MASK        (0x800U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_SHIFT       (11U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_SET_OVERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_MASK   (0x1000U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_SHIFT  (12U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_MASK)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_MASK (0x2000U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_SHIFT (13U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_MASK)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_MASK    (0x4000U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_SHIFT   (14U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_MASK     (0x8000U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_SHIFT    (15U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_MASK (0xF0000U)
#define LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_SHIFT (16U)
#define LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_MASK)
#define LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_MASK)
#define LCDIF_CTRL1_SET_FIFO_CLEAR_MASK          (0x200000U)
#define LCDIF_CTRL1_SET_FIFO_CLEAR_SHIFT         (21U)
#define LCDIF_CTRL1_SET_FIFO_CLEAR(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_SET_FIFO_CLEAR_MASK)
#define LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_MASK)
#define LCDIF_CTRL1_SET_INTERLACE_FIELDS_MASK    (0x800000U)
#define LCDIF_CTRL1_SET_INTERLACE_FIELDS_SHIFT   (23U)
#define LCDIF_CTRL1_SET_INTERLACE_FIELDS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_SET_INTERLACE_FIELDS_MASK)
#define LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_MASK (0x1000000U)
#define LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_SHIFT (24U)
#define LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_MASK)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_MASK        (0x2000000U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_SHIFT       (25U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_SET_BM_ERROR_IRQ_MASK)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_MASK     (0x4000000U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_SHIFT    (26U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_MASK)
#define LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_MASK (0x8000000U)
#define LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_SHIFT (27U)
#define LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_MASK)
#define LCDIF_CTRL1_SET_RSRVD1_MASK              (0xF0000000U)
#define LCDIF_CTRL1_SET_RSRVD1_SHIFT             (28U)
#define LCDIF_CTRL1_SET_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RSRVD1_SHIFT)) & LCDIF_CTRL1_SET_RSRVD1_MASK)

/*! @name CTRL1_CLR - eLCDIF General Control1 Register */
#define LCDIF_CTRL1_CLR_RESET_MASK               (0x1U)
#define LCDIF_CTRL1_CLR_RESET_SHIFT              (0U)
#define LCDIF_CTRL1_CLR_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RESET_SHIFT)) & LCDIF_CTRL1_CLR_RESET_MASK)
#define LCDIF_CTRL1_CLR_MODE86_MASK              (0x2U)
#define LCDIF_CTRL1_CLR_MODE86_SHIFT             (1U)
#define LCDIF_CTRL1_CLR_MODE86(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_MODE86_SHIFT)) & LCDIF_CTRL1_CLR_MODE86_MASK)
#define LCDIF_CTRL1_CLR_BUSY_ENABLE_MASK         (0x4U)
#define LCDIF_CTRL1_CLR_BUSY_ENABLE_SHIFT        (2U)
#define LCDIF_CTRL1_CLR_BUSY_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_CLR_BUSY_ENABLE_MASK)
#define LCDIF_CTRL1_CLR_RSRVD0_MASK              (0xF8U)
#define LCDIF_CTRL1_CLR_RSRVD0_SHIFT             (3U)
#define LCDIF_CTRL1_CLR_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL1_CLR_RSRVD0_MASK)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_MASK      (0x100U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_SHIFT     (8U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_MASK)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_MASK  (0x200U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_SHIFT (9U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_MASK)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_MASK       (0x400U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_SHIFT      (10U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_MASK        (0x800U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_SHIFT       (11U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_OVERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_MASK   (0x1000U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_SHIFT  (12U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_MASK)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_MASK (0x2000U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_SHIFT (13U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_MASK)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_MASK    (0x4000U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_SHIFT   (14U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_MASK     (0x8000U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_SHIFT    (15U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_MASK (0xF0000U)
#define LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_SHIFT (16U)
#define LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_MASK)
#define LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_MASK)
#define LCDIF_CTRL1_CLR_FIFO_CLEAR_MASK          (0x200000U)
#define LCDIF_CTRL1_CLR_FIFO_CLEAR_SHIFT         (21U)
#define LCDIF_CTRL1_CLR_FIFO_CLEAR(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_CLR_FIFO_CLEAR_MASK)
#define LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_MASK)
#define LCDIF_CTRL1_CLR_INTERLACE_FIELDS_MASK    (0x800000U)
#define LCDIF_CTRL1_CLR_INTERLACE_FIELDS_SHIFT   (23U)
#define LCDIF_CTRL1_CLR_INTERLACE_FIELDS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_CLR_INTERLACE_FIELDS_MASK)
#define LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_MASK (0x1000000U)
#define LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_SHIFT (24U)
#define LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_MASK)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_MASK        (0x2000000U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_SHIFT       (25U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_BM_ERROR_IRQ_MASK)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_MASK     (0x4000000U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_SHIFT    (26U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_MASK)
#define LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_MASK (0x8000000U)
#define LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_SHIFT (27U)
#define LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_MASK)
#define LCDIF_CTRL1_CLR_RSRVD1_MASK              (0xF0000000U)
#define LCDIF_CTRL1_CLR_RSRVD1_SHIFT             (28U)
#define LCDIF_CTRL1_CLR_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RSRVD1_SHIFT)) & LCDIF_CTRL1_CLR_RSRVD1_MASK)

/*! @name CTRL1_TOG - eLCDIF General Control1 Register */
#define LCDIF_CTRL1_TOG_RESET_MASK               (0x1U)
#define LCDIF_CTRL1_TOG_RESET_SHIFT              (0U)
#define LCDIF_CTRL1_TOG_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RESET_SHIFT)) & LCDIF_CTRL1_TOG_RESET_MASK)
#define LCDIF_CTRL1_TOG_MODE86_MASK              (0x2U)
#define LCDIF_CTRL1_TOG_MODE86_SHIFT             (1U)
#define LCDIF_CTRL1_TOG_MODE86(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_MODE86_SHIFT)) & LCDIF_CTRL1_TOG_MODE86_MASK)
#define LCDIF_CTRL1_TOG_BUSY_ENABLE_MASK         (0x4U)
#define LCDIF_CTRL1_TOG_BUSY_ENABLE_SHIFT        (2U)
#define LCDIF_CTRL1_TOG_BUSY_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_TOG_BUSY_ENABLE_MASK)
#define LCDIF_CTRL1_TOG_RSRVD0_MASK              (0xF8U)
#define LCDIF_CTRL1_TOG_RSRVD0_SHIFT             (3U)
#define LCDIF_CTRL1_TOG_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL1_TOG_RSRVD0_MASK)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_MASK      (0x100U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_SHIFT     (8U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_MASK)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_MASK  (0x200U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_SHIFT (9U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_MASK)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_MASK       (0x400U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_SHIFT      (10U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_MASK        (0x800U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_SHIFT       (11U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_OVERFLOW_IRQ_MASK)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_MASK   (0x1000U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_SHIFT  (12U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_MASK)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_MASK (0x2000U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_SHIFT (13U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_MASK)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_MASK    (0x4000U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_SHIFT   (14U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_MASK     (0x8000U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_SHIFT    (15U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_MASK)
#define LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_MASK (0xF0000U)
#define LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_SHIFT (16U)
#define LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_MASK)
#define LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_MASK)
#define LCDIF_CTRL1_TOG_FIFO_CLEAR_MASK          (0x200000U)
#define LCDIF_CTRL1_TOG_FIFO_CLEAR_SHIFT         (21U)
#define LCDIF_CTRL1_TOG_FIFO_CLEAR(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_TOG_FIFO_CLEAR_MASK)
#define LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_MASK)
#define LCDIF_CTRL1_TOG_INTERLACE_FIELDS_MASK    (0x800000U)
#define LCDIF_CTRL1_TOG_INTERLACE_FIELDS_SHIFT   (23U)
#define LCDIF_CTRL1_TOG_INTERLACE_FIELDS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_TOG_INTERLACE_FIELDS_MASK)
#define LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_MASK (0x1000000U)
#define LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_SHIFT (24U)
#define LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_MASK)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_MASK        (0x2000000U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_SHIFT       (25U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_BM_ERROR_IRQ_MASK)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_MASK     (0x4000000U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_SHIFT    (26U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_MASK)
#define LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_MASK (0x8000000U)
#define LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_SHIFT (27U)
#define LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_MASK)
#define LCDIF_CTRL1_TOG_RSRVD1_MASK              (0xF0000000U)
#define LCDIF_CTRL1_TOG_RSRVD1_SHIFT             (28U)
#define LCDIF_CTRL1_TOG_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RSRVD1_SHIFT)) & LCDIF_CTRL1_TOG_RSRVD1_MASK)

/*! @name CTRL2 - eLCDIF General Control2 Register */
#define LCDIF_CTRL2_RSRVD0_MASK                  (0x1U)
#define LCDIF_CTRL2_RSRVD0_SHIFT                 (0U)
#define LCDIF_CTRL2_RSRVD0(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD0_SHIFT)) & LCDIF_CTRL2_RSRVD0_MASK)
#define LCDIF_CTRL2_INITIAL_DUMMY_READ_MASK      (0xEU)
#define LCDIF_CTRL2_INITIAL_DUMMY_READ_SHIFT     (1U)
#define LCDIF_CTRL2_INITIAL_DUMMY_READ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_INITIAL_DUMMY_READ_MASK)
#define LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_MASK)
#define LCDIF_CTRL2_RSRVD1_MASK                  (0x80U)
#define LCDIF_CTRL2_RSRVD1_SHIFT                 (7U)
#define LCDIF_CTRL2_RSRVD1(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD1_SHIFT)) & LCDIF_CTRL2_RSRVD1_MASK)
#define LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_MASK   (0x100U)
#define LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_SHIFT  (8U)
#define LCDIF_CTRL2_READ_MODE_6_BIT_INPUT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_MASK)
#define LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)
#define LCDIF_CTRL2_READ_PACK_DIR_MASK           (0x400U)
#define LCDIF_CTRL2_READ_PACK_DIR_SHIFT          (10U)
#define LCDIF_CTRL2_READ_PACK_DIR(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_READ_PACK_DIR_MASK)
#define LCDIF_CTRL2_RSRVD2_MASK                  (0x800U)
#define LCDIF_CTRL2_RSRVD2_SHIFT                 (11U)
#define LCDIF_CTRL2_RSRVD2(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD2_SHIFT)) & LCDIF_CTRL2_RSRVD2_MASK)
#define LCDIF_CTRL2_EVEN_LINE_PATTERN_MASK       (0x7000U)
#define LCDIF_CTRL2_EVEN_LINE_PATTERN_SHIFT      (12U)
#define LCDIF_CTRL2_EVEN_LINE_PATTERN(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_EVEN_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_RSRVD3_MASK                  (0x8000U)
#define LCDIF_CTRL2_RSRVD3_SHIFT                 (15U)
#define LCDIF_CTRL2_RSRVD3(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD3_SHIFT)) & LCDIF_CTRL2_RSRVD3_MASK)
#define LCDIF_CTRL2_ODD_LINE_PATTERN_MASK        (0x70000U)
#define LCDIF_CTRL2_ODD_LINE_PATTERN_SHIFT       (16U)
#define LCDIF_CTRL2_ODD_LINE_PATTERN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_ODD_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_RSRVD4_MASK                  (0x80000U)
#define LCDIF_CTRL2_RSRVD4_SHIFT                 (19U)
#define LCDIF_CTRL2_RSRVD4(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD4_SHIFT)) & LCDIF_CTRL2_RSRVD4_MASK)
#define LCDIF_CTRL2_BURST_LEN_8_MASK             (0x100000U)
#define LCDIF_CTRL2_BURST_LEN_8_SHIFT            (20U)
#define LCDIF_CTRL2_BURST_LEN_8(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_BURST_LEN_8_MASK)
#define LCDIF_CTRL2_OUTSTANDING_REQS_MASK        (0xE00000U)
#define LCDIF_CTRL2_OUTSTANDING_REQS_SHIFT       (21U)
#define LCDIF_CTRL2_OUTSTANDING_REQS(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_OUTSTANDING_REQS_MASK)
#define LCDIF_CTRL2_RSRVD5_MASK                  (0xFF000000U)
#define LCDIF_CTRL2_RSRVD5_SHIFT                 (24U)
#define LCDIF_CTRL2_RSRVD5(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD5_SHIFT)) & LCDIF_CTRL2_RSRVD5_MASK)

/*! @name CTRL2_SET - eLCDIF General Control2 Register */
#define LCDIF_CTRL2_SET_RSRVD0_MASK              (0x1U)
#define LCDIF_CTRL2_SET_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_SET_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD0_SHIFT)) & LCDIF_CTRL2_SET_RSRVD0_MASK)
#define LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_MASK  (0xEU)
#define LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_SHIFT (1U)
#define LCDIF_CTRL2_SET_INITIAL_DUMMY_READ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_MASK)
#define LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_MASK)
#define LCDIF_CTRL2_SET_RSRVD1_MASK              (0x80U)
#define LCDIF_CTRL2_SET_RSRVD1_SHIFT             (7U)
#define LCDIF_CTRL2_SET_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD1_SHIFT)) & LCDIF_CTRL2_SET_RSRVD1_MASK)
#define LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_MASK (0x100U)
#define LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_SHIFT (8U)
#define LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_MASK)
#define LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)
#define LCDIF_CTRL2_SET_READ_PACK_DIR_MASK       (0x400U)
#define LCDIF_CTRL2_SET_READ_PACK_DIR_SHIFT      (10U)
#define LCDIF_CTRL2_SET_READ_PACK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_SET_READ_PACK_DIR_MASK)
#define LCDIF_CTRL2_SET_RSRVD2_MASK              (0x800U)
#define LCDIF_CTRL2_SET_RSRVD2_SHIFT             (11U)
#define LCDIF_CTRL2_SET_RSRVD2(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD2_SHIFT)) & LCDIF_CTRL2_SET_RSRVD2_MASK)
#define LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_MASK   (0x7000U)
#define LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_SHIFT  (12U)
#define LCDIF_CTRL2_SET_EVEN_LINE_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_SET_RSRVD3_MASK              (0x8000U)
#define LCDIF_CTRL2_SET_RSRVD3_SHIFT             (15U)
#define LCDIF_CTRL2_SET_RSRVD3(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD3_SHIFT)) & LCDIF_CTRL2_SET_RSRVD3_MASK)
#define LCDIF_CTRL2_SET_ODD_LINE_PATTERN_MASK    (0x70000U)
#define LCDIF_CTRL2_SET_ODD_LINE_PATTERN_SHIFT   (16U)
#define LCDIF_CTRL2_SET_ODD_LINE_PATTERN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_SET_ODD_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_SET_RSRVD4_MASK              (0x80000U)
#define LCDIF_CTRL2_SET_RSRVD4_SHIFT             (19U)
#define LCDIF_CTRL2_SET_RSRVD4(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD4_SHIFT)) & LCDIF_CTRL2_SET_RSRVD4_MASK)
#define LCDIF_CTRL2_SET_BURST_LEN_8_MASK         (0x100000U)
#define LCDIF_CTRL2_SET_BURST_LEN_8_SHIFT        (20U)
#define LCDIF_CTRL2_SET_BURST_LEN_8(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_SET_BURST_LEN_8_MASK)
#define LCDIF_CTRL2_SET_OUTSTANDING_REQS_MASK    (0xE00000U)
#define LCDIF_CTRL2_SET_OUTSTANDING_REQS_SHIFT   (21U)
#define LCDIF_CTRL2_SET_OUTSTANDING_REQS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_SET_OUTSTANDING_REQS_MASK)
#define LCDIF_CTRL2_SET_RSRVD5_MASK              (0xFF000000U)
#define LCDIF_CTRL2_SET_RSRVD5_SHIFT             (24U)
#define LCDIF_CTRL2_SET_RSRVD5(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD5_SHIFT)) & LCDIF_CTRL2_SET_RSRVD5_MASK)

/*! @name CTRL2_CLR - eLCDIF General Control2 Register */
#define LCDIF_CTRL2_CLR_RSRVD0_MASK              (0x1U)
#define LCDIF_CTRL2_CLR_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_CLR_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD0_MASK)
#define LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_MASK  (0xEU)
#define LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_SHIFT (1U)
#define LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_MASK)
#define LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_MASK)
#define LCDIF_CTRL2_CLR_RSRVD1_MASK              (0x80U)
#define LCDIF_CTRL2_CLR_RSRVD1_SHIFT             (7U)
#define LCDIF_CTRL2_CLR_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD1_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD1_MASK)
#define LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_MASK (0x100U)
#define LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_SHIFT (8U)
#define LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_MASK)
#define LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)
#define LCDIF_CTRL2_CLR_READ_PACK_DIR_MASK       (0x400U)
#define LCDIF_CTRL2_CLR_READ_PACK_DIR_SHIFT      (10U)
#define LCDIF_CTRL2_CLR_READ_PACK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_CLR_READ_PACK_DIR_MASK)
#define LCDIF_CTRL2_CLR_RSRVD2_MASK              (0x800U)
#define LCDIF_CTRL2_CLR_RSRVD2_SHIFT             (11U)
#define LCDIF_CTRL2_CLR_RSRVD2(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD2_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD2_MASK)
#define LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_MASK   (0x7000U)
#define LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_SHIFT  (12U)
#define LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_CLR_RSRVD3_MASK              (0x8000U)
#define LCDIF_CTRL2_CLR_RSRVD3_SHIFT             (15U)
#define LCDIF_CTRL2_CLR_RSRVD3(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD3_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD3_MASK)
#define LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_MASK    (0x70000U)
#define LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_SHIFT   (16U)
#define LCDIF_CTRL2_CLR_ODD_LINE_PATTERN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_CLR_RSRVD4_MASK              (0x80000U)
#define LCDIF_CTRL2_CLR_RSRVD4_SHIFT             (19U)
#define LCDIF_CTRL2_CLR_RSRVD4(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD4_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD4_MASK)
#define LCDIF_CTRL2_CLR_BURST_LEN_8_MASK         (0x100000U)
#define LCDIF_CTRL2_CLR_BURST_LEN_8_SHIFT        (20U)
#define LCDIF_CTRL2_CLR_BURST_LEN_8(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_CLR_BURST_LEN_8_MASK)
#define LCDIF_CTRL2_CLR_OUTSTANDING_REQS_MASK    (0xE00000U)
#define LCDIF_CTRL2_CLR_OUTSTANDING_REQS_SHIFT   (21U)
#define LCDIF_CTRL2_CLR_OUTSTANDING_REQS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_CLR_OUTSTANDING_REQS_MASK)
#define LCDIF_CTRL2_CLR_RSRVD5_MASK              (0xFF000000U)
#define LCDIF_CTRL2_CLR_RSRVD5_SHIFT             (24U)
#define LCDIF_CTRL2_CLR_RSRVD5(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD5_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD5_MASK)

/*! @name CTRL2_TOG - eLCDIF General Control2 Register */
#define LCDIF_CTRL2_TOG_RSRVD0_MASK              (0x1U)
#define LCDIF_CTRL2_TOG_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_TOG_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD0_MASK)
#define LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_MASK  (0xEU)
#define LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_SHIFT (1U)
#define LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_MASK)
#define LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_MASK)
#define LCDIF_CTRL2_TOG_RSRVD1_MASK              (0x80U)
#define LCDIF_CTRL2_TOG_RSRVD1_SHIFT             (7U)
#define LCDIF_CTRL2_TOG_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD1_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD1_MASK)
#define LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_MASK (0x100U)
#define LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_SHIFT (8U)
#define LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_MASK)
#define LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)
#define LCDIF_CTRL2_TOG_READ_PACK_DIR_MASK       (0x400U)
#define LCDIF_CTRL2_TOG_READ_PACK_DIR_SHIFT      (10U)
#define LCDIF_CTRL2_TOG_READ_PACK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_TOG_READ_PACK_DIR_MASK)
#define LCDIF_CTRL2_TOG_RSRVD2_MASK              (0x800U)
#define LCDIF_CTRL2_TOG_RSRVD2_SHIFT             (11U)
#define LCDIF_CTRL2_TOG_RSRVD2(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD2_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD2_MASK)
#define LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_MASK   (0x7000U)
#define LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_SHIFT  (12U)
#define LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_TOG_RSRVD3_MASK              (0x8000U)
#define LCDIF_CTRL2_TOG_RSRVD3_SHIFT             (15U)
#define LCDIF_CTRL2_TOG_RSRVD3(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD3_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD3_MASK)
#define LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_MASK    (0x70000U)
#define LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_SHIFT   (16U)
#define LCDIF_CTRL2_TOG_ODD_LINE_PATTERN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_MASK)
#define LCDIF_CTRL2_TOG_RSRVD4_MASK              (0x80000U)
#define LCDIF_CTRL2_TOG_RSRVD4_SHIFT             (19U)
#define LCDIF_CTRL2_TOG_RSRVD4(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD4_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD4_MASK)
#define LCDIF_CTRL2_TOG_BURST_LEN_8_MASK         (0x100000U)
#define LCDIF_CTRL2_TOG_BURST_LEN_8_SHIFT        (20U)
#define LCDIF_CTRL2_TOG_BURST_LEN_8(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_TOG_BURST_LEN_8_MASK)
#define LCDIF_CTRL2_TOG_OUTSTANDING_REQS_MASK    (0xE00000U)
#define LCDIF_CTRL2_TOG_OUTSTANDING_REQS_SHIFT   (21U)
#define LCDIF_CTRL2_TOG_OUTSTANDING_REQS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_TOG_OUTSTANDING_REQS_MASK)
#define LCDIF_CTRL2_TOG_RSRVD5_MASK              (0xFF000000U)
#define LCDIF_CTRL2_TOG_RSRVD5_SHIFT             (24U)
#define LCDIF_CTRL2_TOG_RSRVD5(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD5_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD5_MASK)

/*! @name TRANSFER_COUNT - eLCDIF Horizontal and Vertical Valid Data Count Register */
#define LCDIF_TRANSFER_COUNT_H_COUNT_MASK        (0xFFFFU)
#define LCDIF_TRANSFER_COUNT_H_COUNT_SHIFT       (0U)
#define LCDIF_TRANSFER_COUNT_H_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_TRANSFER_COUNT_H_COUNT_SHIFT)) & LCDIF_TRANSFER_COUNT_H_COUNT_MASK)
#define LCDIF_TRANSFER_COUNT_V_COUNT_MASK        (0xFFFF0000U)
#define LCDIF_TRANSFER_COUNT_V_COUNT_SHIFT       (16U)
#define LCDIF_TRANSFER_COUNT_V_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_TRANSFER_COUNT_V_COUNT_SHIFT)) & LCDIF_TRANSFER_COUNT_V_COUNT_MASK)

/*! @name CUR_BUF - LCD Interface Current Buffer Address Register */
#define LCDIF_CUR_BUF_ADDR_MASK                  (0xFFFFFFFFU)
#define LCDIF_CUR_BUF_ADDR_SHIFT                 (0U)
#define LCDIF_CUR_BUF_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CUR_BUF_ADDR_SHIFT)) & LCDIF_CUR_BUF_ADDR_MASK)

/*! @name NEXT_BUF - LCD Interface Next Buffer Address Register */
#define LCDIF_NEXT_BUF_ADDR_MASK                 (0xFFFFFFFFU)
#define LCDIF_NEXT_BUF_ADDR_SHIFT                (0U)
#define LCDIF_NEXT_BUF_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_NEXT_BUF_ADDR_SHIFT)) & LCDIF_NEXT_BUF_ADDR_MASK)

/*! @name TIMING - LCD Interface Timing Register */
#define LCDIF_TIMING_DATA_SETUP_MASK             (0xFFU)
#define LCDIF_TIMING_DATA_SETUP_SHIFT            (0U)
#define LCDIF_TIMING_DATA_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_DATA_SETUP_SHIFT)) & LCDIF_TIMING_DATA_SETUP_MASK)
#define LCDIF_TIMING_DATA_HOLD_MASK              (0xFF00U)
#define LCDIF_TIMING_DATA_HOLD_SHIFT             (8U)
#define LCDIF_TIMING_DATA_HOLD(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_DATA_HOLD_SHIFT)) & LCDIF_TIMING_DATA_HOLD_MASK)
#define LCDIF_TIMING_CMD_SETUP_MASK              (0xFF0000U)
#define LCDIF_TIMING_CMD_SETUP_SHIFT             (16U)
#define LCDIF_TIMING_CMD_SETUP(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_CMD_SETUP_SHIFT)) & LCDIF_TIMING_CMD_SETUP_MASK)
#define LCDIF_TIMING_CMD_HOLD_MASK               (0xFF000000U)
#define LCDIF_TIMING_CMD_HOLD_SHIFT              (24U)
#define LCDIF_TIMING_CMD_HOLD(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_CMD_HOLD_SHIFT)) & LCDIF_TIMING_CMD_HOLD_MASK)

/*! @name VDCTRL0 - eLCDIF VSYNC Mode and Dotclk Mode Control Register0 */
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_MASK     (0x3FFFFU)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_SHIFT    (0U)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_MASK)
#define LCDIF_VDCTRL0_HALF_LINE_MODE_MASK        (0x40000U)
#define LCDIF_VDCTRL0_HALF_LINE_MODE_SHIFT       (18U)
#define LCDIF_VDCTRL0_HALF_LINE_MODE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_HALF_LINE_MODE_MASK)
#define LCDIF_VDCTRL0_HALF_LINE_MASK             (0x80000U)
#define LCDIF_VDCTRL0_HALF_LINE_SHIFT            (19U)
#define LCDIF_VDCTRL0_HALF_LINE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_HALF_LINE_MASK)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_MASK)
#define LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_MASK     (0x200000U)
#define LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_SHIFT    (21U)
#define LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_MASK)
#define LCDIF_VDCTRL0_RSRVD1_MASK                (0xC00000U)
#define LCDIF_VDCTRL0_RSRVD1_SHIFT               (22U)
#define LCDIF_VDCTRL0_RSRVD1(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_RSRVD1_MASK)
#define LCDIF_VDCTRL0_ENABLE_POL_MASK            (0x1000000U)
#define LCDIF_VDCTRL0_ENABLE_POL_SHIFT           (24U)
#define LCDIF_VDCTRL0_ENABLE_POL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_ENABLE_POL_MASK)
#define LCDIF_VDCTRL0_DOTCLK_POL_MASK            (0x2000000U)
#define LCDIF_VDCTRL0_DOTCLK_POL_SHIFT           (25U)
#define LCDIF_VDCTRL0_DOTCLK_POL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_DOTCLK_POL_MASK)
#define LCDIF_VDCTRL0_HSYNC_POL_MASK             (0x4000000U)
#define LCDIF_VDCTRL0_HSYNC_POL_SHIFT            (26U)
#define LCDIF_VDCTRL0_HSYNC_POL(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_HSYNC_POL_MASK)
#define LCDIF_VDCTRL0_VSYNC_POL_MASK             (0x8000000U)
#define LCDIF_VDCTRL0_VSYNC_POL_SHIFT            (27U)
#define LCDIF_VDCTRL0_VSYNC_POL(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_VSYNC_POL_MASK)
#define LCDIF_VDCTRL0_ENABLE_PRESENT_MASK        (0x10000000U)
#define LCDIF_VDCTRL0_ENABLE_PRESENT_SHIFT       (28U)
#define LCDIF_VDCTRL0_ENABLE_PRESENT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_ENABLE_PRESENT_MASK)
#define LCDIF_VDCTRL0_VSYNC_OEB_MASK             (0x20000000U)
#define LCDIF_VDCTRL0_VSYNC_OEB_SHIFT            (29U)
#define LCDIF_VDCTRL0_VSYNC_OEB(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_VSYNC_OEB_MASK)
#define LCDIF_VDCTRL0_RSRVD2_MASK                (0xC0000000U)
#define LCDIF_VDCTRL0_RSRVD2_SHIFT               (30U)
#define LCDIF_VDCTRL0_RSRVD2(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_RSRVD2_MASK)

/*! @name VDCTRL0_SET - eLCDIF VSYNC Mode and Dotclk Mode Control Register0 */
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_MASK (0x3FFFFU)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_SHIFT (0U)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_MASK)
#define LCDIF_VDCTRL0_SET_HALF_LINE_MODE_MASK    (0x40000U)
#define LCDIF_VDCTRL0_SET_HALF_LINE_MODE_SHIFT   (18U)
#define LCDIF_VDCTRL0_SET_HALF_LINE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_SET_HALF_LINE_MODE_MASK)
#define LCDIF_VDCTRL0_SET_HALF_LINE_MASK         (0x80000U)
#define LCDIF_VDCTRL0_SET_HALF_LINE_SHIFT        (19U)
#define LCDIF_VDCTRL0_SET_HALF_LINE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_SET_HALF_LINE_MASK)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_MASK)
#define LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_MASK (0x200000U)
#define LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_SHIFT (21U)
#define LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_MASK)
#define LCDIF_VDCTRL0_SET_RSRVD1_MASK            (0xC00000U)
#define LCDIF_VDCTRL0_SET_RSRVD1_SHIFT           (22U)
#define LCDIF_VDCTRL0_SET_RSRVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_SET_RSRVD1_MASK)
#define LCDIF_VDCTRL0_SET_ENABLE_POL_MASK        (0x1000000U)
#define LCDIF_VDCTRL0_SET_ENABLE_POL_SHIFT       (24U)
#define LCDIF_VDCTRL0_SET_ENABLE_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_SET_ENABLE_POL_MASK)
#define LCDIF_VDCTRL0_SET_DOTCLK_POL_MASK        (0x2000000U)
#define LCDIF_VDCTRL0_SET_DOTCLK_POL_SHIFT       (25U)
#define LCDIF_VDCTRL0_SET_DOTCLK_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_SET_DOTCLK_POL_MASK)
#define LCDIF_VDCTRL0_SET_HSYNC_POL_MASK         (0x4000000U)
#define LCDIF_VDCTRL0_SET_HSYNC_POL_SHIFT        (26U)
#define LCDIF_VDCTRL0_SET_HSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_SET_HSYNC_POL_MASK)
#define LCDIF_VDCTRL0_SET_VSYNC_POL_MASK         (0x8000000U)
#define LCDIF_VDCTRL0_SET_VSYNC_POL_SHIFT        (27U)
#define LCDIF_VDCTRL0_SET_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_POL_MASK)
#define LCDIF_VDCTRL0_SET_ENABLE_PRESENT_MASK    (0x10000000U)
#define LCDIF_VDCTRL0_SET_ENABLE_PRESENT_SHIFT   (28U)
#define LCDIF_VDCTRL0_SET_ENABLE_PRESENT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_SET_ENABLE_PRESENT_MASK)
#define LCDIF_VDCTRL0_SET_VSYNC_OEB_MASK         (0x20000000U)
#define LCDIF_VDCTRL0_SET_VSYNC_OEB_SHIFT        (29U)
#define LCDIF_VDCTRL0_SET_VSYNC_OEB(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_OEB_MASK)
#define LCDIF_VDCTRL0_SET_RSRVD2_MASK            (0xC0000000U)
#define LCDIF_VDCTRL0_SET_RSRVD2_SHIFT           (30U)
#define LCDIF_VDCTRL0_SET_RSRVD2(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_SET_RSRVD2_MASK)

/*! @name VDCTRL0_CLR - eLCDIF VSYNC Mode and Dotclk Mode Control Register0 */
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_MASK (0x3FFFFU)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_SHIFT (0U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_MASK)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_MASK    (0x40000U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_SHIFT   (18U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_MASK)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_MASK         (0x80000U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_SHIFT        (19U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_CLR_HALF_LINE_MASK)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_MASK)
#define LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_MASK (0x200000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_SHIFT (21U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_MASK)
#define LCDIF_VDCTRL0_CLR_RSRVD1_MASK            (0xC00000U)
#define LCDIF_VDCTRL0_CLR_RSRVD1_SHIFT           (22U)
#define LCDIF_VDCTRL0_CLR_RSRVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_CLR_RSRVD1_MASK)
#define LCDIF_VDCTRL0_CLR_ENABLE_POL_MASK        (0x1000000U)
#define LCDIF_VDCTRL0_CLR_ENABLE_POL_SHIFT       (24U)
#define LCDIF_VDCTRL0_CLR_ENABLE_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_ENABLE_POL_MASK)
#define LCDIF_VDCTRL0_CLR_DOTCLK_POL_MASK        (0x2000000U)
#define LCDIF_VDCTRL0_CLR_DOTCLK_POL_SHIFT       (25U)
#define LCDIF_VDCTRL0_CLR_DOTCLK_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_DOTCLK_POL_MASK)
#define LCDIF_VDCTRL0_CLR_HSYNC_POL_MASK         (0x4000000U)
#define LCDIF_VDCTRL0_CLR_HSYNC_POL_SHIFT        (26U)
#define LCDIF_VDCTRL0_CLR_HSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_HSYNC_POL_MASK)
#define LCDIF_VDCTRL0_CLR_VSYNC_POL_MASK         (0x8000000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_POL_SHIFT        (27U)
#define LCDIF_VDCTRL0_CLR_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_POL_MASK)
#define LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_MASK    (0x10000000U)
#define LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_SHIFT   (28U)
#define LCDIF_VDCTRL0_CLR_ENABLE_PRESENT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_MASK)
#define LCDIF_VDCTRL0_CLR_VSYNC_OEB_MASK         (0x20000000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_OEB_SHIFT        (29U)
#define LCDIF_VDCTRL0_CLR_VSYNC_OEB(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_OEB_MASK)
#define LCDIF_VDCTRL0_CLR_RSRVD2_MASK            (0xC0000000U)
#define LCDIF_VDCTRL0_CLR_RSRVD2_SHIFT           (30U)
#define LCDIF_VDCTRL0_CLR_RSRVD2(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_CLR_RSRVD2_MASK)

/*! @name VDCTRL0_TOG - eLCDIF VSYNC Mode and Dotclk Mode Control Register0 */
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_MASK (0x3FFFFU)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_SHIFT (0U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_MASK)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_MASK    (0x40000U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_SHIFT   (18U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_MASK)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_MASK         (0x80000U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_SHIFT        (19U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_TOG_HALF_LINE_MASK)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_MASK)
#define LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_MASK (0x200000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_SHIFT (21U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_MASK)
#define LCDIF_VDCTRL0_TOG_RSRVD1_MASK            (0xC00000U)
#define LCDIF_VDCTRL0_TOG_RSRVD1_SHIFT           (22U)
#define LCDIF_VDCTRL0_TOG_RSRVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_TOG_RSRVD1_MASK)
#define LCDIF_VDCTRL0_TOG_ENABLE_POL_MASK        (0x1000000U)
#define LCDIF_VDCTRL0_TOG_ENABLE_POL_SHIFT       (24U)
#define LCDIF_VDCTRL0_TOG_ENABLE_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_ENABLE_POL_MASK)
#define LCDIF_VDCTRL0_TOG_DOTCLK_POL_MASK        (0x2000000U)
#define LCDIF_VDCTRL0_TOG_DOTCLK_POL_SHIFT       (25U)
#define LCDIF_VDCTRL0_TOG_DOTCLK_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_DOTCLK_POL_MASK)
#define LCDIF_VDCTRL0_TOG_HSYNC_POL_MASK         (0x4000000U)
#define LCDIF_VDCTRL0_TOG_HSYNC_POL_SHIFT        (26U)
#define LCDIF_VDCTRL0_TOG_HSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_HSYNC_POL_MASK)
#define LCDIF_VDCTRL0_TOG_VSYNC_POL_MASK         (0x8000000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_POL_SHIFT        (27U)
#define LCDIF_VDCTRL0_TOG_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_POL_MASK)
#define LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_MASK    (0x10000000U)
#define LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_SHIFT   (28U)
#define LCDIF_VDCTRL0_TOG_ENABLE_PRESENT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_MASK)
#define LCDIF_VDCTRL0_TOG_VSYNC_OEB_MASK         (0x20000000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_OEB_SHIFT        (29U)
#define LCDIF_VDCTRL0_TOG_VSYNC_OEB(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_OEB_MASK)
#define LCDIF_VDCTRL0_TOG_RSRVD2_MASK            (0xC0000000U)
#define LCDIF_VDCTRL0_TOG_RSRVD2_SHIFT           (30U)
#define LCDIF_VDCTRL0_TOG_RSRVD2(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_TOG_RSRVD2_MASK)

/*! @name VDCTRL1 - eLCDIF VSYNC Mode and Dotclk Mode Control Register1 */
#define LCDIF_VDCTRL1_VSYNC_PERIOD_MASK          (0xFFFFFFFFU)
#define LCDIF_VDCTRL1_VSYNC_PERIOD_SHIFT         (0U)
#define LCDIF_VDCTRL1_VSYNC_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL1_VSYNC_PERIOD_SHIFT)) & LCDIF_VDCTRL1_VSYNC_PERIOD_MASK)

/*! @name VDCTRL2 - LCDIF VSYNC Mode and Dotclk Mode Control Register2 */
#define LCDIF_VDCTRL2_HSYNC_PERIOD_MASK          (0x3FFFFU)
#define LCDIF_VDCTRL2_HSYNC_PERIOD_SHIFT         (0U)
#define LCDIF_VDCTRL2_HSYNC_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL2_HSYNC_PERIOD_SHIFT)) & LCDIF_VDCTRL2_HSYNC_PERIOD_MASK)
#define LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_MASK     (0xFFFC0000U)
#define LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_SHIFT    (18U)
#define LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_MASK)

/*! @name VDCTRL3 - eLCDIF VSYNC Mode and Dotclk Mode Control Register3 */
#define LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_MASK     (0xFFFFU)
#define LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_SHIFT    (0U)
#define LCDIF_VDCTRL3_VERTICAL_WAIT_CNT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_SHIFT)) & LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_MASK)
#define LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_MASK   (0xFFF0000U)
#define LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_SHIFT  (16U)
#define LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_SHIFT)) & LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_MASK)
#define LCDIF_VDCTRL3_VSYNC_ONLY_MASK            (0x10000000U)
#define LCDIF_VDCTRL3_VSYNC_ONLY_SHIFT           (28U)
#define LCDIF_VDCTRL3_VSYNC_ONLY(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_VSYNC_ONLY_SHIFT)) & LCDIF_VDCTRL3_VSYNC_ONLY_MASK)
#define LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_MASK      (0x20000000U)
#define LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_SHIFT     (29U)
#define LCDIF_VDCTRL3_MUX_SYNC_SIGNALS(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_SHIFT)) & LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_MASK)
#define LCDIF_VDCTRL3_RSRVD0_MASK                (0xC0000000U)
#define LCDIF_VDCTRL3_RSRVD0_SHIFT               (30U)
#define LCDIF_VDCTRL3_RSRVD0(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_RSRVD0_SHIFT)) & LCDIF_VDCTRL3_RSRVD0_MASK)

/*! @name VDCTRL4 - eLCDIF VSYNC Mode and Dotclk Mode Control Register4 */
#define LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_MASK (0x3FFFFU)
#define LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_SHIFT (0U)
#define LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_SHIFT)) & LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_MASK)
#define LCDIF_VDCTRL4_SYNC_SIGNALS_ON_MASK       (0x40000U)
#define LCDIF_VDCTRL4_SYNC_SIGNALS_ON_SHIFT      (18U)
#define LCDIF_VDCTRL4_SYNC_SIGNALS_ON(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_SYNC_SIGNALS_ON_SHIFT)) & LCDIF_VDCTRL4_SYNC_SIGNALS_ON_MASK)
#define LCDIF_VDCTRL4_RSRVD0_MASK                (0x1FF80000U)
#define LCDIF_VDCTRL4_RSRVD0_SHIFT               (19U)
#define LCDIF_VDCTRL4_RSRVD0(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_RSRVD0_SHIFT)) & LCDIF_VDCTRL4_RSRVD0_MASK)
#define LCDIF_VDCTRL4_DOTCLK_DLY_SEL_MASK        (0xE0000000U)
#define LCDIF_VDCTRL4_DOTCLK_DLY_SEL_SHIFT       (29U)
#define LCDIF_VDCTRL4_DOTCLK_DLY_SEL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_DOTCLK_DLY_SEL_SHIFT)) & LCDIF_VDCTRL4_DOTCLK_DLY_SEL_MASK)

/*! @name DVICTRL0 - Digital Video Interface Control0 Register */
#define LCDIF_DVICTRL0_H_BLANKING_CNT_MASK       (0xFFFU)
#define LCDIF_DVICTRL0_H_BLANKING_CNT_SHIFT      (0U)
#define LCDIF_DVICTRL0_H_BLANKING_CNT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_H_BLANKING_CNT_SHIFT)) & LCDIF_DVICTRL0_H_BLANKING_CNT_MASK)
#define LCDIF_DVICTRL0_RSRVD0_MASK               (0xF000U)
#define LCDIF_DVICTRL0_RSRVD0_SHIFT              (12U)
#define LCDIF_DVICTRL0_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_RSRVD0_SHIFT)) & LCDIF_DVICTRL0_RSRVD0_MASK)
#define LCDIF_DVICTRL0_H_ACTIVE_CNT_MASK         (0xFFF0000U)
#define LCDIF_DVICTRL0_H_ACTIVE_CNT_SHIFT        (16U)
#define LCDIF_DVICTRL0_H_ACTIVE_CNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_H_ACTIVE_CNT_SHIFT)) & LCDIF_DVICTRL0_H_ACTIVE_CNT_MASK)
#define LCDIF_DVICTRL0_RSRVD1_MASK               (0xF0000000U)
#define LCDIF_DVICTRL0_RSRVD1_SHIFT              (28U)
#define LCDIF_DVICTRL0_RSRVD1(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_RSRVD1_SHIFT)) & LCDIF_DVICTRL0_RSRVD1_MASK)

/*! @name DVICTRL1 - Digital Video Interface Control1 Register */
#define LCDIF_DVICTRL1_F2_START_LINE_MASK        (0x3FFU)
#define LCDIF_DVICTRL1_F2_START_LINE_SHIFT       (0U)
#define LCDIF_DVICTRL1_F2_START_LINE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_F2_START_LINE_SHIFT)) & LCDIF_DVICTRL1_F2_START_LINE_MASK)
#define LCDIF_DVICTRL1_F1_END_LINE_MASK          (0xFFC00U)
#define LCDIF_DVICTRL1_F1_END_LINE_SHIFT         (10U)
#define LCDIF_DVICTRL1_F1_END_LINE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_F1_END_LINE_SHIFT)) & LCDIF_DVICTRL1_F1_END_LINE_MASK)
#define LCDIF_DVICTRL1_F1_START_LINE_MASK        (0x3FF00000U)
#define LCDIF_DVICTRL1_F1_START_LINE_SHIFT       (20U)
#define LCDIF_DVICTRL1_F1_START_LINE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_F1_START_LINE_SHIFT)) & LCDIF_DVICTRL1_F1_START_LINE_MASK)
#define LCDIF_DVICTRL1_RSRVD0_MASK               (0xC0000000U)
#define LCDIF_DVICTRL1_RSRVD0_SHIFT              (30U)
#define LCDIF_DVICTRL1_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_RSRVD0_SHIFT)) & LCDIF_DVICTRL1_RSRVD0_MASK)

/*! @name DVICTRL2 - Digital Video Interface Control2 Register */
#define LCDIF_DVICTRL2_V1_BLANK_END_LINE_MASK    (0x3FFU)
#define LCDIF_DVICTRL2_V1_BLANK_END_LINE_SHIFT   (0U)
#define LCDIF_DVICTRL2_V1_BLANK_END_LINE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_V1_BLANK_END_LINE_SHIFT)) & LCDIF_DVICTRL2_V1_BLANK_END_LINE_MASK)
#define LCDIF_DVICTRL2_V1_BLANK_START_LINE_MASK  (0xFFC00U)
#define LCDIF_DVICTRL2_V1_BLANK_START_LINE_SHIFT (10U)
#define LCDIF_DVICTRL2_V1_BLANK_START_LINE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_V1_BLANK_START_LINE_SHIFT)) & LCDIF_DVICTRL2_V1_BLANK_START_LINE_MASK)
#define LCDIF_DVICTRL2_F2_END_LINE_MASK          (0x3FF00000U)
#define LCDIF_DVICTRL2_F2_END_LINE_SHIFT         (20U)
#define LCDIF_DVICTRL2_F2_END_LINE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_F2_END_LINE_SHIFT)) & LCDIF_DVICTRL2_F2_END_LINE_MASK)
#define LCDIF_DVICTRL2_RSRVD0_MASK               (0xC0000000U)
#define LCDIF_DVICTRL2_RSRVD0_SHIFT              (30U)
#define LCDIF_DVICTRL2_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_RSRVD0_SHIFT)) & LCDIF_DVICTRL2_RSRVD0_MASK)

/*! @name DVICTRL3 - Digital Video Interface Control3 Register */
#define LCDIF_DVICTRL3_V_LINES_CNT_MASK          (0x3FFU)
#define LCDIF_DVICTRL3_V_LINES_CNT_SHIFT         (0U)
#define LCDIF_DVICTRL3_V_LINES_CNT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_V_LINES_CNT_SHIFT)) & LCDIF_DVICTRL3_V_LINES_CNT_MASK)
#define LCDIF_DVICTRL3_V2_BLANK_END_LINE_MASK    (0xFFC00U)
#define LCDIF_DVICTRL3_V2_BLANK_END_LINE_SHIFT   (10U)
#define LCDIF_DVICTRL3_V2_BLANK_END_LINE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_V2_BLANK_END_LINE_SHIFT)) & LCDIF_DVICTRL3_V2_BLANK_END_LINE_MASK)
#define LCDIF_DVICTRL3_V2_BLANK_START_LINE_MASK  (0x3FF00000U)
#define LCDIF_DVICTRL3_V2_BLANK_START_LINE_SHIFT (20U)
#define LCDIF_DVICTRL3_V2_BLANK_START_LINE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_V2_BLANK_START_LINE_SHIFT)) & LCDIF_DVICTRL3_V2_BLANK_START_LINE_MASK)
#define LCDIF_DVICTRL3_RSRVD0_MASK               (0xC0000000U)
#define LCDIF_DVICTRL3_RSRVD0_SHIFT              (30U)
#define LCDIF_DVICTRL3_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_RSRVD0_SHIFT)) & LCDIF_DVICTRL3_RSRVD0_MASK)

/*! @name DVICTRL4 - Digital Video Interface Control4 Register */
#define LCDIF_DVICTRL4_H_FILL_CNT_MASK           (0xFFU)
#define LCDIF_DVICTRL4_H_FILL_CNT_SHIFT          (0U)
#define LCDIF_DVICTRL4_H_FILL_CNT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_H_FILL_CNT_SHIFT)) & LCDIF_DVICTRL4_H_FILL_CNT_MASK)
#define LCDIF_DVICTRL4_CR_FILL_VALUE_MASK        (0xFF00U)
#define LCDIF_DVICTRL4_CR_FILL_VALUE_SHIFT       (8U)
#define LCDIF_DVICTRL4_CR_FILL_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_CR_FILL_VALUE_SHIFT)) & LCDIF_DVICTRL4_CR_FILL_VALUE_MASK)
#define LCDIF_DVICTRL4_CB_FILL_VALUE_MASK        (0xFF0000U)
#define LCDIF_DVICTRL4_CB_FILL_VALUE_SHIFT       (16U)
#define LCDIF_DVICTRL4_CB_FILL_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_CB_FILL_VALUE_SHIFT)) & LCDIF_DVICTRL4_CB_FILL_VALUE_MASK)
#define LCDIF_DVICTRL4_Y_FILL_VALUE_MASK         (0xFF000000U)
#define LCDIF_DVICTRL4_Y_FILL_VALUE_SHIFT        (24U)
#define LCDIF_DVICTRL4_Y_FILL_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_Y_FILL_VALUE_SHIFT)) & LCDIF_DVICTRL4_Y_FILL_VALUE_MASK)

/*! @name CSC_COEFF0 - RGB to YCbCr 4:2:2 CSC Coefficient0 Register */
#define LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_MASK (0x3U)
#define LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_SHIFT (0U)
#define LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_SHIFT)) & LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_MASK)
#define LCDIF_CSC_COEFF0_RSRVD0_MASK             (0xFFFCU)
#define LCDIF_CSC_COEFF0_RSRVD0_SHIFT            (2U)
#define LCDIF_CSC_COEFF0_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF0_RSRVD0_MASK)
#define LCDIF_CSC_COEFF0_C0_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF0_C0_SHIFT                (16U)
#define LCDIF_CSC_COEFF0_C0(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_C0_SHIFT)) & LCDIF_CSC_COEFF0_C0_MASK)
#define LCDIF_CSC_COEFF0_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF0_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF0_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF0_RSRVD1_MASK)

/*! @name CSC_COEFF1 - RGB to YCbCr 4:2:2 CSC Coefficient1 Register */
#define LCDIF_CSC_COEFF1_C1_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF1_C1_SHIFT                (0U)
#define LCDIF_CSC_COEFF1_C1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_C1_SHIFT)) & LCDIF_CSC_COEFF1_C1_MASK)
#define LCDIF_CSC_COEFF1_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF1_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF1_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF1_RSRVD0_MASK)
#define LCDIF_CSC_COEFF1_C2_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF1_C2_SHIFT                (16U)
#define LCDIF_CSC_COEFF1_C2(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_C2_SHIFT)) & LCDIF_CSC_COEFF1_C2_MASK)
#define LCDIF_CSC_COEFF1_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF1_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF1_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF1_RSRVD1_MASK)

/*! @name CSC_COEFF2 - RGB to YCbCr 4:2:2 CSC Coefficent2 Register */
#define LCDIF_CSC_COEFF2_C3_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF2_C3_SHIFT                (0U)
#define LCDIF_CSC_COEFF2_C3(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_C3_SHIFT)) & LCDIF_CSC_COEFF2_C3_MASK)
#define LCDIF_CSC_COEFF2_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF2_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF2_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF2_RSRVD0_MASK)
#define LCDIF_CSC_COEFF2_C4_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF2_C4_SHIFT                (16U)
#define LCDIF_CSC_COEFF2_C4(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_C4_SHIFT)) & LCDIF_CSC_COEFF2_C4_MASK)
#define LCDIF_CSC_COEFF2_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF2_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF2_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF2_RSRVD1_MASK)

/*! @name CSC_COEFF3 - RGB to YCbCr 4:2:2 CSC Coefficient3 Register */
#define LCDIF_CSC_COEFF3_C5_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF3_C5_SHIFT                (0U)
#define LCDIF_CSC_COEFF3_C5(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_C5_SHIFT)) & LCDIF_CSC_COEFF3_C5_MASK)
#define LCDIF_CSC_COEFF3_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF3_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF3_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF3_RSRVD0_MASK)
#define LCDIF_CSC_COEFF3_C6_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF3_C6_SHIFT                (16U)
#define LCDIF_CSC_COEFF3_C6(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_C6_SHIFT)) & LCDIF_CSC_COEFF3_C6_MASK)
#define LCDIF_CSC_COEFF3_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF3_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF3_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF3_RSRVD1_MASK)

/*! @name CSC_COEFF4 - RGB to YCbCr 4:2:2 CSC Coefficient4 Register */
#define LCDIF_CSC_COEFF4_C7_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF4_C7_SHIFT                (0U)
#define LCDIF_CSC_COEFF4_C7(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_C7_SHIFT)) & LCDIF_CSC_COEFF4_C7_MASK)
#define LCDIF_CSC_COEFF4_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF4_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF4_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF4_RSRVD0_MASK)
#define LCDIF_CSC_COEFF4_C8_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF4_C8_SHIFT                (16U)
#define LCDIF_CSC_COEFF4_C8(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_C8_SHIFT)) & LCDIF_CSC_COEFF4_C8_MASK)
#define LCDIF_CSC_COEFF4_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF4_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF4_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF4_RSRVD1_MASK)

/*! @name CSC_OFFSET - RGB to YCbCr 4:2:2 CSC Offset Register */
#define LCDIF_CSC_OFFSET_Y_OFFSET_MASK           (0x1FFU)
#define LCDIF_CSC_OFFSET_Y_OFFSET_SHIFT          (0U)
#define LCDIF_CSC_OFFSET_Y_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_Y_OFFSET_SHIFT)) & LCDIF_CSC_OFFSET_Y_OFFSET_MASK)
#define LCDIF_CSC_OFFSET_RSRVD0_MASK             (0xFE00U)
#define LCDIF_CSC_OFFSET_RSRVD0_SHIFT            (9U)
#define LCDIF_CSC_OFFSET_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_RSRVD0_SHIFT)) & LCDIF_CSC_OFFSET_RSRVD0_MASK)
#define LCDIF_CSC_OFFSET_CBCR_OFFSET_MASK        (0x1FF0000U)
#define LCDIF_CSC_OFFSET_CBCR_OFFSET_SHIFT       (16U)
#define LCDIF_CSC_OFFSET_CBCR_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_CBCR_OFFSET_SHIFT)) & LCDIF_CSC_OFFSET_CBCR_OFFSET_MASK)
#define LCDIF_CSC_OFFSET_RSRVD1_MASK             (0xFE000000U)
#define LCDIF_CSC_OFFSET_RSRVD1_SHIFT            (25U)
#define LCDIF_CSC_OFFSET_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_RSRVD1_SHIFT)) & LCDIF_CSC_OFFSET_RSRVD1_MASK)

/*! @name CSC_LIMIT - RGB to YCbCr 4:2:2 CSC Limit Register */
#define LCDIF_CSC_LIMIT_Y_MAX_MASK               (0xFFU)
#define LCDIF_CSC_LIMIT_Y_MAX_SHIFT              (0U)
#define LCDIF_CSC_LIMIT_Y_MAX(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_Y_MAX_SHIFT)) & LCDIF_CSC_LIMIT_Y_MAX_MASK)
#define LCDIF_CSC_LIMIT_Y_MIN_MASK               (0xFF00U)
#define LCDIF_CSC_LIMIT_Y_MIN_SHIFT              (8U)
#define LCDIF_CSC_LIMIT_Y_MIN(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_Y_MIN_SHIFT)) & LCDIF_CSC_LIMIT_Y_MIN_MASK)
#define LCDIF_CSC_LIMIT_CBCR_MAX_MASK            (0xFF0000U)
#define LCDIF_CSC_LIMIT_CBCR_MAX_SHIFT           (16U)
#define LCDIF_CSC_LIMIT_CBCR_MAX(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_CBCR_MAX_SHIFT)) & LCDIF_CSC_LIMIT_CBCR_MAX_MASK)
#define LCDIF_CSC_LIMIT_CBCR_MIN_MASK            (0xFF000000U)
#define LCDIF_CSC_LIMIT_CBCR_MIN_SHIFT           (24U)
#define LCDIF_CSC_LIMIT_CBCR_MIN(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_CBCR_MIN_SHIFT)) & LCDIF_CSC_LIMIT_CBCR_MIN_MASK)

/*! @name DATA - LCD Interface Data Register */
#define LCDIF_DATA_DATA_ZERO_MASK                (0xFFU)
#define LCDIF_DATA_DATA_ZERO_SHIFT               (0U)
#define LCDIF_DATA_DATA_ZERO(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_ZERO_SHIFT)) & LCDIF_DATA_DATA_ZERO_MASK)
#define LCDIF_DATA_DATA_ONE_MASK                 (0xFF00U)
#define LCDIF_DATA_DATA_ONE_SHIFT                (8U)
#define LCDIF_DATA_DATA_ONE(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_ONE_SHIFT)) & LCDIF_DATA_DATA_ONE_MASK)
#define LCDIF_DATA_DATA_TWO_MASK                 (0xFF0000U)
#define LCDIF_DATA_DATA_TWO_SHIFT                (16U)
#define LCDIF_DATA_DATA_TWO(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_TWO_SHIFT)) & LCDIF_DATA_DATA_TWO_MASK)
#define LCDIF_DATA_DATA_THREE_MASK               (0xFF000000U)
#define LCDIF_DATA_DATA_THREE_SHIFT              (24U)
#define LCDIF_DATA_DATA_THREE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_THREE_SHIFT)) & LCDIF_DATA_DATA_THREE_MASK)

/*! @name BM_ERROR_STAT - Bus Master Error Status Register */
#define LCDIF_BM_ERROR_STAT_ADDR_MASK            (0xFFFFFFFFU)
#define LCDIF_BM_ERROR_STAT_ADDR_SHIFT           (0U)
#define LCDIF_BM_ERROR_STAT_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_BM_ERROR_STAT_ADDR_SHIFT)) & LCDIF_BM_ERROR_STAT_ADDR_MASK)

/*! @name CRC_STAT - CRC Status Register */
#define LCDIF_CRC_STAT_CRC_VALUE_MASK            (0xFFFFFFFFU)
#define LCDIF_CRC_STAT_CRC_VALUE_SHIFT           (0U)
#define LCDIF_CRC_STAT_CRC_VALUE(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CRC_STAT_CRC_VALUE_SHIFT)) & LCDIF_CRC_STAT_CRC_VALUE_MASK)

/*! @name STAT - LCD Interface Status Register */
#define LCDIF_STAT_LFIFO_COUNT_MASK              (0x1FFU)
#define LCDIF_STAT_LFIFO_COUNT_SHIFT             (0U)
#define LCDIF_STAT_LFIFO_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_LFIFO_COUNT_SHIFT)) & LCDIF_STAT_LFIFO_COUNT_MASK)
#define LCDIF_STAT_RSRVD0_MASK                   (0xFFFE00U)
#define LCDIF_STAT_RSRVD0_SHIFT                  (9U)
#define LCDIF_STAT_RSRVD0(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_RSRVD0_SHIFT)) & LCDIF_STAT_RSRVD0_MASK)
#define LCDIF_STAT_DVI_CURRENT_FIELD_MASK        (0x1000000U)
#define LCDIF_STAT_DVI_CURRENT_FIELD_SHIFT       (24U)
#define LCDIF_STAT_DVI_CURRENT_FIELD(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_DVI_CURRENT_FIELD_SHIFT)) & LCDIF_STAT_DVI_CURRENT_FIELD_MASK)
#define LCDIF_STAT_BUSY_MASK                     (0x2000000U)
#define LCDIF_STAT_BUSY_SHIFT                    (25U)
#define LCDIF_STAT_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_BUSY_SHIFT)) & LCDIF_STAT_BUSY_MASK)
#define LCDIF_STAT_TXFIFO_EMPTY_MASK             (0x4000000U)
#define LCDIF_STAT_TXFIFO_EMPTY_SHIFT            (26U)
#define LCDIF_STAT_TXFIFO_EMPTY(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_TXFIFO_EMPTY_SHIFT)) & LCDIF_STAT_TXFIFO_EMPTY_MASK)
#define LCDIF_STAT_TXFIFO_FULL_MASK              (0x8000000U)
#define LCDIF_STAT_TXFIFO_FULL_SHIFT             (27U)
#define LCDIF_STAT_TXFIFO_FULL(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_TXFIFO_FULL_SHIFT)) & LCDIF_STAT_TXFIFO_FULL_MASK)
#define LCDIF_STAT_LFIFO_EMPTY_MASK              (0x10000000U)
#define LCDIF_STAT_LFIFO_EMPTY_SHIFT             (28U)
#define LCDIF_STAT_LFIFO_EMPTY(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_LFIFO_EMPTY_SHIFT)) & LCDIF_STAT_LFIFO_EMPTY_MASK)
#define LCDIF_STAT_LFIFO_FULL_MASK               (0x20000000U)
#define LCDIF_STAT_LFIFO_FULL_SHIFT              (29U)
#define LCDIF_STAT_LFIFO_FULL(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_LFIFO_FULL_SHIFT)) & LCDIF_STAT_LFIFO_FULL_MASK)
#define LCDIF_STAT_PRESENT_MASK                  (0x80000000U)
#define LCDIF_STAT_PRESENT_SHIFT                 (31U)
#define LCDIF_STAT_PRESENT(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_PRESENT_SHIFT)) & LCDIF_STAT_PRESENT_MASK)

/*! @name THRES - eLCDIF Threshold Register */
#define LCDIF_THRES_PANIC_MASK                   (0x1FFU)
#define LCDIF_THRES_PANIC_SHIFT                  (0U)
#define LCDIF_THRES_PANIC(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_PANIC_SHIFT)) & LCDIF_THRES_PANIC_MASK)
#define LCDIF_THRES_RSRVD1_MASK                  (0xFE00U)
#define LCDIF_THRES_RSRVD1_SHIFT                 (9U)
#define LCDIF_THRES_RSRVD1(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_RSRVD1_SHIFT)) & LCDIF_THRES_RSRVD1_MASK)
#define LCDIF_THRES_FASTCLOCK_MASK               (0x1FF0000U)
#define LCDIF_THRES_FASTCLOCK_SHIFT              (16U)
#define LCDIF_THRES_FASTCLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_FASTCLOCK_SHIFT)) & LCDIF_THRES_FASTCLOCK_MASK)
#define LCDIF_THRES_RSRVD2_MASK                  (0xFE000000U)
#define LCDIF_THRES_RSRVD2_SHIFT                 (25U)
#define LCDIF_THRES_RSRVD2(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_RSRVD2_SHIFT)) & LCDIF_THRES_RSRVD2_MASK)

/*! @name AS_CTRL - eLCDIF AS Buffer Control Register */
#define LCDIF_AS_CTRL_AS_ENABLE_MASK             (0x1U)
#define LCDIF_AS_CTRL_AS_ENABLE_SHIFT            (0U)
#define LCDIF_AS_CTRL_AS_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_AS_ENABLE_SHIFT)) & LCDIF_AS_CTRL_AS_ENABLE_MASK)
#define LCDIF_AS_CTRL_ALPHA_CTRL_MASK            (0x6U)
#define LCDIF_AS_CTRL_ALPHA_CTRL_SHIFT           (1U)
#define LCDIF_AS_CTRL_ALPHA_CTRL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ALPHA_CTRL_SHIFT)) & LCDIF_AS_CTRL_ALPHA_CTRL_MASK)
#define LCDIF_AS_CTRL_ENABLE_COLORKEY_MASK       (0x8U)
#define LCDIF_AS_CTRL_ENABLE_COLORKEY_SHIFT      (3U)
#define LCDIF_AS_CTRL_ENABLE_COLORKEY(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ENABLE_COLORKEY_SHIFT)) & LCDIF_AS_CTRL_ENABLE_COLORKEY_MASK)
#define LCDIF_AS_CTRL_FORMAT_MASK                (0xF0U)
#define LCDIF_AS_CTRL_FORMAT_SHIFT               (4U)
#define LCDIF_AS_CTRL_FORMAT(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_FORMAT_SHIFT)) & LCDIF_AS_CTRL_FORMAT_MASK)
#define LCDIF_AS_CTRL_ALPHA_MASK                 (0xFF00U)
#define LCDIF_AS_CTRL_ALPHA_SHIFT                (8U)
#define LCDIF_AS_CTRL_ALPHA(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ALPHA_SHIFT)) & LCDIF_AS_CTRL_ALPHA_MASK)
#define LCDIF_AS_CTRL_ROP_MASK                   (0xF0000U)
#define LCDIF_AS_CTRL_ROP_SHIFT                  (16U)
#define LCDIF_AS_CTRL_ROP(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ROP_SHIFT)) & LCDIF_AS_CTRL_ROP_MASK)
#define LCDIF_AS_CTRL_ALPHA_INVERT_MASK          (0x100000U)
#define LCDIF_AS_CTRL_ALPHA_INVERT_SHIFT         (20U)
#define LCDIF_AS_CTRL_ALPHA_INVERT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ALPHA_INVERT_SHIFT)) & LCDIF_AS_CTRL_ALPHA_INVERT_MASK)
#define LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_MASK    (0x600000U)
#define LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_SHIFT   (21U)
#define LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_MASK)
#define LCDIF_AS_CTRL_PS_DISABLE_MASK            (0x800000U)
#define LCDIF_AS_CTRL_PS_DISABLE_SHIFT           (23U)
#define LCDIF_AS_CTRL_PS_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_PS_DISABLE_SHIFT)) & LCDIF_AS_CTRL_PS_DISABLE_MASK)
#define LCDIF_AS_CTRL_RVDS1_MASK                 (0x7000000U)
#define LCDIF_AS_CTRL_RVDS1_SHIFT                (24U)
#define LCDIF_AS_CTRL_RVDS1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_RVDS1_SHIFT)) & LCDIF_AS_CTRL_RVDS1_MASK)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_MASK       (0x8000000U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_SHIFT      (27U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_SHIFT)) & LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_MASK)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_MASK    (0x10000000U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_SHIFT   (28U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_SHIFT)) & LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_MASK)
#define LCDIF_AS_CTRL_CSI_VSYNC_MODE_MASK        (0x20000000U)
#define LCDIF_AS_CTRL_CSI_VSYNC_MODE_SHIFT       (29U)
#define LCDIF_AS_CTRL_CSI_VSYNC_MODE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_VSYNC_MODE_SHIFT)) & LCDIF_AS_CTRL_CSI_VSYNC_MODE_MASK)
#define LCDIF_AS_CTRL_CSI_VSYNC_POL_MASK         (0x40000000U)
#define LCDIF_AS_CTRL_CSI_VSYNC_POL_SHIFT        (30U)
#define LCDIF_AS_CTRL_CSI_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_VSYNC_POL_SHIFT)) & LCDIF_AS_CTRL_CSI_VSYNC_POL_MASK)
#define LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_MASK      (0x80000000U)
#define LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_SHIFT     (31U)
#define LCDIF_AS_CTRL_CSI_VSYNC_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_SHIFT)) & LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_MASK)

/*! @name AS_BUF - Alpha Surface Buffer Pointer */
#define LCDIF_AS_BUF_ADDR_MASK                   (0xFFFFFFFFU)
#define LCDIF_AS_BUF_ADDR_SHIFT                  (0U)
#define LCDIF_AS_BUF_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_BUF_ADDR_SHIFT)) & LCDIF_AS_BUF_ADDR_MASK)

/*! @name AS_NEXT_BUF -  */
#define LCDIF_AS_NEXT_BUF_ADDR_MASK              (0xFFFFFFFFU)
#define LCDIF_AS_NEXT_BUF_ADDR_SHIFT             (0U)
#define LCDIF_AS_NEXT_BUF_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_NEXT_BUF_ADDR_SHIFT)) & LCDIF_AS_NEXT_BUF_ADDR_MASK)

/*! @name AS_CLRKEYLOW - eLCDIF Overlay Color Key Low */
#define LCDIF_AS_CLRKEYLOW_PIXEL_MASK            (0xFFFFFFU)
#define LCDIF_AS_CLRKEYLOW_PIXEL_SHIFT           (0U)
#define LCDIF_AS_CLRKEYLOW_PIXEL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYLOW_PIXEL_SHIFT)) & LCDIF_AS_CLRKEYLOW_PIXEL_MASK)
#define LCDIF_AS_CLRKEYLOW_RSVD1_MASK            (0xFF000000U)
#define LCDIF_AS_CLRKEYLOW_RSVD1_SHIFT           (24U)
#define LCDIF_AS_CLRKEYLOW_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYLOW_RSVD1_SHIFT)) & LCDIF_AS_CLRKEYLOW_RSVD1_MASK)

/*! @name AS_CLRKEYHIGH - eLCDIF Overlay Color Key High */
#define LCDIF_AS_CLRKEYHIGH_PIXEL_MASK           (0xFFFFFFU)
#define LCDIF_AS_CLRKEYHIGH_PIXEL_SHIFT          (0U)
#define LCDIF_AS_CLRKEYHIGH_PIXEL(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYHIGH_PIXEL_SHIFT)) & LCDIF_AS_CLRKEYHIGH_PIXEL_MASK)
#define LCDIF_AS_CLRKEYHIGH_RSVD1_MASK           (0xFF000000U)
#define LCDIF_AS_CLRKEYHIGH_RSVD1_SHIFT          (24U)
#define LCDIF_AS_CLRKEYHIGH_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYHIGH_RSVD1_SHIFT)) & LCDIF_AS_CLRKEYHIGH_RSVD1_MASK)

/*! @name SYNC_DELAY - LCD working insync mode with CSI for VSYNC delay */
#define LCDIF_SYNC_DELAY_H_COUNT_DELAY_MASK      (0xFFFFU)
#define LCDIF_SYNC_DELAY_H_COUNT_DELAY_SHIFT     (0U)
#define LCDIF_SYNC_DELAY_H_COUNT_DELAY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_SYNC_DELAY_H_COUNT_DELAY_SHIFT)) & LCDIF_SYNC_DELAY_H_COUNT_DELAY_MASK)
#define LCDIF_SYNC_DELAY_V_COUNT_DELAY_MASK      (0xFFFF0000U)
#define LCDIF_SYNC_DELAY_V_COUNT_DELAY_SHIFT     (16U)
#define LCDIF_SYNC_DELAY_V_COUNT_DELAY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_SYNC_DELAY_V_COUNT_DELAY_SHIFT)) & LCDIF_SYNC_DELAY_V_COUNT_DELAY_MASK)


/*!
 * @}
 */ /* end of group LCDIF_Register_Masks */


/* LCDIF - Peripheral instance base addresses */
/** Peripheral LCDIF base address */
#define LCDIF_BASE                               (0x21C8000u)
/** Peripheral LCDIF base pointer */
#define LCDIF                                    ((LCDIF_Type *)LCDIF_BASE)
/** Array initializer of LCDIF peripheral base addresses */
#define LCDIF_BASE_ADDRS                         { LCDIF_BASE }
/** Array initializer of LCDIF peripheral base pointers */
#define LCDIF_BASE_PTRS                          { LCDIF }

/*!
 * @}
 */ /* end of group LCDIF_Peripheral_Access_Layer */


 

typedef struct
{
    __IO uint32_t DR;       /**< GPIO data register, offset: 0x0 */
    __IO uint32_t GDIR;     /**< GPIO direction register, offset: 0x4 */
    __I uint32_t PSR;       /**< GPIO pad status register, offset: 0x8 */
    __IO uint32_t ICR1;     /**< GPIO interrupt configuration register1, offset: 0xC */
    __IO uint32_t ICR2;     /**< GPIO interrupt configuration register2, offset: 0x10 */
    __IO uint32_t IMR;      /**< GPIO interrupt mask register, offset: 0x14 */
    __IO uint32_t ISR;      /**< GPIO interrupt status register, offset: 0x18 */
    __IO uint32_t EDGE_SEL; /**< GPIO edge select register, offset: 0x1C */

} GPIO_Type;

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIO1 base address */
#define GPIO1_BASE                               (0x209C000u)
/** Peripheral GPIO1 base pointer */
#define GPIO1                                    ((GPIO_Type *)GPIO1_BASE)
/** Peripheral GPIO2 base address */
#define GPIO2_BASE                               (0x20A0000u)
/** Peripheral GPIO2 base pointer */
#define GPIO2                                    ((GPIO_Type *)GPIO2_BASE)
/** Peripheral GPIO3 base address */
#define GPIO3_BASE                               (0x20A4000u)
/** Peripheral GPIO3 base pointer */
#define GPIO3                                    ((GPIO_Type *)GPIO3_BASE)
/** Peripheral GPIO4 base address */
#define GPIO4_BASE                               (0x20A8000u)
/** Peripheral GPIO4 base pointer */
#define GPIO4                                    ((GPIO_Type *)GPIO4_BASE)
/** Peripheral GPIO5 base address */
#define GPIO5_BASE                               (0x20AC000u)
/** Peripheral GPIO5 base pointer */
#define GPIO5                                    ((GPIO_Type *)GPIO5_BASE)

typedef struct
{
    uint8_t RESERVED_0[68];               /**< IOMUXC从0x20E0000开始，前68个字节是空的，68=0x44 */
    __IO uint32_t SW_MUX_CTL_PAD[112];    /**< 功能复用寄存器共有112个，每个32位即4字节。从SW_MUX_CTL_PAD_JTAG_MOD寄存器到SW_MUX_CTL_PAD_CSI_DATA07寄存器，起始地址0x20E0000+0x44，array offset: 0x44, array step: 0x4 */
    __IO uint32_t SW_PAD_CTL_PAD_DDR[34]; /**< SW_PAD_CTL_PAD_DRAM_ADDR00 SW PAD Control Register..SW_PAD_CTL_PAD_DRAM_RESET SW PAD Control Register, array offset: 0x204, array step: 0x4 */
    uint8_t RESERVED_1[68];
    __IO uint32_t SW_PAD_CTL_PAD[112]; /**< SW_PAD_CTL_PAD_JTAG_MOD SW PAD Control Register..SW_PAD_CTL_PAD_CSI_DATA07 SW PAD Control Register, array offset: 0x2D0, array step: 0x4 */
    __IO uint32_t SW_PAD_CTL_GRP[10];  /**< SW_PAD_CTL_GRP_ADDDS SW GRP Register..SW_PAD_CTL_GRP_DDR_TYPE SW GRP Register, array offset: 0x490, array step: 0x4 */
    __IO uint32_t SELECT_INPUT[122];   /**< USB_OTG1_ID_SELECT_INPUT DAISY Register..USDHC2_WP_SELECT_INPUT DAISY Register, array offset: 0x4B8, array step: 0x4 */
} IOMUXC_Type;

/** 功能复用寄存器设置复用模式，ALT0、ALT1...和SION */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK (0xFU)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT (0U)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK) /* */
#define IOMUXC_SW_MUX_CTL_PAD_SION_MASK (0x10U)
#define IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT (4U)
#define IOMUXC_SW_MUX_CTL_PAD_SION(x) (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_SION_MASK)

#define IOMUXC_BASE (0x20E0000u)
/** Peripheral IOMUXC base pointer */
#define IOMUXC ((IOMUXC_Type *)IOMUXC_BASE)


/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __I  uint32_t URXD;                              /**< UART Receiver Register, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __IO uint32_t UTXD;                              /**< UART Transmitter Register, offset: 0x40 */
       uint8_t RESERVED_1[60];
  __IO uint32_t UCR1;                              /**< UART Control Register 1, offset: 0x80 */
  __IO uint32_t UCR2;                              /**< UART Control Register 2, offset: 0x84 */
  __IO uint32_t UCR3;                              /**< UART Control Register 3, offset: 0x88 */
  __IO uint32_t UCR4;                              /**< UART Control Register 4, offset: 0x8C */
  __IO uint32_t UFCR;                              /**< UART FIFO Control Register, offset: 0x90 */
  __IO uint32_t USR1;                              /**< UART Status Register 1, offset: 0x94 */
  __IO uint32_t USR2;                              /**< UART Status Register 2, offset: 0x98 */
  __IO uint32_t UESC;                              /**< UART Escape Character Register, offset: 0x9C */
  __IO uint32_t UTIM;                              /**< UART Escape Timer Register, offset: 0xA0 */
  __IO uint32_t UBIR;                              /**< UART BRM Incremental Register, offset: 0xA4 */
  __IO uint32_t UBMR;                              /**< UART BRM Modulator Register, offset: 0xA8 */
  __I  uint32_t UBRC;                              /**< UART Baud Rate Count Register, offset: 0xAC */
  __IO uint32_t ONEMS;                             /**< UART One Millisecond Register, offset: 0xB0 */
  __IO uint32_t UTS;                               /**< UART Test Register, offset: 0xB4 */
  __IO uint32_t UMCR;                              /**< UART RS-485 Mode Control Register, offset: 0xB8 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name URXD - UART Receiver Register */
#define UART_URXD_RX_DATA_MASK                   (0xFFU)
#define UART_URXD_RX_DATA_SHIFT                  (0U)
#define UART_URXD_RX_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << UART_URXD_RX_DATA_SHIFT)) & UART_URXD_RX_DATA_MASK)
#define UART_URXD_PRERR_MASK                     (0x400U)
#define UART_URXD_PRERR_SHIFT                    (10U)
#define UART_URXD_PRERR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_URXD_PRERR_SHIFT)) & UART_URXD_PRERR_MASK)
#define UART_URXD_BRK_MASK                       (0x800U)
#define UART_URXD_BRK_SHIFT                      (11U)
#define UART_URXD_BRK(x)                         (((uint32_t)(((uint32_t)(x)) << UART_URXD_BRK_SHIFT)) & UART_URXD_BRK_MASK)
#define UART_URXD_FRMERR_MASK                    (0x1000U)
#define UART_URXD_FRMERR_SHIFT                   (12U)
#define UART_URXD_FRMERR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_URXD_FRMERR_SHIFT)) & UART_URXD_FRMERR_MASK)
#define UART_URXD_OVRRUN_MASK                    (0x2000U)
#define UART_URXD_OVRRUN_SHIFT                   (13U)
#define UART_URXD_OVRRUN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_URXD_OVRRUN_SHIFT)) & UART_URXD_OVRRUN_MASK)
#define UART_URXD_ERR_MASK                       (0x4000U)
#define UART_URXD_ERR_SHIFT                      (14U)
#define UART_URXD_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_URXD_ERR_SHIFT)) & UART_URXD_ERR_MASK)
#define UART_URXD_CHARRDY_MASK                   (0x8000U)
#define UART_URXD_CHARRDY_SHIFT                  (15U)
#define UART_URXD_CHARRDY(x)                     (((uint32_t)(((uint32_t)(x)) << UART_URXD_CHARRDY_SHIFT)) & UART_URXD_CHARRDY_MASK)

/*! @name UTXD - UART Transmitter Register */
#define UART_UTXD_TX_DATA_MASK                   (0xFFU)
#define UART_UTXD_TX_DATA_SHIFT                  (0U)
#define UART_UTXD_TX_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UTXD_TX_DATA_SHIFT)) & UART_UTXD_TX_DATA_MASK)

/*! @name UCR1 - UART Control Register 1 */
#define UART_UCR1_UARTEN_MASK                    (0x1U)
#define UART_UCR1_UARTEN_SHIFT                   (0U)
#define UART_UCR1_UARTEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_UARTEN_SHIFT)) & UART_UCR1_UARTEN_MASK)
#define UART_UCR1_DOZE_MASK                      (0x2U)
#define UART_UCR1_DOZE_SHIFT                     (1U)
#define UART_UCR1_DOZE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_DOZE_SHIFT)) & UART_UCR1_DOZE_MASK)
#define UART_UCR1_ATDMAEN_MASK                   (0x4U)
#define UART_UCR1_ATDMAEN_SHIFT                  (2U)
#define UART_UCR1_ATDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ATDMAEN_SHIFT)) & UART_UCR1_ATDMAEN_MASK)
#define UART_UCR1_TXDMAEN_MASK                   (0x8U)
#define UART_UCR1_TXDMAEN_SHIFT                  (3U)
#define UART_UCR1_TXDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TXDMAEN_SHIFT)) & UART_UCR1_TXDMAEN_MASK)
#define UART_UCR1_SNDBRK_MASK                    (0x10U)
#define UART_UCR1_SNDBRK_SHIFT                   (4U)
#define UART_UCR1_SNDBRK(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_SNDBRK_SHIFT)) & UART_UCR1_SNDBRK_MASK)
#define UART_UCR1_RTSDEN_MASK                    (0x20U)
#define UART_UCR1_RTSDEN_SHIFT                   (5U)
#define UART_UCR1_RTSDEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RTSDEN_SHIFT)) & UART_UCR1_RTSDEN_MASK)
#define UART_UCR1_TXMPTYEN_MASK                  (0x40U)
#define UART_UCR1_TXMPTYEN_SHIFT                 (6U)
#define UART_UCR1_TXMPTYEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TXMPTYEN_SHIFT)) & UART_UCR1_TXMPTYEN_MASK)
#define UART_UCR1_IREN_MASK                      (0x80U)
#define UART_UCR1_IREN_SHIFT                     (7U)
#define UART_UCR1_IREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_IREN_SHIFT)) & UART_UCR1_IREN_MASK)
#define UART_UCR1_RXDMAEN_MASK                   (0x100U)
#define UART_UCR1_RXDMAEN_SHIFT                  (8U)
#define UART_UCR1_RXDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RXDMAEN_SHIFT)) & UART_UCR1_RXDMAEN_MASK)
#define UART_UCR1_RRDYEN_MASK                    (0x200U)
#define UART_UCR1_RRDYEN_SHIFT                   (9U)
#define UART_UCR1_RRDYEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_RRDYEN_SHIFT)) & UART_UCR1_RRDYEN_MASK)
#define UART_UCR1_ICD_MASK                       (0xC00U)
#define UART_UCR1_ICD_SHIFT                      (10U)
#define UART_UCR1_ICD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ICD_SHIFT)) & UART_UCR1_ICD_MASK)
#define UART_UCR1_IDEN_MASK                      (0x1000U)
#define UART_UCR1_IDEN_SHIFT                     (12U)
#define UART_UCR1_IDEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_IDEN_SHIFT)) & UART_UCR1_IDEN_MASK)
#define UART_UCR1_TRDYEN_MASK                    (0x2000U)
#define UART_UCR1_TRDYEN_SHIFT                   (13U)
#define UART_UCR1_TRDYEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR1_TRDYEN_SHIFT)) & UART_UCR1_TRDYEN_MASK)
#define UART_UCR1_ADBR_MASK                      (0x4000U)
#define UART_UCR1_ADBR_SHIFT                     (14U)
#define UART_UCR1_ADBR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ADBR_SHIFT)) & UART_UCR1_ADBR_MASK)
#define UART_UCR1_ADEN_MASK                      (0x8000U)
#define UART_UCR1_ADEN_SHIFT                     (15U)
#define UART_UCR1_ADEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR1_ADEN_SHIFT)) & UART_UCR1_ADEN_MASK)

/*! @name UCR2 - UART Control Register 2 */
#define UART_UCR2_SRST_MASK                      (0x1U)
#define UART_UCR2_SRST_SHIFT                     (0U)
#define UART_UCR2_SRST(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_SRST_SHIFT)) & UART_UCR2_SRST_MASK)
#define UART_UCR2_RXEN_MASK                      (0x2U)
#define UART_UCR2_RXEN_SHIFT                     (1U)
#define UART_UCR2_RXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RXEN_SHIFT)) & UART_UCR2_RXEN_MASK)
#define UART_UCR2_TXEN_MASK                      (0x4U)
#define UART_UCR2_TXEN_SHIFT                     (2U)
#define UART_UCR2_TXEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_TXEN_SHIFT)) & UART_UCR2_TXEN_MASK)
#define UART_UCR2_ATEN_MASK                      (0x8U)
#define UART_UCR2_ATEN_SHIFT                     (3U)
#define UART_UCR2_ATEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ATEN_SHIFT)) & UART_UCR2_ATEN_MASK)
#define UART_UCR2_RTSEN_MASK                     (0x10U)
#define UART_UCR2_RTSEN_SHIFT                    (4U)
#define UART_UCR2_RTSEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RTSEN_SHIFT)) & UART_UCR2_RTSEN_MASK)
#define UART_UCR2_WS_MASK                        (0x20U)
#define UART_UCR2_WS_SHIFT                       (5U)
#define UART_UCR2_WS(x)                          (((uint32_t)(((uint32_t)(x)) << UART_UCR2_WS_SHIFT)) & UART_UCR2_WS_MASK)
#define UART_UCR2_STPB_MASK                      (0x40U)
#define UART_UCR2_STPB_SHIFT                     (6U)
#define UART_UCR2_STPB(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_STPB_SHIFT)) & UART_UCR2_STPB_MASK)
#define UART_UCR2_PROE_MASK                      (0x80U)
#define UART_UCR2_PROE_SHIFT                     (7U)
#define UART_UCR2_PROE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_PROE_SHIFT)) & UART_UCR2_PROE_MASK)
#define UART_UCR2_PREN_MASK                      (0x100U)
#define UART_UCR2_PREN_SHIFT                     (8U)
#define UART_UCR2_PREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_PREN_SHIFT)) & UART_UCR2_PREN_MASK)
#define UART_UCR2_RTEC_MASK                      (0x600U)
#define UART_UCR2_RTEC_SHIFT                     (9U)
#define UART_UCR2_RTEC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_RTEC_SHIFT)) & UART_UCR2_RTEC_MASK)
#define UART_UCR2_ESCEN_MASK                     (0x800U)
#define UART_UCR2_ESCEN_SHIFT                    (11U)
#define UART_UCR2_ESCEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ESCEN_SHIFT)) & UART_UCR2_ESCEN_MASK)
#define UART_UCR2_CTS_MASK                       (0x1000U)
#define UART_UCR2_CTS_SHIFT                      (12U)
#define UART_UCR2_CTS(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR2_CTS_SHIFT)) & UART_UCR2_CTS_MASK)
#define UART_UCR2_CTSC_MASK                      (0x2000U)
#define UART_UCR2_CTSC_SHIFT                     (13U)
#define UART_UCR2_CTSC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_CTSC_SHIFT)) & UART_UCR2_CTSC_MASK)
#define UART_UCR2_IRTS_MASK                      (0x4000U)
#define UART_UCR2_IRTS_SHIFT                     (14U)
#define UART_UCR2_IRTS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_IRTS_SHIFT)) & UART_UCR2_IRTS_MASK)
#define UART_UCR2_ESCI_MASK                      (0x8000U)
#define UART_UCR2_ESCI_SHIFT                     (15U)
#define UART_UCR2_ESCI(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR2_ESCI_SHIFT)) & UART_UCR2_ESCI_MASK)

/*! @name UCR3 - UART Control Register 3 */
#define UART_UCR3_ACIEN_MASK                     (0x1U)
#define UART_UCR3_ACIEN_SHIFT                    (0U)
#define UART_UCR3_ACIEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR3_ACIEN_SHIFT)) & UART_UCR3_ACIEN_MASK)
#define UART_UCR3_INVT_MASK                      (0x2U)
#define UART_UCR3_INVT_SHIFT                     (1U)
#define UART_UCR3_INVT(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR3_INVT_SHIFT)) & UART_UCR3_INVT_MASK)
#define UART_UCR3_RXDMUXSEL_MASK                 (0x4U)
#define UART_UCR3_RXDMUXSEL_SHIFT                (2U)
#define UART_UCR3_RXDMUXSEL(x)                   (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RXDMUXSEL_SHIFT)) & UART_UCR3_RXDMUXSEL_MASK)
#define UART_UCR3_DTRDEN_MASK                    (0x8U)
#define UART_UCR3_DTRDEN_SHIFT                   (3U)
#define UART_UCR3_DTRDEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DTRDEN_SHIFT)) & UART_UCR3_DTRDEN_MASK)
#define UART_UCR3_AWAKEN_MASK                    (0x10U)
#define UART_UCR3_AWAKEN_SHIFT                   (4U)
#define UART_UCR3_AWAKEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_AWAKEN_SHIFT)) & UART_UCR3_AWAKEN_MASK)
#define UART_UCR3_AIRINTEN_MASK                  (0x20U)
#define UART_UCR3_AIRINTEN_SHIFT                 (5U)
#define UART_UCR3_AIRINTEN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_AIRINTEN_SHIFT)) & UART_UCR3_AIRINTEN_MASK)
#define UART_UCR3_RXDSEN_MASK                    (0x40U)
#define UART_UCR3_RXDSEN_SHIFT                   (6U)
#define UART_UCR3_RXDSEN(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RXDSEN_SHIFT)) & UART_UCR3_RXDSEN_MASK)
#define UART_UCR3_ADNIMP_MASK                    (0x80U)
#define UART_UCR3_ADNIMP_SHIFT                   (7U)
#define UART_UCR3_ADNIMP(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UCR3_ADNIMP_SHIFT)) & UART_UCR3_ADNIMP_MASK)
#define UART_UCR3_RI_MASK                        (0x100U)
#define UART_UCR3_RI_SHIFT                       (8U)
#define UART_UCR3_RI(x)                          (((uint32_t)(((uint32_t)(x)) << UART_UCR3_RI_SHIFT)) & UART_UCR3_RI_MASK)
#define UART_UCR3_DCD_MASK                       (0x200U)
#define UART_UCR3_DCD_SHIFT                      (9U)
#define UART_UCR3_DCD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DCD_SHIFT)) & UART_UCR3_DCD_MASK)
#define UART_UCR3_DSR_MASK                       (0x400U)
#define UART_UCR3_DSR_SHIFT                      (10U)
#define UART_UCR3_DSR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DSR_SHIFT)) & UART_UCR3_DSR_MASK)
#define UART_UCR3_FRAERREN_MASK                  (0x800U)
#define UART_UCR3_FRAERREN_SHIFT                 (11U)
#define UART_UCR3_FRAERREN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_FRAERREN_SHIFT)) & UART_UCR3_FRAERREN_MASK)
#define UART_UCR3_PARERREN_MASK                  (0x1000U)
#define UART_UCR3_PARERREN_SHIFT                 (12U)
#define UART_UCR3_PARERREN(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UCR3_PARERREN_SHIFT)) & UART_UCR3_PARERREN_MASK)
#define UART_UCR3_DTREN_MASK                     (0x2000U)
#define UART_UCR3_DTREN_SHIFT                    (13U)
#define UART_UCR3_DTREN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DTREN_SHIFT)) & UART_UCR3_DTREN_MASK)
#define UART_UCR3_DPEC_MASK                      (0xC000U)
#define UART_UCR3_DPEC_SHIFT                     (14U)
#define UART_UCR3_DPEC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR3_DPEC_SHIFT)) & UART_UCR3_DPEC_MASK)

/*! @name UCR4 - UART Control Register 4 */
#define UART_UCR4_DREN_MASK                      (0x1U)
#define UART_UCR4_DREN_SHIFT                     (0U)
#define UART_UCR4_DREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_DREN_SHIFT)) & UART_UCR4_DREN_MASK)
#define UART_UCR4_OREN_MASK                      (0x2U)
#define UART_UCR4_OREN_SHIFT                     (1U)
#define UART_UCR4_OREN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_OREN_SHIFT)) & UART_UCR4_OREN_MASK)
#define UART_UCR4_BKEN_MASK                      (0x4U)
#define UART_UCR4_BKEN_SHIFT                     (2U)
#define UART_UCR4_BKEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_BKEN_SHIFT)) & UART_UCR4_BKEN_MASK)
#define UART_UCR4_TCEN_MASK                      (0x8U)
#define UART_UCR4_TCEN_SHIFT                     (3U)
#define UART_UCR4_TCEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_TCEN_SHIFT)) & UART_UCR4_TCEN_MASK)
#define UART_UCR4_LPBYP_MASK                     (0x10U)
#define UART_UCR4_LPBYP_SHIFT                    (4U)
#define UART_UCR4_LPBYP(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_LPBYP_SHIFT)) & UART_UCR4_LPBYP_MASK)
#define UART_UCR4_IRSC_MASK                      (0x20U)
#define UART_UCR4_IRSC_SHIFT                     (5U)
#define UART_UCR4_IRSC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_IRSC_SHIFT)) & UART_UCR4_IRSC_MASK)
#define UART_UCR4_IDDMAEN_MASK                   (0x40U)
#define UART_UCR4_IDDMAEN_SHIFT                  (6U)
#define UART_UCR4_IDDMAEN(x)                     (((uint32_t)(((uint32_t)(x)) << UART_UCR4_IDDMAEN_SHIFT)) & UART_UCR4_IDDMAEN_MASK)
#define UART_UCR4_WKEN_MASK                      (0x80U)
#define UART_UCR4_WKEN_SHIFT                     (7U)
#define UART_UCR4_WKEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_WKEN_SHIFT)) & UART_UCR4_WKEN_MASK)
#define UART_UCR4_ENIRI_MASK                     (0x100U)
#define UART_UCR4_ENIRI_SHIFT                    (8U)
#define UART_UCR4_ENIRI(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_ENIRI_SHIFT)) & UART_UCR4_ENIRI_MASK)
#define UART_UCR4_INVR_MASK                      (0x200U)
#define UART_UCR4_INVR_SHIFT                     (9U)
#define UART_UCR4_INVR(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UCR4_INVR_SHIFT)) & UART_UCR4_INVR_MASK)
#define UART_UCR4_CTSTL_MASK                     (0xFC00U)
#define UART_UCR4_CTSTL_SHIFT                    (10U)
#define UART_UCR4_CTSTL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UCR4_CTSTL_SHIFT)) & UART_UCR4_CTSTL_MASK)

/*! @name UFCR - UART FIFO Control Register */
#define UART_UFCR_RXTL_MASK                      (0x3FU)
#define UART_UFCR_RXTL_SHIFT                     (0U)
#define UART_UFCR_RXTL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UFCR_RXTL_SHIFT)) & UART_UFCR_RXTL_MASK)
#define UART_UFCR_DCEDTE_MASK                    (0x40U)
#define UART_UFCR_DCEDTE_SHIFT                   (6U)
#define UART_UFCR_DCEDTE(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UFCR_DCEDTE_SHIFT)) & UART_UFCR_DCEDTE_MASK)
#define UART_UFCR_RFDIV_MASK                     (0x380U)
#define UART_UFCR_RFDIV_SHIFT                    (7U)
#define UART_UFCR_RFDIV(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UFCR_RFDIV_SHIFT)) & UART_UFCR_RFDIV_MASK)
#define UART_UFCR_TXTL_MASK                      (0xFC00U)
#define UART_UFCR_TXTL_SHIFT                     (10U)
#define UART_UFCR_TXTL(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UFCR_TXTL_SHIFT)) & UART_UFCR_TXTL_MASK)

/*! @name USR1 - UART Status Register 1 */
#define UART_USR1_SAD_MASK                       (0x8U)
#define UART_USR1_SAD_SHIFT                      (3U)
#define UART_USR1_SAD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR1_SAD_SHIFT)) & UART_USR1_SAD_MASK)
#define UART_USR1_AWAKE_MASK                     (0x10U)
#define UART_USR1_AWAKE_SHIFT                    (4U)
#define UART_USR1_AWAKE(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR1_AWAKE_SHIFT)) & UART_USR1_AWAKE_MASK)
#define UART_USR1_AIRINT_MASK                    (0x20U)
#define UART_USR1_AIRINT_SHIFT                   (5U)
#define UART_USR1_AIRINT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_USR1_AIRINT_SHIFT)) & UART_USR1_AIRINT_MASK)
#define UART_USR1_RXDS_MASK                      (0x40U)
#define UART_USR1_RXDS_SHIFT                     (6U)
#define UART_USR1_RXDS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RXDS_SHIFT)) & UART_USR1_RXDS_MASK)
#define UART_USR1_DTRD_MASK                      (0x80U)
#define UART_USR1_DTRD_SHIFT                     (7U)
#define UART_USR1_DTRD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_DTRD_SHIFT)) & UART_USR1_DTRD_MASK)
#define UART_USR1_AGTIM_MASK                     (0x100U)
#define UART_USR1_AGTIM_SHIFT                    (8U)
#define UART_USR1_AGTIM(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR1_AGTIM_SHIFT)) & UART_USR1_AGTIM_MASK)
#define UART_USR1_RRDY_MASK                      (0x200U)
#define UART_USR1_RRDY_SHIFT                     (9U)
#define UART_USR1_RRDY(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RRDY_SHIFT)) & UART_USR1_RRDY_MASK)
#define UART_USR1_FRAMERR_MASK                   (0x400U)
#define UART_USR1_FRAMERR_SHIFT                  (10U)
#define UART_USR1_FRAMERR(x)                     (((uint32_t)(((uint32_t)(x)) << UART_USR1_FRAMERR_SHIFT)) & UART_USR1_FRAMERR_MASK)
#define UART_USR1_ESCF_MASK                      (0x800U)
#define UART_USR1_ESCF_SHIFT                     (11U)
#define UART_USR1_ESCF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_ESCF_SHIFT)) & UART_USR1_ESCF_MASK)
#define UART_USR1_RTSD_MASK                      (0x1000U)
#define UART_USR1_RTSD_SHIFT                     (12U)
#define UART_USR1_RTSD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RTSD_SHIFT)) & UART_USR1_RTSD_MASK)
#define UART_USR1_TRDY_MASK                      (0x2000U)
#define UART_USR1_TRDY_SHIFT                     (13U)
#define UART_USR1_TRDY(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_TRDY_SHIFT)) & UART_USR1_TRDY_MASK)
#define UART_USR1_RTSS_MASK                      (0x4000U)
#define UART_USR1_RTSS_SHIFT                     (14U)
#define UART_USR1_RTSS(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR1_RTSS_SHIFT)) & UART_USR1_RTSS_MASK)
#define UART_USR1_PARITYERR_MASK                 (0x8000U)
#define UART_USR1_PARITYERR_SHIFT                (15U)
#define UART_USR1_PARITYERR(x)                   (((uint32_t)(((uint32_t)(x)) << UART_USR1_PARITYERR_SHIFT)) & UART_USR1_PARITYERR_MASK)

/*! @name USR2 - UART Status Register 2 */
#define UART_USR2_RDR_MASK                       (0x1U)
#define UART_USR2_RDR_SHIFT                      (0U)
#define UART_USR2_RDR(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR2_RDR_SHIFT)) & UART_USR2_RDR_MASK)
#define UART_USR2_ORE_MASK                       (0x2U)
#define UART_USR2_ORE_SHIFT                      (1U)
#define UART_USR2_ORE(x)                         (((uint32_t)(((uint32_t)(x)) << UART_USR2_ORE_SHIFT)) & UART_USR2_ORE_MASK)
#define UART_USR2_BRCD_MASK                      (0x4U)
#define UART_USR2_BRCD_SHIFT                     (2U)
#define UART_USR2_BRCD(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_BRCD_SHIFT)) & UART_USR2_BRCD_MASK)
#define UART_USR2_TXDC_MASK                      (0x8U)
#define UART_USR2_TXDC_SHIFT                     (3U)
#define UART_USR2_TXDC(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_TXDC_SHIFT)) & UART_USR2_TXDC_MASK)
#define UART_USR2_RTSF_MASK                      (0x10U)
#define UART_USR2_RTSF_SHIFT                     (4U)
#define UART_USR2_RTSF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_RTSF_SHIFT)) & UART_USR2_RTSF_MASK)
#define UART_USR2_DCDIN_MASK                     (0x20U)
#define UART_USR2_DCDIN_SHIFT                    (5U)
#define UART_USR2_DCDIN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR2_DCDIN_SHIFT)) & UART_USR2_DCDIN_MASK)
#define UART_USR2_DCDDELT_MASK                   (0x40U)
#define UART_USR2_DCDDELT_SHIFT                  (6U)
#define UART_USR2_DCDDELT(x)                     (((uint32_t)(((uint32_t)(x)) << UART_USR2_DCDDELT_SHIFT)) & UART_USR2_DCDDELT_MASK)
#define UART_USR2_WAKE_MASK                      (0x80U)
#define UART_USR2_WAKE_SHIFT                     (7U)
#define UART_USR2_WAKE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_WAKE_SHIFT)) & UART_USR2_WAKE_MASK)
#define UART_USR2_IRINT_MASK                     (0x100U)
#define UART_USR2_IRINT_SHIFT                    (8U)
#define UART_USR2_IRINT(x)                       (((uint32_t)(((uint32_t)(x)) << UART_USR2_IRINT_SHIFT)) & UART_USR2_IRINT_MASK)
#define UART_USR2_RIIN_MASK                      (0x200U)
#define UART_USR2_RIIN_SHIFT                     (9U)
#define UART_USR2_RIIN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_RIIN_SHIFT)) & UART_USR2_RIIN_MASK)
#define UART_USR2_RIDELT_MASK                    (0x400U)
#define UART_USR2_RIDELT_SHIFT                   (10U)
#define UART_USR2_RIDELT(x)                      (((uint32_t)(((uint32_t)(x)) << UART_USR2_RIDELT_SHIFT)) & UART_USR2_RIDELT_MASK)
#define UART_USR2_ACST_MASK                      (0x800U)
#define UART_USR2_ACST_SHIFT                     (11U)
#define UART_USR2_ACST(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_ACST_SHIFT)) & UART_USR2_ACST_MASK)
#define UART_USR2_IDLE_MASK                      (0x1000U)
#define UART_USR2_IDLE_SHIFT                     (12U)
#define UART_USR2_IDLE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_IDLE_SHIFT)) & UART_USR2_IDLE_MASK)
#define UART_USR2_DTRF_MASK                      (0x2000U)
#define UART_USR2_DTRF_SHIFT                     (13U)
#define UART_USR2_DTRF(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_DTRF_SHIFT)) & UART_USR2_DTRF_MASK)
#define UART_USR2_TXFE_MASK                      (0x4000U)
#define UART_USR2_TXFE_SHIFT                     (14U)
#define UART_USR2_TXFE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_TXFE_SHIFT)) & UART_USR2_TXFE_MASK)
#define UART_USR2_ADET_MASK                      (0x8000U)
#define UART_USR2_ADET_SHIFT                     (15U)
#define UART_USR2_ADET(x)                        (((uint32_t)(((uint32_t)(x)) << UART_USR2_ADET_SHIFT)) & UART_USR2_ADET_MASK)

/*! @name UESC - UART Escape Character Register */
#define UART_UESC_ESC_CHAR_MASK                  (0xFFU)
#define UART_UESC_ESC_CHAR_SHIFT                 (0U)
#define UART_UESC_ESC_CHAR(x)                    (((uint32_t)(((uint32_t)(x)) << UART_UESC_ESC_CHAR_SHIFT)) & UART_UESC_ESC_CHAR_MASK)

/*! @name UTIM - UART Escape Timer Register */
#define UART_UTIM_TIM_MASK                       (0xFFFU)
#define UART_UTIM_TIM_SHIFT                      (0U)
#define UART_UTIM_TIM(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UTIM_TIM_SHIFT)) & UART_UTIM_TIM_MASK)

/*! @name UBIR - UART BRM Incremental Register */
#define UART_UBIR_INC_MASK                       (0xFFFFU)
#define UART_UBIR_INC_SHIFT                      (0U)
#define UART_UBIR_INC(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UBIR_INC_SHIFT)) & UART_UBIR_INC_MASK)

/*! @name UBMR - UART BRM Modulator Register */
#define UART_UBMR_MOD_MASK                       (0xFFFFU)
#define UART_UBMR_MOD_SHIFT                      (0U)
#define UART_UBMR_MOD(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UBMR_MOD_SHIFT)) & UART_UBMR_MOD_MASK)

/*! @name UBRC - UART Baud Rate Count Register */
#define UART_UBRC_BCNT_MASK                      (0xFFFFU)
#define UART_UBRC_BCNT_SHIFT                     (0U)
#define UART_UBRC_BCNT(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UBRC_BCNT_SHIFT)) & UART_UBRC_BCNT_MASK)

/*! @name ONEMS - UART One Millisecond Register */
#define UART_ONEMS_ONEMS_MASK                    (0xFFFFFFU)
#define UART_ONEMS_ONEMS_SHIFT                   (0U)
#define UART_ONEMS_ONEMS(x)                      (((uint32_t)(((uint32_t)(x)) << UART_ONEMS_ONEMS_SHIFT)) & UART_ONEMS_ONEMS_MASK)

/*! @name UTS - UART Test Register */
#define UART_UTS_SOFTRST_MASK                    (0x1U)
#define UART_UTS_SOFTRST_SHIFT                   (0U)
#define UART_UTS_SOFTRST(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_SOFTRST_SHIFT)) & UART_UTS_SOFTRST_MASK)
#define UART_UTS_RXFULL_MASK                     (0x8U)
#define UART_UTS_RXFULL_SHIFT                    (3U)
#define UART_UTS_RXFULL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXFULL_SHIFT)) & UART_UTS_RXFULL_MASK)
#define UART_UTS_TXFULL_MASK                     (0x10U)
#define UART_UTS_TXFULL_SHIFT                    (4U)
#define UART_UTS_TXFULL(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_TXFULL_SHIFT)) & UART_UTS_TXFULL_MASK)
#define UART_UTS_RXEMPTY_MASK                    (0x20U)
#define UART_UTS_RXEMPTY_SHIFT                   (5U)
#define UART_UTS_RXEMPTY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXEMPTY_SHIFT)) & UART_UTS_RXEMPTY_MASK)
#define UART_UTS_TXEMPTY_MASK                    (0x40U)
#define UART_UTS_TXEMPTY_SHIFT                   (6U)
#define UART_UTS_TXEMPTY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_TXEMPTY_SHIFT)) & UART_UTS_TXEMPTY_MASK)
#define UART_UTS_RXDBG_MASK                      (0x200U)
#define UART_UTS_RXDBG_SHIFT                     (9U)
#define UART_UTS_RXDBG(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UTS_RXDBG_SHIFT)) & UART_UTS_RXDBG_MASK)
#define UART_UTS_LOOPIR_MASK                     (0x400U)
#define UART_UTS_LOOPIR_SHIFT                    (10U)
#define UART_UTS_LOOPIR(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UTS_LOOPIR_SHIFT)) & UART_UTS_LOOPIR_MASK)
#define UART_UTS_DBGEN_MASK                      (0x800U)
#define UART_UTS_DBGEN_SHIFT                     (11U)
#define UART_UTS_DBGEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UTS_DBGEN_SHIFT)) & UART_UTS_DBGEN_MASK)
#define UART_UTS_LOOP_MASK                       (0x1000U)
#define UART_UTS_LOOP_SHIFT                      (12U)
#define UART_UTS_LOOP(x)                         (((uint32_t)(((uint32_t)(x)) << UART_UTS_LOOP_SHIFT)) & UART_UTS_LOOP_MASK)
#define UART_UTS_FRCPERR_MASK                    (0x2000U)
#define UART_UTS_FRCPERR_SHIFT                   (13U)
#define UART_UTS_FRCPERR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UTS_FRCPERR_SHIFT)) & UART_UTS_FRCPERR_MASK)

/*! @name UMCR - UART RS-485 Mode Control Register */
#define UART_UMCR_MDEN_MASK                      (0x1U)
#define UART_UMCR_MDEN_SHIFT                     (0U)
#define UART_UMCR_MDEN(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_MDEN_SHIFT)) & UART_UMCR_MDEN_MASK)
#define UART_UMCR_SLAM_MASK                      (0x2U)
#define UART_UMCR_SLAM_SHIFT                     (1U)
#define UART_UMCR_SLAM(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SLAM_SHIFT)) & UART_UMCR_SLAM_MASK)
#define UART_UMCR_TXB8_MASK                      (0x4U)
#define UART_UMCR_TXB8_SHIFT                     (2U)
#define UART_UMCR_TXB8(x)                        (((uint32_t)(((uint32_t)(x)) << UART_UMCR_TXB8_SHIFT)) & UART_UMCR_TXB8_MASK)
#define UART_UMCR_SADEN_MASK                     (0x8U)
#define UART_UMCR_SADEN_SHIFT                    (3U)
#define UART_UMCR_SADEN(x)                       (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SADEN_SHIFT)) & UART_UMCR_SADEN_MASK)
#define UART_UMCR_SLADDR_MASK                    (0xFF00U)
#define UART_UMCR_SLADDR_SHIFT                   (8U)
#define UART_UMCR_SLADDR(x)                      (((uint32_t)(((uint32_t)(x)) << UART_UMCR_SLADDR_SHIFT)) & UART_UMCR_SLADDR_MASK)


/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x2020000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x21E8000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
/** Peripheral UART3 base address */
#define UART3_BASE                               (0x21EC000u)
/** Peripheral UART3 base pointer */
#define UART3                                    ((UART_Type *)UART3_BASE)
/** Peripheral UART4 base address */
#define UART4_BASE                               (0x21F0000u)
/** Peripheral UART4 base pointer */
#define UART4                                    ((UART_Type *)UART4_BASE)
/** Peripheral UART5 base address */
#define UART5_BASE                               (0x21F4000u)
/** Peripheral UART5 base pointer */
#define UART5                                    ((UART_Type *)UART5_BASE)
/** Peripheral UART6 base address */
#define UART6_BASE                               (0x21FC000u)
/** Peripheral UART6 base pointer */
#define UART6                                    ((UART_Type *)UART6_BASE)
/** Peripheral UART7 base address */
#define UART7_BASE                               (0x2018000u)
/** Peripheral UART7 base pointer */
#define UART7                                    ((UART_Type *)UART7_BASE)
/** Peripheral UART8 base address */
#define UART8_BASE                               (0x2288000u)
/** Peripheral UART8 base pointer */
#define UART8                                    ((UART_Type *)UART8_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { 0u, UART1_BASE, UART2_BASE, UART3_BASE, UART4_BASE, UART5_BASE, UART6_BASE, UART7_BASE, UART8_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { (UART_Type *)0u, UART1, UART2, UART3, UART4, UART5, UART6, UART7, UART8 }
/** Interrupt vectors for the UART peripheral type */
#define UART_IRQS                                { NotAvail_IRQn, UART1_IRQn, UART2_IRQn, UART3_IRQn, UART4_IRQn, UART5_IRQn, UART6_IRQn, UART7_IRQn, UART8_IRQn }

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */



#endif