#pragma once
#include <exception>

// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。

/**
 * 由前序遍历第一个数字获得根节点，在中序遍历中找到根节点位置，可确定左右子树
 * 的节点数量；再根据在前序和中序中左右子树节点值的划分 递归 调用函数来分别构
 * 建左子树和右子树。
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

// 使用不同函数参数的递归函数
BinaryTreeNode* constructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
	// 获得根节点
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	// 是否只有一个节点
	if (startPreOrder == endPreOrder)
	{
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw std::exception("Invalid Input.");
	}

	// 找出根节点在中序结果中的位置
	int* rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
		++rootInOrder;	// 如果是无效输入则rootInOrder要大于endInOrder才能跳出循环，那if语句肯定不会执行啊？
	if (rootInOrder == endInOrder && *rootInOrder != rootValue)
		throw std::exception("Invalid Input.");

	// 中序结果中算左子树长度
	int leftLength = rootInOrder - startInOrder;
	// 左子树在前序结果中的结尾
	int* leftPreOrderEnd = startPreOrder + leftLength;

	// 当左子树和右子树的长度大于0时要进行递归求解,直到返回一个节点
	// 构建左子树
	if (leftLength > 0)
		root->m_pLeft = constructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	// 构建右子树
	if (endPreOrder - startPreOrder > leftLength)
		root->m_pRight = constructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);

	return root;
}