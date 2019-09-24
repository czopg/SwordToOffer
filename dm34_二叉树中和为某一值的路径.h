#pragma once
// ��Ŀ������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ������������
// ��·���������ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
#include <vector>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/**
 * ǰ������㷨�任
 * ��Ҫ��ջ������·���ϵ�ֵ����ʼ��ջ������ջ
 * �ݹ����
 */
void pathInBT(BinaryTreeNode* pRoot, int sum)
{
	if (pRoot == nullptr)
		return;

	// �ݹ���Ҫ����Ĳ���
	std::vector<int> path;	// vectorģ��ջ,��ӡ���ݷ���
	int countSum = 0;
	pathInBTCore(pRoot, sum, path, countSum);
}

void pathInBTCore(BinaryTreeNode* pRoot, int sum, std::vector<int>& path, int countSum)	// ����
{
	countSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	// Ҷ�ӽڵ���·����һ��
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