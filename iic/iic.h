/**
 * @file iic.h
 * @brief IIC通信接口
 * 
 * @details 提供了IIC通信所需的一系列接口; 目前提供了IIC1-2的初始化
 * 
 * @author chenphxx
 * @version V2024.9.13
 * @copyright (c) Copyright 2024
 */
#ifndef IIC_H_
#define IIC_H_


#include "stm32f10x.h"


/**
 * @brief IIC1初始化
 * 
 * @param void
 * @return 无
 */
void IIC1_Init(void);

/**
 * @brief IIC2初始化
 * 
 * @param void
 * @return 无
 */
void IIC2_Init(void);


#endif
