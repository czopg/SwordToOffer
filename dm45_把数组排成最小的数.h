#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * �������� ������ת��Ϊ�ַ������бȽ�
 * �����µıȽϹ��򣨺������� ��ö���֤����������
 */
// https://blog.csdn.net/wuzhekai1985/article/details/6704902

// �����µıȽϹ��򣨺�������
struct Compare
{
	bool operator()(const string& str1, const string& str2)
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		
		return s1 < s2;	// �������У���Ҫ��С����
	}
};

void leastNumOfArray(int* numbers, int length)
{
	string* ptrString = new string[length];
	// ����ת�ַ��� ʹ��stringstream���ص��ס�÷���
	for (int i = 0; i < length; ++i)
	{
		stringstream stream;
		stream << numbers[i];
		stream >> ptrString[i];	// ͨ��stringstream������뼴���ת��
	}

	sort(ptrString, ptrString + length, Compare());	// ���ַ�����������

	for (int i = 0; i < length; ++i)
		cout << ptrString[i];
	cout << endl;

	delete[] ptrString;
}