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
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);//等待按键释放再输出结果
		return KEY_ON;
	}
	else 
		return KEY_OFF;
}
//确定一个引脚，最少需要指定一个端口和一个引脚号
//引脚端口GPIO_TypeDef* GPIOx，引脚号uint16_t GPIO_Pin
//读取按键引脚用的是浮空输入
