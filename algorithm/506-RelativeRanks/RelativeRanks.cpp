// Source: https://leetcode.com/problems/relative-ranks/description/
// Author: Diego Lee
// Date: 2018-09-19
//
// Description:
// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
// Example 1:
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
// For the left two athletes, you just need to output their relative ranks according to their scores.
// Note:
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.

#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution {
    struct RankItem {
        int val;
        int index;

        RankItem() : val(0), index(0) {}
        RankItem(int _val, int _index) : val(_val), index(_index) {}
    };

    friend bool operator<(const RankItem& rhs, const RankItem& lhs) {
        return lhs.val < rhs.val;
    }
    public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& nums) {
        std::vector<RankItem> items;
        for (size_t i = 0; i < nums.size(); ++i) {
            items.push_back(RankItem(nums[i], i));
        }
        std::sort(items.begin(), items.end());

        std::vector<std::string> result(items.size());
        for (int i = 0; i < items.size(); ++i) {
            const RankItem& ri = items[i];
            if (i == 0) {
                result[ri.index] = "Gold Medal";
            }
            else if (i == 1) {
                result[ri.index] = "Silver Medal";
            }
            else if (i == 2) {
                result[ri.index] = "Bronze Medal";
            }
            else {
                result[ri.index] = intToStr(i + 1);
            }
        }
        return result;
    }

    std::string intToStr(int n) {
        std::stringstream ss;
        ss << n;
        return ss.str();
    }
};

void testFindRelativeRanks() {
    std::vector<int> nums = {5, 4, 3, 2, 1};
    Solution s;

    std::vector<std::string> result = s.findRelativeRanks(nums);
    assert(result == std::vector<std::string>({
        "Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"}));
}

int main() {
    testFindRelativeRanks();
    return 0;
}
