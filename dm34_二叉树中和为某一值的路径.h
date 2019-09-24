#pragma once
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
#include <vector>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * 前序遍历算法变换
 * 需要用栈来保存路径上的值，开始入栈和最后出栈
 * 递归求解
 */
void pathInBT(BinaryTreeNode* pRoot, int sum)
{
	if (pRoot == nullptr)
		return;

	// 递归需要另外的参数
	std::vector<int> path;	// vector模拟栈,打印数据方便
	int countSum = 0;
	pathInBTCore(pRoot, sum, path, countSum);
}

void pathInBTCore(BinaryTreeNode* pRoot, int sum, std::vector<int>& path, int countSum)	// 引用
{
	countSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	// 叶子节点且路径和一样
	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
	if (isLeaf && countSum == sum)
	{
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
			printf("%d\t", *iter);

		printf("\n");
	}

	if(pRoot->m_pLeft!=nullptr)
		pathInBTCore(pRoot->m_pLeft, sum, path, countSum);
	if (pRoot->m_pRight != nullptr)
		pathInBTCore(pRoot->m_pRight, sum, path, countSum);

	path.pop_back();
}