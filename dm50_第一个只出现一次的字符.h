#pragma once
#include <limits>

// ��Ŀһ �ַ�����һ��ֻ����һ�ε��ַ�
/**
 * �ռ任ʱ��	ʹ�ù�ϣ�� ����STL��map��unorder_map������������ģ��
 * char�� 256��ASCIIֵ��Ϊ��ϣ��keyֵ�����ִ���Ϊvalueֵ
 * ��һ��ɨ���ÿ���ַ����ִ�����¼�ڹ�ϣ���ڶ���ɨ�践�ش���Ϊ1���ַ�
 */

char charFirstToShowOnce(char* pString)
{
	if (pString == nullptr)
		return '\0';
	const int tableSize = 256;
	unsigned int hashTable[tableSize] = { 0 };

	char* pHashKey = pString;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)]++;	// �����ϣֵ��hashTable[*pHashKey]++; pHashKey++;
	
	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		++pHashKey;
	}

	return '\0';
}


// ��Ŀ�� �ַ�����һ��ֻ����һ�ε��ַ�
/**
 * ʹ������ʵ�ֹ�ϣ��keyֵΪ�ַ���ӦASCIIֵ��valueֵΪ�ַ����ַ����е�λ��
 * value��ʼΪ-1���ٴγ�����ֵ-2�������������ҵ���С�Ĵ��ڵ���0��valueֵ��Ӧ���ַ�
 */

class CharStaistics
{
public:
	CharStaistics() : index(0)
	{
		for (int i = 0; i < 256; ++i)
			position[i] = -1;
	}

	// ���ϣ�����ֵ
	void insertValue(char ch)
	{
		if (position[ch] == -1)
			position[ch] = index;
		else if (position[ch] >= 0)
			position[ch] = -2;

		++index;
	}

	// �����С�Ĵ��ڵ���0��valueֵ��Ӧ���ַ�
	char charAppearOnce()
	{
		char ch = '\0';	// ȫΪ����ʱ�践�ؿ�
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
	int index;	// ��ǰλ��
};