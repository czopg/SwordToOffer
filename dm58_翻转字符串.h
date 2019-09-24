#pragma once
// ��Ŀһ����ת����˳��
// ����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ������
/**
 * ���η�ת�ַ������������ӷ�ת ÿ�����ʷ�ת
 */
void reverseStr(char* pBegin, char* pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		++pBegin;
		--pEnd;
	}
}

char* reverseSentence(char* pData)
{
	if (pData == nullptr)
		return;

	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd != '\0')
		++pEnd;
	--pEnd;

	reverseStr(pBegin, pEnd);	// ��ת����

	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			++pBegin;
			++pEnd;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			reverseStr(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			++pEnd;
	}

	return pData;
}


// ��Ŀ��������ת�ַ���
// ��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
/**
 * ���η�ת�ַ������ַ����ֳ������֣��ֱ�ת��Ȼ�������ַ�����ת
 */
char* leftRotateString(char* pStr, int n)
{
	if (pStr != nullptr)
	{
		int len = static_cast<int>(strlen(pStr));	//
		if (len > 0 && n > 0 && n < len)
		{
			char* pFirstBegin = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondBegin = pStr + n;
			char* pSecondEnd = pStr + len - 1;

			reverseStr(pFirstBegin, pFirstEnd);
			reverseStr(pSecondBegin, pSecondEnd);
			reverseStr(pFirstBegin, pSecondEnd);
		}
	}

	return pStr;
}
