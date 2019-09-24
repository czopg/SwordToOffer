#pragma once
#include <iostream>
using namespace std;

// ��Ŀһ���ҳ��������ظ������� 0~n-1 ����n
/**
 * һά�������ڴ��������洢�����Ը����±궨λ��Ӧ��Ԫ��
 * ���±�Ϊ i ������ m ���±�Ϊ m ��������Ƚϣ�������򽻻���ֱ�����Ϊֹ��ʱ�临�Ӷ� O(n)��
 */
bool duplicate(int* number, int length, int* duplication)	// duplicationΪ�ظ�ֵ
{
	// �߽����� ��Ч������
	if (number == nullptr || length <= 0)
		return false;

	for (int i = 0; i < length; ++i)
	{
		if (number[i]<0 || number[i]>length - 1)
			return false;
	}

	for (int i = 0; i < length; ++i)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				*duplication = number[i];
				return true;
			}
			// ������򽻻�
			int tmp = number[i];
			number[i] = number[tmp];
			number[tmp] = tmp;
		}
	}

	return false;
}


// ��Ŀ�������޸������ҳ��ظ������� 1~n	����n+1��Ҫ��1��
/**
 * ���ַ������������� 1��n Ϊ 1��m���м�ֵ���� m+1��n�����������������������г��ִ�����
 * �����ڸ������ֵ��Ӧ�ڸ�����������ֲ��ҡ�ʱ�临�Ӷ� O(nlogn)��
 *
 * ���ǰ�����ֶΣ����ǰ����ֵ�ֵ���ڷ�Χ�ֶ�
 */
int getDuplication(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return -1;

	for (int i = 0; i < length; ++i)
	{
		if (number[i]<1 || number[i]>length - 1)	// 1~length-1
			return -1;
	}

	// ���ֲ���
	int start = 1;
	int end = length - 1;
	while (end > start)
	{
		int mid = (start + end) / 2;
		// ͳ�����������������������ֵ���Ŀ
		int count = countRange(number, length, start, mid);

		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > mid - start + 1)
			end = mid;
		else
			start = mid + 1;
	}

	return -1;
}

// ͳ�����������������������ֵ���Ŀ
int countRange(int* number, int length, int start, int end)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
		if (number[i] >= start && number[i] <= end)
			++count;
	return count;
}