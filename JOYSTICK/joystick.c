#include "joystick.h"


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if(hadc->Instance == ADC1)
	{
		unsigned int ad1 = 0;
		unsigned int ad2 = 0;
		for(int i = 0; i < 50;)
		{
			ad1 += adc_buff[i++];
			ad2 += adc_buff[i++];
		}
			
		ad1 = ad1 / 25 * 330 / 4096;
		ad2 = ad2 / 25 * 330 / 4096;
		
		#if 1
		printf("\n\r ADC1_Volt:%d.%d%d \n\r",ad1/100,(ad1/100)%10,ad1%10);
		printf("\n\r ADC2_Volt:%d.%d%d \n\r",ad2/100,(ad2/100)%10,ad2%10);
		#endif
	}
}
