/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 22:10:13
 * @FilePath: /projects/p14_lcd/user/main.c
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
#include "bsp_lcd.h"
#include "bsp_lcdapi.h"

/* 背景颜色索引 */
unsigned int backcolor[10] = {
    LCD_BLUE, LCD_GREEN, LCD_RED, LCD_CYAN, LCD_YELLOW,
    LCD_LIGHTBLUE, LCD_DARKBLUE, LCD_WHITE, LCD_BLACK, LCD_ORANGE

};

int main(void)
{
    unsigned char state = LED_OFF;
    unsigned char index = 0;

    int_init();     /* 中断初始化 */
    clk_init();     /* 初始化系统时钟 */
    clk_start();    /* 开启所有时钟 */
    delay_init();   /* 初始化延时函数 */
    led_init();     /* 初始化LED */
    // beep_init(); /* 初始化蜂鸣器 */
    uart_init();    /* 初始化串口 */
    lcd_init();     /* 初始化LCD */

    tftlcd_dev.forecolor = LCD_RED;     /* 设置前景色为红色 */

    led_switch(state);  /* 确保初始状态为灭 */
    delayms(10);

    while (1)
    {
        lcd_clear(backcolor[index]);
        delayms(1);
        lcd_show_string(10, 40, 260, 32, 32, (char *)"ALPHA IMX6U");
        lcd_show_string(10, 80, 240, 24, 24, (char *)"RGBLCD TEST");
        lcd_show_string(10, 110, 240, 16, 16, (char *)"ATOM@ALIENTEK");
        lcd_show_string(10, 130, 240, 12, 12, (char *)"2019/8/14");
        index++;
        if (index == 10)
            index = 0;
        state = !state;
        led_switch(state); /* 切换LED状态 */
        delayms(500);      /* 延时500ms */

        #if 1
        // index++;
        if(index == 10)
            index = 0;
        lcd_fill(0, 300, 1023, 599, backcolor[index]);
        lcd_show_string(800,10,240,32,32,(char*)"INDEX=");  /*显示字符串				  */
        lcd_shownum(896,10, index, 2, 32); 					/* 显示数字，叠加显示	*/
        
        state = !state;
        led_switch(state);
        delayms(1000);	/* 延时一秒	*/
        #endif
    }
    return 0;
}