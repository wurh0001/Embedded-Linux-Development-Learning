/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-15 20:59:31
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 16:11:14
 * @FilePath: /projects/p13_printf/bsp/clk/bsp_clk.c
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
    // 修改步骤：1、判断当前ARM内核时钟源，若是主时钟源切换到辅时钟源；
    //         2、设置主时钟为1056MHZ【CCM_ANLOG: PLL_ARM】，分频为2，即得到528MHZ主频
    //         3、切回主时钟源，ARM_ROOT线路分频设为2【CCM:CACRR】
    if((((CCM->CCSR)>>2)&0x01) == 0)    // 当前是主时钟源，先切换到辅时钟源
    {
        CCM->CCSR &= ~(1<<8);   // 设置ccsr中step_clk位=0，时钟源为osc（24MHZ）
        CCM->CCSR |= (1<<2);    // 设置ccsr中pll1_sw_clk_sel位=1，即设置为辅时钟源step_clk
    }
    // 设置主时钟频率为1056MHZ；
    CCM_ANALOG->PLL_ARM = (1 << 13) | (88 & 0x7f);  // bit13：设置时钟使能；bit[0:6]：赋值88，得到1056MHZ
    CCM->CCSR &= ~(1<<2);   // 设置ccsr中pll1_sw_clk_sel=0，切换为主时钟源
    CCM->CACRR = 0x01;      // 设置arm_root线路分频为2

    // 2、设置PLL2(SYS PLL)各个PFD
    reg = CCM_ANALOG->PFD_528;
    reg &= ~(0X3F3F3F3F);      /* 清除原来的设置 */
    reg |= 32 << 24;           /* PLL2_PFD3=528*18/32=297Mhz */
    reg |= 24 << 16;           /* PLL2_PFD2=528*18/24=396Mhz(DDR使用的时钟，最大400Mhz) */
    reg |= 16 << 8;            /* PLL2_PFD1=528*18/16=594Mhz */
    reg |= 27 << 0;            /* PLL2_PFD0=528*18/27=352Mhz */
    CCM_ANALOG->PFD_528 = reg; /* 设置PLL2_PFD0~3 */

    // 3、设置PLL3(USB1)各个PFD
	reg = 0;					/* 清零 */
	reg = CCM_ANALOG->PFD_480;
	reg &= ~(0X3F3F3F3F);		/* 清除原来的设置 */
	reg |= 19<<24;				/* PLL3_PFD3=480*18/19=454.74Mhz */
	reg |= 17<<16;				/* PLL3_PFD2=480*18/17=508.24Mhz */
	reg |= 16<<8;				/* PLL3_PFD1=480*18/16=540Mhz */
	reg |= 12<<0;				/* PLL3_PFD0=480*18/12=720Mhz */
	CCM_ANALOG->PFD_480=reg;	/* 设置PLL3_PFD0~3 */	

	// 4、设置AHB时钟 最小6Mhz， 最大132Mhz (boot rom自动设置好了可以不用设置)
	CCM->CBCMR &= ~(3 << 18); 	    /* 清除设置 */ 
	CCM->CBCMR |= (1 << 18);	    /* pre_periph_clk=PLL2_PFD2=396MHz */
	CCM->CBCDR &= ~(1 << 25);	    /* periph_clk=pre_periph_clk=396MHz */
	while(CCM->CDHIPR & (1 << 5));  /* 等待握手完成 */

    /* 5、设置IPG_CLK_ROOT最小3Mhz，最大66Mhz (boot rom自动设置好了可以不用设置)*/
	CCM->CBCDR &= ~(3 << 8);	/* CBCDR的IPG_PODF清零 */
	CCM->CBCDR |= 1 << 8;		/* IPG_PODF 2分频，IPG_CLK_ROOT=66MHz */

    /* 6、设置PERCLK_CLK_ROOT时钟 */
	CCM->CSCMR1 &= ~(1 << 6);	/* PERCLK_CLK_ROOT时钟源为IPG */
	CCM->CSCMR1 &= ~(7 << 0);	/* PERCLK_PODF位清零，即1分频 */

    /* 7、设置 UART 时钟源为 pll3_80m，不分频 */
    CCM->CSCDR1 &= ~(1 << 6);    /* UART_CLK_SEL = 0 */
    CCM->CSCDR1 &= ~0x3F;        /* UART_CLK_PODF = 0 */
}
