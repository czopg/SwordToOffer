#pragma once

// 题目一：统计一个数字在排序数组中出现的次数。
/**
 * 二分查找		查找第一个k和最后一个k（递归），然后算出次数
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
		
		if (first > -1 && last > -1)	// 需要判断数组中是否包含k
			count = last - first + 1;
	}

	return count;
}


// 题目二：0到n-1中缺失的数字
// 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。
/**
 * 二分查找		查找第一个数组的值和下标不一样的数字
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
			if (middle == 0 || number[middle - 1] == middle - 1)	// 第一个数字
				return middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	if (left == length)	// 最后一个数字
		return length;

	return -1;
}


// 题目三：数组中数值和下标相等的元素
// 假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。
/**
 * 二分查找
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