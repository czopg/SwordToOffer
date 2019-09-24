#pragma once

// ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
// �����1��ʼ�������������β����ǵ�����1����㡣

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * ���� ��������ָ�� 
 * ��k-1�� Ȼ������һ����
 */

ListNode* findKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)
		return nullptr;

	ListNode* pAHead = pListHead;
	ListNode* pBehind = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pAHead->m_pNext != nullptr)	// �ܽڵ������ܲ�����k
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