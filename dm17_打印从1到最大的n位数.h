#pragma once
#include <string>

/* ����1 ���ַ�������ʾ���� �ַ���ģ�����ּӷ� */
void print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!increase(number))
	{
		printNum(number);
	}
	delete[] number;
}

// ʵ���ַ�����Ӧ�����ּ�1�����ж��Ƿ����
bool increase(char* number)
{
	bool nOverFlow = false;
	int nTakeOver = 0;	// ��λ
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; --i)	// �Ӹ�λ�����λ
	{
		int nSum = number[i] - '0' + nTakeOver;	// ÿ����λ��ֵ
		if (i == nLength - 1)
			++nSum;
		if (nSum >= 10)
		{
			if (i == 0)
				nOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;	// �޽�λ��ֱ���˳�ѭ��
		}
	}
	return nOverFlow;
}

// �ӵ�һ����0��λ��ʼ��ӡ1������
void printNum(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}


/* ����2 nλʮ������������n����0��9��ȫ���� ȫ���в��� �ݹ� �ķ��� */
void print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	//memset(number, '0', n);
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)	// ����0-9
	{
		number[0] = '0' + i;		// �����λ����λ
		printDecursively(number, n, 0);
	}
	delete[] number;
}

// �ݹ����
void printDecursively(char* number, int length, int index)
{
	if (index == length - 1)	// �ݹ��������
	{
		printNum(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index+1]= '0' + i;
		printDecursively(number, length, index + 1);
	}
}