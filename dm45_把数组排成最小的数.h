#pragma once
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * 大数问题 把数字转换为字符串进行比较
 * 定义新的比较规则（函数对象） 最好懂得证明规则适用
 */
// https://blog.csdn.net/wuzhekai1985/article/details/6704902

// 定义新的比较规则（函数对象）
struct Compare
{
	bool operator()(const string& str1, const string& str2)
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		
		return s1 < s2;	// 升序排列，需要从小到大
	}
};

void leastNumOfArray(int* numbers, int length)
{
	string* ptrString = new string[length];
	// 数字转字符串 使用stringstream（重点记住用法）
	for (int i = 0; i < length; ++i)
	{
		stringstream stream;
		stream << numbers[i];
		stream >> ptrString[i];	// 通过stringstream输出输入即完成转换
	}

	sort(ptrString, ptrString + length, Compare());	// 对字符串数组排序

	for (int i = 0; i < length; ++i)
		cout << ptrString[i];
	cout << endl;

	delete[] ptrString;
}