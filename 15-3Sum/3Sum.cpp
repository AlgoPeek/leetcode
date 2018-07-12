// Source: https://leetcode.com/problems/3sum/description/
// Author: Diego Lee
// Date: 2018-07-13
//
// Description:
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which
// gives the sum of zero.
//
// Note:
// The solution set must not contain duplicate triplets.
//
// Example:
// Given array nums = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
//]
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
            std::vector<std::vector<int> > vv;
            std::sort(nums.begin(), nums.end());

            for (size_t i = 0; i < nums.size() - 2; ++i) {
                if (i == 0 || nums[i] > nums[i - 1]) {
                    int negate = -nums[i];
                    int start = i + 1;
                    int end = nums.size() - 1;
                    while (start < end) {
                        // case 1
                        if (nums[start] + nums[end] == negate) {

                            std::vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[start]);
                            v.push_back(nums[end]);
                            vv.push_back(v);
                            ++start;
                            --end;

                            // avoid duplicate solutions
                            while (start < end && nums[end] == nums[end + 1])
                                --end;
                            while (start < end && nums[start] == nums[start - 1])
                                ++start;
                        }
                        else if (nums[start] + nums[end] < negate) {
                            ++start;
                        }
                        else {
                            --end;
                        }
                    }
                }
            }
            return vv;
        }
};

void testThreeSum() {
    int a[] = {-1, 0, 1, 2, -1, -4};
    std::vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    std::vector<std::vector<int> > vv = s.threeSum(nums);
    // std::cout << vv.size() << std::endl;
    assert(vv.size() == 2);
    assert(vv[0].size() == 3);
    assert(vv[1].size() == 3);
    assert(vv[0][0] + vv[0][1] + vv[0][2] == 0);
    assert(vv[1][0] + vv[1][1] + vv[1][2] == 0);
}

int main() {
    testThreeSum();
    return 0;
}
