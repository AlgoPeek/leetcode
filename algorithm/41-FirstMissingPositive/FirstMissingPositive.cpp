// Source: https://leetcode.com/problems/first-missing-positive/description/
// Author: Diego Lee
// Date: 2018-07-26
//
// Description:
// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
//
// Input: [1,2,0]
// Output: 3
// Example 2:
//
// Input: [3,4,-1,1]
// Output: 2
// Example 3:
//
// Input: [7,8,9,11,12]
// Output: 1
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution
{
    public:
        int firstMissingPositive(std::vector<int>& nums)
        {
            return firstMissingPositiveBySort(nums);
        }

        int firstMissingPositiveBySort(std::vector<int>& nums)
        {
            if (nums.empty())
            {
                return 1;
            }

            std::sort(nums.begin(), nums.end());
            int result = 1;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                if (nums[i] > result && nums[i] > 1)
                {
                    break;
                }
                else
                {
                    result = nums[i] + 1;
                }
            }
            return std::max(result, 1);
        }
};

void testFirstMissingPositive()
{
    int A1[] = {1,2,0};
    int A2[] = {3,4,-1,1};
    int A3[] = {7,8,9,11,12};
    int A4[] = {-3,-2,-1,0};
    int A5[] = {1,2,2,1,3,1,0,4,0};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));
    std::vector<int> nums3(std::begin(A3), std::end(A3));
    std::vector<int> nums4(std::begin(A4), std::end(A4));
    std::vector<int> nums5(std::begin(A5), std::end(A5));

    Solution s;
    assert(s.firstMissingPositive(nums1) == 3);
    assert(s.firstMissingPositive(nums2) == 2);
    assert(s.firstMissingPositive(nums3) == 1);
    assert(s.firstMissingPositive(nums4) == 1);
    assert(s.firstMissingPositive(nums5) == 5);
}

int main()
{
    testFirstMissingPositive();
    return 0;
}
