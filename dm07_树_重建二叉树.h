#pragma once
#include <exception>

// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡�

/**
 * ��ǰ�������һ�����ֻ�ø��ڵ㣬������������ҵ����ڵ�λ�ã���ȷ����������
 * �Ľڵ��������ٸ�����ǰ������������������ڵ�ֵ�Ļ��� �ݹ� ���ú������ֱ�
 * ������������������
 */
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* binaryTreeConstruct(int* preOrder, int* inOrder, int length)
{
	if (preOrder == nullptr || inOrder == nullptr || length <= 0)
		return nullptr;

	return constructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

// ʹ�ò�ͬ���������ĵݹ麯��
BinaryTreeNode* constructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
	// ��ø��ڵ�
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	// �Ƿ�ֻ��һ���ڵ�
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw std::exception("Invalid Input.");
	}

	// �ҳ����ڵ����������е�λ��
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;	// �������Ч������rootInOrderҪ����endInOrder��������ѭ������if���϶�����ִ�а���
	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
		throw std::exception("Invalid Input.");

	// ��������������������
	int leftLength = rootInOrder - startInOrder;
	// ��������ǰ�����еĽ�β
	int* leftPreOrderEnd = startPreOrder + leftLength;

	// �����������������ĳ��ȴ���0ʱҪ���еݹ����,ֱ������һ���ڵ�
	// ����������
	if (leftLength > 0)
		root->m_pLeft = constructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	// ����������
	if (endPreOrder - startPreOrder > leftLength)
		root->m_pRight = constructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);

	return root;
}