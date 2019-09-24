#pragma once
#include <cmath>

// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？

/* 动态规划 从上到下分析，从下到上求解 */
int maxProductAfterCutting_soultion1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* products = new int[length + 1];	// 用数组来存储子问题的最优解
	// 以下为此长度不再剪绳子时的值
	products[0] = 0;	// 此为占位，无用
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	// 通过for循环从下到上求解
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
		}
		products[i] = max;	// 在外循环
	}

	max = products[length];
	delete[] products;	// 
	return max;
}



/* 贪婪算法 要求证明，需要扎实的数学基本功 */
// n>=5时先尽可能多划分成3，再划分为2
// 证明：2(n-2)>=n  3(n-3)>=n
int maxProductAfterCutting_soultion2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOf3 = length / 3;
	// 当最后可以余4时，划分成2更好
	if (length - timesOf3 * 3 == 1)
		--timesOf3;
	int timesOf2 = (length - timesOf3 * 3) / 2;
	return (int)pow(3, timesOf3) * (int)pow(2, timesOf2);
}