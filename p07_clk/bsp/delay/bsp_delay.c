/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-14 22:14:25
 * @FilePath: /projects/p05-beep/bsp/delay/bsp_delay.c
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