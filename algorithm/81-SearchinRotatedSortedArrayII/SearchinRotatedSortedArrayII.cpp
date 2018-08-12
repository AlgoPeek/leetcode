// Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// Author: Diego Lee
// Date: 2018-08-12
//
// Description:
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
// Follow up:
//
// This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// Would this affect the run-time complexity? How and why?

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        bool search(std::vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                {
                    return true;
                }
                else if (nums[mid] > nums[right])
                {
                    if (target >= nums[left] && target < nums[mid])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                else if (nums[mid] < nums[right])
                {
                    if (target > nums[mid] && target <= nums[right])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    --right;
                }
            }
            return false;
        }
};

void testSearch()
{
    int A1[] = {2,5,6,0,0,1,2};
    int A2[] = {2,5,6,0,0,1,2};
    int A3[] = {1,2,1,1,1,1,1};

    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));
    std::vector<int> nums3(std::begin(A3), std::end(A3));

    Solution s;
    assert(s.search(nums1, 0) == true);
    assert(s.search(nums2, 3) == false);
    assert(s.search(nums3, 2) == true);
}

int main()
{
    testSearch();
    return 0;
}
