// Source: https://leetcode.com/problems/longest-harmonious-subsequence/description/
// Author: Diego Lee
// Date: 2018-09-04
//
// Description:
// We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
//
// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
//
// Example 1:
// Input: [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].
// Note: The length of the input array will not exceed 20,000.

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class Solution
{
    public:
        int findLHS(std::vector<int>& nums)
        {
            std::unordered_map<int, int> hash;
            for (auto n : nums)
            {
                ++hash[n];
            }

            int result = 0;
            for (auto it = hash.begin(); it != hash.end(); ++it)
            {
                int next = it->first + 1;
                if (hash.find(next) != hash.end())
                {
                    result = std::max(result, it->second + hash[next]);
                }
            }
            return result;
        }
};

void testFindLHS(void)
{
    std::vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    std::vector<int> nums2 = {1, 2, 3, 4};

    Solution s;
    int result = s.findLHS(nums1);
    assert(result == 5);
    result = s.findLHS(nums2);
    assert(result == 2);
}

int main()
{
    testFindLHS();
    return 0;
}
