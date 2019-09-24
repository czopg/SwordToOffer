#pragma once

// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * 定义3个指针，在遍历过程中指向前一个节点 当前节点 下一个节点
 */

ListNode* reverseList(ListNode* pHead)
{
	ListNode* pReversedHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPre = nullptr;

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		if (pNext == nullptr)
			pReversedHead = pNode;

		pNode->m_pNext = pPre;	// 重新指向

		pPre = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}