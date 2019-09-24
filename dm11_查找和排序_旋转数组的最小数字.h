#pragma once
#include <exception>
#include <cstdlib>	// 包含srand() rand()
#include <ctime>	// 包含time()
using namespace std;

// 顺序查找 二分查找 哈希表查找 二叉排序树查找
// 要对各种排序算法烂熟于心，能对额外空间消耗 平均时间复杂度 最坏时间复杂度 进行分析

/* 1 快速排序 */
// 随机数设置
int randomInRange(int start, int end)
{
	if (end > start)
	{
		srand(time(nullptr));
		return start + rand() % (end - start);	// 随机数设置
	}
	return 0;
}

// 元素交换
void swap(int* element1, int* element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

/**
 * 先用随机函数生成index，交换index和end（end变成枢纽值），定义small（指向最终存放最初
 * 的index指向的枢纽值），将index初始化并赋值为start。当index满足index<end时，交换index
 * 和small处的值。并++index。
 * ++small,将比枢纽值小的数都放在了此时small指针的前面。最终交换end和small处的值。
 */
 // 在数组中选择一个数字a(随机选择)，把数组中小于a的数移到a的左边，大于a的数移到a的右边，返回枢纽值a
int partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end < 0)
		throw new exception("Invalid input.");

	int index = randomInRange(start, end);
	swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])	// 把小于small（枢纽）的值放到其左边，因small从左开始递增
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

// 快速排序主函数	采用递归的方法
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


/* 2 给公司的员工的年龄排序 时间复杂度O(n) 辅助空间O(n) */
void sortAges(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
		throw new exception("Invalid input.");

	const int oldestAge = 99;
	int timesOfAges[oldestAge + 1] = { 0 };	// 这样赋0不是更简单吗？

	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];
		if (age<0 || age>oldestAge)
			throw new exception("Out of range.");
		++timesOfAges[age];	// 存放每个年龄出现的次数
	}

	int index = 0;
	for (int i = 0; i < oldestAge; ++i)
	{
		for (int j = 0; j < timesOfAges[i]; ++j)
		{
			ages[index] = i;// 每个年龄出现多少次则重新存放多少个这个年龄值，相当于排序
			++index;
		}
	}
}


/* 3 旋转数组的最小数字 采用二分查找 */
/**
 * 使用两个辅助指针，分别指向第一和最后一个元素，然后二分查找；（循环结束条件）最终会分别
 * 指向前面递增子数组的最后一个元素和后面递增子数组的第一个元素。
 */
int getMin(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
		throw new exception("Invalid input.");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;	// 特例：旋转0个元素
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)	// 循环结束条件
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		// 当下标为index1，index2和indexMid的值都相等时，只能顺序查找
		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
			return getMinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1])	// 在前面递增子数组
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
		/*else
			throw new exception("Invalid input.");*/	// 实例无此段
	}

	return numbers[indexMid];
}

// 范围内顺序查找
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
