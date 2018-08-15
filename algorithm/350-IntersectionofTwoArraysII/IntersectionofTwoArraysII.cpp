// Source: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Author: Diego Lee
// Date: 2018-08-15
//
// Description:
// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:
//
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:
//
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
        {
            std::sort(nums1.begin(), nums1.end());
            std::sort(nums2.begin(), nums2.end());

            std::vector<int> result;
            int i = 0;
            int j = 0;
            while (i < nums1.size() && j < nums2.size())
            {
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

void testIntersect()
{
    int A1[] = {1,2,2,1};
    int A2[] = {2,2};
    int R[] = {2,2};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));

    Solution s;
    assert(s.intersect(nums1, nums2) == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testIntersect();
    return 0;
}
