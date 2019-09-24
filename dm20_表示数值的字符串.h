/**
 * ע��||��&&ǰ����ú����ķ��� ��Ҫ���� ��·���� �Լ����ټ�����
 */
#pragma once

// ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������

/**
 * A.B e|E C
 * A C�ǿɴ������ŵ����� BΪ����
 * �Ӻ��������ö���ָ��
 */

bool isNumeric(const char* str)
{
	if (str == nullptr)
		return false;

	bool numeric = scanInteger(&str);	// ��ɨA	str�к���
	if (*str == '.')
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;// ���ڶ�·���� ������ɨB ����strû�к���
	}
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && scanInteger(&str);// numeric��ǰ��ɼ��ٿ��ܵļ���
	}

	return numeric && *str == '\0';
}

// ɨ��A C
bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
		++(*str);

	return scanUnsignedInteger(str);
}

// ɨ��B
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	return *str > before;	// �������˵����ɨ����ֵ
}
