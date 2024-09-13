/**
 * @file usart.h
 * @brief USART通信接口
 * 
 * @details 提供了USART通信所需的一系列接口; 目前提供了USART1-3的初始化接口; 
 *          此外还对fputc函数进行了重定义, 可以使用printf直接通过USART输出
 * 
 * @author chenphxx
 * @version V2024.9.13
 * @copyright (c) Copyright 2024
 */
#include "stm32f10x.h"
#include <stdio.h>


#ifndef USART_H_
#define USART_H_


/**
 * @brief USART1初始化
 * 
 * @param rate 波特率
 * @return 无
 */
void USART1_Init(int rate);

/**
 * @brief USART2初始化
 * 
 * @param rate 波特率
 * @return 无
 */
void USART2_Init(int rate);

/**
 * @brief USART3初始化
 * 
 * @param rate 波特率
 * @return 无
 */
void USART3_Init(int rate);

/**
 * @brief 标准库需要支持的函数
 */
struct __FILE
{
	int handle; 

};
FILE __stdout;

/** @brief 定义_sys_exit()以避免使用半主机模式
 * 
 * @param x
 * @return 无
 */
void _sys_exit(int x);

/**
 * @brief 重定义fputc
 * 
 * @param ch
 * @param f
 * @return ch
 */
int fputc(int ch, FILE *f);


#endif
