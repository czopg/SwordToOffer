#pragma once

// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

/**
 * 复杂问题分解成几个简单问题：
 * 1 循环打印矩阵，每次打印一个圈；循环条件：columns>startX*2 && rows>startY*2
 * 2 打印圈分成4步：1）左到右 2）上到下 3）右到左 4）下到上 ；通过起始坐标和终止坐标循环打印
 *	 要注意打印第2～4步的前提条件（因 最后1圈 可能只有1行、1列或1个数字）
 */

// 1
void printMatrixClockwisely(int** numbers, int rows, int columns)
{
	if (numbers == nullptr || rows < 0 || columns < 0)
		return;

	int start = 0;	// 每圈起始坐标点
	while (rows > start * 2 && columns > start * 2)
	{
		printMatrixInCircle(numbers, rows, columns, start);
		++start;
	}
}

// 2 画图分清楚起始和终止坐标
void printMatrixInCircle(int** numbers, int rows, int columns, int start)
{
	int endX = columns - 1 - start;	// 终止坐标点
	int endY = rows - 1 - start;

	// 1)
	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		printNumber(number);
	}

	// 2)
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			printNumber(number);
		}
	}

	// 3)
	if (start < endY && start < endX)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	// 4)
	if (start < endY - 1 && start < endX)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			printNumber(number);
		}
	}
}

void printNumber(int num)
{
	printf("%d\t", num);
}