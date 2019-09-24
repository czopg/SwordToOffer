#pragma once
#include <iostream>
using namespace std;

/**
 * �Ӿ����������֣����ݶ�ά������кź��кż������������׵�ַ��ƫ�������ҳ���ӦԪ��
 * �������Ͻ����ֻ����½�������Ϊ�жϵ�
 *
 * �����Ͻǣ����½ǣ��������֣�ÿ��ɾ��һ�л�һ������С���ҷ�Χ��ֱ���ҵ����֡�
 * ��ά�����ʾ��matrix[row * columns + column]
 */
bool findInMatrix(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;	// ���Ͻ�����
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