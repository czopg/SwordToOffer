#pragma once

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * ʵ�������˫������->ʹ����������㷨
 * �ֳ�3���֣������� �� ������ -> �ݹ鴦��
 * �����������ֵ���Ӹ��ڵ� ���ڵ���������������Сֵ
 * �ȵõ�����β�ڵ�
 */

BinaryTreeNode* convert(BinaryTreeNode* pRoot)
{
	// ���ź������������ڵ㣨����ֵ��
	BinaryTreeNode* pLastInList = nullptr;
	convertCore(pRoot, &pLastInList);	// Ҫ��֤�����޸ĵ�ָ�� ȡ���ַ
	// ��β�ڵ�õ�ͷ�ڵ�
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
		pCurrent = (*pLastInList)->m_pRight;	// ˫�� 8->10 �������һ���ڵ�

	*pLastInList = pCurrent;

	if (pCurrent->m_pRight != nullptr)
		convertCore(pCurrent->m_pRight, pLastInList);
}