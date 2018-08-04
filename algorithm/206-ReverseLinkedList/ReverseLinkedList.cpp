// Source: https://leetcode.com/problems/reverse-linked-list/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Reverse a singly linked list.
//
// Example:
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?


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
        ListNode* reverseList(ListNode* head)
        {
            if (NULL == head)
            {
                return NULL;
            }

            ListNode* newHead = head;
            ListNode* nextNode = head->next;
            newHead->next = NULL;
            ListNode* currNode = NULL;
            while (nextNode != NULL)
            {
                currNode = nextNode->next;
                nextNode->next = newHead;
                newHead = nextNode;
                nextNode = currNode;
            }
            return newHead;
        }
};

ListNode* createList(int* a, int n)
{
    ListNode fakeHead(0);
    ListNode* p = &fakeHead;
    for (int i = 0; i < n; ++i)
    {
        p->next = new ListNode(a[i]);
        p = p->next;
    }
    return fakeHead.next;
}

void printList(ListNode* head)
{
    ListNode* p = head;
    while (p != NULL)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void testReverseList()
{
    int a[] = {3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    ListNode* head = createList(a, n);
    // printList(head);

    Solution sln;
    ListNode* newHead = sln.reverseList(head);
    // printList(newHead);
    assert(1 == newHead->val);
    assert(2 == newHead->next->val);
    assert(3 == newHead->next->next->val);
}

int main()
{
    testReverseList();
    return 0;
}
