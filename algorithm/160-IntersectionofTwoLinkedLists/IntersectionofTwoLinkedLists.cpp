// Source: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
// Author: Diego Lee
// Date: 2018-07-18
//
// Description:
// Write a program to find the node at which the intersection of two singly linked lists begins.
// For example, the following two linked lists:
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// begin to intersect at node c1.
//
// Notes:
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            int lengthA = 0;
            int lengthB = 0;
            ListNode* currA = headA;
            while (currA != NULL)
            {
                ++lengthA;
                currA = currA->next;
            }

            ListNode* currB = headB;
            while (currB != NULL)
            {
                ++lengthB;
                currB = currB->next;
            }

            currA = headA;
            currB = headB;
            int forward = abs(lengthA - lengthB);
            if (forward > 0)
            {
                while (forward-- > 0)
                {
                    if (lengthA > lengthB)
                    {
                        currA = currA->next;
                    }
                    else
                    {
                        currB = currB->next;
                    }
                }
            }

            while (currA != NULL && currB != NULL && currA != currB)
            {
                currA = currA->next;
                currB = currB->next;
            }
            return (currA == currB) ? currA : NULL;
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

ListNode* Forward(ListNode* head, int n)
{
    ListNode* curr = head;
    while (curr != NULL && n-- > 0)
    {
        curr = curr->next;
    }
    return curr;
}

void testGetIntersectionNode()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {1, 2, 3};
    ListNode* headA = buildList(A, countof(A));
    assert(headA);
    ListNode* headB = buildList(B, countof(B));
    assert(headB);
    ListNode* intersection = Forward(headA, 2);
    assert(intersection);
    ListNode* tailB = Forward(headB, 2);
    assert(tailB);
    tailB->next = intersection;
    ListNode* result = Solution().getIntersectionNode(headA, headB);
    assert(result == intersection);
}

int main()
{
    testGetIntersectionNode();
    return 0;
}
