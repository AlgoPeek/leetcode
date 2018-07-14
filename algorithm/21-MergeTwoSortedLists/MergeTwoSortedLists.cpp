// Source: https://leetcode.com/problems/merge-two-sorted-lists/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include <iostream>
#include <cassert>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* mergeTwoLists(ListNode* L1, ListNode* L2)
        {
            ListNode* fakeHead = new ListNode(0);
            ListNode* p1 = L1;
            ListNode* p2 = L2;
            ListNode* p = fakeHead;

            while (p1 != NULL && p2 != NULL)
            {
                if (p1->val <= p2->val)
                {
                    p->next = p1;
                    p1 = p1->next;
                }
                else
                {
                    p->next = p2;
                    p2 = p2->next;
                }
                p = p->next;
            }
            if (p1 != NULL)
            {
                p->next = p1;
            }
            if (p2 != NULL)
            {
                p->next = p2;
            }

            ListNode* head = fakeHead->next;
            delete fakeHead;
            return head;
        }
};

void printList(ListNode* head)
{
    ListNode* p = head;
    while (p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void testMergeTwoLists()
{
    ListNode* L1 = new ListNode(1);
    L1->next = new ListNode(3);

    ListNode* L2 = new ListNode(2);
    L2->next = new ListNode(4);

    Solution sln;
    ListNode* head = sln.mergeTwoLists(L1, L2);
    // printList(head);
}

int main()
{
    testMergeTwoLists();
    return 0;
}

