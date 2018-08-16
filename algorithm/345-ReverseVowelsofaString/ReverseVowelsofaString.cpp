// Source: https://leetcode.com/problems/reverse-vowels-of-a-string/description/
// Author: Diego Lee
// Date: 2018-08-16
//
// Description:
// Write a function that takes a string as input and reverse only the vowels of a string.
//
// Example 1:
//
// Input: "hello"
// Output: "holle"
// Example 2:
//
// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".

#include <iostream>
#include <string>
#include <cassert>

class Solution
{
    public:
        std::string reverseVowels(std::string s)
        {
            int left = 0;
            int right = s.size() - 1;
            while (left < right)
            {
                if (!isVowel(s[left]))
                {
                    ++left;
                }
                else if (!isVowel(s[right]))
                {
                    --right;
                }
                else
                {
                    std::swap(s[left++], s[right--]);
                }
            }
            return s;
        }

        char toLower(char ch)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch - 'A' + 'a';
            }
            return ch;
        }

        bool isVowel(char ch)
        {
            char chLower = toLower(ch);
            return (chLower == 'a'
                    || chLower == 'e'
                    || chLower == 'i'
                    || chLower == 'o'
                    || chLower == 'u');
        }
};

void testReverseVowels()
{
    Solution s;
    assert(s.reverseVowels("hello") == std::string("holle"));
}

int main()
{
    testReverseVowels();
    return 0;
}
