#pragma once

#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString() {};
	~CMyString() {};

	CMyString& operator=(const CMyString& obj)	// �������ã���ʽ���
	{
		// 1 ������ڴ�
		if (m_pData != nullptr)
			delete[] m_pData;
		// 2 �������ڴ�
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
