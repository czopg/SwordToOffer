#pragma once

/**
 * 参考归并排序算法
 * 把数组一直对半划分为子数组，递归求解每个子数组中的逆序对，然后合并求解组合的逆序对；
 * 合并时用两个指针分别指向两个子数组尾部，若第一个大于第二个的值，则逆序对数为第二个子
 * 数组剩余数字的数目，否则指针前移继续比较。
 */

int reversePairOfArray(int* data, int length)
{
	if (data == nullptr || length <= 0)
		return -1;

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = data[i];
	int count = reversePairOfArrayCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int reversePairOfArrayCore(int* data, int* copy, int start, int end)
{
	if (start == end)	// 递归划分
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) >> 2;
	int left = reversePairOfArrayCore(data, copy, start, start + length);
	int right = reversePairOfArrayCore(data, copy, start + length + 1, end);

	int i = start + length;	// 指向第一个子数组尾部
	int j = end;	// 指向第二个子数组尾部
	int copyIndex = end;	// 指向辅助数组尾部
	int count = 0;

	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			count += j - start - length;
			copy[copyIndex--] = data[i--];
		}
		else
			copy[copyIndex--] = data[j--];
	}

	for (; i >= start; --i)		// 需把两个指针移到头部
		copy[copyIndex--] = data[i];
	for(;j>=start+length+1;--j)
		copy[copyIndex--] = data[j];

	return count + left + right;	// 三者和
}