/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 15:59:17
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-14 22:15:15
 * @FilePath: /projects/p05-beep/user/main.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_clk.h"
#include "beep.h"
#include "bsp_delay.h"

int main(void)
{
    clk_start();
    beep_init();
    while(1)
    {
        beep_switch(1);
        delay_ms(1000);
        beep_switch(0);
        delay_ms(1000);
    }
}