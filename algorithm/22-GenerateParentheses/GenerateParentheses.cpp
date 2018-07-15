// Source: https://leetcode.com/problems/generate-parentheses/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <stack>

class Solution
{
    public:
        std::vector<std::string> generateParenthesis(int n)
        {
            std::vector<std::string> result;
            generateParenthesisHelp(n, 0, 0, "", result);
            return result;
        }

        void generateParenthesisHelp(int n, int leftParentheseCount, int rightParentheseCount, std::string curr,
                std::vector<std::string>& result)
        {
            if (curr.size() >= 2 * n)
            {
                // std::cout << curr << std::endl;
                result.push_back(curr);
                return;
            }

            if (leftParentheseCount < n)
            {
                generateParenthesisHelp(n, leftParentheseCount + 1, rightParentheseCount, curr + "(", result);
            }
            if (rightParentheseCount < leftParentheseCount)
            {
                generateParenthesisHelp(n, leftParentheseCount, rightParentheseCount + 1, curr + ")", result);
            }
        }
};

void testGenerateParenthesis(void)
{
    char M[][7] =
    {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
    };
    std::vector<std::string> expire(std::begin(M), std::end(M));
    std::vector<std::string> result = Solution().generateParenthesis(3);
    assert(expire == result);
}

int main()
{
    testGenerateParenthesis();
    return 0;
}
