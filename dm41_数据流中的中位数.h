#pragma once
#include <vector>
#include <algorithm>	// heap
#include <functional>
#include <exception>
using namespace std;

/**
 * �������е�������Ҫ�洢��ʵ����ߵ����ݶ����ұߵ�����ҪС����������ݵ����ֵ���ұ�����
 * ����Сֵ�����λ��
 * ���������Ѻ���С����ʵ�֣���������O(logn)�������λ��O(1)
 * ʵ�֣���֤������ƽ���������ݣ���������Ϊż��ʱ���� ��С�� ������������
 * 1����������С�ѵ�����С�����ѵ�������֣���Ӧ�����������Ѳ������ѵ�������ֵ���������С��
 * 2�����������ѵ����ִ�����С�ѵ���С���֣�...
 */

// ��������ʱ��less<T>()������less<T>����С���ŵ�...

template <typename T>
class DynamicArray
{
public:
	// ����������������
	void insertNum(T num)
	{
		if (((min.size() + max.size()) & 1) == 0)	// Ϊż��
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

	// �����λ��
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
	vector<T> min;	// ��С��
	vector<T> max;	// ����
};

