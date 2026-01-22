<!--
 * @Author: wurh0001 wuuua_ahu@163.com
 * @Date: 2026-01-10 23:46:04
 * @LastEditors: wurh0001 wuuua_ahu@163.com
 * @LastEditTime: 2026-01-22 22:34:25
 * @FilePath: /projects/README.md
 * @Description: 
 * 
 * Copyright (c) 2026 by ${git_name_email}, All Rights Reserved. 
-->
# Embedded-Linux-Development-Learning
This repository is used for learning embedded Linux development and serves to store the code generated during the learning process.

## 重要说明
裸机阶段代码均引用或参考正点原子例程，仅在源代码基础上做部分改动，暂无独立开发部分

## 硬件说明
学习使用的是正点原子的imx6ull-alpha开发板（EMMC8GB+DDR3L512MB）
开发平台：Mac mini M4 + orbstack + Ubuntu jammy LTS虚拟机
交叉编译工具链：arm-linux-gnueabihf-gcc 7.3.0
烧录工具：
    SD卡烧录：Mac下通过imxdownload软件烧录
    USB烧录：Mac下使用uuu工具烧录
    注：因为orbstack虚拟机无法直通USB设备，所以编译在ubuntu虚拟机中完成，烧录在mac下完成
串口调试工具：Mac下使用vscode插件"Serial Monitor"进行串口调试