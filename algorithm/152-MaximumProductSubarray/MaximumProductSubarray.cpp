// Source: https://leetcode.com/problems/maximum-product-subarray/description/
// Author: Diego Lee
// Date: 2018-10-20
//
// Description:
// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    public:
        int maxProduct(std::vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }

            std::vector<int> dp_min(nums.size());
            std::vector<int> dp_max(nums.size());
            int m = nums[0];
            dp_min[0] = m, dp_max[0] = m;
            for (int i = 1, len = nums.size(); i < len; ++i) {
                dp_min[i] = std::min(dp_min[i-1] * nums[i], std::min(dp_max[i-1] * nums[i], nums[i]));
                dp_max[i] = std::max(dp_max[i-1] * nums[i], std::max(dp_min[i-1] * nums[i], nums[i]));
                m = std::max(m, dp_max[i]);
            }
            return m;
        }
};

void testMaxProduct() {
    std::vector<int> nums = {2,3,-2,4};
    int result = Solution().maxProduct(nums);
    assert(result == 6);
}

int main() {
    testMaxProduct();
    return 0;
}
