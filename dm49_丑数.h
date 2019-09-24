#pragma once

/**
 * 方法一 逐个求每个整数是否是丑数
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
 * 方法二 空间换时间
 * 使用数组存储从小到大排序的丑数，下一个丑数由前面丑数乘以2、3或5得到，由于是排序的，
 * 下一个丑数应该是乘积中第一个大于前面丑数的，即3个乘积中最小的那个
 * 3个乘积需要紧跟着当前丑数
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

// 返回3个数的最小值
int minNum(int num1, int num2, int num3)
{
	int min = (num1 < num2) ? num1 : num2;
	min = (min < num3) ? min : num3;

	return min;
}
