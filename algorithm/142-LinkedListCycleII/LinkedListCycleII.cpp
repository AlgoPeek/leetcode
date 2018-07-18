// Source: https://leetcode.com/problems/linked-list-cycle-ii/description/
// Author: Diego Lee
// Date: 2018-07-18
//
// Description:
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// Note: Do not modify the linked list.
//
// Follow up:
// Can you solve it without using extra space?

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode *detectCycle(ListNode *head)
        {
            ListNode* slow = head;
            ListNode* fast = head;
            bool isCycle = false;
            while (slow != NULL && fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                {
                    isCycle = true;
                    break;
                }
            }

            ListNode* intersection = NULL;
            if (isCycle)
            {
                fast = head;
                while (fast != slow)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                intersection = fast;
            }
            return intersection;
        }
};

ListNode* buildList(int* A, int n)
{
    ListNode* head = NULL;
    ListNode* curr = NULL;
    for (int i = 0; i < n; ++i)
    {
        if (head == NULL)
        {
            head = new ListNode(A[i]);
            curr = head;
        }
        else
        {
            curr->next = new ListNode(A[i]);
            curr = curr->next;
        }
    }
    return head;
}

ListNode* forwardList(ListNode* head, int step)
{
    ListNode* curr = head;
    while (curr && step-- > 0)
    {
        curr = curr->next;
    }
    return curr;
}

void testDetectCycle()
{
    int A[] = {1, 2, 3, 4};
    ListNode* head = buildList(A, countof(A));
    assert(Solution().detectCycle(head) == NULL);

    ListNode* tail = forwardList(head, 3);
    ListNode* intersection = forwardList(head, 1);
    tail->next = intersection;
    assert(Solution().detectCycle(head) == intersection);
}

int main()
{
    testDetectCycle();
    return 0;
}
