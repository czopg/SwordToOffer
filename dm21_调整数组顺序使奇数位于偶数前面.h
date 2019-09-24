#pragma once

// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

/** 
 * 采用 两个辅助指针 变量指向数组头尾
 * 前为偶后为奇则交换
 * 采用 函数指针 指向分组标准，提供扩展性
 */

void reOrder(int* pData, int length, bool (*func)(int))
{
	if (pData == nullptr || length <= 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			++pBegin;
		while (pBegin < pEnd && func(*pEnd))
			--pEnd;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void reOrderOddEven(int* pData, int length)
{
	reOrder(pData, length, isEven);
}