#ifndef _led_h
#define _led_h

#include "stm32f10x.h"

#define LED_GPIO_PORT 	GPIOB
#define LED_GPIO_CLK 		RCC_APB2Periph_GPIOB
#define LED_GPIO_PIN		GPIO_Pin_0
//IO¿ØÖÆÎ»ÎªPB0

#define digitalHi(p,i)	{p->BSRR=i;}
#define digitalLo(p,i)	{p->BRR=i;}
#define digitalToggle(p,i)	{p->ODR^=i;}

#define LED_OFF		digitalLo(LED_GPIO_PORT,LED_GPIO_PIN)
#define LED_ON		digitalHi(LED_GPIO_PORT,LED_GPIO_PIN)


#endif
void LED_GPIO_config(void);
