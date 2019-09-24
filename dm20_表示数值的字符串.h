/**
 * 注意||和&&前后调用函数的放置 需要符合 短路规则 以及减少计算量
 */
#pragma once

// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

/**
 * A.B e|E C
 * A C是可带正负号的整数 B为整数
 * 子函数参数用二次指针
 */

bool isNumeric(const char* str)
{
	if (str == nullptr)
		return false;

	bool numeric = scanInteger(&str);	// 先扫A	str有后移
	if (*str == '.')
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;// 由于短路规则 必须先扫B 否则str没有后移
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && scanInteger(&str);// numeric放前面可减少可能的计算
	}

	return numeric && *str == '\0';
}

// 扫描A C
bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
		++(*str);

	return scanUnsignedInteger(str);
}

// 扫描B
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	return *str > before;	// 若不相等说明有扫到数值
}
