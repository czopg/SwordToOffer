#pragma once
#include <string>
using namespace std;

/**
 * 递归求解 会有重复的子问题 -> 采用动态规划 从尾部开始从右往左循环求解
 * f(i)=f(i+1)+g(i,i+1)*f(i+2) 当组成的两位数在10-25之间时g(i,i+1)才为1，否则为0
 */

// 返回总翻译方法数目
int numberTranslationCount(int num)
{
	if (num < 0)
		return -1;

	string numInStr = to_string(num);	// 数字转字符串
	return numberTranslationCount(numInStr);
}

int numberTranslationCount(const string& str)
{
	int length = str.length();
	int* counts = new int[length];	// f(i)
	int count = 0;

	for (int i = length - 1; i >= 0; --i)
	{
		count = 0;
		if (i < length - 1)
			count = counts[i + 1];
		else
			count = 1;

		if (i < length - 1)
		{
			int digit1 = str[i] - '0';
			int digit2 = str[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
					count += counts[i + 2];
				else
					count += 1;
			}
		}
		counts[i] = count;
	}

	count = counts[0];
	delete[] counts;
	return count;
}