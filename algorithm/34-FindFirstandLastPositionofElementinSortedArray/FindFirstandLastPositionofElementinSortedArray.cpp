// Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Author: Diego Lee
// Date: 2018-07-23
//
// Descripton:
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

class Solution
{
    public:
        std::vector<int> searchRange(const std::vector<int>& nums, int target)
        {
            int start = -1;
            int end = -1;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                if (nums[i] == target)
                {
                    if (start == -1)
                    {
                        start = i;
                    }
                    if (i == nums.size() - 1)
                    {
                        end = i;
                    }
                }
                else if (start != -1)
                {
                    end = i - 1;
                    break;
                }
            }

            std::vector<int> result;
            result.push_back(start);
            result.push_back(end);
            return result;
        }
};

void testSearchRange()
{
    int A1[] = {5,7,7,8,8,10};
    int A2[] = {5,7,7,8,8,10};
    int R1[] = {3, 4};
    int R2[] = {-1, -1};

    Solution s;
    std::vector<int> result = s.searchRange(std::vector<int>(std::begin(A1), std::end(A1)), 8);
    assert(result == std::vector<int>(std::begin(R1), std::end(R1)));

    result = s.searchRange(std::vector<int>(std::begin(A1), std::end(A1)), 6);
    assert(result == std::vector<int>(std::begin(R2), std::end(R2)));
}

int main(void)
{
    testSearchRange();
    return 0;
}
