#pragma once
// ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ���������
// ��Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1��2��3��4��
// 5��ĳջ��ѹջ���У�����4��5��3��2��1�Ǹ�ѹջ���ж�Ӧ��һ���������У���
// 4��3��5��1��2�Ͳ������Ǹ�ѹջ���еĵ������С�

#include <stack>

/**
 * 1 �����һ�����������ָպ���ջ�����֣���ôֱ�ӵ�����
 * 2 �����һ�����������ֲ���ջ�������ǰ�ѹջ�����л�û����ջ������ѹ�븨��
 * ջ��ֱ������һ����Ҫ����������ѹ��ջ��Ϊֹ��
 * 3 ������е����ֶ�ѹ��ջ����Ȼû���ҵ���һ�����������֣���ô�����в�������һ���������С�
 */

bool isPopOrder(const int* pPush, const int* pPop, int length)
{
	bool bPossible = false;
	if (pPush != nullptr && pPop != nullptr && length > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;
		std::stack<int> dataStack;

		while (pNextPop - pPop < length)
		{
			while (dataStack.empty() || dataStack.top() != *pNextPop)	// ѹ������
			{
				if (pNextPush - pPush == length)
					break;
				dataStack.push(*pNextPush);
				++pNextPush;
			}
			if (dataStack.top() != *pNextPop)	// ��3�����
				break;
			dataStack.pop();
			++pNextPop;
		}
		if (dataStack.empty() && pNextPop - pPop == length)
			bPossible == true;
	}

	return bPossible;
} 