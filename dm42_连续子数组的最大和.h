#pragma once
#include <exception>

/**
 * 从数组规律入手或者考虑动态规划
 * f(i-1)>0时累加才有意义
 */

int findMaxSumOfSubArray(int* pData, int length)
{
	if (pData == nullptr || length <= 0)
		throw new std::exception("Invalid input.");

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;	// -(2^31) 满足全负输入
	for (int i = 0; i < length; ++i)
	{
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}

	return nGreatestSum;
}