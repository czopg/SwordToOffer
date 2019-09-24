#pragma once

// ��Ŀ����ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'
// ��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���

/** 
 * ���õݹ�ʵ�� 
 * ����*�Ƿ��ڵڶ�λ��2��������ڵڶ�λʱ�ַ�3�������ƥ��0�� 1�� ���
 */

bool match(char* str, char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);
}

// �ݹ���Ĵ���
bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')	// �ݹ��������
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			// ��3�������ƥ��1�� ��� 0��  ���ڶ�·���� ��ǡ����˳�����пɼ��ټ���
			return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
		}
		else
			return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}