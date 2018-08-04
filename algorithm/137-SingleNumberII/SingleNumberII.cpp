// Source: https://leetcode.com/problems/single-number-ii/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
// Input: [2,2,3,2]
// Output: 3
// Example 2:
//
// Input: [0,1,0,1,0,1,99]
// Output: 99

#include <iostream>
#include <assert.h>
#include <vector>

class Solution
{
    public:
        int singleNumber(std::vector<int>& nums)
        {
            int result = 0;
            for (int i = 0; i < 32; ++i)
            {
                int c = 0;
                int mask = 1 << i;
                for (int j = 0; j < nums.size(); ++j)
                {
                    if (nums[j] & mask)
                    {
                        ++c;
                    }
                }
                if (c % 3)
                {
                    result |= mask;
                }
            }
            return result;
        }
};

void testSingleNumber()
{
    int a[] = {1,1,1,2,2,2,3};
    std::vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));

    Solution s;
    int r = s.singleNumber(vec);
    assert(3 == r);
}

int main()
{
    testSingleNumber();
    return 0;
}
