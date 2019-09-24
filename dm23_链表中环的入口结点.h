#pragma once

// ��Ŀ��һ�������а�����������ҳ�������ڽ�㣿

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * �ֽ����⣺1 �������Ƿ��л����ҵ����е�����ڵ㣨��������ָ�룩
 * 2 ������еĽڵ��������Ƽ�����
 * 3 �ҵ�������ڽڵ㣨��������ָ�룬һ�����ƶ����ڵ������ڵ㣬��ͬʱ���ƣ����ʱ��Ϊ��ڽڵ㣩
 */

// �ҵ����������ڵ�
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

	// ���㻷�еĽڵ���
	int nodesInLoop = 1;
	ListNode* pNode1 = meetNode;
	while (pNode1->m_pNext != meetNode)
	{
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}

	// һָ�����ƶ����ڵ������ڵ�
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;

	// ͬʱ����
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode1;
}