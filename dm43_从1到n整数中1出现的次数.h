#pragma once

/**
 * ����n�ж���λ����ÿһλ�仯0-9��
 * ���赱ǰλΪweight��Ȩ��base������߸�λΪround���ұߵ�λΪformer(=n%base)
 * �� 1) weight=0 -> round*base 2) weight=1 -> round*base+former+1
 * 3) weight>1 -> round*base+base
 * �Ӹ�λ�����λѭ��weight		O(logn)
 */
// https://blog.csdn.net/yi_afly/article/details/52012593

int countOf1In1Ton(int n)
{
	if (n < 1)
		return 0;

	int count = 0;
	int base = 1;
	int round = n;
	while (round > 0)
	{
		int weight = round % 10;	// �Ӹ�λ�����λѭ��
		round /= 10;
		count = round * base;
		if (weight == 1)
			count += n % base + 1;
		else if (weight > 1)
			count += base;
		base *= 10;
	}

	return count;
}