#pragma once

// ��Ŀһ��ͳ��һ�����������������г��ֵĴ�����
/**
 * ���ֲ���		���ҵ�һ��k�����һ��k���ݹ飩��Ȼ���������
 */
int getFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int middle = (start + end) >> 2;
	int midValue = data[middle];
	if (midValue == k)
	{
		if ((middle > 0 && data[middle - 1] != k) || middle == 0)
			return middle;
		else
			end = middle - 1;
	}
	else if (midValue > k)
		end = middle - 1;
	else
		start = middle + 1;

	return getFirstK(data, length, k, start, end);
}

int getLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int middle = (start + end) >> 2;
	int midValue = data[middle];
	if (midValue == k)
	{
		if ((middle < length - 1 && data[middle + 1] != k) || middle == length - 1)
			return middle;
		else
			start = middle + 1;
	}
	else if (midValue > k)
		end = middle - 1;
	else
		start = middle + 1;

	return getFirstK(data, length, k, start, end);
}

int countOfKInArray(int* data, int length, int k)
{
	int count = 0;
	if (data != nullptr && length > 0)
	{
		int first = getFirstK(data, length, k, 0, length - 1);
		int last = getLastK(data, length, k, 0, length - 1);
		
		if (first > -1 && last > -1)	// ��Ҫ�ж��������Ƿ����k
			count = last - first + 1;
	}

	return count;
}


// ��Ŀ����0��n-1��ȱʧ������
// һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ������
// ���ڷ�Χ0��n-1֮�ڡ��ڷ�Χ0��n-1��n������������ֻ��һ�����ֲ��ڸ�����
// �У����ҳ�������֡�
/**
 * ���ֲ���		���ҵ�һ�������ֵ���±겻һ��������
 */
int getMissingNum(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (left + right) >> 2;
		if (number[middle] != middle)
		{
			if (middle == 0 || number[middle - 1] == middle - 1)	// ��һ������
				return middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	if (left == length)	// ���һ������
		return length;

	return -1;
}


// ��Ŀ������������ֵ���±���ȵ�Ԫ��
// ����һ�������������������ÿ��Ԫ�ض�������������Ψһ�ġ�����ʵ
// ��һ�������ҳ�����������һ����ֵ�������±��Ԫ�ء�
/**
 * ���ֲ���
 */
int getNumSameAsIndex(int* number, int length)
{
	if (number == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (left + right) >> 2;
		if (number[middle] == middle)
			return middle;

		if (number[middle] > middle)
			right = middle - 1;
		else
			left = middle + 1;
	}

	return -1;
}