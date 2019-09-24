#pragma once
/**
 * 问题分成2部分：1 第1个字符和后面所有字符的排列
 * 2 由第一个字符和后面的每个字符交换完成所有可能情况
 * 递归处理
 */
void permutation(char* pStr)
{
	if (pStr == nullptr)
		return;
	permutation(pStr, pStr);
}

void permutation(char* pStr, char* pBegin)	// pBegin当前排列的第一个字符
{
	if (*pBegin == '\0')	// 递归结束条件
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			// 第一个字符和后面字符交换（包括自己）
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			permutation(pStr, pBegin + 1);	// 递归处理

			// 还原
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}