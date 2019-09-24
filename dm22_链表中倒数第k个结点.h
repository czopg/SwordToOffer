#pragma once

// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * 采用 两个辅助指针 
 * 走k-1步 然后两个一起走
 */

ListNode* findKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)
		return nullptr;

	ListNode* pAHead = pListHead;
	ListNode* pBehind = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pAHead->m_pNext != nullptr)	// 总节点数可能不大于k
			pAHead = pAHead->m_pNext;
		else
			return nullptr;
	}

	pBehind = pListHead;
	while (pAHead->m_pNext != nullptr)
	{
		pAHead = pAHead->m_pNext;
		pBehind = pBehind->m_pNext;
	}

	return pBehind;
}