#pragma once
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 题目一：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
/**
 * 后序遍历算法
 */
int treeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int left = treeDepth(pRoot->m_pLeft);
	int right = treeDepth(pRoot->m_pRight);
	return (left > right) ? (left + 1) : (right + 1);
}


// 题目二：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
/**
 * 后序遍历算法	遍历每个节点时记录其深度，即可以判断其是否平衡
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