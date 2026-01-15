/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-15 20:59:31
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-15 21:17:57
 * @FilePath: /projects/p07_clk/bsp/clk/bsp_clk.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#include "bsp_clk.h"

/**
 * @description: 开启所有时钟
 * @return {*}
 */
void clk_start(void)
{
    CCM->CCGR0 = 0XFFFFFFFF;
    CCM->CCGR1 = 0XFFFFFFFF;
    CCM->CCGR2 = 0XFFFFFFFF;
    CCM->CCGR3 = 0XFFFFFFFF;
    CCM->CCGR4 = 0XFFFFFFFF;
    CCM->CCGR5 = 0XFFFFFFFF;
    CCM->CCGR6 = 0XFFFFFFFF;
}

void clk_init(void)
{
    uint32_t reg = 0;
    // 1、设置ARM内核时钟为528MHZ
    // 先判断开发板当前的ARM时钟源是哪个，时钟树中ARM的时钟来源是PLL1
    // 而PLL1的时钟线是pll1_sw_clk，这条线有两种时钟来源：pll1_main_clk（主）和step_clk（辅）【CCSR: pll1_sw_clk_sel】
    // step_clk（辅）又有两个时钟来源：OSC_clk（晶振24MHZ）和secondary_clk【CCSR: step_sel】
    // secondary_clk也有两个时钟来源：PLL2（528MHZ）、PLL2_PFD2（400/396MHZ）【CCSR: secondary_clk_sel】
}