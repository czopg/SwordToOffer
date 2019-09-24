#pragma once
#include <vector>
#include <deque>

#include <exception>
using namespace std;

// ��Ŀһ���������ڵ����ֵ
// ����һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬
// �����������{2, 3, 4, 2, 6, 2, 5, 1}���������ڵĴ�С3����ôһ������6��
// �������ڣ����ǵ����ֵ�ֱ�Ϊ{4, 4, 6, 6, 6, 5}
/**
 * ֻ���п��������ֵ����ֵ�������˿��ڵĶ���
 * ���д�������±꣬��ĳ��ֵ�±�͵�ǰ�������ֵ�±�֮��>=���ڴ�С�������Ƴ���������
 */
vector<int> maxInWindow(const vector<int>& num, int size)
{
	vector<int> maxInWindow;	// �������ֵ
	if (num.size() > size && size > 0)
	{
		deque<int> index;
		for (int i = 0; i < size; ++i)
		{
			while (!num.empty() && num[i] >= num[index.back()])
				index.pop_back();

			index.push_back(i);
		}

		for (int i = size; i < num.size(); ++i)
		{
			maxInWindow.push_back(num[index.front()]);

			while (!num.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!num.empty() && index.front() <= (i - size))
				index.pop_front();

			index.push_back(i);
		}
		maxInWindow.push_back(num[index.front()]);
	}

	return maxInWindow;
}


// ��Ŀ�������е����ֵ
// ����һ�����в�ʵ�ֺ���max�õ����е����ֵ��O(1)
template <typename T>
class QueueWithMax
{
public:
	QueueWithMax() :currentIndex(0)
	{
	}
	~QueueWithMax()
	{
	}

	void push_back(T num)
	{
		while (!maxNums.empty() && num >= maxNums.back().number)
			maxNums.pop_back();

		InternalData internalData = { num,currentIndex };
		data.push_back(internalData);
		maxNums.push_back(internalData);
		++currentIndex;
	}

	void pop_front()
	{
		if (maxNums.empty())
			throw new exception("Queue is empty.");
		if (maxNums.front().index == data.front().index)
			maxNums.pop_front();

		data.pop_front();
	}

	T max() const
	{
		if (maxNums.empty())
			throw new exception("Queue is empty.");

		return maxNums.front().number;
	}

private:
	struct InternalData
	{
		T number;
		int index;
	};

	deque<InternalData> data;
	deque<InternalData> maxNums;
	int currentIndex;
};

