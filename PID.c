#include <REGX52.H>

#define SCALING_FACTOR    1000.0   //倍率

//误差
int error = 0;
int last_error = 0;
//float error = 0.0;
//float last_error = 0.0;

//比例P/积分I/微分D
//float Kp = 10.0;
//float Ki = 0.1;
//float Kd = 0.0;
int Kp = 5000;
int Ki = 100;
int Kd = 0;//不使用

//计算
float Output = 0.0;
//float Integral = 0.0;
//float Derivative = 0.0;
int Output_Int = 0;
int Integral = 0;
int Derivative = 0;

float PID_Calculate(int input)
{
	error = input;
	
	//积分项
	Integral += error;
	//积分限幅
	if(Integral >= 100){Integral = 100;}
	if(Integral <= -100){Integral = -100;}
	
	//微分项
	Derivative = error - last_error;
	
	//PI计算
	Output_Int = Kp * error + Integral * Ki + Derivative * Kd;
	//除去倍率
	Output = Output_Int / SCALING_FACTOR;
	
	//保存上一次的误差
	last_error = error;
	
	return Output;
}