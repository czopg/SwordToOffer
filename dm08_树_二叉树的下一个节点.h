#pragma once

// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

/**
 * 分3种情况：1 有右子树 2 无右子树且是父节点的左子节点 3 无右子树且是父节点的右子节点
 */
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* getNextNode(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)	// 情形1 找右子树的最左子节点
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}

	if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;

		while (pParent != nullptr && pParent->m_pRight == pCurrent)	// 情形2
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}