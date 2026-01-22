/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-13 22:32:49
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 14:05:04
 * @FilePath: /projects/p12_uart/bsp/led/bsp_led.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "imx6ull.h"

#define LED_ON  1
#define LED_OFF 0

void led_init(void);
void led_switch(int led_status);

#endif