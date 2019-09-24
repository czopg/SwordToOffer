#pragma once
#include <cmath>

// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣�

/* ��̬�滮 ���ϵ��·��������µ������ */
int maxProductAfterCutting_soultion1(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* products = new int[length + 1];	// ���������洢����������Ž�
	// ����Ϊ�˳��Ȳ��ټ�����ʱ��ֵ
	products[0] = 0;	// ��Ϊռλ������
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	// ͨ��forѭ�����µ������
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
				max = product;
		}
		products[i] = max;	// ����ѭ��
	}

	max = products[length];
	delete[] products;	// 
	return max;
}



/* ̰���㷨 Ҫ��֤������Ҫ��ʵ����ѧ������ */
// n>=5ʱ�Ⱦ����ܶ໮�ֳ�3���ٻ���Ϊ2
// ֤����2(n-2)>=n  3(n-3)>=n
int maxProductAfterCutting_soultion2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOf3 = length / 3;
	// ����������4ʱ�����ֳ�2����
	if (length - timesOf3 * 3 == 1)
		--timesOf3;
	int timesOf2 = (length - timesOf3 * 3) / 2;
	return (int)pow(3, timesOf3) * (int)pow(2, timesOf2);
}