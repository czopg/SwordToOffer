#pragma once

// ��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
// ���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣

/**
 * ��3�������1 �������� 2 �����������Ǹ��ڵ�����ӽڵ� 3 �����������Ǹ��ڵ�����ӽڵ�
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
	if (pNode->m_pRight != nullptr)	// ����1 ���������������ӽڵ�
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

		while (pParent != nullptr && pParent->m_pRight == pCurrent)	// ����2
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}