#pragma once

/**
 * �ο��鲢�����㷨
 * ������һֱ�԰뻮��Ϊ�����飬�ݹ����ÿ���������е�����ԣ�Ȼ��ϲ������ϵ�����ԣ�
 * �ϲ�ʱ������ָ��ֱ�ָ������������β��������һ�����ڵڶ�����ֵ�����������Ϊ�ڶ�����
 * ����ʣ�����ֵ���Ŀ������ָ��ǰ�Ƽ����Ƚϡ�
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
	if (start == end)	// �ݹ黮��
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) >> 2;
	int left = reversePairOfArrayCore(data, copy, start, start + length);
	int right = reversePairOfArrayCore(data, copy, start + length + 1, end);

	int i = start + length;	// ָ���һ��������β��
	int j = end;	// ָ��ڶ���������β��
	int copyIndex = end;	// ָ��������β��
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

	for (; i >= start; --i)		// �������ָ���Ƶ�ͷ��
		copy[copyIndex--] = data[i];
	for(;j>=start+length+1;--j)
		copy[copyIndex--] = data[j];

	return count + left + right;	// ���ߺ�
}