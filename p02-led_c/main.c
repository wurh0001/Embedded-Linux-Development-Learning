/*
 * @Author: wurh0001 z02014268@stu.ahu.edu.cn
 * @Date: 2026-01-10 22:33:51
 * @LastEditors: wurh0001 z02014268@stu.ahu.edu.cn
 * @LastEditTime: 2026-01-10 23:51:01
 * @FilePath: /projects/p02-led_c/main.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "main.h"

// 开启时钟函数：开启所有时钟
void clk_start(void)
{
    CCM_CCGR0 = 0xffffffff;
    CCM_CCGR1 = 0xffffffff;
    CCM_CCGR2 = 0xffffffff;
    CCM_CCGR3 = 0xffffffff;
    CCM_CCGR4 = 0xffffffff;
    CCM_CCGR5 = 0xffffffff;
    CCM_CCGR6 = 0xffffffff;
}
/* led初始化函数
设置GPIO复用和电气特性；设置GPIO输出电平
*/ 
void led_init(void)
{
    // 初始化GPIO的复用，使用GPIO1_IO03
}

// led开启

// led关闭

// 实现呼吸灯效果

