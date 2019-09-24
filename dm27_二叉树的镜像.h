#pragma once

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * �������ı����㷨 ǰ�����
 * �������ӽڵ�Ľڵ㣬�򽻻��ӽڵ�
 */

void mirrorBinaryTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;
	if (pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr)
		return;

	BinaryTreeNode* pTemp = pRoot->m_pLeft;	// ����
	pRoot->m_pLeft = pRoot->m_pRight;
	pRoot->m_pRight = pTemp;

	if (pRoot->m_pLeft)
		mirrorBinaryTree(pRoot->m_pLeft);
	if (pRoot->m_pRight)
		mirrorBinaryTree(pRoot->m_pRight);
}