#pragma once

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

// 题目1 O(1)时间内删除单链表节点
void deleteListNode(ListNode** pHead, ListNode* pToBeDeleted)
{
	if (!*pHead || !pHead || !pToBeDeleted)
		return;

	if (pToBeDeleted->m_pNext != nullptr)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;	// 后面的值赋值给要删除的节点
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = nullptr;
	}
	else if (*pHead == pToBeDeleted)	// 只有一个节点 删除
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		*pHead = nullptr;
	}
	// 多个节点 删除尾节点 顺序遍历
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != pToBeDeleted)	// 找到删除节点的前一个节点
			pNode = pNode->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pNode->m_pNext = nullptr;
	}
}


// 题目2 删除排序后的单链表的重复节点
void deleteRepetition(ListNode** pHead)
{
	if (!*pHead || !pHead)
		return;

	ListNode* pNode = *pHead;
	ListNode* pPreNode = nullptr;	// 删除节点的前一个节点
	while (pNode != nullptr)	// 顺序遍历
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;	// 判定标志位	不需要也可以？
		if (pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNext;
		}
		else
		{
			int value = pNode->m_nValue;	// 重复的数值已固定
			ListNode* pToBeDel = pNode;
			while (pToBeDel != nullptr && pToBeDel->m_nValue == value)	// 连续删除重复节点
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}
			// 连接节点
			if (pPreNode == nullptr)	// 若删除的是头节点（pPreNode只有最开始为空）  *pHead == pNode可以吗？
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;	// 判断下一个节点
		}
	}

}


