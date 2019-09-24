#pragma once
#include <cmath>

// ��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s
// �����п��ܵ�ֵ���ֵĸ��ʡ�
/**
 * �ⷨһ�����ڵݹ�ʵ�� �͵�ֵ��ΧΪ[n,6n]�����������п��ܵ�����Ϊ6^n
 * �����ӷֳ����ѣ���һ�ѣ�����ֵ1-6����n-1�ѣ�Ȼ��ݹ鴦��
 * ��һ��6n-n+1����������ÿ���ͳ��ֵĴ�������s�����s-n��λ�ã�����n����λ��0��
 */
int maxValue = 6;
void printProbability(int num)
{
	if (num < 1)
		return;

	int maxSum = maxValue * num;
	int* pProbabilities = new int[maxSum - num + 1];
	for (int i = num; i <= maxSum; ++i)
		pProbabilities[i - num] = 0;

	probability(num, pProbabilities);

	double total = (double)std::pow(num, maxValue);
	for (int i = num; i <= maxSum; ++i)
	{
		double ratio = (double)pProbabilities[i - num] / total;
		printf("%d: %f\n", i, ratio);
	}

	delete[] pProbabilities;
}

void probability(int num, int* pProbabilities)
{
	for (int i = 1; i <= maxValue; ++i)
		probability(num, num, i, pProbabilities);
}

void probability(int src, int cur, int sum, int* pProbabilities)
{
	if (cur == 1)
		pProbabilities[sum - src]++;	// �ݹ��������Ӧ������1
	else
	{
		for (int i = 1; i <= maxValue; ++i)
			probability(src, cur - 1, sum + i, pProbabilities);	// ���ۼ�
	}
}