#include <algorithm>

//leetcode remove duplicates 
class Solution {
public:
	// c���Է�ʽ
	int removeDuplicates1(int A[], int n)
	{
		if (n == 0) return 0;
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[index] != A[i])
				A[++index] = A[i];
		}
		return index + 1;
	}

	// STL 
	int removeDuplicates2(int A[], int n)
	{
		return std::distance(A, std::unique(A, A + n));
	}

	// STL �ظ��϶�ʱ��ʹ��
	int removeDuplicates3(int A[], int n)
	{
		return removeDuplicates3(A, A + n, A) - A;
	}
	template<typename InIt, typename OutIt>
	OutIt removeDuplicates3(InIt first, InIt last, OutIt output)
	{
		while (first != last)
		{
			*output++ = *first;   // ���� *output = *first; output ++;
			first = upper_bound(first, last, *first);  // ���ҹ���Ϊ���ֲ��ҷ�
		}
	}
};
