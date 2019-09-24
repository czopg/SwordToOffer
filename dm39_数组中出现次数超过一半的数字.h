#pragma once
#include <exception>
#include <cstdlib>	// ����srand() rand()
#include <ctime>	// ����time()
using namespace std;

/**
 * ����1 �ο����������㷨���ź��������� ��λ�� ��������
 * �������ѡ��һ�����֣�����С�ķ�����ߣ�������ұߣ��������±�Ϊn/2��ΪҪ�ҵģ�
 * ������n/2����������ң������ұ��� --> �ݹ�	O(n)
 */

/* ���������һ���Ĳ��� partition */
/*------------------------------------------*/
int randomInRange(int start, int end)
{
	if (end > start)
	{
		srand(time(nullptr));
		return start + rand() % (end - start);	// ���������
	}
	return 0;
}

void swap(int* element1, int* element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}
 
int partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end < 0)
		throw new exception("Invalid input.");

	int index = randomInRange(start, end);
	swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])	
		{
			++small;
			if (small != index)		// �����ʱ�Ž���
				swap(&data[index], &data[small]);
		}
	}
	++small;
	swap(&data[small], &data[end]);	// ������Ŧֵ

	return small;
}
/*------------------------------------------*/
// ������	��Ч���봦��
int moreThanHalfNum(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return 0;

	int start = 0;
	int end = length - 1;
	int middle = length >> 1;
	int index = partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
			index = partition(numbers, length, start, index - 1);
		else
			index = partition(numbers, length, index + 1, end);
	}

	int result = numbers[middle];
	if (!checkMoreThanHalf(numbers,length,result))
		return 0;

	return result;
}

// ������ִ�����ߵ������Ƿ�������ִ�������һ��
bool checkMoreThanHalf(int* numbers, int length, int num)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == num)
			++times;
	}
	bool isMoreThanHalf = true;
	if (times * 2 < length)
		isMoreThanHalf = false;

	return isMoreThanHalf;
}


/**
 * �Ƽ�����2 ���������ص㣬���ִ�����ߵ����ֵĴ������������ֳ��ֵ��ܺͻ�Ҫ��
 * �������飬�ǳ��ֵ����ֺͶ�Ӧ�Ĵ����������ִ�����ߵ����ֺ��������ֵĳ��ִ������� ������
 * Ȼ���ֻʣ�´�����ߵ�����
 * O(n)
 */
int moreThanHalfNum2(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return 0;

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = numbers[i];	// ����Ϊ0�Ÿ���ֵ
			times = 1;
		}
		else if (result == numbers[i])
			++times;
		else
			--times;
	}

	if (!checkMoreThanHalf(numbers, length, result))
		return 0;

	return result;
}
