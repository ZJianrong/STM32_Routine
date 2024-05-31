#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	// 配置外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1  | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// 设置输出口为高电平（LED熄灭）
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
	
}
/**
  * @brief 控制LED亮灭
  * @param LEDNum GPIOA口的第几个LED 范围：1，2
		   OPEN 1为打开，2为关闭
  * @retval 
  */

/**自己写的函数
void CONTROL_LED(int LEDNum, int OPEN)	
{
	if(LEDNum == 1)
	{
		if(OPEN == 1)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		}
		if(OPEN == 0)
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_1);
		}
	}
	
	if(LEDNum == 2)
	{
		if(OPEN == 1)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		}
		if(OPEN == 0)
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_2);
		}
	}
}
*/


void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}


void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

/**
  * @brief GPIOA_1端口输出翻转
  * @param 无
  * @retval 无
  */
void LED1_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}


void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}

/**
  * @brief GPIOA_2端口输出翻转
  * @param 无
  * @retval 无
  */
void LED2_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}

