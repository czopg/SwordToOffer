#pragma once

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSiBling;	// ָ������ڵ��nullptr
};

/**
 * Ϊ��ʵ��O(n)��ʱ�临�ӶȺ�O(1)�Ŀռ�ĸ��Ӷ�
 * ��������ĸ��Ʒֽ��3����
 * 1 ����ԭ����Ľڵ㲢���ӵ����ƽڵ�ĺ��棬��A A' B B'���γ�һ��������
 * 2 ���ø�������ڵ��m_pSiBlingָ�룬�ڵ�N��m_pSiBlingָ��S����N'��m_pSiBlingָ��S����һ���ڵ�S'
 * 3 ��ֳ�����ż���ڵ�ͨ��m_pNext���Ӽ�ΪҪ��ĸ�������
 */

// 1
void cloneNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		ComplexListNode* pClone = new ComplexListNode();
		pClone->m_nValue = pNode->m_nValue;
		pClone->m_pNext = pNode->m_pNext;	// A'->B
		pClone->m_pSiBling = nullptr;

		pNode->m_pNext = pClone;	// A->A'
		pNode = pClone->m_pNext;
	}
}
// 2
void connectSiBlingNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		ComplexListNode* pClone = pNode->m_pNext;
		if (pNode->m_pSiBling != nullptr)
		{
			pClone->m_pSiBling = pNode->m_pSiBling->m_pNext;
		}

		pNode = pClone->m_pNext;
	}
}
// 3
ComplexListNode* reconnectNode(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = nullptr;
	ComplexListNode* pCloneNode = nullptr;

	if (pNode != nullptr)
	{
		pCloneHead = pCloneNode = pNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;	// A->B
		
		pNode = pNode->m_pNext;
	}

	while (pNode != nullptr)
	{
		pCloneNode->m_pNext = pNode->m_pNext;	// A'->B'
		pCloneNode = pCloneNode->m_pNext;	// B'

		pNode->m_pNext = pCloneNode->m_pNext;	// B->C
		pNode = pNode->m_pNext;	// C
	}

	return pCloneHead;
}

ComplexListNode* clone(ComplexListNode* pHead)
{
	cloneNode(pHead);
	connectSiBlingNode(pHead);
	return reconnectNode(pHead);
}