#pragma once
#include <string>
using namespace std;

/**
 * �ݹ���� �����ظ��������� -> ���ö�̬�滮 ��β����ʼ��������ѭ�����
 * f(i)=f(i+1)+g(i,i+1)*f(i+2) ����ɵ���λ����10-25֮��ʱg(i,i+1)��Ϊ1������Ϊ0
 */

// �����ܷ��뷽����Ŀ
int numberTranslationCount(int num)
{
	if (num < 0)
		return -1;

	string numInStr = to_string(num);	// ����ת�ַ���
	return numberTranslationCount(numInStr);
}

int numberTranslationCount(const string& str)
{
	int length = str.length();
	int* counts = new int[length];	// f(i)
	int count = 0;

	for (int i = length - 1; i >= 0; --i)
	{
		count = 0;
		if (i < length - 1)
			count = counts[i + 1];
		else
			count = 1;

		if (i < length - 1)
		{
			int digit1 = str[i] - '0';
			int digit2 = str[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
					count += counts[i + 2];
				else
					count += 1;
			}
		}
		counts[i] = count;
	}

	count = counts[0];
	delete[] counts;
	return count;
}