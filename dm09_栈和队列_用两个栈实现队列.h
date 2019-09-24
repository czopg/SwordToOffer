#pragma once
#include <exception>
#include <stack>
#include <queue>
using namespace std;	// 容器定义在此命名空间里

template <typename T>
class CQueue
{
public:
	CQueue() {};
	~CQueue() {};

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}


template <typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("Queue is empty.");	// new返回一个指针，因而需要捕获指针类型

	T head = stack2.top();
	stack2.pop();

	return head;
}


// 延伸：两个队列实现一个栈

//思路：
//两个队列q1, q2。不管是插入还是弹出，保证总有一个队列为空。那么：
//队列入栈：将元素插入空队列，同时将非空队列的元素依次插入到空队列。此时之前的非空队列
//变为空队列，空队列变为非空队列。
//队列出栈：将非空队列的队首弹出即可。

// 每次压入保证新元素在空队列的队首
template <typename T>
class QueueToStack
{
public:
	void _push(T n)
	{
		if (q1.empty())
		{
			q1.push(n);
			while (q2.size() > 0)
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
		else
		{
			q2.push(n);
			while (q1.size() > 0)
			{
				q2.push(q1.front());
				q1.pop();
			}
		}
	}

	void _pop()
	{
		if (q1.empty())
			q2.pop();
		else
			q1.pop();
	}

	T _top()
	{
		if (q1.empty())
			return q2.front();
		else
			return q1.front();
	}

	bool _empty()
	{
		return (q1.empty() && q2.empty());
	}

private:
	queue<T> q1;
	queue<T> q2;
};