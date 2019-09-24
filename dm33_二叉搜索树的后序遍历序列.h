#pragma once

/**
 * 找到根节点，在据此找到左、右子序列
 * 递归求解
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
	if (i < length - 1)	// 至少右子序列有一个点才进行递归，代入考虑则其无点时i=length-1
		right = verifySeqenceOfBST(seqence + i, length - i - 1);

	return left && right;
}