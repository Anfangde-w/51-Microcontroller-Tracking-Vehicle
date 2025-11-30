#include <REGX52.H>
#include <INTRINS.h>

void Timer_Init(void)//PWM 100us
{
	//计时器模式
	TMOD &= 0x00;
	TMOD |= 0x11;
	//计时器初始值
	TL1 = 0xA4;
	TH1 = 0xFF;
	TL0 = 0xF7;
	TH0 = 0xFF;
	//计时器独自开关
	TF0 = 0;
	TR0 = 1;
	TF1 = 0;
	TR1 = 1;
	//计时器中断开关
	ET0 = 1;
	ET1 = 1;
	//中断总开关
	EA = 1;
	//计时器优先级
	PT0 = 0;
	PT1 = 1;
}
