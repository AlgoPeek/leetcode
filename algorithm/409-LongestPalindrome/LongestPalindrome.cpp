// Source: https://leetcode.com/problems/longest-palindrome/description/
// Author: Diego Lee
// Date: 2018-08-22
//
// Description:
// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
// Example:
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

class Solution
{
    public:
        int longestPalindrome(std::string s)
        {
            int result = 0;
            std::unordered_map<char, int> hash;
            for (char ch : s)
            {
                ++hash[ch];
            }

            bool hasOdd = false;
            for (auto it = hash.begin(); it != hash.end(); ++it)
            {
                if (it->second % 2 == 0)
                {
                    result += it->second;
                }
                else
                {
                    hasOdd = true;
                    if (it->second > 1)
                    {
                        result += (it->second - 1);
                    }
                }
            }
            if (hasOdd)
            {
                result += 1;
            }
            return result;
        }
};

void testLongestPalindrome()
{
    Solution s;
    int result = s.longestPalindrome("abccccdd");
    assert(result == 7);
}

int main()
{
    testLongestPalindrome();
    return 0;
}
