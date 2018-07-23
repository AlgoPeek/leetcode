// Source: https://leetcode.com/problems/search-insert-position/description/
// Author: Diego Lee
// Date: 2018-07-23
//
// Description:
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.
//
// Example 1:
// Input: [1,3,5,6], 5
// Output: 2
//
// Example 2:
// Input: [1,3,5,6], 2
// Output: 1
//
// Example 3:
// Input: [1,3,5,6], 7
// Output: 4
//
// Example 4:
// Input: [1,3,5,6], 0
// Output: 0

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

class Solution
{
    public:
        int searchInsert(std::vector<int>& nums, int target)
        {
            int pos = 0;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                if (target > nums[i])
                {
                    ++pos;
                }
                else
                {
                    break;
                }
            }
            return pos;
        }
};

void TestCase(int* A, int n, int target, int expire)
{
    std::vector<int> nums(A, A + n);

    Solution s;
    assert(s.searchInsert(nums, target) == expire);
}

void testSearInsert(void)
{
    int A1[] = {1, 3, 5, 6};
    int A2[] = {1, 3, 5, 6};
    int A3[] = {1, 3, 5, 6};
    int A4[] = {1, 3, 5, 6};
    TestCase(A1, countof(A1), 5, 2);
    TestCase(A2, countof(A2), 2, 1);
    TestCase(A3, countof(A3), 7, 4);
    TestCase(A4, countof(A4), 0, 0);
}

int main()
{
    testSearInsert();
    return 0;
}

