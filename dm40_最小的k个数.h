#pragma once
#include <vector>
#include <set>
#include <functional>
using namespace std;

/**
 * ����1 �ο����������㷨��partition����������dm39
 * �Ե�k������Ϊ��Ŧ���ݹ����	O(n)
 */

void getLeastNumbers(int* input, int n, int* output, int k)
{
	if (input == nullptr || output == nullptr || n < k || n <= 0 || k <= 0)
		return;

	int start = 0;
	int end = n - 1;
	int index = partition(input, n, start, end);
	while (index != k-1)
	{
		if (index > k - 1)
			partition(input, n, start, index - 1);
		else
			partition(input, n, index + 1, end);
	}

	for (int i = 0; i < k; ++k)
		output[i] = input[i];
}


/**
 * ����2 �����ö��������洢��С��������Ҫ�����з����������ֵȻ��ɾ���滻
 * ���öѡ������������Ķ���������STL��multiset	O(nlogk)
 */

typedef multiset<int, greater<int>> setLeast;
typedef multiset<int, greater<int>>::iterator setIter;
void getLeastNumbers2(const vector<int>& numbers, setLeast& leastNums, int k)
{
	leastNums.clear();
	if (k <= 0 || numbers.size() < k)
		return;

	vector<int>::const_iterator iter = numbers.begin();
	for (; iter != numbers.end(); ++iter)
	{
		if (leastNums.size() < k)
			leastNums.insert(*iter);
		else
		{
			setIter greatNum = leastNums.begin();
			if (*iter < *greatNum)
			{
				leastNums.erase(greatNum);
				leastNums.insert(*iter);
			}
		}
	}
}
