#pragma once

/* 负数右移时会用符号位1来填补 */
// 方法1 改用左移
int numberOf1_1(int n)
{
	int count = 0;
	unsigned int flag = 1;	// 需是无符号整数
	while (flag)	// 左移32次
	{
		if (n & flag)
			++count;
		flag = flag << 1;
	}
	return count;
}


// 方法2 整数与整数-1后相与&，可把最右边的1变为0
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


