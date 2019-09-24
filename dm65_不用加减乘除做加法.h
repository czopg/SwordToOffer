#pragma once
/* 位运算 三步走策略：1 不考虑进位各位相加 异或 2 进位 相与后左移
   3 结果相加 重复1、2步 */
int add_(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = num1 ^ num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}