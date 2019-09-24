#pragma once

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * 二叉树的遍历算法		前序遍历和 对称 前序遍历
 * 要补足nullptr节点（针对节点值都相等的情况）
 */

bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

// 前序遍历和 对称 前序遍历的节点值比较
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
		&& isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}