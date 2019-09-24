#pragma once
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// ��Ŀһ������һ�ö������ĸ���㣬���������ȡ��Ӹ���㵽Ҷ������ξ�����
// ��㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
/**
 * ��������㷨
 */
int treeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int left = treeDepth(pRoot->m_pLeft);
	int right = treeDepth(pRoot->m_pRight);
	return (left > right) ? (left + 1) : (right + 1);
}


// ��Ŀ��������һ�ö������ĸ���㣬�жϸ����ǲ���ƽ������������ĳ��������
// ��������������������������1����ô������һ��ƽ���������
/**
 * ��������㷨	����ÿ���ڵ�ʱ��¼����ȣ��������ж����Ƿ�ƽ��
 */
bool isBalanced(BinaryTreeNode* pRoot, int* depth)
{
	if (pRoot == nullptr)
	{
		*depth = 0;
		return true;
	}

	int left, right;
	if (isBalanced(pRoot->m_pLeft, &left) && isBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*depth= (left > right) ? (left + 1) : (right + 1);
			return true;
		}
	}

	return false;
}

bool isBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return isBalanced(pRoot, &depth);
}