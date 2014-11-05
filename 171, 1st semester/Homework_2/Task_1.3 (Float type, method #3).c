/*
Получает на вход вещественное число и разделяет его на знак, мантиссу и экспоненту, используя битовое поле. 
Затем выводит это число в другом представлении.
===========================================================================================================
Takes as input a float number and divides it on sign, exponent and mantissa using bit field. 
Then writes this number in other representation.

Author: Mikhail Kita, group 171
*/


#include <stdio.h>

struct floatNumber
{
	int sign;
	int exponent;
	int mantissa;
} f;

void print(floatNumber)
{
	const int maxNum = 255; //It's maximum number for exponent = 2^8 - 1 
	if (f.sign) f.sign = -1; else f.sign = 1;
	if (f.exponent == 0 && f.mantissa == 0) printf("Zero\n");
	else if (f.exponent == maxNum && f.mantissa == 0) 
	{
		if (f.sign > 0) printf("+ Infinity\n");
		else printf("- Infinity\n");
	}
	else if (f.exponent == maxNum && f.mantissa != 0) printf("NaN\n");
	else printf("%d * 2^%d * %f\n", f.sign, f.exponent - 127, 1+((float)f.mantissa)/(1 << 23));
}

void method3()
{
	union
	{
		float floatValue;
		struct
		{
			unsigned m : 23;
			unsigned e : 8;
			unsigned s : 1;
		} bitField;
	} floatNum;

	scanf("%f", &floatNum.floatValue);
	f.sign = floatNum.bitField.s;
	f.exponent = floatNum.bitField.e;
	f.mantissa = floatNum.bitField.m;
	print(f);
}

int main(void)
{
	method3();
	return 0;
}
