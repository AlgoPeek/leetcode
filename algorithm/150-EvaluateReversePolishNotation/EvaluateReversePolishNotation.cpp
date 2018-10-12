// Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// Author: Diego Lee
// Date: 2018-10-12
//
// Description:
// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
// Note:
//
// Division between two integers should truncate toward zero.
// The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
// Example 1:
//
// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:
//
// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:
//
// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
// Explanation:
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22

#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <stack>

class Solution {
    public:
        int evalRPN(std::vector<std::string>& tokens) {
            std::stack<int> S;
            for (auto token : tokens) {
                if (token == "+"
                    || token == "-"
                    || token == "*"
                    || token == "/") {
                    if (S.size() < 2) {
                        return -1;
                    }

                    int second = S.top();
                    S.pop();
                    int first = S.top();
                    S.pop();
                    int curr = 0;
                    if (token == "+") {
                        curr = first + second;
                    }
                    else if (token == "-") {
                        curr = first - second;
                    }
                    else if (token == "*") {
                        curr = first * second;
                    }
                    else if (token == "/") {
                        curr = first / second;
                    }
                    else {
                        return -1;
                    }
                    S.push(curr);
                }
                else {
                    S.push(atoi(token.c_str()));
                }
            }
            if (S.size() == 1) {
                return S.top();
            }
            else {
                return -1;
            }
        }
};

void testEvalRPNCase1() {
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;
    int result = s.evalRPN(tokens);
    assert(result == 9);
}

void testEvalRPNCase2() {
    std::vector<std::string> tokens = {"4","13","5","/","+"};
    Solution s;
    int result = s.evalRPN(tokens);
    assert(result == 6);
}

int main() {
    testEvalRPNCase1();
    testEvalRPNCase2();
    return 0;
}
