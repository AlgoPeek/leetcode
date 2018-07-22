// Source: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Author: Diego Lee
// Date: 2018-07-22
//
// Description:
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int search(std::vector<int>& nums, int target)
        {
            int pivot = findPivot(nums);
            if (pivot != -1)
            {
                if (target >= nums[0] && target <= nums[pivot - 1])
                {
                    return binarySearch(nums, 0, pivot - 1, target);
                }
                else if (target >= nums[pivot] && target <= nums[nums.size() - 1])
                {
                    return binarySearch(nums, pivot, nums.size() - 1, target);
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return binarySearch(nums, 0, nums.size() - 1, target);
            }
        }

        int findPivot(std::vector<int>& nums)
        {
            int left = 0;
            int right = nums.size() - 1;
            int pivot = -1;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                // std::cout << "left=" << left << ",right=" << right << ", mid=" << mid << std::endl;
                if (mid + 1 <= right && nums[mid] > nums[mid + 1])
                {
                    pivot = mid + 1;
                    break;
                }
                else if (mid - 1 >= left && nums[mid] < nums[mid - 1])
                {
                    pivot = mid;
                    break;
                }
                else if (nums[mid] >= nums[left])
                {
                    // [left, mid] is ordered
                    left = mid + 1;
                }
                else
                {
                    // mid
                    right = mid - 1;
                }
            }
            return pivot;
        }

        int binarySearch(std::vector<int>& nums, int left, int right, int target)
        {
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    return mid;
                }
            }
            return -1;
        }
};

void testSearch()
{
    int A1[] = {4,5,6,7,0,1,2};
    int A2[] = {3, 1};
    int A3[] = {5, 1, 3};

    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));
    std::vector<int> nums3(std::begin(A3), std::end(A3));

    Solution s;
    assert(s.search(nums1, 0) == 4);
    assert(s.search(nums1, 3) == -1);
    assert(s.search(nums2, 1) == 1);
    assert(s.search(nums3, 5) == 0);
}

int main()
{
    testSearch();
    return 0;
}
