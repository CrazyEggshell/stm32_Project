#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"



extern char Flag;


void Adc_Init(void);								//ADC��ʼ��
void TIM2_Int_Init(u16 arr,u16 psc);//��ʱ��2��ʼ��
void TIMER(u8 NewState);						//���ƶ�ʱ���ж�
u16  Get_Adc(u8 ch); 
u16 Get_Adc_Average(u8 ch,u8 times); 
 
#endif 
