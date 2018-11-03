// Source: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: Diego Lee
// Date: 2018-11-03
//
// Description:
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

class Solution {
    public:
        int longestConsecutive(std::vector<int>& nums) {
            std::unordered_set<int> s(nums.begin(), nums.end());
            int maxlen = 0;
            for (auto n : s) {
                if (s.find(n-1) == s.end()) {
                    int k = n + 1;
                    while (s.find(k) != s.end()) {
                        k += 1;
                    }
                    maxlen = std::max(maxlen, k - n);
                }
            }
            return maxlen;
        }
};

void testLongestConsecutive() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = Solution().longestConsecutive(nums);
    assert(result == 4);
}

int main() {
    testLongestConsecutive();
    return 0;
}
