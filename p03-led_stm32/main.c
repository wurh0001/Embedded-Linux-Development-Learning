/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-11 23:52:25
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-12 22:36:22
 * @FilePath: /projects/p03-led_stm32/main.c
 * @Description: 本实验为点亮led灯，通过类似stm32通过宏定义的指针来操作寄存器
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "imx6ul.h"

/**
 * @description: 
 * @return {*}
 */
void clk_start(void)
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

/**
 * @description: 
 * @return {*}
 */
void led_init(void)
{
    IOMUX_SW_MUX->GPIO1_IO03 = 0x5;
    IOMUX_SW_PAD->GPIO1_IO03 = 0x10B0;
    GPIO1->GDIR = 0x00000008;
    GPIO1->DR &= ~(1 << 3);
}

void led_on(void)
{
    GPIO1->DR &= ~(1 << 3);
}

void led_off(void)
{
    GPIO1->DR |= (1 << 3);
}

/**
 * @description: 实现微秒延时
 * @param {volatile unsigned int} us
 * @return {*}
 */
void delay_us(volatile unsigned int us)
{
    volatile unsigned int i;
    while(us--)
    {
        /* 循环次数取决于CPU时钟频率，建议使用示波器校准 */
        for(i = 0; i < 40; i++)
        {
            __asm("nop");
        }
    }
}

/**
 * @description: 实现毫秒延时
 * @param {volatile unsigned int} ms
 * @return {*}
 */
void delay_ms(volatile unsigned int ms)
{
    unsigned int i = 0x7ff;
    while(ms--)
    {
        while(i--)
        {
            __asm("nop");
        }
    }
}

/**
 * @description: 通过软件模拟pwm实现呼吸灯效果
 * @return {*}
 */
void breathing_led(void)
{
    int i = 0;
    unsigned int period = 2000;
    while(1)
    {
        for(i = 0; i < period; i++)
        {
            led_on();
            delay_us(i);
            led_off();
            delay_us(period - i);
        }
        for(i = 0; i < period; i++)
        {
            led_on();
            delay_us(period - i);
            led_off();
            delay_us(i);
        }
    }
}

int main(void)
{
    clk_start();
    led_init();
    breathing_led();
    return 0;
}
