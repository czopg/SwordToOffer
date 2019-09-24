#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * 从第一个公共点开始，之后它们的节点都是重合的，考虑从尾部向前查找
 * 思路一：后进先出 用栈存储两个链表节点，从栈顶开始比较
 * 思路二：先得到两个链表长度，让长的链表先走几步，然后两个链表同时遍历到第一个公共点
 */

ListNode* findFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;

	int nLength1 = getListLength(pHead1);
	int nLength2 = getListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;
	ListNode* pLongList = pHead1;
	ListNode* pShortList = pHead2;
	if (nLength1 < nLength2)
	{
		nLengthDif = nLength2 - nLength1;
		pLongList = pHead2;
		pShortList = pHead1;
	}

	for (int i = 0; i < nLengthDif; ++i)
		pLongList = pLongList->m_pNext;

	while ((pLongList != nullptr) && (pShortList != nullptr) && (pLongList != pShortList))
	{
		pLongList = pLongList->m_pNext;
		pShortList = pShortList->m_pNext;
	}

	ListNode* pFirstCommonNode = pLongList;

	return pFirstCommonNode;
}

unsigned int getListLength(ListNode* pHead)
{
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}

	return nLength;
}