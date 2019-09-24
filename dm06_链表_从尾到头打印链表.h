#pragma once
#include <stack>

// 单链表
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

// 后进先出 使用栈
void printListReversingly(ListNode* pHead)
{
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}


// 递归 链表节点过多可能导致程序栈溢出，鲁棒性不高
void printListReversingly_Recursion(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			printListReversingly_Recursion(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nKey);
	}
}