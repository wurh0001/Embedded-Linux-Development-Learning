/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-10 22:33:51
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-11 22:49:24
 * @FilePath: /projects/p02-led_c/main.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */

#include "main.h"

/**
 * @description: 开启时钟函数：开启所有时钟
 * @return {*}
 */
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

/**
 * @description: led初始化函数,设置GPIO复用和电气特性；设置GPIO输出电平
 * @return {*}
 */
void led_init(void)
{
    // 初始化GPIO的复用，使用GPIO1_IO03
    SW_MUX_GPIO1_IO03 = 0x5;
    // 设置GPIO的电气特性,
    SW_PAD_GPIO1_IO03 = 0x10B0;
    // 设置GPIO为输出
    GPIO1_GDIR = 0x00000008;
    // 设置输出低电平，会使led0点亮
    GPIO1_DR = 0x0;
}

// led开启
void led_on(void)
{
    GPIO1_DR &= ~(1<<3);
}
// led关闭
void led_off(void)
{
    GPIO1_DR |= (1<<3);
}

/**
 * @description: 延时函数
 * @param {volatile unsigned int} n需要延时的毫秒数，该延时函数并不精确
 * @return {*}
 */
void delay(volatile unsigned int n)
{
    while (n--)
    {
        volatile unsigned int one_ms_delay_num = 0x7ff;
        while (one_ms_delay_num--)
        {
        }
    }
}

/**
 * @description: 短延时函数，用于软件模拟PWM
 * @param {volatile unsigned int} n 延时周期
 * @return {*}
 */
void delay_short(volatile unsigned int n)
{
    while (n--);
}

void breathing_light_soft(void)
{
    const int period = 2000; // PWM 周期
    int i;

    while (1)
    {
        // 逐渐变亮：增加亮的时间
        for(i = 0; i < period; i++)
        {
            led_on();
            delay_short(i);
            led_off();
            delay_short(period - i);
        }
        // 逐渐变暗：减少亮的时间
        for(i = 0; i < period; i++)
        {
            led_on();
            delay_short(period - i);
            led_off();
            delay_short(i);
        }
    }
}

// TODO：用硬件PWM实现呼吸灯效果

int main(void)
{
    clk_start();
    led_init();
    breathing_light_soft();
    return 0;
}
