#pragma once
#include <string>

/* �ܽ᣺dm46-48�����ö�̬�滮 ����ѭ����� �����ظ�������������õݹ� */

/**
 * ��̬�滮 f(i)	
 * 1) ��i���ַ�ǰ��û�г��ֹ� f(i)=f(i-1)+1
 * 2) ���ֹ���a) ���ظ��ַ����� d<=f(i-1) -> ������󳤶ȣ�f(i)=d
 *			  b) d>f(i-1) -> f(i)=f(i-1)+1
 * ʹ�������ݴ���ֵ��ַ����±�ֵ
 * ���������д�ķ������
 */

int longestSubstringWithoutDuplication(const std::string& str)
{
	int curLength = 0;
	int maxLength = 0;
	int* position = new int[26];	// �ݴ���ֵ��ַ����±�ֵ
	for (int i = 0; i < 26; ++i)
		position[i] = -1;	// Ϊ������ʾû���ֹ�

	for (int i = 0; i < str.length(); ++i)
	{
		int prevIndex = position[str[i] - 'a'];
		if (prevIndex < 0 || i - prevIndex > curLength)
			++curLength;
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;

			curLength = i - prevIndex;
		}

		position[str[i] - 'a'] = i;
	}

	if (curLength > maxLength)
		maxLength = curLength;
	delete[] position;

	return maxLength;
}