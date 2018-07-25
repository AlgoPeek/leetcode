// Source: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Author: Diego Lee
// Date: 2018-07-25
//
// Description:
// Given an input string, reverse the string word by word.
//
// Example:
// Input: "the sky is blue",
// Output: "blue is sky the".
//
// Note:
// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// You need to reduce multiple spaces between two words to a single space in the reversed string.
// Follow up: For C programmers, try to solve it in-place in O(1) space.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution {
    public:
        void reverseWords(std::string &s)
        {
            std::vector<std::string> tokens;
            splitString(s, tokens);
            int left = 0;
            int right = tokens.size() - 1;
            while (left < right)
            {
                std::swap(tokens[left++], tokens[right--]);
            }

            s.clear();
            for (size_t i = 0; i < tokens.size(); ++i)
            {
                // std::cout << "i=" << i << ", token=" << tokens[i] << std::endl;
                s.append(tokens[i]);
                if (i != tokens.size() - 1)
                {
                    s.append(" ");
                }
            }
        }

        void splitString(const std::string& s, std::vector<std::string>& tokens)
        {
            std::string str = trim(s);
            int pos = -1;
            for (int i = 0; i < str.size(); ++i)
            {
                if (str[i] == ' ')
                {
                    std::string token = str.substr(pos + 1, i - pos - 1);
                    if (!token.empty())
                    {
                        tokens.push_back(token);
                    }
                    pos = i;
                }
            }
            std::string token = str.substr(pos + 1, str.size() - pos - 1);
            if (!token.empty())
            {
                tokens.push_back(token);
            }
        }

        std::string trim(const std::string& s)
        {
            if (s.empty())
            {
                return s;
            }

            int left = 0;
            while (left < s.size() && s[left] == ' ')
            {
                ++left;
            }

            int right = s.size() - 1;
            while (right >= 0 && s[right] == ' ')
            {
                --right;
            }

            if (right >= left)
            {
                return s.substr(left, right - left + 1);
            }
            else
            {
                return "";
            }
        }
};

void testReverseWords()
{
    Solution s;
    std::string str = "the sky is blue";
    s.reverseWords(str);
    assert(str == std::string("blue is sky the"));

    str = " ";
    s.reverseWords(str);
    assert(str == std::string(""));

    str = "a";
    s.reverseWords(str);
    assert(str == std::string("a"));

    str = "   a   b ";
    s.reverseWords(str);
    assert(str == std::string("b a"));
}

int main()
{
    testReverseWords();
    return 0;
}
