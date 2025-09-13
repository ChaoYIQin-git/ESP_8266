#include "stm32f10x.h"  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	//解除PB3,PA15的默认JTAG模式

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_SetBits(GPIOA,GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_SetBits(GPIOB, GPIO_Pin_3);
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_3);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_3);
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_15);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_15);
}
