#pragma once
#include <cmath>

// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。
/**
 * 解法一：基于递归实现 和的值范围为[n,6n]，骰子数所有可能的排列为6^n
 * 将骰子分成两堆：第一堆（可能值1-6）和n-1堆，然后递归处理
 * 用一个6n-n+1辅助数组存放每个和出现的次数，和s存放在s-n的位置（即和n放在位置0）
 */
int maxValue = 6;
void printProbability(int num)
{
	if (num < 1)
		return;

	int maxSum = maxValue * num;
	int* pProbabilities = new int[maxSum - num + 1];
	for (int i = num; i <= maxSum; ++i)
		pProbabilities[i - num] = 0;

	probability(num, pProbabilities);

	double total = (double)std::pow(num, maxValue);
	for (int i = num; i <= maxSum; ++i)
	{
		double ratio = (double)pProbabilities[i - num] / total;
		printf("%d: %f\n", i, ratio);
	}

	delete[] pProbabilities;
}

void probability(int num, int* pProbabilities)
{
	for (int i = 1; i <= maxValue; ++i)
		probability(num, num, i, pProbabilities);
}

void probability(int src, int cur, int sum, int* pProbabilities)
{
	if (cur == 1)
		pProbabilities[sum - src]++;	// 递归结束，相应次数加1
	else
	{
		for (int i = 1; i <= maxValue; ++i)
			probability(src, cur - 1, sum + i, pProbabilities);	// 和累加
	}
}