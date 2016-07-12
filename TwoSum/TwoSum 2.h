/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Modification history:
2.13.2016  Return indice can starts from zero(0)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
class Solution{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> mapping_nums;
		unsigned len = nums.size();

		//put the values of input vector and its indices two the unordered_map
		for (int i = 0; i < len; i++)
		{

			mapping_nums[nums[i]] = i;
		}
		vector<int> result;

		for (auto i = 0; i < len; ++i)
		{
			int gap = target - nums[i];
			if (mapping_nums.find(gap) != mapping_nums.end() && mapping_nums[gap] > i)
			{
				result.push_back(mapping_nums[nums[i]]);
				result.push_back(mapping_nums[gap]);
				break;
			}
		}

		//if comes this far, that means there is no such indices pair of the input vector.
		//then, we pushback negative number -1 to break the program.
	/*	{
			result.push_back(-1);
			result.push_back(-1);
		}*/
		return result;
	}
};