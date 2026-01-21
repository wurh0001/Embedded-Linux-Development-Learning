/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-21 19:11:52
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-21 22:06:53
 * @FilePath: /projects/p12_uart/bsp/uart/bsp_uart.h
 * @Description: 
 * 
 * Copyright (c) 2026 by wuuua_ahu@163.com, All Rights Reserved. 
 */
#ifndef _BSP_UART_H
#define _BSP_UART_H

#include "imx6ull.h"

/* 函数声明 */
void uart_init(void);
void uart_io_init(void);
void uart_disable(UART_Type *base);
void uart_enable(UART_Type *base);
void uart_softreset(UART_Type *base);
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz);
void uart_putc(unsigned char c);
void uart_puts(const char *str);
unsigned char uart_getc(void);
void raise(int sig_nr);


#endif
