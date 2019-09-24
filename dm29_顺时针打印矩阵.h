#pragma once

// ��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�

/**
 * ��������ֽ�ɼ��������⣺
 * 1 ѭ����ӡ����ÿ�δ�ӡһ��Ȧ��ѭ��������columns>startX*2 && rows>startY*2
 * 2 ��ӡȦ�ֳ�4����1������ 2���ϵ��� 3���ҵ��� 4���µ��� ��ͨ����ʼ�������ֹ����ѭ����ӡ
 *	 Ҫע���ӡ��2��4����ǰ���������� ���1Ȧ ����ֻ��1�С�1�л�1�����֣�
 */

// 1
void printMatrixClockwisely(int** numbers, int rows, int columns)
{
	if (numbers == nullptr || rows < 0 || columns < 0)
		return;

	int start = 0;	// ÿȦ��ʼ�����
	while (rows > start * 2 && columns > start * 2)
	{
		printMatrixInCircle(numbers, rows, columns, start);
		++start;
	}
}

// 2 ��ͼ�������ʼ����ֹ����
void printMatrixInCircle(int** numbers, int rows, int columns, int start)
{
	int endX = columns - 1 - start;	// ��ֹ�����
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