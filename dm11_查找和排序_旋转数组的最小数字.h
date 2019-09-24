#pragma once
#include <exception>
#include <cstdlib>	// ����srand() rand()
#include <ctime>	// ����time()
using namespace std;

// ˳����� ���ֲ��� ��ϣ����� ��������������
// Ҫ�Ը��������㷨�������ģ��ܶԶ���ռ����� ƽ��ʱ�临�Ӷ� �ʱ�临�Ӷ� ���з���

/* 1 �������� */
// ���������
int randomInRange(int start, int end)
{
	if (end > start)
	{
		srand(time(nullptr));
		return start + rand() % (end - start);	// ���������
	}
	return 0;
}

// Ԫ�ؽ���
void swap(int* element1, int* element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

/**
 * ���������������index������index��end��end�����Ŧֵ��������small��ָ�����մ�����
 * ��indexָ�����Ŧֵ������index��ʼ������ֵΪstart����index����index<endʱ������index
 * ��small����ֵ����++index��
 * ++small,������ŦֵС�����������˴�ʱsmallָ���ǰ�档���ս���end��small����ֵ��
 */
 // ��������ѡ��һ������a(���ѡ��)����������С��a�����Ƶ�a����ߣ�����a�����Ƶ�a���ұߣ�������Ŧֵa
int partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end < 0)
		throw new exception("Invalid input.");

	int index = randomInRange(start, end);
	swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])	// ��С��small����Ŧ����ֵ�ŵ�����ߣ���small����ʼ����
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

// ��������������	���õݹ�ķ���
void quickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = partition(data, length, start, end);
	if (index > start)
		quickSort(data, length, start, index - 1);
	if(index<end)
		quickSort(data, length, index + 1, end);
}


/* 2 ����˾��Ա������������ ʱ�临�Ӷ�O(n) �����ռ�O(n) */
void sortAges(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
		throw new exception("Invalid input.");

	const int oldestAge = 99;
	int timesOfAges[oldestAge + 1] = { 0 };	// ������0���Ǹ�����

	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];
		if (age<0 || age>oldestAge)
			throw new exception("Out of range.");
		++timesOfAges[age];	// ���ÿ��������ֵĴ���
	}

	int index = 0;
	for (int i = 0; i < oldestAge; ++i)
	{
		for (int j = 0; j < timesOfAges[i]; ++j)
		{
			ages[index] = i;// ÿ��������ֶ��ٴ������´�Ŷ��ٸ��������ֵ���൱������
			++index;
		}
	}
}


/* 3 ��ת�������С���� ���ö��ֲ��� */
/**
 * ʹ����������ָ�룬�ֱ�ָ���һ�����һ��Ԫ�أ�Ȼ����ֲ��ң���ѭ���������������ջ�ֱ�
 * ָ��ǰ���������������һ��Ԫ�غͺ������������ĵ�һ��Ԫ�ء�
 */
int getMin(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
		throw new exception("Invalid input.");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;	// ��������ת0��Ԫ��
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)	// ѭ����������
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		// ���±�Ϊindex1��index2��indexMid��ֵ�����ʱ��ֻ��˳�����
		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
			return getMinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])	// ��ǰ�����������
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
		/*else
			throw new exception("Invalid input.");*/	// ʵ���޴˶�
	}

	return numbers[indexMid];
}

// ��Χ��˳�����
int getMinInOrder(int numbers[], int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}
