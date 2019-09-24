#pragma once

#include <assert.h>
#include <stack>
using namespace std;

template <typename T>
class StackWithMin
{
public:
	StackWithMin() {};
	~StackWithMin() {};

	void push(const T& value);
	void pop();
	const T& Min();

private:
	stack<T> m_data;	// 数据栈
	stack<T> m_min;		// 辅助栈
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.size() == 0 || m_min.top() > value)
		m_min.push(value);
	else
		m_min.push(m_min.top());	// 辅助栈重复插入当前最小值
}

template <typename T>
void StackWithMin<T>::pop()
{
	// 条件返回错误则程序终止；错误和异常不同 错误是不应该出现的 异常是不可避免的
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::Min()
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	return m_min.top();
}