#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

// ��Ŀ1 O(1)ʱ����ɾ��������ڵ�
void deleteListNode(ListNode** pHead, ListNode* pToBeDeleted)
{
	if (!*pHead || !pHead || !pToBeDeleted)
		return;

	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;	// �����ֵ��ֵ��Ҫɾ���Ľڵ�
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	else if (*pHead == pToBeDeleted)	// ֻ��һ���ڵ� ɾ��
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pHead = nullptr;
	}
	// ����ڵ� ɾ��β�ڵ� ˳�����
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != pToBeDeleted)	// �ҵ�ɾ���ڵ��ǰһ���ڵ�
			pNode = pNode->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pNode->m_pNext = nullptr;
	}
}


// ��Ŀ2 ɾ�������ĵ�������ظ��ڵ�
void deleteRepetition(ListNode** pHead)
{
	if (!*pHead || !pHead)
		return;

	ListNode* pNode = *pHead;
	ListNode* pPreNode = nullptr;	// ɾ���ڵ��ǰһ���ڵ�
	while (pNode != nullptr)	// ˳�����
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;	// �ж���־λ	����ҪҲ���ԣ�
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNext;
		}
		else
		{
			int value = pNode->m_nValue;	// �ظ�����ֵ�ѹ̶�
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value)	// ����ɾ���ظ��ڵ�
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}
			// ���ӽڵ�
			if (pPreNode == nullptr)	// ��ɾ������ͷ�ڵ㣨pPreNodeֻ���ʼΪ�գ�  *pHead == pNode������
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;	// �ж���һ���ڵ�
		}
	}

}


