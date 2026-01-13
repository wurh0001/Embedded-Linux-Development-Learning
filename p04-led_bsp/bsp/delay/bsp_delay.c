/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:49:39
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-13 23:13:51
 * @FilePath: /projects/p04-led_bsp/bsp/delay/bsp_delay.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_delay.h"

void delay_short(volatile uint32_t count)
{
    while(count--);

}

void delay_ms(volatile uint32_t count)
{
    while(count--)
    {
        delay_short(0x7ff);
    }
}