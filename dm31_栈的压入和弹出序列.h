#pragma once
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <stack>

/**
 * 1 如果下一个弹出的数字刚好是栈顶数字，那么直接弹出。
 * 2 如果下一个弹出的数字不在栈顶，我们把压栈序列中还没有入栈的数字压入辅助
 * 栈，直到把下一个需要弹出的数字压入栈顶为止。
 * 3 如果所有的数字都压入栈了仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。
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
			while (dataStack.empty() || dataStack.top() != *pNextPop)	// 压入数字
			{
				if (pNextPush - pPush == length)
					break;
				dataStack.push(*pNextPush);
				++pNextPush;
			}
			if (dataStack.top() != *pNextPop)	// 第3种情况
				break;
			dataStack.pop();
			++pNextPop;
		}
		if (dataStack.empty() && pNextPop - pPop == length)
			bPossible == true;
	}

	return bPossible;
} 