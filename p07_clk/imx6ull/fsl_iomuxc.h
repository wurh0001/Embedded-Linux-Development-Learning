/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 02:41:42
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-14 21:25:17
 * @FilePath: /projects/p05-beep/imx6ull/fsl_iomuxc.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __FSL_IOMUXC_H__
#define __FSL_IOMUXC_H__

#include "MCIMX6Y2.h"

#define IOMUXC_SW_MUX_CTL_PADGPIO1_IO03 (0X020E0068U)
#define IOMUXC_SW_PAD_CTL_PADGPIO1_IO03 (0X020E02F4U)

/** 复用寄存器地址、ALT值、PAD寄存器地址 */
/** GPIO1_IO01功能复用 */
#define IOMUXC_GPIO1_IO01_I2C2_SDA                  0x020E0060U, 0x0U, 0x020E05B0U, 0x1U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_GPT1_COMPARE1             0x020E0060U, 0x1U, 0x00000000U, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_USB_OTG1_OC               0x020E0060U, 0x2U, 0x020E0664U, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_ENET2_REF_CLK2            0x020E0060U, 0x3U, 0x020E057CU, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_MQS_LEFT                  0x020E0060U, 0x4U, 0x00000000U, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_GPIO1_IO01                0x020E0060U, 0x5U, 0x00000000U, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_ENET1_1588_EVENT0_OUT     0x020E0060U, 0x6U, 0x00000000U, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_SRC_EARLY_RESET           0x020E0060U, 0x7U, 0x00000000U, 0x0U, 0x020E02ECU
#define IOMUXC_GPIO1_IO01_WDOG1_WDOG_B              0x020E0060U, 0x8U, 0x00000000U, 0x0U, 0x020E02ECU

/** GPIO1_IO03功能复用 */
#define IOMUXC_GPIO1_IO03_I2C1_SDA                  0x020E0068U, 0x0U, 0x020E05A8U, 0x1U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_GPT1_COMPARE3             0x020E0068U, 0x1U, 0x00000000U, 0x0U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_USB_OTG2_OC               0x020E0068U, 0x2U, 0x020E0660U, 0x0U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_USDHC1_CD_B               0x020E0068U, 0x4U, 0x020E0668U, 0x0U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_GPIO1_IO03                0x020E0068U, 0x5U, 0x00000000U, 0x0U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_CCM_DI0_EXT_CLK           0x020E0068U, 0x6U, 0x00000000U, 0x0U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_SRC_TESTER_ACK            0x020E0068U, 0x7U, 0x00000000U, 0x0U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_UART1_RX                  0x020E0068U, 0x8U, 0x020E0624U, 0x1U, 0x020E02F4U
#define IOMUXC_GPIO1_IO03_UART1_TX                  0x020E0068U, 0x8U, 0x00000000U, 0x0U, 0x020E02F4U

/** GPIO5功能复用 */
#define IOMUXC_SNVS_BOOT_MODE0_GPIO5_IO10           0x02290000U, 0x5U, 0x00000000U, 0x0U, 0x02290044U
#define IOMUXC_SNVS_BOOT_MODE1_GPIO5_IO11           0x02290004U, 0x5U, 0x00000000U, 0x0U, 0x02290048U
#define IOMUXC_SNVS_SNVS_TAMPER0_GPIO5_IO00         0x02290008U, 0x5U, 0x00000000U, 0x0U, 0x0229004CU
#define IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01         0x0229000CU, 0x5U, 0x00000000U, 0x0U, 0x02290050U
#define IOMUXC_SNVS_SNVS_TAMPER2_GPIO5_IO02         0x02290010U, 0x5U, 0x00000000U, 0x0U, 0x02290054U
#define IOMUXC_SNVS_SNVS_TAMPER3_GPIO5_IO03         0x02290014U, 0x5U, 0x00000000U, 0x0U, 0x02290058U
#define IOMUXC_SNVS_SNVS_TAMPER4_GPIO5_IO04         0x02290018U, 0x5U, 0x00000000U, 0x0U, 0x0229005CU
#define IOMUXC_SNVS_SNVS_TAMPER5_GPIO5_IO05         0x0229001CU, 0x5U, 0x00000000U, 0x0U, 0x02290060U
#define IOMUXC_SNVS_SNVS_TAMPER6_GPIO5_IO06         0x02290020U, 0x5U, 0x00000000U, 0x0U, 0x02290064U
#define IOMUXC_SNVS_SNVS_TAMPER7_GPIO5_IO07         0x02290024U, 0x5U, 0x00000000U, 0x0U, 0x02290068U
#define IOMUXC_SNVS_SNVS_TAMPER8_GPIO5_IO08         0x02290028U, 0x5U, 0x00000000U, 0x0U, 0x0229006CU
#define IOMUXC_SNVS_SNVS_TAMPER9_GPIO5_IO09         0x0229002CU, 0x5U, 0x00000000U, 0x0U, 0x02290070U

/**
 * @description: 用于设置IO的引脚复用
 * @param {uint32_t} muxRegister：寄存器基地址
 * @param {uint32_t} muxMode：选择复用模式
 * @param {uint32_t} inputRegister
 * @param {uint32_t} inputDaisy
 * @param {uint32_t} configRegister
 * @param {uint32_t} inputOnfield：强制输入开关
 * @return {*}
 */
static inline void IOMUXC_SetPinMux(
    uint32_t muxRegister,
    uint32_t muxMode,
    uint32_t inputRegister,
    uint32_t inputDaisy,
    uint32_t configRegister,
    uint32_t inputOnfield)
{
    *((volatile uint32_t *)muxRegister) = IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(muxMode) | IOMUXC_SW_MUX_CTL_PAD_SION(inputOnfield);
}

/**
 * @description: 用于IO的引脚配置，电气特性
 * @param {uint32_t} muxRegister：
 * @param {uint32_t} muxMode
 * @param {uint32_t} inputRegister
 * @param {uint32_t} inputDaisy
 * @param {uint32_t} configRegister：pad寄存器地址
 * @param {uint32_t} configValue：pad寄存器写入的值
 * @return {*}
 */
static inline void IOMUXC_SetPinConfig(
    uint32_t muxRegister,
    uint32_t muxMode,
    uint32_t inputRegister,
    uint32_t inputDaisy,
    uint32_t configRegister,
    uint32_t configValue
)
{
    *((volatile uint32_t *)configRegister) = configValue;
}
#endif