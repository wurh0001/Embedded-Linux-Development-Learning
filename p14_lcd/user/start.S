/***************************************************************
Copyright © zuozhongkai Co., Ltd. 1998-2019. All rights reserved.
文件名	: 	 start.s
作者	   : 左忠凯
版本	   : V1.0
描述	   : ZERO-I.MX6UL/I.MX6ULL开发板启动文件，完成C环境初始化，
		 C环境初始化完成以后跳转到C代码。
其他	   : 无
论坛 	   : www.wtmembed.com
日志	   : 初版V1.0 2019/1/3 左忠凯修改
		 V2.0 2019/1/4 左忠凯修改
		 添加中断相关定义
**************************************************************/

.global _start  				/* 全局标号 */

/*
 * 描述：	_start函数，首先是中断向量表的创建
 * 参考文档:ARM Cortex-A(armV7)编程手册V4.0.pdf P42，3 ARM Processor Modes and Registers（ARM处理器模型和寄存器）
 * 		 	ARM Cortex-A(armV7)编程手册V4.0.pdf P165 11.1.1 Exception priorities(异常)
 */
_start:
	/*这是系统运行的第一条指令。它跳转到 Reset_Handler，负责初始化 CPU、关闭看门狗、设置栈、初始化 DDR 等，最后跳转到 C 语言的 main 函数。*/
	ldr pc, =Reset_Handler		/* 复位中断，使用绝对跳转，将Reset_Handler地址加载到程序计数器（pc）*/	
	ldr pc, =Undefined_Handler	/* 未定义中断*/
	ldr pc, =SVC_Handler		/* SVC(Supervisor)中断*/
	ldr pc, =PrefAbort_Handler	/* 预取终止中断*/
	ldr pc, =DataAbort_Handler	/* 数据终止中断*/
	ldr	pc, =NotUsed_Handler	/* 未使用中断*/
	ldr pc, =IRQ_Handler		/* IRQ中断*/
	ldr pc, =FIQ_Handler		/* FIQ(快速中断)未定义中断*/

/* 复位中断 */	
Reset_Handler:

	cpsid i						/* 关闭全局中断，其实就是设置寄存器CPSR的 I=1 */

	/* 关闭I,DCache和MMU 
	 * 采取读-改-写的方式。
	 */
	mrc     p15, 0, r0, c1, c0, 0     /* 读取CP15的C1寄存器到R0中       		        	*/
    bic     r0,  r0, #(0x1 << 12)     /* 清除C1寄存器的bit12位(I位)，关闭I Cache            	*/
    bic     r0,  r0, #(0x1 <<  2)     /* 清除C1寄存器的bit2(C位)，关闭D Cache    				*/
    bic     r0,  r0, #0x2             /* 清除C1寄存器的bit1(A位)，关闭对齐						*/
    bic     r0,  r0, #(0x1 << 11)     /* 清除C1寄存器的bit11(Z位)，关闭分支预测					*/
    bic     r0,  r0, #0x1             /* 清除C1寄存器的bit0(M位)，关闭MMU				       	*/
    mcr     p15, 0, r0, c1, c0, 0     /* 将r0寄存器中的值写入到CP15的C1寄存器中	 				*/

	
	#if 0
		/* 汇编版本设置中断向量表偏移 */
		ldr r0, =0X87800000

		dsb
		isb
		mcr p15, 0, r0, c12, c0, 0
		dsb
		isb
	#endif
    
	/* 设置各个模式下的栈指针，
	 * 注意：IMX6UL的堆栈是向下增长的！
	 * 堆栈指针地址一定要是4字节地址对齐的！！！
	 * DDR范围:0X80000000~0X9FFFFFFF
	 */
	/* CPU进入IRQ模式 */
	mrs r0, cpsr		/*CPSR 寄存器不能直接通过立即数修改，必须采用“读出-修改-写入”的步骤。*/
	bic r0, r0, #0x1f 	/* 将r0寄存器中的低5位清零，也就是cpsr的M0~M4，这5位就是CPU模式选择位 */
	orr r0, r0, #0x12 	/* r0或上0x12,表示使用IRQ模式					*/
	msr cpsr, r0		/* 将r0 的数据写入到cpsr中，CPU 正式切换进入 IRQ 模式。此时，CPU 访问的 sp 寄存器自动变成了 sp_irq（IRQ 模式私有的栈指针）*/
	ldr sp, =0x80600000	/* 设置IRQ模式下的栈首地址为0X80600000,大小为2MB */

	/* 进入SYS模式 */
	mrs r0, cpsr
	bic r0, r0, #0x1f 	/* 位清除（Bit Clear），将r0寄存器中的低5位清零，也就是cpsr的M0~M4	*/
	orr r0, r0, #0x1f 	/* r0或上0x1f,表示使用SYS模式					*/
	msr cpsr, r0		/* 将r0 的数据写入到cpsr_c中 					*/
	ldr sp, =0x80400000	/* 设置SYS模式下的栈首地址为0X80400000,大小为2MB */

	/* 进入SVC模式 */
	mrs r0, cpsr
	bic r0, r0, #0x1f 	/* 将r0寄存器中的低5位清零，也就是cpsr的M0~M4 	*/
	orr r0, r0, #0x13 	/* r0或上0x13,表示使用SVC模式					*/
	msr cpsr, r0		/* 将r0 的数据写入到cpsr_c中 					*/
	ldr sp, =0X80200000	/* 设置SVC模式下的栈首地址为0X80200000,大小为2MB */

	cpsie i				/* 打开全局中断 */
	#if 0
		/* 使能IRQ中断 */
		mrs r0, cpsr		/* 读取cpsr寄存器值到r0中 			*/
		bic r0, r0, #0x80	/* 将r0寄存器中bit7清零，也就是CPSR中的I位清零，表示允许IRQ中断 */
		msr cpsr, r0		/* 将r0重新写入到cpsr中 			*/
	#endif

	b main				/* 跳转到main函数 			 	*/

/* 未定义中断 */
Undefined_Handler:
	ldr r0, =Undefined_Handler
	bx r0

/* SVC中断 */
SVC_Handler:
	ldr r0, =SVC_Handler
	bx r0

/* 预取终止中断 */
PrefAbort_Handler:
	ldr r0, =PrefAbort_Handler	
	bx r0

/* 数据终止中断 */
DataAbort_Handler:
	ldr r0, =DataAbort_Handler
	bx r0

/* 未使用的中断 */
NotUsed_Handler:

	ldr r0, =NotUsed_Handler
	bx r0

/* IRQ中断！重点！！！！！ */
IRQ_Handler:
	/* 1. 保存现场 */
    push {lr}               /* 保存 IRQ 模式下的 LR (返回地址) */
    push {r0-r3, r12}       /* 保存 AAPCS 规定的调用者保存寄存器 (R0-R3, R12) */
    mrs r0, spsr            /* 读取 SPSR (保存了中断发生前的 CPSR 状态) */
    push {r0}               /* 将 SPSR 保存到栈中 */

	/* 2. 读取 GIC 控制器，获取中断号 */
	mrc p15, 4, r1, c15, c0, 0 /* 从CP15的C0(CBAR)寄存器内的值到R1寄存器中，CBAR 保存了 GIC 的基地址 (PERIPHBASE)
								* 参考文档ARM Cortex-A(armV7)编程手册V4.0.pdf P49
								* Cortex-A7 Technical ReferenceManua.pdf P68 P138
								*/							
	add r1, r1, #0X2000			/* GIC基地址加0X2000，也就是GIC的CPU接口端基地址 */
	ldr r0, [r1, #0XC]			/* GIC的CPU接口端基地址加0X0C就是GICC_IAR寄存器，
								 * GICC_IAR寄存器保存这当前发生中断的中断号，我们要根据
								 * 这个中断号来绝对调用哪个中断服务函数
								 */
	push {r0, r1}				/* 保存r0,r1 */
	
	/* 3. 切换到 SVC 模式并执行 C 函数 */
	cps #0x13					/* 进入SVC模式，允许其他中断再次进去 */
	
	push {lr}					/* 保存SVC模式的lr寄存器 */
	ldr r2, =system_irqhandler	/* 加载C语言中断处理函数到r2寄存器中*/
	blx r2						/* 运行C语言中断处理函数，带有一个参数，保存在R0寄存器中 */

	pop {lr}					/* 执行完C语言中断服务函数，lr出栈 */
	cps #0x12					/* 进入IRQ模式 */

	/* 4. 通知 GIC 中断完成 (EOI) */
	pop {r0, r1}				
	str r0, [r1, #0X10]			/* 中断执行完成，写EOIR */

	/* 5. 恢复现场并返回 */
	pop {r0}						
	msr spsr_cxsf, r0			/* 恢复spsr */

	pop {r0-r3, r12}			/* r0-r3,r12出栈 */
	pop {lr}					/* lr出栈 */
	subs pc, lr, #4				/* 将lr-4赋给pc */
	
	

/* FIQ中断 */
FIQ_Handler:

	ldr r0, =FIQ_Handler	
	bx r0									

