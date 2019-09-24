#pragma once

// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * ����3��ָ�룬�ڱ���������ָ��ǰһ���ڵ� ��ǰ�ڵ� ��һ���ڵ�
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

		pNode->m_pNext = pPre;	// ����ָ��

		pPre = pNode;
		pNode = pNext;
	}

	return pReversedHead;
}