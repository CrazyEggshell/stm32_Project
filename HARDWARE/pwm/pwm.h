#include "stm32f10x.h"
#include "sys.h"

#ifndef MOTOR_INIT_
#define MOTOR_INIT_



void tim3_pwm_init(u16 arr , u32 fre);								//pwm��ʼ��
void GPIO_Shift(void);																//GPIO��ʼ��
float Change_Number(float A,float B);		//�����ݽ���ת����ת��Ϊռ�ձ�						

#endif

