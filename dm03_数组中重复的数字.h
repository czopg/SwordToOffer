#pragma once
#include <iostream>
using namespace std;

// 题目一：找出数组中重复的数字 0~n-1 长度n
/**
 * 一维数组在内存中连续存储，可以根据下标定位对应的元素
 * 将下标为 i 的数字 m 和下标为 m 的数字相比较，不相等则交换，直到相等为止。时间复杂度 O(n)。
 */
bool duplicate(int* number, int length, int* duplication)	// duplication为重复值
{
	// 边界条件 无效输入检查
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
			// 不相等则交换
			int tmp = number[i];
			number[i] = number[tmp];
			number[tmp] = tmp;
		}
	}

	return false;
}


// 题目二：不修改数组找出重复的数字 1~n	长度n+1（要多1）
/**
 * 二分法划分数字区间 1～n 为 1～m（中间值）和 m+1～n，计算区间内数字在数组中出现次数，
 * 若大于该区间差值则应在该区间继续二分查找。时间复杂度 O(nlogn)。
 *
 * 不是把数组分段，而是把数字的值所在范围分段
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

	// 二分查找
	int start = 1;
	int end = length - 1;
	while (end > start)
	{
		int mid = (start + end) / 2;
		// 统计在整个数组里该区间的数字的数目
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

// 统计在整个数组里该区间的数字的数目
int countRange(int* number, int length, int start, int end)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
		if (number[i] >= start && number[i] <= end)
			++count;
	return count;
}