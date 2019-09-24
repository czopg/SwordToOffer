#pragma once
#include <stack>

// ������
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

// ����ȳ� ʹ��ջ
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


// �ݹ� ����ڵ������ܵ��³���ջ�����³���Բ���
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