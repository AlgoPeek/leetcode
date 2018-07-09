// Source: https://leetcode.com/problems/two-sum/description/
// Author: Diego Lee
// Date: 2018-07-09
//
// Description:
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//

#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
		std::vector<int> result;
		std::map<int, int> viMap;
		for (size_t i = 0; i < nums.size(); ++i)
        {
			int val = nums[i];
			std::map<int, int>::iterator it = viMap.find(val);
			if (it != viMap.end())
            {
				result.push_back(it->second + 1);
				result.push_back(i + 1);
				break;
			}
			else
            {
				viMap.insert(std::make_pair(target - val, i));
			}
		}
		return result;
	}
};

void testTwoSumCase(int* A, int n, int target)
{
	std::vector<int> nums(A, A + n);
    std::vector<int> result = Solution().twoSum(nums, target);
	assert(result.size() == 1);
	assert(result[0] == 1);
	assert(result[1] == 2);
}

int main()
{
    int A[] = {2, 7, 11, 15};
    int target = 9;
	testTwoSumCase(A, sizeof(A) / sizeof(int), target);
	return 0;
}
