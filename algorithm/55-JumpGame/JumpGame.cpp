// Source: https://leetcode.com/problems/jump-game/description/
// Author: Diego Lee
// Date: 2018-07-27
//
// Description:
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Determine if you are able to reach the last index.
//
// Example 1:
//
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:
//
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
// jump length is 0, which makes it impossible to reach the last index.

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return true;
        }

        int maxstep = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (maxstep == 0)
            {
                return false;
            }

            --maxstep;
            if (maxstep < nums[i])
            {
                maxstep = nums[i];
            }
            if (i + maxstep >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};

void testCanJump()
{
    int A1[] = {2,3,1,1,4};
    int A2[] = {3,2,1,0,4};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));

    Solution s;
    assert(s.canJump(nums1) == true);
    assert(s.canJump(nums2) == false);
}

int main()
{
    testCanJump();
    return 0;
}
