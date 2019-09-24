#pragma once
#include <vector>
using namespace std;
/* ���� B[i]�ֳ������֣�C[i]=C[i-1]��A[i-1] �� D[i]=D[i+1]��A[i+1] 
   ע�����ֲ�����߽�ֵ0��n-1 */
void multiply(const vector<double>& arrayA, const vector<double>& arrayB)
{
	int len1 = arrayA.size();
	int len2 = arrayB.size();
	if (len1 == len2 && len2 > 1)
	{
		arrayB[0] = 1;
		for (int i = 1; i < len2; ++i)
		{
			arrayB[i] = arrayB[i - 1] * arrayA[i - 1];
		}

		double temp = 1;
		for (int i = len2 - 2; i >= 0; --i)
		{
			temp *= arrayA[i + 1];
			arrayB[i] *= temp;
		}
	}
}