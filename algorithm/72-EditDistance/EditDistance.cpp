// Source: https://leetcode.com/problems/edit-distance/description/
// Author: Diego Lee
// Date: 2018-09-08
//
// Description:
// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
// Insert a character
// Delete a character
// Replace a character
// Example 1:
//
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:
//
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int minDistance(std::string word1, std::string word2)
        {
            int m = word1.size();
            int n = word2.size();
            std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
            for (int i = 1; i <= m; ++i)
            {
                dp[i][0] = i;
            }
            for (int j = 1; j <= n; ++j)
            {
                dp[0][j] = j;
            }

            for (int i = 1; i <= m; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (word1[i-1] == word2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = std::min(dp[i-1][j-1] + 1, std::min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                    }
                }
            }
            // std::cout << "word1=" << word1 << ", word1=" << word2 << ", result=" << dp[m][n] << std::endl;
            return dp[m][n];
        }
};

void testMinDistanceCase1()
{
    Solution s;
    int result = s.minDistance("horse", "ros");
    assert(result == 3);
}

void testMinDistanceCase2()
{
    Solution s;
    int result = s.minDistance("intention", "execution");
    assert(result == 5);
}

int main()
{
    testMinDistanceCase1();
    testMinDistanceCase2();
    return 0;
}
