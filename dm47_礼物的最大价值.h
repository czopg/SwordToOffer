#pragma once
#include <algorithm>

/**
 * 递归求解 会有重复的子问题 -> 采用动态规划 使用 二维数组 来缓存中间值
 * （也可用一维数组代替，因为只需保存得到它的前两个值）
 * f(i,j)=max(f(i,j-1),f(i-1,j))+gift[i,j]
 */

int getMaxValue(const int* values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		return -1;

	int** maxValues = new int[rows];
	for (int i = 0; i < rows; ++i)
		maxValues[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int up = 0;
			int left = 0;
			if (i > 0)
				up = maxValues[i - 1][j];
			else
				left = maxValues[i][j - 1];

			maxValues[i][j] = std::max(up, left) + values[i * cols + j];
		}
	}

	int maxValue = maxValues[rows - 1][cols - 1];
	for (int i = 0; i < rows; ++i)
		delete[] maxValues[i];
	delete[] maxValues;

	return maxValue;
}

// 可用一维数组代替二维数组，得到f(i,j)只需第i行和i-1行当数据，不需i-2行以前的（结合书理解）
int getMaxValue2(const int* values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0)
		return -1;

	int* maxValues = new int[cols];
	
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int up = 0;
			int left = 0;
			if (i > 0)
				up = maxValues[j];
			else
				left = maxValues[j - 1];

			maxValues[j] = std::max(up, left) + values[i * cols + j];
		}
	}

	int maxValue = maxValues[cols - 1];
	delete[] maxValues;

	return maxValue;
}