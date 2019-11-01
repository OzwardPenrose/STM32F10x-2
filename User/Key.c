#include "key.h"
#include "stm32f10x.h"

void key_init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=KEY1_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEY2_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(KEY2_GPIO_PORT,&GPIO_InitStructure);
}

uint8_t key_scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin){
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON){
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);//�ȴ������ͷ���������
		return KEY_ON;
	}
	else 
		return KEY_OFF;
}
//ȷ��һ�����ţ�������Ҫָ��һ���˿ں�һ�����ź�
//���Ŷ˿�GPIO_TypeDef* GPIOx�����ź�uint16_t GPIO_Pin
//��ȡ���������õ��Ǹ�������
