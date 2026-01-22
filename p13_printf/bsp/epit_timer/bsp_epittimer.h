/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-20 22:49:20
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-20 22:49:46
 * @FilePath: /projects/p09_epit_timer/bsp/epit_timer/bsp_epittimer.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef _BSP_EPITTIMER_H
#define _BSP_EPITTIMER_H
/***************************************************************
Copyright © zuozhongkai Co., Ltd. 1998-2019. All rights reserved.
文件名	: 	 bsp_epittimer.h
作者	   : 左忠凯
版本	   : V1.0
描述	   : EPIT定时器驱动头文件。
其他	   : 无
论坛 	   : www.wtmembed.com
日志	   : 初版V1.0 2019/1/5 左忠凯创建
***************************************************************/
#include "imx6ull.h"


/* 函数声明 */
void epit1_init(unsigned int frac, unsigned int value);
void epit1_irqhandler(void);

#endif
