/**
 * @file spi.h
 * @brief SPI通信接口
 * 
 * @details 提供了SPI通信所需的一系列接口; 目前提供了SPI1-3的初始化
 * 
 * @author chenphxx
 * @version V2024.9.13
 * @copyright (c) Cpoyright 2024
 */
#ifndef SPI_H_
#define SPI_H_


#include "stm32f10x.h"


/**
 * @brief SPI1初始化
 * 
 * @param void
 * @return 无
 */
void SPI1_Init(void);

/**
 * @brief SPI2初始化
 * 
 * @param void
 * @return 无
 */
void SPI2_Init(void);

/**
 * @brief SPI3初始化
 * 
 * @param void
 * @return 无
 */
void SPI3_Init(void);


#endif
