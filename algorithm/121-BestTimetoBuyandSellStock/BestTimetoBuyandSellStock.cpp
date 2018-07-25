// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Author: Diego Lee
// Date: 2018-07-25
//
// Desciption:
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.
// Note that you cannot sell a stock before you buy one.
//
// Example 1:
// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
//
// Example 2:
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int maxProfit(std::vector<int>& prices)
        {
            if (prices.empty())
            {
                return 0;
            }

            std::vector<int> minBuy(prices.size());
            minBuy[0] = prices[0];
            for (int i = 1; i < prices.size(); ++i)
            {
                minBuy[i] = std::min(prices[i], minBuy[i - 1]);
            }

            int result = 0;
            for (int j = 0; j < prices.size(); ++j)
            {
                result = std::max(result, prices[j] - minBuy[j]);
            }
            return result;
        }
};

void testMaxProfix()
{
    int A[] = {7, 1, 5, 3, 6, 4};
    std::vector<int> prices(std::begin(A), std::end(A));

    Solution s;
    assert(s.maxProfit(prices) == 5);
}

int main()
{
    testMaxProfix();
    return 0;
}
