#pragma once

// �õݹ�ķ����ظ���̫�ߣ�Ч��̫��
// ����ѭ���ķ��������м��������		O(n)

long long Fibonacci(unsigned int n)
{
	int initial[2] = { 0,1 };
	if (n < 2)
		return initial[n];

	long long fibNumOne = 1;
	long long fibNumTwo = 0;
	long long fibResult = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibResult = fibNumOne + fibNumTwo;

		fibNumTwo = fibNumOne;
		fibNumOne = fibResult;
	}

	return fibResult;
}

// ������������̨������		С���θ��Ǵ��������