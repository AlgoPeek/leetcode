// Source: https://leetcode.com/problems/missing-number/description/
// Author: Diego Lee
// Date: 2018-08-08
//
// Description:
// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
// Example 1:
//
// Input: [3,0,1]
// Output: 2
// Example 2:
//
// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <iostream>
#include <cassert>
#include <vector>

class Solution
{
    public:
        int missingNumber(std::vector<int>& nums)
        {
            if (nums.empty())
            {
                return 0;
            }

            int n = nums.size();
            int sum = n * (n + 1) / 2;
            for (int i = 0; i < n; ++i)
            {
                sum -= nums[i];
            }
            return sum;
        }
};

void testMissingNumber()
{
    int A1[] = {3,0,1};
    int A2[] = {9,6,4,2,3,5,7,0,1};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));

    Solution s;
    assert(s.missingNumber(nums1) == 2);
    assert(s.missingNumber(nums2) == 8);
}

int main()
{
    testMissingNumber();
    return 0;
}
