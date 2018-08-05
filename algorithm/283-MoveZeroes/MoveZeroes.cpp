// Source: https://leetcode.com/problems/move-zeroes/description/
// Author: Diego Lee
// Date: 2018-08-05
//
// Description:
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
// Example:
//
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:
//
// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        void moveZeroes(std::vector<int>& nums)
        {
            int n = nums.size();
            int zerocnt = 0;
            for (int i = 0; i + zerocnt < n; ++i)
            {
                if (nums[i] == 0)
                {
                    int remain = n - zerocnt;
                    for (int j = i; j < remain - 1; ++j)
                    {
                        nums[j] = nums[j + 1];
                    }
                    nums[remain - 1] = 0;
                    zerocnt += 1;
                    i -= 1;
                }
            }
        }
};

void testMoveZeroes()
{
    int A[] = {0,1,0,3,12};
    int R[] = {1,3,12,0,0};
    std::vector<int> nums(std::begin(A), std::end(A));

    Solution s;
    s.moveZeroes(nums);
    assert(nums == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testMoveZeroes();
    return 0;
}
