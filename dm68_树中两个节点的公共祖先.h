#pragma once

#include <vector>
#include <list>
using namespace std;

struct TreeNode
{
	int m_nValue;
	vector<TreeNode*> m_vChildren;
};

/* ��ͨ�� ͨ�����ø����ڴ� �������������洢���ڵ㵽�����ڵ��·�� 
   ת�����������������󹫹����� */

// �ݹ� ��������ö�Ӧ�ڵ��·����������
bool getNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path)
{
	if (pRoot == pNode)
		return true;

	path.push_back(pRoot);
	bool found = false;
	vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();	// �õ������� ������������ӽڵ�

	while (!found && iter < pRoot->m_vChildren.end())
	{
		found = getNodePath(*iter, pNode, path); // �ݹ� ����������һ��
		++iter;
	}

	if (!found)
		path.pop_back();	// �������ʱû���ҵ������ص�������

	return found;
}

// ��ֻ�������������ҵ������������󹫹��ڵ�
TreeNode* getLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2)
{
	list<TreeNode*>::const_iterator iter1 = path1.begin();
	list<TreeNode*>::const_iterator iter2 = path2.begin();

	TreeNode* pLast = nullptr;
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
			pLast = *iter1;	// ��ʼ��ȵ�ֵ�ᱻ������ȵĸ���
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