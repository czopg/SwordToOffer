#pragma once
// 题目一：翻转单词顺序
// 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。
/**
 * 两次翻转字符串：整个句子翻转 每个单词翻转
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

	reverseStr(pBegin, pEnd);	// 翻转句子

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


// 题目二：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。
/**
 * 三次翻转字符串：字符串分成两部分，分别翻转；然后整个字符串翻转
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
