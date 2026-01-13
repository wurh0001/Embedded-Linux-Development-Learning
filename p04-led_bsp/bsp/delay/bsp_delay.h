/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:49:48
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-13 23:14:03
 * @FilePath: /projects/p04-led_bsp/bsp/delay/bsp_delay.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H

#include "imx6ull.h"

void delay_short(volatile uint32_t count);
void delay_ms(volatile uint32_t count);

#endif