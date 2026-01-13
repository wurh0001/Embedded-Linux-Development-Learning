/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 02:41:42
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-13 21:45:12
 * @FilePath: /projects/p04-led_bsp/imx6ull/fsl_iomuxc.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __FSL_IOMUXC_H__
#define __FSL_IOMUXC_H__

#include "MCIMX6Y2.h"

#define IOMUXC_GPIO1_IO03 0X020E0068U;

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

#endif