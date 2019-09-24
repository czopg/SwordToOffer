#pragma once
#include <vector>
#include <deque>

#include <exception>
using namespace std;

// 题目一：滑动窗口的最大值
// 给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}
/**
 * 只把有可能是最大值的数值存入两端开口的队列
 * 队列存入的是下标，若某数值下标和当前处理的数值下标之差>=窗口大小，则已移出滑动窗口
 */
vector<int> maxInWindow(const vector<int>& num, int size)
{
	vector<int> maxInWindow;	// 所有最大值
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


// 题目二：队列的最大值
// 定义一个队列并实现函数max得到队列的最大值，O(1)
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

