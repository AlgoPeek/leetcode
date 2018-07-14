// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description: Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
// Note:
// Given n will always be valid.
//
// Follow up:
// Could you do this in one pass?

#include <iostream>
#include <assert.h>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            assert(n > 0);
            int step = 0;
            ListNode* pre = NULL;
            ListNode* end = head;
            while (end != NULL)
            {
                if (step == n)
                {
                    pre = head;
                }
                else if (step > n)
                {
                    pre = pre->next;
                }

                ++step;
                end = end->next;
            }
            if (pre == NULL)
            {
                return head->next;
            }
            pre->next = pre->next->next;
            return head;
        }
};

void printList(ListNode* head)
{
    ListNode* tmp = head;
    while (tmp != NULL)
    {
        std::cout << tmp->val << std::endl;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void testRemoveNthFromEnd()
{
    ListNode* guard = new ListNode(0);
    ListNode* tmp = guard;
    for (int i = 1; i <= 2; ++i)
    {
        ListNode* node = new ListNode(i);
        tmp->next = node;
        tmp = node;
    }

    Solution s;
    ListNode* head = s.removeNthFromEnd(guard->next, 2);
    assert(head != NULL && head->val == 2);
}

int main()
{
    testRemoveNthFromEnd();
    return 0;
}
