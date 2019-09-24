#pragma once
#include <list>
using namespace std;
/**
 * Լɪ������ -> �û�������ģ��ԲȦ
 * list ������������β��ʱ�����Ƶ�ͷ��
 */
int lastRemaining(int n, int m)
{
	if (n < 1 || m < 1)
		return -1;

	list<int> data;
	for (int i = 0; i < n; ++i)
		data.push_back(i);
	list<int>::iterator cur = data.begin();
	while (data.size() > 1)
	{
		for (int i = 1; i < m; ++i)
		{
			++cur;
			if (cur == data.end())
				cur = data.begin();
		}

		list<int>::iterator next = ++cur;
		--cur;
		data.erase(cur);
		cur = next;
	}

	return *cur;
}