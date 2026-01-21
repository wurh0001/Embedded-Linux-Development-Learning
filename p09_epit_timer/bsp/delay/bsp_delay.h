/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-14 22:14:29
 * @FilePath: /projects/p05-beep/bsp/delay/bsp_delay.h
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