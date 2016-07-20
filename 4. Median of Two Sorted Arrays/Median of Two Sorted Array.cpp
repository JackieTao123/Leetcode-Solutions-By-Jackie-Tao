#include <iostream>
#include "Median of Two Sorted Arrays.h"
int main()
{
	Solution s;
	vector<int> vec1{ 1,3 };
	vector<int> vec2{ 2 };
	std::cout << s.findMedianSortedArrays(vec1, vec2) << std::endl;

	system("pause");
	return 0;
}