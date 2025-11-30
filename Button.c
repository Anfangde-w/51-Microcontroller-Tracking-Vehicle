#include "Button.h"
#include <REGX52.h>
#include <INTRINS.h>

//延时
void Delay(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;
	while(ms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

//矩阵键盘检测并输出打印字符
unsigned char JvzhenJianpan()
{
	unsigned char KeyNumber = 0;
	
	P1 = 0xFF;
	P1_3 = 0;
	if(P1_7 == 0) {Delay(10); while(P1_7 == 0); Delay(10); KeyNumber = '1';}
	if(P1_6 == 0) {Delay(10); while(P1_6 == 0); Delay(10); KeyNumber = '4';}
	if(P1_5 == 0) {Delay(10); while(P1_5 == 0); Delay(10); KeyNumber = '7';}
	if(P1_4 == 0) {Delay(10); while(P1_4 == 0); Delay(10); KeyNumber = '.';}
	
	P1 = 0xFF;
	P1_2 = 0;
	if(P1_7 == 0) {Delay(10); while(P1_7 == 0); Delay(10); KeyNumber = '2';}
	if(P1_6 == 0) {Delay(10); while(P1_6 == 0); Delay(10); KeyNumber = '5';}
	if(P1_5 == 0) {Delay(10); while(P1_5 == 0); Delay(10); KeyNumber = '8';}
	if(P1_4 == 0) {Delay(10); while(P1_4 == 0); Delay(10); KeyNumber = '0';}
	
	P1 = 0xFF;
	P1_1 = 0;
	if(P1_7 == 0) {Delay(10); while(P1_7 == 0); Delay(10); KeyNumber = '3';}
	if(P1_6 == 0) {Delay(10); while(P1_6 == 0); Delay(10); KeyNumber = '6';}
	if(P1_5 == 0) {Delay(10); while(P1_5 == 0); Delay(10); KeyNumber = '9';}
	if(P1_4 == 0) {Delay(10); while(P1_4 == 0); Delay(10); KeyNumber = '=';}
	
	P1 = 0xFF;
	P1_0 = 0;
	if(P1_7 == 0) {Delay(10); while(P1_7 == 0); Delay(10); KeyNumber = '+';}
	if(P1_6 == 0) {Delay(10); while(P1_6 == 0); Delay(10); KeyNumber = '-';}
	if(P1_5 == 0) {Delay(10); while(P1_5 == 0); Delay(10); KeyNumber = '*';}
	if(P1_4 == 0) {Delay(10); while(P1_4 == 0); Delay(10); KeyNumber = '/';}
	
	return KeyNumber;
}


//独立按键
unsigned char Indiv_Key()
{
	unsigned char KeyNumber = 0;
	
	if(P3_1 == 0) {Delay(10); while(P3_1 == 0); Delay(10); KeyNumber = 1;}
	if(P3_0 == 0) {Delay(10); while(P3_0 == 0); Delay(10); KeyNumber = 2;}
	if(P3_2 == 0) {Delay(10); while(P3_2 == 0); Delay(10); KeyNumber = 3;}
	if(P3_3 == 0) {Delay(10); while(P3_3 == 0); Delay(10); KeyNumber = 4;}
	
	return KeyNumber;
}