#include "iic.h"


void IIC1_Init(void)
{
    // 使能IIC GPIO时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 引脚配置 SCL-PB6 SDA-PB7
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;  // 复用开漏
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // 参数配置
    I2C_InitTypeDef I2C_InitStructure;

    I2C_InitStructure.I2C_ClockSpeed = 100000;  // 100kHz
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;  // I2C 模式
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;  // 占空比 1:2（标准模式）
    I2C_InitStructure.I2C_OwnAddress1 = 0x00;  // 主机模式无需配置具体地址
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;  // 启用应答
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;  // 7位地址模式

    I2C_Init(I2C1, &I2C_InitStructure);  // 初始化IIC
    I2C_Cmd(I2C1, ENABLE);  // 启用 IIC
}

void IIC2_Init(void)
{
    // 使能IIC GPIO时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // SCL-PB10 SDA-PB11
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // 参数配置
    I2C_InitTypeDef I2C_InitStructure;

    I2C_InitStructure.I2C_ClockSpeed = 100000;
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Init(I2C2, &I2C_InitStructure);
    I2C_Cmd(I2C2, ENABLE);
}
