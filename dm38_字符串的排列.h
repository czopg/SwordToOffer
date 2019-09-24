#pragma once
/**
 * ����ֳ�2���֣�1 ��1���ַ��ͺ��������ַ�������
 * 2 �ɵ�һ���ַ��ͺ����ÿ���ַ�����������п������
 * �ݹ鴦��
 */
void permutation(char* pStr)
{
	if (pStr == nullptr)
		return;
	permutation(pStr, pStr);
}

void permutation(char* pStr, char* pBegin)	// pBegin��ǰ���еĵ�һ���ַ�
{
	if (*pBegin == '\0')	// �ݹ��������
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			// ��һ���ַ��ͺ����ַ������������Լ���
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			permutation(pStr, pBegin + 1);	// �ݹ鴦��

			// ��ԭ
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}