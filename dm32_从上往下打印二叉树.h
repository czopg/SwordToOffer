#pragma once

#include <queue>
#include <stack>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// ��Ŀһ�������д������´�ӡ������

/* ��϶��е�ʹ�� */
void printFromTopToButtom(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);

	while (!nodes.empty())
	{
		BinaryTreeNode* pNode = nodes.front();
		nodes.pop();
		printf("%d", pNode->m_nValue);
		if (pNode->m_pLeft != nullptr)
			nodes.push(pNode->m_pLeft);
		if (pNode->m_pRight != nullptr)
			nodes.push(pNode->m_pRight);
	}
}


// ��Ŀ�������д������´�ӡ������

/* ����2����������ǰ�л�δ��ӡ�Ľڵ�������һ��Ҫ��ӡ�Ľڵ��� */
void printFromTopToButtom2(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);

	int toBePrint = 1;
	int nextLevel = 0;

	while (!nodes.empty())
	{
		BinaryTreeNode* pNode = nodes.front();
		
		printf("%d", pNode->m_nValue);
		if (pNode->m_pLeft != nullptr)
		{
			nodes.push(pNode->m_pLeft);
			++nextLevel;
		}
		if (pNode->m_pRight != nullptr)
		{
			nodes.push(pNode->m_pRight);
			++nextLevel;
		}

		nodes.pop();
		--toBePrint;
		if (toBePrint == 0)	// ������ĩ
		{
			printf("\n");
			toBePrint = nextLevel;
			nextLevel = 0;
		}
	}
}

// ��Ŀ����֮���δ������´�ӡ������

/* �Լ����뷨����Ŀ������ı�Ϊ��˫����У��ж�������ż����Ҫ�ȿ���ÿ��
�ȱ������ӽڵ㻹�����ӽڵ㣩�����к���ǰ����ż����ǰ���� ==> �ƺ������鷳*/

/* ��Ϊ��ɺ����ȳ�����������ջ����ӡż����ʱ�ȱ������ӽڵ��ٱ������ӽڵ㵽��һ��ջ����ӡ������ʱ�෴ */
void printFromTopToButtom3(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*> stackNodes[2];
	stackNodes[0].push(pRoot);
	int current = 0;	// ��żջת��
	int next = 1;

	while (!stackNodes[0].empty() || !stackNodes[1].empty())
	{
		BinaryTreeNode* pNode = stackNodes[current].top();
		stackNodes[current].pop();
		printf("%d", pNode->m_nValue);

		if (current == 0)	// ��ӡż����ʱ�ȱ������ӽڵ��ٱ������ӽڵ�
		{
			if (pNode->m_pLeft != nullptr)
				stackNodes[next].push(pNode->m_pLeft);
			if (pNode->m_pRight != nullptr)
				stackNodes[next].push(pNode->m_pRight);
		}
		else
		{
			if (pNode->m_pRight != nullptr)
				stackNodes[next].push(pNode->m_pRight);
			if (pNode->m_pLeft != nullptr)
				stackNodes[next].push(pNode->m_pLeft);
		}
		
		if (stackNodes[current].empty())	// ��ӡ��һ��
		{
			printf("\n");
			current = 1 - current;	// ��żջת��
			next = 1 - next;
		}
	}
}
