#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * �ݹ� ע��ݹ��������
 */

ListNode* mergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode* pMergedHead = nullptr;
	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergedHead = pHead1;
		pMergedHead->m_pNext = mergeList(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->m_pNext = mergeList(pHead1, pHead2->m_pNext);
	}

	return pMergedHead;
}