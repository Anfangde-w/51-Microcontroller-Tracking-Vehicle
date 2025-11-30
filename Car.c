#include <REGX52.H>

//传感器串口
sbit sensorL1 = P2 ^ 0;
sbit sensorL2 = P2 ^ 1;
sbit sensorMi = P2 ^ 2;
sbit sensorR2 = P2 ^ 3;
sbit sensorR1 = P2 ^ 4;
//电机串口
sbit MotorL1 = P0 ^ 3;
sbit MotorL2 = P0 ^ 4;
sbit MotorR1 = P0 ^ 5;
sbit MotorR2 = P0 ^ 6;

int TurnValue = 0;

//传感器检测
//sensorL1 = P2 ^ 0;
//sensorL2 = P2 ^ 1;
//sensorMi = P2 ^ 2;
//sensorR2 = P2 ^ 3;
//sensorR1 = P2 ^ 4;
int Sensor_Move(void)
{
	//居中前进
	if(sensorL1 == 1 && sensorL2 == 0 && sensorMi == 0 && sensorR2 == 0 && sensorR1 == 1)
	{
		//正误差偏右向左转，负误差偏左向右转
		TurnValue = ((1 * -2)+(0 * -1)+(0 * 0)+(0 * 1)+(1 * 2));
	}
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 0 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((1 * -2)+(1 * -1)+(0 * 0)+(1 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 0 && sensorMi == 0 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((1 * -2)+(0 * -1)+(0 * 0)+(1 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 0 && sensorR2 == 0 && sensorR1 == 1)
	{TurnValue = ((1 * -2)+(1 * -1)+(0 * 0)+(0 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 1 && sensorR2 == 0 && sensorR1 == 1)
	{TurnValue = ((1 * -2)+(1 * -1)+(1 * 0)+(0 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 0 && sensorMi == 1 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((1 * -2)+(0 * -1)+(1 * 0)+(1 * 1)+(1 * 2));}
	
	if(sensorL1 == 0 && sensorL2 == 0 && sensorMi == 1 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((0 * -2)+(0 * -1)+(1 * 0)+(1 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 1 && sensorR2 == 0 && sensorR1 == 0)
	{TurnValue = ((1 * -2)+(1 * -1)+(1 * 0)+(0 * 1)+(0 * 2));}
	
	if(sensorL1 == 0 && sensorL2 == 1 && sensorMi == 1 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((0 * -2)+(1 * -1)+(1 * 0)+(1 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 1 && sensorR2 == 1 && sensorR1 == 0)
	{TurnValue = ((1 * -2)+(1 * -1)+(1 * 0)+(1 * 1)+(0 * 2));}
	
	if(sensorL1 == 0 && sensorL2 == 0 && sensorMi == 0 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((0 * -2)+(0 * -1)+(0 * 0)+(1 * 1)+(1 * 2));}
	
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 0 && sensorR2 == 0 && sensorR1 == 0)
	{TurnValue = ((1 * -2)+(1 * -1)+(0 * 0)+(0 * 1)+(0 * 2));}
	
	//无轨道前进
	if(sensorL1 == 1 && sensorL2 == 1 && sensorMi == 1 && sensorR2 == 1 && sensorR1 == 1)
	{TurnValue = ((1 * -2)+(1 * -1)+(1 * 0)+(1 * 1)+(1 * 2));}
	
	//停止线或标记线停下或鸣响
	if((sensorL1 == 0 && sensorL2 == 1 && sensorMi == 1 && sensorR2 == 1 && sensorR1 == 0) ||
		(sensorL1 == 1 && sensorL2 == 0 && sensorMi == 1 && sensorR2 == 0 && sensorR1 == 1))
	{
		TurnValue = 10;
	}
	
	return TurnValue;
}

//电机控制
void Motor_Go(unsigned char* L,unsigned char* R)
{
	MotorL1 = 1;MotorL2 = 0;
	MotorR1 = 1;MotorR2 = 0;
	*L = 255;*R = 255;
}

void Motor_Back(unsigned char* L,unsigned char* R)
{
	MotorL1 = 0;MotorL2 = 1;
	MotorR1 = 0;MotorR2 = 1;
	*L = 255;*R = 255;
}

void Motor_TurnLeft(unsigned char* L,unsigned char* R)
{
	MotorL1 = 1;MotorL2 = 0;
	MotorR1 = 1;MotorR2 = 0;
	*L = 128;*R = 255;
}

void Motor_TurnRight(unsigned char* L,unsigned char* R)
{
	MotorL1 = 1;MotorL2 = 0;
	MotorR1 = 1;MotorR2 = 0;
	*L = 255;*R = 128;
}

void Motor_Break(unsigned char* L,unsigned char* R)
{
	MotorL1 = 1;MotorL2 = 1;
	MotorR1 = 1;MotorR2 = 1;
	*L = 255;*R = 255;
}

void Motor_Null(unsigned char* L,unsigned char* R)
{
	MotorL1 = 0;MotorL2 = 0;
	MotorR1 = 0;MotorR2 = 0;
	*L = 255;*R = 255;
}

