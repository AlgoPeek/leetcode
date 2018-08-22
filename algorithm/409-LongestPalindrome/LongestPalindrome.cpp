// Source: https://leetcode.com/problems/longest-palindrome/description/
// Author: Diego Lee
// Date: 2018-08-22
//

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
    return 0;
}
