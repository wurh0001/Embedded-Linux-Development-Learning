/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 02:43:05
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-15 22:26:48
 * @FilePath: /projects/p07_clk/imx6ull/MCIMX6Y2.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __MCIMX6Y2_H__
#define __MCIMX6Y2_H__

#include "cc.h"

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