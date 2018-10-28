// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Author: Diego Lee
// Date: 2018-10-28
//
// Description:
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:
//
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            if (prices.empty()) {
                return 0;
            }

            std::vector<std::vector<int>> dp;
            for (size_t k = 0; k < 3; ++k) {
                dp.push_back(std::vector<int>(prices.size()));
            }

            for (size_t k = 1; k < 3; ++k) {
                int min = prices[0];
                for (size_t i = 1; i < prices.size(); ++i) {
                    min = std::min(min, prices[i] - dp[k-1][i-1]);
                    dp[k][i] = std::max(dp[k][i-1], prices[i] - min);
                }
            }
            return dp[2][prices.size() - 1];
        }
};

void testMaxProfit() {
    std::vector<int> prices = {3,3,5,0,0,3,1,4};
    int result = Solution().maxProfit(prices);
    assert(result == 6);
}

int main() {
    testMaxProfit();
    return 0;
}
