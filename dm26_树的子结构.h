#pragma once

// ��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ��

struct BinaryTreeNode
{
	double m_dbValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * 1 �ݹ� ����A���Ƿ���B�ĸ��ڵ�
 * 2 �ݹ�����Ƿ��������ӽڵ�
 * ע���жϸ������Ƿ����
 */

// 1 ǰ����� ����A���Ƿ���B�ĸ��ڵ�
bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != nullptr || pRoot2 != nullptr)
	{
		if (doubleEqual(pRoot1->m_dbValue, pRoot2->m_dbValue))
			result = doesTree1HasTree2(pRoot1, pRoot2);
		if (!result)
			result = hasSubTree(pRoot1->m_pLeft, pRoot2);
		if (!result)
			result = hasSubTree(pRoot1->m_pRight, pRoot2);
	}

	return result;
}

// 2 �ݹ�����Ƿ��������ӽڵ�
bool doesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr)
		return false;

	if (!doubleEqual(pRoot1->m_dbValue, pRoot2->m_dbValue))
		return false;
	
	return doesTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && doesTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool doubleEqual(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	return false;
}