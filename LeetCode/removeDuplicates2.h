
// remove duplcates from sorted array 2

class Solution{
public:
	// �㷨�кܺõ���չ�ԣ���������ظ�k��ֵ�����
	int removeDuplicates1(int A[], int n)
	{
		if (n <= 2) return 2;

		int index = 2;
		for (int i = 2; i < n; i++)
		{
			if (A[i] != A[index - 2])
				A[index++] = A[i];
		}
		return index;
	}

	// �������߼��෴
	int removeDuplicates2(int A[], int n)
	{
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i > 0 && i < n - 1 && A[i] == A[i - 1] && A[i] == A[i + 1])
				continue;
			A[index++] = A[i];
		}
		return index;
	}
};