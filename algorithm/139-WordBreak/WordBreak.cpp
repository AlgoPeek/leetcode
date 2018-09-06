// Source: https://leetcode.com/problems/word-break/description/
// Author: Diego Lee
// Date: 2018-09-06
//
// Description:
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_set>

class Solution
{
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict)
        {
            std::unordered_set<std::string> dict;
            for (auto word : wordDict)
            {
                dict.insert(word);
            }

            std::vector<bool> dp(s.size() + 1, false);
            dp[0] = true;
            for (int i = 1; i <= s.size(); ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                    {
                        // std::cout << "i=" << i << ", j=" << j << ", word=" << s.substr(j, i - j) << std::endl;
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp.back();
        }
};

void testWordBreak()
{
    std::vector<std::string> dict = {"leet", "code"};
    Solution s;
    assert(s.wordBreak(std::string("leetcode"), dict) == true);
}

int main()
{
    testWordBreak();
    return 0;
}
