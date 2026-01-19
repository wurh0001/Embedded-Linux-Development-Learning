/*
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-18 23:02:55
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-19 23:28:04
 * @FilePath: /projects/p08_interruption/bsp/gpio/bsp_gpio.c
 * @Description: 
 * 
 * Copyright (c) 2026 by wurh0001 wuuua_ahu@163.com, All Rights Reserved. 
 */

#include "bsp_gpio.h"

/*
 * @description		: GPIO初始化。设置GPIO的输入输出属性和中断属性。
 * @param - base	: 要初始化的GPIO组。
 * @param - pin		: 要初始化GPIO在组内的编号。
 * @param - config	: GPIO配置结构体。
 * @return 			: 无
 */
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
	// 将中断屏蔽寄存器IMR对应位清0，禁止中断
	base->IMR &= ~(1U << pin);
	
	if(config->direction == kGPIO_DigitalInput) /* GPIO作为输入 */
	{
		// 将GDIR对应位置0，设置为输入
		base->GDIR &= ~(1U << pin);
	}
	else										/* 输出 */
	{
		// 将GDIR对应位置1，设置为输出
		base->GDIR |= (1U << pin);
		gpio_pinwrite(base,pin, config->outputLogic);	/* 设置默认输出电平 */
	}
	gpio_intconfig(base, pin, config->interruptMode);	/* 中断功能配置 */
}

/*
 * @description	 : 读取指定GPIO的电平值 。
 * @param - base	 : 要读取的GPIO组。
 * @param - pin	 : 要读取的GPIO脚号。
 * @return 		 : 无
 */
 int gpio_pinread(GPIO_Type *base, int pin)
 {
	 return (((base->DR) >> pin) & 0x1);
 }

/*
 * @description	 : 指定GPIO输出高或者低电平 。
 * @param - base	 : 要输出的的GPIO组。
 * @param - pin	 : 要输出的GPIO脚号。
 * @param - value	 : 要输出的电平，1 输出高电平， 0 输出低低电平
 * @return 		 : 无
 */
void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
	 if (value == 0U)
	 {
		 base->DR &= ~(1U << pin); /* 输出低电平 */
	 }
	 else
	 {
		 base->DR |= (1U << pin); /* 输出高电平 */
	 }
}

/*
 * @description  			: 设置GPIO的中断配置功能
 * @param - base 			: 要配置的IO所在的GPIO组。
 * @param - pin  			: 要配置的GPIO脚号。
 * @param - pinInterruptMode: 中断模式，参考枚举类型gpio_interrupt_mode_t
 * @return		 			: 无
 */
void gpio_intconfig(GPIO_Type* base, unsigned int pin, gpio_interrupt_mode_t pin_int_mode)
{
	volatile uint32_t *icr;
	uint32_t icrShift;

	icrShift = pin;
	
	// 先将 EDGE_SEL 中对应引脚的位清零。这意味着默认情况下，中断触发方式将由 ICR 寄存器决定，除非用户明确选择了双边沿模式。
	base->EDGE_SEL &= ~(1U << pin);

	// 确定使用 ICR1 还是 ICR2 寄存器；将ICR寄存器对应位置指针赋值给icr
	if(pin < 16) 	/* 低16位 */
	{
		icr = &(base->ICR1);
	}
	else			/* 高16位 */
	{
		icr = &(base->ICR2);
		icrShift -= 16;
	}
	switch(pin_int_mode)
	{
		// 低电平触发，写入00
		case(kGPIO_IntLowLevel):
			*icr &= ~(3U << (2 * icrShift));
			break;
		
		// 高电平触发，写入01
		case(kGPIO_IntHighLevel):
			*icr = (*icr & (~(3U << (2 * icrShift)))) | (1U << (2 * icrShift));
			break;
		
		// 上升沿触发，写入10
		case(kGPIO_IntRisingEdge):
			*icr = (*icr & (~(3U << (2 * icrShift)))) | (2U << (2 * icrShift));
			break;
		
		// 下降沿触发，写入11
		case(kGPIO_IntFallingEdge):
			*icr |= (3U << (2 * icrShift));
			break;

		// 既有上升沿又有下降沿触发，中断边沿选择寄存器EDGE_SEL对应位置1
		case(kGPIO_IntRisingOrFallingEdge):
			base->EDGE_SEL |= (1U << pin);
			break;

		default:
			break;
	}
}


/*
 * @description  			: 使能GPIO的中断功能
 * @param - base 			: 要使能的IO所在的GPIO组。
 * @param - pin  			: 要使能的GPIO在组内的编号。
 * @return		 			: 无
 */
void gpio_enableint(GPIO_Type* base, unsigned int pin)
{ 
    base->IMR |= (1 << pin);
}

/*
 * @description  			: 禁止GPIO的中断功能
 * @param - base 			: 要禁止的IO所在的GPIO组。
 * @param - pin  			: 要禁止的GPIO在组内的编号。
 * @return		 			: 无
 */
void gpio_disableint(GPIO_Type* base, unsigned int pin)
{ 
    base->IMR &= ~(1 << pin);
}

/*
 * @description  			: 清除中断标志位(写1清除)
 * @param - base 			: 要清除的IO所在的GPIO组。
 * @param - pin  			: 要清除的GPIO掩码。
 * @return		 			: 无
 */
void gpio_clearintflags(GPIO_Type* base, unsigned int pin)
{
    base->ISR |= (1 << pin);
}


