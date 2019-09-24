#pragma once

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * 实现排序的双向链表->使用中序遍历算法
 * 分成3部分：左子树 根 右子树 -> 递归处理
 * 左子树的最大值连接根节点 根节点连接右子树的最小值
 * 先得到链表尾节点
 */

BinaryTreeNode* convert(BinaryTreeNode* pRoot)
{
	// 已排好序的链表的最后节点（最大的值）
	BinaryTreeNode* pLastInList = nullptr;
	convertCore(pRoot, &pLastInList);	// 要保证返回修改的指针 取其地址
	// 由尾节点得到头节点
	BinaryTreeNode* pHeadInList = pLastInList;
	while (pHeadInList != nullptr && pHeadInList->m_pLeft != nullptr)
		pHeadInList = pHeadInList->m_pLeft;

	return pHeadInList;
}

void convertCore(BinaryTreeNode* pNode, BinaryTreeNode** pLastInList)
{
	if (pNode == nullptr)
		return;

	BinaryTreeNode* pCurrent = pNode;

	if (pCurrent->m_pLeft != nullptr)
		convertCore(pCurrent->m_pLeft, pLastInList);

	pCurrent->m_pLeft = *pLastInList;	// 10->8
	while (*pLastInList != nullptr)
		pCurrent = (*pLastInList)->m_pRight;	// 双向 8->10 链表的下一个节点

	*pLastInList = pCurrent;

	if (pCurrent->m_pRight != nullptr)
		convertCore(pCurrent->m_pRight, pLastInList);
}