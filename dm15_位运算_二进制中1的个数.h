#pragma once

/* ��������ʱ���÷���λ1��� */
// ����1 ��������
int numberOf1_1(int n)
{
	int count = 0;
	unsigned int flag = 1;	// �����޷�������
	while (flag)	// ����32��
	{
		if (n & flag)
			++count;
		flag = flag << 1;
	}
	return count;
}


// ����2 ����������-1������&���ɰ����ұߵ�1��Ϊ0
int numberOf1_2(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = n & (n - 1);
	}
	return count;
}


