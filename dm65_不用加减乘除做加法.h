#pragma once
/* λ���� �����߲��ԣ�1 �����ǽ�λ��λ��� ��� 2 ��λ ���������
   3 ������ �ظ�1��2�� */
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