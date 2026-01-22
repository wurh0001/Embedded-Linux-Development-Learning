/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 16:48:53
 * @FilePath: /projects/p13_printf/user/main.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_clk.h"
#include "bsp_beep.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_int.h"
#include "bsp_key.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"
#include "stdio.h"

int main(void)
{
    unsigned char state = LED_OFF;
    int a, b;

    int_init();                /* 中断初始化 */
    clk_init();                /* 初始化系统时钟 */
    clk_start();               /* 开启所有时钟 */
    delay_init();              /* 初始化延时函数 */
    led_init();                /* 初始化LED */
    // beep_init();               /* 初始化蜂鸣器 */
    uart_init();              /* 初始化串口 */

    led_switch(state);         /* 确保初始状态为灭 */
    delayms(10);
    
    while(1)
    {
        printf("\r\n============================\r\n");
        printf("this is used to test printf if long string can be sent completely, at begining,abcdefghijklmnopqrstuvwxyz\r\n");
        printf("输入两个整数\r\n");
        printf("使用空格隔开:\r\n");
        scanf("%d %d", &a, &b);                              /* 输入两个整数 */
        printf("\r\n数据%d + %d = %d\r\n\r\n", a, b, a + b); /* 输出两个数相加的和 */

        state = !state;                                     /* 翻转状态 */
        led_switch(state);
        printf(" LED状态已切换为: %s\r\n\r\n", state ? "ON" : "OFF");
        printf("this is used to test printf if long string can be sent completely\r\n");
        printf("这是为了测试printf对汉字长字符串的支持情况\r\n");
    }
    return 0;
}