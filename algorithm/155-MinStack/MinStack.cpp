// Source: https://leetcode.com/problems/min-stack/hints/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
//
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

#include <stack>
#include <cassert>
#include <iostream>

class MinStack {
    public:
        MinStack()
        {

        }

        void push(int x)
        {
            if (m_min.empty() || x <= m_min.top())
            {
                m_min.push(x);
            }
            m_stack.push(x);
        }

        void pop()
        {
            if (m_stack.top() == m_min.top())
            {
                m_min.pop();
            }
            m_stack.pop();
        }

        int top()
        {
            return m_stack.top();
        }

        int getMin()
        {
            return m_min.top();
        }
    private:
        std::stack<int> m_stack;
        std::stack<int> m_min;
};

void testMinStack()
{
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    assert(ms.getMin() == -3);
    ms.pop();
    assert(ms.top() == 0);
    assert(ms.getMin() == -2);
}

int main()
{
    testMinStack();
    return 0;
}

