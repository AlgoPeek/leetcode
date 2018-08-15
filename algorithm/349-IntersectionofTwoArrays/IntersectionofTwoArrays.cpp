// Source: https://leetcode.com/problems/intersection-of-two-arrays/description/
// Author: Diego Lee
// Date: 2018-08-15
//
// Description:
// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Note:
//
// Each element in the result must be unique.
// The result can be in any order.

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

class Solution
{
    public:
        std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
        {
            std::sort(nums1.begin(), nums1.end());
            std::sort(nums2.begin(), nums2.end());

            std::vector<int> result;
            int i = 0;
            int j = 0;
            while (i < nums1.size() && j < nums2.size())
            {
                // skip nums1 duplicate
                if (i > 0 && nums1[i] == nums2[i-1])
                {
                    ++i;
                    continue;
                }

                // skip nums2 duplicate
                if (j > 0 && nums2[j] == nums2[j-1])
                {
                    ++j;
                    continue;
                }

                if (nums1[i] == nums2[j])
                {
                    result.push_back(nums1[i]);
                    ++i;
                    ++j;
                }
                else if (nums1[i] < nums2[j])
                {
                    ++i;
                }
                else
                {
                    ++j;
                }
            }
            return result;
        }
};

void testIntersection()
{
    int A1[] = {1,2,2,1};
    int A2[] = {2,2};
    int R[] = {2};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));

    Solution s;
    std::vector<int> result = s.intersection(nums1, nums2);
    assert(result == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testIntersection();
    return 0;
}

