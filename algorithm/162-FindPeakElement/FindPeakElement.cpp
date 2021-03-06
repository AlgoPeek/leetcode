// Source: https://leetcode.com/problems/find-peak-element/
// Author: Diego Lee
// Date: 2018-10-23
//
// Description:
// A peak element is an element that is greater than its neighbors.
//
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
//
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
// You may imagine that nums[-1] = nums[n] = -∞.
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak element is 2,
//              or index number 5 where the peak element is 6.
// Note:
//
// Your solution should be in logarithmic complexity.

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    public:
        int findPeakElement(std::vector<int>& nums) {
            for (int i = 0; i < nums.size(); ++i) {
                bool largerThanLeft = true;
                bool largerThanRight = true;
                if (i > 0) {
                    largerThanLeft = nums[i] > nums[i-1];
                }
                if (i < nums.size() - 1) {
                    largerThanRight = nums[i] > nums[i+1];
                }
                if (largerThanLeft && largerThanRight) {
                    return i;
                }
            }
            return -1;
        }
};

void testFindPeakElement() {
    std::vector<int> nums = {1,2,3,1};
    int result = Solution().findPeakElement(nums);
    assert(result == 2);
}

int main() {
    testFindPeakElement();
    return 0;
}
