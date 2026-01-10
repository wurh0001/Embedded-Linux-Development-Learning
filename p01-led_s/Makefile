led.bin:led.s
	arm-linux-gnueabihf-gcc -g -c led.s -o led.o	# 交叉编译为.o目标文件 -c只编译不链接
	arm-linux-gnueabihf-ld -Ttext 0X87800000 led.o -o led.elf	# 将.o文件链接为elf文件，并设置起始地址
	arm-linux-gnueabihf-objcopy -O binary -S -g led.elf led.bin	# 将elf文件转为bin文件
	arm-linux-gnueabihf-objdump -D led.elf > led.dis	# 反汇编

clean:
	rm -rf *.o led.bin led.elf led.dis