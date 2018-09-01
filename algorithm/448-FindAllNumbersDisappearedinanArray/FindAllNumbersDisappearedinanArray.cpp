// Source: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// Author: Diego Lee
// Date: 2018-09-01
//
// Description:
// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements of [1, n] inclusive that do not appear in this array.
//
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [5,6]
//

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
        {
            int len = nums.size();
            for (int i = 0; i < len; ++i)
            {
                int index = abs(nums[i]) - 1;
                if (index < len && nums[index] > 0)
                {
                    nums[index] = -nums[index];
                }
            }

            std::vector<int> result;
            for (int i = 0; i < len; ++i)
            {
                if (nums[i] > 0)
                {
                    result.push_back(i + 1);
                }
            }
            return result;
        }
};

void testFindDisappearedNumbers()
{
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution s;
    std::vector<int> result = s.findDisappearedNumbers(nums);
    assert(result == std::vector<int>({5, 6}));
}

int main()
{
    testFindDisappearedNumbers();
    return 0;
}
