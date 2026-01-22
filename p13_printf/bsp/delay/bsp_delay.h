/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-21 16:20:59
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-21 16:53:02
 * @FilePath: /projects/p11_High_precision_delay/bsp/delay/bsp_delay.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H

#include "imx6ull.h"


/* 函数声明 */
void delay_init(void);
void delayus(unsigned int usdelay);
void delayms(unsigned int msdelay);
void delay_short(volatile uint32_t count);
void delay_ms(volatile uint32_t count);
void gpt1_irqhandler(void);

#endif

