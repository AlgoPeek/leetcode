// Source: https://leetcode.com/problems/maximum-average-subarray-i/description/
// Author: Diego Lee
// Date: 2018-09-29
//
// Description:
// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
//
// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
// Note:
// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    public:
        double findMaxAverage(std::vector<int>& nums, int k) {
            if (k <= 0 && k > nums.size()) {
                return 0.0;
            }

            int sum = 0;
            for (int i = 0; i < k; ++i) {
                sum += nums[i];
            }

            double maxAverage = (double)sum / k;
            for (int i = k, len = nums.size(); i < len; ++i) {
                sum += (nums[i] - nums[i - k]);
                double aver = ((double)sum / k);
                if (aver > maxAverage) {
                    maxAverage = aver;
                }
            }
            return maxAverage;
        }
};

void testFindMaxAverage() {
    std::vector<int> nums = {1,12,-5,-6,50,3};
    Solution s;
    double result = s.findMaxAverage(nums, 4);
    assert(result == 12.75);
}

int main() {
    testFindMaxAverage();
    return 0;
}
