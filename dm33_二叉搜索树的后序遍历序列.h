#pragma once

/**
 * �ҵ����ڵ㣬�ھݴ��ҵ�����������
 * �ݹ����
 */
bool verifySeqenceOfBST(int* seqence, int length)
{
	if (seqence == nullptr || length <= 0)
		return false;

	int root = seqence[length - 1];

	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (seqence[i] > root)
			break;
	}

	int j = i;
	for (; j < length - 1; ++j)
	{
		if (seqence[j] < root)
			return false;
	}

	bool left = true;
	if (i > 0)
		left = verifySeqenceOfBST(seqence, i);

	bool right = true;
	if (i < length - 1)	// ��������������һ����Ž��еݹ飬���뿼�������޵�ʱi=length-1
		right = verifySeqenceOfBST(seqence + i, length - i - 1);

	return left && right;
}