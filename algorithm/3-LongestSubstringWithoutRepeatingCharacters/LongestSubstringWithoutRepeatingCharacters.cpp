// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Author: Diego Lee
// Date: 2018-07-10
//
// Description
// Given a string, find the length of the longest substring without repeating characters.
//
// Example:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring,
// "pwke" is a subsequence and not a substring.
//

#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
    public:
        int lengthOfLongestSubstring(const std::string& s)
        {
            std::vector<bool> flag(256, false);
            size_t result = 0;
            size_t start = 0;
            for (size_t i = 0; i < s.size(); ++i)
            {
                char curr = s[i];
                if (flag[curr])
                {
                    result = std::max(i - start, result);
                    for (size_t j = start; j < i; ++j)
                    {
                        if (curr == s[j])
                        {
                            start = j + 1;
                            break;
                        }
                        flag[s[j]] = false;
                    }
                }
                else
                {
                    flag[curr] = true;
                }
            }
            return std::max(s.size() - start, result);
        }
};

void testLengthOfLongestSubstring()
{
    Solution s;
    std::string str = "abcabcbb";
    int len = s.lengthOfLongestSubstring(str);
    assert(3 == len);

    str = "bbbbb";
    len = s.lengthOfLongestSubstring(str);
    assert(1 == len);

    str = "abca";
    len = s.lengthOfLongestSubstring(str);
    assert(3 == len);

    str = "abcdd";
    len = s.lengthOfLongestSubstring(str);
    assert(4 == len);
}

int main()
{
    testLengthOfLongestSubstring();
    return 0;
}
