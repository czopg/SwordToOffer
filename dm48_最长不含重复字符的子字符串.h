#pragma once
#include <string>

/* 总结：dm46-48都采用动态规划 基于循环求解 因有重复子问题而不采用递归 */

/**
 * 动态规划 f(i)	
 * 1) 第i个字符前面没有出现过 f(i)=f(i-1)+1
 * 2) 出现过：a) 此重复字符距离 d<=f(i-1) -> 保存最大长度，f(i)=d
 *			  b) d>f(i-1) -> f(i)=f(i-1)+1
 * 使用数组暂存出现的字符的下标值
 * 结合书上自写的分析理解
 */

int longestSubstringWithoutDuplication(const std::string& str)
{
	int curLength = 0;
	int maxLength = 0;
	int* position = new int[26];	// 暂存出现的字符的下标值
	for (int i = 0; i < 26; ++i)
		position[i] = -1;	// 为负数表示没出现过

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