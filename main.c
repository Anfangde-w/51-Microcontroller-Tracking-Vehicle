#include <REGX52.H>
#include "TB6612FNC.h"
#include "Button.h"
#include "Car.h"
#include "PID.h"
#include "Timer.h"

#define BASE_SPEED_LEVEL  0      //速度价值
#define BASE_SPEED        128    //基础速度
#define SCALING_FACTOR    1000   //倍率
#define SCALING_FACTOR_f  1000.0 //倍率

//PWM串口
sbit PWMA = P0 ^ 2;
sbit PWMB = P0 ^ 7;
//电机串口
sbit MotorL1 = P0 ^ 3;
sbit MotorL2 = P0 ^ 4;
sbit MotorR1 = P0 ^ 5;
sbit MotorR2 = P0 ^ 6;

unsigned char counter = 0;
unsigned char standardL = 0;
unsigned char standardR = 0;
float CarValue = 0.0;
int CarValue_Int = 0.0;
int speedL_Int = 0;
int speedR_Int = 0;
float speedL = 0.0;
float speedR = 0.0;

//电机驱动
void Motor_MoveGo(void)
{
	MotorL1 = 1;MotorL2 = 0;
	MotorR1 = 1;MotorR2 = 0;
}
//电机制动
void Motor_MoveStop(void)
{
	MotorL1 = 1;MotorL2 = 1;
	MotorR1 = 1;MotorR2 = 1;
}

//主函数
int main(void)
{
	Timer_Init();
	standardL = 128;
	standardR = 128;
	while (1)
	{
		if(Sensor_Move() != 10){Motor_MoveGo();}
		if(Sensor_Move() == 10){Motor_MoveStop();}
		standardL = BASE_SPEED + speedL * BASE_SPEED;
		standardR = BASE_SPEED + speedR * BASE_SPEED;
	}
}

//中断函数
void Timer0_Rountine(void) interrupt 1 //用来计算左右PWM
{	
	//per 10us counter add 1
	TL0 = 0xF7;
	TH0 = 0xFF;
	
	if(counter > standardL){PWMA = 0; P2_0 = 0;}else{PWMA = 1; P2_0 = 1;}
	if(counter > standardR){PWMB = 0; P2_0 = 0;}else{PWMB = 1; P2_0 = 1;}
	counter++;
	
	TF0 = 0;
}

void Timer1_Rountine(void) interrupt 3
{
	//per 100us counter add 1
	TL1 = 0xA4;
	TH1 = 0xFF;
	if(Sensor_Move() != 10)
	{
	CarValue = PID_Calculate(Sensor_Move());
	CarValue_Int = CarValue * SCALING_FACTOR;
	speedL_Int = BASE_SPEED_LEVEL - CarValue_Int;
	speedR_Int = BASE_SPEED_LEVEL + CarValue_Int;
	speedL = speedL_Int / SCALING_FACTOR_f;
	speedR = speedR_Int / SCALING_FACTOR_f;
	}
	TF1 = 0;
}