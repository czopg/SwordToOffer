#pragma once
// ��Ŀһ����Ϊs����������
// ����һ����������������һ������s���������в�����������ʹ������
// �ĺ�������s������ж�����ֵĺ͵���s���������һ�Լ��ɡ�
/**
 * ʹ������ָ�룬ָ���һ���������֣����С��s���һ��ָ����ƣ�
 * ��ʹ���s�����һ��ָ��ǰ�ơ�
 */
bool findNumsWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (data == nullptr || length < 1 || num1 == nullptr || num2 == nullptr)
		return found;

	int ahead = 0;
	int behind = length - 1;
	while (ahead < behind)
	{
		long long numSum = data[ahead] + data[behind];
		if (numSum = sum)
		{
			*num1 = data[ahead];
			*num2 = data[behind];
			found = true;
			break;
		}
		else if (numSum > sum)
			--behind;
		else
			++ahead;
	}

	return found;
}


// ��Ŀ������Ϊs��������������
// ����һ������s����ӡ�����к�Ϊs�������������У����ٺ�������������
// ��������15������1+2+3+4+5=4+5+6=7+8=15�����Խ����ӡ��3����������1��5��
// 4��6��7��8��
/**
 * ʹ������ָ�룬small=1,big=2 ��������չ��smallһֱ���ӵ�(s+1)/2
 */
void findContinuousSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (sum + 1) >> 2;
	int numSum = small + big;
	while (small < middle)
	{
		if (numSum == sum)
			printSequence(small, big);
		else if (numSum > sum)
		{
			numSum -= small;
			++small;
		}
		else
		{
			++big;
			numSum += big;	// Ҫ����ָ����
		}
	}
}

void printSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d ", i);
	printf("\n");
}