#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/**
 * �ӵ�һ�������㿪ʼ��֮�����ǵĽڵ㶼���غϵģ����Ǵ�β����ǰ����
 * ˼·һ������ȳ� ��ջ�洢��������ڵ㣬��ջ����ʼ�Ƚ�
 * ˼·�����ȵõ����������ȣ��ó����������߼�����Ȼ����������ͬʱ��������һ��������
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