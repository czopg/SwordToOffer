#pragma once

// 用递归的方法重复性太高，效率太低
// 采用循环的方法，把中间项保存起来		O(n)

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

// 用例：青蛙跳台阶问题		小矩形覆盖大矩形问题