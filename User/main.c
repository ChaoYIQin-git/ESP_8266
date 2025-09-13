#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "OLED.h"
#include "esp.h"
#include "string.h"

uint16_t esp_ret = 0;

int main(void)
{
	OLED_Init();
	LED_Init();
	ESP_Init();

	LED1_ON();
	LED2_ON();
	OLED_ShowImage(0,0,16,16,Diode);
	OLED_Update();


	
	while (1)
	{

	}
}


void USART3_IRQHandler(void)
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) == SET)
	{
		esp_ret = USART_ReceiveData(USART3);
		if(esp_ret == '1')
		{
			LED1_ON();
			LED2_OFF();
		}
		if(esp_ret == '2')
		{
			LED2_ON();
			LED1_OFF();
		}
	}
	USART_ClearITPendingBit(USART3, USART_IT_RXNE);
}
