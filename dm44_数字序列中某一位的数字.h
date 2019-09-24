#pragma once
#include <cmath>
/**
 * 考虑通过 具体例子 分析好理解：第1001位
 * 1位数有0-9共10个，2位数有10-99共90个即有180个数字，3位数有100-999共900个即有
 * 2700个数字（此时第1001-10-180=811位数字，811<2700，811=270×3+1，则其为100开
 * 始第270位数370中的一位，从第0位开始计数即为7
 */

// 主函数
int digitInIndex(int index)
{
	if (index < 0)
		return -1;

	int digit = 1;
	while (true)
	{
		int numbers = countOfInteger(digit);
		if (index < numbers * digit)
			return digitInIndex(index, digit);

		index -= numbers * digit;	// 不在该范围内则减去
		++digit;
	}

	return -1;
}

// 返回m位数的总数目
int countOfInteger(int digit)
{
	if (digit == 1)
		return 10;

	int count = (int)std::pow(10, digit - 1);
	return count * 9;
}

// 返回在m位数中的那个数字
int digitInIndex(int index, int digit)
{
	int number = beginNumber(digit) + index / digit;	// 811=270*3+1
	int rightOfIndex = digit - index % digit;	// 余数0->百位 1->十位 2->个位
	for (int i = 1; i < rightOfIndex; ++i)
		number /= 10;

	return number % 10;
}

// 返回m位数开始的树
int beginNumber(int digit)
{
	if (digit == 1)
		return 0;

	return (int)std::pow(10, digit - 1);
}