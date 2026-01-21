/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-14 16:11:35
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-19 21:39:27
 * @FilePath: /projects/p08_interruption/bsp/beep/beep.c
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#include "bsp_beep.h"

void beep_init(void)
{
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01,0x10B0);
    GPIO5->GDIR |= (1 << 1);
    GPIO5->DR |= (1 << 1);
}

/**
 * @description: 
 * @param {int16_t} status：0：关闭蜂鸣器；1：打开
 * @return {*}
 */
void beep_switch(int16_t status)
{
    if(status == 0)
    {
        GPIO5->DR |= (1<<1);
    }
    else
    {
        GPIO5->DR &= ~(1<<1);
    }
}
