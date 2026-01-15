/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:32:49
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-13 22:56:16
 * @FilePath: /projects/p04-led_bsp/bsp/led/bsp_led.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "imx6ull.h"

void led_init(void);
void led_switch(int led_status);

#endif