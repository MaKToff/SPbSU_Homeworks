﻿/*
Prints components of the given float number.
Method #1: using pointers. 

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
	const int maxNum = 255; // It is a maximum number for the exponent = 2^8 - 1
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

void compute(int bits)
{
	int sign = (bits >> 31) & 1;
	int exponent = (bits >> 23) & ((1 << 8) - 1);
	int mantissa = bits & ((1 << 23) - 1);
	f.sign = sign;
	f.exponent = exponent;
	f.mantissa = mantissa;
	print(f);
}

void method1()
{
	float number;
	scanf("%f", &number);
	compute(*(int *)(& number));
}

int main(void)
{
	method1();
	return 0;
}
