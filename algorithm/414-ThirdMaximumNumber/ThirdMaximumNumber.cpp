// Source: https://leetcode.com/problems/third-maximum-number/description/
// Author: Diego Lee
// Date: 2018-08-30
//
// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
//
// Example 1:
// Input: [3, 2, 1]
//
// Output: 1
//
// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]
//
// Output: 2
//
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]
//
// Output: 1
//
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.

#include <iostream>
#include <cassert>
#include <set>
#include <vector>

class Solution
{
    public:
        int thirdMax(std::vector<int>& nums)
        {
            if (nums.empty())
            {
                return 0;
            }

            std::set<int> s;
            for (auto n : nums)
            {
                s.insert(n);
                if (s.size() > 3)
                {
                    s.erase(s.begin());
                }
            }
            return s.size() >= 3 ? *s.begin() : *s.rbegin();
        }
};

void testThirdMax()
{
    std::vector<int> nums1 = {3, 2, 1};
    std::vector<int> nums2 = {1, 2};
    std::vector<int> nums3 = {2, 2, 3, 1};

    Solution s;
    assert(s.thirdMax(nums1) == 1);
    assert(s.thirdMax(nums2) == 2);
    assert(s.thirdMax(nums3) == 1);
}

int main()
{
    testThirdMax();
    return 0;
}
