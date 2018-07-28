// Source: https://leetcode.com/problems/maximum-subarray/
// Author: Diego Lee
// Date: 2018-07-28
//
// Description:
// Given an integer array nums, find the contiguous subarray (containing at least one number)
// which has the largest sum and return its sum.
//
// Example:
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and
// conquer approach, which is more subtle.

#include <iostream>
#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        std::vector<int> dp(nums.size());
        int m = nums[0];
        dp[0] = m;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
            m = std::max(m, dp[i]);
        }
        return m;
    }
};

void testMaxSubArray()
{
    int A[] = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> v(A, A + sizeof(A) / sizeof(int));
    Solution s;
    assert(s.maxSubArray(v) == 6);
}

int main()
{
    testMaxSubArray();
    return 0;
}
