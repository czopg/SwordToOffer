#pragma once

#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString() {};
	~CMyString() {};

	CMyString& operator=(const CMyString& obj)	// 返回引用，链式编程
	{
		// 1 清除旧内存
		if (m_pData != nullptr)
			delete[] m_pData;
		// 2 分配新内存
		if (obj.m_pData == nullptr)
			m_pData = nullptr;
		else
		{
			int len = strlen(obj.m_pData) + 1;
			m_pData = new char[len];
			strcpy(m_pData, obj.m_pData);
		}
		return *this;
	}

private:
	char* m_pData;

};
