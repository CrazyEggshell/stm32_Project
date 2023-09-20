#include "stm32f10x.h"
#include "uart.h"
#include "sys.h"
#include "delay.h"
#include "stdio.h"
//#include "oled.h"
#include "adc.h"
#include "pwm.h"

int main(void)
{
	float adcx; 
	float	result;
	
	delay_init();	    						//延时初始化	 	
	//OLED_Init(); 									//显示OLED初始化
	Adc_Init();										//ADC初始化
	TIM2_Int_Init(5000,7199);   	//0.5s记一次
	tim3_pwm_init(100,2000000);		//一周期为5ms
	UART1_GPIO_Config();
	
	//OLED_Clear();									//清屏

	TIMER(1);

	while(1)
	{
		
		//printf("电压为：");
		
		if(Flag == 1)
		{
			Flag = 0;
			
			adcx=Get_Adc_Average(ADC_Channel_1,10);
			adcx = (float)adcx * (3.3/4096);

			printf("电压为：%.2f \r\n",adcx);
			
			result = Change_Number(adcx,100);
			TIM_SetCompare3(TIM3,(int)result);
			
			printf("占空比为：%.2f \r\n",result);
			
			printf("\r\n");
		}

		
		
	}
}	

//			if( adcx >= 3.28 )
//			{
//				GPIO_Shift();
//				
//				GPIO_SetBits(GPIOB, GPIO_Pin_0);
//				printf("占空比为：100 \r\n");
//				
//				tim3_pwm_init(100,2000000);
//			}
//	

