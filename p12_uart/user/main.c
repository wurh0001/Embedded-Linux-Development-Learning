/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-21 22:27:41
 * @FilePath: /projects/p12_uart/user/main.c
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

int main(void)
{
    unsigned char state = 0;
    unsigned char a;

    int_init();                /* 中断初始化 */
    clk_init();                /* 初始化系统时钟 */
    clk_start();               /* 开启所有时钟 */
    delay_init();              /* 初始化延时函数 */
    led_init();                /* 初始化LED */
    beep_init();               /* 初始化蜂鸣器 */
    uart_init();              /* 初始化串口 */
    
    while(1)
    {
        uart_puts("请输入1个字符:");
		a=uart_getc();
		uart_putc(a);	//回显功能
		uart_puts("\r\n");

		//显示输入的字符
		uart_puts("您输入的字符为:");
		uart_putc(a);
		uart_puts("\r\n\r\n");
		
		state = !state;
		led_switch(state);
    }
    return 0;
}