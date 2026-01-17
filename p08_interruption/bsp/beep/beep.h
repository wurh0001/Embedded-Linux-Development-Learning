/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 16:11:29
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-14 21:44:01
 * @FilePath: /projects/p05-beep/bsp/beep/beep.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __BEEP_H
#define __BEEP_H

#include "imx6ull.h"

void beep_init(void);
void beep_switch(int16_t status);

#endif