// Source: https://leetcode.com/problems/valid-parentheses/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
//
// Example 1:
// Input: "()"
// Output: true
//
// Example 2:
// Input: "()[]{}"
// Output: true
//
// Example 3:
// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true

#include <iostream>
#include <assert.h>
#include <string>
#include <stack>

class Solution
{
    public:
        bool isValid(const std::string& s)
        {
            std::stack<char> stack;
            for (size_t i = 0; i < s.size(); ++i)
            {
                char ch = s[i];
                if (ch == '(' || ch == '[' || ch == '{')
                {
                    stack.push(ch);
                }
                else if ( ch == ')' || ch == ']' || ch == '}' )
                {
                    if (stack.empty())
                    {
                        return false;
                    }

                    char top = stack.top();
                    bool bValid;
                    switch (ch)
                    {
                        case ')': bValid = (top == '('); break;
                        case ']': bValid = (top == '['); break;
                        case '}': bValid = (top == '{'); break;
                        default : bValid = false;
                    }

                    if (bValid)
                    {
                        stack.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            return stack.empty();
        }
};

void testValidParentheses()
{
    Solution sln;
    std::string s = "()";
    bool bValid = sln.isValid(s);
    assert(bValid);

    s = "[(])";
    bValid = sln.isValid(s);
    assert(!bValid);

    s = "]";
    bValid = sln.isValid(s);
    assert(!bValid);
}

int main()
{
    testValidParentheses();
    return 0;
}
