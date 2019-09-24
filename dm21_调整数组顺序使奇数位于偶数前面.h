#pragma once

// ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
// ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

/** 
 * ���� ��������ָ�� ����ָ������ͷβ
 * ǰΪż��Ϊ���򽻻�
 * ���� ����ָ�� ָ������׼���ṩ��չ��
 */

void reOrder(int* pData, int length, bool (*func)(int))
{
	if (pData == nullptr || length <= 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			++pBegin;
		while (pBegin < pEnd && func(*pEnd))
			--pEnd;

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void reOrderOddEven(int* pData, int length)
{
	reOrder(pData, length, isEven);
}