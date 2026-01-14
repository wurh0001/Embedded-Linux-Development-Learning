#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "imxdownload.h"

#define SHELLCMD_LEN	(512)
#define BIN_OFFSET		(3072)

/* 此宏指明是否打印u-boot.imx的IVT DCD表信息，不同的开发板其IVT和DCD
 * 表的数据是不同的，因此需要获取所使用的开发板的IVT和DCD表信息，最
 * 简单的方法就是读取开发板配套资料里面的u-boot.imx的前1KB数据，理论上
 * 应该读取3KB的数据，但是表信息远远没有3K这么多，因此读1KB即可 
 */
#define PRINT_TAB		0	
/*
 * 介绍： 此软件是针对NXP的IMX6U系列芯片的，软件用来烧写bin文件到SD卡里面，
 *        本软件会自动添加IVT、DCD等信息到原始的bin文件里面，主要用于裸机和uboot的烧写。
 * 使用方法： 1、编译好原始的二进制bin文件，如，u-boot.bin等，并将编译好的.bin文件和本
 *             软件放置到同一个目录下！！！！
 *        	2、执行命令sudo ./imxdownload <soucre_bin> <sd_device>
 *             如烧写u-boot.bin到/dev/sdd中即可使用如下所示命令:
 *             sudo ./imxdownload u-boot.bin /dev/sdd
 * 			3、修改：添加参数实现烧录可选择，当加入-g参数时，只生成load.imx文件，当加入-w参数时生成并烧录
 * 				示例：sudo ./imxdownload -g led.bin 	\   sudo ./imxdownload -w led.bin /dev/disk6
 */

/*
 * 输出一些信息
 */
void message_print(void)
{	
	printf("I.MX6ULL bin download software\r\n");
	// printf("Edit by:zuozhongkai\r\n");
	// printf("Date:2019/6/10\r\n");
	printf("Version:V1.2\r\n");
	// printf("log:V1.0 initial version,just support 512MB DDR3\r\n");
	// printf("    V1.1 and support 256MB DDR3\r\n");
	printf("    V1.2 supports whether to enable burning\r\n");
}

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned char *buf;
	unsigned char *cmdbuf;
	int nbytes, filelen;
	int i = 0, j = 0;
	int ddrsize = 0; /* 0为512MB，1为256MB，2为128MB...... */

	message_print();

	if(argc < 2){
		printf("Error Usage! Reference Below:\r\n");
		printf("sudo ./%s <-512m or -256m> <-g or -w> [-o <output_imx>] <source_bin> [sd_device]\r\n", argv[0]);
		return -1;
	}

	/* 查找参数，获取DDR容量 */
	int do_write = 1; /* default: write to sd device */
	char *source_bin = NULL;
	char *sd_device = NULL;
	char *output_imx = "load.imx";
	for(i = 1; i < argc; i++)
	{
		char *param = argv[i];
		if(param[0] == '-') {
			if(strcmp(param, "-256m") == 0) 		/* 256MB */
				ddrsize = 1;
			else if(strcmp(param, "-512m") == 0)	/* 512MB */
				ddrsize = 0;
			else if(strcmp(param, "-g") == 0)		/* generate only */
				do_write = 0;
			else if(strcmp(param, "-w") == 0)		/* write to sd */
				do_write = 1;
			else if(strcmp(param, "-o") == 0) {
				i++;
				if(i >= argc) {
					printf("Error: -o option requires an argument\r\n");
					return -1;
				}
				int len = strlen(argv[i]);
				if(len > 0 && argv[i][len - 1] == '/') {
					static char path_buf[SHELLCMD_LEN];
					snprintf(path_buf, sizeof(path_buf), "%sload.imx", argv[i]);
					output_imx = path_buf;
				} else {
					output_imx = argv[i];
				}
			}
			continue;
		}
		if(source_bin == NULL)
			source_bin = param;
		else if(sd_device == NULL)
			sd_device = param;
	}
	if(source_bin == NULL || (do_write && sd_device == NULL)){
		printf("Error Usage! Reference Below:\r\n");
		printf("sudo ./%s <-512m or -256m> <-g or -w> [-o <output_imx>] <source_bin> [sd_device]\r\n", argv[0]);
		return -1;
	}

	/* 打开bin文件 */
	fp = fopen(source_bin, "rb"); /* 以二进制只读方式打开bin文件 */
	if(fp == NULL){
		printf("Can't Open file %s\r\n", source_bin);
		return -1;
	}
	
	/* 获取bin文件长度 */
	fseek(fp, 0L, SEEK_END);
	filelen = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	printf("file %s size = %dBytes\r\n", source_bin, filelen);
	
	/* 读取bin文件到缓冲区buf中 */
	buf = malloc(filelen + BIN_OFFSET);
	if(buf == NULL){
		printf("Mem Malloc Failed!\r\n");
		fclose(fp);
		return -1;
	}
	memset(buf, 0, filelen + BIN_OFFSET); /* 清零 */
	/* 读取bin源码文件 */
	fread(buf + BIN_OFFSET, 1, filelen, fp);

	/* 关闭文件 */
	fclose(fp);

#if PRINT_TAB
	printf("IVT DCD Table:\r\n");
	for(i = 0; i < 1024/32; i++){
		for(j = 0; j < 8; j++)
		{
			printf("0X%08X,",*(int *)(buf + BIN_OFFSET + (((i * 8) + j) * 4)));
		}
		printf("\r\n");
	}	
	free(buf);
	return 0;
#endif
	
	/* 添加IVT DCD等表信息到bin文件里面 */
	if(ddrsize == 0) {		/* 512MB */
		printf("Board DDR SIZE: 512MB\r\n");
		memcpy(buf, imx6_512mb_ivtdcd_table, sizeof(imx6_512mb_ivtdcd_table));
	}
	else if (ddrsize == 1) {	/* 256MB */
		printf("Board DDR SIZE: 256MB\r\n");
		memcpy(buf, imx6_256mb_ivtdcd_table, sizeof(imx6_256mb_ivtdcd_table));
	}

	/* 现在我们已经在buf中构建好了可以用于下载的bin文件，将buf中的数据保存到
	 * 到一个文件中，文件命名为load.imx
	 */
	printf("Delete Old %s\r\n", output_imx);
	remove(output_imx);
	
	printf("Create New %s\r\n", output_imx);
	fp = fopen(output_imx, "wb");	/* 打开laod.imx	*/
	if(fp == NULL){
		printf("Cant't Open %s!!!\r\n", output_imx);
		free(buf);
		return -1;
	}
	nbytes = fwrite(buf, 1, filelen + BIN_OFFSET, fp);
	if(nbytes != (filelen + BIN_OFFSET)){
		printf("File Write Error!\r\n");
		free(buf);
		fclose(fp);
		return -1;
	}
	free(buf);
	fclose(fp);	
	
	/* 构建烧写的shell命令 */
	if(do_write){
		/* 构建烧写的shell命令 */
		cmdbuf = malloc(SHELLCMD_LEN);
		sprintf(cmdbuf, "sudo dd if=%s of=%s bs=512 seek=2 conv=notrunc", output_imx, sd_device);	
		printf("Download %s to %s  ......\r\n", output_imx, sd_device);
		
		/* 执行上面的shell命令 */
		system(cmdbuf);
		free(cmdbuf);
	}
	return 0;	
}
