#include "public.h"
#include "stm32f10x.h"
#include "key.h"
#include "led.h"

void LED_GPIO_config(void);
void key_init(void);
uint8_t key_scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);
int main(void){
	LED_GPIO_config();
	key_init();
	while(1){
		if(key_scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN)==KEY_ON){
			GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
		}
		else if(key_scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN)==KEY_ON){
			GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
		 }
 }
}
