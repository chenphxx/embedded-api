/**
 * @file can.h
 * @brief CAN通信接口
 * 
 * @details 提供了CAN通信所需的一系列接口; 范围为1
 * 
 * @author chenphxx
 * @version V2024.9.14
 * @copyright (c) Copyright 2024
 */
#ifndef CAN_H_
#define CAN_H_


#include "stm32f10x.h"


/**
 * @brief CAN1初始化
 * 
 * @param void
 * @return 无
 */
void CAN1_Init(void);


#endif
