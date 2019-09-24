#pragma once

/**
 * ����һ �����ÿ�������Ƿ��ǳ���
 */
bool isUgly(int num)
{
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;

	return (num == 1) ? true : false;
}

int getUglyNumber(int index)
{
	if (index <= 0)
		return -1;

	int number = 1;
	int nextUglyNum = 1;
	while (nextUglyNum < index)
	{
		++number;
		if (isUgly(number))
			++nextUglyNum;
	}

	return number;
}


/**
 * ������ �ռ任ʱ��
 * ʹ������洢��С��������ĳ�������һ��������ǰ���������2��3��5�õ�������������ģ�
 * ��һ������Ӧ���ǳ˻��е�һ������ǰ������ģ���3���˻�����С���Ǹ�
 * 3���˻���Ҫ�����ŵ�ǰ����
 */
int getUglyNumber2(int index)
{
	if (index <= 0)
		return -1;

	int* uglyNumbers = new int[index];
	uglyNumbers[0] = 1;
	int nextUglyNum = 1;
	int* uglyNum2 = uglyNumbers;
	int* uglyNum3 = uglyNumbers;
	int* uglyNum5 = uglyNumbers;

	while (nextUglyNum < index)
	{
		uglyNumbers[nextUglyNum] = minNum((*uglyNum2) * 2, (*uglyNum3) * 3, (*uglyNum5) * 5);

		while ((*uglyNum2) * 2 <= uglyNumbers[nextUglyNum])
			++uglyNum2;
		while ((*uglyNum3) * 3 <= uglyNumbers[nextUglyNum])
			++uglyNum3;
		while ((*uglyNum5) * 5 <= uglyNumbers[nextUglyNum])
			++uglyNum5;

		++nextUglyNum;
	}

	int uglyNumber = uglyNumbers[nextUglyNum - 1];
	delete[] uglyNumbers;

	return uglyNumber;
}

// ����3��������Сֵ
int minNum(int num1, int num2, int num3)
{
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;

	return min;
}
