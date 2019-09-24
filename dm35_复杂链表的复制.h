#pragma once

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSiBling;	// 指向任意节点或nullptr
};

/**
 * 为了实现O(n)的时间复杂度和O(1)的空间的复杂度
 * 复杂链表的复制分解成3步：
 * 1 复制原链表的节点并连接到复制节点的后面，如A A' B B'，形成一个长链表
 * 2 设置复制链表节点的m_pSiBling指针，节点N的m_pSiBling指向S，则N'的m_pSiBling指向S的下一个节点S'
 * 3 拆分长链表：偶数节点通过m_pNext连接即为要求的复制链表
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