/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:50:24
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-13 23:18:42
 * @FilePath: /projects/p04-led_bsp/user/main.c
 * @Description: 本工程用于SDK移植验证和标准工程搭建
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_delay.h"

int main(void)
{
    clk_start();
    led_init();
    while(1)
    {
        led_on();
        delay_ms(1000);
        led_off();
        delay_ms(1000);
    }
}