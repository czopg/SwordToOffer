#pragma once

// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。

/** 
 * 采用递归实现 
 * 根据*是否在第二位分2种情况，在第二位时又分3种情况：匹配0个 1个 多个
 */

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);
}

// 递归核心代码
bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')	// 递归结束条件
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			// 分3种情况：匹配1个 多个 0个  由于短路规则 按恰当的顺序排列可减少计算
			return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
		}
		else
			return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}