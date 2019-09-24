#pragma once

/**
 * 考虑n有多少位数，每一位变化0-9，
 * 假设当前位为weight，权重base，其左边高位为round，右边低位为former(=n%base)
 * 则 1) weight=0 -> round*base 2) weight=1 -> round*base+former+1
 * 3) weight>1 -> round*base+base
 * 从个位到最高位循环weight		O(logn)
 */
// https://blog.csdn.net/yi_afly/article/details/52012593

int countOf1In1Ton(int n)
{
	if (n < 1)
		return 0;

	int count = 0;
	int base = 1;
	int round = n;
	while (round > 0)
	{
		int weight = round % 10;	// 从个位到最高位循环
		round /= 10;
		count = round * base;
		if (weight == 1)
			count += n % base + 1;
		else if (weight > 1)
			count += base;
		base *= 10;
	}

	return count;
}