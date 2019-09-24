#pragma once
#include <vector>
#include <set>
#include <functional>
using namespace std;

/**
 * 方法1 参考快速排序算法的partition函数，类似dm39
 * 以第k个数作为枢纽，递归求解	O(n)
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
 * 方法2 考虑用二叉树来存储最小的数，需要在其中反复查找最大值然后删除替换
 * 可用堆、红黑树等特殊的二叉树，即STL的multiset	O(nlogk)
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
