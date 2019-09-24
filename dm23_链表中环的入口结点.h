#pragma once

// 题目：一个链表中包含环，如何找出环的入口结点？

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * 分解问题：1 链表中是否有环，找到环中的任意节点（两个辅助指针）
 * 2 算出环中的节点数（后移计数）
 * 3 找到环的入口节点（两个辅助指针，一个先移动环节点数个节点，再同时后移，相等时即为入口节点）
 */

// 找到环中相遇节点
ListNode* meetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode* pSlow = pHead->m_pNext;
	if (pSlow == nullptr)
		return nullptr;
	ListNode* pFast = pSlow->m_pNext;

	while (pFast != nullptr && pSlow != nullptr)
	{
		if (pFast == pSlow)
			return pFast;

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast != nullptr)
			pFast = pFast->m_pNext;
	}

	return nullptr;
}

ListNode* entryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetNode = meetingNode(pHead);
	if (meetNode == nullptr)
		return nullptr;

	// 计算环中的节点数
	int nodesInLoop = 1;
	ListNode* pNode1 = meetNode;
	while (pNode1->m_pNext != meetNode)
	{
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	// 一指针先移动环节点数个节点
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;

	// 同时后移
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode1;
}