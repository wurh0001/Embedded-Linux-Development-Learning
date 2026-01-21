/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 16:11:29
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-19 21:39:10
 * @FilePath: /projects/p08_interruption/bsp/beep/beep.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "imx6ull.h"

void beep_init(void);
void beep_switch(int16_t status);

#endif