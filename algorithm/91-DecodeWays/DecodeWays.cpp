// Source: https://leetcode.com/problems/decode-ways/description/
// Author: Diego Lee
// Date: 2018-08-18
//
// Description:
// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>

class Solution
{
    public:
        int numDecodings(std::string s)
        {
            if (s.empty())
            {
                return 0;
            }

            std::vector<int> dp(s.size() + 1);
            dp[0] = 1;
            dp[1] = (s[0] != '0') ? 1 : 0;
            for (int i = 2; i <= s.size(); ++i)
            {
                int first = s[i-1] - '0';
                int second = atoi(s.substr(i-2, 2).c_str());

                // one number
                if (first >= 1 && first <= 9)
                {
                    dp[i] += dp[i-1];
                }

                // two number combination
                if (second >= 10 && second <= 26)
                {
                    dp[i] += dp[i-2];
                }
            }
            return dp.back();
        }
};

void testNumDecodings()
{
    Solution s;
    assert(s.numDecodings("17") == 2);
}

int main()
{
    testNumDecodings();
    return 0;
}
