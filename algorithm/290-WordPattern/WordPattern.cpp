// Source: https://leetcode.com/problems/word-pattern/description/
// Author: Diego Lee
// Date: 2018-08-13
//
// Description:
// Given a pattern and a string str, find if str follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Example 1:
//
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
// Example 2:
//
// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
// Example 3:
//
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
// Example 4:
//
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>

class Solution
{
    public:
        bool wordPattern(std::string pattern, std::string str)
        {
            std::vector<std::string> tokens = getTokens(str);
            if (pattern.size() != tokens.size())
            {
                return false;
            }

            std::unordered_map<char, std::string> hash1;
            std::unordered_map<std::string, char> hash2;
            for (int i = 0; i < pattern.size(); ++i)
            {
                if (hash1.find(pattern[i]) == hash1.end())
                {
                    if (hash2.find(tokens[i])== hash2.end())
                    {
                        hash1[pattern[i]] = tokens[i];
                        hash2[tokens[i]] = pattern[i];
                    }
                    else
                    {
                        if (hash2[tokens[i]] != pattern[i])
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if (hash1[pattern[i]] != tokens[i])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        std::vector<std::string> getTokens(const std::string& str)
        {
            std::vector<std::string> result;
            int pos = 0;
            for (int i = 0, len = str.size(); i < len; ++i)
            {
                if (str[i] == ' ')
                {
                    std::string token = str.substr(pos, i - pos);
                    if (!token.empty())
                    {
                        result.push_back(token);
                    }
                    pos = i + 1;
                }
                else if (i == len - 1)
                {
                    while (pos < len && str[pos] == ' ')
                    {
                        ++pos;
                    }
                    if (pos < len)
                    {
                        result.push_back(str.substr(pos));
                    }
                }
            }
            return result;
        }
};

void testWordPattern()
{
    Solution s;
    assert(s.wordPattern("abba", "dog cat cat dog") == true);
    assert(s.wordPattern("abba", "dog cat cat fish") == false);
    assert(s.wordPattern("aaaa", "dog cat cat dog") == false);
    assert(s.wordPattern("abba", "dog dog dog dog") == false);
}

int main()
{
    testWordPattern();
    return 0;
}
