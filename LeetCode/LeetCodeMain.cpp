#include <iostream>
#include <algorithm>

//#include "removeDuplicates.h"
#include "removeDuplicates2.h"

using namespace std;


int main()
{
	// remove Duplicates 
	Solution s;
	int a[10] = { 1, 1, 1, 3, 5, 6, 8, 10, 10, 10 };
	cout << s.removeDuplicates2(a, 10) << endl;

	system("pause");
	return 0;
}