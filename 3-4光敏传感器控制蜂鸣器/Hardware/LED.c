#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	// ��������ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1  | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// ���������Ϊ�ߵ�ƽ��LEDϨ��
	GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
	
}
/**
  * @brief ����LED����
  * @param LEDNum GPIOA�ڵĵڼ���LED ��Χ��1��2
		   OPEN 1Ϊ�򿪣�2Ϊ�ر�
  * @retval 
  */

/**�Լ�д�ĺ���
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
  * @brief GPIOA_1�˿������ת
  * @param ��
  * @retval ��
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
  * @brief GPIOA_2�˿������ת
  * @param ��
  * @retval ��
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

