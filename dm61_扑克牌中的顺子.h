#pragma once
#include <stdlib.h>
/**
 * �˿�������ֵ1-13����С������0��0�����������ֵ��
 * �ȶ�5����ֵ����������(qsort)������0�ĸ���������������ֵ��������ָ�����
 * ��С�ڵ���0�ĸ���ʱ��Ϊ˳�ӣ�ע������0��ֵ�ظ�������Ϊ˳�ӡ�
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