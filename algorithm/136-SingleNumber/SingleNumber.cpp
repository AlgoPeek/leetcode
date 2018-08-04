// Source: https://leetcode.com/problems/single-number/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
// Input: [2,2,1]
// Output: 1
// Example 2:
//
// Input: [4,1,2,1,2]
// Output: 4

#include <iostream>
#include <cassert>
#include <vector>

class Solution
{
    public:
        int singleNumber(const std::vector<int>& nums)
        {
            int mask = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                mask ^= nums[i];
            }
            return mask;
        }
};

void testSingleNumber()
{
    int arr[] = {1, 1, 4, 4, 10};
    std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution s;
    int result = s.singleNumber(nums);
    assert(result == 10);
}

int main()
{
    testSingleNumber();
    return 0;
}
