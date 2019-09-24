#pragma once
#include <cmath>
/**
 * ����ͨ�� �������� ��������⣺��1001λ
 * 1λ����0-9��10����2λ����10-99��90������180�����֣�3λ����100-999��900������
 * 2700�����֣���ʱ��1001-10-180=811λ���֣�811<2700��811=270��3+1������Ϊ100��
 * ʼ��270λ��370�е�һλ���ӵ�0λ��ʼ������Ϊ7
 */

// ������
int digitInIndex(int index)
{
	if (index < 0)
		return -1;

	int digit = 1;
	while (true)
	{
		int numbers = countOfInteger(digit);
		if (index < numbers * digit)
			return digitInIndex(index, digit);

		index -= numbers * digit;	// ���ڸ÷�Χ�����ȥ
		++digit;
	}

	return -1;
}

// ����mλ��������Ŀ
int countOfInteger(int digit)
{
	if (digit == 1)
		return 10;

	int count = (int)std::pow(10, digit - 1);
	return count * 9;
}

// ������mλ���е��Ǹ�����
int digitInIndex(int index, int digit)
{
	int number = beginNumber(digit) + index / digit;	// 811=270*3+1
	int rightOfIndex = digit - index % digit;	// ����0->��λ 1->ʮλ 2->��λ
	for (int i = 1; i < rightOfIndex; ++i)
		number /= 10;

	return number % 10;
}

// ����mλ����ʼ����
int beginNumber(int digit)
{
	if (digit == 1)
		return 0;

	return (int)std::pow(10, digit - 1);
}