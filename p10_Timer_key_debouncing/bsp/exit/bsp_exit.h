/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-19 21:36:28
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-19 21:38:17
 * @FilePath: /projects/p08_interruption/bsp/exit/bsp_exit.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef _BSP_EXIT_H
#define _BSP_EXIT_H

#include "imx6ull.h"

/* 函数声明 */
void exit_init(void);						/* 中断初始化 */
void gpio1_io18_irqhandler(void); 			/* 中断处理函数 */

#endif
