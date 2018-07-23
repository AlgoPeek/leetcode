// Source: https://leetcode.com/problems/longest-valid-parentheses/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
// Example 2:
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <stack>

class Solution
{
    public:
        int longestValidParentheses(std::string s)
        {
            int result = 0;
            std::stack<int> stack;
            stack.push(-1);
            for (int i = 0; i < static_cast<int>(s.size()); ++i)
            {
                if (s[i] == '(')
                {
                    stack.push(i);
                }
                else if (s[i] == ')')
                {
                    stack.pop();
                    if (!stack.empty())
                    {
                        result = std::max(result, i - stack.top());
                    }
                    else
                    {
                        stack.push(i);
                    }
                }
            }
            return result;
        }
};

void testLongestValidParentheses()
{
    Solution s;
    assert(s.longestValidParentheses("(()") == 2);
    assert(s.longestValidParentheses(")()())") == 4);
    assert(s.longestValidParentheses("()(()") == 2);
    assert(s.longestValidParentheses("()((())(") == 4);
    assert(s.longestValidParentheses("(()(((()") == 2);
}

int main()
{
    testLongestValidParentheses();
    return 0;
}

