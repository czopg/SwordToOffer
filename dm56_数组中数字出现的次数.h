#pragma once
// 题目一：数组中只出现一次的两个数字
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。
/**
 * 通过位运算 异或 可求出数组中 一个 只出现一次的数字 -> 因而可考虑原数组分组
 * 分组标准：以原数组异或结果的右边第一个1为标准，此位为1是一组，为0是一组
 */
void findNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
		return;

	int result_or = 0;
	for (int i = 0; i < length; ++i)
		result_or ^= data[i];	// 异或

	int indexOf1 = findIndexOf1(result_or);

	*num1 = *num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (isBit1(data[j], indexOf1))
			*num1 ^= data[j];
		else
			*num2 ^= data[j];
	}
}

// 找到异或结果的右边第一个1
int findIndexOf1(int num)
{
	int indexBit = 0;
	while ((num & 1 == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

// 判断此位是否是1
bool isBit1(int num, int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}


// 题目二：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个只出现一次的数字。
/**
 * 沿用位运算思路 把所有数字的每一位分别加起来，其和能被3整除
 * 则只出现一次的数字该位为0，否则为1。
 */
int findNumAppearOnce(int data[], int length)
{
	if (data == nullptr || length <= 0)
		return -1;

	int bitSum[32] = { 0 };
	for (int i = 0; i < length; ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = data[i] & bitMask;
			if (bit != 0)
				bitSum[j] += bit;
			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;
}