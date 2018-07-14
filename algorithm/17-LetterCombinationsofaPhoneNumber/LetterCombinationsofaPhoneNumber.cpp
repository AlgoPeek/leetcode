// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Author: Diego Lee
// Date: 2018-07-14
//
// Description:
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// {2 : "abc"}, {3 : "def"}, {4 : "ghi"}, {5 : "jkl"}, {6 : "mno"}, {7 : "qprs"}, {8 : "tuv"}, {9 : "wxyz"}
//
// Example:
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    std::vector<std::string> _symbols;
public:
    Solution()
    {
        char LETTER_SYMBOLE[10][5] =
        {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        for (int i = 0; i < 10; ++i)
        {
            _symbols.push_back(LETTER_SYMBOLE[i]);
        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        std::string curr;
        letterCombinationsHelp(digits, 0, curr, result);
        return result;
    }

    void letterCombinationsHelp(const std::string& digits, size_t i, std::string& curr,
        std::vector<std::string>& result)
    {
        if (i >= digits.size() && !curr.empty())
        {
            // std::cout << curr << std::endl;
            result.push_back(curr);
            return;
        }

        std::string symbol = _symbols[digits[i] - '0'];
        for (size_t j = 0; j < symbol.size(); ++j)
        {
            curr.push_back(symbol[j]);
            letterCombinationsHelp(digits, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

void testLetterCombinations()
{
    char A[][3] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    std::vector<std::string> expire(std::begin(A), std::end(A));
    std::vector<std::string> result = Solution().letterCombinations("23");
    assert(result == expire);
}

int main()
{
    testLetterCombinations();
    return 0;
}
