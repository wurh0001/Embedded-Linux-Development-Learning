CROSS_COMPILE ?= arm-linux-gnueabihf-
CC            := $(CROSS_COMPILE)gcc
LD            := $(CROSS_COMPILE)ld
OBJCOPY       := $(CROSS_COMPILE)objcopy
OBJDUMP       := $(CROSS_COMPILE)objdump

LINK_ADDR     := 0X87800000
OBJS          := start.o main.o

load.imx: ledc.bin
	../imxdownload -g ledc.bin

ledc.bin: $(OBJS)
# 使用imx6ull.lds文件自定义程序编译位置
	$(LD) -Timx6ull.lds -o ledc.elf $^
# 	$(LD) -Ttext $(LINK_ADDR) -o ledc.elf $^
	$(OBJCOPY) -O binary -S ledc.elf $@
	$(OBJDUMP) -D -m arm ledc.elf > ledc.dis

# 兼容汇编文件拓展名大小写，将汇编文件编译为.o文件
%.o:%.s
	$(CC) -Wall -nostdlib -c -o $@ $<

%.o:%.S
	$(CC) -Wall -nostdlib -c -o $@ $<

%.o:%.c
	$(CC) -Wall -nostdlib -c -o $@ $<

# 显式添加头文件依赖
# main.o: main.h

.PHONY: clean
clean:
	rm -rf *.o ledc.bin ledc.elf ledc.dis load.imx