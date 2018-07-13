// Source: https://leetcode.com/problems/valid-palindrome/description/
// Author: Diego Lee
// Date: 2018-07-13
//
// Description:
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
// Example 2:
// Input: "race a car"
// Output: false
//
#include <iostream>
#include <string>
#include <cassert>

class Solution
{
    public:
        bool isPalindrome(const std::string& s)
        {
            bool result = true;
            int left = 0;
            int right = static_cast<int>(s.size()) - 1;
            while (left < right)
            {
                while (!isAlphanum(s[left]) && left < right)
                {
                    ++left;
                }
                while (!isAlphanum(s[right]) && left < right)
                {
                    --right;
                }

                if (!isEqualIgnoreCase(s[left++], s[right--]))
                {
                    result = false;
                    break;
                }
            }
            return result;
        }
    private:
        bool isAlphanum(char c)
        {
            return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
        }

        bool isEqualIgnoreCase(char c1, char c2)
        {
            //std::cout << "(" << c1 << "," << c2 << ")" << std::endl;
            return toLower(c1) == toLower(c2);
        }

        char toLower(char c)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c - 'A' + 'a';
            }
            return c;
        }
};

void testIsPalindrome()
{
    std::string str = "A man, a plan, a canal: Panama";
    assert(Solution().isPalindrome(str) == true);
}

int main()
{
    testIsPalindrome();
    return 0;
}
