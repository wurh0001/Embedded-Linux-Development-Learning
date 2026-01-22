CROSS_COMPILE 	?= arm-linux-gnueabihf-
TARGET		  	?= printf
OUTPUTDIR		:= output

CC 				:= $(CROSS_COMPILE)gcc
LD				:= $(CROSS_COMPILE)ld
OBJCOPY 		:= $(CROSS_COMPILE)objcopy
OBJDUMP 		:= $(CROSS_COMPILE)objdump

# 动态获取库路径
LIBGCC_FILE := $(shell $(CC) -print-libgcc-file-name)
LIBPATH := -L $(shell dirname $(LIBGCC_FILE))

INCDIRS 		:= imx6ull \
				   bsp/clk \
				   bsp/led \
				   bsp/delay  \
				   bsp/beep \
				   bsp/gpio \
				   bsp/key \
				   bsp/exit \
				   bsp/int \
				   bsp/epit_timer \
				   bsp/keyfilter \
				   bsp/uart\
				   bsp/stdio/include
				   			   
SRCDIRS			:= user \
				   bsp/clk \
				   bsp/led \
				   bsp/delay \
				   bsp/beep \
				   bsp/gpio \
				   bsp/key \
				   bsp/exit \
				   bsp/int \
				   bsp/epit_timer \
				   bsp/keyfilter \
				   bsp/uart\
				   bsp/stdio/lib
				   

# 1. 生成编译器头文件搜索路径 (-I)
#    - INCDIRS 变量是一个目录列表 (e.g., "imx6ull bsp/clk ...")。
#    - `patsubst` 函数遍历 INCDIRS 中的每个目录，并在其前面加上 "-I "。
#    - 最终，INCLUDE 变量会变成一个可以直接传递给编译器的字符串，   
INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))


# 2. 查找所有源文件 (.S 和 .c)
#    - SRCDIRS 变量是所有源代码目录的列表。
#    - `foreach` 函数遍历 SRCDIRS 中的每个目录。
#    - `wildcard` 函数在每个目录中查找匹配 *.S 或 *.c 的文件。
#    - 最终，SFILES 和 CFILES 变量会包含项目中所有源文件的完整路径列表。
SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# 3. 提取不带路径的文件名
#    - `notdir` 函数会移除文件路径，只保留文件名。
#    - 例如，如果 SFILES 是 "user/start.S"，那么 SFILENDIR 就是 "start.S"。
#    - 这是为了下一步能将所有生成的目标文件 (.o) 统一放置到 `obj/` 目录下。
SFILENDIR		:= $(notdir  $(SFILES))
CFILENDIR		:= $(notdir  $(CFILES))

# 4. 生成所有对应的目标文件 (.o) 列表
#    - `$(SFILENDIR:.S=.o)` 将文件名列表中的 ".S" 后缀替换为 ".o"。
#    - `patsubst` 函数再为每个处理后的文件名加上 "obj/" 前缀。
#    - 例如: "start.S" -> "start.o" -> "obj/start.o"。
#    - 最终，SOBJS 和 COBJS 变量就包含了所有需要生成的目标文件的路径。
SOBJS			:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))

# 5. 合并所有目标文件列表
#    - 将汇编和 C 语言的目标文件列表合并成一个总列表 OBJS。
#    - 这个 OBJS 变量将在后续的链接步骤中，作为所有依赖项被使用。
OBJS			:= $(SOBJS) $(COBJS)
# 确保启动文件 start.o 始终是第一个目标文件
OBJS 			:= obj/start.o $(filter-out obj/start.o, $(OBJS))

# 6. 设置源文件搜索路径 (VPATH)
#    - VPATH 是一个特殊的 make 变量，它告诉 make 在哪里寻找依赖文件。
#    - 当 make 处理像 `obj/main.o : main.c` 这样的规则时，它需要 `main.c` 文件。
#    - 由于设置了 VPATH，make 会自动在 SRCDIRS 列表的所有目录中去查找 `main.c`。
#    - 这是实现 "out-of-source" 构建（即源码和编译产物分离）的关键。
VPATH			:= $(SRCDIRS)

.PHONY: clean

$(OUTPUTDIR)/$(TARGET).imx: $(OUTPUTDIR)/$(TARGET).bin
	../imxdownload -g -o $(OUTPUTDIR)/ $(OUTPUTDIR)/$(TARGET).bin

$(OUTPUTDIR)/$(TARGET).bin : $(OBJS)
	mkdir -p $(OUTPUTDIR)
# 	注意顺序：目标文件在前，库路径在后，库名最后
	$(LD) -Timx6ul.lds -o $(OUTPUTDIR)/$(TARGET).elf $(OBJS) $(LIBPATH) -lgcc
	$(OBJCOPY) -O binary -S $(OUTPUTDIR)/$(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(OUTPUTDIR)/$(TARGET).elf > $(OUTPUTDIR)/$(TARGET).dis

$(SOBJS) : obj/%.o : %.S
	mkdir -p obj
# 	使用 -fno-builtin 禁用内置函数，以避免链接时出现未定义引用错误
	$(CC) -Wall -nostdlib -fno-builtin -c -O2  $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	mkdir -p obj
	$(CC) -Wall -Wa,-mimplicit-it=thumb -nostdlib -fno-builtin -c -O2  $(INCLUDE) -o $@ $<
	
clean:
	rm -rf $(OUTPUTDIR) obj
