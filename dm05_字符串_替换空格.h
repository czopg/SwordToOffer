#pragma once
/**
 * 在从前往后替换需要移动相同字符多次的情况下，考虑从后往前移动字符
 * 可以减少移动次数，提高时间效率。
 * 内存覆盖的问题。
 *
 * 计算空格数目得到替换后字符串长度，两个辅助指针分别指向替换前后的
 * 字符串末尾，从后往前复制。时间复杂度 O(n)。
 */
// 输入字符串数组及其容量
void replaceBlank(char m_string[], int capacity)
{
	if (m_string == nullptr || capacity <= 0)
		return;

	// 计算字符串长度和空格个数
	int lengthOfString = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (m_string[i] != '\0')
	{
		++lengthOfString;
		if (m_string[i] == ' ')
			++numberOfBlank;
		++i;
	}

	// 替换后字符串新长度
	int newLength = lengthOfString + numberOfBlank * 2;
	if (newLength > capacity)
		return;

	// 通过两个辅助指针从后往前替换字符串
	int oldIndex = lengthOfString;
	int newIndex = newLength;
	while (oldIndex >= 0 && newIndex > oldIndex)
	{
		if (m_string[oldIndex] == ' ')
		{
			m_string[newIndex--] = '0';
			m_string[newIndex--] = '2';
			m_string[newIndex--] = '%';
		}
		else
			m_string[newIndex--] = m_string[oldIndex];
		--oldIndex;
	}
}