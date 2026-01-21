/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:32:40
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-13 22:54:26
 * @FilePath: /projects/p04-led_bsp/bsp/led/bsp_led.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_led.h"

void led_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SW_MUX_CTL_PADGPIO1_IO03, 0x05, 0, 0, IOMUXC_SW_PAD_CTL_PADGPIO1_IO03, 0);
    IOMUXC_SetPinConfig(IOMUXC_SW_PAD_CTL_PADGPIO1_IO03, 0x05, 0, 0, IOMUXC_SW_PAD_CTL_PADGPIO1_IO03, 0x10B00);
    GPIO1->GDIR |= (1 << 3);
    GPIO1->DR &= ~(1 << 3);
}

/**
 * @description: led开关
 * @param {int} led_status：1：打开；0：关闭
 * @return {*}
 */
void led_switch(int led_status)
{
    if (led_status)
    {
        GPIO1->DR |= (1 << 3);
    }
    else
    {
        GPIO1->DR &= ~(1 << 3);
    }
}
