/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-20 00:23:36
 * @FilePath: /projects/p08_interruption/user/main.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_clk.h"
#include "bsp_beep.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_exit.h"
#include "bsp_int.h"
#include "bsp_key.h"

int main(void)
{
    unsigned char state = 0;

    int_init();                /* 中断初始化 */
    clk_init();                /* 初始化系统时钟 */
    clk_start();               /* 开启所有时钟 */
    led_init();                /* 初始化LED */
    beep_init();               /* 初始化蜂鸣器 */
    exit_init();               /* 初始化外部中断 */
    
    while(1)
    {
        state = !state;
        led_switch(LED0, state); /* 切换LED状态 */
        delay_ms(500);           /* 使用bsp_delay中定义的毫秒延时 */
    }
    return 0;
}