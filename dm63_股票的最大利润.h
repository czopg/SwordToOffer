#pragma once
/**
 * 扫描到i时保存有前i-1个数中的最小值
 */
int diff(int* nums, int len)
{
	if (nums == nullptr || len < 2)
		return -1;

	int min = nums[0];
	int maxDiff = nums[1] - min;
	for (int i = 2; i < len; ++i)
	{
		if (nums[i - 1] < min)
			min = nums[i - 1];

		int curDiff = nums[i] - min;
		if (curDiff > maxDiff)
			maxDiff = curDiff;
	}

	return maxDiff;
}