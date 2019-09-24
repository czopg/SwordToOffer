#pragma once

#include <queue>
#include <stack>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 题目一：不分行从上往下打印二叉树

/* 结合队列的使用 */
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


// 题目二：分行从上往下打印二叉树

/* 增加2个变量：当前行还未打印的节点数；下一行要打印的节点数 */
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
		if (toBePrint == 0)	// 到达行末
		{
			printf("\n");
			toBePrint = nextLevel;
			nextLevel = 0;
		}
	}
}

// 题目二：之字形从上往下打印二叉树

/* 自己的想法：题目二程序改变为用双向队列，判断行数奇偶，（要先考虑每行
先保存左子节点还是右子节点）奇数行后入前出，偶数行前入后出 ==> 似乎还是麻烦*/

/* 因为变成后入先出，采用两个栈，打印偶数行时先保存左子节点再保存右子节点到另一个栈，打印奇数行时相反 */
void printFromTopToButtom3(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*> stackNodes[2];
	stackNodes[0].push(pRoot);
	int current = 0;	// 奇偶栈转换
	int next = 1;

	while (!stackNodes[0].empty() || !stackNodes[1].empty())
	{
		BinaryTreeNode* pNode = stackNodes[current].top();
		stackNodes[current].pop();
		printf("%d", pNode->m_nValue);

		if (current == 0)	// 打印偶数行时先保存左子节点再保存右子节点
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
		
		if (stackNodes[current].empty())	// 打印完一行
		{
			printf("\n");
			current = 1 - current;	// 奇偶栈转换
			next = 1 - next;
		}
	}
}
