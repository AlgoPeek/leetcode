// Source: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
// Author: Diego Lee
// Date: 2018-09-01
//
// Description:
// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements that appear twice in this array.
//
// Could you do it without extra space and in O(n) runtime?
//
// Example:
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]

#include <iostream>
#include <vector>

class Solution
{
    public:
        std::vector<int> findDuplicates(std::vector<int>& nums)
        {
            std::vector<int> result;

            int len = nums.size();
            for (int i = 0; i < len; ++i)
            {
                int index = std::abs(nums[i]) - 1;
                if (nums[index] < 0)
                {
                    result.push_back(index + 1);
                }
                else
                {
                    nums[index] = -nums[index];
                }
            }
            return result;
        }
};

void testFindDuplicates(void)
{
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> result = Solution().findDuplicates(nums);
    assert(result == std::vector<int>({2, 3}));
}

int main()
{
    testFindDuplicates();
    return 0;
}
