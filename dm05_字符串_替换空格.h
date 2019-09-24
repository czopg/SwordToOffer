#pragma once
/**
 * �ڴ�ǰ�����滻��Ҫ�ƶ���ͬ�ַ���ε�����£����ǴӺ���ǰ�ƶ��ַ�
 * ���Լ����ƶ����������ʱ��Ч�ʡ�
 * �ڴ渲�ǵ����⡣
 *
 * ����ո���Ŀ�õ��滻���ַ������ȣ���������ָ��ֱ�ָ���滻ǰ���
 * �ַ���ĩβ���Ӻ���ǰ���ơ�ʱ�临�Ӷ� O(n)��
 */
// �����ַ������鼰������
void replaceBlank(char m_string[], int capacity)
{
	if (m_string == nullptr || capacity <= 0)
		return;

	// �����ַ������ȺͿո����
	int lengthOfString = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (m_string[i] != '\0')
	{
		++lengthOfString;
		if (m_string[i] == ' ')
			++numberOfBlank;
		++i;
	}

	// �滻���ַ����³���
	int newLength = lengthOfString + numberOfBlank * 2;
	if (newLength > capacity)
		return;

	// ͨ����������ָ��Ӻ���ǰ�滻�ַ���
	int oldIndex = lengthOfString;
	int newIndex = newLength;
	while (oldIndex >= 0 && newIndex > oldIndex)
	{
		if (m_string[oldIndex] == ' ')
		{
			m_string[newIndex--] = '0';
			m_string[newIndex--] = '2';
			m_string[newIndex--] = '%';
		}
		else
			m_string[newIndex--] = m_string[oldIndex];
		--oldIndex;
	}
}