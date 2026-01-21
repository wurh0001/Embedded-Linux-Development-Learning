/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 02:43:05
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-21 16:23:26
 * @FilePath: /projects/p11_High_precision_delay/imx6ull/MCIMX6Y2.h
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

#endif