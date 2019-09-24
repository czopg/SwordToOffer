#pragma once
#include <exception>
#include <cstdlib>	// 包含srand() rand()
#include <ctime>	// 包含time()
using namespace std;

/**
 * 方法1 参考快速排序算法，排好序的数组的 中位数 符合条件
 * 数组随机选择一个数字，比它小的放在左边，大的在右边；若数字下标为n/2则为要找的，
 * 若大于n/2则在其左边找，否则右边找 --> 递归	O(n)
 */

/* 与快速排序一样的部分 partition */
/*------------------------------------------*/
int randomInRange(int start, int end)
{
	if (end > start)
	{
		srand(time(nullptr));
		return start + rand() % (end - start);	// 随机数设置
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
			if (small != index)		// 不相等时才交换
				swap(&data[index], &data[small]);
		}
	}
	++small;
	swap(&data[small], &data[end]);	// 交换枢纽值

	return small;
}
/*------------------------------------------*/
// 主函数	无效输入处理
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

// 检验出现次数最高的数字是否满足出现次数超过一半
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
 * 推荐方法2 根据数组特点，出现次数最高的数字的次数比其它数字出现的总和还要大
 * 遍历数组，记出现的数字和对应的次数，将出现次数最高的数字和其它数字的出现次数互相 抵消，
 * 然后会只剩下次数最高的数字
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
			result = numbers[i];	// 次数为0才赋新值
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
