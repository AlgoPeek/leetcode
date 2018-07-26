// Source: https://leetcode.com/problems/jump-game-ii/description/
// Author: Diego Lee
// Date: 2018-07-26
//
// Descripton:
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Note:
//
// You can assume that you can always reach the last index.

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int jump(std::vector<int>& nums)
        {
            int n = nums.size();
            int steps = 0;
            int start = 0;
            int end = 0;
            while (end < n - 1)
            {
                ++steps;
                int maxend = end + 1;
                for (int i = start; i <= end; ++i)
                {
                    if (i + nums[i] >= n - 1)
                    {
                        return steps;
                    }
                    else
                    {
                        maxend = std::max(maxend, i + nums[i]);
                    }
                }
                start = end + 1;
                end = maxend;
            }
            return steps;
        }
};

void testJump()
{
    int A1[] = {2,3,1,1,4};
    int A2[] = {0};
    int A3[] = {1,2,3};
    int A4[] = {1,2,1,1,1};
    int A5[] = {10,9,8,7,6,5,4,3,2,1,1,0};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));
    std::vector<int> nums3(std::begin(A3), std::end(A3));
    std::vector<int> nums4(std::begin(A4), std::end(A4));
    std::vector<int> nums5(std::begin(A5), std::end(A5));

    Solution s;
    assert(s.jump(nums1) == 2);
    assert(s.jump(nums2) == 0);
    assert(s.jump(nums3) == 2);
    assert(s.jump(nums4) == 3);
    assert(s.jump(nums5) == 2);
}

int main()
{
    testJump();
    return 0;
}
