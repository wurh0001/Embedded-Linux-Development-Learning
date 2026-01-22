/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-19 23:35:52
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-19 23:38:15
 * @FilePath: /projects/p08_interruption/bsp/key/bsp_key.h
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef _BSP_KEY_H
#define _BSP_KEY_H
#include "imx6ull.h"


/* 定义按键值 */
enum keyvalue{
	KEY_NONE   = 0,
	KEY0_VALUE,
	KEY1_VALUE,
	KEY2_VALUE,
};

/* 函数声明 */
void key_init(void);
int key_getvalue(void);


#endif
