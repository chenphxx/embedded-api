#include "stm32f10x.h"


void CAN1_Init(void)
{
    // 使能 CAN GPIO时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 引脚配置 PA11-RX PA12-TX
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  // 上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  // 复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // CAN 配置
    CAN_InitTypeDef CAN_InitStructure;
    CAN_DeInit(CAN1);  // 复位 CAN1 外设
    CAN_StructInit(&CAN_InitStructure);  // 初始化 CAN 配置结构

    // 配置 CAN
    CAN_InitStructure.CAN_TTCM = DISABLE;  // 禁用时间触发通信模式
    CAN_InitStructure.CAN_ABOM = DISABLE;  // 禁用自动总线关闭管理
    CAN_InitStructure.CAN_AWUM = DISABLE;  // 禁用自动唤醒模式
    CAN_InitStructure.CAN_NART = DISABLE;  // 禁用非自动重传
    CAN_InitStructure.CAN_RFLM = DISABLE;  // 禁用接收 FIFO 锁定模式
    CAN_InitStructure.CAN_TXFP = DISABLE;  // 禁用优先级传输
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;  // 设置为普通模式(标准通信模式)
    
    // 配置波特率, 假设时钟频率为 36 MHz
    CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;  // 重新同步跳转宽度(1个时间单位)
    CAN_InitStructure.CAN_BS1 = CAN_BS1_9tq;  // 时间段1(9个时间单位)
    CAN_InitStructure.CAN_BS2 = CAN_BS2_4tq;  // 时间段2(4个时间单位)
    CAN_InitStructure.CAN_Prescaler = 4;  // 波特率分频器

    CAN_Init(CAN1, &CAN_InitStructure);  // 初始化 CAN1

    // 配置 CAN 过滤器
    CAN_FilterInitTypeDef CAN_FilterInitStructure;
    
    CAN_FilterInitStructure.CAN_FilterNumber = 0;  // 过滤器编号
    CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;  // 使用标识符屏蔽模式
    CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;  // 32位过滤器
    CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;  // 设置过滤器标识符高位
    CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;  // 设置过滤器标识符低位
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;  // 过滤器掩码高位
    CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;  // 过滤器掩码低位
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;  // 分配到 FIFO 0
    CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;  // 启用过滤器
    CAN_FilterInit(&CAN_FilterInitStructure);

    // 启用 CAN1 接收中断
    CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);  // FIFO 0 消息挂起中断使能

    // 配置中断优先级并使能中断
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;  // CAN1 RX0 中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  // 抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  // 子优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  // 使能中断
    NVIC_Init(&NVIC_InitStructure);
}
