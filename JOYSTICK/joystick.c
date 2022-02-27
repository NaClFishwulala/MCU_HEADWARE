#include "joystick.h"

/**
* @brief  ADC�жϻص������������������е�adc����ֵ
* @param  hadc: ADC handle
* @retval ��ȡjoystick״̬
*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if(hadc->Instance == ADC1)
	{
		unsigned int x = 0;
		unsigned int y = 0;

		for(int i = 0; i < 50;)
		{
			x += adc_buff[i++];
			y += adc_buff[i++];
		}
			
		x = x / 25 * 330 / 4096;
		y = y / 25 * 330 / 4096;
		
		if(y >= 300)
			dirction = up;
		else if(y <= 30)
			dirction = down;
		else if(x >= 300)
			dirction = left;
		else if(x <= 30)
			dirction = right;
	}
}

/**
* @brief  ����ADC�ɼ�
* @param  None
* @retval ����ADC�ص�����
*/
//void GetJoyStickStatus(void)
//{

//		
//		#if 0
//		printf("\n\r x:%d ADC1_Volt:%d.%d%d \n\r",x,x/100,(x/100)%10,x%10);
//		printf("\n\r y:%d ADC2_Volt:%d.%d%d \n\r",y,y/100,(y/100)%10,y%10);
//		#endif
//}
