/*
	There are two sorted arrays nums1 and nums2 of size m and n respectively.
	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

	Example 1:
	nums1 = [1, 3]
	nums2 = [2]

	The median is 2.0
	Example 2:
	nums1 = [1, 2]
	nums2 = [3, 4]
	The median is (2 + 3)/2 = 2.5
*/

//using a temp vecotr to store all the elements of these two vectors,
//sort the temp vector,
//then we can get the median number easily.
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> temp(0);
		vector<int>::iterator iter = nums1.begin();
		for (; iter != nums1.end(); ++iter)
			temp.push_back(*iter);
		iter = nums2.begin();
		for (; iter != nums2.end(); ++iter)
			temp.push_back(*iter);
		std::sort(temp.begin(), temp.end());
		if (temp.size() & 0x1)
		{
			return temp[temp.size()/2.0];
		}
		else
		{
			return (temp[temp.size() >> 1] + temp[(temp.size() >> 1) - 1]) / 2.0;
		}

	}
};