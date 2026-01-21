/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-21 19:11:52
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-21 22:36:32
 * @FilePath: /projects/p12_uart/bsp/uart/bsp_uart.c
 * @Description: 
 * 
 * Copyright (c) 2026 by wuuua_ahu@163.com, All Rights Reserved. 
 */

#include "bsp_uart.h"

/*
 * @description : 初始化串口1,波特率为115200
 * @param		: 无
 * @return		: 无
 */
void uart_init(void)
{
    /* 1、初始化串口IO 			*/
    uart_io_init();

    /* 2、初始化UART1  			*/
    uart_disable(UART1);   /* 先关闭UART1 		*/
    uart_softreset(UART1); /* 软件复位UART1 		*/

    UART1->UCR1 = 0; /* 先清除UCR1寄存器 */

    /*
     * 设置UART的UCR1寄存器，关闭自动波特率
     * bit14: 0 关闭自动波特率检测,我们自己设置波特率
     */
    UART1->UCR1 &= ~(1 << 14);

    /*
     * 设置UART的UCR2寄存器，设置内容包括字长，停止位，校验模式，关闭RTS硬件流控
     * bit14: 1 忽略RTS引脚
     * bit8: 0 关闭奇偶校验
     * bit6: 0 1位停止位
     * bit5: 1 8位数据位
     * bit2: 1 打开发送
     * bit1: 1 打开接收
     */
    UART1->UCR2 |= (1 << 14) | (1 << 5) | (1 << 2) | (1 << 1);

    /*
     * UART1的UCR3寄存器
     * bit2: 1 必须设置为1！参考IMX6ULL参考手册3624页
     */
    UART1->UCR3 |= 1 << 2;

    /*
     * 设置波特率
     * 波特率计算公式:Baud Rate = Ref Freq / (16 * (UBMR + 1)/(UBIR+1))
     * 如果要设置波特率为115200，那么可以使用如下参数:
     * Ref Freq = 80M 也就是寄存器UFCR的bit9:7=101, 表示1分频
     * UBMR = 3124
     * UBIR =  71
     * 因此波特率= 80000000/(16 * (3124+1)/(71+1))=80000000/(16 * 3125/72) = (80000000*72) / (16*3125) = 115200
     */
    UART1->UFCR = 5 << 7; // ref freq等于ipg_clk/1=80Mhz
    UART1->UBIR = 71;
    UART1->UBMR = 3124;

#if 0
	 uart_setbaudrate(UART1, 115200, 80000000); /* 设置波特率 */
#endif

    /* 使能串口 */
    uart_enable(UART1);
}

/*
 * @description : 初始化串口1所使用的IO引脚
 * @param		: 无
 * @return		: 无
 */
void uart_io_init(void)
{
	/* 1、初始化IO复用 
     * UART1_RXD -> UART1_TX_DATA
     * UART1_TXD -> UART1_RX_DATA
	 */
	IOMUXC_SetPinMux(IOMUXC_UART1_TX_DATA_UART1_TX,0);	/* 复用为UART1_TX */
	IOMUXC_SetPinMux(IOMUXC_UART1_RX_DATA_UART1_RX,0);	/* 复用为UART1_RX */

	/* 2、配置UART1_TX_DATA、UART1_RX_DATA的IO属性 
 	*bit 16:0 HYS关闭
 	*bit [15:14]: 00 默认100K下拉
 	*bit [13]: 0 keeper功能
 	*bit [12]: 1 pull/keeper使能
 	*bit [11]: 0 关闭开路输出
 	*bit [7:6]: 10 速度100Mhz
 	*bit [5:3]: 110 驱动能力R0/6
 	*bit [0]: 0 低转换率
 	*/
	IOMUXC_SetPinConfig(IOMUXC_UART1_TX_DATA_UART1_TX,0x10B0);
	IOMUXC_SetPinConfig(IOMUXC_UART1_RX_DATA_UART1_RX,0x10B0);
}

/*
 * @description 		: 波特率计算公式，
 *    			  	  	  可以用此函数计算出指定串口对应的UFCR，
 * 				          UBIR和UBMR这三个寄存器的值
 * @param - base		: 要计算的串口。
 * @param - baudrate	: 要使用的波特率。
 * @param - srcclock_hz	:串口时钟源频率，单位Hz
 * @return		: 无
 */
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz)
{
    uint32_t numerator = 0u;		//分子
    uint32_t denominator = 0U;		//分母
    uint32_t divisor = 0U;          //最大公约数
    uint32_t refFreqDiv = 0U;       //参考频率分频系数
    uint32_t divider = 1U;          //分频系数
    uint64_t baudDiff = 0U;         //计算出的波特率与期望波特率的差值
    uint64_t tempNumerator = 0U;    //临时分子
    uint32_t tempDenominator = 0u;  //临时分母

    /* get the approximately maximum divisor */
    // 1. 初始化分子和分母，准备进行第一次分数简化
    // 目标是计算 (UBMR + 1) / (UBIR + 1) = srcclock_hz / (baudrate * 16)
    numerator = srcclock_hz;
    denominator = baudrate << 4;    // baudrate * 16
    
    // 2. 使用欧几里得算法计算 numerator 和 denominator 的最大公约数 (GCD)
    // 这一步是为了简化分数，使 UBMR 和 UBIR 的值尽可能小，以适应寄存器宽度。
    divisor = 1;
    while (denominator != 0)
    {
        divisor = denominator;
        denominator = numerator % denominator;
        numerator = divisor;
    }
    // 循环结束后，divisor 存储了 srcclock_hz 和 (baudrate * 16) 的 GCD。

    // 3. 用 GCD 简化原始分数
    // 此时，numerator 存储的是 (srcclock_hz / GCD)
    // denominator 存储的是 ((baudrate * 16) / GCD)
    // 它们代表了 (UBMR + 1) / (UBIR + 1) 的最简分数形式。
    numerator = srcclock_hz / divisor;
    denominator = (baudrate << 4) / divisor;

    /* numerator ranges from 1 ~ 7 * 64k */
    /* denominator ranges from 1 ~ 64k */
    // 4. 检查简化后的分子和分母是否仍然太大，超出寄存器可表示的范围。
    // UBIR 和 UBMR 都是 16 位寄存器，所以它们的值 (UBIR+1, UBMR+1) 最大为 65536。
    // UART_UBIR_INC_MASK 是 0xFFFF (65535)。
    // UBIR+1 对应这里的 denominator，所以不能超过 65536。
    // UBMR+1 对应这里的 numerator，但它还会被 divider 分频，所以最大值是 65536 * 7。
    if ((numerator > (UART_UBIR_INC_MASK * 7)) || (denominator > UART_UBIR_INC_MASK))
    {
        // 如果超出范围，需要进一步缩小分子和分母，同时保持它们的比例不变。
        // m: 确保 numerator / m 不超过 7 * 65535
        uint32_t m = (numerator - 1) / (UART_UBIR_INC_MASK * 7) + 1;
        // n: 确保 denominator / n 不超过 65535
        uint32_t n = (denominator - 1) / UART_UBIR_INC_MASK + 1;
        // 取 m 和 n 中较大的一个作为缩放因子 max，以确保两者都被充分缩小。
        uint32_t max = m > n ? m : n;
        numerator /= max;
        denominator /= max;
        // 避免除以0的情况（虽然对于时钟频率和波特率来说不太可能发生）
        if (0 == numerator)
        {
            numerator = 1;
        }
        if (0 == denominator)
        {
            denominator = 1;
        }
    }

    // 5. 根据最终的 numerator 计算 divider (参考时钟分频系数)。
    // divider 的选择是为了让 (numerator / divider) 能够适应 UBMR 寄存器 (16位)。
    // (numerator / divider) 必须小于等于 65536。
    divider = (numerator - 1) / UART_UBIR_INC_MASK + 1;

    // 6. 将计算出的 divider 映射到 UFCR 寄存器中 RFDIV 字段的实际值 (refFreqDiv)。
    // 这个映射是 i.MX6ULL 硬件特定的。
    // 例如，当 divider 为 1 时，表示参考时钟不分频，对应 RFDIV = 0x05。
    switch (divider)
    {
        case 1:
            refFreqDiv = 0x05;
            break;
        case 2:
            refFreqDiv = 0x04;
            break;
        case 3:
            refFreqDiv = 0x03;
            break;
        case 4:
            refFreqDiv = 0x02;
            break;
        case 5:
            refFreqDiv = 0x01;
            break;
        case 6:
            refFreqDiv = 0x00;
            break;
        case 7:
            refFreqDiv = 0x06;
            break;
        default:
            refFreqDiv = 0x05;
            break;
    }
    /* Compare the difference between baudRate_Bps and calculated baud rate.
     * Baud Rate = Ref Freq / (16 * (UBMR + 1)/(UBIR+1)).
     * baudDiff = (srcClock_Hz/divider)/( 16 * ((numerator / divider)/ denominator).
     */
    // 7. 重新计算实际将达到的波特率，并与目标波特率进行比较。
    // 这里的 tempNumerator 和 tempDenominator 用于精确计算实际波特率，避免浮点误差。
    // 实际波特率 = (srcclock_hz * denominator) / (numerator * 16)
    tempNumerator = srcclock_hz;
    tempDenominator = (numerator << 4);     // // 这里的 numerator 是经过缩放后的 N_final
    divisor = 1;
    /* get the approximately maximum divisor */
    // 再次计算 GCD，简化 (srcclock_hz) 和 (numerator * 16) 的分数
    while (tempDenominator != 0)
    {
        divisor = tempDenominator;
        tempDenominator = tempNumerator % tempDenominator;
        tempNumerator = divisor;
    }

    // 简化后的分子和分母
    tempNumerator = srcclock_hz / divisor;
    tempDenominator = (numerator << 4) / divisor;

    // 计算实际波特率
    // 实际波特率 = (tempNumerator * denominator) / tempDenominator
    // 这里的 denominator 是经过缩放后的 D_final
    baudDiff = (tempNumerator * denominator) / tempDenominator;

    // 计算实际波特率与目标波特率的绝对差值
    baudDiff = (baudDiff >= baudrate) ? (baudDiff - baudrate) : (baudrate - baudDiff);

    // 8. 如果实际波特率与目标波特率的误差在 3% 以内，则应用这些设置。
    if (baudDiff < (baudrate / 100) * 3)
    {
        base->UFCR &= ~UART_UFCR_RFDIV_MASK;
        base->UFCR |= UART_UFCR_RFDIV(refFreqDiv);
        base->UBIR = UART_UBIR_INC(denominator - 1); //要先写UBIR寄存器，然后在写UBMR寄存器，3592页 
        base->UBMR = UART_UBMR_MOD(numerator / divider - 1);
    }
}

/*
 * @description : 关闭指定的UART
 * @param - base: 要关闭的UART
 * @return		: 无
 */
void uart_disable(UART_Type *base)
{
	base->UCR1 &= ~(1<<0);	
}

/*
 * @description : 打开指定的UART
 * @param - base: 要打开的UART
 * @return		: 无
 */
void uart_enable(UART_Type *base)
{
	base->UCR1 |= (1<<0);	
}

/*
 * @description : 复位指定的UART
 * @param - base: 要复位的UART
 * @return		: 无
 */
void uart_softreset(UART_Type *base)
{
	base->UCR2 &= ~(1<<0); 			/* UCR2的bit0为0，复位UART  	  	*/
	while((base->UCR2 & 0x1) == 0); /* 等待复位完成 					*/
}

/*
 * @description : 发送一个字符
 * @param - c	: 要发送的字符
 * @return		: 无
 */
void putc(unsigned char c)
{
	while(((UART1->USR2 >> 3) &0X01) == 0);/* 等待上一次发送完成 */
	UART1->UTXD = c & 0XFF; 				/* 发送数据 */
}

/*
 * @description : 发送一个字符串
 * @param - str	: 要发送的字符串
 * @return		: 无
 */
void puts(const char *str)
{
	while(*str)
		putc(*str++);
}

/*
 * @description : 接收一个字符
 * @param 		: 无
 * @return		: 接收到的字符
 */
unsigned char getc(void)
{
	while((UART1->USR2 & 0x1) == 0);/* 等待接收完成 */
	return UART1->URXD;				/* 返回接收到的数据 */
}

/*
 * @description : 防止编译器报错
 * @param 		: 无
 * @return		: 无
 */
void raise(int sig_nr) 
{

}
