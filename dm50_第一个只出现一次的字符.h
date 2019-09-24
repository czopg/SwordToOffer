#pragma once
#include <limits>

// 题目一 字符串第一个只出现一次的字符
/**
 * 空间换时间	使用哈希表 可用STL的map和unorder_map，这里用数组模拟
 * char型 256个ASCII值作为哈希表key值，出现次数为value值
 * 第一次扫描把每个字符出现次数记录在哈希表，第二次扫描返回次数为1的字符
 */

char charFirstToShowOnce(char* pString)
{
	if (pString == nullptr)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize] = { 0 };

	char* pHashKey = pString;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)]++;	// 插入哈希值：hashTable[*pHashKey]++; pHashKey++;
	
	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		++pHashKey;
	}

	return '\0';
}


// 题目二 字符流第一个只出现一次的字符
/**
 * 使用数组实现哈希表，key值为字符对应ASCII值，value值为字符在字符流中的位置
 * value初始为-1，再次出现则赋值-2，最后遍历数组找到最小的大于等于0的value值对应的字符
 */

class CharStaistics
{
public:
	CharStaistics() : index(0)
	{
		for (int i = 0; i < 256; ++i)
			position[i] = -1;
	}

	// 向哈希表插入值
	void insertValue(char ch)
	{
		if (position[ch] == -1)
			position[ch] = index;
		else if (position[ch] >= 0)
			position[ch] = -2;

		++index;
	}

	// 获得最小的大于等于0的value值对应的字符
	char charAppearOnce()
	{
		char ch = '\0';	// 全为负数时需返回空
		int minIndex = std::numeric_limits<int>::max();
		for (int i = 0; i < 256; ++i)
		{
			if (position[i] >= 0 && position[i] < minIndex)
			{
				ch = (char)i;
				minIndex = position[i];
			}
		}

		return ch;
	}

private:
	int position[256];
	int index;	// 当前位置
};