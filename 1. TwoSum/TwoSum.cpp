//#include "TwoSum.h"
#include "TwoSum 2.h"

int main()
{
	Solution s;
	vector<int> nums = { 2, 7, 11, 15, 16 };
	int target = 31;
	vector<int> result = s.twoSum(nums, target);
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	system("pause");
	return 0;
}