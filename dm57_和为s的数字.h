#pragma once
// 题目一：和为s的两个数字
// 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
/**
 * 使用两个指针，指向第一和最后的数字，其和小于s则第一个指针后移，
 * 其和大于s则最后一个指针前移。
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


// 题目二：和为s的连续正数序列
// 输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。
/**
 * 使用两个指针，small=1,big=2 向两边扩展，small一直增加到(s+1)/2
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
			numSum += big;	// 要先移指针后加
		}
	}
}

void printSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d ", i);
	printf("\n");
}