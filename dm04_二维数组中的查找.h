#pragma once
#include <iostream>
using namespace std;

/**
 * 从具体问题入手，根据二维数组的行号和列号计算出相对于其首地址的偏移量，找出相应元素
 * 可用右上角数字或左下角数字作为判断点
 *
 * 从右上角（左下角）查找数字，每次删除一行或一列以缩小查找范围，直至找到数字。
 * 二维数组表示：matrix[row * columns + column]
 */
bool findInMatrix(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;	// 右上角数字
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				--column;
			else
				++row;
		}
	}

	return found;
}