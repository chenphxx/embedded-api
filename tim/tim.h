/**
 * @file tim.h
 * @brief 定时器接口文件
 * 
 * @details 提供了使用定时器所需的一系列接口; 范围为1-8
 * 
 * @author chenphxx
 * @version V2024.9.14
 * @copyright (c) Copyright 2024
 */
#ifndef TIM_H_
#define TIM_H_


#include "stm32f10x.h"


/**
 * @brief TIM1初始化
 * 
 * @param void
 * @return 无
 */
void TIM1_Init(void);

/**
 * @brief TIM2初始化
 * 
 * @param void
 * @return 无
 */
void TIM2_Init(void);

/**
 * @brief TIM3初始化
 * 
 * @param void
 * @return 无
 */
void TIM3_Init(void);

/**
 * @brief TIM4初始化
 * 
 * @param void
 * @return 无
 */
void TIM4_Init(void);

/**
 * @brief TIM5初始化
 * 
 * @param void
 * @return 无
 */
void TIM5_Init(void);

/**
 * @brief TIM6初始化
 * 
 * @param void
 * @return 无
 */
void TIM6_Init(void);

/**
 * @brief TIM7初始化
 * 
 * @param void
 * @return 无
 */
void TIM7_Init(void);

/**
 * @brief TIM8初始化
 * 
 * @param void
 * @return 无
 */
void TIM8_Init(void);


#endif
