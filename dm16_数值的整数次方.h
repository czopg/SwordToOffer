#pragma once
//#include <iostream>
//#include <cmath>
//using namespace std;

// 考虑问题的全面性 快速求乘方的方法
bool g_InvalidInput = false;	// 用全局变量处理错误
double power(double base, int exponent)
{
	g_InvalidInput = false;
	if (numEqual(base,0.0) && exponent < 0)	// 考虑底数为0指数<0
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
		absExponent = (unsigned int)-exponent;

	double result = powerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	
	return result;
}

// 重点掌握 ： 乘方的快速计算 递归的方式
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)	
		return 1.0;
	if (exponent == 1)	// 递归的结束条件
		return base;

	double result = powerWithUnsignedExponent(base, exponent >> 1);	// 右移符号代替除
	result *= result;	// 比如32=16^2
	if (exponent & 0x1 == 1)	// 用与来判断是否是奇数
		result *= base;

	return result;
}

// 选择一个合适的精度来比较浮点数是否相等
bool numEqual(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}