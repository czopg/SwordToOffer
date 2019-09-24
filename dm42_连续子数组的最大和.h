#pragma once
#include <exception>

/**
 * ������������ֻ��߿��Ƕ�̬�滮
 * f(i-1)>0ʱ�ۼӲ�������
 */

int findMaxSumOfSubArray(int* pData, int length)
{
	if (pData == nullptr || length <= 0)
		throw new std::exception("Invalid input.");

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;	// -(2^31) ����ȫ������
	for (int i = 0; i < length; ++i)
	{
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}

	return nGreatestSum;
}