#pragma once
#include <exception>
#include <stack>
#include <queue>
using namespace std;	// ���������ڴ������ռ���

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
		throw new exception("Queue is empty.");	// new����һ��ָ�룬�����Ҫ����ָ������

	T head = stack2.top();
	stack2.pop();

	return head;
}


// ���죺��������ʵ��һ��ջ

//˼·��
//��������q1, q2�������ǲ��뻹�ǵ�������֤����һ������Ϊ�ա���ô��
//������ջ����Ԫ�ز���ն��У�ͬʱ���ǿն��е�Ԫ�����β��뵽�ն��С���ʱ֮ǰ�ķǿն���
//��Ϊ�ն��У��ն��б�Ϊ�ǿն��С�
//���г�ջ�����ǿն��еĶ��׵������ɡ�

// ÿ��ѹ�뱣֤��Ԫ���ڿն��еĶ���
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