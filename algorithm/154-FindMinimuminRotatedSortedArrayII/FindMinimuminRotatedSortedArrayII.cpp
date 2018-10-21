// Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
// Author: Diego Lee
// Date: 2018-10-21
//
// Description:
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// The array may contain duplicates.
//
// Example 1:
//
// Input: [1,3,5]
// Output: 1
// Example 2:
//
// Input: [2,2,2,0,1]
// Output: 0
// Note:
//
// This is a follow up problem to Find Minimum in Rotated Sorted Array.
// Would allow duplicates affect the run-time complexity? How and why?

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    public:
        int findMin(std::vector<int>& nums) {
            if (nums.empty()) {
                return -1;
            }

            int left = 0;
            int right = nums.size() - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > nums[right]) {
                    left = mid + 1;
                }
                else if (nums[mid] < nums[right]) {
                    right = mid;
                }
                else {
                    right -= 1;
                }
            }
            return nums[left];
        }
};

void testFindMin() {
    std::vector<int> nums = {1,3,5};
    int result = Solution().findMin(nums);
    assert(result == 1);
}

int main() {
    testFindMin();
    return 0;
}
