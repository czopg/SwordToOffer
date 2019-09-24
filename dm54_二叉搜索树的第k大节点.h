#pragma once
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * ÖÐÐò±éÀúËã·¨
 */
BinaryTreeNode* kthNode(BinaryTreeNode* pRoot, int k)
{
	if (pRoot == nullptr || k <= 0)
		return nullptr;

	return kthNodeCore(pRoot, k);
}

BinaryTreeNode* kthNodeCore(BinaryTreeNode* pRoot, int& k)
{
	BinaryTreeNode* target = nullptr;
	if (pRoot->m_pLeft != nullptr)
		target = kthNodeCore(pRoot->m_pLeft, k);

	if (target == nullptr)
	{
		if (k == 1)
			target = pRoot;
		--k;
	}

	if (target == nullptr && pRoot->m_pRight != nullptr)
		target = kthNodeCore(pRoot->m_pRight, k);

	return target;
}