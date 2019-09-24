#pragma once
#include <algorithm>

/**
 * �ݹ���� �����ظ��������� -> ���ö�̬�滮 ʹ�� ��ά���� �������м�ֵ
 * ��Ҳ����һά������棬��Ϊֻ�豣��õ�����ǰ����ֵ��
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

// ����һά��������ά���飬�õ�f(i,j)ֻ���i�к�i-1�е����ݣ�����i-2����ǰ�ģ��������⣩
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