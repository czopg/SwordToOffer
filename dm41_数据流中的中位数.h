#pragma once
#include <vector>
#include <algorithm>	// heap
#include <functional>
#include <exception>
using namespace std;

/**
 * 数据流中的数据先要存储，实现左边的数据都比右边的数据要小，由左边数据的最大值和右边数据
 * 的最小值求得中位数
 * 考虑用最大堆和最小堆来实现，插入数据O(logn)，获得中位数O(1)
 * 实现：保证两个堆平均分配数据，数据总数为偶数时插入 最小堆 ，奇数则最大堆
 * 1）若插入最小堆的数字小于最大堆的最大数字，则应把它插入最大堆并把最大堆的最大数字弹出插入最小堆
 * 2）若插入最大堆的数字大于最小堆的最小数字，...
 */

// 函数调用时用less<T>()而不是less<T>，有小括号的...

template <typename T>
class DynamicArray
{
public:
	// 插入数据流的数据
	void insertNum(T num)
	{
		if (((min.size() + max.size()) & 1) == 0)	// 为偶数
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}

			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else
		{
			if (min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}

			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	// 获得中位数
	T getMedian()
	{
		int dataSize = min.size() + max.size();
		if (dataSize == 0)
			throw new exception("Invalid input.");

		T median;
		if (dataSize & 1 == 1)
			median = min[0];
		else
			median = (min[0] + max[0]) >> 1;

		return median;
	}

private:
	vector<T> min;	// 最小堆
	vector<T> max;	// 最大堆
};

