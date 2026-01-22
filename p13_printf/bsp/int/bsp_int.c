#include "bsp_int.h"
/***************************************************************
Copyright © zuozhongkai Co., Ltd. 1998-2019. All rights reserved.
文件名	: 	 bsp_int.c
作者	   : 左忠凯
版本	   : V1.0
描述	   : 中断驱动文件。
其他	   : 无
论坛 	   : www.wtmembed.com
日志	   : 初版V1.0 2019/1/4 左忠凯创建
***************************************************************/

/* 中断嵌套计数器 */
static unsigned int irqNesting;

/* 中断服务函数表 */
// 160个中断处理函数结构体
static sys_irq_handle_t irqTable[NUMBER_OF_INT_VECTORS];

/*
 * @description	: 中断初始化函数
 * @param		: 无
 * @return 		: 无
 */
void int_init(void)
{
	GIC_Init(); 						/* 初始化GIC，硬件初始化，包括……*/
	system_irqtable_init();				/* 初始化中断表 */
	__set_VBAR((uint32_t)0x87800000); 	/* 中断向量表偏移，偏移到起始地址 */
}

/*
 * @description	: 初始化中断服务函数表 
 * @param		: 无
 * @return 		: 无
 */
void system_irqtable_init(void)
{
	unsigned int i = 0;
	irqNesting = 0;
	
	/* 先将所有的中断服务函数设置为默认值 */
	// 循环遍历所有中断号，并将每个中断号对应的中断服务函数设置为默认的中断处理函数 default_irqhandler，参数设置为 NULL。
	// 这样做的目的是确保在系统启动时，每个中断号都有一个有效的处理函数，防止出现未定义行为。
	for(i = 0; i < NUMBER_OF_INT_VECTORS; i++)
	{
		system_register_irqhandler((IRQn_Type)i,default_irqhandler, NULL);
	}
}

/*
 * @description			: 给指定的中断号注册中断服务函数 
 * @param - irq			: 要注册的中断号
 * @param - handler		: 要注册的中断处理函数
 * @param - usrParam	: 中断服务处理函数参数
 * @return 				: 无
 */
void system_register_irqhandler(IRQn_Type irq, system_irq_handler_t handler, void *userParam) 
{
	irqTable[irq].irqHandler = handler;
  	irqTable[irq].userParam = userParam;
}

/*
 * @description			: C语言中断服务函数，irq汇编中断服务函数会
 						  调用此函数，此函数通过在中断服务列表中查
 						  找指定中断号所对应的中断处理函数并执行。
 * @param - giccIar		: 中断号
 * @return 				: 无
 */
void system_irqhandler(unsigned int giccIar)
{

	// GIC v2 规范中，IAR 寄存器的低 10 位（Bit 0~9）表示 中断 ID (Interrupt ID)。
	// Bit 10~12 表示 CPU ID（在多核系统中区分是哪个 CPU 触发的），这里通过按位与 0x3FF 将其屏蔽，只取出纯粹的中断号 intNum。
	uint32_t intNum = giccIar & 0x3FFUL;

	/* 检查中断号是否符合要求 */
	// 1023 是 GIC 规范中保留的 Spurious Interrupt ID，表示没有有效的中断请求。
	// 当 CPU 响应中断请求读取 IAR 寄存器时，如果此时没有任何挂起的中断（例如干扰信号消失，或者被其他更高优先级中断抢占处理了），GIC 就会返回 1023。此时直接返回，不做处理。
	// 另外，如果中断号大于等于 NUMBER_OF_INT_VECTORS（即超出定义的中断范围），也直接返回，不做处理。
	if ((intNum == 1023) || (intNum >= NUMBER_OF_INT_VECTORS))
	{
		return;
	}

	// 这是一个全局静态变量，用于记录当前进入了多少层中断。
	// 仅仅增加这个变量并不会开启中断嵌套功能。在 Cortex-A7 中，进入 IRQ 模式时硬件会自动禁止中断（CPSR 的 I 位置 1）。
	// 如果要支持真正的中断嵌套（即在处理一个中断时允许被更高优先级的中断打断），需要在汇编入口或此函数中显式地重新使能中断（CPSIE I），这通常比较复杂，简单的裸机系统一般不开启嵌套。
	irqNesting++; /* 中断嵌套计数器加一 */

	/* 根据传递进来的中断号，在irqTable中调用确定的中断服务函数*/
	irqTable[intNum].irqHandler(intNum, irqTable[intNum].userParam);

	irqNesting--; /* 中断执行完成，中断嵌套寄存器减一 */
}

/*
 * @description			: 默认中断服务函数
 * @param - giccIar		: 中断号
 * @param - usrParam	: 中断服务处理函数参数
 * @return 				: 无
 */
void default_irqhandler(unsigned int giccIar, void *userParam) 
{
	while(1) 
  	{
   	}
}



