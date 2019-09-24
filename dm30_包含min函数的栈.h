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
	stack<T> m_data;	// ����ջ
	stack<T> m_min;		// ����ջ
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);

	if (m_min.size() == 0 || m_min.top() > value)
		m_min.push(value);
	else
		m_min.push(m_min.top());	// ����ջ�ظ����뵱ǰ��Сֵ
}

template <typename T>
void StackWithMin<T>::pop()
{
	// �������ش����������ֹ��������쳣��ͬ �����ǲ�Ӧ�ó��ֵ� �쳣�ǲ��ɱ����
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