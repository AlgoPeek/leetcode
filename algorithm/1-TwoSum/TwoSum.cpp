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
            int val = target - nums[i];
            std::map<int, int>::iterator it = viMap.find(val);
            if (it != viMap.end())
            {
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            else
            {
                viMap.insert(std::make_pair(nums[i], i));
            }
        }
        return result;
    }
};

void testTwoSum()
{
    int A[] = {2, 7, 11, 15};
    std::vector<int> nums(std::begin(A), std::end(A));
    std::vector<int> result = Solution().twoSum(nums, 9);
    assert(result.size() == 2);
    assert(result[0] == 0);
    assert(result[1] == 1);
}

int main()
{
    testTwoSum();
    return 0;
}
