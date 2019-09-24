#pragma once
// ��Ŀһ��������ֻ����һ�ε���������
// һ�����������������������֮�⣬���������ֶ����������Ρ���д����
// �ҳ�������ֻ����һ�ε����֡�
/**
 * ͨ��λ���� ��� ����������� һ�� ֻ����һ�ε����� -> ����ɿ���ԭ�������
 * �����׼����ԭ������������ұߵ�һ��1Ϊ��׼����λΪ1��һ�飬Ϊ0��һ��
 */
void findNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
		return;

	int result_or = 0;
	for (int i = 0; i < length; ++i)
		result_or ^= data[i];	// ���

	int indexOf1 = findIndexOf1(result_or);

	*num1 = *num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (isBit1(data[j], indexOf1))
			*num1 ^= data[j];
		else
			*num2 ^= data[j];
	}
}

// �ҵ���������ұߵ�һ��1
int findIndexOf1(int num)
{
	int indexBit = 0;
	while ((num & 1 == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

// �жϴ�λ�Ƿ���1
bool isBit1(int num, int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}


// ��Ŀ������һ�������г���һ������ֻ����һ��֮�⣬�������ֶ����������Ρ���
// �ҳ��Ǹ�ֻ����һ�ε����֡�
/**
 * ����λ����˼· ���������ֵ�ÿһλ�ֱ������������ܱ�3����
 * ��ֻ����һ�ε����ָ�λΪ0������Ϊ1��
 */
int findNumAppearOnce(int data[], int length)
{
	if (data == nullptr || length <= 0)
		return -1;

	int bitSum[32] = { 0 };
	for (int i = 0; i < length; ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = data[i] & bitMask;
			if (bit != 0)
				bitSum[j] += bit;
			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;
}