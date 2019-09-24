#pragma once
//#include <iostream>
//#include <cmath>
//using namespace std;

// ���������ȫ���� ������˷��ķ���
bool g_InvalidInput = false;	// ��ȫ�ֱ����������
double power(double base, int exponent)
{
	g_InvalidInput = false;
	if (numEqual(base,0.0) && exponent < 0)	// ���ǵ���Ϊ0ָ��<0
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

// �ص����� �� �˷��Ŀ��ټ��� �ݹ�ķ�ʽ
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)	
		return 1.0;
	if (exponent == 1)	// �ݹ�Ľ�������
		return base;

	double result = powerWithUnsignedExponent(base, exponent >> 1);	// ���Ʒ��Ŵ����
	result *= result;	// ����32=16^2
	if (exponent & 0x1 == 1)	// �������ж��Ƿ�������
		result *= base;

	return result;
}

// ѡ��һ�����ʵľ������Ƚϸ������Ƿ����
bool numEqual(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}