#pragma once
#include <string>

/* 方法1 用字符串来表示大数 字符串模拟数字加法 */
void print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!increase(number))
	{
		printNum(number);
	}
	delete[] number;
}

// 实现字符串对应的数字加1，并判断是否溢出
bool increase(char* number)
{
	bool nOverFlow = false;
	int nTakeOver = 0;	// 进位
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; --i)	// 从个位到最高位
	{
		int nSum = number[i] - '0' + nTakeOver;	// 每个数位的值
		if (i == nLength - 1)
			++nSum;
		if (nSum >= 10)
		{
			if (i == 0)
				nOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;	// 无进位可直接退出循环
		}
	}
	return nOverFlow;
}

// 从第一个非0数位开始打印1个数字
void printNum(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}


/* 方法2 n位十进制数看成是n个从0到9的全排列 全排列采用 递归 的方法 */
void print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	//memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)	// 数字0-9
	{
		number[0] = '0' + i;		// 从最高位到低位
		printDecursively(number, n, 0);
	}
	delete[] number;
}

// 递归求解
void printDecursively(char* number, int length, int index)
{
	if (index == length - 1)	// 递归结束条件
	{
		printNum(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index+1]= '0' + i;
		printDecursively(number, length, index + 1);
	}
}