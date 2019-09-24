#pragma once

#include <vector>
#include <list>
using namespace std;

struct TreeNode
{
	int m_nValue;
	vector<TreeNode*> m_vChildren;
};

/* 普通树 通过利用辅助内存 用两个链表来存储根节点到给定节点的路径 
   转换成求两个链表的最后公共祖先 */

// 递归 遍历树获得对应节点的路径存入链表
bool getNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path)
{
	if (pRoot == pNode)
		return true;

	path.push_back(pRoot);
	bool found = false;
	vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();	// 用到迭代器 横向查找树的子节点

	while (!found && iter < pRoot->m_vChildren.end())
	{
		found = getNodePath(*iter, pNode, path); // 递归 进入子树下一层
		++iter;
	}

	if (!found)
		path.pop_back();	// 在最深层时没有找到则往回弹出链表

	return found;
}

// 由只读迭代器遍历找到两个链表的最后公共节点
TreeNode* getLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
{
	list<TreeNode*>::const_iterator iter1 = path1.begin();
	list<TreeNode*>::const_iterator iter2 = path2.begin();

	TreeNode* pLast = nullptr;
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
			pLast = *iter1;	// 开始相等的值会被后面相等的覆盖
		++iter1;
		++iter2;
	}

	return pLast;
}

TreeNode* getLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2)
{
	if (pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
		return nullptr;

	list<TreeNode*> path1;
	list<TreeNode*> path2;
	getNodePath(pRoot, pNode1, path1);
	getNodePath(pRoot, pNode2, path2);
	
	return getLastCommonNode(path1, path2);
}