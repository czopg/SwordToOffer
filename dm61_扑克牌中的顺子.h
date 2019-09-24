#pragma once
#include <stdlib.h>
/**
 * 扑克牌有数值1-13，大小王当作0，0可替代任意数值；
 * 先对5个数值的数组排序(qsort)，计算0的个数，计算相邻数值间隔的数字个数，
 * 其小于等于0的个数时则为顺子；注意若非0数值重复出现则不为顺子。
 */
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

bool isContinuous(int* nums, int len)
{
	if (nums == nullptr || len <= 0)
		return false;

	qsort(nums, len, sizeof(int), cmp);

	int numof0 = 0;
	int numofGap = 0;
	for (int i = 0; i < len && nums[i] == 0; ++i)
		++numof0;

	int small = numof0;
	int big = small + 1;
	while (big < len)
	{
		if (nums[big] == nums[small])
			return false;

		numofGap += nums[big] - nums[small] - 1;
		++small;
		++big;
	}

	return (numofGap > numof0) ? false : true;
}