/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:32:40
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 14:15:05
 * @FilePath: /projects/p12_uart/bsp/led/bsp_led.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_led.h"

void led_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    /* 修正：0x10B0 确保 DSE 驱动能力开启，0x10B0 会禁用驱动 */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10B0);
    GPIO1->GDIR |= (1 << 3);
    /* 默认关闭 LED (高电平) */
    GPIO1->DR |= (1 << 3);
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
        /* 低电平点亮 */
        GPIO1->DR &= ~(1 << 3);
    }
    else
    {
        /* 高电平熄灭 */
        GPIO1->DR |= (1 << 3);
    }
}
